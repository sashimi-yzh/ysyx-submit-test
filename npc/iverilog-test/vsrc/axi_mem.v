// ============================================================================
// 模块名称 : axi_mem
// 功能描述 : 用于 32 位 RISC-V 处理器的 AXI 接口仿真存储器
// 存储容量 : 256 MB (地址范围 0x80000000 - 0x8FFFFFFF)
// 写通道   : 单拍传输
// 读通道   : 支持 FIXED 和 INCR 突发
// ============================================================================
`timescale 1ns/1ps

module axi_mem #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter STRB_WIDTH = 4,
    parameter ID_WIDTH    = 4,
    parameter BASE_ADDR   = 32'h8000_0000,
    parameter HIGH_ADDR   = 32'h8FFF_FFFF
) (
    input  wire                        aclk,
    input  wire                        aresetn,

    // 写地址通道
    input  wire [ID_WIDTH-1:0]         awid,
    input  wire [ADDR_WIDTH-1:0]       awaddr,
    input  wire [7:0]                  awlen,
    input  wire [2:0]                  awsize,
    input  wire [1:0]                  awburst,
    input  wire                        awvalid,
    output wire                        awready,

    // 写数据通道
    input  wire [DATA_WIDTH-1:0]       wdata,
    input  wire [STRB_WIDTH-1:0]       wstrb,
    input  wire                        wlast,
    input  wire                        wvalid,
    output wire                        wready,

    // 写响应通道
    output wire [ID_WIDTH-1:0]         bid,
    output wire [1:0]                  bresp,
    output wire                        bvalid,
    input  wire                        bready,

    // 读地址通道
    input  wire [ID_WIDTH-1:0]         arid,
    input  wire [ADDR_WIDTH-1:0]       araddr,
    input  wire [7:0]                  arlen,
    input  wire [2:0]                  arsize,
    input  wire [1:0]                  arburst,
    input  wire                        arvalid,
    output wire                        arready,

    // 读数据通道
    output wire [ID_WIDTH-1:0]         rid,
    output wire [DATA_WIDTH-1:0]       rdata,
    output wire [1:0]                  rresp,
    output wire                        rlast,
    output wire                        rvalid,
    input  wire                        rready
);
    `ifdef HEX_FILE
        parameter HEX_FILE_NAME = `HEX_FILE;
    `else
        parameter HEX_FILE_NAME = "prog/microbench-riscv32e-npc.bin";
    `endif
    // ----- 本地参数 -----
    localparam MEM_SIZE = (HIGH_ADDR - BASE_ADDR + 1) >> 2;  // 64M 字

    // ----- 存储阵列 (256 MB) -----
    reg [DATA_WIDTH-1:0] mem [0:MEM_SIZE-1];
    reg [DATA_WIDTH-1:0] mem_rd [0:MEM_SIZE-1];

    // ===== 仿真初始化：使用 $readmemh() 加载十六进制文件 =====
    integer init_idx;
    integer i, j, mem_file;
    initial begin
        // 使用$readmemh直接加载hex文件到mem数组
        $display("[INFO] Loading memory from %s", HEX_FILE_NAME);
        
        // 尝试加载文件
        $readmemh(HEX_FILE_NAME, mem);
        
        // 检查是否成功加载（通过检查第一个字是否为x或z状态）
        // 如果文件不存在或格式错误，$readmemh会报错并停止仿真
        // 也可以添加额外的验证
        
        $display("[INFO] Memory init done, file: %s", HEX_FILE_NAME);
        $display("[INFO] First word at 0x80000000: 0x%08h", mem[0]);
end

    // ========================================================================
    // 写通道
    // ========================================================================
    reg                awready_r, wready_r;
    reg                bvalid_r;
    reg  [1:0]         bresp_r;
    reg  [ID_WIDTH-1:0] bid_r;
    reg  [ADDR_WIDTH-1:0] awaddr_r;
    reg  [DATA_WIDTH-1:0] wdata_r;
    reg  [STRB_WIDTH-1:0] wstrb_r;

    wire               write_hit;
    wire [ADDR_WIDTH-1:0] write_word_addr;

    assign write_word_addr = ((awaddr_r >= BASE_ADDR) && (awaddr_r <= HIGH_ADDR)) ?
                             (awaddr_r - BASE_ADDR) >> 2 : 0;
    assign write_hit = (awaddr_r >= BASE_ADDR) && (awaddr_r <= HIGH_ADDR);

    always @(posedge aclk) begin
        if (!aresetn) begin
            awready_r <= 1'b1;
            wready_r  <= 1'b1;
            bvalid_r  <= 1'b0;
            bid_r     <= {ID_WIDTH{1'b0}};
            bresp_r   <= 2'b00;
        end else begin
            // 接收写地址，锁存 awid
            if (awready_r && awvalid) begin
                awready_r <= 1'b0;
                awaddr_r  <= awaddr;
                bid_r     <= awid;  // 锁存 ID
            end

            // 接收写数据
            if (wready_r && wvalid && wlast) begin
                wready_r  <= 1'b0;
                wdata_r   <= wdata;
                wstrb_r   <= wstrb;
            end

            // 执行写入
            if (!awready_r && !wready_r && !bvalid_r) begin
                if (write_hit) begin
                    mem[write_word_addr] <= (mem[write_word_addr] & ~{ {8{wstrb_r[3]}}, {8{wstrb_r[2]}}, {8{wstrb_r[1]}}, {8{wstrb_r[0]}} })
                                            | (wdata_r & { {8{wstrb_r[3]}}, {8{wstrb_r[2]}}, {8{wstrb_r[1]}}, {8{wstrb_r[0]}} });
                    bresp_r <= 2'b00;
                end else begin
                    bresp_r <= 2'b11;
                end
                bvalid_r <= 1'b1;
            end

            // 写响应握手
            if (bvalid_r && bready) begin
                bvalid_r  <= 1'b0;
                awready_r <= 1'b1;
                wready_r  <= 1'b1;
            end
        end
    end

    assign awready = awready_r;
    assign wready  = wready_r;
    assign bvalid  = bvalid_r;
    assign bresp   = bresp_r;
    assign bid     = bid_r;

    // ========================================================================
    // 读通道（支持 FIXED 和 INCR）
    // ========================================================================
    localparam S_IDLE       = 2'd0;
    localparam S_READ_BURST = 2'd1;

    reg [1:0]         rd_state, rd_next;
    reg [ID_WIDTH-1:0] rid_r;
    reg [7:0]         burst_len;
    reg [7:0]         burst_cnt;
    reg [31:0]        rd_addr_word;
    reg [31:0]        rd_start_addr;  // FIXED 时需要记住起始地址
    reg               rd_is_fixed;    // 是否为 FIXED 突发
    reg [1:0]         rresp_r;

    wire              ar_hit;
    wire [31:0]       ar_word_addr;

    assign ar_word_addr = ((araddr >= BASE_ADDR) && (araddr <= HIGH_ADDR)) ?
                          (araddr - BASE_ADDR) >> 2 : 0;
    assign ar_hit = (araddr >= BASE_ADDR) && (araddr <= HIGH_ADDR);

    assign arready = (rd_state == S_IDLE);
    assign rdata   = mem[rd_addr_word];
    assign rresp   = rresp_r;
    assign rid     = rid_r;
    assign rlast   = (rd_state == S_READ_BURST) && (burst_cnt == burst_len - 1);
    assign rvalid  = (rd_state == S_READ_BURST);

    always @(posedge aclk) begin
        if (!aresetn) begin
            rd_state <= S_IDLE;
        end else begin
            rd_state <= rd_next;
        end
    end

    always @(*) begin
        rd_next = rd_state;
        case (rd_state)
            S_IDLE: begin
                if (arvalid && arready) begin
                    // 支持 FIXED(00) 和 INCR(01)
                    if (arburst == 2'b00 || arburst == 2'b01)
                        rd_next = S_READ_BURST;
                    else
                        rd_next = S_IDLE;
                end
            end

            S_READ_BURST: begin
                if (rvalid && rready && (burst_cnt == burst_len - 1))
                    rd_next = S_IDLE;
                else
                    rd_next = S_READ_BURST;
            end

            default: rd_next = S_IDLE;
        endcase
    end

    always @(posedge aclk) begin
        if (!aresetn) begin
            burst_len     <= 8'd0;
            burst_cnt     <= 8'd0;
            rd_addr_word  <= 32'd0;
            rd_start_addr <= 32'd0;
            rd_is_fixed   <= 1'b0;
            rresp_r       <= 2'b00;
            rid_r         <= {ID_WIDTH{1'b0}};
        end else begin
            case (rd_state)
                S_IDLE: begin
                    if (arvalid && arready && (arburst == 2'b00 || arburst == 2'b01)) begin
                        burst_len     <= arlen + 8'd1;
                        burst_cnt     <= 8'd0;
                        rd_addr_word  <= ar_word_addr;
                        rd_start_addr <= ar_word_addr;
                        rd_is_fixed   <= (arburst == 2'b00);
                        rresp_r       <= ar_hit ? 2'b00 : 2'b11;
                        rid_r         <= arid;  // 锁存读 ID
                    end
                end

                S_READ_BURST: begin
                    if (rvalid && rready) begin
                        if (burst_cnt < burst_len - 1) begin
                            // FIXED: 地址不变; INCR: 地址递增
                            if (!rd_is_fixed)
                                rd_addr_word <= rd_addr_word + 32'd1;
                            burst_cnt    <= burst_cnt + 8'd1;
                        end
                    end
                end
            endcase
        end
    end

endmodule