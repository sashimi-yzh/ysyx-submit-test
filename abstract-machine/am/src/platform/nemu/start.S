# .section entry, "ax"
# .globl _start
# .type _start, @function
# 
# _start:
#   mv s0, zero
#   la sp, _stack_pointer
#   call _trm_init
# 
# .size _start, . - _start

    .section entry, "ax"
    .globl _start
_start:
    # ---------------------------
    # 初始化寄存器 x1–x15
    # ---------------------------
    li x1, 1
    li x2, 2
    li x3, 3
    li x4, 4
    li x5, 5
    li x6, 6
    li x7, 7
    li x8, 8
    li x9, 9
    li x10, 10
    li x11, 11
    li x12, 12
    li x13, 13
    li x14, 14
    li x15, 15

    # ---------------------------
    # RV32I 基础指令测试
    # ---------------------------
    lui   x5, 0x12345           # LUI
    auipc x6, 0                 # AUIPC

    # ---- 修正版 JAL / JALR ----
    la   x1, return_from_jal    # 将返回地址加载到 x1
    jal  x5, func_jal           # JAL：跳转到 func_jal，返回地址保存在 x5

return_from_jal:
    beq   x1, x1, label_beq     # BEQ
    nop

func_jal:
    jalr  x0, 0(x1)             # JALR 返回到 return_from_jal
	
label_beq:
    bne   x1, x2, label_bne
label_bne:
    blt   x2, x3, label_blt
label_blt:
    bge   x3, x2, label_bge
label_bge:
    bltu  x1, x2, label_bltu
label_bltu:
    bgeu  x2, x1, label_bgeu
label_bgeu:

    # ---------------------------
    # Load / Store
    # ---------------------------
    la    x10, data
    lb    x11, 0(x10)
    lh    x12, 0(x10)
    lw    x13, 0(x10)
    lbu   x14, 0(x10)
    lhu   x15, 0(x10)

    sb    x11, 1(x10)
    sh    x12, 2(x10)
    sw    x13, 4(x10)

    # ---------------------------
    # Immediate arithmetic / logic
    # ---------------------------
    addi  x2, x2, 5
    slti  x3, x2, 10
    sltiu x4, x2, 10
    xori  x5, x2, 0xFF
    ori   x6, x2, 0xAA
    andi  x7, x2, 0x55
    slli  x8, x2, 1
    srli  x9, x2, 1
    srai  x10, x2, 1

    # ---------------------------
    # Register arithmetic / logic
    # ---------------------------
    add   x2, x2, x3
    sub   x3, x3, x2
    sll   x4, x4, x2
    slt   x5, x5, x6
    sltu  x6, x6, x7
    xor   x7, x7, x8
    srl   x8, x8, x9
    sra   x9, x9, x10
    or    x10, x10, x11
    and   x11, x11, x12

    # ---------------------------
    # RV32M 乘除法指令
    # ---------------------------
    # 确保除数非零
    addi  x8, x8, 1
    addi  x9, x9, 1

    mul     x2, x3, x4
    mulh    x3, x4, x5
    mulhsu  x4, x5, x6
    mulhu   x5, x6, x7
    div     x6, x7, x8
    divu    x7, x8, x9
    rem     x8, x9, x10
    remu    x9, x10, x11

    # ---------------------------
    # RV32Zicsr CSR 测试
    # ---------------------------
	# 先写入已知值到 CSR，防止未定义值
	li x1, 0x100          # x1 = 0x100
	csrw mstatus, x1      # mstatus = x1
	csrw mtvec, x1        # mtvec   = x1
	li x1, 0x200
	csrw mepc, x1      # mepc   = 0x200
	csrwi mcause, 0x1      # mcause = 0x1
	# csrrs: 将 x5 的值 OR 到 mtvec，旧值读回到 x4
	li x5, 0x3            # x5 = 0x3
	csrrs x4, mtvec, x5   # x4 = old mtvec, mtvec |= x5
	# csrrc: 将 x7 的值取反后 AND 到 mepc，旧值读回到 x6
	li x7, 0x1            # x7 = 0x1
	csrrc x6, mepc, x7    # x6 = old mepc, mepc &= ~x7
	# csrrwi: 将立即数 0xA 写入 mcause，旧值读回到 x8
	csrrwi x8, mcause, 0xA # x8 = old mcause, mcause = 0xA

    # ---------------------------
    # Trap 入口设置
    # ---------------------------
    la     x1, trap_handler
    csrw   mtvec, x1

    # ---------------------------
    # ECALL + MRET 测试
    # ecall 语义：保存 PC->mepc, mcause=11, 跳转 mtvec
    # trap handler 中将 mepc+4 后返回
    # ---------------------------
    ecall

after_trap:
    addi  x15, x15, 1      # 标志执行返回成功

end:
    j realend

# ---------------------------
# Trap 处理函数
# ---------------------------
trap_handler:
    csrr  x2, mepc          # 读出 mepc
    addi  x2, x2, 4         # mepc + 4
    csrw  mepc, x2          # 写回 mepc
    li    x3, 11
    csrw  mcause, x3        # 设置 mcause = 11
    mret                    # 返回到 ecall 后一条

realend:
	mv s0, zero
	la sp, _stack_pointer
	call _trm_init
# ---------------------------
# 数据段
# ---------------------------
    .section .data
data:
    .word 0x11223344
