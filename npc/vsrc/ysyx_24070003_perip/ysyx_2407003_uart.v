module ysyx_24070003_uart(
   input clk,
   input rst,
   
//read
   input  [31:0]araddr,
   input  [7:0]arlen,
   input  [2:0]arsize,
   input  [1:0]arburst,
   input  arvalid,
   output  arready,

   output [31:0]rdata,
   output reg [1:0]rresp,
   output  rlast,
   output reg rvalid,
   input  rready,

//write
   input [31:0]awaddr,
   input [7:0]awlen,
   input [2:0]awsize,
   input [1:0]awburst,
   input awvalid,
   output awready,

   input [31:0]wdata,
   input [ 3:0]wstrb,
   input wlast,
   input wvalid,
   output reg wready,

   output [1:0]bresp,
   output bvalid,
   input bready
   
);


// 辅助：字节地址 -> word 索引
function [31:0] addr2w;
    input [31:0] a;
    reg [31:0] temp;
    begin
        temp = a - 32'h80000000;
        addr2w = {temp[31:2], 2'b00};
    end
endfunction

//************** read  *******************
reg [1:0]read_current_state, read_next_state;

localparam read_idle       = 2'b00;        //waiting for arvalid
localparam read_send_rdata = 2'b01;        //sending read data after read address handshake
//localparam read_last_send  = 2'b11;        //sending the last data and 'rlast'


reg [31:0]r_addr;
reg  [7:0]r_len;
reg  [2:0]r_size;
reg  [1:0]r_burst;
reg  [7:0]r_count;

reg [31:0] mtime_low;
reg [31:0] mtime_high;
always @(posedge clk) begin
    if (rst) begin
        mtime_low <= 32'b0;
    end else if(mtime_low == 32'hffffffff) begin
        mtime_low <= 32'b0;
    end else begin
        mtime_low <= mtime_low + 32'b1;
    end
end
always @(posedge clk) begin
    if (rst) begin
        mtime_high <= 32'b0;
    end else if (mtime_low == 32'hffffffff)begin
            mtime_high <= mtime_high + 32'b1;
    end else begin
        mtime_high <= mtime_high;
    end
end

// wire [31:0] rdata;
//assign AXI4_CLINT_RDATA = (r_addr == 32'ha0000048) ? mtime_low : (r_addr == 32'ha000004c) ? mtime_high : 32'b0;

import "DPI-C" function void vpmem_write(input int waddr, input byte wmask,input int wdata,input byte wen);
always @(posedge clk) begin
	if(rst == 1'b1) read_current_state <= read_idle;
	else            read_current_state <= read_next_state;

	if(arvalid&&arready&&(read_current_state==read_idle)) begin
		r_addr  <= araddr;
		r_len   <= arlen;
		r_size  <= arsize;
		r_burst <= arburst;

		r_count <= 8'b0;
	end
	else if(read_current_state == read_send_rdata) begin
        r_addr <= r_addr + 4'h4;
		r_count <= r_count + 8'h1;
	end
end

// reg [63:0]r_data;
// wire [31:0] a = addr2w(r_addr);
// wire [7:0] data1 = mem[a];
// wire [7:0] data2 = mem[a+1];
// wire [7:0] data3 = mem[a+2];
// wire [7:0] data4 = mem[a+3];
// wire [31:0] r_cache = {data4,data3,data2,data1};
//wire [31:0] r_cache = (r_addr == 32'ha0000048) ? mtime_low : (r_addr == 32'ha000004c) ? mtime_high : {data4,data3,data2,data1};
//assign rdata = r_cache;
assign arready = read_current_state == read_idle;
assign rlast  = (r_count == r_len) && (read_current_state == read_send_rdata);


always @(*) begin
	case(read_current_state)
		read_idle: begin
			rvalid = 1'b0;
			rresp  = 2'b0;
			read_next_state = (arvalid == 1'b1)? read_send_rdata : read_idle;
		end
		read_send_rdata: begin
			rvalid = 1'b1;
			rresp  = 2'b0;
			read_next_state = (r_count == r_len) ? read_idle : read_send_rdata;
		end
		default: begin
			rvalid = 1'b0;
			rresp  = 2'b0;
			read_next_state = read_idle;
		end
	endcase
end





//************** write *******************
reg [1:0]write_current_state, write_next_state;

localparam write_idle  = 2'b00;
localparam write_receive_wdata = 2'b01;        //receive wdata and write it to memory
localparam write_w_rsp = 2'b11;                //write respone

reg [31:0]w_addr;
reg  [7:0]w_len;
reg  [2:0]w_size;
reg  [1:0]w_burst;
reg  [7:0]w_count;

always @(posedge clk) begin
	if(rst == 1'b1) write_current_state <= write_idle;
	else            write_current_state <= write_next_state;

	if(awvalid&&awready&&(write_current_state==write_idle)) begin
		w_addr  <= awaddr;
		w_len   <= awlen;
		w_size  <= awsize;
		w_burst <= awburst;

		w_count <= 8'b0;
	end
	else if(write_current_state == write_receive_wdata) begin
		w_count <= w_count + 8'h1;
	end
end


always @(posedge clk) begin
	if(rst == 1'b1) write_current_state <= write_idle;
	else            write_current_state <= write_next_state;


end

assign awready = write_current_state==write_idle;
assign bresp   = 2'b0;
assign bvalid  = write_current_state==write_w_rsp;

always @(*) begin
	case(write_current_state)
		write_idle: begin
			wready  = 1'b0;
			write_next_state = (awvalid && awready) ? write_receive_wdata : write_idle;
		end
		write_receive_wdata: begin
			wready  = 1'b1;
			write_next_state = (w_count == w_len) ? write_w_rsp : write_receive_wdata;
		end
		write_w_rsp: begin
			wready  = 1'b0;
			write_next_state = write_idle;
		end
		default: begin
			wready  = 1'b0;
			write_next_state = write_idle;
		end
	endcase
end
reg [31:0] w_data_cache;
integer byte_idx;
always @(posedge clk) begin
    if (wvalid && wready) begin
        if(w_addr == 32'ha00003f8)begin
            $write("%c",wdata[7:0]);
        end
    end
end


endmodule
