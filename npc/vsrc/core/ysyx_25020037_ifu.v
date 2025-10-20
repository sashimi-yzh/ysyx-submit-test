`include "ysyx_25020037_config.vh"

module ysyx_25020037_ifu #(
    parameter BLOCK_SIZE = 4
) (
    input  wire         clk,
    input  wire         rst,
    input  wire         exu_dnpc_valid,
    input  wire [31: 0] exu_dnpc,
    output wire         pc_updata,
    input  wire         idu_ready,
    output wire         ifu_valid,
    output reg  [31: 0] pc,

    output wire [31: 0] icache_addr,
    output wire         icache_valid,
    input  wire         icache_hit
);
    wire [31:0] snpc = pc + 32'h4;
    wire [31:0] dnpc = exu_dnpc_valid ? exu_dnpc : snpc;
    assign      pc_updata = icache_hit & idu_ready;

    assign icache_addr  = pc;
    assign icache_valid = idu_ready;
    assign ifu_valid    = icache_hit & ~exu_dnpc_valid;
    always @(posedge clk or posedge rst) begin
        if (rst) begin
`ifdef NPC
            pc <= `NPC_RESET_VAL;
`else
            pc <= `YSYXSOC_RESET_VAL;
`endif
        end else begin
            pc <= pc_updata ? dnpc : pc;
        end
    end

endmodule
