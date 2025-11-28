module ysyx_24100012_rom #(ADDR_WIDTH=32,DATA_WIDTH=32)(
    input [ADDR_WIDTH-1:0] addr,
    output reg [DATA_WIDTH-1:0] val
);
always@(*)
    case(addr)
        32'h80000000:   val=32'h00100513;       //addi a0 x0 1
        32'h80000004:   val=32'h00100513;       //addi a0 x0 1
        32'h80000008:   val=32'h00150513;       //addi a0 a0 1
        32'h8000000c:   val=32'h00150513;       //addi a0 a0 1
        32'h80000010:   val=32'h00150513;       //addi a0 a0 1
        32'h80000014:   val=32'h00150513;       //addi a0 a0 1
        32'h80000018:   val=32'h00108073;       //ebreak
        default:        val=32'h00100073;
    endcase
endmodule