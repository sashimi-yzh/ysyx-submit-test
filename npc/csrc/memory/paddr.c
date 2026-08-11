#include <isa.h>
#include <npc/diagnostics.h>
#include <npc/memory.h>
#include <npc/platform.h>

void init_mem() {
  log_memory();
}

word_t paddr_read(paddr_t address, int length) {
  word_t result = 0;
  Assert(host_access_size_valid(length), "invalid physical read: pc=" FMT_WORD " addr=" FMT_PADDR " len=%d", cpu.pc, address, length);
  if (!mem_read(address, length, &result)) {
    mem_fault(address);
  }
  return result;
}

void paddr_write(paddr_t address, int length, word_t value) {
  Assert(host_access_size_valid(length), "invalid physical write: pc=" FMT_WORD " addr=" FMT_PADDR " len=%d data=" FMT_WORD, cpu.pc, address, length, value);
  if (!mem_write(address, length, value)) {
    mem_fault(address);
  }
}
