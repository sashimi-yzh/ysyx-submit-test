
module ysyx_25020042_gpr  (
    input clock,
    // input reset,   
    /* verilator lint_off UNUSEDSIGNAL */
    input  [4:0] i_rs1,
    input  [4:0] i_rs2,
    input  [4:0] i_rd,
    /* verilator lint_on UNUSEDSIGNAL */
    input  [31:0] i_data,
    input  wbu_valid,
    output [31:0] o_src1,
    output [31:0] o_src2
    );
    
    wire [14:0] wen;
   /* verilator lint_off UNUSEDSIGNAL */
    wire [15:0] wen16 = wbu_valid ? (16'b1 << i_rd[3:0]) >> 1 : 16'b0;
    /* verilator lint_on UNUSEDSIGNAL */
    assign wen = wen16[14:0];

    // wire [31:0] reg_file [0:15];
    reg [31:0] src1;
    reg [31:0] src2;
    // reg [31:0] zero;
    reg [31:0] ra;  
    reg [31:0] sp; 
    reg [31:0] gp;  
    reg [31:0] tp;  
    reg [31:0] t0;  
    reg [31:0] t1;  
    reg [31:0] t2;  
    reg [31:0] s0;  
    reg [31:0] s1;  
    reg [31:0] a0;  
    reg [31:0] a1;  
    reg [31:0] a2;  
    reg [31:0] a3;  
    reg [31:0] a4;  
    reg [31:0] a5; 
    always @(posedge clock) begin
        // if (reset) begin
        //     // zero <= 32'b0;
        //     ra   <= 32'b0;
        //     sp   <= 32'b0;
        //     gp   <= 32'b0;
        //     tp   <= 32'b0;
        //     t0   <= 32'b0;
        //     t1   <= 32'b0;
        //     t2   <= 32'b0;
        //     s0   <= 32'b0;
        //     s1   <= 32'b0;
        //     a0   <= 32'b0;
        //     a1   <= 32'b0;
        //     a2   <= 32'b0;
        //     a3   <= 32'b0;
        //     a4   <= 32'b0;
        //     a5   <= 32'b0;
        // end else begin
            // if (wen[0]) zero   <= 0;
            if (wen[0]) ra   <= i_data;
            if (wen[1]) sp   <= i_data;
            if (wen[2]) gp   <= i_data;
            if (wen[3]) tp   <= i_data;
            if (wen[4]) t0   <= i_data;
            if (wen[5]) t1   <= i_data;
            if (wen[6]) t2   <= i_data;
            if (wen[7]) s0   <= i_data;
            if (wen[8]) s1   <= i_data;
            if (wen[9]) a0  <= i_data;
            if (wen[10]) a1  <= i_data;
            if (wen[11]) a2  <= i_data;
            if (wen[12]) a3  <= i_data;
            if (wen[13]) a4  <= i_data;
            if (wen[14]) a5  <= i_data;
        // end
    end

    always @(*) begin
        case (i_rs1[3:0])
            4'd1: src1 = ra;
            4'd2: src1 = sp;
            4'd3: src1 = gp;
            4'd4: src1 = tp;
            4'd5: src1 = t0;
            4'd6: src1 = t1;
            4'd7: src1 = t2;
            4'd8: src1 = s0;
            4'd9: src1 = s1;
            4'd10: src1 = a0;
            4'd11: src1 = a1;
            4'd12: src1 = a2;
            4'd13: src1 = a3;
            4'd14: src1 = a4;
            4'd15: src1 = a5;
            default: src1 = 32'h0;
        endcase
    end

    always @(*) begin
        case (i_rs2[3:0])
            4'd1: src2 = ra;
            4'd2: src2 = sp;
            4'd3: src2 = gp;
            4'd4: src2 = tp;
            4'd5: src2 = t0;
            4'd6: src2 = t1;
            4'd7: src2 = t2;
            4'd8: src2 = s0;
            4'd9: src2 = s1;
            4'd10: src2 = a0;
            4'd11: src2 = a1;
            4'd12: src2 = a2;
            4'd13: src2 = a3;
            4'd14: src2 = a4;
            4'd15: src2 = a5;
            default: src2 = 32'h0;
        endcase
    end


// 读取寄存器
    assign o_src1 = src1;
    assign o_src2 = src2;

endmodule





