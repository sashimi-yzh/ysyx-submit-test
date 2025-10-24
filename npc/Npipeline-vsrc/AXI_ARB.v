module AXI_ARB (
    input wire clk,           // 时钟信号
    input wire reset,         // 复位信号

    // IFU主设备（只读）
    input wire [31:0] ifu_araddr,   // IFU读地址
    input wire        ifu_arvalid,  // IFU读地址有效
    output reg        ifu_arready,  // IFU读地址ready
    output reg [31:0] ifu_rdata,    // IFU读数据
    output reg [1:0]  ifu_rresp,    // IFU读响应
    output reg        ifu_rvalid,   // IFU读数据有效
    input wire        ifu_rready,   // IFU读数据ready

    // LSU主设备（读写）
    input wire [31:0] lsu_araddr,   // LSU读地址
    input wire        lsu_arvalid,  // LSU读地址有效
    output reg        lsu_arready,  // LSU读地址ready
    output reg [31:0] lsu_rdata,    // LSU读数据
    output reg [1:0]  lsu_rresp,    // LSU读响应
    output reg        lsu_rvalid,   // LSU读数据有效
    input wire        lsu_rready,   // LSU读数据ready

    input wire [31:0] lsu_awaddr,   // LSU写地址
    input wire        lsu_awvalid,  // LSU写地址有效
    output reg        lsu_awready,  // LSU写地址ready
    input wire [31:0] lsu_wdata,    // LSU写数据
    input wire [3:0]  lsu_wstrb,    // LSU写选通
    input wire        lsu_wvalid,   // LSU写数据有效
    output reg        lsu_wready,   // LSU写数据ready
    output reg [1:0]  lsu_bresp,    // LSU写响应
    output reg        lsu_bvalid,   // LSU写响应有效
    input wire        lsu_bready,   // LSU写响应ready

    // UART从设备（读写）
    output reg [31:0] uart_araddr,   // UART读地址
    output reg        uart_arvalid,  // UART读地址有效
    input wire        uart_arready,  // UART读地址ready
    input wire [31:0] uart_rdata,    // UART读数据
    input wire [1:0]  uart_rresp,    // UART读响应
    input wire        uart_rvalid,   // UART读数据有效
    output reg        uart_rready,   // UART读数据ready
    output reg [31:0] uart_awaddr,   // UART写地址
    output reg        uart_awvalid,  // UART写地址有效
    input wire        uart_awready,  // UART写地址ready
    output reg [31:0] uart_wdata,    // UART写数据
    output reg [3:0]  uart_wstrb,    // UART写选通
    output reg        uart_wvalid,   // UART写数据有效
    input wire        uart_wready,   // UART写数据ready
    input wire [1:0]  uart_bresp,    // UART写响应
    input wire        uart_bvalid,   // UART写响应有效
    output reg        uart_bready,   // UART写响应ready

    // SRAM从设备（读写）
    output reg [31:0] sram_araddr,   // SRAM读地址
    output reg        sram_arvalid,  // SRAM读地址有效
    input wire        sram_arready,  // SRAM读地址ready
    input wire [31:0] sram_rdata,    // SRAM读数据
    input wire [1:0]  sram_rresp,    // SRAM读响应
    input wire        sram_rvalid,   // SRAM读数据有效
    output reg        sram_rready,   // SRAM读数据ready
    output reg [31:0] sram_awaddr,   // SRAM写地址
    output reg        sram_awvalid,  // SRAM写地址有效
    input wire        sram_awready,  // SRAM写地址ready
    output reg [31:0] sram_wdata,    // SRAM写数据
    output reg [3:0]  sram_wstrb,    // SRAM写选通
    output reg        sram_wvalid,   // SRAM写数据有效
    input wire        sram_wready,   // SRAM写数据ready
    input wire [1:0]  sram_bresp,    // SRAM写响应
    input wire        sram_bvalid,   // SRAM写响应有效
    output reg        sram_bready,   // SRAM写响应ready

    // CLINT从设备（只读） - 新增
    output reg [31:0] clint_araddr,   // CLINT读地址
    output reg        clint_arvalid,  // CLINT读地址有效
    input wire        clint_arready,  // CLINT读地址ready
    input wire [31:0] clint_rdata,    // CLINT读数据
    input wire [1:0]  clint_rresp,    // CLINT读响应
    input wire        clint_rvalid,   // CLINT读数据有效
    output reg        clint_rready,   // CLINT读数据ready
    output reg [31:0] clint_awaddr,   // CLINT写地址
    output reg        clint_awvalid,  // CLINT写地址有效
    input wire        clint_awready,  // CLINT写地址ready
    output reg [31:0] clint_wdata,    // CLINT写数据
    output reg [3:0]  clint_wstrb,    // CLINT写选通
    output reg        clint_wvalid,   // CLINT写数据有效
    input wire        clint_wready,   // CLINT写数据ready
    input wire [1:0]  clint_bresp,    // CLINT写响应
    input wire        clint_bvalid,   // CLINT写响应有效
    output reg        clint_bready    // CLINT写响应ready
);

    // 状态机定义
    localparam NONE      = 3'd0;
    localparam IFU       = 3'd1;
    localparam LSU_READ  = 3'd2;
    localparam LSU_WRITE = 3'd3;
    localparam ERROR     = 3'd4;

    localparam SRAM  = 2'd1;
    localparam UART  = 2'd2;
    localparam CLINT = 2'd3;
    localparam ERR   = 2'd0;

    reg [2:0] current_master, next_master;

    parameter OKAY = 2'b00;
    parameter SLVERR = 2'b10;
    parameter DECERR = 2'b11;

    // 地址解码函数
    function [1:0] decode_address(input [31:0] addr);
        if (addr >= 32'h8000_0000 && addr <= 32'h87ff_ffff) begin
            decode_address = SRAM;
        end 
        else if (addr >= 32'ha000_0000 && addr <= 32'ha000_0007) begin
            decode_address = UART;
        end 
        else if (addr >= 32'ha000_2000 && addr <= 32'ha000_2007) begin
            decode_address = CLINT;
        end
        else begin
            decode_address = ERR;
        end
    endfunction

    // 状态转换
    always @(posedge clk) begin
        if (reset) begin
            current_master <= NONE;
        end else begin
            current_master <= next_master;
        end
    end

    // 下一状态逻辑
    always @(*) begin
        case (current_master)
            NONE: begin
                if (lsu_awvalid) begin
                    case (decode_address(lsu_awaddr))
                        SRAM:  next_master = LSU_WRITE;
                        UART:  next_master = LSU_WRITE;
                        CLINT: next_master = LSU_WRITE; 
                        default: next_master = ERROR;
                    endcase
                end else if (lsu_arvalid) begin
                    case (decode_address(lsu_araddr))
                        SRAM:  next_master = LSU_READ;
                        UART:  next_master = LSU_READ;
                        CLINT: next_master = LSU_READ; 
                        default: next_master = ERROR;
                    endcase
                end else if (ifu_arvalid) begin
                    case (decode_address(ifu_araddr))
                        SRAM:  next_master = IFU;
                        UART:  next_master = IFU;
                        CLINT: next_master = IFU; 
                        default: next_master = ERROR;
                    endcase
                end else begin
                    next_master = NONE;
                end
            end
            IFU: begin
                if ((sram_rvalid && sram_rready) || (uart_rvalid && uart_rready) || (clint_rvalid && clint_rready)) begin 
                    next_master = NONE;
                end else begin
                    next_master = IFU;
                end
            end
            LSU_READ: begin
                if ((sram_rvalid && sram_rready) || (uart_rvalid && uart_rready) || (clint_rvalid && clint_rready)) begin
                    next_master = NONE;
                end else begin
                    next_master = LSU_READ;
                end
            end
            LSU_WRITE: begin
                if ((sram_bvalid && sram_bready) || (uart_bvalid && uart_bready) || (clint_bvalid && clint_bready)) begin 
                    next_master = NONE;
                end else begin
                    next_master = LSU_WRITE;
                end
            end
            ERROR: begin
                if ((ifu_rvalid && ifu_rready) || (lsu_rvalid && lsu_rready) || (lsu_bvalid && lsu_bready)) begin
                    next_master = NONE;
                end else begin
                    next_master = ERROR;
                end
            end
            default: next_master = NONE;
        endcase
    end

    // 读地址通道处理
    always @(*) begin
        sram_araddr   = 32'h0;
        sram_arvalid  = 1'b0;
        uart_araddr   = 32'h0;
        uart_arvalid  = 1'b0;
        clint_araddr  = 32'h0; 
        clint_arvalid = 1'b0;  
        ifu_arready   = 1'b0;
        lsu_arready   = 1'b0;

        case (current_master)
            IFU: begin
                case (decode_address(ifu_araddr))
                    SRAM: begin
                        sram_araddr   = ifu_araddr;
                        sram_arvalid  = ifu_arvalid;
                        ifu_arready   = sram_arready;
                        lsu_arready   = 1'b0;
                        uart_araddr   = 32'h0;
                        uart_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                    end
                    UART: begin
                        uart_araddr   = ifu_araddr;
                        uart_arvalid  = ifu_arvalid;
                        ifu_arready   = uart_arready;
                        lsu_arready   = 1'b0;
                        sram_araddr   = 32'h0;
                        sram_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                    end
                    CLINT: begin 
                        clint_araddr  = ifu_araddr;
                        clint_arvalid = ifu_arvalid;
                        ifu_arready   = clint_arready;
                        lsu_arready   = 1'b0;
                        sram_araddr   = 32'h0;
                        sram_arvalid  = 1'b0;
                        uart_araddr   = 32'h0;
                        uart_arvalid  = 1'b0;
                    end
                    ERR: begin
                        sram_araddr   = 32'h0;
                        sram_arvalid  = 1'b0;
                        uart_araddr   = 32'h0;
                        uart_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                        ifu_arready   = 1'b1; // 接受地址以返回错误
                        lsu_arready   = 1'b0;
                        $display("\033[31m[ARB][IFU][AR] 地址解码错误！地址: %h\033[0m", ifu_araddr);
                    end
                    default: begin
                        sram_araddr   = 32'h0;
                        sram_arvalid  = 1'b0;
                        uart_araddr   = 32'h0;
                        uart_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                        ifu_arready   = 1'b0;
                        lsu_arready   = 1'b0;
                    end 
                endcase
            end
            LSU_READ: begin
                case (decode_address(lsu_araddr))
                    SRAM: begin
                        sram_araddr   = lsu_araddr;
                        sram_arvalid  = lsu_arvalid;
                        lsu_arready   = sram_arready;
                        ifu_arready   = 1'b0;
                        uart_araddr   = 32'h0;
                        uart_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                    end
                    UART: begin
                        uart_araddr   = lsu_araddr;
                        uart_arvalid  = lsu_arvalid;
                        lsu_arready   = uart_arready;
                        ifu_arready   = 1'b0;
                        sram_araddr   = 32'h0;
                        sram_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                    end
                    CLINT: begin 
                        clint_araddr  = lsu_araddr;
                        clint_arvalid = lsu_arvalid;
                        lsu_arready   = clint_arready;
                        ifu_arready   = 1'b0;
                        sram_araddr   = 32'h0;
                        sram_arvalid  = 1'b0;
                        uart_araddr   = 32'h0;
                        uart_arvalid  = 1'b0;
                    end
                    ERR: begin
                        sram_araddr   = 32'h0;
                        sram_arvalid  = 1'b0;
                        uart_araddr   = 32'h0;
                        uart_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                        lsu_arready   = 1'b1; // 接受地址以返回错误
                        ifu_arready   = 1'b0;
                        $display("\033[31m[ARB][LSU][AR] 地址解码错误！地址: %h\033[0m", lsu_araddr);
                    end
                    default: begin
                        sram_araddr   = 32'h0;
                        sram_arvalid  = 1'b0;
                        uart_araddr   = 32'h0;
                        uart_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                        ifu_arready   = 1'b0;
                        lsu_arready   = 1'b0;
                    end
                endcase
            end
            ERROR: begin
                ifu_arready = ifu_arvalid;
                lsu_arready = lsu_arvalid;
                sram_araddr   = 32'h0;
                sram_arvalid  = 1'b0;
                uart_araddr   = 32'h0;
                uart_arvalid  = 1'b0;
                clint_araddr  = 32'h0;
                clint_arvalid = 1'b0;
            end
            default: begin
                sram_araddr   = 32'h0;
                sram_arvalid  = 1'b0;
                uart_araddr   = 32'h0;
                uart_arvalid  = 1'b0;
                clint_araddr  = 32'h0;
                clint_arvalid = 1'b0;
                ifu_arready   = 1'b0;
                lsu_arready   = 1'b0;
            end
        endcase
    end

    // 写地址通道处理
    always @(*) begin
        sram_awaddr   = 32'h0;
        sram_awvalid  = 1'b0;
        uart_awaddr   = 32'h0;
        uart_awvalid  = 1'b0;
        clint_awaddr  = 32'h0; 
        clint_awvalid = 1'b0;  
        lsu_awready   = 1'b0;

        case (current_master)
            LSU_WRITE: begin
                case (decode_address(lsu_awaddr))
                    SRAM: begin
                        sram_awaddr   = lsu_awaddr;
                        sram_awvalid  = lsu_awvalid;
                        lsu_awready   = sram_awready;
                        uart_awaddr   = 32'h0;
                        uart_awvalid  = 1'b0;
                        clint_awaddr  = 32'h0;
                        clint_awvalid = 1'b0;
                    end
                    UART: begin
                        uart_awaddr   = lsu_awaddr;
                        uart_awvalid  = lsu_awvalid;
                        lsu_awready   = uart_awready;
                        sram_awaddr   = 32'h0;
                        sram_awvalid  = 1'b0;
                        clint_awaddr  = 32'h0;
                        clint_awvalid = 1'b0;
                    end
                    CLINT: begin 
                        clint_awaddr  = lsu_awaddr;
                        clint_awvalid = lsu_awvalid;
                        lsu_awready   = clint_awready;
                        sram_awaddr   = 32'h0;
                        sram_awvalid  = 1'b0;
                        uart_awaddr   = 32'h0;
                        uart_awvalid  = 1'b0;
                    end
                    ERR: begin
                        sram_awaddr   = 32'h0;
                        sram_awvalid  = 1'b0;
                        uart_awaddr   = 32'h0;
                        uart_awvalid  = 1'b0;
                        clint_awaddr  = 32'h0;
                        clint_awvalid = 1'b0;
                        lsu_awready   = 1'b1; // 接受地址以返回错误
                        $display("\033[31m[ARB][LSU][AW] 地址解码错误！地址: %h\033[0m", lsu_awaddr);
                    end
                    default: begin
                        sram_awaddr   = 32'h0;
                        sram_awvalid  = 1'b0;
                        uart_awaddr   = 32'h0;
                        uart_awvalid  = 1'b0;
                        clint_awaddr  = 32'h0;
                        clint_awvalid = 1'b0;
                        lsu_awready   = 1'b0;
                    end
                endcase
            end
            ERROR: begin
                lsu_awready = lsu_awvalid;
                sram_awaddr   = 32'h0;
                sram_awvalid  = 1'b0;
                uart_awaddr   = 32'h0;
                uart_awvalid  = 1'b0;
                clint_awaddr  = 32'h0;
                clint_awvalid = 1'b0;
            end
            default: begin
                sram_awaddr   = 32'h0;
                sram_awvalid  = 1'b0;
                uart_awaddr   = 32'h0;
                uart_awvalid  = 1'b0;
                clint_awaddr  = 32'h0;
                clint_awvalid = 1'b0;
                lsu_awready   = 1'b0;
            end
        endcase
    end

    // 写数据通道处理
    always @(*) begin
        sram_wdata   = 32'h0;
        sram_wstrb   = 4'b0;
        sram_wvalid  = 1'b0;
        uart_wdata   = 32'h0;
        uart_wstrb   = 4'b0;
        uart_wvalid  = 1'b0;
        clint_wdata  = 32'h0; 
        clint_wstrb  = 4'b0;  
        clint_wvalid = 1'b0;   
        lsu_wready   = 1'b0;

        case (current_master)
            LSU_WRITE: begin
                case (decode_address(lsu_awaddr))
                    SRAM: begin
                        sram_wdata   = lsu_wdata;
                        sram_wstrb   = lsu_wstrb;
                        sram_wvalid  = lsu_wvalid;
                        lsu_wready   = sram_wready;
                        uart_wdata   = 32'h0;
                        uart_wstrb   = 4'b0;
                        uart_wvalid  = 1'b0;
                        clint_wdata  = 32'h0;
                        clint_wstrb  = 4'b0;
                        clint_wvalid = 1'b0;
                    end
                    UART: begin
                        uart_wdata   = lsu_wdata;
                        uart_wstrb   = lsu_wstrb;
                        uart_wvalid  = lsu_wvalid;
                        lsu_wready   = uart_wready;
                        sram_wdata   = 32'h0;
                        sram_wstrb   = 4'b0;
                        sram_wvalid  = 1'b0;
                        clint_wdata  = 32'h0;
                        clint_wstrb  = 4'b0;
                        clint_wvalid = 1'b0;
                    end
                    CLINT: begin 
                        clint_wdata  = lsu_wdata;
                        clint_wstrb  = lsu_wstrb;
                        clint_wvalid = lsu_wvalid;
                        lsu_wready   = clint_wready;
                        sram_wdata   = 32'h0;
                        sram_wstrb   = 4'b0;
                        sram_wvalid  = 1'b0;
                        uart_wdata   = 32'h0;
                        uart_wstrb   = 4'b0;
                        uart_wvalid  = 1'b0;
                    end
                    ERR: begin
                        sram_wdata   = 32'h0;
                        sram_wstrb   = 4'b0;
                        sram_wvalid  = 1'b0;
                        uart_wdata   = 32'h0;
                        uart_wstrb   = 4'b0;
                        uart_wvalid  = 1'b0;
                        clint_wdata  = 32'h0;
                        clint_wstrb  = 4'b0;
                        clint_wvalid = 1'b0;
                        lsu_wready   = lsu_wvalid; // 接受数据以返回错误
                    end
                    default: begin
                        sram_wdata   = 32'h0;
                        sram_wstrb   = 4'b0;
                        sram_wvalid  = 1'b0;
                        uart_wdata   = 32'h0;
                        uart_wstrb   = 4'b0;
                        uart_wvalid  = 1'b0;
                        clint_wdata  = 32'h0;
                        clint_wstrb  = 4'b0;
                        clint_wvalid = 1'b0;
                        lsu_wready   = 1'b0;
                    end
                endcase
            end
            default: begin
                sram_wdata   = 32'h0;
                sram_wstrb   = 4'b0;
                sram_wvalid  = 1'b0;
                uart_wdata   = 32'h0;
                uart_wstrb   = 4'b0;
                uart_wvalid  = 1'b0;
                clint_wdata  = 32'h0;
                clint_wstrb  = 4'b0;
                clint_wvalid = 1'b0;
                lsu_wready   = 1'b0;
            end
        endcase
    end

    // 读数据通道处理
    always @(*) begin
        sram_rready  = 1'b0;
        uart_rready  = 1'b0;
        clint_rready = 1'b0;
        ifu_rdata    = 32'h0;
        ifu_rvalid   = 1'b0;
        ifu_rresp    = OKAY;
        lsu_rdata    = 32'h0;
        lsu_rvalid   = 1'b0;
        lsu_rresp    = OKAY;

        case (current_master)
            IFU: begin
                case (decode_address(ifu_araddr))
                    SRAM: begin
                        ifu_rdata    = sram_rdata;
                        ifu_rvalid   = sram_rvalid;
                        ifu_rresp    = sram_rresp;
                        sram_rready  = ifu_rready;
                        uart_rready  = 1'b0;
                        clint_rready = 1'b0;
                    end
                    UART: begin
                        ifu_rdata    = uart_rdata;
                        ifu_rvalid   = uart_rvalid;
                        ifu_rresp    = uart_rresp;
                        uart_rready  = ifu_rready;
                        sram_rready  = 1'b0;
                        clint_rready = 1'b0;
                    end
                    CLINT: begin 
                        ifu_rdata    = clint_rdata;
                        ifu_rvalid   = clint_rvalid;
                        ifu_rresp    = clint_rresp;
                        clint_rready = ifu_rready;
                        sram_rready  = 1'b0;
                        uart_rready  = 1'b0;
                    end
                    ERR: begin
                        ifu_rdata    = 32'h0;
                        ifu_rvalid   = ifu_arvalid;
                        ifu_rresp    = DECERR; // DECERR
                        sram_rready  = 1'b0;
                        uart_rready  = 1'b0;
                        clint_rready = 1'b0;
                    end
                    default: begin
                        ifu_rdata    = 32'h0;
                        ifu_rvalid   = 1'b0;
                        ifu_rresp    = OKAY;
                        sram_rready  = 1'b0;
                        uart_rready  = 1'b0;
                        clint_rready = 1'b0;
                    end
                endcase
            end
            LSU_READ: begin
                case (decode_address(lsu_araddr))
                    SRAM: begin
                        lsu_rdata    = sram_rdata;
                        lsu_rvalid   = sram_rvalid;
                        lsu_rresp    = sram_rresp;
                        sram_rready  = lsu_rready;
                        uart_rready  = 1'b0;
                        clint_rready = 1'b0;
                    end
                    UART: begin
                        lsu_rdata    = uart_rdata;
                        lsu_rvalid   = uart_rvalid;
                        lsu_rresp    = uart_rresp;
                        uart_rready  = lsu_rready;
                        sram_rready  = 1'b0;
                        clint_rready = 1'b0;
                    end
                    CLINT: begin 
                        lsu_rdata    = clint_rdata;
                        lsu_rvalid   = clint_rvalid;
                        lsu_rresp    = clint_rresp;
                        clint_rready = lsu_rready;
                        sram_rready  = 1'b0;
                        uart_rready  = 1'b0;
                    end
                    ERR: begin
                        lsu_rdata    = 32'h0;
                        lsu_rvalid   = lsu_arvalid;
                        lsu_rresp    = DECERR; // DECERR
                        sram_rready  = 1'b0;
                        uart_rready  = 1'b0;
                        clint_rready = 1'b0;
                    end
                    default: begin
                        lsu_rdata    = 32'h0;
                        lsu_rvalid   = 1'b0;
                        lsu_rresp    = OKAY;
                        sram_rready  = 1'b0;
                        uart_rready  = 1'b0;
                        clint_rready = 1'b0;
                    end
                endcase
            end
            ERROR: begin
                if (ifu_arvalid) begin
                    ifu_rdata    = 32'h0;
                    ifu_rvalid   = 1'b1;
                    ifu_rresp    = DECERR; // DECERR
                end else if (lsu_arvalid) begin
                    lsu_rdata    = 32'h0;
                    lsu_rvalid   = 1'b1;
                    lsu_rresp    = DECERR; // DECERR
                end
                sram_rready  = 1'b0;
                uart_rready  = 1'b0;
                clint_rready = 1'b0;
            end
            default: begin
                sram_rready  = 1'b0;
                uart_rready  = 1'b0;
                clint_rready = 1'b0;
                ifu_rdata    = 32'h0;
                ifu_rvalid   = 1'b0;
                ifu_rresp    = OKAY;
                lsu_rdata    = 32'h0;
                lsu_rvalid   = 1'b0;
                lsu_rresp    = OKAY;
            end
        endcase
    end

    // 写响应通道处理
    always @(*) begin
        sram_bready  = 1'b0;
        uart_bready  = 1'b0;
        clint_bready = 1'b0; 
        lsu_bresp    = OKAY;
        lsu_bvalid   = 1'b0;

        case (current_master)
            LSU_WRITE: begin
                case (decode_address(lsu_awaddr))
                    SRAM: begin
                        lsu_bresp    = sram_bresp;
                        lsu_bvalid   = sram_bvalid;
                        sram_bready  = lsu_bready;
                        uart_bready  = 1'b0;
                        clint_bready = 1'b0;
                    end
                    UART: begin
                        lsu_bresp    = uart_bresp;
                        lsu_bvalid   = uart_bvalid;
                        uart_bready  = lsu_bready;
                        sram_bready  = 1'b0;
                        clint_bready = 1'b0;
                    end
                    CLINT: begin 
                        lsu_bresp    = clint_bresp;
                        lsu_bvalid   = clint_bvalid;
                        clint_bready = lsu_bready;
                        sram_bready  = 1'b0;
                        uart_bready  = 1'b0;
                    end
                    ERR: begin
                        lsu_bresp    = DECERR; // DECERR
                        lsu_bvalid   = lsu_awvalid;
                        sram_bready  = 1'b0;
                        uart_bready  = 1'b0;
                        clint_bready = 1'b0;
                    end
                    default: begin
                        lsu_bresp    = OKAY;
                        lsu_bvalid   = 1'b0;
                        sram_bready  = 1'b0;
                        uart_bready  = 1'b0;
                        clint_bready = 1'b0;
                    end
                endcase
            end
            ERROR: begin
                if (lsu_awvalid) begin
                    lsu_bresp    = DECERR; // DECERR
                    lsu_bvalid   = 1'b1;
                end
                sram_bready  = 1'b0;
                uart_bready  = 1'b0;
                clint_bready = 1'b0;
            end
            default: begin
                sram_bready  = 1'b0;
                uart_bready  = 1'b0;
                clint_bready = 1'b0;
                lsu_bresp    = OKAY;
                lsu_bvalid   = 1'b0;
            end
        endcase
    end

endmodule