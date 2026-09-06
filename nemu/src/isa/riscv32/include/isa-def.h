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

#ifndef __ISA_RISCV_H__
#define __ISA_RISCV_H__

#include <common.h>
#include <stdint.h>

#include "csr-xmacro.h"

// 定义结构体
typedef struct {
#define DEFINE_CSR_MEMBER(name, idx) uint32_t name;
  EACH_RAW_CSR(DEFINE_CSR_MEMBER)
#undef DEFINE_CSR_MEMBER
} riscv32_CPU_csr;

typedef enum { S_MODE, M_MODE, U_MODE } CPU_MODE;

typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  vaddr_t pc;
  riscv32_CPU_csr csr;
  CPU_MODE priv;
  bool legacy_timer_interrupt_pending;
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state);

// decode
typedef struct {
  union {
    uint32_t val;
  } inst;
} MUXDEF(CONFIG_RV64, riscv64_ISADecodeInfo, riscv32_ISADecodeInfo);

// #define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)
#include "csr/csr-irq.h"
#include "csr/machine-id.h"
#include "csr/mcounteren.h"
#include "csr/misa.h"
#include "csr/mstatus.h"

#endif
