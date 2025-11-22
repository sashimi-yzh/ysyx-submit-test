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

typedef struct{
  word_t mcause;//存放异常原因
  vaddr_t mepc;//存放触发异常的地址PC
  word_t mstatus;//存放当前状态
  word_t mtvec;//存放异常向量表地址
}riscv32_CSRs;

// typedef struct{
//   word_t gpr[32];
//   vaddr_t pc;
//   riscv32_CSRs csr;
// }riscv32_CPU_state;

typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  vaddr_t pc;
  riscv32_CSRs csr;
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state);

// decode
typedef struct {
  uint32_t inst;
} MUXDEF(CONFIG_RV64, riscv64_ISADecodeInfo, riscv32_ISADecodeInfo);

#define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)

#endif
