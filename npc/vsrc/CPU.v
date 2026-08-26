  

// ████████╗  ██████╗  ██████╗
// ╚══██╔══╝ ██╔═══██╗ ██╔══██╗
//    ██║    ██║   ██║ ██████╔╝
//    ██║    ██║   ██║ ██╔═══╝
//    ██║    ╚██████╔╝ ██║
//    ╚═╝     ╚═════╝  ╚═╝
`ifdef USE_VERILATOR
import "DPI-C" function int pmem_read(input int raddr);
import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
`endif
`include "csr_defines.v"

module ysyx_26010011(
	input clock,
	input reset/*verilator public*/,

	input			io_master_awready,
	output			io_master_awvalid,
	output	[31:0]	io_master_awaddr,
	output	[3:0]	io_master_awid,
	output	[7:0]	io_master_awlen,
	output	[2:0]	io_master_awsize,
	output	[1:0]	io_master_awburst,
	input			io_master_wready,
	output			io_master_wvalid,
	output	[31:0]	io_master_wdata,
	output	[3:0]	io_master_wstrb,
	output			io_master_wlast,
	output			io_master_bready,
	input			io_master_bvalid,
	input	[1:0]	io_master_bresp,
	input	[3:0]	io_master_bid,
	input			io_master_arready,
	output			io_master_arvalid,
	output	[31:0]	io_master_araddr,
	output	[3:0]	io_master_arid,
	output	[7:0]	io_master_arlen,
	output	[2:0]	io_master_arsize,
	output	[1:0]	io_master_arburst,
	output			io_master_rready,
	input			io_master_rvalid,
	input	[1:0]	io_master_rresp,
	input	[31:0]	io_master_rdata,
	input			io_master_rlast,
	input	[3:0]	io_master_rid,
/* verilator lint_off UNUSEDSIGNAL */
	output			io_slave_awready,
	input			io_slave_awvalid,
	input	[31:0]	io_slave_awaddr,
	input	[3:0]	io_slave_awid,
	input	[7:0]	io_slave_awlen,
	input	[2:0]	io_slave_awsize,
	input	[1:0]	io_slave_awburst,
	output			io_slave_wready,
	input			io_slave_wvalid,
	input	[31:0]	io_slave_wdata,
	input	[3:0]	io_slave_wstrb,
	input			io_slave_wlast,
	input			io_slave_bready,
	output			io_slave_bvalid,
	output	[1:0]	io_slave_bresp,
	output	[3:0]	io_slave_bid,
	output			io_slave_arready,
	input			io_slave_arvalid,
	input	[31:0]	io_slave_araddr,
	input	[3:0]	io_slave_arid,
	input	[7:0]	io_slave_arlen,
	input	[2:0]	io_slave_arsize,
	input	[1:0]	io_slave_arburst,
	input			io_slave_rready,
	output			io_slave_rvalid,
	output	[1:0]	io_slave_rresp,
	output	[31:0]	io_slave_rdata,
	output			io_slave_rlast,
	output	[3:0]	io_slave_rid,
	input 			io_interrupt
/* verilator lint_on UNUSEDSIGNAL */
);

	assign io_slave_awready = 0;
	assign io_slave_wready=0;
	assign io_slave_bvalid=0;
	assign io_slave_bresp=0;
	assign io_slave_bid=0;
	assign io_slave_arready=0;
	assign io_slave_rvalid=0;
	assign io_slave_rresp=0;
	assign io_slave_rdata=0;
	assign io_slave_rlast=0;
	assign io_slave_rid=0;

	wire idu_out_valid,idu_out_ready;
	wire [11:0]idu_out_bus_csrrd;
	wire [31:0]idu_out_bus_imm,idu_out_bus_rs1_val,idu_out_bus_rs2_val;   //idu_out_bus_imm 可作CSR地址
	wire idu_out_bus_isLOAD,idu_out_bus_isSTORE,idu_out_bus_isWGPR,idu_out_bus_isJUMP,idu_out_bus_isWCOMP,idu_out_bus_isBRANCH,idu_out_bus_isUnSigned,idu_out_bus_isUsePC,idu_out_bus_alu_isUseImm,idu_out_bus_comp_isUseImm;
	wire [ 3:0]idu_out_bus_alu_op;
	wire [ 1:0]idu_out_bus_comp_op,idu_out_bus_perip_mask;
	wire [ 2:0]idu_out_bus_opCSR;
	wire [ 4:0]idu_out_bus_exception;
	wire [ 3:0]idu_out_bus_rd;

	wire exu_in_valid,exu_in_ready,exu_in_bus_isLOAD,exu_in_bus_isSTORE,exu_in_bus_isWGPR,exu_in_bus_isJUMP,exu_in_bus_isWCOMP,exu_in_bus_isBRANCH,exu_in_bus_isUnSigned,exu_in_bus_isUsePC,exu_in_bus_alu_isUseImm,exu_in_bus_comp_isUseImm;
	wire [3:0]exu_in_bus_rd,exu_out_bus_rd;
	wire [4:0]exu_in_bus_exception;
	wire [31:0]exu_in_bus_rs1_val,exu_in_bus_rs2_val,exu_in_bus_imm,exu_in_bus_pc;
	wire [3:0]exu_in_bus_alu_op;
	wire [1:0]exu_in_bus_comp_op,exu_in_bus_perip_mask;
	wire [2:0]exu_in_bus_opCSR;
	wire [11:0]exu_in_bus_csrrd,exu_out_bus_csrrd;

	wire exu_out_valid,exu_out_ready,exu_out_bus_dnpc_valid;
	wire [4:0]exu_out_bus_exception;
	wire [31:0]exu_out_bus_alu_result;
	wire exu_out_bus_opCSR;
// `ifdef USE_VERILATOR
	
// `endif
	wire [31:0]exu_out_bus_csr_result;
	

	wire wbu_in_valid,wbu_in_ready,wbu_in_bus_isWGPR;
	wire [31:0]wbu_in_bus_csr_result,wbu_in_bus_pc;
	wire [11:0]wbu_in_bus_csrrd,wbu_out_bus_csrrd;
	wire       wbu_in_bus_opCSR;
	wire [3:0]wbu_in_bus_rd,wbu_out_bus_rd;
	wire [4:0]wbu_in_bus_exception;
	wire [31:0]wbu_out_bus_gpr_wdata;
`ifdef USE_VERILATOR
	wire [31:0]dbg_wbu_in_bus_instruction,dbg_exu_in_bus_instruction;
	wire [31:0]dbg_wbu_in_bus_lsu_result,dbg_wbu_in_bus_alu_result;
	wire dbg_wbu_in_bus_comp_result,dbg_wbu_in_bus_isLOAD,dbg_wbu_in_bus_isSTORE,dbg_wbu_in_bus_isJUMP,dbg_wbu_in_bus_isWCOMP,dbg_wbu_in_bus_isBRANCH;
`endif
	
	wire lsu_in_valid,lsu_in_ready,lsu_in_bus_isWGPR,lsu_in_bus_isUnSigned;
	wire [31:0]lsu_in_bus_wdata,lsu_in_bus_pc,/*lsu_in_bus_snpc,*/lsu_in_bus_csr_result;
	wire [1:0]lsu_in_bus_perip_mask;
	wire [3:0]lsu_in_bus_rd,lsu_out_bus_rd;
	wire [4:0]lsu_in_bus_exception;
	wire [11:0]lsu_in_bus_csrrd,lsu_out_bus_csrrd;
	wire lsu_in_bus_opCSR;
	wire lsu_in_bus_isLOAD,lsu_in_bus_isSTORE;
	wire lsu_out_valid,lsu_out_ready;
	wire [4:0]lsu_out_bus_exception;
	wire [31:0]lsu_out_bus_csr_result;

`ifdef USE_VERILATOR
	wire [31:0] dbg_lsu_in_bus_alu_result,dbg_lsu_in_bus_instruction;
	wire dbg_lsu_in_bus_comp_result,dbg_lsu_in_bus_isJUMP;
	wire dbg_lsu_in_bus_isWCOMP,dbg_lsu_in_bus_isBRANCH,dbg_lsu_out_bus_comp_result;
	wire [31:0] dbg_lsu_out_bus_alu_result;
	wire dbg_exu_out_bus_comp_result;
`endif

	//dnpc
	wire [31:0]dnpc;
	wire dnpc_valid;

	wire [3:0] gpr_raddra,gpr_raddrb,gpr_waddr;
	wire [31:0]gpr_rdataa,gpr_rdatab,gpr_wdata,csr_mtvec,csr_mepc,csr_pc;
	wire gpr_we;
	wire [11:0]csr_waddr;
	wire [31:0]csr_wdata,csr_rdata;
	wire csr_we;
	
	wire fencei_pass;
	wire [4:0]wbu_out_bus_exception;

	wire flush_valid/*verilator public*/;
	wire flush_exception_valid/*verilator public*/;

	reg [31:0] exu_out_bus_gpr_wdata;
	wire [31:0] lsu_in_bus_gpr_wdata;
	reg [31:0] lsu_out_bus_gpr_wdata;
	wire [31:0] wbu_in_bus_gpr_wdata;

	wire ifu_out_valid,ifu_out_ready;
	wire [31:0]ifu_out_bus_pc;
	wire [4:0]ifu_out_bus_exception;
	wire [31:0]ifu_out_bus_instruction,idu_in_bus_instruction;

	wire idu_in_valid,idu_in_ready;
	wire [31:0]idu_in_bus_pc,idu_out_bus_pc;
	wire [4:0]idu_in_bus_exception;

	wire [31:0] S_araddr,S_rdata,S_awaddr,S_wdata;
	wire S_arvalid,S_rvalid,S_awvalid,S_wvalid,S_bvalid,S_rlast,S_wlast;
	wire S_arready,S_rready,S_awready,S_wready,S_bready;
	wire [1:0] S_rresp,S_bresp;
	wire [3:0] S_wstrb;
	wire [3:0] S_arid,S_awid,S_bid,S_rid;
	wire [1:0] S_arburst,S_awburst;
	wire [2:0] S_arsize,S_awsize;
	wire [7:0] S_arlen,S_awlen;
	wire [31:0] CLINT_araddr,CLINT_rdata;
	wire CLINT_arvalid,CLINT_rvalid,CLINT_rlast;
	wire CLINT_arready,CLINT_rready;
	wire [1:0] CLINT_rresp;

	wire [31:0] IROM_araddr,IROM_rdata;
	wire IROM_arvalid,IROM_arready,IROM_rvalid,IROM_rready;
	wire [1:0] IROM_rresp;
	wire [3:0] IROM_arid;
	wire [7:0] IROM_arlen;
	wire [2:0] IROM_arsize;
	wire [1:0] IROM_arburst;
	wire IROM_rlast;
	wire [3:0] IROM_rid;

	wire [31:0] DRAM_awaddr,DRAM_wdata,DRAM_araddr,DRAM_rdata;
	wire [3:0] DRAM_wstrb;
	wire DRAM_awvalid,DRAM_wvalid,DRAM_arvalid,DRAM_rvalid,DRAM_bvalid;
	wire DRAM_awready,DRAM_wready,DRAM_arready,DRAM_rready,DRAM_bready;
	wire [1:0] DRAM_bresp,DRAM_rresp;
	wire [3:0] DRAM_awid;  wire [7:0] DRAM_awlen;  wire [2:0] DRAM_awsize;  wire [1:0] DRAM_awburst;
	wire DRAM_wlast;
	wire [3:0] DRAM_bid;
	wire [3:0] DRAM_arid;  wire [7:0] DRAM_arlen;  wire [2:0] DRAM_arsize;  wire [1:0] DRAM_arburst;
	wire DRAM_rlast;
	wire [3:0] DRAM_rid;

	wire exu_out_bus_rd_valid,exu_out_bus_bypass_valid,exu_out_bus_csr_valid;
	wire lsu_out_bus_rd_valid,lsu_out_bus_bypass_valid,lsu_out_bus_csr_valid;
	wire wbu_out_bus_rd_valid,wbu_out_bus_bypass_valid,wbu_out_bus_csr_valid;
	wire [31:0] mcycle;
	wire [15:0] mcycleh;

	// assign dnpc=(wbu_out_bus_exception[4])?
	// 		(
	// 			(wbu_out_bus_exception[3:0]==`ysyx_26010011_EXCEPTION_MRET)?(csr_mepc):(csr_mtvec)
	// 		):(
	// 			exu_out_bus_alu_result
	// 		);

	assign csr_pc = wbu_in_bus_pc;
	assign dnpc_valid = flush_exception_valid | exu_out_bus_dnpc_valid;
	
	assign flush_exception_valid= wbu_out_bus_exception[4];
	assign flush_valid=dnpc_valid;



	ysyx_26010011_IFU IFU_0(
		.clock(clock),
		.reset(reset),
		
		// .dnpc(dnpc),
		.flush_valid(flush_valid),
		.csr_mepc(csr_mepc),
		.csr_mtvec(csr_mtvec),
		.exu_out_bus_alu_result(exu_out_bus_alu_result),
		.wbu_out_bus_exception(wbu_out_bus_exception),

		.ifu_out_valid(ifu_out_valid),
		.ifu_out_ready(ifu_out_ready),
		.ifu_out_bus_instruction(ifu_out_bus_instruction),
		.ifu_out_bus_pc(ifu_out_bus_pc),
		.ifu_out_bus_exception(ifu_out_bus_exception),

		.araddr(IROM_araddr),
		.arvalid(IROM_arvalid),
		.arready(IROM_arready),
		.arid(IROM_arid),
		.arlen(IROM_arlen),
		.arsize(IROM_arsize),
		.arburst(IROM_arburst),
		.rdata(IROM_rdata),
		.rresp(IROM_rresp),
		.rvalid(IROM_rvalid),
		.rready(IROM_rready),
		.rlast(IROM_rlast),
		.rid(IROM_rid),
		.fencei_flush(fencei_pass)
	);/*verilator public_module*/


	ysyx_26010011_IF_ID_pipeline IF_ID_inst(
		.clock(clock),
		.reset(reset),
		.flush_valid(flush_valid | fencei_pass),

		.ifu_out_valid(ifu_out_valid),
		.ifu_out_ready(ifu_out_ready),
		.ifu_out_bus_instruction(ifu_out_bus_instruction),
		.ifu_out_bus_pc(ifu_out_bus_pc),
		.ifu_out_bus_exception(ifu_out_bus_exception),

		.idu_in_valid(idu_in_valid),
		.idu_in_ready(idu_in_ready),
		.idu_in_bus_instruction(idu_in_bus_instruction),
		.idu_in_bus_exception(idu_in_bus_exception),
		.idu_in_bus_pc(idu_in_bus_pc)
	);/*verilator public_module*/

	ysyx_26010011_IDU IDU_0(
		.clock(clock),
		.reset(reset),
		.fencei_pass(fencei_pass),
		.flush_valid(flush_valid),
		.idu_in_bus_instruction(idu_in_bus_instruction),
		.idu_in_bus_pc(idu_in_bus_pc),
		.idu_in_bus_exception(idu_in_bus_exception),
		.idu_in_valid(idu_in_valid),
		.idu_in_ready(idu_in_ready),

		.gpr_rdataa(gpr_rdataa),
		.gpr_rdatab(gpr_rdatab),
		.csr_rdata(csr_rdata),

		.idu_out_valid(idu_out_valid),
		.idu_out_ready(idu_out_ready),
		.idu_out_bus_rd(idu_out_bus_rd),
		.idu_out_bus_exception(idu_out_bus_exception),
		.idu_out_bus_csrrd(idu_out_bus_csrrd),  //CSR地址
		.idu_out_bus_imm(idu_out_bus_imm),
		.idu_out_bus_isLOAD(idu_out_bus_isLOAD),
		.idu_out_bus_isSTORE(idu_out_bus_isSTORE),
		.idu_out_bus_isWGPR(idu_out_bus_isWGPR),
		.idu_out_bus_isJUMP(idu_out_bus_isJUMP),
		.idu_out_bus_isWCOMP(idu_out_bus_isWCOMP),
		.idu_out_bus_isBRANCH(idu_out_bus_isBRANCH),
		.idu_out_bus_opCSR(idu_out_bus_opCSR),
		.idu_out_bus_isUnSigned(idu_out_bus_isUnSigned),
		.idu_out_bus_isUsePC(idu_out_bus_isUsePC),
		.idu_out_bus_alu_isUseImm(idu_out_bus_alu_isUseImm),
		.idu_out_bus_comp_isUseImm(idu_out_bus_comp_isUseImm),
		.idu_out_bus_alu_op(idu_out_bus_alu_op),
		.idu_out_bus_comp_op(idu_out_bus_comp_op),
		.idu_out_bus_perip_mask(idu_out_bus_perip_mask),
		.idu_out_bus_rs1_val(idu_out_bus_rs1_val),
		.idu_out_bus_rs2_val(idu_out_bus_rs2_val),
		.idu_out_bus_rs1(gpr_raddra),
		.idu_out_bus_rs2(gpr_raddrb),
		.idu_out_bus_pc(idu_out_bus_pc),

		.exu_out_bus_rd_valid(exu_out_bus_rd_valid),
		.exu_out_bus_bypass_valid(exu_out_bus_bypass_valid),
		.exu_out_bus_csr_valid(exu_out_bus_csr_valid),
		.exu_out_bus_rd(exu_out_bus_rd),
		.exu_out_bus_csrrd(exu_out_bus_csrrd),
		.exu_out_bus_gpr_wdata(exu_out_bus_gpr_wdata),

		.lsu_out_bus_rd_valid(lsu_out_bus_rd_valid),
		.lsu_out_bus_bypass_valid(lsu_out_bus_bypass_valid),
		.lsu_out_bus_csr_valid(lsu_out_bus_csr_valid),
		.lsu_out_bus_rd(lsu_out_bus_rd),
		.lsu_out_bus_csrrd(lsu_out_bus_csrrd),
		.lsu_out_bus_gpr_wdata(lsu_out_bus_gpr_wdata),

		.wbu_out_bus_rd_valid(wbu_out_bus_rd_valid),
		.wbu_out_bus_bypass_valid(wbu_out_bus_bypass_valid),
		.wbu_out_bus_csr_valid(wbu_out_bus_csr_valid),
		.wbu_out_bus_rd(wbu_out_bus_rd),
		.wbu_out_bus_csrrd(wbu_out_bus_csrrd),
		.wbu_out_bus_gpr_wdata(wbu_out_bus_gpr_wdata)
	);/*verilator public_module*/

	ysyx_26010011_ID_EX_pipeline ID_EX_inst(
		.clock(clock),
		.reset(reset),
		.flush_valid(flush_valid),
		.idu_out_bus_exception(idu_out_bus_exception),
		.idu_out_valid(idu_out_valid),
		.idu_out_ready(idu_out_ready),
		.idu_out_bus_rd(idu_out_bus_rd),
		.idu_out_bus_csrrd(idu_out_bus_csrrd),  //CSR地址
		.idu_out_bus_rs1_val(idu_out_bus_rs1_val), //[~]zimm or rs1_val
		.idu_out_bus_rs2_val(idu_out_bus_rs2_val),
		.idu_out_bus_imm(idu_out_bus_imm),     //CSR值
`ifdef USE_VERILATOR
		.dbg_idu_out_bus_instruction(idu_in_bus_instruction),
`endif
		.idu_out_bus_isLOAD(idu_out_bus_isLOAD),
		.idu_out_bus_isSTORE(idu_out_bus_isSTORE),
		.idu_out_bus_isWGPR(idu_out_bus_isWGPR),
		.idu_out_bus_isJUMP(idu_out_bus_isJUMP),
		.idu_out_bus_isWCOMP(idu_out_bus_isWCOMP),
		.idu_out_bus_isBRANCH(idu_out_bus_isBRANCH),
		.idu_out_bus_opCSR(idu_out_bus_opCSR),
		.idu_out_bus_isUnSigned(idu_out_bus_isUnSigned),
		.idu_out_bus_isUsePC(idu_out_bus_isUsePC),
		.idu_out_bus_alu_isUseImm(idu_out_bus_alu_isUseImm),
		.idu_out_bus_comp_isUseImm(idu_out_bus_comp_isUseImm),
		.idu_out_bus_alu_op(idu_out_bus_alu_op),
		.idu_out_bus_comp_op(idu_out_bus_comp_op),
		.idu_out_bus_perip_mask(idu_out_bus_perip_mask),
		.idu_out_bus_pc(idu_out_bus_pc),

		.exu_in_valid(exu_in_valid),
		.exu_in_bus_exception(exu_in_bus_exception),
		.exu_in_ready(exu_in_ready),
		.exu_in_bus_rd(exu_in_bus_rd),
		.exu_in_bus_csrrd(exu_in_bus_csrrd),
		.exu_in_bus_rs1_val(exu_in_bus_rs1_val),
		.exu_in_bus_rs2_val(exu_in_bus_rs2_val),
		.exu_in_bus_imm(exu_in_bus_imm),
`ifdef USE_VERILATOR
		.dbg_exu_in_bus_instruction(dbg_exu_in_bus_instruction),
`endif
		.exu_in_bus_isLOAD(exu_in_bus_isLOAD),
		.exu_in_bus_isSTORE(exu_in_bus_isSTORE),
		.exu_in_bus_isWGPR(exu_in_bus_isWGPR),
		.exu_in_bus_isJUMP(exu_in_bus_isJUMP),
		.exu_in_bus_isWCOMP(exu_in_bus_isWCOMP),
		.exu_in_bus_isBRANCH(exu_in_bus_isBRANCH),
		.exu_in_bus_opCSR(exu_in_bus_opCSR),
		.exu_in_bus_isUnSigned(exu_in_bus_isUnSigned),
		.exu_in_bus_isUsePC(exu_in_bus_isUsePC),
		.exu_in_bus_alu_isUseImm(exu_in_bus_alu_isUseImm),
		.exu_in_bus_comp_isUseImm(exu_in_bus_comp_isUseImm),
		.exu_in_bus_alu_op(exu_in_bus_alu_op),
		.exu_in_bus_comp_op(exu_in_bus_comp_op),
		.exu_in_bus_perip_mask(exu_in_bus_perip_mask),
		.exu_in_bus_pc(exu_in_bus_pc)
	);/*verilator public_module*/

	ysyx_26010011_EXU EXU_0(
		.clock(clock),
		.reset(reset),
		.flush_valid(flush_valid),

		.exu_in_valid(exu_in_valid),
		.exu_in_ready(exu_in_ready),
		.exu_in_bus_exception(exu_in_bus_exception),
		.exu_in_bus_a(exu_in_bus_rs1_val),
		.exu_in_bus_b(exu_in_bus_rs2_val),
		.exu_in_bus_pc(exu_in_bus_pc),
		.exu_in_bus_imm(exu_in_bus_imm),
		.exu_in_bus_alu_op(exu_in_bus_alu_op),
		.exu_in_bus_comp_op(exu_in_bus_comp_op),
		.exu_in_bus_isJUMP(exu_in_bus_isJUMP),
		.exu_in_bus_isBRANCH(exu_in_bus_isBRANCH),
		.exu_in_bus_opCSR(exu_in_bus_opCSR),
		.exu_in_bus_isUnSigned(exu_in_bus_isUnSigned),
		.exu_in_bus_isUsePC(exu_in_bus_isUsePC),//PC+imm
		.exu_in_bus_alu_isUseImm(exu_in_bus_alu_isUseImm),//imm
		.exu_in_bus_comp_isUseImm(exu_in_bus_comp_isUseImm),//imm
		.exu_in_bus_isWGPR(exu_in_bus_isWGPR),
		.exu_in_bus_isLOAD(exu_in_bus_isLOAD),
		.exu_in_bus_isWCOMP(exu_in_bus_isWCOMP),
				
		.exu_out_bus_rd_valid(exu_out_bus_rd_valid),
		.exu_out_bus_bypass_valid(exu_out_bus_bypass_valid),
		.exu_out_bus_csr_valid(exu_out_bus_csr_valid),

		.exu_out_valid(exu_out_valid),
		.exu_out_bus_exception(exu_out_bus_exception),
		.exu_out_ready(exu_out_ready),
		.exu_out_bus_alu_result(exu_out_bus_alu_result),
		.exu_out_bus_opCSR(exu_out_bus_opCSR),
`ifdef USE_VERILATOR
		.dbg_exu_out_bus_comp_result(dbg_exu_out_bus_comp_result),       //暂存CSR目的地址
`endif
		.exu_out_bus_csr_result(exu_out_bus_csr_result),
		.exu_out_bus_gpr_wdata(exu_out_bus_gpr_wdata),
		.exu_out_bus_dnpc_valid(exu_out_bus_dnpc_valid)
	);/*verilator public_module*/
	assign exu_out_bus_rd = exu_in_bus_rd;
	assign exu_out_bus_csrrd = exu_in_bus_csrrd;

	ysyx_26010011_EX_LS_pipeline EX_LS_inst(
		.clock(clock),
		.reset(reset),
		.flush_valid(flush_exception_valid),

		.exu_out_valid(exu_out_valid),
		.exu_out_ready(exu_out_ready),
		
		.exu_out_bus_gpr_wdata(exu_out_bus_gpr_wdata),
		.exu_out_bus_csr_result(exu_out_bus_csr_result),
		
		.exu_out_bus_lsu_val(exu_in_bus_rs2_val),
		.exu_out_bus_rd(exu_out_bus_rd),
		.exu_out_bus_exception(exu_out_bus_exception),
		.exu_out_bus_csrrd(exu_out_bus_csrrd),
		
		.exu_out_bus_isLOAD(exu_in_bus_isLOAD),
		.exu_out_bus_isSTORE(exu_in_bus_isSTORE),
		.exu_out_bus_isWGPR(exu_in_bus_isWGPR),
		
		.exu_out_bus_opCSR(exu_out_bus_opCSR),
		.exu_out_bus_isUnSigned(exu_in_bus_isUnSigned),
		.exu_out_bus_perip_mask(exu_in_bus_perip_mask),
`ifdef USE_VERILATOR
		.dbg_exu_out_bus_alu_result(exu_out_bus_alu_result),
		.dbg_exu_out_bus_comp_result(dbg_exu_out_bus_comp_result),
		.dbg_exu_out_bus_instruction(dbg_exu_in_bus_instruction),
		.dbg_exu_out_bus_isJUMP(exu_in_bus_isJUMP),
		.dbg_exu_out_bus_isWCOMP(exu_in_bus_isWCOMP),
		.dbg_exu_out_bus_isBRANCH(exu_in_bus_isBRANCH),
`endif
		.exu_out_bus_pc(exu_in_bus_pc),
		.lsu_in_valid(lsu_in_valid),
		.lsu_in_bus_exception(lsu_in_bus_exception),
		.lsu_in_ready(lsu_in_ready),
		.lsu_in_bus_gpr_wdata(lsu_in_bus_gpr_wdata),
		.lsu_in_bus_csr_result(lsu_in_bus_csr_result),
		.lsu_in_bus_lsu_val(lsu_in_bus_wdata),
		.lsu_in_bus_rd(lsu_in_bus_rd),
		.lsu_in_bus_csrrd(lsu_in_bus_csrrd),
		.lsu_in_bus_isLOAD(lsu_in_bus_isLOAD),
		.lsu_in_bus_isSTORE(lsu_in_bus_isSTORE),
		.lsu_in_bus_isWGPR(lsu_in_bus_isWGPR),
		.lsu_in_bus_opCSR(lsu_in_bus_opCSR),
		.lsu_in_bus_isUnSigned(lsu_in_bus_isUnSigned),
		.lsu_in_bus_perip_mask(lsu_in_bus_perip_mask),
`ifdef USE_VERILATOR
		.dbg_lsu_in_bus_comp_result(dbg_lsu_in_bus_comp_result),
		.dbg_lsu_in_bus_alu_result(dbg_lsu_in_bus_alu_result),
		.dbg_lsu_in_bus_instruction(dbg_lsu_in_bus_instruction),
		.dbg_lsu_in_bus_isJUMP(dbg_lsu_in_bus_isJUMP),
		.dbg_lsu_in_bus_isWCOMP(dbg_lsu_in_bus_isWCOMP),
		.dbg_lsu_in_bus_isBRANCH(dbg_lsu_in_bus_isBRANCH),
`endif
		.lsu_in_bus_pc(lsu_in_bus_pc)
	);/*verilator public_module*/

`ifdef USE_VERILATOR
	assign dbg_lsu_out_bus_alu_result=dbg_lsu_in_bus_alu_result;
	assign dbg_lsu_out_bus_comp_result=dbg_lsu_in_bus_comp_result;
`endif

	ysyx_26010011_LSU LSU_0(
		.clock(clock),
		.reset(reset),
		.flush_valid(flush_exception_valid),
		.lsu_in_valid(lsu_in_valid),
		.lsu_in_ready(lsu_in_ready),
		.lsu_in_bus_exception(lsu_in_bus_exception),
		.lsu_in_bus_addr(lsu_in_bus_gpr_wdata),
		.lsu_in_bus_wdata(lsu_in_bus_wdata),
		.lsu_in_bus_perip_mask(lsu_in_bus_perip_mask),
		.lsu_in_bus_isUnSigned(lsu_in_bus_isUnSigned),
		.lsu_in_bus_isLOAD(lsu_in_bus_isLOAD),
		.lsu_in_bus_isSTORE(lsu_in_bus_isSTORE),
		.lsu_in_bus_isWGPR(lsu_in_bus_isWGPR),
		.lsu_in_bus_opCSR(lsu_in_bus_opCSR),
		.lsu_in_bus_rd(lsu_in_bus_rd),
		.lsu_in_bus_csrrd(lsu_in_bus_csrrd),
		.lsu_in_bus_csr_result(lsu_in_bus_csr_result),

		.lsu_out_bus_rd_valid(lsu_out_bus_rd_valid),
		.lsu_out_bus_bypass_valid(lsu_out_bus_bypass_valid),
		.lsu_out_bus_csr_valid(lsu_out_bus_csr_valid),

		.lsu_out_valid(lsu_out_valid),
		.lsu_out_bus_exception(lsu_out_bus_exception),
		.lsu_out_ready(lsu_out_ready),
		.lsu_out_bus_gpr_wdata(lsu_out_bus_gpr_wdata),
		.lsu_out_bus_rd(lsu_out_bus_rd),
		.lsu_out_bus_csrrd(lsu_out_bus_csrrd),
		.lsu_out_bus_csr_result(lsu_out_bus_csr_result),
		.awaddr(DRAM_awaddr),
		.awvalid(DRAM_awvalid),
		.awready(DRAM_awready),
		.awid(DRAM_awid),
		.awlen(DRAM_awlen),
		.awsize(DRAM_awsize),
		.awburst(DRAM_awburst),
		.wdata(DRAM_wdata),
		.wstrb(DRAM_wstrb),
		.wvalid(DRAM_wvalid),
		.wready(DRAM_wready),
		.wlast(DRAM_wlast),
		.bresp(DRAM_bresp),
		.bvalid(DRAM_bvalid),
		.bready(DRAM_bready),
		.bid(DRAM_bid),

		.araddr(DRAM_araddr),
		.arvalid(DRAM_arvalid),
		.arready(DRAM_arready),
		.arid(DRAM_arid),
		.arlen(DRAM_arlen),
		.arsize(DRAM_arsize),
		.arburst(DRAM_arburst),
		.rdata(DRAM_rdata),
		.rresp(DRAM_rresp),
		.rvalid(DRAM_rvalid),
		.rready(DRAM_rready),
		.rlast(DRAM_rlast),
		.rid(DRAM_rid)
	);/*verilator public_module*/
	ysyx_26010011_LS_WB_pipeline LS_WB_inst(
		.clock(clock),
		.reset(reset),
		.flush_valid(flush_exception_valid),

		.lsu_out_valid(lsu_out_valid),
		.lsu_out_ready(lsu_out_ready),
		.lsu_out_bus_rd(lsu_in_bus_rd),
		.lsu_out_bus_exception(lsu_out_bus_exception),
		.lsu_out_bus_csrrd(lsu_in_bus_csrrd),
		.lsu_out_bus_isWGPR(lsu_in_bus_isWGPR),
		.lsu_out_bus_gpr_wdata(lsu_out_bus_gpr_wdata),
		.lsu_out_bus_csr_result(lsu_out_bus_csr_result),

`ifdef USE_VERILATOR
		.dbg_lsu_out_bus_alu_result(dbg_lsu_out_bus_alu_result),
		.dbg_lsu_out_bus_comp_result(dbg_lsu_in_bus_comp_result),
		.dbg_lsu_out_bus_lsu_result(0),
		.dbg_lsu_out_bus_instruction(dbg_lsu_in_bus_instruction),
		.dbg_lsu_out_bus_isLOAD(lsu_in_bus_isLOAD),
		.dbg_lsu_out_bus_isSTORE(lsu_in_bus_isSTORE),
		.dbg_lsu_out_bus_isJUMP(dbg_lsu_in_bus_isJUMP),
		.dbg_lsu_out_bus_isWCOMP(dbg_lsu_in_bus_isWCOMP),
		.dbg_lsu_out_bus_isBRANCH(dbg_lsu_in_bus_isBRANCH),
`endif
		.lsu_out_bus_pc(lsu_in_bus_pc),
		.lsu_out_bus_opCSR(lsu_in_bus_opCSR),

		.wbu_in_valid(wbu_in_valid),
		.wbu_in_ready(wbu_in_ready),

`ifdef USE_VERILATOR
		.dbg_wbu_in_bus_comp_result(dbg_wbu_in_bus_comp_result),
		.dbg_wbu_in_bus_instruction(dbg_wbu_in_bus_instruction),
		.dbg_wbu_in_bus_isLOAD(dbg_wbu_in_bus_isLOAD),
		.dbg_wbu_in_bus_isSTORE(dbg_wbu_in_bus_isSTORE),
		
		.dbg_wbu_in_bus_isJUMP(dbg_wbu_in_bus_isJUMP),
		.dbg_wbu_in_bus_isWCOMP(dbg_wbu_in_bus_isWCOMP),
		.dbg_wbu_in_bus_isBRANCH(dbg_wbu_in_bus_isBRANCH),
		.dbg_wbu_in_bus_lsu_result(dbg_wbu_in_bus_lsu_result),
		.dbg_wbu_in_bus_alu_result(dbg_wbu_in_bus_alu_result),
`endif
		.wbu_in_bus_pc(wbu_in_bus_pc),
		.wbu_in_bus_csr_result(wbu_in_bus_csr_result),
		.wbu_in_bus_gpr_wdata(wbu_in_bus_gpr_wdata),

		.wbu_in_bus_rd(wbu_in_bus_rd),
		.wbu_in_bus_exception(wbu_in_bus_exception),
		.wbu_in_bus_csrrd(wbu_in_bus_csrrd),

		.wbu_in_bus_isWGPR(wbu_in_bus_isWGPR),

		.wbu_in_bus_opCSR(wbu_in_bus_opCSR)
		
	);/*verilator public_module*/


	ysyx_26010011_WBU WBU_0(
		.clock(clock),
		.reset(reset),
		.flush_valid(flush_exception_valid),

		.wbu_in_valid(wbu_in_valid),
		.wbu_in_ready(wbu_in_ready),
		.wbu_in_bus_csr_result(wbu_in_bus_csr_result),
		.wbu_in_bus_gpr_wdata(wbu_in_bus_gpr_wdata),

		.wbu_out_bus_rd_valid(wbu_out_bus_rd_valid),
		.wbu_out_bus_bypass_valid(wbu_out_bus_bypass_valid),
		.wbu_out_bus_csr_valid(wbu_out_bus_csr_valid),
		.wbu_out_bus_rd(wbu_out_bus_rd),
		.wbu_out_bus_csrrd(wbu_out_bus_csrrd),
		.wbu_out_bus_gpr_wdata(wbu_out_bus_gpr_wdata),
		
		.wbu_in_bus_rd(wbu_in_bus_rd),
		.wbu_in_bus_csrrd(wbu_in_bus_csrrd),
		.wbu_in_bus_isWGPR(wbu_in_bus_isWGPR),
		.wbu_in_bus_opCSR(wbu_in_bus_opCSR),
		.wbu_in_bus_exception(wbu_in_bus_exception),
		.wbu_out_bus_exception(wbu_out_bus_exception),
		.gpr_we(gpr_we),
		.gpr_wdata(gpr_wdata),
		.gpr_address(gpr_waddr),
		.csr_we(csr_we),
		.csr_wdata(csr_wdata),
		.csr_address(csr_waddr),
		.fencei_pass(fencei_pass)
	);/*verilator public_module*/
	

`ifdef USE_VERILATOR
  	//WBU FINAL
	reg tb_isFINAL/*verilator public*/,tb_dnpc_valid/*verilator public*/,tb_isMEM/*verilator public*/;
	reg [31:0]tb_FINAL_pc/*verilator public*/,tb_FINAL_npc/*verilator public*/,tb_alu_result/*verilator public*/,tb_FINAL_inst/*verilator public*/;
	always @(posedge clock) begin
		if(reset) begin
		tb_isFINAL<=0;
		tb_FINAL_pc<=0;
		tb_FINAL_npc<=0;
		tb_dnpc_valid<=0;
		tb_isMEM<=0;
		tb_FINAL_inst<=0;
		end else if(wbu_in_valid) begin
		tb_isFINAL<=1;
		tb_FINAL_pc<=wbu_in_bus_pc;
		// tb_FINAL_npc<=(dbg_wbu_in_bus_isJUMP | (dbg_wbu_in_bus_isBRANCH & dbg_wbu_in_bus_comp_result)) ? dbg_wbu_in_bus_alu_result : ((wbu_in_bus_exception[4])?csr_mtvec:wbu_in_bus_pc + 32'd4);//TODO MTVEC
		tb_FINAL_npc<=(wbu_out_bus_exception[4])?((wbu_out_bus_exception[3:0]==`ysyx_26010011_EXCEPTION_MRET)?csr_mepc:csr_mtvec):((dbg_wbu_in_bus_isJUMP | (dbg_wbu_in_bus_isBRANCH & dbg_wbu_in_bus_comp_result)) ? dbg_wbu_in_bus_alu_result : wbu_in_bus_pc + 32'd4);//TODO MTVEC
		tb_dnpc_valid<=(dbg_wbu_in_bus_isJUMP | (dbg_wbu_in_bus_isBRANCH&dbg_wbu_in_bus_comp_result) | (wbu_in_bus_exception[4]));
		tb_isMEM<=(dbg_wbu_in_bus_isLOAD | dbg_wbu_in_bus_isSTORE)&wbu_in_valid;
		tb_FINAL_inst<=dbg_wbu_in_bus_instruction;
		end else begin
		tb_isFINAL<=0;
		tb_FINAL_pc<=tb_FINAL_pc;
		tb_FINAL_npc<=tb_FINAL_npc;
		tb_dnpc_valid<=0;
		tb_isMEM<=0;
		tb_FINAL_inst<=tb_FINAL_inst;
		end
	end
`endif

	ysyx_26010011_AXI4Arbiter RAM_AXI4Arbiter(
		.clock(clock),
		.reset(reset),

		//MASTER1 AR
		.M1_araddr(IROM_araddr),  .M1_arvalid(IROM_arvalid),  .M1_arready(IROM_arready),
		.M1_arid(IROM_arid),      .M1_arlen(IROM_arlen),      .M1_arsize(IROM_arsize),    .M1_arburst(IROM_arburst),
		//MASTER1 R
		.M1_rdata(IROM_rdata),    .M1_rresp(IROM_rresp),      .M1_rvalid(IROM_rvalid),    .M1_rready(IROM_rready),
		.M1_rlast(IROM_rlast),    .M1_rid(IROM_rid),

		//MASTER2 AW
		.M2_awaddr(DRAM_awaddr),  .M2_awvalid(DRAM_awvalid),  .M2_awready(DRAM_awready),
		.M2_awid(DRAM_awid),      .M2_awlen(DRAM_awlen),      .M2_awsize(DRAM_awsize),    .M2_awburst(DRAM_awburst),
		//MASTER2 W
		.M2_wdata(DRAM_wdata),    .M2_wstrb(DRAM_wstrb),      .M2_wvalid(DRAM_wvalid),    .M2_wready(DRAM_wready),
		.M2_wlast(DRAM_wlast),
		//MASTER2 B
		.M2_bresp(DRAM_bresp),    .M2_bvalid(DRAM_bvalid),    .M2_bready(DRAM_bready),
		.M2_bid(DRAM_bid),
		//MASTER2 AR
		.M2_araddr(DRAM_araddr),  .M2_arvalid(DRAM_arvalid),  .M2_arready(DRAM_arready),
		.M2_arid(DRAM_arid),      .M2_arlen(DRAM_arlen),      .M2_arsize(DRAM_arsize),    .M2_arburst(DRAM_arburst),
		//MASTER2 R
		.M2_rdata(DRAM_rdata),    .M2_rresp(DRAM_rresp),      .M2_rvalid(DRAM_rvalid),    .M2_rready(DRAM_rready),
		.M2_rlast(DRAM_rlast),    .M2_rid(DRAM_rid),

		//SLAVE AW
		.S_awaddr(S_awaddr),  .S_awvalid(S_awvalid),  .S_awready(S_awready),
		.S_awid(S_awid),      .S_awlen(S_awlen),      .S_awsize(S_awsize),    .S_awburst(S_awburst),
		//SLAVE W
		.S_wdata(S_wdata),    .S_wstrb(S_wstrb),      .S_wvalid(S_wvalid),    .S_wready(S_wready),
		.S_wlast(S_wlast),
		//SLAVE B
		.S_bresp(S_bresp),    .S_bvalid(S_bvalid),    .S_bready(S_bready),
		.S_bid(S_bid),
		//SLAVE AR
		.S_araddr(S_araddr),  .S_arvalid(S_arvalid),  .S_arready(S_arready),
		.S_arid(S_arid),      .S_arlen(S_arlen),      .S_arsize(S_arsize),    .S_arburst(S_arburst),
		//SLAVE R
		.S_rdata(S_rdata),    .S_rresp(S_rresp),      .S_rvalid(S_rvalid),    .S_rready(S_rready),
		.S_rlast(S_rlast),    .S_rid(S_rid)
	);



	ysyx_26010011_bridge u_bridge(
		.clock(clock),
		.reset(reset),
		
		.S_araddr(S_araddr),  .S_arvalid(S_arvalid), .S_arready(S_arready), .S_arid(S_arid), .S_arlen(S_arlen), .S_arsize(S_arsize), .S_arburst(S_arburst),
		.S_rdata(S_rdata),   .S_rresp(S_rresp),   .S_rvalid(S_rvalid),  .S_rready(S_rready), .S_rlast(S_rlast), .S_rid(S_rid),
		.S_awaddr(S_awaddr),  .S_awvalid(S_awvalid), .S_awready(S_awready), .S_awid(S_awid), .S_awlen(S_awlen), .S_awsize(S_awsize), .S_awburst(S_awburst),
		.S_wdata(S_wdata),   .S_wstrb(S_wstrb),   .S_wvalid(S_wvalid),  .S_wready(S_wready), .S_wlast(S_wlast),
		.S_bresp(S_bresp),   .S_bvalid(S_bvalid),  .S_bready(S_bready), .S_bid(S_bid),

		///////////////////////////////////////////////////////
		//MEM
		.MEM_araddr(io_master_araddr),   .MEM_arvalid(io_master_arvalid),  .MEM_arready(io_master_arready), .MEM_arid(io_master_arid), .MEM_arlen(io_master_arlen), .MEM_arsize(io_master_arsize), .MEM_arburst(io_master_arburst),
		.MEM_rdata(io_master_rdata),    .MEM_rresp(io_master_rresp),    .MEM_rvalid(io_master_rvalid),   .MEM_rready(io_master_rready), .MEM_rlast(io_master_rlast), .MEM_rid(io_master_rid),
		.MEM_awaddr(io_master_awaddr),   .MEM_awvalid(io_master_awvalid),  .MEM_awready(io_master_awready), .MEM_awid(io_master_awid), .MEM_awlen(io_master_awlen), .MEM_awsize(io_master_awsize), .MEM_awburst(io_master_awburst),
		.MEM_wdata(io_master_wdata),    .MEM_wstrb(io_master_wstrb),    .MEM_wvalid(io_master_wvalid),   .MEM_wready(io_master_wready), .MEM_wlast(io_master_wlast),
		.MEM_bresp(io_master_bresp),    .MEM_bvalid(io_master_bvalid),   .MEM_bready(io_master_bready), .MEM_bid(io_master_bid),

		//CLINT
		.CLINT_araddr(CLINT_araddr),   .CLINT_arvalid(CLINT_arvalid),  .CLINT_arready(CLINT_arready),
		.CLINT_rdata(CLINT_rdata),    .CLINT_rresp(CLINT_rresp),    .CLINT_rvalid(CLINT_rvalid),   .CLINT_rready(CLINT_rready), .CLINT_rlast(CLINT_rlast)
	);	

	ysyx_26010011_CLINT u_clint(
		.clock(clock),
		.reset(reset),
		.mcycle(mcycle),
		.mcycleh(mcycleh),
		//AR
		.araddr(CLINT_araddr),
		.arvalid(CLINT_arvalid),
		.arready(CLINT_arready),

		//R
		.rdata(CLINT_rdata),
		.rresp(CLINT_rresp),
		.rvalid(CLINT_rvalid),
		.rlast(CLINT_rlast),
		.rready(CLINT_rready)
	);


  
	ysyx_26010011_GPRs GPR_0(
		.clock(clock),
		.reset(reset),
		.gpr_in_addra(gpr_raddra),
		.gpr_in_addrb(gpr_raddrb),
		.gpr_out_a(gpr_rdataa),
		.gpr_out_b(gpr_rdatab),
		.gpr_in_addw(gpr_waddr),
		.gpr_in_data(gpr_wdata),
		.gpr_in_wen(gpr_we)
	);/*verilator public_module*/
	
  	ysyx_26010011_CSRs CSR_0(
		.clock(clock),
		.reset(reset),
		.csr_in_addr(idu_out_bus_csrrd),
		.csr_out_data(csr_rdata),
		.mcycle(mcycle),
		.mcycleh(mcycleh),

		.csr_in_data(csr_wdata),
		.csr_in_wen(csr_we),
		.csr_in_addw(csr_waddr),
		
		.csr_pc(csr_pc),
		.csr_mtvec(csr_mtvec),
		.csr_mepc(csr_mepc),
		.csr_in_bus_exception(wbu_out_bus_exception)
	);/*verilator public_module*/
endmodule