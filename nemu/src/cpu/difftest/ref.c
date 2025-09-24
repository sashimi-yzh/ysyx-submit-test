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
  if (direction == DIFFTEST_TO_REF) {
    memcpy(guest_to_host(addr), buf, n);
  } else {
    assert(0);
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  CPU_state *ctx = dut;
  if (direction == DIFFTEST_TO_REF) {
    for (int i = 0; i < 16; i++) {
      cpu.gpr[i] = ctx->gpr[i];
    }
    cpu.csr[MSTATUS] = ctx->csr[MSTATUS];
    cpu.csr[MTVEC]   = ctx->csr[MTVEC];
    cpu.csr[MEPC]    = ctx->csr[MEPC];
    cpu.csr[MCAUSE]  = ctx->csr[MCAUSE];
    cpu.pc = ctx->pc;
  } else {
    for (int i = 0; i < 16; i++) {
      ctx->gpr[i] = cpu.gpr[i];
    }
    ctx->csr[MSTATUS] = cpu.csr[MSTATUS];
    ctx->csr[MTVEC]   = cpu.csr[MTVEC];
    ctx->csr[MEPC]    = cpu.csr[MEPC];
    ctx->csr[MCAUSE]  = cpu.csr[MCAUSE];
    ctx->pc = cpu.pc;
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
