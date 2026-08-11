.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv ra, zero
  mv gp, zero
  mv tp, zero
  mv t0, zero
  mv t1, zero
  mv t2, zero
  mv s0, zero
  mv s1, zero
  mv a0, zero
  mv a1, zero
  mv a2, zero
  mv a3, zero
  mv a4, zero
  mv a5, zero
  la sp, _stack_pointer
  call _trm_init

.size _start, . - _start
