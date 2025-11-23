#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>
#include "soc.h"
#include <string.h>
#include <stdio.h>



extern char _heap_start;
extern char _psram_end;
extern char _sdram_end;
extern uint32_t _bl_s[];
extern uint32_t _bl_s_load[];
extern uint32_t _ebl_s[];
extern uint32_t _text[];
extern uint32_t _text_load[];
extern uint32_t _etext[];
extern uint32_t _data[];
extern uint32_t _data_load[];
extern uint32_t _edata[];
extern uint32_t _data_extra[];
extern uint32_t _data_extra_load[];
extern uint32_t _edata_extra[];
extern uint32_t _bss_start[];
extern uint32_t _ebss[];

int main(const char *args);

extern char _sram_start;
#define SRAM_SIZE (8 * 1024)
#define SRAM_END ((uintptr_t)&_sram_start + SRAM_SIZE)

Area heap = RANGE(&_heap_start, &_sdram_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

void _trm_init(void);

void bl_memory_copy(uint32_t *dst, uint32_t *src, uint32_t *end) {
  uint32_t size = end - dst;
  uint32_t i;
  
  for (i = 0; i < size; i++) {
      dst[i] = src[i];
  }
}

void bl_memory_set(uint32_t *dst, uint32_t value, uint32_t size) {
  uint32_t i;

  for (i = 0; i < size; i++) {
      dst[i] = 0;
  }
}

void ssbl(void) {
  bl_memory_copy(_text, _text_load, _etext);
  bl_memory_copy(_data, _data_load, _edata);
  bl_memory_copy(_data_extra, _data_extra_load, _edata_extra);

  bl_memory_set(_bss_start, 0, _ebss - _bss_start);

  _trm_init();
}

void fsbl(void) {
  bl_memory_copy(_bl_s, _bl_s_load, _ebl_s);
  ssbl();
}


void putch(char ch) {
  while (!(inb(UART_REG_LSR) & 0x20)) {
  }
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}

void uart_init() {
  uint16_t divisor = 1;  // 修改成 16
  // 打开 DLAB
  outb(UART_REG_LC, inb(UART_REG_LC) | 0x80);
  // 写高低字节
  outb(UART_REG_DL2, (divisor >> 8) & 0xFF);
  outb(UART_REG_DL1, divisor & 0xFF);
  // 关闭 DLAB
  outb(UART_REG_LC, inb(UART_REG_LC) & ~0x80);

  // 设置 8N1 格式
  outb(UART_REG_LC, 0x03); // 8 bit, no parity, 1 stop bit
}


void print_csr() {
  uint32_t mvendorid, marchid;
  asm volatile ("csrr %0, mvendorid" : "=r" (mvendorid): : );
  asm volatile ("csrr %0, marchid" : "=r" (marchid) : : );
  printf("mvendorid = %c%c%c%c\n",
    (char)(mvendorid >> 24),
    (char)(mvendorid >> 16),
    (char)(mvendorid >> 8),
    (char)mvendorid);
  printf("marchid   = %d\n", marchid);
}

void _trm_init() {
  uart_init();
  print_csr();
  int ret = main(mainargs);
  halt(ret);
}