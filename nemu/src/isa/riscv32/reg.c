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
	"s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

void isa_reg_display()
{
	printf("pc= %u\t0x%x\n", cpu.pc, cpu.pc);
	for (int i = 0; i < sizeof(regs) / sizeof(regs[0]); i++)
	{
		printf("%s= %010u\t0x%08x\t\t", reg_name(i), gpr(i), gpr(i));
		if (i % 2 == 1)
			printf("\n");
	}
}

void copy_regs(void *dut)
{
	uint32_t *reg = (uint32_t *)dut;
	// pc
	cpu.pc = reg[0];
	for (int i = 0; i < 16; i++)
	{
		cpu.gpr[i] = reg[i + 1];
	}
}
void regs_copy(void *dut)
{
	uint32_t *reg = (uint32_t *)dut;
	reg[0] = cpu.pc;
	for (int i = 0; i < 16; i++)
	{
		reg[i + 1] = gpr(i);
	}
}
word_t isa_reg_str2val(const char *s, bool *success)
{
	int i = 0;
	if (success != NULL)
		*success = false;
	if (strcmp(s, "pc") == 0)
	{
		*success = true;
		return cpu.pc;
	}
	for (; i < sizeof(regs) / sizeof(regs[0]); i++)
	{
		if (strcmp(s, regs[i]) == 0)
		{
			if (success != NULL)
				*success = true;
			break;
		}
	}
	return (*success) ? gpr(i) : 0;
}
