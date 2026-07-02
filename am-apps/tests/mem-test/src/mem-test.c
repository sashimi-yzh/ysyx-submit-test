#include <am.h>
#include <stdint.h>

static inline uintptr_t read_sp(void) {
  uintptr_t sp;
  asm volatile("mv %0, sp" : "=r"(sp));
  return sp;
}

static inline uintptr_t align_up(uintptr_t x, uintptr_t a) {
  return (x + (a - 1)) & ~(a - 1);
}

static inline uintptr_t align_down(uintptr_t x, uintptr_t a) {
  return x & ~(a - 1);
}

int main(void) {
  uintptr_t start = (uintptr_t)heap.start;
  uintptr_t end = read_sp();

  {
    uintptr_t lo = align_up(start, 1);
    uintptr_t hi = align_down(end, 1);
    for (uintptr_t addr = lo; addr < hi; addr += 1) {
      *(volatile uint8_t *)addr = (uint8_t)(addr & 0xffu);
    }
    for (uintptr_t addr = lo; addr < hi; addr += 1) {
      uint8_t expected = (uint8_t)(addr & 0xffu);
      uint8_t got = *(volatile uint8_t *)addr;
      if (got != expected) halt(1);
    }
  }

  {
    uintptr_t lo = align_up(start, 2);
    uintptr_t hi = align_down(end, 2);
    for (uintptr_t addr = lo; addr < hi; addr += 2) {
      *(volatile uint16_t *)addr = (uint16_t)(addr & 0xffffu);
    }
    for (uintptr_t addr = lo; addr < hi; addr += 2) {
      uint16_t expected = (uint16_t)(addr & 0xffffu);
      uint16_t got = *(volatile uint16_t *)addr;
      if (got != expected) halt(1);
    }
  }

  {
    uintptr_t lo = align_up(start, 4);
    uintptr_t hi = align_down(end, 4);
    for (uintptr_t addr = lo; addr < hi; addr += 4) {
      *(volatile uint32_t *)addr = (uint32_t)addr;
    }
    for (uintptr_t addr = lo; addr < hi; addr += 4) {
      uint32_t expected = (uint32_t)addr;
      uint32_t got = *(volatile uint32_t *)addr;
      if (got != expected) halt(1);
    }
  }

  {
    uintptr_t lo = align_up(start, 8);
    uintptr_t hi = align_down(end, 8);
    for (uintptr_t addr = lo; addr < hi; addr += 8) {
      *(volatile uint64_t *)addr = (uint64_t)addr;
    }
    for (uintptr_t addr = lo; addr < hi; addr += 8) {
      uint64_t expected = (uint64_t)addr;
      uint64_t got = *(volatile uint64_t *)addr;
      if (got != expected) halt(1);
    }
  }

  return 0;
}
