// ALU 路径评估：实例化 npc 真实的 ysyx_26030092_ALU（加法/移位/比较等）
// 输入端和输出端都插触发器，模拟真实的"寄存器到寄存器"路径
module adder_bench(
  input  clock,
  input  [3:0]  ctl,
  input  [31:0] src1,
  input  [31:0] src2,
  output [31:0] out_q
);

  reg [3:0]  ctl_q;
  reg [31:0] src1_q, src2_q;
  always @(posedge clock) begin
    ctl_q  <= ctl;
    src1_q <= src1;
    src2_q <= src2;
  end

  wire [31:0] alu_out;
  ysyx_26030092_ALU u_alu(
    .in_ctl  (ctl_q),
    .in_src1 (src1_q),
    .in_src2 (src2_q),
    .out     (alu_out)
  );

  reg [31:0] out_qr;
  always @(posedge clock) out_qr <= alu_out;
  assign out_q = out_qr;

endmodule
