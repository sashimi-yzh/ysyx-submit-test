#include <am.h>
#include <klib-macros.h>
#include <stdio.h>

int main(const char *args);

extern char _heap_start;
extern char _heap_end;

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] =
    TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

extern char _my_ext_serial_port;
#define SERIAL_PORT ((uintptr_t)(&_my_ext_serial_port))

void putch(char ch) { *(uint8_t *)(SERIAL_PORT + 0x00) = ch; }
// unsupported now, just return 0xff to indicate no char available
char try_getch() { return 0xff; }

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : : "r"(code));
  while (1) {
  } // make sure no return
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
