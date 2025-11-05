#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>
#include <nemu.h>


void __am_uart_tx(AM_UART_TX_T *tx) {
    outb(SERIAL_PORT, tx->data);
}

void __am_uart_rx(AM_UART_RX_T *rx) {

    rx->data = inb(SERIAL_PORT);;
}
