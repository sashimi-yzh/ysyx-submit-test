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

#include "../local-include/reg.h"
#include "isa-def.h"
#include <cpu/difftest.h>
#include <isa.h>
#include <stdio.h>

#define riscv_check_csr(csrname)                                               \
  do {                                                                         \
    if (ref_r->csr.csrname != cpu.csr.csrname) {                               \
      printf("the difftest encounter a error at pc:%x\n", pc);                 \
      printf("nemu[" #csrname "] %08x spike[" #csrname "] %08x \n",            \
             cpu.csr.csrname, ref_r->csr.csrname);                             \
      return false;                                                            \
    }                                                                          \
  } while (0);

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  for (int i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++) {
    if (ref_r->gpr[i] != cpu.gpr[i]) {
      printf("the difftest encounter a error at pc:%x\n", pc);
      printf("nemu[%2d] %08x spike[%2d] %08x \n", i, cpu.gpr[i], i,
             ref_r->gpr[i]);
      return false;
    }

#define CHECK_DIFFTEST_CSR(name) riscv_check_csr(name)
    EACH_DIFFTEST_CSR(CHECK_DIFFTEST_CSR)
#undef CHECK_DIFFTEST_CSR
  }

#ifdef CONFIG_DIFFTEST
  if (difftest_ref_priv != cpu.priv) {
    printf("the difftest encounter a error at pc:%x\n", pc);
    printf("nemu[priv] %08x spike[priv] %08x \n", cpu.priv,
           (uint32_t)difftest_ref_priv);
    return false;
  }
#endif
  return true;
}

void isa_difftest_attach() { difftest_attach(); }

void isa_difftest_detach() { difftest_detach(); }

bool isa_difftest_is_attach() { return difftest_is_attach(); }
