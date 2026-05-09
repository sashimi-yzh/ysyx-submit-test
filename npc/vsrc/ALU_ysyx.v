
module ysyx_25040102_ALU_ysyx(
    input   [3:0]   ALUctr,
    input   [31:0]  dataA,
    input   [31:0]  dataB,

    output          less,
    output          is_compare,
    output  [31:0]  result

);

    reg             carry;
    reg     [31:0]  result_r;
    reg             overflow;
    reg             less_r;

    wire     [32:0]  dataB_x;

    reg    sub;

    assign is_compare = (ALUctr == 4'b0011 || ALUctr == 4'b0010);

    // assign result = ((is_compare == 1'b1) ? {31'b0, less_r} : result_r);
    assign  result  = result_r;
    assign  less    = less_r;

    always @(*) begin
        case (ALUctr)
            4'b1000: sub = 1'b1;
            4'b0011: sub = 1'b1;
            4'b0010: sub = 1'b1;
            default: sub = 1'b0;
        endcase
    end

    assign  dataB_x = ({33{sub}} ^ {1'b0, dataB}) + {32'h0, sub};
    
    wire    [32:0]  result_add  = {1'b0, dataA} + dataB_x; // add
    wire    [32:0]  result_lui  = {1'b0, dataB};
    wire    [32:0]  result_xor  = {1'b0, dataA ^ dataB};
    wire    [32:0]  result_or   = {1'b0, dataA | dataB};
    wire    [32:0]  result_and  = {1'b0, dataA & dataB};
    wire    [32:0]  result_left = {1'b0, dataA << dataB[4:0]};
    wire    [32:0]  result_right = {1'b0, dataA >> dataB[4:0]};
    wire    [32:0]  result_right_a = {1'b0, $signed(dataA) >>> dataB[4:0]};

    always @(*) begin
        case (ALUctr)
            4'b0000: {carry,result_r} = result_add; //add.
            4'b0001: {carry,result_r} = result_left; // left
            4'b0010: {carry,result_r} = result_add;// signed compare
            4'b0011: {carry,result_r} = result_add; // unsigned compare
            4'b0100: {carry,result_r} = result_xor; // xor
            4'b0101: {carry,result_r} = result_right; // right_logic
            4'b0110: {carry,result_r} = result_or; // or
            4'b0111: {carry,result_r} = result_and; // and
            4'b1000: {carry,result_r} = result_add; // sub.
            4'b1001: {carry,result_r} = 33'b0;
            4'b1010: {carry,result_r} = result_lui;
            4'b1011: {carry,result_r} = 33'b0;
            4'b1100: {carry,result_r} = 33'b0;
            4'b1101: {carry,result_r} = result_right_a;
            4'b1110: {carry,result_r} = 33'b0;
            4'b1111: {carry,result_r} = 33'b0;
        endcase
    end

    always @(*) begin
        if(ALUctr[0] == 1'b1) begin
            overflow = (dataA[31] == dataB[31]) & (result_r[31] ^ dataA[31]);
            less_r = carry;
        end
        else begin
            overflow = (dataA[31] ^ dataB[31]) & (result_r[31] ^ dataA[31]);
            less_r = overflow ? ~result_r[31] : result_r[31];
        end
    end

endmodule
