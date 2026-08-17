module Ebreaker (
    input clock,
    input reset,
    input ebreak
);
  always @(posedge clock) begin
    if (ebreak && !reset) begin
      $finish;
    end
  end
endmodule
