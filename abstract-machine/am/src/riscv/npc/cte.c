#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 11: ev.event = EVENT_YIELD; c->mepc += 4; break;  //因为spike上面是11，所以都改成了11
      default: ev.event = EVENT_ERROR; break;
    }

    /*
    printf("before:\n");
    printf("ctx->mepc=%x\n",c->mepc);
    printf("ctx->mcause=%x\n",c->mcause);
    printf("ctx->mstatus=%x\n",c->mstatus);
    printf("ctx->gpr[10]=%x\n",c->gpr[10]);*/
    c = user_handler(ev, c);
    // printf("ctx->mepc=%x\n",c->mepc);
    // printf("ctx->mcause=%x\n",c->mcause);
    // printf("ctx->mstatus=%x\n",c->mstatus);
    // printf("ctx->gpr[10]=%x\n",c->gpr[10]);
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
  //Context *ctx = kstack.end - sizeof(Context);

  uintptr_t stack_top = (uintptr_t)kstack.end;
  stack_top -= stack_top % sizeof(uintptr_t); //对齐
  stack_top -= sizeof(Context);// 为Context结构体留出空间
  Context* ctx = (Context *)stack_top;
  ctx->mepc=(uintptr_t)entry;
  ctx->mstatus=0x1800;
  ctx->gpr[10]=(uintptr_t)arg;  //a0
  ctx->gpr[2]=stack_top; //sp
  return ctx;
}


void yield() {
#ifdef __riscv_e
  //asm volatile("li a5, -1; ecall");
  asm volatile("li a5, 11; ecall");  //根据下面的改成了11，下面的根据spike修改
#else
  //asm volatile("li a7, -1; ecall");
  asm volatile("li a7, 11; ecall"); //Spike 那边是0xb来着
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
