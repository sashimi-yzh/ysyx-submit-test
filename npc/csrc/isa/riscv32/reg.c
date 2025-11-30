#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./../../include/common.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};
extern CPU_state cpu;

void isa_regs_display() {
	for(int i = 0; i < 32; i ++) {
    printf("%s:0x%08x\t", regs[i], cpu.gpr[i]);
  }
  printf("\n");
	printf("%s:0x%08x\n", "pc", cpu.pc);
	printf("%s:0x%08x\n", "mepc", cpu.csr.mepc);
	printf("%s:0x%08x\n", "mstatus", cpu.csr.mstatus);
	printf("%s:0x%08x\n", "mcause", cpu.csr.mcause);
	printf("%s:0x%08x\n", "mtvec", cpu.csr.mtvec);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  for(int i = 0 ; i < 32 ; i ++){
   	if(strcmp(regs[i], s) == 0){
			return cpu.gpr[i];
			break;
		}
	}
	if(strcmp(s, "pc") == 0) {
		return cpu.pc;
	}
	if(strcmp(s, "mepc") == 0) {
		return cpu.csr.mepc;
	}
	if(strcmp(s, "mstatus") == 0) {
		return cpu.csr.mstatus;
	}
	if(strcmp(s, "mcause") == 0) {
		return cpu.csr.mcause;
	}
	if(strcmp(s, "mtvec") == 0) {
		return cpu.csr.mtvec;
	}
	*success = false;
	printf("Invalid reg name\n");
	return 0;
}

#ifndef CONFIG_SIM_FAST
void isa_gpr_push() {
	for(int i = 0; i < 32; i ++) {
		cpu.gpr[i] = gpr_regs_display(i);
	}
	cpu.csr.mepc = csrs_display(0);
	cpu.csr.mstatus = csrs_display(1);
	cpu.csr.mcause = csrs_display(2);
	cpu.csr.mtvec = csrs_display(3);
}
#endif
