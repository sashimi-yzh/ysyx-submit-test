#include <am.h>
#include <nemu.h>

void __am_uart_rx(AM_UART_RX_T *cfg){
        cfg->data = inb(SERIAL_PORT);
}
