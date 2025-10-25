

 module ysyx_25040129_IDU (
	input [31:0] inst,
	input [31:0] pc,
	output [31:0] pc_out_idu,
	output [`ysyx_25040129_REGS_DIG-1:0] src1_id,
	output [`ysyx_25040129_REGS_DIG-1:0] src2_id,
	output reg[`ysyx_25040129_CSR_DIG-1:0] csr_read_id_out_idu,
	output reg[`ysyx_25040129_CSR_DIG-1:0] csr_write_id_out_idu,
	input [31:0] src1_in_idu_reg,
	input [31:0] src2_in_idu_reg,
	input [31:0] csr_in_idu,
	`ifdef ysyx_25040129_DEBUG
	output [31:0] inst_out_idu,
	`endif
	
	output reg[31:0] src1_out_idu,
	output reg[31:0] src2_out_idu,
	output [31:0] lsu_write_data_out_idu,
	output reg is_jalr_out_idu,
	output reg[31:0] imm,
	output [`ysyx_25040129_REGS_DIG-1:0] rd_out_idu,//该信号将被一路传递至WB阶段
	output reg[3:0] alu_opcode, // 该信号将被一路传递至ALU阶段
	
	output reg reg_write_out_idu,//该信号将被一路传递至WB阶段
	output reg[1:0] lsu_write_out_idu, // 该信号将被一路传递至MEM阶段
	output reg[2:0] lsu_read_out_idu, // 该信号将被一路传递至MEM阶段
	output reg ecall_out_idu,
	output reg is_jump_out_idu,
	output reg ebreak_out_idu,
	output reg mret_out_idu,
	
	output reg csr_write_out_idu,//该信号将被一路传递至WB阶段
	
	input is_req_valid_from_ifu,
	output is_req_ready_to_ifu,
	output is_req_valid_to_exu,
	input is_req_ready_from_exu,
	output reg fence_i,
//---------------数据冒险控制--------------------
	input [`ysyx_25040129_REGS_DIG-1:0] rd_idu_pip_exu,
	input valid_rd_write_idu_pip_exu,
	input [`ysyx_25040129_REGS_DIG-1:0] rd_exu_pip_lsu,
	input valid_rd_write_exu_pip_lsu,
	input [`ysyx_25040129_REGS_DIG-1:0] rd_lsu_pip_wbu,
	input valid_rd_write_lsu_pip_wbu,

	input [`ysyx_25040129_CSR_DIG-1:0] csr_addr_idu_pip_exu,
	input valid_csr_addr_write_idu_pip_exu,
	input [`ysyx_25040129_CSR_DIG-1:0] csr_addr_exu_pip_lsu,
	input valid_csr_addr_write_exu_pip_lsu,
	input [`ysyx_25040129_CSR_DIG-1:0] csr_addr_lsu_pip_wbu,
	input valid_csr_addr_write_lsu_pip_wbu,
//---------------数据前递控制--------------------
	input [31:0] exu_forward_data,
	input is_exu_forward_valid,
	input [31:0] lsu_forward_data,
	input is_lsu_forward_valid,
	input [31:0] wbu_forward_data,
	input is_wbu_forward_valid
);
	wire  funct7_5;
	wire [2:0] funct3;
	wire [6:0] opcode;
`ifdef ysyx_25040129_DEBUG
	assign inst_out_idu = inst;
`endif
	wire is_src1_raw;
	wire is_src2_raw;
	wire is_csr_raw;
	wire raw;
	reg is_csrr;
	reg is_src1_from_reg;
	reg is_src2_from_reg;
	wire [31:0] src1_in_idu;
	wire [31:0] src2_in_idu;
	//------------------------------------------------------------------------------
	wire src1_raw_with_exu;
	wire use_src1_from_exu;
	wire src2_raw_with_exu;
	wire use_src2_from_exu;
	//------------------------------------------------------------------------------
	wire src1_raw_with_lsu;
	wire use_src1_from_lsu;
	wire src2_raw_with_lsu;
	wire use_src2_from_lsu;
	//------------------------------------------------------------------------------
	wire src1_raw_with_wbu;
	wire use_src1_from_wbu;
	wire src2_raw_with_wbu;
	wire use_src2_from_wbu;
	//-------------------------------------------------------------------------------
	assign src1_in_idu = use_src1_from_exu ? exu_forward_data : (use_src1_from_lsu ? lsu_forward_data : (use_src1_from_wbu ? wbu_forward_data : src1_in_idu_reg));
	assign src2_in_idu = use_src2_from_exu ? exu_forward_data : (use_src2_from_lsu ? lsu_forward_data : (use_src2_from_wbu ? wbu_forward_data : src2_in_idu_reg));
	//----------------------------------exu数据前递控制--------------------------------
	assign src1_raw_with_exu = ((rd_idu_pip_exu == src1_id) && valid_rd_write_idu_pip_exu)&& (|src1_id);
	assign use_src1_from_exu = is_exu_forward_valid && src1_raw_with_exu;
	assign src2_raw_with_exu = ((rd_idu_pip_exu == src2_id) && valid_rd_write_idu_pip_exu)&& (|src2_id);
	assign use_src2_from_exu = is_exu_forward_valid && src2_raw_with_exu;
	//-------------------------------LSU数据前递控制-----------------------------------
	assign src1_raw_with_lsu = ((rd_exu_pip_lsu == src1_id) && valid_rd_write_exu_pip_lsu)&& (|src1_id);
	assign use_src1_from_lsu =  src1_raw_with_lsu && is_lsu_forward_valid;
	assign src2_raw_with_lsu = ((rd_exu_pip_lsu == src2_id) && valid_rd_write_exu_pip_lsu)&& (|src2_id);
	assign use_src2_from_lsu =  src2_raw_with_lsu && is_lsu_forward_valid;
	//-------------------------------WBU数据前递控制-----------------------------------
	assign src1_raw_with_wbu = ((rd_lsu_pip_wbu == src1_id) && valid_rd_write_lsu_pip_wbu)&& (|src1_id);
	assign use_src1_from_wbu =  src1_raw_with_wbu && is_wbu_forward_valid;
	assign src2_raw_with_wbu = ((rd_lsu_pip_wbu == src2_id) && valid_rd_write_lsu_pip_wbu)&& (|src2_id);
	assign use_src2_from_wbu =  src2_raw_with_wbu && is_wbu_forward_valid;
	//---------------------------------------------------------------------------------
	assign is_src1_raw = is_src1_from_reg && (|src1_id) && (
		(src1_raw_with_exu && ~is_exu_forward_valid) ||
		(src1_raw_with_lsu && ~is_lsu_forward_valid) ||
		(src1_raw_with_wbu && ~is_wbu_forward_valid) 
		);
	assign is_src2_raw = is_src2_from_reg && (|src2_id) && (
		(src2_raw_with_exu && ~is_exu_forward_valid) ||
		(src2_raw_with_lsu && ~is_lsu_forward_valid) ||
		(src2_raw_with_wbu && ~is_wbu_forward_valid)
		);
	assign is_csr_raw = is_csrr && (|csr_read_id_out_idu) && (
		((csr_addr_idu_pip_exu == csr_read_id_out_idu) && valid_csr_addr_write_idu_pip_exu) ||
		((csr_addr_exu_pip_lsu == csr_read_id_out_idu) && valid_csr_addr_write_exu_pip_lsu) ||
		((csr_addr_lsu_pip_wbu == csr_read_id_out_idu) && valid_csr_addr_write_lsu_pip_wbu)
		);
	assign raw = is_src1_raw || is_src2_raw || is_csr_raw ;
//---------------我滴妈好长一段代码--------------------

	assign pc_out_idu = pc; 
	assign lsu_write_data_out_idu = src2_in_idu; 
	assign is_req_ready_to_ifu = is_req_ready_from_exu && !raw; 
	assign is_req_valid_to_exu = (is_req_valid_from_ifu && is_req_ready_from_exu && !raw);


	always @(*) begin
		if(opcode == `ysyx_25040129_I_TYPE_SYSTEM && funct3 == 3'b000 && inst[31:20]== `ysyx_25040129_ECALL)begin 
			csr_read_id_out_idu = `ysyx_25040129_MTVEC; 
			csr_write_id_out_idu = `ysyx_25040129_MEPC;
		end 
		else if(opcode == `ysyx_25040129_I_TYPE_SYSTEM && funct3 == 3'b000 && inst[31:20]== `ysyx_25040129_MRET)begin
			csr_read_id_out_idu = `ysyx_25040129_MEPC;
			csr_write_id_out_idu = `ysyx_25040129_CSR_ERROR; 
		end
		else begin
		case(inst[31:20])
		12'h114: csr_read_id_out_idu = `ysyx_25040129_MVENDORID; 
		12'h514: csr_read_id_out_idu = `ysyx_25040129_MARCHID;
		12'h300: csr_read_id_out_idu = `ysyx_25040129_MSTATUS;
		12'h305: csr_read_id_out_idu = `ysyx_25040129_MTVEC;
		12'h341: csr_read_id_out_idu = `ysyx_25040129_MEPC;
		12'h342: csr_read_id_out_idu = `ysyx_25040129_MCAUSE;
		default: csr_read_id_out_idu = `ysyx_25040129_CSR_ERROR; 
		endcase
		csr_write_id_out_idu = csr_read_id_out_idu;
		end
	end
	//-----------------------------------------------------
	assign funct7_5 = inst[30];
	assign funct3 = inst[14:12];
	assign opcode = inst[6:0];
	assign rd_out_idu = inst[10:7];
	assign src1_id = inst[18:15];
	assign src2_id = inst[23:20];
//---------------调试信号---------------
// always @(posedge clk) begin
// 	`ifdef ysyx_25040129_DEBUG
// 	track_inst_in_idu({5'b0,state},{1'b0,opcode});
// 	`endif
// end
//--------------综合时删除---------------
	always @(*) begin
		reg_write_out_idu = 1'b0;
		is_jump_out_idu = 1'b0;
		ecall_out_idu = 1'b0;
		ebreak_out_idu = 1'b0;
		mret_out_idu = 1'b0;
		is_jalr_out_idu = 1'b0;
		csr_write_out_idu = 1'b0;
		lsu_write_out_idu = `ysyx_25040129_NO_MEM_WRITE;
		lsu_read_out_idu = `ysyx_25040129_NO_MEM_READ;
		is_csrr = 1'b0;
		fence_i = 1'b0;
		is_src1_from_reg = 1'b0;
		is_src2_from_reg = 1'b0;
		src1_out_idu = src1_in_idu;
		src2_out_idu = src2_in_idu;
		imm = 32'b0;
		alu_opcode = `ysyx_25040129_ADD; 
		case (opcode)
			`ysyx_25040129_I_TYPE_IMM:begin
				 imm = {{20{inst[31]}},inst[31:20]};
				 src2_out_idu= imm;
				 reg_write_out_idu = 1'b1;
				 alu_opcode = {(funct3==3'b101)?funct7_5:1'b0,funct3};
				 is_src1_from_reg = 1'b1; 
			end // I-type immediate
			`ysyx_25040129_B_TYPE: begin 
				imm = {{20{inst[31]}},inst[7], inst[30:25], inst[11:8], 1'b0};
				is_src1_from_reg = 1'b1;
				is_src2_from_reg = 1'b1;
				case (funct3)
					3'b000: alu_opcode = `ysyx_25040129_EQ; // BEQ
					3'b001: alu_opcode = `ysyx_25040129_NEQ; // BNE
					3'b100: alu_opcode = `ysyx_25040129_LT; // BLT
					3'b101: alu_opcode = `ysyx_25040129_GE; // BGE
					3'b110: alu_opcode = `ysyx_25040129_LTU; // BLTU
					3'b111: alu_opcode = `ysyx_25040129_GEU; // BGEU
					default: begin
						alu_opcode = 4'b0000; // 默认值
						
					 end
				endcase			
			end// B-type branch

			`ysyx_25040129_I_TYPE_LOAD: begin 
				imm = {{20{inst[31]}},inst[31:20]};
				src2_out_idu= imm; 
				reg_write_out_idu = 1'b1;
				alu_opcode = `ysyx_25040129_ADD; // LOAD指令的ALU操作是加法
				is_src1_from_reg = 1'b1;
				case (funct3)
					3'b000: lsu_read_out_idu = `ysyx_25040129_MEM_READ_BYTE; // LB
					3'b001: lsu_read_out_idu = `ysyx_25040129_MEM_READ_HALF; // LH
					3'b010: lsu_read_out_idu = `ysyx_25040129_MEM_READ_WORD; // LW
					3'b100: lsu_read_out_idu = `ysyx_25040129_MEM_READ_BYTE_U; // LBU
					3'b101: lsu_read_out_idu = `ysyx_25040129_MEM_READ_HALF_U; // LHU
					default: begin end
				endcase

			end // I-type load
			`ysyx_25040129_I_TYPE_FENCE: begin
				imm = 32'b100;
				fence_i = 1'b1;
			end
			`ysyx_25040129_S_TYPE: begin
				imm = {{20{inst[31]}},inst[31:25],inst[11:7]}; // S-type store
				src2_out_idu= imm;
				is_src1_from_reg = 1'b1;
				is_src2_from_reg = 1'b1;
				alu_opcode = `ysyx_25040129_ADD; // STORE指令的ALU操作是加法

				case (funct3)
					3'b000: lsu_write_out_idu = `ysyx_25040129_MEM_WRITE_BYTE; // SB
					3'b001: lsu_write_out_idu = `ysyx_25040129_MEM_WRITE_HALF; // SH
					3'b010: lsu_write_out_idu = `ysyx_25040129_MEM_WRITE_WORD; // SW
					default: begin end
				endcase

				
			end
			`ysyx_25040129_J_TYPE: begin 
				imm = {{12{inst[31]}},inst[19:12],inst[20],inst[30:21],1'b0}; // J-type jump
				src1_out_idu= pc; 
				src2_out_idu= imm; 
				alu_opcode = `ysyx_25040129_ADD; // JAL指令的ALU操作是加法
				is_jump_out_idu = 1'b1;
				is_jalr_out_idu = 1'b1;
				reg_write_out_idu = 1'b1;
			end
			`ysyx_25040129_I_TYPE_JALR: begin 
				imm = {{20{inst[31]}},inst[31:20]}; // JALR
				src2_out_idu= imm;
				is_src1_from_reg = 1'b1;
				alu_opcode = `ysyx_25040129_ADD; // JALR指令的ALU操作是加法
				is_jump_out_idu = 1'b1;
				is_jalr_out_idu = 1'b1;
				reg_write_out_idu = 1'b1;
			end
			`ysyx_25040129_I_TYPE_SYSTEM: begin
				imm = {{20{inst[31]}},inst[31:20]}; // I-type system
				
				case (funct3)
					3'b000: begin
						case(inst[31:20])
							`ysyx_25040129_EBREAK:begin
								ebreak_out_idu = 1'b1;
							end
							`ysyx_25040129_MRET:begin
								mret_out_idu = 1'b1;
								src1_out_idu = csr_in_idu; 
								src2_out_idu = 32'b0;
								alu_opcode = `ysyx_25040129_ADD;  
							end
							`ysyx_25040129_ECALL: begin
								ecall_out_idu = 1'b1;
								csr_write_out_idu = 1'b1;
								src1_out_idu = csr_in_idu;
								src2_out_idu = 32'b0; // ECALL指令不需要src2 
								is_jalr_out_idu = 1'b1;
							end
							default: begin
								
							end
						endcase
						
					end
					3'b001:begin
						csr_write_out_idu = 1'b1;
						reg_write_out_idu = 1'b0;
						is_src1_from_reg = 1'b1;
						src2_out_idu= 32'b0; 
						alu_opcode = `ysyx_25040129_ADD; 
					end
					3'b010:begin
						is_csrr = 1'b1;
						is_src1_from_reg = 1'b1;
						reg_write_out_idu = 1'b1;
						src2_out_idu= csr_in_idu;
						alu_opcode = `ysyx_25040129_OR; 
					end
					default: begin
						`ifdef ysyx_25040129_DPI
						unknown_inst(inst); // Unknown instruction
						`endif
						alu_opcode = 4'b0000; // 默认值
					end
				endcase
			end
			`ysyx_25040129_R_TYPE: begin 
				imm = 32'b0; // R-type
				reg_write_out_idu = 1'b1;
				is_src1_from_reg = 1'b1;
				is_src2_from_reg = 1'b1;
				alu_opcode = {(funct7_5), funct3}; // 根据funct7的第6位决定是加法还是减法
			end
			`ysyx_25040129_U_TYPE_LUI: begin 
				imm = {inst[31:12], 12'b0}; // LUI
				reg_write_out_idu = 1'b1;
				src1_out_idu= 32'b0; // LUI指令不需要src1
				src2_out_idu= imm; // src2_out为立即数
				alu_opcode = `ysyx_25040129_ADD; // LUI指令的ALU操作是加法
			end
			`ysyx_25040129_U_TYPE_AUIPC: begin 
				imm = {inst[31:12], 12'b0}; // AUIPC
				reg_write_out_idu = 1'b1;
				src1_out_idu= pc; // AUIPC指令的src1为pc
				src2_out_idu= imm; // src2_out为立即数
				alu_opcode = `ysyx_25040129_ADD; // AUIPC指令的ALU操作是加法
			end
			default: begin
				imm = 32'b0;
				
			end
		endcase
	end
	
endmodule
