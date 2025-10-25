

module ysyx_25040129_REG (
	input clk,
	/* verilator lint_off UNUSEDSIGNAL */
	input rst,
	/* verilator lint_on UNUSEDSIGNAL */
	input [`ysyx_25040129_REGS_DIG-1:0] rd,
	input [`ysyx_25040129_REGS_DIG-1:0] src1_id,
	input [`ysyx_25040129_REGS_DIG-1:0] src2_id,
	input reg_write,
	`ifdef __ICARUS__
	output [31:0] a0,
	`endif
	input [31:0] result,
	output [31:0] src1,
	output [31:0] src2
);
	reg [31:0] regs[15:1];
	`ifdef __ICARUS__
	assign a0 = regs[10];
	`endif
	assign src1 = src1_id == 4'b0000 ? 32'b0: regs[src1_id];
	assign src2 = src2_id == 4'b0000 ? 32'b0: regs[src2_id];
	always @(*) begin
		`ifdef ysyx_25040129_DEBUG
		update_regs(
			32'b0,
			regs[1], 
			regs[2], 
			regs[3], 
			regs[4], 
			regs[5], 
			regs[6], 
			regs[7], 
			regs[8], 
			regs[9], 
			regs[10], 
			regs[11], 
			regs[12], 
			regs[13], 
			regs[14], 
			regs[15]
		);
		`endif
	end
	always @(posedge clk) begin
		 begin
			if (rd != 4'b0000 && reg_write) begin
				regs[rd] <=result;
			end
		end
	end
endmodule
