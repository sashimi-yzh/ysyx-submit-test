#include <device/dtrace.h>
#include <device/map.h>
#include <isa.h>
void dtrace_read(paddr_t addr, int len, IOMap *map) {
  Log("Device Name = %s : read address = " FMT_PADDR " at pc = " FMT_WORD " with byte = %d",
      map->name, addr, cpu.pc, len);
}
void dtrace_write(paddr_t addr, int len, word_t data, IOMap *map) {
  Log("Drive Name = %s : write address = " FMT_PADDR " at pc = " FMT_WORD " with byte = %d and data = " FMT_WORD,
      map->name, addr, cpu.pc, len, data);
}