
module ysyx_25040102_Branch_Cond(
    input   [2:0]   branch,
    input           less,
    input           zero,
    input           mpcWr,

    output  [1:0]   mux
);

    reg     [1:0]   val;
    // wire    [4:0]   key;
    wire    [1:0]   key;

    assign key      = {less,zero};
    assign mux      = (mpcWr == 1'b1) ? 2'b10 : val;

    always @(*) begin // 2'b00 result; 2'b01 snpc/mpc; 2'b11 dnpc
        case(branch)
            3'b000: val = 2'b01; // default
            3'b001: val = 2'b00; // jar result
            3'b010: val = 2'b00; // jalr result
            3'b011: val = 2'b01; // default
            3'b100: val = (key == 2'b01) ? 2'b11 : 2'b01; // beq
            3'b101: val = zero ? 2'b01 : 2'b11; // bne
            3'b110: val = (key == 2'b10) ? 2'b11 : 2'b01; // blt
            3'b111: val = less ? 2'b01 : 2'b11; // 
        endcase
    end 

endmodule
