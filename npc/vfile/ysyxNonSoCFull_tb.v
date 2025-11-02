`ifndef __YSYXNONSOCFULL_TB__
`define __YSYXNONSOCFULL_TB__

`timescale 1ps/1ps
//`include "ysyxNonSoCFull.v"

module ysyxNonSoCFull_tb;
	reg clock;
	reg reset;
	//wire [31:0] pc;
	//wire one_inst_done;
	
	parameter HEX_FILE = "none";

	ysyxNonSoCFull  #(.HEX_FILE(HEX_FILE)) mytop (clock, reset);

	initial begin
		clock = 0;
		reset = 1;
		#6 reset = 0;//发生在下降沿,避免和posedge clk重叠
		#5000000 $stop;
	end

	always #1 clock = ~clock;


	initial begin
		$display("sim begin...");
		//$dumpfile("ysyxNonSoCFull_tb.vcd");
		//$dumpvars(0, ysyxNonSoCFull_tb);
	end

endmodule


`endif
