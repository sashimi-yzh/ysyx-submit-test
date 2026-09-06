#ifndef __CSR_MISA_H__
#define __CSR_MISA_H__

#define MISA_MXL_RV32 (1u << 30)

#define MISA_EXT_A (1u << ('A' - 'A'))
#define MISA_EXT_C (1u << ('C' - 'A'))
#define MISA_EXT_I (1u << ('I' - 'A'))
#define MISA_EXT_M (1u << ('M' - 'A'))
#define MISA_EXT_S (1u << ('S' - 'A'))
#define MISA_EXT_U (1u << ('U' - 'A'))

#define MISA_RV32_IMAC_SU                                                      \
  (MISA_MXL_RV32 | MISA_EXT_I | MISA_EXT_M | MISA_EXT_A | MISA_EXT_C |        \
   MISA_EXT_S | MISA_EXT_U)

#endif
