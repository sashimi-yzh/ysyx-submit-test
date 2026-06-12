#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <riscv/riscv.h>
#include "npc.h"

int main(const char *args);

extern char _heap_start[], _heap_end[];
Area heap = RANGE(_heap_start, _heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  io_write(AM_UART_TX, ch);
}

__attribute__((naked))
void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

// static void put_csrid(void) {
//   unsigned long mvendorid = 0, marchid = 0; 
//   asm volatile("csrr %0, mvendorid" : "=r"(mvendorid));
//   asm volatile("csrr %0, marchid" : "=r"(marchid));
//   printf("[TRM] mvendorid: 0x%lx  marchid: %lu\n", mvendorid, marchid);
// }

void __am_uart_init(void);
extern void __am_asm_trap(void);
void _trm_init() {
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  __am_uart_init();
  // put_csrid();
  int ret = main(mainargs);
  halt(ret);
}
