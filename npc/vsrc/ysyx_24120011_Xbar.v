
module ysyx_24120011_Xbar(
    input clk,
    input rst,
    //============Xbar=============//        
    //AR-axi4lite
    input  [31:0]     Xbar_araddr,
    input             Xbar_arvalid,
    output            Xbar_arready,
    //AR-axi4
    input  [3:0]      Xbar_arid,
    input  [7:0]      Xbar_arlen,
    input  [2:0]      Xbar_arsize,
    input  [1:0]      Xbar_arburst,
    //R-axi4lite               
    output [31:0]     Xbar_rdata,
    output [1:0]      Xbar_rresp,
    output            Xbar_rvalid,
    input             Xbar_rready,
    //R-axi4
    output            Xbar_rlast,
    output [3:0]      Xbar_rid,
    //AW-axi4lite
    input  [31:0]     Xbar_awaddr,
    input             Xbar_awvalid,
    output            Xbar_awready,
    //AW-axi4
    input  [3:0]      Xbar_awid,
    input  [7:0]      Xbar_awlen,
    input  [2:0]      Xbar_awsize,
    input  [1:0]      Xbar_awburst,
    //W-axi4lite
    input  [31:0]     Xbar_wdata,
    input  [3:0]      Xbar_wstrb,
    input             Xbar_wvalid,
    output            Xbar_wready,
    //W-axi4
    input             Xbar_wlast,
    //B-axi4lite
    output [1:0]      Xbar_bresp,
    output            Xbar_bvalid,
    input             Xbar_bready,
    //B-axi4
    output [3:0]	  Xbar_bid,
    //============Xbar_S0=============//        
    //AR-axi4lite
    output  [31:0]     Xbar_S0_araddr,
    output             Xbar_S0_arvalid,
    input              Xbar_S0_arready,
    //AR-axi4
    output  [3:0]      Xbar_S0_arid,
    output  [7:0]      Xbar_S0_arlen,
    output  [2:0]      Xbar_S0_arsize,
    output  [1:0]      Xbar_S0_arburst,
    //R-axi4lite               
    input   [31:0]     Xbar_S0_rdata,
    input   [1:0]      Xbar_S0_rresp,
    input              Xbar_S0_rvalid,
    output             Xbar_S0_rready,
    //R-axi4
    input              Xbar_S0_rlast,
    input   [3:0]      Xbar_S0_rid,
    //AW-axi4lite
    output  [31:0]     Xbar_S0_awaddr,
    output             Xbar_S0_awvalid,
    input              Xbar_S0_awready,
    //AW-axi4
    output  [3:0]      Xbar_S0_awid,
    output  [7:0]      Xbar_S0_awlen,
    output  [2:0]      Xbar_S0_awsize,
    output  [1:0]      Xbar_S0_awburst,
    //W-axi4lite
    output  [31:0]     Xbar_S0_wdata,
    output  [3:0]      Xbar_S0_wstrb,
    output             Xbar_S0_wvalid,
    input              Xbar_S0_wready,
    //W-axi4
    output             Xbar_S0_wlast,
    //B-axi4lite
    input   [1:0]      Xbar_S0_bresp,
    input              Xbar_S0_bvalid,
    output             Xbar_S0_bready,
    //B-axi4
    input   [3:0]	   Xbar_S0_bid,
    //============Xbar_S1=============//        
    //AR-axi4lite
    output  [31:0]     Xbar_S1_araddr,
    output             Xbar_S1_arvalid,
    input              Xbar_S1_arready,
    //AR-axi4
    output  [3:0]      Xbar_S1_arid,
    output  [7:0]      Xbar_S1_arlen,
    output  [2:0]      Xbar_S1_arsize,
    output  [1:0]      Xbar_S1_arburst,
    //R-axi4lite               
    input   [31:0]     Xbar_S1_rdata,
    input   [1:0]      Xbar_S1_rresp,
    input              Xbar_S1_rvalid,
    output             Xbar_S1_rready,
    //R-axi4
    input              Xbar_S1_rlast,
    input   [3:0]      Xbar_S1_rid,
    //AW-axi4lite
    output  [31:0]     Xbar_S1_awaddr,
    output             Xbar_S1_awvalid,
    input              Xbar_S1_awready,
    //AW-axi4
    output  [3:0]      Xbar_S1_awid,
    output  [7:0]      Xbar_S1_awlen,
    output  [2:0]      Xbar_S1_awsize,
    output  [1:0]      Xbar_S1_awburst,
    //W-axi4lite
    output  [31:0]     Xbar_S1_wdata,
    output  [3:0]      Xbar_S1_wstrb,
    output             Xbar_S1_wvalid,
    input              Xbar_S1_wready,
    //W-axi4
    output             Xbar_S1_wlast,
    //B-axi4lite
    input   [1:0]      Xbar_S1_bresp,
    input              Xbar_S1_bvalid,
    output             Xbar_S1_bready,
    //B-axi4
    input   [3:0]	   Xbar_S1_bid
    // //============Xbar_S2=============//        
    // //AR-axi4lite
    // output  [31:0]     Xbar_S2_araddr,
    // output             Xbar_S2_arvalid,
    // input              Xbar_S2_arready,
    // //AR-axi4
    // output  [3:0]      Xbar_S2_arid,
    // output  [7:0]      Xbar_S2_arlen,
    // output  [2:0]      Xbar_S2_arsize,
    // output  [1:0]      Xbar_S2_arburst,
    // //R-axi4lite               
    // input   [31:0]     Xbar_S2_rdata,
    // input   [1:0]      Xbar_S2_rresp,
    // input              Xbar_S2_rvalid,
    // output             Xbar_S2_rready,
    // //R-axi4
    // input              Xbar_S2_rlast,
    // input   [3:0]      Xbar_S2_rid,
    // //AW-axi4lite
    // output  [31:0]     Xbar_S2_awaddr,
    // output             Xbar_S2_awvalid,
    // input              Xbar_S2_awready,
    // //AW-axi4
    // output  [3:0]      Xbar_S2_awid,
    // output  [7:0]      Xbar_S2_awlen,
    // output  [2:0]      Xbar_S2_awsize,
    // output  [1:0]      Xbar_S2_awburst,
    // //W-axi4lite
    // output  [31:0]     Xbar_S2_wdata,
    // output  [3:0]      Xbar_S2_wstrb,
    // output             Xbar_S2_wvalid,
    // input              Xbar_S2_wready,
    // //W-axi4
    // output             Xbar_S2_wlast,
    // //B-axi4lite
    // input   [1:0]      Xbar_S2_bresp,
    // input              Xbar_S2_bvalid,
    // output             Xbar_S2_bready,
    // //B-axi4
    // input   [3:0]	   Xbar_S2_bid
);
    parameter ysyx_24120011_Xbar_IDLE = 3'b000;
    parameter ysyx_24120011_Xbar_S0 = 3'b001;
    parameter ysyx_24120011_Xbar_S1 = 3'b010;
    // parameter ysyx_24120011_Xbar_S2 = 3'b011;

    reg [2:0] r_Xbar_state;
    reg [2:0] r_Xbar_next_state;
    reg [2:0] w_Xbar_state;
    reg [2:0] w_Xbar_next_state;

    reg [31:0] reg_Xbar_rdata     ;
    reg [1:0]  reg_Xbar_rresp     ;
    reg        reg_Xbar_rvalid    ;
    reg        reg_Xbar_awready   ;
    reg        reg_Xbar_wready    ;
    reg [1:0]  reg_Xbar_bresp     ;
    reg        reg_Xbar_bvalid    ;
    reg        reg_Xbar_arready   ;
    reg        reg_Xbar_rlast     ;
    reg [3:0]  reg_Xbar_rid       ;
    reg [3:0]  reg_Xbar_bid       ;

    reg [31:0] reg_Xbar_S0_araddr ;
    reg        reg_Xbar_S0_arvalid;
    reg        reg_Xbar_S0_rready ;
    reg [31:0] reg_Xbar_S0_awaddr ;
    reg        reg_Xbar_S0_awvalid;
    reg [31:0] reg_Xbar_S0_wdata  ;
    reg [3:0]  reg_Xbar_S0_wstrb  ;
    reg        reg_Xbar_S0_wvalid ;
    reg        reg_Xbar_S0_bready ;
    reg [3:0]  reg_Xbar_S0_arid   ;
    reg [7:0]  reg_Xbar_S0_arlen  ;
    reg [2:0]  reg_Xbar_S0_arsize ;
    reg [1:0]  reg_Xbar_S0_arburst;
    reg [3:0]  reg_Xbar_S0_awid   ;
    reg [7:0]  reg_Xbar_S0_awlen  ;
    reg [2:0]  reg_Xbar_S0_awsize ;
    reg [1:0]  reg_Xbar_S0_awburst;
    reg        reg_Xbar_S0_wlast  ;
    

    reg [31:0] reg_Xbar_S1_araddr ;
    reg        reg_Xbar_S1_arvalid;
    reg        reg_Xbar_S1_rready ;
    reg [31:0] reg_Xbar_S1_awaddr ;
    reg        reg_Xbar_S1_awvalid;
    reg [31:0] reg_Xbar_S1_wdata  ;
    reg [3:0]  reg_Xbar_S1_wstrb  ;
    reg        reg_Xbar_S1_wvalid ;
    reg        reg_Xbar_S1_bready ;
    reg [3:0]  reg_Xbar_S1_arid   ;
    reg [7:0]  reg_Xbar_S1_arlen  ;
    reg [2:0]  reg_Xbar_S1_arsize ;
    reg [1:0]  reg_Xbar_S1_arburst;
    reg [3:0]  reg_Xbar_S1_awid   ;
    reg [7:0]  reg_Xbar_S1_awlen  ;
    reg [2:0]  reg_Xbar_S1_awsize ;
    reg [1:0]  reg_Xbar_S1_awburst;
    reg        reg_Xbar_S1_wlast  ;
    
    // reg [31:0] reg_Xbar_S2_araddr ;
    // reg        reg_Xbar_S2_arvalid;
    // reg        reg_Xbar_S2_rready ;
    // reg [31:0] reg_Xbar_S2_awaddr ;
    // reg        reg_Xbar_S2_awvalid;
    // reg [31:0] reg_Xbar_S2_wdata  ;
    // reg [3:0]  reg_Xbar_S2_wstrb  ;
    // reg        reg_Xbar_S2_wvalid ;
    // reg        reg_Xbar_S2_bready ;
    // reg [3:0]  reg_Xbar_S2_arid   ;
    // reg [7:0]  reg_Xbar_S2_arlen  ;
    // reg [2:0]  reg_Xbar_S2_arsize ;
    // reg [1:0]  reg_Xbar_S2_arburst;
    // reg [3:0]  reg_Xbar_S2_awid   ;
    // reg [7:0]  reg_Xbar_S2_awlen  ;
    // reg [2:0]  reg_Xbar_S2_awsize ;
    // reg [1:0]  reg_Xbar_S2_awburst;
    // reg        reg_Xbar_S2_wlast  ;
    
    

    wire read_S0_done;
    wire write_S0_done;
    wire read_S1_done;
    wire write_S1_done;
    // wire read_S2_done;
    // wire write_S2_done;

    assign read_S0_done = Xbar_S0_rlast && Xbar_S0_rready && Xbar_S0_rvalid;
    assign write_S0_done = Xbar_S0_bready && Xbar_S0_bvalid;
    assign read_S1_done = Xbar_S1_rlast && Xbar_S1_rready && Xbar_S1_rvalid;
    assign write_S1_done = Xbar_S1_bready && Xbar_S1_bvalid;
    // assign read_S2_done = Xbar_S2_rlast && Xbar_S2_rready && Xbar_S2_rvalid;
    // assign write_S2_done = Xbar_S2_bready && Xbar_S2_bvalid;

    
    assign Xbar_rdata      = reg_Xbar_rdata     ;
    assign Xbar_rresp      = reg_Xbar_rresp     ;
    assign Xbar_rvalid     = reg_Xbar_rvalid    ;
    assign Xbar_awready    = reg_Xbar_awready   ;
    assign Xbar_wready     = reg_Xbar_wready    ;
    assign Xbar_bresp      = reg_Xbar_bresp     ;
    assign Xbar_bvalid     = reg_Xbar_bvalid    ;
    assign Xbar_arready    = reg_Xbar_arready   ;
    assign Xbar_rlast      = reg_Xbar_rlast     ;
    assign Xbar_rid        = reg_Xbar_rid       ;
    assign Xbar_bid        = reg_Xbar_bid       ;

    assign Xbar_S0_araddr  = reg_Xbar_S0_araddr ;
    assign Xbar_S0_arvalid = reg_Xbar_S0_arvalid;
    assign Xbar_S0_rready  = reg_Xbar_S0_rready ;
    assign Xbar_S0_awaddr  = reg_Xbar_S0_awaddr ;
    assign Xbar_S0_awvalid = reg_Xbar_S0_awvalid;
    assign Xbar_S0_wdata   = reg_Xbar_S0_wdata  ;
    assign Xbar_S0_wstrb   = reg_Xbar_S0_wstrb  ;
    assign Xbar_S0_wvalid  = reg_Xbar_S0_wvalid ;
    assign Xbar_S0_bready  = reg_Xbar_S0_bready ;
    assign Xbar_S0_arid    = reg_Xbar_S0_arid   ;
    assign Xbar_S0_arlen   = reg_Xbar_S0_arlen  ;
    assign Xbar_S0_arsize  = reg_Xbar_S0_arsize ;
    assign Xbar_S0_arburst = reg_Xbar_S0_arburst;
    assign Xbar_S0_awid    = reg_Xbar_S0_awid   ;
    assign Xbar_S0_awlen   = reg_Xbar_S0_awlen  ;
    assign Xbar_S0_awsize  = reg_Xbar_S0_awsize ;
    assign Xbar_S0_awburst = reg_Xbar_S0_awburst;
    assign Xbar_S0_wlast   = reg_Xbar_S0_wlast  ;

    assign Xbar_S1_araddr  = reg_Xbar_S1_araddr ;
    assign Xbar_S1_arvalid = reg_Xbar_S1_arvalid;
    assign Xbar_S1_rready  = reg_Xbar_S1_rready ;
    assign Xbar_S1_awaddr  = reg_Xbar_S1_awaddr ;
    assign Xbar_S1_awvalid = reg_Xbar_S1_awvalid;
    assign Xbar_S1_wdata   = reg_Xbar_S1_wdata  ;
    assign Xbar_S1_wstrb   = reg_Xbar_S1_wstrb  ;
    assign Xbar_S1_wvalid  = reg_Xbar_S1_wvalid ;
    assign Xbar_S1_bready  = reg_Xbar_S1_bready ;
    assign Xbar_S1_arid    = reg_Xbar_S1_arid   ;
    assign Xbar_S1_arlen   = reg_Xbar_S1_arlen  ;
    assign Xbar_S1_arsize  = reg_Xbar_S1_arsize ;
    assign Xbar_S1_arburst = reg_Xbar_S1_arburst;
    assign Xbar_S1_awid    = reg_Xbar_S1_awid   ;
    assign Xbar_S1_awlen   = reg_Xbar_S1_awlen  ;
    assign Xbar_S1_awsize  = reg_Xbar_S1_awsize ;
    assign Xbar_S1_awburst = reg_Xbar_S1_awburst;
    assign Xbar_S1_wlast   = reg_Xbar_S1_wlast  ;

    // assign Xbar_S2_araddr  = reg_Xbar_S2_araddr ;
    // assign Xbar_S2_arvalid = reg_Xbar_S2_arvalid;
    // assign Xbar_S2_rready  = reg_Xbar_S2_rready ;
    // assign Xbar_S2_awaddr  = reg_Xbar_S2_awaddr ;
    // assign Xbar_S2_awvalid = reg_Xbar_S2_awvalid;
    // assign Xbar_S2_wdata   = reg_Xbar_S2_wdata  ;
    // assign Xbar_S2_wstrb   = reg_Xbar_S2_wstrb  ;
    // assign Xbar_S2_wvalid  = reg_Xbar_S2_wvalid ;
    // assign Xbar_S2_bready  = reg_Xbar_S2_bready ;
    // assign Xbar_S2_arid    = reg_Xbar_S2_arid   ;
    // assign Xbar_S2_arlen   = reg_Xbar_S2_arlen  ;
    // assign Xbar_S2_arsize  = reg_Xbar_S2_arsize ;
    // assign Xbar_S2_arburst = reg_Xbar_S2_arburst;
    // assign Xbar_S2_awid    = reg_Xbar_S2_awid   ;
    // assign Xbar_S2_awlen   = reg_Xbar_S2_awlen  ;
    // assign Xbar_S2_awsize  = reg_Xbar_S2_awsize ;
    // assign Xbar_S2_awburst = reg_Xbar_S2_awburst;
    // assign Xbar_S2_wlast   = reg_Xbar_S2_wlast  ;

    //接线
    always@(*) begin
        case(r_Xbar_state)
            ysyx_24120011_Xbar_IDLE:begin
                reg_Xbar_arready    = 'd0;
                reg_Xbar_rdata      = 'd0;
                reg_Xbar_rresp      = 'd0;
                reg_Xbar_rvalid     = 'd0;
                reg_Xbar_rlast      = 'd0;
                reg_Xbar_rid        = 'd0;

                reg_Xbar_S0_araddr  = 'd0;
                reg_Xbar_S0_arvalid = 'd0;
                reg_Xbar_S0_rready  = 'd0;
                reg_Xbar_S0_arid    = 'd0;
                reg_Xbar_S0_arlen   = 'd0;
                reg_Xbar_S0_arsize  = 'd0;
                reg_Xbar_S0_arburst = 'd0;

                reg_Xbar_S1_araddr  = 'd0;
                reg_Xbar_S1_arvalid = 'd0;
                reg_Xbar_S1_rready  = 'd0;
                reg_Xbar_S1_arid    = 'd0;
                reg_Xbar_S1_arlen   = 'd0;
                reg_Xbar_S1_arsize  = 'd0;
                reg_Xbar_S1_arburst = 'd0;

                // reg_Xbar_S2_araddr  = 'd0;
                // reg_Xbar_S2_arvalid = 'd0;
                // reg_Xbar_S2_rready  = 'd0;
                // reg_Xbar_S2_arid    = 'd0;
                // reg_Xbar_S2_arlen   = 'd0;
                // reg_Xbar_S2_arsize  = 'd0;
                // reg_Xbar_S2_arburst = 'd0;
            end
            ysyx_24120011_Xbar_S0:begin
                reg_Xbar_arready    = Xbar_S0_arready;
                reg_Xbar_rdata      = Xbar_S0_rdata;
                reg_Xbar_rresp      = Xbar_S0_rresp;
                reg_Xbar_rvalid     = Xbar_S0_rvalid;
                reg_Xbar_rlast      = Xbar_S0_rlast;
                reg_Xbar_rid        = Xbar_S0_rid;

                reg_Xbar_S0_araddr  = Xbar_araddr ;
                reg_Xbar_S0_arvalid = Xbar_arvalid;
                reg_Xbar_S0_rready  = Xbar_rready ;
                reg_Xbar_S0_arid    = Xbar_arid   ;
                reg_Xbar_S0_arlen   = Xbar_arlen  ;
                reg_Xbar_S0_arsize  = Xbar_arsize ;
                reg_Xbar_S0_arburst = Xbar_arburst;

                reg_Xbar_S1_araddr  = 'd0;
                reg_Xbar_S1_arvalid = 'd0;
                reg_Xbar_S1_rready  = 'd0;
                reg_Xbar_S1_arid    = 'd0;
                reg_Xbar_S1_arlen   = 'd0;
                reg_Xbar_S1_arsize  = 'd0;
                reg_Xbar_S1_arburst = 'd0;

                // reg_Xbar_S2_araddr  = 'd0;
                // reg_Xbar_S2_arvalid = 'd0;
                // reg_Xbar_S2_rready  = 'd0;
                // reg_Xbar_S2_arid    = 'd0;
                // reg_Xbar_S2_arlen   = 'd0;
                // reg_Xbar_S2_arsize  = 'd0;
                // reg_Xbar_S2_arburst = 'd0;
            end
            ysyx_24120011_Xbar_S1:begin
                
                reg_Xbar_arready    = Xbar_S1_arready;
                reg_Xbar_rdata      = Xbar_S1_rdata;
                reg_Xbar_rresp      = Xbar_S1_rresp;
                reg_Xbar_rvalid     = Xbar_S1_rvalid;
                reg_Xbar_rlast      = Xbar_S1_rlast;
                reg_Xbar_rid        = Xbar_S1_rid;

                reg_Xbar_S0_araddr  = 'd0;
                reg_Xbar_S0_arvalid = 'd0;
                reg_Xbar_S0_rready  = 'd0;
                reg_Xbar_S0_arid    = 'd0;
                reg_Xbar_S0_arlen   = 'd0;
                reg_Xbar_S0_arsize  = 'd0;
                reg_Xbar_S0_arburst = 'd0;

                reg_Xbar_S1_araddr  = Xbar_araddr ;
                reg_Xbar_S1_arvalid = Xbar_arvalid;
                reg_Xbar_S1_rready  = Xbar_rready ;
                reg_Xbar_S1_arid    = Xbar_arid   ;
                reg_Xbar_S1_arlen   = Xbar_arlen  ;
                reg_Xbar_S1_arsize  = Xbar_arsize ;
                reg_Xbar_S1_arburst = Xbar_arburst;

                // reg_Xbar_S2_araddr  = 'd0;
                // reg_Xbar_S2_arvalid = 'd0;
                // reg_Xbar_S2_rready  = 'd0;
                // reg_Xbar_S2_arid    = 'd0;
                // reg_Xbar_S2_arlen   = 'd0;
                // reg_Xbar_S2_arsize  = 'd0;
                // reg_Xbar_S2_arburst = 'd0;
            end
            // ysyx_24120011_Xbar_S2:begin
                
            //     reg_Xbar_arready    = Xbar_S2_arready;
            //     reg_Xbar_rdata      = Xbar_S2_rdata;
            //     reg_Xbar_rresp      = Xbar_S2_rresp;
            //     reg_Xbar_rvalid     = Xbar_S2_rvalid;
            //     reg_Xbar_rlast      = Xbar_S2_rlast;
            //     reg_Xbar_rid        = Xbar_S2_rid;

            //     reg_Xbar_S0_araddr  = 'd0;
            //     reg_Xbar_S0_arvalid = 'd0;
            //     reg_Xbar_S0_rready  = 'd0;
            //     reg_Xbar_S0_arid    = 'd0;
            //     reg_Xbar_S0_arlen   = 'd0;
            //     reg_Xbar_S0_arsize  = 'd0;
            //     reg_Xbar_S0_arburst = 'd0;

            //     reg_Xbar_S1_araddr  = 'd0;
            //     reg_Xbar_S1_arvalid = 'd0;
            //     reg_Xbar_S1_rready  = 'd0;
            //     reg_Xbar_S1_arid    = 'd0;
            //     reg_Xbar_S1_arlen   = 'd0;
            //     reg_Xbar_S1_arsize  = 'd0;
            //     reg_Xbar_S1_arburst = 'd0;

            //     reg_Xbar_S2_araddr  = Xbar_araddr ;
            //     reg_Xbar_S2_arvalid = Xbar_arvalid;
            //     reg_Xbar_S2_rready  = Xbar_rready ;
            //     reg_Xbar_S2_arid    = Xbar_arid   ;
            //     reg_Xbar_S2_arlen   = Xbar_arlen  ;
            //     reg_Xbar_S2_arsize  = Xbar_arsize ;
            //     reg_Xbar_S2_arburst = Xbar_arburst;
            // end
            default:begin
                reg_Xbar_arready    = 'd0;
                reg_Xbar_rdata      = 'd0;
                reg_Xbar_rresp      = 'd0;
                reg_Xbar_rvalid     = 'd0;
                reg_Xbar_rlast      = 'd0;
                reg_Xbar_rid        = 'd0;

                reg_Xbar_S0_araddr  = 'd0;
                reg_Xbar_S0_arvalid = 'd0;
                reg_Xbar_S0_rready  = 'd0;
                reg_Xbar_S0_arid    = 'd0;
                reg_Xbar_S0_arlen   = 'd0;
                reg_Xbar_S0_arsize  = 'd0;
                reg_Xbar_S0_arburst = 'd0;

                reg_Xbar_S1_araddr  = 'd0;
                reg_Xbar_S1_arvalid = 'd0;
                reg_Xbar_S1_rready  = 'd0;
                reg_Xbar_S1_arid    = 'd0;
                reg_Xbar_S1_arlen   = 'd0;
                reg_Xbar_S1_arsize  = 'd0;
                reg_Xbar_S1_arburst = 'd0;

                // reg_Xbar_S2_araddr  = 'd0;
                // reg_Xbar_S2_arvalid = 'd0;
                // reg_Xbar_S2_rready  = 'd0;
                // reg_Xbar_S2_arid    = 'd0;
                // reg_Xbar_S2_arlen   = 'd0;
                // reg_Xbar_S2_arsize  = 'd0;
                // reg_Xbar_S2_arburst = 'd0;
            end
        endcase
        case(w_Xbar_state)
            ysyx_24120011_Xbar_IDLE:begin
                reg_Xbar_awready    = 'd0;
                reg_Xbar_wready     = 'd0;
                reg_Xbar_bresp      = 'd0;
                reg_Xbar_bvalid     = 'd0;
                reg_Xbar_bid        = 'd0;

                reg_Xbar_S0_wdata   = 'd0;
                reg_Xbar_S0_wstrb   = 'd0;
                reg_Xbar_S0_wvalid  = 'd0;
                reg_Xbar_S0_awaddr  = 'd0;
                reg_Xbar_S0_awvalid = 'd0;
                reg_Xbar_S0_bready  = 'd0;
                reg_Xbar_S0_awid    = 'd0;
                reg_Xbar_S0_awlen   = 'd0;
                reg_Xbar_S0_awsize  = 'd0;
                reg_Xbar_S0_awburst = 'd0;
                reg_Xbar_S0_wlast  = 'd0;

                reg_Xbar_S1_wdata   = 'd0;
                reg_Xbar_S1_wstrb   = 'd0;
                reg_Xbar_S1_wvalid  = 'd0;
                reg_Xbar_S1_awaddr  = 'd0;
                reg_Xbar_S1_awvalid = 'd0;
                reg_Xbar_S1_bready  = 'd0;
                reg_Xbar_S1_awid    = 'd0;
                reg_Xbar_S1_awlen   = 'd0;
                reg_Xbar_S1_awsize  = 'd0;
                reg_Xbar_S1_awburst = 'd0;
                reg_Xbar_S1_wlast  = 'd0;
                
                // reg_Xbar_S2_wdata   = 'd0;
                // reg_Xbar_S2_wstrb   = 'd0;
                // reg_Xbar_S2_wvalid  = 'd0;
                // reg_Xbar_S2_awaddr  = 'd0;
                // reg_Xbar_S2_awvalid = 'd0;
                // reg_Xbar_S2_bready  = 'd0;
                // reg_Xbar_S2_awid    = 'd0;
                // reg_Xbar_S2_awlen   = 'd0;
                // reg_Xbar_S2_awsize  = 'd0;
                // reg_Xbar_S2_awburst = 'd0;
                // reg_Xbar_S2_wlast  = 'd0;
            end
            ysyx_24120011_Xbar_S0:begin
                reg_Xbar_awready    = Xbar_S0_awready;
                reg_Xbar_wready     = Xbar_S0_wready ;
                reg_Xbar_bresp      = Xbar_S0_bresp  ;
                reg_Xbar_bvalid     = Xbar_S0_bvalid ;
                reg_Xbar_bid        = Xbar_S0_bid    ;

                reg_Xbar_S0_wdata   = Xbar_wdata   ;
                reg_Xbar_S0_wstrb   = Xbar_wstrb   ;
                reg_Xbar_S0_wvalid  = Xbar_wvalid  ;
                reg_Xbar_S0_awaddr  = Xbar_awaddr  ;
                reg_Xbar_S0_awvalid = Xbar_awvalid ;
                reg_Xbar_S0_bready  = Xbar_bready  ;
                reg_Xbar_S0_awid    = Xbar_awid    ;
                reg_Xbar_S0_awlen   = Xbar_awlen   ;
                reg_Xbar_S0_awsize  = Xbar_awsize  ;
                reg_Xbar_S0_awburst = Xbar_awburst ;
                reg_Xbar_S0_wlast  = Xbar_wlast  ;

                reg_Xbar_S1_wdata   = 'd0;
                reg_Xbar_S1_wstrb   = 'd0;
                reg_Xbar_S1_wvalid  = 'd0;
                reg_Xbar_S1_awaddr  = 'd0;
                reg_Xbar_S1_awvalid = 'd0;
                reg_Xbar_S1_bready  = 'd0;
                reg_Xbar_S1_awid    = 'd0;
                reg_Xbar_S1_awlen   = 'd0;
                reg_Xbar_S1_awsize  = 'd0;
                reg_Xbar_S1_awburst = 'd0;
                reg_Xbar_S1_wlast  = 'd0;
                
                // reg_Xbar_S2_wdata   = 'd0;
                // reg_Xbar_S2_wstrb   = 'd0;
                // reg_Xbar_S2_wvalid  = 'd0;
                // reg_Xbar_S2_awaddr  = 'd0;
                // reg_Xbar_S2_awvalid = 'd0;
                // reg_Xbar_S2_bready  = 'd0;
                // reg_Xbar_S2_awid    = 'd0;
                // reg_Xbar_S2_awlen   = 'd0;
                // reg_Xbar_S2_awsize  = 'd0;
                // reg_Xbar_S2_awburst = 'd0;
                // reg_Xbar_S2_wlast  = 'd0;
            end
            ysyx_24120011_Xbar_S1:begin
                reg_Xbar_awready    = Xbar_S1_awready;
                reg_Xbar_wready     = Xbar_S1_wready ;
                reg_Xbar_bresp      = Xbar_S1_bresp  ;
                reg_Xbar_bvalid     = Xbar_S1_bvalid ;
                reg_Xbar_bid        = Xbar_S1_bid    ;

                reg_Xbar_S0_wdata   = 'd0;
                reg_Xbar_S0_wstrb   = 'd0;
                reg_Xbar_S0_wvalid  = 'd0;
                reg_Xbar_S0_awaddr  = 'd0;
                reg_Xbar_S0_awvalid = 'd0;
                reg_Xbar_S0_bready  = 'd0;
                reg_Xbar_S0_awid    = 'd0;
                reg_Xbar_S0_awlen   = 'd0;
                reg_Xbar_S0_awsize  = 'd0;
                reg_Xbar_S0_awburst = 'd0;
                reg_Xbar_S0_wlast  = 'd0;

                reg_Xbar_S1_wdata   = Xbar_wdata   ;
                reg_Xbar_S1_wstrb   = Xbar_wstrb   ;
                reg_Xbar_S1_wvalid  = Xbar_wvalid  ;
                reg_Xbar_S1_awaddr  = Xbar_awaddr  ;
                reg_Xbar_S1_awvalid = Xbar_awvalid ;
                reg_Xbar_S1_bready  = Xbar_bready  ;
                reg_Xbar_S1_awid    = Xbar_awid    ;
                reg_Xbar_S1_awlen   = Xbar_awlen   ;
                reg_Xbar_S1_awsize  = Xbar_awsize  ;
                reg_Xbar_S1_awburst = Xbar_awburst ;
                reg_Xbar_S1_wlast  = Xbar_wlast  ;
                
                // reg_Xbar_S2_wdata   = 'd0;
                // reg_Xbar_S2_wstrb   = 'd0;
                // reg_Xbar_S2_wvalid  = 'd0;
                // reg_Xbar_S2_awaddr  = 'd0;
                // reg_Xbar_S2_awvalid = 'd0;
                // reg_Xbar_S2_bready  = 'd0;
                // reg_Xbar_S2_awid    = 'd0;
                // reg_Xbar_S2_awlen   = 'd0;
                // reg_Xbar_S2_awsize  = 'd0;
                // reg_Xbar_S2_awburst = 'd0;
                // reg_Xbar_S2_wlast  = 'd0;
            end
            // ysyx_24120011_Xbar_S2:begin
            //     reg_Xbar_awready    = Xbar_S2_awready;
            //     reg_Xbar_wready     = Xbar_S2_wready ;
            //     reg_Xbar_bresp      = Xbar_S2_bresp  ;
            //     reg_Xbar_bvalid     = Xbar_S2_bvalid ;
            //     reg_Xbar_bid        = Xbar_S2_bid    ;

            //     reg_Xbar_S0_wdata   = 'd0;
            //     reg_Xbar_S0_wstrb   = 'd0;
            //     reg_Xbar_S0_wvalid  = 'd0;
            //     reg_Xbar_S0_awaddr  = 'd0;
            //     reg_Xbar_S0_awvalid = 'd0;
            //     reg_Xbar_S0_bready  = 'd0;
            //     reg_Xbar_S0_awid    = 'd0;
            //     reg_Xbar_S0_awlen   = 'd0;
            //     reg_Xbar_S0_awsize  = 'd0;
            //     reg_Xbar_S0_awburst = 'd0;
            //     reg_Xbar_S0_wlast  = 'd0;

            //     reg_Xbar_S1_wdata   = 'd0;
            //     reg_Xbar_S1_wstrb   = 'd0;
            //     reg_Xbar_S1_wvalid  = 'd0;
            //     reg_Xbar_S1_awaddr  = 'd0;
            //     reg_Xbar_S1_awvalid = 'd0;
            //     reg_Xbar_S1_bready  = 'd0;
            //     reg_Xbar_S1_awid    = 'd0;
            //     reg_Xbar_S1_awlen   = 'd0;
            //     reg_Xbar_S1_awsize  = 'd0;
            //     reg_Xbar_S1_awburst = 'd0;
            //     reg_Xbar_S1_wlast  = 'd0;

            //     reg_Xbar_S2_wdata   = Xbar_wdata   ;
            //     reg_Xbar_S2_wstrb   = Xbar_wstrb   ;
            //     reg_Xbar_S2_wvalid  = Xbar_wvalid  ;
            //     reg_Xbar_S2_awaddr  = Xbar_awaddr  ;
            //     reg_Xbar_S2_awvalid = Xbar_awvalid ;
            //     reg_Xbar_S2_bready  = Xbar_bready  ;
            //     reg_Xbar_S2_awid    = Xbar_awid    ;
            //     reg_Xbar_S2_awlen   = Xbar_awlen   ;
            //     reg_Xbar_S2_awsize  = Xbar_awsize  ;
            //     reg_Xbar_S2_awburst = Xbar_awburst ;
            //     reg_Xbar_S2_wlast  = Xbar_wlast  ;
            // end
            default:begin
                reg_Xbar_awready    = 'd0;
                reg_Xbar_wready     = 'd0;
                reg_Xbar_bresp      = 'd0;
                reg_Xbar_bvalid     = 'd0;
                reg_Xbar_bid        = 'd0;

                reg_Xbar_S0_wdata   = 'd0;
                reg_Xbar_S0_wstrb   = 'd0;
                reg_Xbar_S0_wvalid  = 'd0;
                reg_Xbar_S0_awaddr  = 'd0;
                reg_Xbar_S0_awvalid = 'd0;
                reg_Xbar_S0_bready  = 'd0;
                reg_Xbar_S0_awid    = 'd0;
                reg_Xbar_S0_awlen   = 'd0;
                reg_Xbar_S0_awsize  = 'd0;
                reg_Xbar_S0_awburst = 'd0;
                reg_Xbar_S0_wlast  = 'd0;

                reg_Xbar_S1_wdata   = 'd0;
                reg_Xbar_S1_wstrb   = 'd0;
                reg_Xbar_S1_wvalid  = 'd0;
                reg_Xbar_S1_awaddr  = 'd0;
                reg_Xbar_S1_awvalid = 'd0;
                reg_Xbar_S1_bready  = 'd0;
                reg_Xbar_S1_awid    = 'd0;
                reg_Xbar_S1_awlen   = 'd0;
                reg_Xbar_S1_awsize  = 'd0;
                reg_Xbar_S1_awburst = 'd0;
                reg_Xbar_S1_wlast  = 'd0;
                
                // reg_Xbar_S2_wdata   = 'd0;
                // reg_Xbar_S2_wstrb   = 'd0;
                // reg_Xbar_S2_wvalid  = 'd0;
                // reg_Xbar_S2_awaddr  = 'd0;
                // reg_Xbar_S2_awvalid = 'd0;
                // reg_Xbar_S2_bready  = 'd0;
                // reg_Xbar_S2_awid    = 'd0;
                // reg_Xbar_S2_awlen   = 'd0;
                // reg_Xbar_S2_awsize  = 'd0;
                // reg_Xbar_S2_awburst = 'd0;
                // reg_Xbar_S2_wlast  = 'd0;
            end
        endcase
    end
    //next_state赋值
    always@(*) begin
        case(r_Xbar_state)
            ysyx_24120011_Xbar_IDLE:begin
                if(Xbar_arvalid) begin
                    if(Xbar_araddr == 32'h02000048 || Xbar_araddr == 32'h0200004c) begin
                        r_Xbar_next_state = ysyx_24120011_Xbar_S1;
                    end
                    else begin
                        r_Xbar_next_state = ysyx_24120011_Xbar_S0;
                    end
                end
                else begin
                    r_Xbar_next_state = ysyx_24120011_Xbar_IDLE;
                end
            end
            ysyx_24120011_Xbar_S0:begin
                if(read_S0_done)begin
                    r_Xbar_next_state = ysyx_24120011_Xbar_IDLE;
                end
                else begin
                    r_Xbar_next_state = ysyx_24120011_Xbar_S0;
                end
            end
            ysyx_24120011_Xbar_S1:begin
                if(read_S1_done)begin
                    r_Xbar_next_state = ysyx_24120011_Xbar_IDLE;
                end
                else begin
                    r_Xbar_next_state = ysyx_24120011_Xbar_S1;
                end
            end
            // ysyx_24120011_Xbar_S2:begin
            //     if(read_S2_done)begin
            //         r_Xbar_next_state = ysyx_24120011_Xbar_IDLE;
            //     end
            //     else begin
            //         r_Xbar_next_state = ysyx_24120011_Xbar_S2;
            //     end
            // end
            default: r_Xbar_next_state = ysyx_24120011_Xbar_IDLE;
        endcase
        case(w_Xbar_state)
            ysyx_24120011_Xbar_IDLE:begin
                if(Xbar_awvalid) begin
                    // if(Xbar_awaddr == 32'h000003f8) begin
                    //     w_Xbar_next_state = ysyx_24120011_Xbar_S1;
                    // end
                    // else begin
                        w_Xbar_next_state = ysyx_24120011_Xbar_S0;
                    //end
                end
                else begin
                    w_Xbar_next_state = ysyx_24120011_Xbar_IDLE;
                end
            end
            ysyx_24120011_Xbar_S0:begin
                if(write_S0_done)begin
                    w_Xbar_next_state = ysyx_24120011_Xbar_IDLE;
                end
                else begin
                    w_Xbar_next_state = ysyx_24120011_Xbar_S0;
                end
            end
            ysyx_24120011_Xbar_S1:begin
                if(write_S1_done)begin
                    w_Xbar_next_state = ysyx_24120011_Xbar_IDLE;
                end
                else begin
                    w_Xbar_next_state = ysyx_24120011_Xbar_S1;
                end
            end
            // ysyx_24120011_Xbar_S2:begin
            //     if(write_S2_done)begin
            //         w_Xbar_next_state = ysyx_24120011_Xbar_IDLE;
            //     end
            //     else begin
            //         w_Xbar_next_state = ysyx_24120011_Xbar_S2;
            //     end
            // end
            default: w_Xbar_next_state = ysyx_24120011_Xbar_IDLE;
        endcase
    end
    //状态跳转
    always@(posedge clk) begin
        if(rst) begin
            r_Xbar_state <= ysyx_24120011_Xbar_IDLE;
            w_Xbar_state <= ysyx_24120011_Xbar_IDLE;
        end
        else begin
            r_Xbar_state <= r_Xbar_next_state;
            w_Xbar_state <= w_Xbar_next_state;
        end
    end
endmodule