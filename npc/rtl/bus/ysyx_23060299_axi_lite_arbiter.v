module ysyx_23060299_axi_lite_arbiter (
    input   wire            clock           ,
    input   wire            reset           ,   

    // IFU AXI signals
    input   wire    [31:0]  ifu_araddr      ,
    input   wire            ifu_arvalid     ,
    output  reg             ifu_arready     ,
    input   wire    [7:0]   ifu_arlen       ,
    input   wire    [2:0]   ifu_arsize      ,
    input   wire    [1:0]   ifu_arburst     ,

    output  reg     [31:0]  ifu_rdata       ,
    output  reg     [1:0]   ifu_rresp       ,
    output  reg             ifu_rvalid      ,
    input   wire            ifu_rready      ,
    output  reg             ifu_rlast       ,

    // LSU AXI signals
    input   wire            lsu_awvalid     ,
    output  reg             lsu_awready     ,
    input   wire    [31:0]  lsu_awaddr      ,
    input   wire    [2:0]   lsu_awsize      ,

    input   wire            lsu_wvalid      ,
    output  reg             lsu_wready      ,
    input   wire    [31:0]  lsu_wdata       ,
    input   wire    [3:0]   lsu_wstrb       ,

    output  reg     [1:0]   lsu_bresp       ,
    output  reg             lsu_bvalid      ,
    input   wire            lsu_bready      ,

    input   wire    [31:0]  lsu_araddr      ,
    input   wire            lsu_arvalid     ,
    output  reg             lsu_arready     ,
    input   wire    [2:0]   lsu_arsize      ,

    output  reg     [31:0]  lsu_rdata       ,
    output  reg     [1:0]   lsu_rresp       ,
    output  reg             lsu_rvalid      ,
    input   wire            lsu_rready      ,


    input   wire            io_master_awready   ,
    output  reg             io_master_awvalid   ,
    output  reg     [31:0]  io_master_awaddr    ,
    // output  wire    [3:0]   io_master_awid      ,
    // output  wire    [7:0]   io_master_awlen     ,
    output  reg     [2:0]   io_master_awsize    ,
    // output  wire    [1:0]   io_master_awburst   ,
    input   wire            io_master_wready    ,
    output  reg             io_master_wvalid    ,
    output  reg     [31:0]  io_master_wdata     ,
    output  reg     [3:0]   io_master_wstrb     ,
    // output  wire            io_master_wlast     ,
    output  reg             io_master_bready    ,
    input   wire            io_master_bvalid    ,
    input   wire    [1:0]   io_master_bresp     ,
    input   wire    [3:0]   io_master_bid       ,
    input   wire            io_master_arready   ,
    output  reg             io_master_arvalid   ,
    output  reg     [31:0]  io_master_araddr    ,
    // output  wire    [3:0]   io_master_arid      ,
    output  reg     [7:0]   io_master_arlen     ,
    output  reg     [2:0]   io_master_arsize    ,
    output  reg     [1:0]   io_master_arburst   ,
    output  reg             io_master_rready    ,
    input   wire            io_master_rvalid    ,
    input   wire    [1:0]   io_master_rresp     ,
    input   wire    [31:0]  io_master_rdata     ,
    input   wire            io_master_rlast     ,
    input   wire    [3:0]   io_master_rid       
);

reg     [1:0]   current_master  ; // 0: none, 1: IFU, 2: LSU
wire            is_transmiting  ;
reg             write_back      ;
reg             read_done       ;

wire    aw_handshake    ;
wire    w_handshake     ;
wire    b_handshake     ;
wire    ar_handshake    ;
wire    r_handshake     ;

assign  aw_handshake    =   io_master_awvalid   &&  io_master_awready   ;
assign  w_handshake     =   io_master_wvalid    &&  io_master_wready    ;
assign  b_handshake     =   io_master_bvalid    &&  io_master_bready    ;
assign  ar_handshake    =   io_master_arvalid   &&  io_master_arready   ;
assign  r_handshake     =   io_master_rvalid    &&  io_master_rready    ;

always @(posedge clock ) begin
    if(reset)
        write_back  <=  1'b1    ;
    // else    if(aw_handshake)
    else    if(io_master_awvalid)
        write_back  <=  1'b0    ;
    else    if(b_handshake)
        write_back  <=  1'b1    ;
end

always @(posedge clock ) begin
    if(reset)
        read_done  <=  1'b1    ;
    else    if(ar_handshake || (ifu_arvalid &&  !is_transmiting &&  !(lsu_awvalid ||  lsu_arvalid)))
        read_done  <=  1'b0    ;
    else    if(io_master_rlast)
        read_done  <=  1'b1    ;
end

assign  is_transmiting  =   aw_handshake
                        ||  w_handshake 
                        ||  b_handshake 
                        ||  ar_handshake
                        ||  r_handshake 
                        ||  !write_back
                        ||  !read_done
                        ;

always @(posedge clock ) begin
    if (reset) begin
        current_master  <= 2'b01;
    end
    else if(!is_transmiting) begin  // can't change when transmit is happenning
        if(lsu_awvalid ||  lsu_arvalid)
            current_master  <= 2'b10;
        else if(ifu_arvalid)
            current_master  <= 2'b01;
        else
            current_master  <= 2'b10;
    end
end

always @(*) begin
    if(current_master   ==  2'b01) begin
        ifu_arready             =   io_master_arready   ;
        ifu_rdata               =   io_master_rdata     ;
        ifu_rresp               =   io_master_rresp     ;
        ifu_rvalid              =   io_master_rvalid    ;
        ifu_rlast               =   io_master_rlast     ;
        lsu_awready             =   'd0                 ;
        lsu_wready              =   'd0                 ;
        lsu_bresp               =   'd0                 ;
        lsu_bvalid              =   'd0                 ;
        lsu_arready             =   'd0                 ;
        lsu_rdata               =   'd0                 ;
        lsu_rresp               =   'd0                 ;
        lsu_rvalid              =   'd0                 ;
        io_master_awvalid       =   'd0                 ;
        io_master_awaddr        =   'd0                 ;
        io_master_awsize        =   'd2                 ;
        io_master_wvalid        =   'd0                 ;
        io_master_wdata         =   'd0                 ;
        io_master_wstrb         =   'd0                 ;
        io_master_bready        =   'd0                 ;
        io_master_arvalid       =   ifu_arvalid         ;
        io_master_araddr        =   ifu_araddr          ;
        io_master_arsize        =   ifu_arsize          ;
        io_master_rready        =   ifu_rready          ;
        io_master_arburst       =   ifu_arburst         ;
        io_master_arlen         =   ifu_arlen           ;
    end
    else if(current_master   ==  2'b10) begin
        ifu_arready             =   'd0             ;
        ifu_rdata               =   'd0             ;
        ifu_rresp               =   'd0             ;
        ifu_rvalid              =   'd0             ;
        ifu_rlast               =   'd0             ;
        lsu_awready             =   io_master_awready    ;
        lsu_wready              =   io_master_wready     ;
        lsu_bresp               =   io_master_bresp      ;
        lsu_bvalid              =   io_master_bvalid     ;
        lsu_arready             =   io_master_arready    ;
        lsu_rdata               =   io_master_rdata      ;
        lsu_rresp               =   io_master_rresp      ;
        lsu_rvalid              =   io_master_rvalid     ;
        io_master_awvalid       =   lsu_awvalid     ;
        io_master_awaddr        =   lsu_awaddr      ;
        io_master_awsize        =   lsu_awsize      ;
        io_master_wvalid        =   lsu_wvalid      ;
        io_master_wdata         =   lsu_wdata       ;
        io_master_wstrb         =   lsu_wstrb       ;
        io_master_bready        =   lsu_bready      ;
        io_master_arvalid       =   lsu_arvalid     ;
        io_master_araddr        =   lsu_araddr      ;
        io_master_arsize        =   lsu_arsize      ;
        io_master_rready        =   lsu_rready      ;
        io_master_arburst       =   'd0             ;
        io_master_arlen         =   'd0             ;
    end
    else begin
        ifu_arready             =   'd0             ;
        ifu_rdata               =   'd0             ;
        ifu_rresp               =   'd0             ;
        ifu_rvalid              =   'd0             ;
        ifu_rlast               =   'd0             ;
        lsu_awready             =   'd0             ;
        lsu_wready              =   'd0             ;
        lsu_bresp               =   'd0             ;
        lsu_bvalid              =   'd0             ;
        lsu_arready             =   'd0             ;
        lsu_rdata               =   'd0             ;
        lsu_rresp               =   'd0             ;
        lsu_rvalid              =   'd0             ;
        io_master_awvalid       =   'd0             ;
        io_master_awaddr        =   'd0             ;
        io_master_awsize        =   'd2             ;
        io_master_wvalid        =   'd0             ;
        io_master_wdata         =   'd0             ;
        io_master_wstrb         =   'd0             ;
        io_master_bready        =   'd0             ;
        io_master_arvalid       =   'd0             ;
        io_master_araddr        =   'd0             ;
        io_master_arsize        =   'd2             ;
        io_master_rready        =   'd0             ;
        io_master_arburst       =   'd0             ;
        io_master_arlen         =   'd0             ;
    end
end

// AXI4 Style
// assign  io_master_awid      =   'd0     ;
// assign  io_master_awlen     =   'd0     ;
// assign  io_master_awburst   =   2'b00   ;
// assign  io_master_wlast     =   'd1     ;
// assign  io_master_arid      =   'd0     ;


endmodule
