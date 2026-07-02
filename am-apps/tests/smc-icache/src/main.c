#include <am.h>
#include <stdint.h>
#include <klib.h>

/*
 * npc executes from 0x8000_0000 and marks that region cacheable.
 * ysyxsoc boots through flash, but the runtime image executes from
 * 0xa000_0000 SDRAM, which is also cacheable.
 *
 * Default mode inserts fence.i after the self-modifying store and should
 * print a single 'A' before returning. mainargs=repro skips fence.i and
 * keeps reproducing the stale-icache bug.
 */

#define UART_MMIO_ADDR 0x10000000u
#define RET_INSN       0x00008067u

static int is_repro_mode(const char *args) {
  return args != NULL && strcmp(args, "repro") == 0;
}

__attribute__((naked, noinline, aligned(4))) static void smc_entry_repro(void) {
  asm volatile(
      ".balign 4\n"
      "li a1, %[uart]\n"
      "li t1, 0x41\n"
      "la a2, .Lagain_repro\n"
      "li t2, %[ret]\n"
      ".balign 4\n"
      ".Lagain_repro:\n"
      "sb t1, 0(a1)\n"
      "sw t2, 0(a2)\n"
      "j .Lagain_repro\n"
      :
      : [uart] "i"(UART_MMIO_ADDR), [ret] "i"(RET_INSN)
      : "memory", "a1", "a2", "t1", "t2");
}

__attribute__((naked, noinline, aligned(4))) static void smc_entry_fencei(void) {
  asm volatile(
      ".balign 4\n"
      "li a1, %[uart]\n"
      "li t1, 0x41\n"
      "la a2, .Lagain_fencei\n"
      "li t2, %[ret]\n"
      ".balign 4\n"
      ".Lagain_fencei:\n"
      "sb t1, 0(a1)\n"
      "sw t2, 0(a2)\n"
      "fence.i\n"
      "j .Lagain_fencei\n"
      :
      : [uart] "i"(UART_MMIO_ADDR), [ret] "i"(RET_INSN)
      : "memory", "a1", "a2", "t1", "t2");
}

int main(const char *args) {
  if (is_repro_mode(args)) {
    smc_entry_repro();
  } else {
    smc_entry_fencei();
  }

  *(volatile uint8_t *)(uintptr_t)UART_MMIO_ADDR = (uint8_t)'\n';
  return 0;
}
