// 寄存器堆读路径评估：实例化 npc 真实的 RegBlackBox（1 写 2 读 DFF 寄存器堆）
// 输入端和输出端都插触发器，模拟真实的"寄存器到寄存器"路径
module rf_bench(
  input  clock,
  input  [31:0] wdata,
  input  [4:0]  waddr,
  input         wen,
  input  [4:0]  raddr1,
  input  [4:0]  raddr2,
  output [31:0] rdata1_q,
  output [31:0] rdata2_q
);

  reg [31:0] wdata_q;
  reg [4:0]  waddr_q;
  reg        wen_q;
  reg [4:0]  raddr1_q;
  reg [4:0]  raddr2_q;
  always @(posedge clock) begin
    wdata_q  <= wdata;
    waddr_q  <= waddr;
    wen_q    <= wen;
    raddr1_q <= raddr1;
    raddr2_q <= raddr2;
  end

  wire [31:0] rdata1, rdata2;
  RegBlackBox u_rf(
    .clock  (clock),
    .wdata  (wdata_q),
    .waddr  (waddr_q),
    .wen    (wen_q),
    .raddr1 (raddr1_q),
    .rdata1 (rdata1),
    .raddr2 (raddr2_q),
    .rdata2 (rdata2)
  );

  reg [31:0] rdata1_qr, rdata2_qr;
  always @(posedge clock) begin
    rdata1_qr <= rdata1;
    rdata2_qr <= rdata2;
  end
  assign rdata1_q = rdata1_qr;
  assign rdata2_q = rdata2_qr;

endmodule
