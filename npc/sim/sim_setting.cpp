#include "sim.hpp"
#include <spdlog/spdlog.h>

static void _Get(bool &field, const char *env_p) {
  if (env_p != nullptr) {
    if (strcmp(env_p, "0") == 0 || strcasecmp(env_p, "false") == 0) {
      field = false;
    } else {
      field = true;
    }
  }
}
static void _Get(int &field, const char *env_p) {
	if (env_p != nullptr) {
		field = atoi(env_p);
	}
}
static void _Get(std::string &field, const char *env_p) {
  if (env_p != nullptr) {
    field = std::string(env_p);
  }
}

#define GET(v)                                                                 \
  do {                                                                         \
    const char *env_p = getenv(_STR(_CONCAT(VSIM_, v)));                       \
    _Get(setting.v, env_p);                                                    \
    log_msg += fmt::format("[{}] {:25}{}", setting.v ? '*' : ' ', #v,          \
                           msg_line_first ? ' ' : '\n');                       \
    msg_line_first = !msg_line_first;                                          \
  } while (0)

void load_sim_setting_from_env(sim_setting &setting) {
  std::string log_msg = "sim_setting: \n";
  bool msg_line_first = true;

	spdlog::info("loading sim_setting from env");

  GET(en_wave);
  GET(en_inst_trace);
  GET(showdisasm);
  GET(always_showdisasm);
	GET(gdb_mode);
  GET(no_batch);
  GET(ftrace);
  GET(iringbuf);
  GET(etrace);
  GET(difftest);
  GET(nvboard);
  GET(zero_uninit_ram);
  GET(trace_difftest_skip);
  GET(trace_pmem_readcall);
  GET(trace_pmem_writecall);
  GET(trace_inst_fetchcall);
  GET(trace_mmio_write);

#define GET_DPI_FLAG(name) GET(trace_dpi_##name);
  GET_DPI_FLAG(mrom_read);
  GET_DPI_FLAG(sdram_read);
  GET_DPI_FLAG(sdram_write);
  GET_DPI_FLAG(flash_read);
  GET_DPI_FLAG(psram_read);
  GET_DPI_FLAG(psram_write);

  spdlog::info("{}", log_msg);
}
