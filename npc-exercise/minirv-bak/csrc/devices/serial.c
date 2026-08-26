#include "common.h"
#include "devices.h"

static uint32_t serial_io_handler(uint32_t offset, uint32_t data, int len, bool is_write){
  if(is_write && offset == 0)
		putchar(data);
  return 0;
}

void init_serial(){
  add_mmio_space("serial", CONFIG_SERIAL_MMIO, CONFIG_SERIAL_MMIO_SIZE, serial_io_handler);
}