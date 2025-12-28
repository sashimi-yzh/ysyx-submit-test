#include <am.h>
#include <riscv/riscv.h>
#define UART_BASE 0x10000000
#define UART_TX   0
#define UART_dL1   0
#define UART_dL2   1
#define UART_FC   2
#define UART_LC   3
#define UART_LS   5

void __am_uart_rx(AM_UART_RX_T *cfg){
    if((*(volatile uint8_t  *)(UART_BASE + UART_LS) & 0x1) == 0x1){
        cfg->data = *(volatile uint8_t  *)(UART_BASE );
        
    }
    else {
        cfg->data = 0xff;
    }
}

