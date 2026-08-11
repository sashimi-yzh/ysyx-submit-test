#include <isa.h>
#include <string.h>
// inital the isa cpu struct is in (npc/csrc/isa/riscv32/include/isa-def.h)
void init_isa() {
  memset(&cpu, 0, sizeof(cpu));
  cpu.mstatus = 3u << 11;
  cpu.mtvec = 1;
}
