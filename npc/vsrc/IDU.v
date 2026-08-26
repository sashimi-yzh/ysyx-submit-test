

// ██╗ ██████╗  ██╗   ██╗
// ██║ ██╔══██╗ ██║   ██║
// ██║ ██║  ██║ ██║   ██║
// ██║ ██║  ██║ ██║   ██║
// ██║ ██████╔╝ ╚██████╔╝
// ╚═╝ ╚═════╝   ╚═════╝
`include "csr_defines.v"
module ysyx_26010011_IDU(
	input 			   clock,
	input 			   reset,
	input 			   flush_valid,
	input			   fencei_pass,
	input        [31:0]gpr_rdataa,
	input        [31:0]gpr_rdatab,
	input        [31:0]csr_rdata,

	input			   exu_out_bus_rd_valid,
	input			   exu_out_bus_bypass_valid,
	input 			   exu_out_bus_csr_valid,
	input 		 [ 3:0]exu_out_bus_rd,
	input 		 [11:0]exu_out_bus_csrrd,
	input 		 [31:0]exu_out_bus_gpr_wdata,

	input 			   lsu_out_bus_rd_valid,
	input 			   lsu_out_bus_bypass_valid,
	input 			   lsu_out_bus_csr_valid,
	input 		 [ 3:0]lsu_out_bus_rd,
	input 		 [11:0]lsu_out_bus_csrrd,
	input 		 [31:0]lsu_out_bus_gpr_wdata,

	input			   wbu_out_bus_rd_valid,
	input 			   wbu_out_bus_bypass_valid,
	input 			   wbu_out_bus_csr_valid,
	input 		 [ 3:0]wbu_out_bus_rd,
	input 		 [11:0]wbu_out_bus_csrrd,
	input 		 [31:0]wbu_out_bus_gpr_wdata,

	input        [31:0]idu_in_bus_instruction,
	input        [31:0]idu_in_bus_pc,
	input        [ 4:0]idu_in_bus_exception,
	input              idu_in_valid,
	output             idu_in_ready,

	output             idu_out_valid,
	input              idu_out_ready,
	output       [ 3:0]idu_out_bus_rd,
	output reg   [ 4:0]idu_out_bus_exception,
	output       [11:0]idu_out_bus_csrrd,
	output       [ 3:0]idu_out_bus_rs1,
	output       [ 3:0]idu_out_bus_rs2,
	output reg   [31:0]idu_out_bus_imm,
	output             idu_out_bus_isLOAD,
	output             idu_out_bus_isSTORE,
	output             idu_out_bus_isWGPR,
	output             idu_out_bus_isJUMP,
	output             idu_out_bus_isWCOMP,
	output             idu_out_bus_isBRANCH,
	output reg   [ 2:0]idu_out_bus_opCSR,
	output             idu_out_bus_isUnSigned,
	output             idu_out_bus_isUsePC,
	output             idu_out_bus_alu_isUseImm,
	output             idu_out_bus_comp_isUseImm,
	output reg   [ 3:0]idu_out_bus_alu_op,
	output reg   [ 1:0]idu_out_bus_comp_op,
	output       [31:0]idu_out_bus_pc,
	output reg   [31:0]idu_out_bus_rs1_val,
	output reg   [31:0]idu_out_bus_rs2_val,

	output       [ 1:0]idu_out_bus_perip_mask
);

	reg state, next_state;
	parameter S_WORKING = 1'b0, S_WAITING = 1'b1;

	logic [ 6: 0]opcode;
	logic [11: 0]immI;
	logic [11: 0]immS;
	logic [12: 1]immB;
	logic [31:12]immU;
	logic [20: 1]immJ;
	logic [ 2: 0]funct3;
	logic [ 6: 0]funct7;

	logic isECALL, isEBREAK, isMRET,isFENCEI;
	logic isLUI, isAUIPC, isJAL, isJALR, isBEQ, isBNE, isBLT, isBGE, isBLTU, isBGEU;
	logic isLB, isLH, isLW, isLBU, isLHU, isSB, isSH, isSW, isADDI, isSLTI, isSLTIU;
	logic isXORI, isORI, isANDI, isSLLI, isSRLI, isSRAI, isADD, isSUB, isSLL, isSLT;
	logic isSLTU, isXOR, isSRL, isSRA, isOR, isAND;
	logic isCSRRW,isCSRRS,isCSRRC,isCSRRWI,isCSRRSI,isCSRRCI;
	logic isR,isI,isS,isB,isU,isJ;
	
	reg [31:0] rs1_val_bypass;
	reg [1:0]rs1_bypass_sel,rs2_bypass_sel;
	wire all_inst,idu_isRAW/*verilator public*/;

	always @(posedge clock) begin
		if(reset | flush_valid | fencei_pass) state <= S_WORKING;
		else      state <= next_state;
	end

	always @(*) begin
		if(state == S_WORKING) begin
			if(idu_in_valid && isFENCEI) begin
				next_state = S_WAITING;
			end else begin
				next_state = S_WORKING;
			end
		end else if(state == S_WAITING) begin
			if(fencei_pass) begin
				next_state = S_WORKING;
			end else begin
				next_state = S_WAITING;
			end
		end else begin
			next_state = S_WORKING;
		end
	end
	assign idu_out_bus_pc = idu_in_bus_pc;
	assign idu_in_ready = idu_out_ready && (!idu_isRAW || idu_out_bus_exception[4]) && (state == S_WORKING && next_state == S_WORKING);
	assign idu_out_valid = idu_in_valid && (!idu_isRAW || idu_out_bus_exception[4]) && (state == S_WORKING);

	assign all_inst = (isLUI|isAUIPC|isJAL|isJALR|isBEQ|isBNE|isBLT|isBGE|isBLTU|isBGEU
					|isLB|isLH|isLW|isLBU|isLHU|isSB|isSH|isSW
					|isADDI|isSLTI|isSLTIU|isXORI|isORI|isANDI
					|isSLLI|isSRLI|isSRAI
					|isADD|isSUB|isSLL|isSLT|isSLTU
					|isXOR|isSRL|isSRA|isOR|isAND
					|(|idu_out_bus_opCSR)
					|isECALL|isEBREAK|isMRET|isFENCEI);//////////////////////////

	assign opcode=				idu_in_bus_instruction[ 6: 0];
	assign idu_out_bus_rd=      idu_in_bus_instruction[10: 7];//4bit
	assign idu_out_bus_csrrd=   idu_in_bus_instruction[31:20];
	assign idu_out_bus_rs1=     idu_in_bus_instruction[18:15];//4bit
	assign idu_out_bus_rs2=     idu_in_bus_instruction[23:20];//4bit
	assign funct3=				idu_in_bus_instruction[14:12];
	assign funct7=				idu_in_bus_instruction[31:25];
	
	assign immI = {idu_in_bus_instruction[31:20]                                             };
	assign immS = {idu_in_bus_instruction[31:25],idu_in_bus_instruction[11: 7]                              };
	assign immB = {idu_in_bus_instruction[31:31],idu_in_bus_instruction[ 7: 7],idu_in_bus_instruction[30:25],idu_in_bus_instruction[11: 8]};
	assign immU = {idu_in_bus_instruction[31:12]                                             };
	assign immJ = {idu_in_bus_instruction[31:31],idu_in_bus_instruction[19:12],idu_in_bus_instruction[20:20],idu_in_bus_instruction[30:21]};
	assign idu_out_bus_alu_isUseImm = (isI|isS|isB|isU|isJ)?1:0;
	assign idu_out_bus_comp_isUseImm = (isSLTI|isSLTIU)?1:0;
/////////////////////////
	assign isLUI    = (opcode == 7'b0110111                                             ) ? 1 : 0;
	assign isAUIPC  = (opcode == 7'b0010111                                             ) ? 1 : 0;
	assign isJAL    = (opcode == 7'b1101111                                             ) ? 1 : 0;
	assign isJALR   = (opcode == 7'b1100111 && funct3 == 3'b000                         ) ? 1 : 0;
	assign isBEQ    = (opcode == 7'b1100011 && funct3 == 3'b000                         ) ? 1 : 0;
	assign isBNE    = (opcode == 7'b1100011 && funct3 == 3'b001                         ) ? 1 : 0;
	assign isBLT    = (opcode == 7'b1100011 && funct3 == 3'b100                         ) ? 1 : 0;
	assign isBGE    = (opcode == 7'b1100011 && funct3 == 3'b101                         ) ? 1 : 0;
	assign isBLTU   = (opcode == 7'b1100011 && funct3 == 3'b110                         ) ? 1 : 0;
	assign isBGEU   = (opcode == 7'b1100011 && funct3 == 3'b111                         ) ? 1 : 0;
	assign isLB     = (opcode == 7'b0000011 && funct3 == 3'b000                         ) ? 1 : 0;
	assign isLH     = (opcode == 7'b0000011 && funct3 == 3'b001                         ) ? 1 : 0;
	assign isLW     = (opcode == 7'b0000011 && funct3 == 3'b010                         ) ? 1 : 0;
	assign isLBU    = (opcode == 7'b0000011 && funct3 == 3'b100                         ) ? 1 : 0;
	assign isLHU    = (opcode == 7'b0000011 && funct3 == 3'b101                         ) ? 1 : 0;
	assign isSB     = (opcode == 7'b0100011 && funct3 == 3'b000                         ) ? 1 : 0;
	assign isSH     = (opcode == 7'b0100011 && funct3 == 3'b001                         ) ? 1 : 0;
	assign isSW     = (opcode == 7'b0100011 && funct3 == 3'b010                         ) ? 1 : 0;
	assign isADDI   = (opcode == 7'b0010011 && funct3 == 3'b000                         ) ? 1 : 0;
	assign isSLTI   = (opcode == 7'b0010011 && funct3 == 3'b010                         ) ? 1 : 0;
	assign isSLTIU  = (opcode == 7'b0010011 && funct3 == 3'b011                         ) ? 1 : 0;
	assign isXORI   = (opcode == 7'b0010011 && funct3 == 3'b100                         ) ? 1 : 0;
	assign isORI    = (opcode == 7'b0010011 && funct3 == 3'b110                         ) ? 1 : 0;
	assign isANDI   = (opcode == 7'b0010011 && funct3 == 3'b111                         ) ? 1 : 0;
	assign isSLLI   = (opcode == 7'b0010011 && funct3 == 3'b001 && funct7 == 7'b0000000 ) ? 1 : 0;
	assign isSRLI   = (opcode == 7'b0010011 && funct3 == 3'b101 && funct7 == 7'b0000000 ) ? 1 : 0;
	assign isSRAI   = (opcode == 7'b0010011 && funct3 == 3'b101 && funct7 == 7'b0100000 ) ? 1 : 0;
	assign isADD    = (opcode == 7'b0110011 && funct3 == 3'b000 && funct7 == 7'b0000000 ) ? 1 : 0;
	assign isSUB    = (opcode == 7'b0110011 && funct3 == 3'b000 && funct7 == 7'b0100000 ) ? 1 : 0;
	assign isSLL    = (opcode == 7'b0110011 && funct3 == 3'b001 && funct7 == 7'b0000000 ) ? 1 : 0;
	assign isSLT    = (opcode == 7'b0110011 && funct3 == 3'b010 && funct7 == 7'b0000000 ) ? 1 : 0;
	assign isSLTU   = (opcode == 7'b0110011 && funct3 == 3'b011 && funct7 == 7'b0000000 ) ? 1 : 0;
	assign isXOR    = (opcode == 7'b0110011 && funct3 == 3'b100 && funct7 == 7'b0000000 ) ? 1 : 0;
	assign isSRL    = (opcode == 7'b0110011 && funct3 == 3'b101 && funct7 == 7'b0000000 ) ? 1 : 0;
	assign isSRA    = (opcode == 7'b0110011 && funct3 == 3'b101 && funct7 == 7'b0100000 ) ? 1 : 0;
	assign isOR     = (opcode == 7'b0110011 && funct3 == 3'b110 && funct7 == 7'b0000000 ) ? 1 : 0;
	assign isAND    = (opcode == 7'b0110011 && funct3 == 3'b111 && funct7 == 7'b0000000 ) ? 1 : 0;

	assign isCSRRC  = (opcode == 7'b1110011 && funct3 == 3'b011                         );
	assign isCSRRCI = (opcode == 7'b1110011 && funct3 == 3'b111                         );
	assign isCSRRS  = (opcode == 7'b1110011 && funct3 == 3'b010                         );
	assign isCSRRSI = (opcode == 7'b1110011 && funct3 == 3'b110                         );
	assign isCSRRW  = (opcode == 7'b1110011 && funct3 == 3'b001                         );
	assign isCSRRWI = (opcode == 7'b1110011 && funct3 == 3'b101                         );

	assign isECALL  = (opcode == 7'b1110011 && funct3 == 3'b000 && funct7 == 7'b0000000 );
	assign isEBREAK = (opcode == 7'b1110011 && funct3 == 3'b000 && funct7 == 7'b0000001 );
	assign isMRET   = (opcode == 7'b1110011 && funct3 == 3'b000 && funct7 == 7'b0011000 );
	assign isFENCEI = (opcode == 7'b0001111 && funct3 == 3'b001                         );
/////////////////////////

	assign idu_out_bus_isLOAD = (isLW|isLBU|isLB|isLH|isLHU);
	assign idu_out_bus_isSTORE= (isSW|isSB|isSH);
	assign idu_out_bus_isWGPR = (isLUI|isAUIPC|isJAL|isJALR|isADDI|isSLTI|isSLTIU|isXORI|isORI|isANDI|isSLLI|isSRLI|isSRAI|isADD|isSUB|isSLL|isSLT|isSLTU|isXOR|isSRL|isSRA|isOR|isAND|idu_out_bus_isLOAD|(|idu_out_bus_opCSR))?1:0;
	assign idu_out_bus_isJUMP= (isJAL|isJALR);
	assign idu_out_bus_isUsePC = (isAUIPC|isJAL|isBEQ|isBNE|isBLT|isBGE|isBLTU|isBGEU);
	assign idu_out_bus_isWCOMP=(isSLTI|isSLTIU|isSLT|isSLTU);
/////////////////////////
	assign isI=(isADDI|isSLTI|isSLTIU|isXORI|isORI|isANDI|isSLLI|isSRLI|isSRAI|isJALR|isLW|isLBU|isLB|isLH|isLHU|(|idu_out_bus_opCSR));
	assign isR=(isADD|isSUB|isSLL|isSLT|isSLTU|isXOR|isSRL|isSRA|isOR|isAND);
	assign isS=(isSW|isSB|isSH);
	assign isB=(isBEQ|isBNE|isBLT|isBGE|isBLTU|isBGEU);
	assign isU=(isLUI|isAUIPC);
	assign isJ=(isJAL);
	always @(*) begin
		if(isCSRRS)       idu_out_bus_opCSR=3'b001;
		else if(isCSRRSI) idu_out_bus_opCSR=3'b101;
		else if(isCSRRC)  idu_out_bus_opCSR=3'b010;
		else if(isCSRRCI) idu_out_bus_opCSR=3'b110;
		else if(isCSRRW)  idu_out_bus_opCSR=3'b011;
		else if(isCSRRWI) idu_out_bus_opCSR=3'b111;
		else              idu_out_bus_opCSR=3'b000;
	end

	always @(*) begin
		if((|idu_out_bus_opCSR)) begin
			idu_out_bus_imm=csr_rdata;
		end else begin
			if     (isI)    idu_out_bus_imm={{20{immI[11:11]}},immI[11:0]};
			else if(isJ)    idu_out_bus_imm={{11{immJ[20:20]}},immJ[20:1],1'b0};
			else if(isS)    idu_out_bus_imm={{20{immS[11:11]}},immS[11:0]};
			else if(isU)    idu_out_bus_imm={   {immU[31:12]} ,{12{1'b0}}};
			else if(isB)    idu_out_bus_imm={{19{immB[12:12]}},immB[12:1],1'b0};
			else            idu_out_bus_imm=0;
		end
	end
	always @(*) begin
		if(isAUIPC|isJAL|isJALR|isADD|isLW|isLBU|isLB|isLH|isSW|isSH|isSB|isADDI|isLHU|isBEQ|isBNE|isBLT|isBGE|isBLTU|isBGEU) begin
			idu_out_bus_alu_op = 4'd1;
		end else if(isSUB) begin
			idu_out_bus_alu_op = 4'd2;
		end else if(isSLLI|isSLL) begin
			idu_out_bus_alu_op = 4'd3;
		end else if(isSRLI|isSRL) begin
			idu_out_bus_alu_op = 4'd4;
		end else if(isSRAI|isSRA) begin
			idu_out_bus_alu_op = 4'd5;
		end else if(isANDI|isAND) begin
			idu_out_bus_alu_op = 4'd6;
		end else if(isORI|isOR) begin
			idu_out_bus_alu_op = 4'd7;
		end else if(isXORI|isXOR) begin
			idu_out_bus_alu_op = 4'd8;
		end else begin
			idu_out_bus_alu_op = 4'd0;
		end
	end

	always @(*) begin
		if(isBLTU|isBLT|isSLT|isSLTI|isSLTIU|isSLTU)   idu_out_bus_comp_op=2'b01;
		else if(isBNE)                                 idu_out_bus_comp_op=2'b10;
		else if(isBEQ)                                 idu_out_bus_comp_op=2'b11;
		else                                           idu_out_bus_comp_op=2'b00;//BGE BGEU
	end

	/////////////////////////
	assign idu_out_bus_perip_mask=(isLW|isSW)?2'b10:((isLBU|isLB|isSB)?2'b00:((isLH|isLHU|isSH)?2'b01:2'b11));
	/////////////////////////
	assign idu_out_bus_isUnSigned=(isLBU|isLHU|isBLTU|isBGEU|isSLTIU|isSLTU);

	//BRANCH
	assign idu_out_bus_isBRANCH = isB;

	always @(*) begin
		if(idu_in_bus_exception[4]) begin
			idu_out_bus_exception = idu_in_bus_exception;
		end else begin
			if(!all_inst) begin
				idu_out_bus_exception = {1'b1,`ysyx_26010011_EXCEPTION_ILLEGAL_INSTRUCTION};
			end else if(isEBREAK)begin
				idu_out_bus_exception = {1'b1,`ysyx_26010011_EXCEPTION_BREAKPOINT};
			end else if(isECALL)begin
				idu_out_bus_exception = {1'b1,`ysyx_26010011_EXCEPTION_ECALL_MMODE};
			end else if(isMRET)begin
				idu_out_bus_exception = {1'b1,`ysyx_26010011_EXCEPTION_MRET};
			end else if(isFENCEI)begin
				idu_out_bus_exception = {1'b0,`ysyx_26010011_EXCEPTION_FENCEI};
			end else begin
				idu_out_bus_exception = 5'b0;
			end
		end
	end

	
	always @(*) begin
		case(idu_out_bus_opCSR)
			3'b110:
				idu_out_bus_rs1_val = ~{{28{1'b0}},idu_out_bus_rs1};
			3'b100:
				idu_out_bus_rs1_val = {{28{1'b0}},idu_out_bus_rs1};
			3'b101:
				idu_out_bus_rs1_val = {{28{1'b0}},idu_out_bus_rs1};
			3'b111:
				idu_out_bus_rs1_val = {{28{1'b0}},idu_out_bus_rs1};
			3'b010:
				idu_out_bus_rs1_val = ~rs1_val_bypass;
			3'b000:
				idu_out_bus_rs1_val = rs1_val_bypass;
			3'b001:
				idu_out_bus_rs1_val = rs1_val_bypass;
			3'b011:
				idu_out_bus_rs1_val = rs1_val_bypass;
			default:
				idu_out_bus_rs1_val = rs1_val_bypass;
		endcase
	end
	
	always @(*) begin
		if(idu_out_bus_rs1 == exu_out_bus_rd && exu_out_bus_rd_valid && exu_out_bus_bypass_valid && idu_out_bus_rs1 != 4'd0) begin
			rs1_bypass_sel = 2'd1;
		end else if(idu_out_bus_rs1 == lsu_out_bus_rd && lsu_out_bus_rd_valid && lsu_out_bus_bypass_valid && idu_out_bus_rs1 != 4'd0) begin
			rs1_bypass_sel = 2'd2;
		end else if(idu_out_bus_rs1 == wbu_out_bus_rd && wbu_out_bus_rd_valid && wbu_out_bus_bypass_valid && idu_out_bus_rs1 != 4'd0) begin
			rs1_bypass_sel = 2'd3;
		end else begin
			rs1_bypass_sel = 2'd0;
		end
	end
	always @(*) begin
		if(idu_out_bus_rs2 == exu_out_bus_rd && exu_out_bus_rd_valid && exu_out_bus_bypass_valid && idu_out_bus_rs2 != 4'd0) begin
			rs2_bypass_sel = 2'd1;
		end else if(idu_out_bus_rs2 == lsu_out_bus_rd && lsu_out_bus_rd_valid && lsu_out_bus_bypass_valid && idu_out_bus_rs2 != 4'd0) begin
			rs2_bypass_sel = 2'd2;
		end else if(idu_out_bus_rs2 == wbu_out_bus_rd && wbu_out_bus_rd_valid && wbu_out_bus_bypass_valid && idu_out_bus_rs2 != 4'd0) begin
			rs2_bypass_sel = 2'd3;
		end else begin
			rs2_bypass_sel = 2'd0;
		end
	end
	always @(*) begin
		case (rs1_bypass_sel)
			2'd1:rs1_val_bypass = exu_out_bus_gpr_wdata;
			2'd2:rs1_val_bypass = lsu_out_bus_gpr_wdata;
			2'd3:rs1_val_bypass = wbu_out_bus_gpr_wdata;
			default:rs1_val_bypass = gpr_rdataa;
		endcase
		case (rs2_bypass_sel)
			2'd1:idu_out_bus_rs2_val = exu_out_bus_gpr_wdata;
			2'd2:idu_out_bus_rs2_val = lsu_out_bus_gpr_wdata;
			2'd3:idu_out_bus_rs2_val = wbu_out_bus_gpr_wdata;
			default:idu_out_bus_rs2_val = gpr_rdatab;
		endcase
	end
	ysyx_26010011_RAW u_RAW(
		.rs1(idu_out_bus_rs1),
		.rs2(idu_out_bus_rs2),
		.csr(idu_out_bus_csrrd),
		.rs2_valid(isB || isS || isR),

		.exu_rd_valid(exu_out_bus_rd_valid),
		.lsu_rd_valid(lsu_out_bus_rd_valid),
		.wbu_rd_valid(wbu_out_bus_rd_valid),

		.exu_csr_valid(exu_out_bus_csr_valid && (|idu_out_bus_opCSR)),
		.lsu_csr_valid(lsu_out_bus_csr_valid && (|idu_out_bus_opCSR)),
		.wbu_csr_valid(wbu_out_bus_csr_valid && (|idu_out_bus_opCSR)),

		.exu_bypass_valid(exu_out_bus_bypass_valid),
		.lsu_bypass_valid(lsu_out_bus_bypass_valid),
		.wbu_bypass_valid(wbu_out_bus_bypass_valid),

		.exu_in_bus_rd(exu_out_bus_rd),
		.lsu_in_bus_rd(lsu_out_bus_rd),
		.wbu_in_bus_rd(wbu_out_bus_rd),

		.exu_in_bus_csr_rd(exu_out_bus_csrrd),
		.lsu_in_bus_csr_rd(lsu_out_bus_csrrd),
		.wbu_in_bus_csr_rd(wbu_out_bus_csrrd),

		.is_RAW(idu_isRAW)
	);
endmodule
