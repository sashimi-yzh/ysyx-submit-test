#include <am.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define SDRAM_BASE 0xa0000000u
#define SDRAM_SIZE 0x02000000u  // 32MB modeled by MT48LC16M16A2
#define SDRAM_END  (SDRAM_BASE + SDRAM_SIZE)
#define STRIDE     0x00010000u  // sparse test: 64KB step

extern char _heap_start;
extern char _heap_end;

static inline void store_b(uintptr_t addr, uint8_t val) {
  asm volatile("sb %1, 0(%0)" :: "r"(addr), "r"(val) : "memory");
}

static inline void store_h(uintptr_t addr, uint16_t val) {
  asm volatile("sh %1, 0(%0)" :: "r"(addr), "r"(val) : "memory");
}

static inline void store_w(uintptr_t addr, uint32_t val) {
  asm volatile("sw %1, 0(%0)" :: "r"(addr), "r"(val) : "memory");
}

static inline int8_t load_b(uintptr_t addr) {
  int32_t v;
  asm volatile("lb %0, 0(%1)" : "=r"(v) : "r"(addr) : "memory");
  return (int8_t)v;
}

static inline uint8_t load_bu(uintptr_t addr) {
  uint32_t v;
  asm volatile("lbu %0, 0(%1)" : "=r"(v) : "r"(addr) : "memory");
  return (uint8_t)v;
}

static inline int16_t load_h(uintptr_t addr) {
  int32_t v;
  asm volatile("lh %0, 0(%1)" : "=r"(v) : "r"(addr) : "memory");
  return (int16_t)v;
}

static inline uint16_t load_hu(uintptr_t addr) {
  uint32_t v;
  asm volatile("lhu %0, 0(%1)" : "=r"(v) : "r"(addr) : "memory");
  return (uint16_t)v;
}

static inline uint32_t load_w(uintptr_t addr) {
  uint32_t v;
  asm volatile("lw %0, 0(%1)" : "=r"(v) : "r"(addr) : "memory");
  return v;
}

static inline uint32_t mix32(uint32_t x) {
  x ^= x >> 16;
  x *= 0x7feb352dU;
  x ^= x >> 15;
  x *= 0x846ca68bU;
  x ^= x >> 16;
  return x;
}

static void fail(const char *op, uintptr_t addr, uint32_t exp, uint32_t got) {
  printf("%s mismatch @0x%08x exp=0x%08x got=0x%08x\n", op, (uint32_t)addr, exp, got);
  halt(1);
}

static void test_site(uintptr_t base) {
  // base must be 4-byte aligned and base+3 valid.
  uint32_t pat = mix32((uint32_t)base) ^ 0xa5a55a5aU;

  // sw/lw
  store_w(base, pat);
  {
    uint32_t got = load_w(base);
    if (got != pat) fail("lw/sw", base, pat, got);
  }

  // sb/lbu/lb : force sign bit to validate lb sign-extension.
  for (int i = 0; i < 4; i++) {
    uint8_t ub = (uint8_t)(0x80u | ((pat >> (i * 8)) & 0x7fu));
    int8_t sb = (int8_t)ub;
    store_b(base + (uintptr_t)i, ub);

    uint8_t got_u = load_bu(base + (uintptr_t)i);
    if (got_u != ub) fail("lbu/sb", base + (uintptr_t)i, ub, got_u);

    int8_t got_s = load_b(base + (uintptr_t)i);
    if (got_s != sb) fail("lb/sb", base + (uintptr_t)i, (uint8_t)sb, (uint8_t)got_s);
  }

  // sh/lhu/lh : test at halfword-aligned offsets 0 and 2.
  for (int i = 0; i < 2; i++) {
    uintptr_t a = base + (uintptr_t)(i * 2);
    uint16_t uh = (uint16_t)(0x8000u | ((pat >> (i * 8)) & 0x7fffu));
    int16_t shv = (int16_t)uh;
    store_h(a, uh);

    uint16_t got_u = load_hu(a);
    if (got_u != uh) fail("lhu/sh", a, uh, got_u);

    int16_t got_s = load_h(a);
    if (got_s != shv) fail("lh/sh", a, (uint16_t)shv, (uint16_t)got_s);
  }
}

int main(void) {
  uintptr_t used_end = (uintptr_t)&_heap_start;
  uintptr_t heap_end = (uintptr_t)&_heap_end;
  uintptr_t start = (used_end + 3u) & ~(uintptr_t)0x3u;
  uintptr_t end   = (heap_end < (uintptr_t)SDRAM_END) ? heap_end : (uintptr_t)SDRAM_END;
  uint32_t n = 0;
  uint32_t dots = 0;

  if (start < (uintptr_t)SDRAM_BASE) start = (uintptr_t)SDRAM_BASE;
  if (end > (uintptr_t)SDRAM_END) end = (uintptr_t)SDRAM_END;
  if (start + 4 > end) {
    printf("[sdram-test] no free SDRAM range to test: used_end=0x%08x end=0x%08x\n",
           (uint32_t)used_end, (uint32_t)end);
    halt(1);
  }

  printf("[sdram-test] range: [0x%08x, 0x%08x)\n", (uint32_t)start, (uint32_t)end);
  printf("[sdram-test] skip runtime image: [0x%08x, 0x%08x)\n",
         (uint32_t)SDRAM_BASE, (uint32_t)start);
  printf("[sdram-test] sparse stride: 0x%08x\n", STRIDE);

  // 1) Boundary-focused points (head/tail and around stride edges).
  uintptr_t points[] = {
    start,
    start + 4,
    start + 0x100 - 4,
    start + 0x100,
    start + STRIDE - 4,
    start + STRIDE,
    end - STRIDE - 4,
    end - STRIDE,
    end - 8,
    end - 4
  };
  for (uint32_t i = 0; i < sizeof(points) / sizeof(points[0]); i++) {
    uintptr_t p = points[i] & ~((uintptr_t)0x3);
    if (p >= start && p + 4 <= end) {
      test_site(p);
      n++;
    }
  }
  printf("[sdram-test] boundary pass (%u sites)\n", n);

  // 2) Full-range sparse walk.
  for (uintptr_t addr = start; addr + 4 <= end; addr += STRIDE) {
    test_site(addr);
    n++;
    if ((n & 0x3fU) == 0) {
      dots++;
      if ((dots & 0x0fU) == 0) {
        printf("[sdram-test] progress: %u sites\n", n);
      }
    }
  }
  printf("[sdram-test] sparse pass (%u sites total)\n", n);

  printf("[sdram-test] done (covered lb/sb/lbu/lhu/lh/sh/lw/sw)\n");
  return 0;
}
