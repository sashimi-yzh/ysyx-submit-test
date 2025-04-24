#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
#ifndef __ICS_EXPORT
      case 11:
        ev.event = (c->GPR1 == -1) ? EVENT_YIELD : EVENT_SYSCALL;
        c->mepc += 4;
        break;
#endif
      default: ev.event = EVENT_ERROR; break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
#ifdef __ICS_EXPORT
  return NULL;
#else
  Context *c = (Context*)kstack.end - 1;
  c->pdir = NULL;
  c->mepc = (uintptr_t)entry;
  c->GPR2 = (uintptr_t)arg;
  c->mstatus = (MODE_M << 11);
  c->gpr[2] = (uintptr_t)(c + 1); // sp
  c->np = 0;
  return c;
#endif
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
