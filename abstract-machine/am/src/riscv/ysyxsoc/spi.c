#include <am.h>
#include "ysyxsoc.h"

void spi_config(uint8_t SS, uint8_t CHAR_LEN) {
  uint32_t ctrl_statu = 0x2800 | CHAR_LEN;
  outw(SPI_DIV, 1);
  outb(SPI_SS, SS);
  outw(SPI_CTRL, ctrl_statu);
}

uint32_t bitrev_read(uint32_t data) {
  outl(SPI_TX0, data);
  uint32_t ctrl_statu = inw(SPI_CTRL) | 0x100;  
  outw(SPI_CTRL, ctrl_statu);
  while (1)
  {
    if(!(inw(SPI_CTRL) & 0x100)) {
      return inl(SPI_RX0);
    }
  }
}