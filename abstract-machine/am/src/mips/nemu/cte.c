#include <am.h>
#include <mips/mips32.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
#ifndef __ICS_EXPORT
  void __am_get_cur_as(Context *c);
  void __am_switch(Context *c);
  void __am_tlb_refill(void);

  __am_get_cur_as(c);
#endif
  if (user_handler) {
    Event ev = {0};
#ifdef __ICS_EXPORT
    uint32_t ex_code = 0;
    switch (ex_code) {
      default: ev.event = EVENT_ERROR; break;
    }
#else
    uint32_t ex_code = (c->cause >> 2) & 0x1f;
    switch (ex_code) {
      case 0: ev.event = EVENT_IRQ_TIMER; break;
      case 2:
      case 3: __am_tlb_refill(); goto ret;
      case 8: ;
        uint32_t syscall_instr = *(uint32_t *)(c->epc);
        ev.event = ((syscall_instr >> 6) == 1) ? EVENT_YIELD : EVENT_SYSCALL;
        c->epc += 4;
        break;
      default: ev.event = EVENT_ERROR; break;
    }
#endif

    c = user_handler(ev, c);
    assert(c != NULL);
  }

#ifndef __ICS_EXPORT
ret:
  if (((c->status >> 28) & 0x1) == 0) {
    // return to user
    asm volatile("move $k0, %0": : "r"(c + 1));
    __am_switch(c);
  }
#endif
  return c;
}

extern void __am_asm_trap(void);

#define EX_ENTRY 0x80000180

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  const uint32_t j_opcode = 0x08000000;
  uint32_t instr = j_opcode | (((uint32_t)__am_asm_trap >> 2) & 0x3ffffff);
  *(uint32_t *)EX_ENTRY = instr;
  *(uint32_t *)(EX_ENTRY + 4) = 0;  // delay slot
  *(uint32_t *)0x80000000 = instr;  // TLB refill exception
  *(uint32_t *)(0x80000000 + 4) = 0;  // delay slot

#ifndef __ICS_EXPORT
  asm volatile("move $k0, $zero");

#endif
  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
#ifdef __ICS_EXPORT
  return NULL;
#else
  Context *c = (Context*)kstack.end - 1;
  c->pdir = NULL;
  c->epc = (uintptr_t)entry;
  c->GPR2 = (uintptr_t)arg; // a0
  c->gpr[29] = (uintptr_t)(c + 1); // sp
  c->status = 0x10000000;  // status.cu0 = 1
  return c;
#endif
}

void yield() {
  asm volatile("syscall 1");
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
