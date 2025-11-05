#include <am.h>
#include <klib-macros.h>
#include <riscv/riscv.h>

#define UART_BASE 0x10000000L
#define UART_RX   (*(volatile uint8_t *)(UART_BASE + 0))   // R   Receiver FIFO output
#define UART_TX   (*(volatile uint8_t *)(UART_BASE + 0))   // W   Transmit FIFO input
#define UART_IE   (*(volatile uint8_t *)(UART_BASE + 1))   // RW  Interrupt Enable
#define UART_II   (*(volatile uint8_t *)(UART_BASE + 2))   // R   Interrupt Identification
#define UART_FC   (*(volatile uint8_t *)(UART_BASE + 2))   // W   FIFO control
#define UART_LC   (*(volatile uint8_t *)(UART_BASE + 3))   // RW  Line Control
#define UART_MC   (*(volatile uint8_t *)(UART_BASE + 4))   // W   Modem Control
#define UART_LS   (*(volatile uint8_t *)(UART_BASE + 5))   // R   Line Status
#define UART_MS   (*(volatile uint8_t *)(UART_BASE + 6))   // W   Modem Status


// The registers can be accessed when the 7th (DLAB) bit
// of the Line Control Register is set to ‘1’
#define UART_DVLSB (*(volatile uint8_t *)(UART_BASE + 0)) // RW  Divisor Latch 1(LSB)
#define UART_DVMSB (*(volatile uint8_t *)(UART_BASE + 1)) // RW  Divisor Latch 2(MSB)

 // NVBoard中，Update 一次(1 clk)，divisor_cnt就减1，传输一个比特, (divisor_cnt+1默认等于16)
 // 也就是 ---> 1-bit (divisor_cnt+1) cycles, 所以最少设置为16
 // 该串口 ---> 1-bit (16*DIVISOR) cycles
#define DIVISOR 1 

void __am_uart_init() {
    // UART_LC |= 0x80;
    // UART_DVMSB = (DIVISOR >> 8);
    // UART_DVLSB = DIVISOR;
    // UART_LC &= ~0x80;
    // UART_LC |= 0x3;
    // UART_FC = 0x7;

    // To pass difftest
    uint8_t uart_lc = 0x03;
    uart_lc |= 0x80;
    UART_LC = uart_lc;
    UART_DVMSB = (DIVISOR >> 8);
    UART_DVLSB = DIVISOR;
    uart_lc &= ~0x80;
    uart_lc |= 0x3;
    UART_LC = uart_lc;
    UART_FC = 0x7;
}

void __am_uart_config(AM_INPUT_CONFIG_T *cfg) {
    cfg->present = true;
}

bool __uart_tx_ready() {
    return UART_LS & (1 << 5);
}

// Can not be inline, we need its symbol 
void __am_uart_tx(AM_UART_TX_T *tx) {    
    while (!__uart_tx_ready());
    UART_TX = tx->data;
}

bool __uart_rx_ready() {
    return UART_LS & (1 << 0);
}

// Can not be inline, we need its symbol 
void __am_uart_rx(AM_UART_RX_T *rx) {    
    if (__uart_rx_ready()) {
        rx->data = UART_RX;
    } else {
        rx->data = 0xff;
    }
}
/*
void UART_init(){
    __am_uart_init();
}*/


void UART_send(uint8_t c) {

   io_write(AM_UART_TX, c);

}
