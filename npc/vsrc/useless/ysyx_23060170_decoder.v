module ysyx_23060170_decoder #(
    parameter WIDTH = 3
) (
    input [WIDTH - 1:0] in,
    output [2**WIDTH - 1:0] out
);
  genvar i;
  generate
    for (i = 0; i < 2 ** WIDTH; i = i + 1) begin : gen_block
      assign out[i] = (in == i);
    end
  endgenerate

endmodule
