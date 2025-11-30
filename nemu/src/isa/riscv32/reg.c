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

#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"
#ifndef CONFIG_RVE
	,
	"a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
#endif
};

void isa_reg_display() {
	/***打印寄存器***/
	int i;
	printf("The value of the register:\n");
	for(i = 0; i < 4; i++) {
		printf("%s:0x%08x\t", regs[i], cpu.gpr[i]);
	}
	printf("\n");
	for(i = 4; i < 8; i++) {
		printf("%s:0x%08x\t", regs[i], cpu.gpr[i]);
	}
	printf("\n");
	for(i = 8; i < 12; i++) {
		printf("%s:0x%08x\t", regs[i], cpu.gpr[i]);
	}
	printf("\n");
	for(i = 12; i < 16; i++) {
		printf("%s:0x%08x\t", regs[i], cpu.gpr[i]);
	}
	printf("\n");
#ifndef CONFIG_RVE
	for(i = 16; i < 20; i++) {
		printf("%s:0x%08x\t", regs[i], cpu.gpr[i]);
	}
	printf("\n");
	for(i = 20; i < 24; i++) {
		printf("%s:0x%08x\t", regs[i], cpu.gpr[i]);
	}
	printf("\n");
	for(i = 24; i < 28; i++) {
		printf("%s:0x%08x\t", regs[i], cpu.gpr[i]);
	}
	printf("\n");
	for(i = 28; i < 32; i++) {
		printf("%s:0x%08x\t", regs[i], cpu.gpr[i]);
	}
	printf("\n");
#endif
	printf("%s:0x%08x\n", "pc", cpu.pc);
	printf("%s:0x%08x\n", "mepc", cpu.csr.mepc);
	printf("%s:0x%08x\n", "mstatus", cpu.csr.mstatus);
	printf("%s:0x%08x\n", "mcause", cpu.csr.mcause);
	printf("%s:0x%08x\n", "mtvec", cpu.csr.mtvec);
}

word_t isa_reg_str2val(const char *s, bool *success) {
#ifndef CONFIG_RVE
  for(int i = 0; i < 32; i ++){
#else
	for(int i = 0; i < 16; i ++){
#endif
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
  success = false;
	printf("Invalid reg name\n");
  return 0;
}
