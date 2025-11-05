#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>


#define DEVICE_BASE 0xa0000000

#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)

void __am_uart_tx(AM_UART_TX_T *tx) {
    outb(SERIAL_PORT, tx->data);
}


void __am_uart_rx(AM_UART_RX_T *rx) {

}

