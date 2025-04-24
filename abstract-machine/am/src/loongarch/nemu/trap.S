#define concat_temp(x, y) x ## y
#define concat(x, y) concat_temp(x, y)
#define MAP(c, f) c(f)

#define REGS(f) \
      f( 1) f( 2)       f( 4) f( 5) f( 6) f( 7) f( 8) f( 9) \
f(10) f(11) f(12) f(13) f(14) f(15) f(16) f(17) f(18) f(19) \
f(20) f(21) f(22) f(23) f(24) f(25) f(26) f(27) f(28) f(29) \
f(30) f(31)

#define PUSH(n) st.w $concat(r, n), $sp, (n * 4);
#define POP(n)  ld.w  $concat(r, n), $sp, (n * 4);

#define CONTEXT_SIZE  ((32 + 3) * 4)
#define OFFSET_SP     ( 3 * 4)
#define OFFSET_ESTAT  (32 * 4)
#define OFFSET_PRMD   (33 * 4)
#define OFFSET_ERA    (34 * 4)

#define CSR_ESTAT  0x5
#define CSR_PRMD  0x1
#define CSR_ERA   0x6

.align 6
.globl __am_asm_trap
__am_asm_trap:
#ifndef __ICS_EXPORT
#define CSR_SAVE0 0x30
#define CSR_SAVE1 0x31

  csrwr $sp, CSR_SAVE1
  csrrd $sp, CSR_SAVE0
  bne   $sp, $zero, save_context
  # trap from kernel, restore the original sp
  csrrd $sp, CSR_SAVE1

save_context:
#endif
  addi.w $sp, $sp, -CONTEXT_SIZE

  MAP(REGS, PUSH)

#ifndef __ICS_EXPORT
  csrrd $t0, CSR_SAVE1 # t0 = sp before trap
  csrwr $zero, CSR_SAVE0
  st.w $t0, $sp, OFFSET_SP

#endif
  csrrd $t0, CSR_ESTAT
  csrrd $t1, CSR_PRMD
  csrrd $t2, CSR_ERA

  st.w $t0, $sp, OFFSET_ESTAT
  st.w $t1, $sp, OFFSET_PRMD
  st.w $t2, $sp, OFFSET_ERA

  move $a0, $sp
  bl __am_irq_handle
#ifndef __ICS_EXPORT

  move $sp, $a0
#endif

  ld.w $t1, $sp, OFFSET_PRMD
  ld.w $t2, $sp, OFFSET_ERA
  csrwr $t1, CSR_PRMD
  csrwr $t2, CSR_ERA

  MAP(REGS, POP)

#ifdef __ICS_EXPORT
  addi.w $sp, $sp, CONTEXT_SIZE
#else
  ld.w $sp, $sp, OFFSET_SP
#endif
  ertn
