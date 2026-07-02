#include <isa.h>
static void restart() {
  /* The zero register is always 0. */
  cpu.gpr[0] = 0;
  cpu.mstatus = 0x1800;
  cpu.mtvec = 1;
  cpu.mepc = 0;
  cpu.mcause = 0;
}

void init_isa() {
  /* Initialize this virtual computer system. */
  restart();
}
