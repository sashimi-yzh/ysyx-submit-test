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

#include "../local-include/csr.h"
#include "../local-include/trap-cause.h"
#include "common.h"
#include "debug.h"
#include "isa-def.h"
#include <isa.h>
#include <stdint.h>

inline static uint32_t encode_mpp(CPU_MODE priv) {
  switch (priv) {
  case M_MODE:
    return MSTATUS_MPP_M;
  case S_MODE:
    return MSTATUS_MPP_S;
  case U_MODE:
    return MSTATUS_MPP_U;
  default:
    assert(0 && "invalid cpu.priv");
    return MSTATUS_MPP_U;
  }
}

inline static bool is_delegated_to_supervisor(word_t NO) {
  bool is_intr = (NO & TRAP_CAUSE_INT_BIT) != 0;
  uint32_t cause = NO & ~TRAP_CAUSE_INT_BIT;

  if (is_intr) {
    return (cpu.csr.mideleg >> cause) & 1;
  } else {
    return (cpu.csr.medeleg >> cause) & 1;
  }
}

typedef enum {
  INTR_TARGET_NONE,
  INTR_TARGET_MACHINE,
  INTR_TARGET_SUPERVISOR,
} intr_target_t;

typedef struct {
  word_t cause;
  uint32_t pending_bit;
  uint32_t enable_bit;
} intr_source_t;

// clang-format off
static const intr_source_t intr_sources_in_priority_order[] = {
  {IRQ_M_EXTERNAL  , MIP_MEIP, MIE_MEIE},
  {IRQ_M_SOFTWARE  , MIP_MSIP, MIE_MSIE},
  {IRQ_M_TIMER     , MIP_MTIP, MIE_MTIE},
  {IRQ_S_EXTERNAL  , MIP_SEIP, MIE_SEIE},
  {IRQ_S_SOFTWARE  , MIP_SSIP, MIE_SSIE},
  {IRQ_S_TIMER     , MIP_STIP, MIE_STIE},
};
// clang-format on

inline static intr_target_t interrupt_target(word_t cause) {
  if (cpu.priv == M_MODE) {
    // A delegated interrupt cannot lower M-mode's privilege.
    return is_delegated_to_supervisor(cause) ? INTR_TARGET_NONE
                                             : INTR_TARGET_MACHINE;
  }

  return is_delegated_to_supervisor(cause) ? INTR_TARGET_SUPERVISOR
                                           : INTR_TARGET_MACHINE;
}

inline static bool can_target_accept_interrupt(intr_target_t target) {
  switch (target) {
  case INTR_TARGET_MACHINE:
    return cpu.priv != M_MODE || (cpu.csr.mstatus & MSTATUS_MIE) != 0;
  case INTR_TARGET_SUPERVISOR:
    return cpu.priv != S_MODE || (cpu.csr.mstatus & MSTATUS_SIE) != 0;
  default:
    return false;
  }
}

static uint32_t pending_interrupts(void) {
  uint32_t pending = riscv_csr_mip_value();

#ifndef CONFIG_HAS_CLINT
  // The legacy host timer is an edge source, not an architectural MTIP level.
  if (cpu.legacy_timer_interrupt_pending) {
    pending |= MIP_MTIP;
  }
#endif

  return pending;
}

inline static bool interrupt_source_is_ready(const intr_source_t *source,
                                             uint32_t pending) {
  return (pending & source->pending_bit) != 0 &&
         (cpu.csr.mie & source->enable_bit) != 0;
}

static word_t highest_priority_interrupt_for(intr_target_t target,
                                             uint32_t pending) {
  if (!can_target_accept_interrupt(target)) {
    return INTR_EMPTY;
  }

  for (int i = 0; i < ARRLEN(intr_sources_in_priority_order); i++) {
    const intr_source_t *source = &intr_sources_in_priority_order[i];
    // only return intr or excp for target privilige
    if (interrupt_target(source->cause) != target) {
      continue;
    }
    if (interrupt_source_is_ready(source, pending)) {
      return source->cause;
    }
  }

  return INTR_EMPTY;
}

inline static word_t get_trap_pc(word_t NO, word_t tvec) {
  uint32_t mode = tvec & 0x3u;
  uint32_t base = tvec & ~0x3u;

  bool is_intr = (NO & TRAP_CAUSE_INT_BIT) != 0;
  uint32_t cause = NO & ~TRAP_CAUSE_INT_BIT;

  // mtval[1:0] set the mode
  if (mode == 0) {
    return base;
  } else if (mode == 1) {
    if (is_intr) {
      return base + 4 * cause;
    } else {
      return base;
    }
  } else {
    panic("invalid stvec mode");
  }
}

static word_t raise_intr(word_t NO, vaddr_t epc, word_t tval, bool sync) {
  uint32_t trap_pc = 0;

  if (cpu.priv != M_MODE && is_delegated_to_supervisor(NO)) {
    CPU_MODE previous_priv = cpu.priv;
    cpu.priv = S_MODE;
    uint32_t old = cpu.csr.mstatus;
    cpu.csr.mstatus = (old & ~(SSTATUS_SIE | SSTATUS_SPIE | SSTATUS_SPP)) |
                      ((old & SSTATUS_SIE) << 4) |
                      (previous_priv == S_MODE ? SSTATUS_SPP : 0);
    cpu.csr.sepc = epc;
    cpu.csr.scause = NO;
    cpu.csr.stval = sync ? tval : 0;
    trap_pc = get_trap_pc(NO, cpu.csr.stvec);
  } else {
    uint32_t mstatus = cpu.csr.mstatus;
    cpu.csr.mstatus =
        (mstatus & ~(MSTATUS_MPP_MASK | MSTATUS_MPIE | MSTATUS_MIE)) |
        encode_mpp(cpu.priv) | ((mstatus & MSTATUS_MIE) << 4);
    cpu.priv = M_MODE;
    cpu.csr.mepc = epc;
    cpu.csr.mcause = NO;
    cpu.csr.mtval = sync ? tval : 0;
    trap_pc = get_trap_pc(NO, cpu.csr.mtvec);
  }

  return trap_pc;
}

inline static void acknowledge_legacy_timer_interrupt(word_t NO) {
#ifndef CONFIG_HAS_CLINT
  if (NO == IRQ_M_TIMER) {
    cpu.legacy_timer_interrupt_pending = false;
  }
#endif
}

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  acknowledge_legacy_timer_interrupt(NO);
  return raise_intr(NO, epc, 0, false);
}

word_t isa_raise_sync_intr(word_t NO, vaddr_t epc, word_t tval) {
  return raise_intr(NO, epc, tval, true);
}

bool isa_enable_intr() {
  switch (cpu.priv) {
  case M_MODE:
    return (cpu.csr.mstatus & MSTATUS_MIE) != 0;
  case S_MODE:
    return (cpu.csr.mstatus & MSTATUS_SIE) != 0;
  case U_MODE:
    return true;
  default:
    assert(0 && "invalid cpu.priv");
    return false;
  }
}

word_t isa_query_intr() {
  uint32_t pending = pending_interrupts();
  word_t interrupt =
      highest_priority_interrupt_for(INTR_TARGET_MACHINE, pending);
  if (interrupt != INTR_EMPTY) {
    return interrupt;
  }

  // Delegated interrupts cannot lower M-mode's privilege to S-mode.
  if (cpu.priv == M_MODE) {
    return INTR_EMPTY;
  }

  return highest_priority_interrupt_for(INTR_TARGET_SUPERVISOR, pending);
}
