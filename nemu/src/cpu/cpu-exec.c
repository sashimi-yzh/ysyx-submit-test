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
#include <ringbuffer.h>
#include <ftrace.h>

#define INST_STREAM_SIZE 0x10000000

extern FtraceMeta *ftrace_meta;
extern char* inst_stream_file;
static char inst_stream_buf[INST_STREAM_SIZE];
static char* inst_stream_ptr = (char*)inst_stream_buf;

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

// src/monitor/sdb/watchpoint.c
extern bool wps_diff();

extern RingBuffer *log_buff;

void log_inst_stream(uint32_t addr, uint32_t inst, char *name){
  if (inst_stream_ptr >= inst_stream_buf + INST_STREAM_SIZE) 
    panic("inst stream buffer overflow");

  inst_stream_ptr += snprintf(inst_stream_ptr, INST_STREAM_SIZE,"    " FMT_WORD "," FMT_WORD ",%s\n", addr,inst,name);
}

void dump_inst_stream(){
    FILE* f = fopen(inst_stream_file, "w");
    fwrite(inst_stream_buf, inst_stream_ptr - inst_stream_buf, 1, f);
    fclose(f);
}

void itrace_once(Decode*s) {
  // 32 match inst name in capstone define
  #ifdef CONFIG_ITRACE
  char inst_name[32];
  char *p = s->logbuf;
  p +=  (nemu_state.state != NEMU_ABORT) ? 
      snprintf(p, LOG_BUFSIZE,"    " FMT_WORD ":", s->pc):
      snprintf(p, LOG_BUFSIZE," -->" FMT_WORD ":", s->pc);
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
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte,char* inst);
  disassemble(p, s->logbuf + LOG_BUFSIZE - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen,inst_name);
  int len = strlen(s->logbuf);
  memset(s->logbuf+len,' ',ITRACE_SIZE-len);
  s->logbuf[ITRACE_SIZE-1] = '\n';
  if(RingBuffer_available(log_buff)<ITRACE_SIZE){
    RingBuffer_commit_read(log_buff,ITRACE_SIZE);
  }
  Assert(ITRACE_SIZE>(len+1),"length of itrace excceed\n");
  RingBuffer_put(log_buff,s->logbuf,ITRACE_SIZE);
  memset(s->logbuf,0,ITRACE_SIZE);
  log_inst_stream(s->pc,s->isa.inst,inst_name);
  #endif

#ifdef CONFIG_FTRACE
    ftrace_message(s->pc,s->dnpc,inst_name);
#endif
}


static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc)); 

#ifdef CONFIG_ITRACE_COND
  itrace_once(_this);
  char itrace_log [LOG_BUFSIZE];
  // print the invalid inst
  if (nemu_state.state!=NEMU_RUNNING) {
    RingBuffer_get(log_buff,itrace_log,LOG_BUFSIZE);
    log_write("%s", itrace_log); }
#endif
  // if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(temp_buf)); }
#ifdef CONFIG_WATCHPOINT
  if (nemu_state.state != NEMU_END && wps_diff()){

      nemu_state.state = NEMU_STOP;
  }
#endif
#ifdef CONFIG_ETRACE
  if (_this->is_exception==1) display_exception_info();
#endif
}

static void exec_once(Decode *s, vaddr_t pc) {
  cpu.mem_access = (mem_access_t){0, 0, 0, 0};
  s->pc = pc;
  s->snpc = pc;
  IFDEF(CONFIG_ETRACE, s->is_exception = 0);
  isa_exec_once(s);
  cpu.pc = s->dnpc;
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
      if (inst_stream_file) {
        dump_inst_stream();
      }
      // fall through
    case NEMU_QUIT: statistic();
  }
}
