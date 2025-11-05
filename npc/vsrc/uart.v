
module UART(
    input clock,
    input en,
    input [7:0]data
);

//import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);

always@(posedge clock) begin
    if(en) begin
        $write("%c",data);
        //pmem_write(32'ha00003f8, {24'h0,data}, 8'b0000_0001);
    end
end

endmodule
