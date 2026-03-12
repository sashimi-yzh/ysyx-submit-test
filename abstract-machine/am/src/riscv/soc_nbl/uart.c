#include <ysyxsoc.h>


void __am_uart_tx(AM_UART_TX_T *uart) {
    putch(uart->data);
}


void __am_uart_rx(AM_UART_RX_T *uart) {
    if(inb(SERIAL_PORT + 5) & 0x01) {
        uart->data = inb(SERIAL_PORT);
    } else {
        uart->data = (char)-1;
    }
}
