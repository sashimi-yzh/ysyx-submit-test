#include <am.h>
#include <stdint.h>

#define SPI_BASE       0x10001000u

#define SPI_TX0_ADDR   (SPI_BASE + 0x00u)
#define SPI_RX0_ADDR   (SPI_BASE + 0x00u)
#define SPI_CTRL_ADDR  (SPI_BASE + 0x10u)
#define SPI_DIV_ADDR   (SPI_BASE + 0x14u)
#define SPI_SS_ADDR    (SPI_BASE + 0x18u)

#define SPI_CTRL_ASS       (1u << 13)
#define SPI_CTRL_IE        (1u << 12)
#define SPI_CTRL_LSB       (1u << 11)
#define SPI_CTRL_TX_NEG    (1u << 10)
#define SPI_CTRL_RX_NEG    (1u << 9)
#define SPI_CTRL_GO        (1u << 8)
#define SPI_CTRL_CHAR_MASK 0x7fu

static inline uint32_t mmio_read32(uintptr_t addr) {
  return *(volatile uint32_t *)addr;
}

static inline void mmio_write32(uintptr_t addr, uint32_t data) {
  *(volatile uint32_t *)addr = data;
}

static uint8_t reverse8(uint8_t x) {
  x = ((x & 0xf0u) >> 4) | ((x & 0x0fu) << 4);
  x = ((x & 0xccu) >> 2) | ((x & 0x33u) << 2);
  x = ((x & 0xaau) >> 1) | ((x & 0x55u) << 1);
  return x;
}

static uint8_t spi_bitrev_once(uint8_t in) {
  const uint32_t ss = (1u << 7);
  mmio_write32(SPI_DIV_ADDR, 0u);
  mmio_write32(SPI_SS_ADDR, ss);
  mmio_write32(SPI_TX0_ADDR, (uint32_t)in);

  uint32_t ctrl = SPI_CTRL_ASS | SPI_CTRL_LSB | SPI_CTRL_RX_NEG | (16u & SPI_CTRL_CHAR_MASK);
  mmio_write32(SPI_CTRL_ADDR, ctrl | SPI_CTRL_GO);

  while ((mmio_read32(SPI_CTRL_ADDR) & SPI_CTRL_GO) != 0) {
  }

  uint32_t rx = mmio_read32(SPI_RX0_ADDR);
  return (uint8_t)((rx >> 8) & 0xffu);
}

int main(void) {
  uint8_t vec[] = {0x01u, 0x12u, 0x69u, 0x96u, 0xa5u};
  for (int i = 0; i < (int)(sizeof(vec) / sizeof(vec[0])); i++) {
    uint8_t in = vec[i];
    uint8_t got = spi_bitrev_once(in);
    uint8_t exp = reverse8(in);
    if (got != exp) {
      halt(1);
    }
  }
  return 0;
}
