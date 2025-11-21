module sdram_32(
  input        clk,
  input        cke,
  input        cs,
  input        ras,
  input        cas,
  input        we,
  input [12:0] a,
  input [ 1:0] ba,
  input [ 3:0] dqm,
  inout [31:0] dq
);

sdram_16 u_sdram_16_L(
  .clk   (clk      ),
  .cke   (cke      ),
  .cs    (cs       ),
  .ras   (ras      ),
  .cas   (cas      ),
  .we    (we       ),
  .a     (a        ),
  .ba    (ba       ),
  .dqm   (dqm[1:0] ),
  .dq    (dq[15:0] )
);

sdram_16 u_sdram_16_H(
  .clk   (clk      ),
  .cke   (cke      ),
  .cs    (cs       ),
  .ras   (ras      ),
  .cas   (cas      ),
  .we    (we       ),
  .a     (a        ),
  .ba    (ba       ),
  .dqm   (dqm[3:2] ),
  .dq    (dq[31:16])
);

endmodule
