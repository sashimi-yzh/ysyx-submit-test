#pragma once
#include "spdlog/spdlog.h"
#include <ELFParser.h>
#include <Simulate.h>
#include <cstddef>
#include <cstdint>
#include <fmt/format.h>
inline std::array<uint32_t, 16> ftracer_gpr_last;

inline void sync_ftracer() {
  for (size_t i = 0; i < 16; i++)
    ftracer_gpr_last[i] = dut->getGPR(i);
}

inline void update_ftracer(uint32_t inst, uint32_t pc) {
  uint32_t opcode = inst & 0x7f;
  uint32_t rd = (inst >> 7) & 0x1f;
  uint32_t dnxt_pc = -1;
  if (opcode == 0x6f) {
    uint32_t imm20 = inst >> 31;
    uint32_t imm10_1 = (inst >> 21) & 0x3ff;
    uint32_t imm11 = (inst >> 20) & 0x1;
    uint32_t imm19_12 = (inst >> 12) & 0xff;
    uint32_t imm =
        (imm20 << 20) | (imm19_12 << 12) | (imm11 << 11) | (imm10_1 << 1);
    imm |= -(imm & 0x80000);
    dnxt_pc = (pc + imm) & ~0x1;
  } else if (opcode == 0x67) {
    uint32_t rs1 = (inst >> 15) & 0x1f;
    uint32_t imm = inst >> 20;
    imm |= -(imm & 0x800);
    dnxt_pc = (imm + ftracer_gpr_last[rs1]) & ~0x1;
  }
  std::string indent = "", info = "";
  for (int i = 0; i < sym_table->stack_cnt(); i++)
    indent.push_back(' ');
  if ((opcode == 0x67 || opcode == 0x6f) && rd == 1) {
    int to_symbol = sym_table->find_symbol_by_addr(dnxt_pc);
    info = fmt::format("{}call {}@{:#010x}", indent,
                       sym_table->find_symbol_name(to_symbol), pc);
    sym_table->push_call_stack(to_symbol, pc);
  } else if (inst == 0x00008067) {
    ProgSymTab::Call top = sym_table->pop_call_stack();
    info = fmt::format("{}ret  {}@{:#010x}", indent,
                       sym_table->find_symbol_name(top.symbol), pc);
  } else
    return;
  spdlog::info("{}{}", indent, info);
}