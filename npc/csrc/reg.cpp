#include "common.h"
#include "debug.h"
#include "macro.h"
#include "utils.h"
#include "include.h"

regfile cpu;

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
	int i=32;
	//printf("%d",cpu.gpr[1]);
	for(;i>0;i--) {
		printf("%s\t%x\n",regs[32-i],cpu.gpr[32-i]);
	}
  printf("pc\t%x\n",cpu.pc);
  printf("mstatus\t%x\n",cpu.csr_mstatus);
  printf("mcause\t%x\n",cpu.csr_mcause);
  printf("mepc\t%x\n",cpu.csr_mepc);
  printf("mtvec\t%x\n",cpu.csr_mtvec);

}

word_t isa_reg_str2val(const char *s, bool *success) {
  bool flag=0;
  int i=32;
  uint32_t value=0;
  char reg1[10]={'x','\0'};
  //printf("%s\n",reg1);
  //sscanf(s,"%s",reg1);
  strcpy(reg1,s);
  //printf("%s\n",reg1);
  for(;i>0;i--) {
    if(strcmp(regs[32-i], reg1) == 0){
      flag=1;
      //printf("%s\t%x\n",regs[32-i],cpu.gpr[32-i]);
      value=cpu.gpr[32-i];      
    }	
	}

  if(strcmp("pc", reg1) == 0) {
    flag=1;
    //printf("%s\t%x\n","pc",cpu.pc);
    value=cpu.pc; 
  }

  if(!flag) {
    *success=0;
    assert(0);
  }
  return value;
}

bool checkregs(regfile *ref, regfile *dut) {
    bool check = true;
  //if(ref->pc != dut->pc){
  //  printf("difftest error: ");
  //  printf("next reg pc is diff: ref = 0x%x, dut = 0x%x\n",ref->pc,dut->pc);
  //  check = false;
  //}
  for (int i = 0; i < 16; i++) {
    if(ref->gpr[i] != dut->gpr[i]){
      printf("difftest error at nextpc = 0x%x, ",dut->pc);
      printf("reg %s is diff: ref = 0x%x, dut = 0x%x\n",regs[i],ref->gpr[i],dut->gpr[i]);
      check = false;
    }
  }

  if(ref->csr_mepc != dut->csr_mepc){
    printf("difftest error: ");
    printf("csr_mepc is diff: ref = 0x%x, dut = 0x%x\n",ref->csr_mepc,dut->csr_mepc);
    check = false;
  }
  if(ref->csr_mstatus != dut->csr_mstatus){
    printf("difftest error: ");
    printf("csr_mstatus is diff: ref = 0x%x, dut = 0x%x\n",ref->csr_mstatus,dut->csr_mstatus);
    check = false;
  }
  if(ref->csr_mcause != dut->csr_mcause){
    printf("difftest error: ");
    printf("csr_mcause is diff: ref = 0x%x, dut = 0x%x\n",ref->csr_mcause,dut->csr_mcause);
    check = false;
  }
  if(ref->csr_mtvec != dut->csr_mtvec){
    printf("difftest error: ");
    printf("csr_mtvec is diff: ref = 0x%x, dut = 0x%x\n",ref->csr_mtvec,dut->csr_mtvec);
    check = false;
  }
  return check;

}

void print_regs(){
  printf("dut pc = 0x%x\n",cpu.pc);
  for (int i = 0; i < ARRLEN(regs); i++) {
    printf("dut reg %3s = 0x%x\n",regs[i],cpu.gpr[i]);
  }

}