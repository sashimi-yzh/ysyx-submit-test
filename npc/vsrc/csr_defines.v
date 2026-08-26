

// ██████╗  ███████╗ ███████╗ ██╗ ███╗   ██╗ ███████╗
// ██╔══██╗ ██╔════╝ ██╔════╝ ██║ ████╗  ██║ ██╔════╝
// ██║  ██║ █████╗   █████╗   ██║ ██╔██╗ ██║ █████╗
// ██║  ██║ ██╔══╝   ██╔══╝   ██║ ██║╚██╗██║ ██╔══╝
// ██████╔╝ ███████╗ ██║      ██║ ██║ ╚████║ ███████╗
// ╚═════╝  ╚══════╝ ╚═╝      ╚═╝ ╚═╝  ╚═══╝ ╚══════╝
`ifndef CSR_DEFINES_VH
	`define CSR_DEFINES_VH

	`define ysyx_26010011_ADD_MCYCLE    12'hb00
	`define ysyx_26010011_ADD_MCYCLEH   12'hb80
	`define ysyx_26010011_ADD_MISA      12'h301
	`define ysyx_26010011_ADD_MTVEC     12'h305
	`define ysyx_26010011_ADD_MSCRATCH  12'h340
	`define ysyx_26010011_ADD_MEPC      12'h341
	`define ysyx_26010011_ADD_MCAUSE    12'h342
	`define ysyx_26010011_ADD_MTVAL     12'h343
	`define ysyx_26010011_ADD_MSTATUS   12'h300
	`define ysyx_26010011_ADD_MVENDORID 12'hf11
	`define ysyx_26010011_ADD_MARCHID   12'hf12

	`define ysyx_26010011_EXCEPTION_MISALIGNED_FETCH 4'd0
	`define ysyx_26010011_EXCEPTION_FETCH_ACCESS 4'd1
	`define ysyx_26010011_EXCEPTION_ILLEGAL_INSTRUCTION 4'd2
	`define ysyx_26010011_EXCEPTION_BREAKPOINT 4'd3
	`define ysyx_26010011_EXCEPTION_MISALIGNED_LOAD 4'd4
	`define ysyx_26010011_EXCEPTION_LOAD_ACCESS 4'd5
	`define ysyx_26010011_EXCEPTION_MISALIGNED_STORE 4'd6
	`define ysyx_26010011_EXCEPTION_STORE_ACCESS 4'd7
	`define ysyx_26010011_EXCEPTION_ECALL_UMODE 4'd8
	`define ysyx_26010011_EXCEPTION_ECALL_SMODE 4'd9
	`define ysyx_26010011_EXCEPTION_FENCEI 4'd14                //RESERVED but used to indicate FENCE.I instruction, not a real exception
	`define ysyx_26010011_EXCEPTION_ECALL_MMODE 4'd11
	`define ysyx_26010011_EXCEPTION_FETCH_PAGE_FAULT 4'd12
	`define ysyx_26010011_EXCEPTION_LOAD_PAGE_FAULT 4'd13
	`define ysyx_26010011_EXCEPTION_MRET 4'd14                //RESERVED but used to indicate MRET instruction, not a real exception
	`define ysyx_26010011_EXCEPTION_STORE_PAGE_FAULT 4'd15
	`define ysyx_26010011_INST_NOP 32'h00000013

	`ifdef __ICARUS__
		`define ysyx_26010011_RESET_PC_VECTOR 32'h80000000
	`elsif  SYNTHESIS 
		`define ysyx_26010011_RESET_PC_VECTOR 32'h80000000
	`else 
		`define ysyx_26010011_RESET_PC_VECTOR 32'h30000000
	`endif 
`endif
