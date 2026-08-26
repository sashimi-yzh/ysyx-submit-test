#include "common.h"
#include "trace.h"
#include "cpu.h"
#include "sdb.h"

#ifdef CONFIG_FTRACE_ENABLE
symtab_t *funsymtab=NULL;
ftracer_stack_t  ftracer_stack={.depth=0, .is_ftrace=false, .symtab_size=0, .stack=NULL};
ftrace_log_t ftrace_log={0};
#endif


void mtrace(int addr, char wmask, int sdata){
#ifdef CONFIG_MTRACE_ENABLE
    if(!(addr >= CONFIG_MTRACE_RANGE_LEFT && addr <= CONFIG_MTRACE_RANGE_RIGHT)) return;
    static uint32_t laddr=0,lpc=0;
    if(addr == laddr && cpu.pc == lpc) return;
    laddr = addr; lpc = cpu.pc;
    if(wmask == 0){//READ
        Log("MTrace: Read memory [" FMT_WORD "] = " FMT_WORD " at pc = " FMT_WORD , addr, MEM(addr), cpu.dnpc);
    }else{         //WRITE
        Log("MTrace:Write memory [" FMT_WORD "] : " FMT_WORD " -> " FMT_WORD " @mask[0x%04x] at pc = " FMT_WORD , addr, sdata, MEM(addr), wmask, cpu.dnpc);
    }              
#endif
}

void dtrace(int addr, bool isWrite, int data){
#ifdef CONFIG_DTRACE_ENABLE
    static uint32_t laddr=0,lpc=0,ldata=0;
    static bool lisWrite=0;
    if(addr == laddr && cpu.pc == lpc && data == ldata && isWrite == lisWrite) return;
    laddr = addr; lpc = cpu.pc; ldata = data; lisWrite = isWrite;
    if(!isWrite){//READ
        Log("DTrace: Read device %s[" FMT_WORD "] = " FMT_WORD " at pc = " FMT_WORD , get_device_name(addr), addr, data, cpu.dnpc);
    }else{         //WRITE
        Log("DTrace:Write device %s[" FMT_WORD "]<- " FMT_WORD " at pc = " FMT_WORD , get_device_name(addr), addr, data, cpu.dnpc);
    }              
#endif
}

void itrace(){
    char *p = cpu.logbuf;
    p += snprintf(p, sizeof(cpu.logbuf), "[%08ld]" FMT_WORD ":", cpu.counter_inst, cpu.tb_FINAL_pc);
    uint32_t inst_t = pmem_read(cpu.tb_FINAL_pc);
    uint8_t *inst = (uint8_t *)&inst_t;
    for (int i = CONFIG_INST_LEN - 1; i >= 0; i --) {
        p += snprintf(p, 4, " %02x", inst[i]);
    }
    memset(p, ' ', 1);
    p ++;
    disassemble(p, cpu.logbuf + sizeof(cpu.logbuf) - p, cpu.tb_FINAL_pc, (uint8_t *)&inst_t, CONFIG_INST_LEN);
    #ifdef CONFIG_ITRACE_PRINT
    Log("ITrace: %s",cpu.logbuf);
    #endif
}

void trace_and_difftest(){
#ifdef CONFIG_ITRACE_ENABLE
    itrace();
#endif
#ifdef CONFIG_WATCHPOINT_ENABLE
    for(int i=0;i<32;i++){
        if(1==diff_wp(i)){
            WP *wp=find_wp(i);
            bool success=true;
            uint32_t nval=expr(wp->expr,&success);
            printf("watchpoint[%d]\t%u\t->\t%u\t%s\n",i,wp->val,nval,wp->expr);
            wp->val=nval;
            cpu.state=NPC_STOP;
        }
    }
#endif
#ifdef CONFIG_FTRACE_ENABLE

    if(((cpu.tb_FINAL_inst & 0x7f) == 0x6f) || (((cpu.tb_FINAL_inst & 0x7f) == 0x67) && (((cpu.tb_FINAL_inst >> 12) & 0x07) == 0b000))){
        //jal or jalr
        func_trace(&cpu);
    }
#endif
#ifdef CONFIG_DIFFTEST_ENABLE
    extern void difftest_step(uint32_t pc, uint32_t npc,uint32_t mem_addr);
    difftest_step(cpu.tb_FINAL_pc, cpu.tb_FINAL_npc, cpu.mem_access_addr);
#endif
}

#ifdef CONFIG_FTRACE_ENABLE
void func_trace(CPUState *s){
  if(!funsymtab || !ftracer_stack.is_ftrace)  return;
  CPUState start={.tb_FINAL_pc=RESET_VECTOR,.tb_FINAL_npc=RESET_VECTOR};
  if(s==NULL) s=&start;
  //PUSH
  for(int i=0;i<ftracer_stack.symtab_size;i++){
    if(s->tb_FINAL_npc == funsymtab[i].start_add){
      ftracer_t stack_frame = {.src_pc = s->tb_FINAL_pc, .dst_pc = s->tb_FINAL_npc, .dst_func = funsymtab + i,};
      // Log("Push STACK (pc=%x)(func=%s) depth=%d",stack_frame.dst_pc,stack_frame.dst_func->name,ftracer_stack.depth+1);
      ftracer_push(stack_frame);
      char S[256]={0};
      sprintf(S+strlen(S),"[%010lu]0x%08x:FUNTRACER: ", s->counter_inst, s->tb_FINAL_pc);
      for(int i=1;i<ftracer_stack.depth;i++)  sprintf(S+strlen(S),"| ");
      sprintf(S+strlen(S),"call [%s@0x%08x]\n",stack_frame.dst_func->name,stack_frame.dst_func->start_add);
      ftracer_write_log(S);
      return;
    }
  }

  //POP
  for(int i=ftracer_stack.depth-1;i>=0;i--){
    if(s->tb_FINAL_npc == ftracer_stack.stack[i].src_pc + 4){
      //is RETURN
      char this_name[64]={0};
      for(int j=0;j<ftracer_stack.symtab_size;j++){//FIND NAME
        if(IN_FUNCRANGE(s->tb_FINAL_pc,funsymtab[j])){
          strcpy(this_name,funsymtab[j].name);
          break;
        }
      }
      if(this_name[0]=='\0') strcpy(this_name,"[**Cannot find function name**]");
      int ret_depth = ftracer_stack.depth - i;

      for(int n=0;n<ret_depth;n++){ //POP COUNT
        char S[256]={0};
        sprintf(S+strlen(S),"[%010lu]0x%08x:FUNTRACER: ", s->counter_inst,s->tb_FINAL_pc);
        for(int k=1;k<ftracer_stack.depth;k++)  sprintf(S+strlen(S),"| ");
        sprintf(S+strlen(S),"ret [%s<-%s]\n",ftracer_stack.stack[ftracer_stack.depth-2].dst_func->name,this_name);
        ftracer_write_log(S);
        //Log("Pop  STACK (pc=%08x)(func:%s <- %s) depth=%d",s->tb_FINAL_pc,ftracer_stack.stack[ftracer_stack.depth-2].dst_func->name,this_name,ftracer_stack.depth-1);
        ftracer_pop();
      }
      return;
    }
  }
  return;
}


int ftracer_push(ftracer_t stack_frame){
  ftracer_stack.depth++;
  ftracer_t *tpr = (ftracer_t*)realloc(ftracer_stack.stack, sizeof(ftracer_t)*ftracer_stack.depth);
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
    ftrace_log.buf=(char*)malloc(128);
    if(!ftrace_log.buf){Log("ERROR fireset malloc ftracer_log_buffer!.");return;}
    memset(ftrace_log.buf,0,128);
    ftrace_log.alloc=128;
  }
  while(strlen(s)>ftrace_log.alloc-ftrace_log.len-1){
    char *tpr=(char*)realloc(ftrace_log.buf,ftrace_log.alloc+128);
    if(!tpr){Log("ERROR malloc ftracer_log_buffer!.");return;}
    ftrace_log.alloc+=128;
    ftrace_log.buf=tpr;
  }
  strcat(ftrace_log.buf,s);
  ftrace_log.len=strlen(ftrace_log.buf);
}
#endif