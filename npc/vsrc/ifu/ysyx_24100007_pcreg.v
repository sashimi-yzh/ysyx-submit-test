module ysyx_24100007_pcreg (
    input clk,
    input [31:0] npc,
    input rst,
    input ready_from,
    output reg [31:0] pcout
);

`ifndef SYNTHESIS
`ifdef __NPC__
  localparam init = 32'h80000000;
`else
  localparam init = 32'h30000000;
`endif
`else
  localparam init = 32'h80000000;
`endif

  // synopsys translate_off
  initial begin
    pcout = init;
`ifdef __ICARUS__
    $display("[Init] Start PC: 0x%h", pcout);
`endif
  end
  // synopsys translate_on
  // 综合时仅依赖 reset 初始化，initial 块已被 translate_off 排除

  always @(posedge clk) begin
    if (rst) begin
      pcout <= init;
    end else if (ready_from == 1) begin
      pcout <= npc;
    end
  end

endmodule
