.section entry, "ax"
.globl _fsbl
.type _fsbl, @function

_fsbl:
  // addi x0, x0, 0
  mv s0, zero
  la sp, _stack_pointer
  call _first_bootloader
