.section entry, "ax"
.globl _start
# 第一级引导加载程序
_start:
    la      a0, boot_start          # 目标地址
    la      a1, boot_load_start     # 源地址
    la      a2, boot_size           # 大小

    beq     a0, a1, _boot_end 
    beqz    a2, _boot_end
    # 计算4字节块数和剩余字节
    srli    a3, a2, 2
    andi    a4, a2, 0x3
    beqz    a3, _bootf_1bytes
_bootf_4bytes:
    lw      a5, 0(a1)
    sw      a5, 0(a0)
    addi    a0, a0, 4
    addi    a1, a1, 4
    addi    a3, a3, -1
    bnez    a3, _bootf_4bytes
    beqz    a4, _boot_end

_bootf_1bytes:
    lb      a5, 0(a1)
    sb      a5, 0(a0)
    addi    a0, a0, 1
    addi    a1, a1, 1
    addi    a4, a4, -1
    bnez    a4, _bootf_1bytes

_boot_end:
    la      t0, _boot_ssbl    # 加载目标地址到寄存器
    jr      t0                # 跳转

.section boot, "ax"
.globl _real_start


# 第二级引导加载程序
_boot_ssbl:
    # 复制.text段
    la      a0, text_start
    la      a1, text_load_start
    la      a2, text_size
    beq     a0, a1, _boot_ssbl_rodata 
    beqz    a2, _boot_ssbl_rodata
    jal     _boots_32pre
  
_boot_ssbl_rodata:
    # 复制.rodata段
    la      a0, rodata_start
    la      a1, rodata_load_start
    la      a2, rodata_size
    beq     a0, a1, _boot_ssbl_data 
    beqz    a2, _boot_ssbl_data
    jal     _boots_32pre

_boot_ssbl_data:
    # 复制.data段
    la      a0, data_start
    la      a1, data_load_start
    la      a2, data_size
    beq     a0, a1, _boot_ssbl_bss
    beqz    a2, _boot_ssbl_bss
    jal     _boots_32pre

_boot_ssbl_bss:
    # 初始化.bss段
    la      a0, bss_start
    la      a2, bss_size
    beqz    a2, _real_start
    jal     _boots_32pre_bss

# 程序入口点
_real_start:
    # 清零寄存器
    mv      ra, zero
    mv      s0, zero
    mv      a0, zero
    mv      a1, zero
    mv      a2, zero
    mv      a3, zero
    mv      a4, zero
    mv      a5, zero
    
    # 设置栈指针并跳转到主程序
    la      sp, _stack_pointer
    call    _trm_init

# 32字节预复制例程
_boots_32pre:
    srli    a3, a2, 5               # 计算32字节块数
    andi    a4, a2, 0x1f            # 计算剩余字节数
    beqz    a3, _boots_8pre
    
_boots_32bytes:
    # 32字节块复制
    lw      t0, 0(a1)
    lw      t1, 4(a1)
    lw      t2, 8(a1)
    sw      t0, 0(a0)
    sw      t1, 4(a0)
    sw      t2, 8(a0)

    lw      t0, 12(a1)
    lw      t1, 16(a1)
    lw      t2, 20(a1)
    sw      t0, 12(a0)
    sw      t1, 16(a0)
    sw      t2, 20(a0)

    lw      t0, 24(a1)
    lw      t1, 28(a1)
    sw      t0, 24(a0)
    sw      t1, 28(a0)

    # 更新指针和计数器
    addi    a0, a0, 32
    addi    a1, a1, 32
    addi    a3, a3, -1
    bnez    a3, _boots_32bytes
    beqz    a4, _boots_copy_ret

_boots_8pre:
    srli    a3, a4, 3               # 计算8字节块数
    andi    a4, a4, 0x7             # 计算剩余字节数
    beqz    a3, _boots_1pre

_boots_8bytes:
    # 8字节块复制
    lw      t0, 0(a1)
    lw      t1, 4(a1)
    sw      t0, 0(a0)
    sw      t1, 4(a0)

    addi    a0, a0, 8
    addi    a1, a1, 8
    addi    a3, a3, -1
    bnez    a3, _boots_8bytes
    beqz    a4, _boots_copy_ret

_boots_1pre:
    mv      a3, a4

_boots_1bytes:
    # 单字节复制
    lb      t0, 0(a1)
    sb      t0, 0(a0)

    addi    a0, a0, 1
    addi    a1, a1, 1
    addi    a3, a3, -1
    bnez    a3, _boots_1bytes

_boots_copy_ret:
    jr      ra                      # 返回

# BSS段清零例程
_boots_32pre_bss:
    srli    a3, a2, 5               # 计算32字节块数
    andi    a4, a2, 0x1f            # 计算剩余字节数
    beqz    a3, _boots_8pre_bss
    
_boots_32bytes_bss:
    # 32字节清零
    sw      zero, 0(a0)
    sw      zero, 4(a0)
    sw      zero, 8(a0)
    sw      zero, 12(a0)
    sw      zero, 16(a0)
    sw      zero, 20(a0)
    sw      zero, 24(a0)
    sw      zero, 28(a0)

    addi    a0, a0, 32
    addi    a3, a3, -1
    bnez    a3, _boots_32bytes_bss
    beqz    a4, _boots_copy_bss_ret

_boots_8pre_bss:
    srli    a3, a4, 3               # 计算8字节块数
    andi    a4, a4, 0x7             # 计算剩余字节数
    beqz    a3, _boots_1pre_bss

_boots_8bytes_bss:
    # 8字节清零
    sw      zero, 0(a0)
    sw      zero, 4(a0)

    addi    a0, a0, 8
    addi    a3, a3, -1
    bnez    a3, _boots_8bytes_bss
    beqz    a4, _boots_copy_bss_ret

_boots_1pre_bss:
    mv      a3, a4

_boots_1bytes_bss:
    # 单字节清零
    sb      zero, 0(a0)

    addi    a0, a0, 1
    addi    a3, a3, -1
    bnez    a3, _boots_1bytes_bss

_boots_copy_bss_ret:
    jr      ra                      # 返回