#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;
#define CONFIG_ETRACE

Context* __am_irq_handle(Context *c) {

  if (user_handler) {
    Event ev = {0};

    uint32_t cause = c->mcause;

    switch (cause) {
      case 8: case 9: case 11:
        ev.event=EVENT_YIELD;
          c->mepc += 4;
          #ifdef CONFIG_ETRACE
          // printf("Trap: EVENT_YIELD\n"); 
          #endif
        break;
      default: ev.event = EVENT_ERROR; 
          #ifdef CONFIG_ETRACE
          printf("Trap: EVENT_ERROR\n"); 
          #endif
        break;
    }
    // printf("处理前上下文: %d\n", c);
    c = user_handler(ev, c);
    assert(c != NULL);
    // printf("处理后上下文: %d\n", c);
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

// #define CONTEXT_SIZE  ((NR_REGS + 3) * 4)

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  uintptr_t stack_top = (uintptr_t)(kstack.end);
  stack_top = stack_top & ~0xF;
  Context *c = (Context*)(stack_top - sizeof(Context));
  memset(c, 0, sizeof(Context));
  c->mepc = (uintptr_t)entry;
  c->gpr[10] = (uintptr_t)arg;
  c->gpr[2] = stack_top;
  c->mstatus = 0x1800;
  // printf("创建上下文: %d -> 大小=%d, 栈顶=%d\n", 
  //      c, sizeof(Context), stack_top);
  return c;
}

void yield() {

  // printf("Sizeof Context: %d bytes\n", sizeof(Context));
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
