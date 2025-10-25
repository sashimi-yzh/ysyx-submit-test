// import "DPI-C" function void ebreak_trigger();
// import "DPI-C" function void unknown_inst(int inst);
// import "DPI-C" function int paddr_read(int addr, int len);
// import "DPI-C" function void test();
// import "DPI-C" function void paddr_write(int addr, int len, int data);
/*verilator lint_off DECLFILENAME*/module top(
	input clk,
	input rst,
	input [31:0] inst,
	output [31:0]pc
	
);
	wire [4:0] src1_id;
	wire [31:0] src1 ;
	wire [4:0] src2_id;
	wire [31:0] src2 ;
	wire [31:0] imm;
	wire [31:0] result;
	wire [4:0] rd;
	wire [31:0] next_pc;
	wire [6:0] funct7;
	wire [2:0] funct3;
	wire [6:0] opcode;
	wire [31:0] jump_target;
	wire is_branch;
	wire reg_write;
	wire [31:0] read_data;
	ysyx_25040129_REG u_ysyx_25040129_REG (
		.clk(clk),
		.rst(rst),
		.rd(rd),
		.reg_write(reg_write),
		.result(result),
		.src1_id(src1_id),
		.src2_id(src2_id),
		.src1(src1),
		.src2(src2)
	);

	ysyx_25040129_PC u_ysyx_25040129_PC (
		.clk(clk),
		.rst(rst),
		.next_pc(next_pc),
		.pc(pc)
	);
	ysyx_25040129_IFU u_ysyx_25040129_IFU (
		.pc(pc),
		.next_pc(next_pc),
		.is_branch(is_branch),
		.jump_target(jump_target)
	);

	ysyx_25040129_IDU u_ysyx_25040129_IDU (
		.inst(inst),
		.src1_id(src1_id),
		.src2_id(src2_id),
		.imm(imm),
		.rd(rd),
		.funct7(funct7),
		.funct3(funct3),
		.opcode(opcode),
		.reg_write(reg_write)
	);

	ysyx_25040129_EXU u_ysyx_25040129_EXU (
		.src1(src1),
		.src2(src2),
		.imm(imm),
		.funct7(funct7),
		.funct3(funct3),
		.opcode(opcode),
		.result(result),
		.pc(pc),
		.read_data(read_data)
	);

	ysyx_25040129_BRC u_ysyx_25040129_BRC (
		.pc(pc),
		.src1(src1),
		.src2(src2),
		.funct3(funct3),
		.imm(imm),
		.opcode(opcode),
		.is_branch(is_branch),
		.branch_target(jump_target)
	);

	ysyx_25040129_LSU u_ysyx_25040129_LSU (
		.opcode(opcode),
		.imm(imm),
		.src1(src1),
		.src2(src2),
		.funct3(funct3),
		.read_data(read_data)
	);

endmodule/*verilator lint_on DECLFILENAME*/

module ysyx_25040129_REG (
	input clk,
	input rst,
	input [4:0] rd,
	input reg_write,
	input [31:0] result,
	input [4:0] src1_id,
	input [4:0] src2_id,
	output [31:0] src1,
	output [31:0] src2
);
	reg [511:0] regs;
	assign src1 =  regs[src1_id*32 +: 32];
	assign src2 =  regs[src2_id*32 +: 32];
	always @(posedge clk) begin
		if (rst) regs <= 512'b0;
		 else begin
			if (rd != 5'b00000 && reg_write) begin
				regs[rd*32 +:32] <=result;
			end
		end
	end
endmodule

module ysyx_25040129_BRC (
	input [31:0] pc,
	input [31:0] src1,
	input [31:0] src2,
	input [2:0] funct3,
	input [31:0] imm,
	input [6:0] opcode,
	output reg is_branch,
	output reg [31:0] branch_target
);
always @(*)begin
	case (opcode)
		7'b1100011: begin // B-type
			case (funct3)
				3'b000: is_branch = (src1 == src2); // BEQ
				3'b001: is_branch = (src1 != src2); // BNE
				3'b100: is_branch = ($signed(src1) < $signed(src2)); // BLT
				3'b101: is_branch = ($signed(src1) >= $signed(src2)); // BGE
				3'b110: is_branch = (src1 < src2); // BLTU
				3'b111: is_branch = (src1 >= src2); // BGEU
				default: begin is_branch = 0;
				end
			endcase
			branch_target = imm + pc;
		end
		7'b1101111: begin // JAL
			is_branch = 1;
			branch_target = imm + pc;
		end
		7'b1100111: begin // JALR
			is_branch = 1;
			branch_target = (src1 + imm) & 32'hfffffffe;
		end
		default: begin
			is_branch = 0;
			branch_target = 32'h00000000;
		end
	endcase
end
endmodule

module ysyx_25040129_LSU (
	input [6:0] opcode,
	input [31:0] imm,
	input [31:0] src1,
	input [31:0] src2,
	input [2:0] funct3,
	output reg [31:0] read_data
);
wire [31:0] addr;
reg [2:0] write_len;
assign addr = src1 + imm;

always @(*) begin
	case (opcode)
		7'b0000011: begin // LOAD
			// read_data = paddr_read(addr, 4);
		end
		7'b0100011: begin // STORE
			case (funct3)
				3'b000: begin // SB
					write_len = 1;
				end
				3'b001: begin // SH
					write_len = 2;
				end
				3'b010: begin // SW
					write_len = 4;
				end
				default: begin
					write_len = 0;
					// unknown_inst(32'b0); // Unknown store instruction
				end
				 // Write data to memory
				endcase
			// paddr_write(addr, {29'b0,write_len}, src2);
		end
		default: begin
		end
	endcase
end
	
endmodule

module ysyx_25040129_PC (
	input clk,
	input rst,
	input [31:0] next_pc,
	output reg[31:0] pc
);
always @(posedge clk)
		if(rst)pc <= 32'h80000000;
	 else pc <= next_pc;
endmodule

module ysyx_25040129_IFU (
	input [31:0] pc,
	output [31:0] next_pc,
	input is_branch,
	input [31:0] jump_target
);
// assign inst = (pc==32'h0)?paddr_read(32'h80000000,4):paddr_read(pc, 4);
assign next_pc = (is_branch) ? jump_target : pc + 4;
endmodule

//解码指令，准备好数据以及给EXU的控制信号
module ysyx_25040129_IDU (
	input [31:0] inst,
	output [4:0] src1_id,
	output [4:0] src2_id,
	output reg[31:0] imm,
	output [4:0] rd,
	output [6:0] funct7,
	output [2:0] funct3,
	output [6:0] opcode,
	output reg reg_write
);
	assign funct7 = inst[31:25];
	assign funct3 = inst[14:12];
	assign opcode = inst[6:0];
	assign rd = inst[11:7];
	assign src1_id = inst[19:15];
	assign src2_id = inst[24:20];
	always @(*) begin
		case (opcode)
			7'b0010011:begin
				 imm = {{20{inst[31]}},inst[31:20]};
				 reg_write = 1'b1;
			end // I-type immediate
			7'b1100011: begin 
				imm = {{20{inst[31]}},inst[7], inst[30:25], inst[11:8], 1'b0};
				reg_write = 1'b0;
			end// B-type branch
			7'b0000011: begin 
				imm = {{20{inst[31]}},inst[31:20]};
				reg_write = 1'b1;
			end // I-type load
			7'b0100011: begin
				imm = {{20{inst[31]}},inst[31:25],inst[11:7]}; // S-type store
				reg_write = 1'b0;
			end
			7'b1101111: begin 
				imm = {{12{inst[31]}},inst[19:12],inst[20],inst[30:21],1'b0}; // J-type jump
				reg_write = 1'b1;
			end
			7'b1100111: begin 
				imm = {{20{inst[31]}},inst[31:20]}; // JALR
				reg_write = 1'b1;
			end
			7'b1110011: begin
				imm = {{20{inst[31]}},inst[31:20]}; // I-type system
				reg_write = 1'b0;
			end
			7'b0110011: begin 
				imm = 32'b0; // R-type
				reg_write = 1'b1;
			end
			7'b0110111: begin 
				imm = {inst[31:12], 12'b0}; // LUI
				reg_write = 1'b1;
			end
			7'b0010111: begin 
				imm = {inst[31:12], 12'b0}; // AUIPC
				reg_write = 1'b1;
			end
			default: begin
				imm = 32'b0;
				reg_write = 1'b0;
				// unknown_inst(inst); // Unknown instruction
			end
		endcase
	end
	
endmodule

module ysyx_25040129_EXU (
	input [31:0] pc,
	input [31:0] src1,
	input [31:0] src2,
	input [31:0] imm,
	/* verilator lint_off UNUSEDSIGNAL */
	input [6:0] funct7,
	/* verilator lint_on UNUSEDSIGNAL */
	input [2:0] funct3,
	input [6:0] opcode,
	output reg [31:0] result,
	input [31:0] read_data
);
	always @(*) begin
		case (opcode)
			7'b0000011: begin
				case (funct3)
					3'b000: result = {{24{read_data[7]}}, read_data[7:0]}; // LB
					3'b001: result = {{16{read_data[15]}}, read_data[15:0]}; // LH
					3'b010: result = read_data; // LW
					3'b100: result = {24'b0, read_data[7:0]}; // LBU
					3'b101: result = {16'b0, read_data[15:0]}; // LHU
					default: result = 32'b0;
				endcase
			end
			7'b0110111: result = imm;
			7'b0010111: result = imm + pc; // AUIPC
			7'b1110011:	if (funct3 == 0 && imm == 32'h1)begin result=32'b0;end // EBREAK
			else result = 32'b0; // SYSTEM
			7'b1101111: // JAL
				result = pc + 4;
			7'b1100111:  // JALRR
				result = pc + 4;
			7'b0010011: begin // I-type
				case (funct3)
					3'b000: result = src1 + imm; // ADDI
					3'b010: result = ($signed(src1) < $signed(imm)) ? 1 : 0; // SLTI
					3'b011: result = (src1 < imm) ? 1 : 0; // SLTIU
					3'b100: result = src1 ^ imm; // XORI
					3'b110: result = src1 | imm; // ORI
					3'b111: result = src1 & imm; // ANDI
					3'b001: result = src1 << imm[4:0]; // SLLI
					3'b101: begin // SRLI/SRAI
						if (funct7[5] == 0) begin
							result = src1 >> imm[4:0];
						end else begin
							result = $signed(src1) >>> imm[4:0];
						end
					end
				endcase
			end
			7'b0110011: begin // R-type
				case (funct3)
					3'b000: begin // ADD
						if (funct7[5] == 0) begin
							result = src1 + src2;
						end else begin
							result = src1 - src2;
						end
					end
					3'b001: result = src1 << src2[4:0]; // SLL
					3'b010: result = ($signed(src1) < $signed(src2)) ? 1 : 0; // SLT
					3'b011: result = (src1 < src2) ? 1 : 0; // SLTU
					3'b100: result = src1 ^ src2; // XOR
					3'b101: begin // SRL/SRA
						if (funct7[5] == 0) begin
							result = src1 >> src2[4:0];
						end else begin
							result = $signed(src1) >>> src2[4:0];
						end
					end
					3'b110: result = src1 | src2; // OR
					3'b111: result = src1 & src2; // AND
				endcase
			end
			default:begin
				result = 32'b0;
			end
		endcase
	end



endmodule

