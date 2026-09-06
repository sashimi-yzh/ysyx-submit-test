#include "am.h"
#include <klib-macros.h>
#include <riscv/riscv.h>

#define UART_BASE 0x10000000
#define UART_TX 0
#define UART_RX 0
#define UART_LCR 3
#define UART_LSR 5
#define UART_DLL 0
#define UART_DLM 1
#define UART_FCR 2
#define UART_DIVISOR 1

#define UART_LSB 0
#define UART_MSB 1

extern char _heap_start;
extern char _heap_end;
int main(const char *args);

extern char _pmem_start;
// #define PMEM_SIZE (8 * 1024 * 1024)
// #define PMEM_END ((uintptr_t) & _pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, &_heap_end);
#ifndef MAINARGS
#define MAINARGS ""
#endif

static const char mainargs[] = "test";

void serial_init() {
  *(volatile unsigned char *)(UART_BASE + UART_LCR) = 0b10000011;
  *(volatile unsigned char *)(UART_BASE + UART_MSB) = UART_DIVISOR >> 8;
  *(volatile unsigned char *)(UART_BASE + UART_LSB) = UART_DIVISOR & 0xff;
  *(volatile unsigned char *)(UART_BASE + UART_LCR) = 0b00000011;
}

void putch(char ch) {
  while ((*(volatile unsigned char *)(UART_BASE + UART_LSR) & 0x60) == 0)
    ;
  *(volatile unsigned char *)(UART_BASE + UART_TX) = ch;
}

void halt(int code) {
  while (1)
    ;
}

void display_ysyx() {
  uint32_t ysyx_ascll;
  uint32_t ysyx_num;
  asm volatile("csrr %0, 0xf11" : "=r"(ysyx_ascll));
  asm volatile("csrr %0, 0xf12" : "=r"(ysyx_num));
  for (int i = 0; i < 8; i++) {
    putch((ysyx_ascll >> ((4 - i) * 8)) & 0xFF);
  }

  char buffer[10];
  int i = 0;
  while (ysyx_num > 0) {
    buffer[i] = (ysyx_num % 10) + '0';
    ysyx_num /= 10;
    i++;
  }
  for (int j = i - 1; j >= 0; j--) {
    putch(buffer[j]);
  }
  putch('\n');
}

// i want to detect the state
#define LOAD_MAGIC_NUMBER 0b1110101011

__attribute__((section(".stage1"))) void _trm_init() {
  *(volatile uint16_t *)0x10002000 = LOAD_MAGIC_NUMBER;
  loader_init();
  serial_init();
  *(volatile uint16_t *)0x10002000 = 0;
  // display_ysyx();
  int ret = main(mainargs);
  halt(ret);
}
