// 定义一个名为entry的段，属性为"ax"，"ax"属性表示这个段是可执行且可分配的。
.section entry, "ax"
// 将_start符号声明为全局符号
.globl _start
// 将_start的类型设置为函数
.type _start, @function

_start:
  // 将寄存器s0清零
  mv s0, zero
  // 将栈指针寄存器sp加载为_stack_pointer的地址
  la sp, _stack_pointer
  // 调用_trm_init函数
  call _trm_init

// 设置_start函数的大小
.size _start, . - _start
