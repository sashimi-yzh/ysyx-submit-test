#include "mem.hpp"
#include "mregion.hpp"

#include "../sim.hpp"

#include "../common.hpp"
#include <algorithm>
#include <cstdint>
#include <ranges>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/dup_filter_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <variant>

#define mem_regions get_mem_regions()

uint8_t *mem_guest_to_host(uint32_t addr) {
  for (auto &r : mem_regions) {
    auto res = std::visit(
        [&](auto &region) -> uint8_t * {
          if (region.contains(addr)) {
            return region.get_data_ptr_at(addr);
          }
          return nullptr;
        },
        r);
    if (res) {
      return res;
    }
  }
  spdlog::error("sim_guest_to_host addr={:08x} no mapping region", addr);
  return nullptr;
}

bool read_guest_mem(uint32_t addr, uint32_t *data) {
  bool ok = std::ranges::any_of(mem_regions, [&](auto &v) {
    return std::visit(
        [&](auto &r) { return r.contains(addr) && r.read_word(addr, *data); },
        v);
  });
  if (!ok)
    spdlog::warn("sim_read_vmem addr={:08x} no mapping region or read failed",
                 addr);
  return ok;
}
bool write_guest_mem(uint32_t addr, uint32_t data) {
  bool ok = std::ranges::any_of(mem_regions, [&](auto &v) {
    return std::visit(
        [&](auto &r) { return r.contains(addr) && r.write_word(addr, data); },
        v);
  });
  if (!ok)
    spdlog::warn("sim_write_vmem addr={:08x} no mapping region or write failed",
                 addr);
  return ok;
}
