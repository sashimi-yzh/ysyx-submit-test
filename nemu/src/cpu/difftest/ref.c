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


__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {//同步内存数据
	//printf("difftest_memcpy\n");
	if (direction == DIFFTEST_TO_DUT) {//从REF（NEMU）复制到DUT（NPC）
    	for (int i = 0; i < n; i++) {
            *((uint32_t *)buf + i*4) = paddr_read(addr + i*4, 4);
    	}
    } else if(direction == DIFFTEST_TO_REF){//从DUT（NPC）复制到REF（NEMU）
		//printf("n=0x%lx\n",n);
    	for (int i = 0; i*4 < n; i++) {
            paddr_write(addr + i*4, 4, *((uint32_t *)buf + i) );
			//printf("ref_peme[0X%08X]=0X%08X\n", addr + i * 4, paddr_read(addr + i * 4, 4));
    	}
	}   
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {//同步寄存器数据
	//printf("difftest_regcpy\n");
	CPU_state *gpr_dut = (CPU_state *)dut;
	if (direction == DIFFTEST_TO_DUT) {//从REF（NEMU）复制到DUT（NPC）
    	for (int i = 0; i < 32; i++) {
      		gpr_dut->gpr[i] = cpu.gpr[i];
    	}
    	gpr_dut->pc = cpu.pc;
  	} else if (direction == DIFFTEST_TO_REF) {//从DUT（NPC）复制到REF（NEMU）
    	for (int i = 0; i < 32; i++) {
      		cpu.gpr[i] = gpr_dut->gpr[i];
    	}
    	cpu.pc = gpr_dut->pc;
	}
	
}

__EXPORT void difftest_exec(uint64_t n) {
	//printf("difftest_exec\n");
	cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
	assert(0);
}

__EXPORT void difftest_init(int port) {
	void init_mem();
	init_mem();
	/* Perform ISA dependent initialization. */
	init_isa();
}
