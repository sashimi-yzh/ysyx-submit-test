.section ssbl, "ax"
.globl _start_ss
.type _start_ss, @function

_start_ss:
  la a0, _copy_vma
  la a1, _copy_lma
  la a2, _copy_end
1:
  lw t0, 0(a1)
  sw t0, 0(a0)
  addi a0, a0, 4
  addi a1, a1, 4
  bltu a0, a2, 1b

  la a0, _bss_start
  la a1, _stack_top
1:
  sw zero, 0(a0)
  addi a0, a0, 4
  bltu a0, a1, 1b

  fence.i

  la sp, _stack_pointer
  la t0, _trm_init
  jalr zero, t0, 0

.size _start_ss, . - _start_ss
