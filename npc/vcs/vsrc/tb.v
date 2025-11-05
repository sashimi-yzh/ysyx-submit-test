module tb();

reg clk;
reg rst;

ysyxSoCTop soc(
    .clock(clk),
    .reset(rst)
);
initial begin
    rst = 1;
    #50;
    rst = 0;
end



initial begin
//    $fsdbDumpfile("tb.fsdb");
//    $fsdbDumpvars("+all");
	// $dumpfile("wave.vcd");
	// $dumpvars(0,tb);	
end

// initial begin
//
// 	#1100000
// 	$finish;
//
// end
//
//

initial begin
    clk = 0;
    forever begin
        #1 clk = ~clk;
    end
end

endmodule
