.section ssbl, "ax"
.globl _ssbl
.type _ssbl, @function

/*#define __RTTHREAD__*/

_ssbl:
  la t2, _text_lma
  la t0, _stext
  la t1, _etext
1:
  bge  t0, t1, 2f
  lw   a0, 0(t2)
  sw   a0, 0(t0)
  addi t0, t0, 4
  addi t2, t2, 4
  j    1b


2:
  la t2, _rodata_lma
  la t0, _srodata
  la t1, _erodata
3:
  bge  t0, t1, 4f
  lw   a0, 0(t2)
  sw   a0, 0(t0)
  addi t0, t0, 4
  addi t2, t2, 4
  j    3b

4:
#ifdef __RTTHREAD__
  la t2, _data_extra_lma
  la t0, __fsymtab_start
  la t1, _edata
#else
  la t2, _data_lma
  la t0, _sdata
  la t1, _edata
#endif

5:
  bge  t0, t1, 6f
  lw   a0, 0(t2)
  sw   a0, 0(t0)
  addi t0, t0, 4
  addi t2, t2, 4
  j    5b

6:
#ifdef __RTTHREAD__
  la t2, _bss_extra_lma
  la t0, __am_apps_bss_start
  la t1, _ebss
#else
  la t2, _bss_lma
  la t0, _sbss
  la t1, _ebss
#endif
  
7:
  bge  t0, t1, 8f
  sw   zero, 0(t0)
  addi t0, t0, 4
  j    7b

8:
  la   t0, _start     # jump to _start in psram
  jr   t0


  

