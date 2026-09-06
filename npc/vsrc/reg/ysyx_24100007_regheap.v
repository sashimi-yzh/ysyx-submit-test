module ysyx_24100007_regheap(
  input clk,
  input rst,
  input ew,
  input [4:0] addr,
  input [4:0] src1,
  input [4:0] src2,
  input [11:0] csr,
  input [31:0] data,
  input csrrw,
  input csrrs,
  input ecallsig,
  output [31:0] regout1,
  output [31:0] regout2,
  output [31:0] mepc,
  output [31:0] mtvec
);

  wire [32*15-1:0] rf_flat;
  wire [32*6-1:0] rf_csr_flat;
  wire [31:0] reg_write_data;
  wire [31:0] rf_src1_word;
  wire [31:0] rf_src2_word;

  assign rf_src1_word = (src1 == 0) ? 32'b0 : rf_flat[({5'b0, src1[3:0]} - 9'd1) * 32 +: 32];
  assign rf_src2_word = (src2 == 0) ? 32'b0 : rf_flat[({5'b0, src2[3:0]} - 9'd1) * 32 +: 32];
  assign reg_write_data = data;

  reg [2:0] csr_choose;
  always @(*) begin
    case (csr)
      12'h300: csr_choose = 3'b000;  // mstatus
      12'h305: csr_choose = 3'b001;  // mtvec
      12'h341: csr_choose = 3'b010;  // mepc
      12'h342: csr_choose = 3'b011;  // mcause
      12'hf11: csr_choose = 3'b100;  // mvendorid
      12'hf12: csr_choose = 3'b101;  // marchid
      default: csr_choose = 3'b000;  // 或保持与 MuxKey 行为一致
    endcase
  end

  ysyx_24100007_registers registers0(
    .clk(clk),
    .rst(rst),
    .ew(ew),
    .csrrs(csrrs),
    .csrrw(csrrw),
    .ecall(ecallsig),
    .addr(addr),
    .csr_choose(csr_choose),
    .data(reg_write_data),
    .gr_flat(rf_flat),
    .csr_flat(rf_csr_flat)
  );

  assign regout1 = (src1 == 0) ? 0 : rf_src1_word;
  assign regout2 = (src2 == 0) ? 0 : rf_src2_word;

  assign mepc = rf_csr_flat[2*32 +: 32];
  assign mtvec = rf_csr_flat[1*32 +: 32];

endmodule
