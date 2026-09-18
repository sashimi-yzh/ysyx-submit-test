#include <common.h>
#include <device/map.h>
#include <npc.h>

#define CH_OFFSET 0

static uint8_t *serial_base = NULL;

static void serial_io_handler(uint32_t offset, int len, bool is_write) {
  switch (offset) {
    case CH_OFFSET:
      if (is_write) putchar(serial_base[0]);
      else serial_base[0] = getchar();
      break;
    default: Assert(0, "serial: unsupported offset = %d", offset);
  }
}

void init_serial() {
  serial_base = new_space(8);
  add_mmio_map("serial", CONFIG_SERIAL_MMIO, serial_base, 8, serial_io_handler);
}
