#include <am.h>
#include <nemu.h>

#define NEMUSOC_SERIAL 0x10000000
extern char _heap_start;
extern char _heap_end;
int main(const char *args);
Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  outb(NEMUSOC_SERIAL, ch);
}

void halt(int code) {
  nemu_trap(code);

  // should not reach here
  while (1);
}
static void _id_puts() {
  uint32_t mvendorid, marchid;
  asm volatile ("csrr %0, mvendorid" : "=r"(mvendorid));
  asm volatile ("csrr %0, marchid" : "=r"(marchid));
  for (int i = 7; i >= 0; i--) { 
      uint8_t nibble = (mvendorid >> (i * 4)) & 0xF;
      putch(nibble < 10 ? '0' + nibble : 'A' + nibble - 10);
  }
  putch('\n');
  for (int i = 7; i >= 0; i--) {  
      uint8_t nibble = (marchid >> (i * 4)) & 0xF;
      putch(nibble < 10 ? '0' + nibble : 'A' + nibble - 10);
  }
  putch('\n');
}
void _trm_init() {
  _id_puts();
  int ret = main(mainargs);
  halt(ret);
}
