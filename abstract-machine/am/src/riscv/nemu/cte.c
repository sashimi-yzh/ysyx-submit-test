#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 11:  
        if ((intptr_t)c->GPR1 == -1) {
          ev.event = EVENT_YIELD;
          c->mepc += 4; 
        } else {
          ev.event = EVENT_ERROR;
        }
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

bool cte_init(Context*(*handler)(Event, Context*)) {
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  user_handler = handler;
  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context *c = (Context *)((uintptr_t)kstack.end - sizeof(Context));
  c = (Context *)((uintptr_t)c & ~0x7);
  memset(c, 0, sizeof(Context));
  c->mepc = (uintptr_t)entry;
  c->gpr[10] = (uintptr_t)arg;   
  c->gpr[2]  = (uintptr_t)kstack.end; 
  c->mstatus = 0x1800;
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
