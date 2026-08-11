#ifndef __ISA_RISCV_H__
#define __ISA_RISCV_H__

#include <npc/base.h>

typedef struct {
  word_t gpr[32];
  vaddr_t pc;
  // Must match NEMU's RISC-V CPU_state layout and npc/src/isa/riscv32/difftest/dut.c.
  word_t mstatus, mtvec, mepc, mcause, satp;
} riscv32_CPU_state;

// decode
typedef struct {
  uint32_t inst;
} riscv32_ISADecodeInfo;

#endif
