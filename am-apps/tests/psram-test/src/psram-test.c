#include <am.h>
#include <stdint.h>
#include <klib.h>

#define PSRAM_BASE_ADDR  0x80000000u
#define PSRAM_TEST_BYTES 4096u

static inline uintptr_t align_up(uintptr_t x, uintptr_t a) {
  return (x + (a - 1)) & ~(a - 1);
}

int main(void) {
  printf("[psram-test] start base=0x%08x size=%u bytes\n", PSRAM_BASE_ADDR, PSRAM_TEST_BYTES);

  {
    volatile uint8_t *p8 = (volatile uint8_t *)(uintptr_t)PSRAM_BASE_ADDR;
    for (uint32_t i = 0; i < PSRAM_TEST_BYTES; i++) {
      p8[i] = (uint8_t)((i * 17u) ^ 0x5au);
    }
    for (uint32_t i = 0; i < PSRAM_TEST_BYTES; i++) {
      uint8_t expected = (uint8_t)((i * 17u) ^ 0x5au);
      uint8_t got = p8[i];
      if (got != expected) {
        printf("[psram-test] byte mismatch at +0x%x: exp=0x%02x got=0x%02x\n", i, expected, got);
        halt(1);
      }
    }
    printf("[psram-test] byte pass\n");
  }

  {
    uintptr_t base = align_up((uintptr_t)PSRAM_BASE_ADDR, 2);
    volatile uint16_t *p16 = (volatile uint16_t *)base;
    uint32_t count = PSRAM_TEST_BYTES / 2;

    for (uint32_t i = 0; i < count; i++) {
      uint16_t pattern = (uint16_t)(((i * 29u) + 0x1357u) ^ 0xa55au);
      p16[i] = pattern;
    }
    for (uint32_t i = 0; i < count; i++) {
      uint16_t expected = (uint16_t)(((i * 29u) + 0x1357u) ^ 0xa55au);
      uint16_t got = p16[i];
      if (got != expected) {
        printf("[psram-test] half mismatch at +0x%x: exp=0x%04x got=0x%04x\n", (unsigned)(i * 2u), expected, got);
        halt(1);
      }
    }
    printf("[psram-test] half pass\n");
  }

  {
    uintptr_t base = align_up((uintptr_t)PSRAM_BASE_ADDR, 4);
    volatile uint32_t *p32 = (volatile uint32_t *)base;
    uint32_t count = PSRAM_TEST_BYTES / 4;

    for (uint32_t i = 0; i < count; i++) {
      uint32_t pattern = (0x9e3779b9u ^ (i * 0x10203u)) + 0x2468ace1u;
      p32[i] = pattern;
    }
    for (uint32_t i = 0; i < count; i++) {
      uint32_t expected = (0x9e3779b9u ^ (i * 0x10203u)) + 0x2468ace1u;
      uint32_t got = p32[i];
      if (got != expected) {
        printf("[psram-test] word mismatch at +0x%x: exp=0x%08x got=0x%08x\n", (unsigned)(i * 4u), expected, got);
        halt(1);
      }
    }
    printf("[psram-test] word pass\n");
  }

  printf("[psram-test] done\n");
  return 0;
}
