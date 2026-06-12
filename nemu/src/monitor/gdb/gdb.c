#include "breakpoint.h"
#include <cpu/cpu.h>
#include <errno.h>
#include <gdbstub.h>
#include <isa.h>
#include <macro.h>
#include <memory/paddr.h>

extern bool g_cpu_stop_flag;

gdb_action_t emu_cont(void *args) {
  cpu_exec(-1);
  if (nemu_state.state == NEMU_STOP || nemu_state.state == NEMU_ABORT) {
    return ACT_RESUME;
  } else {
    return ACT_SHUTDOWN;
  }
}

gdb_action_t emu_stepi(void *args) {
  cpu_exec(1);
  if (nemu_state.state == NEMU_STOP || nemu_state.state == NEMU_ABORT) {
    return ACT_RESUME;
  } else {
    return ACT_SHUTDOWN;
  }
}

size_t emu_get_reg_bytes(int regno) {
  size_t len;
  return isa_try_find_reg(regno, NULL, &len) ? len : 0;
}

int emu_read_reg(void *args, int regno, void *value) {
  return isa_try_read_reg(regno, value) ? 0 : EINVAL;
}

int emu_write_reg(void *args, int regno, void *value) {
  return isa_try_write_reg(regno, value) ? 0 : EINVAL;
}

int emu_read_mem(void *args, size_t addr, size_t len, void *val) {
  if (try_paddr_read(addr, len, val)) {
    return 0;
  } else {
    return EFAULT;
  }
}

int emu_write_mem(void *args, size_t addr, size_t len, void *val) {
  if (try_paddr_write(addr, len, val)) {
    return 0;
  } else {
    return EFAULT;
  }
}

bool emu_set_bp(void *args, size_t addr, bp_type_t type) {
  if (type != BP_SOFTWARE) {
    return false;
  }
  return new_bp(addr);
}

bool emu_del_bp(void *args, size_t addr, bp_type_t type) {
  if (type != BP_SOFTWARE) {
    return true;
  }
  free_bp(addr);
  return true;
};

void emu_on_interrupt(void *args) { g_cpu_stop_flag = true; }

static struct target_ops emu_ops = {
    .get_reg_bytes = emu_get_reg_bytes,
    .read_reg = emu_read_reg,
    .write_reg = emu_write_reg,
    .read_mem = emu_read_mem,
    .write_mem = emu_write_mem,
    .cont = emu_cont,
    .stepi = emu_stepi,
    .set_bp = emu_set_bp,
    .del_bp = emu_del_bp,
    .on_interrupt = emu_on_interrupt,
};

static gdbstub_t gdbstub;

void init_gdb(char *gdb_socket) {
  init_bp_pool();
  Assert(gdbstub_init(&gdbstub, &emu_ops, arch_info, 
        gdb_socket ? gdb_socket : "127.0.0.1:1234"),
         "Fail to create socket.");
}

int gdb_mainloop(void) {
  Assert(gdbstub_run(&gdbstub, NULL), "Fail to run in debug mode.");
  gdbstub_close(&gdbstub);
  return 0;
}
