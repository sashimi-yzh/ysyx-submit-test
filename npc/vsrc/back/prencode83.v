module prencoder83(
  input  [7:0] x,
  input  en,
  output reg [2:0]y,
  output [6:0] seg
);
  
  integer i;
  always @(x or en) begin
    if (en) begin
      y = 0;
      for( i = 0; i <= 7; i = i+1)
          if(x[i] == 1)  y = i[2:0];
    end
    else  y = 0;
  end

  hex u_hex0 (
    .hex({1'b0, y}),
    .seg(seg)
  );

endmodule