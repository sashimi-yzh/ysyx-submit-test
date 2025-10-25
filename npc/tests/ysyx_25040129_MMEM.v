module ysyx_25040129_MMEM (
input clk,
input rst,
//---------------读地址---------------
input [31:0] araddr,
input arvalid,
output arready,
//---------------读数据---------------
output reg[31:0] rdata,
output [1:0]rresp,
output rvalid,
input rready,
//---------------写地址---------------
input [31:0] awaddr,
input awvalid,
output awready,
//---------------写数据---------------
input [1:0] wstrb,
input [31:0] wdata,
input wvalid,
output wready,
//---------------写响应---------------
output [1:0]bresp,
output bvalid,
input bready
);

wire [4:0] delay = 5'b1;
localparam  R_IDLE = 3'b000;
localparam  R_READING = 3'b001;
localparam  R_WAIT_R_READY = 3'b010;

localparam  W_IDLE = 3'b000;
localparam  W_WAIT_AW_VALID = 3'b001; 
localparam  W_WAIT_W_VALID = 3'b010;
localparam  W_WRITING = 3'b100;
localparam  W_WAIT_B_READY = 3'b101;
/* verilator lint_off UNUSEDSIGNAL */
reg [31:0] read_addr_store;
reg [31:0] write_addr_store;
reg [31:0] write_data_store;
reg [1:0] write_strb_store;
/* verilator lint_on UNUSEDSIGNAL */
reg [2:0] r_state;
reg [2:0] next_r_state;
reg [2:0] w_state;
reg [2:0] next_w_state;
reg [4:0] r_delay_cnt;
reg [4:0] r_delay;
reg [4:0] w_delay_cnt;
reg [4:0] w_delay;
always @(*) begin
	case (r_state)
		R_IDLE: next_r_state = arvalid ?R_READING : R_IDLE;
		R_READING: next_r_state = (r_delay_cnt == r_delay) ? R_WAIT_R_READY : R_READING;
		R_WAIT_R_READY: next_r_state = rready ? R_IDLE : R_WAIT_R_READY;
		default: next_r_state = R_IDLE;
	endcase
	case (w_state)
		W_IDLE: next_w_state = awvalid ? (wvalid?W_WRITING:W_WAIT_W_VALID) : (wvalid?W_WAIT_AW_VALID:W_IDLE);
		W_WAIT_AW_VALID: next_w_state = awvalid ?W_WRITING : W_WAIT_AW_VALID;
		W_WAIT_W_VALID: next_w_state = wvalid ?W_WRITING: W_WAIT_W_VALID;
		W_WRITING: next_w_state = (w_delay_cnt == w_delay) ? W_WAIT_B_READY : W_WRITING;
		W_WAIT_B_READY: next_w_state = bready ? W_IDLE : W_WAIT_B_READY;
		default: next_w_state = W_IDLE;
endcase
end

assign arready = (r_state == R_IDLE);
assign rvalid = (r_state == R_WAIT_R_READY);
assign rresp = `ysyx_25040129_OKAY;
assign awready = (w_state == W_IDLE) || (w_state == W_WAIT_AW_VALID);
assign wready = (w_state == W_WAIT_W_VALID) || (w_state == W_IDLE);
assign bvalid = (w_state == W_WAIT_B_READY);
assign bresp = `ysyx_25040129_OKAY;

always @(posedge clk) begin
	if(rst)begin
		r_state <= R_IDLE;
		w_state <= W_IDLE;
	end else begin
		r_state <= next_r_state;
		if((r_state !=R_READING)&&(next_r_state == R_READING))begin
			r_delay <= delay; 
			r_delay_cnt <= 1; 
		end
		else r_delay_cnt <= r_delay_cnt + 1;
		w_state <= next_w_state;
		if(w_state!= W_WRITING&&next_w_state == W_WRITING) begin
			w_delay <= delay; 
			w_delay_cnt <= 1;
		end
		else w_delay_cnt <= w_delay_cnt + 1;
	end
end

always @(posedge clk) begin
	if(next_r_state == R_WAIT_R_READY)begin
		rdata <= paddr_read(read_addr_store, 4, 0, 32'b1);
	end
	else if(next_w_state == W_WAIT_B_READY) begin
		case (write_strb_store)
			2'b01: paddr_write(write_addr_store, 1, {24'b0, write_data_store[7:0]}, write_strb_store == 2'b01 ? 32'b1 : 32'b0);
			2'b10: paddr_write(write_addr_store, 2, {16'b0, write_data_store[15:0]}, write_strb_store == 2'b10 ? 32'b1 : 32'b0);
			2'b11: paddr_write(write_addr_store, 4, write_data_store, write_strb_store == 2'b11 ? 32'b1 : 32'b0);
			default: ;
		endcase
	end
end
//在进入对应状态时，锁存必要数据
always @(posedge clk) begin
	if(r_state == R_IDLE && arvalid) read_addr_store <= araddr;
	if(w_state == W_IDLE && awvalid && wvalid) begin 
		write_addr_store <= awaddr;
		write_data_store <= wdata;
		write_strb_store <= wstrb;
	end
	else if(w_state == W_WAIT_AW_VALID && awvalid) write_addr_store <= awaddr;
	else if(w_state == W_WAIT_W_VALID && wvalid) begin
		write_data_store <= wdata;
		write_strb_store <= wstrb;
	end
end
endmodule
// always @(posedge clk) begin
// 	if (rst) begin
// 		state <= IDLE;
// 	end else begin
// 		state <= next_state;
// 	end
// end
// always @(*) begin
// 	case (state)
// 		IDLE: begin
// 			if (is_req_valid) begin
// 				if (mmem_read != `ysyx_25040129_NO_MEM_READ) begin
// 					next_state = PROCESS_READ;
// 				end else if (mmem_write != `ysyx_25040129_NO_MEM_WRITE) begin
// 					next_state = PROCESS_WRITE;
// 				end else begin
// 					next_state = IDLE;
// 				end
// 			end else begin
// 				next_state = IDLE;
// 			end
// 		end
// 		PROCESS_READ: next_state = is_rsp_ready ? IDLE : PROCESS_READ;
// 		PROCESS_WRITE: next_state = is_rsp_ready ? IDLE : PROCESS_WRITE;
// 		default: next_state = IDLE;
// 	endcase
// end
// always @(posedge clk) begin
// 	case (state)
// 		IDLE:begin
// 			if(is_req_valid)begin
// 				if(mmem_read != `ysyx_25040129_NO_MEM_READ)begin
// 					case (mmem_read)
// 						`MEM_READ_BYTE:mmem_read_data <= {{24{paddr_read(mmem_addr,1,0,mmem_read == `MEM_READ_BYTE ? 32'b1 : 32'b0)[7]}}, paddr_read(mmem_addr,1,0,mmem_read == `MEM_READ_BYTE ? 32'b1 : 32'b0)[7:0]};
// 						`MEM_READ_HALF:mmem_read_data <= {{16{paddr_read(mmem_addr,2,0,mmem_read == `MEM_READ_HALF ? 32'b1 : 32'b0)[15]}}, paddr_read(mmem_addr,2,0,mmem_read == `MEM_READ_HALF ? 32'b1 : 32'b0)[15:0]};
// 						`MEM_READ_WORD:mmem_read_data <= paddr_read(mmem_addr,4,0,mmem_read == `MEM_READ_WORD ? 32'b1 : 32'b0);
// 						`MEM_READ_BYTE_U:mmem_read_data <= {24'b0, paddr_read(mmem_addr,1,0,mmem_read == `MEM_READ_BYTE_U ? 32'b1 : 32'b0)[7:0]};
// 						`MEM_READ_HALF_U:mmem_read_data <= {16'b0, paddr_read(mmem_addr,2,0,mmem_read == `MEM_READ_HALF_U ? 32'b1 : 32'b0)[15:0]}; 
// 						default: begin	end
// 					endcase
// 				end
// 				else if(mmem_write != `ysyx_25040129_NO_MEM_WRITE)begin
// 					case (mmem_write)
// 						`MEM_WRITE_BYTE:paddr_write(mmem_addr,1,{24'b0,mmem_write_data[7:0]},mmem_write == `MEM_WRITE_BYTE ? 32'b1 : 32'b0);
// 						`MEM_WRITE_HALF:paddr_write(mmem_addr,2,{16'b0,mmem_write_data[15:0]},mmem_write == `MEM_WRITE_HALF ? 32'b1 : 32'b0);
// 						`MEM_WRITE_WORD: paddr_write(mmem_addr,4,mmem_write_data,mmem_write == `MEM_WRITE_WORD ? 32'b1 : 32'b0);
// 						default: begin	end
// 					endcase
// 				end
// 			end
// 		end 
// 		default:mmem_read_data = mmem_read_data; 
// 	endcase
// end




// assign is_req_ready = (state == IDLE);
// assign is_rsp_valid = (state == PROCESS_READ)||(state == PROCESS_WRITE);
// // 通过paddr_read()和paddr_write()函数来实现对主存的读写操作







// endmodule
