
module ysyx_24120011_Clint (
    input wire clk,
    input wire rst,

    //AR-axi4lite
    input  [31:0]     araddr,
    input             arvalid,
    output            arready,
    //AR-axi4
    input  [3:0]      arid,
    input  [7:0]      arlen,
    input  [2:0]      arsize,
    input  [1:0]      arburst,
    //R-axi4lite               
    output [31:0]     rdata,
    output [1:0]      rresp,
    output            rvalid,
    input             rready,
    //R-axi4
    output            rlast,
    output [3:0]      rid,
    //AW-axi4lite
    input  [31:0]     awaddr,
    input             awvalid,
    output            awready,
    //AW-axi4
    input  [3:0]      awid,
    input  [7:0]      awlen,
    input  [2:0]      awsize,
    input  [1:0]      awburst,
    //W-axi4lite
    input  [31:0]     wdata,
    input  [3:0]      wstrb,
    input             wvalid,
    output            wready,
    //W-axi4
    input             wlast,
    //B-axi4lite
    output [1:0]      bresp,
    output            bvalid,
    input             bready,
    //B-axi4
    output [3:0]	  bid
);
    parameter ysyx_24120011_S_AXI_IDLE  = 3'b000;
    parameter ysyx_24120011_S_AXI_RADDR = 3'b001;
    parameter ysyx_24120011_S_AXI_RDATA = 3'b010;

    reg [2:0] state;
    reg [2:0] next_state;

    reg [31:0] rdata_reg;
    reg rvalid_reg;
    
    reg [63:0] mtime;

    // AR
	assign arready = (state == ysyx_24120011_S_AXI_RADDR) ? 1 : 0;
	// R
	assign rdata   = rdata_reg;
    assign rresp   = 2'b00;
	assign rvalid  = rvalid_reg;
    assign rid     = 'd0;
    assign rlast   = rvalid;
	// AW 
	assign awready = 'd0;
	// W 
	assign wready  = 'd0;
	// B 
	assign bvalid  = 'd0;
	assign bresp   = 2'b00;
    assign bid     = 'd0;


    always@(posedge clk)begin
        if(rst) begin
            mtime <= 64'b0;
        end
        else begin
            mtime <= mtime + 1;
        end
    end

    //read_delay
    always@(posedge clk)begin
        if(state == ysyx_24120011_S_AXI_RDATA)begin
            if(araddr == 32'h02000048) begin
                rdata_reg <= mtime[31:0];
            end
            else if(araddr == 32'h0200004c) begin
                rdata_reg <= mtime[63:32];
            end
            else begin
                rdata_reg <= 32'b0;
            end
            rvalid_reg <= 1;
        end
        else begin
            rvalid_reg <= 0;
        end
    end

    always@(*)begin
        case(state)
            ysyx_24120011_S_AXI_IDLE  : next_state = (arvalid) ? ysyx_24120011_S_AXI_RADDR :  ysyx_24120011_S_AXI_IDLE;
			ysyx_24120011_S_AXI_RADDR : next_state = (arvalid && arready) ? ysyx_24120011_S_AXI_RDATA : ysyx_24120011_S_AXI_RADDR;
			ysyx_24120011_S_AXI_RDATA : next_state = (rvalid  && rready ) ? ysyx_24120011_S_AXI_IDLE  : ysyx_24120011_S_AXI_RDATA;
			default : next_state = ysyx_24120011_S_AXI_IDLE;
        endcase
    end

    always@(posedge clk)begin
        if(rst)begin
            state <= ysyx_24120011_S_AXI_IDLE;
        end
        else begin
            state <= next_state;
        end
    end

endmodule