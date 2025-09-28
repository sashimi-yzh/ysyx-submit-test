#define concat_temp(x, y) x ## y
#define concat(x, y) concat_temp(x, y)
#define MAP(c, f) c(f)

#if __riscv_xlen == 32
#define LOAD  lw
#define STORE sw
#define XLEN  4
#else
#define LOAD  ld
#define STORE sd
#define XLEN  8
#endif

#define REGS_LO16(f) \
      f( 1)       f( 3) f( 4)       f( 6) f( 7) f( 8) f( 9) \
f(10) f(11) f(12) f(13) f(14) f(15)
#ifndef __riscv_e
#define REGS_HI16(f) \
                                    f(16) f(17) f(18) f(19) \
f(20) f(21) f(22) f(23) f(24) f(25) f(26) f(27) f(28) f(29) \
f(30) f(31)
#define NR_REGS 32
#else
#define REGS_HI16(f)
#define NR_REGS 16
#endif

#define REGS(f) REGS_LO16(f) REGS_HI16(f)

#define PUSH(n) STORE concat(x, n), (n * XLEN)(sp);
#define POP(n)  LOAD  concat(x, n), (n * XLEN)(sp);

#define CONTEXT_SIZE  ((NR_REGS + 4) * XLEN)
#define OFFSET_PRIV   (0)
#define OFFSET_SP     (2 * XLEN)
#define OFFSET_CAUSE  ((NR_REGS + 0) * XLEN)
#define OFFSET_STATUS ((NR_REGS + 1) * XLEN)
#define OFFSET_EPC    ((NR_REGS + 2) * XLEN)

.type __am_asm_trap, @function

.align 3
.globl __am_asm_trap
__am_asm_trap:

  csrrw sp, mscratch, sp
  beqz sp, .L1
  
  addi sp, sp, -CONTEXT_SIZE
  PUSH(5) # push t0/x5
  csrr t0, mscratch
  STORE t0, OFFSET_SP(sp)
  li t0, 0x1
  STORE t0, OFFSET_PRIV(sp) # PRIV_USER
  j .L2

.L1:

  csrr sp, mscratch
  addi sp, sp, -CONTEXT_SIZE
  PUSH(5) # push t0/x5
  addi t0, sp, CONTEXT_SIZE
  STORE t0, OFFSET_SP(sp)
  STORE x0, OFFSET_PRIV(sp) # PRIV_KERNAL

.L2:

  csrw mscratch, x0

  MAP(REGS, PUSH)

  csrr t0, mcause
  csrr t1, mstatus
  csrr t2, mepc

  STORE t0, OFFSET_CAUSE(sp)
  STORE t1, OFFSET_STATUS(sp)
  STORE t2, OFFSET_EPC(sp)

  # set mstatus.MPRV to pass difftest
  li a0, (1 << 17)
  or t1, t1, a0
  csrw mstatus, t1

  mv a0, sp
  jal __am_irq_handle
  mv sp, a0

  LOAD t1, OFFSET_STATUS(sp)
  LOAD t2, OFFSET_EPC(sp)
  csrw mstatus, t1
  csrw mepc, t2

  MAP(REGS, POP)

  LOAD t0, OFFSET_PRIV(sp)
  beqz t0, .L3

  addi t0, sp, CONTEXT_SIZE
  csrw mscratch, t0

.L3:
  POP(5) # t0/x5
  POP(2) # sp/x2

  mret

.size __am_asm_trap, . - __am_asm_trap
