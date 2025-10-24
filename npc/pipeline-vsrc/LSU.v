`timescale 1ns/1ns
`include "/home/furina/ysyx-workbench/npc/pipeline-vsrc/defines/defines.v"

module LSU (
    input         clk,
    input         rst,
    // input         MEM_LSU_read_ready,   // 内存读就绪信号（假设外部提供）
    // input         MEM_LSU_write_ready,  // 内存写就绪信号（假设外部提供）
    // 流水线握手信号
    input         ex_lsu_valid,       // 从 EX 阶段传入的有效信号
    output reg    lsu_ex_ready,       // 返回给 EX 阶段的就绪信号
    input         wb_lsu_ready,       // 从 WB 阶段传入的就绪信号
    output reg    lsu_wb_valid,       // 传递给 WB 阶段的有效信号

    input         ex_lsu_forward_las,
    input         ex_lsu_RegWrite,     // 寄存器写使能
    input  [4:0]  ex_lsu_rd,           // 目标寄存器地址
    input         ex_lsu_MemRead,            // 内存读使能
    input         ex_lsu_MemWrite,           // 内存写使能
    input  [2:0]  ex_lsu_MemLen,             // 内存访问长度（字节、半字、字）
    input  [31:0] ex_lsu_inst,               // 指令
    input  [31:0] ex_lsu_pc,                 // 程序计数器

    input  [31:0] addr,               // 内存访问地址(传ex计算结果）
    input  [31:0] data_in,            // 写内存的数据
    input  [31:0] ex_lsu_imm,         // 立即数（从 EX 阶段传入）
    input  [6:0]  ex_lsu_opcode,      // 指令操作码

    // 前递信号
    output [4:0]  lsu_ex_forward_rd,          // 前递的目标寄存器地址
    output        lsu_ex_forward_RegWrite,    // 前递使能
    output        lsu_ex_forward_MemRead,     // 前递加载标志

    input         ex_lsu_csr,
    input         ex_lsu_csr_wen1,
    input         ex_lsu_csr_wen2,
    input [31:0]  ex_lsu_csr_wr_data1,
    input [31:0]  ex_lsu_csr_wr_data2,
    input [11:0]  ex_lsu_csr_wr_addr1,
    input [11:0]  ex_lsu_csr_wr_addr2,
    input [31:0]  ex_lsu_csr_rdata,
    input         ex_lsu_csr_ecall,
    input         ex_lsu_csr_mret,
    input  [31:0] ex_lsu_process_result,

    // 传递到 WB 阶段的信号
    output reg [31:0] lsu_wb_inst,         // 指令
    output reg [31:0] lsu_wb_pc,           // 程序计数器

    output reg [31:0] lsu_wb_csr_wr_data1,
    output reg [31:0] lsu_wb_csr_wr_data2,
    output reg [11:0] lsu_wb_csr_wr_addr1,
    output reg [11:0] lsu_wb_csr_wr_addr2,
    output reg        lsu_wb_csr_wen1,
    output reg        lsu_wb_csr_wen2,
    output reg        lsu_wb_RegWrite,        // 寄存器写使能
    output reg [4:0]  lsu_wb_rd,              // 目标寄存器地址
    output reg [31:0] lsu_wb_write_rd_data    // 写回寄存器的数据
);
    // DPI 函数声明
    import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
    import "DPI-C" function void pmem_write(input int unsigned waddr, input int unsigned wdata, input int len);
    import "DPI-C" function void ebreak(input int station, input int inst);
    import "DPI-C" function void counter(input int inst_type, input int ifu_inc, input int lsu_inc, input int exu_inc);

    // 内部寄存器
    reg l_load;            // 加载标志
    reg l_rd_en;           // 寄存器写使能
    reg [4:0]  l_rd_addr;  // 目标寄存器地址
    reg [31:0] l_inst;     // 指令
    reg [31:0] l_pc;       // 程序计数器
    reg [2:0]  l_MemLen;   // 内存访问长度
    reg [6:0]  l_opcode;   // 指令操作码

    reg read_valid;// 内存读有效信号
    reg write_valid;// 内存写有效信号

    // 前递信号赋值
    assign lsu_ex_forward_rd = l_rd_addr;
    assign lsu_ex_forward_RegWrite   = l_rd_en;
    assign lsu_ex_forward_MemRead    = l_load;

    // 内存读写数据
    reg [31:0] read_lsu_data;  // 从内存读取的数据
    wire [31:0] wr_rd_data; // 处理后的写回数据

    // 寄存器更新逻辑
    always @(posedge clk) begin
        if (rst) begin
            l_load    <= 0;
            l_rd_en   <= 0;
            l_rd_addr <= 0;
            l_inst    <= 0;
            l_pc      <= 0;
            l_MemLen  <= 0;
            l_opcode  <= 0;
        end
        else if (ex_lsu_valid & lsu_ex_ready & (ex_lsu_MemRead | ex_lsu_MemWrite)) begin
            l_load    <= ex_lsu_MemRead;
            l_rd_en   <= ex_lsu_RegWrite;
            l_rd_addr <= ex_lsu_rd;    
            l_inst    <= ex_lsu_inst;   
            l_pc      <= ex_lsu_pc;   
            l_MemLen  <= ex_lsu_MemLen;
            l_opcode  <= ex_lsu_opcode;
        end
        else if (lsu_wb_valid & wb_lsu_ready) begin
            l_load    <= 0;
            l_rd_en   <= ex_lsu_RegWrite;
            l_rd_addr <= ex_lsu_rd;    
            l_inst    <= ex_lsu_inst;   
            l_pc      <= ex_lsu_pc;  
            l_MemLen  <= ex_lsu_MemLen;
            l_opcode  <= l_inst[6:0]; // 从指令中提取 opcode
        end
        else if(ex_lsu_valid && lsu_ex_ready) begin//非访存指令
            l_load    <= l_load;
            l_rd_en   <= ex_lsu_RegWrite;
            l_rd_addr <= ex_lsu_rd;    
            l_inst    <= ex_lsu_inst;   
            l_pc      <= ex_lsu_pc;   
            l_MemLen  <= ex_lsu_MemLen;
            l_opcode  <= l_inst[6:0]; // 从指令中提取 opcode
        end
        else begin
            l_load    <= l_load;
            l_rd_en   <= l_rd_en;
            l_rd_addr <= l_rd_addr;    
            l_inst    <= l_inst;   
            l_pc      <= l_pc;   
            l_MemLen  <= l_MemLen;
            l_opcode  <= l_opcode; 
        end
    end

    // 内存读控制
    always @(posedge clk) begin 
        if (rst) begin
            read_valid <= 0;
            read_lsu_data     = 0;
        end
        else if ((ex_lsu_valid & lsu_ex_ready) & (ex_lsu_MemRead & ~ex_lsu_MemWrite)) begin
            read_valid <= 1;
            counter(7, 0, 1, 0);
            // read_mem_data = pmem_read(addr, 4);
            case (l_MemLen)
                `Mem_UBit:  begin
                    read_lsu_data = pmem_read(addr, 1);
                end
                `Mem_Bit:   begin
                    read_lsu_data = pmem_read(addr, 1);
                end
                `Mem_UHalf: begin
                    read_lsu_data = pmem_read(addr, 2);
                end
                `Mem_Half:  begin
                    read_lsu_data = pmem_read(addr, 2);
                end
                `Mem_Word:  begin
                    read_lsu_data = pmem_read(addr, 4);
                end
                // default: read_lsu_data = 32'h0;
                default: begin
                    ebreak(`ABORT, 32'hdead_beef); // 错误处理
                    $display("\033[32mError: Unsupported memory read length %b at address %h\033[0m", l_MemLen, addr);
                end
            endcase
            // $display("read addr: %h, data: %h, MemLen: %b, opcode: %b", addr, read_lsu_data, l_MemLen, ex_lsu_opcode);
        end
        // else if (LSU_MEM_read_valid & MEM_LSU_read_ready) begin
        //     LSU_MEM_read_valid <= 0;
        // end
        else begin
            read_valid <= 0;
            read_lsu_data = read_lsu_data;
        end
    end

    assign wr_rd_data = (l_MemLen == `Mem_UBit) ? {{24{1'b0}}, read_lsu_data[7:0]} :
                        (l_MemLen == `Mem_Bit)  ? {{24{read_lsu_data[7]}}, read_lsu_data[7:0]} :
                        (l_MemLen == `Mem_UHalf)? {{16{1'b0}}, read_lsu_data[15:0]} :
                        (l_MemLen == `Mem_Half) ? {{16{read_lsu_data[15]}}, read_lsu_data[15:0]} :
                        (l_MemLen == `Mem_Word)? read_lsu_data : 32'b0;
    // 内存写控制
    // reg [31:0] data_in;
    always @(posedge clk) begin
        if (rst) begin
            write_valid <= 0;
        end
        else if (ex_lsu_valid & lsu_ex_ready & ~ex_lsu_MemRead & ex_lsu_MemWrite) begin
            write_valid <= 1;
            case (ex_lsu_MemLen)
                `Mem_Bit:  pmem_write(addr,data_in,1);//sb
                `Mem_Half: pmem_write(addr,data_in,2);//sh
                `Mem_Word: pmem_write(addr,data_in,4);//sw
                // default:   pmem_write(addr,data_in,4);
                default: begin
                    ebreak(`ABORT, 32'hdead_beef); // 错误处理
                    $display("\033[32mError: Unsupported memory write length %b at address %h\033[0m", ex_lsu_MemLen, addr);
                end
            endcase
            // $display("write addr: %h, data: %h, MemLen: %b, opcode: %b", addr, data_in, ex_lsu_MemLen, ex_lsu_opcode);
        end
        else begin
            write_valid <= 0;
        end
    end

    reg [31:0] rd_data;
    always @(*) begin
        if(l_load) begin
            rd_data = wr_rd_data;
        end
        else if(ex_lsu_forward_las) begin
            rd_data = data_in;
        end
        else if(ex_lsu_MemWrite) begin
            rd_data = 32'h0;
        end
        else if(ex_lsu_csr & !ex_lsu_csr_ecall & !ex_lsu_csr_mret) begin
            rd_data = ex_lsu_csr_rdata;
        end
        else begin
            rd_data = ex_lsu_process_result;
        end
    end
    // assign rd_data = (ex_lsu_forward_las) ? data_in :
    //                  (ex_lsu_opcode == `INST_LW) ? wr_rd_data :
    //                 //  (ex_lsu_opcode == `INST_LW) ? wr_rd_data :
    //                  (ex_lsu_opcode == `INST_LUI) ? ex_lsu_imm :
    //                 //  (ex_lsu_opcode == `INST_AUIPC) ? ex_lsu_process_result:
    //                  (ex_lsu_opcode == `INST_AUIPC) ? ex_lsu_pc + ex_lsu_imm :
    //                  (ex_lsu_opcode == `INST_JAL) ? ex_lsu_pc + 4 :
    //                  (ex_lsu_opcode == `INST_JALR) ? ex_lsu_pc + 4 :
    //                  (ex_lsu_opcode == `INST_CSR) ? ex_lsu_csr_rdata :
    //                  (ex_lsu_opcode == `INST_R) ? ex_lsu_process_result :
    //                  (ex_lsu_opcode == `INST_I) ? ex_lsu_process_result : 32'b0;

    // 流水线握手逻辑
    always @(posedge clk) begin
        if (rst) begin
            lsu_ex_ready <= 1;
        end
        else if (ex_lsu_valid & lsu_ex_ready & (ex_lsu_MemRead | ex_lsu_MemWrite)) begin
            lsu_ex_ready <= 0;
        end
        else if (lsu_wb_valid & wb_lsu_ready) begin
            lsu_ex_ready <= 1;
        end
        // else begin
        //     lsu_ex_ready <= lsu_ex_ready;
        // end
    end

    always @(posedge clk) begin
        if (rst) begin
            lsu_wb_valid <= 0;
        end
        else if (ex_lsu_valid & lsu_ex_ready & ~(ex_lsu_MemRead | ex_lsu_MemWrite)) begin
            lsu_wb_valid <= 1;
        end
        else if (read_valid || write_valid) begin
            lsu_wb_valid <= 1;
        end
        else if (ex_lsu_valid & lsu_ex_ready & (ex_lsu_MemRead | ex_lsu_MemWrite)) begin
            lsu_wb_valid <= 0;
        end
        else if ((~(ex_lsu_valid && lsu_ex_ready)) && lsu_wb_valid) begin
            lsu_wb_valid <= 0;
        end
        // else begin
        //     lsu_wb_valid <= lsu_wb_valid;
        // end
    end

    // 输出到 WB 阶段
    always @(posedge clk) begin
        if (rst) begin
            lsu_wb_RegWrite        <= 0;
            lsu_wb_rd              <= 0;
            lsu_wb_write_rd_data   <= 0;
            lsu_wb_inst            <= 0;
            lsu_wb_pc              <= 0;
            lsu_wb_csr_wen1     <= 0;
            lsu_wb_csr_wen2     <= 0;
            lsu_wb_csr_wr_addr1 <= 0;
            lsu_wb_csr_wr_addr2 <= 0;
            lsu_wb_csr_wr_data1 <= 0;
            lsu_wb_csr_wr_data2 <= 0;
        end
        else if (write_valid) begin
            lsu_wb_RegWrite        <= l_rd_en;
            lsu_wb_rd              <= l_rd_addr;
            lsu_wb_csr_wen1     <= ex_lsu_csr_wen1;
            lsu_wb_csr_wen2     <= ex_lsu_csr_wen2;
            lsu_wb_csr_wr_addr1 <= ex_lsu_csr_wr_addr1;
            lsu_wb_csr_wr_addr2 <= ex_lsu_csr_wr_addr2;
            lsu_wb_csr_wr_data1 <= ex_lsu_csr_wr_data1;
            lsu_wb_csr_wr_data2 <= ex_lsu_csr_wr_data2;
            lsu_wb_write_rd_data  <= rd_data;
            lsu_wb_inst           <= l_inst;
            lsu_wb_pc             <= l_pc;
        end
        else if (read_valid) begin
            lsu_wb_RegWrite       <= l_rd_en;
            lsu_wb_rd             <= l_rd_addr;
            lsu_wb_csr_wen1     <= ex_lsu_csr_wen1;
            lsu_wb_csr_wen2     <= ex_lsu_csr_wen2;
            lsu_wb_csr_wr_addr1 <= ex_lsu_csr_wr_addr1;
            lsu_wb_csr_wr_addr2 <= ex_lsu_csr_wr_addr2;
            lsu_wb_csr_wr_data1 <= ex_lsu_csr_wr_data1;
            lsu_wb_csr_wr_data2 <= ex_lsu_csr_wr_data2;
            lsu_wb_write_rd_data  <= rd_data;
            lsu_wb_inst           <= l_inst;
            lsu_wb_pc             <= l_pc;
        end
        else if (ex_lsu_valid & lsu_ex_ready & ~(ex_lsu_MemRead | ex_lsu_MemWrite)) begin
            lsu_wb_RegWrite        <= ex_lsu_RegWrite; // 非内存访问指令
            lsu_wb_rd              <= ex_lsu_rd;
            lsu_wb_csr_wen1     <= ex_lsu_csr_wen1;
            lsu_wb_csr_wen2     <= ex_lsu_csr_wen2;
            lsu_wb_csr_wr_addr1 <= ex_lsu_csr_wr_addr1;
            lsu_wb_csr_wr_addr2 <= ex_lsu_csr_wr_addr2;
            lsu_wb_csr_wr_data1 <= ex_lsu_csr_wr_data1;
            lsu_wb_csr_wr_data2 <= ex_lsu_csr_wr_data2;
            lsu_wb_write_rd_data  <= rd_data;
            lsu_wb_inst           <= ex_lsu_inst;
            lsu_wb_pc             <= ex_lsu_pc;
        end
        else begin
            lsu_wb_RegWrite     <= lsu_wb_RegWrite;
            lsu_wb_rd           <= lsu_wb_rd;
            lsu_wb_write_rd_data<= lsu_wb_write_rd_data;
            lsu_wb_inst         <= lsu_wb_inst;
            lsu_wb_pc           <= lsu_wb_pc;
            lsu_wb_csr_wr_data1 <= lsu_wb_csr_wr_data1;
            lsu_wb_csr_wr_data2 <= lsu_wb_csr_wr_data2;
            lsu_wb_csr_wr_addr1 <= lsu_wb_csr_wr_addr1;
            lsu_wb_csr_wr_addr2 <= lsu_wb_csr_wr_addr2;
            lsu_wb_csr_wen1     <= lsu_wb_csr_wen1;
            lsu_wb_csr_wen2     <= lsu_wb_csr_wen2;
        end
    end

endmodule