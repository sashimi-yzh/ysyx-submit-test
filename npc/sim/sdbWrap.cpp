#include "elf_tool.hpp"
#include "memory/mem.hpp"
#include "memory/socmem.hpp"
#include "sim.hpp"
#include "spdlog/spdlog.h"
#include "tracers.hpp"
#include <sdb.hpp>

#include "common.hpp"

#include "sprobe.hpp"

#include "sdbWrap.hpp"

SProbe sprobe;
cycle_end_callback_t _old_cycle_callback = nullptr;

void cyc_callback() {
  if (sim_halted())
    return;
  sprobe.dump_watched();
  if (_old_cycle_callback)
    _old_cycle_callback();
}

std::shared_ptr<sdb::debuger> dbg;
sdb::difftest_trace_handler_ptr diff_handler;

void sdb_skip_difftest_ref() {
  if (diff_handler)
    diff_handler->skip_ref();
}

void sdb_memcpy_to_ref(uint32_t addr, std::span<uint8_t> data) {
  if (diff_handler)
    diff_handler->memcpy_to_ref(data, addr);
}

void sdb_exec(std::string_view cmd, bool *quit) {
  dbg->exec_command(cmd);
  if (dbg->state().state == sdb::run_state::quit) {
    if (quit)
      *quit = true;
  }
}

bool sdb_is_hitbadtrap() { return dbg->state().is_badexit(); }

void sdb_set_halt(int a0) { dbg->state().halt(a0); }
void sdb_dump_recent_info() { dbg->dump_all(); }

namespace sdbwrap {
sdb::paddr_t cpu_exec(size_t n) {
  while (n-- > 0) {
    sim_step_inst();
    if (sim_halted())
      break;
  }
  return sim_get_cpu_state()->pc;
}
void shot_regsnap(sdb::reg_snapshot_t &regsnap) {
  for (size_t i = 0; i < 32; i++) {
    regsnap[i] = sim_get_cpu_state()->gpr[i];
  }
}
sdb::vlen_inst_code inst_fetcher(sdb::paddr_t pc) {
  sdb::word_t inst;
  read_guest_mem(pc, &inst);
  uint8_t *p = (uint8_t *)&inst;
  return sdb::vlen_inst_code(p, p + 4);
}
uint8_t *loadmem(sdb::paddr_t addr, size_t nbyte) {
  return mem_guest_to_host(addr);
}
} // namespace sdbwrap
using namespace sdb;
std::array<std::string_view, 32> reg_names = {
    "$0", "ra", "sp", "gp", "tp",  "t0",  "t1", "t2", "s0", "s1", "a0",
    "a1", "a2", "a3", "a4", "a5",  "a6",  "a7", "s2", "s3", "s4", "s5",
    "s6", "s7", "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};
// void dump_regs() {
//   for (int i = 0; i < 32; i++) {
//     printf("%s: %08x\n", reg_names[i].data(), gpr_snap[i]);
//   }
// }
void sdb_init(word_t init_pc, size_t img_size, const char *img_file,
              sim_setting setting) {
  dbg = std::make_shared<sdb::debuger>(
      init_pc, init_pc, img_size, sdbwrap::cpu_exec, sdbwrap::loadmem,
      sdbwrap::shot_regsnap,
      std::vector<std::string_view>(reg_names.begin(), reg_names.end()),
      sdbwrap::inst_fetcher);

  dbg->enable_inst_trace = setting.en_inst_trace;

  if (setting.en_inst_trace) {
    if (setting.showdisasm) {
      size_t inst_show_limit = setting.always_showdisasm ? SIZE_MAX : 16;
      dbg->add_trace(sdb::make_disasm_trace_handler(sdb::default_inst_disasm,
                                                    inst_show_limit));
    }
    if (setting.etrace)
      dbg->add_trace(sdb::make_etrace_handler());
    if (setting.iringbuf > 0) {
      dbg->add_trace(sdb::make_iringbuf_trace_handler(sdb::default_inst_disasm,
                                                      setting.iringbuf));
    }

    if (img_file && setting.ftrace) {
      auto elf_file = try_find_elf_file_of(img_file);

      if (!elf_file.empty()) {
        // printf("Found ELF file: %s\n", elf_file.c_str());
        spdlog::info("Found ELF file {}", elf_file);
        dbg->add_trace(sdb::make_ftrace_handler(elf_file));
      }
    }

    if (setting.difftest) {
      try {
        diff_handler = sdb::make_difftest_trace_handler(
            "../nemu/build/riscv32-nemu-interpreter-so", 0);
      } catch (std::exception &e) {
        spdlog::warn("Failed to create difftest trace handler: {}, difftest "
                     "will be disabled",
                     e.what());
        return;
      }
      dbg->add_trace(diff_handler);

      auto mr = get_mem_regions_need_init_difftest();
      for (auto &r : mr) {
        spdlog::info("Initializing difftest ref mem region '{}' at host addr "
                     "{:08x} with size {} bytes",
                     r.name, r.host_base, r.size);
        diff_handler->memcpy_to_ref({(uint8_t *)r.data, r.size}, r.host_base);
      }
    }

    dbg->add_trace(sdb::make_self_loop_trace_handler(
        []() { return jyd_is_good_trap() ? 0 : 1; }));
  }
}

int sdb_mainloop() {
  spdlog::info("sim started in sdb debug mode");

  auto &cfg = *sim_get_config();
  cfg.raise_halt_cb = sdb_set_halt;
  spdlog::trace("setting raise_halt_cb to sdb_set_halt");

  sdb_init(cfg.init_pc, cfg.img_size, cfg.img_file_path, cfg.setting);
  spdlog::info("sdb entering {} mode",
               cfg.is_batch_mode() ? "batch" : "interactive");

  if (cfg.is_batch_mode()) {
    sdb_exec("c", nullptr);
    return sdb_is_hitbadtrap() ? 1 : 0;
  }

  std::string top_vpi_name =
      std::string("TOP.") + std::string(_STR(TOP_NAME)).substr(1);
  // sprobe.add_watch(top_vpi_name + ".asic.cpu.cpu.io_master_araddr");
  _old_cycle_callback = cfg.setting.cycle_finish_cb;
  cfg.setting.cycle_finish_cb = cyc_callback;

  std::string cmd;
  bool quit = false;
  while (!sim_halted() && !quit) {
    std::cout << "(sdb) ";
    std::getline(std::cin, cmd);
    if (cmd == "sc") {
      sim_step_cycle();
      continue;
    }
    if (cmd.size() > 3 && cmd.substr(0, 2) == "ps") {
      std::string sig_name = cmd.substr(3);
      if (sig_name == "*") {
        sprobe.add_watch(top_vpi_name);
        continue;
      }
      if (sig_name.starts_with("`c.")) {
        sig_name = "asic.cpu.cpu." + sig_name.substr(3);
      }

      auto fullname = top_vpi_name + '.' + sig_name;
      if (sprobe.add_watch(fullname))
        printf("Added watch for '%s'\n", fullname.c_str());
      continue;
    }
    sdb_exec(cmd, &quit);
  }

  return sdb_is_hitbadtrap() ? 1 : 0;
}
