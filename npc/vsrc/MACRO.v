`define ALU_OP_ADD 4'b0000
`define ALU_OP_SUB 4'b0001
`define ALU_OP_AND 4'b0010
`define ALU_OP_OR  4'b0011
`define ALU_OP_XOR 4'b0100
`define ALU_OP_LT 4'b0101
`define ALU_OP_GE 4'b0110
`define ALU_OP_EQ 4'b0111
`define ALU_OP_SLL 4'b1000
`define ALU_OP_SRL 4'b1001
`define ALU_OP_SRA 4'b1010
`define ALU_OP_LTU 4'b1011
`define ALU_OP_GEU 4'b1100
`define ALU_OP_NE 4'b1101

`define WB_SEL_IMM 3'b000
`define WB_SEL_ALU 3'b001
`define WB_SEL_MEM 3'b010
`define WB_SEL_PC4 3'b011
`define WB_SEL_CSR 3'b100

`define OP_WIDTH_BYTE 2'b00
`define OP_WIDTH_HALF 2'b01
`define OP_WIDTH_WORD 2'b10

`define ALU_SEL_RS1 2'b00
`define ALU_SEL_PC 2'b01

`define ALU_SEL_RS2 2'b00
`define ALU_SEL_IMM 2'b01
`define ALU_SEL_CSR 2'b10

`define PC_NORMAL 3'b000
`define PC_NEAR 3'b001
`define PC_FAR 3'b010
`define PC_BRANCH 3'b011
`define PC_MRET 3'b100

`define CSR_SEL_RS1 1'b0
`define CSR_SEL_ALU 1'b1

