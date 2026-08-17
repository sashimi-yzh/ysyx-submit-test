import "DPI-C" function void trap(input int signal);

module Trap (
    clk,
    ebreak
);
  input ebreak, clk;

  always @(posedge clk) begin
    trap({31'h0, ebreak});
  end

endmodule
