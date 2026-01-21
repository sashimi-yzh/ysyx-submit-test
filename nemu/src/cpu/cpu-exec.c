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
#include <memory/paddr.h>
#include "sdb.h"


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

void device_update();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
}

// 下面部分是判断监视点的部分内容
//===============================================
#ifdef CONFIG_WATCHPOINT
static void monitor_check(Decode *_this) {
  static word_t data_pre[NR_WP] = {0};
  static word_t data_new[NR_WP] = {0};
  int index[NR_WP] = {0};
  scan_watchpoint(data_new, index);

  for (int i = 0; i < NR_WP; i++)
  {
    if(index[i])
    {
      if(data_new[i] != data_pre[i])
      {
        nemu_state.state = NEMU_STOP;
        printf("监视点%d发生了变化\n", i);
        IFDEF(CONFIG_ITRACER,puts(_this->logbuf));
        data_pre[i] = data_new[i];
      }
    }
  }
}
#endif
//===============================================

// 下面这里是IRINGBUF
//===============================================
#ifdef CONFIG_ITRACE
  #define IRINGBUF_DEEPTH 10
  struct {
    uint8_t now_p;
    uint8_t p;
    char iringbuf[IRINGBUF_DEEPTH][128];
  } IRINGBUF = {0};

  static void print_iringbuf() {
    printf("iringbuf打印\n");
    printf("如果是发生了 HIT BAD TRAP 或者 ABORT, 则--->指向发生问题的指令\n");
    printf("如果是发生了 assert 0 报错的话, 则--->指向发生问题的指令的上一条指令\n");
    for(int i = 0; i < IRINGBUF_DEEPTH; i++) {
      if(i == IRINGBUF.now_p) 
        printf("--->");
      else
        printf(">>>>");
      puts(IRINGBUF.iringbuf[i]);
    }
    printf("\n");
  }
#endif
//===============================================

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  nemu_mem_info.type = 0;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst;
#ifdef CONFIG_ISA_x86
  for (i = 0; i < ilen; i ++) 
#else
  {
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
  // 这里也是IRINGBUF部分的代码
  //===============================================
  IRINGBUF.now_p = IRINGBUF.p;
  strcpy(IRINGBUF.iringbuf[IRINGBUF.p], s->logbuf);
  if(IRINGBUF.p < IRINGBUF_DEEPTH - 1)
    IRINGBUF.p++;
  else
    IRINGBUF.p = 0;
  //===============================================
  }
#endif
}

static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    IFDEF(CONFIG_WATCHPOINT, monitor_check(&s));
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
  // 下面这里是IRINGBUF
  //===============================================
  IFDEF(CONFIG_ITRACE,print_iringbuf());
  //===============================================
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
#ifdef CONFIG_DTRACE
      extern char D_name_buf[10];
      extern int  D_count;
      dtracer_write("调用 %s , 次数为 %d\n", D_name_buf, D_count);
#endif
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // 下面这里是IRINGBUF
      //===============================================
      IFDEF(CONFIG_ITRACE,if(nemu_state.state == NEMU_ABORT || nemu_state.halt_ret != 0)
      print_iringbuf());
      //===============================================
      // fall through
    case NEMU_QUIT: statistic();
  }
}
