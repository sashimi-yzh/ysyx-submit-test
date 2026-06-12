.section entry, "ax"
.globl _start
.type _start, @function
.option norelax

_start:
  # la gp, __global_pointer$
  la gp, 0
  la sp, _stack_pointer
  call _fsbl

.size _start, . - _start
