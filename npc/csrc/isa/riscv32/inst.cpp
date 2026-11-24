/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NPC is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <verilated.h>
#include "VysyxSoCFull.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cpu/decode.h>
#include <cpu/ifetch.h>
#include <memory/paddr.h>
#include <signal.h>
#include "dpi.h"
#ifdef CONFIG_WTRACE
#include <verilated_fst_c.h>
#endif
#ifdef CONFIG_NVBOARD
#include <nvboard.h>
#endif

// soc compile
extern "C" void flash_read(int32_t addr, int32_t *data);
extern "C" void mrom_read(int32_t addr, int32_t *data);

#ifdef CONFIG_NVBOARD
void nvboard_bind_all_pins(TOP_NAME* top);
#endif

static VerilatedContext *contextp = NULL;
static VysyxSoCFull *top = NULL;
#ifdef CONFIG_WTRACE
static VerilatedFstC *tfp = NULL;
#endif

#ifdef CONFIG_EXEC_TIMEOUT
static void check_exec_timeout(const struct timespec *exec_start) {
  struct timespec now;
  time_t elapsed_sec;
  long elapsed_nsec;

  clock_gettime(CLOCK_MONOTONIC, &now);
  elapsed_sec = now.tv_sec - exec_start->tv_sec;
  elapsed_nsec = now.tv_nsec - exec_start->tv_nsec;
  if (elapsed_nsec < 0) {
    elapsed_sec--;
    elapsed_nsec += 1000000000L;
  }
  if (elapsed_sec > 3 || (elapsed_sec == 3 && elapsed_nsec >= 0)) {
    fprintf(stderr, "isa_exec_once timeout after 3 seconds\n");
    deinit_verilator_env();
    exit(EXIT_FAILURE);
  }
}
#endif

void verilator_signal_handler(int signum) {
  deinit_verilator_env();
  signal(signum, SIG_DFL);
  raise(signum);
}

extern "C" void init_verilator_env (int argc, char *argv[]) {

  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);

#ifdef CONFIG_WTRACE
  contextp->traceEverOn(true);
#endif

  top = new VysyxSoCFull{contextp};
#ifdef CONFIG_WTRACE
  tfp = new VerilatedFstC;
  top->trace(tfp, 99);
  tfp->open("build/riscv.fst");
#endif

#ifdef CONFIG_NVBOARD
  nvboard_bind_all_pins(top);
  nvboard_init();
#endif
  // initial clock and reset
  top->clock = -1;
  top->reset = 1;
  //top->pc = CONFIG_MBASE;

  /* Reset the system.
     Keep reset for 10 cycles as the SOC reset happened at 10th cycle
     This change is to cover SOC reset to avoid twice reset.
     And the one clock includes 1 low and 1 high, so 22 is set here
     to make sure it is bigger than 10. */
  for (int i = -1; i < 22; ++i)
  {
    top->clock = !top->clock;
    top->eval();
#ifdef CONFIG_WTRACE
    tfp->dump(contextp->time());
#endif
    contextp->timeInc(1);
  }

  // reset done
  top->reset = 0;

  signal(SIGABRT, verilator_signal_handler);
  signal(SIGSEGV, verilator_signal_handler);
  signal(SIGINT,  verilator_signal_handler);
}

extern "C" void deinit_verilator_env() {
  static bool deinited = false;
  if (deinited)
    return;
  deinited = true;

  top->final();
#ifdef CONFIG_WTRACE
  tfp->flush();
  tfp->close();
  delete tfp;
#endif
  delete top;
  delete contextp;
}

extern "C" int isa_exec_once(Decode *s) {

  setup_scope("cpu");
  if(!contextp->gotFinish()) {
    s->cycles_per_exec = 0;
#ifdef CONFIG_EXEC_TIMEOUT
    struct timespec exec_start;
    clock_gettime(CLOCK_MONOTONIC, &exec_start);
#endif
    /* for single-cycle cpu, the pc is got from
    the last cycle and executed in this cycle */
    do {
      for (uint32_t i = 0; i < 2; i++) {
        top->clock = !top->clock;
        top->eval();
#ifdef CONFIG_WTRACE
        tfp->dump(contextp->time());
#endif
        contextp->timeInc(1);
      }
#ifdef CONFIG_NVBOARD
      nvboard_update();
#endif
      s->cycles_per_exec++;
      s->exe_done = get_cycle_done();
#ifdef CONFIG_EXEC_TIMEOUT
      if (!s->exe_done) {
        check_exec_timeout(&exec_start);
      }
#endif
    } while (!s->exe_done);
    s->pc           = get_pc();
    s->isa.inst.val = get_inst();
    s->snpc         = s->pc + 4;
    s->dnpc         = get_npc();
#ifdef CONFIG_DIFFTEST
    get_npc_gpr_regs(&cpu);
#else
    // cpu.gpr is only consumed by difftest;
    // other users read GPRs via DPI
    cpu.pc = s->pc;
#endif
    return 1;
  }
  return 0;
}
