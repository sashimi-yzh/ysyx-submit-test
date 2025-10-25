#include "device.h"
#include "../../riscv.h"
#include "am.h"

void flash_spi_init()
{
  device_ctrl spi_ctrl = (device_ctrl)(DEV_SPI + 0x10);
  spi_ctrl[3] = 0x00;
  spi_ctrl[2] = 0x00;
  spi_ctrl[1] = 0x20;
  spi_ctrl[0] = 0x40;//10000
  
  device_ctrl spi_divider = (device_ctrl)(DEV_SPI + 0x14);
  spi_divider[3] = 0;
  spi_divider[2] = 0;
  spi_divider[1] = 0;
  spi_divider[0] = 0x01;

  device_ctrl spi_ss = (device_ctrl)(DEV_SPI + 0x18);
  spi_ss[3] = 0;
  spi_ss[2] = 0;
  spi_ss[1] = 0;
  spi_ss[0] = 1;
}


uint32_t flash_read(uint32_t addr)
{
    uint8_t* addr_t = (uint8_t*)&addr;
    device_ctrl spi_tx = (device_ctrl)(DEV_SPI + 4);
    spi_tx[3] = 0x03;
    spi_tx[2] = addr_t[2];
    spi_tx[1] = addr_t[1];
    spi_tx[0] = addr_t[0];

    device_ctrl spi_ctrl = (device_ctrl)(DEV_SPI + 0x10);
    spi_ctrl[1] = 0x21;

    while (spi_ctrl[1] == 0x21);

    device_ctrl spi_rx = (device_ctrl)(DEV_SPI);
    uint32_t ret = 0;
    addr_t = (uint8_t*)&ret;
    addr_t[0] = spi_rx[3];
    addr_t[1] = spi_rx[2];
    addr_t[2] = spi_rx[1];
    addr_t[3] = spi_rx[0];

    return ret;
}