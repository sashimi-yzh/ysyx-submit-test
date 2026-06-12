#include <am.h>
#include <nemu.h>

extern char _heap_start;
int main(const char *args);

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  nemu_trap(code);

  // should not reach here
  while (1);
}

extern void __am_asm_trap(void);

void _trm_init() {
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  int ret = main(mainargs);
  halt(ret);
}
