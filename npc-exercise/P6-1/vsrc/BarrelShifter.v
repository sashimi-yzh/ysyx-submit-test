module BarrelShifter(
	input [7:0]din,
	input [2:0]shamt,
	input dir,
	input mode,
	output [7:0]dout
);
	wire [7:0]shift1;
	wire [7:0]shift2;
	wire [7:0]shift4;
	assign shift1=(shamt[0])?((!dir)?((mode)?({   din[7]     ,din[7:1]   }):({1'b0,din[7:1]   })):({din[6:0]   ,1'b0})):(din   );
	assign shift2=(shamt[1])?((!dir)?((mode)?({{2{shift1[7]}},shift1[7:2]}):({2'b0,shift1[7:2]})):({shift1[5:0],2'b0})):(shift1);
	assign shift4=(shamt[2])?((!dir)?((mode)?({{4{shift2[7]}},shift2[7:4]}):({4'b0,shift2[7:4]})):({shift2[3:0],4'b0})):(shift2);
	assign dout=shift4;
endmodule
