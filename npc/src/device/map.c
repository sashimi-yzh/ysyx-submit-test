#include <common.h>
#include <npc.h>
#include <device/map.h>
#include <sys/time.h>

#define IO_SPACE_MAX (32 * 1024 * 1024)
#define PAGE_SIZE 4096
#define PAGE_MASK (PAGE_SIZE - 1)

static uint8_t *io_space = NULL;
static uint8_t *p_space = NULL;

uint8_t* new_space(int size) {
  uint8_t *p = p_space;
  size = (size + (PAGE_SIZE - 1)) & ~PAGE_MASK;
  p_space += size;
  assert(p_space - io_space < IO_SPACE_MAX);
  return p;
}

static void check_bound(IOMap *map, paddr_t addr) {
  if (map == NULL) {
    Assert(map != NULL, "address (0x%08x) is out of bound", addr);
  } else {
    Assert(addr <= map->high && addr >= map->low,
        "address (0x%08x) is out of bound {%s} [0x%08x, 0x%08x]",
        addr, map->name, map->low, map->high);
  }
}

static void invoke_callback(io_callback_t c, paddr_t offset, int len, bool is_write) {
  if (c != NULL) { c(offset, len, is_write); }
}

static word_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: assert(0); return 0;
  }
}

static void host_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    default: assert(0);
  }
}

void init_map() {
  io_space = (uint8_t *)malloc(IO_SPACE_MAX);
  assert(io_space);
  p_space = io_space;
}

word_t map_read(paddr_t addr, int len, IOMap *map) {
  assert(len >= 1 && len <= 4);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  invoke_callback(map->callback, offset, len, false);
  word_t ret = host_read((uint8_t *)map->space + offset, len);

#ifdef CONFIG_MTRACE
  printf("(device)read  %s at 0x%08x len %d, data = 0x%08x\n", map->name, addr, len, ret);
#endif

  return ret;
}

void map_write(paddr_t addr, int len, word_t data, IOMap *map) {
  assert(len >= 1 && len <= 4);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  host_write((uint8_t *)map->space + offset, len, data);
  invoke_callback(map->callback, offset, len, true);

#ifdef CONFIG_MTRACE
  printf("(device)write %s at 0x%08x len %d, data = 0x%08x\n", map->name, addr, len, data);
#endif
}

uint64_t get_time() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (uint64_t)tv.tv_sec * 1000000 + (uint64_t)tv.tv_usec;
}
