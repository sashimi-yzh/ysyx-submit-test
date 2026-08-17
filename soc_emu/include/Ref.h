#pragma once

#include "BTB.h"
#include "Cache.h"
#include "Setup.h"
#include <InstPattern/InstPattern.h>
#include <VirtualBus.h>
#include <cstdint>
#include <format>
#include <my_utils.h>
#include <stdexcept>
#include <sys/types.h>
// std::ofstream ref_trace_file;
class Ref {
public:
  Ref()
      : csr({.mstatus = 0x1800,
             .mvendorid = 0x79737978,
             .marchid = 0x17eb198}) {}

  void init(Config config) {
    icache.init(config.nr_icacheline_words_2pow, config.nr_icachelines_2pow);
    icache_hit = 0;
    dcache.init(config.nr_dcacheline_words_2pow, config.nr_dcachelines_2pow);
    dcache_hit = 0;
    btb.init(config.nr_btbsize_2pow);
    inst_count = 0;
    data_fetch_count = 0;
    vbus.init_flash(config.image_path);
  }
  bool isHalt() { return is_halt; }
  unsigned long long getICacheHit() { return icache_hit; }
  unsigned long long getDCacheHit() { return dcache_hit; }
  unsigned long long getPCPredictMiss() { return btb.getMissCount(); }
  unsigned long long getPCPredictHit() { return btb.getHitCount(); }

  unsigned long long getDataFetchCount() { return data_fetch_count; }
  uint32_t getGPR(int id) { return cpu.gpr[id]; }
  uint32_t getPC() { return cpu.pc; };

  void reset() {
    inst_count = 0;
    for (int i = 0; i < 32; i++) {
      cpu.gpr[i] = 0;
    }
    icache.reset();
    icache_hit = 0;
    dcache.reset();
    dcache_hit = 0;
    btb.reset();
    cpu.pc = 0x30000000;
  };
  void step();
  unsigned long long instrCount() { return inst_count; }

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
    std::array<uint32_t, 32> gpr;
    uint32_t pc;
  };

private:
  unsigned long long inst_count;

  unsigned long long icache_hit;
  unsigned long long dcache_hit;
  unsigned long long data_fetch_count;
  bool is_halt;

  CPU_State cpu;
  VirtualBus vbus;
  Cache icache, dcache;
  BTB btb;
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
  if (icache.fetch(cpu.pc))
    icache_hit++;
  uint32_t ifnst_fetch = vbus.readMemory(cpu.pc, 4);
  const uint32_t inst = ifnst_fetch;
  Decoded d = decode(inst);

  uint32_t dnpc = cpu.pc + 4;
  bool data_access = false;
  uint32_t address;
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
           int shift = (addr & 0x3) * 8;
           uint32_t result = vbus.readMemory(addr, 1); data_access = true;
           address = addr;
           cpu.gpr[d.dst_id] = sign_ext<8>((result >> shift) & 0xFF));
  try_this("??????? ????? ????? 100 ????? 00000 11", lbu,
           uint32_t addr = cpu.gpr[d.src1_id] + d.imm_I;
           int shift = (addr & 0x3) * 8;
           uint32_t result = vbus.readMemory(addr, 1); data_access = true;
           address = addr; cpu.gpr[d.dst_id] = (result >> shift) & 0xFF);
  try_this("??????? ????? ????? 001 ????? 00000 11", lh,
           uint32_t addr = cpu.gpr[d.src1_id] + d.imm_I;
           int shift = (addr & 0x3) * 8;
           uint32_t result = vbus.readMemory(addr, 2); data_access = true;
           address = addr;
           cpu.gpr[d.dst_id] = sign_ext<16>((result >> shift) & 0xFFFF));
  try_this("??????? ????? ????? 101 ????? 00000 11", lhu,
           uint32_t addr = cpu.gpr[d.src1_id] + d.imm_I;
           int shift = (addr & 0x3) * 8;
           uint32_t result = vbus.readMemory(addr, 2); data_access = true;
           address = addr; cpu.gpr[d.dst_id] = (result >> shift) & 0xFFFF);
  try_this("??????? ????? ????? 010 ????? 00000 11", lw,
           uint32_t result = vbus.readMemory(cpu.gpr[d.src1_id] + d.imm_I, 4);
           cpu.gpr[d.dst_id] = result);
  try_this("??????? ????? ????? ??? ????? 11011 11", jal,
           uint32_t target = cpu.pc + d.imm_J;
           cpu.gpr[d.dst_id] = cpu.pc + 4; dnpc = cpu.pc + d.imm_J;
           btb.predict_jal(cpu.pc, target));
  try_this("??????? ????? ????? 000 ????? 11001 11", jalr,
           dnpc = (cpu.gpr[d.src1_id] + d.imm_I) & (~0x1u);
           cpu.gpr[d.dst_id] = cpu.pc + 4; btb.predict_jalr(cpu.pc, dnpc));

  try_this("??????? ????? ????? 001 ????? 11000 11", bne,
           bool jump = cpu.gpr[d.src1_id] != cpu.gpr[d.src2_id];
           uint32_t target = cpu.pc + d.imm_B; if (jump) dnpc = target;
           btb.predict_branch(cpu.pc, target, jump));
  try_this("??????? ????? ????? 000 ????? 11000 11", beq,
           bool jump = cpu.gpr[d.src1_id] == cpu.gpr[d.src2_id];
           uint32_t target = cpu.pc + d.imm_B; if (jump) dnpc = target;
           btb.predict_branch(cpu.pc, target, jump));
  try_this("??????? ????? ????? 101 ????? 11000 11", bge,
           bool jump =
               (int32_t)cpu.gpr[d.src1_id] >= (int32_t)cpu.gpr[d.src2_id];
           uint32_t target = cpu.pc + d.imm_B; if (jump) dnpc = target;
           btb.predict_branch(cpu.pc, target, jump));
  try_this("??????? ????? ????? 100 ????? 11000 11", blt,
           bool jump =
               (int32_t)cpu.gpr[d.src1_id] < (int32_t)cpu.gpr[d.src2_id];
           uint32_t target = cpu.pc + d.imm_B; if (jump) dnpc = target;
           btb.predict_branch(cpu.pc, target, jump));
  try_this("??????? ????? ????? 111 ????? 11000 11", bgeu,
           bool jump = cpu.gpr[d.src1_id] >= cpu.gpr[d.src2_id];
           uint32_t target = cpu.pc + d.imm_B; if (jump) dnpc = target;
           btb.predict_branch(cpu.pc, target, jump));
  try_this("??????? ????? ????? 110 ????? 11000 11", bltu,
           bool jump = cpu.gpr[d.src1_id] < cpu.gpr[d.src2_id];
           uint32_t target = cpu.pc + d.imm_B; if (jump) dnpc = target;
           btb.predict_branch(cpu.pc, target, jump));

  try_this("??????? ????? ????? 000 ????? 01000 11", sb,
           uint32_t addr = cpu.gpr[d.src1_id] + d.imm_S;
           uint32_t shift = addr & 0x3; data_access = true; address = addr;
           vbus.writeMemory(addr & ~0x3, cpu.gpr[d.src2_id] << (shift * 8),
                            1 << shift));
  try_this("??????? ????? ????? 001 ????? 01000 11", sh,
           uint32_t addr = cpu.gpr[d.src1_id] + d.imm_S;
           uint32_t shift = addr & 0x3; data_access = true; address = addr;
           vbus.writeMemory(addr & ~0x3, cpu.gpr[d.src2_id] << (shift * 8),
                            0x3 << shift));
  try_this("??????? ????? ????? 010 ????? 01000 11", sw,
           uint32_t addr = (cpu.gpr[d.src1_id] + d.imm_S) & ~0x3;
           data_access = true; address = addr;
           vbus.writeMemory(addr, cpu.gpr[d.src2_id], 0xF));

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
  try_this("??????? ????? ????? 001 ????? 00011 11", fence.i, icache.clear());
  try_this("??????? ????? ????? ??? ????? ????? ??", invalid,
           log_and_throw<std::logic_error>(
               "Encountered invalid instruction {:#010x} @PC={:#010x}", inst,
               cpu.pc));
  END_PATTERN
  inst_count++;
  if (data_access) {
    data_fetch_count++;
    if (dcache.fetch(address))
      dcache_hit++;
  }

  cpu.pc = dnpc;
  cpu.gpr[0] = 0;
}