#define UART_BASE 0x10000000L
#define UART_TX   0
#define UART_RX   0
#define SERIAL_PORT     (UART_BASE + UART_TX)
#define KBD_ADDR         0x10011000L
#define UART_REG_LC      0x10000003L
#define UART_REG_DL1     0x10000000L
#define UART_REG_DL2     0x10000001L
#define UART_REG_LSR     0x10000005L
#define FB_ADDR          0x21000000L
