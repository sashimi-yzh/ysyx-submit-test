module Encode83 (
    input [7:0] x,
    output flag,
    output reg [2:0] y,
    output reg [7:0] seg0
);

  assign flag = x != 0;

  // 优先编码
  wire x7 = x[7];
  wire x6 = ~x[7] & x[6];
  wire x5 = ~x[7] & ~x[6] & x[5];
  wire x4 = ~x[7] & ~x[6] & ~x[5] & x[4];
  wire x3 = ~x[7] & ~x[6] & ~x[5] & ~x[4] & x[3];
  wire x2 = ~x[7] & ~x[6] & ~x[5] & ~x[4] & ~x[3] & x[2];
  wire x1 = ~x[7] & ~x[6] & ~x[5] & ~x[4] & ~x[3] & ~x[2] & x[1];
  wire x0 = ~x[7] & ~x[6] & ~x[5] & ~x[4] & ~x[3] & ~x[2] & ~x[1] & x[0];

  assign y[0] = x1 | x3 | x5 | x7;
  assign y[1] = x2 | x6 | x3 | x7;
  assign y[2] = x4 | x5 | x6 | x7;

  bcd7seg bcd (
      y,
      seg0
  );


endmodule

module bcd7seg (
    input [2:0] b,
    output reg [7:0] h
);

  always @(b) begin
    case (b)
      3'b000: h = 8'b0000_0011;
      3'b001: h = 8'b1001_1111;
      3'b010: h = 8'b0010_0101;
      3'b011: h = 8'b0000_1101;
      3'b100: h = 8'b1001_1001;
      3'b101: h = 8'b0100_1001;
      3'b110: h = 8'b0100_0001;
      3'b111: h = 8'b0001_1111;
    endcase
  end

endmodule
