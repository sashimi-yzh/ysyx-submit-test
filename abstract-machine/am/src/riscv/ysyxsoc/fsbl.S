.section fsbl, "ax"
.global _fsbl
.type _fsbl, @function

_fsbl:
  la t0, _ssbl_src
  la t1, _ssbl_start
  la t2, _ssbl_end

.L1:
  lw a2, 0(t0)
  addi t0, t0, 4
  sw a2, 0(t1)
  addi t1, t1, 4
  bltu t1, t2, .L1

  tail _ssbl

.size _fsbl, . - _fsbl
