module ysyx_24100007_transmit(
    input clk,
    input rst,

    input [4:0] src1_addr_in,
    input [4:0] src2_addr_in,
    input [4:0] exu_rd,
    input [4:0] wbu_rd,

    input exu_res_valid,
    input exu_regew,
    input wbu_res_valid,
    input wbu_regew,
    input exu_memer_bypass,              // EXU 是否是 load 指令（用于处理 load-use 冲突）

    input [31:0] regout1_in,
    input [31:0] regout2_in,
    input [31:0] exu_transmit_data,
    input [31:0] wbu_transmit_data,

    output [31:0] src1,
    output [31:0] src2,
    output valid
);  
  wire src1_valid, src2_valid;

  // 实例化两次旁路选择模块，分别用于 src1 和 src2（纯组合逻辑）
  ysyx_24100007_bypass_sel bypass_src1 (
    .src_addr_in           (src1_addr_in),
    .reg_data_in           (regout1_in),
    .wbu_rd                (wbu_rd),
    .wbu_regew             (wbu_regew),
    .wbu_transmit_data     (wbu_transmit_data),
    .wbu_transmit_data_valid(wbu_res_valid),
    .exu_rd                (exu_rd),
    .exu_regew             (exu_regew),
    .exu_transmit_data     (exu_transmit_data),
    .exu_transmit_data_valid(exu_res_valid),
    .exu_memer_bypass      (exu_memer_bypass),
    .src_data_out          (src1),
    .src_valid             (src1_valid)
  );

  ysyx_24100007_bypass_sel bypass_src2 (
    .src_addr_in           (src2_addr_in),
    .reg_data_in           (regout2_in),
    .wbu_rd                (wbu_rd),
    .wbu_regew             (wbu_regew),
    .wbu_transmit_data     (wbu_transmit_data),
    .wbu_transmit_data_valid(wbu_res_valid),
    .exu_rd                (exu_rd),
    .exu_regew             (exu_regew),
    .exu_transmit_data     (exu_transmit_data),
    .exu_transmit_data_valid(exu_res_valid),
    .exu_memer_bypass      (exu_memer_bypass),
    .src_data_out          (src2),
    .src_valid             (src2_valid)
  );

  // 整体有效信号：两个源都有效时才有效
  assign valid = src1_valid && src2_valid;
endmodule

module ysyx_24100007_bypass_sel(
  input [4:0] src_addr_in,          // 源寄存器地址（src1 或 src2）
  input [31:0] reg_data_in,          // 从寄存器堆读出的数据

  // WBU 旁路接口
  input [4:0] wbu_rd,
  input wbu_regew,
  input [31:0] wbu_transmit_data,
  input wbu_transmit_data_valid,

  // EXU 旁路接口
  input [4:0] exu_rd,
  input exu_regew,
  input [31:0] exu_transmit_data,
  input exu_transmit_data_valid,
  input exu_memer_bypass,              // EXU 是否是 load 指令（用于处理 load-use 冲突）

  output [31:0] src_data_out,        // 选择后的数据
  output src_valid                   // 数据有效信号
);

  // 优先级：EXU > WBU（EXU是上一级指令，更接近当前指令）
  wire need_exu_forward = (src_addr_in != 5'b0) && (src_addr_in == exu_rd) && exu_regew;
  wire need_wbu_forward = (src_addr_in != 5'b0) && (src_addr_in == wbu_rd) && wbu_regew && !need_exu_forward;

  // 检测 load-use 冲突：需要 EXU 转发，但 EXU 是 load（数据未就绪）
  // 简化方案：直接 stall，等 load 进 WBU 后走 need_wbu_forward，无需 load_use_wait 和锁存
  wire load_use_hazard = need_exu_forward && exu_memer_bypass;

  // 有效条件：遇到 load-use 则 invalid（IDU 被 stall）
  assign src_valid = load_use_hazard ? 1'b0 :
                   need_exu_forward && !exu_memer_bypass ? exu_transmit_data_valid :
                   need_wbu_forward ? wbu_transmit_data_valid : 1'b1;

  // 数据选择：load-use 时数据无效不会被使用；否则 EXU > WBU > 寄存器堆
  assign src_data_out = need_exu_forward && !exu_memer_bypass ? exu_transmit_data :
                        need_wbu_forward ? wbu_transmit_data : reg_data_in;

endmodule
