#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
   if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      // Environment call from M-mode
      case 11: 
        ev.event = EVENT_YIELD;
        c->mepc += 4;
        break;
      case 0x80000007: ev.event = EVENT_IRQ_TIMER;break;
      default: ev.event = EVENT_ERROR; break;
    }
    c = user_handler(ev, c);
    assert(c != NULL);
    
  }
  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  putch('c');
  putch('t');
  putch('e');
  // initialize exception entry
  asm volatile("li t0, %0" : : "n"(0x1800) );
  asm volatile("csrw mstatus, t0");
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context *c = kstack.end-sizeof(Context);              // ? pointer kstart 
  c->mstatus = 0x1800;  
  c->mcause = 11; 
  c-> mepc = (uintptr_t)entry;             // mepc is set to entry 
  c->gpr[10] =(uintptr_t)arg;              // a0 = &arg
  c->gpr[2] = (uintptr_t)c;               // sp = kstack.start for after __am_irq_handle will addi sp, sp CONTEXT_SIZE?
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
