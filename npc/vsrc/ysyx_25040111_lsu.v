`include "HDR/ysyx_25040111_inc.vh"

module ysyx_25040111_lsu (
    input           clock,          
    input           reset,

    input           lsu_rvalid,
    output          lsu_rready,
    output [31:0]   lsu_rdata,
    input  [31:0]   lsu_raddr,
    input  [7:0]    lsu_rlen,
    input           lsu_burst,
    input           lsu_rsign,
    input  [1:0]    lsu_rmask,

    input           lsu_wvalid,
    output          lsu_wready,
    input  [31:0]   lsu_wdata,
    input  [31:0]   lsu_waddr,
    input  [1:0]    lsu_wmask

`ifdef STA_SOC
    ,input          io_master_awready,
    output          io_master_awvalid,
    output [31:0]   io_master_awaddr,
    output [3:0]    io_master_awid,
    output [7:0]    io_master_awlen,
    output [2:0]    io_master_awsize,
    output [1:0]    io_master_awburst,

    input           io_master_wready,
    output          io_master_wvalid,
    output [31:0]   io_master_wdata,
    output [3:0]    io_master_wstrb,
    output          io_master_wlast,

    output          io_master_bready,
    input           io_master_bvalid,
    input  [1:0]    io_master_bresp,
    input  [3:0]    io_master_bid,

    input           io_master_arready,
    output          io_master_arvalid,
    output [31:0]   io_master_araddr,
    output [3:0]    io_master_arid,
    output [7:0]    io_master_arlen,
    output [2:0]    io_master_arsize,
    output [1:0]    io_master_arburst,

    output          io_master_rready,
    input           io_master_rvalid,
    input  [1:0]    io_master_rresp,
    input  [31:0]   io_master_rdata,
    input           io_master_rlast,
    input  [3:0]    io_master_rid
`endif // RUNSOC
);

//-----------------------------------------------------------------
// Register / Wire
//-----------------------------------------------------------------

    // axi read
    reg         arvalid;
    wire        arready;
    wire        rvalid;
    wire        rready;
    wire [31:0] rout;

    // clint
    wire        arready_clint;
    wire [31:0] rdata_clint;
    wire        rvalid_clint;

    // axi write
    reg         awvalid;
    wire        awready;
    reg         wvalid;
    wire        wready;
    reg         wlast;
    wire        bready;
    wire        bvalid;

    // wire to case
    reg [31:0]  rdata;
    reg [31:0]  woffset, roffset;
    reg [2:0]   wsize, rsize;
    reg [3:0]   wstrb;
    // wire to case

    reg         reading;
    reg         writing;
    reg [7:0]   rcount;

    wire [7:0]  arlen = lsu_burst ? lsu_rlen : 8'b0;
    wire        is_clint = (lsu_raddr >= `DEV_CLINT && lsu_raddr <= `DEV_CLINT_END);
    wire        rend     = rcount == arlen;
    
//-----------------------------------------------------------------
// External Interface
//-----------------------------------------------------------------

    assign lsu_rready = rvalid & rready & reading;
    assign lsu_rdata  = rdata;
    assign lsu_wready = bvalid & bready & writing;

`ifdef STA_SOC
    assign awready            = io_master_awready;
    assign io_master_awvalid  = awvalid;
    assign io_master_awaddr   = lsu_waddr;
    assign io_master_awid     = 4'b0;
    assign io_master_awlen    = 8'b0;
    assign io_master_awsize   = wsize;
    assign io_master_awburst  = 2'b0;

    assign wready             = io_master_wready;
    assign io_master_wvalid   = wvalid;
    assign io_master_wdata    = woffset;
    assign io_master_wstrb    = wstrb;
    assign io_master_wlast    = wlast;

    assign io_master_bready   = bready;
    assign bvalid             = io_master_bvalid;

    assign io_master_arid     = 4'b0;
    assign io_master_arsize   = rsize;
    assign io_master_araddr   = lsu_raddr;
    assign io_master_arlen    = arlen;
    assign io_master_arburst  = {1'b0, lsu_burst};
    assign arready            = is_clint ? arready_clint   : io_master_arready;
    assign io_master_arvalid  = is_clint ? 1'b0            : arvalid;

    assign io_master_rready   = is_clint ? 1'b0            : rready;
    assign rvalid             = is_clint ? rvalid_clint    : io_master_rvalid;
    assign rout               = is_clint ? rdata_clint     : io_master_rdata;
`else
    assign awready            = awready_sram;
    assign wready             = wready_sram;
    assign bvalid             = bvalid_sram;
    assign arready            = is_clint ? arready_clint   : arready_sram;
    assign rvalid             = is_clint ? rvalid_clint    : rvalid_sram;
    assign rout               = is_clint ? rdata_clint     : rdata_sram;
`endif

//-----------------------------------------------------------------
// State Machine
//-----------------------------------------------------------------

    // -------------------------axi ready-----------------------
    // reading
    always @(posedge clock) begin
        if (reset)
            reading <= 1'b0;
        else if (lsu_rvalid & ~reading)
            reading <= 1'b1;
        else if (rvalid & rready & rend)
            reading <= 1'b0;
    end

    // arvalid
    always @(posedge clock) begin
        if (reset)
            arvalid <= 1'b0;
        else if (lsu_rvalid & ~reading)
            arvalid <= 1'b1;
        else if (arvalid & arready)
            arvalid <= 1'b0;
    end

    // rcount
    always @(posedge clock) begin
        if (reset)
            rcount <= 0;
        else if (rready & rvalid)
            rcount <= rend ? 8'b0 : rcount + 1;
    end

    // -------------------------axi write-----------------------
    // writing
    always @(posedge clock) begin
        if (reset)
            writing <= 1'b0;
        else if (lsu_wvalid & ~writing)
            writing <= 1'b1;
        else if (bvalid & bready)
            writing <= 1'b0;
    end

    // awvalid
    always @(posedge clock) begin
        if (reset)
            awvalid <= 1'b0;
        else if (lsu_wvalid & ~writing)
            awvalid <= 1'b1;
        else if (awvalid & awready)
            awvalid <= 0;
    end

    // wlast wvalid
    always @(posedge clock) begin
        if (reset) begin
            wvalid <= 1'b0;
            wlast <= 1'b0;
        end
        else if (lsu_wvalid & ~writing) begin
            wvalid <= 1'b1;
            wlast <= 1'b1;
        end
        else if (wvalid & wready) begin
            wvalid <= 1'b0;
            wlast <= 1'b0;
        end
    end

//-----------------------------------------------------------------
// Combinational Logic
//-----------------------------------------------------------------

    // ready always high
    assign rready = 1'b1;
    assign bready = 1'b1;

    // read data process
    always @(*) begin
        case (lsu_raddr[1:0])
            2'b00: roffset = rout;
            2'b01: roffset = rout >> 8;
            2'b10: roffset = rout >> 16;
            2'b11: roffset = rout >> 24;
        endcase

        case (lsu_rmask)
            2'b00: begin 
                rsize = 3'b000; 
                rdata = 32'b0; 
            end
            2'b01: begin 
                rsize = 3'b000; 
                rdata = {{24{roffset[7] & lsu_rsign}}, roffset[7:0]}; 
            end
            2'b10: begin 
                rsize = 3'b001; 
                rdata = {{16{roffset[15] & lsu_rsign}}, roffset[15:0]};   
            end
            2'b11: begin
                 rsize = 3'b010; 
                 rdata = roffset; 
            end
        endcase
    end

    // write data process
      always @(*) begin
        case (lsu_waddr[1:0])
            2'b00: woffset = lsu_wdata;
            2'b01: woffset = lsu_wdata << 8;
            2'b10: woffset = lsu_wdata << 16;
            2'b11: woffset = lsu_wdata << 24;
        endcase

        case (lsu_wmask)
            2'b00: begin 
                wstrb = 4'h0; 
                wsize = 3'b000;
            end
            2'b01: begin 
                wstrb = 4'b0001 << lsu_waddr[1:0];
                wsize = 3'b000; 
            end
            2'b10: begin 
                wstrb = lsu_waddr[1] ? 4'b1100 : 4'b0011; 
                wsize = 3'b001;
            end
            2'b11: begin 
                wstrb = 4'b1111; 
                wsize = 3'b010;
            end
        endcase
    end

//-----------------------------------------------------------------
// MODULE INSTANCES
//-----------------------------------------------------------------

    // CLINT
    ysyx_25040111_clint u_clint(
        .clock   	(clock          ),
        .reset   	(reset          ),
        .araddr  	(lsu_raddr      ),
        .arvalid 	(arvalid        ),
        .rready  	(rready         ),
        .arready 	(arready_clint  ),
        .rdata   	(rdata_clint    ),
        .rvalid  	(rvalid_clint   )
    );
    
`ifndef STA_SOC
    // SRAM
    wire        arready_sram;
    wire [31:0] rdata_sram;
    reg         rvalid_sram;
    wire        awready_sram;
    wire        wready_sram;
    wire        bvalid_sram;
    ysyx_25040111_sram u_sram(
        .clock   	(clock          ),
        .reset   	(reset          ),
        .arburst    ({1'b0, lsu_burst}),
        .arlen      (arlen),
        .araddr  	(lsu_raddr      ),
        .arsize     (rsize          ),
        .arvalid 	(arvalid & ~is_clint),
        .arready 	(arready_sram   ),
        .rdata   	(rdata_sram     ),
        .rvalid  	(rvalid_sram    ),
        .rready  	(rready         ),
        .awaddr  	(lsu_waddr      ),
        .awsize     (wsize          ),
        .awvalid 	(awvalid        ),
        .awready 	(awready_sram   ),
        .wdata   	(woffset        ),
        .wstrb   	(wstrb          ),
        .wvalid  	(wvalid         ),
        .wlast      (wlast          ),
        .wready  	(wready_sram    ),
        .bvalid  	(bvalid_sram    ),
        .bready  	(bready         )
    );
`endif

endmodule
