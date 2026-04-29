#include <cstdint>
#include <system_error>
extern "C" {
#include <gdbstub.h>
}
#include <stdint.h>

#include "common.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>

#include "sim.hpp"
#include "memory/mem.hpp"

#define N_GPR 16

static std::shared_ptr<spdlog::logger> _logger =
    spdlog::stdout_color_mt("gdbstub");

static size_t _op_get_regbytes(int regno) { return 4; }

static int _op_read_reg(void *args, int regno, void *value) {
  if (regno < 0 || regno > N_GPR) {
    _logger->error("read reg invalid regno {}", regno);
    return (int)std::errc::invalid_argument;
  } else if (regno == N_GPR) {
    // pc
    uint32_t pc = sim_get_cpu_state()->pc;
    _logger->trace("read reg pc value {:08x}", pc);
    *(uint32_t *)value = pc;
    return 0;
  } else {
    uint32_t r = sim_get_cpu_state()->gpr[regno];
    // _logger->trace("read reg {} value {:08x}", regno, r);
    *(uint32_t *)value = r;
    return 0;
  }
}

static int _op_write_reg(void *args, int regno, void *value) {
  if (regno < 0 || regno > N_GPR) {
    _logger->error("write reg invalid regno {}", regno);
    return (int)std::errc::invalid_argument;
  } else if (regno == N_GPR) {
    // pc
    uint32_t pc = *(uint32_t *)value;
    _logger->trace("write reg pc value {:08x}", pc);
    sim_get_cpu_state()->pc = pc;
    return 0;
  } else {
    uint32_t r = *(uint32_t *)value;
    _logger->trace("write reg {} value {:08x}", regno, r);
    sim_get_cpu_state()->gpr[regno] = r;
    return 0;
  }
  return 0;
}

static int _op_read_mem(void *args, size_t addr, size_t len, void *val) {
  if (len == 0)
    return 0;

	_logger->trace("read mem addr {:08x} len {}", addr, len);

	if(len==1){
		uint32_t word;
		if(!read_guest_mem(addr & ~0x3, &word)){
			*(uint8_t*)val = 0;
			return (int)std::errc::address_family_not_supported;
		}
		*(uint8_t *)val = *((uint8_t *)(&word) + (addr & 0x3));
		_logger->warn("use unverified impl read byte at addr {:08x}", addr);
		_logger->trace("read mem addr {:08x} byte {:02x}", addr, *(uint8_t *)val);
		return 0;
	}

	if((addr & 0x1)==0 && len == 2){
		uint32_t word;
		if(!read_guest_mem(addr & ~0x3, &word)){
			*(uint16_t*)val = 0;
			return (int)std::errc::address_family_not_supported;
		}
		uint16_t half;

		*(uint16_t *)val = *((uint16_t *)(&word) + ((addr & 0x2) >> 1));
		_logger->warn("use unverified impl read halfword at addr {:08x}", addr);
		_logger->trace("read mem addr {:08x} half {:04x}", addr, half);
		return 0;
	}
	if(addr & 0x3){
		_logger->error("read unaligned addr not supported addr {:08x}", addr);
		return (int)std::errc::not_supported;
	}

	if(len == 4){
		uint32_t word;
		if(!read_guest_mem(addr, &word)){
			*(uint32_t*)val = 0;
			return (int)std::errc::address_family_not_supported;
		}
		*(uint32_t *)val = word;
		_logger->trace("read mem addr {:08x} word {:08x}", addr, word);
		return 0;
	}
	if((len & 0x3) == 0){
		size_t words = len / 4;
		uint32_t *dest = (uint32_t *)val;
		for(size_t i=0;i<words;i++){
			uint32_t word;
			if(!read_guest_mem(addr + i*4, &word)){
				dest[i] = 0;
				return (int)std::errc::address_family_not_supported;
			}
			dest[i] = word;
			// _logger->trace("read mem addr {:08x} word {:08x}", addr + i*4, word);
		}
		_logger->trace("read mem addr {:08x} len {} words {}", addr, len, words);
		return 0;
	}


	_logger->error("read len not supported addr {:08x} len {}", addr, len);

  return (int)std::errc::not_supported;
}

static int _op_write_mem(void *args, size_t addr, size_t len, void *val) {
  return (int)std::errc::not_supported;
}

static std::set<size_t> _breakpoints;

static bool _op_set_bp(void *args, size_t addr, bp_type_t type) {
  // _logger->info("set bp at addr {:08x}", addr);
  _breakpoints.insert(addr);
  _logger->debug("current breakpoints count {}", _breakpoints.size());
  return true;
}

static bool _op_del_bp(void *args, size_t addr, bp_type_t type) {
  // _logger->info("del bp at addr {:08x}", addr);
  _breakpoints.erase(addr);
  _logger->debug("current breakpoints count {}", _breakpoints.size());
  return true;
}

static bool _request_interrupt = false;
static volatile bool _request_int_ack = false;
static void _op_on_interrupt(void *args) {
	_request_interrupt = true;
	_request_int_ack = false;
	_logger->info("gdbstub on_interrupt called, interrupt requested");
	while(!_request_int_ack){
	}
	_request_interrupt = false;
	_logger->info("gdbstub on_interrupt acknowledged");
	// _logger->warn("gdbstub on_interrupt called, but not implemented");
}

static void _op_set_cpu(void *args, int cpuid) {}
static int _op_get_cpu(void *args) { return 0; }

static void _cb_on_halt(int a0) {
  _logger->info("sim halted callback called with a0={}", a0);
}

static gdb_action_t _op_cont(void *args) {
  _logger->trace("cont called");
  while (true) {
    uint32_t pc = sim_get_cpu_state()->pc;
    if (_breakpoints.count(pc)) {
      // _logger->info("hit breakpoint at pc {:08x}", pc);
      break;
    }
    sim_step_inst();
    if (sim_halted()) {
      _logger->info("sim halted at pc {:08x}", sim_get_cpu_state()->pc);
      return ACT_SHUTDOWN;
      break;
    }
		if(_request_interrupt){
			_logger->info("interrupt requested, stopping execution at pc {:08x}", sim_get_cpu_state()->pc);
			_request_int_ack = true;
			break;
		}
  }
  return ACT_RESUME;
}
static gdb_action_t _op_stepi(void *args) {
  _logger->info("stepi called");
  sim_step_inst();
  return ACT_RESUME;
}

static gdbstub_t gdbstub;

bool gdbop_init(const char *socket) {
  static struct target_ops ops = {
      .cont = _op_cont,
      .stepi = _op_stepi,
      .get_reg_bytes = _op_get_regbytes,
      .read_reg = _op_read_reg,
      .write_reg = _op_write_reg,
      .read_mem = _op_read_mem,
      .write_mem = _op_write_mem,
      .set_bp = _op_set_bp,
      .del_bp = _op_del_bp,
      .on_interrupt = _op_on_interrupt,
      .set_cpu = _op_set_cpu,
      .get_cpu = _op_get_cpu,
  };

  static arch_info_t arch = {
      .target_desc = (char *)TARGET_RV32,
      .smp = 1,
      .reg_num = N_GPR,
  };

  return gdbstub_init(&gdbstub, &ops, arch, (char *)socket);
}
bool gdbop_run() { return gdbstub_run(&gdbstub, nullptr); }
void gdbop_close() { gdbstub_close(&gdbstub); }

int gdb_mainloop() {
  spdlog::info("sim started in gdb debug mode");

  auto &cfg = *sim_get_config();
  cfg.raise_halt_cb = _cb_on_halt;

	_logger->set_level(spdlog::level::info);
	

  constexpr std::string_view gdb_socket = "127.0.0.1:1235";
  _logger->info("initializing gdbstub at {}", gdb_socket);
  _logger->info("this step will stuck until gdb connects");
  _logger->info("try use 'target remote {}' in gdb", gdb_socket);

  bool res = gdbop_init(gdb_socket.data());
  if (!res) {
    _logger->error("gdbop_init failed");
    return 1;
  }
  spdlog::info("gdbstub initialized, waiting for gdb commands");
  res = gdbop_run();
  if (!res) {
    _logger->error("gdbop_run failed");
    return 1;
  }
  gdbop_close();
  spdlog::info("session ended");
  return 0;
}
