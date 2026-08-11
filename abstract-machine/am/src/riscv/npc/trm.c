#include <am.h>
#include "include/npc.h"
#include <klib.h>
#include <klib-macros.h>

extern char _heap_start;
int main(const char *args);

Area heap = RANGE(&_heap_start, NPC_PMEM_END_ADDR);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void _trm_init() {
  print_boot_banner();
  int ret = main(mainargs);
  halt(ret);
}
