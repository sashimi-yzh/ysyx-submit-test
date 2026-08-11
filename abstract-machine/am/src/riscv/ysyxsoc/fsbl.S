.section .entry.fsbl, "ax"
.globl __am_fsbl
.type __am_fsbl, @function

__am_fsbl:
  la t0, _ssbl_lma_start
  la t1, _ssbl_vma_start
  la t2, _ssbl_vma_end

  sub a0, t2, t1
  srli a1, a0, 2
  andi a0, a0, 3

_copy_words:
  beqz a1, _copy_bytes
  lw a2, 0(t0)
  sw a2, 0(t1)
  addi t0, t0, 4
  addi t1, t1, 4
  addi a1, a1, -1
  j _copy_words

_copy_bytes:
  beqz a0, _enter_ssbl
  lbu a2, 0(t0)
  sb a2, 0(t1)
  addi t0, t0, 1
  addi t1, t1, 1
  addi a0, a0, -1
  j _copy_bytes

_enter_ssbl:
  la t0, _ssbl_entry
  jr t0

.size __am_fsbl, . - __am_fsbl

.section .ssbl, "ax"
.globl _ssbl_entry
.type _ssbl_entry, @function

_ssbl_entry:
  call __am_ssbl_load
  la t0, _trm_init
  jr t0

.size _ssbl_entry, . - _ssbl_entry
