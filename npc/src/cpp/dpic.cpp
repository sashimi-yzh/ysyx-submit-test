#include <bits/stdc++.h>
#include <format.hpp>
#include <memory.hpp>
using namespace std;
extern "C" {
auto &memory = Memory::getInstance();
uint32_t pmem_read(uint32_t addr) {
  assert(addr < MEMORY_SIZE);
  return memory.read(addr);
}

void pmem_write(uint32_t addr, uint32_t data, uint32_t mask) {
  assert(addr < MEMORY_SIZE);
  // print("pmem_write", hex(addr), hex(data));
  memory.write(addr, data, mask);
}
void uart(uint8_t data) { putchar(data); }
void flash_read(int32_t addr, int32_t *data) {
  assert(addr < FLASH_BASE + FLASH_SIZE);
  // print("flash_read:", hex(addr), hex(memory.read(addr)));
  *data = memory.read(addr);
}
void mrom_read(int32_t addr, int32_t *data) {
  assert(addr < PMEM_BASE + MEMORY_SIZE);
  // print("mrom_read:",hex(addr), hex(memory.read(addr - PMEM_BASE)));
  *data = memory.read(addr - PMEM_BASE);
}
}
