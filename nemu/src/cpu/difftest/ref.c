/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/
// clang-format off

#include <cpu/cpu.h>
#include <difftest-def.h>
#include <isa.h>
#include <memory/paddr.h>
#include <memory/vaddr.h>
#include <stdint.h>
#include <string.h>

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    if (in_pmem(addr) && (uint64_t)addr + n <= (uint64_t)PMEM_RIGHT + 1) {
      memcpy(guest_to_host(addr), buf, n);
      return;
    }
    for (int i = 0; i < n; i++){
      paddr_write(addr + i, 1, *((uint8_t *)buf + i));
    }
  } else {
    assert(0);
  }
}

// get DIFFTEST_TO_REF means init the nemu, input the state of 
// npc and set the npc state to nemu
// get DIFFTEST_TO_DUT means the npc instance a diffcontext and
// trans it to nemu, nemu cpy its state to the diffcontext, then
// npc used the diffcontext to check its state
__EXPORT void difftest_regcpy(void *dut, bool direction) { 
  if(direction == DIFFTEST_TO_REF){
#ifdef CONFIG_ISA_riscv
    riscv_difftest_ctx_t *ctx = (riscv_difftest_ctx_t *)dut;
    for (int i = 0; i < RISCV_GPR_NUM; i++) {
      cpu.gpr[i] = ctx->gpr[i];
    }
    cpu.priv = ctx->priv;
#define UNPACK_DIFFTEST_CSR(name) cpu.csr.name = ctx->csr.name;
    EACH_DIFFTEST_CSR(UNPACK_DIFFTEST_CSR)
#undef UNPACK_DIFFTEST_CSR
    cpu.pc = ctx->pc;
#else
    assert(0);
#endif
  } else {
#ifdef CONFIG_ISA_riscv
    riscv_difftest_ctx_t *ctx = (riscv_difftest_ctx_t *)dut;
    for (int i = 0; i < RISCV_GPR_NUM; i++) {
      ctx->gpr[i] = cpu.gpr[i];
    }
    ctx->priv = cpu.priv;
#define PACK_DIFFTEST_CSR(name) ctx->csr.name = cpu.csr.name;
    EACH_DIFFTEST_CSR(PACK_DIFFTEST_CSR)
#undef PACK_DIFFTEST_CSR
    ctx->pc = cpu.pc;
#else
    assert(0);
#endif
  }
}

__EXPORT uint32_t difftest_get_mem(uint32_t addr) {
  return paddr_read(addr, 4);
}

__EXPORT void difftest_probe_mem(vaddr_t addr, difftest_mem_probe_t *result,
                                 size_t n) {
  word_t data = 0;
  word_t cause = 0;
  assert(result != NULL);
  assert(n <= sizeof(result->data));

  result->success = vaddr_read_safe(addr, n, &data, &cause);
  result->data = (uint32_t)data;
  result->cause = (uint32_t)cause;
}

__EXPORT void difftest_exec(uint64_t n) { cpu_exec(n); }

__EXPORT void difftest_raise_intr(uint32_t cause) {
  cpu.pc = isa_raise_intr(cause, cpu.pc);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}

// clang-format on
