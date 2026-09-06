// ---------------------------------------------
// version created at 2025/12/20 sunmingyang
// 单 master 版本：仅做地址解码与 slave 路由，无 master 仲裁
// ---------------------------------------------
module ysyx_24100007_arbiter #(
    parameter SLAVE_NUM = 2  // slave设备数量（CLINT, 外部AXI等）
) (
    input wire clk,
    input wire rst,

    // 单 master AXI 接口
    input  awvalid,
    input  wvalid,
    input  arvalid,
    input  rready,
    input  bready,
    output bvalid,
    output rvalid,
    output awready,
    output wready,
    output arready,

    input  [31:0] araddr,
    input  [31:0] awaddr,
    input  [31:0] wdata,
    input  [ 3:0] wstrb,
    output [31:0] rdata,
    output [ 1:0] bresp,
    input  [ 2:0] awsize,
    input  [ 2:0] arsize,
    input  [ 7:0] awlen,
    input  [ 7:0] arlen,
    input  [ 1:0] awburst,
    input  [ 1:0] arburst,
    input         wlast,
    output        rlast,

    // slave 接口
    output [SLAVE_NUM-1:0] awvalid_out,
    output [SLAVE_NUM-1:0] wvalid_out,
    output [SLAVE_NUM-1:0] arvalid_out,
    output [SLAVE_NUM-1:0] rready_out,
    output [SLAVE_NUM-1:0] bready_out,
    input  [SLAVE_NUM-1:0] bvalid_in,
    input  [SLAVE_NUM-1:0] rvalid_in,
    input  [SLAVE_NUM-1:0] awready_in,
    input  [SLAVE_NUM-1:0] wready_in,
    input  [SLAVE_NUM-1:0] arready_in,

    output [SLAVE_NUM*32-1:0] araddr_out,
    output [SLAVE_NUM*32-1:0] awaddr_out,
    output [SLAVE_NUM*32-1:0] wdata_out,
    output [SLAVE_NUM*4-1:0]  wstrb_out,
    input  [SLAVE_NUM*32-1:0] rdata_in,
    input  [SLAVE_NUM*2-1:0]  bresp_in,
    output [SLAVE_NUM*3-1:0]  awsize_out,
    output [SLAVE_NUM*3-1:0]  arsize_out,
    output [SLAVE_NUM*8-1:0]  awlen_out,
    output [SLAVE_NUM*8-1:0]  arlen_out,
    output [SLAVE_NUM*2-1:0]  awburst_out,
    output [SLAVE_NUM*2-1:0]  arburst_out,
    output [SLAVE_NUM-1:0]    wlast_out,
    input  [SLAVE_NUM-1:0]    rlast_in
);

  typedef enum logic {
    ST_IDLE,
    ST_TRANS
  } state_t;
  state_t state;

  wire has_req = arvalid | awvalid;
  wire trans_end = (rvalid & rready & rlast) | (bvalid & bready);

  wire [31:0] current_addr = arvalid ? araddr : awaddr;
  wire is_clint_addr = (current_addr >= 32'h02000000) && (current_addr <= 32'h0200ffff);

  reg slave_owner;
  wire trans_active = (state == ST_TRANS);
  wire owner_external = trans_active & ~slave_owner;
  wire owner_clint = trans_active & slave_owner;
  wire [SLAVE_NUM-1:0] slave_owner_one_hot = {owner_clint, owner_external};

  always @(posedge clk) begin
    if (rst) begin
      state <= ST_IDLE;
      slave_owner <= 1'b0;
    end else begin
      case (state)
        ST_IDLE: begin
          if (has_req) begin
            state <= ST_TRANS;
            slave_owner <= is_clint_addr;
          end
        end

        ST_TRANS: begin
          if (trans_end) begin
            state <= ST_IDLE;
            slave_owner <= 1'b0;
          end
        end

        default: begin
          state <= ST_IDLE;
          slave_owner <= 1'b0;
          // synopsys translate_off
          $error("arbiter Invalid state");
          // synopsys translate_on
        end
      endcase
    end
  end

  // master 信号直通到 slave（由 slave_owner 选通）
  wire [31:0] master_awaddr = awaddr;
  wire [31:0] master_araddr = araddr;
  wire [31:0] master_wdata = wdata;
  wire [ 3:0] master_wstrb = wstrb;
  wire [ 2:0] master_awsize = awsize;
  wire [ 2:0] master_arsize = arsize;
  wire [ 7:0] master_awlen = awlen;
  wire [ 7:0] master_arlen = arlen;
  wire [ 1:0] master_awburst = awburst;
  wire [ 1:0] master_arburst = arburst;
  wire        master_wlast = wlast;

  genvar m;
  generate
    for (m = 0; m < SLAVE_NUM; m = m + 1) begin : gen_slave_route
      assign awvalid_out[m] = slave_owner_one_hot[m] ? awvalid : 1'b0;
      assign awaddr_out[m*32 +: 32] = master_awaddr;
      assign awsize_out[m*3  +: 3 ] = master_awsize;
      assign awlen_out[m*8   +: 8 ] = master_awlen;
      assign awburst_out[m*2 +: 2 ] = master_awburst;

      assign wvalid_out[m] = slave_owner_one_hot[m] ? wvalid : 1'b0;
      assign wdata_out[m*32 +: 32] = master_wdata;
      assign wstrb_out[m*4  +: 4 ] = master_wstrb;
      assign wlast_out[m] = master_wlast;

      assign arvalid_out[m] = slave_owner_one_hot[m] ? arvalid : 1'b0;
      assign araddr_out[m*32 +: 32] = master_araddr;
      assign arsize_out[m*3  +: 3 ] = master_arsize;
      assign arlen_out[m*8   +: 8 ] = master_arlen;
      assign arburst_out[m*2 +: 2 ] = master_arburst;

      assign rready_out[m] = slave_owner_one_hot[m] ? rready : 1'b0;
      assign bready_out[m] = slave_owner_one_hot[m] ? bready : 1'b0;
    end
  endgenerate

  // Return zero while idle instead of implicitly selecting CLINT.
  assign rdata   = owner_external ? rdata_in[0*32+:32] : owner_clint ? rdata_in[1*32+:32] : 32'b0;
  assign bresp   = owner_external ? bresp_in[0*2+:2] : owner_clint ? bresp_in[1*2+:2] : 2'b0;
  assign rvalid  = owner_external ? rvalid_in[0] : owner_clint ? rvalid_in[1] : 1'b0;
  assign bvalid  = owner_external ? bvalid_in[0] : owner_clint ? bvalid_in[1] : 1'b0;
  assign rlast   = owner_external ? rlast_in[0] : owner_clint ? rlast_in[1] : 1'b0;
  assign awready = owner_external ? awready_in[0] : owner_clint ? awready_in[1] : 1'b0;
  assign wready  = owner_external ? wready_in[0] : owner_clint ? wready_in[1] : 1'b0;
  assign arready = owner_external ? arready_in[0] : owner_clint ? arready_in[1] : 1'b0;

endmodule
