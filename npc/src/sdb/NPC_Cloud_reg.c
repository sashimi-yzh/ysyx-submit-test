#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "npc.h"
#include "sdb.h"

const char *regs[32] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  	printf("寄存器状态:\n");
	for(int i = 0; i < 32; i++){
		printf("gpr[%02d]:%s \t 0X%08X \t %08u\n", i, regs[i], npc.gpr[i], npc.gpr[i]);
	}
	printf("\n%s \t 0X%08X \t %08u\n", "pc", npc.dnpc, npc.dnpc);
}

uint32_t isa_reg_str2val(const char *s, int *success) {
	char hex_str[11];
	int value;
	if(strcmp(s, "$0") == 0){
		//printf("%-8s \t 0x%-8x \t %-8u\n", regs[0], cpu.gpr[0], cpu.gpr[0]);
		*success = 16;
		return npc.gpr[0];
	}
	if(strcmp(s, "$pc") == 0){
		//printf("%-8s \t 0x%-8x \t %-8u\n", "pc", cpu.pc, cpu.pc);
		*success = 16;
		return npc.dnpc;
	}
	char s_str[32];
	strncpy(s_str, s+1, sizeof(s) - 1);
	for(int i = 1; i < 32; i++){
		if(strcmp(s_str, regs[i]) == 0){
			//printf("%-8s \t 0x%-8x \t %-8u\n", regs[i], cpu.gpr[i], cpu.gpr[i]);
			*success = 16;
			return npc.gpr[i];
		}
	}
	snprintf(hex_str, sizeof(hex_str), "0x%08X", value);
	*success = false;
	return 0;
}
