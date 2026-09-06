#include "common.h"
#include "map.h"
#include <assert.h>
#include <iostream>

#define SERIAL_BASE 0xa00003f8

uint8_t *serial_port = NULL;

static void serial_io_handle(uint32_t offset, int len, bool is_write) {
  assert(len == 1);
  if (offset != 0) {
    std::cerr << "[error] unsupport offset of serial " << offset << std::endl;
    assert(0);
  }
  if (!is_write) {
    std::cerr << "[error] serila dont support to read" << std::endl;
    assert(0);
  }
  std::putc(serial_port[0], stderr);
  return;
}

void serial_init() {
  serial_port = new_space(8);
  add_mmio_map("serial", SERIAL_BASE, 8, serial_port, serial_io_handle);
}
