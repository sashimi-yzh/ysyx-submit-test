`timescale 1ns/1ps

module tb_ysyx_23060299 (

);

reg clock, reset    ;

`ifndef NETLIST
	wire 		sim_end			;
	wire [31:0] return_value	;
`endif

always #10 clock = !clock    ;

initial begin
    clock   =   1'b1    ;
    reset   <=  1'b1    ;
    #21
    reset   <=  1'b0    ;
	
	$display("Start simulation");
	// $finish;

`ifdef WAVE_TRACE
	$dumpfile("iverilog_wave.fst");
	$dumpvars(0, tb_ysyx_23060299);
`endif

`ifndef NETLIST
	wait(sim_end == 1);
	$display("Simulation ended at time %0t ns", $time);
	if (return_value == 0) begin
		$display("HIT GOOD TRAP");
		$finish;
	end
	else begin
		$display("HIT BAD TRAP");
		$fatal;
	end
`endif

end

reg         io_master_awready;
wire        io_master_awvalid;
wire [31:0] io_master_awaddr;
wire [3:0]  io_master_awid;
wire [7:0]  io_master_awlen;
wire [2:0]  io_master_awsize;
wire [1:0]  io_master_awburst;

reg         io_master_wready;
wire        io_master_wvalid;
wire [31:0] io_master_wdata;
wire [3:0]  io_master_wstrb;
wire        io_master_wlast;

wire        io_master_bready;
reg         io_master_bvalid;
wire [1:0]  io_master_bresp;
wire [3:0]  io_master_bid;

reg         io_master_arready;
wire        io_master_arvalid;
wire [31:0] io_master_araddr;
wire [3:0]  io_master_arid;
wire [7:0]  io_master_arlen;
wire [2:0]  io_master_arsize;
wire [1:0]  io_master_arburst;

wire        io_master_rready;
reg         io_master_rvalid;
wire [1:0]  io_master_rresp;
reg  [31:0] io_master_rdata;
wire        io_master_rlast;
wire [3:0]  io_master_rid;

parameter MEM_SIZE = 2**27;
reg  [7:0] memory [MEM_SIZE];
integer i;
initial begin
	$readmemh(`MEM_FILE, memory);
end

// write
reg  [31:0] write_addr;

assign io_master_bid = 0;
assign io_master_bresp = 0;
assign io_master_wlast = 1;

always @(posedge clock) begin
// io_master_awready
	if (reset) io_master_awready <= 1;
	else if (io_master_awready & io_master_awvalid) 
		io_master_awready <= 0;
	else if (io_master_bvalid & io_master_bready)
		io_master_awready <= 1;

// write_addr
	if (io_master_awready & io_master_awvalid)
		write_addr <= io_master_awaddr;

// io_master_wready
	if (reset) io_master_wready <= 0;
	else if (io_master_wvalid & io_master_wready)
		io_master_wready <= 0;
	else if (io_master_awvalid & io_master_awready)
		io_master_wready <= 1;

// pmem_write & write_wstrb
	if (io_master_wvalid & io_master_wready) begin
		if (write_addr == 32'ha00003f8) begin
			$write("%c", io_master_wdata[7:0]);
			$fflush();
		end
		else begin
			if (io_master_wstrb[0]) memory[{write_addr[26:2],2'b0}  ] <= io_master_wdata[7 :0 ];
			if (io_master_wstrb[1]) memory[{write_addr[26:2],2'b0}+1] <= io_master_wdata[15:8 ];
			if (io_master_wstrb[2]) memory[{write_addr[26:2],2'b0}+2] <= io_master_wdata[23:16];
			if (io_master_wstrb[3]) memory[{write_addr[26:2],2'b0}+3] <= io_master_wdata[31:24];
		end
	end

// io_master_bvalid
	if (reset) io_master_bvalid <= 0;
	else if (io_master_bvalid & io_master_bready)
		io_master_bvalid <= 0;
	else if (io_master_wvalid & io_master_wready)
		io_master_bvalid <= 1;
end

//read
reg  [31:0] read_addr;
reg  [7:0]  read_len;

assign io_master_rid = 0;
assign io_master_rresp = 0;
assign io_master_rlast = (read_len == 0);

always @(posedge clock) begin
// io_master_arready
	if (reset) io_master_arready <= 1;
	else if (io_master_arready & io_master_arvalid)
		io_master_arready <= 0;
	else if (io_master_rready & io_master_rvalid & (read_len == 0))
		io_master_arready <= 1;

// read_addr
	if (io_master_arready & io_master_arvalid)
		read_addr <= io_master_araddr + 4;
	else if (io_master_rready & io_master_rvalid)
		read_addr <= read_addr + 4;

// read_len
	if (io_master_arready & io_master_arvalid)
		if (io_master_arburst == 2'b01)
			read_len <= io_master_arlen;
		else read_len <= 0;
	else if (io_master_rvalid & io_master_rready & (read_len != 0))
		read_len <= read_len - 1;

// io_master_rvalid
	if (reset) io_master_rvalid <= 0;
	else if (io_master_rvalid & io_master_rready)
		if (read_len != 0) io_master_rvalid <= 1;
		else io_master_rvalid <= 0;
	else if (io_master_arvalid & io_master_arready)
		io_master_rvalid <= 1;

// io_master_rdata
	if (io_master_arvalid & io_master_arready) begin
		io_master_rdata[7 :0 ] <= memory[{io_master_araddr[26:2],2'b0}  ];
		io_master_rdata[15:8 ] <= memory[{io_master_araddr[26:2],2'b0}+1];
		io_master_rdata[23:16] <= memory[{io_master_araddr[26:2],2'b0}+2];
		io_master_rdata[31:24] <= memory[{io_master_araddr[26:2],2'b0}+3];
	end
	else if (io_master_rvalid & io_master_rready & (read_len != 0)) begin
		io_master_rdata[7 :0 ] <= memory[{read_addr[26:2],2'b0}  ];
		io_master_rdata[15:8 ] <= memory[{read_addr[26:2],2'b0}+1];
		io_master_rdata[23:16] <= memory[{read_addr[26:2],2'b0}+2];
		io_master_rdata[31:24] <= memory[{read_addr[26:2],2'b0}+3];
	end
end

ysyx_23060299 u_ysyx_23060299(
    .clock               (clock),
    .reset               (reset),
   
`ifndef NETLIST
`ifdef __ICARUS__
	.return_value(return_value),
	.sim_end(sim_end),
`endif
`endif

    .io_master_awready   (io_master_awready ),
    .io_master_awvalid   (io_master_awvalid ),
    .io_master_awaddr    (io_master_awaddr  ),
    .io_master_awid      (io_master_awid    ),
    .io_master_awlen     (io_master_awlen   ),
    .io_master_awsize    (io_master_awsize  ),
    .io_master_awburst   (io_master_awburst ),
    .io_master_wready    (io_master_wready  ),
    .io_master_wvalid    (io_master_wvalid  ),
    .io_master_wdata     (io_master_wdata   ),
    .io_master_wstrb     (io_master_wstrb   ),
    .io_master_wlast     (io_master_wlast   ),
    .io_master_bready    (io_master_bready  ),
    .io_master_bvalid    (io_master_bvalid  ),
    .io_master_bresp     (io_master_bresp   ),
    .io_master_bid       (io_master_bid     ),
    .io_master_arready   (io_master_arready ),
    .io_master_arvalid   (io_master_arvalid ),
    .io_master_araddr    (io_master_araddr  ),
    .io_master_arid      (io_master_arid    ),
    .io_master_arlen     (io_master_arlen   ),
    .io_master_arsize    (io_master_arsize  ),
    .io_master_arburst   (io_master_arburst ),
    .io_master_rready    (io_master_rready  ),
    .io_master_rvalid    (io_master_rvalid  ),
    .io_master_rresp     (io_master_rresp   ),
    .io_master_rdata     (io_master_rdata   ),
    .io_master_rlast     (io_master_rlast   ),
    .io_master_rid       (io_master_rid     ),

    .io_slave_awready    (),
    .io_slave_wready     (),
    .io_slave_bvalid     (),
    .io_slave_bresp      (), 
    .io_slave_bid        (),  
    .io_slave_arready    (), 
    .io_slave_rvalid     (),
    .io_slave_rresp      (),  
    .io_slave_rdata      (),  
    .io_slave_rlast      (),  
    .io_slave_rid        () 
);



    
endmodule