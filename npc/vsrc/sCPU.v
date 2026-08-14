module sCPU (
  input clk,
  input rst,

  output [6:0] seg0,
  output [6:0] seg1
);

reg [7:0] inst_rom [15:0];
initial begin
  $readmemb("resource/sCPU_inst_rom.hex", inst_rom);
end

reg [3:0] pc;
reg [7:0] regs [3:0];

wire branch_flag;
wire [3:0] branch_target;
wire [3:0] pc_next = branch_flag ? branch_target : pc + 1;
always @(posedge clk) begin
  if(rst) pc <= 0;
  else pc <= pc_next;
end

wire [7:0] inst = inst_rom[pc];

wire inst_add = ~inst[7] & ~inst[6];
wire inst_li = inst[7] & ~inst[6];
wire inst_bner0 = inst[7] & inst[6];
wire inst_out = ~inst[7] & inst[6];

wire [1:0] rd = inst[5:4];
wire [1:0] rs1 = inst[3:2];
wire [1:0] rs2 = inst[1:0];
wire [3:0] imm = inst[3:0];
wire [3:0] addr = inst[5:2];

assign branch_flag = inst_bner0 & (|(regs[0] ^ regs[rs2]));
assign branch_target = addr;

wire we = inst_add | inst_li;
wire [7:0] wdata = inst_add ? (regs[rs1] + regs[rs2]) : {4'd0, imm};

always @(posedge clk) begin
  if(rst) begin
    regs[0] <= 0;
    regs[1] <= 0;
    regs[2] <= 0;
    regs[3] <= 0;
  end
  else if(we) begin
    regs[rd] <= wdata;
  end
end

// out 指令产生的效果是持续性的，直到下一个 out 指令到来或复位才会改变
reg [3:0] seg0_data;
reg [3:0] seg1_data;
always @(posedge clk) begin
  if(rst) begin
    seg0_data <= 0;
    seg1_data <= 0;
  end
  else if(inst_out) begin
    seg0_data <= regs[rs1][3:0];
    seg1_data <= regs[rs1][7:4];
  end
end

x7seg x7seg0(seg0_data, seg0);
x7seg x7seg1(seg1_data, seg1);

endmodule