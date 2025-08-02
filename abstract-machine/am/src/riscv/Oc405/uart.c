#include <am.h>

#define UART_BASE_ADDR  0x10013000

#define UART_RBR        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x00))
#define UART_DLL        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x00))
#define UART_THR        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x00))

#define UART_DLM        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x04))
#define UART_IER        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x04))

#define UART_IIR        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x08))
#define UART_FCR        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x08))

#define UART_LCR        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x0C))
#define UART_MCR        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x10))
#define UART_LSR        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x14))
#define UART_MSR        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x18))
#define UART_SCR        (*(volatile uint32_t *)(UART_BASE_ADDR + 0x1C))

int32_t uart_write(uint8_t val)
{
    while ((UART_LSR & 0x20) == 0);
    UART_THR = val;
    return 0;
}

void putch(char ch) {
    uart_write(ch);
} 

void __am_uart_init(uint32_t baudrate) {
    unsigned int uart_div = 50000000 / baudrate - 1;
    UART_LCR = 0x80;
    UART_DLM = (uart_div >> 8) & 0xFF;
    UART_DLL = uart_div        & 0xFF;
    UART_FCR = 0xC6;
    UART_LCR = 0x03;
}
