#ifndef CSR_XMACRO__H_
#define CSR_XMACRO__H_

#include "debug.h"
#include "stdint.h"

// clang-format off
// Single source of truth for RISC-V CSR metadata.
//
// Columns:
//   kind   : CSR_RAW has backing storage in cpu.csr; CSR_VIRT is a projection.
//   name   : C member name / printable name.
//   addr   : architectural CSR number.
//   reset  : reset value for raw CSRs; ignored for virtual CSRs.
//   read   : NULL means direct raw read; otherwise a semantic read handler.
//   write  : NULL means direct raw write; otherwise a semantic write handler.
//   diff   : CSR_DIFF means included in difftest sync and register display.
#define CSR_TABLE(M, arg)                                                       \
  M(arg, RAW,  mepc,      0x341, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  sepc,      0x141, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  misa,      0x301, MISA_RV32_IMAC_SU, NULL,                    disable_write,           DIFF)   \
  M(arg, RAW,  mstatus,   0x300, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  mstatush,  0x310, 0,                 NULL,                    NULL,                    NODIFF) \
  M(arg, RAW,  mcause,    0x342, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  mtval,     0x343, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  mtvec,     0x305, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  mscratch,  0x340, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  satp,      0x180, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  medeleg,   0x302, 0,                 NULL,                    csr_write_medeleg,       DIFF)   \
  M(arg, RAW,  mideleg,   0x303, 0,                 NULL,                    csr_write_mideleg,       DIFF)   \
  M(arg, RAW,  mvendorid, 0xf11, MVENDORID_YSYX,    NULL,                    disable_write,           DIFF)   \
  M(arg, RAW,  marchid,   0xf12, MARCHID_YSYX,      NULL,                    disable_write,           DIFF)   \
  M(arg, RAW,  mhartid,   0xf14, 0,                 NULL,                    disable_write,           NODIFF) \
  M(arg, RAW,  mimpid,    0xf13, 0,                 NULL,                    disable_write,           NODIFF) \
  M(arg, RAW,  pmpaddr0,  0x3b0, 0,                 NULL,                    NULL,                    NODIFF) \
  M(arg, RAW,  pmpaddr1,  0x3b1, 0,                 NULL,                    NULL,                    NODIFF) \
  M(arg, RAW,  pmpaddr2,  0x3b2, 0,                 NULL,                    NULL,                    NODIFF) \
  M(arg, RAW,  pmpaddr3,  0x3b3, 0,                 NULL,                    NULL,                    NODIFF) \
  M(arg, RAW,  pmpaddr4,  0x3b4, 0,                 NULL,                    NULL,                    NODIFF) \
  M(arg, RAW,  pmpaddr5,  0x3b5, 0,                 NULL,                    NULL,                    NODIFF) \
  M(arg, RAW,  pmpaddr6,  0x3b6, 0,                 NULL,                    NULL,                    NODIFF) \
  M(arg, RAW,  pmpaddr7,  0x3b7, 0,                 NULL,                    NULL,                    NODIFF) \
  M(arg, RAW,  pmpcfg0,   0x3a0, 0,                 NULL,                    NULL,                    NODIFF) \
  M(arg, RAW,  pmpcfg1,   0x3a1, 0,                 NULL,                    NULL,                    NODIFF) \
  M(arg, RAW,  scause,    0x142, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  stval,     0x143, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  sscratch,  0x140, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  stvec,     0x105, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  mie,       0x304, 0,                 NULL,                    NULL,                    DIFF)   \
  M(arg, RAW,  mcounteren, 0x306, 0,                 csr_read_mcounteren,     csr_write_mcounteren,    NODIFF) \
  M(arg, RAW,  scounteren, 0x106, 0,                 csr_read_scounteren,     csr_write_scounteren,    NODIFF) \
  M(arg, RAW,  mcountinhibit, 0x320, 0,              csr_read_mcountinhibit,  csr_write_mcountinhibit, NODIFF) \
  M(arg, VIRT, cycle,     0xc00, 0,                 virt_csr_cycle_read,     virt_csr_cycle_write,    NODIFF) \
  M(arg, VIRT, time,      0xc01, 0,                 virt_csr_time_read,      virt_csr_time_write,     NODIFF) \
  M(arg, VIRT, instret,   0xc02, 0,                 virt_csr_instret_read,   virt_csr_instret_write,  NODIFF) \
  M(arg, VIRT, cycleh,    0xc80, 0,                 virt_csr_cycleh_read,    virt_csr_cycleh_write,   NODIFF) \
  M(arg, VIRT, timeh,     0xc81, 0,                 virt_csr_timeh_read,     virt_csr_timeh_write,    NODIFF) \
  M(arg, VIRT, instreth,  0xc82, 0,                 virt_csr_instreth_read,  virt_csr_instreth_write, NODIFF) \
  M(arg, VIRT, sie,       0x104, 0,                 virt_csr_sie_read,       virt_csr_sie_write,      NODIFF) \
  M(arg, VIRT, sip,       0x144, 0,                 virt_csr_sip_read,       virt_csr_sip_write,      NODIFF) \
  M(arg, VIRT, mip,       0x344, 0,                 virt_csr_mip_read,       virt_csr_mip_write,      NODIFF) \
  M(arg, VIRT, sstatus,   0x100, 0,                 virt_csr_sstatus_read,   virt_csr_sstatus_write,  NODIFF)
// clang-format on

#define CSR_EMIT_RAW(emit, kind, name, addr, reset, read, write, diff)         \
  CSR_EMIT_RAW_##kind(emit, name, addr)
#define CSR_EMIT_RAW_RAW(emit, name, addr) emit(name, addr)
#define CSR_EMIT_RAW_VIRT(emit, name, addr)

#define CSR_EMIT_VIRT(emit, kind, name, addr, reset, read, write, diff)        \
  CSR_EMIT_VIRT_##kind(emit, name, addr)
#define CSR_EMIT_VIRT_RAW(emit, name, addr)
#define CSR_EMIT_VIRT_VIRT(emit, name, addr) emit(name, addr)

#define CSR_EMIT_ALL(emit, kind, name, addr, reset, read, write, diff)         \
  emit(name, addr)

#define CSR_EMIT_DIFF(emit, kind, name, addr, reset, read, write, diff)        \
  CSR_EMIT_DIFF_##diff(emit, name)
#define CSR_EMIT_DIFF_DIFF(emit, name) emit(name)
#define CSR_EMIT_DIFF_NODIFF(emit, name)

#define CSR_EMIT_DESC(emit, kind, name, addr, reset, read, write, diff)        \
  emit(kind, name, addr, reset, read, write)

#define EACH_RAW_CSR(_) CSR_TABLE(CSR_EMIT_RAW, _)
#define EACH_VIRTUAL_CSR(_) CSR_TABLE(CSR_EMIT_VIRT, _)
#define EACH_DIFFTEST_CSR(_) CSR_TABLE(CSR_EMIT_DIFF, _)
#define EACH_CSR(_) CSR_TABLE(CSR_EMIT_ALL, _)
#define EACH_CSR_DESC(_) CSR_TABLE(CSR_EMIT_DESC, _)

#endif
