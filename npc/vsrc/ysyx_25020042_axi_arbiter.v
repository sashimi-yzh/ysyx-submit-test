
module ysyx_25020042_axi_arbiter (
    input              clock,
    input              reset,
    // lsu
    input [31:0]       io_lsu_araddr,
    input              io_lsu_arvalid,
    input      [3:0]   io_lsu_arid,
    input      [7:0]   io_lsu_arlen,
    input      [2:0]   io_lsu_arsize,
    input      [1:0]   io_lsu_arburst,    
    output reg         io_lsu_arready ,

    output reg [31:0]  io_lsu_rdata ,
    output reg         io_lsu_rvalid ,
    output reg [1:0]   io_lsu_rresp ,
    output reg [3:0]   io_lsu_rid,
    output reg         io_lsu_rlast,
    input              io_lsu_rready ,

    input [31:0]       io_lsu_awaddr ,
    input              io_lsu_awvalid ,
    input      [3:0]   io_lsu_awid,
    input      [7:0]   io_lsu_awlen,
    input      [2:0]   io_lsu_awsize,
    input      [1:0]   io_lsu_awburst,    
    output reg         io_lsu_awready ,

    input [31:0]       io_lsu_wdata ,
    input [3:0]        io_lsu_wstrb ,
    input              io_lsu_wvalid ,
    input              io_lsu_wlast,
    output reg         io_lsu_wready ,

    output reg         io_lsu_bvalid ,
    input              io_lsu_bready ,
    output reg [1:0]   io_lsu_bresp ,
    output reg [3:0]   io_lsu_bid,

    //IFU
    input [31:0]       io_ifu_araddr,
    input              io_ifu_arvalid,
    output reg         io_ifu_arready,
    input [7:0]        io_ifu_arlen,
    input [3:0]        io_ifu_arid,
    input [1:0]        io_ifu_arburst,
    input [2:0]        io_ifu_arsize,

    output reg [31:0]  io_ifu_rdata,
    output reg         io_ifu_rvalid,
    output reg [1:0]   io_ifu_rresp,
    input              io_ifu_rready,
    output reg         io_ifu_rlast,
    output reg [3:0]   io_ifu_rid,

    // out
    input              io_awready,
    output reg         io_awvalid,
    output reg [31:0]  io_awaddr ,
    output reg [3:0]   io_awid   ,
    output reg [7:0]   io_awlen  ,
    output reg [2:0]   io_awsize ,
    output reg [1:0]   io_awburst,
    input              io_wready ,
    output reg         io_wvalid ,
    output reg [31:0]  io_wdata  ,
    output reg [3:0]   io_wstrb  ,
    output reg         io_wlast  ,
    output reg         io_bready ,
    input              io_bvalid ,
    input   [1:0]      io_bresp  ,
    input   [3:0]      io_bid    ,
    input              io_arready,
    output reg         io_arvalid,
    output reg [31:0]  io_araddr ,
    output reg [3:0]   io_arid   ,
    output reg [7:0]   io_arlen  ,
    output reg [2:0]   io_arsize ,
    output reg [1:0]   io_arburst,
    output reg         io_rready ,
    input              io_rvalid ,
    input   [1:0]      io_rresp  ,
    input   [31:0]     io_rdata  ,
    input              io_rlast  ,
    input   [3:0]      io_rid    ,
    // clint
    input              io_clint_awready,
    output reg         io_clint_awvalid,
    output reg [31:0]  io_clint_awaddr ,
    output reg [3:0]   io_clint_awid   ,
    output reg [7:0]   io_clint_awlen  ,
    output reg [2:0]   io_clint_awsize ,
    output reg [1:0]   io_clint_awburst,
    input              io_clint_wready ,
    output reg         io_clint_wvalid ,
    output reg [31:0]  io_clint_wdata  ,
    output reg [3:0]   io_clint_wstrb  ,
    output reg         io_clint_wlast  ,
    output reg         io_clint_bready ,
    input              io_clint_bvalid ,
    input   [1:0]      io_clint_bresp  ,
    input   [3:0]      io_clint_bid    ,
    input              io_clint_arready,
    output reg         io_clint_arvalid,
    output reg [31:0]  io_clint_araddr ,
    output reg [3:0]   io_clint_arid   ,
    output reg [7:0]   io_clint_arlen  ,
    output reg [2:0]   io_clint_arsize ,
    output reg [1:0]   io_clint_arburst,
    output reg         io_clint_rready ,
    input              io_clint_rvalid ,
    input   [1:0]      io_clint_rresp  ,
    input   [31:0]     io_clint_rdata  ,
    input              io_clint_rlast  ,
    input   [3:0]      io_clint_rid   
);

    // arbiter
    reg [1:0] state;
    wire clint_active = (io_lsu_araddr >= 32'h0200_0000 && io_lsu_araddr < 32'h0201_0000);

    parameter ARB_IDLE = 2'd0, ARB_LSU = 2'd1, ARB_IFU = 2'd2;

    // reg io_lsu_arvalid_reg;

    // always @(posedge clock) begin
    //     io_lsu_arvalid_reg <= io_lsu_arvalid;
    // end

    always @ (posedge clock) begin
        if (reset) begin
            state <= ARB_IDLE;
        end
        else begin
            case (state)
                ARB_IDLE: begin
                    if (io_lsu_arvalid | io_lsu_awvalid) begin
                        state <= ARB_LSU;
                    end
                    else if (io_ifu_arvalid) begin
                        state <= ARB_IFU;
                    end
                    else begin
                        state <= ARB_IDLE;
                    end
                end
                ARB_LSU: begin
                    if (io_lsu_rready & io_lsu_rvalid & (io_rlast | io_clint_rlast)) begin
                        state <= ARB_IDLE;
                    end
                    else if (io_lsu_bvalid & io_lsu_bready) begin
                        state <= ARB_IDLE;
                    end
                    else begin
                        state <= ARB_LSU;
                    end
                end
                ARB_IFU: begin
                    if (io_ifu_rready & io_ifu_rvalid & io_rlast) begin
                        state <= ARB_IDLE;
                    end
                    else begin
                        state <= ARB_IFU;
                    end
                end
                default: begin
                    state <= ARB_IDLE;
                end
            endcase      
        end
    end

    always @(*) begin
        io_araddr = 0;
        io_arvalid = 0;
        io_arid = 0;
        io_arlen = 0;
        io_arsize = 0;
        io_arburst = 0;
        io_rready = 0;
        io_awaddr = 0;
        io_awvalid = 0;
        io_awid = 0;
        io_awlen = 0;
        io_awsize = 0;
        io_awburst = 0;
        io_wdata = 0;
        io_wstrb = 0;
        io_wvalid = 0;
        io_wlast = 0;
        io_bready = 0;

        io_clint_araddr = 0;
        io_clint_arvalid = 0;
        io_clint_arid = 0;
        io_clint_arlen = 0;
        io_clint_arsize = 0;
        io_clint_arburst = 0;
        io_clint_rready = 0;
        io_clint_awaddr = 0;
        io_clint_awvalid = 0;
        io_clint_awid = 0;
        io_clint_awlen = 0;
        io_clint_awsize = 0;
        io_clint_awburst = 0;
        io_clint_wdata = 0;
        io_clint_wstrb = 0;
        io_clint_wvalid = 0;
        io_clint_wlast = 0;
        io_clint_bready = 0;

        io_lsu_arready = 0;
        io_lsu_rdata = 0;
        io_lsu_rvalid = 0;
        io_lsu_rresp = 0;
        io_lsu_awready = 0;
        io_lsu_wready = 0;
        io_lsu_bvalid = 0;
        io_lsu_bresp = 0;
        io_lsu_rid = 0;
        io_lsu_rlast = 0;
        io_lsu_bid = 0;

        io_ifu_arready = 0;
        io_ifu_rdata = 0;
        io_ifu_rvalid = 0;
        io_ifu_rresp = 0;
        io_ifu_rlast = 0;
        io_ifu_rid = 0;
        
        if (state == ARB_IFU) begin
            io_araddr = io_ifu_araddr;
            io_arvalid = io_ifu_arvalid;
            io_rready = io_ifu_rready;
            io_arid = io_ifu_arid;
            io_arlen = io_ifu_arlen;
            io_arsize = io_ifu_arsize;
            io_arburst = io_ifu_arburst;

            io_ifu_arready = io_arready;
            io_ifu_rdata = io_rdata;
            io_ifu_rvalid = io_rvalid;
            io_ifu_rresp = io_rresp;
            io_ifu_rlast = io_rlast;
            io_ifu_rid = io_rid;
            
        end
        else if (state == ARB_LSU) begin
            if (clint_active) begin
                io_clint_araddr =  io_lsu_araddr;
                io_clint_arvalid = io_lsu_arvalid;
                io_clint_arid =    io_lsu_arid;
                io_clint_arlen =   io_lsu_arlen;
                io_clint_arsize =  io_lsu_arsize;
                io_clint_arburst = io_lsu_arburst;
                io_clint_rready =  io_lsu_rready;
                io_clint_awaddr =  io_lsu_awaddr;
                io_clint_awvalid = io_lsu_awvalid;
                io_clint_awlen =   io_lsu_awlen;
                io_clint_awsize =  io_lsu_awsize;
                io_clint_awburst = io_lsu_awburst;
                io_clint_awid =    io_lsu_awid;
                io_clint_wdata =   io_lsu_wdata;
                io_clint_wstrb =   io_lsu_wstrb;
                io_clint_wvalid =  io_lsu_wvalid;
                io_clint_wlast =   io_lsu_wlast;
                io_clint_bready =  io_lsu_bready;

                io_lsu_arready =io_clint_arready ;
                io_lsu_rdata   =io_clint_rdata   ;
                io_lsu_rvalid  =io_clint_rvalid  ;
                io_lsu_rresp   =io_clint_rresp   ;
                io_lsu_awready =io_clint_awready ;
                io_lsu_wready  =io_clint_wready  ;
                io_lsu_bvalid  =io_clint_bvalid  ;
                io_lsu_bresp   =io_clint_bresp   ;
                io_lsu_rid     =io_clint_rid     ;
                io_lsu_rlast   =io_clint_rlast   ;
                io_lsu_bid     =io_clint_bid     ;
            end
            else begin
                io_araddr =  io_lsu_araddr;
                io_arvalid = io_lsu_arvalid;
                io_arid =    io_lsu_arid;
                io_arlen =   io_lsu_arlen;
                io_arsize =  io_lsu_arsize;
                io_arburst = io_lsu_arburst;
                io_rready =  io_lsu_rready;
                io_awaddr =  io_lsu_awaddr;
                io_awvalid = io_lsu_awvalid;
                io_awlen =   io_lsu_awlen;
                io_awsize =  io_lsu_awsize;
                io_awburst = io_lsu_awburst;
                io_awid =    io_lsu_awid;
                io_wdata =   io_lsu_wdata;
                io_wstrb =   io_lsu_wstrb;
                io_wvalid =  io_lsu_wvalid;
                io_wlast =   io_lsu_wlast;
                io_bready =  io_lsu_bready;

                io_lsu_arready = io_arready;
                io_lsu_rdata   = io_rdata;
                io_lsu_rvalid  = io_rvalid;
                io_lsu_rresp   = io_rresp;
                io_lsu_awready = io_awready;
                io_lsu_wready  = io_wready;
                io_lsu_bvalid  = io_bvalid;
                io_lsu_bresp   = io_bresp;
                io_lsu_rid     = io_rid;
                io_lsu_rlast   = io_rlast;
                io_lsu_bid     = io_bid;
            end
            
        end
    end
endmodule
