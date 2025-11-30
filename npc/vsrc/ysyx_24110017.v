`ifdef __ICARUS__
	`timescale 1ns/1ps
`endif
`define ysyx_24110017_SIMFAST

module ysyx_24110017(
	input	 wire clock,
	input	 wire reset,
	input	 wire io_interrupt,
	input	 wire io_master_awready,
	output wire io_master_awvalid,
	output wire [ 3:0] io_master_awid,
	output wire [31:0] io_master_awaddr,
	output wire [ 7:0] io_master_awlen,
	output wire [ 2:0] io_master_awsize,
	output wire [ 1:0] io_master_awburst,
	input  wire io_master_wready,
	output wire io_master_wvalid,
	output wire [31:0] io_master_wdata,
	output wire [ 3:0] io_master_wstrb,
	output wire io_master_wlast,
	output wire io_master_bready,
	input  wire io_master_bvalid,
	input  wire [ 3:0] io_master_bid,
	input  wire [ 1:0] io_master_bresp,
	input  wire io_master_arready,
	output wire io_master_arvalid,
	output wire [ 3:0] io_master_arid,
	output wire [31:0] io_master_araddr,
	output wire [ 7:0] io_master_arlen,
	output wire [ 2:0] io_master_arsize,
	output wire [ 1:0] io_master_arburst,
	output wire io_master_rready,
	input  wire io_master_rvalid,
	input  wire [ 3:0] io_master_rid,
	input  wire [31:0] io_master_rdata,
	input  wire [ 1:0] io_master_rresp,
	input  wire io_master_rlast,
	output wire io_slave_awready,
	input  wire io_slave_awvalid,
	input  wire [ 3:0] io_slave_awid,
	input  wire [31:0] io_slave_awaddr,
	input  wire [ 7:0] io_slave_awlen,
	input  wire [ 2:0] io_slave_awsize,
	input  wire [ 1:0] io_slave_awburst,
	output wire io_slave_wready,
	input  wire io_slave_wvalid,
	input  wire [31:0] io_slave_wdata,
	input  wire [ 3:0] io_slave_wstrb,
	input  wire io_slave_wlast,
	input  wire io_slave_bready,
	output wire io_slave_bvalid,
	output wire [ 3:0] io_slave_bid,
	output wire [ 1:0] io_slave_bresp,
	output wire io_slave_arready,
	input  wire io_slave_arvalid,
	input  wire [ 3:0] io_slave_arid,
	input  wire [31:0] io_slave_araddr,
	input  wire [ 7:0] io_slave_arlen,
	input  wire [ 2:0] io_slave_arsize,
	input  wire [ 1:0] io_slave_arburst,
	input  wire io_slave_rready,
	output wire io_slave_rvalid,
	output wire [ 3:0] io_slave_rid,
	output wire [31:0] io_slave_rdata,
	output wire [ 1:0] io_slave_rresp,
	output wire io_slave_rlast
);

/***UNDRIVEN***/
assign io_slave_awready = 1'b0;
assign io_slave_wready  = 1'b0;
assign io_slave_bvalid  = 1'b0;
assign io_slave_bid     = 4'b0;
assign io_slave_bresp   = 2'b0;
assign io_slave_arready = 1'b0;
assign io_slave_rvalid  = 1'b0;
assign io_slave_rid     = 4'b0;
assign io_slave_rdata   = 32'b0;
assign io_slave_rresp   = 2'b0;
assign io_slave_rlast   = 1'b0;

/***BTB***/
wire [31:0] snpc;
/***IFU***/
wire [31:0] inst_if,pc_if;
wire if_valid;
wire [31:0] if_axi_araddr,if_axi_rdata;
wire [ 7:0] if_axi_arlen;
wire [ 3:0] if_axi_arid,if_axi_rid;
wire [ 2:0] if_axi_arsize;
wire [ 1:0] if_axi_arburst;
wire [ 1:0] if_axi_rresp;
wire if_axi_arvalid,if_axi_arready,if_axi_rvalid,if_axi_rready,if_axi_rlast;
/***ICACHE***/
wire [31:0] icache_axi_araddr,icache_axi_rdata;
wire [ 7:0] icache_axi_arlen;
wire [ 3:0] icache_axi_arid,icache_axi_rid;
wire [ 2:0] icache_axi_arsize;
wire [ 1:0] icache_axi_arburst;
wire [ 1:0] icache_axi_rresp;
wire icache_axi_arvalid,icache_axi_arready,icache_axi_rvalid,icache_axi_rready,icache_axi_rlast;
/***IDU***/
`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
`ifndef ysyx_24110017_SIMFAST
wire [31:0] inst_id;//difftest
`endif
`endif
`endif
wire id_valid,id_ready;
wire [20:0] prepc;
wire [ 1:0] prepc_en;
wire [ 3:0] rs1,rs2;
wire [31:0] pc_id,imm_id;
wire [ 4:0] op_id;
wire [ 2:0] funct3_id;
wire [31:0] r1_id,r2_id;
wire [ 3:0] rd_id;
wire gpr_wen_id;
wire ls_valid_id;
wire fencei_id;
/***EXU***/
`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
`ifndef ysyx_24110017_SIMFAST
wire [31:0] pc_ex,inst_ex,npc_ex;//difftest
`endif
`endif
`endif
wire        ex_ready,ex_valid;
wire [31:0] xrd_ex;
wire [ 3:0] rd_ex;
wire        gpr_wen_ex;
wire [3:0]  csrs_wen_ex;
wire [31:0] ls_addr,ls_wdata;
wire [31:0] dnpc_ex;
/***LSU***/
wire [31:0] ls_rdata;
wire        ls_done;
wire [31:0] ls_axi_awaddr,ls_axi_wdata,ls_axi_araddr,ls_axi_rdata;
wire [ 3:0] ls_axi_wstrb;
wire [ 7:0] ls_axi_awlen,ls_axi_arlen;
wire [ 3:0] ls_axi_awid,ls_axi_bid,ls_axi_arid,ls_axi_rid;
wire [ 2:0] ls_axi_awsize,ls_axi_arsize;
wire [ 1:0] ls_axi_awburst,ls_axi_arburst;
wire [ 1:0] ls_axi_bresp,ls_axi_rresp;
wire        ls_axi_awvalid,ls_axi_awready,ls_axi_wvalid,ls_axi_wready,
            ls_axi_bvalid,ls_axi_bready,ls_axi_arvalid,ls_axi_arready,
						ls_axi_rvalid,ls_axi_rready,ls_axi_wlast,ls_axi_rlast;
/***Arbiter-Xbar***/
/***My-Clint***/
wire [31:0] c_axi_araddr,c_axi_rdata;
wire [ 7:0] c_axi_arlen;
wire [ 3:0] c_axi_arid,c_axi_rid;
wire [ 2:0] c_axi_arsize;
wire [ 1:0] c_axi_arburst;
wire [ 1:0] c_axi_rresp;
wire c_axi_arvalid,c_axi_arready,c_axi_rvalid,c_axi_rready,c_axi_rlast;
/***RFU***/
wire [31:0]r1,r2;
wire [31:0]mepc,mstatus,mcause,mtvec;
`ifdef __ICARUS__
wire [31:0] a0;//iverilog仿真检测a0
`endif

wire isRAW = ((rs1 == rd_ex) || (rs2 == rd_ex)) && (rd_ex != 0);
reg CHazarden;
always @(posedge clock) begin
	if(id_valid && ex_ready) CHazarden <= 1'b1;
  else CHazarden <= 1'b0;
end
wire isCHazard = CHazarden && (dnpc_ex != pc_id) && (pc_id != 32'h0) && (dnpc_ex != 32'h0);

ysyx_24110017_BTB #(1,16,8,1,16,16) BTB(clock,reset,if_axi_araddr,snpc,prepc,pc_if,prepc_en);
ysyx_24110017_IFU IFU(clock,reset,isCHazard,
	if_valid,id_ready,dnpc_ex,snpc,pc_if,inst_if,
	if_axi_arready,if_axi_arvalid,if_axi_arid,if_axi_araddr,
	if_axi_arlen,if_axi_arsize,if_axi_arburst,
	if_axi_rready,if_axi_rvalid,if_axi_rid,if_axi_rdata,if_axi_rresp,if_axi_rlast
);
ysyx_24110017_CACHE #(1,4,16) ICACHE(clock,reset,fencei_id, //w < n
	if_axi_arready,if_axi_arvalid,if_axi_arid,if_axi_araddr,
	if_axi_arlen,if_axi_arsize,if_axi_arburst,
	if_axi_rready,if_axi_rvalid,if_axi_rid,if_axi_rdata,if_axi_rresp,if_axi_rlast,
	icache_axi_arready,icache_axi_arvalid,icache_axi_arid,icache_axi_araddr,
  icache_axi_arlen,icache_axi_arsize,icache_axi_arburst,
  icache_axi_rready,icache_axi_rvalid,icache_axi_rid,icache_axi_rdata,icache_axi_rresp,icache_axi_rlast
);
ysyx_24110017_IDU IDU(clock,reset,isRAW,isCHazard,
`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
`ifndef ysyx_24110017_SIMFAST
	inst_id,
`endif
`endif
`endif
	prepc,prepc_en,rs1,rs2,r1,r2,
	if_valid,id_ready,id_valid,ex_ready,
	pc_if,inst_if,
	pc_id,imm_id,op_id,funct3_id,r1_id,r2_id,
	rd_id,gpr_wen_id,ls_valid_id,
	fencei_id
);
ysyx_24110017_EXU EXU(clock,reset,isCHazard,
`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
`ifndef ysyx_24110017_SIMFAST
	inst_id,pc_ex,inst_ex,npc_ex,
`endif
`endif
`endif
	id_valid,ex_ready,ex_valid,
	pc_id,imm_id,op_id,funct3_id,
	r1_id,r2_id,rd_id,gpr_wen_id,
	mepc,mstatus,mcause,mtvec,
	xrd_ex,rd_ex,gpr_wen_ex,
	csrs_wen_ex,
	ls_addr,ls_wdata,ls_rdata,ls_done,
	dnpc_ex
);
ysyx_24110017_LSU LSU(clock,reset,
	op_id,funct3_id,ls_valid_id && (!isCHazard),
	ls_addr,ls_wdata,ls_rdata,ls_done,
	ls_axi_awready,ls_axi_awvalid,ls_axi_awid,ls_axi_awaddr,
	ls_axi_awlen,ls_axi_awsize,ls_axi_awburst,
	ls_axi_wready,ls_axi_wvalid,ls_axi_wdata,ls_axi_wstrb,ls_axi_wlast,
	ls_axi_bready,ls_axi_bvalid,ls_axi_bid,ls_axi_bresp,
	ls_axi_arready,ls_axi_arvalid,ls_axi_arid,ls_axi_araddr,
	ls_axi_arlen,ls_axi_arsize,ls_axi_arburst,
	ls_axi_rready,ls_axi_rvalid,ls_axi_rid,ls_axi_rdata,ls_axi_rresp,ls_axi_rlast
);
ysyx_24110017_Xbar Xbar(clock,reset,
  icache_axi_arready,icache_axi_arvalid,icache_axi_arid,icache_axi_araddr,
  icache_axi_arlen,icache_axi_arsize,icache_axi_arburst,
  icache_axi_rready,icache_axi_rvalid,icache_axi_rid,icache_axi_rdata,icache_axi_rresp,icache_axi_rlast,
	ls_axi_awready,ls_axi_awvalid,ls_axi_awid,ls_axi_awaddr,
	ls_axi_awlen,ls_axi_awsize,ls_axi_awburst,
	ls_axi_wready,ls_axi_wvalid,ls_axi_wdata,ls_axi_wstrb,ls_axi_wlast,
	ls_axi_bready,ls_axi_bvalid,ls_axi_bid,ls_axi_bresp,
	ls_axi_arready,ls_axi_arvalid,ls_axi_arid,ls_axi_araddr,
	ls_axi_arlen,ls_axi_arsize,ls_axi_arburst,
	ls_axi_rready,ls_axi_rvalid,ls_axi_rid,ls_axi_rdata,ls_axi_rresp,ls_axi_rlast,
	io_master_awready,io_master_awvalid,io_master_awid,io_master_awaddr,
	io_master_awlen,io_master_awsize,io_master_awburst,
	io_master_wready,io_master_wvalid,io_master_wdata,io_master_wstrb,io_master_wlast,
	io_master_bready,io_master_bvalid,io_master_bid,io_master_bresp,
	io_master_arready,io_master_arvalid,io_master_arid,io_master_araddr,
	io_master_arlen,io_master_arsize,io_master_arburst,
	io_master_rready,io_master_rvalid,io_master_rid,io_master_rdata,io_master_rresp,io_master_rlast,
	c_axi_arready,c_axi_arvalid,c_axi_arid,c_axi_araddr,
	c_axi_arlen,c_axi_arsize,c_axi_arburst,
	c_axi_rready,c_axi_rvalid,c_axi_rid,c_axi_rdata,c_axi_rresp,c_axi_rlast
);
/***My-Clint***/
ysyx_24110017_CLINT CLINT(clock,reset,
	c_axi_arready,c_axi_arvalid,c_axi_arid,c_axi_araddr,
	c_axi_arlen,c_axi_arsize,c_axi_arburst,
	c_axi_rready,c_axi_rvalid,c_axi_rid,c_axi_rdata,c_axi_rresp,c_axi_rlast
);

ysyx_24110017_RegisterFile #(4,32) RFU (clock,xrd_ex,rd_ex,gpr_wen_ex,rs1,r1,rs2,r2
`ifdef __ICARUS__
	,a0
`endif
);
ysyx_24110017_Reg #(32, 32'b0)    mepc_reg    (clock,reset,xrd_ex,mepc   ,csrs_wen_ex[0]);
ysyx_24110017_Reg #(32, 32'h1800) mstatus_reg (clock,reset,xrd_ex,mstatus,csrs_wen_ex[1]);
ysyx_24110017_Reg #(32, 32'b0)    mcause_reg  (clock,reset,xrd_ex,mcause ,csrs_wen_ex[2]);
ysyx_24110017_Reg #(32, 32'b0)    mtvec_reg   (clock,reset,xrd_ex,mtvec  ,csrs_wen_ex[3]);

`ifndef ysyx_24110017_YOSYS_STA
`ifdef __ICARUS__
/***iverilog***/
always@(*) begin
		if(inst_if == 32'b00000000000100000000000001110011) begin
			if(a0 == 0) $write("%sHIT GOOD TRAP at pc = 0x%h%s\n","\033[1;32m",pc_if,"\033[0m");
			else $write("%sHIT BAD TRAP at pc = 0x%h%s\n","\033[1;31m",pc_if,"\033[0m");
			$finish;
		end
	end
`endif
`endif

`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__

`ifndef ysyx_24110017_SIMFAST
/***DIFFTEST***/
reg difftest_delay;
reg difftest;
always@(posedge clock) begin
	if(ex_valid && !isCHazard) difftest_delay <= 1'b1;
	else difftest_delay <= 1'b0;
	if(difftest_delay) difftest <= 1'b1;
	else difftest <= 1'b0;
end
`endif
/***DPIC*etrace***/
import "DPI-C" function void npc_trap();
always@(*) begin
  if(ex_valid && inst_if == 32'b00000000000100000000000001110011) begin
    npc_trap();
  end
end
`ifndef ysyx_24110017_SIMFAST
/***DPI-C*CSR***/
export "DPI-C" function csr_grab;                                    
function int csr_grab(int i);
  begin
    assign csr_grab = (i == 0) ? mepc : (i == 1) ? mstatus : (i == 2) ? mcause : (i == 3) ? mtvec : 32'b0;
  end
endfunction
/***DPI-C*DIFFTEST***/
export "DPI-C" function dpic_grab;                                    
function int dpic_grab(int i);
  begin
		assign dpic_grab = (i == 0) ? pc_ex : (i == 1) ? npc_ex : (i == 2) ? inst_ex : (i == 3) ? {31'b0,difftest} : 32'b0;
  end
endfunction
/***DPI-C*PERFORMANCE_COUNTER***/
export "DPI-C" function performance_counter;
function int performance_counter(int i);
  begin
    assign performance_counter = (i == 0) ? {31'b0,if_valid && id_ready}
															 : (i == 1) ? {31'b0,id_valid && ex_ready}
															 : (i == 2) ? {31'b0,ex_valid}
															 : (i == 3) ? {31'b0,ls_axi_rvalid && ls_axi_rready}
															 : (i == 4) ? {25'b0,inst_if[6:0]}
															 : (i == 6) ? {31'b0,if_axi_arvalid && if_axi_arready && !isCHazard}
															 : (i == 7) ? {31'b0,if_axi_rvalid && if_axi_rready}
															 : (i == 9) ? {31'b0,ls_axi_awvalid && ls_axi_awready}
															 : (i == 10) ? {31'b0,ls_axi_arvalid && ls_axi_arready}
															 : (i == 11) ? {31'b0,ls_axi_bvalid && ls_axi_bready}
															 : (i == 12) ? {31'b0,isCHazard}
															 : (i == 13) ? {31'b0,if_valid}
															 : (i == 14) ? {25'b0,inst_ex[6:0]}
															 : (i == 15) ? {31'b0,(inst_ex[6:0] == 7'b1100011) && isCHazard}
															 : (i == 16) ? {31'b0,(inst_ex[6:0] == 7'b1101111) && isCHazard}
															 : (i == 17) ? {31'b0,(inst_ex[6:0] == 7'b1100111) && isCHazard}
															 : 32'b0;
  end
endfunction
`endif
`endif
`endif
endmodule


module ysyx_24110017_IFU(
	input  wire clk,
	input  wire rst,

	input  wire flush,
	output reg  if_valid_o,
	input  wire id_ready_i,

	input  wire [31:0] dnpc_i,
	input  wire [31:0] snpc_i,

  output reg  [31:0] pc_o,
  output reg  [31:0] inst_o,
/***AXI4*R***/
	input  wire				 if_axi_arready_i,
	output reg				 if_axi_arvalid_o,
	output wire [ 3:0] if_axi_arid_o,
	output wire [31:0] if_axi_araddr_o,
	output wire [ 7:0] if_axi_arlen_o,
	output wire	[ 2:0] if_axi_arsize_o,
	output wire	[ 1:0] if_axi_arburst_o,
	output reg				 if_axi_rready_o,
	input	 wire				 if_axi_rvalid_i,
	input  wire	[ 3:0] if_axi_rid_i,
	input	 wire	[31:0] if_axi_rdata_i,
	input  wire	[ 1:0] if_axi_rresp_i,
	input  wire				 if_axi_rlast_i
);

/***分布式控制***/
parameter IDLE = 1'b0,WAIT = 1'b1;
reg state;

always @(posedge clk) begin
	if(rst || flush) state <= IDLE;
	else begin
		case(state)
			IDLE: state <= WAIT;
			WAIT:	state <= (if_valid_o && id_ready_i)   ? IDLE : state;
		endcase
	end
end

always @(posedge clk) begin
  casez({rst || flush, state})
		2'b1? : if_valid_o <= 1'b0;
		2'b01 : begin
			if(if_axi_rvalid_i && if_axi_rready_o && !if_axi_arvalid_o) begin
				if_valid_o <= 1'b1;
			end
			if(if_valid_o && id_ready_i) begin
				if_valid_o <= 1'b0;
			end
		end
		default : begin
		end
  endcase
end

`ifdef __ICARUS__
	`ifndef ysyx_24110017_YOSYS_STA
        localparam RESET_PC = 32'h80000000;
  `else
        localparam RESET_PC = 32'h30000000;
  `endif
`else
localparam RESET_PC = 32'h30000000;
`endif

wire updata = if_valid_o && id_ready_i;

reg [31:0]pc;
always @(posedge clk) begin
  casez({rst, flush, updata})
    3'b1??:  pc <= RESET_PC;
    3'b01?:  pc <= dnpc_i;
    3'b001:  pc <= snpc_i;
		default: pc <= pc;
	endcase
end

always @(posedge clk) begin
	if(updata) pc_o <= pc;
end
always @(posedge clk) begin
  if(updata) inst_o <= if_axi_rdata_i;
end

/***AXI4_LITE***/
assign if_axi_arid_o    = 4'b0;
assign if_axi_arlen_o   = 8'b0;
assign if_axi_arsize_o  = 3'b0;
assign if_axi_arburst_o = 2'b0;
assign if_axi_araddr_o  = pc;

always @(posedge clk) begin
  if(rst) begin
		if_axi_arvalid_o <= 1'b0;
		if_axi_rready_o  <= 1'b0;
  end
	else if(flush) begin
		if_axi_arvalid_o <= 1'b0;
		if_axi_rready_o <= 1'b1;
	end
	else begin
    case (state)
      IDLE: begin
				if_axi_arvalid_o <= 1'b1;
      end
      WAIT: begin
				if(if_axi_arvalid_o && if_axi_arready_i) begin
					if_axi_arvalid_o <= 1'b0;
					if_axi_rready_o  <= 1'b1;
				end
        if(if_axi_rvalid_i && if_axi_rready_o) begin
					if_axi_rready_o <= 1'b0;
				end
      end
    endcase
  end
end

endmodule


//`define ysyx_24110017_Associative //w != 0
module ysyx_24110017_BTB 
#(B_N = 2, BTAG = 16, BTARG = 8, J_N = 1, JTAG = 16, JTARG = 16) 
(
	input  wire        clk,
	input  wire        rst,

	input  wire [31:0] pc_i,
	output wire [31:0] snpc_o,

	input  wire [20:0] prepc_i,
	input  wire [31:0] prepc_tag_i,
	input  wire [ 1:0] prepc_en_i
);
	
	reg  [JTARG - 1 : 0]      jsnpc_reg [(1<<J_N) - 1 : 0];
  reg  [JTAG - 3 - J_N : 0] jtag_reg  [(1<<J_N) - 1 : 0];
  wire [JTAG - 3 - J_N : 0] jtag   = pc_i[JTAG - 1 : 2 + J_N];
  wire [J_N-1 : 0]			    jindex = pc_i[J_N + 1 : 2];

	reg  [BTARG - 1 : 0]      bsnpc_reg [(1<<B_N) - 1 : 0];
  reg  [BTAG - 3 - B_N : 0] btag_reg  [(1<<B_N) - 1 : 0];
	wire [BTAG - 3 - B_N : 0] btag   = pc_i[BTAG - 1 : 2 + B_N];
	wire [B_N - 1 : 0]			  bindex = pc_i[B_N + 1 : 2];

	wire [JTAG - 3 - J_N : 0] jtag_pre   = prepc_tag_i[JTAG - 1 : 2 + J_N];
	wire [J_N - 1 : 0]        jindex_pre = prepc_tag_i[J_N + 1 : 2];
	wire [BTAG - 3 - B_N : 0] btag_pre   = prepc_tag_i[BTAG - 1 : 2 + B_N];
	wire [B_N - 1 : 0]        bindex_pre = prepc_tag_i[B_N + 1 : 2];

	wire bhit;
  assign bhit = (btag == btag_reg[bindex]);

	wire jhit;
  assign jhit = (jtag == jtag_reg[jindex]);

	assign snpc_o = (jhit) ? {pc_i[31:JTARG],jsnpc_reg[jindex]} : (bhit) ? {pc_i[31:BTARG],bsnpc_reg[bindex]} : pc_i + 4;

  always @(posedge clk) begin
		if(rst) begin
			integer i5;
      for (i5 = 0; i5 < (1<<B_N); i5 = i5 + 1) begin
				jsnpc_reg[i5]  <= 0;
      end
    end
		else begin
			if(prepc_en_i[1]) begin
				jsnpc_reg[jindex_pre] <= prepc_i[JTARG-1:0];
			end
		end
  end

  always @(posedge clk) begin
		if(rst) begin
			integer i6;
      for (i6 = 0; i6 < (1<<J_N); i6 = i6 + 1) begin
        jtag_reg[i6]  <= 0;
      end
		end
		else begin
			if(prepc_en_i[1]) begin
				jtag_reg[jindex_pre]  <= prepc_tag_i[JTAG-1:2+J_N];
			end
		end
	end

	always @(posedge clk) begin
		if(rst) begin
	    integer i7;
	    for (i7 = 0; i7 < (1<<B_N); i7 = i7 + 1) begin
	      bsnpc_reg[i7]  <= 0;
	    end
	  end
		else begin
			if(prepc_en_i[0]) begin
				bsnpc_reg[bindex_pre] <= prepc_i[BTARG-1:0];
			end
		end
	end

	always @(posedge clk) begin
		if(rst) begin
			integer i8;
      for (i8 = 0; i8 < (1<<B_N); i8 = i8 + 1) begin
				btag_reg[i8]  <= 0;
      end
		end
		else begin
			if(prepc_en_i[0]) begin
				btag_reg[bindex_pre]  <= prepc_tag_i[BTAG-1:2+B_N];
			end
		end
	end

endmodule


module ysyx_24110017_CACHE #(n = 1, m = 4, TAG_WIDTH = 16) (
//tag width = 16中型程序,而且对于n=1的cache块，考虑burst命中的地址范围最多为5位，tag六位以上改变大概率miss，tag保存到8位,大部分branch指令范围在8位以内,但是16位综合器综合后的面积时序最优
	input  wire clk,
	input  wire rst,
	input  wire fencei_i,

	output reg  m_axi_arready,
	input  wire m_axi_arvalid,
	input  wire [ 3:0]m_axi_arid,
	input  wire [31:0]m_axi_araddr,
	input  wire [ 7:0]m_axi_arlen,
	input  wire [ 2:0]m_axi_arsize,
	input  wire [ 1:0]m_axi_arburst,
	input  wire m_axi_rready,
	output wire m_axi_rvalid,
	output wire [ 3:0]m_axi_rid,
	output wire [31:0]m_axi_rdata,
	output wire [ 1:0]m_axi_rresp,
	output wire m_axi_rlast,

	input  wire s_axi_arready,
	output reg  s_axi_arvalid,
	output wire [ 3:0]s_axi_arid,
	output reg  [31:0]s_axi_araddr,
	output reg  [ 7:0]s_axi_arlen,
	output wire [ 2:0]s_axi_arsize,
	output wire [ 1:0]s_axi_arburst,
	output wire s_axi_rready,
	input  wire s_axi_rvalid,
	input  wire [ 3:0]s_axi_rid,
	input  wire [31:0]s_axi_rdata,
	input  wire [ 1:0]s_axi_rresp,
	input  wire s_axi_rlast
);
	
	assign m_axi_rid   = 4'b0;
	assign m_axi_rresp = 2'b0;
	assign m_axi_rlast = 1'b0;
	assign s_axi_arid  = 4'b0;

	reg state;
	
	reg [31-TAG_WIDTH:0] tag_check;
	always@(posedge clk) begin
		if(m_axi_arvalid && m_axi_arready)
			tag_check <= m_axi_araddr[31:TAG_WIDTH];
	end
	wire unvalid = m_axi_arvalid && m_axi_arready && (tag_check != m_axi_araddr[31:TAG_WIDTH]);

	localparam CACHE_WIDTH = (1 << (m-2));
	localparam CACHE_DEPTH = (1 << n);

	reg  [31:0]								   cache_reg [CACHE_WIDTH - 1 : 0][CACHE_DEPTH - 1 : 0];
  reg  [TAG_WIDTH-1-m-n : 0]   tag_reg	 [CACHE_DEPTH - 1 : 0];
  reg  [CACHE_WIDTH - 1 : 0]   valid_reg [CACHE_DEPTH - 1 : 0];
	
	wire [31:0] axi_araddr = (!state) ? m_axi_araddr : s_axi_araddr;
	wire [TAG_WIDTH-1-m-n : 0] tag			 = axi_araddr[TAG_WIDTH-1 : m+n];
  wire [n-1 : 0]					   index		 = axi_araddr[m+n-1 : m];
  wire [m-3 : 0]						 offset	   = axi_araddr[m-1:2];
 
	wire hit;
	assign hit = ((tag == tag_reg[index]) && (valid_reg[index][offset])) ? 1'b1 : 1'b0;

	assign m_axi_rdata  = (|hit) ? cache_reg[offset][index] : 32'h0;
	wire	 axi_rvalid   = (s_axi_arlen != 0) ? s_axi_rlast : hit && !(m_axi_arvalid && m_axi_arready);
	reg axi_rvalid_enable;
	always @(posedge clk) begin
		if(axi_rvalid) axi_rvalid_enable <= 1'b1;
		else axi_rvalid_enable <= 1'b0;
	end
	assign m_axi_rvalid = axi_rvalid && !axi_rvalid_enable;

	localparam IDLE  = 1'b0;
  localparam TRANS = 1'b1;

	always @(posedge clk) begin
		if(rst) state <= IDLE;
		else begin
			case(state)
				IDLE:    state <= m_axi_arvalid && ((hit == 0) || unvalid) ? TRANS : state;
				TRANS:   state <= (m_axi_rready && m_axi_rvalid) ? IDLE : state;
        default: state <= state;
			endcase
		end
	end

	assign s_axi_arburst = 2'b01;
	assign s_axi_arsize = 3'b10;
	reg [m-3 : 0] burst_counter;

	always @(posedge clk) begin
		if(rst || fencei_i || unvalid) begin
			integer f;
			for (f = 0; f < CACHE_DEPTH; f = f + 1) begin : fencei
				valid_reg[f] <= 0;
			end
		end
		else begin
			case(state)
				TRANS: begin
					if(s_axi_arvalid && s_axi_arready) begin
						valid_reg[index] <= 0;
					end
					if(s_axi_rready && s_axi_rvalid) begin
						valid_reg[index][burst_counter] <= 1'b1;
					end
				end
				default : begin
				end
			endcase
		end
	end

	always @(posedge clk) begin
		if(rst) begin
			integer i10;
      for (i10 = 0; i10 < CACHE_DEPTH; i10 = i10 + 1) begin
        tag_reg[i10] <= 0;
      end
		end
		else begin
			case(state)
				TRANS: begin
					//if(s_axi_arvalid && s_axi_arready) begin
						//tag_reg[index] <= 0;
					//end
					if(s_axi_rready && s_axi_rvalid) begin
						tag_reg[index] <= s_axi_araddr[TAG_WIDTH-1:m+n];
					end
				end
				default : begin
				end
			endcase
		end
	end

	assign m_axi_arready = !state;
	assign s_axi_rready = state;
	always @(posedge clk) begin
		if(rst) begin
			s_axi_arvalid <= 1'b0;
		end
		else begin
			case(state)
				IDLE: begin
					s_axi_araddr  <= m_axi_araddr;
					if(m_axi_arvalid && m_axi_arready) begin
						if(hit == 0 || unvalid) begin
							s_axi_arvalid <= 1'b1;
							if(m_axi_araddr - 32'ha0000000 < 32'h20000000) begin
								s_axi_arlen <= CACHE_WIDTH - {6'b0,offset} - 1;
							end
							else begin
								s_axi_arlen <= 8'h0;
							end
							burst_counter <= offset;
						end
					end
				end
				TRANS: begin
					if(s_axi_arvalid && s_axi_arready) begin
						s_axi_arvalid <= 1'b0;
					end
					if(s_axi_rready && s_axi_rvalid) begin
						cache_reg[burst_counter][index] <= s_axi_rdata;
						burst_counter <= burst_counter + 1;
					end
					if(s_axi_rlast) begin
						s_axi_arlen   <= 8'b0;
					end
				end
			endcase
		end
	end

/***DPIC-AMAT***/
`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
`ifndef ysyx_24110017_SIMFAST
	export "DPI-C" function amat_counter;
	function int amat_counter(int i);
	  begin
			assign amat_counter = (i == 0) ? {31'b0,((hit != 0) && (!unvalid))} : 32'b0;
		end
	endfunction
`endif
`endif
`endif

endmodule


module ysyx_24110017_IDU(
	input	 wire clk,
	input  wire rst,

	input  wire isRAW_i,
	input  wire flush_i,

`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
`ifndef ysyx_24110017_SIMFAST
	output reg  [31:0] inst_o,//difftest
`endif
`endif
`endif

	output wire [20:0] prepc_o,
	output wire [ 1:0] prepc_en_o,
	output wire [ 3:0] rs1,
	output wire [ 3:0] rs2,
	input  wire [31:0] r1,
	input  wire [31:0] r2,

	input  wire if_valid_i,
	output wire id_ready_o,
	output wire id_valid_o,
	input  wire ex_ready_i,

	input  wire [31:0] pc_i,
  input  wire [31:0] inst_i,
	
	output reg  [31:0] pc_o,
	output reg	[31:0] imm_o,
	output reg  [ 4:0] op_o,
	output reg  [ 2:0] funct3_o,
	output reg	[31:0] r1_o,
  output reg	[31:0] r2_o,
	//output reg  [ 3:0] rs1_o,
	//output reg  [ 3:0] rs2_o,
	output reg	[ 3:0] rd_o,
	output wire	       gpr_wen_o,
	output reg         ls_valid_o,
	output wire        fencei_o
);
/***分布式控制***/
parameter IDLE = 1'b0,WAIT = 1'b1;
reg state;

always @(posedge clk) begin
	if(rst || flush_i) state <= IDLE;
  else begin
		case (state)
			IDLE: state <= (if_valid_i && id_ready_o) ? WAIT : state;
			WAIT: state <= (id_valid_o && ex_ready_i) ?	IDLE : state;
		endcase
	end
end

assign id_valid_o = (state == WAIT) && (!isRAW_i);
assign id_ready_o = (state == IDLE) && (!isRAW_i);

wire updata = id_valid_o && ex_ready_i;
/***pattern***/
wire [4:0]op;
wire [3:0]rd; //R I U J
wire [2:0]funct3;
//wire [3:0]rs1;  //R I S B
//wire [3:0]rs2;  //R S B
wire [31:0]immI,immU,immS,immB,immJ,imm;
wire [6:0]funct7; //R

always@(posedge clk) begin
  if(updata) begin
`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
`ifndef ysyx_24110017_SIMFAST
    inst_o <= inst_i;
`endif
`endif
`endif
		pc_o <= pc_i;
	end
end
always@(posedge clk) begin
  if(updata) imm_o <= imm;
end
always@(posedge clk) begin
  if(updata) op_o  <= op;
end
always@(posedge clk) begin
  if(updata) funct3_o <= funct3;
end
always@(posedge clk) begin
  if(updata) r1_o <= r1;
end
always@(posedge clk) begin
  if(updata) r2_o <= r2;
end
always@(posedge clk) begin
  if(updata) rd_o  <= rd;
end
always@(posedge clk) begin
  case(state)
	  IDLE : ls_valid_o <= 1'b0;
		WAIT : if(updata) ls_valid_o <= (op == 5'b01000 || op == 5'b00000);
	endcase
end
 
assign op = inst_i[6:2];
assign rd = (op == 5'b01101 || op == 5'b00101 || op == 5'b11011 || op == 5'b11001 || op == 5'b00000 || op == 5'b00100 || op == 5'b11100 || op == 5'b01100) ? inst_i[10:7] : 4'b0;
assign gpr_wen_o = (rd_o != 0);
assign funct3 = inst_i[14:12];
assign rs1 = (op == 5'b11001 || op == 5'b00000 || op == 5'b00100 || op == 5'b11100	//I
 || op == 5'b11000	//B
 || op == 5'b01000	//S
 || op == 5'b01100) ? //R
 inst_i[18:15] : 4'b0;
assign rs2 = (op == 5'b11000  //B
 || op == 5'b01000 //S
 || op == 5'b01100) ? inst_i[23:20] //R
 : (op == 5'b11100 && imm == 32'd0 && funct3 == 3'b000) ? 4'd15 //ecall
 : 4'b0;
assign immI = {{20{inst_i[31]}},inst_i[31:20]};	//SEXTIimmediate
assign immU = {inst_i[31:12],{12{1'b0}}};	//UEXTUimm
assign immS = {{20{inst_i[31]}}, inst_i[31:25], inst_i[11:7]};	//SEXTSimm
assign immB = {{19{inst_i[31]}}, inst_i[31], inst_i[7], inst_i[30:25], inst_i[11:8], 1'b0};	//SEXTBimm
assign immJ = {{11{inst_i[31]}}, inst_i[31], inst_i[19:12], inst_i[20], inst_i[30:21], 1'b0};	//SEXTJimm
assign funct7 = inst_i[31:25];

assign imm = (op == 5'b01101 || op == 5'b00101) ? immU
 : (op == 5'b11011) ? immJ
 : (op == 5'b11000) ? immB
 : (op == 5'b01000) ? immS
 : (op == 5'b11001 || op == 5'b00000 || op == 5'b00100 || op == 5'b11100) ? immI 
 : (op == 5'b01100) ? {20'b0,funct7,5'b0}
 : 32'b0;

assign fencei_o = (op == 5'b00011 && id_valid_o);

//静态分支预测
reg prevalid;
always @(posedge clk) begin
	if(if_valid_i && id_ready_o) prevalid <= 1'b1;
	else prevalid <= 1'b0;
end
wire [1:0] prepc_en = (op == 5'b11000 && inst_i[31]) ? 2'b01 : (op == 5'b11011) ? 2'b10 : 2'b00;
wire [31:0] prepc = pc_i + imm;
assign prepc_en_o = prevalid ? prepc_en : 2'b00;
assign prepc_o = ((op == 5'b11000 && inst_i[31]) || (op == 5'b11011)) ? prepc[20:0] : 21'b0;

endmodule


module ysyx_24110017_EXU(
	input  wire clk,
	input  wire rst,

	input  wire flush_i,

`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
`ifndef ysyx_24110017_SIMFAST
	input  wire [31:0] inst_i,//difftest
	output reg  [31:0] pc_o,
	output reg  [31:0] inst_o,
	output reg  [31:0] npc_o,
`endif
`endif
`endif

	input  wire  id_valid_i,
	output wire  ex_ready_o,
	output wire  ex_valid_o,
	
  input  wire [31:0] pc_i,
  input  wire [31:0] imm_i,
  input  wire [ 4:0] op_i,
  input  wire [ 2:0] funct3_i,
  input  wire [31:0] r1_i,
	input  wire [31:0] r2_i,
	input  wire [ 3:0] rd_i,
	input  wire				 gpr_wen_i,
	input  wire [31:0] mepc_i,mstatus_i,mcause_i,mtvec_i,

	output reg  [31:0] xrd_o,
	output reg  [ 3:0] rd_o,
	output reg				 gpr_wen_o,
  output reg  [ 3:0] csrs_wen_o,

	output wire [31:0] ls_addr_o,ls_wdata_o,
	input  wire [31:0] ls_rdata_i,
	input  wire ls_done_i,

	output reg  [31:0] dnpc_o
);

/***分布式控制***/
reg state;
assign ex_ready_o = !state;
parameter IDLE = 1'b0,WAIT = 1'b1;

wire ls_valid;
wire jalen,jalren,beqen,bneen,blten,bgeen,bltuen,bgeuen,ecall_en,mret_en;
wire [31:0] xrd;
wire [ 3:0] csrs_wen;
wire [31:0] alu_res;
wire [31:0] csr,mcause_w,csrs_w;
wire [31:0] dnpc;

wire [1:0]abnormal;
wire updata = (!ls_valid || ls_done_i) && (abnormal == 0);
assign ex_valid_o = updata && state;
always @(posedge clk) begin
  if(rst || flush_i)					  state <= IDLE;
  else if(id_valid_i && !state) state <= WAIT;
  else if(updata && state)			state <= IDLE;
end

wire [1:0]total = (ecall_en) ? 2'd2 : (|csrs_wen) ? 2'd1 : 2'd0;
reg [1:0]counter;
always @(posedge clk) begin
	if(id_valid_i && ex_ready_o) counter <= 2'd0;
	else if(counter != total) counter <= counter + 1;
end
assign abnormal = total - counter;

`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
`ifndef ysyx_24110017_SIMFAST
always@(posedge clk) begin
	casez({flush_i,state})
		2'b1? : begin
			pc_o   <= 32'h0;
			inst_o <= 32'h0;
			npc_o  <= 32'h0;
		end
		2'b01 : begin
			if(updata) begin
				pc_o	 <= pc_i;
				inst_o <= inst_i;
				npc_o  <= dnpc;
			end
		end
		default : begin
		end
	endcase
end
`endif
`endif
`endif

always@(posedge clk) begin
  casez({flush_i,state})
    2'b1? : begin
      xrd_o  <= 32'h0;
    end
    2'b01 : begin
			if(abnormal == 2'd2)
				xrd_o <= mcause_w;
			else if(abnormal == 2'd1)
				xrd_o <= csrs_w;
      else if(updata) begin
        xrd_o  <= xrd;
      end
    end
    default : begin
    end
  endcase
end

always@(posedge clk) begin
	case(state)
	  IDLE : rd_o <= 4'b0;
		WAIT : begin
			if(updata) rd_o <= rd_i;
		end
	endcase
end

always@(posedge clk) begin
  if(flush_i) gpr_wen_o	<= 1'b0;
  else begin
    case(state)
      IDLE : gpr_wen_o	<= 1'b0;
      WAIT : begin
        if(updata) gpr_wen_o <= gpr_wen_i;
      end
    endcase
  end
end

always@(posedge clk) begin
  casez({flush_i,state})
		2'b1? : csrs_wen_o <= 4'b0;
    2'b01 : begin
				if(abnormal == 2'd2)
					csrs_wen_o <= 4'b0100;
				else if(abnormal == 2'd1)
					csrs_wen_o <= csrs_wen; 
        else if(updata)
					csrs_wen_o <= 4'b0;
      end
		default : begin
		end
  endcase
end

always@(posedge clk) begin
	casez({rst || flush_i,state})
		2'b1? : dnpc_o <= 32'h0;
		2'b01 : begin
			if(updata) dnpc_o <= dnpc;
		end
		default : dnpc_o <= dnpc_o;
	endcase
end

wire [31:0]add_res = ((op_i == 5'b00000 || op_i == 5'b01000 || op_i == 5'b11001 || op_i == 5'b00100 || op_i == 5'b01100) ? r1_i : pc_i) + ((op_i == 5'b01100) ? r2_i : imm_i);
wire [31:0]add_pc_4 = pc_i + 4;
wire [31:0]sll_res = (op_i == 5'b00100 || op_i == 5'b01100) ? r1_i << ((op_i == 5'b00100) ? imm_i[4:0] : r2_i[4:0]) : 32'b0;
wire [31:0]srl_res = (op_i == 5'b00100 || op_i == 5'b01100) ? r1_i >> ((op_i == 5'b00100) ? imm_i[4:0] : r2_i[4:0]) : 32'b0;
wire slt_res = (op_i == 5'b00100 || op_i == 5'b01100 || op_i == 5'b11000) ? ((funct3_i == 3'b010 || funct3_i == 3'b100 || funct3_i == 3'b101) ? $signed(r1_i) < $signed((op_i == 5'b00100) ? imm_i : r2_i) : r1_i < ((op_i == 5'b00100) ? imm_i : r2_i)) : 1'b0;
wire [31:0]and_res = (op_i == 5'b00100 || op_i == 5'b01100) ? r1_i & ((op_i == 5'b00100) ? imm_i : r2_i) : 32'b0;
wire [31:0]or_res  = (op_i == 5'b00100 || op_i == 5'b01100) ? r1_i | ((op_i == 5'b00100) ? imm_i : r2_i) : 32'b0;
wire [31:0]xor_res = (op_i == 5'b00100 || op_i == 5'b01100) ? r1_i ^ ((op_i == 5'b00100) ? imm_i : r2_i) : 32'b0;

assign xrd = 
/***I*addi~srai***/
				(op_i == 5'b00100) ? alu_res :
/***R_add~R_remu***/
				(op_i == 5'b01100) ? alu_res :
/*********/
				(op_i == 5'b11011) ? add_pc_4 : //jal
				(op_i == 5'b11001) ? add_pc_4 : //jalr
				(op_i == 5'b01101) ? imm_i		: //U_lui
				(op_i == 5'b00101) ? alu_res  :	//U_auipc
/***LSU***/
				(op_i == 5'b00000) ? ls_rdata_i : //load
/***CSRU***/
				(op_i == 5'b11100) ? csr : //csrr
				32'h0;

wire ismepc    = {imm_i[11],imm_i[9],imm_i[6],imm_i[1],imm_i[0]} == 5'b01101; //1101000001
wire ismstatus = {imm_i[11],imm_i[9],imm_i[6],imm_i[1],imm_i[0]} == 5'b01000; //1100000000
wire ismcause  = {imm_i[11],imm_i[9],imm_i[6],imm_i[1],imm_i[0]} == 5'b01110; //1101000010
wire ismtvec   = {imm_i[11],imm_i[9],imm_i[6],imm_i[1],imm_i[0]} == 5'b01001; //1100000101
wire isecall   = {imm_i[11],imm_i[9],imm_i[6],imm_i[1],imm_i[0]} == 5'b00000;
wire ismret    = {imm_i[11],imm_i[9],imm_i[6],imm_i[1],imm_i[0]} == 5'b01010;
//wire isebreak= {imm_i[11],imm_i[9],imm_i[6],imm_i[1],imm_i[0]} == 5'b00001;
wire ismvendorid = {imm_i[11],imm_i[0]} == 2'b10; //0xFF0
wire ismarchid   = {imm_i[11],imm_i[0]} == 2'b11; //0xFF1
localparam MVENDORID = 32'h79737978;
localparam MARCHID   = 32'h016fe3c1;

assign csr = (ismepc) ? mepc_i : (ismstatus) ? mstatus_i : (ismcause) ? mcause_i : (ismtvec) ? mtvec_i : (ismvendorid) ? MVENDORID : (ismarchid) ? MARCHID : 32'b0;

assign mcause_w = (ecall_en) ? 32'hb : csrs_w; //ecall a5
assign csrs_w = 
			({32{funct3_i == 3'b001}} & (r1_i))        | //csrrw
			({32{funct3_i == 3'b010}} & (r1_i | csr))  | //csrrs
      ({32{funct3_i == 3'b011}} & (~r1_i & csr)) | //csrrc
			({32{ecall_en}} & pc_i); //ecall_mepc
assign csrs_wen = {
    (op_i == 5'b11100 && ismtvec),
    (op_i == 5'b11100 && ismcause),
    (op_i == 5'b11100 && ismstatus),
    (op_i == 5'b11100 && ismepc) || ecall_en
};

/***ALU***/
wire funct7_i = imm_i[10];
localparam [3:0] ADD = 4'd0,SUB = 4'd1,SLL = 4'd2,SRL = 4'd3,SRA = 4'd4,SLT = 4'd5,AND = 4'd6,OR = 4'd7,XOR = 4'd8;
wire [3:0]alu_sel =
    ((op_i == 5'b00100 && funct3_i == 3'b000) || (op_i == 5'b01100 && funct3_i == 3'b000 && funct7_i == 1'b0)) ? ADD
  :  (op_i == 5'b01100 && funct3_i == 3'b000 && funct7_i == 1'b1) ? SUB
	: ((op_i == 5'b00100 && funct3_i == 3'b001) || (op_i == 5'b01100 && (funct3_i == 3'b001 && funct7_i == 1'b0))) ? SLL
	: ((op_i == 5'b00100 &&(funct3_i == 3'b010 || funct3_i == 3'b011)) || (op_i == 5'b01100 && ((funct3_i == 3'b010 && funct7_i == 1'b0) || (funct3_i == 3'b011 && funct7_i == 1'b0)))) ? SLT
	: ((op_i == 5'b00100 && funct3_i == 3'b100) || (op_i == 5'b01100 && (funct3_i == 3'b100 && funct7_i == 1'b0))) ? XOR
	: ((op_i == 5'b00100 && funct3_i == 3'b101 && funct7_i == 1'b0) || (op_i == 5'b01100 && funct3_i == 3'b101 && funct7_i == 1'b0)) ? SRL
	: ((op_i == 5'b00100 && funct3_i == 3'b101 && funct7_i == 1'b1) || (op_i == 5'b01100 && funct3_i == 3'b101 && funct7_i == 1'b1)) ? SRA
	: ((op_i == 5'b00100 && funct3_i == 3'b110) || (op_i == 5'b01100 && funct3_i == 3'b110 && funct7_i == 1'b0)) ? OR
	: ((op_i == 5'b00100 && funct3_i == 3'b111) || (op_i == 5'b01100 && funct3_i == 3'b111 && funct7_i == 1'b0)) ? AND : ADD;
assign alu_res = (alu_sel == ADD) ? add_res
	: (alu_sel == SUB) ? r1_i - r2_i
	: (alu_sel == SLL) ? sll_res
	: (alu_sel == SRL) ? srl_res
	: (alu_sel == SRA) ? ((op_i == 5'b00100) ? ({32{r1_i[31]}} << (32 - imm_i[4:0])) | (r1_i >> imm_i[4:0]) : ({32{r1_i[31]}} << (32 - r2_i[4:0])) | (r1_i >> r2_i[4:0]))
	: (alu_sel == SLT) ? {31'b0, slt_res} 
	: (alu_sel == AND) ? and_res
	: (alu_sel == OR)  ? or_res 
	: (alu_sel == XOR) ? xor_res 
	: 32'b0;

/***LSU***/
assign ls_valid = (op_i == 5'b01000) || (op_i == 5'b00000);
assign ls_addr_o = (ls_valid) ? add_res : 32'h0;
assign ls_wdata_o = 
				(ls_addr_o[1:0] == 2'b00) ? r2_i
			: (ls_addr_o[1:0] == 2'b01) ? {r2_i[23:0],8'b0}
			: (ls_addr_o[1:0] == 2'b10) ? {r2_i[15:0],16'b0}
			: (ls_addr_o[1:0] == 2'b11) ? {r2_i[7:0],24'b0} : 32'h0;

/***BU***/
assign jalen		= (op_i == 5'b11011);
assign jalren		= (op_i == 5'b11001);
assign beqen		= (op_i == 5'b11000 && funct3_i == 3'b000 && (r1_i == r2_i));
assign bneen		= (op_i == 5'b11000 && funct3_i == 3'b001 && (r1_i != r2_i));
assign blten		= (op_i == 5'b11000 && funct3_i == 3'b100 &&  slt_res);
assign bgeen		= (op_i == 5'b11000 && funct3_i == 3'b101 && !slt_res);
assign bltuen		= (op_i == 5'b11000 && funct3_i == 3'b110 &&  slt_res);
assign bgeuen		= (op_i == 5'b11000 && funct3_i == 3'b111 && !slt_res);
assign ecall_en = (op_i == 5'b11100 && isecall);
assign mret_en  = (op_i == 5'b11100 && ismret);

assign dnpc =
    (jalen)  ? add_res	//jal
	: (jalren) ? (add_res & ~1) //jalr
	: (beqen)  ? add_res	//beq
	: (bneen)  ? add_res	//bne
	: (blten)  ? add_res	//blt
	: (bgeen)  ? add_res	//bge
	: (bltuen) ? add_res	//bltu
	:	(bgeuen) ? add_res	//bgeu
	: (ecall_en) ? mtvec_i //ecall
	: (mret_en)  ? mepc_i //mret
	: add_pc_4;

endmodule


module ysyx_24110017_LSU(
	input  wire clk,
	input  wire rst,
	input  wire [ 4:0] op_i,
	input  wire [ 2:0] funct3_i,
	input  wire        ls_valid_i,
	input  wire [31:0] ls_addr_i,ls_wdata_i,
	output reg  [31:0] ls_rdata_o,
	output wire        ls_done_o,
 
	input  wire				 ls_axi_awready,
	output reg				 ls_axi_awvalid,
	output wire [ 3:0] ls_axi_awid,
	output reg  [31:0] ls_axi_awaddr,
	output wire [ 7:0] ls_axi_awlen,
	output wire [ 2:0] ls_axi_awsize,
	output wire [ 1:0] ls_axi_awburst,
	input  wire				 ls_axi_wready,
	output reg				 ls_axi_wvalid,
	output reg  [31:0] ls_axi_wdata,
	output wire [ 3:0] ls_axi_wstrb,
	output reg         ls_axi_wlast,
	output reg				 ls_axi_bready,
	input  wire				 ls_axi_bvalid,
	input  wire [ 3:0] ls_axi_bid,
	input  wire [ 1:0] ls_axi_bresp,

	input  wire				 ls_axi_arready,
	output reg				 ls_axi_arvalid,
	output wire [ 3:0] ls_axi_arid,
	output reg  [31:0] ls_axi_araddr,
	output wire [ 7:0] ls_axi_arlen,
	output wire [ 2:0] ls_axi_arsize,
	output wire [ 1:0] ls_axi_arburst,
	output reg				 ls_axi_rready,
	input  wire				 ls_axi_rvalid,
	input  wire	[ 3:0] ls_axi_rid,
	input  wire [31:0] ls_axi_rdata,
	input  wire [ 1:0] ls_axi_rresp,
	input  wire				 ls_axi_rlast
);

assign ls_axi_awid    = 4'b0;
assign ls_axi_awlen   = 8'b0;
assign ls_axi_awburst = 2'b01;
assign ls_axi_arid    = 4'b0;
assign ls_axi_arlen   = 8'b0;
assign ls_axi_arburst = 2'b01;

reg ls_read_done;
assign ls_done_o = (ls_read_done) || (ls_axi_bvalid && ls_axi_bready); 
wire ls_wen_i = (op_i == 5'b01000) && ls_valid_i;
wire ls_ren_i = (op_i == 5'b00000) && ls_valid_i;

wire [ 3:0] ls_wmask_i = 
	 ((ls_addr_i[1:0] == 0) && op_i == 5'b01000 && funct3_i == 3'b000) ? 4'b0001
 : ((ls_addr_i[1:0] == 0) && op_i == 5'b01000 && funct3_i == 3'b001) ? 4'b0011
 : ((ls_addr_i[1:0] == 0) && op_i == 5'b01000 && funct3_i == 3'b010) ? 4'b1111
 : ((ls_addr_i[1:0] == 1) && op_i == 5'b01000 && funct3_i == 3'b000) ? 4'b0010
 : ((ls_addr_i[1:0] == 2) && op_i == 5'b01000 && funct3_i == 3'b000) ? 4'b0100 
 : ((ls_addr_i[1:0] == 2) && op_i == 5'b01000 && funct3_i == 3'b001) ? 4'b1100 
 : ((ls_addr_i[1:0] == 3) && op_i == 5'b01000 && funct3_i == 3'b000) ? 4'b1000 
 : 4'b0;
wire[31:0] ls_rdata = 
   ((ls_addr_i[1:0] == 0) && op_i == 5'b00000 && funct3_i == 3'b010) ? ls_axi_rdata
 : ((ls_addr_i[1:0] == 0) && op_i == 5'b00000 && funct3_i == 3'b000) ? {{24{ls_axi_rdata[7]}},ls_axi_rdata[7:0]}
 : ((ls_addr_i[1:0] == 1) && op_i == 5'b00000 && funct3_i == 3'b000) ? {{24{ls_axi_rdata[15]}},ls_axi_rdata[15:8]}
 : ((ls_addr_i[1:0] == 2) && op_i == 5'b00000 && funct3_i == 3'b000) ? {{24{ls_axi_rdata[23]}},ls_axi_rdata[23:16]}
 : ((ls_addr_i[1:0] == 3) && op_i == 5'b00000 && funct3_i == 3'b000) ? {{24{ls_axi_rdata[31]}},ls_axi_rdata[31:24]}
 : ((ls_addr_i[1:0] == 0) && op_i == 5'b00000 && funct3_i == 3'b001) ? {{16{ls_axi_rdata[15]}},ls_axi_rdata[15:0]}
 : ((ls_addr_i[1:0] == 2) && op_i == 5'b00000 && funct3_i == 3'b001) ? {{16{ls_axi_rdata[31]}},ls_axi_rdata[31:16]}
 : ((ls_addr_i[1:0] == 0) && op_i == 5'b00000 && funct3_i == 3'b100) ? {24'b0,ls_axi_rdata[7:0]}
 : ((ls_addr_i[1:0] == 1) && op_i == 5'b00000 && funct3_i == 3'b100) ? {24'b0,ls_axi_rdata[15:8]}
 : ((ls_addr_i[1:0] == 2) && op_i == 5'b00000 && funct3_i == 3'b100) ? {24'b0,ls_axi_rdata[23:16]}
 : ((ls_addr_i[1:0] == 3) && op_i == 5'b00000 && funct3_i == 3'b100) ? {24'b0,ls_axi_rdata[31:24]}
 : ((ls_addr_i[1:0] == 0) && op_i == 5'b00000 && funct3_i == 3'b101) ? {16'b0,ls_axi_rdata[15:0]}
 : ((ls_addr_i[1:0] == 2) && op_i == 5'b00000 && funct3_i == 3'b101) ? {16'b0,ls_axi_rdata[31:16]}
 : 32'b0;
wire [ 2:0]ls_awsize_i = (op_i == 5'b01000 && funct3_i == 3'b000) ? 3'b000 : (op_i ==  5'b01000 && funct3_i == 3'b001) ? 3'b1 : (op_i == 5'b01000 && funct3_i == 3'b010) ? 3'b10 : 3'b10;
wire [ 2:0]ls_arsize_i = (op_i == 5'b00000 && (funct3_i == 3'b000 || funct3_i == 3'b100)) ? 3'b0 : (op_i == 5'b00000 && (funct3_i == 3'b001 || funct3_i == 3'b101)) ? 3'b1 : (op_i == 5'b00000 && funct3_i == 3'b010) ? 3'b10 : 3'b10;

/***时序最差路径***/
always @(posedge clk) begin
	if(ls_axi_rvalid && ls_axi_rready) begin
		ls_read_done <= 1'b1;
		ls_rdata_o <= ls_rdata;
	end
	else ls_read_done <= 1'b0;
end

`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
`ifndef ysyx_24110017_SIMFAST
import "DPI-C" function void diff_skip_ref();
`endif
`endif
`endif

parameter AXI_IDLE=2'b00,AXI_READ=2'b01,AXI_WRITE=2'b10;
reg [1:0]axi_state;

assign ls_axi_awsize = (ls_axi_awvalid) ? ls_awsize_i : 3'b0;
assign ls_axi_wstrb  = (ls_axi_wvalid)  ? ls_wmask_i  : 4'b0;
assign ls_axi_arsize = (ls_axi_arvalid) ? ls_arsize_i : 3'b0;

always @(posedge clk) begin
	if(rst) begin
		axi_state			 <= AXI_IDLE;
		ls_axi_arvalid <= 1'b0;
		ls_axi_awvalid <= 1'b0;
  end 
	else begin
		case (axi_state)
			AXI_IDLE: begin
				if(ls_ren_i) begin
					axi_state		   <= AXI_READ;
					ls_axi_arvalid <= 1'b1;
					ls_axi_araddr  <= ls_addr_i;
				end
				if(ls_wen_i) begin
					axi_state      <= AXI_WRITE;
					ls_axi_awvalid <= 1'b1;
					ls_axi_wvalid  <= 1'b1;
					ls_axi_awaddr  <= ls_addr_i;
					ls_axi_wdata   <= ls_wdata_i;
					ls_axi_wlast   <= 1'b1;
				end
			end
			AXI_READ: begin
        if(ls_axi_arvalid && ls_axi_arready) begin
					ls_axi_arvalid <= 1'b0;
					ls_axi_rready  <= 1'b1;
					end
	        if(ls_axi_rvalid && ls_axi_rready) begin
						ls_axi_araddr  <= 32'h0;
						ls_axi_rready  <= 1'b0;
            axi_state			 <= AXI_IDLE;
`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
`ifndef ysyx_24110017_SIMFAST
					if((ls_axi_araddr - 32'h10000000 < 32'h1000) || (ls_axi_araddr == 32'h02000000) || (ls_axi_araddr == 32'h02000004)) begin //DEVICE DIFFTEST
						diff_skip_ref();
					end
`endif
`endif
`endif
        end
      end
			AXI_WRITE: begin
				if(ls_axi_awvalid && ls_axi_awready) begin
					ls_axi_awvalid <= 1'b0;
				end
				if(ls_axi_wvalid && ls_axi_wready && ls_axi_awvalid && ls_axi_awready) begin
					ls_axi_wvalid  <= 1'b0;
					ls_axi_wdata   <= 32'h0;
					ls_axi_bready  <= 1'b1;
				end
				if(ls_axi_bvalid && ls_axi_bready) begin
					ls_axi_bready <= 1'b0;
					ls_axi_awaddr <= 32'h0;
					ls_axi_wlast  <= 1'b0;
					axi_state     <= AXI_IDLE;
				end
			end
			default : begin
			end
		endcase
	end
end

endmodule


module ysyx_24110017_Xbar(
	input wire clk,
	input wire rst,
/***AXI_IFU***/
	output wire				IFU_AXI_ARREADY,
	input  wire				IFU_AXI_ARVALID,
	input  wire [ 3:0]IFU_AXI_ARID,
	input  wire [31:0]IFU_AXI_ARADDR,
	input  wire [ 7:0]IFU_AXI_ARLEN,
	input  wire [ 2:0]IFU_AXI_ARSIZE,
	input  wire [ 1:0]IFU_AXI_ARBURST,
	input  wire				IFU_AXI_RREADY,
	output wire				IFU_AXI_RVALID,
	output wire [ 3:0]IFU_AXI_RID,
	output wire [31:0]IFU_AXI_RDATA,
	output wire [ 1:0]IFU_AXI_RRESP,
	output wire				IFU_AXI_RLAST,
/***AXI_LSU***/
	output wire				LSU_AXI_AWREADY,
	input  wire				LSU_AXI_AWVALID,
	input  wire [ 3:0]LSU_AXI_AWID,
	input  wire [31:0]LSU_AXI_AWADDR,
	input  wire [ 7:0]LSU_AXI_AWLEN,
	input  wire [ 2:0]LSU_AXI_AWSIZE,
	input  wire [ 1:0]LSU_AXI_AWBURST, 
	output wire				LSU_AXI_WREADY,
	input  wire				LSU_AXI_WVALID,
	input  wire [31:0]LSU_AXI_WDATA,
	input  wire [ 3:0]LSU_AXI_WSTRB,
	input  wire				LSU_AXI_WLAST,
	input  wire				LSU_AXI_BREADY,
	output wire				LSU_AXI_BVALID,
	output wire [ 3:0]LSU_AXI_BID,
	output wire [ 1:0]LSU_AXI_BRESP,
	output wire				LSU_AXI_ARREADY,
	input  wire				LSU_AXI_ARVALID,
	input  wire [ 3:0]LSU_AXI_ARID,
	input  wire [31:0]LSU_AXI_ARADDR,
	input  wire [ 7:0]LSU_AXI_ARLEN,
	input  wire [ 2:0]LSU_AXI_ARSIZE,
	input  wire [ 1:0]LSU_AXI_ARBURST,
	input  wire				LSU_AXI_RREADY,
	output wire				LSU_AXI_RVALID,
	output wire	[ 3:0]LSU_AXI_RID,
	output wire [31:0]LSU_AXI_RDATA,
	output wire [ 1:0]LSU_AXI_RRESP,
	output wire				LSU_AXI_RLAST,

	input  wire				io_master_awready,
	output wire				io_master_awvalid,
  output wire [ 3:0]io_master_awid,
  output wire [31:0]io_master_awaddr,
  output wire [ 7:0]io_master_awlen,
  output wire [ 2:0]io_master_awsize,
  output wire [ 1:0]io_master_awburst,
  input  wire				io_master_wready,
  output wire				io_master_wvalid,
  output wire [31:0]io_master_wdata,
  output wire [ 3:0]io_master_wstrb,
  output wire				io_master_wlast,
  output wire				io_master_bready,
  input  wire				io_master_bvalid,
  input  wire [ 3:0]io_master_bid,
  input  wire [ 1:0]io_master_bresp,
  input  wire				io_master_arready,
  output wire				io_master_arvalid,
  output wire [ 3:0]io_master_arid,
  output wire [31:0]io_master_araddr,
  output wire [ 7:0]io_master_arlen,
  output wire [ 2:0]io_master_arsize,
  output wire [ 1:0]io_master_arburst,
  output wire				io_master_rready,
  input  wire				io_master_rvalid,
  input  wire [ 3:0]io_master_rid,
  input  wire [31:0]io_master_rdata,
  input  wire [ 1:0]io_master_rresp,
  input  wire				io_master_rlast,
/***MY_CLINT***/
	input  wire				C_AXI_ARREADY,
	output wire				C_AXI_ARVALID,
	output wire [ 3:0]C_AXI_ARID,
	output wire [31:0]C_AXI_ARADDR,
	output wire [ 7:0]C_AXI_ARLEN,
	output wire [ 2:0]C_AXI_ARSIZE,
	output wire [ 1:0]C_AXI_ARBURST,
	output wire				C_AXI_RREADY,
	input  wire				C_AXI_RVALID,
	input  wire [ 3:0]C_AXI_RID,
	input  wire [31:0]C_AXI_RDATA,
	input  wire [ 1:0]C_AXI_RRESP,
	input  wire				C_AXI_RLAST
);

wire [31:0]X_AXI_AWADDR,X_AXI_WDATA,X_AXI_ARADDR,X_AXI_RDATA;
wire [ 3:0]X_AXI_WSTRB;
wire [ 7:0]X_AXI_AWLEN,X_AXI_ARLEN;
wire [ 3:0]X_AXI_AWID,X_AXI_BID,X_AXI_ARID,X_AXI_RID;
wire [ 2:0]X_AXI_AWSIZE,X_AXI_ARSIZE;
wire [ 1:0]X_AXI_AWBURST,X_AXI_ARBURST;
wire [ 1:0]X_AXI_BRESP,X_AXI_RRESP;
wire			 X_AXI_AWVALID,X_AXI_AWREADY,X_AXI_WVALID,X_AXI_WREADY,X_AXI_BVALID,X_AXI_BREADY,X_AXI_WLAST;
wire			 X_AXI_ARVALID,X_AXI_ARREADY,X_AXI_RVALID,X_AXI_RREADY,X_AXI_RLAST;
wire [31:0]I_AXI_RDATA;
wire       I_AXI_ARREADY,I_AXI_RVALID;

parameter SEL_IFU = 1'b0,SEL_LSU = 1'b1;
parameter IDLE = 2'b00,GRANT_LSU = 2'b01,GRANT_IFU = 2'b10;
reg [1:0] state;
always @(posedge clk) begin
	if(rst) state <= IDLE;
	else begin
		case (state)
			IDLE :			state <= (LSU_AXI_ARVALID || LSU_AXI_AWVALID) ? GRANT_LSU : (IFU_AXI_ARVALID) ? GRANT_IFU : state;
			GRANT_LSU : state <= (C_AXI_RVALID || io_master_rvalid || io_master_bvalid) ? IDLE : state;
			GRANT_IFU : state <= (((IFU_AXI_ARADDR >= 32'ha0000000) && (IFU_AXI_ARADDR < 32'hc0000000)) ? (io_master_rlast) : (io_master_rvalid && io_master_rready)) ? IDLE : state;
			default :   state <= state;
		endcase
	end
end

wire sel_m = ((state != GRANT_IFU) && (LSU_AXI_ARVALID || LSU_AXI_AWVALID || state == GRANT_LSU)) ? SEL_LSU : SEL_IFU;

assign X_AXI_AWID      = (sel_m == SEL_LSU) ? LSU_AXI_AWID    : 4'b0;
assign X_AXI_AWLEN     = (sel_m == SEL_LSU) ? LSU_AXI_AWLEN   : 8'b0;
assign X_AXI_AWSIZE    = (sel_m == SEL_LSU) ? LSU_AXI_AWSIZE  : 3'b0;
assign X_AXI_AWBURST   = (sel_m == SEL_LSU) ? LSU_AXI_AWBURST : 2'b0;
assign X_AXI_WLAST     = (sel_m == SEL_LSU) ? LSU_AXI_WLAST   : 1'b0;
assign LSU_AXI_BID     = (sel_m == SEL_LSU) ? X_AXI_BID       : 4'b0;
assign X_AXI_AWADDR    = (sel_m == SEL_LSU) ? LSU_AXI_AWADDR  : 32'h0;
assign X_AXI_AWVALID   = (sel_m == SEL_LSU) ? LSU_AXI_AWVALID : 1'b0;
assign LSU_AXI_AWREADY = (sel_m == SEL_LSU) ? X_AXI_AWREADY   : 1'b0;
assign X_AXI_WDATA     = (sel_m == SEL_LSU) ? LSU_AXI_WDATA   : 32'h0;
assign X_AXI_WSTRB     = (sel_m == SEL_LSU) ? LSU_AXI_WSTRB   : 4'b0;
assign X_AXI_WVALID    = (sel_m == SEL_LSU) ? LSU_AXI_WVALID  : 1'b0;
assign LSU_AXI_WREADY  = (sel_m == SEL_LSU) ? X_AXI_WREADY    : 1'b0;
assign LSU_AXI_BRESP   = (sel_m == SEL_LSU) ? X_AXI_BRESP     : 2'b0;
assign LSU_AXI_BVALID  = (sel_m == SEL_LSU) ? X_AXI_BVALID    : 1'b0;
assign X_AXI_BREADY    = (sel_m == SEL_LSU) ? LSU_AXI_BREADY  : 1'b0;
 
assign X_AXI_ARID			 = (sel_m == SEL_LSU) ? LSU_AXI_ARID		: IFU_AXI_ARID;
assign X_AXI_ARLEN     = (sel_m == SEL_LSU) ? LSU_AXI_ARLEN		: IFU_AXI_ARLEN;
assign X_AXI_ARSIZE		 = (sel_m == SEL_LSU) ? LSU_AXI_ARSIZE  : IFU_AXI_ARSIZE;
assign X_AXI_ARBURST   = (sel_m == SEL_LSU) ? LSU_AXI_ARBURST : IFU_AXI_ARBURST;
assign X_AXI_ARADDR    = (sel_m == SEL_LSU) ? LSU_AXI_ARADDR  : IFU_AXI_ARADDR;
assign X_AXI_ARVALID   = (sel_m == SEL_LSU) ? LSU_AXI_ARVALID : IFU_AXI_ARVALID;
assign LSU_AXI_ARREADY = (sel_m == SEL_LSU) ? X_AXI_ARREADY   : 1'b0;
assign LSU_AXI_RDATA   = (sel_m == SEL_LSU) ? X_AXI_RDATA     : 32'h0;
assign LSU_AXI_RRESP   = (sel_m == SEL_LSU) ? X_AXI_RRESP     : 2'b0;
assign LSU_AXI_RVALID  = (sel_m == SEL_LSU) ? X_AXI_RVALID    : 1'b0;
assign X_AXI_RREADY    = (sel_m == SEL_LSU) ? LSU_AXI_RREADY  : IFU_AXI_RREADY;
assign LSU_AXI_RID     = (sel_m == SEL_LSU) ? X_AXI_RID       : 4'b0;
assign LSU_AXI_RLAST   = (sel_m == SEL_LSU) ? X_AXI_RLAST     : 1'b0;

assign IFU_AXI_ARREADY = (sel_m == SEL_IFU) ? X_AXI_ARREADY   : 1'b0;
assign IFU_AXI_RDATA   = (sel_m == SEL_IFU) ? X_AXI_RDATA     : 32'h0;
assign IFU_AXI_RRESP   = (sel_m == SEL_IFU) ? X_AXI_RRESP     : 2'b0;
assign IFU_AXI_RVALID  = (sel_m == SEL_IFU) ? X_AXI_RVALID    : 1'b0;
assign IFU_AXI_RID     = (sel_m == SEL_IFU) ? X_AXI_RID       : 4'b0;
assign IFU_AXI_RLAST   = (sel_m == SEL_IFU) ? X_AXI_RLAST     : 1'b0;

/***SoC***/
localparam DEVICE_CLINT_LOW_ADDR  = 32'h02000048;//32'ha0000048;
localparam DEVICE_CLINT_HIGH_ADDR = 32'h0200004c;//32'ha000004c;
wire sel_clint = (X_AXI_ARADDR == DEVICE_CLINT_LOW_ADDR) || (X_AXI_ARADDR == DEVICE_CLINT_HIGH_ADDR);

assign X_AXI_AWREADY = io_master_awready;
assign io_master_awvalid = X_AXI_AWVALID;
assign io_master_awid = X_AXI_AWID;
assign io_master_awaddr = X_AXI_AWADDR;
assign io_master_awlen = X_AXI_AWLEN;
assign io_master_awsize = X_AXI_AWSIZE;
assign io_master_awburst = X_AXI_AWBURST;
assign X_AXI_WREADY = io_master_wready;
assign io_master_wvalid = X_AXI_WVALID;
assign io_master_wdata = X_AXI_WDATA;
assign io_master_wstrb = X_AXI_WSTRB;
assign io_master_wlast = X_AXI_WLAST;
assign io_master_bready = X_AXI_BREADY;
assign X_AXI_BVALID = io_master_bvalid;
assign X_AXI_BID = io_master_bid;
assign X_AXI_BRESP = io_master_bresp;

assign X_AXI_ARREADY = (sel_clint) ? C_AXI_ARREADY : io_master_arready;
assign {C_AXI_ARVALID,io_master_arvalid} = (sel_clint) ? {X_AXI_ARVALID,1'b0} : {1'b0,X_AXI_ARVALID};
assign {C_AXI_ARID,io_master_arid} = (sel_clint) ? {X_AXI_ARID,4'b0} : {4'b0,X_AXI_ARID};
assign {C_AXI_ARADDR,io_master_araddr} = (sel_clint) ? {X_AXI_ARADDR,32'b0} : {32'b0,X_AXI_ARADDR};
assign {C_AXI_ARLEN,io_master_arlen} = (sel_clint) ? {X_AXI_ARLEN,8'b0} : {8'b0,X_AXI_ARLEN};
assign {C_AXI_ARSIZE,io_master_arsize} = (sel_clint) ? {X_AXI_ARSIZE,3'b0} : {3'b0,X_AXI_ARSIZE};
assign {C_AXI_ARBURST,io_master_arburst} = (sel_clint) ? {X_AXI_ARBURST,2'b0} : {2'b0,X_AXI_ARBURST};
assign {C_AXI_RREADY,io_master_rready} = (sel_clint) ? {X_AXI_RREADY,1'b0} : {1'b0,X_AXI_RREADY};
assign X_AXI_RVALID = (sel_clint) ? C_AXI_RVALID : io_master_rvalid;
assign X_AXI_RID = (sel_clint) ? C_AXI_RID : io_master_rid;
assign X_AXI_RDATA = (sel_clint) ? C_AXI_RDATA : io_master_rdata;
assign X_AXI_RRESP = (sel_clint) ? C_AXI_RRESP : io_master_rresp;
assign X_AXI_RLAST = (sel_clint) ? C_AXI_RLAST : io_master_rlast;

endmodule


module ysyx_24110017_CLINT(
  input  wire clk,
  input  wire rst,

  output reg	      c_axi_arready,
  input  wire       c_axi_arvalid,
  input  wire [ 3:0]c_axi_arid,
  input  wire [31:0]c_axi_araddr,
  input  wire [ 7:0]c_axi_arlen,
  input  wire [ 2:0]c_axi_arsize,
  input  wire [ 1:0]c_axi_arburst,
  input  wire       c_axi_rready,
  output reg        c_axi_rvalid,
  output wire [ 3:0]c_axi_rid,
  output reg  [31:0]c_axi_rdata,
  output wire [ 1:0]c_axi_rresp,
  output wire       c_axi_rlast
);

assign c_axi_rid      = 4'b0;
assign c_axi_rresp    = 2'b0;
assign c_axi_rlast    = 1'b0;

localparam DEVICE_CLINT_LOW_ADDR = 32'h02000048;
localparam DEVICE_CLINT_HIGH_ADDR = 32'h0200004c;

reg [63:0] mtime;
wire[31:0] c_rdata = {32{(c_axi_araddr == DEVICE_CLINT_LOW_ADDR)}} & mtime[31:0] | {32{(c_axi_araddr == DEVICE_CLINT_HIGH_ADDR)}} & mtime[63:32];

always @(posedge clk) begin
  if(rst) begin
    c_axi_arready <= 1'b0;
    c_axi_rvalid  <= 1'b0;
	end
	else begin
		c_axi_arready <= 1'b1;
		if(c_axi_arvalid && c_axi_arready) begin
			c_axi_rvalid <= 1'b1;
			c_axi_rdata  <= c_rdata;
		end
		if(c_axi_rvalid && c_axi_rready) begin
			c_axi_rvalid <= 1'b0;
		end
	end
end

always @(posedge clk) begin
	if(rst) begin
		mtime <= 64'b0;
	end
	else begin
		mtime <= mtime + 1;
	end
end

endmodule


module ysyx_24110017_RegisterFile #(ADDR_WIDTH = 4, DATA_WIDTH = 32) (
	input clk,
	input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
	input [ADDR_WIDTH-1:0]raddr1,
	output [DATA_WIDTH-1:0]r1,
	input [ADDR_WIDTH-1:0]raddr2,
	output [DATA_WIDTH-1:0]r2
`ifdef __ICARUS__
	,output wire [31:0]a0
`endif
);

reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];

always @(posedge clk) begin
  if (wen && (waddr != 0)) rf[waddr] <= wdata;
end

wire [31:0] rdata1_low = {
		({32{raddr1[3:0] == 'd1}} & rf[1]) |
		({32{raddr1[3:0] == 'd2}} & rf[2]) |
		({32{raddr1[3:0] == 'd3}} & rf[3]) |
		({32{raddr1[3:0] == 'd4}} & rf[4]) |
		({32{raddr1[3:0] == 'd5}} & rf[5]) |
		({32{raddr1[3:0] == 'd6}} & rf[6]) |
		({32{raddr1[3:0] == 'd7}} & rf[7]) 
};
wire [31:0] rdata1_high = {
		({32{raddr1[3:0] == 'd8 }} & rf[ 8]) |
		({32{raddr1[3:0] == 'd9 }} & rf[ 9]) |
		({32{raddr1[3:0] == 'd10}} & rf[10]) |
		({32{raddr1[3:0] == 'd11}} & rf[11]) |
		({32{raddr1[3:0] == 'd12}} & rf[12]) |
		({32{raddr1[3:0] == 'd13}} & rf[13]) |
		({32{raddr1[3:0] == 'd14}} & rf[14]) |
		({32{raddr1[3:0] == 'd15}} & rf[15])
};

wire [31:0] rdata2_low = {
	({32{raddr2[3:0] == 'd1}} & rf[1]) |
	({32{raddr2[3:0] == 'd2}} & rf[2]) |
	({32{raddr2[3:0] == 'd3}} & rf[3]) |
	({32{raddr2[3:0] == 'd4}} & rf[4]) |
	({32{raddr2[3:0] == 'd5}} & rf[5]) |
	({32{raddr2[3:0] == 'd6}} & rf[6]) |
	({32{raddr2[3:0] == 'd7}} & rf[7])
};
wire [31:0] rdata2_high = {
	({32{raddr2[3:0] == 'd8 }} & rf[ 8]) |
	({32{raddr2[3:0] == 'd9 }} & rf[ 9]) |
	({32{raddr2[3:0] == 'd10}} & rf[10]) |
	({32{raddr2[3:0] == 'd11}} & rf[11]) |
	({32{raddr2[3:0] == 'd12}} & rf[12]) |
	({32{raddr2[3:0] == 'd13}} & rf[13]) |
	({32{raddr2[3:0] == 'd14}} & rf[14]) |
	({32{raddr2[3:0] == 'd15}} & rf[15])
};
 assign r1 = raddr1[3] ? rdata1_high : rdata1_low;
 assign r2 = raddr2[3] ? rdata2_high : rdata2_low;

	wire[31:0]rf0 = rf[0];
	wire[31:0]rf1 = rf[1];
	wire[31:0]rf2 = rf[2];
  wire[31:0]rf3 = rf[3];
	wire[31:0]rf4 = rf[4];
  wire[31:0]rf5 = rf[5];
  wire[31:0]rf6 = rf[6];
  wire[31:0]rf7 = rf[7];
	wire[31:0]rf8 = rf[8];
  wire[31:0]rf9 = rf[9];
  wire[31:0]rf10 = rf[10];
  wire[31:0]rf11 = rf[11];
  wire[31:0]rf12 = rf[12];
  wire[31:0]rf13 = rf[13];
  wire[31:0]rf14 = rf[14];
  wire[31:0]rf15 = rf[15];

`ifdef __ICARUS__
	assign a0 = rf[10];
`endif
/***DPI-C***/
`ifndef ysyx_24110017_YOSYS_STA
`ifndef __ICARUS__
export "DPI-C" function gpr_reg_grab;
function int gpr_reg_grab(int addr);
	begin
		assign gpr_reg_grab = (addr < 2 ** ADDR_WIDTH) ? rf[addr] : 32'h0;
	end
endfunction
`endif
`endif
/***E*N*D***/
endmodule

module ysyx_24110017_Reg #(WIDTH = 1, RESET_VAL = 0) (
  input clk,
  input rst,
  input [WIDTH-1:0] din,
  output reg [WIDTH-1:0] dout,
  input wen
);
  always @(posedge clk) begin
    if (rst) dout <= RESET_VAL;
    else if (wen) dout <= din;
  end
endmodule
