module bcd7seg (
    input [3:0] b,
    output reg [7:0] h
);

  always @(b) begin
    case (b)
      4'b0000: h = 8'b0000_0011;
      4'b0001: h = 8'b1001_1111;
      4'b0010: h = 8'b0010_0101;
      4'b0011: h = 8'b0000_1101;
      4'b0100: h = 8'b1001_1001;
      4'b0101: h = 8'b0100_1001;
      4'b0110: h = 8'b0100_0001;
      4'b0111: h = 8'b0001_1111;
      4'b1000: h = 8'b0000_0001;
      default: h = 8'b1111_1111;
    endcase
  end

endmodule
