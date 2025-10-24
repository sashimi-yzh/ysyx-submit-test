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

    // MEM主设备（读写）
    input wire [31:0] mem_araddr,   // MEM读地址
    input wire        mem_arvalid,  // MEM读地址有效
    output reg        mem_arready,  // MEM读地址ready
    output reg [31:0] mem_rdata,    // MEM读数据
    output reg [1:0]  mem_rresp,    // MEM读响应
    output reg        mem_rvalid,   // MEM读数据有效
    input wire        mem_rready,   // MEM读数据ready

    input wire [31:0] mem_awaddr,   // MEM写地址
    input wire        mem_awvalid,  // MEM写地址有效
    output reg        mem_awready,  // MEM写地址ready
    input wire [31:0] mem_wdata,    // MEM写数据
    input wire [3:0]  mem_wstrb,    // MEM写选通
    input wire        mem_wvalid,   // MEM写数据有效
    output reg        mem_wready,   // MEM写数据ready
    output reg [1:0]  mem_bresp,    // MEM写响应
    output reg        mem_bvalid,   // MEM写响应有效
    input wire        mem_bready,   // MEM写响应ready

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
    localparam MEM_READ  = 3'd2;
    localparam MEM_WRITE = 3'd3;
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
                if (mem_awvalid) begin
                    case (decode_address(mem_awaddr))
                        SRAM:  next_master = MEM_WRITE;
                        UART:  next_master = MEM_WRITE;
                        CLINT: next_master = MEM_WRITE; 
                        default: next_master = ERROR;
                    endcase
                end else if (mem_arvalid) begin
                    case (decode_address(mem_araddr))
                        SRAM:  next_master = MEM_READ;
                        UART:  next_master = MEM_READ;
                        CLINT: next_master = MEM_READ; 
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
            MEM_READ: begin
                if ((sram_rvalid && sram_rready) || (uart_rvalid && uart_rready) || (clint_rvalid && clint_rready)) begin
                    next_master = NONE;
                end else begin
                    next_master = MEM_READ;
                end
            end
            MEM_WRITE: begin
                if ((sram_bvalid && sram_bready) || (uart_bvalid && uart_bready) || (clint_bvalid && clint_bready)) begin 
                    next_master = NONE;
                end else begin
                    next_master = MEM_WRITE;
                end
            end
            ERROR: begin
                if ((ifu_rvalid && ifu_rready) || (mem_rvalid && mem_rready) || (mem_bvalid && mem_bready)) begin
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
        mem_arready   = 1'b0;

        case (current_master)
            IFU: begin
                case (decode_address(ifu_araddr))
                    SRAM: begin
                        sram_araddr   = ifu_araddr;
                        sram_arvalid  = ifu_arvalid;
                        ifu_arready   = sram_arready;
                        mem_arready   = 1'b0;
                        uart_araddr   = 32'h0;
                        uart_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                    end
                    UART: begin
                        uart_araddr   = ifu_araddr;
                        uart_arvalid  = ifu_arvalid;
                        ifu_arready   = uart_arready;
                        mem_arready   = 1'b0;
                        sram_araddr   = 32'h0;
                        sram_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                    end
                    CLINT: begin 
                        clint_araddr  = ifu_araddr;
                        clint_arvalid = ifu_arvalid;
                        ifu_arready   = clint_arready;
                        mem_arready   = 1'b0;
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
                        mem_arready   = 1'b0;
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
                        mem_arready   = 1'b0;
                    end 
                endcase
            end
            MEM_READ: begin
                case (decode_address(mem_araddr))
                    SRAM: begin
                        sram_araddr   = mem_araddr;
                        sram_arvalid  = mem_arvalid;
                        mem_arready   = sram_arready;
                        ifu_arready   = 1'b0;
                        uart_araddr   = 32'h0;
                        uart_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                    end
                    UART: begin
                        uart_araddr   = mem_araddr;
                        uart_arvalid  = mem_arvalid;
                        mem_arready   = uart_arready;
                        ifu_arready   = 1'b0;
                        sram_araddr   = 32'h0;
                        sram_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                    end
                    CLINT: begin 
                        clint_araddr  = mem_araddr;
                        clint_arvalid = mem_arvalid;
                        mem_arready   = clint_arready;
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
                        mem_arready   = 1'b1; // 接受地址以返回错误
                        ifu_arready   = 1'b0;
                        $display("\033[31m[ARB][MEM][AR] 地址解码错误！地址: %h\033[0m", mem_araddr);
                    end
                    default: begin
                        sram_araddr   = 32'h0;
                        sram_arvalid  = 1'b0;
                        uart_araddr   = 32'h0;
                        uart_arvalid  = 1'b0;
                        clint_araddr  = 32'h0;
                        clint_arvalid = 1'b0;
                        ifu_arready   = 1'b0;
                        mem_arready   = 1'b0;
                    end
                endcase
            end
            ERROR: begin
                ifu_arready = ifu_arvalid;
                mem_arready = mem_arvalid;
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
                mem_arready   = 1'b0;
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
        mem_awready   = 1'b0;

        case (current_master)
            MEM_WRITE: begin
                case (decode_address(mem_awaddr))
                    SRAM: begin
                        sram_awaddr   = mem_awaddr;
                        sram_awvalid  = mem_awvalid;
                        mem_awready   = sram_awready;
                        uart_awaddr   = 32'h0;
                        uart_awvalid  = 1'b0;
                        clint_awaddr  = 32'h0;
                        clint_awvalid = 1'b0;
                    end
                    UART: begin
                        uart_awaddr   = mem_awaddr;
                        uart_awvalid  = mem_awvalid;
                        mem_awready   = uart_awready;
                        sram_awaddr   = 32'h0;
                        sram_awvalid  = 1'b0;
                        clint_awaddr  = 32'h0;
                        clint_awvalid = 1'b0;
                    end
                    CLINT: begin 
                        clint_awaddr  = mem_awaddr;
                        clint_awvalid = mem_awvalid;
                        mem_awready   = clint_awready;
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
                        mem_awready   = 1'b1; // 接受地址以返回错误
                        $display("\033[31m[ARB][MEM][AW] 地址解码错误！地址: %h\033[0m", mem_awaddr);
                    end
                    default: begin
                        sram_awaddr   = 32'h0;
                        sram_awvalid  = 1'b0;
                        uart_awaddr   = 32'h0;
                        uart_awvalid  = 1'b0;
                        clint_awaddr  = 32'h0;
                        clint_awvalid = 1'b0;
                        mem_awready   = 1'b0;
                    end
                endcase
            end
            ERROR: begin
                mem_awready = mem_awvalid;
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
                mem_awready   = 1'b0;
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
        mem_wready   = 1'b0;

        case (current_master)
            MEM_WRITE: begin
                case (decode_address(mem_awaddr))
                    SRAM: begin
                        sram_wdata   = mem_wdata;
                        sram_wstrb   = mem_wstrb;
                        sram_wvalid  = mem_wvalid;
                        mem_wready   = sram_wready;
                        uart_wdata   = 32'h0;
                        uart_wstrb   = 4'b0;
                        uart_wvalid  = 1'b0;
                        clint_wdata  = 32'h0;
                        clint_wstrb  = 4'b0;
                        clint_wvalid = 1'b0;
                    end
                    UART: begin
                        uart_wdata   = mem_wdata;
                        uart_wstrb   = mem_wstrb;
                        uart_wvalid  = mem_wvalid;
                        mem_wready   = uart_wready;
                        sram_wdata   = 32'h0;
                        sram_wstrb   = 4'b0;
                        sram_wvalid  = 1'b0;
                        clint_wdata  = 32'h0;
                        clint_wstrb  = 4'b0;
                        clint_wvalid = 1'b0;
                    end
                    CLINT: begin 
                        clint_wdata  = mem_wdata;
                        clint_wstrb  = mem_wstrb;
                        clint_wvalid = mem_wvalid;
                        mem_wready   = clint_wready;
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
                        mem_wready   = mem_wvalid; // 接受数据以返回错误
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
                        mem_wready   = 1'b0;
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
                mem_wready   = 1'b0;
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
        mem_rdata    = 32'h0;
        mem_rvalid   = 1'b0;
        mem_rresp    = OKAY;

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
            MEM_READ: begin
                case (decode_address(mem_araddr))
                    SRAM: begin
                        mem_rdata    = sram_rdata;
                        mem_rvalid   = sram_rvalid;
                        mem_rresp    = sram_rresp;
                        sram_rready  = mem_rready;
                        uart_rready  = 1'b0;
                        clint_rready = 1'b0;
                    end
                    UART: begin
                        mem_rdata    = uart_rdata;
                        mem_rvalid   = uart_rvalid;
                        mem_rresp    = uart_rresp;
                        uart_rready  = mem_rready;
                        sram_rready  = 1'b0;
                        clint_rready = 1'b0;
                    end
                    CLINT: begin 
                        mem_rdata    = clint_rdata;
                        mem_rvalid   = clint_rvalid;
                        mem_rresp    = clint_rresp;
                        clint_rready = mem_rready;
                        sram_rready  = 1'b0;
                        uart_rready  = 1'b0;
                    end
                    ERR: begin
                        mem_rdata    = 32'h0;
                        mem_rvalid   = mem_arvalid;
                        mem_rresp    = DECERR; // DECERR
                        sram_rready  = 1'b0;
                        uart_rready  = 1'b0;
                        clint_rready = 1'b0;
                    end
                    default: begin
                        mem_rdata    = 32'h0;
                        mem_rvalid   = 1'b0;
                        mem_rresp    = OKAY;
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
                end else if (mem_arvalid) begin
                    mem_rdata    = 32'h0;
                    mem_rvalid   = 1'b1;
                    mem_rresp    = DECERR; // DECERR
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
                mem_rdata    = 32'h0;
                mem_rvalid   = 1'b0;
                mem_rresp    = OKAY;
            end
        endcase
    end

    // 写响应通道处理
    always @(*) begin
        sram_bready  = 1'b0;
        uart_bready  = 1'b0;
        clint_bready = 1'b0; 
        mem_bresp    = OKAY;
        mem_bvalid   = 1'b0;

        case (current_master)
            MEM_WRITE: begin
                case (decode_address(mem_awaddr))
                    SRAM: begin
                        mem_bresp    = sram_bresp;
                        mem_bvalid   = sram_bvalid;
                        sram_bready  = mem_bready;
                        uart_bready  = 1'b0;
                        clint_bready = 1'b0;
                    end
                    UART: begin
                        mem_bresp    = uart_bresp;
                        mem_bvalid   = uart_bvalid;
                        uart_bready  = mem_bready;
                        sram_bready  = 1'b0;
                        clint_bready = 1'b0;
                    end
                    CLINT: begin 
                        mem_bresp    = clint_bresp;
                        mem_bvalid   = clint_bvalid;
                        clint_bready = mem_bready;
                        sram_bready  = 1'b0;
                        uart_bready  = 1'b0;
                    end
                    ERR: begin
                        mem_bresp    = DECERR; // DECERR
                        mem_bvalid   = mem_awvalid;
                        sram_bready  = 1'b0;
                        uart_bready  = 1'b0;
                        clint_bready = 1'b0;
                    end
                    default: begin
                        mem_bresp    = OKAY;
                        mem_bvalid   = 1'b0;
                        sram_bready  = 1'b0;
                        uart_bready  = 1'b0;
                        clint_bready = 1'b0;
                    end
                endcase
            end
            ERROR: begin
                if (mem_awvalid) begin
                    mem_bresp    = DECERR; // DECERR
                    mem_bvalid   = 1'b1;
                end
                sram_bready  = 1'b0;
                uart_bready  = 1'b0;
                clint_bready = 1'b0;
            end
            default: begin
                sram_bready  = 1'b0;
                uart_bready  = 1'b0;
                clint_bready = 1'b0;
                mem_bresp    = OKAY;
                mem_bvalid   = 1'b0;
            end
        endcase
    end

endmodule