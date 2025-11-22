`timescale 1ns/1ps
module fpu (
    input             clk              ,
    input             reset            ,
    input             flush            ,
    input             fpu_op_valid     ,        // FPU操作请求
    input      [ 5:0] fpu_op_type      ,        // 操作类型
    input      [ 2:0] fpu_op_round     ,        // 舍入模式
    input      [31:0] operand1_fp      ,        // 浮点操作数1 (frs1)
    input      [31:0] operand2_fp      ,        // 浮点操作数2 (frs2)
    /* verilator lint_off UNUSEDSIGNAL */
    input      [31:0] operand3_fp      ,        // 浮点操作数3 (frs3, 用于FMA)
    /* verilator lint_on UNUSEDSIGNAL */
    input      [31:0] operand4_int     ,        // 整数操作数 (rs1)
    output reg        fpu_ready        ,        // FPU准备好接收新指令
    input             downstream_valid ,        // 下游准备好
    output reg [31:0] fpu_result       ,        // 浮点结果
    output reg [31:0] int_result       ,        // 整数结果
    output reg [ 4:0] exception_flags  ,        // 异常标志
    output reg        fpu_result_valid          // 结果有效
);
// 操作码
localparam FMV_W_X  = 6'b000001;
localparam FMV_X_W  = 6'b000010;
localparam FLW      = 6'b000011;
localparam FSW      = 6'b000100;
localparam FSGNJ_S  = 6'b000101;
localparam FSGNJN_S = 6'b000110;
localparam FSGNJX_S = 6'b000111;
localparam FCLASS_S = 6'b001000;
localparam FADD_S   = 6'b001001;
localparam FSUB_S   = 6'b001010;
localparam FMUL_S   = 6'b001011;
localparam FDIV_S   = 6'b001100; 
localparam FMIN_S   = 6'b001101;
localparam FMAX_S   = 6'b001110;
localparam FEQ_S    = 6'b001111;
localparam FLE_S    = 6'b010000;
localparam FLT_S    = 6'b010001;
// 状态机
localparam IDLE     = 3'b000;
localparam EXECUTE  = 3'b001;
localparam MUL_WAIT = 3'b010;
localparam DIV_WAIT = 3'b011; 
localparam OUTPUT   = 3'b100;
reg [ 2:0] state, next_state; // 扩展状态机位宽
reg [31:0] temp_result;       // 结果寄存器
reg [31:0] temp_int_result;   // 整数结果寄存器
reg [ 4:0] temp_exception;    // 异常寄存器
reg        next_fpu_ready;
// 组合逻辑变量
reg [31:0] comb_result;
reg [31:0] comb_int_result;
reg [ 4:0] comb_exception;
reg [ 9:0] shift_amt;
reg [ 8:0] lzc;
reg [27:0] mant_for_round;
reg [ 9:0] true_exp1, true_exp2, max_exp;
reg [23:0] norm_mant1, norm_mant2;
reg [ 8:0] lead_zeros1, lead_zeros2;
reg [28:0] shifted_mant1, shifted_mant2;
reg [28:0] sum_mant;
reg [ 9:0] result_exp;
reg        result_sign;
reg        guard, round, sticky;
reg [47:0] prod_mant;
reg        sign2_eff;
// 舍入变量
reg [26:0] l_rounded_mant;
reg [24:0] l_rounded_mant_middle;
reg [ 9:0] l_rounded_exp;
reg        l_guard;
reg        l_round;
/* verilator lint_off UNUSEDSIGNAL */
reg        l_lsb;
reg        l_round_up;
reg [22:0] l_denorm_mant;
reg [ 9:0] l_shift_amt;
// MUL_WAIT 和 DIV_WAIT 存储指数
reg [ 9:0] stored_true_exp1, stored_true_exp2;
// Booth-Wallace 乘法器信号
reg [31:0] multiplier_mant1, multiplier_mant2;
wire [63:0] multiplier_product;
wire        multiplier_valid;

// 除法器信号
reg [31:0] div_dividend, div_divisor;
wire [31:0] div_quotient;
/* verilator lint_off UNUSEDSIGNAL */
wire [31:0] div_remainder;
wire        div_valid;
/* verilator lint_on UNUSEDSIGNAL */
reg continue_mul;
reg continue_div;
amultiplier mul_inst (
    .clk          (clk               ),
    .rst_n        (~reset            ),
    .multiplicand (multiplier_mant1  ),
    .multiplier   (multiplier_mant2  ),
    .is_signed    (1'b0              ), // 无符号乘法
    .product      (multiplier_product),
    .valid        (multiplier_valid  )
);
divider div_inst (
    .clk       (clk          ),
    .reset     (reset        ),
    .dividend  (div_dividend ),
    .divisor   (div_divisor  ),
    .is_signed (1'b0         ),
    .quotient  (div_quotient ),
    .remainder (div_remainder),
    .valid     (div_valid    )
);
wire        sign1  = operand1_fp[31];
wire [ 7:0] exp1   = operand1_fp[30:23];
wire [22:0] frac1  = operand1_fp[22:0];
wire        sign2  = operand2_fp[31];
wire [ 7:0] exp2   = operand2_fp[30:23];
wire [22:0] frac2  = operand2_fp[22:0];
wire is_nan1  = (exp1 == 8'hFF) && (frac1 != 0);
wire is_nan2  = (exp2 == 8'hFF) && (frac2 != 0);
wire is_snan1 = (exp1 == 8'hFF) && (frac1 != 0) && (frac1[22] == 0);
wire is_snan2 = (exp2 == 8'hFF) && (frac2 != 0) && (frac2[22] == 0);
wire is_inf1  = (exp1 == 8'hFF) && (frac1 == 0);
wire is_inf2  = (exp2 == 8'hFF) && (frac2 == 0);
wire is_zero1 = (exp1 == 0) && (frac1 == 0);
wire is_zero2 = (exp2 == 0) && (frac2 == 0);
wire is_denorm1 = (exp1 == 0) && (frac1 != 0);
wire is_denorm2 = (exp2 == 0) && (frac2 != 0);
wire [23:0] mant1 =  is_denorm1!=1 ? {1'b1, frac1} : {1'b0, frac1};
wire [23:0] mant2 =  is_denorm2!=1 ? {1'b1, frac2} : {1'b0, frac2};
always @(*) begin
    comb_result           = 32'h7FC00000; // 默认 NaN
    comb_int_result       = 32'h0;
    comb_exception        = 5'b0;
    shift_amt             = 0;
    lzc                   = 0;
    mant_for_round        = 0;
    true_exp1             = 0;
    true_exp2             = 0;
    max_exp               = 0;
    norm_mant1            = 0;
    norm_mant2            = 0;
    lead_zeros1           = 0;
    lead_zeros2           = 0;
    shifted_mant1         = 0;
    shifted_mant2         = 0;
    sum_mant              = 0;
    result_exp            = 0;
    result_sign           = 0;
    guard                 = 0;
    round                 = 0;
    sticky                = 0;
    prod_mant             = 0;
    sign2_eff             = 0;
    multiplier_mant1      = 0;
    multiplier_mant2      = 0;
    div_dividend          = 0;
    div_divisor           = 0;
    l_rounded_mant        = 0;
    l_rounded_mant_middle = 0;
    l_rounded_exp         = 0;
    l_guard               = 0;
    l_round               = 0;
    l_lsb                 = 0;
    l_round_up            = 0;
    l_denorm_mant         = 0;
    l_shift_amt           = 0;
    continue_div          = 0;
    continue_mul          = 0;
    if (state == EXECUTE) begin
        case (fpu_op_type)
            FMV_W_X: begin
                comb_result    = operand4_int;
                comb_exception = 5'b0;
            end
            FMV_X_W: begin
                comb_int_result = operand1_fp;
                comb_exception  = 5'b0;
            end
            FLW: begin
                comb_result    = operand1_fp;
                comb_exception = 5'b0;
            end
            FSW: begin
                comb_result    = operand1_fp;
                comb_exception = 5'b0;
            end
            FSGNJ_S: begin
                comb_result    = {operand2_fp[31], operand1_fp[30:0]};
                comb_exception = 5'b0;
            end
            FSGNJN_S: begin
                comb_result    = {~operand2_fp[31], operand1_fp[30:0]};
                comb_exception = 5'b0;
            end
            FSGNJX_S: begin
                comb_result    = {sign1 ^ sign2, operand1_fp[30:0]};
                comb_exception = 5'b0;
            end
            FCLASS_S: begin
                if (is_nan1) begin
                    comb_int_result = is_snan1 ? 32'h100 : 32'h200;
                end else if (is_inf1) begin
                    comb_int_result = sign1 ? 32'h1 : 32'h80;
                end else if (is_zero1) begin
                    comb_int_result = sign1 ? 32'h8 : 32'h10;
                end else if (is_denorm1) begin
                    comb_int_result = sign1 ? 32'h4 : 32'h20;
                end else begin
                    comb_int_result = sign1 ? 32'h2 : 32'h40;
                end
                comb_exception = 5'b0;
            end
            FADD_S, FSUB_S: begin
                sign2_eff = (fpu_op_type == FSUB_S) ? ~operand2_fp[31] : operand2_fp[31];
                if (is_nan1 || is_nan2) begin
                    if (is_nan1 && is_nan2) begin
                        comb_result = is_snan1 ? {operand1_fp[31:23], 1'b1, operand1_fp[21:0]} :
                                      is_snan2 ? {operand2_fp[31:23], 1'b1, operand2_fp[21:0]} : operand1_fp ;
                    end else begin
                        comb_result = is_nan1 ? (is_snan1 ? {operand1_fp[31:23], 1'b1, operand1_fp[21:0]} : operand1_fp) :
                                      (is_snan2 ? {operand2_fp[31:23], 1'b1, operand2_fp[21:0]} : operand2_fp);
                    end
                    comb_result[22:0]=23'h400000;
                    comb_exception[4] = 1;
                end else if (is_inf1 || is_inf2) begin
                    if (is_inf1 && is_inf2 && sign1 != sign2_eff) begin
                        comb_result = 32'h7FC00000;
                        comb_exception[4] = 1;
                    end else begin
                        comb_result = is_inf1 ? {sign1, 8'hFF, 23'b0} : {sign2_eff, 8'hFF, 23'b0};
                        comb_exception = 5'b0;
                    end
                end else if (is_zero1 && is_zero2) begin
                    comb_result    = {1'b0, 8'h00, 23'b0};
                    comb_exception = 5'b0;
                end else begin
                    // 次正常数归一化
                    if (is_denorm1) begin
                        lead_zeros1       = 0;
                        while (frac1[23-lead_zeros1] == 0 && lead_zeros1 < 23) lead_zeros1 = lead_zeros1 + 1;
                        norm_mant1        = {1'b0, frac1} << lead_zeros1;
                        norm_mant1[23]    = 1'b1;
                        true_exp1         = 10'h0 - lead_zeros1; //23
                        comb_exception[1] = 1;   
                    end else begin
                        norm_mant1        = mant1;
                        true_exp1         = {2'b0, exp1};  
                    end
                    if (is_denorm2) begin
                        lead_zeros2       = 0;
                        comb_exception[1] = 1;
                        while (frac2[23-lead_zeros2] == 0 && lead_zeros2 < 23) lead_zeros2 = lead_zeros2 + 1;
                        norm_mant2        = {1'b0, frac2} << lead_zeros2;
                        norm_mant2[23]    = 1'b1;
                        true_exp2         = 10'h0 - lead_zeros2; // -126 - lead_zeros2
                    end else begin
                        norm_mant2        = mant2;
                        true_exp2         = {2'b0, exp2};
                    end
                    // 指数对齐
                    if ($signed(true_exp1) >= $signed(true_exp2)) begin
                        max_exp       = true_exp1;
                        shifted_mant1 = {1'b0,norm_mant1, 4'b0};
                        shift_amt     = $signed(true_exp1) - $signed(true_exp2);
                        if ($signed(shift_amt) > 28) shift_amt = 28;
                        shifted_mant2 = {1'b0,norm_mant2, 4'b0} >> shift_amt;
                        sticky        = |({norm_mant2, 4'b0} << (28 - shift_amt));
                    end else begin
                        max_exp       = true_exp2;
                        shifted_mant2 = {1'b0,norm_mant2, 4'b0};
                        shift_amt     = $signed(true_exp2) - $signed(true_exp1);
                        if ($signed(shift_amt) > 28) shift_amt = 28;
                        shifted_mant1 = {1'b0,norm_mant1, 4'b0} >> shift_amt;
                        sticky        = |({norm_mant1, 4'b0} << (28 - shift_amt));
                    end
                    // 尾数运算
                    if (sign1 == sign2_eff) begin
                        sum_mant        = shifted_mant1 + shifted_mant2;
                        result_sign     = sign1;
                    end else begin
                        if ($signed(shifted_mant1) >= $signed(shifted_mant2)) begin
                            sum_mant    = shifted_mant1 - shifted_mant2;
                            result_sign = sign1;  
                        end else begin
                            sum_mant    = shifted_mant2 - shifted_mant1;
                            result_sign = sign2_eff;
                        end
                    end
                    // 归一化
                    if (sum_mant == 0) begin//////////////*////
                        result_exp  = 0;
                        result_sign = (sign1 & sign2_eff) ? 1'b1 : 1'b0;/////////////*//////////////////
                        guard       = 0;
                        round       = 0;
                        sticky      = 0;
                    end else if (sum_mant[28]) begin                       
                        sum_mant    = sum_mant >> 1;
                        result_exp  = max_exp + 1;
                        guard       = sum_mant[4];
                        round       = sum_mant[3];
                        sticky      = sum_mant[2] | sum_mant[1] | sum_mant[0];
                    end else begin
                        result_exp  = max_exp;
                        guard       = sum_mant[4];
                        round       = sum_mant[3];
                        sticky      = sum_mant[2] | sum_mant[1] | sum_mant[0];
                        lzc         = 0;
                        while (sum_mant[27-lzc] == 0 && lzc < 28 && $signed(result_exp) > -23) begin
                            lzc     = lzc + 1;
                        end 
                        if (lzc > 0) begin
                            //sticky = sticky | |(sum_mant[27:0] << (28 - lzc));
                            sum_mant   = sum_mant << lzc;
                            result_exp = result_exp - lzc;
                            guard      = sum_mant[4];
                            round      = sum_mant[3];
                            sticky     = sticky | sum_mant[2] | sum_mant[1] | sum_mant[0];
                        end    
                    end
                    // 舍入
                    l_rounded_mant        = sum_mant[27:1];
                    l_rounded_mant_middle = {1'b0,l_rounded_mant[26:3]};
                    l_rounded_exp         = result_exp; 
                    l_guard               = guard;
                    l_round               = round;
                    l_lsb                 = sum_mant[5];
                    l_round_up            = 1'b0;
                    case (fpu_op_round)
                        //3'b000: l_round_up = l_guard & (l_round | sticky | l_lsb); // RNE
                        3'b000:  l_round_up = (l_guard &  l_round &  ~(|sticky) ) | (l_round & |sticky);// RNE
                        3'b001:  l_round_up = 1'b0; // RTZ
                        3'b010:  l_round_up = ( l_round | sticky) & result_sign; // RDN
                        3'b011:  l_round_up = ( l_round | sticky) & ~result_sign; // RUP
                        3'b100:  l_round_up = l_round ; // RMM
                        default: l_round_up = 1'b0;
                    endcase
                    if (l_round_up) begin
                
                        //l_rounded_mant = sum_mant[27:1] + (1 << 3)
                        l_rounded_mant_middle = l_rounded_mant_middle + 1;
                        if (l_rounded_mant_middle[24]) begin
                            l_rounded_mant    = {l_rounded_mant_middle,l_rounded_mant[2:1]};
                            l_rounded_exp     = l_rounded_exp + 1;
                        end else begin
                            l_rounded_mant    = l_rounded_mant+(1 << 3);
                        end
                    end
                    // 溢出和次正常数处理
                    if ($signed(l_rounded_exp) >= 255) begin
                        comb_result    = {result_sign, 8'hFF, 23'b0};
                        comb_exception = detect_exceptions(1'b0, 1'b0, 1'b1, is_denorm1 || is_denorm2, 1'b1);
                    end else if ($signed(l_rounded_exp) < 0) begin                       
                        l_shift_amt    = 0 - $signed(l_rounded_exp);
                        if (l_shift_amt > 23) begin
                        l_denorm_mant  = 23'b0;
                        l_round        = (l_shift_amt == 24) ? l_rounded_mant[26] :0;
                        sticky         = (l_shift_amt == 24) ? sticky | |(l_rounded_mant[25:3]) : sticky | |(l_rounded_mant[26:3]) ;
                        end else begin
                            l_denorm_mant = l_rounded_mant[26:4] >> (l_shift_amt-1);
                            sticky        = sticky | |(l_rounded_mant[26:3] << (25 - l_shift_amt));
                            l_round       = l_rounded_mant[l_shift_amt+2];
                        end       
                        l_guard = l_denorm_mant[0];
                        case (fpu_op_round)
                            //3'b000: l_round_up = l_guard & (l_round | sticky | l_lsb); // RNE
                            3'b000:  l_round_up = (l_guard &  l_round &  ~(|sticky) ) | (l_round & |sticky);// RNE
                            3'b001:  l_round_up = 1'b0; // RTZ
                            3'b010:  l_round_up = ( l_round | sticky) & result_sign; // RDN
                            3'b011:  l_round_up = ( l_round | sticky) & ~result_sign; // RUP
                            3'b100:  l_round_up = l_round ; // RMM
                            default: l_round_up = 1'b0;
                        endcase
                        l_denorm_mant  = (l_round_up == 1) ? l_denorm_mant+1 : l_denorm_mant ;
                        comb_result    = {result_sign, 8'h00, l_denorm_mant};
                        comb_exception = detect_exceptions(1'b0, 1'b0, 1'b0, 1'b1,  l_round | sticky);
                            end else begin
                                comb_result       = {result_sign, l_rounded_exp[7:0], l_rounded_mant[25:3]};
                                comb_exception[0] = ( l_round | sticky) ? 1'b1 :1'b0 ;
                            end
                        end
                    end
            FMUL_S: begin
                if (is_nan1 || is_nan2) begin
                    if (is_nan1 && is_nan2) begin
                        comb_result = is_snan1 ? {operand1_fp[31:23], 1'b1, operand1_fp[21:0]} :
                                      is_snan2 ? {operand2_fp[31:23], 1'b1, operand2_fp[21:0]} : operand1_fp ;
                        
                    end else begin
                        comb_result = is_nan1 ? (is_snan1 ? {operand1_fp[31:23], 1'b1, operand1_fp[21:0]} : operand1_fp) :
                                      (is_snan2 ? {operand2_fp[31:23], 1'b1, operand2_fp[21:0]} : operand2_fp);
                        
                        
                    end
                    comb_result[22:0] = 23'h400000;
                    comb_exception[4] = 1;

                end else if ((is_inf1 && is_zero2) || (is_inf2 && is_zero1)) begin
                    comb_result    = 32'h7FC00000;///***************////
                    comb_exception = 5'b10000;
                end else if (is_inf1 || is_inf2) begin
                    comb_result    = {(sign1 ^ sign2), 8'hFF, 23'b0};
                    comb_exception = 5'b0;
                end else if (is_zero1 || is_zero2) begin
                    comb_result    = {1'b0, 8'h00, 23'b0};
                    comb_exception = 5'b0;
                end else begin
                    // 次正常数归一化
                    if (is_denorm1) begin
                        lead_zeros1    = 0;
                        while (frac1[22-lead_zeros1] == 0 && lead_zeros1 < 23) lead_zeros1 = lead_zeros1 + 1;
                        norm_mant1     = {1'b0, frac1} << lead_zeros1;
                        norm_mant1[23] = 1'b1;
                        true_exp1      = 10'b0 - lead_zeros1;
                    end else begin
                        norm_mant1     = mant1;
                        true_exp1      = {2'b0, exp1};
                    end
                    if (is_denorm2) begin
                        lead_zeros2    = 0;
                        while (frac2[22-lead_zeros2] == 0 && lead_zeros2 < 23) lead_zeros2 = lead_zeros2 + 1;
                        norm_mant2     = {1'b0, frac2} << lead_zeros2;
                        norm_mant2[23] = 1'b1;
                        true_exp2      = 10'b0 - lead_zeros2;
                    end else begin
                        norm_mant2     = mant2;
                        true_exp2      = {2'b0, exp2};
                    end
                    // 启动乘法器
                    multiplier_mant1 = {8'b0, norm_mant1};
                    multiplier_mant2 = {8'b0, norm_mant2};
                    /*comb_result = 32'h7FC00000;
                    comb_exception = 5'b0;*/
                    continue_mul     = 1'b1;
                    // 调试输出
                    
                end
            end
            FDIV_S: begin
                if (is_nan1 || is_nan2) begin
                   if (is_nan1 && is_nan2) begin
                        comb_result = is_snan1 ? {operand1_fp[31:23], 1'b1, operand1_fp[21:0]} :
                                      is_snan2 ? {operand2_fp[31:23], 1'b1, operand2_fp[21:0]} :
                                      operand1_fp[22] ? operand1_fp : operand2_fp;
                        
                    end else begin
                        comb_result = is_nan1 ? (is_snan1 ? {operand1_fp[31:23], 1'b1, operand1_fp[21:0]} : operand1_fp) :
                                      (is_snan2 ? {operand2_fp[31:23], 1'b1, operand2_fp[21:0]} : operand2_fp);
                        
                    end
                    comb_result[22:0]=23'h400000;
                    comb_exception[4] = 1;
                end else if (is_zero2) begin
                    if (is_zero1) begin
                        comb_result = 32'h7FC00000; // 0/0 = NaN
                        comb_exception = 5'b10000;
                    end else if (is_inf1) begin
                        comb_result = {(sign1 ^ sign2), 8'hFF, 23'b0}; // Inf/0 = Inf
                        comb_exception = 5'b01001; // Divide by zero
                    end else begin
                        comb_result = {(sign1 ^ sign2), 8'hFF, 23'b0}; // x/0 = Inf
                        comb_exception = 5'b01001; // Divide by zero
                    end
                end else if (is_inf1 && is_inf2) begin
                    comb_result = 32'h7FC00000; // Inf/Inf = NaN
                    comb_exception = 5'b10000;
                end else if (is_inf1) begin
                    comb_result = {(sign1 ^ sign2), 8'hFF, 23'b0}; // Inf/x = Inf
                    comb_exception = 5'b0;
                end else if (is_zero1 && !is_inf2) begin
                    comb_result = {(sign1 ^ sign2), 8'h00, 23'b0}; // 0/x = 0
                    comb_exception = 5'b0;
                end else if (is_inf2) begin
                    comb_result = {(sign1 ^ sign2), 8'h00, 23'b0}; // x/Inf = 0
                    comb_exception = 5'b0;
                end else begin
                    // 次正常数归一化
                    if (is_denorm1) begin
                        lead_zeros1 = 0;
                        while (frac1[22-lead_zeros1] == 0 && lead_zeros1 < 23) lead_zeros1 = lead_zeros1 + 1;
                        norm_mant1 = {1'b0, frac1} << lead_zeros1;
                        norm_mant1[23] = 1'b1;
                        true_exp1 = 10'b0 - lead_zeros1;
                    end else begin
                        norm_mant1 = mant1;
                        true_exp1 = {2'b0, exp1};
                    end
                    if (is_denorm2) begin
                        lead_zeros2 = 0;
                        while (frac2[22-lead_zeros2] == 0 && lead_zeros2 < 23) lead_zeros2 = lead_zeros2 + 1;
                        norm_mant2 = {1'b0, frac2} << lead_zeros2;
                        norm_mant2[23] = 1'b1;
                        true_exp2 = 10'h0 - lead_zeros2;
                    end else begin
                        norm_mant2 = mant2;
                        true_exp2 = {2'b0, exp2};
                    end
                    // 启动除法器
                    div_dividend = {8'b0, norm_mant1};
                    div_divisor = {8'b0, norm_mant2};
                    continue_div=1'b1;
                    /*comb_result = 32'h7FC00000;
                    comb_exception = 5'b0;*/
                    // 调试输出
                    /*if (fpu_op_type == FDIV_S && state == EXECUTE) begin
                        $display("FDIV_S: div_dividend=%h, div_divisor=%h", div_dividend, div_divisor);
                    end*/
                end
            end
            FMIN_S, FMAX_S, FEQ_S, FLT_S, FLE_S: begin
                // 保持原有逻辑不变
                if (fpu_op_type == FMIN_S) begin
                    if (is_nan1 || is_nan2) begin
                        comb_result = 32'h7FC00000;
                        comb_exception = 5'b10000;
                    end else if (is_zero1 && is_zero2) begin
                        comb_result = (~sign1 & sign2) ? operand2_fp : operand1_fp;
                        comb_exception = 5'b0;
                    end else if (sign1 == 0 && sign2 == 1) begin
                        comb_result = operand2_fp;
                        comb_exception = 5'b0;
                    end else if (sign1 == 1 && sign2 == 0) begin
                        comb_result = operand1_fp;
                        comb_exception = 5'b0;
                    end else begin
                        if (sign1 == 0) begin
                            comb_result = (exp1 < exp2 || (exp1 == exp2 && frac1 < frac2)) ? operand1_fp : operand2_fp;
                        end else begin
                            comb_result = (exp1 > exp2 || (exp1 == exp2 && frac1 > frac2)) ? operand1_fp : operand2_fp;
                        end
                        comb_exception = 5'b0;
                    end
                end else if (fpu_op_type == FMAX_S) begin
                    if (is_nan1 || is_nan2) begin
                        comb_result = 32'h7FC00000;
                        comb_exception = 5'b10000;
                    end else if (is_zero1 && is_zero2) begin
                        comb_result = (sign1 | sign2) ? 32'h00000000 : operand1_fp;
                        comb_exception = 5'b0;
                    end else if (sign1 == 0 && sign2 == 1) begin
                        comb_result = operand1_fp;
                        comb_exception = 5'b0;
                    end else if (sign1 == 1 && sign2 == 0) begin
                        comb_result = operand2_fp;
                        comb_exception = 5'b0;
                    end else begin
                        if (sign1 == 0) begin
                            comb_result = (exp1 > exp2 || (exp1 == exp2 && frac1 > frac2)) ? operand1_fp : operand2_fp;
                        end else begin
                            comb_result = (exp1 < exp2 || (exp1 == exp2 && frac1 < frac2)) ? operand1_fp : operand2_fp;
                        end
                        comb_exception = 5'b0;
                    end
                end else if (fpu_op_type == FEQ_S) begin
                    if (is_nan1 || is_nan2) begin
                        comb_int_result = 32'h0;
                        comb_exception =  5'b10000;
                    end else if (is_zero1 && is_zero2) begin
                        comb_int_result = 32'h1;
                        comb_exception = 5'b0;
                    end else begin
                        comb_int_result = (operand1_fp == operand2_fp) ? 32'h1 : 32'h0;
                        comb_exception = 5'b0;
                    end
                end else if (fpu_op_type == FLT_S) begin
                    if (is_nan1 || is_nan2) begin
                        comb_int_result = 32'h0;
                        comb_exception = 5'b10000;
                    end else if (is_zero1 && is_zero2) begin
                        comb_int_result = 32'h0;
                        comb_exception = 5'b0;
                    end else if (sign1 == 0 && sign2 == 1) begin
                        comb_int_result = 32'h0;
                        comb_exception = 5'b0;
                    end else if (sign1 == 1 && sign2 == 0) begin
                        comb_int_result = 32'h1;
                        comb_exception = 5'b0;
                    end else begin
                        if (sign1 == 0) begin
                            comb_int_result = (exp1 < exp2 || (exp1 == exp2 && frac1 < frac2)) ? 32'h1 : 32'h0;
                        end else begin
                            comb_int_result = (exp1 > exp2 || (exp1 == exp2 && frac1 > frac2)) ? 32'h1 : 32'h0;
                        end
                        comb_exception = 5'b0;
                    end
                end else if (fpu_op_type == FLE_S) begin
                    if (is_nan1 || is_nan2) begin
                        comb_int_result = 32'h0;
                        comb_exception = 5'b10000;
                    end else if (is_zero1 && is_zero2) begin
                        comb_int_result = 32'h1;
                        comb_exception = 5'b0;
                    end else if (sign1 == 0 && sign2 == 1) begin
                        comb_int_result = 32'h0;
                        comb_exception = 5'b0;
                    end else if (sign1 == 1 && sign2 == 0) begin
                        comb_int_result = 32'h1;
                        comb_exception = 5'b0;
                    end else begin
                        if (sign1 == 0) begin
                            comb_int_result = (exp1 <= exp2 && (exp1 != exp2 || frac1 <= frac2)) ? 32'h1 : 32'h0;
                        end else begin
                            comb_int_result = (exp1 >= exp2 && (exp1 != exp2 || frac1 >= frac2)) ? 32'h1 : 32'h0;
                        end
                        comb_exception = 5'b0;
                    end
                end
            end
            default: begin
                comb_result = 32'h7FC00000;
                comb_exception = 5'b10000;
            end
        endcase
    end else if (state == MUL_WAIT && multiplier_valid && fpu_op_type == FMUL_S ) begin
        prod_mant = multiplier_product[47:0];
        
        result_sign = sign1 ^ sign2;
        result_exp = $signed(stored_true_exp1) + $signed(stored_true_exp2) - 10'd127;////////*/////
                     
        // 初始溢出检查
        if ($signed(result_exp) >= 255) begin
            case (fpu_op_round)
                3'b000, 3'b001, 3'b100: comb_result = {result_sign, 8'hFF, 23'b0};
                3'b010: comb_result = result_sign ? {1'b1, 8'hFE, 23'h7FFFFF} : {1'b0, 8'hFF, 23'b0};
                3'b011: comb_result = result_sign ? {1'b1, 8'hFF, 23'b0} : {1'b0, 8'hFE, 23'h7FFFFF};
                default: comb_result = {result_sign, 8'hFF, 23'b0};
            endcase
            comb_exception = detect_exceptions(1'b0, 1'b0, 1'b1, 1'b0, 1'b1);
        end else begin
            // 增强归一化逻辑
            if (prod_mant[47]) begin 
                sticky = |(prod_mant[21:0]);
                prod_mant = prod_mant >> 1;
                result_exp = result_exp + 10'd1;
                guard = prod_mant[23];
                round = prod_mant[22];
                sticky = |(prod_mant[21:0]) | sticky;
            end else begin
                lzc = 0;
                while (prod_mant[46-lzc] == 0 && lzc < 24) lzc = lzc + 1;
                prod_mant = prod_mant << lzc;
                result_exp = result_exp - lzc;
                guard = prod_mant[23];
                round = prod_mant[22];
                sticky = |(prod_mant[21:0]);
            end
            mant_for_round = {prod_mant[47:23], round, 2'b0};
            // 舍入
            l_rounded_mant = mant_for_round[26:0];/****************/
            l_rounded_exp = result_exp;
            l_guard = guard;
            l_round = round;
            l_lsb = mant_for_round[4];
            l_round_up = 1'b0;

            case (fpu_op_round)
                3'b000: l_round_up = (l_guard &  l_round &  ~(|sticky) ) | (l_round & |sticky); // RNE
                3'b001: l_round_up = 1'b0; // RTZ
                3'b010: l_round_up = (l_round | sticky) & result_sign; // RDN
                3'b011: l_round_up = ( l_round | sticky) & ~result_sign; // RUP
                3'b100: l_round_up = l_round ; // RMM
                default: l_round_up = 1'b0;
            endcase
            if (l_round_up) begin
                //l_rounded_mant = mant_for_round + (1 << 3);/*****************/
                /*if (l_rounded_mant[26]) begin
                    l_rounded_mant = l_rounded_mant >> 1;
                    l_rounded_exp = l_rounded_exp + 1;
                end*/
                mant_for_round = mant_for_round + (1 << 3);/*****************/
                if (mant_for_round[27]) begin
                    l_rounded_mant=mant_for_round[27:1];
                    l_rounded_exp = l_rounded_exp + 1;
                end else begin
                    l_rounded_mant=mant_for_round[26:0];
                end
                
            end
            // 溢出和次正常数处理
            if ($signed(l_rounded_exp) >= 255) begin
                comb_result = {result_sign, 8'hFF, 23'b0};
                comb_exception = detect_exceptions(1'b0, 1'b0, 1'b1, 1'b0, 1'b1);
            end else if ($signed(l_rounded_exp) < 0) begin
                l_shift_amt = 0 - $signed(l_rounded_exp);
                if (l_shift_amt > 23) begin
                    l_denorm_mant = 23'b0;
                    l_round=  l_shift_amt==24 ? l_rounded_mant[26] :0;
                    sticky = l_shift_amt==24 ? sticky | |(l_rounded_mant[25:3]) : sticky | |(l_rounded_mant[26:3]) ;
                end else begin
                    l_denorm_mant = l_rounded_mant[26:4] >> (l_shift_amt-1);
                    sticky = sticky | |(l_rounded_mant[26:3] << (25 - l_shift_amt));
                    l_round=l_rounded_mant[l_shift_amt+2];
                end       
                l_guard=l_denorm_mant[0];
                case (fpu_op_round)
                    //3'b000: l_round_up = l_guard & (l_round | sticky | l_lsb); // RNE
                    3'b000: l_round_up = (l_guard &  l_round &  ~(|sticky) ) | (l_round & |sticky);// RNE
                    3'b001: l_round_up = 1'b0; // RTZ
                    3'b010: l_round_up = ( l_round | sticky) & result_sign; // RDN
                    3'b011: l_round_up = ( l_round | sticky) & ~result_sign; // RUP
                    3'b100: l_round_up = l_round ; // RMM
                    default: l_round_up = 1'b0;
                endcase
                l_denorm_mant=l_round_up==1 ? l_denorm_mant+1 : l_denorm_mant ;
                comb_result = {result_sign, 8'h00, l_denorm_mant};
                comb_exception = detect_exceptions(1'b0, 1'b0, 1'b0, 1'b1,  l_round | sticky);
            end else begin
                comb_result = {result_sign, l_rounded_exp[7:0], l_rounded_mant[25:3]};
                comb_exception[0] = (l_round | sticky) ? 1'b1 :1'b0 ;
            end
            continue_mul=1'b0;
        end
        // 调试输出
        /*if (fpu_op_type == FMUL_S && state == MUL_WAIT) begin
            $display("FMUL_S: prod_mant=%h, result_exp=%b, stored_true_exp1=%d, stored_true_exp2=%d, multiplier_product=%h", 
                     prod_mant, result_exp, stored_true_exp1, stored_true_exp2, multiplier_product);
        end*/
    end else if (state == DIV_WAIT && div_valid && fpu_op_type == FDIV_S ) begin
        result_sign = sign1 ^ sign2;
        result_exp = $signed(stored_true_exp1) - $signed(stored_true_exp2) + 10'd126;
       // $display("result_exp=%b",result_exp);
        prod_mant = {div_quotient, 16'b0}; // 假设商是归一化的尾数
        
        sticky=|div_remainder;
        //$display("余%b",sticky);
        // 初始溢出检查
        if ($signed(result_exp) >= 255 || !div_valid) begin
            case (fpu_op_round)
                3'b000, 3'b001, 3'b100: comb_result = {result_sign, 8'hFF, 23'b0};
                3'b010: comb_result = result_sign ? {1'b1, 8'hFE, 23'h7FFFFF} : {1'b0, 8'hFF, 23'b0};
                3'b011: comb_result = result_sign ? {1'b1, 8'hFF, 23'b0} : {1'b0, 8'hFE, 23'h7FFFFF};
                default: comb_result = {result_sign, 8'hFF, 23'b0};
            endcase
            comb_exception = detect_exceptions(1'b0, !div_valid, 1'b1, 1'b0, 1'b1);
        end else begin
            // 归一化
          //  $display("result_exp=%b前",result_exp);
            if (prod_mant[47]) begin
                sticky = |(prod_mant[21:0]) | sticky;
                prod_mant = prod_mant >> 1;
                result_exp = $signed(result_exp) + 10'd1;
                guard = prod_mant[23];
                round = prod_mant[22];
                sticky = |(prod_mant[21:0]) | sticky;
            end else begin
                lzc = 0;
                while (prod_mant[46-lzc] == 0 && lzc < 24) lzc = lzc + 1;
                prod_mant = prod_mant << lzc;
                result_exp = $signed(result_exp) - lzc;
                guard = prod_mant[23];
                round = prod_mant[22];
                sticky = |(prod_mant[21:0]) | sticky;
            end
           // $display("result_exp=%b后",result_exp);
            mant_for_round = {prod_mant[47:23], round, 2'b0};
            // 舍入
            l_rounded_mant = mant_for_round[26:0];
            l_rounded_exp = result_exp;
            l_guard = guard;
            l_round = round;
            l_lsb = mant_for_round[4];
            l_round_up = 1'b0;
          //  $display("l_rounded_mant=%h前",l_rounded_mant);
            case (fpu_op_round)
                3'b000: l_round_up = (l_guard &  l_round &  ~(|sticky) ) | (l_round & |sticky); // RNE
                3'b001: l_round_up = 1'b0; // RTZ
                3'b010: l_round_up = ( l_round | sticky) & result_sign; // RDN
                3'b011: l_round_up = ( l_round | sticky) & ~result_sign; // RUP
                3'b100: l_round_up = l_round ; // RMM
                default: l_round_up = 1'b0;
            endcase
           
           // $display("(l_guard %b  l_round %b |sticky %b ) | (l_round & |sticky);",l_guard,l_round,|sticky);
            if (l_round_up) begin
                // $display("jin");
               /* l_rounded_mant = mant_for_round + (1 << 4);
                if (l_rounded_mant[26]) begin
                    l_rounded_mant = l_rounded_mant >> 1;
                    l_rounded_exp = l_rounded_exp + 1;
                end*/
                mant_for_round = mant_for_round + (1 << 3);/*****************/
                //$display("mant_for_round %b",mant_for_round );
                if (mant_for_round[27]) begin
                    l_rounded_mant=mant_for_round[27:1];
                    l_rounded_exp = l_rounded_exp + 1;
                end else begin
                    l_rounded_mant=mant_for_round[26:0];
                end
            end
           // $display("l_rounded_mant=%h后",l_rounded_mant);
            // 溢出和次正常数处理
            
            if ($signed(l_rounded_exp) >= 255) begin
                comb_result = {result_sign, 8'hFF, 23'b0};
                comb_exception = detect_exceptions(1'b0, !div_valid, 1'b1, 1'b0, 1'b1);
            end else if ($signed(l_rounded_exp) < 0) begin
                l_shift_amt = 0 - $signed(l_rounded_exp);
               
                if (l_shift_amt > 23) begin
                    l_denorm_mant = 23'b0;
                    l_round=  l_shift_amt==24 ? l_rounded_mant[26] :0;
                    sticky = l_shift_amt==24 ? sticky | |(l_rounded_mant[25:3]) : sticky | |(l_rounded_mant[26:3]) ;
                end else begin
                    l_denorm_mant = l_rounded_mant[26:4] >> (l_shift_amt-1);
                    sticky = sticky | |(l_rounded_mant[26:3] << (25 - l_shift_amt));
                    l_round=l_rounded_mant[l_shift_amt+2];
                end       
                l_guard=l_denorm_mant[0];
                case (fpu_op_round)
                    //3'b000: l_round_up = l_guard & (l_round | sticky | l_lsb); // RNE
                    3'b000: l_round_up = (l_guard &  l_round &  ~(|sticky) ) | (l_round & |sticky);// RNE
                    3'b001: l_round_up = 1'b0; // RTZ
                    3'b010: l_round_up = ( l_round | sticky) & result_sign; // RDN
                    3'b011: l_round_up = ( l_round | sticky) & ~result_sign; // RUP
                    3'b100: l_round_up = l_round ; // RMM
                    default: l_round_up = 1'b0;
                endcase
                l_denorm_mant=l_round_up==1 ? l_denorm_mant+1 : l_denorm_mant ;
                comb_result = {result_sign, 8'h00, l_denorm_mant};
                comb_exception = detect_exceptions(1'b0, 1'b0, 1'b0, 1'b1,  l_round | sticky);
            end else begin
                comb_result = {result_sign, l_rounded_exp[7:0], l_rounded_mant[25:3]};
                comb_exception[0] =  ( l_round | sticky) ? 1'b1 : 1'b0;
            end
        end
        // 调试输出
       /* if (fpu_op_type == FDIV_S && state == DIV_WAIT) begin
            $display("FDIV_S: div_quotient=%h, result_exp=%d, stored_true_exp1=%d, stored_true_exp2=%d", 
                     div_quotient, result_exp, stored_true_exp1, stored_true_exp2);
        end*/
        continue_div=1'b0;
    end
end

// 状态机控制
always @(posedge clk or posedge reset) begin
    if (reset || flush) begin
        state <= IDLE;
        fpu_ready <= 1'b1;
        fpu_result_valid <= 1'b0;
        fpu_result <= 0;
        int_result <= 0;
        exception_flags <= 0;
        temp_result <= 0;
        temp_int_result <= 0;
        temp_exception <= 0;
        stored_true_exp1 <= 0;
        stored_true_exp2 <= 0;
    end else begin
        state <= next_state;
        fpu_ready <= next_fpu_ready;
        if (state == EXECUTE && (fpu_op_type == FMUL_S || fpu_op_type == FDIV_S)) begin
            stored_true_exp1 <= true_exp1;
            stored_true_exp2 <= true_exp2;
        end
        if (state == EXECUTE || (state == MUL_WAIT && multiplier_valid) || (state == DIV_WAIT && div_valid)) begin
            temp_result <= comb_result;
            temp_int_result <= comb_int_result;
            temp_exception <= comb_exception;
        end
        if (state == OUTPUT && downstream_valid) begin
            fpu_result <= temp_result;
            int_result <= temp_int_result;
            exception_flags <= temp_exception;
            fpu_result_valid <= 1'b1;
           
        end else begin
            fpu_result_valid <= 1'b0;
        end
    end
end
// 下状态逻辑
always @(*) begin
    next_state = state;
    next_fpu_ready = 0;
    case (state)
        IDLE: begin
            next_fpu_ready = 1'b1;
            if (fpu_op_valid) begin
                next_state = EXECUTE;
            end
        end
        EXECUTE: begin
            if (fpu_op_type == FMUL_S && continue_mul==1) begin
                next_state = MUL_WAIT;
            end else if (fpu_op_type == FDIV_S && continue_div==1) begin
                next_state = DIV_WAIT;
            end else begin
                next_state = OUTPUT;
            end
        end
        MUL_WAIT: begin
            if (multiplier_valid) begin
                next_state = OUTPUT;
            end
        end
        DIV_WAIT: begin
            if (div_valid) begin
                next_state = OUTPUT;
            end
        end
        OUTPUT: begin
            if (downstream_valid) begin
                next_state = IDLE;
                next_fpu_ready = 1'b1;
            end
        end
        default: begin
            next_state = IDLE;
            next_fpu_ready = 1'b1;
        end
    endcase
end

// 异常检测函数
function [4:0] detect_exceptions;
    input is_nan;
    input is_div_zero;
    input is_overflow;
    input is_underflow;
    input is_inexact;
begin
    detect_exceptions = {is_nan, is_div_zero, is_overflow, is_underflow, is_inexact};
end
endfunction
/*
Invalid Operation（无效操作）：NaN 或无穷大相减。nv
Divide by Zero（除以零）：加法中不触发。dz
Overflow（溢出）：指数 ≥ 255。OF
Underflow（次正常数/下溢）：结果为次正常数。UF
Inexact（不精确）：舍入或截断导致精度损失NX
0: RNE (最近偶数)
1: RTZ (向零)
2: RDN (向下)
3: RUP (向上)
4: RMM (最近最大幅度)*/

endmodule