`include "defines.v"
module EXU(
  input [`WORD_WIDTH-1:0] src1,
  input [`WORD_WIDTH-1:0] src2,
  input [`ALU_OP_WIDTH-1:0] alu_op,
  output [`WORD_WIDTH-1:0] alu_res
);

  wire [`WORD_WIDTH-1:0] add_res = src1 + src2;
  wire [`WORD_WIDTH-1:0] sub_res = src1 - src2;
  wire [`WORD_WIDTH-1:0] sltu_res = {31'b0, src1 < src2};
  wire [`WORD_WIDTH-1:0] slt_res = {31'b0, $signed(src1) < $signed(src2)};
  wire [`WORD_WIDTH-1:0] xor_res = src1 ^ src2;
  wire [`WORD_WIDTH-1:0] or_res = src1 | src2;
  wire [`WORD_WIDTH-1:0] sll_res = src1 << src2[4:0];
  wire [`WORD_WIDTH-1:0] srl_res = src1 >> src2[4:0];
  wire [`WORD_WIDTH-1:0] sra_res = $signed(src1) >>> src2[4:0];
  wire [`WORD_WIDTH-1:0] and_res = src1 & src2;
  MuxKeyWithDefault #(11, 4, `WORD_WIDTH) i0 (alu_res, alu_op, 0, {
    `ALU_ADD, add_res,
    `ALU_SUB, sub_res,
    `ALU_SLTU, sltu_res,
    `ALU_SLT, slt_res,
    `ALU_SLL, sll_res,
    `ALU_SRL, srl_res,
    `ALU_SRA, sra_res,
    `ALU_XOR, xor_res,
    `ALU_OR, or_res,
    `ALU_AND, and_res,
    `ALU_B,   src2
  });
endmodule