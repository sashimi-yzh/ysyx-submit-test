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
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>
#include <string.h>
// DiffTest是处理器调试的一大杀手锏, 在为NPC实现更多指令之前, 为其搭建DiffTest是一个明智的选择. 在这里, DUT是NPC, 而REF则选择NEMU. 为此, 你需要
#define DIFFTEST_TO_REF 1
#define DIFFTEST_TO_DUT 0
// 在nemu/src/cpu/difftest/ref.c中实现DiffTest的API, 包括difftest_memcpy(), difftest_regcpy()和difftest_exec(). 此外difftest_raise_intr()是为中断准备的, 目前暂不使用
void copy_regs(void *dut);
void regs_copy(void *dut);
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction)
{
	if (direction == DIFFTEST_TO_REF)
	{
		memcpy(guest_to_host(0x80000000), buf, n);
		return;
	}
	assert(direction == DIFFTEST_TO_DUT);
}

__EXPORT void difftest_regcpy(void *dut, bool direction)
{
	if (direction == DIFFTEST_TO_REF)
	{
		copy_regs(dut);
		return;
	}
	if (direction == DIFFTEST_TO_DUT)
	{
		regs_copy(dut);
		return;
	}
}

__EXPORT void difftest_exec(uint64_t n)
{
	cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO)
{
	assert(0);
}

__EXPORT void difftest_init(int port)
{
	void init_mem();
	init_mem();
	/* Perform ISA dependent initialization. */
	init_isa();
}
