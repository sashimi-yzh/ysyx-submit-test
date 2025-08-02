module ysyx_23060299_axi_lite_xbar (
    input   wire                clock               ,
    input   wire                reset               ,   

    output  reg                 arb2xbar_awready    ,
    input   wire                arb2xbar_awvalid    ,
    input   wire     [31:0]     arb2xbar_awaddr     ,
    // input   wire     [3:0]      arb2xbar_awid       ,
    // input   wire     [7:0]      arb2xbar_awlen      ,
    input   wire     [2:0]      arb2xbar_awsize     ,
    // input   wire     [1:0]      arb2xbar_awburst    ,
    output  reg                 arb2xbar_wready     ,
    input   wire                arb2xbar_wvalid     ,
    input   wire     [31:0]     arb2xbar_wdata      ,
    input   wire     [3:0]      arb2xbar_wstrb      ,
    // input   wire                arb2xbar_wlast      ,
    input   wire                arb2xbar_bready     ,
    output  reg                 arb2xbar_bvalid     ,
    output  reg     [1:0]       arb2xbar_bresp      ,
    output  reg     [3:0]       arb2xbar_bid        ,
    output  reg                 arb2xbar_arready    ,
    input   wire                arb2xbar_arvalid    ,
    input   wire     [31:0]     arb2xbar_araddr     ,
    // input   wire     [3:0]      arb2xbar_arid       ,
    input   wire     [7:0]      arb2xbar_arlen      ,
    input   wire     [2:0]      arb2xbar_arsize     ,
    input   wire     [1:0]      arb2xbar_arburst    ,
    input   wire                arb2xbar_rready     ,
    output  reg                 arb2xbar_rvalid     ,
    output  reg     [1:0]       arb2xbar_rresp      ,
    output  reg     [31:0]      arb2xbar_rdata      ,
    output  reg                 arb2xbar_rlast      ,
    output  reg     [3:0]       arb2xbar_rid        ,

    //ysyxsoc
    input   wire                io_master_awready   ,
    output  reg                 io_master_awvalid   ,
    output  reg     [31:0]      io_master_awaddr    ,
    // output  reg     [3:0]       io_master_awid      ,
    // output  reg     [7:0]       io_master_awlen     ,
    output  reg     [2:0]       io_master_awsize    ,
    // output  reg     [1:0]       io_master_awburst   ,
    input   wire                io_master_wready    ,
    output  reg                 io_master_wvalid    ,
    output  reg     [31:0]      io_master_wdata     ,
    output  reg     [3:0]       io_master_wstrb     ,
    // output  reg                 io_master_wlast     ,
    output  reg                 io_master_bready    ,
    input   wire                io_master_bvalid    ,
    input   wire    [1:0]       io_master_bresp     ,
    input   wire    [3:0]       io_master_bid       ,
    input   wire                io_master_arready   ,
    output  reg                 io_master_arvalid   ,
    output  reg     [31:0]      io_master_araddr    ,
    // output  reg     [3:0]       io_master_arid      ,
    output  reg     [7:0]       io_master_arlen     ,
    output  reg     [2:0]       io_master_arsize    ,
    output  reg     [1:0]       io_master_arburst   ,
    output  reg                 io_master_rready    ,
    input   wire                io_master_rvalid    ,
    input   wire    [1:0]       io_master_rresp     ,
    input   wire    [31:0]      io_master_rdata     ,
    input   wire                io_master_rlast     ,
    input   wire    [3:0]       io_master_rid       ,

    // CLINT
    output  reg                 clint_awvalid     ,
    input   wire                clint_awready     ,
    output  reg     [31:0]      clint_awaddr      ,
    output  reg     [2:0]       clint_awsize      ,
    output  reg                 clint_wvalid      ,
    input   wire                clint_wready      ,
    output  reg     [31:0]      clint_wdata       ,
    output  reg     [3:0]       clint_wstrb       ,
    input   wire    [1:0]       clint_bresp       ,
    input   wire                clint_bvalid      ,
    output  reg                 clint_bready      ,
    output  reg     [31:0]      clint_araddr      ,
    output  reg                 clint_arvalid     ,
    input   wire                clint_arready     ,
    output  reg     [2:0]       clint_arsize      ,
    input   wire    [31:0]      clint_rdata       ,
    input   wire    [1:0]       clint_rresp       ,
    input   wire                clint_rvalid      ,
    output  reg                 clint_rready      
);

wire    aw_handshake        ;
wire    ar_handshake        ;
wire    clint_r_handshake   ;
wire    clint_b_handshake   ;

wire    clint_selected      ;
reg     clint_selected_r    ;

assign  aw_handshake    =   arb2xbar_awvalid    &&  arb2xbar_awready    ;
assign  ar_handshake    =   arb2xbar_arvalid    &&  arb2xbar_arready    ;
assign  clint_r_handshake   =   clint_rvalid    &&  clint_rready    ;
assign  clint_b_handshake   =   clint_bvalid    &&  clint_bready    ;
assign  clint_selected  =   ((arb2xbar_awaddr[31:24] == 8'h02)   &&  arb2xbar_awvalid) || 
                            ((arb2xbar_araddr[31:24] == 8'h02)   &&  arb2xbar_arvalid)     ;

always @(posedge clock ) begin
    if(reset)
        clint_selected_r    <=  'd0 ;
    else    if(clint_selected   &&  (aw_handshake   ||  ar_handshake))
        clint_selected_r    <=  'd1 ;
    else    if(clint_r_handshake    ||  clint_b_handshake)
        clint_selected_r    <=  'd0 ;
end

// Write address channel
always @(*) begin
    if (clint_selected) begin
        clint_awvalid       =   arb2xbar_awvalid    ;
        clint_awaddr        =   arb2xbar_awaddr     ;
        clint_awsize        =   arb2xbar_awsize     ;
        io_master_awaddr    =   'd0 ;
        io_master_awvalid   =   'd0 ;
        // io_master_awlen     =   'd0 ;
        io_master_awsize    =   'd0 ;
        // io_master_awburst   =   'd0 ;
        // io_master_awid      =   'd0 ;
        arb2xbar_awready    =   clint_awready       ;
    end else begin
        clint_awvalid       =   'd0 ;
        clint_awaddr        =   'd0 ;
        clint_awsize        =   'd0 ;
        io_master_awvalid   =   arb2xbar_awvalid    ;
        io_master_awaddr    =   arb2xbar_awaddr     ;
        // io_master_awlen     =   arb2xbar_awlen      ;
        io_master_awsize    =   arb2xbar_awsize     ;
        // io_master_awburst   =   arb2xbar_awburst    ;
        // io_master_awid      =   arb2xbar_awid       ;
        arb2xbar_awready    =   io_master_awready   ;
    end
end

// Write channel
always @(*) begin
    if (clint_selected_r) begin
        clint_wvalid        =  arb2xbar_wvalid ;
        clint_wdata         =  arb2xbar_wdata  ;
        clint_wstrb         =  arb2xbar_wstrb  ;
        io_master_wvalid    =  'd0 ;
        io_master_wdata     =  'd0 ;  
        io_master_wstrb     =  'd0 ;  
        // io_master_wlast     =  'd0 ;  
        arb2xbar_wready     =  clint_wready    ;
    end else begin
        clint_wvalid        =  'd0 ;
        clint_wdata         =  'd0 ;
        clint_wstrb         =  'd0 ;
        io_master_wvalid    =  arb2xbar_wvalid     ;
        io_master_wdata     =  arb2xbar_wdata      ;
        io_master_wstrb     =  arb2xbar_wstrb      ;
        // io_master_wlast     =  arb2xbar_wlast      ;
        arb2xbar_wready     =  io_master_wready    ;
    end
end

// B channel
always @(*) begin
    if (clint_selected_r) begin
        clint_bready        =  arb2xbar_bready  ;
        io_master_bready    =  'd0 ;
        arb2xbar_bvalid     =  clint_bvalid     ;
        arb2xbar_bresp      =  clint_bresp      ;
        arb2xbar_bid        =  'd0 ;
    end else begin
        clint_bready        =  'd0 ;
        io_master_bready    =  arb2xbar_bready  ;
        arb2xbar_bvalid     =  io_master_bvalid ;
        arb2xbar_bresp      =  io_master_bresp  ;
        arb2xbar_bid        =  io_master_bid    ;
    end
end

// AR channel
always @(*) begin
    if (clint_selected) begin
        clint_araddr        =  arb2xbar_araddr     ;
        clint_arvalid       =  arb2xbar_arvalid    ;
        clint_arsize        =  arb2xbar_arsize     ;
        io_master_arvalid   =  'd0 ;
        io_master_araddr    =  'd0 ;
        // io_master_arid      =  'd0 ;
        io_master_arlen     =  'd0 ;
        io_master_arsize    =  'd0 ;
        io_master_arburst   =  'd0 ;
        arb2xbar_arready    =  clint_arready   ;
    end else begin
        clint_araddr        =  'd0 ;
        clint_arvalid       =  'd0 ;
        clint_arsize        =  'd0 ;
        io_master_arvalid   =  arb2xbar_arvalid    ;
        io_master_araddr    =  arb2xbar_araddr     ;
        // io_master_arid      =  arb2xbar_arid       ;
        io_master_arlen     =  arb2xbar_arlen      ;
        io_master_arsize    =  arb2xbar_arsize     ;
        io_master_arburst   =  arb2xbar_arburst    ;
        arb2xbar_arready    =  io_master_arready   ;
    end
end

// R channel
always @(*) begin
    if (clint_selected_r) begin
        clint_rready        =  arb2xbar_rready ;
        io_master_rready    =  'd0 ;
        arb2xbar_rvalid     =  clint_rvalid    ;
        arb2xbar_rresp      =  clint_rresp     ;
        arb2xbar_rdata      =  clint_rdata     ;
        arb2xbar_rlast      =  'd1 ; 
        arb2xbar_rid        =  'd0 ;   
    end else begin
        clint_rready        =  'd0 ;
        io_master_rready    =  arb2xbar_rready     ;
        arb2xbar_rvalid     =  io_master_rvalid    ;
        arb2xbar_rresp      =  io_master_rresp     ;
        arb2xbar_rdata      =  io_master_rdata     ;
        arb2xbar_rlast      =  io_master_rlast     ;
        arb2xbar_rid        =  io_master_rid       ;       
    end
end

endmodule
