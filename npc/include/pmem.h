#ifndef MEMORY_H
#define MEMORY_H

#include "common.h"

extern word_t flash[];
word_t pmem_read(paddr_t addr);
void pmem_write(word_t addr, word_t data, int mask);

#endif