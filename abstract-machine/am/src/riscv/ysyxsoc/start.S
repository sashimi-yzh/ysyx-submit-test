.section entry.fsbl, "ax"
.globl _fsbl
.type _fsbl, @function

_fsbl:
1:
  la t0, _ssbl_start
  la t1, _ssbl_load_start
  la t2, _essbl
2:
  bgeu t0, t2, 1f
  lw a4, 0(t1)
  sw a4, 0(t0)
  addi t0, t0, 4
  addi t1, t1, 4
  j 2b
1:
  call _ssbl

.size _fsbl, . - _fsbl

.section entry.ssbl, "ax"
.globl _ssbl
.type _ssbl, @function

_ssbl:
  mv s0, zero
  la sp, _stack_pointer
1:
  la t0, _text_start
  la t1, _text_load_start
  la t2, _etext
2:
  bgeu t0, t2, 1f
  lw a4, 0(t1)
  sw a4, 0(t0)
  addi t0, t0, 4
  addi t1, t1, 4
  j 2b
1:
  la t0, _data_start
  la t1, _data_load_start
  la t2, _edata
2:
  bgeu t0, t2, 1f
  lw a4, 0(t1)
  sw a4, 0(t0)
  addi t0, t0, 4
  addi t1, t1, 4
  j 2b
1:
  la t0, _rodata_start
  la t1, _erodata_load_start
  la t2, _erodata
2:
  bgeu t0, t2, 1f
  lw a4, 0(t1)
  sw a4, 0(t0)
  addi t0, t0, 4
  addi t1, t1, 4
  j 2b
#ifdef HAS_DATA_EXTRA
1:
  la t0, _data_extra_start
  la t1, _data_extra_load_start
  la t2, _edata_extra
2:
  bgeu t0, t2, 1f
  lw a4, 0(t1)
  sw a4, 0(t0)
  addi t0, t0, 4
  addi t1, t1, 4
  j 2b
#endif
#ifdef HAS_BSS_EXTRA
# 1:
#   la t0, _bss_extra_start
#   la t1, _bss_extra_load_start
#   la t2, _ebss_extra
# 2:
#   bgeu t0, t2, 1f
#   lw a4, 0(t1)
#   sw a4, 0(t0)
#   addi t0, t0, 4
#   addi t1, t1, 4
#   j 2b
#endif

# 1:
#   la t0, _bss_start
#   la t1, _ebss
# 2:
#   bgeu t0, t1, 1f
#   sw zero, 0(t0)
#   addi t0, t0, 4
#   j 2b
1:
  fence.i
  call _trm_init

.size _ssbl, . - _ssbl

