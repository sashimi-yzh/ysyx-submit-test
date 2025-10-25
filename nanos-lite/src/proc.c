#include <proc.h>
extern int fg_pcb; // current foreground process index
#define MAX_NR_PROC 4
static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
static const char *argv[] = {
	"/bin/exec-test",
	NULL};
static const char *envp[] = {
	NULL};
static PCB pcb_boot = {};
PCB *current = NULL;
extern void naive_uload(PCB *pcb, const char *filename);
extern void context_kload(PCB *pcb, void (*entry)(void *), void *arg);
extern void context_uload(PCB *pcb, char *filename, const char *argv[], const char *envp[]);
void switch_boot_pcb()
{
	current = &pcb_boot;
}

void hello_fun(void *arg)
{
	int j = 1;
	while (1)
	{
		if (j % 100 == 0)
			printf("Hello, %s! %d\n", (char *)arg, j);
		j++;
		yield();
	}
}

void init_proc()
{

	context_uload(&pcb[0], "/bin/nterm", argv, envp);
	context_uload(&pcb[1], "/bin/bird", argv, envp);
	context_uload(&pcb[2], "/bin/pal", argv, envp);
	context_uload(&pcb[3], "/bin/hello", argv, envp);
	switch_boot_pcb();
	printf("Boot process initialized.\n");
	yield();

	Log("Initializing processes...");
	panic("testing context switch,so should not reach here!");
	// load program here
	naive_uload(NULL, "/bin/bmp-test");
}

Context *schedule(Context *prev)
{

	current->cp = prev;
	current = (current == &pcb[3] ? &pcb[fg_pcb] : &pcb[3]);
	return current->cp;
}
