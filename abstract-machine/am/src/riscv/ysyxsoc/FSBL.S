# This file is SDSRAM bootloader.
    .section .text.fsbl, "ax"
    .global FSBL_entry
FSBL_entry:

    lui a0, %hi(boot_loader_lma_addr)      # LMA 起始
    addi a0, a0, %lo(boot_loader_lma_addr)
    lui a1, %hi(sram_boot_loader_start)        # VMA 起始
    addi a1, a1, %lo(sram_boot_loader_start)
    lui a2, %hi(sram_boot_loader_end)        # VMA 结束
    addi a2, a2, %lo(sram_boot_loader_end)   

FSBL_loop:
    lw      t0, 0(a0)        
    sw      t0, 0(a1)         
    addi    a0, a0, 4
    addi    a1, a1, 4
    bne     a1, a2, FSBL_loop

FSBL_done:
    lui t0, %hi(_sram_start)    # 加载高20位：0x0f000000的高20位是0x0f000
    addi t0, t0, %lo(_sram_start) # 加载低12位：0x0f000000的低12位是0x0
    jalr ra, t0, 0
             