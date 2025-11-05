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
#include <watchpoint.h>
#include <breakpoint.h>
#include <ftrace.h>
#include <fmt-def.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10000001
#define IRINGBUF_SIZE 20
#define MTRACER_SIZE 1000

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;
extern int is_batch_mode;
extern uint64_t icache_hit;
extern uint64_t icache_miss;
struct{
  uint32_t inst[IRINGBUF_SIZE];
  word_t pc[IRINGBUF_SIZE];
  uint32_t head;
}iringbuf = {{0}, {0} ,0};




void device_update();
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
void print_iringbuf();
void pc_trace(word_t pc);
void pc_trace_close();
void btrace_close();

#ifdef CONFIG_ITRACE
void print_iringbuf(){
  char logbuf[64];
  for(int i = 0; i < IRINGBUF_SIZE && iringbuf.inst[i] != 0; i++){
    //printf("0x%08x\n", iringbuf.inst[i]);
    disassemble(logbuf, 64, iringbuf.pc[i] , (uint8_t*)(&(iringbuf.inst[i])), 4);

    if( iringbuf.head == 0 ? i == IRINGBUF_SIZE - 1 : i == iringbuf.head - 1)
      printf("--> ");
    else
      printf("    ");
    printf("0x" FMT_WORD_HEX_WIDTH ":    ", iringbuf.pc[i]);
    
    for(int j = 3; j >= 0; j--){
      printf("%02x ", ((uint8_t*)&iringbuf.inst[i])[j]);
    }
   
    

    printf("%s\n", logbuf);
  }
}

#endif

#if defined(CONFIG_TRACE) || defined(CONFIG_DIFFTEST)
static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));

  if(!is_batch_mode){
    scan_watchpoint();
    scan_breakpoint(dnpc);
  }
}
#endif

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  IFDEF(CONFIG_FTRACE, ftrace_func_call(s->pc,s->dnpc, s->isa.inst.val));

#ifdef CONFIG_ITRACE
  iringbuf.inst[iringbuf.head] = s->isa.inst.val;
  iringbuf.pc[iringbuf.head++] = s->pc;
  iringbuf.head = iringbuf.head % IRINGBUF_SIZE;
#endif 

  cpu.pc = s->dnpc;
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
  
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
#endif
}

 void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    IFDEF(CONFIG_PC_TRACE, pc_trace(cpu.pc));
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
#if defined(CONFIG_TRACE) || defined(CONFIG_DIFFTEST)
    trace_and_difftest(&s, cpu.pc);
#endif
    if (nemu_state.state != NEMU_RUNNING) break;
    #ifndef CONFIG_IGNORE_DEVICE_UPDATE
    IFDEF(CONFIG_DEVICE, device_update());
    #endif // !CONFIG_IGNORE_DEVICE_UPDATE
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
  if(icache_hit+icache_miss != 0){
    Log("ICache hit rate = %lf", (double)icache_hit / (icache_hit + icache_miss));}
}

void assert_fail_msg() {
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

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
#ifdef CONFIG_ITRACE
        if((nemu_state.state == NEMU_END && nemu_state.halt_ret != 0) ||
          nemu_state.state == NEMU_ABORT) 
            print_iringbuf();
#endif // CONFIG_ITRACE
    
      // fall through
    case NEMU_QUIT:  pc_trace_close(); btrace_close(); statistic();
  }
}
