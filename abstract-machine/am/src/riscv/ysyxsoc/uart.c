#include <am.h>

#define UART_BASE_ADDR  0x10000000
#define UART_LCR        (*(volatile uint8_t *)(UART_BASE_ADDR + 0x03))  // Line Control Register
#define UART_DLL        (*(volatile uint8_t *)(UART_BASE_ADDR + 0x00))  // Divisor Latch LSB
#define UART_DLM        (*(volatile uint8_t *)(UART_BASE_ADDR + 0x01))  // Divisor Latch MSB
#define UART_LSR        (*(volatile uint8_t *)(UART_BASE_ADDR + 0x05))  // Line Status Register
#define UART_THR        (*(volatile uint8_t *)(UART_BASE_ADDR + 0x00))  // Transmitter Holding Register
#define UART_RBR        (*(volatile uint8_t *)(UART_BASE_ADDR + 0x00))  // Receiver Buffer Register
#define UART_LSR_THRE   0x20  // Transmitter Holding Register Empty
#define UART_LSR_DR     0x01  // Data Ready

void putch(char ch) {
    // Wait until the Transmitter Holding Register is empty
    while (!(UART_LSR & UART_LSR_THRE)) {
        // Busy wait until UART is ready to transmit
    }
    // Write the character to the Transmitter Holding Register
    UART_THR = ch;
} 


void __am_uart_init(void) {
    // Set the baud rate divisor
    // uint16_t divisor = 50000000 / (16 * 115200); // for real
	uint16_t divisor = 1;	// for sim
    // Enable access to the Divisor Latch registers
    UART_LCR |= 0x80; // Set DLAB = 1 to access DLL and DLM

    // Set the Divisor Latch registers
    UART_DLL = divisor & 0xFF;
    UART_DLM = (divisor >> 8) & 0xFF;

    // Set the Line Control Register (8 bits, no parity, 1 stop bit)
    UART_LCR = 0x03; // DLAB = 0, 8 data bits, 1 stop bit, no parity
}

void __am_uart_rx(AM_UART_RX_T *uart_rx) {
    // Check if data is ready to be read
    if (UART_LSR & UART_LSR_DR) {
        // Read the character from the Receiver Buffer Register
        uart_rx->data = UART_RBR;
    } else {
        // No data available, return 0xff
        uart_rx->data = 0xff;
    }
}
