module ysyx_25050136_LSU
     (
        input                         clk          ,
        input                         reset        ,
        // 与dcache握手信号
        input    [31:0]               req_rdata_i  ,
        input                         req_ready_i  ,
        output   [31:0]               req_addr_o   ,
        output                        req_valid_o  ,
        output                        req_ren_o    ,
        output                        req_wen_o    ,
        output   [3:0]                req_mask_o   ,
        output   [2:0]                req_size_o   ,
        output                        req_use_o    ,
        output   [31:0]               req_wdata_o  ,
        // 与clint握手信号
        input    [31:0]               clint_rdata_i,
        input                         clint_ready_i,
        output                        clint_valid_o,
        output   [31:0]               clint_addr_o , 
        // 组合输入
        input                         lsu_en_i     ,
        input                         lsu_ren_i    ,
        input                         lsu_wen_i    ,             
        input    [31:0]               lsu_addr_i   ,
        input    [3:0]                lsu_wmask_i  ,
        input                         lsu_wsigned_i,
        // 时序输入
        input    [3:0]                lsu_rmask_i  ,
        input                         lsu_rsigned_i,
        input                         lsu_signed_i ,
        input    [31:0]               store_data_i ,
        output   [31:0]               load_data_o  ,
        output                        busy_mem_o
     );
    // 地址对齐检查
    // wire misaligned = (lsu_mask_i == 4'h3) ? lsu_addr_i[0] :       // halfword检查bit[0]
    //                   (lsu_mask_i == 4'hF) ? |lsu_addr_i[1:0] :    // word检查bit[1:0]
    //                   1'b0;                                        // byte总是对齐
    wire [3:0] byte_sel = 4'b1 << lsu_addr_i[1:0];
    // 从设备选择
    wire is_clint = (lsu_addr_i >= 32'h0200_0000) && (lsu_addr_i < 32'h0201_0000);
    // DEBUG
`ifdef YSYXSOC
    wire is_mmio = ((lsu_addr_i >= 32'h0200_0000) && (lsu_addr_i < 32'h0201_0000)) ||
                   ((lsu_addr_i >= 32'h1000_0000) && (lsu_addr_i < 32'h1000_1000));
    wire is_lsuop = lsu_wen_i | lsu_ren_i;
    always @(*) begin
        if (is_mmio && is_lsuop) begin
            find_diff_skip();
        end
    end
`endif
    // dcache握手信号
    reg        req_valid_r ;
    reg        req_ren_r   ;
    reg        req_wen_r   ;
    reg [3:0]  req_mask_r  ;
    reg [2:0]  req_size_r  ;
    reg [31:0] req_wdata_r ;
    reg [31:0] req_addr_r  ;
    reg [3:0]  lsu_strb_r  ;
    reg [31:0] lsu_wdata_r ;
    reg [2:0]  lsu_size_r  ;
    reg [31:0] lsu_rdata_r ;

    always @(posedge clk) begin
        if (reset) begin
            req_valid_r <= 0;
            req_ren_r   <= 0;
            req_wen_r   <= 0;
            req_mask_r  <= 0;
            req_size_r  <= 0;
            req_wdata_r <= 0;
            req_addr_r  <= 0;
        end else begin
            if(req_ready_i) begin
                req_valid_r <= 1'b0;
                req_ren_r   <= 0;
                req_wen_r   <= 0;
                req_mask_r  <= 0;
                req_size_r  <= 0;
                req_wdata_r <= 0;
                req_addr_r  <= 0;
            end else if(lsu_en_i & (lsu_ren_i | lsu_wen_i) & (!is_clint)) begin
                req_valid_r <= 1'b1;
                req_ren_r   <= lsu_ren_i;
                req_wen_r   <= lsu_wen_i;
                req_mask_r  <= lsu_strb_r;
                req_size_r  <= lsu_size_r;
                req_wdata_r <= lsu_wdata_r;
                req_addr_r  <= lsu_addr_i;
            end
        end
    end
    assign req_addr_o = lsu_addr_i | req_addr_r;
    assign req_valid_o = is_clint ? 0 : req_valid_r;
    assign req_ren_o = lsu_ren_i | req_ren_r;
    assign req_wen_o = lsu_wen_i | req_wen_r;
    assign req_mask_o = lsu_strb_r | req_mask_r;
    assign req_size_o = lsu_size_r | req_size_r;
    assign req_use_o = 1'b1;
    assign req_wdata_o = lsu_wdata_r | req_wdata_r;
    // clint握手信号
    assign clint_addr_o = lsu_addr_i;
    assign clint_valid_o = lsu_ren_i;
    // 读写数据处理
    always @(*) begin
        // 默认值
        lsu_strb_r = 0;
        lsu_wdata_r = 0;
        lsu_size_r = 0; 
        lsu_rdata_r = 0;
        
        // 统一处理读写
        case (lsu_mask_i)
            4'h1: begin // Byte操作
                lsu_strb_r = byte_sel;
                lsu_wdata_r = {24'd0, {store_data_i[7:0]}} << (8 * lsu_addr_i[1:0]);
                lsu_size_r = 3'b000;
                lsu_rdata_r = lsu_signed_i ?
                    {{24{req_rdata_i[8*lsu_addr_i[1:0] + 7]}}, req_rdata_i[8*lsu_addr_i[1:0] +: 8]} :
                    {24'd0, req_rdata_i[8*lsu_addr_i[1:0] +: 8]};
            end
            4'h3: begin // Halfword操作
                lsu_strb_r = byte_sel | (byte_sel << 1);
                lsu_wdata_r = {16'd0, store_data_i[15:0]} << (8 * lsu_addr_i[1:0]);
                lsu_size_r = 3'b001;
                lsu_rdata_r = lsu_signed_i ?
                    {{16{req_rdata_i[16*lsu_addr_i[1] + 15]}}, req_rdata_i[16*lsu_addr_i[1] +: 16]} :
                    {16'd0, req_rdata_i[16*lsu_addr_i[1] +: 16]};
            end
            4'hF: begin // Word操作
                lsu_strb_r = 4'b1111;
                lsu_wdata_r = store_data_i;
                lsu_size_r = 3'b010;
                lsu_rdata_r = req_rdata_i;
            end
            default;
        endcase
    end
    assign busy_mem_o = (lsu_ren_i | lsu_wen_i) & ~(is_clint ? clint_ready_i : req_ready_i); 
    assign load_data_o = is_clint ? clint_rdata_i : lsu_rdata_r;
 endmodule
