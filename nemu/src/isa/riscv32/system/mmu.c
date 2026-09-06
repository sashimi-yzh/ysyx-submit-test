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

#include "../local-include/exception.h"
#include "../local-include/trap-cause.h"
#include "common.h"
#include "cpu/cpu.h"
#include "debug.h"
#include <isa.h>
#include <memory/paddr.h>
#include <memory/vaddr.h>

static inline CPU_MODE isa_mmu_effective_priv(int type) {
  if (type != MEM_TYPE_IFETCH && cpu.priv == M_MODE &&
      (cpu.csr.mstatus & MSTATUS_MPRV)) {
    uint32_t mpp = cpu.csr.mstatus & MSTATUS_MPP_MASK;
    if (mpp == MSTATUS_MPP_M) {
      return M_MODE;
    }
    if (mpp == MSTATUS_MPP_S) {
      return S_MODE;
    }
    return U_MODE;
  }

  return cpu.priv;
}

int isa_mmu_check(vaddr_t vaddr, int len, int type) {
  if ((cpu.csr.satp & (0x1 << 31)) && isa_mmu_effective_priv(type) != M_MODE) {
    return MMU_TRANSLATE;
  } else {
    return MMU_DIRECT;
  }
}

#define VPN0_SHIFT 12 /* VA[21:12] for Sv32 */
#define VPN1_SHIFT 22 /* VA[31:22] for Sv32 */

#define VPN1_MASK (0x3FF << VPN1_SHIFT)
#define VPN0_MASK (0x3FF << VPN0_SHIFT)
#define OFFSET_MASK 0xFFF /* VA[11:0] for 4KB page */

#define PPN_MASK (0x3FFFFF << 10)
#define PTE_PPN(pte) (pte & PPN_MASK)
#define PTE_PPN0_MASK (0x3FF << 10)

#define PTE_V 0x01
#define PTE_R 0x02
#define PTE_W 0x04
#define PTE_X 0x08
#define PTE_U 0x10
#define PTE_A 0x40
#define PTE_D 0x80

static void isa_mmu_update_pte(paddr_t pte_addr, uint32_t pte, int type) {
  // In Sv32, A/D bits are meaningful for leaf PTEs only.
  // Non-leaf PTEs should keep software/reserved bits unchanged.
  if ((pte & (PTE_R | PTE_W | PTE_X)) == 0) {
    return;
  }

  uint32_t new_pte = pte;
  bool need_update = false;

  // 设置访问位（A位）
  if (!(pte & PTE_A)) {
    new_pte |= PTE_A;
    need_update = true;
  }

  // 如果是写操作，设置脏位（D位）
  if (type == MEM_TYPE_WRITE && !(pte & PTE_D)) {
    new_pte |= PTE_D;
    need_update = true;
  }

  // 如果有更新，写回页表项
  if (need_update) {
    paddr_write(pte_addr, 4, new_pte);
  }
}

static word_t isa_mmu_fault_cause(int type) {
  switch (type) {
  case MEM_TYPE_IFETCH:
    return EXC_INST_PAGE_FAULT;
  case MEM_TYPE_WRITE:
    return EXC_STORE_PAGE_FAULT;
  default:
    return EXC_LOAD_PAGE_FAULT;
  }
}

static bool isa_mmu_permission_check(uint32_t pte, int type,
                                     CPU_MODE effective_priv) {
  if (!(pte & PTE_V) || ((pte & PTE_W) && !(pte & PTE_R))) {
    return false;
  }

  if (effective_priv == U_MODE && !(pte & PTE_U)) {
    return false;
  }

  if (effective_priv == S_MODE && (pte & PTE_U)) {
    if (type == MEM_TYPE_IFETCH) {
      return false;
    }
    if (!(cpu.csr.mstatus & MSTATUS_SUM)) {
      return false;
    }
  }

  if (!(pte & PTE_A)) {
    return false;
  }
  if (type == MEM_TYPE_WRITE && !(pte & PTE_D)) {
    return false;
  }

  if (type == MEM_TYPE_READ) {
    bool can_read =
        (pte & PTE_R) || ((cpu.csr.mstatus & MSTATUS_MXR) && (pte & PTE_X));
    if (!can_read) {
      return false;
    }
  } else if (type == MEM_TYPE_IFETCH) {
    if (!(pte & PTE_X)) {
      return false;
    }
  } else if (type == MEM_TYPE_WRITE) {
    if (!(pte & PTE_W)) {
      return false;
    }
  }

  return true;
}

static bool isa_mmu_pagewalk_safe(vaddr_t vaddr, int type, paddr_t *addr_res,
                                  word_t *cause) {
  paddr_t pgt1_start = (cpu.csr.satp & 0x3FFFFF) << 12;
  CPU_MODE effective_priv = isa_mmu_effective_priv(type);

  int vpn1_idx = (vaddr >> VPN1_SHIFT) & 0x3FF;
  int vpn0_idx = (vaddr >> VPN0_SHIFT) & 0x3FF;
  int offset = vaddr & OFFSET_MASK;

  paddr_t pte1_addr = pgt1_start + 4 * vpn1_idx;
  uint32_t pte1 = paddr_read(pte1_addr, 4);

  if (!(pte1 & PTE_V)) {
    if (cause != NULL) {
      *cause = isa_mmu_fault_cause(type);
    }
    return false;
  }

  if ((pte1 & (PTE_R | PTE_W | PTE_X))) {
    // INFO: if leaf r/w/x is not zero，meaning a 4 MiB megapage
    if ((pte1 & PTE_PPN0_MASK) || // 4 MiB align
        !isa_mmu_permission_check(pte1, type, effective_priv)) {
      if (cause != NULL) {
        *cause = isa_mmu_fault_cause(type);
      }
      return false;
    }

    isa_mmu_update_pte(pte1_addr, pte1, type);

    *addr_res = (PTE_PPN(pte1) << 2) | (vaddr & 0x3fffff);
    return true;
  }

  isa_mmu_update_pte(pte1_addr, pte1, type);

  paddr_t pgt0_start = PTE_PPN(pte1) << 2;
  paddr_t pte0_addr = pgt0_start + 4 * vpn0_idx;
  uint32_t pte0 = paddr_read(pte0_addr, 4);

  if (!isa_mmu_permission_check(pte0, type, effective_priv)) {
    if (cause != NULL) {
      *cause = isa_mmu_fault_cause(type);
    }
    return false;
  }

  isa_mmu_update_pte(pte0_addr, pte0, type);

  *addr_res = (PTE_PPN(pte0) << 2) | offset;
  if (cause != NULL) {
    *cause = 0;
  }
  return true;
}

static paddr_t isa_mmu_pagewalk(vaddr_t vaddr, int type) {
  paddr_t addr_res = 0;
  word_t cause = 0;

  if (!isa_mmu_pagewalk_safe(vaddr, type, &addr_res, &cause)) {
    Log("isa mmu pagewalk safe for vaddr 0x%08x faild, type is %d", vaddr,
        cause);
    cpu_throw_exception(cause, vaddr);
  }

  return addr_res;
}

paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type) {
  int mmu_check = isa_mmu_check(vaddr, len, type);
  if (mmu_check == MMU_TRANSLATE) {
    return isa_mmu_pagewalk(vaddr, type);
  } else if (mmu_check == MMU_DIRECT) {
    return vaddr;
  }

  panic("should not reach here at pc = " FMT_WORD, cpu.pc);
  return 0;
}

bool isa_mmu_translate_safe(vaddr_t vaddr, int len, int type, paddr_t *paddr,
                            word_t *cause) {
  int mmu_check = isa_mmu_check(vaddr, len, type);
  if (mmu_check == MMU_TRANSLATE) {
    return isa_mmu_pagewalk_safe(vaddr, type, paddr, cause);
  }
  if (mmu_check == MMU_DIRECT) {
    *paddr = vaddr;
    if (cause != NULL) {
      *cause = 0;
    }
    return true;
  }

  if (cause != NULL) {
    *cause = isa_mmu_fault_cause(type);
  }
  return false;
}
