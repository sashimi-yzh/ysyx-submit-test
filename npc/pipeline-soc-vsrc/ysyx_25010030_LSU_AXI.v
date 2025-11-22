
`include "ysyx_25010030_define.vh"

module ysyx_25010030_LSU_AXI (
    input             clk,
    input             rst,

    // 流水线握手信号
    input             ex_lsu_valid,       
    output reg        lsu_ex_ready,       
    input             wb_lsu_ready,       
    output reg        lsu_wb_valid,       

    // EX 阶段输入信号
    input              ex_lsu_forward_las,
    input              ex_lsu_RegWrite,    
    input       [ 3:0] ex_lsu_rd,          
    input              ex_lsu_MemRead,     
    input              ex_lsu_MemWrite,    
    input       [ 4:0] ex_lsu_MemLen,
`ifdef DIFFTEST       
    input       [31:0] ex_lsu_pc,
    output reg  [31:0] lsu_wb_pc,
`endif        
    input       [31:0] addr,               
    input       [31:0] data_in,              

    // CSR 相关信号
    input              ex_lsu_csr,
    input              ex_lsu_csr_wen1,
    input       [31:0] ex_lsu_csr_wr_data1,
    input       [31:0] ex_lsu_csr_wr_data2,
    input       [11:0] ex_lsu_csr_wr_addr1,
    input       [31:0] ex_lsu_csr_rdata,
    input              ex_lsu_csr_ecall,
    input              ex_lsu_csr_mret,
    input       [31:0] ex_lsu_process_result,

    // 前递信号
    output      [ 3:0] lsu_ex_forward_rd,         
    output             lsu_ex_forward_RegWrite,   
    output             lsu_ex_forward_MemRead,    

    // 传递到 WB 阶段的信号
    output reg  [31:0] lsu_wb_csr_wr_data1,
    output reg  [31:0] lsu_wb_csr_wr_data2,
    output reg  [11:0] lsu_wb_csr_wr_addr1,
    output reg         lsu_wb_csr_wen1,
    output reg         lsu_wb_csr_ecall,
    output reg         lsu_wb_RegWrite,        
    output reg  [ 3:0] lsu_wb_rd,              
    output reg  [31:0] lsu_wb_write_rd_data,   

`ifdef DCACHE
    output reg  [31:0] lsu_dcache_addr,
    output reg         lsu_dcache_wen,
    output reg         lsu_dcache_req,
    input              dcache_valid,
    output reg  [31:0] lsu_dcache_wdata,
    output reg  [ 3:0] lsu_dcache_wstrb,
    input       [31:0] dcache_rdata,
    output reg  [ 2:0] lsu_dcache_arsize,
    output reg  [ 2:0] lsu_dcache_awsize
`else
    // AXI4-Lite 接口信号
    output reg         lsu_axi_arvalid,      
    input              axi_lsu_arready,      
    output wire [31:0] lsu_axi_araddr,
    output wire [ 3:0] lsu_axi_arid,
    output wire [ 7:0] lsu_axi_arlen,
    output reg  [ 2:0] lsu_axi_arsize,
    output wire [ 1:0] lsu_axi_arburst,        
    input       [31:0] axi_lsu_rdata,         
    input              axi_lsu_rvalid,       
    output reg         lsu_axi_rready,       
    input       [ 1:0] axi_lsu_rresp,
    input       [ 3:0] axi_lsu_rid,
    input              axi_lsu_rlast,         

    output wire [31:0] lsu_axi_awaddr,        
    output reg         lsu_axi_awvalid,      
    input              axi_lsu_awready, 
    output wire [ 3:0] lsu_axi_awid,
    output wire [ 7:0] lsu_axi_awlen,
    output reg  [ 2:0] lsu_axi_awsize,
    output wire [ 1:0] lsu_axi_awburst,     
    output wire [31:0] lsu_axi_wdata,         
    output wire [ 3:0] lsu_axi_wstrb,         
    output reg         lsu_axi_wvalid,       
    input              axi_lsu_wready,
    output reg         lsu_axi_wlast,       
    input       [ 1:0] axi_lsu_bresp,         
    input              axi_lsu_bvalid,       
    output wire        lsu_axi_bready,
    input       [ 3:0] axi_lsu_bid     
`endif
);
    localparam SDRAM_BASE        = 32'hA0000000;  
    localparam SDRAM_END         = 32'hBFFFFFFF;  
    localparam AXI_BURST_FIXED   = 2'b00;       
    localparam AXI_BURST_INCR    = 2'b01;   
    localparam AXI_SIZE_BYTE     = 3'h0;         
    localparam AXI_SIZE_HALF     = 3'h1;  
    localparam AXI_SIZE_WORD     = 3'h2;
    localparam AXI_ID            = 4'h0;  
    localparam BURST_LEN         = 4; 
    localparam BLOCK_SIZE        = 16;
`ifdef YSYXSOC
    wire in_sdram = (saved_addr >= SDRAM_BASE) && (saved_addr <= SDRAM_END);
`else
    wire in_sdram = 0;
`endif

    localparam BLOCK_OFFSET_WIDTH = 4; 
    wire [ 1:0] word_offset = addr[3:2];

    reg  [ 1:0] saved_word_offset;
    reg  [31:0] saved_wdata;  
    reg  [ 3:0] saved_wstrb; 
    reg  [ 3:0] burst_cnt; 

    reg  [ 1:0] addr_off;   
    reg  [31:0] rdata;    
    reg         valid;   
    reg  [31:0] saved_addr; 

    reg [             4:0]  l_MemLen;

`ifdef DCACHE
    localparam IDLE = 2'b00;
    localparam WAIT = 2'b01;
`else
    localparam IDLE = 2'b00; 
    localparam RD   = 2'b10; 
    localparam WR   = 2'b01; 
`endif
    reg [1:0] lsu_state, lsu_next_state;

    wire we = (ex_lsu_valid & lsu_ex_ready & ex_lsu_MemWrite);
    wire req_valid = ((ex_lsu_valid & lsu_ex_ready) & (ex_lsu_MemRead | ex_lsu_MemWrite));

    always @(posedge clk) begin
        if (lsu_state == IDLE & req_valid) begin
            addr_off          <= addr[1:0];
            saved_addr        <= addr; 
            saved_word_offset <= word_offset;
            saved_wdata       <= (ex_lsu_MemLen[3:0] == 4'b0001) ? ({24'b0, data_in[7:0]} << (addr[1:0] * 8)) :
                                 (ex_lsu_MemLen[3:0] == 4'b0011) ? (addr[1:0] == 2'b00 ? {16'b0, data_in[15:0]} :
                                                                    addr[1:0] == 2'b10 ? {data_in[15:0], 16'b0} :
                                                                    data_in) : data_in;
            saved_wstrb       <= ex_lsu_MemLen[3:0] << addr[1:0];
        end
    end

`ifdef DCACHE
    always @(posedge clk) begin
        if (rst) begin
            lsu_state <= IDLE;
        end else begin
            lsu_state <= lsu_next_state;
        end
    end

    always @(*) begin
        case (lsu_state)
            IDLE: lsu_next_state = req_valid ? WAIT : IDLE;
            WAIT: lsu_next_state = valid ? IDLE : WAIT;
            default: lsu_next_state = IDLE;
        endcase
    end

    always @(posedge clk) begin
        if (rst) begin
            valid <= 0;
        end
        else if(lsu_state == WAIT) begin
            valid <= dcache_valid;
        end
    end

    always @(*) begin
        if (rst) begin
            lsu_dcache_req    = 1'b0;
            lsu_dcache_wen    = 1'b0;
            lsu_dcache_addr   = 32'h0;
            lsu_dcache_wdata  = 32'h0;
            lsu_dcache_wstrb  = 4'h0;
            lsu_dcache_arsize = 3'h0;
            lsu_dcache_awsize = 3'h0;
        end else begin
            if (lsu_state == IDLE & req_valid) begin
                lsu_dcache_req   = 1'b1;
                lsu_dcache_wen   = we;
                lsu_dcache_addr  = addr;
                lsu_dcache_wdata = (ex_lsu_MemLen[3:0] == 4'b0001) ? ({24'b0, data_in[7:0]} << (addr[1:0] * 8)) :
                                   (ex_lsu_MemLen[3:0] == 4'b0011) ? (addr[1:0] == 2'b00 ? {16'b0, data_in[15:0]} :
                                                                    addr[1:0] == 2'b10 ? {data_in[15:0], 16'b0} :
                                                                    data_in) : data_in;
                lsu_dcache_wstrb = ex_lsu_MemLen[3:0] << addr[1:0];
                case(ex_lsu_MemLen[3:0])
                    4'b0001: begin
                        lsu_dcache_arsize = AXI_SIZE_BYTE;
                        lsu_dcache_awsize = AXI_SIZE_BYTE;
                    end
                    4'b0011: begin
                        lsu_dcache_arsize = AXI_SIZE_HALF;
                        lsu_dcache_awsize = AXI_SIZE_HALF;
                    end
                    default: begin
                        lsu_dcache_arsize = AXI_SIZE_WORD;
                        lsu_dcache_awsize = AXI_SIZE_WORD;
                    end
                endcase
            end else if (lsu_state == WAIT & dcache_valid) begin
                lsu_dcache_req = 1'b0;
            end
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            rdata <= 32'h0;
        end else if (lsu_state == WAIT & dcache_valid) begin
            rdata <= dcache_rdata;
        end
    end
`else
    reg        aw_done;  
    reg        w_done;   
    reg        b_done;   
    reg        ar_done;
    // reg        valid; 

    always @(posedge clk) begin
        if (rst) begin
            lsu_state <= IDLE;
        end else begin
            lsu_state <= lsu_next_state;
        end
    end

    always @(*) begin
        case (lsu_state)
            IDLE: lsu_next_state = req_valid ? (we ? WR : RD) : IDLE;
            RD:   lsu_next_state = (axi_lsu_rvalid && lsu_axi_rready && axi_lsu_rlast) ? IDLE : RD;
            WR:   lsu_next_state = (aw_done && w_done && b_done) ? IDLE : WR;
            default: lsu_next_state = IDLE;
        endcase
    end
    
    always @(posedge clk) begin
        if(lsu_state == IDLE) begin
            aw_done <= 0;
            w_done  <= 0;
            b_done  <= 0;
            burst_cnt <= 0;
        end
        else begin
            if(axi_lsu_rvalid && lsu_axi_rready) begin
                burst_cnt <= burst_cnt + 1;
            end
            if (lsu_axi_awvalid && axi_lsu_awready               ) aw_done <= 1'b1;
            if (lsu_axi_wvalid && axi_lsu_wready && lsu_axi_wlast) w_done  <= 1'b1;
            if (axi_lsu_bvalid && lsu_axi_bready                 ) b_done  <= 1'b1;
        end
    end

    reg [BLOCK_SIZE*8-1:0] block_data;

    assign lsu_axi_arid    = AXI_ID;
    assign lsu_axi_araddr  = in_sdram ? {saved_addr[31:BLOCK_OFFSET_WIDTH], {BLOCK_OFFSET_WIDTH{1'b0}}} : saved_addr;
    assign lsu_axi_arburst = in_sdram ? AXI_BURST_INCR : AXI_BURST_FIXED;
    assign lsu_axi_arlen   = in_sdram ? BURST_LEN - 1 : 8'h0;
    
    assign lsu_axi_awburst = AXI_BURST_FIXED;
    assign lsu_axi_awid    = AXI_ID;
    assign lsu_axi_awlen   = 8'h0;
    assign lsu_axi_awaddr  = saved_addr;
    assign lsu_axi_wstrb   = saved_wstrb;
    assign lsu_axi_wdata   = saved_wdata;
    assign lsu_axi_bready  = 1'b1;

    always @(*) begin
        case(l_MemLen[3:0])
            4'b0001: lsu_axi_awsize = AXI_SIZE_BYTE;
            4'b0011: lsu_axi_awsize = AXI_SIZE_HALF;
            default: lsu_axi_awsize = AXI_SIZE_WORD; 
        endcase
        case(l_MemLen[3:0])
            4'b0001: lsu_axi_arsize = AXI_SIZE_BYTE;
            4'b0011: lsu_axi_arsize = AXI_SIZE_HALF;
            default: lsu_axi_arsize = AXI_SIZE_WORD; 
        endcase
    end

    always @(posedge clk) begin
        if (rst) begin
            lsu_axi_awvalid <= 1'b0;
            lsu_axi_wvalid  <= 1'b0;
            lsu_axi_arvalid <= 1'b0;
        end 
        if (lsu_state == RD) begin
            if (!ar_done && !lsu_axi_arvalid) begin
                lsu_axi_arvalid <= 1'b1;
            end else if (axi_lsu_arready) begin
                lsu_axi_arvalid <= 1'b0;  
                ar_done         <= 1'b1;
            end
            lsu_axi_rready <= 1'b1;
            if(axi_lsu_rvalid && in_sdram) begin
                block_data[burst_cnt*32 +: 32] = axi_lsu_rdata;
            end
        end 
        else begin
            lsu_axi_arvalid <= 1'b0; 
            ar_done         <= 1'b0;
        end

        if (lsu_state == WR) begin
            if (!lsu_axi_awvalid && !aw_done) begin
                lsu_axi_awvalid <= 1'b1;
            end else if (axi_lsu_awready) begin
                lsu_axi_awvalid <= 1'b0;  // 地址握手完成后清零
            end

            if (!lsu_axi_wvalid && !w_done) begin
                lsu_axi_wvalid <= 1'b1;
                lsu_axi_wlast  <= 1'b1; 
            end else if (axi_lsu_wready) begin
                lsu_axi_wvalid <= 1'b0;
                lsu_axi_wlast  <= 1'b0;
            end
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            rdata  <= 32'h0;
            valid  <= 1'b0;
        end else begin  
            valid <= 1'b0;
            if (axi_lsu_rvalid && lsu_axi_rready && axi_lsu_rlast) begin
                rdata <= in_sdram ? block_data[saved_word_offset*32 +: 32] : axi_lsu_rdata;
                valid <= 1'b1;
            end
            if(aw_done && w_done && b_done) begin
                valid <= 1'b1;
            end
        end
    end
`endif

    reg        l_load;            
    reg        l_rd_en;           
    reg [3:0]  l_rd_addr;                  

    // 前递信号赋值
    assign lsu_ex_forward_rd        = l_rd_addr;
    assign lsu_ex_forward_RegWrite  = l_rd_en;
    assign lsu_ex_forward_MemRead   = l_load;

    // 寄存器更新逻辑
    always @(posedge clk) begin
        if (rst) begin
            l_load    <= 0;
            l_rd_en   <= 0;
            l_rd_addr <= 0;
            l_MemLen  <= 0;
        end 
        else if (req_valid) begin
            l_load    <= ex_lsu_MemRead;
            l_rd_en   <= ex_lsu_RegWrite;
            l_rd_addr <= ex_lsu_rd;
            l_MemLen  <= ex_lsu_MemLen;
        end 
        else if (lsu_wb_valid & wb_lsu_ready) begin
            l_load    <= 0;
            l_rd_en   <= ex_lsu_RegWrite;
            l_rd_addr <= ex_lsu_rd;
            l_MemLen  <= ex_lsu_MemLen;
        end 
        else if (ex_lsu_valid & lsu_ex_ready & ~(ex_lsu_MemRead | ex_lsu_MemWrite)) begin // 非访存指令
            l_load    <= 0;
            l_rd_en   <= ex_lsu_RegWrite;
            l_rd_addr <= ex_lsu_rd;
            l_MemLen  <= ex_lsu_MemLen;
        end 
    end

`ifdef DIFFTEST
    reg [31:0] l_pc;
    always @(posedge clk) begin
        if (rst) begin
            l_pc      <= 0;//FOR DIFFTEST//
        end 
        else if (req_valid) begin
            l_pc      <= ex_lsu_pc;//FOR DIFFTEST//
        end 
        else if (lsu_wb_valid & wb_lsu_ready) begin
            l_pc      <= ex_lsu_pc;//FOR DIFFTEST//
        end 
        else if (ex_lsu_valid & lsu_ex_ready & ~(ex_lsu_MemRead | ex_lsu_MemWrite)) begin // 非访存指令
            l_pc      <= ex_lsu_pc;//FOR DIFFTEST//
        end 
    end
`endif

    wire [31:0] byte_data1 = (rdata >> (addr_off*8));
    wire [ 7:0] byte_data = byte_data1[7:0];
    wire [15:0] half_data = (addr_off == 2'b10) ? (rdata[31:16]) : rdata[15:0];
    wire [31:0] read_lsu_data = (l_MemLen == `Mem_Bit  ) ? {{24{byte_data[7]}}, byte_data} :
                                (l_MemLen == `Mem_UBit ) ? {24'b0, byte_data} :
                                (l_MemLen == `Mem_Half ) ? {{16{half_data[15]}}, half_data} :
                                (l_MemLen == `Mem_UHalf) ? {16'b0, half_data} :
                                rdata;
                                
    // 写回数据选择
    reg [31:0] rd_data;
    always @(*) begin
        if (l_load) begin
            rd_data = read_lsu_data;
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
        else if (req_valid) begin
            lsu_ex_ready <= 0;
        end 
        else if (lsu_wb_valid & wb_lsu_ready) begin
            lsu_ex_ready <= 1;
        end 
    end

    always @(posedge clk) begin
        if (rst) begin
            lsu_wb_valid <= 0;
        end 
        else if (ex_lsu_valid & lsu_ex_ready) begin
            lsu_wb_valid <= ~(ex_lsu_MemRead | ex_lsu_MemWrite);
        end 
        else if (valid) begin
            lsu_wb_valid <= 1;
        end 
        else if ((~(ex_lsu_valid && lsu_ex_ready)) && lsu_wb_valid) begin
            lsu_wb_valid <= 0;
        end
    end

    // 输出到 WB 阶段
    always @(posedge clk) begin
        if (valid) begin
            lsu_wb_RegWrite      <= l_rd_en;
            lsu_wb_rd            <= l_rd_addr;
            lsu_wb_csr_wen1      <= ex_lsu_csr_wen1;
            lsu_wb_csr_ecall     <= ex_lsu_csr_ecall;
            lsu_wb_csr_wr_addr1  <= ex_lsu_csr_wr_addr1;
            lsu_wb_csr_wr_data1  <= ex_lsu_csr_wr_data1;
            lsu_wb_csr_wr_data2  <= ex_lsu_csr_wr_data2;
            lsu_wb_write_rd_data <= rd_data;
`ifdef DIFFTEST
            lsu_wb_pc <= l_pc; // FOR DIFFTEST//
`endif
        end else if (ex_lsu_valid & lsu_ex_ready & ~(ex_lsu_MemRead | ex_lsu_MemWrite)) begin
            lsu_wb_RegWrite      <= ex_lsu_RegWrite; // 非内存访问指令
            lsu_wb_rd            <= ex_lsu_rd;
            lsu_wb_csr_wen1      <= ex_lsu_csr_wen1;
            lsu_wb_csr_ecall     <= ex_lsu_csr_ecall;
            lsu_wb_csr_wr_addr1  <= ex_lsu_csr_wr_addr1;
            lsu_wb_csr_wr_data1  <= ex_lsu_csr_wr_data1;
            lsu_wb_csr_wr_data2  <= ex_lsu_csr_wr_data2;
            lsu_wb_write_rd_data <= rd_data;
`ifdef DIFFTEST
            lsu_wb_pc <= ex_lsu_pc; // FOR DIFFTEST//
`endif
        end
    end


endmodule
