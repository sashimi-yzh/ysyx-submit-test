.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  la sp, _stack_pointer

  la a0, _ssbl_lma_start
  la a1, _ssbl_vma_start
  la a2, _ssbl_lma_size

_bootloader_ssbl_loop:
  beqz a2, _bootloader_ssbl_loop_end
  lb t0, 0(a0)
  sb t0, 0(a1)
  addi a0, a0, 1
  addi a1, a1, 1
  addi a2, a2, -1
  j _bootloader_ssbl_loop

_bootloader_ssbl_loop_end:
  call _ssbl

.size _start, . - _start
