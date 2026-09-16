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

static inline int check_csr_idx(int idx) {
  switch (idx){
    case 0x300: return idx; // mstatus
    case 0x305: return idx; // MTVEC
    case 0x341: return idx; // mepc
    case 0x342: return idx; // mcause
    case 0xF11: return idx; // mvendorid
    case 0xF12: return idx; // marchid
    default: panic("Unknown csr");
  }
}

#define gpr(idx) (cpu.gpr[check_reg_idx(idx)])
// #define csr(idx) (cpu.csr[check_csr_idx(idx)])
#define csr(idx) ({ \
    int __idx = check_csr_idx(idx); \
    __idx == 0x300 ? &cpu.mstatus : \
    __idx == 0x305 ? &cpu.mtvec : \
    __idx == 0x341 ? &cpu.mepc : \
    __idx == 0x342 ? &cpu.mcause : \
    __idx == 0xF11 ? &cpu.mvendorid : \
    __idx == 0xF12 ? &cpu.marchid : \
    (assert(0 && "Invalid CSR index"), &cpu.mstatus); \
})

#define MSTATUS *csr(0x300) // mstatus
#define MTVEC *csr(0x305) // MTVEC
#define MEPC *csr(0x341) // mepc
#define MCAUSE *csr(0x342) // mcause

static inline const char* reg_name(int idx) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}

#endif
