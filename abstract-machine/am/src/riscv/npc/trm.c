#include <am.h>
#include <klib-macros.h>
#include "../riscv.h"

#define SERIAL_PORT 0x10000000

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS


void putch(char ch) {
    outb(SERIAL_PORT, ch);
}

void npc_trap(int code) {
    asm volatile("mv a0, %0; ebreak" : :"r"(code));
}

void halt(int code) {
  npc_trap(code);
  
  // should not reach here
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
