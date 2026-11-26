module hex(
    input [3:0] hex,
    output reg [6:0] seg        // 数码管 HEX
);

always @(*) begin

case (hex)
    4'h0: seg = 7'b0000001; // 0: A-F亮, G灭 -> 0000001
    4'h1: seg = 7'b1001111; // 1: B,C亮 -> A=1, B=0, C=0, D=1, E=1, F=1, G=1
    4'h2: seg = 7'b0010010; // 2: A,B,D,E,G亮
    4'h3: seg = 7'b0000110; // 3: A,B,C,D,G亮
    4'h4: seg = 7'b1001100; // 4: B,C,F,G亮
    4'h5: seg = 7'b0100100; // 5: A,C,D,F,G亮
    4'h6: seg = 7'b0100000; // 6: A,C,D,E,F,G亮
    4'h7: seg = 7'b0001111; // 7: A,B,C亮
    4'h8: seg = 7'b0000000; // 8: 全亮
    4'h9: seg = 7'b0000100; // 9: A,B,C,D,F,G亮
    4'hA: seg = 7'b0001000; // A: A,B,C,E,F,G亮
    4'hB: seg = 7'b1100000; // B: C,D,E,F,G亮
    4'hC: seg = 7'b0110001; // C: A,D,E,F亮
    4'hD: seg = 7'b1000010; // D: B,C,D,E,G亮
    4'hE: seg = 7'b0110000; // E: A,D,E,F,G亮
    4'hF: seg = 7'b0111000; // F: A,E,F,G亮
    default: seg = 7'b1111111;
endcase

end

endmodule