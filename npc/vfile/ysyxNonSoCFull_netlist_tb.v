`ifndef __YSYXNONSOCFULL_NETLIST_TB__
`define __YSYXNONSOCFULL_NETLIST_TB__

`timescale 1ps/1ps

module ysyxNonSoCFull_netlist_tb;
	reg clock;
	reg reset;
	//wire [31:0] pc;
	//wire one_inst_done;
	
	parameter HEX_FILE = "none";

	ysyxNonSoCFull_netlist  #(.HEX_FILE(HEX_FILE)) mytop (clock, reset);

	initial begin
		clock = 0;
		reset = 0;
		#30 reset = 1;
		//reset = 1;
		#100 reset = 0;//发生在下降沿,避免和posedge clk重叠
		//#8000000 $stop;
		#3300000 $stop;
	end

	always #1 clock = ~clock;


	initial begin
		$display("sim begin...");
		//$dumpfile("ysyxNonSoCFull_netlist_tb.vcd");
		//$dumpvars(0, ysyxNonSoCFull_netlist_tb);
	end

endmodule


`endif
