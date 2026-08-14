module LFSR(
  input [7:0] din,
  input r, s,
  input btn_clk,

  output [6:0] seg0,
  output [6:0] seg1
);

reg [7:0] LFSR_reg = 0;
always @(posedge btn_clk or posedge r or posedge s) begin
  if(r) LFSR_reg <= 0;
  else if(s) LFSR_reg <= din;
  else LFSR_reg <= {(LFSR_reg[0]^LFSR_reg[2]^LFSR_reg[3]^LFSR_reg[4]), LFSR_reg[7:1]};
end

x7seg x7seg0(LFSR_reg[3:0], seg0);
x7seg x7seg1(LFSR_reg[7:4], seg1);

endmodule