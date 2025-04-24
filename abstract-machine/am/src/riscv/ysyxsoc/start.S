.section entry, "ax"
.globl _start
.type _start, @function

//#define EXECUTE_IN_MROM
//#define EXECUTE_IN_SRAM
#define EXECUTE_IN_SDRAM

#define HAS_SSBL

#ifndef EXECUTE_IN_SDRAM
#undef HAS_SSBL
#endif

_start:
#ifdef HAS_SSBL
  la a0, _ssbl_vma
  la a1, _ssbl_lma
  la a2, _ssbl_size
  beqz a2, fsbl_memcpy_finish
  add a2, a0, a2
fsbl_memcpy_loop:
  lw t0, (a1)
  sw t0, (a0)
  addi a0, a0, 4
  addi a1, a1, 4
  bne  a0, a2, fsbl_memcpy_loop
fsbl_memcpy_finish:
  tail _ssbl

.section ssbl, "ax"
.globl _ssbl
.type _ssbl, @function

_ssbl:
#endif
#ifndef EXECUTE_IN_MROM
  la a0, _text_vma
  la a1, _text_lma
  la a2, _text_size
  call _ssbl_memcpy
#endif

  la a0, _data_vma
  la a1, _data_lma
  la a2, _data_size
  call _ssbl_memcpy

  la a2, _bss_size
  beqz a2, _ssbl_memset_finish
  la a0, _bss_vma
  add a2, a0, a2
_ssbl_memset_loop:
  sw zero, (a0)
  addi a0, a0, 4
  bltu a0, a2, _ssbl_memset_loop
_ssbl_memset_finish:

  mv s0, zero
  la sp, _stack_pointer
  call _trm_init

_ssbl_memcpy:
  beqz a2, _ssbl_memcpy_finish
  add a2, a0, a2
_ssbl_memcpy_loop:
  lw t0, (a1)
  sw t0, (a0)
  addi a0, a0, 4
  addi a1, a1, 4
  bne  a0, a2, _ssbl_memcpy_loop
_ssbl_memcpy_finish:
  ret
