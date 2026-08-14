module priority_encode83 (
  input [7:0] x,
  input en,
  output reg [2:0] y,
  output valid,
  output [6:0] seg_0
);
  integer i;
  always @(x or en) begin
    y = 0;
    if(en) begin
      for( i = 0; i <= 7; i = i+1)
        if(x[i] == 1) y = i[2:0];
    end
  end
  assign valid = en & (|x);
  x7seg seg0({1'b0, y}, seg_0);
endmodule
