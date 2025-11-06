#include <common.h>
#include "syscall.h"
#include "fs.h"

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0]          = c->GPR1;
  a[1]          = c->GPR2;
  a[2]          = c->GPR3;
  a[3]          = c->GPR4;
  // printf("%d\n",a[0]);
  switch (a[0]) {
    case SYS_exit:
      Log("sys_exit( %d(status) )", a[1]);
      halt(0);
      break;
    case SYS_yield:
      #ifdef CONFIG_STRACE
      Log("sys_yield");
      #endif
      c->GPRx = 0;
      yield();
      break;
    case SYS_write:
      #ifdef CONFIG_STRACE
      Log("[sys_wirte] fd:%d",a[1]);
      #endif
      c->GPRx = fs_write(a[1],(void *)a[2],a[3]);
      break;
    default: panic("Unhandled syscall ID = %d", a[0]);
  }
}
