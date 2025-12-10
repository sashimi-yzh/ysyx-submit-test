module ysyx_25050136_CSRU
     (
         input                                              clk,
         input   [31:0]                                    pc_i,
         input   [`ysyx_25050136_CSRU_OP_NUM-1:0]   operation_i,
         input   [31:0]                            csru_wdata_i,
         input   [11:0]                             csru_addr_i,
         input                                       csru_ren_i,
         input                                       csru_wen_i,
         output  reg [31:0]                        csru_rdata_o
     );

    reg [31:0] csr_wdata1, csr_wdata2;
    reg [11:0] csr_waddr1, csr_waddr2, csr_raddr;
    reg csr_wen1, csr_wen2, csr_ren;
    always @(*) begin
        csr_wdata1 = csru_wdata_i;
        csr_waddr1 = csru_addr_i;
        csr_wen1 = csru_wen_i;
        csr_raddr = csru_addr_i;
        csr_ren = csru_ren_i;
        csr_wdata2 = 0;
        csr_waddr2 = 0;
        csr_wen2 = 0;
        case (1'b1)
            operation_i[`ysyx_25050136_CSRU_CSRRS]: begin
                csr_wdata1 = csru_rdata_o | csru_wdata_i;
            end
            operation_i[`ysyx_25050136_CSRU_CSRRC]: begin
                csr_wdata1 = csru_rdata_o & (~csru_wdata_i);
            end
            operation_i[`ysyx_25050136_CSRU_ECALL]: begin
                csr_wdata1 = pc_i;
                csr_waddr1 = 12'h341;
                csr_wdata2 = 32'd11;
                csr_waddr2 = 12'h342;
                csr_wen2   = 1;
            end
            default:;
        endcase
    end
    
    // CSR 地址参数
    localparam MEPC      = 12'h341;
    localparam MCAUSE    = 12'h342;
    localparam MTVEC     = 12'h305;
    localparam MSTATUS   = 12'h300;
    // 只读CSR
    localparam MVENDORID = 12'hf11;
    localparam MARCHID   = 12'hf12;

    // CSR 物理寄存器
    reg [31:0] mepc, mcause, mtvec, mstatus;

    // --- 写寄存器逻辑 (时序逻辑) ---
    // 将两个写端口的逻辑合并到一个 always 块中
    always @(posedge clk) begin
        // --- 处理写端口 1 ---
        if (csr_wen1) begin
            case (csr_waddr1)
                MEPC:    mepc    <= csr_wdata1;
                MCAUSE:  mcause  <= csr_wdata1;
                MTVEC:   mtvec   <= csr_wdata1;
                MSTATUS: mstatus <= csr_wdata1;
                default: ; // 端口1写其他地址，无操作
            endcase
        end

        // --- 处理写端口 2 ---
        if (csr_wen2) begin
            case (csr_waddr2)
                MEPC:    mepc    <= csr_wdata2;
                MCAUSE:  mcause  <= csr_wdata2;
                MTVEC:   mtvec   <= csr_wdata2;
                MSTATUS: mstatus <= csr_wdata2;
                default: ; // 端口2写其他地址，无操作
            endcase
        end
    end

    // --- 读寄存器逻辑 (组合逻辑) ---
    always @(*) begin
        csru_rdata_o = 32'b0;
        if (csr_ren) begin
            case (csr_raddr)
                MEPC:      csru_rdata_o = mepc;
                MCAUSE:    csru_rdata_o = mcause;
                MTVEC:     csru_rdata_o = mtvec;
                MSTATUS:   csru_rdata_o = mstatus;
                MVENDORID: csru_rdata_o = 32'h79737978; // "ysyx"
                MARCHID:   csru_rdata_o = 32'd25050136; // 你的学号
                default:   csru_rdata_o = 32'b0;       // 读取未实现的CSR返回0
            endcase
        end
    end
endmodule
