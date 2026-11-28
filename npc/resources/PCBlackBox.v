module ysyx_26030092_PCBlackBox(
    input clock,
    input reset,
    input [31:0] pc_next,
    input pc_we,
    input pc_4,
    output [31:0]pc
);
`ifdef NPC
    localparam CONFIG_START_ADDR = 32'h80000000;
`elsif NETLIST_SIM
    localparam CONFIG_START_ADDR = 32'h80000000;
`else
    localparam CONFIG_START_ADDR = 32'h30000000;
`endif
    reg [31:0] PC;
    assign pc = PC;
    always@(posedge clock) begin
        if(reset)begin
            PC <= CONFIG_START_ADDR;
        end
        else begin
            if(pc_we)begin
                PC <= pc_next;
            end
            else if(pc_4)begin
                PC <= PC + 4;
            end
        end
    end
`ifdef NPC_DPI
    export "DPI-C" task read_pc;
    task read_pc(output int data);
        data = PC;
    endtask
`endif
endmodule
