module ALU(
	input [3:0]inA,
	input [3:0]inB,
	input [2:0]mode,
	output reg [3:0]out,
	output reg CF,
	output reg ZF,
	output reg OF	
);
	wire cin;
	assign cin=(mode==3'b001) ? 1 : 0;
	wire [3:0]inB_modified=cin?~inB:inB;
	wire [4:0]sum;
	wire [3:0] diff = inA + ~inB + 4'b0001;
	assign sum={1'b0,inA}+{1'b0,inB_modified}+{4'b0000,cin};
	assign CF=cin?~sum[4]:sum[4];
	assign OF=(inA[3]==inB_modified[3])&&(sum[3] != inA[3]);
	always @(*)	begin
		case(mode)
			3'b000:out=sum[3:0];
			3'b001:out=sum[3:0];
			3'b010:out=~inA;
			3'b011:out=inA&inB;
			3'b100:out=inA|inB;
			3'b101:out=inA^inB;
			3'b110:
                out = {3'b000,{(inA[3] != inB[3]) ? inA[3] : diff[3]}};
			3'b111:out=(diff[3:0]==4'b0000)?4'b0001:4'b0000;
			default:out=4'b0000;
		endcase
	end
	assign ZF= ~|out[3:0];
endmodule
