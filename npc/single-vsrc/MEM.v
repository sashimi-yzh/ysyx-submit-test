`include "/home/furina/ysyx-workbench/npc/single-vsrc/defines.v"
// 内存模块
module MEM (
    input         clk,
    input         MemRead,
    input         MemWrite,
    input  [31:0] addr,
    input  [31:0] data_in,
    input  [2:0]  MemLen,
    output reg [31:0] data_out
);
    
    import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
    import "DPI-C" function void pmem_write(input int unsigned waddr, input int unsigned wdata, input int len);
    
    reg [31:0] read_data;

    always @(posedge clk) begin
        // if(MemRead) data_out = pmem_read(addr,4);
        // else if(MemWrite) pmem_write(addr,data_in,4);
        // else data_out = 32'b0;
        if(MemRead) begin
            case(MemLen)
                // `Mem_Bit:   data_out = {24'b0,pmem_read(addr,1)[7:0]};//lbu
                `Mem_UBit: begin
                    read_data = pmem_read(addr,1);
                    data_out  = {24'b0,read_data[7:0]};//无符号扩展
                end
                `Mem_Bit: begin
                    read_data = pmem_read(addr,1);
                    data_out  = {{24{read_data[7]}},read_data[7:0]};//符号拓展
                end
                `Mem_Half: begin
                    read_data = pmem_read(addr,2);
                    data_out  = {{16{read_data[15]}},read_data[15:0]};//符号扩展，支持lh
                end
                `Mem_UHalf: begin
                    read_data = pmem_read(addr,2);
                    data_out  = {16'b0,read_data[15:0]};//无符号扩展，支持lhu
                end
                `Mem_Word:  data_out = pmem_read(addr,4);//lw
                default: data_out = 32'b0;
            endcase
            // $display("MEM read");
        end
        else if(MemWrite) begin
            case(MemLen)
                `Mem_Bit:  pmem_write(addr,data_in,1);//sb
                `Mem_Half: pmem_write(addr,data_in,2);//sh
                `Mem_Word: pmem_write(addr,data_in,4);//sw
                default: pmem_write(addr,data_in,4);
            endcase
            // $display("MEM write");
        end
        else data_out=32'b0;
    end

endmodule