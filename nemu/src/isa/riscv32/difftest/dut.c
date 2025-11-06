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

// 这里传入的参数是指ref执行之后的结果
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  
  if(ref_r->pc != cpu.pc){
    Log("ref_r: " FMT_WORD "\tpc:" FMT_WORD, ref_r->pc, cpu.pc);
    return false;
  }

  int reg_num = ARRLEN(cpu.gpr);
  for(int i = 0; i < reg_num;i++){
    if(cpu.gpr[i] != ref_r->gpr[i]){
      // Log("ref_r.pc:%x\tpc: %x\tcpu.pc: %x\tgpr[%d] : ref_r.gpr[%d]: %x\tcpu.gpr[%d]: %x", ref_r->pc, pc, cpu.pc, i, i, ref_r->gpr[i], i, cpu.gpr[i]);
      
      Log("PC = 0x%x, Difftest Reg Compare failed at GPR[%d], Difftest Get " FMT_WORD ", NEMU Get " FMT_WORD, cpu.pc, i, ref_r->gpr[i], cpu.gpr[i]);
      return false;
    }
  }

  return true;
}

void isa_difftest_attach() {
}
