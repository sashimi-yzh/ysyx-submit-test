/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 * PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <isa.h>
#include <memory/paddr.h>

// clang-format off
word_t vaddr_ifetch(vaddr_t addr, int len) {
  paddr_t paddr;
  int mmu_check = isa_mmu_check(addr, len, MEM_TYPE_IFETCH);
  if(mmu_check == MMU_DIRECT) {
    paddr = addr;
  } else if(mmu_check == MMU_TRANSLATE) {
    paddr = isa_mmu_translate(addr, len, MEM_TYPE_IFETCH);
  } else {
    assert(false && "should not reach here");
  }

  return paddr_read(paddr, len);
}

word_t vaddr_read(vaddr_t addr, int len) {
  paddr_t paddr;
  int mmu_check = isa_mmu_check(addr, len, MEM_TYPE_READ);
  if(mmu_check == MMU_DIRECT) {
    paddr = addr;
  } else if(mmu_check == MMU_TRANSLATE) {
    paddr = isa_mmu_translate(addr, len, MEM_TYPE_READ);
  } else {
    assert(false && "should not reach here");
  }

  return paddr_read(paddr, len);
}

bool vaddr_read_safe(vaddr_t addr, int len, word_t *data, word_t *cause) {
  paddr_t paddr = 0;
  if (!isa_mmu_translate_safe(addr, len, MEM_TYPE_READ, &paddr, cause)) {
    if (data != NULL) {
      *data = 0;
    }
    return false;
  }

  if (data != NULL) {
    *data = paddr_read(paddr, len);
  }
  if (cause != NULL) {
    *cause = 0;
  }
  return true;
}

void vaddr_write(vaddr_t addr, int len, word_t data) {
  paddr_t paddr;
  int mmu_check = isa_mmu_check(addr, len, MEM_TYPE_WRITE);
  if(mmu_check == MMU_DIRECT) {
    paddr = addr;
  } else if(mmu_check == MMU_TRANSLATE) {
    paddr = isa_mmu_translate(addr, len, MEM_TYPE_WRITE);
  } else {
    assert(false && "should not reach here");
  }

  paddr_write(paddr, len, data);
}
