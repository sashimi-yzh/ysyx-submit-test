#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
		
	// printf("npc/cte/__am_irq_handle \n");
	// for(int i=0; i < NR_REGS; i++) printf("gpr[%02d]:0x%x\n", i, c->gpr[i]);
	// printf("mcause(Interrupt):\t%d mcause(Code):\t%d\n", c->mcause >> 31, c->mcause & 0x7FFFFFFF);
	// printf("mstatus:\t 0x%x\n", c->mstatus);
	// printf("mepc:\t 0x%x\n", c->mepc);
	// printf("*pdir:\t 0x%x\n", c->pdir);

  if (user_handler) {
	Event ev = {0};
			if (c->mcause & 0x80000000) {//mcause最高位为1
			switch (c->mcause & 0x7FFFFFFF) {
				default: ev.event = EVENT_ERROR; break;
		   }
		}else {//mcause最高位为0
			switch (c->mcause & 0x7FFFFFFF) {
				case 3: ev.event = EVENT_YIELD; break;
				case 11: //ev.event = EVENT_SYSCALL; break;
					if(c->gpr[15] == -1){ev.event = EVENT_YIELD; ;break;}
					else{ev.event = EVENT_SYSCALL; break;}
				default: ev.event = EVENT_ERROR; break;
		   }
		}
	// switch (c->mcause) {
	//   default: ev.event = EVENT_ERROR; break;
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
	Context* kcontext = (Context*)kstack.end - 1; // 开辟空间

	kcontext->mepc = (uintptr_t)entry - 4; //保存f函数的地址 减去4是因为mret加4了，这里要返回原位置
	kcontext->gpr[10] = (uintptr_t)arg;// a0 -> gpr[10] RISC-V调用约定：a0 = 第一个参数/返回值

	return kcontext;
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
