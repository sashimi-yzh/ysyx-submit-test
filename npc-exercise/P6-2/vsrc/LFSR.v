module LFSR(
	input [7:0]in,
	input clk,
	output [7:0]out
);
	reg [7:0]buffer;
	always @(posedge clk)begin
		if(buffer[7:0]==8'b0)
			buffer<=in;
		else begin
			buffer<={(buffer[0]^buffer[2]^buffer[3]^buffer[4]),buffer[7:1]};
		end
	end
	assign out=buffer;
endmodule
