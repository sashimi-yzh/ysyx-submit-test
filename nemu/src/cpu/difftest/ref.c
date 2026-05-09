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

typedef struct {
  word_t gpr[16]; // 寄存器
  vaddr_t pc;
} REF_state;


void diff_get_regs(void* diff_context) {
  REF_state* ctx = (REF_state*)diff_context;
  for (int i = 0; i < 16; i++) {
    ctx->gpr[i] = cpu.gpr[i];
  }
  ctx->pc = cpu.pc;
}

void diff_set_regs(void* diff_context) {
  REF_state* ctx = (REF_state*)diff_context;
  for (int i = 0; i < 16; i++) {
    cpu.gpr[i] = ctx->gpr[i];
  }
  cpu.pc = ctx->pc;
}



// extern "C" {

// 把第二个地址的后n个字节复制到第一个参数的内存下
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {

  if(direction == DIFFTEST_TO_REF){
    memcpy(guest_to_host(addr), buf, n);
  }

  // assert(0);
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {

  // CPU_state *ctx = (CPU_state *)dut;
  
  if(direction == DIFFTEST_TO_DUT){ // 把nemu的寄存器复制到npc，此时dut为npc的中间变量
    diff_get_regs(dut);
  }
  else if(direction == DIFFTEST_TO_REF){ // 把npc的寄存器复制到nemu，此时dut为npc的寄存器和pc值
    diff_set_regs(dut);
  }
  // assert(0);
}

__EXPORT void difftest_exec(uint64_t n) {

  cpu_exec(n);


  // assert(0);
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


// }