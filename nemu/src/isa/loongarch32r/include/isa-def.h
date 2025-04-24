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

#ifndef __ISA_LOONGARCH32R_H__
#define __ISA_LOONGARCH32R_H__

#include <common.h>

typedef struct {
  word_t gpr[32];
  vaddr_t pc;
#ifndef __ICS_EXPORT
  vaddr_t eentry;
  union {
    struct {
      uint32_t pad :16;
      uint32_t ecode: 6;
    };
    uint32_t val;
  } estat;
  vaddr_t era;
  union {
    struct {
      uint32_t plv : 2;
      uint32_t ie  : 1;
      uint32_t pad : 1;
      uint32_t pg  : 1;
    };
    uint32_t val;
  } crmd;
  union {
    struct {
      uint32_t pplv: 2;
      uint32_t pie : 1;
    };
    uint32_t val;
  } prmd;
  vaddr_t save0;
  vaddr_t save1;

  vaddr_t tlbrentry;
  union {
    struct {
      uint32_t pad :13;
      uint32_t VPN2:19;
    };
    uint32_t val;
  } tlbehi;
  uint32_t tlbelo0, tlbelo1;
  union {
    struct {
      uint32_t idx :4;
      uint32_t pad1:12;
      uint32_t pad2:8;
      uint32_t ps  :6;
      uint32_t pad3:1;
      uint32_t ne  :1;
    };
    uint32_t val;
  } tlbidx;

  bool INTR;
#endif
} loongarch32r_CPU_state;

// decode
typedef struct {
  uint32_t inst;
} loongarch32r_ISADecodeInfo;

#ifdef __ICS_EXPORT
#define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)
#else
#define isa_mmu_state() (MMU_DYNAMIC)
#define isa_mmu_check(vaddr, len, type) ((vaddr & 0x80000000u) == 0 && cpu.crmd.pg ? MMU_TRANSLATE : MMU_DIRECT)
#endif

#endif
