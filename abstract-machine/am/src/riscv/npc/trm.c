#include <am.h>
#include <klib-macros.h>
#include <stdio.h>
#include "npc.h"

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
// #define SERIAL_PORT 0x00003f8

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  *(uint8_t *)SERIAL_PORT = ch;
}

void halt(int code) {
  npc_trap(code);
  while (1);
}

void _trm_init() {
  // ----- 打印 CPU ID -----
  // int vendor_id, arch_id;
  // char num[4];

  // asm volatile("csrr %0, mvendorid" : "=r"(vendor_id));
  // asm volatile("csrr %0, marchid"   : "=r"(arch_id));

  // for (int i = 0; i < 4; i ++) num[i] = (vendor_id >> (8 * i)) & 0xFF;
  // for (int i = 3; i >= 0; i --) printf("%c", num[i]);
  // printf("\n");
  // printf("NPC ID: %d\n", arch_id);
  // ----------------------

  int ret = main(mainargs);
  halt(ret);
}
