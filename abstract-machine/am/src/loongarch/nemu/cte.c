#include <am.h>
#include <loongarch/loongarch32r.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
#ifndef __ICS_EXPORT
  void __am_get_cur_as(Context *c);
  void __am_switch(Context *c);
  void __am_tlb_refill(void);

  __am_get_cur_as(c);
#endif
  if (user_handler) {
    Event ev = {0};
#ifdef __ICS_EXPORT
    uintptr_t ecode = 0;
    switch (ecode) {
      default: ev.event = EVENT_ERROR; break;
    }
#else
    uintptr_t ecode = (c->estat >> 16) & 0x3f;
    switch (ecode) {
      case 0x0: ev.event = EVENT_IRQ_TIMER; break;
      case 0xb:
        ev.event = (c->GPR1 == -1) ? EVENT_YIELD : EVENT_SYSCALL;
        c->era += 4;
        break;
      case 0x3f: __am_tlb_refill(); goto ret;
      default: ev.event = EVENT_ERROR; break;
    }
#endif

    c = user_handler(ev, c);
    assert(c != NULL);
  }

#ifndef __ICS_EXPORT
ret:
  if ((c->prmd & 0x3) == 0x3) {
    // return to user
    asm volatile("csrwr %0, 0x30" : : "r"(c + 1)); // 0x30 = save0
    __am_switch(c);
  }
#endif
  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrwr %0, 0xc" : : "r"(__am_asm_trap));  // 0xc = eentry

#ifndef __ICS_EXPORT
  asm volatile("csrwr $zero, 0x30"); // 0x30 = save0
  asm volatile("csrwr %0, 0x88" : : "r"(__am_asm_trap));  // 0x88 = tlbrentry
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
  c->era = (uintptr_t)entry;
  c->GPR2 = (uintptr_t)arg;
  c->prmd = 0;
  c->gpr[3] = (uintptr_t)(c + 1); // sp
  return c;
#endif
}

void yield() {
  asm volatile("li.w $a7, -1; syscall 0");
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
