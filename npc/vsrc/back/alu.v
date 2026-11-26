module alu(
    input  [3:0] A,      // 操作数 A (补码)
    input  [3:0] B,      // 操作数 B (补码)
    input  [2:0] sel,      // 功能选择信号
    output reg  [3:0] out, // 运算结果
    output wire        Z,  // 零标志位 (Zero): 结果为0则置1
    output wire        O,  // 溢出标志位 (Overflow): 仅加减法有效
    output wire        C   // 进位/借位标志位 (Carry): 仅加减法有效
);

    // 内部信号
    wire [3:0] sum_add;  // 加法结果
    wire [3:0] sum_sub;  // 减法结果
    wire       c_add;    // 加法进位
    wire       c_sub;    // 减法进位 (用于判断借位)
    wire       of_add;   // 加法溢出
    wire       of_sub;   // 减法溢出
    wire       slt;      // 带符号小于 (seligned Less Than)

    // --- 加法器与减法器实例 ---
    // 加法: A + B
    assign {c_add, sum_add} = A + B;
    // 减法: A - B = A + (~B + 1)
    assign {c_sub, sum_sub} = {1'b0, A} + {1'b0, ~B} + 1'b1;

    // --- 溢出判断逻辑 ---
    // 加法溢出: 操作数符号相同，但结果符号不同
    assign of_add = (A[3] == B[3]) && (sum_add[3] != A[3]);
    // 减法溢出: 操作数符号不同，且结果符号与A不同 (相当于正-负=负 或 负-正=正)
    assign of_sub = (A[3] != B[3]) && (sum_sub[3] != A[3]);

    // --- 比较大小逻辑 (带符号) ---
    // 如果 A < B，则 (A - B) 应该是负数。
    // 如果没有溢出，看 sum_sub[3] (符号位)。
    // 如果发生溢出，符号位取反才是真实结果。
    assign slt = sum_sub[3] ^ of_sub;

    // --- 主运算逻辑 ---
    always @(*) begin
        case (sel)
            3'b000: out = sum_add;          // 加法 (A + B)
            3'b001: out = sum_sub;          // 减法 (A - B)
            3'b010: out = ~A;               // 取反
            3'b011: out = A & B;            // 与
            3'b100: out = A | B;            // 或
            3'b101: out = A ^ B;            // 异或
            3'b110: out = {3'b0, slt};      // 比较大小 (A<B ? 1 : 0)
            3'b111: out = {3'b0, (A == B)}; // 判断相等 (A==B ? 1 : 0)
            default: out = 4'b0;
        endcase
    end

    // --- 标志位输出逻辑 ---
    // 零标志位：所有运算结果都判断是否为0
    assign Z = (out == 4'b0);

    // 溢出标志位：仅在加减法时有效，逻辑操作时输出0
    assign O = (sel == 3'b000) ? of_add : 
               (sel == 3'b001) ? of_sub : 1'b0;

    // 进位标志位：
    // 加法：直接取进位 c_add
    // 减法：取反 c_sub (c_sub=1表示无借位/A>=B，c_sub=0表示有借位/A<B)
    // 逻辑操作：输出0
    assign C = (sel == 3'b000) ? c_add : 
               (sel == 3'b001) ? ~c_sub : 1'b0;

endmodule
