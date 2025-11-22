module ALU (
    input      [ 3:0]  alu_op,
    input      [31:0]  a,
    input      [31:0]  b,
    output reg [31:0]  result,
    output reg         zero,
    output reg         less
);
    // ALU 操作码
    localparam ALU_ADD   = 4'b0000;
    localparam ALU_SUB   = 4'b0001;
    localparam ALU_AND   = 4'b0010;
    localparam ALU_OR    = 4'b0011;
    localparam ALU_XOR   = 4'b0100;//xor,xori
    localparam ALU_SLL   = 4'b0101;//sll,slli
    localparam ALU_SLTU  = 4'b0110;//sltiu,sltu
    localparam ALU_SLT   = 4'b0111;
    localparam ALU_SRA   = 4'b1000;//sra,srai
    localparam ALU_SRL   = 4'b1001;//srl,srli


    always @(*) begin
        case(alu_op)
            ALU_SLT:  less=($signed(a) < $signed(b)) ? 1'b1 : 1'b0;//有符号比较
            ALU_SLTU: less=(a < b) ? 1'b1 : 1'b0;//无符号比较
            default:  less=($signed(a) < $signed(b)) ? 1'b1 : 1'b0;
        endcase
        case (alu_op)
            ALU_ADD:  result = a + b;  // 加法 (add, addi)
            ALU_SUB:  result = a - b;  // 减法 (sub, bne)
            ALU_AND:  result = a & b;  // 与 (and)
            ALU_OR:   result = a | b;  // 或 (or)
            ALU_XOR:  result = a ^ b;  // 异或(xor)
            ALU_SLTU: result = {31'b0, less};//无符号小于比较(sltiu,sltu)
            ALU_SLT:  result = {31'b0, less};
            ALU_SRA:  result = $signed(a) >>> b[4:0];//算术右移sra,srai
            ALU_SLL:  result = a << b[4:0];//逻辑左移sll,slli
            ALU_SRL:  result = a >> b[4:0];//逻辑右移，srl，srli
            default: begin
                result = 32'b0;
                $display("ALU : Unknown alu_op = %b",alu_op);
            end
        endcase
    end

    assign zero = (result == 32'b0);
endmodule
