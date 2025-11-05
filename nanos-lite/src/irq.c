#include <common.h>

Context* schedule(Context *prev);
void do_syscall(Context *c);
static Context* do_event(Event e, Context* c) {
  // printf("do_event\n");
  switch (e.event) {
    case EVENT_YIELD: Log("Event: yield"); break;
    case EVENT_SYSCALL: 
      do_syscall(c); break;
    default: panic("Unhandled event ID = %d", e.event);
  }
  return c;
}

void init_irq(void) {
  Log("Initializing interrupt/exception handler...");
  cte_init(do_event);
}
