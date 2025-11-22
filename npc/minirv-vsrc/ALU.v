`include "/home/furina/ysyx-workbench/npc/minirv-vsrc/defines.v"
// ALU模块
module ALU (
    input      [3:0]   alu_op,
    input      [31:0]  a,
    input      [31:0]  b,
    output reg [31:0]  result
    // output             zero,
    // output             less
);
    import "DPI-C" function void ebreak(input int station, input int inst);
    always @(*) begin
        case (alu_op)
            `ALU_ADD:  result = a + b;  // 加法 (add, addi)
            default: begin
                result = 32'b0;
                ebreak(`ABORT,32'hdeadbeef);
                $display("ALU : Unknown alu_op = %b",alu_op);
            end
        endcase
    end
endmodule