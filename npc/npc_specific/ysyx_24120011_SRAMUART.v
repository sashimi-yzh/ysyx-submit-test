module ysyx_24120011_SRAMUART (
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
    reg [7:0] sram [2**26-1:0];

    parameter ysyx_24120011_S_AXI_IDLE  = 3'b000;
    parameter ysyx_24120011_S_AXI_RADDR = 3'b001;
    parameter ysyx_24120011_S_AXI_RDATA = 3'b010;
    parameter ysyx_24120011_S_AXI_WADDR = 3'b011;
    parameter ysyx_24120011_S_AXI_WDATA = 3'b100;
    parameter ysyx_24120011_S_AXI_WRESP = 3'b101;
    parameter ysyx_24120011_S_AXI_RESP_OKAY = 2'b00;

    reg [2:0] state;
    reg [2:0] next_state;
    reg wready_reg;

    // AR
	assign arready = (state == ysyx_24120011_S_AXI_RADDR) ? 1 : 0;
	// R
	assign rdata   = araddr == 32'h30000000 ? 32'h800002b7 :
                     araddr == 32'h30000004 ? 32'h00028067 :
                     {sram[{araddr[31:2],2'b00}+3-32'h80000000],sram[{araddr[31:2],2'b00}+2-32'h80000000],sram[{araddr[31:2],2'b00}+1-32'h80000000],sram[{araddr[31:2],2'b00}+0-32'h80000000]};
    assign rresp   = ysyx_24120011_S_AXI_RESP_OKAY;
	assign rvalid  = (state == ysyx_24120011_S_AXI_RDATA) ? 1 : 0;
    assign rid     = 'd0;
    assign rlast   = rvalid;
	// AW 
	assign awready = (state == ysyx_24120011_S_AXI_WADDR) ? 1 : 0;
	// W 
	assign wready  = (state == ysyx_24120011_S_AXI_WADDR) ? 1 : 0;
	// B 
	assign bvalid  = (state == ysyx_24120011_S_AXI_WRESP) ? 1 : 0;
	assign bresp   = ysyx_24120011_S_AXI_RESP_OKAY;
    assign bid     = 'd0;

    initial begin
        string img_file;
        if (!$value$plusargs("IMG=%s", img_file)) begin
        $display("Error: IMG not provided.");
        $finish;
        end
        $readmemh(img_file, sram, 0, 2**26-1);
    end
    
    always@(posedge clk)begin
        if(state == ysyx_24120011_S_AXI_WADDR)begin
            if(awaddr == 32'ha00003f8) begin
                $write("%c", wdata[7:0]);
                $fflush();
            end
            else begin
                if(wstrb[0])begin
                    sram[{awaddr[31:2],2'b00}+0-32'h80000000] <= wdata[7:0];
                end
                if(wstrb[1])begin
                    sram[{awaddr[31:2],2'b00}+1-32'h80000000] <= wdata[15:8];
                end
                if(wstrb[2])begin
                    sram[{awaddr[31:2],2'b00}+2-32'h80000000] <= wdata[23:16];
                end
                if(wstrb[3])begin
                    sram[{awaddr[31:2],2'b00}+3-32'h80000000] <= wdata[31:24];
                end
            end
        end
        else begin
        end
    end

    always@(*)begin
        case(state)
            ysyx_24120011_S_AXI_IDLE  : next_state = (arvalid) ? ysyx_24120011_S_AXI_RADDR : (awvalid) ? ysyx_24120011_S_AXI_WADDR : ysyx_24120011_S_AXI_IDLE;
			ysyx_24120011_S_AXI_RADDR :  next_state = (arvalid && arready) ? ysyx_24120011_S_AXI_RDATA : ysyx_24120011_S_AXI_RADDR;
			ysyx_24120011_S_AXI_RDATA :  next_state = (rvalid  && rready ) ? ysyx_24120011_S_AXI_IDLE  : ysyx_24120011_S_AXI_RDATA;
			ysyx_24120011_S_AXI_WADDR :  next_state = (awvalid && awready) ? ysyx_24120011_S_AXI_WRESP : ysyx_24120011_S_AXI_WADDR;
			//ysyx_24120011_S_AXI_WDATA :  next_state = (wvalid  && wready ) ? ysyx_24120011_S_AXI_WRESP : ysyx_24120011_S_AXI_WDATA;
			ysyx_24120011_S_AXI_WRESP :  next_state = (bvalid  && bready ) ? ysyx_24120011_S_AXI_IDLE  : ysyx_24120011_S_AXI_WRESP;
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