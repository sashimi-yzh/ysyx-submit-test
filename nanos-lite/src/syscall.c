#include "syscall.h"
#include "am.h"
#include "fs.h"
#include "proc.h"
#include <common.h>

static char *sys_table[20] = {
    [SYS_exit] = "sys_exit",
    [SYS_yield] = "sys_yield",
    [SYS_open] = "sys_open",
    [SYS_read] = "sys_read",
    [SYS_write] = "sys_write",
    [SYS_close] = "sys_close",
    [SYS_lseek] = "sys_lseek",
    [SYS_execve] = "sys_execve",
    [SYS_gettimeofday] = "sys_gettimeofday",
    [SYS_brk] = "sys_brk",
};

static bool strace_on = false;

static const char *syscall_name(uintptr_t id) {
  if (id < LENGTH(sys_table) && sys_table[id] != NULL) {
    return sys_table[id];
  }
  return "unknown";
}

bool do_syscall(Context *c) {
  uintptr_t a[4];
  bool need_schedule = false;
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

  if (strace_on) {
    Log("[strace] syscall %s(%d), a0=%p, a1=%p, a2=%p, mepc=%p",
        syscall_name(a[0]), (int)a[0], (void *)a[1], (void *)a[2], (void *)a[3],
        (void *)c->mepc);
  }

  switch (a[0]) {
  case SYS_exit:
    halt(c->GPR2);

  case SYS_yield:
    c->GPRx = 0;
    need_schedule = true;
    break;

  case SYS_write: {
    size_t res = fs_write(a[1], (void *)a[2], a[3]);
    c->GPRx = res;
    break;
  }

  case SYS_read: {
    size_t res = fs_read(a[1], (void *)a[2], a[3]);
    c->GPRx = res;
    break;
  }

  case SYS_lseek:
    c->GPRx = fs_lseek(a[1], a[2], a[3]);
    break;

  case SYS_close:
    c->GPRx = fs_close(a[1]);
    break;

  case SYS_open:
    c->GPRx = fs_open((const char *)a[1], a[2], a[3]);
    break;

  case SYS_gettimeofday:
    c->GPRx = get_time((struct timeval *)a[1], (struct timezone *)a[2]);
    break;

  case SYS_execve: {
    Context *new_context =
        syscall_execve((const char *)a[1], (char **)a[2], (char **)a[3]);
    if (new_context != NULL) {
      sched_set_override(new_context);
      need_schedule = true;
      break;
    }
    c->GPRx = -2;
    break;
  }

  case SYS_brk:
    c->GPRx = mm_brk(a[1]);
    break;

  default:
    panic("Unhandled syscall ID = %d", a[0]);
  }

  return need_schedule;
}
