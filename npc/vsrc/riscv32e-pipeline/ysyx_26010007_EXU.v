`include "ysyx_26010007_defines.v"
module ysyx_26010007_EXU(
`ifdef ysyx_26010007_debug
  output wire [`ysyx_26010007_WORD_WIDTH-1:0] debug_exu_jaddr,
`endif
  // 握手信号
  input                     exu_valid_i,
  output                    exu_ready_i,
  output                    exu_valid_o,
  input                     exu_ready_o,

  input [`ysyx_26010007_WORD_WIDTH-1:0]   exu_SrcA,
  input [`ysyx_26010007_WORD_WIDTH-1:0]   exu_SrcB,
  input [`ysyx_26010007_ALU_OP_WIDTH-1:0] exu_ALU_OP,
  input [`ysyx_26010007_WORD_WIDTH-1:0]   exu_pc,
  input [`ysyx_26010007_WORD_WIDTH-1:0]   exu_plusImm,
  input [1:0]               exu_jump_op,

  output [`ysyx_26010007_WORD_WIDTH-1:0] res,
  output jump_flag,
  output [`ysyx_26010007_WORD_WIDTH-1:0] jump_addr
);
  wire [`ysyx_26010007_WORD_WIDTH-1:0] add_res;
  wire carry, zero, overflow;
  ysyx_26010007_AddSuber ysyx_26010007_AddSuber0(
    .A(exu_SrcA),
    .B(exu_SrcB),
    .Sub(exu_ALU_OP[3]),
    .Result(add_res),
    .Carry(carry),
    .Zero(zero),
    .Overflow(overflow)
  );

  wire [`ysyx_26010007_WORD_WIDTH-1:0] sltu_res = {31'b0, ~carry};
  wire [`ysyx_26010007_WORD_WIDTH-1:0] slt_res = {31'b0, add_res[31] ^ overflow};
  
  wire [`ysyx_26010007_WORD_WIDTH-1:0] xor_res = exu_SrcA ^ exu_SrcB;
  wire [`ysyx_26010007_WORD_WIDTH-1:0] and_res = exu_SrcA & exu_SrcB;
  wire [`ysyx_26010007_WORD_WIDTH-1:0] or_res = exu_SrcA | exu_SrcB;

  wire [`ysyx_26010007_WORD_WIDTH-1:0] srl_res = exu_SrcA >> exu_SrcB[4:0];
  wire [`ysyx_26010007_WORD_WIDTH-1:0] sra_res = $signed(exu_SrcA) >>> exu_SrcB[4:0];
  wire [`ysyx_26010007_WORD_WIDTH-1:0] sll_res = exu_SrcA << exu_SrcB[4:0];

  wire [`ysyx_26010007_WORD_WIDTH-1:0] alu_res;
  ysyx_26010007_MuxKeyWithDefault #(11, 4, `ysyx_26010007_WORD_WIDTH) i0 (alu_res, exu_ALU_OP[3:0], 0, {
    `ysyx_26010007_ALU_ADD, add_res,
    `ysyx_26010007_ALU_SUB, add_res,
    `ysyx_26010007_ALU_SLTU, sltu_res,
    `ysyx_26010007_ALU_SLT, slt_res,
    `ysyx_26010007_ALU_SLL, sll_res,
    `ysyx_26010007_ALU_SRL, srl_res,
    `ysyx_26010007_ALU_SRA, sra_res,
    `ysyx_26010007_ALU_XOR, xor_res,
    `ysyx_26010007_ALU_OR, or_res,
    `ysyx_26010007_ALU_AND, and_res,
    `ysyx_26010007_ALU_LUI, exu_SrcB
  });

  wire beq_result = zero;
  wire bne_result = ~zero;
  wire blt_result = slt_res[0]; // 负数 < 正数 | 同号，相减结果为负数
  wire bltu_result = ~carry;
  wire bge_result = ~slt_res[0];
  wire bgeu_result = carry;
  // branch
  wire isTrue;
  ysyx_26010007_MuxKeyWithDefault #(6, 4, 1) i1 (isTrue, exu_ALU_OP[3:0], 1'b0, {
    `ysyx_26010007_ALU_BEQ, beq_result,
    `ysyx_26010007_ALU_BNE, bne_result,
    `ysyx_26010007_ALU_BLT, blt_result,
    `ysyx_26010007_ALU_BLTU, bltu_result,
    `ysyx_26010007_ALU_BGE, bge_result,
    `ysyx_26010007_ALU_BGEU, bgeu_result
  });
  wire jal_inst = exu_jump_op == 2'b10;
  assign jump_addr = isTrue | jal_inst ? exu_plusImm : (add_res & 32'hfffffffe);
  assign jump_flag = exu_jump_op[1] | (isTrue & exu_ALU_OP[4]);

  assign res = exu_jump_op[1] ? exu_pc + 32'd4 : alu_res;

  // 握手信号
  assign exu_valid_o = exu_valid_i;
  assign exu_ready_i = exu_ready_o;
`ifdef ysyx_26010007_debug
  assign debug_exu_jaddr = jump_flag ? jump_addr : exu_pc + 32'd4;
`endif
endmodule

module ysyx_26010007_AddSuber #(
  parameter DATA_LEN = 32,
  parameter Adder_LookAhead_len = 8,
  parameter Adder_LookAhead_num = 4
)(
  input                   [DATA_LEN-1 : 0]        A, B,
  input                                           Sub,
  output                  [DATA_LEN-1 : 0]        Result,
  output                                          Carry,
  output                                          Zero,
  output                                          Overflow
);
wire [DATA_LEN-1:0] t_no_Cin;
assign {Carry, Result}= t_no_Cin + A + {31'd0, Sub};

assign Zero = ~(|Result);
assign t_no_Cin = {DATA_LEN{ Sub }}^B;
assign Overflow = (A[DATA_LEN-1] ~^ t_no_Cin[DATA_LEN-1]) & (Result [DATA_LEN-1] ^ A[DATA_LEN-1]);
endmodule