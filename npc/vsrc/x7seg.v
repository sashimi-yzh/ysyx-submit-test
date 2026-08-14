
module x7seg (
  input [3:0] b,
  output reg [6:0] h
);
  always @(*) begin
    case (b)
      4'd0: h = 7'b1000000;
      4'd1: h = 7'b1111001;
      4'd2: h = 7'b0100100;
      4'd3: h = 7'b0110000;
      4'd4: h = 7'b0011001;
      4'd5: h = 7'b0010010;
      4'd6: h = 7'b0000010;
      4'd7: h = 7'b1111000;
      4'd8: h = 7'b0000000;
      4'd9: h = 7'b0010000;
      4'ha: h = 7'b0001000;
      4'hb: h = 7'b0000011;
      4'hc: h = 7'b1000110;
      4'hd: h = 7'b0100001;
      4'he: h = 7'b0000110;
      4'hf: h = 7'b0001110;
      default: h = 7'h7f;
    endcase
  end
endmodule
