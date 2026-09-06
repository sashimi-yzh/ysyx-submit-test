#include "common.h"
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string.h>

const char *regs[] = {"$0", "ra", "sp",  "gp",  "tp", "t0", "t1", "t2",
                      "s0", "s1", "a0",  "a1",  "a2", "a3", "a4", "a5",
                      "a6", "a7", "s2",  "s3",  "s4", "s5", "s6", "s7",
                      "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

#define REGNUM 32

extern Cpu *cpu;
void display_reg() {
  for (int i = 0; i < REGNUM; i++) {
    std::cout << std::left << std::setfill(' ') << std::setw(3) << regs[i];
    std::cout << " 0x" << std::right << std::hex << std::setfill('0') << std::setw(8)
              << cpu->con.gpr[i];

    std::cout << " " << std::dec << cpu->con.gpr[i];
    std::cout << std::endl;
  }
}

uint32_t npc_reg_str2val(char *regname, bool *success) {
  if (strcmp(regname, "$pc") == 0)
    return cpu->con.pc;
  for (int i = 0; i < REGNUM; i++) {
    if (strcmp(regname + 1, regs[i]) == 0)
      return cpu->con.gpr[i];
  }
  std::cout << "[error]unfind reg name " << regname << std::endl;
  *success = false;
  return 0;
}
