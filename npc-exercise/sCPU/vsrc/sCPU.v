module sCPU(
	input clk,
	output [6:0]segH,
	output [6:0]segL,
	output reg [7:0]segnum,
	output reg [3:0]PC,
	output [7:0] temp,
	output [7:0] tempR1,
	output [7:0] tempR2,
	output [7:0] tempR3,
	output [7:0] tempR0,
	output [7:0] regA,
	output [7:0] regB
);
reg [7:0]R [0:3];
reg [1:0]CLKcounter;
reg [2:0]step;
wire liFlag;
wire addFlag;
wire bner0Flag;
wire outFlag;
wire [1:0]opcode;
wire [7:0]instant;
wire regWEN;
wire [1:0]regWCH;
wire PCJFlag;
//reg [7:0] regA,regB;
wire [1:0] regAAdd,regBAdd;
wire [7:0] added;
SevenSegDecoder SegL(segnum[3:0],segL);
SevenSegDecoder SegH(segnum[7:4],segH);
reg [7:0] PROGRAM [0:8];
initial begin
PROGRAM[0] = 8'h8A;
PROGRAM[1] = 8'h90;
PROGRAM[2] = 8'hA0;
PROGRAM[3] = 8'hB1;
PROGRAM[4] = 8'h17;
PROGRAM[5] = 8'h29;
PROGRAM[6] = 8'hD1;
PROGRAM[7] = 8'h42;
PROGRAM[8] = 8'hE3;
end
assign opcode=PROGRAM[PC][7:6];
assign liFlag=opcode[1]&~opcode[0];
assign addFlag=~opcode[1]&~opcode[0];
assign bner0Flag= &opcode;
assign outFlag=~opcode[1]&opcode[0];
assign instant={4'b0000,PROGRAM[PC][3:0]};
assign regWEN=addFlag|liFlag;
assign regWCH=PROGRAM[PC][5:4];
assign PCJFlag=bner0Flag& (regA!=regB);
assign regAAdd=PROGRAM[PC][1:0];
assign regBAdd=bner0Flag?2'b00:PROGRAM[PC][3:2];
always @(posedge clk)begin
	if(CLKcounter==2'b10)
		CLKcounter<=2'b00;
	else
		CLKcounter<=CLKcounter+2'b01;
end
always @(*)begin
	case(CLKcounter)
		2'b00:step=3'b001;
		2'b01:step=3'b010;
		2'b10:step=3'b100;
		default:step=3'b000;
	endcase
end
always @(posedge step[1])begin
	R[regWCH]<=(regWEN)?((addFlag)?added:instant):R[regWCH];
	segnum<=outFlag?regA:segnum;
end

always @(posedge step[2])begin
	if(PCJFlag)
		PC<=PROGRAM[PC][5:2];
	else
		PC<=PC+4'b0001;
end
always @(*)begin
	regA=R[regAAdd];
	regB=R[regBAdd];
	temp=added;
	tempR0=R[0];
	tempR1=R[1];
	tempR2=R[2];
	tempR3=R[3];
end
adder8 adder8_0 (regA,regB,added);
endmodule

module SevenSegDecoder(
    input [3:0] hex,      // 4位十六进制输入
    output reg [6:0] seg  // 7段输出 (A,B,C,D,E,F,G)
);

always @(*) begin
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

endmodule

module adder8(
	input [7:0]inA,
	input [7:0]inB,
	output [7:0]sum
);
wire [7:0]cout;
fadder fa0(inA[0],inB[0],0      ,sum[0],cout[0]);
fadder fa1(inA[1],inB[1],cout[0],sum[1],cout[1]);
fadder fa2(inA[2],inB[2],cout[1],sum[2],cout[2]);
fadder fa3(inA[3],inB[3],cout[2],sum[3],cout[3]);
fadder fa4(inA[4],inB[4],cout[3],sum[4],cout[4]);
fadder fa5(inA[5],inB[5],cout[4],sum[5],cout[5]);
fadder fa6(inA[6],inB[6],cout[5],sum[6],cout[6]);
fadder fa7(inA[7],inB[7],cout[6],sum[7],cout[7]);
endmodule

module fadder(
	input A,
	input B,
	input C,
	output S,
	output Cout
);
assign S=A^B^C;
assign Cout=(A&B)^(C&(A^B));
endmodule
