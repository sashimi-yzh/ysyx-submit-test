#include <am.h>
#include "include/npc.h"
#include <klib.h>
#include <klib-macros.h>

extern char _heap_start;
extern char _heap_end;
int main(const char *args);
void halt(int code);

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

enum {
  GPIO_SEG_REG_OFF = 0x8u,
};

static inline void uart_write8(uint32_t off, uint8_t val) {
  outb(UART_BASE + off, val);
}

static inline uint8_t uart_read8(uint32_t off) {
  return inb(UART_BASE + off);
}

static void uart_init(void) {
  // Enable divisor latch access.
  uart_write8(UART_REG_LCR, UART_LCR_DLAB);
  // Small divisor for fast transmit in simulation.
  uart_write8(UART_REG_DLL, 0x01u);
  uart_write8(UART_REG_DLM, 0x00u);
  // Restore normal register map and set 8N1 format.
  uart_write8(UART_REG_LCR, UART_LCR_8N1);
  // Enable FIFO and clear TX/RX FIFOs.
  uart_write8(UART_REG_FCR, 0x07u);
}

void putch(char ch) {
  // Poll TX FIFO empty bit before writing to avoid character loss.
  while ((uart_read8(UART_REG_LSR) & UART_LSR_THRE) == 0) {}
  uart_write8(UART_REG_THR, (uint8_t)ch);
}

void halt(int code) {
  (void)code;
  asm volatile("ebreak");
  while (1);
}

void _trm_init() {
  uint32_t vendor = 0, arch = 0;
  uint32_t t0 = 0, t1 = 0, t2 = 0;
  asm volatile("csrr %0, mvendorid" : "=r"(vendor));
  asm volatile("csrr %0, marchid" : "=r"(arch));
  t0 = inl(CLINT_MTIME);
  t1 = inl(CLINT_MTIME);
  t2 = inl(CLINT_MTIME);

  // Show marchid in decimal on 8-digit 7-seg (one BCD digit per nibble).
  uint32_t packed_bcd = 0;
  uint32_t x = arch;
  for (int i = 0; i < 8; i++) {
    packed_bcd |= (x % 10u) << (i * 4);
    x /= 10u;
  }
  outl(GPIO_BASE + GPIO_SEG_REG_OFF, packed_bcd);

  uart_init();
  printf("CSR mvendorid=0x%08x marchid=%u(0x%08x)\n", vendor, arch, arch);
  printf("CLINT mtime samples: %u -> %u -> %u\n", t0, t1, t2);
  int ret = main(mainargs);
  halt(ret);
}
