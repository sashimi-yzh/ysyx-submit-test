`include "ysyx_26010007_defines.v"
module ysyx_26010007_EXU(
  // 握手信号
  input idu_valid,
  output exu_ready,
  output exu_valid,
  input lsu_ready,

  input [`WORD_WIDTH-1:0] idu_src1,
  input [`WORD_WIDTH-1:0] idu_src2,
  input [`ALU_OP_WIDTH-1:0] idu_alu_op,
  input idu_wreg,
  input [`REG_ADDR_WIDTH-1:0] idu_wa,
  input [7:0] idu_ls_inst,
  input [`WORD_WIDTH-1:0]       idu_store_data,

  output [`WORD_WIDTH-1:0]      exu_alu_res,
  output                        exu_wreg,
  output [`REG_ADDR_WIDTH-1:0]  exu_wa,
  output [7:0]                  exu_ls_inst,
  output [`WORD_WIDTH-1:0]      exu_store_data
);
  wire cin, carry;
  assign cin = idu_alu_op[3];

  wire [`WORD_WIDTH-1:0] src2 = {32{cin}} ^ idu_src2;

  wire [`WORD_WIDTH-1:0] add_res;
  
  assign {carry, add_res} = idu_src1 + src2 + {31'd0, cin};

  wire [`WORD_WIDTH-1:0] sltu_res = {31'b0, ~carry};
  wire [`WORD_WIDTH-1:0] slt_res = {31'b0, ((idu_src1[31] & ~idu_src2[31]) | ((idu_src1[31] ~^ idu_src2[31]) & add_res[31]))};
  
  wire [`WORD_WIDTH-1:0] xor_res = idu_src1 ^ idu_src2;
  wire [`WORD_WIDTH-1:0] or_res = idu_src1 | idu_src2;
  wire [`WORD_WIDTH-1:0] sll_res = idu_src1 << idu_src2[4:0];
  wire [`WORD_WIDTH-1:0] srl_res = idu_src1 >> idu_src2[4:0];
  wire [`WORD_WIDTH-1:0] sra_res = $signed(idu_src1) >>> idu_src2[4:0];
  wire [`WORD_WIDTH-1:0] and_res = idu_src1 & idu_src2;
  ysyx_26010007_MuxKeyWithDefault #(11, 4, `WORD_WIDTH) i0 (exu_alu_res, idu_alu_op, 0, {
    `ALU_ADD, add_res,
    `ALU_SUB, add_res,
    `ALU_SLTU, sltu_res,
    `ALU_SLT, slt_res,
    `ALU_SLL, sll_res,
    `ALU_SRL, srl_res,
    `ALU_SRA, sra_res,
    `ALU_XOR, xor_res,
    `ALU_OR, or_res,
    `ALU_AND, and_res,
    `ALU_B,   idu_src2
  });

  assign exu_wa = idu_wa;
  assign exu_wreg = idu_wreg;
  assign exu_ls_inst = idu_ls_inst;
  assign exu_store_data = idu_store_data;

  // 握手信号
  assign exu_valid = idu_valid;
  assign exu_ready = lsu_ready;

endmodule