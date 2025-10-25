

module ysyx_25040129_EXU (
	input [31:0] pc,
	input [31:0] src1,
	input [31:0] src2,
	input [31:0] imm,
	input [3:0] alu_opcode, // 该信号将被一路传递至ALU阶段

	`ifdef ysyx_25040129_DEBUG
	output [31:0] pc_out_exu,
	input [31:0] inst_in_exu,
	output [31:0] inst_out_exu,
	`endif

	input [31:0] lsu_write_data_in_exu, // 该信号将被一路传递至MEM阶段

	output reg [31:0] result_out_exu,
	output [31:0]lsu_write_data_out_exu,
	output [31:0] branch_target_out_exu, // 分支目标地址

	input is_jalr_in_exu,

	input ebreak_in_exu,
	input [`ysyx_25040129_REGS_DIG-1:0]rd_in_exu,
	input csr_write_in_exu,
	input [`ysyx_25040129_CSR_DIG-1:0] csr_write_addr_in_exu, 
	input ecall_in_exu,
	input mret_in_exu,
	input reg_write_in_exu,

	output ebreak_out_exu,
	output [`ysyx_25040129_REGS_DIG-1:0] rd_out_exu,
	output csr_write_out_exu,
	output [`ysyx_25040129_CSR_DIG-1:0] csr_write_addr_out_exu, 
	output ecall_out_exu,
	output mret_out_exu,
	output reg_write_out_exu,

	input [2:0] lsu_read_in_exu, // 该信号将被一路传递至MEM阶段
	input [1:0] lsu_write_in_exu, // 该信号将被一路传
	output [2:0] lsu_read_out_exu, // 该信号将被一路传递至MEM阶
	output [1:0] lsu_write_out_exu, // 该信号将被一路传递至MEM阶段
	input is_jump_in_exu,
	output is_branch_out_exu,
	input is_req_valid_from_idu,
	output is_req_ready_to_idu,
	output is_req_valid_to_lsu,
	input is_req_ready_from_lsu,
	input fence_i_in_exu,
	output fence_i_out_exu,

	output is_data_forward_valid_from_exu
);	

//--------------调试信号----------------
// always @(posedge clk) begin
// 	`ifdef ysyx_25040129_DEBUG
// 	execute_count_inc({5'b0,state});
// 	`endif
// end
//-------------综合时删除----------------
`ifdef ysyx_25040129_DEBUG
assign pc_out_exu = pc;
assign inst_out_exu = inst_in_exu;
`endif
assign ebreak_out_exu = ebreak_in_exu ;
assign csr_write_addr_out_exu = csr_write_addr_in_exu;
assign fence_i_out_exu = fence_i_in_exu ;
assign is_req_valid_to_lsu = (is_req_valid_from_idu && is_req_ready_from_lsu);
assign is_req_ready_to_idu = is_req_ready_from_lsu;

reg is_branch;
assign lsu_write_data_out_exu =  lsu_write_data_in_exu; // 如果是写请求，则将计算结果传递出去，否则传递计算结果
assign rd_out_exu = rd_in_exu;

assign is_branch_out_exu = is_jump_in_exu || is_branch; 
assign branch_target_out_exu =(is_jalr_in_exu || mret_in_exu)? src1 + src2 : pc + imm; 
assign lsu_read_out_exu = lsu_read_in_exu; // 直接传递MEM阶段的读请求
assign lsu_write_out_exu = lsu_write_in_exu; // 直接传递

assign csr_write_out_exu = csr_write_in_exu; // 直接传递CSR
assign ecall_out_exu = ecall_in_exu; // 直接传递CSR写使能信号
assign mret_out_exu = mret_in_exu; // 直接传递寄
assign reg_write_out_exu = reg_write_in_exu; // 直接传递寄存器写使能信号
assign is_data_forward_valid_from_exu =  (lsu_read_in_exu == `ysyx_25040129_NO_MEM_READ);
always @(*) begin
	result_out_exu = 32'b0;
	is_branch = 1'b0; 
	case (alu_opcode)
		`ysyx_25040129_ADD: result_out_exu = (is_jalr_in_exu)?(ecall_in_exu ? pc : pc+`ysyx_25040129_WORD_T):src1 + src2;
		`ysyx_25040129_SUB: result_out_exu = src1 - src2;
		`ysyx_25040129_SLL: result_out_exu = src1 << src2[4:0];
		`ysyx_25040129_SLT: result_out_exu = ($signed(src1) < $signed(src2)) ? 32'b1 : 32'b0;
		`ysyx_25040129_SLTU: result_out_exu = (src1 < src2) ? 32'b1 : 32'b0;
		`ysyx_25040129_XOR: result_out_exu = src1 ^ src2;
		`ysyx_25040129_SRL: result_out_exu = src1 >> src2[4:0];
		`ysyx_25040129_SRA: result_out_exu = $signed(src1) >>> src2[4:0];
		`ysyx_25040129_OR: result_out_exu = src1 | src2;
		`ysyx_25040129_AND: result_out_exu = src1 & src2;
		`ysyx_25040129_EQ: is_branch = (src1 == src2);
		`ysyx_25040129_NEQ: is_branch = (src1 != src2);
		`ysyx_25040129_LT: is_branch = ($signed(src1) < $signed(src2));
		`ysyx_25040129_GE: is_branch = ($signed(src1) >= $signed(src2));
		`ysyx_25040129_LTU: is_branch = (src1 < src2);
		`ysyx_25040129_GEU: is_branch = (src1 >= src2);
	endcase
	// $display("EXU: branch_target_out_exu = %h, result_out_exu = %h, src 1 = %h, src2 = %h, imm = %h, alu_opcode = %b", 
	// 	branch_target_out_exu, result_out_exu, src1, src2, imm, alu_opcode);
end
endmodule
