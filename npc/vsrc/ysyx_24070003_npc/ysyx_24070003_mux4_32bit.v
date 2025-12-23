module ysyx_24070003_mux4_32bit(
    input [1:0] sel,
    input [31:0] a, 
    input [31:0] b,
    input [31:0] c,
    input [31:0] d,
    output reg [31:0] out
);
    always @(*) begin
        case(sel)
            2'b00: out = a;
            2'b01: out = b;
            2'b10: out = c;
            2'b11: out = d;
        endcase
    end
endmodule
