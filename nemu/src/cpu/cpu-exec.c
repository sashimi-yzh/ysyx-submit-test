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
#include <ftrace.h>
#include "../src/monitor/sdb/sdb.h"
#include <memory/paddr.h>
/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

#ifdef CONFIG_FTRACE
extern symtab_t *funsymtab;
extern ftracer_stack_t  ftracer_stack;
ftrace_log_t ftrace_log={0};
#endif

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = true;
#ifdef CONFIG_ITRACE_RING
void print_ring_inst_buf(void);
static char ring_inst_buf[CONFIG_ITRACE_RING_MAX][128]={0};

void print_ring_inst_buf(){
  printf("=============================================\n");
  printf("Instruction ring tracer:\n");
  for(int i=0;i<CONFIG_ITRACE_RING_MAX;i++){
    if(ring_inst_buf[i][0]=='\0') continue;
    printf("=%s\n",ring_inst_buf[i]);
  }
  printf("=============================================\n");
}
#endif

void device_update();


#ifdef CONFIG_TRACE_FILE_LOG
static bool itrace_log_init = false;
FILE *itrace_log_fp = NULL;
void init_itrace_log(){
    if (itrace_log_fp == NULL) {
      FILE *fp = fopen("itrace.log", "w");
      Assert(fp, "Can not open '%s'", "./itrace.log");
      itrace_log_fp = fp;
    }
    Log("ITrace log is written to %s", "./itrace.log");
    itrace_log_init = true;
}
static bool btrace_log_init = false;
FILE *btrace_log_fp = NULL;
void init_btrace_log(){
    if (btrace_log_fp == NULL) {
      FILE *fp = fopen("btrace.log", "w");
      Assert(fp, "Can not open '%s'", "./btrace.log");
      btrace_log_fp = fp;
    }
    Log("BTrace log is written to %s", "./btrace.log");
    btrace_log_init = true;
}
#endif
void write_btrace_log(uint32_t pc,uint32_t tar,uint32_t is_jump){
#ifdef CONFIG_TRACE_FILE_LOG
  if(!btrace_log_init) init_btrace_log();
  fwrite(&pc,  sizeof(uint32_t), 1, btrace_log_fp);
  fwrite(&tar, sizeof(uint32_t), 1, btrace_log_fp);
  fwrite(&is_jump, sizeof(uint32_t), 1, btrace_log_fp);
#endif
}

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) {
    log_write("%s\n", _this->logbuf);
    IFDEF(CONFIG_TRACE_FILE_LOG, do{if(!itrace_log_init) init_itrace_log();fwrite(&_this->pc, sizeof(_this->pc), 1, itrace_log_fp);}while(0));
    // 写入字节 _this->pc
  }
#endif
  if (g_print_step) {
    IFDEF(CONFIG_ITRACE, puts(_this->logbuf));
  }

#ifdef CONFIG_ITRACE_RING
  if(CONFIG_ITRACE_RING_MAX>0){
    for(int i=0;i<CONFIG_ITRACE_RING_MAX-1;i++){
      memcpy(ring_inst_buf[i],ring_inst_buf[i+1],128);
    }
    sprintf(ring_inst_buf[CONFIG_ITRACE_RING_MAX-1],"%s",_this->logbuf);
  }
#endif

  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
#ifdef CONFIG_WATCHPOINT
#ifndef CONFIG_TARGET_AM
  for(int i=0;i<32;i++){
    if(1==diff_wp(i)){
      WP *wp=find_wp(i);
      bool success=true;
      uint32_t nval=expr(wp->expr,&success);
      printf("watchpoint[%d]\t%u\t->\t%u\t%s\n",i,wp->val,nval,wp->expr);
      wp->val=nval;
      nemu_state.state=NEMU_STOP;
      IFDEF(CONFIG_ITRACE_RING,print_ring_inst_buf(););
    }
  }
#endif
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
  isa_reg_display(cpu);
#ifdef CONFIG_ITRACE_RING
  print_ring_inst_buf();
#endif
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
      Log("nemu: %s at pc = " FMT_WORD, \
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) : \
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) : \
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))), \
          nemu_state.halt_pc);
      IFDEF(CONFIG_FTRACE,printf("%s",ftrace_log.buf));
#ifdef CONFIG_ITRACE_RING
      print_ring_inst_buf();
#endif
      // fall through
    case NEMU_QUIT: statistic();
  }
}

void func_trace(Decode *s){
#ifdef CONFIG_FTRACE
  if(!funsymtab || !ftracer_stack.is_ftrace)  return;
  Decode start={.pc=RESET_VECTOR,.dnpc=RESET_VECTOR};
  if(s==NULL) s=&start;
  //PUSH
  for(int i=0;i<ftracer_stack.symtab_size;i++){
    if(s->dnpc == funsymtab[i].start_add){
      ftracer_t stack_frame = {.dst_func = funsymtab + i, .dst_pc = s->dnpc, .src_pc = s->pc};
      //Log("Push STACK (pc=%x)(func=%s) depth=%d",stack_frame.dst_pc,stack_frame.dst_func->name,ftracer_stack.depth+1);
      ftracer_push(stack_frame);
      char S[256]={0};
      sprintf(S+strlen(S),"0x%08x:FUNTRACER: ", s->pc);
      for(int i=1;i<ftracer_stack.depth;i++)  sprintf(S+strlen(S),"| ");
      sprintf(S+strlen(S),"call [%s@0x%08x]\n",stack_frame.dst_func->name,stack_frame.dst_func->start_add);
      ftracer_write_log(S);
      return;
    }
  }

  //POP
  for(int i=ftracer_stack.depth-1;i>=0;i--){
    if(s->dnpc == ftracer_stack.stack[i].src_pc + 4){
      //is RETURN
      char this_name[64]={0};
      for(int j=0;j<ftracer_stack.symtab_size;j++){//FIND NAME
        if(IN_FUNCRANGE(s->pc,funsymtab[j])){
          strcpy(this_name,funsymtab[j].name);
          break;
        }
      }
      if(this_name[0]=='\0') strcpy(this_name,"[**Cannot find function name**]");
      int ret_depth = ftracer_stack.depth - i;

      for(int n=0;n<ret_depth;n++){ //POP COUNT
        char S[256]={0};
        sprintf(S+strlen(S),"0x%08x:FUNTRACER: ", s->pc);
        for(int k=1;k<ftracer_stack.depth;k++)  sprintf(S+strlen(S),"| ");
        sprintf(S+strlen(S),"ret [%s<-%s]\n",ftracer_stack.stack[ftracer_stack.depth-2].dst_func->name,this_name);
        ftracer_write_log(S);
        //Log("Pop  STACK (pc=%08x)(func:%s <- %s) depth=%d",s->pc,ftracer_stack.stack[ftracer_stack.depth-2].dst_func->name,this_name,ftracer_stack.depth-1);
        ftracer_pop();
      }
      return;
    }
  }
#endif
  return;
}

#ifdef CONFIG_FTRACE
int ftracer_push(ftracer_t stack_frame){
  ftracer_stack.depth++;
  ftracer_t *tpr = realloc(ftracer_stack.stack, sizeof(ftracer_t)*ftracer_stack.depth);
  if(!tpr) {Log("Cannot realloc ftracer_stack! Stop ftracing.");ftracer_stack.is_ftrace=0;free(ftracer_stack.stack);return 1;}
  ftracer_stack.stack = tpr;
  memcpy(ftracer_stack.stack+ftracer_stack.depth-1, &stack_frame, sizeof(ftracer_t));
  return 0;
}

void ftracer_pop(){
  if(ftracer_stack.depth<=0){
    Log("ERROR POP STACK. Depth<=0");
    return;
  }
  // for(int i=0;i<ftracer_stack.symtab_size;i++){
  //   if(ftracer_stack.stack[ftracer_stack.depth-1].)
  // }
  ftracer_stack.depth--;
  return;
}

void ftracer_write_log(char *s){
  log_write("%s", s);
  if(!ftrace_log.buf){
    ftrace_log.buf=malloc(128);
    if(!ftrace_log.buf){Log("ERROR first malloc ftracer_log_buffer!.");return;}
    memset(ftrace_log.buf,0,128);
    ftrace_log.alloc=128;
  }
  while(strlen(s)>ftrace_log.alloc-ftrace_log.len-1){
    char *tpr=realloc(ftrace_log.buf,ftrace_log.alloc+128);
    if(!tpr){Log("ERROR malloc ftracer_log_buffer!.");return;}
    ftrace_log.alloc+=128;
    ftrace_log.buf=tpr;
  }
  strcat(ftrace_log.buf,s);
  ftrace_log.len=strlen(ftrace_log.buf);
}
#endif

