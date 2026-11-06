# This file is SDSRAM bootloader.
    .section SSBL, "ax"
    .global SSBL_entry
    .type SSBL_entry, @function
SSBL_entry:

  la a0, _copy_vma
  la a1, _copy_lma
  la a2, _copy_end
 

SSBL_loop:

  lw t0, 0(a1)
  sw t0, 0(a0)
  addi a0, a0, 4
  addi a1, a1, 4
  bltu a0, a2, SSBL_loop
  la a0, _bss_start
  la a1, _bss_end

SSBL_loop2:
  sw zero, 0(a0)
  addi a0, a0, 4
  bltu a0, a1, SSBL_loop2


SSBL_done:

  fence.i

  la sp, _stack_pointer
  la t0, _trm_init
  jalr zero, t0, 0
             