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

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 100

#define OPTMASK 0x7f
#define RDMASK 0x1f
#define INDENT_SIZE 2

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;
uint64_t g_running_cycles = 0;
void device_update();
bool check_watchpointers(void);
char* find_symbol_by_address(vaddr_t address);

#ifdef CONFIG_ITRACE_COND
#ifdef CONFIG_FTRACE
static bool decode_jal_jalr_func(Decode *_this) {
    vaddr_t call_addr, ret_addr;
    char *sym_name;
    uint32_t i = _this->isa.inst.val;
    uint32_t opcode = i & OPTMASK;
    uint32_t rd = (i >> 7) & RDMASK;
    static uint32_t level = 0;
    uint32_t spaces = 0;

    call_addr = _this->dnpc;
    ret_addr = _this->pc;
    sym_name = find_symbol_by_address(call_addr);

    /* JAL */
    if (opcode == 0x6f) {
      if (rd) {
        spaces = (level++) * INDENT_SIZE;
        sprintf(_this->ftracebuf, "%x %*s call %s@%x\n",
          _this->pc, spaces, "", sym_name, call_addr);
      } else {
        spaces = (level) * INDENT_SIZE;
        sprintf(_this->ftracebuf, "%x %*s J %s@%x\n",
          _this->pc, spaces, "", sym_name, call_addr);
      }
        return true;
    }

    /* JALR */
    if (opcode == 0x67) {
      if (rd) {
        spaces = (level++) * INDENT_SIZE;
        sprintf(_this->ftracebuf, "%x %*s call %s@%x\n",
                _this->pc, spaces, "", sym_name, call_addr);
      } else {
        sym_name = find_symbol_by_address(ret_addr);
        spaces = (--level) * INDENT_SIZE;
        sprintf(_this->ftracebuf, "%x %*s ret %s@%x\n",
                _this->pc, spaces, "", sym_name, ret_addr);
      }
      return true;
    }
    return false;
}
#endif
#endif

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) {
    log_write("%s\n", _this->logbuf);
    log_wr_iringbuf("%s", _this->logbuf);
  }
#endif
#ifdef CONFIG_FTRACE
  if (decode_jal_jalr_func(_this)) log_ftrace("%s", _this->ftracebuf);
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, if (_this->exe_done) difftest_step(_this->pc, dnpc));

#ifdef CONFIG_WATCHPOINT
  if (check_watchpointers()) {
    nemu_state.state = NEMU_STOP;
    Log("Value changes is captured by watchpointers");
  }
#endif
}


static void exec_once(Decode *s, vaddr_t pc) {

  if (!isa_exec_once(s)) {
    nemu_state.state = NEMU_END;
    return;
  }

#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

#ifndef CONFIG_ISA_loongarch32r
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
#endif
}

static void execute(uint64_t n) {
  Decode s = {0};
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    g_running_cycles = g_running_cycles + s.cycles_per_exec;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  Log("total cycles = " NUMBERIC_FMT, g_running_cycles);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
  if (g_running_cycles > 0) Log("average IPC = " "%.6f", (double)g_nr_guest_inst / g_running_cycles);
  else Log("Finish running in less than 1 cycle and can not calculate the average IPC");
}

void assert_fail_msg() {
  isa_reg_display();
  statistic();
  deinit_verilator_env();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("npc: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      log_show_iringbuf();
      isa_reg_display();
      IFDEF(CONFIG_PERF, perf_cnt_display());
      deinit_verilator_env();
      // fall through
    case NEMU_QUIT: statistic();
  }
}
