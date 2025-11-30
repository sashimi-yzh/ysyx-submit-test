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
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
	int reg_num = ARRLEN(cpu.gpr);
	for(int i = 0; i < reg_num; i++) {
		if(ref_r->gpr[i] != cpu.gpr[i]) {
			printf("ref.gpr[%d]:%08x != cpu.gpr[%d]:%08x\n", i, ref_r->gpr[i], i, cpu.gpr[i]);
			return false;
		}
	}
	if(ref_r->pc != cpu.pc) {
		printf("ref.pc:%08x != cpu.pc:%08x\n", ref_r->pc, cpu.pc);
		return false;	
	}
	if(ref_r->csr.mepc != cpu.csr.mepc) {
		printf("ref.mepc:%08x != cpu.mepc:%08x\n", ref_r->csr.mepc, cpu.csr.mepc);
		return false;
	}
	if(ref_r->csr.mstatus != cpu.csr.mstatus) {
		printf("ref.matatus:%08x != cpu.mstatus:%08x\n", ref_r->csr.mstatus, cpu.csr.mstatus);
		return false;
	}
	if(ref_r->csr.mcause != cpu.csr.mcause) {
		printf("ref.mcause:%08x != cpu.mcause:%08x\n", ref_r->csr.mcause, cpu.csr.mcause);
		return false;
	}
	if(ref_r->csr.mtvec != cpu.csr.mtvec) {
		printf("ref.mtvec:%08x != cpu.mtvec:%08x\n", ref_r->csr.mtvec, cpu.csr.mtvec);
		return false;
	}
  return true;
}

void isa_difftest_attach() {
}
