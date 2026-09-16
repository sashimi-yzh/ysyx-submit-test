.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero
  lui sp, %hi(_stack_pointer)     # 加载高20位（绝对地址）
  addi sp, sp, %lo(_stack_pointer)  # 加上低12位
  call FSBL_entry
  call _boot_loader
  call _trm_init

.size _start, . - _start
