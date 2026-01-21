module ysyx_25050136_ALU
     (
         input  [31:0]                          op1_i,
         input  [31:0]                          op2_i,
         input  [3:0]                            op_i,
         output [31:0]                          out_o
     );
    // 加法器用作加法/减法/比较
    wire [31:0] adder_op2;
    wire        adder_cin;
    wire        adder_cout;
    wire [31:0] adder_result;
    wire slt_res;
    wire sltu_res;

    assign adder_cin = (op_i == `ysyx_25050136_ALU_SUB || op_i == `ysyx_25050136_ALU_SLT || op_i == `ysyx_25050136_ALU_SLTU);
    assign adder_op2 = adder_cin ? ~op2_i : op2_i;
    assign {adder_cout, adder_result} = op1_i + adder_op2 + {31'b0, adder_cin};
    assign slt_res = (op1_i[31] ^ op2_i[31]) ? op1_i[31] : adder_result[31];
    assign sltu_res = ~adder_cout;
    // 移位器
    wire [31:0] sra_result = $signed(op1_i) >>> op2_i[4:0];
    wire [31:0] srl_result = op1_i >> op2_i[4:0];
    wire [31:0] sll_result = op1_i << op2_i[4:0];
    reg [31:0] out;
    always @(*) begin
        case (op_i)
            `ysyx_25050136_ALU_ADD:  out = adder_result;
            `ysyx_25050136_ALU_SUB:  out = adder_result;
            `ysyx_25050136_ALU_XOR:  out = op1_i ^ op2_i;
            `ysyx_25050136_ALU_OR:   out = op1_i | op2_i;
            `ysyx_25050136_ALU_AND:  out = op1_i & op2_i;
            `ysyx_25050136_ALU_SLTU: out = {{31{1'b0}},sltu_res};
            `ysyx_25050136_ALU_SLT:  out = {{31{1'b0}},slt_res};
            `ysyx_25050136_ALU_SRA:  out = sra_result;
            `ysyx_25050136_ALU_SLL:  out = sll_result;
            `ysyx_25050136_ALU_SRL:  out = srl_result;
            `ysyx_25050136_ALU_OPD2: out = op2_i;
            default:                 out = 0;     
        endcase
    end
    assign out_o = out;
endmodule //ysyx_25050136_ALU
