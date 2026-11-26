#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include "ysyxsoc.h"

#define WEAK __attribute__((weak))

extern char _heap_start, _heap_end;
extern char _data_start, _data_end, _data_lma;
extern char _bss_start, _bss_end;
extern char _ssbl_start, _ssbl_end, _ssbl_lma;
extern char _text_start, _text_end, _text_lma,
            _rodata_start, _rodata_end, _rodata_lma,
            _data_start, _data_end, _data_lma;
extern char WEAK _data_extra_start, WEAK _data_extra_end, WEAK _data_extra_lma;
extern char WEAK _bss_extra_start, WEAK _bss_extra_end;

int main(const char *args);

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); 

void putch(char ch) {
  while ((*(volatile uint8_t *)(UART_BASE + UART_LSR) & UART_LSR_THRE) == 0);
  *(volatile uint8_t *)(UART_BASE + UART_TX) = ch;
}

static void uart_init() {
  *(volatile uint8_t *)(UART_BASE + UART_LCR) = UART_LCR_DLAB;          // 进入除数访问模式 (DLAB=1)
  *(volatile uint8_t *)(UART_BASE + UART_IE)  = (UART_DIVISOR >> 8) & 0xff; // 除数高字节
  *(volatile uint8_t *)(UART_BASE + UART_TX)  = UART_DIVISOR & 0xff;    // 除数低字节
  *(volatile uint8_t *)(UART_BASE + UART_LCR) = UART_LCR_8N1;           // DLAB=0, 8N1
}

void halt(int code) {
  npc_trap(code);
  while (1);  
}

void fsbl() {
  uint32_t sz = (uint32_t)(uintptr_t)&_ssbl_end - (uint32_t)(uintptr_t)&_ssbl_start;
  uint8_t *dst = (uint8_t *)&_ssbl_start;
  uint8_t *src = (uint8_t *)&_ssbl_lma;
  for (uint32_t i = 0; i < sz; i++) dst[i] = src[i];
}

void load(uint8_t *dst8, const uint8_t *src8, uint32_t size) {
  uint32_t *dst = (uint32_t *)dst8;
  const uint32_t *src = (const uint32_t *)src8;
  uint32_t n = size / 4;

  for (uint32_t i = 0; i < n; i++) {
    dst[i] = src[i];
  }
  for (uint32_t i = n * 4; i < size; i++) {
    dst8[i] = src8[i];
  }
}

void ssbl() {
  load((uint8_t *)&_text_start, (uint8_t *)&_text_lma, (uint32_t)(uintptr_t)&_text_end - (uint32_t)(uintptr_t)&_text_start);
  load((uint8_t *)&_rodata_start, (uint8_t *)&_rodata_lma, (uint32_t)(uintptr_t)&_rodata_end - (uint32_t)(uintptr_t)&_rodata_start);
  load((uint8_t *)&_data_start, (uint8_t *)&_data_lma, (uint32_t)(uintptr_t)&_data_end - (uint32_t)(uintptr_t)&_data_start);
  load((uint8_t *)&_data_extra_start, (uint8_t *)&_data_extra_lma, (uint32_t)(uintptr_t)&_data_extra_end - (uint32_t)(uintptr_t)&_data_extra_start);

  for (char *p = &_bss_start; p < &_bss_end; p++) *p = 0;
  for (char *p = &_bss_extra_start; p < &_bss_extra_end; p++) *p = 0;

  asm volatile("fence.i" ::: "memory");
}

void _trm_init() {
  uart_init();
  int ret = main(mainargs);
  halt(ret);
}
