module ysyx_25010008_EXU (
    input clock,
    input reset,

    input block,

    input decode_valid,
    output reg execute_valid,
    input [31:0] idu_pc,
    output reg [31:0] exu_pc,
    input [1:0] npc_sel,

    input [31:0] imm,

    input [31:0] src1,
    input [31:0] src2,
    input [ 1:0] exu_r_wdata_sel,

    input [31:0] csr_src,
    input [ 1:0] csr_src_sel,

    input  [ 7:0] alu_opcode,
    input  [ 1:0] alu_operand1_sel,
    input  [ 3:0] alu_operand2_sel,
    output [31:0] alu_result,

    input [31:0] forward_data,
    output reg [31:0] wsrc,

    output reg [31:0] exu_npc,

    output reg [31:0] exu_r_wdata,
    output reg [31:0] csr_wdata,

    input clear_pipeline,
    output reg is_wrong_prediction
);

  reg [ 7:0] opcode;
  reg [31:0] operand1;
  reg [31:0] operand2;

  ysyx_25010008_ALU alu (
      .opcode  (opcode),
      .operand1(operand1),
      .operand2(operand2),
      .result  (alu_result)
  );

  reg [31:0] snpc;
  reg [31:0] dnpc;
  reg [ 1:0] npc_sel_buffer;
  reg [ 1:0] exu_r_wdata_sel_buffer;
  reg [31:0] csr_src_buffer;
  reg [31:0] exu_npc_buffer;

  always @(*) begin
    case (npc_sel_buffer)
      2'b00: exu_npc_buffer = snpc;
      2'b01: exu_npc_buffer = dnpc;  // jal
      2'b10: exu_npc_buffer = alu_result & (~32'b1);  // jalr
      2'b11: exu_npc_buffer = alu_result[0] ? dnpc : snpc;  // branch
    endcase
  end

  always @(*) begin
    case (exu_r_wdata_sel_buffer)
      2'b00: exu_r_wdata = alu_result;
      2'b01: exu_r_wdata = snpc;  // jal jalr
      2'b10: exu_r_wdata = dnpc;  // auipc 
      2'b11: exu_r_wdata = csr_src_buffer;  // csrrw csrrs csrrc
    endcase
  end

  wire [31:0] src2_tmp = alu_operand2_sel[2] ? exu_r_wdata : alu_operand2_sel[3] ? forward_data : src2;
  wire [31:0] csr_src_tmp = csr_src_sel[0] ? alu_result : csr_src_sel[1] ? csr_wdata : csr_src;

  always @(posedge clock) begin
    if (reset | clear_pipeline) begin
      execute_valid <= 0;
      is_wrong_prediction <= 0;
    end else begin
      if (!block) begin
        execute_valid <= decode_valid;
        is_wrong_prediction <= execute_valid && npc_sel_buffer != 0;

        opcode <= alu_opcode;
        operand1 <= alu_operand1_sel[0] ? exu_r_wdata : alu_operand1_sel[1] ? forward_data : src1;
        operand2 <= alu_operand2_sel[0] ? imm : alu_operand2_sel[1] ? csr_src_tmp : src2_tmp;

        snpc <= idu_pc + 4;
        dnpc <= idu_pc + imm;

        exu_pc <= idu_pc;
        exu_npc <= exu_npc_buffer;

        wsrc <= src2_tmp;

        npc_sel_buffer <= npc_sel;

        csr_src_buffer <= csr_src_tmp;

        exu_r_wdata_sel_buffer <= exu_r_wdata_sel;

        csr_wdata <= alu_result;
      end
    end
  end

endmodule
