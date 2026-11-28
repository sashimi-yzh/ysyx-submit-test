module ysyx_26030092_mtrace (
    input is_write,
    input [31:0] addr,
    input [31:0] data,
    input [3:0] size,
    input valid,
    input [31:0] pc
);
`ifdef NPC_DPI
    import "DPI-C" context function void mtrace(input byte is_write,input int addr, input int data, input int size, input int pc);
    always@(*) begin
        if(valid) mtrace({7'b0, is_write}, addr, data, {28'd0, size}, pc);
    end
`endif
endmodule
