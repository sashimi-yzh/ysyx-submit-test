`include "/home/furina/ysyx-workbench/npc/minirv-vsrc/defines.v"
// 内存模块
module MEM (
    input             clk,
    input             MemRead,
    input             MemWrite,
    input      [31:0] addr,
    input      [31:0] data_in,
    input      [2:0]  MemLen,
    output reg [31:0] data_out
);
    
    import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
    import "DPI-C" function void pmem_write(input int unsigned waddr, input int unsigned wdata, input int len);
    
    reg [31:0] read_data;

    always @(posedge clk) begin
        if(MemRead) begin
            case(MemLen)
                `Mem_UBit: begin
                    read_data = pmem_read(addr,1);
                    data_out  = {24'b0,read_data[7:0]};//无符号扩展
                end
                `Mem_Word:  data_out = pmem_read(addr,4);//lw
                default: data_out = 32'b0;
            endcase
        end
        else if(MemWrite) begin
            case(MemLen)
                `Mem_Bit:  pmem_write(addr,data_in,1);//sb
                `Mem_Word: pmem_write(addr,data_in,4);//sw
                default: pmem_write(addr,data_in,4);
            endcase
        end
        else data_out=32'b0;
    end

endmodule