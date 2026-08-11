#include <am.h>
#include "include/npc.h"
#include <klib.h>
#include <klib-macros.h>

extern char _heap_start;
extern char _heap_end;
int main(const char *args);

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER);

void _trm_init() {
  uart_init();
  nvboard_init();
  int ret = main(mainargs);
  halt(ret);
}
