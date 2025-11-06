// 负责串口的接收
#include <am.h>
#include "ysyxsoc.h"

void __am_uart_rx(AM_UART_RX_T *rx){
    uint8_t lsr;    // 读取LS寄存器
    uint8_t dr;     // 判断接收数据是否准备好
    char    data;   // 接收传入的数据
    // 下面是判断串口是否接收到数据
    lsr = inb(UART_REG_LS);
    dr  = (lsr >> UART_LS_DR) & 1;
    if(dr){
        data = inb(UART_REG_RB);
        rx->data = data;
    } else {
        rx->data = 0xff;
    }
}
