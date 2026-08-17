#pragma once

#include <Flash.h>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <my_utils.h>
#include <print>
#include <spdlog/spdlog.h>
#include <stdexcept>
#include <vector>

struct VirtualBus {
  VirtualBus()
      : sram(2048), psram(1024 * 1024 * 1), sdram(1024 * 1024 * 8 * 4),
        vga_buffer(640 * 480) {}

  uint32_t readMemory(uint32_t addr, int sz) {
    if ((addr & (sz - 1)) != 0) {
      log_and_throw<std::logic_error>(
          "Unaligned read in address {:08x}, size = {}", addr, sz);
    }

    auto check_range = [=](Area area) {
      return addr >= area.from && addr + sz - 1 <= area.to;
    };
    if (check_range(clint_field)) {
      return 0;
    } else if (check_range(sram_field)) {
      return sram[(addr & 0x00FFFFFF) >> 2];
    } else if (check_range(flash_field)) {
      // spdlog::info("{:08x} {:08x}", (addr & 0x0FFFFFFF) >> 2,
      //              flash_content.size());
      return flash_content[(addr & 0x0FFFFFFF) >> 2];
    } else if (check_range(uart_field)) {
      int internal_addr = (addr & 0xFFF);
      if (internal_addr == 0) {
        if (uart_lcr & (1 << 7))
          return uart_div_lsb;
        else
          return std::cin.get();
      }
      if (internal_addr == 1) {
        if (uart_lcr & (1 << 7))
          return uart_div_msb;
        else
          return 0;
      }
      if (internal_addr == 2)
        return 0x00c10000;
      if (internal_addr == 3)
        return uart_lcr;
      if (internal_addr == 5) {
        return 0x00006000;
      }
      log_and_throw<std::logic_error>(
          "Reading addr {} in UART is not supported", internal_addr);
    } else if (check_range(spi_field)) {
      log_and_throw<std::logic_error>("Direct visit to spi is not supported");
    } else if (check_range(psram_field)) {
      return psram[(addr & 0x00FFFFFF) >> 2];
    } else if (check_range(sdram_field)) {
      if (((addr & 0x0FFFFFFF) >> 2) >= sdram.size()) {
        log_and_throw<std::logic_error>("SDRAM read addr {:08x} overflow",
                                        addr);
      }
      return sdram[(addr & 0x0FFFFFFF) >> 2];
    } else if (check_range(gpio_field)) {
      return 0xdeadbeef;
    } else if (check_range(keyboard_field)) {
      return 0xdeadbeef;
    } else if (check_range(vga_field)) {
      return vga_buffer[(addr & 0x00FFFFFF) >> 2];
    } else {
      log_and_throw<std::logic_error>(
          "Failed to decode read addr {:08x}, size = {}", addr, sz);
    }
  }

  void writeMemory(uint32_t addr, uint32_t wdata, uint32_t wmask) {
    constexpr std::array<uint32_t, 16> lookup_mask32 = {
        0x00000000, 0x000000FF, 0x0000FF00, 0x0000FFFF, 0x00FF0000, 0x00FF00FF,
        0x00FFFF00, 0x00FFFFFF, 0xFF000000, 0xFF0000FF, 0xFF00FF00, 0xFF00FFFF,
        0xFFFF0000, 0xFFFF00FF, 0xFFFFFF00, 0xFFFFFFFF};
    auto check_range = [=](Area area) {
      return addr >= area.from && addr <= area.to;
    };
    uint32_t mask32 = lookup_mask32[wmask];
    auto masked_write = [=](uint32_t &dst) {
      dst &= ~mask32;
      dst |= wdata & mask32;
    };

    if ((addr & 0x3) != 0) {
      log_and_throw<std::logic_error>("Unaligned write to address {:08x}",
                                      addr);
    }

    if (check_range(sram_field)) {
      masked_write(sram[(addr & 0x00FFFFFF) >> 2]);
    } else if (check_range(uart_field)) {
      int internal_addr = (addr & 0xFFF);
      if (internal_addr == 0) {
        if (uart_lcr & (1 << 7))
          masked_write(uart_div_lsb);
        else {
          std::cout.put(wdata & 0xff);
        }
      } else if (internal_addr == 1) {
        if (uart_lcr & (1 << 7)) {
          masked_write(uart_div_msb);
          uart_div_msb >>= 8;
        } else
          log_and_throw<std::logic_error>("UART INT is not supported");
      } else if (internal_addr == 2) {
        log_and_throw<std::logic_error>(
            "UART FIFO control register is not supported");
      } else if (internal_addr == 3) {
        masked_write(uart_lcr);
        uart_lcr >>= 24;
      } else if (internal_addr == 4) {
        log_and_throw<std::logic_error>(
            "UART modem control register is not supported");
      } else {
        log_and_throw<std::logic_error>("Can not write to UART addr {}",
                                        internal_addr);
      }

    } else if (check_range(spi_field)) {
      log_and_throw<std::logic_error>("Direct visit to spi is not supported");
    } else if (check_range(flash_field)) {
      log_and_throw<std::logic_error>(
          "Failed to write to address {:} : flash can not be written", addr);
    } else if (check_range(psram_field)) {
      masked_write(psram[(addr & 0x00FFFFFF) >> 2]);
    } else if (check_range(sdram_field)) {
      if (((addr & 0x0FFFFFFF) >> 2) >= sdram.size()) {
        log_and_throw<std::logic_error>("SDRAM write addr {:08x} overflow",
                                        addr);
      }
      masked_write(sdram[(addr & 0x0FFFFFFF) >> 2]);
    } else if (check_range(gpio_field)) {
      log_and_throw<std::logic_error>("GPIO is not supported in SOC EMU");
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

  std::vector<uint32_t> flash;
  const Area clint_field = {0x02000000, 0x0200ffff};
  const Area flash_field = {0x30000000, 0x3fffffff};

  std::vector<uint32_t> sram;
  const Area sram_field = {0x0f000000, 0x0f001fff};

  uint32_t uart_div_msb, uart_div_lsb, uart_lcr;
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

  void init_flash(std::string_view image_path) {
    // image_path =
    // "/home/shitful/1s1x/ysyx-workbench/soc_kernal/mrom_test/build/"
    //              "mromtest.bin";
    using std::ifstream;
    using std::ios;

    std::filesystem::path program_path = image_path;
    std::ifstream prog_file(program_path, ios::in | ios::binary);
    if (!prog_file.is_open()) {
      log_and_throw<std::runtime_error>("Failed to open image file : {}",
                                        image_path);
    }
    uint32_t size_prog = 0;
    prog_file.seekg(0, ios::end);
    size_prog = prog_file.tellg();
    prog_file.seekg(0, ios::beg);
    flash_content.resize((size_prog + 3) / 4);

    prog_file.read(reinterpret_cast<char *>(flash_content.data()), size_prog);
    prog_file.close();
    spdlog::info("Loaded {} bytes to flash", size_prog);
  }
};