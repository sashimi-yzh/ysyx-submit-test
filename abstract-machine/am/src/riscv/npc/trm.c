#include <am.h>
#include <klib-macros.h>
#include <npc.h>
#include <riscv/riscv.h>
extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  outb(SERIAL_PORT,ch);
}

void halt(int code) {
  asm volatile("ebreak");
  while (1);
}

void _trm_init() {
  char mvendorid[5];
  mvendorid[4] = 0;
  uint32_t marchid;
  asm volatile("csrr %0, mvendorid":"=r"(*(uint32_t *)mvendorid)::);
  asm volatile("csrr %0, marchid":"=r"(marchid)::);
  putch(mvendorid[3]); putch(mvendorid[2]); putch(mvendorid[1]); putch(mvendorid[0]);
  putch('_');
  printf("%u\n",marchid);
  int ret = main(mainargs);
  halt(ret);
}
