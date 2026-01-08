.section entry, "ax"
.globl _start
.type _start, @function

_start:
    mv s0, zero
    la sp, _stack_pointer
    call bootloader1
    call bootloader2
    call _trm_init //bootloader结束后返回进入SRAM中的_trm_init
    

.size _start, . - _start

