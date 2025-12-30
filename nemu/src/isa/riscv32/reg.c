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

#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  	printf("寄存器状态:\n");
	int i;
	for(i = 0; i < 32; i++){
		printf("%-8s \t 0x%-8x \t %-8u\n", regs[i], cpu.gpr[i], cpu.gpr[i]);
	}
	printf("\n%-8s \t 0x%-8x \t %-8x\n", "pc", cpu.pc, cpu.pc);
}

word_t isa_reg_str2val(const char *s, int *success) {
	char hex_str[11];
	int value;
	if(strcmp(s, "$0") == 0){
		//printf("%-8s \t 0x%-8x \t %-8u\n", regs[0], cpu.gpr[0], cpu.gpr[0]);
		*success = 16;
		return cpu.gpr[0];
	}
	if(strcmp(s, "$pc") == 0){
		//printf("%-8s \t 0x%-8x \t %-8u\n", "pc", cpu.pc, cpu.pc);
		*success = 16;
		return cpu.pc;
	}
	char s_str[32];
	strncpy(s_str, s+1, sizeof(s) - 1);
	for(int i = 1; i < 32; i++){
		if(strcmp(s_str, regs[i]) == 0){
			//printf("%-8s \t 0x%-8x \t %-8u\n", regs[i], cpu.gpr[i], cpu.gpr[i]);
			*success = 16;
			return cpu.gpr[i];
		}
	}
	snprintf(hex_str, sizeof(hex_str), "0x%08X", value);
	*success = false;
	return 0;
}
