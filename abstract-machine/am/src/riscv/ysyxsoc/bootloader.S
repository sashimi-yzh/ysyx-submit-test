# This file is SDSRAM bootloader.
    .section .text.boot, "ax"
    .global _boot_loader
_boot_loader:

    li      t0, 1          # 把立即数1加载到t0寄存器（临时寄存器）
    bne     a0, t0, FSBL_entry  # 如果a0≠1，跳转到FSBL_entry（原FSBL_loop入口）
    j       SSBL_entry      # 如果a0=1，直接跳转到SSBL_loop

FSBL_entry:
    lui a0, %hi(entry_lma_addr)      # LMA 起始
    addi a0, a0, %lo(entry_lma_addr)
    lui a1, %hi(_entry_start)        # VMA 起始
    addi a1, a1, %lo(_entry_start)
    lui a2, %hi(_boot_loader_end)        # VMA 结束
    addi a2, a2, %lo(_boot_loader_end)   

FSBL_loop:
    lw      t0, 0(a0)        
    sw      t0, 0(a1)         
    addi    a0, a0, 4
    addi    a1, a1, 4
    bne     a1, a2, FSBL_loop

FSBL_done:
    li      a0, 1
    lui     t0, 0x70000  # SDRAM
    add     ra, ra, t0 
    fence.i
    ret

SSBL_entry:
    lui a0, %hi(text_lma_addr)      # LMA 起始
    addi a0, a0, %lo(text_lma_addr)
    lui a1, %hi(_text_start)        # VMA 起始
    addi a1, a1, %lo(_text_start)
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
    #lui     t0, 0x50000          # 等价于lui t0, %hi(0x50000000)，t0 = 0x50000000
    #sub     ra, ra, t0           # ra = ra - 0x50000000
    ret                  