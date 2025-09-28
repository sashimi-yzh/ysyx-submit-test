#include <proc.h>

#define MAX_NR_PROC 4

static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
static PCB pcb_boot = {};
PCB *current = NULL;

void switch_boot_pcb() {
  current = &pcb_boot;
}

void hello_fun(void *arg) {
  int j = 1;
  while (1) {
    Log("Hello World from Nanos-lite with arg '%p' for the %dth time!", (uintptr_t)arg, j);
    j ++;
    yield();
  }
}

void context_kload(PCB *pcb, void (*entry)(void *), void *arg) {
  Area stack = { .start = pcb->stack, .end = pcb->stack + STACK_SIZE };
  Context *ctx = kcontext(stack, entry, arg);
  pcb->cp = ctx;
}

void init_proc() {
  switch_boot_pcb();

  Log("Initializing processes...");
  
  // context_kload(&pcb[0], hello_fun, (void *)1);

  // void naive_uload(PCB *pcb, const char *filename);
  // naive_uload(NULL, "/bin/dummy");

  // char *const argv[] = { "/bin/nterm", NULL };
  // char *const envp[] = { "KEY=VALUE", NULL };

  char *const empty[] = { NULL };
  context_uload(&pcb[0], "/bin/hello", empty, empty);
  context_uload(&pcb[1], "/bin/pal", empty, empty);
  context_uload(&pcb[2], "/bin/bird", empty, empty);
  context_uload(&pcb[3], "/bin/nslider", empty, empty);

}

int current_process_sw = 1;

Context* schedule(Context *prev) {
  current->cp = prev;

  static int cnt = 0;
  if (current == &pcb[0]) { // hello
    current = &pcb[current_process_sw];
  } else { // pal
    if (cnt == 10) {
      current = &pcb[0];
      cnt = 0;
    } else {
      current = &pcb[current_process_sw];
      ++cnt;
    }
  }

  return current->cp;
}
