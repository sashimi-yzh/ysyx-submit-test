//lui
`define OPT_U_LUI 7'b0110111

//auipc
`define OPT_U_AUIPC 7'b0010111

//jal
`define OPT_J_JAL 7'b1101111

//jalr
`define OPT_I_JALR 7'b1100111

//beq, bne, blt, bge, bltu, bgeu
`define OPT_B 7'b1100011

//lb, lh, lw, lbu, lhu
`define OPT_I_LOAD 7'b0000011

//sb, sh, sw
`define OPT_S_STORE 7'b0100011

//addi, slti, sltiu, xori, ori, andi, slli，srli, srai
`define OPT_I_LOGIC 7'b0010011 

//add, sub, sll, slt, sltu, xor, srl, sra, or, and
`define OPT_R_LOGIC 7'b0110011

//fence, fence.i
`define OPT_I_FENCE 7'b0001111

//ecall, ebreak, csrrw, csrrs, csrrc, csrrwi, csrrsi, csrrci
`define OPT_I_EC 7'b1110011

`define FUNC_ADD 4'b0000
`define FUNC_SUB 4'b0001
`define FUNC_AND 4'b0010
`define FUNC_OR  4'b0011
`define FUNC_XOR 4'b0100
`define FUNC_NOR 4'b0101
`define FUNC_LESS 4'b0110
`define FUNC_LESS_SIGN 4'b0111
`define FUNC_BGE 4'b1000
`define FUNC_BGE_SIGN 4'b1001
`define FUNC_EQ 4'b1010
`define FUNC_NEQ 4'b1011
`define FUNC_SH_L 4'b1100
`define FUNC_SH_R 4'b1101
`define FUNC_SH_AR 4'b1110