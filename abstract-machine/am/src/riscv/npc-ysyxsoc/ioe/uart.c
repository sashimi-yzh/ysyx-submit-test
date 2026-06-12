#include <am.h>
#include <riscv/riscv.h>
#include <stdint.h>
#include "../npc.h"

// #define SERIAL_FREQ 50 * 1000000
// #define SERIAL_BAUD 115200
// #define SERIAL_DL_VAL ((uint16_t)((SERIAL_FREQ) / (16 * (SERIAL_BAUD))))
#define SERIAL_DL_VAL (uint16_t)1u

#define SERIAL_DLLO (SERIAL_PORT)
#define SERIAL_DLHI (SERIAL_PORT + 1u)
#define SERIAL_LCR (SERIAL_PORT + 3u)
#define SERIAL_LSR (SERIAL_PORT + 5u)

void __am_uart_init(void) {
  setb(SERIAL_LCR, 1u << 7);
  outb(SERIAL_DLHI, (uint8_t)(SERIAL_DL_VAL >> 8));
  outb(SERIAL_DLLO, (uint8_t)SERIAL_DL_VAL);
  clearb(SERIAL_LCR, 1u << 7);
}

void __am_uart_tx(AM_UART_TX_T *tx) {
  while (!((inb(SERIAL_LSR) >> 5) & 1u));
  outb(SERIAL_PORT, tx->data);
}

void __am_uart_rx(AM_UART_RX_T *rx) {
  rx->data = (inb(SERIAL_LSR) & 1u) ? inb(SERIAL_PORT) : 0xff;
}
