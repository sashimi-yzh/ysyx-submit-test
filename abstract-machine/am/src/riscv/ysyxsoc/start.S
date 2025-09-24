.section entry, "ax"
.globl _start
.type _start, @function

_start:
  fence.i
  li ra, 0
  la sp, _stack_pointer
  li gp, 0
  li tp, 0
  li t0, 0
  li t1, 0
  li t2, 0
  li s0, 0
  li s1, 0
  li a0, 0
  li a1, 0
  li a2, 0
  li a3, 0
  li a4, 0
  li a5, 0
  jal _fsbl
