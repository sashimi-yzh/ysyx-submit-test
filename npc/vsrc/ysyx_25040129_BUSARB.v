

module ysyx_25040129_BUSARB (//只负责ifu和mem之间的读总线仲裁
	input clk,
	input rst,
	//---------------IFU请求(其实是icache）---------------
	//----------------读地址---------------
	input [31:0] icache_araddr,
	input icache_arvalid,
	output reg icache_arready,
	input [7:0] icache_arlen, // 突发传输大小
	input [1:0] icache_arburst,
	//----------------读数据---------------
	output reg [31:0] icache_rdata,
	output reg [1:0] icache_rresp,
	output reg icache_rvalid,
	input icache_rready,
	output reg icache_rlast,
	//---------------LSU请求---------------
	//----------------读地址---------------
	input [31:0] lsu_araddr,
	input lsu_arvalid,
	output reg lsu_arready,
	input [2:0] lsu_arsize,
	//----------------读数据---------------
	output reg [31:0] lsu_rdata,
	output reg [1:0] lsu_rresp,
	output reg lsu_rvalid,
	input lsu_rready,
	//----------------请求转发---------------
	//----------------读地址---------------
	output reg[31:0] araddr,
	output reg arvalid,
	output reg [2:0] arsize,
	input arready,
	output reg[7:0] arlen, 
	output reg [1:0] arburst,
	//----------------读数据---------------
	input [31:0] rdata,
	input [1:0] rresp,
	input rvalid,
	output reg rready,
	input rlast
);
	// 当前策略是优先处理ifu的请求
	// 如果
	localparam IDLE = 2'b00;
	localparam HANDLE_IFU = 2'b01;
	localparam HANDLE_LSU = 2'b10;
	reg [1:0] state, next_state;
	always @(*) begin
		case (state)
			IDLE:begin
				if(icache_arvalid) next_state = HANDLE_IFU;
				else if(lsu_arvalid) next_state = HANDLE_LSU;
				else next_state = IDLE;
			end 
			HANDLE_IFU: next_state = (icache_rready && rvalid && rlast) ? IDLE : HANDLE_IFU;
			HANDLE_LSU: next_state = (lsu_rready && rvalid) ? IDLE : HANDLE_LSU;
			default: next_state = IDLE;
		endcase
	end
	always @(posedge clk) begin
		if(rst) state <= IDLE;
		else state <= next_state;
	end
	//-------------信号转接逻辑-------------
	always @(*) begin
		case (state)
			IDLE: begin
				icache_arready = 1'b0;
				icache_rdata = 32'b0;
				icache_rresp = 2'b00;
				icache_rvalid = 1'b0;
				icache_rlast = 1'b0;
				lsu_arready = 1'b0;
				lsu_rdata = 32'b0;
				lsu_rresp = 2'b00;
				lsu_rvalid = 1'b0;
				araddr = 32'b0;
				arvalid = 1'b0;
				rready = 1'b0;
				arsize = 3'b000; // 默认不读取
				arlen = 8'b0;
				arburst = 2'b00;
			end
			HANDLE_IFU: begin
				icache_arready = arready;
				icache_rdata = rdata;
				icache_rresp = rresp;
				icache_rvalid = rvalid;
				lsu_arready = 1'b0; // LSU不处理
				lsu_rdata = 32'b0;
				lsu_rresp = 2'b00;
				lsu_rvalid = 1'b0;
				araddr = icache_araddr;
				arvalid = icache_arvalid;
				arsize = 3'b010; // 默认读取字
				rready = icache_rready;
				arlen = icache_arlen;
				arburst = icache_arburst;
				icache_rlast = rlast; 
			end
			HANDLE_LSU: begin
				icache_arready = 1'b0; // IFU不处理
				icache_rdata = 32'b0;
				icache_rresp = 2'b00;
				icache_rvalid = 1'b0;
				icache_rlast = 1'b0;
				lsu_arready = arready;
				lsu_rdata = rdata;
				lsu_rresp = rresp;
				lsu_rvalid = rvalid;
				araddr = lsu_araddr;
				arvalid = lsu_arvalid;
				arsize = lsu_arsize; // LSU的大小
				rready = lsu_rready;
				arlen = 8'b0; // LSU不支持突发传输
				arburst = 2'b00; // LSU不支持突发传输
			end
			default: 
			begin
				icache_arready = 1'b0;
				icache_rdata = 32'b0;
				icache_rresp = 2'b00;
				icache_rvalid = 1'b0;
				icache_rlast = 1'b0;
				lsu_arready = 1'b0;
				lsu_rdata = 32'b0;
				lsu_rresp = 2'b00;
				lsu_rvalid = 1'b0;
				araddr = 32'b0;
				arvalid = 1'b0;
				rready = 1'b0;
				arsize = 3'b000; // 默认不读取
				arlen = 8'b0;
				arburst = 2'b00;
			end
		endcase
	end
endmodule
