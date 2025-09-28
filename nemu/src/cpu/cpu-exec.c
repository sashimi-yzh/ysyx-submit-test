/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 17

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

#ifdef CONFIG_ITRACE
static Decode iringbuf[16];
static uint8_t iringbuf_ptr = 0;

static void print_iringbuf() {
  for (int i = 0; i < 16; ++i) {
    char *log = iringbuf[(iringbuf_ptr + i) & 0xf].logbuf;
    if (*log) puts(log);
  }
  putchar('\n');
}
#endif

void device_update();

#ifdef CONFIG_FTRACE
extern ElfSymbol elf_symbol_list[];
extern int elf_symbol_list_size;

static int get_func_sym_ndx(paddr_t p) {
  for (int i = 0; i < elf_symbol_list_size; ++i) {
    if (elf_symbol_list[i].type == ELF_SYM_FUNC && elf_symbol_list[i].addr <= p) {
      if (p < elf_symbol_list[i].addr + elf_symbol_list[i].size) return i;
    }
  }
  // Log(ANSI_FMT("[FTRACE] Warning: PC outside any FUNC symbol area: " FMT_PADDR, ANSI_FG_YELLOW), p);
  return -1;
}

static void ftrace(Decode *s) {
  static vaddr_t ret_st[128];
  static int ftrace_dep = 0;
  static int lock_dep = 0;

  if (likely(s->dnpc == s->snpc)) return;
  if (elf_symbol_list_size == 0) return; // no elf file
  int from = get_func_sym_ndx(s->pc), to = get_func_sym_ndx(s->dnpc);
  if (likely(from == to)) return;
  if (from == -1 || to == -1) return;

  if (elf_symbol_list[to].addr == s->dnpc) { // call, jump to the begging of a func
    if (!lock_dep) {
      log_write("[FTRACE] " FMT_PADDR ": ", s->pc);
      for (int i = 0; i < ftrace_dep; ++i) log_write(" ");
      log_write("call [%s@" FMT_PADDR "] -> [%s@" FMT_PADDR "]\n",
                elf_symbol_list[from].name,
                elf_symbol_list[from].addr,
                elf_symbol_list[to].name,
                elf_symbol_list[to].addr);
      if (strstr(elf_symbol_list[to].name, "printf")) {
        lock_dep = ftrace_dep;
      }
    }
    ret_st[ftrace_dep++] = s->snpc;
  } else { // ret, return to calling position
    Assert(ftrace_dep, "Error occured in FTRACE: negative deepth");
    while (ret_st[--ftrace_dep] != s->dnpc);
    if (!lock_dep || ftrace_dep <= lock_dep) {
      lock_dep = 0;
      log_write("[FTRACE] " FMT_PADDR ": ", s->pc);
      for (int i = 0; i < ftrace_dep; ++i) log_write(" ");
      log_write("ret [%s@" FMT_PADDR "] -> [%s@" FMT_PADDR "]:" FMT_PADDR "\n",
                elf_symbol_list[from].name,
                elf_symbol_list[from].addr,
                elf_symbol_list[to].name,
                elf_symbol_list[to].addr,
                s->dnpc);
    }
  }
}
#endif

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
#ifdef CONFIG_FTRACE
  ftrace(_this);
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
#ifdef CONFIG_WATCHPOINT
  bool check_wps();
  if (check_wps()) nemu_state.state = NEMU_STOP;
#endif
}

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;

#ifdef CONFIG_PCTRACE
  void pctrace(paddr_t pc);
  pctrace(s->pc);
#endif
#ifdef CONFIG_BRTRACE
  void brtrace(Decode *s);
  brtrace(s);
#endif

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
  *p++ = '\t';

#ifndef CONFIG_ISA_loongarch32r
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif

  iringbuf[iringbuf_ptr++] = *s;
  iringbuf_ptr &= 0xf;
#endif
}

static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());

    word_t intr = isa_query_intr();
    if (intr != INTR_EMPTY) {
      cpu.pc = isa_raise_intr(intr, cpu.pc);
    }
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
  IFDEF(CONFIG_ITRACE, print_iringbuf());
  printf("pc = " FMT_PADDR "\n", cpu.pc);
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
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

    case NEMU_ABORT: IFDEF(CONFIG_ITRACE, print_iringbuf());
    case NEMU_END:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT: statistic();
  }
}
