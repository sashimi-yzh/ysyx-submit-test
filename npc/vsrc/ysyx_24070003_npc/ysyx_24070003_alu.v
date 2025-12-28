

module ysyx_24070003_alu(
    input clock,
    input [31:0] opdata1,
    input [31:0] opdata2,
    input branch,
    input u_alu_type,
    input [3:0] alu_crtl,
    output reg [31:0] alu_out,
    output  zero
);


wire [1:0] logic_ctl;
wire [1:0] shift_ctl;
wire       sub_ctl;
wire [1:0] data_choice;

wire ADD_zero;

assign logic_ctl = alu_crtl[1:0];
assign shift_ctl = alu_crtl[1:0];
assign data_choice = alu_crtl[3:2];
assign sub_ctl = (~ alu_crtl[3]  & ~alu_crtl[2]  & alu_crtl[1]) | ( alu_crtl[3]  & ~alu_crtl[2]);
//*********************logic op***************************
reg [31:0] logic_result;

always@(*) begin
    case(logic_ctl)
	2'b00:logic_result = opdata1 & opdata2;
	2'b01:logic_result = opdata1 | opdata2;
	2'b10:logic_result = opdata1 ^ opdata2;
    2'b11:logic_result = opdata1 | opdata2;
	endcase
end 
//************************shift op************************
wire [5:0]     ALU_SHIFT;
wire [31:0] shift_result;
assign ALU_SHIFT=opdata2[5:0];

ysyx_24070003_Shifter myShifter(.ALU_DA(opdata1),
                .ALU_SHIFT(ALU_SHIFT),
				.Shiftctr(shift_ctl),
				.shift_result(shift_result));

//************************add sub op**********************
wire [31:0] BIT_M,XOR_M;
wire ADD_carry,ADD_OverFlow;
wire [31:0] ADD_result;

assign BIT_M={32{sub_ctl}};
assign XOR_M=BIT_M^opdata2;

ysyx_24070003_Adder Adder(.A(opdata1),
            .B(XOR_M),
			.Cin(sub_ctl),
			.ALU_CTL(alu_crtl),
			.ADD_carry(ADD_carry),
			//.ADD_OverFlow(ADD_OverFlow),
			.ADD_zero(ADD_zero),
			.ADD_result(ADD_result));



//********************************************************
//**************************slt op************************
wire [31:0] SLT_result;
wire LESS_M1,LESS_M2,LESS_S,SLT_M;
wire BLT,BGE,BNE,BEQ;
//assign ADD_OverFlow = (opdata1[31] & ~opdata2[31]) | ((opdata1[31] ~^ opdata2[31]) & ADD_result[31]); 
assign BLT = (alu_crtl[3]  & ~alu_crtl[2]  &  ~alu_crtl[1]  & ~alu_crtl[0]);
assign BGE = (alu_crtl[3]  & ~alu_crtl[2]  &  ~alu_crtl[1]  &  alu_crtl[0]);
assign BNE = (alu_crtl[3]  & ~alu_crtl[2]  &   alu_crtl[1]  & ~alu_crtl[0]);
assign BEQ = (alu_crtl[3]  & ~alu_crtl[2]  &   alu_crtl[1]  &  alu_crtl[0]);
assign zero = (BLT &  branch  &  LESS_S)   |
              (BGE & ~LESS_S)   |
              (BNE & ~ADD_zero) |
              (BEQ &  ADD_zero) ;

assign LESS_M1 = ADD_carry ^ sub_ctl;
assign LESS_M2 = (opdata1[31] & ~opdata2[31]) | ((opdata1[31] ~^ opdata2[31]) & ADD_result[31]);
assign LESS_S = (u_alu_type)?LESS_M1:LESS_M2;
assign SLT_result = (LESS_S)?32'h00000001:32'h00000000;
//708,687,567
always @(*) 
begin
  case(data_choice)
     2'b00:alu_out=ADD_result;
     2'b01:alu_out=logic_result;
     2'b10:alu_out=SLT_result;
     2'b11:alu_out=shift_result; 
  endcase
end

endmodule

module ysyx_24070003_Shifter(input [31:0] ALU_DA,
               input [5:0] ALU_SHIFT,
			   input [1:0] Shiftctr,
			   output reg [31:0] shift_result);
			
     wire [63:0] tmp_res;
     always@(*) begin
	   case(Shiftctr)
	   2'b00:shift_result = ALU_DA << ALU_SHIFT[4:0];
	   2'b01:shift_result = ALU_DA >> ALU_SHIFT[4:0];
	   2'b10:shift_result = tmp_res[31:0];
	   default:shift_result = ALU_DA;
	   endcase
	 end
assign tmp_res = {{{32{ALU_DA[31]}}, ALU_DA} >> ALU_SHIFT};

endmodule

//*************************************************************
//***********************************adder*********************


module ysyx_24070003_Adder(input [31:0] A,
             input [31:0] B,
			 input Cin,
			 input [3:0] ALU_CTL,
			 output ADD_carry,
			 //output ADD_OverFlow,
			 output ADD_zero,
			 output [31:0] ADD_result);


    assign {ADD_carry,ADD_result}=A+B+Cin;


   assign ADD_zero = ~(|ADD_result);
//    assign ADD_OverFlow=((~Cin) & ~A[31] & ~B[31] & ADD_result[31]) 
//                       | ((~Cin) & A[31] & B[31] & ~ADD_result[31])
//                       | ((Cin) & A[31] & ~B[31] & ~ADD_result[31]) 
// 					  | ((Cin) & ~A[31] & B[31] & ADD_result[31]);
     
endmodule
