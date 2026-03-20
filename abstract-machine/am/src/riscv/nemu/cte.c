#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
	/*printf("__am_irq_handle: mcause = %lx\n", c->mcause);
	printf("pdir: %lx\n", c->pdir);
	for(int i = 0; i < 32; i++) {
		printf("gpr[%d] = %lx\n", i, c->gpr[i]);
	}*/
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
			case 11: {
				if(c->GPR1==-1) {
					ev.event = EVENT_YIELD;
				} else {
				 	assert(0);	
				}
				break;
			}

      default: ev.event = EVENT_ERROR; break;
    }

		if(ev.event == EVENT_YIELD){
			c->mepc += 4;
		} else if(ev.event == EVENT_ERROR){}
		else assert(0);

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
	Context* ctx = (Context*)(kstack.end - sizeof(Context));
	memset(ctx, 0, sizeof(Context));
	ctx->mstatus = 0x1800;
	ctx->gpr[10] = (uintptr_t)arg; // a0
	ctx->mepc = (uintptr_t)entry;

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
