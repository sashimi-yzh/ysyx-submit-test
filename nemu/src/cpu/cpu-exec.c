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
#include "macro.h"
#include "utils.h"
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
static char iringbuf[16][128]={};
static int iringbuf_index=0;
static char ftrace_buf[1024][128]={};
static int ftrace_cnt=0;
static int depth=0;
void device_update();
static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif

    IFDEF(CONFIG_ITRACE,strcpy(iringbuf[iringbuf_index],_this->logbuf);
        iringbuf_index=(iringbuf_index+1)%16;)
    IFNDEF(CONFIG_ITRACE,sprintf(iringbuf[iringbuf_index],"%08x",_this->isa.inst);
            iringbuf_index=(iringbuf_index+1)%16;)

    IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
#ifdef CONFIG_WATCHPOINT
    if(Scan_WP()&&(nemu_state.state==NEMU_RUNNING)){
        nemu_state.state=NEMU_STOP;    
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
void iringbuf_print(){
    int i;
    int index;
    printf("Instruction Ring Buffer Trace:\n");
    for(i=0;i<16;i++){
        index=(iringbuf_index+i)%16;
        if(i==15){//这个下标指向下一个
            printf(" --> %s\n",iringbuf[index]);
        }else {
            printf("     %s\n",iringbuf[index]);
        }
    }
}
void ftrace_record(vaddr_t pc,vaddr_t dnpc,int is_return){
    int i;int index1=-1,index2=-1;
    char space[32];
    if(!is_return) depth++;
    int space_len=depth>31?31:depth;
    if(is_return) {depth--; if(depth<0) depth=0;}
    memset(space,' ',space_len);
    space[space_len]='\0';
    for(i=0;i<func_cnt;i++){
        if(pc>=func_list[i].low&&pc<=func_list[i].high){
            index1=i;break;
        }
    }
    for(i=0;i<func_cnt;i++){
        if(dnpc>=func_list[i].low&&dnpc<=func_list[i].high){
            index2=i;break;
        }
    }
    if(is_return){
        sprintf(ftrace_buf[ftrace_cnt],FMT_PADDR ":%sret [%s] to [%s]",pc,space,index1>=0?func_list[index1].name:"???",index2>=0?func_list[index2].name:"???"); 
    }else{
        sprintf(ftrace_buf[ftrace_cnt],FMT_PADDR ":%scall [%s@" FMT_PADDR "], from [%s]",pc,space,index2>=0?func_list[index2].name:"???",dnpc,index1>=0?func_list[index1].name:"???");  
    }
    ftrace_cnt=(ftrace_cnt+1)%1024;
}
void ftrace_print(){
    int i;
    for(i=0;i<ftrace_cnt;i++){
        printf("%s\n",ftrace_buf[i]);
    }
}
/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  //g_print_step = true;
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
        if(!(nemu_state.state==NEMU_END&&nemu_state.halt_ret==0)){
            iringbuf_print();
        }
      // fall through
    case NEMU_QUIT: statistic();
  }
}
