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

#ifdef SIM_ARCH_YSYXSOC

static std::shared_ptr<spdlog::logger> _dpi_logger;

const char *_get_env_or_default(const char *env_name,
                                const char *default_value) {
  const char *env_value = std::getenv(env_name);
  return env_value ? env_value : default_value;
}
void _init_dpi_logger(sim_setting sim_settings) {
  // auto formatter = _gen_logger_formatter_with_simtime();

  auto out_file_name = "dpi";
  auto con_lvl_str = _get_env_or_default("DPI_CONSOLE_LVL", "info");
  auto file_lvl_str = _get_env_or_default("DPI_FILE_LVL", "info");

  auto console_lvl = spdlog::level::from_str(con_lvl_str);
  auto file_lvl = spdlog::level::from_str(file_lvl_str);
  spdlog::info("DPI logger out console lvl {}, out file '{}.log' lvl {}",
               con_lvl_str, out_file_name, file_lvl_str);

  static auto console_sink =
      std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  static auto file_sink = newFileLoggerSink(out_file_name);

  console_sink->set_level(console_lvl);
  auto dup_console = std::make_shared<spdlog::sinks::dup_filter_sink_mt>(
      std::chrono::seconds(3));
  dup_console->add_sink(console_sink);
  dup_console->set_level(console_lvl);

  file_sink->set_level(file_lvl);
  auto dpi_sink_list = spdlog::sinks_init_list{dup_console, file_sink};

#define _REG_DPI_FUNC_LOGGER(func)                                             \
  do {                                                                         \
    auto func_logger = std::make_shared<spdlog::logger>(#func, dpi_sink_list); \
    auto lvl = sim_settings.TRACE_DPI_FLAG(func) ? spdlog::level::trace        \
                                                 : spdlog::level::info;        \
    spdlog::debug("DPI func '{}' logger lvl {}", #func,                        \
                  spdlog::level::to_string_view(lvl));                         \
    func_logger->set_level(lvl);                                               \
    set_logger_pattern_with_simtime(func_logger);                              \
    spdlog::register_logger(func_logger);                                      \
  } while (0)

  _REG_DPI_FUNC_LOGGER(mrom_read);
  _REG_DPI_FUNC_LOGGER(flash_read);
  _REG_DPI_FUNC_LOGGER(psram_read);
  _REG_DPI_FUNC_LOGGER(psram_write);
  _REG_DPI_FUNC_LOGGER(sdram_read);
  _REG_DPI_FUNC_LOGGER(sdram_write);

  _dpi_logger = std::make_shared<spdlog::logger>("DPI", dpi_sink_list);
  _dpi_logger->set_level(spdlog::level::trace);
  set_logger_pattern_with_simtime(_dpi_logger);
  spdlog::register_logger(_dpi_logger);
}

#define EXTERN_C extern "C"

#define DPI_LOG(lvl, fmt, ...)                                                 \
  do {                                                                         \
    auto _loger = spdlog::get(__func__);                                       \
    if (_loger)                                                                \
      _loger->lvl(fmt, ##__VA_ARGS__);                                         \
  } while (0)
#define DPI_TRACE(fmt, ...) DPI_LOG(trace, fmt, ##__VA_ARGS__)
#define DPI_ERROR(fmt, ...) DPI_LOG(error, fmt, ##__VA_ARGS__)
#define DPI_CRITICAL(fmt, ...) DPI_LOG(critical, fmt, ##__VA_ARGS__)

#define DPI_ASSERT(cond, fmt, ...)                                             \
  do {                                                                         \
    if (!(cond)) {                                                             \
      DPI_CRITICAL(fmt, ##__VA_ARGS__);                                        \
      assert(cond);                                                            \
    }                                                                          \
  } while (0)

static struct {
  direct_mapped_mem mrom = {0x20000000u, 0x20010000u, "mrom"};
  direct_mapped_mem flash = {0x30000000u, 0x40000000u, "flash",
                             64 * 1024 * 1024};
  direct_mapped_mem psram = {0x80000000u, 0xa0000000u, "psram",
                             128 * 1024 * 1024};
  direct_mapped_mem sram = {0x0f000000u, 0x10000000u, "sram", 8 * 1024};

  sdram_mem sdram = {0xa0000000u, 0xb0000000u, "sdram"};
} g_mem;

mem_region_group_t &get_mem_regions() {
  static mem_region_group_t mem_regions = {g_mem.mrom, g_mem.flash, g_mem.psram,
                                           g_mem.sram, g_mem.sdram};
  return mem_regions;
}

mem_region_data_span_vec get_mem_regions_need_init_difftest(){
	return {};
}

static void _fill_rams_uninit(bool zero_uninit_ram) {
  if (zero_uninit_ram) {
    g_mem.psram.fill(0);
    g_mem.sdram.fill(0);
  } else {
    g_mem.psram.fill(0xcc);
    spdlog::debug("ysyxSoC psram_data filled with 0xcc");
    g_mem.sdram.fill(0xdd);
    spdlog::debug("ysyxSoC sdram_data filled with 0xdd");
  }
  spdlog::info("RAMs uninitialized area filled with {}",
               zero_uninit_ram ? "zeros" : "non-zero patterns");
}

static void _init_mem_logger() {
  auto lvl = spdlog::level::info;

#define _REG_MEM_REGION_LOGGER(name)                                           \
  do {                                                                         \
    spdlog::debug("Registering logger for mem region '{}'", #name);            \
    auto logger = std::make_shared<spdlog::logger>(                            \
        #name, std::make_shared<spdlog::sinks::stdout_color_sink_mt>());       \
    logger->set_level(lvl);                                                    \
    set_logger_pattern_with_simtime(logger);                                   \
    spdlog::register_logger(logger);                                           \
  } while (0)
  _REG_MEM_REGION_LOGGER(mrom);
  _REG_MEM_REGION_LOGGER(flash);
  _REG_MEM_REGION_LOGGER(psram);
  _REG_MEM_REGION_LOGGER(sram);
  _REG_MEM_REGION_LOGGER(sdram);
}

void init_mem(void *img, const sim_config &cfg) {
  spdlog::info("copy img to ysyxSoC mrom for sim read");
  g_mem.flash.copy_from(img, cfg.img_size);
	_fill_rams_uninit(cfg.setting.zero_uninit_ram);
	_init_mem_logger();
  _init_dpi_logger(cfg.setting);
}

EXTERN_C void mrom_read(int32_t addr, int32_t *data) {
  g_mem.mrom.read_word(addr, (uint32_t &)(*data));
  DPI_TRACE("R addr={:08x} data={:08x}", addr, *data);
}

#define DEF_NOHIGH8_FORWARD_RD(region)                                         \
  EXTERN_C void region##_read(int32_t addr, int32_t *data) {                   \
    DPI_ASSERT((addr & 0xff000000) == 0,                                       \
               #region "_read addr={:08x} has non-zero high 8 bits", addr);    \
    addr += g_mem.region.base();                                               \
    g_mem.region.read_word(addr, (uint32_t &)(*data));                         \
    DPI_TRACE("R addr={:08x} data={:08x}", addr, *data);                       \
  }
// in spi
//   .addr({8'b0, in_paddr[23:2], 2'b0}),
// so the high 8 bits are ignored
// 0x3XXXXXXX -> 0x00XXXXXX
DEF_NOHIGH8_FORWARD_RD(flash)

// DEF_NOHIGH8_FORWARD_RD(psram)
EXTERN_C void psram_read(int32_t addr, int32_t *data) {
  // add back
  addr += g_mem.psram.base();
  g_mem.psram.read_word(addr, (uint32_t &)(*data));
  DPI_TRACE("R addr={:08x} data={:08x}", addr, *data);
}

extern "C" void psram_write(int32_t addr, char strb8, int32_t data, int32_t *) {
  // DPI_ASSERT((addr & 0xff000000) == 0,
  //            "psram_write addr={:08x} has non-zero high 8 bits", addr);
  // add back
  addr += g_mem.psram.base();
  g_mem.psram.write_word(addr, data, strb8);
  uint32_t newdata;
  g_mem.psram.read_word(addr, newdata);

  DPI_TRACE("W addr={:08x} data={:08x} (strb {:02x}) newdata={:08x}", addr,
            (uint32_t)data, (uint32_t)strb8, newdata);
}

extern "C" void sdram_read(char block, char bank, short row, short col,
                           short *data) {
  g_mem.sdram.read_half(bank, row, col, block, (uint16_t &)(*data));
  DPI_TRACE("R bank={:02x} row={:04x} col={:04x} block={} data={:04x}", bank,
            row, col, (uint32_t)block, (uint16_t)*data);
}
extern "C" void sdram_write(char block, char bank, short row, short col,
                            short data, char mask) {
  uint16_t new_data;
  g_mem.sdram.read_half(bank, row, col, block, new_data);

  // mask [0] = 0: write low byte
  // mask [1] = 0: write high byte
  if ((mask & 0x1) == 0) {
    new_data &= 0xff00;
    new_data |= (data & 0x00ff);
  }
  if ((mask & 0x2) == 0) {
    new_data &= 0x00ff;
    new_data |= (data & 0xff00);
  }

  g_mem.sdram.write_half(bank, row, col, block, new_data);

  char human_friendly_mask[3] = {'-', '-', '\0'};
  if ((mask & 0x1) == 0)
    human_friendly_mask[1] = 'L';
  if ((mask & 0x2) == 0)
    human_friendly_mask[0] = 'H';

  DPI_TRACE("W bank={:02x} row={:04x} col={:04x} block={} "
            "data={:04x} mask={} newdata={:04x}",
            bank, row, col, (uint32_t)block, (uint16_t)data,
            human_friendly_mask, new_data);
}

extern "C" void sram_upd(int addr, int data, char mask) {
  g_mem.sram.write_word(addr, data, mask);
}
#else

extern "C" void sram_upd(int addr, int data, char mask) {}

#endif
