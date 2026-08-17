#pragma once

#include "Cache.h"
#include "DUT.h"
#include "Setup.h"
#include <InstPattern/InstPattern.h>
#include <VirtualBus.h>
#include <cstdint>
#include <fmt/format.h>
#include <my_utils.h>
#include <stdexcept>
// std::ofstream ref_trace_file;
class Ref {
public:
  Ref(Config config, Dut &dut, int nr_words_per_line_2pow, int nr_lines_2pow)
      : cache_hit(0), cache(nr_words_per_line_2pow, nr_lines_2pow),
        inst_count(0), dut(dut), csr({.mstatus = 0x1800,
                                      .mvendorid = 0x79737978,
                                      .marchid = 0x17eb198}) {
    // ref_trace_file.open("ref_trace.log");
  }
  uint32_t getGPR(int id) { return cpu.gpr[id]; }
  uint32_t getPC() { return cpu.pc; };

  void reset(Dut &dut) {
    inst_count = 0;
    // std::fill(cpu.gpr.begin(), cpu.gpr.end(), 0);
    for (int i = 0; i < 16; i++) {
      cpu.gpr[i] = dut.getGPR(i);
    }
    cache.reset();
    cache_hit = 0;
    cpu.pc = 0x30000000;
  };
  void step();
  unsigned long long instrCount() { return inst_count; }

  void sync_state() {
    for (int i = 1; i < 16; i++) {
      cpu.gpr[i] = dut.getGPR(i);
    }
    cpu.pc = dut.getPC();
  }

  uint32_t isa_raise_intr(int intr_id) {
    csr.mepc = cpu.pc;
    csr.mcause = intr_id;

    return csr.mtvec;
  }
  uint32_t &csr_id(uint32_t id) {
    switch (id) {
    case 0x300:
      return csr.mstatus;
    case 0x305:
      return csr.mtvec;
    case 0x341:
      return csr.mepc;
    case 0x342:
      return csr.mcause;
    case 0xf11:
      return csr.mvendorid;
    case 0xf12:
      return csr.marchid;
    }
    log_and_throw<std::logic_error>("Visited invalid csr : {:x}", id);
  }

  struct {
    uint32_t mepc;
    uint32_t mstatus;
    uint32_t mtvec;
    uint32_t mcause;
    uint32_t mvendorid;
    uint32_t marchid;
  } csr;

  struct CPU_State {
    std::array<uint32_t, 16> gpr;
    uint32_t pc;
  };
  unsigned long long getCacheHit() { return cache_hit; }

private:
  unsigned long long inst_count;

  unsigned long long cache_hit;
  bool is_halt;

  Dut &dut;
  CPU_State cpu;
  VirtualBus vbus;
  Cache cache;
};

#define BEGIN_PATTERN do {
#define END_PATTERN                                                            \
  }                                                                            \
  while (false)                                                                \
    ;
#define try_this(pat, name, ...)                                               \
  if (Pattern(pat).verify(inst)) {                                             \
    __VA_ARGS__;                                                               \
    break;                                                                     \
  }

inline void Ref::step() {
  if (cache.fetch(cpu.pc))
    cache_hit++;
  auto ifnst_fetch = vbus.readMemory(cpu.pc, 4);
  if (ifnst_fetch.read_nonmemory) {
    log_and_throw<std::logic_error>(
        "Ref tried to fetch instruction in non-memory address {:#010x}",
        cpu.pc);
  }
  const uint32_t inst = ifnst_fetch.data;
  // fmt::println("PC = {:08x}, inst = {:08x}", cpu.pc, inst);
  Decoded d = decode(inst);
  // ref_trace_file
  //     << std::format(
  //            "{:08x} {:08x} | {:08x} {:08x} {:08x} | {:08x} {:08x} {:08x}\n",
  //            cpu.pc, inst, cpu.gpr[10], cpu.gpr[11], cpu.gpr[12],
  //            cpu.gpr[13], cpu.gpr[14], cpu.gpr[15])
  //     << std::flush;

  uint32_t dnpc = cpu.pc + 4;
  BEGIN_PATTERN
  try_this("??????? ????? ????? ??? ????? 00101 11", auipc,
           cpu.gpr[d.dst_id] = cpu.pc + d.imm_U);
  try_this("??????? ????? ????? ??? ????? 01101 11", lui,
           cpu.gpr[d.dst_id] = d.imm_U);

  try_this("??????? ????? ????? 000 ????? 00100 11", addi,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] + d.imm_I);
  try_this("0000000 ????? ????? 000 ????? 01100 11", add,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] + cpu.gpr[d.src2_id]);
  try_this("0100000 ????? ????? 000 ????? 01100 11", sub,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] - cpu.gpr[d.src2_id]);
  try_this("0000001 ????? ????? 000 ????? 01100 11", mul,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] * cpu.gpr[d.src2_id]);
  try_this("0000001 ????? ????? 001 ????? 01100 11", mulh,
           cpu.gpr[d.dst_id] =
               bits<63, 32, uint64_t>((int64_t)(int32_t)cpu.gpr[d.src1_id] *
                                      (int64_t)(int32_t)cpu.gpr[d.src2_id]));
  try_this("0000001 ????? ????? 011 ????? 01100 11", mulhu,
           cpu.gpr[d.dst_id] = bits<63, 32, uint64_t>(
               (uint64_t)cpu.gpr[d.src1_id] * (uint64_t)cpu.gpr[d.src2_id]));
  try_this("0000001 ????? ????? 010 ????? 01100 11", mulhsu,
           cpu.gpr[d.dst_id] =
               bits<63, 32, uint64_t>((int64_t)(int32_t)cpu.gpr[d.src1_id] *
                                      (uint64_t)cpu.gpr[d.src2_id]));
  try_this("0000001 ????? ????? 111 ????? 01100 11", remu,
           if (cpu.gpr[d.src2_id] == 0) cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id];
           else cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] % cpu.gpr[d.src2_id]);
  try_this("0000001 ????? ????? 110 ????? 01100 11", rem,
           if (cpu.gpr[d.src2_id] == 0) cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id];
           else if (cpu.gpr[d.src2_id] == -1) cpu.gpr[d.dst_id] = 0;
           else cpu.gpr[d.dst_id] =
               (int32_t)cpu.gpr[d.src1_id] % (int32_t)cpu.gpr[d.src2_id]);
  try_this("0000001 ????? ????? 101 ????? 01100 11", divu,
           if (cpu.gpr[d.src2_id] == 0) cpu.gpr[d.dst_id] = -1;
           else cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] / cpu.gpr[d.src2_id]);
  try_this("0000001 ????? ????? 100 ????? 01100 11", div,
           if (cpu.gpr[d.src2_id] == 0) cpu.gpr[d.dst_id] = -1;
           else if (cpu.gpr[d.src2_id] == -1) cpu.gpr[d.dst_id] =
               -cpu.gpr[d.src1_id];
           else cpu.gpr[d.dst_id] =
               (int32_t)cpu.gpr[d.src1_id] / (int32_t)cpu.gpr[d.src2_id]);

  try_this("??????? ????? ????? 100 ????? 00100 11", xori,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] ^ d.imm_I);
  try_this("0000000 ????? ????? 100 ????? 01100 11", xor,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] ^ cpu.gpr[d.src2_id]);
  try_this("??????? ????? ????? 111 ????? 00100 11", andi,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] & d.imm_I);
  try_this("0000000 ????? ????? 111 ????? 01100 11", and,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] & cpu.gpr[d.src2_id]);
  try_this("??????? ????? ????? 110 ????? 00100 11", ori,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] | d.imm_I);
  try_this("0000000 ????? ????? 110 ????? 01100 11", or,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] | cpu.gpr[d.src2_id]);
  try_this("0000000 ????? ????? 010 ????? 01100 11", slt,
           cpu.gpr[d.dst_id] =
               (int32_t)cpu.gpr[d.src1_id] < (int32_t)cpu.gpr[d.src2_id] ? 1
                                                                         : 0);
  try_this("0000000 ????? ????? 011 ????? 01100 11", sltu,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] < cpu.gpr[d.src2_id] ? 1 : 0);
  try_this("??????? ????? ????? 011 ????? 00100 11", sltiu,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] < d.imm_I ? 1 : 0);
  try_this("??????? ????? ????? 010 ????? 00100 11", slti,
           cpu.gpr[d.dst_id] =
               (int32_t)cpu.gpr[d.src1_id] < (int32_t)d.imm_I ? 1 : 0);

  try_this("0000000 ????? ????? 001 ????? 00100 11", slli,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] << (d.imm_I & 0x1F));
  try_this("0000000 ????? ????? 001 ????? 01100 11", sll,
           uint32_t shift = bits<4, 0>(cpu.gpr[d.src2_id]);
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] << shift);
  try_this("0000000 ????? ????? 101 ????? 00100 11", srli,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] >> (d.imm_I & 0x1F));
  try_this("0000000 ????? ????? 101 ????? 01100 11", srl,
           uint32_t shift = bits<4, 0>(cpu.gpr[d.src2_id]);
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] >> shift);
  try_this("0100000 ????? ????? 101 ????? 00100 11", srai,
           cpu.gpr[d.dst_id] = (uint32_t)((int32_t)cpu.gpr[d.src1_id] >>
                                          (int32_t)(d.imm_I & 0x1F)));
  try_this("0100000 ????? ????? 101 ????? 01100 11", sra,
           uint32_t shift = cpu.gpr[d.src2_id] & 0x1f;
           cpu.gpr[d.dst_id] =
               (uint32_t)((int32_t)cpu.gpr[d.src1_id] >> (int32_t)shift));
  try_this("0000000 ????? ????? 110 ????? 01100 11", or,
           cpu.gpr[d.dst_id] = cpu.gpr[d.src1_id] | cpu.gpr[d.src2_id]);

  try_this("??????? ????? ????? 000 ????? 00000 11", lb,
           uint32_t addr = cpu.gpr[d.src1_id] + d.imm_I;
           int shift = (addr & 0x3) * 8; auto result = vbus.readMemory(addr, 1);
           if (result.read_nonmemory) cpu.gpr[d.dst_id] = dut.getGPR(d.dst_id);
           else cpu.gpr[d.dst_id] = sign_ext<8>((result.data >> shift) & 0xFF));
  try_this("??????? ????? ????? 100 ????? 00000 11", lbu,
           uint32_t addr = cpu.gpr[d.src1_id] + d.imm_I;
           int shift = (addr & 0x3) * 8; auto result = vbus.readMemory(addr, 1);
           if (result.read_nonmemory) cpu.gpr[d.dst_id] = dut.getGPR(d.dst_id);
           else cpu.gpr[d.dst_id] = (result.data >> shift) & 0xFF);
  try_this("??????? ????? ????? 001 ????? 00000 11", lh,
           uint32_t addr = cpu.gpr[d.src1_id] + d.imm_I;
           int shift = (addr & 0x3) * 8; auto result = vbus.readMemory(addr, 2);
           if (result.read_nonmemory) cpu.gpr[d.dst_id] = dut.getGPR(d.dst_id);
           else cpu.gpr[d.dst_id] =
               sign_ext<16>((result.data >> shift) & 0xFFFF));
  try_this("??????? ????? ????? 101 ????? 00000 11", lhu,
           uint32_t addr = cpu.gpr[d.src1_id] + d.imm_I;
           int shift = (addr & 0x3) * 8; auto result = vbus.readMemory(addr, 2);
           if (result.read_nonmemory) cpu.gpr[d.dst_id] = dut.getGPR(d.dst_id);
           else cpu.gpr[d.dst_id] = (result.data >> shift) & 0xFFFF);
  try_this("??????? ????? ????? 010 ????? 00000 11", lw,
           auto result = vbus.readMemory(cpu.gpr[d.src1_id] + d.imm_I, 4);
           if (result.read_nonmemory) cpu.gpr[d.dst_id] = dut.getGPR(d.dst_id);
           else cpu.gpr[d.dst_id] = result.data);

  try_this("??????? ????? ????? ??? ????? 11011 11", jal,
           cpu.gpr[d.dst_id] = cpu.pc + 4;
           dnpc = cpu.pc + d.imm_J);
  try_this("??????? ????? ????? 000 ????? 11001 11", jalr,
           dnpc = (cpu.gpr[d.src1_id] + d.imm_I) & (~0x1u);
           cpu.gpr[d.dst_id] = cpu.pc + 4);

  try_this("??????? ????? ????? 001 ????? 11000 11", bne,
           if (cpu.gpr[d.src1_id] != cpu.gpr[d.src2_id]) dnpc =
               cpu.pc + d.imm_B);
  try_this("??????? ????? ????? 000 ????? 11000 11", beq,
           if (cpu.gpr[d.src1_id] == cpu.gpr[d.src2_id]) dnpc =
               cpu.pc + d.imm_B);
  try_this("??????? ????? ????? 101 ????? 11000 11", bge,
           if ((int32_t)cpu.gpr[d.src1_id] >= (int32_t)cpu.gpr[d.src2_id])
               dnpc = cpu.pc + d.imm_B);
  try_this("??????? ????? ????? 100 ????? 11000 11", blt,
           if ((int32_t)cpu.gpr[d.src1_id] < (int32_t)cpu.gpr[d.src2_id]) dnpc =
               cpu.pc + d.imm_B);
  try_this("??????? ????? ????? 111 ????? 11000 11", bgeu,
           if (cpu.gpr[d.src1_id] >= cpu.gpr[d.src2_id]) dnpc =
               cpu.pc + d.imm_B);
  try_this("??????? ????? ????? 110 ????? 11000 11", bltu,
           if (cpu.gpr[d.src1_id] < cpu.gpr[d.src2_id]) dnpc =
               cpu.pc + d.imm_B);

  try_this("??????? ????? ????? 000 ????? 01000 11", sb,
           uint32_t addr = cpu.gpr[d.src1_id] + d.imm_S;
           uint32_t shift = addr & 0x3; vbus.writeMemory(
               addr & ~0x3, cpu.gpr[d.src2_id] << (shift * 8), 1 << shift));
  try_this("??????? ????? ????? 001 ????? 01000 11", sh,
           uint32_t addr = cpu.gpr[d.src1_id] + d.imm_S;
           uint32_t shift = addr & 0x3; vbus.writeMemory(
               addr & ~0x3, cpu.gpr[d.src2_id] << (shift * 8), 0x3 << shift));
  try_this("??????? ????? ????? 010 ????? 01000 11", sw,
           vbus.writeMemory((cpu.gpr[d.src1_id] + d.imm_S) & ~0x3,
                            cpu.gpr[d.src2_id], 0xF));

  try_this("0000000 00001 00000 000 00000 11100 11", ebreak,
           is_halt = true); // R(10) is $a0
  try_this("0000000 00000 00000 000 00000 11100 11", ecall,
           dnpc = isa_raise_intr(11));
  try_this("0011000 00010 00000 000 00000 11100 11", mret, dnpc = csr.mepc);
  try_this("??????? ????? ????? 001 ????? 11100 11", csrrw,
           uint32_t csr = inst >> 20;
           uint32_t &which = csr_id(csr); cpu.gpr[d.dst_id] = which;
           which = cpu.gpr[d.src1_id];);
  try_this("??????? ????? ????? 010 ????? 11100 11", csrrs,
           uint32_t csr = inst >> 20;
           uint32_t &which = csr_id(csr); cpu.gpr[d.dst_id] = which;
           which = which | cpu.gpr[d.src1_id]);
  try_this("??????? ????? ????? 001 ????? 00011 11", fence.i, cache.clear());

  try_this("??????? ????? ????? ??? ????? ????? ??", invalid,
           log_and_throw<std::logic_error>(
               "Encountered invalid instruction {:#010x} @PC={:#010x}", inst,
               cpu.pc));
  END_PATTERN
  inst_count++;

  cpu.pc = dnpc;
  cpu.gpr[0] = 0;
}