#include <am.h>
#include "ysyxsoc.h"

void __am_uart_config(AM_UART_CONFIG_T *cfg) { cfg->present = true; }

void __am_uart_tx(AM_UART_TX_T *tx) {
  while ((*(volatile uint8_t *)(UART_BASE + UART_LSR) & UART_LSR_THRE) == 0);
  *(volatile uint8_t *)(UART_BASE + UART_TX) = tx->data;
}

void __am_uart_rx(AM_UART_RX_T *rx) {
  uint8_t lsr = *(volatile uint8_t *)(UART_BASE + UART_LSR);
  if (lsr & UART_LSR_DR) {
    rx->data = *(volatile uint8_t *)(UART_BASE + UART_TX);
  } else {
    rx->data = 0xFF;
  }
}