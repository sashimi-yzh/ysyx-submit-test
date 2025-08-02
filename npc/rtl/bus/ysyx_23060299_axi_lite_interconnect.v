module  ysyx_23060299_axi_lite_interconnect(
    input   wire            clock           ,
    input   wire            reset           ,  

    // IFU AXI signals
    input   wire    [31:0]  ifu_araddr      ,
    input   wire            ifu_arvalid     ,
    output  wire            ifu_arready     ,
    input   wire    [7:0]   ifu_arlen       ,
    input   wire    [2:0]   ifu_arsize      ,
    input   wire    [1:0]   ifu_arburst     ,
    output  wire    [31:0]  ifu_rdata       ,
    output  wire    [1:0]   ifu_rresp       ,
    output  wire            ifu_rvalid      ,
    input   wire            ifu_rready      ,
    output  wire            ifu_rlast       ,

    // LSU AXI signals
    input   wire            lsu_awvalid     ,
    output  wire            lsu_awready     ,
    input   wire    [31:0]  lsu_awaddr      ,
    input   wire    [2:0]   lsu_awsize      ,
    input   wire            lsu_wvalid      ,
    output  wire            lsu_wready      ,
    input   wire    [31:0]  lsu_wdata       ,
    input   wire    [3:0]   lsu_wstrb       ,
    output  wire    [1:0]   lsu_bresp       ,
    output  wire            lsu_bvalid      ,
    input   wire            lsu_bready      ,
    input   wire    [31:0]  lsu_araddr      ,
    input   wire            lsu_arvalid     ,
    output  wire            lsu_arready     ,
    input   wire    [2:0]   lsu_arsize      ,
    output  wire    [31:0]  lsu_rdata       ,
    output  wire    [1:0]   lsu_rresp       ,
    output  wire            lsu_rvalid      ,
    input   wire            lsu_rready      ,

    //ysyxsoc
    input   wire            io_master_awready   ,
    output  wire            io_master_awvalid   ,
    output  wire    [31:0]  io_master_awaddr    ,
    output  wire    [3:0]   io_master_awid      ,
    output  wire    [7:0]   io_master_awlen     ,
    output  wire    [2:0]   io_master_awsize    ,
    output  wire    [1:0]   io_master_awburst   ,
    input   wire            io_master_wready    ,
    output  wire            io_master_wvalid    ,
    output  wire    [31:0]  io_master_wdata     ,
    output  wire    [3:0]   io_master_wstrb     ,
    output  wire            io_master_wlast     ,
    output  wire            io_master_bready    ,
    input   wire            io_master_bvalid    ,
    input   wire    [1:0]   io_master_bresp     ,
    input   wire    [3:0]   io_master_bid       ,
    input   wire            io_master_arready   ,
    output  wire            io_master_arvalid   ,
    output  wire    [31:0]  io_master_araddr    ,
    output  wire    [3:0]   io_master_arid      ,
    output  wire    [7:0]   io_master_arlen     ,
    output  wire    [2:0]   io_master_arsize    ,
    output  wire    [1:0]   io_master_arburst   ,
    output  wire            io_master_rready    ,
    input   wire            io_master_rvalid    ,
    input   wire    [1:0]   io_master_rresp     ,
    input   wire    [31:0]  io_master_rdata     ,
    input   wire            io_master_rlast     ,
    input   wire    [3:0]   io_master_rid       ,

    // CLINT
    output  wire            clint_awvalid     ,
    input   wire            clint_awready     ,
    output  wire    [31:0]  clint_awaddr      ,
    output  wire    [2:0]   clint_awsize      ,
    output  wire            clint_wvalid      ,
    input   wire            clint_wready      ,
    output  wire    [31:0]  clint_wdata       ,
    output  wire    [3:0]   clint_wstrb       ,
    input   wire    [1:0]   clint_bresp       ,
    input   wire            clint_bvalid      ,
    output  wire            clint_bready      ,
    output  wire    [31:0]  clint_araddr      ,
    output  wire            clint_arvalid     ,
    input   wire            clint_arready     ,
    output  wire    [2:0]   clint_arsize      ,
    input   wire    [31:0]  clint_rdata       ,
    input   wire    [1:0]   clint_rresp       ,
    input   wire            clint_rvalid      ,
    output  wire            clint_rready      
);

wire            arb2xbar_awready   ;
wire            arb2xbar_awvalid   ;
wire    [31:0]  arb2xbar_awaddr    ;
wire    [3:0]   arb2xbar_awid      ;
wire    [7:0]   arb2xbar_awlen     ;
wire    [2:0]   arb2xbar_awsize    ;
wire    [1:0]   arb2xbar_awburst   ;
wire            arb2xbar_wready    ;
wire            arb2xbar_wvalid    ;
wire    [31:0]  arb2xbar_wdata     ;
wire    [3:0]   arb2xbar_wstrb     ;
wire            arb2xbar_wlast     ;
wire            arb2xbar_bready    ;
wire            arb2xbar_bvalid    ;
wire    [1:0]   arb2xbar_bresp     ;
wire    [3:0]   arb2xbar_bid       ;
wire            arb2xbar_arready   ;
wire            arb2xbar_arvalid   ;
wire    [31:0]  arb2xbar_araddr    ;
wire    [3:0]   arb2xbar_arid      ;
wire    [7:0]   arb2xbar_arlen     ;
wire    [2:0]   arb2xbar_arsize    ;
wire    [1:0]   arb2xbar_arburst   ;
wire            arb2xbar_rready    ;
wire            arb2xbar_rvalid    ;
wire    [1:0]   arb2xbar_rresp     ;
wire    [31:0]  arb2xbar_rdata     ;
wire            arb2xbar_rlast     ;
wire    [3:0]   arb2xbar_rid       ;


ysyx_23060299_axi_lite_arbiter ysyx_23060299_axi_lite_arbiter(
    .clock                  (clock ),
    .reset                  (reset ),   

    .ifu_araddr             (ifu_araddr     ),
    .ifu_arvalid            (ifu_arvalid    ),
    .ifu_arready            (ifu_arready    ),
    .ifu_arlen              (ifu_arlen      ),
    .ifu_arsize             (ifu_arsize     ),
    .ifu_arburst            (ifu_arburst    ),
    .ifu_rdata              (ifu_rdata      ),
    .ifu_rresp              (ifu_rresp      ),
    .ifu_rvalid             (ifu_rvalid     ),
    .ifu_rready             (ifu_rready     ),
    .ifu_rlast              (ifu_rlast      ),

    .lsu_awvalid            (lsu_awvalid    ),
    .lsu_awready            (lsu_awready    ),
    .lsu_awaddr             (lsu_awaddr     ),
    .lsu_awsize             (lsu_awsize     ),
    .lsu_wvalid             (lsu_wvalid     ),
    .lsu_wready             (lsu_wready     ),
    .lsu_wdata              (lsu_wdata      ),
    .lsu_wstrb              (lsu_wstrb      ),
    .lsu_bresp              (lsu_bresp      ),
    .lsu_bvalid             (lsu_bvalid     ),
    .lsu_bready             (lsu_bready     ),
    .lsu_araddr             (lsu_araddr     ),
    .lsu_arvalid            (lsu_arvalid    ),
    .lsu_arready            (lsu_arready    ),
    .lsu_arsize             (lsu_arsize     ),
    .lsu_rdata              (lsu_rdata      ),
    .lsu_rresp              (lsu_rresp      ),
    .lsu_rvalid             (lsu_rvalid     ),
    .lsu_rready             (lsu_rready     ),


    .io_master_awready      (arb2xbar_awready  ),
    .io_master_awvalid      (arb2xbar_awvalid  ),
    .io_master_awaddr       (arb2xbar_awaddr   ),
    // .io_master_awid         (arb2xbar_awid     ),
    // .io_master_awlen        (arb2xbar_awlen    ),
    .io_master_awsize       (arb2xbar_awsize   ),
    // .io_master_awburst      (arb2xbar_awburst  ),
    .io_master_wready       (arb2xbar_wready   ),
    .io_master_wvalid       (arb2xbar_wvalid   ),
    .io_master_wdata        (arb2xbar_wdata    ),
    .io_master_wstrb        (arb2xbar_wstrb    ),
    // .io_master_wlast        (arb2xbar_wlast    ),
    .io_master_bready       (arb2xbar_bready   ),
    .io_master_bvalid       (arb2xbar_bvalid   ),
    .io_master_bresp        (arb2xbar_bresp    ),
    .io_master_bid          (arb2xbar_bid      ),
    .io_master_arready      (arb2xbar_arready  ),
    .io_master_arvalid      (arb2xbar_arvalid  ),
    .io_master_araddr       (arb2xbar_araddr   ),
    // .io_master_arid         (arb2xbar_arid     ),
    .io_master_arlen        (arb2xbar_arlen    ),
    .io_master_arsize       (arb2xbar_arsize   ),
    .io_master_arburst      (arb2xbar_arburst  ),
    .io_master_rready       (arb2xbar_rready   ),
    .io_master_rvalid       (arb2xbar_rvalid   ),
    .io_master_rresp        (arb2xbar_rresp    ),
    .io_master_rdata        (arb2xbar_rdata    ),
    .io_master_rlast        (arb2xbar_rlast    ),
    .io_master_rid          (arb2xbar_rid      )
);

ysyx_23060299_axi_lite_xbar   ysyx_23060299_axi_lite_xbar(
    .clock              (clock  ), 
    .reset              (reset  ), 

    .arb2xbar_awready   (arb2xbar_awready   ), 
    .arb2xbar_awvalid   (arb2xbar_awvalid   ), 
    .arb2xbar_awaddr    (arb2xbar_awaddr    ), 
    // .arb2xbar_awid      (arb2xbar_awid      ), 
    // .arb2xbar_awlen     (arb2xbar_awlen     ), 
    .arb2xbar_awsize    (arb2xbar_awsize    ), 
    // .arb2xbar_awburst   (arb2xbar_awburst   ), 
    .arb2xbar_wready    (arb2xbar_wready    ), 
    .arb2xbar_wvalid    (arb2xbar_wvalid    ), 
    .arb2xbar_wdata     (arb2xbar_wdata     ), 
    .arb2xbar_wstrb     (arb2xbar_wstrb     ), 
    // .arb2xbar_wlast     (arb2xbar_wlast     ), 
    .arb2xbar_bready    (arb2xbar_bready    ), 
    .arb2xbar_bvalid    (arb2xbar_bvalid    ), 
    .arb2xbar_bresp     (arb2xbar_bresp     ), 
    .arb2xbar_bid       (arb2xbar_bid       ), 
    .arb2xbar_arready   (arb2xbar_arready   ), 
    .arb2xbar_arvalid   (arb2xbar_arvalid   ), 
    .arb2xbar_araddr    (arb2xbar_araddr    ), 
    // .arb2xbar_arid      (arb2xbar_arid      ), 
    .arb2xbar_arlen     (arb2xbar_arlen     ), 
    .arb2xbar_arsize    (arb2xbar_arsize    ), 
    .arb2xbar_arburst   (arb2xbar_arburst   ), 
    .arb2xbar_rready    (arb2xbar_rready    ), 
    .arb2xbar_rvalid    (arb2xbar_rvalid    ), 
    .arb2xbar_rresp     (arb2xbar_rresp     ), 
    .arb2xbar_rdata     (arb2xbar_rdata     ), 
    .arb2xbar_rlast     (arb2xbar_rlast     ), 
    .arb2xbar_rid       (arb2xbar_rid       ), 

    .io_master_awready  (io_master_awready ), 
    .io_master_awvalid  (io_master_awvalid ), 
    .io_master_awaddr   (io_master_awaddr  ), 
    // .io_master_awid     (io_master_awid    ), 
    // .io_master_awlen    (io_master_awlen   ), 
    .io_master_awsize   (io_master_awsize  ), 
    // .io_master_awburst  (io_master_awburst ), 
    .io_master_wready   (io_master_wready  ), 
    .io_master_wvalid   (io_master_wvalid  ), 
    .io_master_wdata    (io_master_wdata   ), 
    .io_master_wstrb    (io_master_wstrb   ), 
    // .io_master_wlast    (io_master_wlast   ), 
    .io_master_bready   (io_master_bready  ), 
    .io_master_bvalid   (io_master_bvalid  ), 
    .io_master_bresp    (io_master_bresp   ), 
    .io_master_bid      (io_master_bid     ), 
    .io_master_arready  (io_master_arready ), 
    .io_master_arvalid  (io_master_arvalid ), 
    .io_master_araddr   (io_master_araddr  ), 
    // .io_master_arid     (io_master_arid    ), 
    .io_master_arlen    (io_master_arlen   ), 
    .io_master_arsize   (io_master_arsize  ), 
    .io_master_arburst  (io_master_arburst ), 
    .io_master_rready   (io_master_rready  ), 
    .io_master_rvalid   (io_master_rvalid  ), 
    .io_master_rresp    (io_master_rresp   ), 
    .io_master_rdata    (io_master_rdata   ), 
    .io_master_rlast    (io_master_rlast   ), 
    .io_master_rid      (io_master_rid     ), 

    .clint_awvalid      (clint_awvalid  ), 
    .clint_awready      (clint_awready  ), 
    .clint_awaddr       (clint_awaddr   ), 
    .clint_awsize       (clint_awsize   ), 
    .clint_wvalid       (clint_wvalid   ), 
    .clint_wready       (clint_wready   ), 
    .clint_wdata        (clint_wdata    ), 
    .clint_wstrb        (clint_wstrb    ), 
    .clint_bresp        (clint_bresp    ), 
    .clint_bvalid       (clint_bvalid   ), 
    .clint_bready       (clint_bready   ), 
    .clint_araddr       (clint_araddr   ), 
    .clint_arvalid      (clint_arvalid  ), 
    .clint_arready      (clint_arready  ), 
    .clint_arsize       (clint_arsize   ), 
    .clint_rdata        (clint_rdata    ), 
    .clint_rresp        (clint_rresp    ), 
    .clint_rvalid       (clint_rvalid   ), 
    .clint_rready       (clint_rready   )
);

assign  io_master_awid      =   'd0     ;
assign  io_master_awlen     =   'd0     ;
assign  io_master_awburst   =   2'b00   ;
assign  io_master_wlast     =   'd1     ;
assign  io_master_arid      =   'd0     ;

endmodule
