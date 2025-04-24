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

#include <isa.h>
#include <memory/paddr.h>
#include <memory/vaddr.h>

#ifndef __ICS_EXPORT
#include <cpu/cpu.h>
#include "../local-include/intr.h"

#define NR_TLB 16

typedef union {
  struct {
    uint32_t pad :13;
    uint32_t VPN2:19;
  };
  uint32_t val;
} EntryHi;

typedef union {
  struct {
    uint32_t V   : 1;
    uint32_t D   : 1;
    uint32_t PLV : 2;
    uint32_t MAT : 2;
    uint32_t G   : 1;
    uint32_t pad : 1;
    uint32_t PFN :20;
    uint32_t pad2: 4;
  };
  uint32_t val;
} EntryLo;

struct {
  EntryHi hi;
  EntryLo lo[2];
  bool v;
} tlb [NR_TLB];

static void update_tlb(int idx) {
//  Log("cpu.pc = 0x%08x, va = 0x%08x, pa0 = 0x%08x, pa1 = 0x%08x",
//      cpu.pc, cpu.tlbehi.val, cpu.tlbelo0 >> 8 << 12, cpu.tlbelo1 >> 8 << 12);
  tlb[idx].hi.val = cpu.tlbehi.val;
  tlb[idx].lo[0].val = cpu.tlbelo0;
  tlb[idx].lo[1].val = cpu.tlbelo1;
  tlb[idx].v = 1;
}

void tlbwr() {
  assert(cpu.tlbidx.ne == 0);
  update_tlb(cpu.tlbidx.idx % NR_TLB);
}

void tlbsrch() {
  int i;
  for (i = 0; i < NR_TLB; i ++) {
    if (tlb[i].hi.VPN2 == cpu.tlbehi.VPN2) {
//      Log("match, i = %d, cpu.pc = 0x%08x, va = 0x%08x", i, cpu.pc, cpu.tlbehi.val);
      cpu.tlbidx.idx = i;
      cpu.tlbidx.ps = 12;
      cpu.tlbidx.ne = 0;
      return;
    }
  }
  cpu.tlbidx.ne = 1;
}

void invtlb() {
  int i;
  for (i = 0; i < NR_TLB; i ++) {
    tlb[i].v = 0;
  }
}


static int32_t search_ppn(vaddr_t addr, int type) {
  union {
    struct {
      uint32_t offset :12;
      uint32_t lo_idx : 1;
      uint32_t vpn    :19;
    };
    uint32_t val;
  } a;
  a.val = addr;
  int i;
  for (i = 0; i < NR_TLB; i ++) {
    if (tlb[i].v == 0) continue;
    if (tlb[i].hi.VPN2 == a.vpn) {
      if (!tlb[i].lo[a.lo_idx].V) {
   //     Log("tlb[%d] invalid at cpu.pc = 0x%08x, badaddr = 0x%08x", i, cpu.pc, addr);
        break;
      }
      //Assert(tlb[i].lo[a.lo_idx].V, "cpu.pc = 0x%08x, addr = 0x%08x, lo0 = 0x%08x, lo1 = 0x%08x",
      //    cpu.pc, addr, tlb[i].lo[0].val, tlb[i].lo[1].val);
      return tlb[i].lo[a.lo_idx].PFN;
    }
  }
  //Log("tlb refill at cpu.pc = 0x%08x, badaddr = 0x%08x", cpu.pc, addr);
  cpu.tlbehi.VPN2 = a.vpn;
  longjmp_exception(TLB_REFILL);
  return -1;
}
#endif
paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type) {
#ifdef __ICS_EXPORT
  return MEM_RET_FAIL;
#else
  int32_t ppn = search_ppn(vaddr, type);
  if (ppn == -1) return MEM_RET_FAIL;
  return ((uint32_t)ppn << 12) | MEM_RET_OK;
#endif
}
