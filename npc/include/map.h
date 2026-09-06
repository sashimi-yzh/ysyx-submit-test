#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#ifndef _MAP_H_
#define _MAP_H_
typedef void (*io_callback_t)(uint32_t, int, bool);

typedef struct {
  char *name;
  uint32_t high;
  uint32_t low;
  void *space;
  io_callback_t callback;
} IOMAP;

inline int map_inside(IOMAP *iomap, uint32_t addr) {
  return (addr >= iomap->low && addr <= iomap->high) ? 1 : 0;
}

void map_init();

uint32_t mmio_read(uint32_t addr, int len);
void mmio_write(uint32_t addr, int len, uint32_t data);

uint8_t *new_space(size_t size);
void add_mmio_map(char *name, uint32_t addr, size_t size, void *space,
                  io_callback_t callback);

// device
void device_init();
void serial_init();
void rtc_init();
#endif
