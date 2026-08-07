#pragma once
#include "memory.hpp"
#include <bits/stdc++.h>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <dlfcn.h>
#include <format.hpp>
#include <stdint.h>
static const char *regs[] = {"$0", "ra", "sp",  "gp",  "tp", "t0", "t1", "t2",
                             "s0", "s1", "a0",  "a1",  "a2", "a3", "a4", "a5",
                             "a6", "a7", "s2",  "s3",  "s4", "s5", "s6", "s7",
                             "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};
struct CSRS {
  uint32_t mtvec;
  uint32_t mepc;
  uint32_t mstatus;
  uint32_t mcause;
  uint32_t mvendorid;
  uint32_t marchid;
};

struct CPU_state {
  uint32_t gpr[32];
  uint32_t npc;
  CSRS csrs;
  bool operator==(const CPU_state &ref) {
    for (int i = 0; i < 16; i++) {
      if (gpr[i] != ref.gpr[i])
        return 0;
    }
    for (int i = 0; i < sizeof(CSRS) / sizeof(uint32_t); i++) {
      uint32_t *_dut = (uint32_t *)&csrs;
      uint32_t *_ref = (uint32_t *)&ref.csrs;
      if (_dut[i] != _ref[i])
        return 0;
    }
    return npc == ref.npc;
  }
  void compare(const CPU_state &ref) {
    for (int i = 0; i < 16; i++) {
      print(gpr[i] != ref.gpr[i] ? format::red : "", regs[i], "\t", hex(gpr[i]),
            "\t\t", hex(ref.gpr[i]), gpr[i] != ref.gpr[i] ? format::clear : "");
    }
    std::string csrNames[] = {"mtvec",  "mepc",      "mstatus",
                              "mcause", "mvendorid", "marchid"};
    for (int i = 0; i < sizeof(CSRS) / sizeof(uint32_t); i++) {
      uint32_t *_dut = (uint32_t *)&csrs;
      uint32_t *_ref = (uint32_t *)&ref.csrs;
      print(_dut[i] != _ref[i] ? format::red : "", csrNames[i], "\t",
            hex(_dut[i]), "\t\t", hex(_ref[i]),
            _dut[i] != _ref[i] ? format::clear : "");
    }
    print(npc != ref.npc ? format::red : "", "npc", "\t", hex(npc), "\t\t",
          hex(ref.npc), npc != ref.npc ? format::clear : "");
  }
};
class Difftest {
  void *handle;
  CPU_state cpuState;
  void (*difftest_init)(int) = NULL;
  void (*difftest_memcpy)(uint32_t addr, void *buf, uint32_t n, bool direction);
  void (*difftest_regcpy)(void *dut, bool direction);
  void (*difftest_exec)(uint64_t n);

public:
  enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

  Difftest(std::string filename) {
    this->handle = dlopen(filename.c_str(), RTLD_NOW);
    if (!this->handle) {
      std::cout << "dlopen failed:" << dlerror() << std::endl;
      assert(this->handle);
    }
    this->difftest_init = (void (*)(int))dlsym(handle, "difftest_init");
    this->difftest_memcpy = (void (*)(uint32_t, void *, uint32_t, bool))dlsym(
        handle, "difftest_memcpy");
    this->difftest_regcpy =
        (void (*)(void *, bool))dlsym(handle, "difftest_regcpy");
    this->difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  }
  ~Difftest() { dlclose(handle); }
  void init(int port) { this->difftest_init(port); }
  void loadMemory() {
    Memory &mem = Memory::getInstance();
    for (int i = 0; i < mem.size(); i += 4) {
      difftest_memcpy(NPC_RESET_VECTOR + i, mem.getBuf() + i, 4,
                      Difftest::DIFFTEST_TO_REF);
    }
  }
  void exec(int n) { this->difftest_exec(n); }
  const CPU_state &reg() {
    this->difftest_regcpy(&this->cpuState, DIFFTEST_TO_DUT);
    return cpuState;
  }
  const void syncReg(CPU_state cpu) {
    this->difftest_regcpy(&cpu, DIFFTEST_TO_REF);
  }
  uint32_t pmem_read(int addr) {
    uint32_t data;
    this->difftest_memcpy(addr, &data, 4, DIFFTEST_TO_DUT);
    return data;
  }
};
