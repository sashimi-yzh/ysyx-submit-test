#include <common.h>

#define LIST_SRC_C(WITH, _) \
  _(WITH, CR) \
  _(WITH, CI) \
  _(WITH, CSS) \
  _(WITH, CIW) \
  _(WITH, CL) \
  _(WITH, CS) \
  _(WITH, CA) \
  _(WITH, CB) \
  _(WITH, CJ)

#define LIST_IMM_C(WITH, _) \
  _(WITH, CNONE) \
  _(WITH, CLWSP) \
  _(WITH, CSWSP) \
  _(WITH, CLSW) \
  _(WITH, CJ) \
  _(WITH, CB) \
  _(WITH, CLIADDI) \
  _(WITH, CLUI) \
  _(WITH, CADDI16SP) \
  _(WITH, CADDI4SPN)

#define CMD_MAP_ENUM_C(A, B) TYPE_ ## A ## _ ## B,
#define WRAP_MAP_ENUM_C(W, T) W(T, CMD_MAP_ENUM_C)
#define GEN_MAP_ENUM_C LIST_SRC_C(LIST_IMM_C, WRAP_MAP_ENUM_C)

#define CMD_MAP_CASE_C(A, B) case TYPE_ ## A ## _ ## B: src##A(); imm##B(); break;
#define WRAP_MAP_CASE_C(W, T) W(T, CMD_MAP_CASE_C)
#define GEN_MAP_CASE_C LIST_SRC_C(LIST_IMM_C, WRAP_MAP_CASE_C)

#define immCNONE()
#define immCLWSP() do { \
  *imm = (BITS(i, 3, 2) << 6) | \
         (BITS(i, 12, 12) << 5) | \
         (BITS(i, 6, 4) << 2); \
} while(0)
#define immCSWSP() do { \
  *imm = (BITS(i, 8, 7) << 6) | \
         (BITS(i, 12, 9) << 2); \
} while(0)
#define immCLSW() do { \
  *imm = (BITS(i, 5, 5) << 6) | \
         (BITS(i, 12, 10) << 3) | \
         (BITS(i, 6, 6) << 2); \
} while(0)
#define immCJ() do { \
  *imm = SEXT((BITS(i, 12, 12) << 11) | \
              (BITS(i, 8, 8) << 10) | \
              (BITS(i, 10, 9) << 8) | \
              (BITS(i, 6, 6) << 7) | \
              (BITS(i, 7, 7) << 6) | \
              (BITS(i, 2, 2) << 5) | \
              (BITS(i, 11, 11) << 4) | \
              (BITS(i, 5, 3) << 1), 12); \
} while(0)
#define immCB() do { \
  *imm = SEXT((BITS(i, 12, 12) << 8) | \
              (BITS(i, 6, 5) << 6) | \
              (BITS(i, 2, 2) << 5) | \
              (BITS(i, 11, 10) << 3) | \
              (BITS(i, 4, 3) << 1), 9); \
} while(0)
#define immCLIADDI() do { \
  *imm = SEXT((BITS(i, 12, 12) << 5) | \
              (BITS(i, 6, 2)), 6); \
} while(0)
#define immCLUI() do { \
  *imm = SEXT((BITS(i, 12, 12) << 17) | \
              (BITS(i, 6, 2) << 12), 18); \
} while(0)
#define immCADDI16SP() do { \
  *imm = SEXT((BITS(i, 12, 12) << 9) | \
              (BITS(i, 4, 3) << 7) | \
              (BITS(i, 5, 5) << 6) | \
              (BITS(i, 2, 2) << 5) | \
              (BITS(i, 6, 6) << 4), 10); \
} while(0)
#define immCADDI4SPN() do { \
  *imm = (BITS(i, 10, 7) << 6) | \
         (BITS(i, 12, 11) << 4) | \
         (BITS(i, 5, 5) << 3) | \
         (BITS(i, 6, 6) << 2); \
} while(0)

#define reg1C_RD_RS1() do { \
  *rs1 = BITS(i, 11, 7); \
  *rd = *rs1; \
  src1R(); \
} while(0)
#define reg1C_RS1_P() do { \
  *rs1 = 8u | BITS(i, 9, 7); \
  src1R(); \
} while(0)
#define reg1C_RD_RS1_P() do { \
  *rs1 = 8u | BITS(i, 9, 7); \
  *rd = *rs1; \
  src1R(); \
} while(0)
#define reg2C_RS2() do { \
  *rs2 = BITS(i, 6, 2); \
  src2R(); \
} while(0)
#define reg2C_RD_P() do { \
  *rd = 8u | BITS(i, 4, 2); \
} while(0)
#define reg2C_RS2_P() do { \
  *rs2 = 8u | BITS(i, 4, 2); \
  src2R(); \
} while(0)

#define srcCR() do { \
  reg1C_RD_RS1(); \
  reg2C_RS2(); \
} while(0);
#define srcCI() do { \
  reg1C_RD_RS1(); \
} while(0);
#define srcCSS() do { \
  reg2C_RS2(); \
} while(0);
#define srcCIW() do { \
  reg2C_RD_P(); \
} while(0);
#define srcCL() do { \
  reg1C_RS1_P(); \
  reg2C_RD_P(); \
} while(0);
#define srcCS() do { \
  reg1C_RS1_P(); \
  reg2C_RS2_P(); \
} while(0);
#define srcCA() do { \
  reg1C_RD_RS1_P(); \
  reg2C_RS2_P(); \
} while(0);
#define srcCB() do { \
  reg1C_RD_RS1_P(); \
} while(0);
#define srcCJ() ;
