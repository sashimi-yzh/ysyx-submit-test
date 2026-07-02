.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  la sp, _stack_pointer

  la t0, _data_load_start
  la t1, _data_start
  la t2, _data_end
  sub a1, t2, t1
  andi a1, a1, -4
  add a2, t1, a1
1:
  bgeu t1, a2, 2f
  lw a0, 0(t0)
  sw a0, 0(t1)
  addi t0, t0, 4
  addi t1, t1, 4
  j 1b
2:
  bgeu t1, t2, 3f
  lb a0, 0(t0)
  sb a0, 0(t1)
  addi t0, t0, 1
  addi t1, t1, 1
  j 2b
3:
  la t1, _bss_start
  la t2, _bss_end
  sub a1, t2, t1
  andi a1, a1, -4
  add a2, t1, a1
4:
  bgeu t1, a2, 5f
  sw zero, 0(t1)
  addi t1, t1, 4
  j 4b
5:
  bgeu t1, t2, 6f
  sb zero, 0(t1)
  addi t1, t1, 1
  j 5b
6:
  fence.i
  la t0, _trm_init
  jr t0

.size _start, . - _start
