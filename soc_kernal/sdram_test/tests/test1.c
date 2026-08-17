#include <klib.h>
#include <stdint.h>

#define NR_DATA LENGTH(test_data)

#define MY_CHECK(C)                                                            \
  do {                                                                         \
    if (!(C))                                                                  \
      return -1;                                                               \
  } while (0)

#define TEST_ADDR_START 0xa0000000
#define TEST_ADDR_END 0xa8000000

int test_word() {
  uint32_t *start = (uint32_t *)(TEST_ADDR_START);
  uint32_t *end = (uint32_t *)(TEST_ADDR_END);
  for (volatile uint32_t *p = start; p < end; p += 0x200) {
    *p = (uint32_t)((uint32_t)p + 3);
  }
  for (volatile uint32_t *p = start; p < end; p += 0x200) {
    MY_CHECK(*p == (uint32_t)((uint32_t)p + 3));
  }
  return 0;
}

int test_half() {
  uint16_t *start = (uint16_t *)(TEST_ADDR_START);
  uint16_t *end = (uint16_t *)(TEST_ADDR_END);
  for (volatile uint16_t *p = start; p < end; p += 0x200) {
    *p = (uint16_t)((uint32_t)p * 42);
  }
  for (volatile uint16_t *p = start; p < end; p += 0x200) {
    MY_CHECK(*p == (uint16_t)((uint32_t)p * 42));
  }
  return 0;
}

int test_byte() {
  uint8_t *start = (uint8_t *)(TEST_ADDR_START);
  uint8_t *end = (uint8_t *)(TEST_ADDR_END);
  for (volatile uint8_t *p = start; p < end; p += 0x400) {
    *p = (uint8_t)((uint32_t)p * 3);
  }
  for (volatile uint8_t *p = start; p < end; p += 0x400) {
    MY_CHECK(*p == (uint8_t)((uint32_t)p * 3));
  }
  return 0;
}

int test_last() {
  *(volatile uint32_t *)(TEST_ADDR_START) = 0xdeadbeef;
  *(volatile uint16_t *)(TEST_ADDR_START + 4) = 0xabcd;
  *(volatile uint8_t *)(TEST_ADDR_START + 6) = 0x3;
  *(volatile uint8_t *)(TEST_ADDR_START + 7) = 0x6;

  MY_CHECK(*(volatile uint8_t *)(TEST_ADDR_START + 7) == 0x6);
  MY_CHECK(*(volatile uint16_t *)(TEST_ADDR_START + 4) == 0xabcd);
  MY_CHECK(*(volatile uint32_t *)(TEST_ADDR_START) == 0xdeadbeef);
  MY_CHECK(*(volatile uint8_t *)(TEST_ADDR_START + 6) == 0x3);

  return 0;
}

int main() {
  int return_value = test_word();
  if (return_value)
    return -1;
  return_value = test_half();
  if (return_value)
    return -1;
  return_value = test_byte();
  if (return_value)
    return -1;
  return_value = test_last();
  if (return_value)
    return -1;
  return 0;
}
