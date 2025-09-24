#include <am.h>
#include <klib-macros.h>

#define SERIAL_PORT 0x10000000
static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

extern char _bss_start [];
extern char _bss_end [];
extern char _bss_size [];

void init() {
  if (_bss_start != _bss_end) {
    for (int i = 0; i < (size_t) _bss_size; i++) {
      _bss_start[i] = 0;
    }
  }
}

void _trm_init() {
  init();
  int ret = main(mainargs);
  halt(ret);
}
