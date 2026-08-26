

// ███████╗ ██╗  ██╗ ██╗   ██╗
// ██╔════╝ ╚██╗██╔╝ ██║   ██║
// █████╗    ╚███╔╝  ██║   ██║
// ██╔══╝    ██╔██╗  ██║   ██║
// ███████╗ ██╔╝ ██╗ ╚██████╔╝
// ╚══════╝ ╚═╝  ╚═╝  ╚═════╝
`include "csr_defines.v"
module ysyx_26010011_EXU(
/* verilator lint_off UNUSEDSIGNAL */
	input            clock,
	input            reset,
	input            flush_valid,
/* verilator lint_on UNUSEDSIGNAL */

	input            exu_in_valid,
	input      [ 4:0]exu_in_bus_exception,
	output           exu_in_ready,
	input      [31:0]exu_in_bus_a,
	input      [31:0]exu_in_bus_b,
	input      [31:0]exu_in_bus_pc,
	input      [31:0]exu_in_bus_imm,
	input      [ 3:0]exu_in_bus_alu_op,
	input      [ 1:0]exu_in_bus_comp_op,
	input            exu_in_bus_isJUMP,
	input            exu_in_bus_isBRANCH,
	input      [ 2:0]exu_in_bus_opCSR,
	input            exu_in_bus_isUnSigned,
	input            exu_in_bus_isUsePC,//PC+imm
	input            exu_in_bus_alu_isUseImm,//imm
	input            exu_in_bus_comp_isUseImm,//imm
	input 		  	 exu_in_bus_isWGPR,
	input 		  	 exu_in_bus_isLOAD,
	input 		  	 exu_in_bus_isWCOMP,

	output           exu_out_valid,
	output reg [ 4:0]exu_out_bus_exception,
	input            exu_out_ready,
	output reg [31:0]exu_out_bus_gpr_wdata,
	output reg [31:0]exu_out_bus_csr_result,
	
	output reg [31:0]exu_out_bus_alu_result,
	output 		     exu_out_bus_opCSR,
`ifdef USE_VERILATOR
	output 		     dbg_exu_out_bus_comp_result,
`endif

	output reg       exu_out_bus_dnpc_valid,
	output           exu_out_bus_rd_valid,
	output           exu_out_bus_bypass_valid,
	output           exu_out_bus_csr_valid
);
	reg        exu_out_bus_comp_result;
	wire [31:0]a,b,comp_a,comp_b;
	wire [31:0]op_xor;
	wire [31:0]op_or;
	wire [31:0]op_and;
	wire [31:0]op_ar;
	wire [31:0]op_lr;
	wire [31:0]op_ll;
	wire [31:0]op_adder;
	wire comp_isEQUAL,comp_isGREATER,comp_suber_carry;
	wire [31:0]comp_suber_out;

	assign a=(exu_in_bus_alu_isUseImm)?(exu_in_bus_isUsePC?exu_in_bus_pc:exu_in_bus_a):exu_in_bus_a;
	assign b=(exu_in_bus_alu_isUseImm)?exu_in_bus_imm:exu_in_bus_b;
	assign comp_a=exu_in_bus_a;
	assign comp_b=(exu_in_bus_comp_isUseImm)?exu_in_bus_imm:exu_in_bus_b;

	assign exu_in_ready = exu_out_ready;
	assign exu_out_valid = exu_in_valid;
	
	assign op_xor=a^b;
	assign op_or=a|b;
	assign op_and=a&b;
	assign op_ar=$signed(a) >>> (b & 32'h1f);
	assign op_lr=a >> (b & 32'h1f);
	assign op_ll=a << (b & 32'h1f);
	assign op_adder = (exu_in_bus_alu_op==4'd2)?(a-b):(a+b);

	assign exu_out_bus_rd_valid = exu_in_valid && exu_in_bus_isWGPR;
	assign exu_out_bus_bypass_valid = exu_out_valid && exu_in_bus_isWGPR && !exu_in_bus_isLOAD;
	assign exu_out_bus_csr_valid = exu_in_valid && exu_out_bus_opCSR;

	
	always @(*) begin
		case (exu_in_bus_alu_op)
			4'd1: exu_out_bus_alu_result=op_adder;
			4'd2: exu_out_bus_alu_result=op_adder;
			4'd3: exu_out_bus_alu_result=op_ll;
			4'd4: exu_out_bus_alu_result=op_lr;
			4'd5: exu_out_bus_alu_result=op_ar;
			4'd6: exu_out_bus_alu_result=op_and;
			4'd7: exu_out_bus_alu_result=op_or;
			4'd8: exu_out_bus_alu_result=op_xor;
			default: exu_out_bus_alu_result=b;
		endcase
	end
	always @(*) begin
		if     (exu_in_bus_opCSR[1:0] == 2'b10) exu_out_bus_csr_result=op_and;
		else if(exu_in_bus_opCSR[1:0] == 2'b01) exu_out_bus_csr_result=op_or;
		else                                    exu_out_bus_csr_result=exu_in_bus_a;
	end
	
	assign {comp_suber_carry,comp_suber_out} = {1'b0,comp_a} + (~{1'b0,comp_b}) + 1;
	assign comp_isEQUAL = (comp_suber_out == 32'b0);
	assign comp_isGREATER = (exu_in_bus_isUnSigned)?((!comp_isEQUAL) && !comp_suber_carry):((!comp_a[31] && comp_b[31]) || ((comp_a[31] ~^ comp_b[31])  && !comp_suber_out[31]));
	always @(*) begin
		case (exu_in_bus_comp_op)
			2'b00: exu_out_bus_comp_result=comp_isEQUAL | comp_isGREATER;
			2'b01: exu_out_bus_comp_result=!(comp_isEQUAL | comp_isGREATER);
			2'b10: exu_out_bus_comp_result=!comp_isEQUAL;
			2'b11: exu_out_bus_comp_result=comp_isEQUAL;
		endcase
	end

	always @(*) begin
		if(exu_in_bus_exception[4]) begin
			exu_out_bus_dnpc_valid = 0;
			exu_out_bus_exception = exu_in_bus_exception;
		end else if(exu_in_valid & exu_in_ready) begin
			if( exu_in_bus_isJUMP | (exu_in_bus_isBRANCH & exu_out_bus_comp_result) ) begin
				if(|exu_out_bus_alu_result[1:0]) begin
					exu_out_bus_dnpc_valid = 0;
					exu_out_bus_exception = {1'b1,`ysyx_26010011_EXCEPTION_MISALIGNED_FETCH};
				end else begin
					exu_out_bus_dnpc_valid = 1;
					exu_out_bus_exception = exu_in_bus_exception;
				end
			end else begin
				exu_out_bus_dnpc_valid = 0;
				exu_out_bus_exception = exu_in_bus_exception;
			end
		end else begin
			exu_out_bus_dnpc_valid = 0;
			exu_out_bus_exception = exu_in_bus_exception;
		end
	end

	always @(*) begin
		if(exu_in_bus_isJUMP) begin
			exu_out_bus_gpr_wdata = exu_in_bus_pc + 4;
		end else if(exu_in_bus_isWCOMP) begin
			exu_out_bus_gpr_wdata = {31'b0,exu_out_bus_comp_result};
		end else begin
			exu_out_bus_gpr_wdata = exu_out_bus_alu_result;
		end
	end
	assign exu_out_bus_opCSR = |exu_in_bus_opCSR;

`ifdef USE_VERILATOR
	assign dbg_exu_out_bus_comp_result = exu_out_bus_comp_result;
`endif
endmodule
