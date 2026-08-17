#pragma once

#include "PerformanceCounter.h"
#include <Flash.h>
#include <MROM.h>
#include <cstdint>
#include <my_utils.h>
#include <ostream>
#include <spdlog/spdlog.h>
#include <stdexcept>
#include <vector>

struct VirtualBus {
  VirtualBus()
      : sram(2048), psram(1024 * 1024 * 1), sdram(1024 * 1024 * 8 * 4),
        vga_buffer(640 * 480) {}

  struct ReadResult {
    uint32_t data;
    bool read_nonmemory;
  };
  ReadResult readMemory(uint32_t addr, int sz) {
    if ((addr & (sz - 1)) != 0) {
      log_and_throw<std::logic_error>(
          "Unaligned read in address {:08x}, size = {}", addr, sz);
    }

    auto check_range = [=](Area area) {
      return addr >= area.from && addr + sz - 1 <= area.to;
    };
    if (check_range(clint_field)) {
      return {0xdeadbeef, true};
    } else if (check_range(mrom_field)) {
      {
        log_and_throw<std::logic_error>(
            "Failed to read from address {:08x} : MROM is no longer supported",
            addr);
        // return {mrom_content[(addr & 0x00FFFFFF) >> 2], false};
      }
    } else if (check_range(sram_field)) {
      return {sram[(addr & 0x00FFFFFF) >> 2], false};
    } else if (check_range(flash_field)) {
      return {flash_content[(addr & 0x0FFFFFFF) >> 2], false};
    } else if (check_range(uart_field)) {
      return {0xdeadbeef, true};
    } else if (check_range(spi_field)) {
      return {0xdeadbeef, true};
    } else if (check_range(psram_field)) {
      return {psram[(addr & 0x00FFFFFF) >> 2], false};
    } else if (check_range(sdram_field)) {
      if (((addr & 0x0FFFFFFF) >> 2) >= sdram.size()) {
        log_and_throw<std::logic_error>("SDRAM read addr {:08x} overflow",
                                        addr);
      }
      return {sdram[(addr & 0x0FFFFFFF) >> 2], false};
    } else if (check_range(gpio_field)) {
      return {0xdeadbeef, true};
    } else if (check_range(keyboard_field)) {
      return {0xdeadbeef, true};
    } else if (check_range(vga_field)) {
      return {vga_buffer[(addr & 0x00FFFFFF) >> 2], false};
    } else {
      log_and_throw<std::logic_error>(
          "Failed to decode read addr {:08x}, size = {}", addr, sz);
    }
  }

  void writeMemory(uint32_t addr, uint32_t wdata, uint32_t wmask) {
    // if (addr == 0x0f001FD8) {
    //   spdlog::info("Addr = {:08x}, pc = {:08x}, wdata = {:08x}, {}ps", addr,
    //                dut->getPC(), wdata, dut->getSimTime() * 2);
    // }
    constexpr std::array<uint32_t, 16> lookup_mask32 = {
        0x00000000, 0x000000FF, 0x0000FF00, 0x0000FFFF, 0x00FF0000, 0x00FF00FF,
        0x00FFFF00, 0x00FFFFFF, 0xFF000000, 0xFF0000FF, 0xFF00FF00, 0xFF00FFFF,
        0xFFFF0000, 0xFFFF00FF, 0xFFFFFF00, 0xFFFFFFFF};
    auto check_range = [=](Area area) {
      return addr >= area.from && addr <= area.to;
    };
    if ((addr & 0x3) != 0) {
      log_and_throw<std::logic_error>("Unaligned write to address {:08x}",
                                      addr);
    }
    uint32_t mask32 = lookup_mask32[wmask];
    if (check_range(clint_field)) {
      log_and_throw<std::logic_error>(
          "Failed to write to address {:08x} : CLINT can not be written", addr);
    } else if (check_range(mrom_field)) {
      log_and_throw<std::logic_error>(
          "Failed to write to address {:08x} : MROM can not be written", addr);
    } else if (check_range(sram_field)) {
      sram[(addr & 0x00FFFFFF) >> 2] &= ~mask32;
      sram[(addr & 0x00FFFFFF) >> 2] |= wdata & mask32;
    } else if (check_range(uart_field)) {
      // no action
    } else if (check_range(spi_field)) {
      // no action
    } else if (check_range(flash_field)) {
      log_and_throw<std::logic_error>(
          "Failed to write to address {:} : flash can not be written", addr);
    } else if (check_range(psram_field)) {
      psram[(addr & 0x00FFFFFF) >> 2] &= ~mask32;
      psram[(addr & 0x00FFFFFF) >> 2] |= wdata & mask32;
    } else if (check_range(sdram_field)) {
      if (((addr & 0x0FFFFFFF) >> 2) >= sdram.size()) {
        log_and_throw<std::logic_error>("SDRAM write addr {:08x} overflow",
                                        addr);
      }
      sdram[(addr & 0x0FFFFFFF) >> 2] &= ~mask32;
      sdram[(addr & 0x0FFFFFFF) >> 2] |= wdata & mask32;
    } else if (check_range(gpio_field)) {
      // no action
    } else if (check_range(keyboard_field)) {
      log_and_throw<std::logic_error>(
          "Failed to write to address {:} : keyboard can not be written", addr);
    } else if (check_range(vga_field)) {
      if (((addr & 0x00FFFFFF) >> 2) >= vga_buffer.size()) {
        log_and_throw<std::logic_error>("VGA buffer write addr {:08x} overflow",
                                        addr);
      }
      vga_buffer[(addr & 0x00FFFFFF) >> 2] &= ~mask32;
      vga_buffer[(addr & 0x00FFFFFF) >> 2] |= wdata & mask32;
    } else {
      log_and_throw<std::logic_error>("Failed to decode write addr {:08x}",
                                      addr);
    }
  }

  struct Area {
    uint32_t from, to;
  };
  const Area clint_field = {0x02000000, 0x02000fff};
  const Area mrom_field = {0x20000000, 0x20000fff};

  const Area flash_field = {0x30000000, 0x3fffffff};

  std::vector<uint32_t> sram;
  const Area sram_field = {0x0f000000, 0x0f001fff};

  const Area uart_field = {0x10000000, 0x10000fff};
  const Area spi_field = {0x10001000, 0x10001fff};

  std::vector<uint32_t> psram;
  const Area psram_field = {0x80000000, 0x9fffffff};

  std::vector<uint32_t> sdram;
  const Area sdram_field = {0xa0000000, 0xbfffffff};
  const Area gpio_field = {0x10002000, 0x1000200f};
  const Area keyboard_field = {0x10011000, 0x10011007};

  std::vector<uint32_t> vga_buffer;
  const Area vga_field = {0x21000000, 0x211fffff};
};