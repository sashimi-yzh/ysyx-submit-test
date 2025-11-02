#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;


Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
		case 0xb: ev.event = EVENT_YIELD; break;
      	default: ev.event = EVENT_ERROR; break;
    }
;
	c->mepc += 4;
    c = user_handler(ev, c);
    assert(c != NULL);
  }
  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  // 把__am_asm_trap作为异常处理入口
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  // register event handler
  user_handler = handler;
  return true;
}



Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
	//在栈底部创建一个上下文结构
	//暂时不考虑Context中的void *pdir成员变量
	Context* Cptr = (Context*)( kstack.end - sizeof(Context) );
	Cptr -> mepc = (uintptr_t)entry;
	Cptr -> gpr[10] = (uintptr_t)arg;
	//Cptr -> gpr[11] = (uintptr_t)(arg + 1);
	//Cptr -> gpr[12] = (uintptr_t)(arg + 2);

	return Cptr;
}



void yield() {
#ifdef __riscv_e
	asm volatile("li a5, -1; ecall");
  //直接跳转到mtvec，即__am_asm_trap处继续执行
#else
  	asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
