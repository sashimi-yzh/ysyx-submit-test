#include <am.h>
#define SPI_BASE 0x10001000
#define SPI_TX0 (*(volatile uint32_t *)(SPI_BASE + 0x00))
#define SPI_TX1 (*(volatile uint32_t *)(SPI_BASE + 0x04))
#define SPI_CTRL (*(volatile uint32_t *)(SPI_BASE + 0x10))
#define SPI_DIV (*(volatile uint32_t *)(SPI_BASE + 0x14))
#define SPI_SS (*(volatile uint8_t *)(SPI_BASE + 0x18))

#define CTRL_ASS (1 << 13)
#define CTRL_TX_NEG (1 << 10)
#define CTRL_RX_NEG (1 << 9)
#define CTRL_GO (1 << 8)
#define SS_FLASH (1 << 0)

static uint32_t bswap32(uint32_t x) {
  return ((x & 0x000000FF) << 24) | ((x & 0x0000FF00) << 8) |
         ((x & 0x00FF0000) >> 8) | ((x & 0xFF000000) >> 24);
}

uint32_t flash_read(uint32_t addr) {
  SPI_TX1 = (0x03u << 24) | (addr & 0x00FFFFFFu);
  SPI_TX0 = 0;
  SPI_DIV = 0;
  SPI_SS = SS_FLASH;
  SPI_CTRL = CTRL_ASS | CTRL_TX_NEG | 64 | CTRL_GO;
  while (SPI_CTRL & CTRL_GO)
    ;
  return bswap32(SPI_TX0);
}