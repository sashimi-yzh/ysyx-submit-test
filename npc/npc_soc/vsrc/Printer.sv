module Printer (
    input clock,
    input valid,
    input [7:0] data
);
  always @(posedge clock) begin
    if (valid) $write("%c", data);
  end
endmodule
