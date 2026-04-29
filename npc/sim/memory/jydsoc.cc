#include "mem.hpp"
#include <cstdint>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <span>

#include "../sdbWrap.hpp"

namespace fs = std::filesystem;

#ifdef SIM_ARCH_JYD

static std::shared_ptr<direct_mapped_mem> irom_ptr, dram_ptr;

mem_region_group_t &get_mem_regions() {
  static mem_region_group_t mem_regions;
  if (mem_regions.empty()) {
    if (irom_ptr && dram_ptr) {
      mem_regions.push_back(*irom_ptr);
      mem_regions.push_back(*dram_ptr);
    } else {
      spdlog::warn(
          "try to get mem regions of jydsoc before init, returning empty "
          "region list");
    }
  }
  return mem_regions;
}

static size_t dram_difftest_need_init_size = 0;

void init_mem(void *img, const sim_config &cfg) {
  fs::path img_path(cfg.img_file_path);
  auto dram_path = img_path;
  dram_path.replace_extension(".data.bin");
  if (!fs::exists(dram_path)) {
    spdlog::error("DRAM data file {} does not exist, cannot init DRAM content",
                  dram_path.string());
    exit(1);
  }

  irom_ptr = std::make_shared<direct_mapped_mem>(
      0x80000000u, 0x80004000u, "irom", 16 * 1024,
      get_dut()
          ->TestSoC->vlSymsp->TOP__TestSoC__devices__irom__mem__mem_ext.Memory
          .data());
  dram_ptr = std::make_shared<direct_mapped_mem>(
      0x80100000u, 0x80140000u, "dram", 256 * 1024,
      get_dut()
          ->TestSoC->vlSymsp->TOP__TestSoC__devices__dram__mem__mem_ext.Memory
          .data());

  spdlog::info("copy {} to irom of jydsoc", img_path.filename().string());
  irom_ptr->copy_from(img, cfg.img_size);
  std::fstream dram_file(dram_path, std::ios::in | std::ios::binary);
  if (!dram_file) {
    spdlog::error("failed to open DRAM data file {}", dram_path.string());
    exit(1);
  }

  dram_file.seekg(0, std::ios::end);
  size_t dram_file_size = dram_file.tellg();
  if (dram_file_size > dram_ptr->actualSizeInBytes) {
    spdlog::error("DRAM data file {} size {} exceeds the DRAM capacity {}",
                  dram_path.filename().string(), dram_file_size,
                  dram_ptr->actualSizeInBytes);
    exit(1);
  }
  dram_file.seekg(0, std::ios::beg);

  dram_file.read((char *)dram_ptr->data, dram_ptr->actualSizeInBytes);
  auto bytes_read = dram_file.gcount();
  spdlog::info("read {} bytes from DRAM data file {}", bytes_read,
               dram_path.filename().string());

  // if the DRAM data file is smaller than the DRAM capacity, difftest other
  // bytes are randomly, which may cause difftest failure. So we make difftest
  // cpy all DRAM size, to make difftest dram content exactly the same as the
  // sim DRAM content
  dram_difftest_need_init_size = dram_ptr->actualSizeInBytes;
  spdlog::info("DRAM need init size set to {}, to make difftest DRAM content "
               "exactly the same as sim DRAM content",
               dram_difftest_need_init_size);
}

static constexpr std::string_view fg_red = "\33[1;31m", fg_green = "\33[1;32m",
                                  fg_yellow = "\33[1;33m",
                                  fg_gray = "\33[1;90m",
                                  fg_purple = "\33[1;35m",
                                  fg_blue = "\33[1;34m", ansi_none = "\33[0m";

static uint32_t last_led = 0, last_segs = 0;

static constexpr uint32_t good_trap_led = 0b00000001001000100001110000001000;

bool jyd_is_good_trap() {
  // seg high should be 37 meaning all 37 basic inst test passed
  // led should be good_trap_led meaning the perf test get the right result

  uint8_t seg_high = (last_segs >> 24) & 0xff;

  if (seg_high != 0x37) {
    spdlog::error("7-seg high byte is 0x{:02x}, expected 0x37, not a good trap",
                  seg_high);
    return false;
  }
  if (last_led != good_trap_led) {
    spdlog::error("LED state is 0b{:032b}, expected 0b{:032b}, not a good trap",
                  last_led, good_trap_led);
    return false;
  }
  return true;
}

static void print_board() {
  auto led = last_led;
  auto segs = last_segs;
  uint8_t led_row[4];

  uint32_t test_passed_led = good_trap_led;
  uint32_t test_failed_led = 0b00100100000110000001100000100100;

  auto led_color = (led == test_passed_led)   ? fg_green
                   : (led == test_failed_led) ? fg_red
                                              : fg_yellow;

  for (int i = 3; i >= 0; i--) {
    led_row[i] = (led >> (i * 8)) & 0xff;
    std::cout << "  [ ";
    for (int j = 7; j >= 0; j--) {
      if (led_row[i] & (1 << j)) {
        std::cout << led_color << 'x' << ansi_none;
      } else {
        std::cout << fg_gray << '.' << ansi_none;
      }
    }
    std::cout << " ]";
    if (i == 3) {
      std::cout << "  7-seg:";
    }
    if (i == 2) {
      std::cout << std::format(
          "  {}[{}{:02x}{}][{}{:02x} {:02x} {:02x}{}]{}", fg_gray, ansi_none,
          (segs >> 24) & 0xff, fg_gray, ansi_none, (segs >> 16) & 0xff,
          (segs >> 8) & 0xff, segs & 0xff, fg_gray, ansi_none);
    }
    std::cout << '\n';
  }
}

extern "C" void jyd_update_led(int leds) {
  spdlog::info("LEDs updated: 0b{:032b}", leds);
  last_led = leds;
  print_board();
}
extern "C" void jyd_update_seg(int segs) {
  spdlog::info("7-segment displays updated: 0x{:08x}", segs);
  last_segs = segs;
  print_board();
}

mem_region_data_span_vec get_mem_regions_need_init_difftest() {
  return {mem_region_data_span{
      .name = dram_ptr->name,
      .host_base = dram_ptr->base(),
      .size = dram_difftest_need_init_size,
      .data = dram_ptr->data,
  }};
}
#endif
