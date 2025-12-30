#include <am.h>
#include <klib-macros.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  //asm volatile("汇编指令" : 输出操作数 : 输入操作数 : 破坏列表);
  // asm volatile("lui	a5, 0xa0000" : : :"a5");
  // asm volatile("sb	a0, 1016(a5)" : :"r"(ch): "memory");

    asm volatile(
        "lui a5, 0xa0000\n"      // a5 = 0xa0000000
        "sb %0, 0x3f8(a5)"       // t0的值存储到 0xa00003f8(a5 + 0x3f8)
        : 
        : "r"(ch)                // %0 对应 ch 参数
        : "a5", "memory"         // a5和内存会被修改
    );
}

void halt(int code) {
  asm volatile("mv a0, %0; ebreak" : :"r"(code): "a0");
  //将函数的code(0的话表示正常退出)参数通过a0寄存器传递给ebreak异常处理器。
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
