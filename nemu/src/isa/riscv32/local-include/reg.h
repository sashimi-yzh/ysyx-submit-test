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

#ifndef __RISCV_REG_H__
#define __RISCV_REG_H__

#include <common.h>

static inline int check_reg_idx(int idx) {
  IFDEF(CONFIG_RT_CHECK, assert(idx >= 0 && idx < MUXDEF(CONFIG_RVE, 16, 32)));
  return idx;
}

void isa_csr_w(word_t csraddr, word_t wdata);
word_t isa_csr_r(word_t csraddr);

#define gpr(idx) (cpu.gpr[check_reg_idx(idx)])
#define csr(idx) (cpu.csr[idx])

static inline const char* reg_name(int idx) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}

#define CSR_MTVEC  0x305
#define CSR_MSCRATCH 0x340
#define CSR_MEPC   0x341
#define CSR_MCAUSE 0x342
#define CSR_MSTATUS 0x300
#define CSR_MCYCLE 0xb00
#define CSR_MCYCLEH 0xb80
#define CSR_MISA   0x301
#define CSR_MVENDORID 0xf11
#define CSR_MARCHID 0xf12
#define CSR_MTVAL 0x343
#endif
