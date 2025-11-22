#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {//a0寄存器传入
  if (user_handler) {
    Event ev = {0};
    // printf("%d\n",c->mcause);
    switch (c->mcause) {
      case 11:  ev.event = EVENT_YIELD; c->mepc += 4;break;
      default: ev.event = EVENT_ERROR; break;
    }
    //user_handler是一个函数指针，指向一个函数，该函数接受一个Event类型的参数和一个Context类型的参数，并返回一个Context类型的指针.
    //是cte_init函数中注册的异常处理函数
    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;//a0寄存器存储
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
  Context *cp = (Context *)(kstack.end - sizeof(Context));
  cp->mepc = (uintptr_t)entry;
  cp->mstatus = 0x1800;//防止切换进程的时候初始化不正确，每次调用时初始化一次
	cp->gpr[10] = (uintptr_t)(arg);//a0寄存器
	
  return cp;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");//a7 = -1 通常表示 程序终止请求
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
