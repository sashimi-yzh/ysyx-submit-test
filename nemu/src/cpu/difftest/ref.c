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

typedef struct diff_context_t {
  uint32_t gpr[32];
  uint32_t pc;
  uint32_t mtvec;
  uint32_t mepc;
  uint32_t mstatus;
  uint32_t mcause;
}diff_context_t;

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if(direction == DIFFTEST_TO_REF) {
    uint8_t *buf_temp = (uint8_t *) buf;
    for(int i = 0; i < n; i++) {
      paddr_write(addr, 1, *(buf_temp + i));
      addr++;
    }
  } else {
    assert(0);
  }  
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  diff_context_t* ctx = (diff_context_t *)dut;
  if(direction == DIFFTEST_TO_REF) {
    for(int i = 0; i < 32; i++) {
      cpu.gpr[i] = ctx->gpr[i];
    }
    cpu.pc           = ctx->pc;
    cpu.csrs.mtvec   = ctx->mtvec;
    cpu.csrs.mepc    = ctx->mepc;
    cpu.csrs.mstatus = ctx->mstatus;
    cpu.csrs.mcause  = ctx->mcause;
  } 
  else {
    for(int i = 0; i < 32; i++) {
      ctx->gpr[i] = cpu.gpr[i];
    }
    ctx->pc      = cpu.pc;
    ctx->mtvec   = cpu.csrs.mtvec; 
    ctx->mepc    = cpu.csrs.mepc;
    ctx->mstatus = cpu.csrs.mstatus;
    ctx->mcause  = cpu.csrs.mcause;
  }
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
