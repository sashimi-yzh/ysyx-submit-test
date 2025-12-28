`define OP_ADD         4'b0000 // +
`define OP_SUB         4'b0001 // -
`define OP_SLL         4'b0010 // <<
`define OP_SLT         4'b0011 // <
`define OP_XOR         4'b0100 // ^
`define OP_SRL         4'b0101 // >>
`define OP_SRA         4'b0110 // >>>
`define OP_OR          4'b0111 // |
`define OP_AND         4'b1000 // &
`define OP_MU          4'b1001 // *
`define OP_DIV         4'b1010 // /
`define OP_REM         4'b1011 // %
`define OP_BGE         4'b1100 // >=
`define OP_BNE         4'b1101 // !=
`define OP_BEQ         4'b1110 // ==
`define MUL_H          4'b1111 // *

`define BEQ_FUNCT3         3'b000
`define BNE_FUNCT3         3'b001
`define BLT_FUNCT3         3'b100
`define BGE_FUNCT3         3'b101
`define BLTU_FUNCT3        3'b110
`define BGEU_FUNCT3        3'b111

`define ADDI_FUNCT3         3'b000
`define SLLI_FUNCT3         3'b001
`define SLTI_FUNCT3         3'b010
`define SLTIU_FUNCT3        3'b011
`define XORI_FUNCT3         3'b100
`define SRLI_SRAI_FUNCT3    3'b101
`define ORI_FUNCT3          3'b110
`define ANDI_FUNCT3         3'b111

`define SUB_ADD_MUL_FUNCT3         3'b000
`define SLL_MULH_FUNCT3            3'b001
`define SLT_FUNCT3                 3'b010
`define SLTU_MULHU_FUNCT3          3'b011
`define XOR_DIV_FUNCT3             3'b100
`define SRL_SRA_DIVU_FUNCT3        3'b101
`define OR_REM_FUNCT3              3'b110
`define AND_REMU_FUNCT3            3'b111


  


//wire srai = (I_type_1 && funct3 == 3'b101 && funct7 == 7'b0100000);
//wire sltiu= (I_type_1 && funct3 == 3'b011);
//wire slti = (I_type_1 && funct3 == 3'b010);
//wire srli = (I_type_1 && funct3 == 3'b101 && funct7 == 7'b0000000);
//wire slli = (I_type_1 && funct3 == 3'b001 && funct7 == 7'b0000000);
// 
