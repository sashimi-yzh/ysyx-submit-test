#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

#ifdef __riscv_e
#define SYSCALL_TYPE_GPR 15
#else
#define SYSCALL_TYPE_GPR 17
#endif

Context* __am_irq_handle(Context *c) {
  void __am_get_cur_as(Context *c);
  __am_get_cur_as(c);
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 11: // ecall
        if (c->gpr[SYSCALL_TYPE_GPR] == -1) ev.event = EVENT_YIELD;
        else ev.event = EVENT_SYSCALL;
        c->mepc += 4;
      break;
      case 0x80000007: // timer interrupt
        ev.event = EVENT_IRQ_TIMER;
      break;
      default:
        ev.event = EVENT_ERROR;
      break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }
  void __am_switch(Context *c);
  __am_switch(c);
  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  asm volatile("csrwi mscratch, 0x0");

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context *ctx = kstack.end - sizeof(Context);
  ctx->pdir = NULL;
  ctx->mcause = 11;
  ctx->mstatus = 0x1880;
  ctx->mepc = (uintptr_t)entry;
  ctx->GPRx = (uintptr_t)arg;
  ctx->R_SP = (uintptr_t)ctx;
  ctx->R_PRIV = PRIV_USER;
  return ctx;
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
