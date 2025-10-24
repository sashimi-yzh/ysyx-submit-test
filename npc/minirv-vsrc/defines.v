//译码模块(指令)
`define INST_TYPE_LUI     5'b01101//U
`define INST_TYPE_JALR    5'b11001
`define INST_TYPE_S       5'b01000
`define INST_TYPE_R       5'b01100
`define INST_TYPE_L       5'b00000
`define INST_TYPE_I       5'b00100
`define INST_TYPE_E       5'b11100

`define INST_LUI       7'b01101_11
`define INST_JALR      7'b11001_11
`define INST_LW        7'b00000_11

`define INST_R         7'b01100_11
`define INST_I         7'b00100_11

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

// ALU 操作码
`define ALU_ADD    4'b0000

//Mem字节选取
`define Mem_Word   3'b010
`define Mem_Half   3'b001
`define Mem_UHalf  3'b011
`define Mem_UBit   3'b000
`define Mem_Bit    3'b100