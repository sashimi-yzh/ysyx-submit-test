module EXU(
    input [31:0]inA,
    input [31:0]inB,
    input [9:0]op,
    output reg [31:0]out
);
wire [31:0]add;
    assign add=inA+inB;

    always @(*) begin
        if(op[9]) out=add;
        else out=inA;
        // case(op)
        // endcase
            
    end
endmodule