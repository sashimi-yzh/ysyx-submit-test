#define UART_BASE 0x10000000L
#define UART_TX   0
void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code));
  while (1);
}
void _start() {
  *(volatile char *)(UART_BASE + UART_TX) = 'A';
  halt(0);
}