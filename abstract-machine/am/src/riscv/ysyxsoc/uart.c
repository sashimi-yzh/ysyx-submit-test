#include <am.h>
#include "../ysyxsoc/include/ysyxsoc.h"
#include "../riscv.h"

void __am_uart_rx(AM_UART_RX_T *cfg){
    if((inb(UART_LSR) & 0x1) == 0x1){
        cfg->data = inb(UART_RX);
    }else{
        cfg->data = 0xff;
    }
}
