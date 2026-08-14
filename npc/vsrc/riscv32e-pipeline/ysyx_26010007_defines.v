
`ifdef __ICARUS__
`define ysyx_26010007_INIT_PC     32'h80000000
`elsif  SYNTHESIS 
`define ysyx_26010007_INIT_PC     32'h80000000
`else 
`define ysyx_26010007_INIT_PC     32'h30000000
`endif 

`define ysyx_26010007_ALU_ADD     4'b0000
`define ysyx_26010007_ALU_SUB     4'b1000
`define ysyx_26010007_ALU_AND     4'b0111
`define ysyx_26010007_ALU_OR      4'b0110
`define ysyx_26010007_ALU_XOR     4'b0100
`define ysyx_26010007_ALU_SLL     4'b0001
`define ysyx_26010007_ALU_SRL     4'b0101
`define ysyx_26010007_ALU_SRA     4'b1101
`define ysyx_26010007_ALU_SLT     4'b1010
`define ysyx_26010007_ALU_SLTU    4'b1011
`define ysyx_26010007_ALU_LUI     4'b0010

`define ysyx_26010007_ALU_BEQ     4'b1000
`define ysyx_26010007_ALU_BNE     4'b1001
`define ysyx_26010007_ALU_BLT     4'b1100
`define ysyx_26010007_ALU_BLTU    4'b1110
`define ysyx_26010007_ALU_BGE     4'b1101
`define ysyx_26010007_ALU_BGEU    4'b1111

// 数据宽度
`define ysyx_26010007_WORD_WIDTH      32
`define ysyx_26010007_PADDR_WIDTH     32
`define ysyx_26010007_ALU_OP_WIDTH    5
`define ysyx_26010007_REG_ADDR_WIDTH  4
`define ysyx_26010007_CSR_ADDR_WIDTH  12
`define ysyx_26010007_EXC_EVENT_WIDTH 2
`define ysyx_26010007_MEMMASK_WIDTH   5

`define ysyx_26010007_ZERO_WORD       32'h0
`define ysyx_26010007_NOP_INST        32'b00000000000000000000000000010011

`define ysyx_26010007_INST_NOP        32'h00000013

// `define ysyx_26010007_CSR_MCYCLE      12'hb00
// `define ysyx_26010007_CSR_MCYCLEH     12'hb80
`define ysyx_26010007_CSR_MVENDORID   12'hf11
`define ysyx_26010007_CSR_MARCHID     12'hf12
`define ysyx_26010007_CSR_MSTATUS     12'h300
`define ysyx_26010007_CSR_MEPC        12'h341
`define ysyx_26010007_CSR_MCAUSE      12'h342
`define ysyx_26010007_CSR_MTVEC       12'h305

`define ysyx_26010007_EXC_ECALL       2'b01
`define ysyx_26010007_EXC_MRET        2'b10

`define ysyx_26010007_SRAM_ADDR_START 32'h80000000
`define ysyx_26010007_SRAM_ADDR_END   32'h87ffffff

`define ysyx_26010007_UART_ADDR_START 32'h10000000
`define ysyx_26010007_UART_ADDR_END   32'h10000fff

`define ysyx_26010007_CLINT_ADDR_START 32'h0200_0000
`define ysyx_26010007_CLINT_ADDR_END   32'h0200_ffff

`define ysyx_26010007_CLINT_ADDR_START_LOW 32'h0200_0000
`define ysyx_26010007_CLINT_ADDR_START_HIGH 32'h0200_0004
