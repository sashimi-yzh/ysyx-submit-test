.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  mv gp, zero
  mv tp, zero
  la sp, _stack_pointer
  call _trm_init
