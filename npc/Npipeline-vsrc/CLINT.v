`include "/home/furina/ysyx-workbench/npc/Npipeline-vsrc/defines/defines.v"

module CLINT #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter MAX_DELAY  = 4,
    parameter MIN_DELAY  = 1
)(
    input  wire                   clk,
    input  wire                   reset,

    // AXI4-Lite 读地址通道
    input  wire [ADDR_WIDTH-1:0]  araddr,
    input  wire                   arvalid,
    output reg                    arready,

    // AXI4-Lite 读数据通道
    output reg   [DATA_WIDTH-1:0] rdata,
    output reg                    rvalid,
    input  wire                   rready,
    output reg   [1:0]            rresp, // 读响应信号

    // AXI4-Lite 写地址通道
    input  wire [ADDR_WIDTH-1:0]  awaddr,
    input  wire                   awvalid,
    output reg                    awready,

    // AXI4-Lite 写数据通道
    input  wire [DATA_WIDTH-1:0]  wdata,
    input  wire [3:0]             wstrb,
    input  wire                   wvalid,
    output reg                    wready,

    // 写响应通道
    output reg   [1:0]            bresp, // 写响应信号
    output reg                    bvalid,
    input  wire                   bready
);
    // import "DPI-C" function void ebreak(input int station, input int inst);

    // 状态机定义
    typedef enum {IDLE, READ_ADDR, READ_DATA, WRITE_ADDR, WRITE_DATA, WRITE_RESP} state_t;
    state_t clint_state, next_clint_state;

    // 寄存器定义
    reg [31:0] LFSR; // 模拟读写延迟计数器
    reg [ADDR_WIDTH-1:0] araddr_reg, awaddr_reg;
    reg [DATA_WIDTH-1:0] wdata_reg, rdata_reg;
    reg [3:0] wstrb_reg;
    reg addr_valid;

    // 检查地址是否有效
    wire addr_valid = (araddr >= 32'ha000_2000 && araddr <= 32'ha000_2007) ||
                      (awaddr >= 32'ha000_2000 && awaddr <= 32'ha000_2007);
    reg  [63:0] mtime;//时间寄存器
    wire [31:0] mtime_low = mtime[31:0];
    wire [31:0] mtime_high = mtime[63:32];

    //时间更新逻辑
    always @(posedge clk) begin
        if(reset) begin
            mtime <= 64'h0;
        end
        else begin
            mtime <= mtime + 64'h1;
        end
    end

    // 状态机：状态转换和信号处理
    always @(posedge clk) begin
        if (reset) begin
            clint_state <= IDLE;
            arready <= 1'b0;
            rvalid <= 1'b0;
            wready <= 1'b0;
            awready <= 1'b0;
            bvalid <= 1'b0;
            rdata <= 32'h0;
            rresp <= `OKAY;
            bresp <= `OKAY;
            LFSR <= MIN_DELAY;
            araddr_reg <= 32'h0;
            awaddr_reg <= 32'h0;
            wdata_reg <= 32'h0;
            rdata_reg <= 32'h0;
            wstrb_reg <= 4'b0;
        end else begin
            clint_state <= next_clint_state;
            case (clint_state)
                IDLE: begin
                    arready <= 1'b1; // 准备接受读地址
                    awready <= 1'b1; // 准备接受写地址
                    rvalid <= 1'b0;
                    bvalid <= 1'b0;
                    LFSR <= $urandom_range(1, 10); // 随机生成1~10的延迟
                    if (arvalid && arready) begin // 读地址握手
                        araddr_reg <= araddr;
                        arready <= 1'b0;
                        next_clint_state <= READ_ADDR;
                    end else if (awvalid && awready) begin // 写地址握手
                        awaddr_reg <= awaddr;
                        wdata_reg <= wdata;
                        wstrb_reg <= wstrb;
                        awready <= 1'b0;
                        next_clint_state <= WRITE_ADDR;
                    end
                end
                READ_ADDR: begin
                    if (LFSR > 0) begin
                        LFSR <= LFSR - 1;
                        next_clint_state <= READ_ADDR;
                    end 
                    else begin
                        if (addr_valid) begin
                            case(araddr_reg)
                                32'ha000_2000: rdata_reg <= mtime_low;//低32位
                                32'ha000_2004: rdata_reg <= mtime_high;//高32位
                                default: begin
                                    rdata <= 32'h0;
                                    rresp <= `SLVERR;
                                    // ebreak(`ABORT, 32'hdead_beef);
                                    $display("\033[31mCLINT: Invalid read address %h\033[0m", araddr_reg);
                                end
                            endcase
                            rresp <= `OKAY;
                        end 
                        else begin
                            rdata_reg <= 32'h0;
                            rresp <= `SLVERR; // 无效地址返回SLVERR
                        end
                        next_clint_state <= READ_DATA;
                    end
                end
                READ_DATA: begin
                    if (rready) begin
                        rdata <= rdata_reg;
                        rvalid <= 1'b1;
                        araddr_reg <= 32'h0; // 清空读地址寄存器
                        next_clint_state <= IDLE;
                    end else begin
                        next_clint_state <= READ_DATA;
                    end
                end
                WRITE_ADDR: begin
                    if (LFSR > 0) begin
                        LFSR <= LFSR - 1;
                        next_clint_state <= WRITE_ADDR;
                    end 
                    else begin
                        // wready <= 1'b1;
                        next_clint_state <= WRITE_DATA;
                    end
                end
                WRITE_DATA: begin
                    wready <= 1'b1;
                    if (wvalid && wready) begin // 写数据握手
                        if (addr_valid) begin
                            bresp <= `OKAY;
                            // wready <= 1'b0;
                        end 
                        else begin
                            bresp <= `SLVERR; // 无效地址返回SLVERR
                        end
                        wready <= 1'b0;
                        // bvalid <= 1'b1;
                        next_clint_state <= WRITE_RESP;
                        // ebreak(`ABORT, 32'hdead_beef);
                        // $display("\033[31mCLINT: Write operation not supported at address %h\033[0m", awaddr_reg);
                    end 
                    // else begin
                    //     next_clint_state <= WRITE_DATA;
                    // end
                end
                WRITE_RESP: begin
                    bvalid <= 1'b1;
                    wready <= 1'b0;
                    if (bready && bvalid) begin
                        bvalid <= 1'b0;
                        awready <= 1'b1;
                        next_clint_state <= IDLE;
                    end 
                    // awready <= 1'b1;
                    // bvalid <= 1'b0;
                    // next_clint_state <= IDLE;
                end
                default: begin
                    next_clint_state <= IDLE;
                end
            endcase
        end
    end

    // 协议断言
    always @(posedge clk) begin
        assert(!(arvalid && arready && clint_state != IDLE)) else $error("[clint] AR channel handshake in wrong state");
        assert(!(rvalid && rready && clint_state != READ_DATA)) else $error("[clint] R channel handshake in wrong state");
        assert(!(awvalid && awready && clint_state != IDLE)) else $error("[clint] AW channel handshake in wrong state");
        assert(!(wvalid && wready && clint_state != WRITE_DATA)) else $error("[clint] W channel handshake in wrong state");
        assert(!(bvalid && bready && clint_state != WRITE_RESP)) else $error("[clint] B channel handshake in wrong state");
    end

endmodule