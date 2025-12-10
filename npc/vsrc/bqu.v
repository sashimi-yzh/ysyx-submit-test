module ysyx_25050136_BQU
   (
      input  [31:0]                      op1_i,
      input  [31:0]                      op2_i,
      input  [5:0]                        op_i,
      output                             out_o
   );
   parameter OP_EQ  = 6'b000001;
   parameter OP_NE  = 6'b000010;
   parameter OP_SLT = 6'b000100;
   parameter OP_SGE = 6'b001000;
   parameter OP_ULT = 6'b010000;
   parameter OP_UGE = 6'b100000;

   wire is_equal = (op1_i == op2_i);
   wire is_slt   = ($signed(op1_i) < $signed(op2_i));
   wire is_ult   = (op1_i < op2_i);
   reg out;
   always @(*) begin
      case (op_i)
         OP_EQ:  out = is_equal;
         OP_NE:  out = ~is_equal;
         OP_SLT: out = is_slt;
         OP_SGE: out = ~is_slt;
         OP_ULT: out = is_ult;
         OP_UGE: out = ~is_ult;
         default: out = 1'b0;
      endcase
   end
   assign out_o = out;
endmodule
