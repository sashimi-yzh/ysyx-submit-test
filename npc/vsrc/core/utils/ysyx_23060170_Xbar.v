module ysyx_23060170_Xbar (
  input                 clock ,
  input                 reset ,
  input                 icache_Xbar_ar_valid ,
  input        [31 :0]  icache_Xbar_ar_addr ,
  input        [3  :0]  icache_Xbar_ar_id ,
  input        [7  :0]  icache_Xbar_ar_len ,
  input        [2  :0]  icache_Xbar_ar_size ,
  input        [1  :0]  icache_Xbar_ar_burst ,
  input                 icache_Xbar_r_ready ,
  input                 icache_Xbar_aw_valid ,
  input        [31 :0]  icache_Xbar_aw_addr ,
  input        [3  :0]  icache_Xbar_aw_id ,
  input        [7  :0]  icache_Xbar_aw_len ,
  input        [2  :0]  icache_Xbar_aw_size ,
  input        [1  :0]  icache_Xbar_aw_burst ,
  input                 icache_Xbar_w_valid ,
  input        [31 :0]  icache_Xbar_w_data ,
  input        [3  :0]  icache_Xbar_w_strb ,
  input                 icache_Xbar_w_last ,
  input                 icache_Xbar_b_ready ,
  input                 lsu_Xbar_ar_valid ,
  input        [31 :0]  lsu_Xbar_ar_addr ,
  input        [3  :0]  lsu_Xbar_ar_id ,
  input        [7  :0]  lsu_Xbar_ar_len ,
  input        [2  :0]  lsu_Xbar_ar_size ,
  input        [1  :0]  lsu_Xbar_ar_burst ,
  input                 lsu_Xbar_r_ready ,
  input                 lsu_Xbar_aw_valid ,
  input        [31 :0]  lsu_Xbar_aw_addr ,
  input        [3  :0]  lsu_Xbar_aw_id ,
  input        [7  :0]  lsu_Xbar_aw_len ,
  input        [2  :0]  lsu_Xbar_aw_size ,
  input        [1  :0]  lsu_Xbar_aw_burst ,
  input                 lsu_Xbar_w_valid ,
  input        [31 :0]  lsu_Xbar_w_data ,
  input        [3  :0]  lsu_Xbar_w_strb ,
  input                 lsu_Xbar_w_last ,
  input                 lsu_Xbar_b_ready ,
  input                 io_master_awready ,
  input                 io_master_wready ,
  input                 io_master_bvalid ,
  input        [3  :0]  io_master_bid ,
  input        [1  :0]  io_master_bresp ,
  input                 io_master_arready ,
  input                 io_master_rvalid ,
  input        [31 :0]  io_master_rdata ,
  input        [3  :0]  io_master_rid ,
  input        [1  :0]  io_master_rresp ,
  input                 io_master_rlast ,
  output  reg           Xbar_icache_ar_ready ,
  output  reg           Xbar_icache_r_valid ,
  output  reg  [31 :0]  Xbar_icache_r_data ,
  output  reg  [1  :0]  Xbar_icache_r_resp ,
  output  reg           Xbar_icache_r_last ,
  output  reg  [3  :0]  Xbar_icache_r_id ,
  output  reg           Xbar_icache_aw_ready ,
  output  reg           Xbar_icache_w_ready ,
  output  reg           Xbar_icache_b_valid ,
  output  reg  [1  :0]  Xbar_icache_b_resp ,
  output  reg  [3  :0]  Xbar_icache_b_id ,
  output  reg           Xbar_lsu_ar_ready ,
  output  reg           Xbar_lsu_r_valid ,
  output  reg  [31 :0]  Xbar_lsu_r_data ,
  output  reg  [1  :0]  Xbar_lsu_r_resp ,
  output  reg           Xbar_lsu_r_last ,
  output  reg  [3  :0]  Xbar_lsu_r_id ,
  output  reg           Xbar_lsu_aw_ready ,
  output  reg           Xbar_lsu_w_ready ,
  output  reg           Xbar_lsu_b_valid ,
  output  reg  [1  :0]  Xbar_lsu_b_resp ,
  output  reg  [3  :0]  Xbar_lsu_b_id ,
  output  reg           io_master_awvalid ,
  output  reg  [3  :0]  io_master_awid ,
  output  reg  [31 :0]  io_master_awaddr ,
  output  reg  [7  :0]  io_master_awlen ,
  output  reg  [2  :0]  io_master_awsize ,
  output  reg  [1  :0]  io_master_awburst ,
  output  reg           io_master_wvalid ,
  output  reg  [31 :0]  io_master_wdata ,
  output  reg  [3  :0]  io_master_wstrb ,
  output  reg           io_master_wlast ,
  output  reg           io_master_bready ,
  output  reg           io_master_arvalid ,
  output  reg  [3  :0]  io_master_arid ,
  output  reg  [31 :0]  io_master_araddr ,
  output  reg  [7  :0]  io_master_arlen ,
  output  reg  [2  :0]  io_master_arsize ,
  output  reg  [1  :0]  io_master_arburst ,
  output  reg           io_master_rready 
);

reg              Xbar_clint_ar_valid ;
reg     [31 :0]  Xbar_clint_ar_addr ;
reg     [3  :0]  Xbar_clint_ar_id ;
reg     [7  :0]  Xbar_clint_ar_len ;
reg     [2  :0]  Xbar_clint_ar_size ;
reg     [1  :0]  Xbar_clint_ar_burst ;
reg              Xbar_clint_r_ready ;
reg              Xbar_clint_aw_valid ;
reg     [31 :0]  Xbar_clint_aw_addr ;
reg     [3  :0]  Xbar_clint_aw_id ;
reg     [7  :0]  Xbar_clint_aw_len ;
reg     [2  :0]  Xbar_clint_aw_size ;
reg     [1  :0]  Xbar_clint_aw_burst ;
reg              Xbar_clint_w_valid ;
reg     [31 :0]  Xbar_clint_w_data ;
reg     [3  :0]  Xbar_clint_w_strb ;
reg              Xbar_clint_w_last ;
reg              Xbar_clint_b_ready ;
reg              icache_acc_sram_grant /*verilator public*/;
reg              lsu_acc_sram_grant ;
reg              lsu_acc_clint_grant ;

wire             clint_Xbar_ar_ready ;
wire             clint_Xbar_r_valid ;
wire    [31 :0]  clint_Xbar_r_data ;
wire    [1  :0]  clint_Xbar_r_resp ;
wire             clint_Xbar_r_last ;
wire    [3  :0]  clint_Xbar_r_id ;
wire             clint_Xbar_aw_ready ;
wire             clint_Xbar_w_ready ;
wire             clint_Xbar_b_valid ;
wire    [1  :0]  clint_Xbar_b_resp ;
wire    [3  :0]  clint_Xbar_b_id ;
wire             icache_req ;
wire             lsu_req ;
wire             addr_in_clint ;
wire clint_Xbar_r_handshake = clint_Xbar_r_valid && Xbar_clint_r_ready;
wire clint_Xbar_b_handshake = clint_Xbar_b_valid && Xbar_clint_b_ready;
wire sram_Xbar_r_handshake = io_master_rvalid && io_master_rready;
wire sram_Xbar_b_handshake = io_master_bvalid && io_master_bready;

assign icache_req = icache_Xbar_ar_valid;
assign lsu_req = lsu_Xbar_ar_valid | lsu_Xbar_aw_valid | lsu_Xbar_w_valid;
assign addr_in_clint = lsu_Xbar_ar_addr == 32'h200bff8
                     | lsu_Xbar_ar_addr == 32'h200bffc;

always @(posedge clock) begin
  if (reset) begin
    icache_acc_sram_grant  <= 1'd0;
    lsu_acc_sram_grant  <= 1'd0;
    lsu_acc_clint_grant <= 1'd0;
  end
  else if (icache_acc_sram_grant) begin
    if (sram_Xbar_r_handshake && io_master_rlast) begin
      icache_acc_sram_grant  <= 1'd0;
    end
    else begin
      icache_acc_sram_grant  <= icache_acc_sram_grant;
    end
  end
  else if (lsu_acc_sram_grant) begin
    if (sram_Xbar_r_handshake || sram_Xbar_b_handshake) begin
      lsu_acc_sram_grant  <= 1'd0;
    end
    else begin
      lsu_acc_sram_grant  <= lsu_acc_sram_grant;
    end
  end
  else if (lsu_acc_clint_grant) begin
    if (clint_Xbar_r_handshake || clint_Xbar_b_handshake) begin
      lsu_acc_clint_grant  <= 1'd0;
    end
    else begin
      lsu_acc_clint_grant  <= lsu_acc_clint_grant;
    end
  end
  else if (icache_req) begin
    icache_acc_sram_grant  <= 1'd1;
    lsu_acc_sram_grant  <= 1'd0;
    lsu_acc_clint_grant <= 1'd0;
  end
  else if (lsu_req && addr_in_clint) begin
    icache_acc_sram_grant  <= 1'd0;
    lsu_acc_clint_grant <= 1'd1;
  end
  else if (lsu_req) begin
    icache_acc_sram_grant  <= 1'd0;
    lsu_acc_sram_grant  <= 1'd1;
  end
  else begin
    icache_acc_sram_grant  <= icache_acc_sram_grant;
    lsu_acc_sram_grant  <= lsu_acc_sram_grant;
    lsu_acc_clint_grant <= lsu_acc_clint_grant;
  end
end

// Xbar to sram
always @(*) begin
  if (icache_acc_sram_grant) begin
    io_master_arvalid = icache_Xbar_ar_valid;
    io_master_araddr  = icache_Xbar_ar_addr;
    io_master_arid    = icache_Xbar_ar_id;
    io_master_arlen   = icache_Xbar_ar_len;
    io_master_arsize  = icache_Xbar_ar_size;
    io_master_arburst = icache_Xbar_ar_burst;
    io_master_rready  = icache_Xbar_r_ready;
    io_master_awvalid = icache_Xbar_aw_valid;
    io_master_awaddr  = icache_Xbar_aw_addr;
    io_master_awid    = icache_Xbar_aw_id;
    io_master_awlen   = icache_Xbar_aw_len;
    io_master_awsize  = icache_Xbar_aw_size;
    io_master_awburst = icache_Xbar_aw_burst;
    io_master_wvalid  = icache_Xbar_w_valid;
    io_master_wdata   = icache_Xbar_w_data;
    io_master_wstrb   = icache_Xbar_w_strb;
    io_master_wlast   = icache_Xbar_w_last;
    io_master_bready  = icache_Xbar_b_ready;
  end
  else if (lsu_acc_sram_grant) begin
    io_master_arvalid = lsu_Xbar_ar_valid;
    io_master_araddr  = lsu_Xbar_ar_addr;
    io_master_arid    = lsu_Xbar_ar_id;
    io_master_arlen   = lsu_Xbar_ar_len;
    io_master_arsize  = lsu_Xbar_ar_size;
    io_master_arburst = lsu_Xbar_ar_burst;
    io_master_rready  = lsu_Xbar_r_ready;
    io_master_awvalid = lsu_Xbar_aw_valid;
    io_master_awaddr  = lsu_Xbar_aw_addr;
    io_master_awid    = lsu_Xbar_aw_id;
    io_master_awlen   = lsu_Xbar_aw_len;
    io_master_awsize  = lsu_Xbar_aw_size;
    io_master_awburst = lsu_Xbar_aw_burst;
    io_master_wvalid  = lsu_Xbar_w_valid;
    io_master_wdata   = lsu_Xbar_w_data;
    io_master_wstrb   = lsu_Xbar_w_strb;
    io_master_wlast   = lsu_Xbar_w_last;
    io_master_bready  = lsu_Xbar_b_ready;
  end
  else begin
    io_master_arvalid =  1'd0;
    io_master_araddr  = 32'd0;
    io_master_arid    =  4'd0;
    io_master_arlen   =  8'd0;
    io_master_arsize  =  3'd0;
    io_master_arburst =  2'd0;
    io_master_rready  =  1'd0;
    io_master_awvalid =  1'd0;
    io_master_awaddr  = 32'd0;
    io_master_awid    =  4'd0;
    io_master_awlen   =  8'd0;
    io_master_awsize  =  3'd0;
    io_master_awburst =  2'd0;
    io_master_wvalid  =  1'd0;
    io_master_wdata   = 32'd0;
    io_master_wstrb   =  4'd0;
    io_master_wlast   =  1'd0;
    io_master_bready  =  1'd0;
  end
end

// Xbar to clint
always @(*) begin
  if (lsu_acc_clint_grant) begin
    Xbar_clint_ar_valid = lsu_Xbar_ar_valid;
    Xbar_clint_ar_addr  = lsu_Xbar_ar_addr;
    Xbar_clint_ar_id    = lsu_Xbar_ar_id;
    Xbar_clint_ar_len   = lsu_Xbar_ar_len;
    Xbar_clint_ar_size  = lsu_Xbar_ar_size;
    Xbar_clint_ar_burst = lsu_Xbar_ar_burst;
    Xbar_clint_r_ready  = lsu_Xbar_r_ready;
    Xbar_clint_aw_valid = lsu_Xbar_aw_valid;
    Xbar_clint_aw_addr  = lsu_Xbar_aw_addr;
    Xbar_clint_aw_id    = lsu_Xbar_aw_id;
    Xbar_clint_aw_len   = lsu_Xbar_aw_len;
    Xbar_clint_aw_size  = lsu_Xbar_aw_size;
    Xbar_clint_aw_burst = lsu_Xbar_aw_burst;
    Xbar_clint_w_valid  = lsu_Xbar_w_valid;
    Xbar_clint_w_data   = lsu_Xbar_w_data;
    Xbar_clint_w_strb   = lsu_Xbar_w_strb;
    Xbar_clint_w_last   = lsu_Xbar_w_last;
    Xbar_clint_b_ready  = lsu_Xbar_b_ready;
  end
  else begin
    Xbar_clint_ar_valid =  1'd0;
    Xbar_clint_ar_addr  = 32'd0;
    Xbar_clint_ar_id    =  4'd0;
    Xbar_clint_ar_len   =  8'd0;
    Xbar_clint_ar_size  =  3'd0;
    Xbar_clint_ar_burst =  2'd0;
    Xbar_clint_r_ready  =  1'd0;
    Xbar_clint_aw_valid =  1'd0;
    Xbar_clint_aw_addr  = 32'd0;
    Xbar_clint_aw_id    =  4'd0;
    Xbar_clint_aw_len   =  8'd0;
    Xbar_clint_aw_size  =  3'd0;
    Xbar_clint_aw_burst =  2'd0;
    Xbar_clint_w_valid  =  1'd0;
    Xbar_clint_w_data   = 32'd0;
    Xbar_clint_w_strb   =  4'd0;
    Xbar_clint_w_last   =  1'd0;
    Xbar_clint_b_ready  =  1'd0;
  end
end

// Xbar to icache
always @(*) begin
  if (icache_acc_sram_grant) begin
    Xbar_icache_ar_ready = io_master_arready;
    Xbar_icache_r_valid  = io_master_rvalid;
    Xbar_icache_r_data   = io_master_rdata;
    Xbar_icache_r_resp   = io_master_rresp;
    Xbar_icache_r_last   = io_master_rlast;
    Xbar_icache_r_id     = io_master_rid;
    Xbar_icache_aw_ready = io_master_awready;
    Xbar_icache_w_ready  = io_master_wready;
    Xbar_icache_b_valid  = io_master_bvalid;
    Xbar_icache_b_resp   = io_master_bresp;
    Xbar_icache_b_id     = io_master_bid;
  end
  else begin
    Xbar_icache_ar_ready =  1'd0;
    Xbar_icache_r_valid  =  1'd0;
    Xbar_icache_r_data   = 32'd0;
    Xbar_icache_r_resp   =  2'd0;
    Xbar_icache_r_last   =  1'd0;
    Xbar_icache_r_id     =  4'd0;
    Xbar_icache_aw_ready =  1'd0;
    Xbar_icache_w_ready  =  1'd0;
    Xbar_icache_b_valid  =  1'd0;
    Xbar_icache_b_resp   =  2'd0;
    Xbar_icache_b_id     =  4'd0;
  end
end

// Xbar to lsu
always @(*) begin
  if (lsu_acc_sram_grant) begin
    Xbar_lsu_ar_ready = io_master_arready;
    Xbar_lsu_r_valid  = io_master_rvalid;
    Xbar_lsu_r_data   = io_master_rdata;
    Xbar_lsu_r_resp   = io_master_rresp;
    Xbar_lsu_r_last   = io_master_rlast;
    Xbar_lsu_r_id     = io_master_rid;
    Xbar_lsu_aw_ready = io_master_awready;
    Xbar_lsu_w_ready  = io_master_wready;
    Xbar_lsu_b_valid  = io_master_bvalid;
    Xbar_lsu_b_resp   = io_master_bresp;
    Xbar_lsu_b_id     = io_master_bid;
  end
  else if (lsu_acc_clint_grant) begin
    Xbar_lsu_ar_ready = clint_Xbar_ar_ready;
    Xbar_lsu_r_valid  = clint_Xbar_r_valid;
    Xbar_lsu_r_data   = clint_Xbar_r_data;
    Xbar_lsu_r_resp   = clint_Xbar_r_resp;
    Xbar_lsu_r_last   = clint_Xbar_r_last;
    Xbar_lsu_r_id     = clint_Xbar_r_id;
    Xbar_lsu_aw_ready = clint_Xbar_aw_ready;
    Xbar_lsu_w_ready  = clint_Xbar_w_ready;
    Xbar_lsu_b_valid  = clint_Xbar_b_valid;
    Xbar_lsu_b_resp   = clint_Xbar_b_resp;
    Xbar_lsu_b_id     = clint_Xbar_b_id;
  end
  else begin
    Xbar_lsu_ar_ready =  1'd0;
    Xbar_lsu_r_valid  =  1'd0;
    Xbar_lsu_r_data   = 32'd0;
    Xbar_lsu_r_resp   =  2'd0;
    Xbar_lsu_r_last   =  1'd0;
    Xbar_lsu_r_id     =  4'd0;
    Xbar_lsu_aw_ready =  1'd0;
    Xbar_lsu_w_ready  =  1'd0;
    Xbar_lsu_b_valid  =  1'd0;
    Xbar_lsu_b_resp   =  2'd0;
    Xbar_lsu_b_id     =  4'd0;
  end
end

//======================================================
//               instance modules
//======================================================
ysyx_23060170_clint clint (
  // input
  .clock               (clock              ),
  .reset               (reset              ),
  .Xbar_clint_ar_valid (Xbar_clint_ar_valid),
  .Xbar_clint_ar_addr  (Xbar_clint_ar_addr ),
  .Xbar_clint_ar_id    (Xbar_clint_ar_id   ),
  .Xbar_clint_ar_len   (Xbar_clint_ar_len  ),
  .Xbar_clint_ar_size  (Xbar_clint_ar_size ),
  .Xbar_clint_ar_burst (Xbar_clint_ar_burst),
  .Xbar_clint_r_ready  (Xbar_clint_r_ready ),
  .Xbar_clint_aw_valid (Xbar_clint_aw_valid),
  .Xbar_clint_aw_addr  (Xbar_clint_aw_addr ),
  .Xbar_clint_aw_id    (Xbar_clint_aw_id   ),
  .Xbar_clint_aw_len   (Xbar_clint_aw_len  ),
  .Xbar_clint_aw_size  (Xbar_clint_aw_size ),
  .Xbar_clint_aw_burst (Xbar_clint_aw_burst),
  .Xbar_clint_w_valid  (Xbar_clint_w_valid ),
  .Xbar_clint_w_data   (Xbar_clint_w_data  ),
  .Xbar_clint_w_strb   (Xbar_clint_w_strb  ),
  .Xbar_clint_w_last   (Xbar_clint_w_last  ),
  .Xbar_clint_b_ready  (Xbar_clint_b_ready ),
  // outpu
  .clint_Xbar_ar_ready (clint_Xbar_ar_ready),
  .clint_Xbar_r_valid  (clint_Xbar_r_valid ),
  .clint_Xbar_r_data   (clint_Xbar_r_data  ),
  .clint_Xbar_r_resp   (clint_Xbar_r_resp  ),
  .clint_Xbar_r_last   (clint_Xbar_r_last  ),
  .clint_Xbar_r_id     (clint_Xbar_r_id    ),
  .clint_Xbar_aw_ready (clint_Xbar_aw_ready),
  .clint_Xbar_w_ready  (clint_Xbar_w_ready ),
  .clint_Xbar_b_valid  (clint_Xbar_b_valid ),
  .clint_Xbar_b_resp   (clint_Xbar_b_resp  ),
  .clint_Xbar_b_id     (clint_Xbar_b_id    )
);

endmodule
