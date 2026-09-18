#include <am.h>
#include <klib-macros.h>
#include <stdio.h>
#include "ysyxsoc.h"

int main(const char *args);

Area heap = RANGE(&_heap_start, HEAP_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

// 初始化 uart
void uart_init() {
  *(volatile uint8_t *) (UART_LCR) = 0x80; // 设置 DLAB = 1
  *(volatile uint8_t *) (UART_LSB) = 0x01; // DLL = 1
  *(volatile uint8_t *) (UART_MSB) = 0x00; // DLM
  *(volatile uint8_t *) (UART_LCR) = 0x03; // DLAB = 0, 8N1
  *(volatile uint8_t *) (UART_MSB) = 0x00; // 禁用中断
}

void putch(char ch) {
  while (!(*(volatile uint8_t *) (UART_LSR) & 0x20)); // 等待 TX FIFO empty
  *(volatile uint8_t *)UART_TX = ch;
}

void halt(int code) {
  ysyxsoc_trap(code);
  while (1);
}

void _trm_init() {
  uart_init();  // 串口初始化

  // ----- 打印 CPU ID -----
  int vendor_id, arch_id;
  char num[4];

  asm volatile("csrr %0, mvendorid" : "=r"(vendor_id));
  asm volatile("csrr %0, marchid"   : "=r"(arch_id));

  for (int i = 0; i < 4; i ++) num[i] = (vendor_id >> (8 * i)) & 0xFF;
  for (int i = 3; i >= 0; i --) printf("%c", num[i]);
  printf("\n");
  printf("NPC ID: %d\n", arch_id);
  // ----------------------

  int ret = main(mainargs);
  halt(ret);
}
