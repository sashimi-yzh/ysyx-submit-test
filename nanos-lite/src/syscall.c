#include <common.h>
#include <fs.h>
#include <sys/time.h>
#include "syscall.h"
#include "proc.h"

const char *fs_get_filename(int fd);
void naive_uload(PCB *pcb, const char *filename);
int mm_brk(uintptr_t brk);

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

  struct timeval *tv;

  switch (a[0]) {
    case SYS_exit:
      Log("[STRACE] exit %u", a[1]);
      halt(a[1]);
    break;
    case SYS_yield:
      // Log("[STRACE] yield");
      yield();
      c->GPRx = 0;
    break;
    case SYS_open:
      // Log("[STRACE] open %s %u %u", (const char *)a[1], a[2], a[3]);
      c->GPRx = fs_open((const char *)a[1], a[2], a[3]);
    break;
    case SYS_read:
      // Log("[STRACE] read %s %p %u", fs_get_filename(a[1]), a[2], a[3]);
      c->GPRx = fs_read(a[1], (void *)a[2], a[3]);
    break;
    case SYS_write:
      // Log("[STRACE] write %s %p %u", fs_get_filename(a[1]), a[2], a[3]);
      c->GPRx = fs_write(a[1], (const void *)a[2], a[3]);
    break;
    case SYS_close:
      // Log("[STRACE] close %s", fs_get_filename(a[1]));
      c->GPRx = fs_close(a[1]);
    break;
    case SYS_lseek:
      // Log("[STRACE] lseek %s %u %u", fs_get_filename(a[1]), a[2], a[3]);
      c->GPRx = fs_lseek(a[1], a[2], a[3]);
    break;
    case SYS_brk:
      // Log("[STRACE] brk %p", a[1]);
      c->GPRx = mm_brk(a[1]);
    break;
    case SYS_execve:
      Log("[STRACE] execve %s %p %p", a[1], a[2], a[3]);
      if (fs_open((char *)a[1], 0, 0) == -1) {
        c->GPRx = -2;
      } else {
        context_uload(current, (char *)a[1], (char *const *)a[2], (char *const *)a[3]);
        switch_boot_pcb();
        yield();
      }
    break;
    case SYS_gettimeofday:
      // Log("[STRACE] gettimeofday %p %p", a[1], a[2]);
      tv = (void *)a[1];
      if (tv) {
        AM_TIMER_UPTIME_T uptime;
        ioe_read(AM_TIMER_UPTIME, &uptime);
        tv->tv_sec = uptime.us / 1000000;
        tv->tv_usec = uptime.us % 1000000;
      }
      c->GPRx = 0;
    break;
    default: panic("Unhandled syscall ID = %d", a[0]);
  }
}
