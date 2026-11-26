// NPCSynth - 当前 NPC 多周期核的综合边界 (synthesis boundary)
//
// 评估对象: npc/vsrc 的当前多周期核
//   top + Core / ICache / LSU / Arbiter / CSR / RegisterFile / CLINT
//
// 使用 -DSYNTHESIS 读取 RTL: 此时 top.v 走内部合成用存储模型
// (synth_rvalid / synth_rdata, 见 top.v `ifndef SOC_MODE + `ifdef SYNTHESIS),
// 仿真专用的 DPI-C (PMEM、trace、difftest、perf) 全部被排除;
// 而总线请求/响应逻辑 (AXI AR/R/AW/W/B 通道与 Arbiter 仲裁) 仍留在
// 面积与时序范围内。
//
// 端口刻意与核的指令存储器接口对齐 (同 npc/eval 参照的
// RTLStandalone_Synth), 便于与其他版本做同口径对比。

module NPCSynth(
  input clk,
  input rst,
  input [31:0] imem_rdata,

  output [31:0] pc,
  output [31:0] inst,
  output [31:0] imem_addr
);

  top u_top(
    .clk(clk),
    .rst(rst),
    .imem_rdata(imem_rdata),
    .pc(pc),
    .inst(inst),
    .imem_addr(imem_addr)
  );

endmodule
