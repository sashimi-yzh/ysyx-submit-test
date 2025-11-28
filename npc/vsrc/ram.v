import "DPI-C" function void pmem_read(input int outaddr,input int length, output int dout);
import "DPI-C" function void pmem_write(input int inaddr,input int length, input int din);

module ysyx_24100012_ram #(
    ADDR_WIDTH=32,
    DATA_WIDTH=32,
    ORIGIN_ADDR=32'h80000000,
    MEM_SIZE=32'h08000000)(
    input clk,
    input MemWEn,
    input MemREn,
    input [DATA_WIDTH-1:0] length,  //? should be 32bits? dpi-c need to match
    input [ADDR_WIDTH-1:0] inaddr,
    input [DATA_WIDTH-1:0] din,
    input [ADDR_WIDTH-1:0] outaddr,
    output reg [DATA_WIDTH-1:0] dout
);  
    always @(*) begin
        if (MemWEn) begin
            pmem_write(inaddr,length,din);
        end else 
            dout=32'b0;
        if (MemREn) begin
            pmem_read(outaddr,length,dout);
        end else begin 
            dout=32'b0;
        end
    end
    // assign  dout=32'0;
endmodule
