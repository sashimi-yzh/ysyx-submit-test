#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <riscv/riscv.h>
#include "npc.h"

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (4 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

__attribute__((naked))
void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

// static inline void put_csrid(void) {
//   unsigned long long mvendorid = 0, marchid = 0; 
//   asm volatile("csrr %0, mvendorid" : "=r"(mvendorid));
//   asm volatile("csrr %0, marchid" : "=r"(marchid));
//   printf("[TRM] mvendorid: 0x%llx  marchid: %llu\n", mvendorid, marchid);
// }

extern void __am_asm_trap(void);
void _trm_init() {
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  // put_csrid();
  int ret = main(mainargs);
  halt(ret);
}
