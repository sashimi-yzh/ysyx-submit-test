// See LICENSE for license details.

#include <am.h>

#define uart16550 ((volatile uint8_t *)0x10000000ul)
#define uart16550_clock 1843200   // a "common" base clock

#define UART_REG_QUEUE     0    // rx/tx fifo data
#define UART_REG_DLL       0    // divisor latch (LSB)
#define UART_REG_IER       1    // interrupt enable register
#define UART_REG_DLM       1    // divisor latch (MSB) 
#define UART_REG_FCR       2    // fifo control register
#define UART_REG_LCR       3    // line control register
#define UART_REG_MCR       4    // modem control register
#define UART_REG_LSR       5    // line status register
#define UART_REG_MSR       6    // modem status register
#define UART_REG_SCR       7    // scratch register
#define UART_REG_STATUS_RX 0x01
#define UART_REG_STATUS_TX 0x20

// We cannot use the word DEFAULT for a parameter that cannot be overridden due to -Werror
#ifndef UART_DEFAULT_BAUD
#define UART_DEFAULT_BAUD  38400
#endif

void uart16550_putchar(char ch) {
  while ((uart16550[UART_REG_LSR] & UART_REG_STATUS_TX) == 0);
  uart16550[UART_REG_QUEUE] = ch;
}

int uart16550_getchar() {
  if (uart16550[UART_REG_LSR] & UART_REG_STATUS_RX)
    return uart16550[UART_REG_QUEUE];
  return -1;
}

void uart16550_init() {
  uint32_t divisor = uart16550_clock / (16 * 115200);

  // http://wiki.osdev.org/Serial_Ports
  uart16550[UART_REG_IER] = 0x00;                // Disable all interrupts
  uart16550[UART_REG_LCR] = 0x80;                // Enable DLAB (set baud rate divisor)
  uart16550[UART_REG_DLL] = (uint8_t)divisor;    // Set divisor (lo byte)
  uart16550[UART_REG_DLM] = (uint8_t)(divisor >> 8);     //     (hi byte)
  uart16550[UART_REG_LCR] = 0x03;                // 8 bits, no parity, one stop bit
  uart16550[UART_REG_FCR] = 0xC7;                // Enable FIFO, clear them, with 14-byte threshold
}
