#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

extern void __am_asm_trap(void);
static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  Event ev = {0};
  if(user_handler){
    switch(c->mcause){
      case 11:
        c->mepc +=4;
        ev.event = (c->GPR1 == (uintptr_t)-1) ? EVENT_YIELD : EVENT_SYSCALL;
        break;
      default: 
        ev.event = EVENT_ERROR;
        break;
    }
    Context *new_event = user_handler(ev, c);
    assert(new_event != NULL);
    return new_event;
  }
  return c;
}

bool cte_init(Context*(*handler)(Event, Context*)) {
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  user_handler = handler;
  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  uintptr_t top = (uintptr_t) kstack.end;
  Context *c = (Context*) (top - sizeof(Context));
  memset(c,0,sizeof(Context));
  c->mepc = (uintptr_t) entry;
  c->mstatus = 0x1800;
  c->gpr[10] = (uintptr_t) arg;
  c->gpr[2] = top;
  return c;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {return false;}
void iset(bool enable) {}
