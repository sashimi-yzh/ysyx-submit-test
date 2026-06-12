/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
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

#include "common.h"
#include "debug.h"
#include "isa.h"
#include "macro.h"
#include "utils.h"
#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 0

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
uint64_t g_nr_guest_cyc = 0;
static uint64_t g_timer = 0; // unit: us
bool g_print_step = false;
bool g_cpu_stop_flag = false;

void device_update();
void iringbuf_display(void);
bool have_change_and_print_wp(void);
int find_bp(word_t addr);

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
  // DIFFTEST
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));

  // WATCHPOINT
  if (nemu_state.state == NEMU_RUNNING) {
#ifdef CONFIG_WATCHPOINT
    if (have_change_and_print_wp()) {
	    nemu_state.state = NEMU_STOP; 
	    printf("stop by watchpoint\n");
    }
#endif
    if (find_bp(cpu.pc) >= 0) {
      g_cpu_stop_flag = true;
    }

    if (g_cpu_stop_flag) {
	    nemu_state.state = NEMU_STOP; 
      g_cpu_stop_flag = false;
    }
  }
}

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
}

static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    g_nr_guest_inst ++;
    exec_once(&s, cpu.pc);
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

IFDEF(CONFIG_NPC, void sim_close(void));

void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_nr_guest_cyc > 0) {
    Log("total guest cycles = " NUMBERIC_FMT, g_nr_guest_cyc);
    Log("IPC = %f", (double)g_nr_guest_inst / (double)g_nr_guest_cyc);
  }
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  IFDEF(CONFIG_TARGET_SHARE, printf("ASSERT FROM SHARE LIB\n"));
  isa_reg_display();
  IFDEF(CONFIG_ITRACE, iringbuf_display());
  statistic();
  IFDEF(CONFIG_NPC, sim_close());
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT: case NEMU_QUIT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_ABORT:
#ifdef CONFIG_DEBUGER_GDB
      break;
#endif
    case NEMU_END: 
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT: 
      statistic();
  }
}
