module FormalMem(
    input clk,
    input en,
    input [31:0] addr,
    output reg [31:0] rdata
);
    reg [31:0] mem [0:127];

    initial begin
        $readmemh("mem_init.hex", mem);  // ← 关键在这里
    end

    always @(posedge clk) begin
        if (en) begin
            rdata <= mem[addr[8:2]];
        end
    end
endmodule
