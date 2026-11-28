module ysyx_26030092_Commit(
    input [31:0] pc,
    input [31:0] inst,
    input [31:0] dnpc,
    input valid,
    input clock,
    input reset,
    input mem_commit,
    input [31:0] mem_addr
);
`ifdef NPC_DPI
    import "DPI-C" context function void commit(input int pc, input int inst, input int dnpc, input int mem_commit, input int mem_addr);
    always @(posedge clock) begin
        if(valid) begin
            commit(pc, inst, dnpc, {31'b0, mem_commit}, mem_addr);
        end
    end
`endif
endmodule
