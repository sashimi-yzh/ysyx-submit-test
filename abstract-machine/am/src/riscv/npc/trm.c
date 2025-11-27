#include <am.h>
#include <klib-macros.h>
#include "../riscv.h"

extern char _heap_start;
int main(const char *args);

#define DEV_SERIAL (0xa00003f8)

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void putch(char ch) {
  outb(DEV_SERIAL, ch);
}

char getch(){
  return (char)inb(DEV_SERIAL);
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
