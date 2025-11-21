module sdram(
  input        clk,
  input        cke,
  input        cs,
  input        ras,
  input        cas,
  input        we,
  input [13:0] a,
  input [ 1:0] ba,
  input [ 3:0] dqm,
  inout [31:0] dq
);

wire [2:0] cmd = {ras,cas,we};
reg ras_l;
reg cas_l;
reg we_l;
reg ras_h;
reg cas_h;
reg we_h;
always @(*) begin
  case(cmd)
    3'b000, 3'b111:begin
      {ras_l,cas_l,we_l} = cmd;
      {ras_h,cas_h,we_h} = cmd;
    end
    default:begin
      {ras_l,cas_l,we_l} = !a[13] ? cmd : 3'b111;
      {ras_h,cas_h,we_h} =  a[13] ? cmd : 3'b111;
    end
  endcase
end

sdram_32 u_sdram_32_L(
  .clk   (clk      ),
  .cke   (cke      ),
  .cs    (cs       ),
  .ras   (ras_l    ),
  .cas   (cas_l    ),
  .we    (we_l     ),
  .a     (a[12:0]  ),
  .ba    (ba       ),
  .dqm   (dqm      ),
  .dq    (dq       )
);

sdram_32 u_sdram_32_H(
  .clk   (clk      ),
  .cke   (cke      ),
  .cs    (cs       ),
  .ras   (ras_h    ),
  .cas   (cas_h    ),
  .we    (we_h     ),
  .a     (a[12:0]  ),
  .ba    (ba       ),
  .dqm   (dqm      ),
  .dq    (dq       )
);

endmodule
