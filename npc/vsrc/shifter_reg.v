module shifter_REG(
  input btn_clk,
  input [2:0] sel,
  input [7:0] din,
  input serial_din,
  output reg [7:0] shifter_reg
);

always @(posedge btn_clk) begin
  case (sel)
    3'd0 : shifter_reg <= 0;
    3'd1 : shifter_reg <= din;
    3'd2 : shifter_reg <= {1'b0, shifter_reg[7:1]};
    3'd3 : shifter_reg <= {shifter_reg[6:0], 1'b0};
    3'd4 : shifter_reg <= {shifter_reg[7], shifter_reg[7:1]};
    3'd5 : shifter_reg <= {serial_din, shifter_reg[7:1]};
    3'd6 : shifter_reg <= {shifter_reg[0], shifter_reg[7:1]};
    3'd7 : shifter_reg <= {shifter_reg[6:0], shifter_reg[7]};
    default: shifter_reg <= 0;
  endcase
end

endmodule