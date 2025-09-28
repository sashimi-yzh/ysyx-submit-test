/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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
#include <memory/vaddr.h>
#include <memory/paddr.h>
#include "../local-include/reg.h"

paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type) {
  // TEMP: Sv32 only
  switch (isa_mmu_check(vaddr, len, type)) {
    case MMU_FAIL: return MEM_RET_FAIL;
    case MMU_DIRECT: return vaddr;
    case MMU_TRANSLATE: ;
  }

  paddr_t pt1_addr = csr_satp << 12;
  paddr_t vpn1 = (vaddr >> 22) & 0x3ff;
  paddr_t pte1_addr = pt1_addr | (vpn1 << 2); 
  word_t pte1 = paddr_read(pte1_addr, 4, 0); // WARN: will be recorded by lstrace
  Assert(pte1 & 1, "Invalid page table 1 entry: " FMT_PADDR, vaddr);

  paddr_t pt0_addr = (pte1 << 2) & ~0xfff;
  paddr_t vpn0 = (vaddr >> 12) & 0x3ff;
  paddr_t pte0_addr = pt0_addr | (vpn0 << 2);
  word_t pte0 = paddr_read(pte0_addr, 4, 0);
  Assert(pte0 & 1, "Invalid page table 0 entry: " FMT_PADDR, vaddr);

  paddr_t paddr = ((pte0 << 2) & ~0xfff) | (vaddr & 0xfff);
  return paddr;
}
