# This file is SDSRAM bootloader.
    .section .text.boot, "ax"
    .global _boot_loader
_boot_loader:

    lui a0, %hi(entry_lma_addr)      # LMA 起始
    addi a0, a0, %lo(entry_lma_addr)
    lui a1, %hi(_entry_start)        # VMA 起始
    addi a1, a1, %lo(_entry_start)
    lui a2, %hi(_etext)        # VMA 结束
    addi a2, a2, %lo(_etext)   

    beq     a1, a2, text_done   

text_loop:
    lw      t0, 0(a0)        
    sw      t0, 0(a1)         
    addi    a0, a0, 4
    addi    a1, a1, 4
    bne     a1, a2, text_loop

text_done:

    lui a0, %hi(rodata_lma_addr)      # LMA 起始
    addi a0, a0, %lo(rodata_lma_addr)
    lui a1, %hi(_rodata_start)        # VMA 起始
    addi a1, a1, %lo(_rodata_start)
    lui a2, %hi(_rodata_end)        # VMA 结束
    addi a2, a2, %lo(_rodata_end)   

    beq     a1, a2, rodata_done   

rodata_loop:
    lw      t0, 0(a0)        
    sw      t0, 0(a1)         
    addi    a0, a0, 4
    addi    a1, a1, 4
    bne     a1, a2, rodata_loop

rodata_done:

    # ---------- 复制 .data 段（从 mrom 的 LMA → sram 的 VMA） ----------
    
    lui a0, %hi(data_lma_addr)      # LMA 
    addi a0, a0, %lo(data_lma_addr)
    lui a1, %hi(_data_start)        # VMA 起始
    addi a1, a1, %lo(_data_start)
    lui a2, %hi(_data_end)        # VMA 结束
    addi a2, a2, %lo(_data_end)        

    beq     a1, a2, data_done   

data_loop:
    lw      t0, 0(a0)        
    sw      t0, 0(a1)         
    addi    a0, a0, 4
    addi    a1, a1, 4
    bne     a1, a2, data_loop

data_done:

    # ---------- 清零 .bss 段 ----------

    lui a0, %hi(_bss_start)      # LMA 
    addi a0, a0, %lo(_bss_start)
    lui a1, %hi(_bss_end)        # VMA 
    addi a1, a1, %lo(_bss_end)
    beq     a0, a1, bss_done   

    li      t0, 0
bss_loop:
    sw      t0, (a0)
    addi    a0, a0, 4
    bne     a0, a1, bss_loop

bss_done:
    lui ra, %hi(0xa0000014)    
    addi ra, ra, %lo(0xa0000014) 
    ret                  