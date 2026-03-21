.section fsbl_entry, "ax"
.globl _start
.type _start, @function

_start:
  la a0, _ssbl_loadaddr
  la a1, _sssbl
  la a2, _essbl

.ssbl_copy_loop:
  beq a1, a2, .ssbl_copy_done
  lw t0, 0(a0)
  sw t0, 0(a1)
  addi a0, a0, 4
  addi a1, a1, 4
  j .ssbl_copy_loop

.ssbl_copy_done:
  la t0, _start_ssbl 
  jr t0

.size _start, . - _start


.section ssbl_entry, "ax"
.globl _start_ssbl
.type _start_ssbl, @function

_start_ssbl:
  la a0, _text_loadaddr
  la a1, _stext
  la a2, _etext

.text_copy:
  beq a1, a2, .text_copy_done
  lw t0, 0(a0)
  sw t0, 0(a1)
  addi a0, a0, 4
  addi a1, a1, 4
  j .text_copy

.text_copy_done:
  la a0, _data_loadaddr
  la a1, _sdata
  la a2, _edata

.data_copy:
  beq a1, a2, .data_copy_done
  lw t0, 0(a0)
  sw t0, 0(a1)
  addi a0, a0, 4
  addi a1, a1, 4
  j .data_copy

.data_copy_done:
  la a0, _szero
  la a1, _ezero

.zero_loop:
  beq a0, a1, .zero_done
  sw zero, 0(a0)
  addi a0, a0, 4
  j .zero_loop

.zero_done:
  la t0, _start_text
  jr t0

.size _start_ssbl, . - _start_ssbl


.section text_entry, "ax"
.globl _start_text
.type _start_text, @function

_start_text:
  mv s0, zero
  la sp, _stack_pointer
  fence.i
  call _trm_init

.size _start_text, . - _start_text