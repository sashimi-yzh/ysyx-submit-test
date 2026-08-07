#include "fast_trace.hpp"
#include <btrace.hpp>
#include <difftest.hpp>
#include <itrace.hpp>
#include <memory.hpp>

void fast_itrace() {
  Itrace &itrace = Itrace::getInstance();
  Difftest ref("./riscv32-nemu-interpreter-so");
  ref.init(0);
  ref.loadMemory();
  uint32_t lastNpc = ref.reg().npc;
  while (1) {
    ref.exec(1);
    auto cpu = ref.reg();
    if (cpu.npc == lastNpc)
      break;
    itrace.trace(cpu.npc, Itrace::FLAGS::TEXT);
    lastNpc = cpu.npc;
  }
}

void fast_btrace() {
  Btrace &btrace = Btrace::getInstance();
  Difftest ref("./riscv32-nemu-interpreter-so");
  ref.init(0);
  ref.loadMemory();
  uint32_t lastNpc = ref.reg().npc;
  while (1) {
    ref.exec(1);
    auto cpu = ref.reg();
    if (cpu.npc == lastNpc)
      break;
    uint32_t inst   = ref.pmem_read(lastNpc);
    uint32_t opcode = inst & 0x7f;
    bool isBType = (opcode == 0x63);
    bool isJal   = (opcode == 0x6f);
    bool isJalr  = (opcode == 0x67) && ((inst >> 12) & 0x7) == 0;
    if (isBType || isJal || isJalr)
      btrace.trace(lastNpc, inst, Btrace::FLAGS::TEXT);
    lastNpc = cpu.npc;
  }
}
