#ifndef DO_SYSCALL_H__
#define DO_SYSCALL_H__
#include <common.h>
#include <sys/time.h>
#include <proc.h>
// #define STRACE
#include "strace.h"
#ifndef size_t
#define size_t unsigned int
#endif
#ifndef mode_t
#define mode_t unsigned int
#endif
#ifndef uintptr_t
#define uintptr_t unsigned int
#endif
static char *const null_argv[] = {NULL};
static char *const null_envp[] = {NULL};
extern void switch_boot_pcb();
extern int fs_open(const char *pathname, int flags, mode_t mode);
extern size_t fs_read(int fd, void *buf, size_t len);
extern int fs_close(int fd);
extern size_t fs_write(int fd, const char *buf, size_t len);
extern size_t fs_lseek(int fd, size_t offset, int whence);
enum
{
	SYS_exit,
	SYS_yield,
	SYS_open,
	SYS_read,
	SYS_write,
	SYS_kill,
	SYS_getpid,
	SYS_close,
	SYS_lseek,
	SYS_brk,
	SYS_fstat,
	SYS_time,
	SYS_signal,
	SYS_execve,
	SYS_fork,
	SYS_link,
	SYS_unlink,
	SYS_wait,
	SYS_times,
	SYS_gettimeofday
};
extern void naive_uload(PCB *pcb, const char *filename);
extern void context_uload(PCB *pcb, char *filename, const char *argv[], const char *envp[]);
extern size_t sys_gettimeofday(struct timeval *tv, struct timezone *tz)
{
	uint64_t t0 = io_read(AM_TIMER_UPTIME).us;
	if (tv)
	{
		tv->tv_sec = t0 / 1000000;
		tv->tv_usec = t0 % 1000000;
	}
	if (tz)
	{
		panic("Timezone not supported in Nanos-lite");
	}
	return 0;
}
int sys_execve(const char *filename, char *const argv[], char *const envp[])
{
	CASE_LOG("sys_execve: filename = %s, argv = %p, envp = %p", filename, argv, envp);
	PCB *pcb = current;
	assert(pcb);
	int res = fs_open(filename, 0, 0);
	if (res < 0)
	{
		return -2;
	}
	fs_close(res); // Close the file descriptor after checking
	context_uload(pcb, (char *)filename, (const char **)argv, (const char **)envp);

	switch_boot_pcb(); // Switch to the boot PCB
	yield();		   // Yield to the scheduler after loading the new program
	panic("should not reach here after sys_execve");
	return -1;
}
int sys_exit(int status)
{
	CASE_LOG("sys_exit: status = %d", status);
	sys_execve("/bin/nterm", null_argv, null_envp);
	panic("should not reach here after sys_exit");
	return -1; // This should never be reached
}
#endif