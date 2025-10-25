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
#include <stdio.h>
int rec = 0;
word_t isa_raise_intr(word_t NO, vaddr_t epc)
{
	// printf("raise:beg:mstatus = %x, mepc = %x, mcause = %d\n", cpu.mstatus, epc, NO);
	word_t MIE = (cpu.mstatus >> 3) & 1;
	cpu.mstatus &= ~(1 << 3);
	cpu.mstatus &= ~(1 << 7);
	cpu.mstatus |= MIE << 7; // MIE = MIE
	// printf("mstatus set to %x,there should not be interrupt\n", cpu.mstatus);
	cpu.mepc = epc;
	// if (cpu.priv == 3)
	// 	cpu.mcause = 11;
	// if (cpu.priv == 0)
	// 	cpu.mcause = 8;
	cpu.mcause = NO;

	IFDEF(CONFIG_ETRACE, printf("error %d at %x\n", cpu.mcause, epc));
	return cpu.mtvec;
}

word_t isa_query_intr()
{
	// if (cpu.mstatus != 0x1800)
	// 	printf("cpu.intr = %d, mstatus = %x\n", cpu.intr, cpu.mstatus);
	if (cpu.intr && (cpu.mstatus & (1 << 3)))
	{
		cpu.intr = false;
		// printf("enabled interrupt, mstatus = %x\n", cpu.mstatus);
		return IRQ_TIMER;
	}
	return INTR_EMPTY;
}
