module ysyx_24100012_alu #(DATA_WIDTH=32,N_SEL=4,SHIFT_WIDTH=5)(
    input clk,
    input rst,
    input [1:0] csrType,
    input [DATA_WIDTH-1:0] in_a,
    input [DATA_WIDTH-1:0] in_b,
    input [N_SEL-1:0] alu_sel,
    output reg [DATA_WIDTH-1:0] out
);
    wire [DATA_WIDTH-1:0] nopriv_out,priv_out;
    ysyx_24100012_MuxKey #(10,4,DATA_WIDTH) alu (
        nopriv_out,
        alu_sel,{
            4'b0000, in_a+in_b,                         //add
            4'b1000, in_a-in_b,                         //sub
            4'b0001, in_a<<in_b[SHIFT_WIDTH-1:0],                        //sll
            4'b0010, ($signed(in_a)<$signed(in_b))? 32'h1 :32'h0,   //slt
            4'b0011, (in_a<in_b)? 32'h1 :32'h0,         //sltu
            4'b0100, in_a^in_b,                         //xor
            4'b0101, in_a>>in_b[SHIFT_WIDTH-1:0],                        //srl
            4'b1101, $signed(in_a)>>>in_b[SHIFT_WIDTH-1:0],                       //sra
            4'b0110, in_a | in_b,                       //or
            4'b0111, in_a & in_b                        //and
        });
    ysyx_24100012_MuxKey #(6,4,DATA_WIDTH) alu_priv (
        priv_out,
        alu_sel,{
            4'b0001, in_a,                              //x[rs1]
            4'b0010, in_a|in_b,                         //t|x[rs1]
            4'b0011, in_a & ~in_b,                      //t&~x[rs1]
            4'b0101, in_a & ~in_b,                       //t&~imm
            4'b0110, in_a|in_b,                         //t|imm
            4'b0111, in_a & ~in_b                       //t&~imm
        });
    ysyx_24100012_MuxKeyWithDefault #(2,2,DATA_WIDTH) alu_out (
        out,
        csrType,
        32'b0,{
            2'b00, priv_out,                            
            2'b11, nopriv_out
        });
    // always@(*)
    //     $display("alu a: %x, b: %x,csrType %b code %b,noprivout: %x", in_a,in_b,csrType,alu_sel,nopriv_out);

endmodule

