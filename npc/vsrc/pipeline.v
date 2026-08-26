

// ██████╗  ██╗ ██████╗  ███████╗ ██╗      ██╗ ███╗   ██╗ ███████╗
// ██╔══██╗ ██║ ██╔══██╗ ██╔════╝ ██║      ██║ ████╗  ██║ ██╔════╝
// ██████╔╝ ██║ ██████╔╝ █████╗   ██║      ██║ ██╔██╗ ██║ █████╗
// ██╔═══╝  ██║ ██╔═══╝  ██╔══╝   ██║      ██║ ██║╚██╗██║ ██╔══╝
// ██║      ██║ ██║      ███████╗ ███████╗ ██║ ██║ ╚████║ ███████╗
// ╚═╝      ╚═╝ ╚═╝      ╚══════╝ ╚══════╝ ╚═╝ ╚═╝  ╚═══╝ ╚══════╝
//////////反压优化
module ysyx_26010011_IF_ID_pipeline(
	input            clock,
	input            reset,
	input            flush_valid,

	input            ifu_out_valid,
	output           ifu_out_ready,
	input      [31:0]ifu_out_bus_instruction,
	input      [31:0]ifu_out_bus_pc,
	input      [ 4:0]ifu_out_bus_exception,
	output reg       idu_in_valid/*verilator public*/,
	input            idu_in_ready,
	output reg [31:0]idu_in_bus_instruction,
	output reg [31:0]idu_in_bus_pc/*verilator public*/,
	output reg [ 4:0]idu_in_bus_exception
);
	assign ifu_out_ready = idu_in_ready | !idu_in_valid;
	always @(posedge clock)begin
		if(reset | flush_valid) begin
			idu_in_valid <= 0;
		end else if(idu_in_ready | !idu_in_valid)begin
			idu_in_valid <= ifu_out_valid;
			idu_in_bus_instruction <= ifu_out_bus_instruction;
			idu_in_bus_pc <= ifu_out_bus_pc;
			idu_in_bus_exception <= ifu_out_bus_exception;
		end
	end
endmodule

module ysyx_26010011_ID_EX_pipeline(
	input            clock,
	input            reset,
	input            flush_valid,

	input            idu_out_valid,
	output           idu_out_ready,
	input      [ 3:0]idu_out_bus_rd,
	input      [ 4:0]idu_out_bus_exception,
	input      [11:0]idu_out_bus_csrrd,
	input      [31:0]idu_out_bus_rs1_val,
	input      [31:0]idu_out_bus_rs2_val,
	input      [31:0]idu_out_bus_imm,
`ifdef USE_VERILATOR
	input      [31:0]dbg_idu_out_bus_instruction,
`endif
	input            idu_out_bus_isLOAD,
	input            idu_out_bus_isSTORE,
	input            idu_out_bus_isWGPR,
	input            idu_out_bus_isJUMP,
	input            idu_out_bus_isWCOMP,
	input            idu_out_bus_isBRANCH,
	input      [ 2:0]idu_out_bus_opCSR,
	input            idu_out_bus_isUnSigned,
	input            idu_out_bus_isUsePC,
	input            idu_out_bus_alu_isUseImm,
	input            idu_out_bus_comp_isUseImm,
	input      [ 3:0]idu_out_bus_alu_op,
	input      [ 1:0]idu_out_bus_comp_op,
	input      [ 1:0]idu_out_bus_perip_mask,
	input      [31:0]idu_out_bus_pc,

	output reg       exu_in_valid/*verilator public*/,
	input            exu_in_ready,
	output reg [ 3:0]exu_in_bus_rd,
	output reg [ 4:0]exu_in_bus_exception,
	output reg [11:0]exu_in_bus_csrrd,
	output reg [31:0]exu_in_bus_rs1_val,
	output reg [31:0]exu_in_bus_rs2_val,
	output reg [31:0]exu_in_bus_imm,
`ifdef USE_VERILATOR
	output reg [31:0]dbg_exu_in_bus_instruction,
`endif
	output reg       exu_in_bus_isLOAD,
	output reg       exu_in_bus_isSTORE,
	output reg       exu_in_bus_isWGPR,
	output reg       exu_in_bus_isJUMP,
	output reg       exu_in_bus_isWCOMP,
	output reg       exu_in_bus_isBRANCH,
	output reg [ 2:0]exu_in_bus_opCSR,
	output reg       exu_in_bus_isUnSigned,
	output reg       exu_in_bus_isUsePC,
	output reg       exu_in_bus_alu_isUseImm,
	output reg       exu_in_bus_comp_isUseImm,
	output reg [ 3:0]exu_in_bus_alu_op,
	output reg [ 1:0]exu_in_bus_comp_op,
	output reg [ 1:0]exu_in_bus_perip_mask,
	output reg [31:0]exu_in_bus_pc/*verilator public*/
	// output reg [31:0]dbg_exu_in_bus_snpc
);
	assign idu_out_ready = exu_in_ready | !exu_in_valid;
	always @(posedge clock)begin
		if(reset | flush_valid) begin
			exu_in_valid<=0;
		end else if(exu_in_ready | !exu_in_valid) begin
			exu_in_valid<=idu_out_valid;
			exu_in_bus_rd<=idu_out_bus_rd;
			exu_in_bus_exception<=idu_out_bus_exception;
			exu_in_bus_csrrd<=idu_out_bus_csrrd;
			exu_in_bus_rs1_val<=idu_out_bus_rs1_val;
			exu_in_bus_rs2_val<=idu_out_bus_rs2_val;
			exu_in_bus_imm<=idu_out_bus_imm;
`ifdef USE_VERILATOR
			dbg_exu_in_bus_instruction<=dbg_idu_out_bus_instruction;
`endif
			exu_in_bus_isLOAD<=idu_out_bus_isLOAD;
			exu_in_bus_isSTORE<=idu_out_bus_isSTORE;
			exu_in_bus_isWGPR<=idu_out_bus_isWGPR;
			exu_in_bus_isJUMP<=idu_out_bus_isJUMP;
			exu_in_bus_isWCOMP<=idu_out_bus_isWCOMP;
			exu_in_bus_isBRANCH<=idu_out_bus_isBRANCH;
			exu_in_bus_opCSR<=idu_out_bus_opCSR;
			exu_in_bus_isUnSigned<=idu_out_bus_isUnSigned;
			exu_in_bus_isUsePC<=idu_out_bus_isUsePC;
			exu_in_bus_comp_isUseImm<=idu_out_bus_comp_isUseImm;
			exu_in_bus_alu_isUseImm<=idu_out_bus_alu_isUseImm;
			exu_in_bus_alu_op<=idu_out_bus_alu_op;
			exu_in_bus_comp_op<=idu_out_bus_comp_op;
			exu_in_bus_perip_mask<=idu_out_bus_perip_mask;
			exu_in_bus_pc<=idu_out_bus_pc;
		end
	end
endmodule

module ysyx_26010011_EX_LS_pipeline(
	input            clock,
	input            reset,
	input            flush_valid,

	input            exu_out_valid,
	output           exu_out_ready,
	input      [31:0]exu_out_bus_csr_result,

	input      [31:0]exu_out_bus_lsu_val,
	input      [31:0]exu_out_bus_gpr_wdata,
	input      [ 3:0]exu_out_bus_rd,
	input      [ 4:0]exu_out_bus_exception,
	input      [11:0]exu_out_bus_csrrd,
	input            exu_out_bus_isLOAD,
	input            exu_out_bus_isSTORE,
	input            exu_out_bus_isWGPR,
	input            exu_out_bus_opCSR,
	input            exu_out_bus_isUnSigned,
	input      [ 1:0]exu_out_bus_perip_mask,
	input      [31:0]exu_out_bus_pc,
`ifdef USE_VERILATOR
	input            dbg_exu_out_bus_comp_result,
	input      [31:0]dbg_exu_out_bus_alu_result,
	input      [31:0]dbg_exu_out_bus_instruction,
	input            dbg_exu_out_bus_isJUMP,
	input            dbg_exu_out_bus_isWCOMP,
	input            dbg_exu_out_bus_isBRANCH,
`endif
	output reg       lsu_in_valid/*verilator public*/,
	input            lsu_in_ready,

	output reg [31:0]lsu_in_bus_csr_result,

	output reg [31:0]lsu_in_bus_lsu_val,
	output reg [31:0]lsu_in_bus_gpr_wdata,
	output reg [ 3:0]lsu_in_bus_rd,
	output reg [ 4:0]lsu_in_bus_exception,
	output reg [11:0]lsu_in_bus_csrrd,
	
	output reg       lsu_in_bus_isLOAD,
	output reg       lsu_in_bus_isSTORE,
	output reg       lsu_in_bus_isWGPR,

	output reg       lsu_in_bus_opCSR,
	output reg       lsu_in_bus_isUnSigned,
	output reg [ 1:0]lsu_in_bus_perip_mask,
`ifdef USE_VERILATOR
	output reg [31:0]dbg_lsu_in_bus_alu_result,
	output reg       dbg_lsu_in_bus_comp_result,
	output reg [31:0]dbg_lsu_in_bus_instruction,
	output reg       dbg_lsu_in_bus_isJUMP,
	output reg       dbg_lsu_in_bus_isWCOMP,
	output reg       dbg_lsu_in_bus_isBRANCH,
`endif
	output reg [31:0]lsu_in_bus_pc/*verilator public*/
);
	assign exu_out_ready = lsu_in_ready | !lsu_in_valid;
	always @(posedge clock)begin
		if(reset | flush_valid) begin
			lsu_in_valid<=0;
		end else if(lsu_in_ready | !lsu_in_valid)begin
			lsu_in_valid<=exu_out_valid;
			lsu_in_bus_csr_result<=exu_out_bus_csr_result;
			
			lsu_in_bus_lsu_val<=exu_out_bus_lsu_val;
			lsu_in_bus_rd<=exu_out_bus_rd;
			lsu_in_bus_exception<=exu_out_bus_exception;
			lsu_in_bus_csrrd<=exu_out_bus_csrrd;
			
			lsu_in_bus_isLOAD<=exu_out_bus_isLOAD;
			lsu_in_bus_isSTORE<=exu_out_bus_isSTORE;
			lsu_in_bus_isWGPR<=exu_out_bus_isWGPR;
			
			lsu_in_bus_opCSR<=exu_out_bus_opCSR;
			lsu_in_bus_isUnSigned<=exu_out_bus_isUnSigned;
			lsu_in_bus_perip_mask<=exu_out_bus_perip_mask;
			lsu_in_bus_pc<=exu_out_bus_pc;
			lsu_in_bus_gpr_wdata<=exu_out_bus_gpr_wdata;
`ifdef USE_VERILATOR
			dbg_lsu_in_bus_alu_result<=dbg_exu_out_bus_alu_result;
			dbg_lsu_in_bus_comp_result<=dbg_exu_out_bus_comp_result;
			dbg_lsu_in_bus_instruction<=dbg_exu_out_bus_instruction;
			dbg_lsu_in_bus_isJUMP<=dbg_exu_out_bus_isJUMP;
			dbg_lsu_in_bus_isWCOMP<=dbg_exu_out_bus_isWCOMP;
			dbg_lsu_in_bus_isBRANCH<=dbg_exu_out_bus_isBRANCH;
`endif
		end
	end
endmodule

module ysyx_26010011_LS_WB_pipeline(
	input            clock,
	input            reset,
	input            flush_valid,

	input            lsu_out_valid,
	output           lsu_out_ready,

	input      [ 3:0]lsu_out_bus_rd,
	input      [ 4:0]lsu_out_bus_exception,
	input      [11:0]lsu_out_bus_csrrd,
	input	   [31:0]lsu_out_bus_gpr_wdata,
	input      [31:0]lsu_out_bus_csr_result,
`ifdef USE_VERILATOR
	input      [31:0]dbg_lsu_out_bus_alu_result,
	input            dbg_lsu_out_bus_comp_result,
	input      [31:0]dbg_lsu_out_bus_lsu_result,
	input      [31:0]dbg_lsu_out_bus_instruction,
	input            dbg_lsu_out_bus_isLOAD,
	input            dbg_lsu_out_bus_isSTORE,
	input            dbg_lsu_out_bus_isJUMP,
	input            dbg_lsu_out_bus_isWCOMP,
	input            dbg_lsu_out_bus_isBRANCH,
`endif
	input      [31:0]lsu_out_bus_pc,
	input            lsu_out_bus_isWGPR,
	input            lsu_out_bus_opCSR,

	output reg       wbu_in_valid/*verilator public*/,
	input            wbu_in_ready,

	output reg [31:0]wbu_in_bus_csr_result,
	output reg [31:0]wbu_in_bus_gpr_wdata,
	output reg [ 3:0]wbu_in_bus_rd,
	output reg [ 4:0]wbu_in_bus_exception,
	output reg [11:0]wbu_in_bus_csrrd,
	output reg       wbu_in_bus_isWGPR,
`ifdef USE_VERILATOR
	output reg [31:0]dbg_wbu_in_bus_lsu_result,
	output reg [31:0]dbg_wbu_in_bus_alu_result,
	output reg       dbg_wbu_in_bus_comp_result,
	output reg [31:0]dbg_wbu_in_bus_instruction,
	output reg       dbg_wbu_in_bus_isLOAD,
	output reg       dbg_wbu_in_bus_isSTORE,
	output reg       dbg_wbu_in_bus_isJUMP,
	output reg       dbg_wbu_in_bus_isWCOMP,
	output reg       dbg_wbu_in_bus_isBRANCH,
`endif
	output reg [31:0]wbu_in_bus_pc/*verilator public*/,
	output reg 		 wbu_in_bus_opCSR

);
	assign lsu_out_ready = wbu_in_ready | !wbu_in_valid;
	always @(posedge clock)begin
		if(reset | flush_valid) begin
			wbu_in_valid<=0; 
		end else if(wbu_in_ready | !wbu_in_valid)begin
			wbu_in_valid<=lsu_out_valid; 
			wbu_in_bus_csr_result<=lsu_out_bus_csr_result;
			wbu_in_bus_gpr_wdata<=lsu_out_bus_gpr_wdata;
			wbu_in_bus_rd<=lsu_out_bus_rd;
			wbu_in_bus_exception<=lsu_out_bus_exception;
			wbu_in_bus_csrrd<=lsu_out_bus_csrrd;
			wbu_in_bus_pc<=lsu_out_bus_pc;
`ifdef USE_VERILATOR
			
			dbg_wbu_in_bus_instruction<=dbg_lsu_out_bus_instruction;
			dbg_wbu_in_bus_lsu_result<=dbg_lsu_out_bus_lsu_result;
			dbg_wbu_in_bus_alu_result<=dbg_lsu_out_bus_alu_result;
			dbg_wbu_in_bus_comp_result<=dbg_lsu_out_bus_comp_result;
			dbg_wbu_in_bus_isLOAD<=dbg_lsu_out_bus_isLOAD;
			dbg_wbu_in_bus_isSTORE<=dbg_lsu_out_bus_isSTORE;
			dbg_wbu_in_bus_isJUMP<=dbg_lsu_out_bus_isJUMP;
			dbg_wbu_in_bus_isWCOMP<=dbg_lsu_out_bus_isWCOMP;
			dbg_wbu_in_bus_isBRANCH<=dbg_lsu_out_bus_isBRANCH;
`endif
			wbu_in_bus_isWGPR<=lsu_out_bus_isWGPR;
			wbu_in_bus_opCSR<=lsu_out_bus_opCSR;
		end
	end
endmodule
