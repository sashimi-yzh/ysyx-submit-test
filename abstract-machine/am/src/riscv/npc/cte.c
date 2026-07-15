#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  switch (c->mcause) {
    case 0:{
      printf("Instruction address misaligned at 0x%08x\n", c->mepc);
      ((void (*)(void))0x00000010)();
      while (1);
      break;
    }
    case 1:{
      printf("Instruction access fault at 0x%08x\n", c->mepc);
      ((void (*)(void))0x00000010)();
      while (1);
      break;
    }
    case 2:{
      printf("Illegal instruction at 0x%08x\n", c->mepc);
      ((void (*)(void))0x00000010)();
      while (1);
      break;
    }
    case 3:{
      uint32_t code = c->gpr[10];
      if (code == 0)
      {
        printf("Code:%d \033[32;1mHit Good Trap\033[0m\n", code);
      }
      else if (code == 1)
      {
        printf("Code:%d \033[31;1mHit Bad Trap\033[0m\n", code);
      }
      printf("Breakpoint at 0x%08x\n", c->mepc);
      ((void (*)(void))0x00000010)();
      while (1);
      break;
    }
    case 4:{
      printf("Load address misaligned at 0x%08x\n", c->mepc);
      ((void (*)(void))0x00000010)();
      while (1);
      break;
    }
    case 5:{
      printf("Load access fault at 0x%08x\n", c->mepc);
      ((void (*)(void))0x00000010)();
      while (1);
      break;
    }
    case 6:{
      printf("Store address misaligned at 0x%08x\n", c->mepc);
      ((void (*)(void))0x00000010)();
      while (1);
      break;
    }
    case 7:{
      printf("Store access fault at 0x%08x\n", c->mepc);
      ((void (*)(void))0x00000010)();
      while (1);
      break;
    }
    case 11:{
      if(c->gpr[15] == 0xFFFFFFFF)
      {
        Event ev = {0};
        ev.event = EVENT_YIELD;
        c->mepc += 4; // skip ecall
        
        if (user_handler) {
          c = user_handler(ev, c);
          assert(c != NULL);
        }

        break;
      }
    }
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
  Context *ctx = (Context *)(kstack.end - sizeof(Context));
  ctx->mepc = (uintptr_t)entry;
  ctx->gpr[10] = (uintptr_t)arg;

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
