#include <am.h>
#include <klib.h>

#include "include/npc.h"

static volatile uint8_t *uart_registers(void) {
  return (volatile uint8_t *)(uintptr_t)YSYXSOC_UART_BASE;
}

void uart_init(void) {
  volatile uint8_t *registers = uart_registers();
  registers[UART_LINE_CONTROL_OFFSET] = UART_CONTROL_DLAB;
  registers[UART_DIVISOR_LOW_OFFSET] = UART_DIVISOR_LOW_VALUE;
  registers[UART_DIVISOR_HIGH_OFFSET] = UART_DIVISOR_HIGH_VALUE;
  registers[UART_LINE_CONTROL_OFFSET] = UART_CONTROL_8N1;
  registers[UART_FIFO_CONTROL_OFFSET] = UART_FIFO_INIT_VALUE;
}

void putch(char ch) {
  volatile uint8_t *registers = uart_registers();
  while ((registers[UART_LINE_STATUS_OFFSET] & UART_STATUS_TX_READY) == 0u) {}
  registers[UART_TX_DATA_OFFSET] = (uint8_t)ch;
}

static uint32_t read_mtime_low(void) {
  return *(volatile uint32_t *)(uintptr_t)YSYXSOC_MTIME_LOW_ADDR;
}

void nvboard_init(void) {
  uint32_t architecture_id = 0;

  asm volatile("csrr %0, marchid" : "=r"(architecture_id));
  (void)read_mtime_low();

  uint32_t display_value = 0;
  uint32_t remaining_id = architecture_id;
  for (unsigned digit = 0; digit < 8u; digit++) {
    display_value |= (remaining_id % 10u) << (digit * 4u);
    remaining_id /= 10u;
  }
  outl(YSYXSOC_GPIO_SEGMENT_ADDR, display_value);

  printf("[ysyxSoC] clock=on nvboard=on uart=on\n");
}

void halt(int code) {
  (void)code;
  asm volatile("ebreak");
  while (1) {}
}
