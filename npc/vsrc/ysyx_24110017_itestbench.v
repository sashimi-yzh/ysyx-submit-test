`timescale 1ns/1ps
module ysyx_24110017_testbench;
	reg clock;
	reg reset;

	reg master_awready;
  reg master_wready;
  reg master_bvalid;
  reg master_arready;
  reg master_rvalid;
  reg master_rlast;
	wire master_awvalid;
	wire [31:0]master_awaddr;
	wire master_wvalid;
	wire [31:0]master_wdata;
	wire [ 3:0]master_wstrb;
	wire master_bready;
	wire master_arvalid;
	wire [31:0]master_araddr;
	wire master_rready;
	wire [31:0]rdata;
	wire [31:0]master_rdata = rdata;
	wire wen = master_wvalid && master_wready;
  wire [31:0]waddr_offset = master_awaddr[31:0] - 32'h80000000;
	wire [31:0]waddr = {waddr_offset[31:2],2'b0};
  wire [ 3:0]wmask = master_wstrb;
	wire [31:0]wdata = master_wdata;
  wire [31:0]raddr_offset = master_araddr[31:0] - 32'h80000000;
	wire [31:0]raddr = {raddr_offset[31:2],2'b0};
	localparam DEVICE_UART_ADDR = 32'ha00003F8;
	wire uwen = master_wvalid && master_wready && master_awaddr == DEVICE_UART_ADDR;
	wire [7:0] uwdata = master_wdata[7:0];

	ysyx_24110017 cpu(
		.clock             (clock),
    .reset             (reset),
    .io_interrupt      (1'h0),
    .io_master_awready (master_awready),
    .io_master_awvalid (master_awvalid),
    .io_master_awid    (),
    .io_master_awaddr  (master_awaddr),
    .io_master_awlen   (),
    .io_master_awsize  (),
    .io_master_awburst (),
    .io_master_wready  (master_wready),
    .io_master_wvalid  (master_wvalid),
    .io_master_wdata   (master_wdata),
    .io_master_wstrb   (master_wstrb),
    .io_master_wlast   (),
    .io_master_bready  (master_bready),
    .io_master_bvalid  (master_bvalid),
    .io_master_bid     (4'b0),
    .io_master_bresp   (2'b0),
    .io_master_arready (master_arready),
    .io_master_arvalid (master_arvalid),
    .io_master_arid    (),
    .io_master_araddr  (master_araddr),
    .io_master_arlen   (),
    .io_master_arsize  (),
    .io_master_arburst (),
    .io_master_rready  (master_rready),
    .io_master_rvalid  (master_rvalid),
    .io_master_rid     (4'b0),
    .io_master_rdata   (master_rdata),
    .io_master_rresp   (2'b0),
    .io_master_rlast   (master_rlast),
    .io_slave_awready  (),
    .io_slave_awvalid  (1'h0),
    .io_slave_awid     (4'h0),
    .io_slave_awaddr   (32'h0),
    .io_slave_awlen    (8'h0),
    .io_slave_awsize   (3'h0),
    .io_slave_awburst  (2'h0),
    .io_slave_wready   (),
    .io_slave_wvalid   (1'h0),
    .io_slave_wdata    (32'h0),
    .io_slave_wstrb    (4'h0),
    .io_slave_wlast    (1'h0),
    .io_slave_bready   (1'h0),
    .io_slave_bvalid   (),
    .io_slave_bid      (),
    .io_slave_bresp    (),
    .io_slave_arready  (),
    .io_slave_arvalid  (1'h0),
    .io_slave_arid     (4'h0),
    .io_slave_araddr   (32'h0),
    .io_slave_arlen    (8'h0),
    .io_slave_arsize   (3'h0),
    .io_slave_arburst  (2'h0),
    .io_slave_rready   (1'h0),
    .io_slave_rvalid   (),
    .io_slave_rid      (),
    .io_slave_rdata    (),
    .io_slave_rresp    (),
    .io_slave_rlast    ()
  );

	ysyx_24110017_memory #(32,32,32'h8000000) iverilog_memory (
		.clock(clock),
		.reset(reset),
		.wen(wen),
		.waddr(waddr),
		.wmask(wmask),
		.wdata(wdata),
		.raddr(raddr),
		.rdata(rdata)
	);
	
	ysyx_24110017_UART uart(
		.clock(clock),
		.reset(reset),
		.wen(uwen),
		.wdata(uwdata)
	);

	always #5 clock = ~clock;

	initial begin
		clock = 0;
		reset = 0;

		$dumpfile("build/wave.vcd");
		$dumpvars(0,ysyx_24110017_testbench);

		#15 reset = 1;
		#50 reset = 0;
		#100000000 $finish; //RTT need
	end

	reg read_delay,write_delay;
	reg [10:0]read_counter,write_counter;
	
	always @(posedge clock) begin
		if(reset) begin
			write_delay <= 1'b0;
			read_delay <= 1'b0;
		end
		else begin
			if(master_wvalid && master_wready) begin
				write_delay <= 1'b1;
			end
			if(master_arvalid && master_arready) begin
				read_delay <= 1'b1;
			end
			if(read_counter == 3) begin
				read_delay <= 1'b0;
			end
			if(write_counter == 3) begin
				write_delay <= 1'b0;
			end
		end
	end

	always @(posedge clock) begin
		if(reset) begin
			read_counter <= 11'b0;
			write_counter <= 11'b0;
		end
		else begin
			if(write_delay) begin
				write_counter <= write_counter + 1;
			end
			if(read_delay) begin
				read_counter <= read_counter + 1;
			end
			if(read_counter == 3) begin
				read_counter <= 11'b0;
			end
			if(write_counter == 3) begin
				write_counter <= 11'b0;
			end
		end
	end

	always @(posedge clock) begin
		if(reset) begin
			master_awready <= 1'b0;
			master_wready  <= 1'b0;
			master_bvalid  <= 1'b0;
			master_arready <= 1'b0;
			master_rvalid  <= 1'b0;
			master_rlast   <= 1'b0;
		end
		else begin
			master_awready <= 1'b1;
			master_wready  <= 1'b1;
			master_arready <= 1'b1;
			if(write_counter == 3) begin
				master_bvalid  <= 1'b1;
			end
			if(master_bvalid && master_bready) begin
				master_bvalid  <= 1'b0;
			end
			if(read_counter == 3) begin
				master_rvalid  <= 1'b1;
				master_rlast   <= 1'b1;
			end
			if(master_rvalid && master_rready) begin
        master_rvalid  <= 1'b0;
        master_rlast   <= 1'b0;
			end
		end
	end

endmodule

module ysyx_24110017_memory #(ADDR_WIDTH = 32, DATA_WIDTH = 32, MEM_SIZE = 16) (
	input wire clock,
	input wire reset,
	input wire wen,
	input wire [ADDR_WIDTH-1:0] waddr,
	input wire [3:0] wmask,
  input wire [DATA_WIDTH-1:0] wdata,
	input wire [ADDR_WIDTH-1:0] raddr,
  output wire [DATA_WIDTH-1:0] rdata
);

	reg [7:0] memory [0:MEM_SIZE-1];

	initial begin
		$readmemh("./build/memory_iverilog.hex",memory);
	end

	always @(posedge clock) begin
		if(wen) begin
			case(wmask)
				4'b0001: memory[waddr] <= wdata[ 7: 0];
				4'b0010: memory[waddr+1] <= wdata[15: 8];
				4'b0100: memory[waddr+2] <= wdata[23:16];
				4'b1000: memory[waddr+3] <= wdata[31:24];
				4'b0011: {memory[waddr+1],memory[waddr]} <= wdata[15:0];
				4'b1100: {memory[waddr+3],memory[waddr+2]} <= wdata[31:16];
				4'b1111: {memory[waddr+3],memory[waddr+2],memory[waddr+1],memory[waddr]} <= wdata;
			default: begin
			end
			endcase
		end
	end

	assign rdata = {memory[raddr+3],memory[raddr+2],memory[raddr+1],memory[raddr]};

endmodule

module ysyx_24110017_UART(
  input wire clock,
  input wire reset,
	input wire wen,
	input wire [ 7:0]wdata
);

always @(posedge clock) begin
	if(wen) begin
    $write("%c",wdata);
	end
end

endmodule
