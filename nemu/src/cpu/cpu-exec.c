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

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include <utils.h>
#include "../monitor/sdb/sdb.h"
#include <utils/iringbuf.h>   // <<<< iringbuf
#ifdef CONFIG_FTRACE
#include <utils/ftrace.h>
#endif
#ifdef CONFIG_PC_TRACE
#include <stdio.h>
#include <stdint.h>

static FILE *pc_trace_fp = NULL;

static void pc_trace_open() {
  if (pc_trace_fp == NULL) {
    pc_trace_fp = fopen(CONFIG_PC_TRACE_FILE, "wb");
    Assert(pc_trace_fp, "Can not open pc.trace.bin");

    static char pc_trace_buf[1 << 20];
    setvbuf(pc_trace_fp, pc_trace_buf, _IOFBF, sizeof(pc_trace_buf));
  }
}

static inline void pc_trace_write(vaddr_t pc) {
  pc_trace_open();

  // riscv32 的 PC 用 32bit 保存即可
  uint32_t pc32 = (uint32_t)pc;
  fwrite(&pc32, sizeof(pc32), 1, pc_trace_fp);
}

static void pc_trace_close() {
  if (pc_trace_fp != NULL) {
    fflush(pc_trace_fp);
    fclose(pc_trace_fp);
    pc_trace_fp = NULL;
  }
}

__attribute__((destructor))
static void pc_trace_close_on_exit() {
  pc_trace_close();
}
#endif

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

static vaddr_t last_loop_pc = 0;
static uint64_t same_pc_cnt = 0;
#define DEAD_LOOP_THRESHOLD 1000000
void device_update();


static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE
# ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
# endif
  if (g_print_step) { puts(_this->logbuf); }
#endif

  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
#ifndef CONFIG_TARGET_AM
  if (nemu_state.state == NEMU_RUNNING && check_watchpoints()) {
    nemu_state.state = NEMU_STOP;
  }
#endif
}

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
#ifdef CONFIG_PC_TRACE
  pc_trace_write(pc);
#endif
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_FTRACE
  uint32_t inst_word = *(uint32_t *)&s->isa.inst;
  ftrace_trace(s->pc, inst_word, s->dnpc);
#endif
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  uint64_t inst_idx = g_nr_guest_inst + 1;
  p += snprintf(p, sizeof(s->logbuf) - (p - s->logbuf),
      "[%" PRIu64 "] " FMT_WORD ":", inst_idx, s->pc);

  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst;

#ifdef CONFIG_ISA_x86
  for (i = 0; i < ilen; i ++) {
#else
  for (i = ilen - 1; i >= 0; i --) {
#endif
    p += snprintf(p, 4, " %02x", inst[i]);
  }

  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen);
#endif

  #ifdef CONFIG_ITRACE
  #ifdef CONFIG_ITRACE_COND
    if (ITRACE_COND) {
      iringbuf_push(s->logbuf);
    }
  #else
    iringbuf_push(s->logbuf);
  #endif
#endif
}

// static void execute(uint64_t n) {
//   Decode s;
//   for (; n > 0; n --) {
//     exec_once(&s, cpu.pc);
//     g_nr_guest_inst ++;
//     trace_and_difftest(&s, cpu.pc);
//     if (nemu_state.state != NEMU_RUNNING) break;
//     IFDEF(CONFIG_DEVICE, device_update());
//   }
// }
static void execute(uint64_t n) {
  Decode s;
  for(;n>0;n--){
    vaddr_t this_pc = cpu.pc;
    exec_once(&s, this_pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    if(this_pc == last_loop_pc){
      same_pc_cnt++;
        if(same_pc_cnt >= DEAD_LOOP_THRESHOLD){
          printf("Dead loop detected at PC = " FMT_WORD "\n", this_pc);
          nemu_state.state = NEMU_STOP;
          break;
        }
      }
      else{
        last_loop_pc=cpu.pc;
        same_pc_cnt=0;
      }
      IFDEF(CONFIG_DEVICE, device_update());
  }
}
static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s",
      g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  // <<<< 出错时打印最近执行的指令
  // iringbuf_dump(false);
#ifdef CONFIG_ITRACE
  iringbuf_dump(false);
#endif
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
#ifdef CONFIG_ITRACE
  static bool iring_inited = false;
  if (!iring_inited) {
    iringbuf_init();
    iring_inited = true;
  }
#endif
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT: case NEMU_QUIT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again later.\n");
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
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      #ifdef CONFIG_ITRACE
        bool goodtrap = (nemu_state.state == NEMU_END) && (nemu_state.halt_ret == 0);
        iringbuf_dump(goodtrap);
      #endif
      // fall through
    case NEMU_QUIT: statistic();
  }
}
