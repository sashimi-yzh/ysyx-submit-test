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

void cpu_exec(uint64_t n);
typedef struct {
    word_t gpr[MUXDEF(CONFIG_RVE,16,32)];
    word_t pc;
    paddr_t mem_addr;
    word_t  mem_data;
    bool    mem_fcn;
    bool    mem_enable;
}diff_context;

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
    uint8_t* buf_in_byte = (uint8_t*)buf;
    if (direction == DIFFTEST_TO_DUT){
      for(size_t i = 0; i < n; i++){
        *(buf_in_byte+i) = paddr_read(addr+i,1);
      }
    } else{
      for(size_t i = 0; i < n; i++){
        paddr_write(addr+i,1,*(buf_in_byte+i));
      }
    }
    return;
}


__EXPORT void difftest_regcpy(void *dut, bool direction) {
  diff_context *context = (diff_context*)dut;
  size_t NXPR = MUXDEF(CONFIG_RVE,16,32);
  if (direction == DIFFTEST_TO_DUT){
    for(int i=0;i<NXPR;i++){
      context->gpr[i] = cpu.gpr[i];
    }
    context->pc = cpu.pc;
    context->mem_addr = cpu.mem_access.addr;
    context->mem_data = cpu.mem_access.data;
    context->mem_enable = cpu.mem_access.enable;
    context->mem_fcn = cpu.mem_access.fcn;
  } else{
    for (int i=0;i<NXPR;i++){
      cpu.gpr[i] = context->gpr[i];
    }
    cpu.pc = (context->pc == 0x0)? cpu.pc : context->pc;
  }

  return;
}

__EXPORT void difftest_exec(uint64_t n) {
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
