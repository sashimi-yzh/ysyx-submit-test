

module ysyx_25040129_CLINT (
	input clk,
	input rst,
	//---------------只读设备---------------
	//---------------读地址---------------
	/* verilator lint_off UNUSEDSIGNAL */
	input [31:0] araddr,
	input arvalid,
	/* verilator lint_on UNUSEDSIGNAL */
	output arready,
	//---------------读数据---------------
	output [31:0] rdata,
	output [1:0] rresp,
	output rvalid,
	/* verilator lint_off UNUSEDSIGNAL */
	input rready
	/* verilator lint_on UNUSEDSIGNAL */
);
	assign rresp = `ysyx_25040129_OKAY;
	// CLINT的实现代码
	reg [15:0] mtime [3:0];
	assign arready = 1'b1; 
	assign rvalid = 1'b1; 
	assign rdata = (araddr[2]) ? {mtime[3],mtime[2]} : {mtime[1],mtime[0]};
	always @(posedge clk) begin
		if(rst)begin
			mtime[0] <= 16'h0;
			mtime[1] <= 16'h0;
			mtime[2] <= 16'h0;
			mtime[3] <= 16'h0;
		end
		else begin
			mtime[0] <= mtime[0] + 1;
			mtime[1] <= (&mtime[0])? mtime[1] + 1 : mtime[1];
			mtime[2] <= (&mtime[1])? mtime[2] + 1 : mtime[2];
			mtime[3] <= (&mtime[2])? mtime[3] + 1 : mtime[3]; 
		end		
	end

endmodule
