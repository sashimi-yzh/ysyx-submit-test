module ysyx_25010008_ALU (
    input [7:0] opcode,
    input [31:0] operand1,
    input [31:0] operand2,
    output reg [31:0] result
);

  always @(*) begin
    case (opcode)
      8'b0000_0000: result = operand1 + operand2;
      8'b0000_0010: result = operand1 ^ operand2;
      8'b0000_0100: result = operand1 | operand2;
      8'b0000_1000: result = operand1 & operand2;
      8'b0001_0000: result = operand1 << operand2[4:0];
      8'b0010_0000: result = operand1 >> operand2[4:0];
      8'b0100_0000: result = $signed(operand1) >>> operand2[4:0];
      8'b1000_0000: result = ~operand1 & operand2;
      8'b0000_0001: result = operand1 - operand2;
      8'b0000_0011: result = {31'b0, operand1 == operand2};
      8'b0000_0101: result = {31'b0, operand1 != operand2};
      8'b0000_1001: result = {31'b0, operand1 < operand2};
      8'b0001_0001: result = {31'b0, operand1 >= operand2};
      8'b0010_0001: result = {31'b0, $signed(operand1) < $signed(operand2)};
      8'b0100_0001: result = {31'b0, $signed(operand1) >= $signed(operand2)};
      default: result = 0;
    endcase
  end

endmodule
