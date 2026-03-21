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
#include <isa.h>

static inline int check_reg_idx(int idx) {
  IFDEF(CONFIG_RT_CHECK, assert(idx >= 0 && idx < MUXDEF(CONFIG_RVE, 16, 32)));
  return idx;
}

#define gpr(idx) (cpu.gpr[check_reg_idx(idx)])

#define Mstatus()  (cpu.csr.mstatus)
#define Mcause()   (cpu.csr.mcause)
#define Mepc()     (cpu.csr.mepc)
#define Mtvec()    (cpu.csr.mtvec)

static word_t ysyx_logo = 0x79737978; //ysyx的logo
static word_t stu_num = 0x25110270; //我的学号-25110270

static inline word_t *csr_reg(int idx) {
  switch (idx) {
    case 0x300: return &Mstatus();
    case 0x305: return &Mtvec();
    case 0x341: return &Mepc();
    case 0x342: return &Mcause();
    case 0xf11: return &ysyx_logo; // mvendorid
    case 0xf12: return &stu_num; // marchid
    default:    panic("Unsupported CSR: 0x%03x\n", idx);
  }
}

static inline const char* reg_name(int idx) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}

#endif
