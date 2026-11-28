module ysyx_26030092_EbreakBlackBox (
    input ebreak_trap
);
`ifdef NPC_DPI
    import "DPI-C" function void ebreak();
    always @(*) begin
        if(ebreak_trap)begin
            ebreak();
        end
    end
`endif
endmodule
