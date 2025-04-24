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
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  vaddr_t pc;
#ifndef CONFIG_PA
  uint64_t mstatus, mepc, mtval, mcause;
  uint64_t          sepc, stval, scause;
#endif
#ifndef __ICS_EXPORT
  IFDEF(CONFIG_RVFD, uint64_t fpr[32]);

  uint8_t mode;

  bool amo;
  int mem_exception;

  // for LR/SC
  uint64_t lr_addr;

  bool INTR;
#endif
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state);

// decode
typedef struct {
  uint32_t inst;
} MUXDEF(CONFIG_RV64, riscv64_ISADecodeInfo, riscv32_ISADecodeInfo);

#ifndef __ICS_EXPORT
enum { MODE_U = 0, MODE_S, MODE_H, MODE_M };

int get_data_mmu_state();
#define isa_mmu_state() get_data_mmu_state()
#else
#define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)
#endif

#endif
