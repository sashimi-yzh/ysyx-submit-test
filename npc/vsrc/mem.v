module ysyx_25050136_MEM
    #(
       parameter ADDR_WIDTH = 4
    )
    (
        input                                              clk ,
        input                                            reset ,
        input                                            flush ,
        input                                       in_valid_i ,
        input                                      in_ebreak_i ,
        input    [ADDR_WIDTH-1:0]                      in_rd_i ,
        input                                       in_rd_en_i ,
        input    [31:0]                         in_gpr_wdata_i ,
        input                                     in_req_ren_i ,
        input                                     in_req_wen_i ,
        input    [3:0]                           in_req_mask_i ,
        input                                  in_lsu_signed_i ,
        input    [31:0]                          in_req_addr_i ,
        input    [31:0]                         in_lsu_wdata_i ,
        output                                      in_ready_o ,
`ifdef YSYXSOC
        input      [31:0]                          in_dbg_pc_i ,
        input      [31:0]                        in_dbg_inst_i ,
        input      [5:0]                       in_dbg_optype_i ,
        output reg [31:0]                         out_dbg_pc_o ,
        output reg [31:0]                       out_dbg_inst_o ,
        output reg                         out_dbg_is_device_o ,
        output reg [5:0]                      out_dbg_optype_o ,
        output reg [31:0]                       out_dbg_addr_o ,
        output reg [31:0]                       out_dbg_data_o ,
        output reg [2:0]                         out_dbg_len_o ,
        output reg [1:0]                        out_dbg_type_o ,
`endif
        input                                      out_ready_i ,
        output   [ADDR_WIDTH-1:0]                     out_rd_o ,
        output                                    out_ebreak_o ,
        output                                     out_rd_en_o ,
        output   [31:0]                        out_gpr_wdata_o ,
        output                                     out_valid_o ,
        output                                           wen_o ,
        output   [ADDR_WIDTH-1:0]                      waddr_o ,
        output   [31:0]                                wdata_o ,
        output                                        wvalid_o ,
        // 与DCACHE握手信号
        input    [31:0]                            ret_rdata_i ,
        input                                      ret_ready_i ,
        output   [31:0]                            req_addr_o  ,
        output                                     req_valid_o ,
        output                                     req_ren_o   ,
        output                                     req_wen_o   ,
        output   [3:0]                             req_mask_o  ,
        output   [2:0]                             req_size_o  ,
        output                                     req_use_o   ,
        output   [31:0]                            req_wdata_o  
    );
    // ==== 信号定义 ====
    localparam IDLE       = 1'd0;
    localparam MISS       = 1'd1;
    // 时序逻辑
    reg idle;
    reg state;
    reg [ADDR_WIDTH-1:0] mem_rd;
    reg                  mem_ebreak;
    reg                  mem_rd_en;
    reg [31:0]           mem_gpr_wdata;
    reg [31:0]           mem_addr;
    reg                  mem_ren;
    reg                  mem_wen;
    reg                  mem_clint;
    // === 有访存时 ===
    reg [31:0]           ret_rdata;
    reg                  lsu_signed;
    reg [31:0]           lsu_wdata;
    reg                  req_valid;
    reg [3:0]            req_mask;
    // 组合逻辑
    wire in_fire = in_valid_i & in_ready_o;
    wire out_fire = out_valid_o & out_ready_i;
    wire ready_go;
    // === 有访存时 ===
    wire is_clint = (in_req_addr_i >= 32'h0200_0000) && (in_req_addr_i < 32'h0201_0000);
    wire mem_hit = (in_req_ren_i | in_req_wen_i) & ~is_clint;
    wire [31:0] clint_rdata;
    wire [3:0] byte_sel;
    reg [3:0] req_strb;
    reg [2:0] req_size;
    reg [31:0] req_wdata;
    reg [31:0] gpr_data;
    // ==== 逻辑实现 ====
    // === 无访存时 ===
    always @(posedge clk) begin
        if(reset) begin
            idle         <= 1;
            // mem_rd       <= 0;
            // mem_ebreak   <= 0;
            // mem_rd_en    <= 0;
            // mem_gpr_wdata <= 0;
            // mem_addr     <= 0;
            // mem_ren      <= 0;
            // mem_wen      <= 0;
            // mem_clint    <= 0;
        end else begin
            idle <= (flush) | (!in_fire & out_fire) | (!in_fire & !flush & idle);
            if(in_fire) begin
                mem_rd         <= in_rd_i;
                mem_ebreak     <= in_ebreak_i;
                mem_rd_en      <= in_rd_en_i;
                mem_gpr_wdata  <= in_gpr_wdata_i;
                mem_addr       <= in_req_addr_i;
                mem_ren        <= in_req_ren_i;
                mem_wen        <= in_req_wen_i;
                mem_clint      <= is_clint;
            end
        end
    end
    // === 有访存时 ===
    always @(posedge clk) begin
        if (reset) begin
            req_valid <= 0;
            req_mask <= 0;
            lsu_wdata <= 0;
            lsu_signed <= 0;
            ret_rdata <= 0;
            state <= IDLE;
        end else begin
            case(state)
                IDLE:begin
                    if(mem_hit & in_fire) begin
                        req_valid <= 1;
                        req_mask <= in_req_mask_i;
                        lsu_wdata <= in_lsu_wdata_i;
                        lsu_signed <= in_lsu_signed_i;
                        state <= MISS;
                    end
                end
                MISS:begin
                    if(ret_ready_i) begin
                        req_valid <= 0;
                        ret_rdata <= ret_rdata_i;
                        state <= IDLE;
                    end
                end
            endcase
        end
    end

    assign byte_sel = 4'b1 << mem_addr[1:0];
    assign req_addr_o = mem_addr;
    assign req_valid_o = req_valid;
    assign req_ren_o = mem_ren;
    assign req_wen_o = mem_wen;
    assign req_mask_o = req_strb;
    assign req_size_o = req_size;
    assign req_use_o = 1'b1;
    assign req_wdata_o = req_wdata;
    // === 读写数据处理 ===
    always @(*) begin
        req_strb = 0;
        req_size = 0;
        req_wdata = 0;
        gpr_data = 0;
        case (req_mask)
            4'h1: begin // Byte操作
                req_strb = byte_sel;
                req_size = 3'b000;
                req_wdata = {24'd0, {lsu_wdata[7:0]}} << (8 * mem_addr[1:0]);
                gpr_data = lsu_signed ?
                    {{24{ret_rdata[8*mem_addr[1:0] + 7]}}, ret_rdata[8*mem_addr[1:0] +: 8]} :
                    {24'd0, ret_rdata[8*mem_addr[1:0] +: 8]};
            end
            4'h3: begin // Halfword操作
                req_strb = byte_sel | (byte_sel << 1);
                req_size = 3'b001;
                req_wdata = {16'd0, lsu_wdata[15:0]} << (8 * mem_addr[1:0]);
                gpr_data = lsu_signed ?
                    {{16{ret_rdata[16*mem_addr[1] + 15]}}, ret_rdata[16*mem_addr[1] +: 16]} :
                    {16'd0, ret_rdata[16*mem_addr[1] +: 16]};
            end
            4'hF: begin // Word操作
                req_strb = 4'hF;
                req_size = 3'b010;
                req_wdata = lsu_wdata;
                gpr_data = ret_rdata;
            end
            default;
        endcase
    end
    
    ysyx_25050136_CLINT 
    u_ysyx_25050136_CLINT(
        .clk    	(clk          ),
        .reset  	(reset        ),
        .addr_i 	(mem_addr     ),
        .data_o 	(clint_rdata  )
    );
    
    // === 输出选择器 ===
    assign out_gpr_wdata_o = mem_ren ? (mem_clint ? clint_rdata : gpr_data) : mem_gpr_wdata;
    assign out_rd_o = mem_rd;
    assign out_ebreak_o = mem_ebreak;
    assign out_rd_en_o = mem_rd_en;
    assign waddr_o = mem_rd;
    assign wdata_o = mem_gpr_wdata;
    assign wvalid_o = mem_rd_en & !mem_ren & out_valid_o;
    assign wen_o = mem_rd_en & (out_valid_o | ~idle);
    // === 握手信号 ===
    assign ready_go = (state === IDLE);
    assign in_ready_o = idle || out_fire;
    assign out_valid_o = !(idle || flush) && ready_go;
`ifdef YSYXSOC
    always @(posedge clk) begin
        if(reset) begin
            out_dbg_is_device_o <= 0;
        end else begin
            if((req_valid_o && !((req_addr_o >= 32'h3000_0000 && req_addr_o < 32'h4000_0000) || 
                   (req_addr_o >= 32'h0f00_0000 && req_addr_o < 32'h1000_0000) ||
                   (req_addr_o >= 32'ha000_0000 && req_addr_o < 32'hc000_0000))) || (in_fire && is_clint && in_req_ren_i)) begin
                    out_dbg_is_device_o <= 1;
            end else if(out_fire) begin
                    out_dbg_is_device_o <= 0;                
            end
        end
    end
    always @(posedge clk) begin
        if(reset) begin
            out_dbg_pc_o   <= 0;
            out_dbg_inst_o <= 0;
        end else begin
            if(flush) begin
            end else if(in_fire) begin
                out_dbg_pc_o   <= in_dbg_pc_i;
                out_dbg_inst_o <= in_dbg_inst_i;
                out_dbg_optype_o <= in_dbg_optype_i;
            end if(out_fire) begin
            end 
        end
    end
    always @(posedge clk) begin
        if(reset) begin
            out_dbg_addr_o <= 0;
            out_dbg_data_o <= 0;
            out_dbg_len_o  <= 0;
            out_dbg_type_o <= 0;
        end else begin
            if(flush) begin
            end else if(in_fire) begin
                out_dbg_addr_o <= in_req_addr_i;
                case(in_req_mask_i)
                    4'h1: begin 
                        out_dbg_data_o <= {24'd0, in_lsu_wdata_i[7:0]};
                        out_dbg_len_o <= 3'd1;
                    end
                    4'h3: begin 
                        out_dbg_data_o <= {16'd0, in_lsu_wdata_i[15:0]};
                        out_dbg_len_o <= 3'd2;
                    end
                    4'hf: begin 
                        out_dbg_data_o <= in_lsu_wdata_i;
                        out_dbg_len_o <= 3'd4;
                    end
                    default;
                endcase
                if(in_req_wen_i) out_dbg_type_o <= 2'd2;
                else out_dbg_type_o <= 0;
            end if(out_fire) begin
            end 
        end
    end
`endif
endmodule
