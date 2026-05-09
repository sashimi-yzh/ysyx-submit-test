`include "npc_config.vh"

module ysyx_25040102_IFU_ysyx(

    input               clk,
    input               reset,

    // output  [31:0]      inst,
    output  [31:0]      pc_out,
    output  [31:0]      snpc,

    input   [31:0]      pc_exu,
    input               pc_valid,
    output              pc_ready,

    output              flush,
    // output              flush_finish,

    output  [31:0]      in_paddr,
    output              in_psel,   // 只向icache发读指令地址

    input               in_pready

);

    reg     [31:0]      pc_r;

    assign  pc_ready            = in_pready;
    assign  in_paddr            = pc_r;
    assign  in_psel             = 1'b1;
    assign  pc_out              = pc_r;
    assign  snpc                = pc_r + 32'b100;

    reg                 flush_r;

    always @(posedge clk) begin
        if(reset == 1'b1) begin
            flush_r     <= 1'b0;
        end
        else begin
            if(in_pready == 1'b1) begin
                if(pc_valid == 1'b1) begin
                    flush_r     <= 1'b1;
                end
                else begin
                    flush_r     <= 1'b0;
                end
            end
        end
    end

    assign  flush   = flush_r;

    always @(posedge clk) begin // 收pc
        if(reset) begin
            pc_r        <= `ysyx_25040102_NPC;
        end
        else begin
            if(in_pready == 1'b1) begin
                if(pc_valid == 1'b1) begin
                    pc_r        <= pc_exu;
                end
                else begin
                    pc_r        <= snpc;
                end
            end
        end
    end


endmodule

