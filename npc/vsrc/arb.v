module ysyx_24110012_arbiter #(
    parameter ADDR_WIDTH  = 32,
    parameter DATA_WIDTH  = 32,
    parameter NUM_MASTERS = 2
) (
    input clk,
    input reset,

    output wire [MASTER_INDEX_WIDTH-1:0] mem_r_grant,

    input wire [NUM_MASTERS-1:0] m_awvalid,
    input wire [NUM_MASTERS-1:0] [2:0] m_awsize,
    output wire [NUM_MASTERS-1:0] m_awready,
    input wire [NUM_MASTERS-1:0][ADDR_WIDTH-1:0] m_awaddr,
    input wire [NUM_MASTERS-1:0] m_wvalid,
    output reg [NUM_MASTERS-1:0] m_wready,
    input wire [NUM_MASTERS-1:0][DATA_WIDTH-1:0] m_wdata,
    input wire [NUM_MASTERS-1:0][DATA_WIDTH/8-1:0] m_wstrb,
    output wire [NUM_MASTERS-1:0][1:0] m_bresp,
    output reg [NUM_MASTERS-1:0] m_bvalid,
    input wire [NUM_MASTERS-1:0] m_bready,
    input wire [NUM_MASTERS-1:0] m_arvalid,
    input wire [NUM_MASTERS-1:0] [2:0] m_arsize,
    input wire [NUM_MASTERS-1:0] [1:0] m_arburst,
    input wire [NUM_MASTERS-1:0] [7:0] m_arlen,
    output reg [NUM_MASTERS-1:0] m_arready,
    input wire [NUM_MASTERS-1:0][ADDR_WIDTH-1:0] m_araddr,
    output wire [NUM_MASTERS-1:0] m_rvalid,
    input wire [NUM_MASTERS-1:0] m_rready,
    output wire [NUM_MASTERS-1:0][DATA_WIDTH-1:0] m_rdata,
    output wire [NUM_MASTERS-1:0] m_rlast,

    output wire                    s_awvalid,
    output wire [             2:0] s_awsize,
    input  wire                    s_awready,
    output wire [  ADDR_WIDTH-1:0] s_awaddr,
    output wire                    s_wvalid,
    input  wire                    s_wready,
    output reg  [  DATA_WIDTH-1:0] s_wdata,
    output reg  [DATA_WIDTH/8-1:0] s_wstrb,
    input  wire [             1:0] s_bresp,
    input  wire                    s_bvalid,
    output reg                     s_bready,
    output reg                     s_arvalid,
    output wire [             2:0] s_arsize,
    output wire [             1:0] s_arburst,
    output wire [             7:0] s_arlen,
    input  wire                    s_arready,
    output reg  [  ADDR_WIDTH-1:0] s_araddr,
    input  wire                    s_rvalid,
    output reg                     s_rready,
    input  wire [  DATA_WIDTH-1:0] s_rdata,
    input  wire                    s_rlast
);

  localparam MASTER_INDEX_WIDTH = $clog2(NUM_MASTERS);

  reg [MASTER_INDEX_WIDTH-1:0] aw_grant, ar_grant;
  reg [MASTER_INDEX_WIDTH-1:0] aw_grant_next, ar_grant_next;
  reg [NUM_MASTERS-1:0] aw_grant_oh, ar_grant_oh;  // one-hot
  reg ar_active, aw_active;
  integer aw_grant_i, ar_grant_i;

  // ar_grant to know which host is using mem and send to regfile to use
  assign mem_r_grant = ar_grant;

  // Lower-index master has higher priority for write channel.
  // At the top level, master 0 is LSU and master 1 is IFU/icache.
  always @(*) begin
    aw_grant_next = aw_grant;
    for (aw_grant_i = NUM_MASTERS - 1; aw_grant_i >= 0; aw_grant_i = aw_grant_i - 1) begin
      if (m_awvalid[aw_grant_i]) begin
        aw_grant_next = aw_grant_i[MASTER_INDEX_WIDTH-1:0];
      end
    end
  end

  // Lower-index master has higher priority for read channel.
  always @(*) begin
    ar_grant_next = ar_grant;
    for (ar_grant_i = NUM_MASTERS - 1; ar_grant_i >= 0; ar_grant_i = ar_grant_i - 1) begin
      if (m_arvalid[ar_grant_i]) begin
        ar_grant_next = ar_grant_i[MASTER_INDEX_WIDTH-1:0];
      end
    end
  end

  always @(posedge clk) begin
    if (reset) begin
      ar_active <= 1'b0;
      aw_active <= 1'b0;
    end else begin
      if (s_arvalid && !ar_active) begin
        ar_active <= 1'b1;
      end else if (s_rvalid && s_rready && (s_rlast || s_arlen == 0) && ar_active) begin
        ar_active <= 1'b0;
      end

      if (s_awvalid && !aw_active) begin
        aw_active <= 1'b1;
      end else if (s_bvalid && s_bready && aw_active) begin
        aw_active <= 1'b0;
      end
    end
  end

  // update grants
  always @(posedge clk) begin
    if (reset) begin
      aw_grant <= 0;
      ar_grant <= 0;
    end else begin
      if ((s_bvalid && s_bready) ||
         (!aw_active && !m_awvalid[aw_grant] && |m_awvalid) ||
         (!aw_active && (aw_grant_next != aw_grant) && |m_awvalid)) begin
        aw_grant <= aw_grant_next;
      end
      // s_arvalid is not needed to check for write as ifu only read
      if ((s_rvalid && s_rready && (s_rlast || s_arlen == 0)) ||
         (!ar_active && !m_arvalid[ar_grant] && |m_arvalid) ||
         (!ar_active && (ar_grant_next != ar_grant) && |m_arvalid && !s_arvalid)) begin
        ar_grant <= ar_grant_next;
      end
    end
  end

  // one-hot encoding
  always @(*) begin
    aw_grant_oh = 0;
    ar_grant_oh = 0;
    aw_grant_oh[aw_grant] = 1'b1;
    ar_grant_oh[ar_grant] = 1'b1;
  end

  wire write_req = |m_awvalid;
  wire read_req  = |m_arvalid;

  // Read/Write mutual exclusion and arbitration logic:
  // 1. While a read transaction is in progress (ar_active), write requests are blocked;
  //    while a write transaction is in progress (aw_active), read requests are blocked.
  // 2. When idle and both read and write are requested simultaneously, the lower master
  //    index wins (LSU index 0 before IFU/icache index 1); a tie defaults to read.
  wire aw_has_priority = (aw_grant_next < ar_grant_next) ? aw_active : ar_active;
  wire aw_enable = !ar_active && write_req && (!read_req || aw_has_priority);
  wire ar_enable = !aw_active && read_req  && (!write_req || !aw_has_priority);

  assign s_awaddr  = m_awaddr[aw_grant];
  assign s_awsize  = m_awsize[aw_grant];
  assign s_awvalid = aw_enable ? m_awvalid[aw_grant] : 1'b0;

  // awready signal distribution
  genvar i;
  generate
    for (i = 0; i < NUM_MASTERS; i = i + 1) begin : gen_aw_ready
      assign m_awready[i] = aw_grant_oh[i] & s_awready & aw_enable;
    end
  endgenerate

  // write data channel multiplexer
  assign s_wdata  = m_wdata[aw_grant];
  assign s_wstrb  = m_wstrb[aw_grant];
  assign s_wvalid = m_wvalid[aw_grant];

  // wready signal distribution
  generate
    for (i = 0; i < NUM_MASTERS; i = i + 1) begin : gen_w_ready
      assign m_wready[i] = aw_grant_oh[i] & s_wready;
    end
  endgenerate

  // write response channel demultiplexer
  generate
    for (i = 0; i < NUM_MASTERS; i = i + 1) begin : gen_b_channel
      assign m_bresp[i]  = s_bresp;
      assign m_bvalid[i] = aw_grant_oh[i] & s_bvalid;
    end
  endgenerate

  assign s_bready  = m_bready[aw_grant];

  // read address channel multiplexer
  assign s_araddr  = m_araddr[ar_grant];
  assign s_arsize  = m_arsize[ar_grant];
  assign s_arvalid = ar_enable ? m_arvalid[ar_grant] : 1'b0;
  assign s_arburst = m_arburst[ar_grant];
  assign s_arlen   = m_arlen[ar_grant];

  // arready signal distribution
  generate
    for (i = 0; i < NUM_MASTERS; i = i + 1) begin : gen_ar_ready
      assign m_arready[i] = ar_grant_oh[i] & s_arready & ar_enable;
    end
  endgenerate

  // read data channel demultiplexer (data return phase is not gated by ar_enable; routed by latched ar_grant)
  generate
    for (i = 0; i < NUM_MASTERS; i = i + 1) begin : gen_r_channel
      assign m_rdata[i]  = s_rdata;
      assign m_rvalid[i] = ar_grant_oh[i] & s_rvalid;
      assign m_rlast[i]  = ar_grant_oh[i] & s_rlast;
    end
  endgenerate

  assign s_rready = m_rready[ar_grant];

  // function [MASTER_INDEX_WIDTH-1:0] priority_arbiter;
  //     input [NUM_MASTERS-1:0] req;

  //     integer i;
  //     begin
  //         priority_arbiter = 0;
  //         for (i = 0; i < NUM_MASTERS; i = i + 1) begin
  //             if (req[i]) begin
  //                 priority_arbiter = MASTER_INDEX_WIDTH'(i);
  //                 break;
  //             end
  //         end
  //     end
  // endfunction

endmodule
