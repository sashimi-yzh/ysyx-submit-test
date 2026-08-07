#pragma once
#include <bits/stdc++.h>
#include <format.hpp>
#define MEMORY_SIZE 0x10000000
#define PMEM_BASE 0x20000000
#define FLASH_BASE 0x30000000
#define FLASH_SIZE 0x01000000
#define SERIAL_PORT 0xa00003f8
class Memory {
private:
  std::unique_ptr<uint8_t[]> mem;
  uint32_t file_size;
  Memory() { mem = std::make_unique<uint8_t[]>(MEMORY_SIZE); };
  Memory(const Memory &) = delete;
  Memory &operator=(const Memory &) = delete;

  bool inRange(uint32_t addr) const { return addr < MEMORY_SIZE; }

public:
  static Memory &getInstance() {
    static Memory instance;
    return instance;
  }
  uint32_t size() const { return file_size; }
  uint32_t read(uint32_t addr) {
    if (!inRange(addr))
      return 0;
    return mem[addr + 0] | (mem[addr + 1] << 8) | (mem[addr + 2] << 16) |
           (mem[addr + 3] << 24);
  }
  void write(uint32_t addr, uint32_t data, uint8_t mask) {
    if (!inRange(addr)) {
      if (addr + NPC_RESET_VECTOR == SERIAL_PORT) {
        putchar(data & 0xff);
        fflush(stdout);
      }
      return;
    }
    for (int i = 0; i < 4; i++) {
      if ((mask >> i) & 1)
        mem[addr + i] = (data >> 8 * i) & 0xff;
    }
  }
  void load(std::string file_name) {
    std::ifstream pmem_file(file_name, std::ios::binary | std::ios::ate);
    file_size = pmem_file.tellg();
    if (file_size > MEMORY_SIZE) {
      print("file_size:", file_size);
      print("MEMORY_SIZE:", MEMORY_SIZE);
      exit(1);
    }
    pmem_file.seekg(0, std::ios::beg);
    pmem_file.read(reinterpret_cast<char *>(mem.get()), file_size);
  }
  uint8_t *getBuf() { return mem.get(); }
};
