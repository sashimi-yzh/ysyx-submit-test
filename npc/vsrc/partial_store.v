module ysyx_24100012_partial_store #(
    ADDR_WIDTH=32,
    DATA_WIDTH=32)(
        input clk,
        input rst,
        input MemWEn,
        input [2:0] func3,
        input [DATA_WIDTH-1:0] addr,
        input [DATA_WIDTH-1:0] data
    );
    
    wire [DATA_WIDTH-1:0] length;  
    wire [1:0] store_sel;
    wire [DATA_WIDTH-1:0] dout;
    assign store_sel = func3[1:0];         
    ysyx_24100012_MuxKeyWithDefault #(3,2,32) mul_store (
        length,
        store_sel,
        32'h4,
        {
            2'b00, 32'h1,
            2'b01, 32'h2,
            2'b10, 32'h4
    });
    ysyx_24100012_ram #(ADDR_WIDTH,DATA_WIDTH) dmem (
        clk,
        MemWEn,
        1'b0,
        length,
        addr,
        data,
        32'b0,
        dout
    );
    // always@(*)
    //     $display("store %x,%x",addr,data);
endmodule