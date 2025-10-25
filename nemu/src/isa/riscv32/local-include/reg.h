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
#include <stdio.h>
static inline int check_reg_idx(int idx) {
  IFDEF(CONFIG_RT_CHECK, assert(idx >= 0 && idx < MUXDEF(CONFIG_RVE, 16, 32)));
  return idx;
}

#define gpr(idx) (cpu.gpr[check_reg_idx(idx)])

static inline const char* reg_name(int idx) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}


#define MSTATUS	0x300
#define MTVEC	  0x305
#define MEPC	  0x341
#define MCAUSE	0x342

#define MVENDORID 0xf11
#define MARCHID   0xf12

#define CSR_N   6
extern word_t csr_reg[CSR_N][2];

static inline int get_csr(word_t i)
{
  i = i & 0x00000fff;
  word_t k = 0;
  for (; k < CSR_N; k++) 
  {
    if (csr_reg[k][0] == i)
      return k;
  }
  assert(k < CSR_N);
  return -1;
}

#define CSR(i) (csr_reg[get_csr(i)][1])

#endif
