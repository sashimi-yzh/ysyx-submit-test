

//  ██████╗  ██████╗  ██████╗
// ██╔════╝  ██╔══██╗ ██╔══██╗
// ██║  ███╗ ██████╔╝ ██████╔╝
// ██║   ██║ ██╔═══╝  ██╔══██╗
// ╚██████╔╝ ██║      ██║  ██║
//  ╚═════╝  ╚═╝      ╚═╝  ╚═╝
`ifdef USE_VERILATOR
import "DPI-C" function void difftest_skip_ref(int reason);
`endif
`include "csr_defines.v"
module ysyx_26010011_GPRs(
	input        clock,
	input        reset,
	input  [ 3:0]gpr_in_addra,
	input  [ 3:0]gpr_in_addrb,
	output reg [31:0]gpr_out_a,
	output reg [31:0]gpr_out_b,
	input  [ 3:0]gpr_in_addw,
	input  [31:0]gpr_in_data,
	input        gpr_in_wen
); 
 	reg [31:0]GPR[0:15]/* verilator public */;

	// assign gpr_out_a=GPR[gpr_in_addra[3:0]];
	// assign gpr_out_b=GPR[gpr_in_addrb[3:0]];
	always @(*) begin
		case (gpr_in_addra[3:0])
			4'h0: gpr_out_a = 32'b0;
			4'h1: gpr_out_a = GPR[1];
			4'h2: gpr_out_a = GPR[2];
			4'h3: gpr_out_a = GPR[3];
			4'h4: gpr_out_a = GPR[4];
			4'h5: gpr_out_a = GPR[5];
			4'h6: gpr_out_a = GPR[6];
			4'h7: gpr_out_a = GPR[7];
			4'h8: gpr_out_a = GPR[8];
			4'h9: gpr_out_a = GPR[9];
			4'ha: gpr_out_a = GPR[10];
			4'hb: gpr_out_a = GPR[11];
			4'hc: gpr_out_a = GPR[12];
			4'hd: gpr_out_a = GPR[13];
			4'he: gpr_out_a = GPR[14];
			4'hf: gpr_out_a = GPR[15];
			default: gpr_out_a = 32'b0;
		endcase
	end
	always @(*) begin
		case (gpr_in_addrb[3:0])
			4'h0: gpr_out_b = 32'b0;
			4'h1: gpr_out_b = GPR[1];
			4'h2: gpr_out_b = GPR[2];
			4'h3: gpr_out_b = GPR[3];
			4'h4: gpr_out_b = GPR[4];
			4'h5: gpr_out_b = GPR[5];
			4'h6: gpr_out_b = GPR[6];
			4'h7: gpr_out_b = GPR[7];
			4'h8: gpr_out_b = GPR[8];
			4'h9: gpr_out_b = GPR[9];
			4'ha: gpr_out_b = GPR[10];
			4'hb: gpr_out_b = GPR[11];
			4'hc: gpr_out_b = GPR[12];
			4'hd: gpr_out_b = GPR[13];
			4'he: gpr_out_b = GPR[14];
			4'hf: gpr_out_b = GPR[15];
			default: gpr_out_b = 32'b0;
		endcase
	end

	integer i;
	always @(posedge clock) begin
		if(reset) begin
			// GPR[0]<={32{1'b0}};
			for(i=0;i<16;i=i+1) begin
				GPR[i]<={32{1'b0}};
			end
		end else begin
			if(gpr_in_wen && gpr_in_addw != 4'b0000) begin
				GPR[gpr_in_addw[3:0]]<=(gpr_in_data);
			end
		end
	end
endmodule


// ██████╗  ███████╗ ██████╗
// ██╔════╝ ██╔════╝ ██╔══██╗
// ██║      ███████╗ ██████╔╝
// ██║      ╚════██║ ██╔══██╗
// ╚██████╗ ███████║ ██║  ██║
//  ╚═════╝ ╚══════╝ ╚═╝  ╚═╝
module ysyx_26010011_CSRs(
	input            clock,
	input            reset,

	input      [11:0]csr_in_addr,
	output reg [31:0]csr_out_data,
	input [31:0]mcycle,
	input [15:0]mcycleh,
	input      [31:0]csr_pc,
	input      [31:0]csr_in_data,
	input            csr_in_wen,
	input      [11:0]csr_in_addw,

	output     [31:0]csr_mtvec,
	output     [31:0]csr_mepc,
	
	input [4:0]csr_in_bus_exception
);
	reg [31:0]CSR_MTVEC/* verilator public */;
	reg [31:0]CSR_MEPC/* verilator public */;
	reg [3:0]CSR_MCAUSE/* verilator public */;
	localparam [31:0]CSR_MVENDORID=32'h79737978;
	localparam [31:0]CSR_MSTATUS=32'h00001800;
	localparam [31:0]CSR_MARCHID=32'h018ce19b;

	always @(*) begin
		case(csr_in_addr)
			`ysyx_26010011_ADD_MCYCLE:   	csr_out_data = mcycle;
			`ysyx_26010011_ADD_MCYCLEH:   	csr_out_data = {16'b0,mcycleh};
			`ysyx_26010011_ADD_MTVEC:   	csr_out_data = CSR_MTVEC;
			`ysyx_26010011_ADD_MEPC:   		csr_out_data = CSR_MEPC;
			`ysyx_26010011_ADD_MCAUSE:   	csr_out_data = {28'b0,CSR_MCAUSE};
			`ysyx_26010011_ADD_MVENDORID:   csr_out_data = CSR_MVENDORID;
			`ysyx_26010011_ADD_MSTATUS:   	csr_out_data = CSR_MSTATUS;
			`ysyx_26010011_ADD_MARCHID:   	csr_out_data = CSR_MARCHID;
			default:      					csr_out_data = 32'h0;
		endcase
	end

	always @(posedge clock) begin
		if(reset) begin
			// CSR_MTVEC <= 32'h0;
			// CSR_MEPC <= 0;
		end else begin
			if(csr_in_bus_exception[4]) begin
				if(csr_in_bus_exception[3:0] != `ysyx_26010011_EXCEPTION_MRET) begin
					CSR_MEPC    <= csr_pc;
					CSR_MCAUSE  <= {csr_in_bus_exception[3:0]};
				end
			end else if(csr_in_wen) begin
				case (csr_in_addw)
					`ysyx_26010011_ADD_MTVEC:      CSR_MTVEC   <= csr_in_data;
					`ysyx_26010011_ADD_MEPC:       CSR_MEPC    <= csr_in_data;
					`ysyx_26010011_ADD_MCAUSE:     CSR_MCAUSE  <= csr_in_data[3:0];
					default:;
				endcase
			end
		end
	end
	assign csr_mepc  = CSR_MEPC;
	assign csr_mtvec = CSR_MTVEC;

`ifdef USE_VERILATOR
	always @(*) begin
		if (csr_in_wen & ((csr_in_addw==`ysyx_26010011_ADD_MCYCLE) | (csr_in_addw==`ysyx_26010011_ADD_MCYCLEH))) begin
			difftest_skip_ref(32'h89898989);
		end
	end
`endif
endmodule
