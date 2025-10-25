

module ysyx_25040129_XBAR (
	input clk,
	input rst,
	//---------------XBAR输入---------------
	//---------------读地址---------------
	input [31:0] araddr,
	input arvalid,
	input [2:0] arsize,
	output reg arready,
	input [7:0] arlen, 
	input [1:0] arburst,
	//---------------读数据---------------
	output reg[31:0] rdata,
	output reg [1:0]rresp,
	output reg rvalid,
	input rready,
	output rlast,
	//---------------写地址---------------
	input [31:0] awaddr,
	input awvalid,
	output awready,
	//---------------写数据---------------
	input [3:0] wstrb,
	input [31:0] wdata,
	input wvalid,
	output wready,
	//---------------写响应---------------
	output [1:0]bresp,
	output bvalid,
	input bready,
	///--------------XBAR转发---------------
	//---------------外部设备转发------------
	//---------------读地址---------------
	output reg [31:0] soc_araddr,
	output reg soc_arvalid,
	output reg [2:0] soc_arsize,
	input soc_arready,
	output [7:0]soc_arlen,
	output [1:0] soc_arburst,
	//---------------读数据---------------
	input [31:0] soc_rdata,
	input [1:0]soc_rresp,
	input soc_rvalid,
	output reg soc_rready,
	input soc_rlast,
	//---------------写地址---------------
	output [31:0] soc_awaddr,
	output soc_awvalid,
	input soc_awready,
	//---------------写数据---------------
	output [3:0] soc_wstrb,
	output [31:0] soc_wdata,
	output soc_wvalid,
	input soc_wready,
	//---------------写响应---------------
	input [1:0]soc_bresp,
	input soc_bvalid,
	output soc_bready,
	//---------------RTC---------------
	//RTC不支持写入，应该在XBAR中拦截并报错
	//---------------读地址---------------
	output reg [31:0] rtc_araddr,
	output reg rtc_arvalid,
	input rtc_arready,
	//---------------读数据---------------
	input [31:0] rtc_rdata,
	input [1:0]rtc_rresp,
	input rtc_rvalid,
	output reg rtc_rready
);
assign soc_arlen = arlen; // 直接转发
assign soc_arburst = arburst; // 直接转发
assign rlast = soc_rlast; // 直接转发

assign soc_awaddr = awaddr;
assign soc_awvalid = awvalid;
assign awready = soc_awready;

assign soc_wstrb = wstrb;
assign soc_wdata = wdata;
assign soc_wvalid = wvalid;
assign wready = soc_wready;

assign bresp = soc_bresp;
assign bvalid = soc_bvalid;
assign soc_bready = bready;

localparam IDLE = 3'b000;
localparam HANDLE_SOC = 3'b001;
localparam HANDLE_RTC = 3'b011;

reg [2:0] state;
reg [2:0] next_state;
always @(posedge clk) begin
	if (rst) begin
		state <= IDLE;
	end else begin
		state <= next_state;
	end
end
//-----------------------信号转接-----------------------
//---------------------目前已经接入
always @(*) begin
	case (state)
		HANDLE_SOC:begin
			soc_araddr = araddr;
			soc_arvalid = arvalid;
			arready = soc_arready;
			soc_arsize = arsize;

			rdata = soc_rdata;
			rresp = soc_rresp;
			rvalid = soc_rvalid;
			soc_rready = rready;

			rtc_araddr = 32'b0;
			rtc_arvalid = 1'b0;

			rtc_rready = 1'b0;
		end
		HANDLE_RTC:begin
			soc_araddr = 32'b0;
			soc_arvalid = 1'b0;
			arready = 1'b0;
			soc_arsize = 3'b000;

			rdata = 32'b0;
			rresp = 2'b00;
			rvalid = 1'b0;
			soc_rready = 1'b0;

			rtc_araddr = araddr;
			rtc_arvalid = arvalid;
			arready = rtc_arready;

			rdata = rtc_rdata;
			rresp = rtc_rresp;
			rvalid = rtc_rvalid;
			rtc_rready = rready;
		end
		default: begin
			arready = 1'b0;
			soc_araddr = 32'b0;

			rdata = 32'b0;
			rresp = 2'b00;
			rvalid = 1'b0;

			rtc_araddr = 32'b0;
			rtc_arvalid = 1'b0;
			rtc_rready = 1'b0;


			soc_araddr = 32'b0;
			soc_arvalid = 1'b0;
			soc_arsize = 3'b000;

			soc_rready = 1'b0;
		end
	endcase
end
//-----------------------下一状态产生逻辑-----------------------
always @(*) begin
	case (state)
		IDLE: begin
			if(arvalid)begin
			if(araddr >= `ysyx_25040129_RTC_PORT_ADDR && araddr < `ysyx_25040129_RTC_PORT_ADDR + `ysyx_25040129_RTC_PORT_SIZE)
				next_state = HANDLE_RTC;
				else next_state = HANDLE_SOC;
			end
			else next_state = IDLE;
		end
		HANDLE_SOC: if(rready && soc_rvalid && soc_rlast) begin 
						next_state = IDLE;
					`ifdef ysyx_25040129_DPI
					if(rresp != `ysyx_25040129_OKAY && rready && soc_rvalid) 
						$error("XBAR: Invalid response %b %b", rresp, bresp);
					if(bresp != `ysyx_25040129_OKAY && bready && soc_bvalid)
						$error("XBAR: Invalid response %b %b", rresp, bresp);
					`endif
		end
					 else next_state = HANDLE_SOC;
		HANDLE_RTC: if(rready && rtc_rvalid)begin
			 next_state = IDLE;
			 `ifdef ysyx_25040129_DPI
			 if(rtc_rresp != `ysyx_25040129_OKAY && rready && rtc_rvalid) 
					$error("XBAR: Invalid RTC response %b", rtc_rresp);
			`endif
		end
		else next_state = HANDLE_RTC;
		default: next_state = IDLE;
	endcase
end

endmodule

