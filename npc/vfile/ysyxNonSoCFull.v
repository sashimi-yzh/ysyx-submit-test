`ifndef __YSYXNONSOCFULL__
`define __YSYXNONSOCFULL__

//`define ysyx_23060229_nonSoC//用于定义RESET_PC=0x80000000
`define ysyx_23060229_sim_iverilog//用于ebreak退出仿真环境

//`include "ysyx_23060229.v"
//`include "ysyx_23060229_memory.v"

module ysyxNonSoCFull(
	input clock,
	input reset
	//output [31:0] pc,
	//output one_inst_done
	//`ifdef verilator
	//,output [31:0] regs [0:15]
	//`endif
);

	parameter HEX_FILE = "none";

	wire [31:0] araddr; wire arvalid; wire arready; wire [3:0] arid; wire [7:0] arlen; wire [2:0] arsize; wire [1:0] arburst;
	wire [31:0] rdata; wire [1:0] rresp; wire rvalid; wire rready; wire rlast; wire [3:0] rid;
	wire [31:0] awaddr; wire awvalid; wire awready; wire [3:0] awid; wire [7:0] awlen; wire [2:0] awsize; wire [1:0] awburst;
	wire [31:0] wdata; wire [3:0] wstrb; wire wvalid; wire wready; wire wlast;
	wire [1:0] bresp; wire bvalid; wire bready; wire [3:0] bid;


	ysyx_23060229			cpu		(.clock(clock), .reset(reset), .io_interrupt(1'b0),//io_interrupt
									.io_master_awready(awready), .io_master_awvalid(awvalid), .io_master_awaddr(awaddr), .io_master_awid(awid), .io_master_awlen(awlen), .io_master_awsize(awsize), .io_master_awburst(awburst),
									.io_master_wready(wready), .io_master_wvalid(wvalid), .io_master_wdata(wdata), .io_master_wstrb(wstrb), .io_master_wlast(wlast), 
									.io_master_bready(bready), .io_master_bvalid(bvalid), .io_master_bresp(bresp), .io_master_bid(bid),
									.io_master_arready(arready), .io_master_arvalid(arvalid), .io_master_araddr(araddr), .io_master_arid(arid), .io_master_arlen(arlen), .io_master_arsize(arsize), .io_master_arburst(arburst),
									.io_master_rready(rready), .io_master_rvalid(rvalid), .io_master_rresp(rresp), .io_master_rdata(rdata), .io_master_rlast(rlast), .io_master_rid(rid),
									.io_slave_awready(), .io_slave_awvalid(1'b0), .io_slave_awaddr(32'b0), .io_slave_awid(4'b0), .io_slave_awlen(8'b0), .io_slave_awsize(3'b0), .io_slave_awburst(2'b0),
									.io_slave_wready(), .io_slave_wvalid(1'b0), .io_slave_wdata(32'b0), .io_slave_wstrb(4'b0), .io_slave_wlast(1'b0),
									.io_slave_bready(1'b0), .io_slave_bvalid(), .io_slave_bresp(), .io_slave_bid(),
									.io_slave_arready(), .io_slave_arvalid(1'b0), .io_slave_araddr(32'b0), .io_slave_arid(4'b0), .io_slave_arlen(8'b0), .io_slave_arsize(3'b0), .io_slave_arburst(2'b0),
									.io_slave_rready(1'b0), .io_slave_rvalid(), .io_slave_rresp(), .io_slave_rdata(), .io_slave_rlast(), .io_slave_rid()
									//.pc(pc), .one_inst_done(one_inst_done)
									//`ifdef verilator
									//, .regs(regs)
									//`endif
									);


	ysyx_23060229_memory	#(.HEX_FILE(HEX_FILE)) 		mem		
									(clock, reset, 
									araddr, arvalid, arready, arid, arlen, arsize, arburst,
									rdata, rresp, rvalid, rready, rlast, rid,
									awaddr, awvalid, awready, awid, awlen, awsize, awburst,
									wdata, wstrb, wvalid, wready, wlast,
									bresp, bvalid, bready, bid
									);

endmodule

`endif
