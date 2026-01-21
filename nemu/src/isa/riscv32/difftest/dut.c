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
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
	if(ref_r->pc != cpu.pc) {
		Log("PC值的difftest检查不通过, 发生在pc = 0x%8x, dut: 0x%8x, ref: 0x%8x", pc, cpu.pc, ref_r->pc);
		return false;
	}
  for (int i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++)
  {
	if(ref_r->gpr[i] != cpu.gpr[i]) {
		Log("gpr值的difftest检查不通过, 发生在pc = 0x%8x, name: x%2d/%3s, dut: 0x%8x, ref: 0x%8x", pc, i, reg_name(i), cpu.gpr[i], ref_r->gpr[i]);
		return false;
	}
  }
  return true;
}

void isa_difftest_attach() {
}
