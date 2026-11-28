#include <am.h>
#include <npc.h>
#include <riscv/riscv.h>

void uart_init() {
  // LCR 的第7位(DLAB)为 1，开启除数寄存器访问
  outb(UART_BASE + UART_REG_LC, 0x80);

  // 
  outb(UART_BASE + UART_REG_DL1, 0x1);
  outb(UART_BASE + UART_REG_DL2, 0x00);

  // 8位数据并关闭 DLAB
  outb(UART_BASE + UART_REG_LC, 0x03);
}

void __am_uart_rx(AM_UART_RX_T *uart_rx){
    if((inb(UART_BASE + UART_REG_LS) & UART_LS_DR) == 0){
        uart_rx->data = 0xff;
    }else uart_rx->data = inb(UART_BASE + UART_REG_XR);
}