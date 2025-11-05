`include "defines.v"


module DMem(
        input clock,
        input reset,

        input wire we,
        input wire [`InstAddrBus] waddr,
        input wire [`InstAddrBus] raddr,
        input wire [`WordBus] wdata,
        input wire [7:0] wmask,

        output reg [`WordBus] rdata
);


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


endmodule


