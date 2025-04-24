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

#ifndef __ISA_MIPS32_H__
#define __ISA_MIPS32_H__

#include <common.h>

typedef struct {
  word_t gpr[32];
#ifdef __ICS_EXPORT
  word_t pad[5];
  vaddr_t pc;
#else
  union {
    struct {
      uint32_t ie:  1;
      uint32_t exl: 1;
      uint32_t dontcare: 30;
    };
    uint32_t val;
  } status;

  word_t lo, hi;
  uint32_t badvaddr;
  uint32_t cause;
  vaddr_t pc;
  uint32_t epc;

  union {
    struct {
      uint32_t ASID: 8;
      uint32_t pad : 5;
      uint32_t VPN2:19;
    };
    uint32_t val;
  } entryhi;
  uint32_t entrylo0, entrylo1;
  uint32_t index;

  bool INTR;
#endif
} mips32_CPU_state;

// decode
typedef struct {
  uint32_t inst;
} mips32_ISADecodeInfo;

#ifdef __ICS_EXPORT
#define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)
#else
#define isa_mmu_state() (MMU_DYNAMIC)
#define isa_mmu_check(vaddr, len, type) ((vaddr & 0x80000000u) == 0 ? MMU_TRANSLATE : MMU_DIRECT)
#endif

#endif
