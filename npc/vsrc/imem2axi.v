module ysyx_25050136_IMEM2AXI
#(
    parameter OFFSET_WIDTH = 4 // cache line = 16B
)
(
    input                                      clk          ,
    input                                      reset        ,
    // 读地址                                        
    output                                     m_arvalid_o  ,
    input                                      m_arready_i  ,
    output   [31:0]                            m_araddr_o   ,
    output   [3:0]                             m_arid_o     ,
    output   [7:0]                             m_arlen_o    ,
    output   [2:0]                             m_arsize_o   ,
    output   [1:0]                             m_arburst_o  ,
    // 读数据                                        
    input                                      m_rvalid_i   ,
    output                                     m_rready_o   ,
    input    [31:0]                            m_rdata_i    ,
    input    [1:0]                             m_rresp_i    ,
    input                                      m_rlast_i    ,
    input    [3:0]                             m_rid_i      ,
    // 内部
    input                                      flush_i      ,
    input                                      req_valid_i  ,
    input    [31:0]                            req_addr_i   ,
    output                                     ret_valid_o  ,
    output                                     ret_last_o   ,
    output   [31:0]                            ret_data_o   
);    
    // ==================== axi信号定义 ================================
    parameter BURST_NUM = 2 ** (OFFSET_WIDTH - 2) - 1;
    localparam READ_IDLE = 2'd0;
    localparam READ_ADDR = 2'd1;
    localparam READ_DATA = 2'd2;
    // 由于flush信号引发的读数据丢弃
    reg is_flush;
    // axi读请求信号
    reg [1:0] state_read;
    reg m_rready_r;
    reg [3:0] m_arid_r;
    reg [31:0] m_araddr_r;
    reg [7:0] m_arlen_r;
    reg [2:0] m_arsize_r;
    reg [1:0] m_arburst_r;
    wire ar_fire, r_fire;
    // 根据存储介质，选择读取方式
    reg [1:0] cnt;
    wire is_sdram_region = (req_addr_i[31:28] == 4'hA); // 0xA000_0000 ~ 0xAFFF_FFFF (越界问题由设备端判断)
    wire [31:0] align_addr = {req_addr_i[31:OFFSET_WIDTH], {OFFSET_WIDTH{1'b0}}};
    wire [31:0] real_addr = align_addr + {28'd0, cnt, 2'd0};
    // ==================== axi信号定义 ================================
    // 读事务
    always @(posedge clk) begin
        if (reset) begin
            state_read      <= READ_IDLE;
            is_flush        <= 0;
            cnt             <= 0;
            m_araddr_r      <= 0;
            m_arid_r        <= 0;
            m_arlen_r       <= 0;   
            m_arsize_r      <= 0;
            m_arburst_r     <= 0;
            m_rready_r      <= 0;
        end else begin
            case(state_read)
                READ_IDLE: begin
                    m_rready_r <= 1;
                    if(is_flush | flush_i) begin
                        is_flush <= 0;
                        cnt <= 0;
                    end else if(req_valid_i) begin
                        state_read <= READ_ADDR;
                        m_arid_r    <= 4'b1000;
                        m_arsize_r  <= 3'b010;
                        m_araddr_r  <= real_addr;
                        if(is_sdram_region) begin // cache line
                            m_arlen_r   <= BURST_NUM;      
                            m_arburst_r <= 2'b01;          
                        end else begin // word
                            m_arlen_r   <= 0;
                            m_arburst_r <= 2'b00;
                        end
                    end
                end 
                READ_ADDR: begin
                    if(flush_i) begin
                        is_flush <= 1;
                    end
                    if (ar_fire) begin
                        if(!is_sdram_region) begin
                            cnt <= cnt + 1;
                        end
                        m_araddr_r <= 0;
                        m_arlen_r <= 0;
                        m_arsize_r <= 0;
                        m_arburst_r <= 0;
                        state_read <= READ_DATA;                        
                    end
                end 
                READ_DATA: begin
                    if(flush_i) begin
                        is_flush <= 1;
                    end
                    if (r_fire) begin
                        if(m_rlast_i) begin
                            m_arid_r <= 0;
                            state_read <= READ_IDLE;
                        end
                        m_rready_r <= 0;
                    end else begin
                        m_rready_r <= 1;                        
                    end
                end 
                default: ;
            endcase
        end
    end

    assign m_arvalid_o = (state_read == READ_ADDR);
    assign m_araddr_o  = m_araddr_r;
    assign m_arid_o = m_arid_r;
    assign m_arlen_o = m_arlen_r;
    assign m_arsize_o = m_arsize_r;
    assign m_arburst_o = m_arburst_r;
    assign m_rready_o = m_rready_r;
    
    assign ar_fire = m_arvalid_o & m_arready_i;
    assign r_fire = m_rvalid_i & m_rready_o;

    assign ret_valid_o = !is_flush & r_fire;
    assign ret_last_o = !is_flush & m_rlast_i & r_fire && (cnt == 0);
    assign ret_data_o = m_rdata_i;
// ========================Simulation only====================================
`ifdef verilator
reg [79:0] dbg_axi_state;
always @(*) begin
    case (state_read)
        READ_IDLE   : dbg_axi_state = "READ_IDLE";
        READ_ADDR   : dbg_axi_state = "READ_ADDR";
        READ_DATA   : dbg_axi_state = "READ_DATA";
        default     : dbg_axi_state = "UNKNOW";
    endcase
end
`endif
endmodule //ysyx_25050136_ICACHE
