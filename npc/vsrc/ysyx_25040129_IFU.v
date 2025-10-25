

module ysyx_25040129_IFU (
	input rst,
	input clk,

	input [31:0] pipeline_flush_target,
	input pipeline_flush,
	input is_req_ready_from_idu,

	output reg[31:0] pc,
	output [31:0] inst_to_idu,
	
	output is_req_valid_to_idu,
	//---------------读地址---------------
	output [31:0] araddr,
	output arvalid,
	input arready,
	//---------------读数据---------------
	input [31:0] rdata,
	input [1:0]rresp,
	input rvalid,
	output rready
	);
localparam WAIT_MMEM_READY = 3'b000;
localparam WAIT_MMEM_REQ = 3'b001;
localparam WAIT_IDU_READY = 3'b010;	
reg get_flush_signal_in_fetching;
reg [31:0] flush_target_latch;
reg [31:0] inst;
reg[2:0] state;
assign araddr = pc;
assign arvalid = (state == WAIT_MMEM_READY);
assign rready = (state == WAIT_MMEM_REQ) || (state == WAIT_MMEM_READY && arready);



//总线信号产生逻辑
assign is_req_valid_to_idu = (state == WAIT_IDU_READY ||(state == WAIT_MMEM_READY && arready && rvalid)) && !pipeline_flush && !get_flush_signal_in_fetching;
assign inst_to_idu = (state == WAIT_MMEM_READY && arready && rvalid) ? rdata : inst;
//--------------------调试接口---------------------
always @(posedge clk) begin
	`ifdef ysyx_25040129_DEBUG
	fetch_count_inc({5'b0,state});
	`endif
	`ifdef ysyx_25040129_GENERATE_PC_QUEUE
		if(state==IDLE && next_state == WAIT_MMEM_READY)record_pc(pc);
	`endif
end
// always @(*) begin
// 	`ifdef ysyx_25040129_DEBUG
// 	update_pc(pc);
// 	update_inst(inst_to_idu);
// 	update_ifu_state({5'b0,state});
// 	`endif
// end
//-------------------综合时直接删除-------------------
// pc 更新逻辑
always @(posedge clk) begin
	if(rst)begin
		pc <= `ysyx_25040129_FLASH_START;
		inst <= 32'b0; 
		get_flush_signal_in_fetching <= 1'b0;
		state <= WAIT_MMEM_READY;
	end
	else begin
		case (state)
			WAIT_MMEM_READY:begin
				if(arready)begin
					if(rvalid) begin
						inst <= rdata;
						if(pipeline_flush)begin
							pc <= pipeline_flush_target;
							get_flush_signal_in_fetching <= 1'b0;
							flush_target_latch <= 32'b0;
							state <= WAIT_MMEM_READY;
						end
						else begin
							if(is_req_ready_from_idu)begin 
								state <= WAIT_MMEM_READY;
								pc <= pc + 4;
							end
							else state <= WAIT_IDU_READY;
						end
						`ifdef ysyx_25040129_DPI
						if(rresp != `ysyx_25040129_OKAY)$error("IFU: Read error, rresp = %b", rresp);
						`endif
					end
					else begin
						if(pipeline_flush)begin
							get_flush_signal_in_fetching <= 1'b1;
							flush_target_latch <= pipeline_flush_target;
						end
						state <= WAIT_MMEM_REQ;
						end
					end
				else begin
					 state <= WAIT_MMEM_READY;
					if(pipeline_flush)begin
					 get_flush_signal_in_fetching <= 1'b1;
					 flush_target_latch <= pipeline_flush_target;
					end
				end
			
			end
			WAIT_MMEM_REQ:begin
				if(rvalid)begin 
					state <= WAIT_IDU_READY;
					inst <= rdata;
					`ifdef ysyx_25040129_DPI
					if(rresp != `ysyx_25040129_OKAY)$error("IFU: Read error, rresp = %b", rresp);
					`endif
				end
				else state <= WAIT_MMEM_REQ;
				if(pipeline_flush)begin
					get_flush_signal_in_fetching <= 1'b1;
					flush_target_latch <= pipeline_flush_target;
				end
			end
			WAIT_IDU_READY:begin
				if(pipeline_flush)begin
					pc <= pipeline_flush_target;
					get_flush_signal_in_fetching <= 1'b0;
					flush_target_latch <= 32'b0;
					state <= WAIT_MMEM_READY;
				end
				else if(get_flush_signal_in_fetching)begin
					pc <= flush_target_latch;
					get_flush_signal_in_fetching <= 1'b0;
					flush_target_latch <= 32'b0;
					state <= WAIT_MMEM_READY;
				end
				else begin
					if(is_req_ready_from_idu)begin 
						state <= WAIT_MMEM_READY;
						pc <= pc + 4;
					end
					else state <= WAIT_IDU_READY;
				end
			end
			default: state <= WAIT_MMEM_READY;
		endcase
	end
end

endmodule
