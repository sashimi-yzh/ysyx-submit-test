module PS2(
	input CLK,
	input CLRN,
	output [7:0]seg0L,
	output [7:0]seg0H,
	output [7:0]seg1L,
	output [7:0]seg1H,
	output [7:0]seg2L,
	output [7:0]seg2H,
	output [7:0]seg3L,
	output [7:0]seg3H,
	output [7:0]data,
	input PS2_CLK,
	input PS2_DAT
);
wire ready,overflow;
reg nextdata_n;
reg [23:0]receiveData;
wire [7:0] ascii_out;
reg displayEnable;
reg ifPressed;
//reg [7:0]ascii;
reg [7:0]count;
reg status,nextstatus;
keycode_to_ascii u_keycode_to_ascii (
    .scancode(receiveData[7:0]),
    .ascii(ascii_out),
    .valid()
);
assign seg0L[0]=1;
assign seg0H[0]=1;
assign seg1L[0]=1;
assign seg1H[0]=1;
assign seg2L[0]=1;
assign seg2H[0]=1;
assign seg3L[0]=1;
assign seg3H[0]=1;
SevenSegDecoder segdec0(receiveData[03:00],seg0L[7:1],displayEnable);
SevenSegDecoder segdec1(receiveData[07:04],seg0H[7:1],displayEnable);
SevenSegDecoder segdec2(ascii_out[3:0],seg1L[7:1],displayEnable);
SevenSegDecoder segdec3(ascii_out[7:4],seg1H[7:1],displayEnable);
SevenSegDecoder segdec4(receiveData[19:16],seg2L[7:1],0);
SevenSegDecoder segdec5(receiveData[23:20],seg2H[7:1],0);
SevenSegDecoder segdec6(count[3:0],seg3L[7:1],1);
SevenSegDecoder segdec7(count[7:4],seg3H[7:1],1);


ps2_keyboard inst(
			.clk(CLK),
			.clrn(CLRN),
			.ps2_clk(PS2_CLK),
			.ps2_data(PS2_DAT),
			.data(data),
			.ready(ready),
			.nextdata_n(nextdata_n),
			.overflow(overflow)
);

always @(posedge CLK)begin
	if(CLRN==0)begin
		nextdata_n<=1;
		status<=0;
		ifPressed<=0;
	end else begin
		if(status==1)begin
			ifPressed<=0;
		end else if(status==0&&ready==1&&ifPressed==0&&nextstatus==0)begin
			ifPressed<=1;
			count<=count+1;
		end
		status<=nextstatus;
		if(nextdata_n==0)begin
			nextdata_n<=1;
		end
		else if(ready) begin
			receiveData[7:0]<=data;
			nextdata_n<=0;
		end
	end
end
always @(*)begin
	if(status)begin
		nextstatus=0;
	end else begin
		if(receiveData[7:0]==8'hF0)
			nextstatus=1;
		else
			nextstatus=0;
	end
end

always @(*)begin
	displayEnable=ifPressed;
end

endmodule
