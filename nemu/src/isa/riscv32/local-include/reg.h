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

#define gpr(idx) (cpu.gpr[check_reg_idx(idx)])

static inline const char* reg_name(int idx) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}

// csr
#define MEPC 0x341
#define MSTATUS 0x300
#define MCAUSE 0x342
#define MTVEC 0x305

extern uint32_t default_csr;
extern bool ref_nemu_difftest_skip_once;

static inline word_t* csr_ptr(uint32_t addr) {
  addr &= 0xfff;
  switch (addr) {
    case MEPC:    return &cpu.csr[0];
    case MSTATUS: return &cpu.csr[1];
    case MCAUSE:  return &cpu.csr[2];
    case MTVEC:   return &cpu.csr[3];
    default:{
      // printf("[NEMU] Warning: unsupported CSR: 0x%x\n", addr);
      ref_nemu_difftest_skip_once = true;
      return &default_csr;
    }
  }
}
#define csr(i) (*csr_ptr(i))


#endif
