#include "proc.h"
#include <common.h>

static Context *do_event(Event e, Context *c) {
  switch (e.event) {
  case EVENT_YIELD:
    c = schedule(c);
    break;
  case EVENT_SYSCALL:
    if (do_syscall(c)) {
      c = schedule(c);
    }
    break;
  case EVENT_IRQ_TIMER:
    Log("get EVENT_IRQ_TIMER");
    c = schedule(c);
    break;
  default:
    panic("Unhandled event ID = %d", e.event);
  }

  return c;
}

extern void __am_asm_nanos_trap(void);

void init_irq(void) {
  Log("Initializing interrupt/exception handler...");
  cte_init(do_event);
#ifdef HAS_VME
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_nanos_trap));
#endif
}
