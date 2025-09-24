#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

char *mcause_map(int cause) {
  switch (cause) {
    case 0: return "Instruction address misaligned";
    case 1: return "Instruction access fault";
    case 2: return "Illegal instruction";
    case 3: return "Breakpoint";
    case 4: return "Load address misaligned";
    case 5: return "Load access fault";
    case 6: return "Store/AMO address misaligned";
    case 7: return "Store/AMO access fault";
    case 8: return "Environment call from U-mode";
    case 9: return "Environment call from S-mode";
    case 11: return "Environment call from M-mode";
    case 12: return "Instruction page fault";
    case 13: return "Load page fault";
    case 15: return "Store/AMO page fault";
    default: return "Unknown cause";
  }
}

Context* __am_irq_handle(Context *c) {
  if (c->mcause != 11) {
    printf("\nUnhandled exception: %s\n", mcause_map(c->mcause));
    halt(1);
  }

  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 11: ev.event = EVENT_YIELD; c->mepc += 4; break;
      default: ev.event = EVENT_ERROR; halt(1); break;
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
  Context *cp = (Context *)kstack.end - 1;
  cp->mepc = (uintptr_t)entry;
  cp->mstatus = 0x1800;
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
