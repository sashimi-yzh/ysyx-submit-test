module SevenSegDecoder(
    input [3:0] hex,      // 4位十六进制输入
    output reg [6:0] seg,  // 7段输出 (A,B,C,D,E,F,G)
	input enable
);

always @(*) begin
	if (enable) begin
	    case(hex)
    	    4'h0: seg = 7'b0000001;  // 0 -> 0x01
       		 4'h1: seg = 7'b1001111;  // 1 -> 0x4F
       		 4'h2: seg = 7'b0010010;  // 2 -> 0x12
       		 4'h3: seg = 7'b0000110;  // 3 -> 0x06
       		 4'h4: seg = 7'b1001100;  // 4 -> 0x4C
       		 4'h5: seg = 7'b0100100;  // 5 -> 0x24
       		 4'h6: seg = 7'b0100000;  // 6 -> 0x20
       		 4'h7: seg = 7'b0001111;  // 7 -> 0x0F
       		 4'h8: seg = 7'b0000000;  // 8 -> 0x00
       		 4'h9: seg = 7'b0000100;  // 9 -> 0x04
       		 4'hA: seg = 7'b0001000;  // A -> 0x08
       		 4'hB: seg = 7'b1100000;  // b -> 0x60
       		 4'hC: seg = 7'b0110001;  // C -> 0x31
       		 4'hD: seg = 7'b1000010;  // d -> 0x42
       		 4'hE: seg = 7'b0110000;  // E -> 0x30
      		 4'hF: seg = 7'b0111000;  // F -> 0x38
      		 default: seg = 7'b1111111; // 熄灭
   		 endcase
	end
	else
		seg=7'b1111111;
end

endmodule
