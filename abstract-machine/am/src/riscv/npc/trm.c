#include <am.h>
#include <klib-macros.h>
#include "npc.h"

extern char _heap_start;
int main(const char *args);

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  // 使用ebreak指令通知NPC程序结束
  npc_trap(code);
  while (1);  // 防止继续执行
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
