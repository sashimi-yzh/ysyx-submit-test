#ifndef NPC_MEMORY_H
#define NPC_MEMORY_H

#include <string.h>

#include <npc/base.h>

static inline bool host_access_size_valid(int length) {
  return length == 1 || length == 2 || length == 4;
}

static inline word_t host_read(const void *address, int length) {
  word_t value = 0;
  if (host_access_size_valid(length)) {
    memcpy(&value, address, (size_t)length);
  }
  return value;
}

static inline void host_write(void *address, int length, word_t value) {
  if (host_access_size_valid(length)) {
    memcpy(address, &value, (size_t)length);
  }
}

NPC_EXTERN_C_BEGIN

word_t paddr_read(paddr_t address, int length);
void paddr_write(paddr_t address, int length, word_t value);

word_t vaddr_read(vaddr_t address, int length);
word_t vaddr_ifetch(vaddr_t address, int length);
void vaddr_write(vaddr_t address, int length, word_t value);

NPC_EXTERN_C_END

#endif
