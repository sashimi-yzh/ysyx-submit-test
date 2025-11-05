`include "defines.v"
module Mem(
        input clock,
        input reset,

        input wire we,
        input wire [31:0] waddr,
        input wire [31:0] raddr,
        input wire [31:0] wdata,
        input wire [7:0] wmask,

        output reg [31:0] rdata
);

`ifndef SYNTHESIS
`ifdef VERILATOR
import "DPI-C" function int pmem_read(input int raddr);
import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);


always @(*) begin
        if (reset == `RstDisable) begin // 有读写请求时
          rdata = pmem_read(raddr);
          if (we) begin // 有写请求时
            pmem_write(waddr, wdata, wmask);
          end
        end
        else begin
          rdata = 0;
        end
      end
`endif
`endif
endmodule


