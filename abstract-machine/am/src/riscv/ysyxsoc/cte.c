#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

static void __am_kcontext_start(void *entry, void *arg) {
  ((void (*)(void *))entry)(arg);
  halt(1);
}

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 11:
        c->mepc += 4;
        ev.event = (c->GPR1 == (uintptr_t)-1) ? EVENT_YIELD : EVENT_SYSCALL;
        break;
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
  Context *c = (Context *)kstack.end - 1;
  assert(kstack.start <= (void *)c && (void *)c < kstack.end);
  *c = (Context) {0};
  c->mepc = (uintptr_t)__am_kcontext_start;
  c->mstatus = 0x1800;
  c->gpr[10] = (uintptr_t)entry; // a0: __am_kcontext_start(entry, arg)
  c->gpr[11] = (uintptr_t)arg;   // a1
  c->pdir = NULL;
  return c;
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
