#define UART_BASE 0x10000000L
#define UART_TX 0
void _start() {
  *(volatile char *)(UART_BASE + UART_TX) = 'A';
  *(volatile char *)(UART_BASE + UART_TX) = '\n';
  asm volatile("lui a0, 0x00000");
  asm volatile("ebreak");
}