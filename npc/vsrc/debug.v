`ifndef SYNTHESIS
//`ifdef VERILATOR
import "DPI-C" function void npc_ebreak();
import "DPI-C" function void inst_invalid();
//import "DPI-C" function void axi_error(input byte unsigned errno, input byte unsigned isRead);//读错误还是写错误
//`endif
`endif
(* keep_hierarchy = 1 *)
(* keep = 1 *)
module ysyx_23060246_InstInvalid(
    input isvalid,
    input clock,
    input reset
);

`ifndef SYNTHESIS
//`ifdef VERILATOR
always @(posedge clock) begin
    if(!isvalid & !reset)begin
        inst_invalid();
    end
end
//`endif
`endif

endmodule


(* keep_hierarchy = 1 *)
(* keep = 1 *)
module ysyx_23060246_Ebreak(
    input isebreak,
    input clock,
    input reset
);

`ifndef SYNTHESIS
//`ifdef VERILATOR
always @(posedge clock) begin
    if(isebreak & !reset)begin
        npc_ebreak();
    end
end
//`endif
`endif

endmodule

//(* keep_hierarchy = 1 *)
//(* keep = 1 *)
//module AXIError(
//    input [1:0] bresp,
//    input [1:0] rresp,
//    input wen,
//    input ren
//);
//
//`ifndef SYNTHESIS
////`ifdef VERILATOR
//always @(*) begin
//    if(wen & bresp[1]) begin
//        axi_error({6'b0,bresp}, 8'b0);
//    end
//
//    if(ren & rresp[1]) begin
//        axi_error({6'b0,rresp}, 8'b1);
//    end
//end
////`endif
//`endif
//
//endmodule
