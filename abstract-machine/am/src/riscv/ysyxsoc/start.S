.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero

  la a0, _ssbl_vma
  la a1, _ssbl_lma
  la a2, _ssbl_end
1:
  lw t0, 0(a1)
  sw t0, 0(a0)
  addi a0, a0, 4
  addi a1, a1, 4
  bltu a0, a2, 1b

  la t0, _start_ss
  jalr zero, t0, 0

.size _start, . - _start
