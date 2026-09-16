#include <memory/host.h>
#include <memory/vaddr.h>
#include <device/map.h>

#define IO_SPACE_MAX (32 * 1024 * 1024)

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
    Assert(map != NULL, "address (" FMT_PADDR ") is out of bound at pc = " FMT_WORD, addr, _lsu_pc_data_);
  } else {
    Assert(addr <= map->high && addr >= map->low,
        "address (" FMT_PADDR ") is out of bound {%s} [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, map->name, map->low, map->high, _lsu_pc_data_);
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
  uint8_t *space_ptr = (uint8_t *)map->space;
  word_t ret = host_read(space_ptr + offset, len);
  #if CONFIG_DTRACE
    char s [128];
    snprintf(s, 128, "map_read: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, ret);
    //printf("map_read: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, ret);
    log_write("%s\n", s);
  #endif
  return ret;
}

void map_write(paddr_t addr, int len, word_t data, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  uint8_t *space_ptr = (uint8_t *)map->space;
  host_write(space_ptr + offset, len, data);
  #if CONFIG_DTRACE
    char s [128];
    snprintf(s, 128, "map_write: addr = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data);
    log_write("%s\n", s);
  #endif
  invoke_callback(map->callback, offset, len, true);
}
