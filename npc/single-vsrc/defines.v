//译码模块(指令)
`define INST_TYPE_LUI     5'b01101//U
`define INST_TYPE_AUIPC   5'b00101//U
`define INST_TYPE_JAL     5'b11011
`define INST_TYPE_JALR    5'b11001
`define INST_TYPE_S       5'b01000
`define INST_TYPE_B       5'b11000
`define INST_TYPE_R       5'b01100
`define INST_TYPE_L       5'b00000
`define INST_TYPE_I       5'b00100
`define INST_TYPE_E       5'b11100
`define INST_TYPE_CSR     5'b10011

`define INST_LUI       7'b01101_11
`define INST_AUIPC     7'b00101_11
`define INST_JAL       7'b11011_11
`define INST_JALR      7'b11001_11
`define INST_LW        7'b00000_11
`define INST_CSR       7'b11100_11

`define INST_B         7'b11000_11
`define INST_R         7'b01100_11
`define INST_I         7'b00100_11

`define INST_ECALL        32'h00000073 
`define INST_MRET         32'h30200073
//ebreak
`define INST_EBREAK       32'h00100073
`define HIT_TRAP          1
`define ABORT             2

//funct3值定义
`define F3_ADDI    3'b000
`define F3_SLTI    3'b010
`define F3_SLTU    3'b011
`define F3_ANDI    3'b111
`define F3_ORI     3'b110
`define F3_BEQ     3'b000
`define F3_BNE     3'b001
`define F3_BLT     3'b100
`define F3_BLTU    3'b110
`define F3_BGE     3'b101

`define F3_RSH   3'b101
`define F3_LSH   3'b001
`define F3_XORI  3'b100
`define F3_SLT   3'b010
`define F3_LW    3'b010
`define F3_LH    3'b001
`define F3_LBU   3'b100
`define F3_LB    3'b000
`define F3_SW    3'b010
`define F3_SH    3'b001
`define F3_SB    3'b000
`define F3_LHU   3'b101
`define F3_BGEU  3'b111

`define F3_CSRRW  3'b001
`define F3_CSRRS  3'b010
`define F3_CSRRC  3'b011
`define F3_CSRRWI 3'b101
`define F3_CSRRSI 3'b110
`define F3_CSRRCI 3'b111
`define F3_ECALL  3'b000

// ALU 操作码
`define ALU_ADD    4'b0000
`define ALU_SUB    4'b0001
`define ALU_AND    4'b0010
`define ALU_OR     4'b0011
`define ALU_XOR    4'b0100//xor,xori
`define ALU_SLL    4'b0101//sll,slli
`define ALU_SLTU   4'b0110//sltiu,sltu
`define ALU_SLT    4'b0111
`define ALU_SRA    4'b1000//sra,srai
`define ALU_SRL    4'b1001//srl,srli

//Mem字节选取
`define Mem_Word   3'b010
`define Mem_Half   3'b001
`define Mem_UHalf  3'b011
`define Mem_UBit   3'b000
`define Mem_Bit    3'b100
// `define Mem_Word   2'b10
// `define Mem_Half   2'b01
// `define Mem_UHalf  2'b11
// `define Mem_Bit    2'b00

//CSR操作码
`define CSR_CSRRW 2'b01
`define CSR_CSRRS 2'b10
`define CSR_CSRRC 2'b11
`define CSR_NONE  2'b00