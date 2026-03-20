#include <am.h>
#include <nemu.h>

#include <kasan_init.h>

extern char _heap_start;
extern char __heap_end;
int main(const char *args);

Area heap = RANGE(&_heap_start, &__heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  nemu_trap(code);

  // should not reach here
  while (1);
}
void _trm_init() { 
	kasan_init();
  int ret = main(mainargs);
  halt(ret);
}
