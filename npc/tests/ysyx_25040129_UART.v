module ysyx_25040129_UART(
	input clk,
	input rst,
	//-------只写设备-------
	//---------------写地址---------------
	/* verilator lint_off UNUSEDSIGNAL */
	input [31:0] awaddr,
	/* verilator lint_on UNUSEDSIGNAL */
	input awvalid,
	output reg awready,
	//---------------写数据---------------
	/* verilator lint_off UNUSEDSIGNAL */
	input [1:0] wstrb,
	input [31:0] wdata,
	/* verilator lint_on UNUSEDSIGNAL */
	input wvalid,
	output reg wready,
	//---------------写响应---------------
	output reg [1:0] bresp,
	output reg bvalid,
	input bready
);
/* verilator lint_off UNUSEDSIGNAL */
reg [15:0] uart_port; 
/* verilator lint_on UNUSEDSIGNAL */


localparam IDLE = 2'b00;
localparam WAIT_AW_VALID = 2'b01;
localparam WAIT_W_VALID = 2'b10;
localparam WRITING = 2'b11;

reg [1:0] state, next_state;
always @(posedge clk) begin
	if(rst) begin
		state <= IDLE;
		uart_port <= 16'b0;
	end else begin
		state <= next_state;
	end
end
//-----------------------下一状态逻辑-----------------------
always @(*) begin
	case (state)
		IDLE: begin
			if(awvalid && wvalid) next_state = WRITING;
		 	else if(awvalid) next_state = WAIT_AW_VALID;
			else if(wvalid) next_state = WAIT_W_VALID;
			else next_state = IDLE;
			end
		WAIT_AW_VALID: next_state = awvalid ? WRITING : WAIT_AW_VALID;
		WAIT_W_VALID: next_state = wvalid ? WRITING : WAIT_W_VALID;
		WRITING: next_state = bready ? IDLE : WRITING;
		endcase
	end
//-----------------------输出逻辑-----------------------
assign awready = (state == IDLE) || (state == WAIT_AW_VALID);
assign wready = (state == WAIT_W_VALID) || (state == IDLE);
assign bvalid = (state == WRITING);
assign bresp = `ysyx_25040129_OKAY;
always @(posedge clk) begin
	if(state!=WRITING && next_state == WRITING) begin
		uart_port <= wdata[15:0]; 
	end
	if(state == WRITING && bready) begin
		$write("%c", uart_port[7:0]); 
	end
end
endmodule
