module RandomGenerator (
    input clk,
    input [7:0] din,
    output [7:0] dout,
    output [7:0] h0,
    output [7:0] h1
);

  reg [7:0] tmp_in;
  reg [7:0] tmp_out;

  assign dout = tmp_in;

  initial begin
    tmp_in = din;
  end

  always @(posedge clk) begin
    tmp_in = {tmp_in[4] ^ tmp_in[3] ^ tmp_in[2] ^ tmp_in[0], tmp_out[6:0]};
  end

  ShiftReg shift (
      tmp_in,
      3'b001,
      1,
      1,
      tmp_out
  );

  bcd7seg bcd0 (
      dout[3:0],
      h0
  );

  bcd7seg bcd1 (
      dout[7:4],
      h1
  );
endmodule
