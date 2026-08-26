

// ██╗    ██╗ ██████╗  ██╗   ██╗
// ██║    ██║ ██╔══██╗ ██║   ██║
// ██║ █╗ ██║ ██████╔╝ ██║   ██║
// ██║███╗██║ ██╔══██╗ ██║   ██║
// ╚███╔███╔╝ ██████╔╝ ╚██████╔╝
//  ╚══╝╚══╝  ╚═════╝   ╚═════╝
module ysyx_26010011_WBU(
/* verilator lint_off UNUSEDSIGNAL */
	input clock,
	input reset,
	input flush_valid,
/* verilator lint_on UNUSEDSIGNAL */
	input wbu_in_valid,
	output wbu_in_ready,
	
	input [31:0]wbu_in_bus_csr_result,
	input [31:0]wbu_in_bus_gpr_wdata,
	
	input [3:0]wbu_in_bus_rd,
	input [11:0]wbu_in_bus_csrrd,
	input wbu_in_bus_isWGPR,
	input wbu_in_bus_opCSR,
	input [4:0]wbu_in_bus_exception,

	output wbu_out_bus_rd_valid,
	output wbu_out_bus_bypass_valid,
	output wbu_out_bus_csr_valid,
	output [3:0]wbu_out_bus_rd,
	output [11:0]wbu_out_bus_csrrd,
	output reg [31:0]wbu_out_bus_gpr_wdata,

	output gpr_we,
	output [31:0]gpr_wdata,
	output [3:0]gpr_address,

	output csr_we,
	output [31:0]csr_wdata,
	output [11:0]csr_address,
	output [4:0]wbu_out_bus_exception,
	output fencei_pass
);  
	assign wbu_out_bus_gpr_wdata = wbu_in_bus_gpr_wdata;
	assign wbu_in_ready=1;

	assign wbu_out_bus_rd_valid = wbu_in_valid & wbu_in_bus_isWGPR;
	assign wbu_out_bus_bypass_valid = wbu_in_valid & wbu_in_bus_isWGPR ;
	assign wbu_out_bus_csr_valid = wbu_in_valid & wbu_in_bus_opCSR;
	assign wbu_out_bus_rd = wbu_in_bus_rd;
	assign wbu_out_bus_csrrd = wbu_in_bus_csrrd;

	assign gpr_wdata = wbu_in_bus_gpr_wdata;
	wire is_not_exception;
	assign is_not_exception = !wbu_in_bus_exception[4];
	assign gpr_address=wbu_in_bus_rd;
	assign gpr_we=(wbu_in_bus_isWGPR & wbu_in_valid & is_not_exception);
	
	assign wbu_out_bus_exception=(wbu_in_valid)?wbu_in_bus_exception:5'b0;
	assign fencei_pass = (wbu_in_valid & is_not_exception & (wbu_in_bus_exception[3:0]==`ysyx_26010011_EXCEPTION_FENCEI));

	assign csr_address=wbu_in_bus_csrrd;
	assign csr_we=(wbu_in_bus_opCSR & wbu_in_valid & is_not_exception);
	assign csr_wdata=wbu_in_bus_csr_result;
endmodule
