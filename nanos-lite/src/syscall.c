#include <common.h>
#include "syscall.h"
#include <sys/time.h>
#include <fs.h>

#ifdef STRACE
const char *syscalls[] = {"SYS_exit", "SYS_yield", "SYS_open",
"SYS_read", "SYS_write", "SYS_kill", "SYS_getpid", "SYS_close", 
"SYS_lseek", "SYS_brk", "SYS_fstat", "SYS_time", "SYS_signal", 
"SYS_execve", "SYS_fork", "SYS_link", "SYS_unlink", "SYS_wait",
"SYS_times", "SYS_gettimeofday"};
#endif 


long sys_write(int fd, const void *buf, size_t len);
long sys_read(int fd, void *buf, size_t len);
long sys_lseek(int fd, size_t offset, int whence);
long sys_close(int fd);
long sys_open(const char *pathname, int flags, int mode);

time_t sys_time(struct timeval *t){ 
  time_t time = io_read(AM_TIMER_UPTIME).us;
  t->tv_sec  = time/1000000;
  t->tv_usec = time%1000000;
  return time;
};
int mm_brk(uintptr_t brk);
// void fs_strace(const char* sys_call, int a1, int a2, int a3);
// const char *fs_get_file_name(int fd);


void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

#ifdef STRACE
if(a[0] == SYS_write || a[0] == SYS_read || a[0] == SYS_lseek || a[0] == SYS_close){
  Log("SYSCALL(%s, %s, 0x%x, 0x%x) ", syscalls[a[0]], fs_get_file_name(a[1]), a[2], a[3]);
  //fs_strace(syscalls[a[0]], a[1], a[2], a[3]);
}
else{
  Log("SYSCALL(%s, 0x%x, 0x%x, 0x%x) ", syscalls[a[0]], a[1], a[2], a[3]);
}
#endif 


  switch (a[0]) {
    case SYS_exit:  Log("SYSCALL(SYS_exit, %d)\n",a[1]);halt(a[1]); break;
    case SYS_yield: yield(); c->GPRx = 0; break;
    case SYS_time:  c->GPRx = sys_time((struct timeval *)a[1]);  break;
    case SYS_brk:   c->GPRx = mm_brk(a[1]); break;
    case SYS_write: c->GPRx = sys_write(a[1], (void *)a[2], a[3]); break;
    case SYS_read:  c->GPRx = sys_read(a[1], (void *)a[2], a[3]); break;
    case SYS_lseek: c->GPRx = sys_lseek(a[1], a[2], a[3]); break;
    case SYS_close: c->GPRx = sys_close(a[1]); break;
    case SYS_open : c->GPRx = sys_open((const char *)a[1], a[2], a[3]); break;
    default: panic("Unhandled syscall ID = %d", a[0]);
  }

#ifdef STRACE
if(a[0] == SYS_write || a[0] == SYS_read || a[0] == SYS_lseek || a[0] == SYS_close){
  Log("SYSCALL_end(%s, %s, 0x%x, 0x%x) = %d", syscalls[a[0]], fs_get_file_name(a[1]), a[2], a[3], c->GPRx);
  //fs_strace(syscalls[a[0]], a[1], a[2], a[3]);
}
else{
  Log("SYSCALL_end(%s, 0x%x, 0x%x, 0x%x) = %d", syscalls[a[0]], a[1], a[2], a[3], c->GPRx);
}
#endif 

}
