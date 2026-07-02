#include <am.h>
#include <stdint.h>
#include <stdio.h>

#define CHIPLINK_BASE 0xc0000000u
#define CHIPLINK_SIZE 0x00001000u

static inline uintptr_t align_up(uintptr_t x, uintptr_t a) {
  return (x + (a - 1)) & ~(a - 1);
}

static inline uintptr_t align_down(uintptr_t x, uintptr_t a) {
  return x & ~(a - 1);
}

static inline uint8_t pat8_addr(uintptr_t addr) {
  return (uint8_t)(((addr >> 1) ^ addr) & 0xffu);
}

static inline uint16_t pat16_addr(uintptr_t addr) {
  return (uint16_t)(((addr >> 1) ^ addr) & 0xffffu);
}

static inline uint32_t pat32_addr(uintptr_t addr) {
  return ((uint32_t)addr ^ 0x5a5aa5a5u);
}

int main(void) {
  uintptr_t start = CHIPLINK_BASE;
  uintptr_t end = CHIPLINK_BASE + CHIPLINK_SIZE;

  printf("[chiplink-mem-test] range: [0x%08x, 0x%08x)\n", (uint32_t)start, (uint32_t)end);

  // Pass 1: address-derived patterns.
  {
    uintptr_t lo = align_up(start, 1);
    uintptr_t hi = align_down(end, 1);
    for (uintptr_t addr = lo; addr < hi; addr += 1) {
      *(volatile uint8_t *)addr = pat8_addr(addr);
    }
    for (uintptr_t addr = lo; addr < hi; addr += 1) {
      uint8_t expected = pat8_addr(addr);
      uint8_t got = *(volatile uint8_t *)addr;
      if (got != expected) {
        printf("[byte-p1] mismatch @0x%08x exp=0x%02x got=0x%02x\n",
               (uint32_t)addr, expected, got);
        halt(1);
      }
    }
    printf("[chiplink-mem-test] byte pass1\n");
  }

  {
    uintptr_t lo = align_up(start, 2);
    uintptr_t hi = align_down(end, 2);
    for (uintptr_t addr = lo; addr < hi; addr += 2) {
      *(volatile uint16_t *)addr = pat16_addr(addr);
    }
    for (uintptr_t addr = lo; addr < hi; addr += 2) {
      uint16_t expected = pat16_addr(addr);
      uint16_t got = *(volatile uint16_t *)addr;
      if (got != expected) {
        printf("[half-p1] mismatch @0x%08x exp=0x%04x got=0x%04x\n",
               (uint32_t)addr, expected, got);
        halt(1);
      }
    }
    printf("[chiplink-mem-test] half pass1\n");
  }

  {
    uintptr_t lo = align_up(start, 4);
    uintptr_t hi = align_down(end, 4);
    for (uintptr_t addr = lo; addr < hi; addr += 4) {
      *(volatile uint32_t *)addr = pat32_addr(addr);
    }
    for (uintptr_t addr = lo; addr < hi; addr += 4) {
      uint32_t expected = pat32_addr(addr);
      uint32_t got = *(volatile uint32_t *)addr;
      if (got != expected) {
        printf("[word-p1] mismatch @0x%08x exp=0x%08x got=0x%08x\n",
               (uint32_t)addr, expected, got);
        halt(1);
      }
    }
    printf("[chiplink-mem-test] word pass1\n");
  }

  // Pass 2: inverted patterns.
  {
    uintptr_t lo = align_up(start, 1);
    uintptr_t hi = align_down(end, 1);
    for (uintptr_t addr = lo; addr < hi; addr += 1) {
      *(volatile uint8_t *)addr = (uint8_t)~pat8_addr(addr);
    }
    for (uintptr_t addr = lo; addr < hi; addr += 1) {
      uint8_t expected = (uint8_t)~pat8_addr(addr);
      uint8_t got = *(volatile uint8_t *)addr;
      if (got != expected) {
        printf("[byte-p2] mismatch @0x%08x exp=0x%02x got=0x%02x\n",
               (uint32_t)addr, expected, got);
        halt(1);
      }
    }
    printf("[chiplink-mem-test] byte pass2\n");
  }

  {
    uintptr_t lo = align_up(start, 2);
    uintptr_t hi = align_down(end, 2);
    for (uintptr_t addr = lo; addr < hi; addr += 2) {
      *(volatile uint16_t *)addr = (uint16_t)~pat16_addr(addr);
    }
    for (uintptr_t addr = lo; addr < hi; addr += 2) {
      uint16_t expected = (uint16_t)~pat16_addr(addr);
      uint16_t got = *(volatile uint16_t *)addr;
      if (got != expected) {
        printf("[half-p2] mismatch @0x%08x exp=0x%04x got=0x%04x\n",
               (uint32_t)addr, expected, got);
        halt(1);
      }
    }
    printf("[chiplink-mem-test] half pass2\n");
  }

  {
    uintptr_t lo = align_up(start, 4);
    uintptr_t hi = align_down(end, 4);
    for (uintptr_t addr = lo; addr < hi; addr += 4) {
      *(volatile uint32_t *)addr = ~pat32_addr(addr);
    }
    for (uintptr_t addr = lo; addr < hi; addr += 4) {
      uint32_t expected = ~pat32_addr(addr);
      uint32_t got = *(volatile uint32_t *)addr;
      if (got != expected) {
        printf("[word-p2] mismatch @0x%08x exp=0x%08x got=0x%08x\n",
               (uint32_t)addr, expected, got);
        halt(1);
      }
    }
    printf("[chiplink-mem-test] word pass2\n");
  }

  printf("[chiplink-mem-test] full 4KB pass\n");
  return 0;
}
