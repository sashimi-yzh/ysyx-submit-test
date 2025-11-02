#include <am.h>
#include <nemu.h>

extern char _heap_start;
int main(const char *args);

Area heap = RANGE(&_heap_start, PMEM_END);

static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void putch(char ch) {
  //printf("in am/src/platform/nemu/trm.c");
  outb(SERIAL_PORT, ch);
}

char getch(void) {
  return inb(SERIAL_PORT);
}

void halt(int code) {
  nemu_trap(code);

  // should not reach here
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);//set the rule that prog starts with main
  halt(ret);
}
