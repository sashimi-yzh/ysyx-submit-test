#include <am.h>
#include <klib.h>
#include <riscv/riscv.h>
#include <stdio.h>

static Context *(*user_handler)(Event, Context *) = NULL;

Context *__am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
    case 11:
      ev.event = EVENT_YIELD;
      // printf("__am_irq_handle %d\n", c->mepc);
      // c->mepc += 4;
      // printf("__am_irq_handle %d\n", c->mepc);
      break;
    default:
      ev.event = EVENT_ERROR;
      break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context *(*handler)(Event, Context *)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context *cp = (Context *)(kstack.end - sizeof(Context));
  cp->mepc = (uintptr_t)entry;
  cp->mstatus = 0x1800;
  cp->gpr[2] = (uintptr_t)kstack.end;
  cp->gpr[10] = (uintptr_t)arg;
  return cp;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, 11; ecall");
#else
  asm volatile("li a7, 11; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
