#include <common.h>
#include <sys/time.h>
#include "syscall.h"

int fs_open(const char *pathname, int flags, int mode);
size_t fs_read(int fd, void *buf, size_t len);
size_t fs_write(int fd, const void *buf, size_t len);
size_t fs_lseek(int fd, size_t offset, int whence);
int fs_close(int fd);



void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

  switch (a[0]) {
    case SYS_exit:
    #ifdef CONFIG_STRACE
      printf(" SYS_exit  :  a[1] = %x, a[2] = %x, a[3] = %x\n", a[1], a[2], a[3] );
    #endif
      halt(c->GPR1);
    break;
    case SYS_yield:
    #ifdef CONFIG_STRACE
      printf(" SYS_yield  :  a[1] = %x, a[2] = %x, a[3] = %x\n", a[1], a[2], a[3] );
    #endif
      yield();
      c->GPRx = 0;
    break;
    case SYS_open:
    #ifdef CONFIG_STRACE
      printf(" SYS_open  :  a[1] = %x, a[2] = %x, a[3] = %x\n", a[1], a[2], a[3] );
    #endif
      c->GPRx = fs_open((char *)a[1], (int)a[2], (int)a[3]);
    break;
    case SYS_close:
    #ifdef CONFIG_STRACE
      printf(" SYS_close  :  a[1] = %x, a[2] = %x, a[3] = %x\n", a[1], a[2], a[3] );
    #endif
      c->GPRx = fs_close((int)a[1]);break;
    case SYS_lseek:
    #ifdef CONFIG_STRACE
      printf(" SYS_lseek  :   a[1] = %x, a[2] = %x, a[3] = %x\n", a[1], a[2], a[3] );
    #endif
      c->GPRx = fs_lseek((int)a[1], (size_t)a[2], (int)a[3]);
    break;
    case SYS_read:
    #ifdef CONFIG_STRACE
      printf(" SYS_read  :   a[1] = %x, a[2] = %x, a[3] = %x\n", a[1], a[2], a[3] );
    #endif
      c->GPRx = fs_read((int)a[1], (void *)a[2], (size_t)a[3]);
    break;
    case SYS_write:
    #ifdef CONFIG_STRACE
      printf(" SYS_write  :   a[1] = %x, a[2] = %x, a[3] = %x\n", a[1], a[2], a[3] );
    #endif
      c->GPRx = fs_write((int)a[1], (void *)a[2], (size_t)a[3]);
    break;
    case SYS_brk :
    #ifdef CONFIG_STRACE
      printf(" SYS_brk  :   a[1] = %x, a[2] = %x, a[3] = %x\n", a[1], a[2], a[3] );
    #endif
      c->GPRx = 0;
    break;
    case SYS_gettimeofday:
    #ifdef CONFIG_STRACE
      printf(" SYS_gettimeofday  :   a[1] = %x, a[2] = %x, a[3] = %x\n", a[1], a[2], a[3] );
    #endif
      ((struct timeval *)a[1])->tv_sec = io_read(AM_TIMER_UPTIME).us / 1000000;
      ((struct timeval *)a[1])->tv_usec = io_read(AM_TIMER_UPTIME).us % 1000000;
      c->GPRx = 0;
    break;
    default: panic("Unhandled syscall ID = %d", a[0]);
  }
}
