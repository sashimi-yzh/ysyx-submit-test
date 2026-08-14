`include "defines.v"
module EXU(
  input [`WORD_WIDTH-1:0] src1,
  input [`WORD_WIDTH-1:0] src2,
  input [`ALU_OP_WIDTH-1:0] alu_op,
  output [`WORD_WIDTH-1:0] alu_res
);

  wire [`WORD_WIDTH-1:0] add_res = src1 + src2;
  wire [`WORD_WIDTH-1:0] sltu_res = src1 < src2;
  wire [`WORD_WIDTH-1:0] xor_res = src1 & src2;
  wire [`WORD_WIDTH-1:0] or_res = src1 | src2;
  MuxKeyWithDefault #(5, 4, `WORD_WIDTH) i0 (alu_res, alu_op, 0, {
    `ALU_ADD, add_res,
    `ALU_SLTU, sltu_res,
    `ALU_XOR, xor_res,
    `ALU_OR, or_res,
    `ALU_B,   src2
  });
endmodule