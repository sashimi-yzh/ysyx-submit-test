import "DPI-C" function void notify_retire(
  input int pc,
  input int inst
);

module Inst_Retire (
  input        clock,
  input        reset,
  input        retire,
  input [31:0] pc,
  input [31:0] inst
);
  always @(posedge clock) begin
    if (retire && !reset) begin
      notify_retire(pc, inst);
    end
  end

endmodule
