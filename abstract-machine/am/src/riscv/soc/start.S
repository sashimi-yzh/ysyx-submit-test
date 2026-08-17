.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  la sp, _stack_pointer
  call fstbootloader
  fence.i
  call secbootloader
  fence.i
  call _init_uart
  csrr a0, mvendorid
  csrr a1, marchid
  call _show_motd
  call _trm_init

.size _start, . - _start
