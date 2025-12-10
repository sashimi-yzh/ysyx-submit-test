#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  c->mepc += 4;
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 11: ev.event = EVENT_YIELD; break;
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
  uint16_t diff_mstatus = 0x1800;
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  asm volatile("csrw mstatus, %0" : : "r"(diff_mstatus));
  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context *ktx = (Context *)(kstack.end - sizeof(Context));
  ktx->gpr[10] = (uintptr_t)arg;
  ktx->mepc = (uintptr_t)entry;
  ktx->mstatus = 0x1800;
  return ktx;
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
