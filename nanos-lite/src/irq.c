
#include "do_syscall.h"
extern int mm_brk(uintptr_t brk);
extern Context *schedule(Context *prev);
static Context *do_event(Event e, Context *c)
{

	switch (e.event)
	{
	case EVENT_IRQ_TIMER:
	{
		return schedule(c); // Yield to the scheduler
	}
	case EVENT_YIELD:
	{
		CASE_LOG("Yield event triggered");
		int syscall_id = c->GPR1;
		switch (syscall_id)
		{
		case -1:
			return schedule(c); // If syscall_id is -1, just yield to the scheduler
		case SYS_exit:
			CASE_LOG("Exit syscall called with code %d", c->GPR2);
			halt(c->GPR2);
			sys_exit(c->GPR2);
			return c; // Terminate the process
		case SYS_yield:
			CASE_LOG("Yield syscall called");
			return schedule(c); // Yield to the scheduler
		case SYS_open:
			CASE_LOG("Open syscall called with path %s, flags %d, mode %d",
					 (char *)c->GPR2, c->GPR3, c->GPR4);
			c->GPRx = fs_open((const char *)c->GPR2, c->GPR3, c->GPR4);
			return c;
		case SYS_read:
			CASE_LOG("Read syscall called with fd %d, buf %p, len %d",
					 c->GPR2, (void *)c->GPR3, c->GPR4);
			c->GPRx = fs_read(c->GPR2, (void *)c->GPR3, c->GPR4);
			return c;
		case SYS_write:
			CASE_LOG("Write syscall called with fd %d, buf %p, len %d",
					 c->GPR2, (void *)c->GPR3, c->GPR4);
			c->GPRx = fs_write(c->GPR2, (const char *)c->GPR3, c->GPR4);
			return c;
		case SYS_kill:
			CASE_LOG("Kill syscall called with pid %d, sig %d",
					 c->GPR2, c->GPR3);
			c->GPRx = -1; // Simulate failure for now
			return c;
		case SYS_getpid:
			CASE_LOG("Getpid syscall called");
			c->GPRx = 1; // Simulate a PID of 1
			return c;
		case SYS_close:
			CASE_LOG("Close syscall called with fd %d", c->GPR2);
			c->GPRx = fs_close(c->GPR2);
			return c;
		case SYS_brk:
			CASE_LOG("Brk syscall called with new_end %u", c->GPR2);
			mm_brk(c->GPR2);
			c->GPRx = 0;
			return c;
		case SYS_lseek:
			CASE_LOG("Lseek syscall called with fd %d, offset %d, whence %d",
					 c->GPR2, c->GPR3, c->GPR4);
			c->GPRx = fs_lseek(c->GPR2, c->GPR3, c->GPR4);
			return c;
		case SYS_gettimeofday:
			CASE_LOG("Gettimeofday syscall called");
			c->GPRx = sys_gettimeofday((struct timeval *)c->GPR2, (struct timezone *)c->GPR3);
			return c;
		case SYS_execve:
			CASE_LOG("Execve syscall called with filename %s, argv %p, envp %p",
					 (char *)c->GPR2, (char **)c->GPR3, (char **)c->GPR4);
			c->GPRx = sys_execve((const char *)c->GPR2, (char *const *)c->GPR3, (char *const *)c->GPR4);
			return c; // This should not return
		default:
			CASE_LOG("Unhandled syscall ID %d", syscall_id);
			c->GPRx = -1; // Simulate failure for unhandled syscalls
			return c;
		}

	default:
		panic("Unhandled event ID = %d", e.event);
	}

		return c;
	}
}

void init_irq(void)
{
	Log("Initializing interrupt/exception handler...");
	cte_init(do_event);
}
