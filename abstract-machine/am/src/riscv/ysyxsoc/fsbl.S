.section fsbl, "ax"
.globl _fsbl
.type _fsbl, @function

_fsbl:
  la t2, _ssbl_lma

  la t0, _sssbl
  la t1, _essbl

1:
  bge  t0, t1, 2f
  lb   a0, 0(t2)
  sb   a0, 0(t0)
  addi t0, t0, 1
  addi t2, t2, 1
  j    1b

2:
  la   t0, _ssbl
  jr   t0
