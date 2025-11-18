#include <am.h>
#include <klib.h>
#define UART_ADDR 0x10000000
#define UART_REG_TR 0
#define UART_REG_LC 3
#define UART_REG_LS 5
#define UART_REG_DLL 0
#define UART_REG_DLH 1

static inline uint8_t inb(uintptr_t addr) { return *(volatile uint8_t *)addr; }

void __am_uart_rx(AM_UART_RX_T *uart) {
  if ((inb(UART_ADDR + UART_REG_LS) & 0x01)) {
    uart->data = inb(UART_ADDR + UART_REG_TR);
  } else {
    uart->data = 0xff;
  }
}
