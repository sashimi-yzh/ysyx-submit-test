#include "map.h"
#include "common.h"
#include "host.h"
#include "vaddr.h"
#include <assert.h>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdint.h>

#define MAXIO 16
#define MAXIOSIZE 2 * 1024 * 1024

static IOMAP iomap[MAXIO] = {};
static int nr_map = 0;
static uint8_t *io_space;
static uint8_t *p_space;

uint8_t *new_space(size_t size) {
  uint8_t *p = (uint8_t *)p_space;
  // page aligned;
  size = (size + (PAGE_SIZE - 1)) & ~PAGE_MASK;
  p_space = p_space + size;
  assert(p_space - io_space < MAXIOSIZE);
  return p;
}

void map_init() {
  io_space = (uint8_t *)malloc(MAXIOSIZE);
  if (io_space == NULL) {
    std::cerr << "[error] falied to alloc io_space" << std::endl;
    assert(0);
  }
  p_space = io_space;
}

void add_mmio_map(char *name, uint32_t addr, size_t size, void *space,
                  io_callback_t callback) {
  assert(nr_map < MAXIO);
  uint32_t left = addr;
  uint32_t right = addr + size - 1;
  if (in_pmem(left) || in_pmem(right)) {
    std::cerr << "[error] confilct iospace and pmem" << std::endl;
    assert(0);
  }
  for (int i = 0; i < nr_map; i++) {
    if (left <= iomap[i].low && right >= iomap[i].high) {
      std::cerr << "[error] confilct addiomap to " << iomap[i].name
                << std::endl;
      assert(0);
    }
  }

  iomap[nr_map] = IOMAP{.name = name,
                        .high = right,
                        .low = left,
                        .space = space,
                        .callback = callback};
  nr_map++;
}

IOMAP *fetch_mmio_map(uint32_t addr) {
  int i = 0;
  for (; i < nr_map; i++) {
    if (map_inside(iomap + i, addr) == 1) {
#ifdef DIFFTEST
      set_ref_skip();
#endif
      return &iomap[i];
    }
  }
  return NULL;
}

static void invoke_callback(io_callback_t c, uint32_t offset, int len,
                            bool is_write) {
  if (c != NULL) {
    c(offset, len, is_write);
  }
}

uint32_t map_read(uint32_t addr, int len, IOMAP *map) {
  if (map == NULL) {
    std::cout << "[paddr_read]the addr 0x" << std::setw(8) << std::hex << addr
              << " is out of bound" << std::endl;
    tfpclose();
    assert(0);
  }
  assert(len >= 1 && len <= 8);
  uint32_t offset = addr - map->low;
  invoke_callback(map->callback, offset, len, false);
  // prepare data to read
  uint32_t ret = pmem_read((uint8_t *)(map->space + offset), len);
  return ret;
}

void map_write(uint32_t addr, int len, uint32_t data, IOMAP *map) {
  if (map == NULL) {
    std::cout << "[paddr_write]the addr 0x" << std::setw(8) << std::hex << addr
              << " is out of bound" << std::endl;
    tfpclose();
    assert(0);
  }
  assert(len >= 1 && len <= 8);
  uint32_t offset = addr - map->low;
  pmem_write((uint8_t *)(map->space) + offset, len, data);
  invoke_callback(map->callback, offset, len, true);
}

uint32_t mmio_read(uint32_t addr, int len) {
  return map_read(addr, len, fetch_mmio_map(addr));
}

void mmio_write(uint32_t addr, int len, uint32_t data) {
  map_write(addr, len, data, fetch_mmio_map(addr));
  return;
}
