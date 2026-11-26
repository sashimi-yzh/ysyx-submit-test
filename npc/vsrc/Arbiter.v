module Arbiter(
  input clk,
  input rst,

  // IFU AR (from ICache)
  input        ifu_arvalid,
  output       ifu_arready,
  input [31:0] ifu_araddr,
  input [7:0]  ifu_arlen,
  input [1:0]  ifu_arburst,

  // IFU R
  output       ifu_rvalid,
  input        ifu_rready,
  output [31:0] ifu_rdata,
  output       ifu_rlast,

  // LSU AR
  input        lsu_arvalid,
  output       lsu_arready,
  input [31:0] lsu_araddr,
  input [3:0]  lsu_arid,
  input [7:0]  lsu_arlen,
  input [2:0]  lsu_arsize,
  input [1:0]  lsu_arburst,

  // LSU R
  output       lsu_rvalid,
  input        lsu_rready,
  output [1:0] lsu_rresp,
  output [31:0] lsu_rdata,
  output       lsu_rlast,
  output [3:0] lsu_rid,

  // LSU AW
  input        lsu_awvalid,
  output       lsu_awready,
  input [31:0] lsu_awaddr,
  input [3:0]  lsu_awid,
  input [7:0]  lsu_awlen,
  input [2:0]  lsu_awsize,
  input [1:0]  lsu_awburst,

  // LSU W
  input        lsu_wvalid,
  output       lsu_wready,
  input [31:0] lsu_wdata,
  input [3:0]  lsu_wstrb,
  input        lsu_wlast,

  // LSU B
  output       lsu_bvalid,
  input        lsu_bready,
  output [1:0] lsu_bresp,
  output [3:0] lsu_bid,

  // CLINT AXI4 AR
  output        clint_arvalid,
  input         clint_arready,
  output [31:0] clint_araddr,
  output [3:0]  clint_arid,
  output [7:0]  clint_arlen,
  output [2:0]  clint_arsize,
  output [1:0]  clint_arburst,

  // CLINT AXI4 R
  input         clint_rvalid,
  output        clint_rready,
  input  [31:0] clint_rdata,
  input  [1:0]  clint_rresp,
  input         clint_rlast,
  input  [3:0]  clint_rid,

  // MEM AXI4 AR
  output        mem_arvalid,
  input         mem_arready,
  output [31:0] mem_araddr,
  output [3:0]  mem_arid,
  output [7:0]  mem_arlen,
  output [2:0]  mem_arsize,
  output [1:0]  mem_arburst,

  // MEM AXI4 R
  input         mem_rvalid,
  output        mem_rready,
  input  [1:0]  mem_rresp,
  input  [31:0] mem_rdata,
  input         mem_rlast,
  input  [3:0]  mem_rid,

  // MEM AXI4 AW
  output        mem_awvalid,
  input         mem_awready,
  output [31:0] mem_awaddr,
  output [3:0]  mem_awid,
  output [7:0]  mem_awlen,
  output [2:0]  mem_awsize,
  output [1:0]  mem_awburst,

  // MEM AXI4 W
  output        mem_wvalid,
  input         mem_wready,
  output [31:0] mem_wdata,
  output [3:0]  mem_wstrb,
  output        mem_wlast,

  // MEM AXI4 B
  input         mem_bvalid,
  output        mem_bready,
  input  [1:0]  mem_bresp,
  input  [3:0]  mem_bid
);

  localparam IFU_ID = 4'b0001;
  localparam LSU_ID = 4'b0010;
  localparam [2:0] IFU_SIZE = 3'b010;

  localparam [31:0] CLINT_BASE = 32'h0200_0000;
  localparam [31:0] CLINT_MASK = 32'hffff_0000;

`ifdef SOC_MODE
  wire [1:0] ifu_chan = ((ifu_araddr & CLINT_MASK) == CLINT_BASE) ? 2'd2 :
                        ((ifu_araddr >= 32'ha000_0000) &&
                         (ifu_araddr <  32'ha200_0000)) ? 2'd1 : 2'd0;
  wire [1:0] lsu_chan = ((lsu_araddr & CLINT_MASK) == CLINT_BASE) ? 2'd2 :
                        ((lsu_araddr >= 32'ha000_0000) &&
                         (lsu_araddr <  32'ha200_0000)) ? 2'd1 : 2'd0;
`else
  wire [1:0] ifu_chan = ((ifu_araddr & CLINT_MASK) == CLINT_BASE) ? 2'd2 : 2'd0;
  wire [1:0] lsu_chan = ((lsu_araddr & CLINT_MASK) == CLINT_BASE) ? 2'd2 : 2'd0;
`endif

  reg rd_busy_ifu, rd_busy_lsu;
  reg [1:0] rd_chan_ifu, rd_chan_lsu;
  reg rd_clint_ifu, rd_clint_lsu;

  wire ch0_used = (rd_busy_ifu && rd_chan_ifu == 2'd0) ||
                  (rd_busy_lsu && rd_chan_lsu == 2'd0);
  wire ch1_used = (rd_busy_ifu && rd_chan_ifu == 2'd1) ||
                  (rd_busy_lsu && rd_chan_lsu == 2'd1);
  wire ch2_used = (rd_busy_ifu && rd_chan_ifu == 2'd2) ||
                  (rd_busy_lsu && rd_chan_lsu == 2'd2);

  wire ifu_free = (ifu_chan == 2'd0) ? !ch0_used :
                  (ifu_chan == 2'd1) ? !ch1_used : !ch2_used;
  wire lsu_free = (lsu_chan == 2'd0) ? !ch0_used :
                  (lsu_chan == 2'd1) ? !ch1_used : !ch2_used;

  wire ifu_req = ifu_arvalid && ifu_free;
  wire lsu_req = lsu_arvalid && lsu_free;

  localparam [1:0] S_IDLE = 2'd0, S_IFU  = 2'd1, S_LSU  = 2'd2;

  reg [1:0] state;
  reg rr_ifu;

  wire pick_ifu = ifu_req && (!lsu_req || rr_ifu);
  wire pick_lsu = lsu_req && (!ifu_req || !rr_ifu);

  wire sel_ifu = (state == S_IFU) || ((state == S_IDLE) && pick_ifu);
  wire sel_lsu = (state == S_LSU) || ((state == S_IDLE) && pick_lsu);

  wire        ar_req   = (sel_ifu && ifu_arvalid) || (sel_lsu && lsu_arvalid);
  wire [31:0] ar_addr  = sel_ifu ? ifu_araddr : lsu_araddr;
  wire [3:0]  ar_id    = sel_ifu ? IFU_ID : lsu_arid;
  wire [7:0]  ar_len   = sel_ifu ? ifu_arlen : lsu_arlen;
  wire [2:0]  ar_size  = sel_ifu ? IFU_SIZE : lsu_arsize;
  wire [1:0]  ar_burst = sel_ifu ? ifu_arburst : lsu_arburst;

  wire ar_clint = ar_req && ((ar_addr & CLINT_MASK) == CLINT_BASE);
  wire ar_ready = ar_clint ? clint_arready : mem_arready;
  wire ar_fire  = ar_req && ar_ready;

  assign clint_arvalid = ar_req &&  ar_clint;
  assign clint_araddr  = ar_addr;
  assign clint_arid    = ar_id;
  assign clint_arlen   = ar_len;
  assign clint_arsize  = ar_size;
  assign clint_arburst = ar_burst;

  assign mem_arvalid  = ar_req && !ar_clint;
  assign mem_araddr   = ar_addr;
  assign mem_arid     = ar_id;
  assign mem_arlen    = ar_len;
  assign mem_arsize   = ar_size;
  assign mem_arburst  = ar_burst;

  assign ifu_arready = sel_ifu && ar_ready;
  assign lsu_arready = sel_lsu && ar_ready;

  wire ifu_from_clint = rd_clint_ifu;
  wire lsu_from_clint = rd_clint_lsu;

  assign ifu_rvalid = ifu_from_clint ? (clint_rvalid && (clint_rid == IFU_ID))
                                     : (mem_rvalid   && (mem_rid   == IFU_ID));
  assign ifu_rdata  = ifu_from_clint ? clint_rdata : mem_rdata;
  assign ifu_rlast  = ifu_from_clint ? clint_rlast : mem_rlast;

  assign lsu_rvalid = lsu_from_clint ? (clint_rvalid && (clint_rid == LSU_ID))
                                     : (mem_rvalid   && (mem_rid   == LSU_ID));
  assign lsu_rresp  = lsu_from_clint ? clint_rresp : mem_rresp;
  assign lsu_rdata  = lsu_from_clint ? clint_rdata : mem_rdata;
  assign lsu_rlast  = lsu_from_clint ? clint_rlast : mem_rlast;
  assign lsu_rid    = lsu_from_clint ? clint_rid   : mem_rid;

  assign clint_rready = (clint_rid == IFU_ID) ? (rd_clint_ifu && ifu_rready) :
                        (clint_rid == LSU_ID) ? (rd_clint_lsu && lsu_rready) : 1'b0;
  assign mem_rready   = (mem_rid == IFU_ID) ? (!rd_clint_ifu && ifu_rready) :
                        (mem_rid == LSU_ID) ? (!rd_clint_lsu && lsu_rready) : 1'b0;

  wire ifu_rfire = ifu_rvalid && ifu_rready && ifu_rlast;
  wire lsu_rfire = lsu_rvalid && lsu_rready && lsu_rlast;

  wire ar_open_ifu = ar_fire && sel_ifu;
  wire ar_open_lsu = ar_fire && sel_lsu;

  wire rd_close_ifu = rd_busy_ifu && ifu_rfire;
  wire rd_close_lsu = rd_busy_lsu && lsu_rfire;

  reg        clint_aw_pending;
  reg        clint_w_done;
  reg        clint_b_pending;
  reg [ 3:0] clint_bid_r;

  wire lsu_aw_clint = lsu_awvalid && ((lsu_awaddr & CLINT_MASK) == CLINT_BASE);
  wire lsu_w_clint = clint_aw_pending || lsu_aw_clint;

  wire clint_aw_fire = lsu_awvalid && lsu_aw_clint && lsu_awready;
  wire clint_w_fire  = lsu_wvalid  && lsu_w_clint  && lsu_wready;

  assign mem_awvalid  = lsu_awvalid && !lsu_aw_clint;
  assign mem_awaddr   = lsu_awaddr;
  assign mem_awid     = lsu_awid;
  assign mem_awlen    = lsu_awlen;
  assign mem_awsize   = lsu_awsize;
  assign mem_awburst  = lsu_awburst;

  assign lsu_awready  = lsu_aw_clint ? 1'b1 : mem_awready;

  assign mem_wvalid   = lsu_wvalid && !lsu_w_clint;
  assign mem_wdata    = lsu_wdata;
  assign mem_wstrb    = lsu_wstrb;
  assign mem_wlast    = lsu_wlast;

  assign lsu_wready   = lsu_w_clint ? 1'b1 : mem_wready;

  assign lsu_bvalid   = clint_b_pending ? 1'b1 : mem_bvalid;
  assign lsu_bresp    = clint_b_pending ? 2'b00 : mem_bresp;
  assign lsu_bid      = clint_b_pending ? clint_bid_r : mem_bid;

  assign mem_bready   = lsu_bready && !clint_b_pending;

  always @(posedge clk) begin
    if (rst) begin
      clint_aw_pending <= 1'b0;
      clint_w_done     <= 1'b0;
      clint_b_pending  <= 1'b0;
      clint_bid_r      <= 4'b0;
    end else begin
      if (clint_aw_fire) begin
        clint_aw_pending <= 1'b1;
        clint_bid_r      <= lsu_awid;
      end
      if (clint_w_fire)
        clint_w_done <= 1'b1;

      if ((clint_aw_pending || clint_aw_fire) &&
          (clint_w_done     || clint_w_fire)) begin
        clint_aw_pending <= 1'b0;
        clint_w_done     <= 1'b0;
        clint_b_pending  <= 1'b1;
      end

      if (clint_b_pending && lsu_bready)
        clint_b_pending <= 1'b0;
    end
  end

  always @(posedge clk) begin
    if (rst) begin
      state       <= S_IDLE;
      rr_ifu      <= 1'b1;
      rd_busy_ifu <= 1'b0;
      rd_busy_lsu <= 1'b0;
      rd_chan_ifu <= 2'd0;
      rd_chan_lsu <= 2'd0;
      rd_clint_ifu <= 1'b0;
      rd_clint_lsu <= 1'b0;
    end else begin
      case (state)
        S_IDLE: begin
          if (ar_req && !ar_ready)
            state <= sel_ifu ? S_IFU : S_LSU;
        end
        S_IFU: begin
          if (!ifu_arvalid || ar_ready)
            state <= S_IDLE;
        end
        S_LSU: begin
          if (!lsu_arvalid || ar_ready)
            state <= S_IDLE;
        end
        default: state <= S_IDLE;
      endcase

      if (ar_fire) begin
        rr_ifu <= ~sel_ifu;
      end else if (!ifu_arvalid && !lsu_arvalid) begin
        rr_ifu <= 1'b1;
      end

      if (ar_open_ifu) begin
        rd_busy_ifu <= 1'b1;
        rd_chan_ifu <= ifu_chan;
        rd_clint_ifu <= ar_clint;
      end else if (rd_close_ifu) begin
        rd_busy_ifu <= 1'b0;
        rd_clint_ifu <= 1'b0;
      end

      if (ar_open_lsu) begin
        rd_busy_lsu <= 1'b1;
        rd_chan_lsu <= lsu_chan;
        rd_clint_lsu <= ar_clint;
      end else if (rd_close_lsu) begin
        rd_busy_lsu <= 1'b0;
        rd_clint_lsu <= 1'b0;
      end
    end
  end

endmodule
