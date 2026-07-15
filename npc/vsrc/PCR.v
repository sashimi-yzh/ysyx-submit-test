`include "MACRO.v"
`ifndef SYNTHESIS
    import PKG::ftrace;
    import PKG::enter_userapp;
`endif

module PCR(
    input clk,
    input reset,
    input [31:0] exu_result,
    input [31:0] imm,
    input [31:0] mtvec,
    input [31:0] mepc,
    input [2:0] behavior,
    input [31:0] pc_now,
    input pc_en,
    input flush,
    input exception,
    output reg [31:0] PC,
    output [1:0] meta_data_BTB_o,
    output hit_BTB_o,

    /*port for BTB*/
    input [31:0] target_BTB,
    input [1:0] meta_data_BTB,
    input hit_BTB
);
    initial begin
        PC = 32'h3000_0000;
    end

    assign meta_data_BTB_o = meta_data_BTB;
    assign hit_BTB_o = hit_BTB;

    reg [31:0] PC_next;
    always @(*) begin
        if(flush) begin
            case(behavior)
                `PC_NORMAL: PC_next = pc_now + 32'd4;
                `PC_MRET: PC_next = mepc;
                `PC_NEAR: PC_next = pc_now + imm;
                `PC_FAR: PC_next = exu_result;
                `PC_BRANCH: PC_next = (exu_result == 32'b1) ? pc_now + imm : pc_now + 32'd4;
                default: PC_next = 32'hFFFF_FFFF;
            endcase
        end

        else if(exception) begin
            PC_next = mtvec;
        end

        else if(hit_BTB) begin
            PC_next = target_BTB;
        end

        else begin
            PC_next = PC + 32'd4;
        end
        
        
    end

    always @(posedge clk) begin
        if(reset) begin
            PC <= 32'h3000_0000;
        end

        else begin
            if(pc_en || flush || exception) begin
                PC <= PC_next;
                `ifndef SYNTHESIS
                    ftrace(PC, PC_next);
                    enter_userapp(PC_next);
                `endif
            end

        end
    end

endmodule
