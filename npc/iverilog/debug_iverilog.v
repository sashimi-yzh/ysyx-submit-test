`ifndef SYNTHESIS
//`ifdef VERILATOR
//`endif
`endif
module ysyx_23060246_InstInvalid(
    input isvalid,
    input clock,
    input reset
);

`ifndef SYNTHESIS
//`ifdef VERILATOR
always @(posedge clock) begin
    if(!isvalid & !reset)begin
        $display("\33[1;31mInst Invalid!\33[0m");
		$finish;
    end
end
//`endif
`endif

endmodule


module ysyx_23060246_Ebreak(
    input isebreak,
    input clock,
    input reset
);

`ifndef SYNTHESIS
always @(posedge clock) begin
    if(isebreak & !reset)begin
	  	$display("\33[1;34mEBreak!\33[0m");
		$finish;
    end
end
`endif

endmodule

//module AXIError(
//    input [1:0] bresp,
//    input [1:0] rresp,
//    input wen,
//    input ren
//);
//
//`ifndef SYNTHESIS
////`ifdef VERILATOR
////always @(*) begin
////    if(wen & bresp[1]) begin
////        axi_error({6'b0,bresp}, 8'b0);
////    end
////
////    if(ren & rresp[1]) begin
////        axi_error({6'b0,rresp}, 8'b1);
////    end
////end
////`endif
//`endif
//
//endmodule
