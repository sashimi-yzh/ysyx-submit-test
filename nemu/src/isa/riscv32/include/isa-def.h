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

#ifndef __ISA_RISCV_H__
#define __ISA_RISCV_H__

#include <common.h>

typedef struct {
  word_t mcause;
  vaddr_t mepc;
  word_t mstatus;
  word_t mtvec;
} riscv32_CSRs; // 存放CSR寄存器

typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)]; // 寄存器
  vaddr_t pc;
  riscv32_CSRs csr;
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state); // MUXDEF是个选择函数，当macro被定义时，返回X，当未被定义时，返回Y

// decode
typedef struct {
  uint32_t inst;
} MUXDEF(CONFIG_RV64, riscv64_ISADecodeInfo, riscv32_ISADecodeInfo);

#define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)

#endif
