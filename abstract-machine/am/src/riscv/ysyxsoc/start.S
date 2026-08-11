.section .entry.start, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  la sp, _stack_pointer
  la t0, __am_fsbl
  jr t0

.size _start, . - _start