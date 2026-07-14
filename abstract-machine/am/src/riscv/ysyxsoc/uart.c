#include <am.h>
#include <klib-macros.h>
#include <ysyxsoc.h>
#include <riscv/riscv.h>

void __am_uart_tx(AM_UART_TX_T *d)
{
    while (!(inb(UART_LSR) & 0b00100000))
        ; // 等待 bit5=1
    outl(UART_BASE, d->data);
}
void __am_uart_rx(AM_UART_RX_T *d)
{
    uint8_t lsr = 0;
    lsr = inb(UART_LSR);
    if(!(lsr & 0b00000001)) {
        d->data = 0xFF;
        return ;
    }
    if (lsr & 0b00011110)
    {
        d->data = 0xEE;
        return ;
    }
    d->data = inb(UART_RBR);
}