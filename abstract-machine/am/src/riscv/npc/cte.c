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
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 11: // ecall
        switch (c->gpr[SYSCALL_TYPE_GPR]) {
          case -1: ev.event = EVENT_YIELD; break;
          default: ev.event = EVENT_ERROR; break;
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
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context *ctx = kstack.end - sizeof(Context);
  ctx->mcause = 11;
  ctx->mstatus = 0x1800;
  ctx->mepc = (uintptr_t)entry - 4;
  ctx->gpr[10] = (uintptr_t)arg;
  ctx->gpr[2] = (uintptr_t)ctx;
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
