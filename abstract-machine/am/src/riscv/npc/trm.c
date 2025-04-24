#include <am.h>
#include <klib-macros.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
#ifndef __ICS_EXPORT
  volatile uint8_t *p = (uint8_t *)0x10000000ul;
  *p = ch;
#endif
}

void halt(int code) {
#ifndef __ICS_EXPORT
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
#endif
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
