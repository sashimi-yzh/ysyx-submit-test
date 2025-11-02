`ifndef __FOO_TB__
`define __FOO_TB__

`timescale 1ps/1ps
//`include "foo.v"


module foo_tb;
	reg clock;
	reg reset;
	reg arready ;

	
	wire arvalid ;
	wire check_assert ;
	reg check_quest ;
	reg readyFromIDU ;
	reg rlast ;
	wire rmem_quest ;
	wire rready ;
	reg rvalid ;
	reg stall_quest_exception_IFU ;
	reg stall_quest_fencei ;
	wire validToIDU ;
	wire [31:0] araddr ;
	wire [1:0] arburst ;
	wire [3:0] arid ;
	wire [7:0] arlen ;
	wire [2:0] arsize ;
	wire [31:0] inst ;
	reg [31:0] mtvec ;
	wire [31:0] pc ;
	reg [31:0] pc_jump ;
	reg [31:0] rdata ;
	reg [3:0] rid ;
	reg [1:0] rresp ;
	
	//parameter HEX_FILE = "none";
	//ysyxNonSoCFull_netlist  #(.HEX_FILE(HEX_FILE)) mytop (clock, reset);
	
	foo	myfoo (
clock,
reset,
check_quest,
stall_quest_fencei,
check_assert,
stall_quest_exception_IFU,
readyFromIDU,
validToIDU,
arvalid,
arready,
rvalid,
rready,
rlast,
rmem_quest,
pc_jump,
mtvec,
pc,
inst,
araddr,
arid,
arlen,
arsize,
arburst,
rdata,
rresp,
rid
);

	initial begin
		clock = 0;
		reset = 0;
		#30 reset = 1;
		//reset = 1;
		#100 reset = 0;//发生在下降沿,避免和posedge clk重叠
		//#8000000 $stop;
		#1000 $stop;
	end

	always #1 clock = ~clock;


	initial begin
		$display("sim begin...");
		$dumpfile("foo_tb.vcd");
		$dumpvars(0, foo_tb);
	end

endmodule


`endif
