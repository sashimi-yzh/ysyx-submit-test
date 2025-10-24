
`timescale 1ns/1ns
`include "/home/furina/ysyx-workbench/npc/Npipeline-vsrc/defines/defines.v"

module LSU_AXI (
    input         clk,
    input         rst,

    // 流水线握手信号
    input         ex_lsu_valid,       // 从 EX 阶段传入的有效信号
    output reg    lsu_ex_ready,       // 返回给 EX 阶段的就绪信号
    input         wb_lsu_ready,       // 从 WB 阶段传入的就绪信号
    output reg    lsu_wb_valid,       // 传递给 WB 阶段的有效信号

    // EX 阶段输入信号
    input         ex_lsu_forward_las,
    input         ex_lsu_RegWrite,     // 寄存器写使能
    input  [4:0]  ex_lsu_rd,           // 目标寄存器地址
    input         ex_lsu_MemRead,      // 内存读使能
    input         ex_lsu_MemWrite,     // 内存写使能
    input  [2:0]  ex_lsu_MemLen,       // 内存访问长度（字节、半字、字）
    input  [31:0] ex_lsu_inst,         // 指令
    input  [31:0] ex_lsu_pc,           // 程序计数器
    input  [31:0] addr,                // 内存访问地址（传 EX 计算结果）
    input  [31:0] data_in,             // 写内存的数据
    input  [31:0] ex_lsu_imm,          // 立即数
    input  [6:0]  ex_lsu_opcode,       // 指令操作码

    // CSR 相关信号
    input         ex_lsu_csr,
    input         ex_lsu_csr_wen1,
    input         ex_lsu_csr_wen2,
    input  [31:0] ex_lsu_csr_wr_data1,
    input  [31:0] ex_lsu_csr_wr_data2,
    input  [11:0] ex_lsu_csr_wr_addr1,
    input  [11:0] ex_lsu_csr_wr_addr2,
    input  [31:0] ex_lsu_csr_rdata,
    input         ex_lsu_csr_ecall,
    input         ex_lsu_csr_mret,
    input  [31:0] ex_lsu_process_result,

    // 前递信号
    output [4:0]  lsu_ex_forward_rd,          // 前递的目标寄存器地址
    output        lsu_ex_forward_RegWrite,    // 前递使能
    output        lsu_ex_forward_MemRead,     // 前递加载标志

    // 传递到 WB 阶段的信号
    output reg [31:0] lsu_wb_inst,         // 指令
    output reg [31:0] lsu_wb_pc,           // 程序计数器
    input             ex_flush,
    output reg        lsu_wb_flush,
    output reg [31:0] lsu_wb_csr_wr_data1,
    output reg [31:0] lsu_wb_csr_wr_data2,
    output reg [11:0] lsu_wb_csr_wr_addr1,
    output reg [11:0] lsu_wb_csr_wr_addr2,
    output reg        lsu_wb_csr_wen1,
    output reg        lsu_wb_csr_wen2,
    output reg        lsu_wb_RegWrite,        // 寄存器写使能
    output reg [4:0]  lsu_wb_rd,              // 目标寄存器地址
    output reg [31:0] lsu_wb_write_rd_data,   // 写回寄存器的数据

    // AXI4-Lite 接口信号（与 SRAM 连接）
    output reg        lsu_sram_arvalid,       // 读地址有效
    input             sram_lsu_arready,       // 读地址就绪
    output reg [31:0] lsu_sram_araddr,        // 读地址
    input      [31:0] sram_lsu_rdata,         // 读数据
    input             sram_lsu_rvalid,        // 读数据有效
    output reg        lsu_sram_rready,        // 读数据就绪
    input      [1:0]  sram_lsu_rresp,         // 读响应

    output reg [31:0] lsu_sram_awaddr,        // 写地址
    output reg        lsu_sram_awvalid,       // 写地址有效
    input             sram_lsu_awready,       // 写地址就绪
    output reg [31:0] lsu_sram_wdata,         // 写数据
    output reg [3:0]  lsu_sram_wstrb,         // 写掩码
    output reg        lsu_sram_wvalid,        // 写数据有效
    input             sram_lsu_wready,        // 写数据就绪
    input      [1:0]  sram_lsu_bresp,         // 写响应
    input             sram_lsu_bvalid,        // 写响应有效
    output reg        lsu_sram_bready,        // 写响应就绪

    output reg [31:0] lsu_active_cycles
);

    import "DPI-C" function void ebreak(input int station, input int inst);
    import "DPI-C" function void counter(input int inst_type, input int ifu_inc, input int lsu_inc, input int exu_inc);

    parameter OKAY = 2'b00;

    // 内部寄存器
    reg        l_load;            // 加载标志
    reg        l_rd_en;           // 寄存器写使能
    reg [4:0]  l_rd_addr;         // 目标寄存器地址
    reg [31:0] l_inst;            // 指令
    reg [31:0] l_pc;              // 程序计数器
    reg [2:0]  l_MemLen;          // 内存访问长度
    reg [6:0]  l_opcode;          // 指令操作码

    reg        read_pending;      // 读请求等待标志
    reg        write_pending;     // 写请求等待标志
    reg        read_valid;        // 读事务完成标志
    reg        write_valid;       // 写事务完成标志
    reg [31:0] read_lsu_data;     // 从 SRAM 读取的数据

    // 前递信号赋值
    assign lsu_ex_forward_rd        = l_rd_addr;
    assign lsu_ex_forward_RegWrite  = l_rd_en;
    assign lsu_ex_forward_MemRead   = l_load;

    // reg [31:0] lsu_active_cycles; // LSU 活跃周期计数器
    always @(posedge clk) begin
        if (rst) begin
            lsu_active_cycles <= 0;
        end else if (read_pending || write_pending) begin
            lsu_active_cycles <= lsu_active_cycles + 1;
        end
    end

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
            l_opcode  <= l_inst[6:0];
        end 
        else if (ex_lsu_valid & lsu_ex_ready & ~(ex_lsu_MemRead | ex_lsu_MemWrite)) begin // 非访存指令
            l_load    <= l_load;
            l_rd_en   <= ex_lsu_RegWrite;
            l_rd_addr <= ex_lsu_rd;
            l_inst    <= ex_lsu_inst;
            l_pc      <= ex_lsu_pc;
            l_MemLen  <= ex_lsu_MemLen;
            l_opcode  <= l_inst[6:0];
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

    // 读通道控制
    always @(posedge clk) begin
        if (rst) begin
            lsu_sram_arvalid <= 0;
            lsu_sram_araddr  <= 32'h0;
            lsu_sram_rready  <= 0;
            read_pending     <= 0;
            read_valid       <= 0;
            read_lsu_data    <= 32'h0;
        end else begin
            // 发起读请求
            if (ex_lsu_valid & lsu_ex_ready & ex_lsu_MemRead & ~ex_lsu_MemWrite & ~read_pending) begin
                lsu_sram_arvalid <= 1;
                lsu_sram_araddr  <= addr;
                lsu_sram_rready  <= 1;
                read_pending     <= 1;
                read_valid       <= 0;
            end
            // 接受读地址响应
            if (lsu_sram_arvalid && sram_lsu_arready) begin
                lsu_sram_arvalid <= 0;
            end
            // 接受读数据
            if (sram_lsu_rvalid && lsu_sram_rready) begin
                lsu_sram_rready  <= 0;
                read_pending     <= 0;
                read_valid       <= 1;
                counter(7, 0, 1, 0);
                case (l_MemLen)
                    `Mem_UBit:  read_lsu_data <= {{24{1'b0}}, sram_lsu_rdata[7:0]};
                    `Mem_Bit:   read_lsu_data <= {{24{sram_lsu_rdata[7]}}, sram_lsu_rdata[7:0]};
                    `Mem_UHalf: read_lsu_data <= {{16{1'b0}}, sram_lsu_rdata[15:0]};
                    `Mem_Half:  read_lsu_data <= {{16{sram_lsu_rdata[15]}}, sram_lsu_rdata[15:0]};
                    `Mem_Word:  read_lsu_data <= sram_lsu_rdata;
                    default: begin
                        read_lsu_data <= 32'h0;
                        ebreak(`ABORT, 32'hdead_beef);
                        $display("\033[31mLSU_AXI: Unsupported memory read length %b at address %h\033[0m", l_MemLen, addr);
                    end
                endcase
                if (sram_lsu_rresp != OKAY) begin
                    ebreak(`ABORT, 32'hdead_beef);
                    $display("\033[31mLSU_AXI: Read access fault at address %h, rresp %b\033[0m", addr, sram_lsu_rresp);
                end
            end 
            else begin
                read_valid <= 0;
            end
        end
    end

    // 数据处理（符号扩展或零扩展）
    wire [31:0] wr_rd_data;
    assign wr_rd_data = (l_MemLen == `Mem_UBit) ? {{24{1'b0}}, read_lsu_data[7:0]} :
                        (l_MemLen == `Mem_Bit)  ? {{24{read_lsu_data[7]}}, read_lsu_data[7:0]} :
                        (l_MemLen == `Mem_UHalf)? {{16{1'b0}}, read_lsu_data[15:0]} :
                        (l_MemLen == `Mem_Half) ? {{16{read_lsu_data[15]}}, read_lsu_data[15:0]} :
                        (l_MemLen == `Mem_Word)? read_lsu_data : 32'b0;

    // 写通道控制
    always @(posedge clk) begin
        if (rst) begin
            lsu_sram_awvalid <= 0;
            lsu_sram_awaddr  <= 32'h0;
            lsu_sram_wvalid  <= 0;
            lsu_sram_wdata   <= 32'h0;
            lsu_sram_wstrb   <= 4'h0;
            lsu_sram_bready  <= 0;
            write_pending    <= 0;
            write_valid      <= 0;
        end else begin
            // 发起写请求
            if (ex_lsu_valid & lsu_ex_ready & ~ex_lsu_MemRead & ex_lsu_MemWrite & ~write_pending) begin
                lsu_sram_awvalid <= 1;
                lsu_sram_awaddr  <= addr;
                lsu_sram_wvalid  <= 1;
                lsu_sram_wdata   <= data_in;
                lsu_sram_bready  <= 1;
                case (ex_lsu_MemLen)
                    `Mem_Bit:  lsu_sram_wstrb <= 4'b0001; // sb
                    `Mem_Half: lsu_sram_wstrb <= 4'b0011; // sh
                    `Mem_Word: lsu_sram_wstrb <= 4'b1111; // sw
                    default: begin
                        lsu_sram_wstrb <= 4'b1111;
                        ebreak(`ABORT, 32'hdead_beef);
                        $display("\033[31mLSU_AXI: Unsupported memory write length %b at address %h\033[0m", ex_lsu_MemLen, addr);
                    end
                endcase
                write_pending <= 1;
                write_valid   <= 0;
            end
            // 接受写地址响应
            if (lsu_sram_awvalid && sram_lsu_awready) begin
                lsu_sram_awvalid <= 0;
            end
            // 接受写数据响应
            if (lsu_sram_wvalid && sram_lsu_wready) begin
                lsu_sram_wvalid <= 0;
            end
            // 接受写响应
            if (sram_lsu_bvalid && lsu_sram_bready) begin
                lsu_sram_bready <= 0;
                write_pending   <= 0;
                write_valid     <= 1;
                if (sram_lsu_bresp != OKAY) begin
                    ebreak(`ABORT, 32'hdead_beef);
                    $display("\033[31mLSU_AXI: Write access fault at address %h, bresp %b\033[0m", addr, sram_lsu_bresp);
                end
            end else begin
                write_valid <= 0;
            end
        end
    end

    // 写回数据选择
    reg [31:0] rd_data;
    always @(*) begin
        if (l_load) begin
            rd_data = wr_rd_data;
        end 
        else if (ex_lsu_forward_las) begin
            rd_data = data_in;
        end 
        else if (ex_lsu_MemWrite) begin
            rd_data = 32'h0;
        end 
        else if (ex_lsu_csr & !ex_lsu_csr_ecall & !ex_lsu_csr_mret) begin
            rd_data = ex_lsu_csr_rdata;
        end 
        else begin
            rd_data = ex_lsu_process_result;
        end
    end

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
            lsu_wb_RegWrite      <= 0;
            lsu_wb_rd            <= 0;
            lsu_wb_write_rd_data <= 0;
            lsu_wb_inst          <= 0;
            lsu_wb_pc            <= 0;
            lsu_wb_csr_wen1      <= 0;
            lsu_wb_csr_wen2      <= 0;
            lsu_wb_csr_wr_addr1  <= 0;
            lsu_wb_csr_wr_addr2  <= 0;
            lsu_wb_csr_wr_data1  <= 0;
            lsu_wb_csr_wr_data2  <= 0;
            lsu_wb_flush         <= 0;
        end else if (write_valid || read_valid) begin
            lsu_wb_RegWrite      <= l_rd_en;
            lsu_wb_rd            <= l_rd_addr;
            lsu_wb_csr_wen1      <= ex_lsu_csr_wen1;
            lsu_wb_csr_wen2      <= ex_lsu_csr_wen2;
            lsu_wb_csr_wr_addr1  <= ex_lsu_csr_wr_addr1;
            lsu_wb_csr_wr_addr2  <= ex_lsu_csr_wr_addr2;
            lsu_wb_csr_wr_data1  <= ex_lsu_csr_wr_data1;
            lsu_wb_csr_wr_data2  <= ex_lsu_csr_wr_data2;
            lsu_wb_write_rd_data <= rd_data;
            lsu_wb_inst          <= l_inst;
            lsu_wb_pc            <= l_pc;
            lsu_wb_flush         <= ex_flush;
        end else if (ex_lsu_valid & lsu_ex_ready & ~(ex_lsu_MemRead | ex_lsu_MemWrite)) begin
            lsu_wb_RegWrite      <= ex_lsu_RegWrite; // 非内存访问指令
            lsu_wb_rd            <= ex_lsu_rd;
            lsu_wb_csr_wen1      <= ex_lsu_csr_wen1;
            lsu_wb_csr_wen2      <= ex_lsu_csr_wen2;
            lsu_wb_csr_wr_addr1  <= ex_lsu_csr_wr_addr1;
            lsu_wb_csr_wr_addr2  <= ex_lsu_csr_wr_addr2;
            lsu_wb_csr_wr_data1  <= ex_lsu_csr_wr_data1;
            lsu_wb_csr_wr_data2  <= ex_lsu_csr_wr_data2;
            lsu_wb_write_rd_data <= rd_data;
            lsu_wb_inst          <= ex_lsu_inst;
            lsu_wb_pc            <= ex_lsu_pc;
            lsu_wb_flush         <= ex_flush;
        end
        // else begin
        //     lsu_wb_RegWrite      <= lsu_wb_RegWrite;
        //     lsu_wb_rd            <= lsu_wb_rd;
        //     lsu_wb_write_rd_data <= lsu_wb_write_rd_data;
        //     lsu_wb_inst          <= lsu_wb_inst;
        //     lsu_wb_pc            <= lsu_wb_pc;
        //     lsu_wb_csr_wr_data1  <= lsu_wb_csr_wr_data1;
        //     lsu_wb_csr_wr_data2  <= lsu_wb_csr_wr_data2;
        //     lsu_wb_csr_wr_addr1  <= lsu_wb_csr_wr_addr1;
        //     lsu_wb_csr_wr_addr2  <= lsu_wb_csr_wr_addr2;
        //     lsu_wb_csr_wen1      <= lsu_wb_csr_wen1;
        //     lsu_wb_csr_wen2      <= lsu_wb_csr_wen2;
        //     lsu_wb_flush         <= ex_flush;
        // end
    end


endmodule