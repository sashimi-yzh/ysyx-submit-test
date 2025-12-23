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

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  
  if(direction == DIFFTEST_TO_DUT){
    #ifndef CONFIG_YSYXSOC
    memcpy(addr - 0x80000000 + buf,guest_to_host(0x80000000),n);
    #else
    memcpy(addr - 0x30000000 + buf,guest_to_host(RESET_VECTOR),n);
    #endif
  }
  else if(direction == DIFFTEST_TO_REF){
    memcpy(guest_to_host(addr), buf, n);
  }
}

__EXPORT void difftest_regcpy(CPU_state *dut, bool direction) {
  
  for(int i =0;i < 32;i++){
    if(direction == DIFFTEST_TO_DUT){
      dut->gpr[i] = cpu.gpr[i];
      dut->pc = cpu.pc;
    }
    else if(direction == DIFFTEST_TO_REF){
      cpu.gpr[i] = dut->gpr[i];
      cpu.pc = dut->pc;
      
    }
  }
 
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
  
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}
void init_mem();
__EXPORT void difftest_init(int port) {
  
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
