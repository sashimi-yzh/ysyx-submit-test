module ppconn #(
  parameter WIDTH = 32
) (
  input wire clk,
  input wire reset,
  input wire flush,

  //upstream
  input  wire             in_valid,
  output wire             in_ready,
  input  wire [WIDTH-1:0] in_data,

  //downstream
  output reg              out_valid,
  input  wire             out_ready,
  output reg  [WIDTH-1:0] out_data
);

  assign in_ready = !out_valid || out_ready;

  always @(posedge clk) begin
    if (reset || flush) begin
      out_valid <= 1'b0;
    end else if (in_ready) begin
      out_valid <= in_valid;
      if (in_valid) begin
        out_data <= in_data;
      end
    end
  end

endmodule
