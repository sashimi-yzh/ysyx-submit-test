module ysyxSoCFull (
    input         clock,
    input         reset
);

ysyxSoCASIC asic (
    .clock  (clock  ),
    .reset  (reset  )
);

endmodule

module ysyxSoCASIC (
    input         clock,
    input         reset
);

CPU cpu (
    .clock  (clock  ),
    .reset  (reset  )
);

endmodule

module CPU (
    input         clock,
    input         reset
);
reg              Xbar_sram_ar_valid ;
reg     [31 :0]  Xbar_sram_ar_addr ;
reg     [3  :0]  Xbar_sram_ar_id ;
reg     [7  :0]  Xbar_sram_ar_len ;
reg     [2  :0]  Xbar_sram_ar_size ;
reg     [1  :0]  Xbar_sram_ar_burst ;
reg              Xbar_sram_r_ready ;
reg              Xbar_sram_aw_valid ;
reg     [31 :0]  Xbar_sram_aw_addr ;
reg     [3  :0]  Xbar_sram_aw_id ;
reg     [7  :0]  Xbar_sram_aw_len ;
reg     [2  :0]  Xbar_sram_aw_size ;
reg     [1  :0]  Xbar_sram_aw_burst ;
reg              Xbar_sram_w_valid ;
reg     [31 :0]  Xbar_sram_w_data ;
reg     [3  :0]  Xbar_sram_w_strb ;
reg              Xbar_sram_w_last ;
reg              Xbar_sram_b_ready ;
reg              Xbar_uart_ar_valid ;
reg     [31 :0]  Xbar_uart_ar_addr ;
reg     [3  :0]  Xbar_uart_ar_id ;
reg     [7  :0]  Xbar_uart_ar_len ;
reg     [2  :0]  Xbar_uart_ar_size ;
reg     [1  :0]  Xbar_uart_ar_burst ;
reg              Xbar_uart_r_ready ;
reg              Xbar_uart_aw_valid ;
reg     [31 :0]  Xbar_uart_aw_addr ;
reg     [3  :0]  Xbar_uart_aw_id ;
reg     [7  :0]  Xbar_uart_aw_len ;
reg     [2  :0]  Xbar_uart_aw_size ;
reg     [1  :0]  Xbar_uart_aw_burst ;
reg              Xbar_uart_w_valid ;
reg     [31 :0]  Xbar_uart_w_data ;
reg     [3  :0]  Xbar_uart_w_strb ;
reg              Xbar_uart_w_last ;
reg              Xbar_uart_b_ready ;
reg              cpu_acc_sram_grant ;
reg              cpu_acc_uart_grant ;
reg              io_master_arready;
reg              io_master_rvalid;
reg     [31 :0]  io_master_rdata;
reg     [1  :0]  io_master_rresp;
reg              io_master_rlast;
reg     [3  :0]  io_master_rid;
reg              io_master_awready;
reg              io_master_wready;
reg              io_master_bvalid;
reg     [1  :0]  io_master_bresp;
reg     [3  :0]  io_master_bid;

wire             sram_Xbar_ar_ready ;
wire             sram_Xbar_r_valid ;
wire    [31 :0]  sram_Xbar_r_data ;
wire    [1  :0]  sram_Xbar_r_resp ;
wire             sram_Xbar_r_last ;
wire    [3  :0]  sram_Xbar_r_id ;
wire             sram_Xbar_aw_ready ;
wire             sram_Xbar_w_ready ;
wire             sram_Xbar_b_valid ;
wire    [1  :0]  sram_Xbar_b_resp ;
wire    [3  :0]  sram_Xbar_b_id ;
wire             uart_Xbar_ar_ready ;
wire             uart_Xbar_r_valid ;
wire    [31 :0]  uart_Xbar_r_data ;
wire    [1  :0]  uart_Xbar_r_resp ;
wire             uart_Xbar_r_last ;
wire    [3  :0]  uart_Xbar_r_id ;
wire             uart_Xbar_aw_ready ;
wire             uart_Xbar_w_ready ;
wire             uart_Xbar_b_valid ;
wire    [1  :0]  uart_Xbar_b_resp ;
wire    [3  :0]  uart_Xbar_b_id ;
wire             addr_in_uart ;
wire             io_master_awvalid;
wire    [3  :0]  io_master_awid;
wire    [31 :0]  io_master_awaddr;
wire    [7  :0]  io_master_awlen;
wire    [2  :0]  io_master_awsize;
wire    [1  :0]  io_master_awburst;
wire             io_master_wvalid;
wire    [31 :0]  io_master_wdata;
wire    [3  :0]  io_master_wstrb;
wire             io_master_wlast;
wire             io_master_bready;
wire             io_master_arvalid;
wire    [3  :0]  io_master_arid;
wire    [31 :0]  io_master_araddr;
wire    [7  :0]  io_master_arlen;
wire    [2  :0]  io_master_arsize;
wire    [1  :0]  io_master_arburst;
wire             io_master_rready;
wire             cpu_req ;

ysyx_23060170 cpu (
    .clock                  (clock                  ),
    .reset                  (reset                  ),
    .io_master_awready      (io_master_awready      ),
    .io_master_awvalid      (io_master_awvalid      ),
    .io_master_awid         (io_master_awid         ),
    .io_master_awaddr       (io_master_awaddr       ),
    .io_master_awlen        (io_master_awlen        ),
    .io_master_awsize       (io_master_awsize       ),
    .io_master_awburst      (io_master_awburst      ),
    .io_master_wready       (io_master_wready       ),
    .io_master_wvalid       (io_master_wvalid       ),
    .io_master_wdata        (io_master_wdata        ),
    .io_master_wstrb        (io_master_wstrb        ),
    .io_master_wlast        (io_master_wlast        ),
    .io_master_bready       (io_master_bready       ),
    .io_master_bvalid       (io_master_bvalid       ),
    .io_master_bid          (io_master_bid          ),
    .io_master_bresp        (io_master_bresp        ),
    .io_master_arready      (io_master_arready      ),
    .io_master_arvalid      (io_master_arvalid      ),
    .io_master_arid         (io_master_arid         ),
    .io_master_araddr       (io_master_araddr       ),
    .io_master_arlen        (io_master_arlen        ),
    .io_master_arsize       (io_master_arsize       ),
    .io_master_arburst      (io_master_arburst      ),
    .io_master_rready       (io_master_rready       ),
    .io_master_rvalid       (io_master_rvalid       ),
    .io_master_rdata        (io_master_rdata        ),
    .io_master_rid          (io_master_rid          ),
    .io_master_rresp        (io_master_rresp        ),
    .io_master_rlast        (io_master_rlast        )
);


wire uart_Xbar_r_handshake = uart_Xbar_r_valid && Xbar_uart_r_ready;
wire uart_Xbar_b_handshake = uart_Xbar_b_valid && Xbar_uart_b_ready;
wire sram_Xbar_r_handshake = sram_Xbar_r_valid && Xbar_sram_r_ready;
wire sram_Xbar_b_handshake = sram_Xbar_b_valid && Xbar_sram_b_ready;

assign addr_in_uart  = io_master_awaddr >= 32'h10000000 && io_master_awaddr < 32'h10001000;
assign cpu_req = io_master_arvalid | io_master_awvalid | io_master_wvalid;

always @(posedge clock) begin
  if (reset) begin
    cpu_acc_sram_grant  <= 1'd0;
    cpu_acc_uart_grant  <= 1'd0;
  end
  else if (cpu_acc_sram_grant) begin
    if (sram_Xbar_r_handshake || sram_Xbar_b_handshake) begin
      cpu_acc_sram_grant  <= 1'd0;
    end
    else begin
      cpu_acc_sram_grant  <= cpu_acc_sram_grant;
    end
  end
  else if (cpu_acc_uart_grant) begin
    if (uart_Xbar_r_handshake || uart_Xbar_b_handshake) begin
      cpu_acc_uart_grant  <= 1'd0;
    end
    else begin
      cpu_acc_uart_grant  <= cpu_acc_uart_grant;
    end
  end
  else if (uart_Xbar_r_handshake || uart_Xbar_b_handshake) begin
    cpu_acc_uart_grant  <= 1'd0;
  end
  else if (cpu_req && addr_in_uart) begin
    cpu_acc_uart_grant  <= 1'd1;
  end
  else if (cpu_req) begin
    cpu_acc_sram_grant  <= 1'd1;
  end
  else begin
    cpu_acc_sram_grant  <= cpu_acc_sram_grant;
    cpu_acc_uart_grant  <= cpu_acc_uart_grant;
  end
end

// Xbar to sram
always @(*) begin
  if (cpu_acc_sram_grant) begin
    Xbar_sram_ar_valid = io_master_arvalid;
    Xbar_sram_ar_addr  = io_master_araddr;
    Xbar_sram_ar_id    = io_master_arid;
    Xbar_sram_ar_len   = io_master_arlen;
    Xbar_sram_ar_size  = io_master_arsize;
    Xbar_sram_ar_burst = io_master_arburst;
    Xbar_sram_r_ready  = io_master_rready;
    Xbar_sram_aw_valid = io_master_awvalid;
    Xbar_sram_aw_addr  = io_master_awaddr;
    Xbar_sram_aw_id    = io_master_awid;
    Xbar_sram_aw_len   = io_master_awlen;
    Xbar_sram_aw_size  = io_master_awsize;
    Xbar_sram_aw_burst = io_master_awburst;
    Xbar_sram_w_valid  = io_master_wvalid;
    Xbar_sram_w_data   = io_master_wdata;
    Xbar_sram_w_strb   = io_master_wstrb;
    Xbar_sram_w_last   = io_master_wlast;
    Xbar_sram_b_ready  = io_master_bready;
  end
  else begin
    Xbar_sram_ar_valid =  1'd0;
    Xbar_sram_ar_addr  = 32'd0;
    Xbar_sram_ar_id    =  4'd0;
    Xbar_sram_ar_len   =  8'd0;
    Xbar_sram_ar_size  =  3'd0;
    Xbar_sram_ar_burst =  2'd0;
    Xbar_sram_r_ready  =  1'd0;
    Xbar_sram_aw_valid =  1'd0;
    Xbar_sram_aw_addr  = 32'd0;
    Xbar_sram_aw_id    =  4'd0;
    Xbar_sram_aw_len   =  8'd0;
    Xbar_sram_aw_size  =  3'd0;
    Xbar_sram_aw_burst =  2'd0;
    Xbar_sram_w_valid  =  1'd0;
    Xbar_sram_w_data   = 32'd0;
    Xbar_sram_w_strb   =  4'd0;
    Xbar_sram_w_last   =  1'd0;
    Xbar_sram_b_ready  =  1'd0;
  end
end

// Xbar to uart
always @(*) begin
  if (cpu_acc_uart_grant) begin
    Xbar_uart_ar_valid = io_master_arvalid;
    Xbar_uart_ar_addr  = io_master_araddr;
    Xbar_uart_ar_id    = io_master_arid;
    Xbar_uart_ar_len   = io_master_arlen;
    Xbar_uart_ar_size  = io_master_arsize;
    Xbar_uart_ar_burst = io_master_arburst;
    Xbar_uart_r_ready  = io_master_rready;
    Xbar_uart_aw_valid = io_master_awvalid;
    Xbar_uart_aw_addr  = io_master_awaddr;
    Xbar_uart_aw_id    = io_master_awid;
    Xbar_uart_aw_len   = io_master_awlen;
    Xbar_uart_aw_size  = io_master_awsize;
    Xbar_uart_aw_burst = io_master_awburst;
    Xbar_uart_w_valid  = io_master_wvalid;
    Xbar_uart_w_data   = io_master_wdata;
    Xbar_uart_w_strb   = io_master_wstrb;
    Xbar_uart_w_last   = io_master_wlast;
    Xbar_uart_b_ready  = io_master_bready;
  end
  else begin
    Xbar_uart_ar_valid =  1'd0;
    Xbar_uart_ar_addr  = 32'd0;
    Xbar_uart_ar_id    =  4'd0;
    Xbar_uart_ar_len   =  8'd0;
    Xbar_uart_ar_size  =  3'd0;
    Xbar_uart_ar_burst =  2'd0;
    Xbar_uart_r_ready  =  1'd0;
    Xbar_uart_aw_valid =  1'd0;
    Xbar_uart_aw_addr  = 32'd0;
    Xbar_uart_aw_id    =  4'd0;
    Xbar_uart_aw_len   =  8'd0;
    Xbar_uart_aw_size  =  3'd0;
    Xbar_uart_aw_burst =  2'd0;
    Xbar_uart_w_valid  =  1'd0;
    Xbar_uart_w_data   = 32'd0;
    Xbar_uart_w_strb   =  4'd0;
    Xbar_uart_w_last   =  1'd0;
    Xbar_uart_b_ready  =  1'd0;
  end
end

// Xbar to cpu
always @(*) begin
  if (cpu_acc_sram_grant) begin
    io_master_arready = sram_Xbar_ar_ready;
    io_master_rvalid  = sram_Xbar_r_valid;
    io_master_rdata   = sram_Xbar_r_data;
    io_master_rresp   = sram_Xbar_r_resp;
    io_master_rlast   = sram_Xbar_r_last;
    io_master_rid     = sram_Xbar_r_id;
    io_master_awready = sram_Xbar_aw_ready;
    io_master_wready  = sram_Xbar_w_ready;
    io_master_bvalid  = sram_Xbar_b_valid;
    io_master_bresp   = sram_Xbar_b_resp;
    io_master_bid     = sram_Xbar_b_id;
  end
  else if (cpu_acc_uart_grant) begin
    io_master_arready = uart_Xbar_ar_ready;
    io_master_rvalid  = uart_Xbar_r_valid;
    io_master_rdata   = uart_Xbar_r_data;
    io_master_rresp   = uart_Xbar_r_resp;
    io_master_rlast   = uart_Xbar_r_last;
    io_master_rid     = uart_Xbar_r_id;
    io_master_awready = uart_Xbar_aw_ready;
    io_master_wready  = uart_Xbar_w_ready;
    io_master_bvalid  = uart_Xbar_b_valid;
    io_master_bresp   = uart_Xbar_b_resp;
    io_master_bid     = uart_Xbar_b_id;
  end
  else begin
    io_master_arready =  1'd0;
    io_master_rvalid  =  1'd0;
    io_master_rdata   = 32'd0;
    io_master_rresp   =  2'd0;
    io_master_rlast   =  1'd0;
    io_master_rid     =  4'd0;
    io_master_awready =  1'd0;
    io_master_wready  =  1'd0;
    io_master_bvalid  =  1'd0;
    io_master_bresp   =  2'd0;
    io_master_bid     =  4'd0;
  end
end

(* keep, keep_hierarchy = "yes", dont_touch = "true" *)
ysyx_23060170_sram sram (
  // input
  .clock              (clock             ),
  .reset              (reset             ),
  .Xbar_sram_ar_valid (Xbar_sram_ar_valid),
  .Xbar_sram_ar_addr  (Xbar_sram_ar_addr ),
  .Xbar_sram_ar_id    (Xbar_sram_ar_id   ),
  .Xbar_sram_ar_len   (Xbar_sram_ar_len  ),
  .Xbar_sram_ar_size  (Xbar_sram_ar_size ),
  .Xbar_sram_ar_burst (Xbar_sram_ar_burst),
  .Xbar_sram_r_ready  (Xbar_sram_r_ready ),
  .Xbar_sram_aw_valid (Xbar_sram_aw_valid),
  .Xbar_sram_aw_addr  (Xbar_sram_aw_addr ),
  .Xbar_sram_aw_id    (Xbar_sram_aw_id   ),
  .Xbar_sram_aw_len   (Xbar_sram_aw_len  ),
  .Xbar_sram_aw_size  (Xbar_sram_aw_size ),
  .Xbar_sram_aw_burst (Xbar_sram_aw_burst),
  .Xbar_sram_w_valid  (Xbar_sram_w_valid ),
  .Xbar_sram_w_data   (Xbar_sram_w_data  ),
  .Xbar_sram_w_strb   (Xbar_sram_w_strb  ),
  .Xbar_sram_w_last   (Xbar_sram_w_last  ),
  .Xbar_sram_b_ready  (Xbar_sram_b_ready ),
  // output
  .sram_Xbar_ar_ready (sram_Xbar_ar_ready),
  .sram_Xbar_r_valid  (sram_Xbar_r_valid ),
  .sram_Xbar_r_data   (sram_Xbar_r_data  ),
  .sram_Xbar_r_resp   (sram_Xbar_r_resp  ),
  .sram_Xbar_r_last   (sram_Xbar_r_last  ),
  .sram_Xbar_r_id     (sram_Xbar_r_id    ),
  .sram_Xbar_aw_ready (sram_Xbar_aw_ready),
  .sram_Xbar_w_ready  (sram_Xbar_w_ready ),
  .sram_Xbar_b_valid  (sram_Xbar_b_valid ),
  .sram_Xbar_b_resp   (sram_Xbar_b_resp  ),
  .sram_Xbar_b_id     (sram_Xbar_b_id    )
);

(* keep, keep_hierarchy = "yes", dont_touch = "true" *)
ysyx_23060170_uart uart (
  // input
  .clock              (clock             ),
  .reset              (reset             ),
  .Xbar_uart_ar_valid (Xbar_uart_ar_valid),
  .Xbar_uart_ar_addr  (Xbar_uart_ar_addr ),
  .Xbar_uart_ar_id    (Xbar_uart_ar_id   ),
  .Xbar_uart_ar_len   (Xbar_uart_ar_len  ),
  .Xbar_uart_ar_size  (Xbar_uart_ar_size ),
  .Xbar_uart_ar_burst (Xbar_uart_ar_burst),
  .Xbar_uart_r_ready  (Xbar_uart_r_ready ),
  .Xbar_uart_aw_valid (Xbar_uart_aw_valid),
  .Xbar_uart_aw_addr  (Xbar_uart_aw_addr ),
  .Xbar_uart_aw_id    (Xbar_uart_aw_id   ),
  .Xbar_uart_aw_len   (Xbar_uart_aw_len  ),
  .Xbar_uart_aw_size  (Xbar_uart_aw_size ),
  .Xbar_uart_aw_burst (Xbar_uart_aw_burst),
  .Xbar_uart_w_valid  (Xbar_uart_w_valid ),
  .Xbar_uart_w_data   (Xbar_uart_w_data  ),
  .Xbar_uart_w_strb   (Xbar_uart_w_strb  ),
  .Xbar_uart_w_last   (Xbar_uart_w_last  ),
  .Xbar_uart_b_ready  (Xbar_uart_b_ready ),
  // output
  .uart_Xbar_ar_ready (uart_Xbar_ar_ready),
  .uart_Xbar_r_valid  (uart_Xbar_r_valid ),
  .uart_Xbar_r_data   (uart_Xbar_r_data  ),
  .uart_Xbar_r_resp   (uart_Xbar_r_resp  ),
  .uart_Xbar_r_last   (uart_Xbar_r_last  ),
  .uart_Xbar_r_id     (uart_Xbar_r_id    ),
  .uart_Xbar_aw_ready (uart_Xbar_aw_ready),
  .uart_Xbar_w_ready  (uart_Xbar_w_ready ),
  .uart_Xbar_b_valid  (uart_Xbar_b_valid ),
  .uart_Xbar_b_resp   (uart_Xbar_b_resp  ),
  .uart_Xbar_b_id     (uart_Xbar_b_id    )
);

endmodule
