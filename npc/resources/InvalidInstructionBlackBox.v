module ysyx_26030092_InvalidInstructionBlackBox (
    input [31:0] pc,
    input [31:0] inst,
    input invalid
);
`ifdef NPC_DPI
    import "DPI-C" context function void invalid_instruction(input int pc,input int inst);
    always@(*) begin
        if(invalid) invalid_instruction(pc,inst);
    end
`endif
endmodule
