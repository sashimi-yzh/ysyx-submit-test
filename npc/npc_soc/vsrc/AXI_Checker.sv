module AXI_Checker (
    input       clock,
    input       reset,
    input       bready,
    input       bvalid,
    input [1:0] bresp,
    input       rready,
    input       rvalid,
    input [1:0] rresp
);
  always @(posedge clock) begin
    if (!reset) begin
      if (bvalid && bready && bresp != 2'b00) begin
        $display("Error on AXI write : bresp = %b", bresp);
      end
      if (rvalid && rready && rresp != 2'b00) begin
        $display("Error on AXI read : rresp = %b", rresp);
      end
    end
  end
endmodule
