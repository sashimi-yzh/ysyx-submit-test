#include <am.h>
#include <klib.h>
#include <klib-macros.h>

extern char _heap_start;
int main(const char *args);
void uart16550_init();
void uart16550_putchar(char ch);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) {
  uart16550_putchar(ch);
}

void halt(int code) {
  printf("Exit with code = %d\n", code);

  volatile uint32_t *finisher = (void *)0x100000l;
  uint32_t status = (code == 0 ? 0x5555 : (code << 16) | 0x3333);
  finisher[0] = status;

  // should not reach here
  while (1);
}

void _trm_init() {
  uart16550_init();
  int ret = main(mainargs);
  halt(ret);
}
