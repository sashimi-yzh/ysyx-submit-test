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
#include "../monitor/sdb/sdb.h" 

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10
#define IRINGBUF_SIZE 16

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();
#ifdef CONFIG_ITRACE
typedef struct {
  vaddr_t pc;
  uint32_t inst;
  char logbuf[128];
} IringBufEntry;

static IringBufEntry iringbuf[IRINGBUF_SIZE];
static int iringbuf_idx = 0;
static bool iringbuf_full = false;

static void iringbuf_write(vaddr_t pc, uint32_t inst, const char *logbuf) {
  iringbuf[iringbuf_idx].pc = pc;
  iringbuf[iringbuf_idx].inst = inst;
  size_t len = strlen(logbuf);
  if (len >= sizeof(iringbuf[iringbuf_idx].logbuf)) {
    len = sizeof(iringbuf[iringbuf_idx].logbuf) - 1;
  }
  memcpy(iringbuf[iringbuf_idx].logbuf, logbuf, len);
  iringbuf[iringbuf_idx].logbuf[len] = '\0';
  
  iringbuf_idx = (iringbuf_idx + 1) % IRINGBUF_SIZE;
  if (iringbuf_idx == 0) {
    iringbuf_full = true;
  }
}

void display_iringbuf() {
  printf("\n" ANSI_FMT("Recent executed instructions (iringbuf):", ANSI_FG_CYAN) "\n");
  
  int start = iringbuf_full ? iringbuf_idx : 0;
  int count = iringbuf_full ? IRINGBUF_SIZE : iringbuf_idx;
  
  if (count == 0) {
    printf("  (empty)\n");
    return;
  }
  
  for (int i = 0; i < count; i++) {
    int idx = (start + i) % IRINGBUF_SIZE;
    
    // 标记最后一条指令（出错的指令）
    if (i == count - 1) {
      printf(ANSI_FMT("-->", ANSI_FG_RED) " %s\n", iringbuf[idx].logbuf);
    } else {
      printf("    %s\n", iringbuf[idx].logbuf);
    }
  }
  printf("\n");
}
#endif
static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
  if (cachesim_trace_fp != NULL) {
    uint32_t trace_pc = (uint32_t)_this->pc;
    fwrite(&trace_pc, sizeof(trace_pc), 1, cachesim_trace_fp);
  }

#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif

  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }

  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));

#ifdef CONFIG_WATCHPOINT
  if (check_watchpoints()) {
    if (nemu_state.state != NEMU_END) nemu_state.state = NEMU_STOP;
  }
#endif
}

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
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
  
  // 将指令写入环形缓冲区
  IFDEF(CONFIG_ITRACE, iringbuf_write(s->pc, s->isa.inst, s->logbuf));
}

static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
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
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  IFDEF(CONFIG_ITRACE, display_iringbuf());
  isa_reg_display();
  statistic();
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

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // 在程序异常终止时显示 iringbuf
      if (nemu_state.state == NEMU_ABORT || nemu_state.halt_ret != 0) {
        IFDEF(CONFIG_ITRACE, display_iringbuf());
      }
      // fall through
    case NEMU_QUIT: statistic();
  }
}
