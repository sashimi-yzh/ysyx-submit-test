#include <device/map.h>
#include <device/mmio.h>
#include <npc.h>

#define NR_MAP 16

static IOMap maps[NR_MAP] = {};
static int nr_map = 0;

static IOMap* fetch_mmio_map(paddr_t addr) {
  int mapid = find_mapid_by_addr(maps, nr_map, addr);
  return (mapid == -1 ? NULL : &maps[mapid]);
}

void add_mmio_map(const char *name, paddr_t addr, void *space, uint32_t len, io_callback_t callback) {
  assert(nr_map < NR_MAP);
  paddr_t left = addr, right = addr + len - 1;

  for (int i = 0; i < nr_map; i++) {
    if (left <= maps[i].high && right >= maps[i].low) {
      Assert(0, "MMIO region %s@[0x%08x, 0x%08x] overlaps with %s@[0x%08x, 0x%08x]",
          name, left, right, maps[i].name, maps[i].low, maps[i].high);
    }
  }

  maps[nr_map] = (IOMap){ .name = name, .low = addr, .high = addr + len - 1,
    .space = space, .callback = callback };
  Log("Add mmio map '%s' at [0x%08x, 0x%08x]",
      maps[nr_map].name, maps[nr_map].low, maps[nr_map].high);

  nr_map ++;
}

word_t mmio_read(paddr_t addr, int len) {
  IOMap *map = fetch_mmio_map(addr);
  if (map == NULL) {
    Log("Warning: mmio_read at unmapped address 0x%08x", addr);
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = CPU_PC();
    return 0;
  }
  return map_read(addr, len, map);
}

void mmio_write(paddr_t addr, int len, word_t data) {
  IOMap *map = fetch_mmio_map(addr);
  if (map == NULL) {
    Log("Warning: mmio_write at unmapped address 0x%08x", addr);
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = CPU_PC();
    return;
  }
  map_write(addr, len, data, map);
}
