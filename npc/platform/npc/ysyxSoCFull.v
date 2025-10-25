import "DPI-C" function void soc_write(int addr,byte strb, int data);
import "DPI-C" function int soc_read(int addr);
module ysyxSoCFull (
	input clock,
	input reset
);
//这是脱离了soc的功能验证模块
//所有从top中传出的AXI-Lite信号都在这里被DPI-C瞬间处理
// verilator lint_off UNUSED
/* verilator lint_off PINCONNECTEMPTY */
ysyx_25040129 u_top (
	.clock                   (clock),
    .reset                   (reset),
    .io_interrupt            (1'h0),	//:35:23, :36:19, :38:21
    .io_master_awready      (awready),
    .io_master_awvalid      (awvalid),
    .io_master_awid    (/* unused */),
    .io_master_awaddr  (awaddr),
    .io_master_awlen   (/* unused */),
    .io_master_awsize  (/* unused */),
    .io_master_awburst (/* unused */),
    .io_master_wready       (wready),
    .io_master_wvalid       (wvalid),
    .io_master_wdata   (wdata),
    .io_master_wstrb   (wstrb),
    .io_master_wlast   (/* unused */),
    .io_master_bready       (bready),
    .io_master_bvalid       (bvalid),
    .io_master_bid     (4'b0),
    .io_master_bresp   (bresp),
    .io_master_arready      (arready),
    .io_master_arvalid      (arvalid),
    .io_master_arid    (/* unused */),
    .io_master_araddr  (araddr),
    .io_master_arlen   (arlen),
    .io_master_arsize  (/* unused */),
    .io_master_arburst (/* unused */),
    .io_master_rready       (rready),
    .io_master_rvalid       (rvalid),
    .io_master_rid     (4'b0),
    .io_master_rdata   (rdata),
    .io_master_rresp   (rresp),
    .io_master_rlast   (rlast),
    .io_slave_awready       (/* unused */),
    .io_slave_awvalid       (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_awid     (4'h0),	//:36:19, :38:21
    .io_slave_awaddr   (32'h0),	//:36:19, :38:21
    .io_slave_awlen    (8'h0),	//:36:19, :38:21
    .io_slave_awsize   (3'h0),	//:36:19, :38:21
    .io_slave_awburst  (2'h0),	//:36:19, :38:21
    .io_slave_wready        (/* unused */),
    .io_slave_wvalid        (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_wdata    (32'h0),	//:36:19, :38:21
    .io_slave_wstrb    (4'h0),	//:36:19, :38:21
    .io_slave_wlast    (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_bready        (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_bvalid        (/* unused */),
    .io_slave_bid      (/* unused */),
    .io_slave_bresp    (/* unused */),
    .io_slave_arready       (/* unused */),
    .io_slave_arvalid       (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_arid     (4'h0),	//:36:19, :38:21
    .io_slave_araddr   (32'h0),	//:36:19, :38:21
    .io_slave_arlen    (8'h0),	//:36:19, :38:21
    .io_slave_arsize   (3'h0),	//:36:19, :38:21
    .io_slave_arburst  (2'h0),	//:36:19, :38:21
    .io_slave_rready        (1'h0),	//:35:23, :36:19, :38:21
    .io_slave_rvalid        (/* unused */),
    .io_slave_rid      (/* unused */),
    .io_slave_rdata    (/* unused */),
    .io_slave_rresp    (/* unused */),
    .io_slave_rlast    (/* unused */));
//-------------------读地址-----------------------
wire [31:0] araddr;
wire arvalid;
wire arready;
wire [7:0] arlen;
wire [1:0] arburst;
//-------------------读数据-----------------------
reg [31:0] rdata;
wire [1:0] rresp;
wire rvalid;
wire rready;
reg rlast;
//-------------------写地址-----------------------
wire [31:0] awaddr;
wire awvalid;
wire awready;
//-------------------写数据-----------------------
wire [3:0] wstrb;
wire [31:0] wdata;
wire wvalid;
wire wready;
//-------------------写响应-----------------------
wire [1:0] bresp;
wire bvalid;
wire bready;
//-------------------DPI-C-----------------------

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
reg [7:0] read_len_store;
reg [31:0] write_addr_store;
reg [31:0] write_data_store;
reg [3:0] write_strb_store;
/* verilator lint_on UNUSEDSIGNAL */
reg [2:0] r_state;
reg [2:0] w_state;
reg [7:0] r_len_cnt;
always @(posedge clock) begin
	case(r_state)
		R_IDLE:begin
			if(arvalid)begin
				r_state <= R_READING;
				read_addr_store <= araddr;
				read_len_store <= arlen;
				r_len_cnt <= 0;
				rdata <= soc_read(araddr);
				if(arlen == 0)
					rlast <= 1'b1; 
			end
		end
		R_READING:begin
			if(rready)begin
				if(r_len_cnt == read_len_store) begin
					r_state <= R_IDLE;
					rlast <= 1'b0;
				end else begin
					if(r_len_cnt + 1 == read_len_store)begin
						rlast <= 1'b1; 
					end
					rdata <= soc_read(read_addr_store +  4);
					r_len_cnt <= r_len_cnt + 1;
					read_addr_store <= read_addr_store + 4;
				end
			end
		end
		default: r_state <= R_IDLE;
endcase
end
always @(posedge clock) begin
	case(w_state)
		W_IDLE:begin
			if(awvalid)begin
				write_addr_store <= awaddr;
				if(wvalid)begin
					w_state <= W_WRITING;
					write_data_store <= wdata;
					write_strb_store <= wstrb;
				end else begin
					w_state <= W_WAIT_AW_VALID;
				end
			end
		end
		W_WAIT_AW_VALID:begin
			if(awvalid)begin
				w_state <= W_WRITING;
				write_addr_store <= awaddr;
			end
		end
		W_WAIT_W_VALID:begin
			if(wvalid)begin
				write_data_store <= wdata;
				write_strb_store <= wstrb;
				w_state <= W_WRITING;
			end
		end
		W_WRITING:begin
			soc_write(write_addr_store, {4'b0,write_strb_store}, write_data_store);
			w_state <= W_WAIT_B_READY;
		end
		W_WAIT_B_READY:begin
			if(bready) begin
				w_state <= W_IDLE;
			end 
		end
		default: w_state <= W_IDLE;
	endcase
end
assign arready = (r_state == R_IDLE);
assign rresp = 2'b00; // OKAY
assign rvalid = (r_state == R_READING) ;
assign awready = (w_state == W_IDLE) || (w_state == W_WAIT_AW_VALID);
assign wready = (w_state == W_WAIT_W_VALID) || (w_state == W_IDLE);
assign bvalid = (w_state == W_WAIT_B_READY);
assign bresp = 2'b00; // OKAY

// verilator lint_on UNUSED
/* verilator lint_on PINCONNECTEMPTY */
endmodule
