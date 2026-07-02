#include <am.h>
#include <stdint.h>

#define FLASH_BASE 0x30000000u
#define FLASH_TEST_BASE_OFF 0x100u
#define FLASH_TEST_BYTES    256u

int main(void) {
  volatile uint32_t *flash32 = (volatile uint32_t *)(uintptr_t)FLASH_BASE;
  volatile uint16_t *flash16 = (volatile uint16_t *)(uintptr_t)FLASH_BASE;
  volatile uint8_t *flash8 = (volatile uint8_t *)(uintptr_t)FLASH_BASE;

  uint32_t base_byte = FLASH_TEST_BASE_OFF;
  for (uint32_t i = 0; i < FLASH_TEST_BYTES; i += 4) {
    uint32_t byte_off = base_byte + i;
    uint32_t idx32 = byte_off >> 2;
    uint32_t w = flash32[idx32];
    uint32_t w2 = flash32[idx32];
    if (w != w2) {
      halt(1);
    }

    uint16_t h0 = flash16[byte_off >> 1];
    uint16_t h1 = flash16[(byte_off >> 1) + 1];
    uint16_t exp_h0 = (uint16_t)(w & 0xffffu);
    uint16_t exp_h1 = (uint16_t)(w >> 16);
    if (h0 != exp_h0 || h1 != exp_h1) {
      halt(1);
    }

    uint8_t b0 = flash8[byte_off + 0];
    uint8_t b1 = flash8[byte_off + 1];
    uint8_t b2 = flash8[byte_off + 2];
    uint8_t b3 = flash8[byte_off + 3];
    uint8_t exp_b0 = (uint8_t)(w & 0xffu);
    uint8_t exp_b1 = (uint8_t)((w >> 8) & 0xffu);
    uint8_t exp_b2 = (uint8_t)((w >> 16) & 0xffu);
    uint8_t exp_b3 = (uint8_t)((w >> 24) & 0xffu);
    if (b0 != exp_b0 || b1 != exp_b1 || b2 != exp_b2 || b3 != exp_b3) {
      halt(1);
    }
  }

  return 0;
}
