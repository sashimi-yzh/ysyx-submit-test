#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include "ysyxsoc.h"
extern char _heap_start;
extern char _heap_end;
extern char _stack_top;
extern char _stack_pointer;
int main(const char *args);

extern char _sram_start;
extern char _psram_start;
extern char _rodata_vma_start;
extern char _rodata_vma_end;
extern char _rodata_lma_start;
extern char _rodata_lma_end;
extern char _data_vma_start;
extern char _data_vma_end;
extern char _data_lma_start;
extern char _data_lma_end;
extern char _bss_vma_start;
extern char _bss_vma_end;
extern char _bss_lma_start;
extern char _bss_lma_end;

// #define SRAM_SIZE (8 * 1024 * 1024)
// #define SRAM_END  ((uintptr_t)&_sram_start + SRAM_SIZE)
// #define PSRAM_SIZE (4 * 1024 * 1024 * 1024)
// #define PSRAM_END  ((uintptr_t)&_psram_start + PSRAM_SIZE)

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] __attribute__((section(".text.mainargs"))) = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS


void putch(char ch) {
  // while(1);
  while(((inb(SERIAL_PORT + 5)>>5) & 0x01)!=1);
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  asm volatile("mv a0, %0" : : "r"(code));
  asm volatile("ebreak");
  while (1);
}

void _trm_init() {
  uint32_t ysyx_name,ysyx_id;
  asm volatile("csrr %0,mvendorid" : "=r"(ysyx_name));
  asm volatile("csrr %0,marchid" : "=r"(ysyx_id));
  ioe_init();
  
  printf("data:[0x%08x-0x%08x) -> [0x%08x-0x%08x)\n",(uint32_t)(void*)(&_data_lma_start),(uint32_t)(void*)(&_data_lma_end),(uint32_t)(void*)(&_data_vma_start),(uint32_t)(void*)(&_data_vma_end));
  printf("bss:[0x%08x-0x%08x) -> [0x%08x-0x%08x)\n",(uint32_t)(void*)(&_bss_lma_start),(uint32_t)(void*)(&_bss_lma_end),(uint32_t)(void*)(&_bss_vma_start),(uint32_t)(void*)(&_bss_vma_end));
  printf("heap:[0x%08x-0x%08x)\n",(uint32_t)(void*)(&_heap_start),(uint32_t)(void*)(&_heap_end));
  printf("stack:[0x%08x-0x%08x)\n",(uint32_t)(void*)(&_stack_top),(uint32_t)(void*)(&_stack_pointer));
  
  printf("===YSYX:%c%c%c%c\n",(ysyx_name>>24)&0xff,(ysyx_name>>16)&0xff,(ysyx_name>>8)&0xff,ysyx_name&0xff);
  printf("===ID:%d\n",ysyx_id);

  

  int ret = main(mainargs);
  halt(ret);
}
