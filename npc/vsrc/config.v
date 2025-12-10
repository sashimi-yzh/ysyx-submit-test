// 操作部件相关宏定义
`define ysyx_25050136_ALU_OP_NUM 11
`define ysyx_25050136_ALU_ADD    4'd1
`define ysyx_25050136_ALU_SUB    4'd2
`define ysyx_25050136_ALU_XOR    4'd3
`define ysyx_25050136_ALU_OR     4'd4
`define ysyx_25050136_ALU_AND    4'd5
`define ysyx_25050136_ALU_SLTU   4'd6
`define ysyx_25050136_ALU_SLT    4'd7
`define ysyx_25050136_ALU_SRA    4'd8
`define ysyx_25050136_ALU_SLL    4'd9
`define ysyx_25050136_ALU_SRL    4'd10
`define ysyx_25050136_ALU_OPD2   4'd11


`define ysyx_25050136_CSRU_OP_NUM 5
`define ysyx_25050136_CSRU_CSRRW  0
`define ysyx_25050136_CSRU_CSRRS  1
`define ysyx_25050136_CSRU_CSRRC  2
`define ysyx_25050136_CSRU_MRET   3
`define ysyx_25050136_CSRU_ECALL  4

`ifdef YSYXSOC
`define ysyx_25050136_DBG_NUM 5
`define ysyx_25050136_DBG_EBREAK 0
`define ysyx_25050136_DBG_ALU  1
`define ysyx_25050136_DBG_CSRU 2
`define ysyx_25050136_DBG_LSU  3
`define ysyx_25050136_DBG_BQU  4
`endif
