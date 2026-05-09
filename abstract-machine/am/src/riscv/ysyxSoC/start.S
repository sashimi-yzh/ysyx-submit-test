.section .entry, "ax"
.globl _start
.type _start, @function

_start:
    mv s0, zero
    mv gp, zero
    mv tp, zero
    lui sp, %hi(_stack_pointer)
    addi sp, sp, %lo(_stack_pointer)

    /* === Stage 1: 拷贝 Stage 2 (copy_routine) 到 SDRAM === */

    /* a0 = 源地址（Flash 中的 .copy_routine LMA） */
    lui a0, %hi(_copy_routine_load_start)
    addi a0, a0, %lo(_copy_routine_load_start)

    /* a1 = 目标地址（SDRAM 中的 .copy_routine VMA） */
    lui a1, %hi(_copy_routine_start)
    addi a1, a1, %lo(_copy_routine_start)

    /* a2 = 长度 */
    lui a2, %hi(_copy_routine_end)
    addi a2, a2, %lo(_copy_routine_end)
    lui t0, %hi(_copy_routine_start)
    addi t0, t0, %lo(_copy_routine_start)
    sub a2, a2, t0

    /* a3 = 源结束地址 */
    add a3, a0, a2

stage1_copy_loop:
    beq a0, a3, stage1_done
    lw t0, 0(a0)
    sw t0, 0(a1)
    addi a0, a0, 4
    addi a1, a1, 4
    j stage1_copy_loop

stage1_done:
    /* 跳转到 SDRAM 中的 Stage 2 */
    lui t0, %hi(_copy_routine_start)
    addi t0, t0, %lo(_copy_routine_start)
    jalr zero, t0, 0


.section .copy_routine, "ax"
.globl copy_routine_entry
copy_routine_entry:

    /* === Stage 2: 在 SDRAM 中运行，拷贝主程序 === */

    /* 拷贝 .main_text */
    lui a0, %hi(_text_load_start)
    addi a0, a0, %lo(_text_load_start)

    lui a1, %hi(_text_start)
    addi a1, a1, %lo(_text_start)

    lui a2, %hi(_text_end)
    addi a2, a2, %lo(_text_end)
    sub a2, a2, a1
    add a3, a0, a2

copy_text_loop:
    beq a0, a3, copy_done
    lw t0, 0(a0)
    sw t0, 0(a1)
    addi a0, a0, 4
    addi a1, a1, 4
    j copy_text_loop

copy_done:

    lui t0, %hi(trampoline)
    addi t0, t0, %lo(trampoline)
    jalr zero, t0, 0

.section .text.trampoline, "ax"
.globl trampoline
trampoline:
    call _trm_init