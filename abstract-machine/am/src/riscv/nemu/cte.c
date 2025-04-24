#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
#ifndef __ICS_EXPORT
  void __am_get_cur_as(Context *c);
  void __am_switch(Context *c);
  static int np = 0; // 0 = KERNEL, 1 = USER

  __am_get_cur_as(c);
  c->np = np;

#endif
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
#ifndef __ICS_EXPORT
#define INTR_BIT (1ul << (__riscv_xlen - 1))
      case INTR_BIT | 0x7: ev.event = EVENT_IRQ_TIMER; break;
      case 8: case 11:
        ev.event = (c->GPR1 == -1) ? EVENT_YIELD : EVENT_SYSCALL;
        c->mepc += 4;
        break;
#endif
      default: ev.event = EVENT_ERROR; break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }
#ifndef __ICS_EXPORT
  if (c->np == 1) {
    // return to user
    asm volatile("csrw mscratch, %0" : : "r"(c + 1));
    __am_switch(c);
  }
  np = c->np;
#endif

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

#ifndef __ICS_EXPORT
  asm volatile("csrw mscratch, zero");

#endif
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
  c->mstatus = MSTATUS_SXL | MSTATUS_UXL | (MODE_M << 11);
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
