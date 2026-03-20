#include "mregion.hpp"
#include "../sim.hpp"
#include <cstdint>
#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

auto _GetLoggerForRegion(std::string_view region_name) {
  auto logger = spdlog::get(region_name.data());
  if (!logger) {
    spdlog::warn("logger for mem region '{}' not found", region_name);
    return spdlog::default_logger();
  }
  return logger;
};

void mem_region_traits::assert_in_range(uint32_t addr) const {
  bool in_range = contains(addr);
  if (!in_range) {
    _GetLoggerForRegion(name)->error(
        "addr {:08x} out of bound for region {} [{:08x}, {:08x})", addr, name,
        _Base, _End);
  }
  assert(in_range);
}

void direct_mapped_mem::assert_in_actual_data_range(uint32_t addr) const {
  size_t offset = addr - _Base;
  if (offset >= actualSizeInBytes) {
    _GetLoggerForRegion(name)->error(
        "addr {:08x} out of actual data bound for region {} "
        "[0, {:08x})",
        addr, this->name, actualSizeInBytes);
  }
  assert(offset < actualSizeInBytes);
}

sdram_mem::u32_data_ptr sdram_mem::get_data_at(uint32_t addr) {
  assert_in_range(addr);
  uint32_t in_sdram_addr = addr - _Base;
  char raw_bank = (in_sdram_addr >> 10) & 0x7;
  uint16_t row = (in_sdram_addr >> 13) & 0x1fff;
  uint16_t col = (in_sdram_addr >> 1) & 0x1ff;
  uint8_t bank = raw_bank % 4;
  uint8_t block = (raw_bank & 0x4) ? 2 : 0;
  return {.lowpart = &data_at(bank, row, col, block),
          .highpart = &data_at(bank, row, col, block + 1)};
}
uint8_t *sdram_mem::get_data_ptr_at(uint32_t addr) {
  assert_in_range(addr);
  spdlog::error(
      "unimpled!!! sdram region does not support direct data pointer access");
  return nullptr;
}

#define ASSERT_BELOW(val, limit)                                               \
  do {                                                                         \
    if ((val) >= (limit)) {                                                    \
      _GetLoggerForRegion(name)->error(                                        \
          "value " #val " should be below " #limit "={}, but got {}", limit,   \
          val);                                                                \
    }                                                                          \
    assert((val) < (limit));                                                   \
  } while (0)
uint16_t &sdram_mem::data_at(size_t bank, size_t row, size_t col,
                             size_t block) {
  ASSERT_BELOW(bank, N_BANKS);
  ASSERT_BELOW(row, N_ROWS);
  ASSERT_BELOW(col, N_COLS);
  ASSERT_BELOW(block, N_BLOCKS);
  return (*mem_container)[bank * (N_ROWS * N_COLS * N_BLOCKS) +
                          row * (N_COLS * N_BLOCKS) + col * N_BLOCKS + block];
}
