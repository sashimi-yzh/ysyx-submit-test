module ysyx_24100012_partial_load #(
    ADDR_WIDTH=32,
    DATA_WIDTH=32)(
        input clk,
        input rst,
        input MemREn,
        input [2:0] load_sel,
        input [DATA_WIDTH-1:0] out_addr,
        output [DATA_WIDTH-1:0] data
    );
    
    wire [DATA_WIDTH-1:0] length;  
    wire [DATA_WIDTH-1:0] mem_data;
    ysyx_24100012_MuxKeyWithDefault #(5,3,32) mul_length (
        length,
        load_sel,
        32'h4,{
            3'b000, 32'h1,
            3'b001, 32'h2,
            3'b010, 32'h4,
            3'b100, 32'h1,
            3'b101, 32'h2
    });
    ysyx_24100012_ram  #(ADDR_WIDTH,DATA_WIDTH) dmem (
        clk,
        1'b0,
        MemREn,
        length,
        32'b0,
        32'b0,
        out_addr,
        mem_data
    );
    ysyx_24100012_MuxKeyWithDefault #(5,3,32) mul_load (
        data,
        load_sel,
        mem_data,
        {
            3'b000, {{25{mem_data[7]}},mem_data[6:0]},
            3'b001, {{17{mem_data[15]}},mem_data[14:0]},
            3'b010, mem_data,
            3'b100, mem_data,
            3'b101, mem_data
        });
    // always@(*) 
    //     if (MemREn)
            // $display("load %x,%x,len %d",out_addr,mem_data,length);

endmodule