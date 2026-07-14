#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 11: {ev.event = EVENT_YIELD; c->mepc += 4; break;} // ecall
      default: ev.event = EVENT_ERROR; break;
    }

  //   printf("Context: mepc = 0x%08x, status = 0x%08x, mcause = 0x%08x\n",
  //        c->mepc, c->status, c->mcause);
  // // 打印全部寄存器
  // for (int i = 0; i < NR_REGS; i++)
  // {
  //   printf("gpr[%d] = 0x%08x\n", i, c->gpr[i]);
  // }

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
  Context *cp = kstack.end - sizeof(Context);
  cp->mepc = (uintptr_t)entry;

  cp->gpr[10] = (uintptr_t)arg;

  return cp;
  

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
