#pragma once

#include "Setup.h"
#include <cstdint>
#include <my_utils.h>
#include <spdlog/spdlog.h>
#include <stdexcept>
#include <vector>

struct VirtualBus {
  VirtualBus() : ram((config.mem_size + 3) / 4) {}

  struct ReadResult {
    uint32_t data;
    bool read_nonmemory;
  };
  ReadResult readMemory(uint32_t addr, int sz) {
    if ((addr & (sz - 1)) != 0) {
      log_and_throw<std::logic_error>(
          "Unaligned read in address {:08x}, size = {}", addr, sz);
    }

    if (addr >= config.base_memory &&
        addr < config.base_memory + config.mem_size) {
      return {ram[(addr - config.base_memory) / sizeof(uint32_t)], false};
    } else if (addr >= config.base_device &&
               addr < config.base_device + config.device_size) {
      return {0xdeadbeef, true};
    } else {
      log_and_throw<std::logic_error>(
          "Failed to decode read addr in difftest {:08x}, size = {}", addr, sz);
    }
  }

  void writeMemory(uint32_t addr, uint32_t wdata, uint32_t wmask) {
    if ((addr & 0x3) != 0) {
      log_and_throw<std::logic_error>("Unaligned write to address {:08x}",
                                      addr);
    }
    uint32_t mask32 = lookup_mask32[wmask];
    if (addr >= config.base_memory &&
        addr < config.base_memory + config.mem_size) {
      write_mask(ram[(addr - config.base_memory) / sizeof(uint32_t)], mask32,
                 wdata);
    } else if (addr >= config.base_device &&
               addr < config.base_device + config.device_size) {
      // Do nothing
    } else {
      log_and_throw<std::logic_error>("Failed to decode write addr {:08x}",
                                      addr);
    }
  }

  std::vector<uint32_t> ram;
};