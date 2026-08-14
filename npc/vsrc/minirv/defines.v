`define ALU_ADD     4'b0000
`define ALU_SUB     4'b1000
`define ALU_SLL     4'b0001
`define ALU_SLT     4'b0010
`define ALU_SLTU    4'b1010
`define ALU_B       4'b0011
`define ALU_XOR     4'b0100
`define ALU_SRL     4'b0101
`define ALU_SRA     4'b1101
`define ALU_OR      4'b0110
`define ALU_AND     4'b0111

`define WORD_WIDTH      32
`define ALU_OP_WIDTH    4

`define INST_DATA_WIDTH 32
`define INST_ADDR_WIDTH 32
`define DATA_DATA_WIDTH 32
`define DATA_ADDR_WIDTH 32

`define REG_ADDR_WIDTH  4
`define REG_DATA_WIDTH  32

`define INIT_PC         32'h80000000
`define ZERO_WORD       32'h0