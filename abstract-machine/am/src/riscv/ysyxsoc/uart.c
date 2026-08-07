#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>

#define UART_BASE 0x10000000L
#define UART_THR (UART_BASE + 0)
#define UART_RBR (UART_BASE + 0)
#define UART_DLL (UART_BASE + 0)
#define UART_DLM (UART_BASE + 1)
#define UART_LCR (UART_BASE + 3)
#define UART_LSR (UART_BASE + 5)

#define LCR_DLAB 0x80
#define LCR_8N1 0x03
#define LSR_THRE (1 << 5)
#define LSR_TEMT (1 << 6)
#define LSR_RFE (1 << 7)
#define LSR_DR 0x01
static _Bool inited = 0;
static void init_uart() {
  outb(UART_LCR, LCR_DLAB | LCR_8N1);
  outb(UART_DLL, 1);
  outb(UART_DLM, 0);
  outb(UART_LCR, LCR_8N1);
  inited = 1;
}

void __am_uart_config(AM_UART_CONFIG_T *cfg) {
  init_uart();
  cfg->present = true;
}

void __am_uart_tx(AM_UART_TX_T *tx) {
  if (!inited) {
    init_uart();
  }
  while ((inb(UART_LSR) & LSR_THRE) == 0)
    ;
  outb(UART_THR, tx->data);
}

void __am_uart_rx(AM_UART_RX_T *uart) {
  unsigned char lsr = inb(UART_LSR);
  unsigned char rbr = inb(UART_RBR);
  uart->data = 0xFF;

  if ((lsr & LSR_DR) && !(lsr & LSR_RFE)) {
    uart->data = rbr;
  }
}
