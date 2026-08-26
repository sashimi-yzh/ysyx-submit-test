
module IFU(
    input clk,
    input rst,
    output reg [31:0] PC,
    input [31:0] dnpc,
    output [31:0] snpc,
    input isJUMP,
    output reg [31:0]PC_command
);
    
    always @(posedge clk,posedge rst) begin
        if (rst) begin
            PC<=32'h80000000;
        end else begin
            if (isJUMP) begin
                PC<=dnpc;
            end else begin
                PC<=snpc;
            end
        end
    end
    assign snpc=PC+4;

    always @(*) begin
        if (rst) begin
            PC_command=0;
        end else begin
            PC_command=pmem_read(PC);
        end
    end
endmodule