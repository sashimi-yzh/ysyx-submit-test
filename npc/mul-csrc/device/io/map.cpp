#include "../../../include/common.h"
#include "../../../include/debug.h"
#include "../../../include/paddr.h"
#include "../../../include/device/map.h"
#include "Vysyx_25010030.h"
#include "Vysyx_25010030__Dpi.h"
#include "../obj_dir/Vysyx_25010030___024root.h"

#define IO_SPACE_MAX (2 * 1024 * 1024)

extern word_t host_read(void *addr, int len);
extern void host_write(void *addr, int len, word_t data);
extern Vysyx_25010030 *top;

static uint8_t *io_space = NULL;
static uint8_t *p_space = NULL;

uint8_t* new_space(int size) {
  uint8_t *p = p_space;
  // page aligned;
  size = (size + (PAGE_SIZE - 1)) & ~PAGE_MASK;
  p_space += size;
  assert(p_space - io_space < IO_SPACE_MAX);
  return p;
}

static void check_bound(IOMap *map, paddr_t addr) {
  if (map == NULL) {
    Assert(map != NULL, "address (" FMT_PADDR ") is out of bound at pc = " FMT_WORD, addr, top->rootp->ysyx_25010030__DOT__pc);
  } else {
    Assert(addr <= map->high && addr >= map->low,
        "address (" FMT_PADDR ") is out of bound {%s} [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, map->name, map->low, map->high, top->rootp->ysyx_25010030__DOT__pc);
  }
}

static void invoke_callback(io_callback_t c, paddr_t offset, int len, bool is_write) {
  if (c != NULL) { c(offset, len, is_write); }
}

void init_map() {
  io_space = (uint8_t *)malloc(IO_SPACE_MAX);
  assert(io_space);
  p_space = io_space;
}

word_t map_read(paddr_t addr, int len, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  invoke_callback(map->callback, offset, len, false); // prepare data to read
  word_t ret = host_read((uint8_t *)map->space + offset, len);
  return ret;
}

void map_write(paddr_t addr, int len, word_t data, IOMap *map) {
  // printf("map_write addr == %x, len == %d, data == %ld\n",addr,len,data);
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  host_write((uint8_t *)map->space + offset, len, data);
  invoke_callback(map->callback, offset, len, true);
}