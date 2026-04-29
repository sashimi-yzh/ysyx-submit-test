`timescale 1ns/1ps

module testbench;
reg clk;
reg rst;

always #5 clk = ~clk;

initial begin
		clk = 0;
		rst = 0;
		#10 rst = 1;
		repeat(30) @(posedge clk);
		rst = 0;
end

TestSoC dut (
		.clock(clk),
		.reset(rst)
);

wire exu_out_valid;
wire [31:0] exu_code;
wire [31:0] gpr_a0;

`ifdef SIM_NETLIST
	`ifdef IS_CI_ENV
		assign exu_out_valid = dut.cpu.\core/_exu_io_out_valid ;
		assign exu_code = {dut.cpu.\core/_idu_io_out_bits_code_raw , 2'b11};
		assign gpr_a0 = dut.cpu.\core/gprs/reg_10 ;
	`else
		assign exu_out_valid = dut.cpu.\core._exu_io_out_valid ;
		// assign exu_out_valid = dut.cpu.\core._exu_io_in_ready & dut.cpu.\core.
		assign exu_code = {dut.cpu.\core._idu_io_out_bits_code_raw , 2'b11};
		assign gpr_a0 = dut.cpu.\core.gprs.reg_10 ;
	`endif
`else
	assign exu_out_valid = dut.cpu.core.exu.io_out_valid;
	assign exu_code = {dut.cpu.core.exu.io_in_bits_code_raw, 2'b11};
	assign gpr_a0 = dut.cpu.core.gprs.reg_10;
`endif

always @(posedge clk) begin
	if (exu_out_valid && exu_code == 32'h00100073) begin // EBREAK
		$display("EBREAK instruction executed. Ending simulation.");
		if(gpr_a0 != 0) begin
			$display("HIT BAD TRAP a0 = %d", gpr_a0);
			$fatal;
		end else begin
			$display("HIT GOOD TRAP");
		end
		$finish;
	end
end

initial begin
  //   $dumpfile("wave.fst");
  //   $dumpvars(0, testbench);
		// #1000;
		// $finish;
end

endmodule
