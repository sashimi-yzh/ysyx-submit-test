#include <am.h>
#include <nemu.h>

extern char _heap_start;// 声明符号
int main(const char *args);// 提前声明main函数
// 指示堆区的起始和末尾
Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS
// 输出一个字符
void putch(char ch) {
  outb(SERIAL_PORT, ch);
  //*(volatile uint8_t *)0xa00003f8 = (uint8_t)ch;
}
// 结束程序的运行
void halt(int code) {
  nemu_trap(code);

  // should not reach here
  while (1);
}
// 进行TRM相关的初始化工作
void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
