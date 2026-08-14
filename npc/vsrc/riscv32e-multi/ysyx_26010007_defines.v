// `define debug

`define ALU_ADD     4'b0000
`define ALU_SUB     4'b1000
`define ALU_SLL     4'b0001
`define ALU_SLT     4'b1010
`define ALU_SLTU    4'b1011
`define ALU_B       4'b0011
`define ALU_XOR     4'b0100
`define ALU_SRL     4'b0101
`define ALU_SRA     4'b1101
`define ALU_OR      4'b0110
`define ALU_AND     4'b0111

// 数据宽度
`define WORD_WIDTH      32
`define PADDR_WIDTH     32
`define ALU_OP_WIDTH    4
`define REG_ADDR_WIDTH  4
`define CSR_ADDR_WIDTH  12
`define EXC_EVENT_WIDTH 2

`define ZERO_WORD       32'h0
`define NOP_INST        32'b00000000000000000000000000010011

`define INIT_PC         32'h30000000

`define CSR_MCYCLE      12'hb00
`define CSR_MCYCLEH     12'hb80
`define CSR_MVENDORID   12'hf11
`define CSR_MARCHID     12'hf12
`define CSR_MSTATUS     12'h300
`define CSR_MEPC        12'h341
`define CSR_MCAUSE      12'h342
`define CSR_MTVEC       12'h305

`define EXC_ECALL       2'b01
`define EXC_MRET        2'b10

`define SRAM_ADDR_START 32'h80000000
`define SRAM_ADDR_END   32'h87ffffff

`define UART_ADDR_START 32'h10000000
`define UART_ADDR_END   32'h10000fff

`define CLINT_ADDR_START 32'h0200_0000
`define CLINT_ADDR_END   32'h0200_ffff
