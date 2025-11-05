module psram_rw(
        input clock,
        input reset,

        input wire sel,
        input wire write,
        input wire [23:0] addr,
        input wire [31:0] wdata,
        input wire [ 3:0] wmask,
        output reg [31:0] rdata
);


import "DPI-C" function int psram_read(input int addr);
import "DPI-C" function void psram_write(input int addr, input int wdata, input byte wmask);
/*
wire reset;

assign reset = 1'b0;*/


always @(*) begin
        if (reset == 1'b1 || (!sel)) begin // 有读写请求时
          rdata = 0;
        end
        else begin
            if(!write) begin
                rdata = psram_read({8'b0,addr});
            end
            else begin
                rdata = 0;
            end
        end
end


always @(posedge clock) begin
    if(!(reset == 1'b1 || (!sel))) begin
            if(write) begin
                psram_write({8'b0,addr}, wdata, {4'b0,wmask});
            end
    end
end


endmodule


