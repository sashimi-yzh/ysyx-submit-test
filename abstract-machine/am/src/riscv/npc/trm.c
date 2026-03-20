#include <am.h>
#include <klib-macros.h>
#include <stdio.h>

#include <kasan_init.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END ((uintptr_t) & _pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] =
    TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

#define SERIAL_PORT 0x10000000

void putch(char ch) { *(uint8_t *)(SERIAL_PORT + 0x00) = ch; }
// unsupported now, just return 0xff to indicate no char available
char try_getch() { return 0xff; }

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : : "r"(code));
  while (1) {
  } // make sure no return
}

void _trm_init() {
	kasan_init();

  uint32_t mvendor_id, marchid;
  asm volatile("csrr %0, mvendorid" : "=r"(mvendor_id));
  asm volatile("csrr %0, marchid" : "=r"(marchid));
  char *vendor = (char *)&mvendor_id;
  printf("mvendor: 0x%08x (%c%c%c%c)\n", mvendor_id, vendor[3], vendor[2],
         vendor[1], vendor[0]);
  printf("marchid: %d\n", marchid);
  int ret = main(mainargs);
  halt(ret);
}
