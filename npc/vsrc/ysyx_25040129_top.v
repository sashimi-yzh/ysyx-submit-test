

`ifdef ysyx_25040129_DPI
import "DPI-C" function void ebreak_trigger();
import "DPI-C" function void unknown_inst(int inst);
import "DPI-C" function int paddr_read(int addr, int len,int is_fetch, int is_avail);
import "DPI-C" function void paddr_write(int addr, int len, int data, int is_avail);
import "DPI-C" function void update_regs(int reg1, int reg2, int reg3, int reg4, int reg5, int reg6, int reg7, int reg8, int reg9, int reg10, int reg11, int reg12, int reg13, int reg14, int reg15, int reg16);
import "DPI-C" function void update_pc(int pc);
import "DPI-C" function void update_inst(int inst);
import "DPI-C" function void update_is_device(bit is_device);
import "DPI-C" function void update_wbu_state(bit wbu_state);
import "DPI-C" function void fetch_count_inc(byte ifu_state);
import "DPI-C" function void execute_count_inc(byte exu_state);
import "DPI-C" function void load_store_count_inc(byte lsu_state);
import "DPI-C" function void track_inst_in_idu(byte idu_state,byte opcode);
import "DPI-C" function void icache_count_inc(byte icache_state,bit ifu_arvalid,bit is_hit);
import "DPI-C" function void record_pc(int pc);
import "DPI-C" function void record_load_store(int addr, int is_load);
`endif 

`ifndef ysyx_25040129_CSR_DIG
`define ysyx_25040129_CSR_DIG 3
`endif
`ifndef ysyx_25040129_REGS_DIG
`define ysyx_25040129_REGS_DIG 4
`endif
/*verilator lint_off DECLFILENAME*/


module ysyx_25040129(
// verilator lint_off UNUSED
/* verilator lint_off UNDRIVEN */
	input clock,
	input reset,
  // --------------- master -----------------
  input  io_interrupt,

  // --------------- master 写地址 AW -----------------
  input  io_master_awready,
  output io_master_awvalid,
  output [3:0]  io_master_awid,
  output [31:0] io_master_awaddr,
  output [7:0]  io_master_awlen,
  output [2:0]  io_master_awsize,
  output [1:0]  io_master_awburst,

  // --------------- master 写数据 W -----------------
  input  io_master_wready,
  output io_master_wvalid,
  output [31:0] io_master_wdata,
  output [3:0]  io_master_wstrb,
  output io_master_wlast,

  // --------------- master 写响应 B -----------------
  output io_master_bready,
  input  io_master_bvalid,
  input  [3:0] io_master_bid,
  input  [1:0] io_master_bresp,

  // --------------- master 读地址 AR -----------------
  input  io_master_arready,
  output io_master_arvalid,
  output [3:0]  io_master_arid,
  output [31:0] io_master_araddr,
  output [7:0]  io_master_arlen,
  output [2:0]  io_master_arsize,
  output [1:0]  io_master_arburst,

  // --------------- master 读数据 R -----------------
  output io_master_rready,
  input  io_master_rvalid,
  input  [3:0]  io_master_rid,
  input  [31:0] io_master_rdata,
  input  [1:0]  io_master_rresp,
  input  io_master_rlast,


  // --------------- slave 写地址 AW -----------------
  output io_slave_awready,
  input  io_slave_awvalid,
  input  [3:0]  io_slave_awid,
  input  [31:0] io_slave_awaddr,
  input  [7:0]  io_slave_awlen,
  input  [2:0]  io_slave_awsize,
  input  [1:0]  io_slave_awburst,

  // --------------- slave 写数据 W -----------------
  output io_slave_wready,
  input  io_slave_wvalid,
  input  [31:0] io_slave_wdata,
  input  [3:0]  io_slave_wstrb,
  input  io_slave_wlast,

  // --------------- slave 写响应 B -----------------
  input  io_slave_bready,
  output io_slave_bvalid,
  output [3:0] io_slave_bid,
  output [1:0] io_slave_bresp,

  // --------------- slave 读地址 AR -----------------
  output io_slave_arready,
  input  io_slave_arvalid,
  input  [3:0]  io_slave_arid,
  input  [31:0] io_slave_araddr,
  input  [7:0]  io_slave_arlen,
  input  [2:0]  io_slave_arsize,
  input  [1:0]  io_slave_arburst,

  // --------------- slave 读数据 R -----------------
  input  io_slave_rready,
  output io_slave_rvalid,
  output [3:0]  io_slave_rid,
  output [31:0] io_slave_rdata,
  output [1:0]  io_slave_rresp,
  output io_slave_rlast
  // verilator lint_on UNUSED
  /* verilator lint_on UNDRIVEN */
);
	wire clk;
	assign clk = clock;
	wire rst;
	assign rst = reset;
	// assign io_master_arlen = 8'b0;
	// assign io_master_arburst = 2'b01; // INCR
	assign io_master_arid = 4'b0;
	assign io_master_awid = 4'b0;
	assign io_master_awlen = 8'b0;
	assign io_master_awsize = 3'b000; 
	assign io_master_awburst = 2'b00;
	assign io_master_wlast = 1'b1;
	//-------------------------------------------------------------------------	
	wire [31:0] araddr_to_rtc;
	wire arvalid_to_rtc;
	wire arready_from_rtc;

	wire [31:0] rdata_from_rtc;
	wire [1:0] rresp_from_rtc;
	wire rvalid_from_rtc;
	wire rready_to_rtc;
	//--------------------------------------------------------------------------
	wire [7:0] arlen_to_xbar;
	wire [1:0] arburst_to_xbar;
	wire rlast_from_xbar;
	wire [2:0] arsize_to_xbar;
	wire [31:0] araddr_to_xbar;
	wire arvalid_to_xbar;
	wire rready_to_xbar;
	wire [31:0] rdata_from_xbar;
	wire [1:0] rresp_from_xbar;
	wire rvalid_from_xbar;
	wire arready_from_xbar;
	
	/* verilator lint_off UNUSEDSIGNAL */
	wire empty_awready;
	wire empty_wready;
	wire empty_bvalid;
	wire [1:0] empty_bresp;
	/* verilator lint_on UNUSEDSIGNAL */
	//--------------------------------------------------------------------------
	wire [7:0] arlen_from_icache;
	wire [1:0] arburst_from_icache;
	wire [31:0] araddr_from_icache;
	wire arvalid_from_icache;
	wire arready_to_icache;
	wire [31:0] rdata_to_icache;
	wire [1:0] rresp_to_icache;
	wire rvalid_to_icache;
	wire rready_from_icache;
	wire rlast_to_icache;
	//--------------------------------------------------------------------------
	wire is_jalr_out_idu;
	wire is_req_valid_from_idu_to_exu;
	wire is_req_ready_from_exu_to_idu;
	wire [31:0] src1_in_idu;
	wire [31:0] src2_in_idu;
	wire [31:0] csr_in_idu;
	wire [`ysyx_25040129_CSR_DIG-1:0] csr_read_id_out_idu;
	wire [`ysyx_25040129_CSR_DIG-1:0] csr_write_id_out_idu;
	wire [31:0] src1_out_idu;
	wire [31:0] src2_out_idu;
	wire [31:0] lsu_write_data_out_idu;
	wire [`ysyx_25040129_REGS_DIG-1:0] src1_id_out_idu;
	wire [`ysyx_25040129_REGS_DIG-1:0] src2_id_out_idu;
	
	wire [31:0] imm;
	wire [`ysyx_25040129_REGS_DIG-1:0] rd_out_idu;
	wire [3:0] alu_opcode;
	wire reg_write_out_idu;
	wire [1:0] lsu_write_out_idu;
	wire [2:0] lsu_read_out_idu;
	wire ecall_out_idu;
	wire is_jump_out_idu;
	wire ebreak_out_idu;
	wire mret_out_idu;
	wire [31:0] pc_out_idu;
	wire csr_write_out_idu;
	wire fence_i_out_idu;
	`ifdef ysyx_25040129_DEBUG
	wire [31:0] debug_inst_out_idu;
	wire [31:0] debug_inst_out_idu_pip;
	`endif
	//--------------------------------------------------------------------------

	wire [31:0] pc_from_ifu;

	wire [31:0] inst_to_idu;

	wire [31:0] araddr_from_ifu;
	wire arvalid_from_ifu;
	wire rready_to_ifu;

	wire [31:0] rdata_to_ifu;
	wire [1:0] rresp_to_ifu;
	wire rvalid_to_ifu;
	wire rready_from_ifu;
	wire is_req_ready_from_idu_to_ifu;
	wire is_req_valid_from_ifu_to_idu;
	//--------------------------------------------------------------------------
	wire is_req_ready_from_pipline_exu_to_idu;
	wire is_req_valid_from_pipeline_idu_to_exu;
	wire [31:0] pc_from_idu_pip;
	wire [31:0] src1_out_idu_pip;
	wire [31:0] src2_out_idu_pip;
	wire [31:0] imm_pip;
	wire [31:0] lsu_write_data_out_idu_pip;
	wire [3:0] alu_opcode_pip;
	wire [`ysyx_25040129_REGS_DIG-1:0] rd_out_idu_pip;
	wire [`ysyx_25040129_CSR_DIG-1:0] csr_write_id_out_idu_pip;
	wire is_jalr_out_idu_pip;
	wire is_jump_out_idu_pip;
	wire reg_write_out_idu_pip;
	wire csr_write_out_idu_pip;
	wire [1:0] lsu_write_out_idu_pip;
	wire [2:0] lsu_read_out_idu_pip;
	wire ecall_out_idu_pip;
	wire ebreak_out_idu_pip;
	wire mret_out_idu_pip;
	wire fence_i_out_idu_pip;
	//--------------------------------------------------------------------------
	wire [31:0] pc_from_ifu_pip;
	wire [31:0] inst_to_idu_pip;
	wire is_req_valid_from_pipeline_ifu_to_idu;
	wire is_req_ready_from_pipeline_idu_to_ifu;
	//--------------------------------------------------------------------------
	wire fence_i_out_exu;
	wire [31:0] data_forward_from_exu;
	wire [31:0] result_out_exu;
	assign data_forward_from_exu = result_out_exu;
	wire is_data_forward_valid_from_exu;

	wire [`ysyx_25040129_CSR_DIG-1:0] csr_addr_out_exu;
	wire [31:0] lsu_write_data_out_exu;

	wire [31:0] branch_target_out_exu;
	wire [`ysyx_25040129_REGS_DIG-1:0] rd_out_exu;
	wire [2:0] lsu_read_out_exu;
	wire [1:0] lsu_write_out_exu;

	wire is_branch_out_exu;
	wire csr_write_out_exu;
	wire ebreak_out_exu;
	wire ecall_out_exu;
	wire mret_out_exu;
	wire reg_write_out_exu;
	wire is_req_valid_from_exu_to_lsu;
	wire is_req_ready_from_lsu_to_exu;
	wire is_req_valid_from_pipeline_exu_to_lsu;
	wire is_req_ready_from_pipeline_lsu_to_exu;
	//--------------------------------------------------------------------------
	wire [2:0] lsu_read_out_exu_pip;
	wire [1:0] lsu_write_out_exu_pip;
	wire [31:0] branch_target_out_exu_pip;
	wire [31:0] result_out_exu_pip;
	wire [31:0] lsu_write_data_out_exu_pip;
	wire [`ysyx_25040129_REGS_DIG-1:0] rd_out_exu_pip;
	wire ebreak_out_exu_pip;
	wire ecall_out_exu_pip;
	wire mret_out_exu_pip;
	wire is_branch_out_exu_pip;
	wire csr_write_out_exu_pip;
	wire reg_write_out_exu_pip;
	wire fence_i_out_exu_pip;
	wire [`ysyx_25040129_CSR_DIG-1:0] csr_addr_out_exu_pip;
	//--------------------------------------------------------------------------
	wire is_data_forward_valid_from_lsu;
	wire [31:0] data_forward_from_lsu;
	wire [31:0] result_out_lsu;
	assign data_forward_from_lsu = result_out_lsu;
	`ifdef ysyx_25040129_DEBUG
	wire [31:0] debug_pc_from_exu_to_lsu_pip;
	wire [31:0] debug_pc_from_exu_to_lsu;
	wire [31:0] debug_inst_from_exu_to_lsu_pip;
	wire [31:0] debug_inst_from_exu_to_lsu;
	`endif 
	`ifdef ysyx_25040129_DEBUG
	wire debug_is_device_lsu_to_wbu;
	wire debug_is_device_lsu_to_wbu_pip;
	`endif
	wire fence_i_out_lsu;
	wire reg_write_out_lsu;
	wire [`ysyx_25040129_CSR_DIG-1:0] csr_addr_out_lsu;
	wire csr_write_out_lsu;
	wire [31:0] araddr_from_lsu;
	wire arvalid_from_lsu;
	wire [2:0] arsize_from_lsu;
	wire rready_to_lsu;

	wire [31:0] rdata_to_lsu;
	wire [1:0] rresp_to_lsu;
	wire rvalid_to_lsu;
	wire rready_from_lsu;

	wire [31:0] awaddr_from_lsu;
	wire awvalid_from_lsu;
	wire awready_to_lsu;

	wire [3:0] wstrb_from_lsu;
	wire [31:0] wdata_from_lsu;
	wire wvalid_from_lsu;
	wire wready_to_lsu;

	wire [1:0] bresp_to_lsu;
	wire bvalid_to_lsu;
	wire bready_from_lsu;

	wire [`ysyx_25040129_REGS_DIG-1:0] rd_out_lsu;
	wire ebreak_out_lsu;
	wire ebreak_out_lsu_pip;
	wire mret_out_lsu;
	wire ecall_out_lsu;
	wire is_branch_out_lsu;
	`ifdef __ICARUS__
	wire [31:0] a0;
	`endif

	wire [31:0] branch_target_out_lsu;
	

	wire is_req_valid_from_lsu_to_wbu;
	wire is_req_ready_from_wbu_to_lsu;//从LSU发出的信号，应该具备冲刷流水线的能力

	//--------------------------------------------------------------------------
	
	//-----------------difftest适配-----------------
	// `ifdef ysyx_25040129_DEBUG
	// reg [31:0] difftest_pc;
	// reg [31:0] flush_latch;
	// always @(posedge clk) begin
	// 	flush_latch <= pipeline_flush_signal? flush_reset_pc : 32'h0;
	// end
	// 	always @(posedge is_req_valid_from_pipeline_lsu_to_wbu) begin
	// 		difftest_pc <= (flush_latch != 32'h0)? flush_latch : debug_pc_from_lsu_to_wbu_pip + 4;
	// 	end
	// 	always @(*) begin
	// 		update_pc(difftest_pc);
	// 	end
	// `endif
	//------------------------------------------------------
	//--------------------------------------------------------------------------
	wire is_req_valid_from_pipeline_lsu_to_wbu;
	wire is_req_ready_from_pipeline_wbu_to_lsu;
	wire [31:0] result_out_lsu_pip;
	wire [`ysyx_25040129_REGS_DIG-1:0] rd_out_lsu_pip;
	wire reg_write_out_lsu_pip;
	wire csr_write_out_lsu_pip;
	wire [`ysyx_25040129_CSR_DIG-1:0] csr_addr_out_lsu_pip;
	//--------------------------------------------------------------------------
	wire [31:0]data_forward_from_wbu;
	wire is_data_forward_valid_from_wbu;
	wire [31:0] result_out_wbu;
	wire [`ysyx_25040129_REGS_DIG-1:0] rd_out_wbu;
	wire csr_write_out_wbu;
	wire [`ysyx_25040129_CSR_DIG-1:0] csr_addr_out_wbu;
	wire reg_write_out_wbu;
	//--------------------------------------------------------------------------
	//-----------------流水线冲刷/重置pc-----------------
	`ifdef ysyx_25040129_DEBUG
	wire [31:0] debug_pc_from_lsu_to_wbu;
	wire [31:0] debug_pc_from_lsu_to_wbu_pip;
	wire [31:0] debug_inst_from_lsu_to_wbu;
	wire [31:0] debug_inst_from_lsu_to_wbu_pip;
	`endif
	wire pipeline_flush_signal;
	wire [31:0] flush_reset_pc;
	assign pipeline_flush_signal = is_req_valid_from_lsu_to_wbu && 
		(is_branch_out_lsu || ecall_out_lsu || mret_out_lsu || fence_i_out_lsu );
	assign flush_reset_pc = branch_target_out_lsu;
	//------------------------------------------------------
	ysyx_25040129_XBAR u_ysyx_25040129_XBAR(
		.clk(clk),
		.rst(rst),

		.araddr(araddr_to_xbar),
		.arvalid(arvalid_to_xbar),
		.arready(arready_from_xbar),
		.arsize(arsize_to_xbar),
		.arlen(arlen_to_xbar),
		.arburst(arburst_to_xbar),

		.rdata(rdata_from_xbar),
		.rresp(rresp_from_xbar),
		.rvalid(rvalid_from_xbar),
		.rready(rready_to_xbar),
		.rlast(rlast_from_xbar),

		.awaddr(awaddr_from_lsu),
		.awvalid(awvalid_from_lsu),
		.awready(awready_to_lsu),

		.wstrb(wstrb_from_lsu),
		.wdata(wdata_from_lsu),
		.wvalid(wvalid_from_lsu),
		.wready(wready_to_lsu),

		.bresp(bresp_to_lsu),
		.bvalid(bvalid_to_lsu),
		.bready(bready_from_lsu),

		.soc_araddr(io_master_araddr),
		.soc_arvalid(io_master_arvalid),
		.soc_arready(io_master_arready),
		.soc_arsize(io_master_arsize),
		.soc_arlen(io_master_arlen),
		.soc_arburst(io_master_arburst),

		.soc_rdata(io_master_rdata),
		.soc_rresp(io_master_rresp),
		.soc_rvalid(io_master_rvalid),
		.soc_rready(io_master_rready),
		.soc_rlast(io_master_rlast),

		.soc_awaddr(io_master_awaddr),
		.soc_awvalid(io_master_awvalid),
		.soc_awready(io_master_awready),

		.soc_wstrb(io_master_wstrb),
		.soc_wdata(io_master_wdata),
		.soc_wvalid(io_master_wvalid),
		.soc_wready(io_master_wready),

		.soc_bresp(io_master_bresp),
		.soc_bvalid(io_master_bvalid),
		.soc_bready(io_master_bready),

		.rtc_araddr(araddr_to_rtc),
		.rtc_arvalid(arvalid_to_rtc),
		.rtc_arready(arready_from_rtc),

		.rtc_rdata(rdata_from_rtc),
		.rtc_rresp(rresp_from_rtc),
		.rtc_rvalid(rvalid_from_rtc),
		.rtc_rready(rready_to_rtc)
	);
	

	ysyx_25040129_CLINT u_ysyx_25040129_CLINT (
		.clk(clk),
		.rst(rst),

		.araddr(araddr_to_rtc),
		.arvalid(arvalid_to_rtc),
		.arready(arready_from_rtc),

		.rdata(rdata_from_rtc),
		.rresp(rresp_from_rtc),
		.rvalid(rvalid_from_rtc),
		.rready(rready_to_rtc)
	);


	ysyx_25040129_BUSARB u_ysyx_25040129_BUSARB(
		.clk(clk),
		.rst(rst),

		.icache_araddr(araddr_from_icache),
		.icache_arvalid(arvalid_from_icache),
		.icache_arready(arready_to_icache),
		.icache_arlen(arlen_from_icache),
		.icache_arburst(arburst_from_icache),

		.icache_rdata(rdata_to_icache),
		.icache_rresp(rresp_to_icache),
		.icache_rvalid(rvalid_to_icache),
		.icache_rready(rready_from_icache),
		.icache_rlast(rlast_to_icache),

		.lsu_araddr(araddr_from_lsu),
		.lsu_arvalid(arvalid_from_lsu),
		.lsu_arready(rready_to_lsu),
		.lsu_arsize(arsize_from_lsu),

		.lsu_rdata(rdata_to_lsu),
		.lsu_rresp(rresp_to_lsu),
		.lsu_rvalid(rvalid_to_lsu),
		.lsu_rready(rready_from_lsu),

		.araddr(araddr_to_xbar),
		.arvalid(arvalid_to_xbar),
		.arready(arready_from_xbar),
		.arsize(arsize_to_xbar),
		.arlen(arlen_to_xbar),
		.arburst(arburst_to_xbar),

		.rdata(rdata_from_xbar),
		.rresp(rresp_from_xbar),
		.rvalid(rvalid_from_xbar),
		.rready(rready_to_xbar),
		.rlast(rlast_from_xbar)
	);	

	ysyx_25040129_ICACHE u_ysyx_25040129_ICACHE (
		.clk(clk),
		.rst(rst),

		.ifu_araddr(araddr_from_ifu),
		.ifu_arvalid(arvalid_from_ifu),
		.ifu_arready(rready_to_ifu),

		.ifu_rdata(rdata_to_ifu),
		.ifu_rresp(rresp_to_ifu),
		.ifu_rvalid(rvalid_to_ifu),
		.ifu_rready(rready_from_ifu),

		.out_araddr(araddr_from_icache),
		.out_arvalid(arvalid_from_icache),
		.out_arready(arready_to_icache),
		.out_arlen(arlen_from_icache),
		.out_arburst(arburst_from_icache),

		.out_rdata(rdata_to_icache),
		.out_rresp(rresp_to_icache),
		.out_rvalid(rvalid_to_icache),
		.out_rready(rready_from_icache),
		.out_rlast(rlast_to_icache),
		.fence_i(fence_i_out_lsu)
	);
	
	ysyx_25040129_IFU u_ysyx_25040129_IFU (
		.pc(pc_from_ifu),
		.pipeline_flush(pipeline_flush_signal),
		.pipeline_flush_target(flush_reset_pc),
	
		.inst_to_idu(inst_to_idu),
		.is_req_valid_to_idu(is_req_valid_from_ifu_to_idu),
		
		.is_req_ready_from_idu(is_req_ready_from_pipeline_idu_to_ifu),
		
		.rst(rst),
		.clk(clk),

		.araddr(araddr_from_ifu),
		.arvalid(arvalid_from_ifu),
		.arready(rready_to_ifu),

		.rdata(rdata_to_ifu),
		.rresp(rresp_to_ifu),
		.rvalid(rvalid_to_ifu),
		.rready(rready_from_ifu)
	);


	ysyx_25040129_PIPELINE #(64) u_ysyx_25040129_PIPELINE_IFU_TO_IDU(
		.clk(clk),
		.rst(rst),
		.pipeline_flush(pipeline_flush_signal), 

		.in_valid(is_req_valid_from_ifu_to_idu),
		.in_ready(is_req_ready_from_pipeline_idu_to_ifu),
		.in_data({pc_from_ifu, inst_to_idu}),

		.out_valid(is_req_valid_from_pipeline_ifu_to_idu),
		.out_ready(is_req_ready_from_idu_to_ifu),
		.out_data({pc_from_ifu_pip, inst_to_idu_pip})
	);
	
	ysyx_25040129_IDU u_ysyx_25040129_IDU (
		.inst(inst_to_idu_pip),
		.pc(pc_from_ifu_pip),
		.src1_id(src1_id_out_idu),
		.src2_id(src2_id_out_idu),
		.csr_read_id_out_idu(csr_read_id_out_idu),
		.csr_write_id_out_idu(csr_write_id_out_idu),
		.src1_in_idu_reg(src1_in_idu),
		.src2_in_idu_reg(src2_in_idu),
		.lsu_write_data_out_idu(lsu_write_data_out_idu),
		.csr_in_idu(csr_in_idu),

		`ifdef ysyx_25040129_DEBUG
		.inst_out_idu(debug_inst_out_idu),
		`endif
	
		.pc_out_idu(pc_out_idu),
		.src1_out_idu(src1_out_idu),
		.src2_out_idu(src2_out_idu),
		
		.imm(imm),
		.rd_out_idu(rd_out_idu),
		.alu_opcode(alu_opcode),
		.reg_write_out_idu(reg_write_out_idu),
		.is_jalr_out_idu(is_jalr_out_idu),
		.lsu_write_out_idu(lsu_write_out_idu),
		.lsu_read_out_idu(lsu_read_out_idu),
		.ecall_out_idu(ecall_out_idu),
		.is_jump_out_idu(is_jump_out_idu),
		.ebreak_out_idu(ebreak_out_idu),
		.mret_out_idu(mret_out_idu),

		.csr_write_out_idu(csr_write_out_idu),

		.is_req_valid_from_ifu(is_req_valid_from_pipeline_ifu_to_idu),
		.is_req_ready_to_ifu(is_req_ready_from_idu_to_ifu),
		.is_req_valid_to_exu(is_req_valid_from_idu_to_exu),
		.is_req_ready_from_exu(is_req_ready_from_pipline_exu_to_idu),
		.fence_i(fence_i_out_idu),

		.rd_idu_pip_exu(rd_out_idu_pip),
		.valid_rd_write_idu_pip_exu(reg_write_out_idu_pip & is_req_valid_from_pipeline_idu_to_exu),
		.csr_addr_idu_pip_exu(csr_write_id_out_idu_pip),
		.valid_csr_addr_write_idu_pip_exu(csr_write_out_idu_pip & is_req_valid_from_pipeline_idu_to_exu),

		.rd_exu_pip_lsu(rd_out_exu_pip),
		.valid_rd_write_exu_pip_lsu(reg_write_out_exu_pip & is_req_valid_from_pipeline_exu_to_lsu),
		.csr_addr_exu_pip_lsu(csr_addr_out_exu_pip),
		.valid_csr_addr_write_exu_pip_lsu(csr_write_out_exu_pip & is_req_valid_from_pipeline_exu_to_lsu),

		.rd_lsu_pip_wbu(rd_out_lsu_pip),
		.valid_rd_write_lsu_pip_wbu(reg_write_out_lsu_pip & is_req_valid_from_pipeline_lsu_to_wbu),
		.csr_addr_lsu_pip_wbu(csr_addr_out_lsu_pip),
		.valid_csr_addr_write_lsu_pip_wbu(csr_write_out_lsu_pip & is_req_valid_from_pipeline_lsu_to_wbu),

		.exu_forward_data(data_forward_from_exu),
		.is_exu_forward_valid(is_data_forward_valid_from_exu),
		.lsu_forward_data(data_forward_from_lsu),
		.is_lsu_forward_valid(is_data_forward_valid_from_lsu),
		.wbu_forward_data(data_forward_from_wbu),
		.is_wbu_forward_valid(is_data_forward_valid_from_wbu)
	);
	

	ysyx_25040129_PIPELINE #(184
	`ifdef ysyx_25040129_DEBUG
		+ 32 // debug_inst_out_idu
	`endif
	) u_ysyx_25040129_PIPELINE_IDU_TO_EXU(
		.clk(clk),
		.rst(rst),
		.pipeline_flush(pipeline_flush_signal), 

		.in_valid(is_req_valid_from_idu_to_exu),
		.in_ready(is_req_ready_from_pipline_exu_to_idu),

		.in_data({pc_out_idu, src1_out_idu, src2_out_idu,
			imm, lsu_write_data_out_idu, alu_opcode, rd_out_idu,
			is_jalr_out_idu, is_jump_out_idu, reg_write_out_idu,
			csr_write_out_idu, lsu_write_out_idu, lsu_read_out_idu,
			ecall_out_idu, ebreak_out_idu, mret_out_idu,fence_i_out_idu,csr_write_id_out_idu
		`ifdef ysyx_25040129_DEBUG
			, debug_inst_out_idu
		`endif
		}),

		.out_valid(is_req_valid_from_pipeline_idu_to_exu),
		.out_ready(is_req_ready_from_exu_to_idu),
		.out_data({pc_from_idu_pip, src1_out_idu_pip, src2_out_idu_pip,
			imm_pip, lsu_write_data_out_idu_pip, alu_opcode_pip, rd_out_idu_pip,
			is_jalr_out_idu_pip, is_jump_out_idu_pip, reg_write_out_idu_pip,
			csr_write_out_idu_pip, lsu_write_out_idu_pip, lsu_read_out_idu_pip,
			ecall_out_idu_pip, ebreak_out_idu_pip, mret_out_idu_pip,fence_i_out_idu_pip,csr_write_id_out_idu_pip
		`ifdef ysyx_25040129_DEBUG
			, debug_inst_out_idu_pip
		`endif
		})
	);

	
	ysyx_25040129_REG u_ysyx_25040129_REG (
		.clk(clk),
		.rst(rst),
		.rd(rd_out_wbu),
		.reg_write(reg_write_out_wbu),
		`ifdef __ICARUS__
		.a0(a0),
		`endif
		.result(result_out_wbu),
		.src1_id(src1_id_out_idu),
		.src2_id(src2_id_out_idu),
		.src1(src1_in_idu),
		.src2(src2_in_idu)
	);

	ysyx_25040129_CSR u_ysyx_25040129_CSR (
		.clk(clk),
		.rst(rst),
		.csr_write(csr_write_out_wbu),
		.csr_read_addr(csr_read_id_out_idu),
		.csr_write_addr(csr_addr_out_wbu),
		.csr_data(result_out_wbu),
		.csr_out(csr_in_idu)
	);
	
	ysyx_25040129_EXU u_ysyx_25040129_EXU (
		.pc(pc_from_idu_pip),
		.src1(src1_out_idu_pip),
		.src2(src2_out_idu_pip),
		.imm(imm_pip),
		.alu_opcode(alu_opcode_pip),
		.result_out_exu(result_out_exu),

		`ifdef ysyx_25040129_DEBUG
		.pc_out_exu(debug_pc_from_exu_to_lsu),
		.inst_in_exu(debug_inst_out_idu_pip),
		.inst_out_exu(debug_inst_from_exu_to_lsu),
		`endif

		.is_jalr_in_exu(is_jalr_out_idu_pip),

		.lsu_write_data_in_exu(lsu_write_data_out_idu_pip),
		.lsu_write_data_out_exu(lsu_write_data_out_exu),
		.branch_target_out_exu(branch_target_out_exu),

		.ebreak_in_exu(ebreak_out_idu_pip),
		.rd_in_exu(rd_out_idu_pip),
		.csr_write_in_exu(csr_write_out_idu_pip),
		.csr_write_addr_in_exu(csr_write_id_out_idu_pip),
		.ecall_in_exu(ecall_out_idu_pip),
		.mret_in_exu(mret_out_idu_pip),
		.reg_write_in_exu(reg_write_out_idu_pip),

		.ebreak_out_exu(ebreak_out_exu),
		.rd_out_exu(rd_out_exu),
		.csr_write_out_exu(csr_write_out_exu),
		.csr_write_addr_out_exu(csr_addr_out_exu),
		.ecall_out_exu(ecall_out_exu),
		.mret_out_exu(mret_out_exu),
		.reg_write_out_exu(reg_write_out_exu),

		.lsu_read_in_exu(lsu_read_out_idu_pip),
		.lsu_write_in_exu(lsu_write_out_idu_pip),
		.lsu_read_out_exu(lsu_read_out_exu),
		.lsu_write_out_exu(lsu_write_out_exu),
		.is_jump_in_exu(is_jump_out_idu_pip),
		.is_branch_out_exu(is_branch_out_exu),
		.is_req_valid_from_idu(is_req_valid_from_pipeline_idu_to_exu),
		.is_req_ready_to_idu(is_req_ready_from_exu_to_idu),
		.is_req_valid_to_lsu(is_req_valid_from_exu_to_lsu),
		.is_req_ready_from_lsu(is_req_ready_from_pipeline_lsu_to_exu),
		.fence_i_in_exu(fence_i_out_idu_pip),
		.fence_i_out_exu(fence_i_out_exu),

		.is_data_forward_valid_from_exu(is_data_forward_valid_from_exu)
	);
	
	ysyx_25040129_PIPELINE #(115
	`ifdef ysyx_25040129_DEBUG
		+ 64
	`endif
	) u_ysyx_25040129_PIPELINE_EXU_TO_LSU(
		.clk(clk),
		.rst(rst),
		.pipeline_flush(pipeline_flush_signal), 

		.in_valid(is_req_valid_from_exu_to_lsu),
		.in_ready(is_req_ready_from_pipeline_lsu_to_exu),

		.in_data({lsu_read_out_exu, lsu_write_out_exu, branch_target_out_exu,
			result_out_exu, lsu_write_data_out_exu, rd_out_exu,ecall_out_exu,
			mret_out_exu, is_branch_out_exu, csr_write_out_exu,ebreak_out_exu,
			reg_write_out_exu, fence_i_out_exu,csr_addr_out_exu
		`ifdef ysyx_25040129_DEBUG
			, debug_pc_from_exu_to_lsu
			, debug_inst_from_exu_to_lsu
		`endif
		}),
		.out_valid(is_req_valid_from_pipeline_exu_to_lsu),
		.out_ready(is_req_ready_from_lsu_to_exu),
		.out_data({lsu_read_out_exu_pip, lsu_write_out_exu_pip, branch_target_out_exu_pip,
			result_out_exu_pip, lsu_write_data_out_exu_pip, rd_out_exu_pip, ecall_out_exu_pip,
			mret_out_exu_pip, is_branch_out_exu_pip, csr_write_out_exu_pip,ebreak_out_exu_pip,
			reg_write_out_exu_pip, fence_i_out_exu_pip,csr_addr_out_exu_pip
		`ifdef ysyx_25040129_DEBUG
			, debug_pc_from_exu_to_lsu_pip
			, debug_inst_from_exu_to_lsu_pip
		`endif
		})
	);
	
	ysyx_25040129_LSU u_ysyx_25040129_LSU (
		.clk(clk),
		.rst(rst),

		`ifdef ysyx_25040129_DEBUG
		.pc_in_lsu(debug_pc_from_exu_to_lsu_pip),
		.pc_out_lsu(debug_pc_from_lsu_to_wbu),
		.inst_in_lsu(debug_inst_from_exu_to_lsu_pip),
		.inst_out_lsu(debug_inst_from_lsu_to_wbu),
		`endif

		`ifdef ysyx_25040129_DEBUG
		.is_device(debug_is_device_lsu_to_wbu),
		`endif
		
		.mmem_read_in_lsu(lsu_read_out_exu_pip),
		.mmem_write_in_lsu(lsu_write_out_exu_pip),
		.branch_target_in_lsu(branch_target_out_exu_pip),
		.branch_target_out_lsu(branch_target_out_lsu),

		.result_in_lsu(result_out_exu_pip),
		.result_out_lsu(result_out_lsu), 

		.is_req_valid_from_exu(is_req_valid_from_pipeline_exu_to_lsu),
		.is_req_ready_to_exu(is_req_ready_from_lsu_to_exu),
		.mmem_write_data_in_lsu(lsu_write_data_out_exu_pip),

		.araddr(araddr_from_lsu),
		.arvalid(arvalid_from_lsu),
		.arready(rready_to_lsu),
		.arsize(arsize_from_lsu),

		.rdata(rdata_to_lsu),
		.rresp(rresp_to_lsu),
		.rvalid(rvalid_to_lsu),
		.rready(rready_from_lsu),

		.awaddr(awaddr_from_lsu),
		.awvalid(awvalid_from_lsu),
		.awready(awready_to_lsu),

		.wstrb(wstrb_from_lsu),
		.wdata(wdata_from_lsu),
		.wvalid(wvalid_from_lsu),
		.wready(wready_to_lsu),

		.bresp(bresp_to_lsu),
		.bvalid(bvalid_to_lsu),
		.bready(bready_from_lsu),

		.is_req_valid_to_wbu(is_req_valid_from_lsu_to_wbu),
		.is_req_ready_from_wbu(is_req_ready_from_pipeline_wbu_to_lsu),

		.reg_write_in_lsu(reg_write_out_exu_pip),
		.reg_write_out_lsu(reg_write_out_lsu),
		.csr_write_in_lsu(csr_write_out_exu_pip),
		.csr_write_out_lsu(csr_write_out_lsu),
		.ecall_in_lsu(ecall_out_exu_pip),
		.ecall_out_lsu(ecall_out_lsu),
		.rd_in_lsu(rd_out_exu_pip),
		.rd_out_lsu(rd_out_lsu),
		.csr_addr_in_lsu(csr_addr_out_exu_pip),
		.csr_addr_out_lsu(csr_addr_out_lsu),
		.mret_in_lsu(mret_out_exu_pip),
		.mret_out_lsu(mret_out_lsu),
		.ebreak_in_lsu(ebreak_out_exu_pip),
		.ebreak_out_lsu(ebreak_out_lsu),
		.is_branch_in_lsu(is_branch_out_exu_pip),
		.is_branch_out_lsu(is_branch_out_lsu),
		.fence_i_in_lsu(fence_i_out_exu_pip),
		.fence_i_out_lsu(fence_i_out_lsu),

		.is_data_forward_valid_from_lsu(is_data_forward_valid_from_lsu)
	);
	//当信号从LSU中发出，并被声明为valid时，开始考虑流水线冲刷
	//什么情况下需要冲刷呢？
	//1. 发生跳转/分支成立
	//2. 抛出异常相关
	//3. fence.i指令
	//4. 发生数据冒险
	
	ysyx_25040129_PIPELINE #(42
	`ifdef ysyx_25040129_DEBUG
		+ 65
	`endif
	) u_ysyx_25040129_PIPELINE_LSU_TO_WBU(
		.clk(clk),
		.rst(rst),
		.pipeline_flush(1'b0), 

		.in_valid(is_req_valid_from_lsu_to_wbu),
		.in_ready(is_req_ready_from_pipeline_wbu_to_lsu),

		.in_data({result_out_lsu,rd_out_lsu,
		reg_write_out_lsu,csr_write_out_lsu,ebreak_out_lsu,
		`ifdef ysyx_25040129_DEBUG
		debug_pc_from_lsu_to_wbu,
		debug_inst_from_lsu_to_wbu,
		debug_is_device_lsu_to_wbu,
		`endif
		csr_addr_out_lsu}),

		.out_valid(is_req_valid_from_pipeline_lsu_to_wbu),
		.out_ready(is_req_ready_from_wbu_to_lsu),
		.out_data({result_out_lsu_pip,rd_out_lsu_pip,
		reg_write_out_lsu_pip,csr_write_out_lsu_pip,ebreak_out_lsu_pip,
		`ifdef ysyx_25040129_DEBUG
		debug_pc_from_lsu_to_wbu_pip,
		debug_inst_from_lsu_to_wbu_pip,
		debug_is_device_lsu_to_wbu_pip,
		`endif
		csr_addr_out_lsu_pip})
	);

	

	ysyx_25040129_WBU u_ysyx_25040129_WBU (
		`ifdef ysyx_25040129_DEBUG
		.pc_in_wbu(debug_pc_from_lsu_to_wbu_pip),
		.inst_in_wbu(debug_inst_from_lsu_to_wbu_pip),
		.is_device_in_wbu(debug_is_device_lsu_to_wbu_pip),
		`endif
		.is_req_valid_from_lsu(is_req_valid_from_pipeline_lsu_to_wbu),
		.is_req_ready_to_lsu(is_req_ready_from_wbu_to_lsu),
		.rd_in_wbu(rd_out_lsu_pip),
		.result_in_wbu(result_out_lsu_pip),
		.csr_addr_in_wbu(csr_addr_out_lsu_pip),
		.csr_write_in_wbu(csr_write_out_lsu_pip),
		.reg_write_in_wbu(reg_write_out_lsu_pip),
		.rd_out_wbu(rd_out_wbu),
		.result_out_wbu(result_out_wbu),
		.csr_write_out_wbu(csr_write_out_wbu),
		.csr_addr_out_wbu(csr_addr_out_wbu),
		.reg_write_out_wbu(reg_write_out_wbu),
		.ebreak_in_wbu(ebreak_out_lsu_pip),
		`ifdef __ICARUS__
		.a0(a0),
		`endif
		.is_data_forward_valid_from_wbu(is_data_forward_valid_from_wbu),
		.wbu_forward_data(data_forward_from_wbu)

	);


endmodule/*verilator lint_on DECLFILENAME*/

