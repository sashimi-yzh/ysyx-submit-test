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
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

__EXPORT void difftest_memcpy(paddr_t addr, uint8_t *buf, size_t n, bool direction) {
  if(direction == DIFFTEST_TO_REF) {//from dut im to ref(nemu) im
		for(int i = 0; i < n; i ++) {	
			paddr_write(addr, 1, buf[i]);
			addr ++;
		}
	}
	else {
		for(int i = 0; i < n; i ++) {
			buf[i] = paddr_read(addr, 1);
			addr ++;
		}
	}
}

__EXPORT void difftest_regcpy(CPU_state *dut, bool direction) {
  if(direction == DIFFTEST_TO_REF) {//from dut regs to ref(nemu)
		for(int i = 0; i < 32; i ++) {
			cpu.gpr[i] = dut->gpr[i];//结构体实现
		}
		cpu.pc = dut->pc;
		cpu.csr.mepc = dut->csr.mepc;
		cpu.csr.mstatus = dut->csr.mstatus;
		cpu.csr.mcause = dut->csr.mcause;
		cpu.csr.mtvec = dut->csr.mtvec;
	}
	else {
		for(int i = 0; i < 32; i ++) {
			dut->gpr[i] = cpu.gpr[i];
		}
		dut->pc = cpu.pc;
		dut->csr.mepc = cpu.csr.mepc;
		dut->csr.mstatus = cpu.csr.mstatus;
		dut->csr.mcause = cpu.csr.mcause;
		dut->csr.mtvec = cpu.csr.mtvec;
	}
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {//中断，暂时不用
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
