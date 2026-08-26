

// ██╗      ███████╗ ██╗   ██╗
// ██║      ██╔════╝ ██║   ██║
// ██║      ███████╗ ██║   ██║
// ██║      ╚════██║ ██║   ██║
// ███████╗ ███████║ ╚██████╔╝
// ╚══════╝ ╚══════╝  ╚═════╝
`ifdef USE_VERILATOR
import "DPI-C" function void difftest_mem_set(int addr);
`endif
`include "csr_defines.v"
module ysyx_26010011_LSU(
	input            clock,
	input            reset,
	input            flush_valid,////////////////////TODO 异常冲刷还未实现！不可中断进行中的axi4
	// CPU 流水线接口
	input            lsu_in_valid,
	input      [ 4:0]lsu_in_bus_exception,/////////////////////TODO 异常冲刷还未实现！不可中断进行中的axi4
	output           lsu_in_ready,
	input      [31:0]lsu_in_bus_addr,
	input      [31:0]lsu_in_bus_wdata,
	input      [ 1:0]lsu_in_bus_perip_mask,
	input            lsu_in_bus_isUnSigned,
	input            lsu_in_bus_isLOAD,
	input            lsu_in_bus_isSTORE,
	input			 lsu_in_bus_isWGPR,
	input		     lsu_in_bus_opCSR,
	input		[3:0]lsu_in_bus_rd,
	input	[11:0]lsu_in_bus_csrrd,
	input	[31:0]lsu_in_bus_csr_result,



	output           lsu_out_valid/*verilator public*/,
	output reg [ 4:0]lsu_out_bus_exception,
	input            lsu_out_ready,
	output reg [31:0]lsu_out_bus_gpr_wdata,
	
	output		   lsu_out_bus_rd_valid,
	output		   lsu_out_bus_bypass_valid,
	output		   lsu_out_bus_csr_valid,
	output   [3:0] lsu_out_bus_rd,
	output  [11:0] lsu_out_bus_csrrd,
	output	[31:0] lsu_out_bus_csr_result,
	
	
	// AXI4 写地址通道
	output [31:0]     awaddr,
	output            awvalid,
	input             awready,
	output [3:0]      awid,
	output [7:0]      awlen,
	output [2:0]      awsize,
	output [1:0]      awburst,
	// AXI4 写数据通道
	output [31:0]     wdata,
	output [3:0]      wstrb,
	output            wvalid,
	input             wready,
	output            wlast,
	// AXI4 写响应通道
	input             bvalid,
	output            bready,
/* verilator lint_off UNUSEDSIGNAL */
	input  [1:0]      bresp,
	input  [3:0]      bid,
/* verilator lint_on UNUSEDSIGNAL */
	// AXI4 读地址通道
	output [31:0]     araddr,
	output            arvalid,
	input             arready,
	output [3:0]      arid,
	output [7:0]      arlen,
	output [2:0]      arsize,
	output [1:0]      arburst,
	// AXI4 读数据通道
	input  [31:0]     rdata,
	input             rvalid,
	output            rready,
	input             rlast,
/* verilator lint_off UNUSEDSIGNAL */
	input  [1:0]      rresp,
	input  [3:0]      rid
/* verilator lint_on UNUSEDSIGNAL */
);
	localparam S_IDLE        = 3'd0;
	localparam S_WAIT_AW_W   = 3'd1; // 等待写地址与写数据握手
	localparam S_WAIT_BRESP  = 3'd2; // 等待写响应(B通道)
	localparam S_WAIT_AR     = 3'd3; // 等待读地址握手
	localparam S_WAIT_RDATA  = 3'd4; // 等待读数据返回(R通道)
	reg [31:0] lsu_out_bus_rdata;
	reg [2:0] state/*verilator public*/, next_state;

	// 握手信号 lsu_
	wire aw_fire;
	wire w_fire;
	wire b_fire/*verilator public*/;
	wire ar_fire;
	wire r_fire/*verilator public*/;

	reg[31:0]val;

	assign lsu_out_bus_rd = lsu_in_bus_rd;
	assign lsu_out_bus_csrrd = lsu_in_bus_csrrd;
	assign lsu_out_bus_csr_result = lsu_in_bus_csr_result;


	assign lsu_out_bus_rd_valid = lsu_in_valid & lsu_in_bus_isWGPR;
	assign lsu_out_bus_bypass_valid = lsu_out_valid & lsu_in_bus_isWGPR;
	assign lsu_out_bus_csr_valid = lsu_in_valid & lsu_in_bus_opCSR;


	assign aw_fire = awvalid && awready;
	assign w_fire  = wvalid && wready;
	assign b_fire = bvalid && bready;
	assign ar_fire = arvalid && arready;
	assign r_fire = rvalid && rready;

	assign awaddr  = {lsu_in_bus_addr};
	assign awid    = 4'b0;
	assign awlen   = 8'b0;
	
	assign awsize  = (lsu_in_bus_perip_mask == 2'b00) ? 3'b000 :
							(lsu_in_bus_perip_mask == 2'b01) ? 3'b001 : 3'b010;
	assign awburst = 2'b01;   // INCR

	assign wdata   = lsu_in_bus_wdata << (lsu_in_bus_addr[1:0] * 8);
	assign wstrb   = (
							(lsu_in_bus_perip_mask == 2'b00) ? 4'b0001 :
							(lsu_in_bus_perip_mask == 2'b01) ? 4'b0011 : 
															   4'b1111 ) << lsu_in_bus_addr[1:0];
	assign wlast   = 1'b1;    // single beat

	assign araddr  = lsu_in_bus_addr;
	assign arid    = 4'b0;
	assign arlen   = 8'b0;
	assign arsize  = (lsu_in_bus_perip_mask == 2'b00) ? 3'b000 :
					 (lsu_in_bus_perip_mask == 2'b01) ? 3'b001 : 3'b010;
	assign arburst = 2'b01;   // INCR

	assign awvalid = ((state == S_WAIT_AW_W)) & !reset & ~lsu_out_bus_exception[4];
	assign wvalid  = awvalid;
	assign arvalid = ((state == S_IDLE && lsu_in_valid && lsu_in_bus_isLOAD) || (state == S_WAIT_AR)) & !reset & ~lsu_out_bus_exception[4];

	assign bready  = ((state == S_WAIT_BRESP) || (state == S_IDLE)) & lsu_out_ready & !reset;
	assign rready  = ((state == S_WAIT_RDATA) || (state == S_IDLE)) & lsu_out_ready & !reset;

`ifdef USE_VERILATOR
	always @(*) begin
		if(lsu_in_bus_isSTORE && awvalid && awready) begin
			if((
				(lsu_in_bus_addr >= 32'h30000000 && lsu_in_bus_addr < 32'h31000000)
				||(lsu_in_bus_addr >= 32'h0f000000 && lsu_in_bus_addr < 32'h0f002000)
				||(lsu_in_bus_addr >= 32'h80000000 && lsu_in_bus_addr < 32'h80400000)
				||(lsu_in_bus_addr >= 32'ha0000000 && lsu_in_bus_addr < 32'ha8000000)
				||(lsu_in_bus_addr >= 32'h20000000 && lsu_in_bus_addr < 32'h20001000)
			))
			begin
				difftest_mem_set(lsu_in_bus_addr);
			end
		end
		if(((lsu_in_bus_isSTORE && lsu_in_valid)||(lsu_in_bus_isLOAD && lsu_in_valid)) && !(
				(lsu_in_bus_addr >= 32'h30000000 && lsu_in_bus_addr < 32'h31000000)
			  ||(lsu_in_bus_addr >= 32'h0f000000 && lsu_in_bus_addr < 32'h0f002000)
			  ||(lsu_in_bus_addr >= 32'h80000000 && lsu_in_bus_addr < 32'h80400000)
			  ||(lsu_in_bus_addr >= 32'ha0000000 && lsu_in_bus_addr < 32'ha8000000)
			  ||(lsu_in_bus_addr >= 32'h20000000 && lsu_in_bus_addr < 32'h20001000)
		)) begin
			if((lsu_in_bus_addr >= 32'h10000000) && (lsu_in_bus_addr <= 32'h10000005)) begin
				difftest_skip_ref(lsu_in_bus_addr);
			end else if((lsu_in_bus_addr >= 32'h21000000) && (lsu_in_bus_addr <= 32'h21200000)) begin
				difftest_skip_ref(lsu_in_bus_addr);
			end else if((lsu_in_bus_addr >= 32'h10011000) && (lsu_in_bus_addr <= 32'h10011004)) begin
				difftest_skip_ref(lsu_in_bus_addr);
			end
		end
	end
`endif

	always @(*) begin
		next_state = state;
		case(state)
			S_IDLE: begin
				if (lsu_in_valid) begin
					if (lsu_in_bus_isSTORE) begin
						if (aw_fire && w_fire) next_state = S_WAIT_BRESP;
						else                   next_state = S_WAIT_AW_W;
					end else if(lsu_in_bus_isLOAD)begin
						if (ar_fire) next_state = S_WAIT_RDATA;
						else         next_state = S_WAIT_AR;
					end else begin
						next_state = S_IDLE;
					end
				end
			end
			
			S_WAIT_AW_W: begin
				if (aw_fire && w_fire) begin
					next_state = S_WAIT_BRESP;
				end
			end
			
			S_WAIT_BRESP: begin
				if (b_fire) next_state = S_IDLE;
			end
			
			S_WAIT_AR: begin
				if (ar_fire) begin
					next_state = S_WAIT_RDATA;
				end
			end
			
			S_WAIT_RDATA: begin
				if (r_fire & rlast) next_state = S_IDLE;
			end
			
			default: next_state = S_IDLE;
		endcase
	end

	always @(posedge clock) begin
		if (reset) state <= S_IDLE;
		else     state <= (lsu_in_valid&lsu_out_bus_exception[4])?S_IDLE:next_state;
	end

	assign lsu_out_valid =  lsu_in_valid & !flush_valid &
							((state == S_WAIT_RDATA && r_fire) ||
							 (state == S_WAIT_BRESP && b_fire) || !(lsu_in_bus_isLOAD || lsu_in_bus_isSTORE) || lsu_out_bus_exception[4]);
	assign lsu_in_ready = (lsu_in_valid & (lsu_in_bus_isLOAD | lsu_in_bus_isSTORE)) ? ((lsu_out_ready & (r_fire | b_fire)) | lsu_out_bus_exception[4]):(1);

	// assign val = val0;
	always @(*) begin
		case(lsu_in_bus_addr[1:0])
			2'b00: val = rdata;
			2'b01: val = {{8{rdata[31]}}, rdata[31:8]};
			2'b10: val = {{16{rdata[31]}}, rdata[31:16]};
			2'b11: val = {{24{rdata[31]}}, rdata[31:24]};
			default: val = rdata;
		endcase
	end


	
	always @(*) begin
		case(lsu_in_bus_perip_mask)
			2'b00: lsu_out_bus_rdata = (!lsu_in_bus_isUnSigned) ? {{24{val[7]}},  val[7:0]}  : {{24{1'b0}}, val[7:0]};
			2'b01: lsu_out_bus_rdata = (!lsu_in_bus_isUnSigned) ? {{16{val[15]}}, val[15:0]} : {{16{1'b0}}, val[15:0]};
			2'b10: lsu_out_bus_rdata = val[31:0];
			default: lsu_out_bus_rdata = val[31:0];
		endcase
	end
	

`ifdef USE_VERILATOR
	wire debug_LSU_LOADING/*verilator public*/;
	wire debug_LSU_WRITING/*verilator public*/;
	wire debug_LSU_WRITE_FINAL/*verilator public*/;
	wire debug_LSU_LOAD_FINAL/*verilator public*/;
	assign debug_LSU_LOADING = (state!=S_IDLE)&lsu_in_bus_isLOAD&lsu_in_valid;
	assign debug_LSU_WRITING = (state!=S_IDLE)&lsu_in_bus_isSTORE&lsu_in_valid;
	assign debug_LSU_WRITE_FINAL = lsu_out_ready&lsu_out_valid&lsu_in_bus_isSTORE&lsu_in_valid;
	assign debug_LSU_LOAD_FINAL = lsu_out_ready&lsu_out_valid&lsu_in_bus_isLOAD&lsu_in_valid;
`endif
	always @(*) begin
		if(lsu_in_bus_exception[4]) begin
			lsu_out_bus_exception = lsu_in_bus_exception;
		end else begin
			if(lsu_in_valid & (lsu_in_bus_isLOAD | lsu_in_bus_isSTORE)) begin
				case (lsu_in_bus_perip_mask)
					2'b00: begin
						lsu_out_bus_exception = lsu_in_bus_exception;
					end
					2'b01: begin
						if(lsu_in_bus_addr[0]) lsu_out_bus_exception = {1'b1,(lsu_in_bus_isLOAD)?`ysyx_26010011_EXCEPTION_MISALIGNED_LOAD:`ysyx_26010011_EXCEPTION_MISALIGNED_STORE};
						else                   lsu_out_bus_exception = lsu_in_bus_exception;
					end
					2'b10: begin
						if(lsu_in_bus_addr[1:0]!=2'b00) lsu_out_bus_exception = {1'b1,(lsu_in_bus_isLOAD)?`ysyx_26010011_EXCEPTION_MISALIGNED_LOAD:`ysyx_26010011_EXCEPTION_MISALIGNED_STORE};
						else                           lsu_out_bus_exception = lsu_in_bus_exception;
					end
					default: begin
						lsu_out_bus_exception = {1'b1,(lsu_in_bus_isLOAD)?`ysyx_26010011_EXCEPTION_MISALIGNED_LOAD:`ysyx_26010011_EXCEPTION_MISALIGNED_STORE};
					end
				endcase
			end else begin
				lsu_out_bus_exception = lsu_in_bus_exception;
			end
		end
	end

	always @(*) begin
		if(lsu_in_bus_isLOAD) begin
			lsu_out_bus_gpr_wdata = lsu_out_bus_rdata;
		end else begin
			lsu_out_bus_gpr_wdata = lsu_in_bus_addr;
		end
	end
endmodule
