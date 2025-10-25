

module ysyx_25040129_WBU (

	input is_req_valid_from_lsu,
	output is_req_ready_to_lsu,
	input [`ysyx_25040129_REGS_DIG-1:0] rd_in_wbu, 
	
	/* verilator lint_off UNUSEDSIGNAL */
	`ifdef ysyx_25040129_DEBUG
	input [31:0] pc_in_wbu,
	input [31:0] inst_in_wbu,
	input is_device_in_wbu,
	`endif 
	/* verilator lint_on UNUSEDSIGNAL */
	
	input [31:0] result_in_wbu,
	input [`ysyx_25040129_CSR_DIG-1:0] csr_addr_in_wbu,
	input csr_write_in_wbu,
	input reg_write_in_wbu,
	output [`ysyx_25040129_REGS_DIG-1:0] rd_out_wbu,
	output [31:0] result_out_wbu,
	output csr_write_out_wbu, 
	output [`ysyx_25040129_CSR_DIG-1:0] csr_addr_out_wbu, 
	output reg_write_out_wbu,
	input ebreak_in_wbu,
	`ifdef __ICARUS__
	input [31:0] a0,
	`endif
	output is_data_forward_valid_from_wbu,
	output [31:0] wbu_forward_data
);
`ifdef ysyx_25040129_DEBUG
always @(*) begin
	update_wbu_state(is_req_valid_from_lsu);
	update_is_device(is_device_in_wbu);
	update_inst(inst_in_wbu);
	update_pc(pc_in_wbu);
end
`endif 

always @(*) begin
	`ifdef ysyx_25040129_DPI
	if (ebreak_in_wbu) ebreak_trigger();
	`endif
	`ifdef __ICARUS__
	if (ebreak_in_wbu) begin
		$display("EBREAK triggered");
		if(a0 == 32'h0)begin
			$display("HIT GOOD TRAP");
			$finish(0);
		end
		else begin
			$display("HIT BAD TRAP");
			$fatal;
		end
	end
	`endif
end
assign wbu_forward_data = result_in_wbu;
assign is_data_forward_valid_from_wbu = is_req_valid_from_lsu ;
assign is_req_ready_to_lsu = is_req_valid_from_lsu;
assign rd_out_wbu = rd_in_wbu; 
assign result_out_wbu = result_in_wbu; 
assign csr_write_out_wbu = csr_write_in_wbu && is_req_valid_from_lsu; 
assign csr_addr_out_wbu = csr_addr_in_wbu; 
assign reg_write_out_wbu = reg_write_in_wbu && is_req_valid_from_lsu; 
endmodule
