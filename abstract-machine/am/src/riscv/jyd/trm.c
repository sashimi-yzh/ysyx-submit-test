#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include "jyd.h"
extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  //while(1);
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  asm volatile("mv a0, %0" : : "r"(code));
  asm volatile("ebreak");
  while (1);
}

void _trm_init() {
  // uint32_t ysyx_name,ysyx_id;
  // asm volatile("csrr %0,mvendorid" : "=r"(ysyx_name));
  // asm volatile("csrr %0,marchid" : "=r"(ysyx_id));
  // printf("===YSYX:%c%c%c%c\n",(ysyx_name>>24)&0xff,(ysyx_name>>16)&0xff,(ysyx_name>>8)&0xff,ysyx_name&0xff);
  // printf("===ID:%d\n",ysyx_id);
  int ret = main(mainargs);
  halt(ret);
}
