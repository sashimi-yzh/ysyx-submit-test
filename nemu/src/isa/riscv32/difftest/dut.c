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
extern CPU_state cpu;

bool skip = true;

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  
  for(int i = 0; i < 32; i ++){
    uint32_t ref_value = ref_r->gpr[i];
    uint32_t value = gpr(i);
    // printf("local:0x%08x\tref:0x%08x\n", value, ref_value);
    if(value != ref_value) {
    printf("gpr[%d] \33[1;31mdut:0x%08x \33[1;32mref:0x%08x\n", i, value, ref_value);
    return false;
    }
  }
  if (skip == true){
    if(ref_r->mstatus == 0x1800) skip = false;
  }
  else{
    if (cpu.mstatus != ref_r->mstatus){
      printf("mstatus \33[1;31mdut:0x%08x \33[1;32mref:0x%08x\n", cpu.mstatus, ref_r->mstatus);
      return false;
    }
    else if (cpu.mepc != ref_r->mepc){
      printf("mepc \33[1;31mdut:0x%08x \33[1;32mref:0x%08x\n", cpu.mepc, ref_r->mepc);
      return false;
    }
    else if (cpu.mcause != ref_r->mcause){
      printf("mcause \33[1;31mdut:0x%08x \33[1;32mref:0x%08x\n", cpu.mcause, ref_r->mcause);
      return false;
    }
    else if (cpu.mtvec != ref_r->mtvec){
      printf("mtvec \33[1;31mdut:0x%08x \33[1;32mref:0x%08x\n", cpu.mtvec, ref_r->mtvec);
      return false;
    }
  }

  return true;
}

void isa_difftest_attach() {
}
