.section entry, "ax"
.globl _start
.type _start, @function

_start:
  mv s0, zero

  la t0, _flash_SSBL_start
  la t1, _sram_SSBL_start
  la t2, _flash_SSBL_end

  1:
    bge t0, t2, 2f
    lw s0, 0(t0)
    addi t0, t0, 4
    sw s0, 0(t1)
    addi t1, t1, 4
    j 1b

  2:
  call _SSBL

.section SSBL, "ax"
.globl _SSBL
.type _SSBL, @function
_SSBL:
/* ----------------- copy .text ----------------- */
  fence.i
  la t0, _flash_text_start
  la t1, _sdram_text_start
  la t2, _flash_text_end

  1:
    bge t0, t2, 2f
    lw s0, 0(t0)
    addi t0, t0, 4
    sw s0, 0(t1)
    addi t1, t1, 4
    j 1b
  2:
    la t0, _flash_rodata_start
    la t1, _sdram_rodata_start
    la t2, _flash_rodata_end

  3:
    bge t0, t2, 4f
    lw s0, 0(t0)
    addi t0, t0, 4
    sw s0, 0(t1)
    addi t1, t1, 4
    j 3b

  4:
    la t0, _flash_data_start
    la t1, _sdram_data_start
    la t2, _flash_data_end

  5:
    bge t0, t2, 6f
    lw s0, 0(t0)
    addi t0, t0, 4
    sw s0, 0(t1)
    addi t1, t1, 4
    j 5b
  6:
    /* ----------------- copy extra data (if exists) ----------------- */
    la t0, _flash_extra_data_start
    la t1, _sdram_extra_data_start
    la t2, _flash_extra_data_end
    
  7:
    bge t0, t2, 8f
    lw s0, 0(t0)
    addi t0, t0, 4
    sw s0, 0(t1)
    addi t1, t1, 4
    j 7b

  8:
    la sp, _stack_pointer
    call _trm_init