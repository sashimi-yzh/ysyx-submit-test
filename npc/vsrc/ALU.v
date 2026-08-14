module ALU (
  input [3:0] A,
  input [3:0] B,
  input [2:0] sel,
  output reg [3:0] Result,
  output Zero,
  output Carry,
  output Overflow
);

wire sub = (sel == 3'b001) || (sel == 3'b110) || (sel == 3'b111);
wire [3:0] Adder_Result;
wire Adder_Zero;
Adder Adder0(.A(A), .B(B), .Cin(sub), .Result(Adder_Result), .Zero(Adder_Zero), .Carry(Carry), .Overflow(Overflow));

always @(*) begin
  case (sel)
    3'b000: Result = Adder_Result; // ADD
    3'b001: Result = Adder_Result; // SUB
    3'b010: Result = ~A; // NOT
    3'b011: Result = A & B; // AND
    3'b100: Result = A | B; // OR
    3'b101: Result = A ^ B; // XOR
    3'b110: Result = (Overflow ^ Adder_Result[3]) ? 4'b0001 : 4'b0000; // SLT
    3'b111: Result = Adder_Zero ? 4'b0001 : 4'b0000; // SEQ
    default: Result = 4'b0000;
  endcase
end

assign Zero = ~(|Result); 
endmodule

module Adder(
  input [3:0] A,
  input [3:0] B,
  input Cin,
  output [3:0] Result,
  output Zero,
  output Overflow,
  output Carry
);

wire [3:0] t_no_Cin = {4{Cin}} ^ B;
wire Cout;
assign {Cout, Result} = (A + t_no_Cin) + {4'd0, Cin};
assign Overflow = ~(A[3] ^ t_no_Cin[3]) & (Result[3] ^ A[3]);
assign Zero = ~(|Result);
assign Carry = Cout ^ Cin;
endmodule
