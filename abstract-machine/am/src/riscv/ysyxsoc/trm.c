#include <klib.h>
#include <klib-macros.h>

#define UART_ADDR 0x10000000
#define UART_REG_TR 0
#define UART_REG_LC 3
#define UART_REG_LS 5
#define UART_REG_DLL 0
#define UART_REG_DLH 1

#define GPIO_BASE 0x10002000
#define GPIO_LED 0
#define GPIO_SWITCH 4
#define GPIO_SEG 8

extern char _heap_start;
int main(const char *args);

extern char _sdram_start;
#define SDRAM_SIZE (32 * 1024 * 1024)
#define SDRAM_END  ((uintptr_t)&_sdram_start + SDRAM_SIZE)

Area heap = RANGE(&_heap_start, SDRAM_END);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

static inline uint8_t  inb(uintptr_t addr) { return *(volatile uint8_t  *)addr; }
static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }

void putch(char ch) {
  // loop until transmitter is empty
  while (!(inb(UART_ADDR + UART_REG_LS) & 0x20)) {
  }

  outb(UART_ADDR + UART_REG_TR, ch);
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : : "r"(code));
  while (1);
}

void init_uart() {
  uint8_t tmp = inb(UART_ADDR + UART_REG_LC);
  outb(UART_ADDR + UART_REG_LC,
       tmp | 0x80); // set dlab(divisor latch access bit)
  outb(UART_ADDR + UART_REG_DLH, 0);
  outb(UART_ADDR + UART_REG_DLL, 1);
  outb(UART_ADDR + UART_REG_LC, tmp); // recover
}

void display_id() {
  uint32_t id = 0;
  asm volatile("csrr %0, marchid" : "=r"(id));
  *(volatile int *)(GPIO_BASE + GPIO_SEG) = id;
  asm volatile("csrr  %0, mvendorid" : "=r"(id));
  printf("ysyx ascii:%x\n", id);
}

void login() {
  // loop until get right password
  while (*(volatile uint16_t *)(GPIO_BASE + GPIO_SWITCH) != 0x0000) {
  }
}

void _trm_init() {
  init_uart();
  display_id();
  login();
  int ret = main(mainargs);
  halt(ret);
}
