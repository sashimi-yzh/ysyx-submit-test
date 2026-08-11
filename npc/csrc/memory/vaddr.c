#include <isa.h>
#include <npc/memory.h>

word_t vaddr_read(vaddr_t address, int length) {
  return paddr_read((paddr_t)address, length);
}

word_t vaddr_ifetch(vaddr_t address, int length) {
  return paddr_read((paddr_t)address, length);
}

void vaddr_write(vaddr_t address, int length, word_t value) {
  paddr_write((paddr_t)address, length, value);
}
