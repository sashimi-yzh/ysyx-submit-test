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

    output reg [31:0] io_master_araddr,
    output reg        io_master_arvalid,
    input wire        io_master_arready,
    input wire [31:0] io_master_rdata,
    input wire [1:0]  io_master_rresp,
    input wire        io_master_rvalid,
    output reg        io_master_rready,
    output reg [31:0] io_master_awaddr,
    output reg        io_master_awvalid,
    input wire        io_master_awready,
    output reg [31:0] io_master_wdata,
    output reg [3:0]  io_master_wstrb,
    output reg        io_master_wvalid,
    input wire        io_master_wready,
    input wire [1:0]  io_master_bresp,
    input wire        io_master_bvalid,
    output reg        io_master_bready,

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

    localparam CLINT = 2'd1;
    localparam MASTER = 2'd2;

    reg [2:0] current_master, next_master;

    parameter OKAY = 2'b00;
    parameter SLVERR = 2'b10;
    parameter DECERR = 2'b11;

    // 地址解码函数
    function [1:0] decode_address(input [31:0] addr);
        if (addr >= 32'h0200_0000 && addr <= 32'h0200_0007) begin
            decode_address = CLINT;
        end
        else begin
            decode_address = MASTER;
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
                    next_master = MEM_WRITE;
                end 
                else if (mem_arvalid) begin
                    next_master = MEM_READ;
                end 
                else if (ifu_arvalid) begin
                    next_master = IFU;
                end 
                else begin
                    next_master = NONE;
                end
            end
            IFU: begin
                if ((io_master_rvalid && io_master_rready) || (clint_rvalid && clint_rready)) begin 
                    next_master = NONE;
                end else begin
                    next_master = IFU;
                end
            end
            MEM_READ: begin
                if ((io_master_rvalid && io_master_rready) || (clint_rvalid && clint_rready)) begin
                    next_master = NONE;
                end else begin
                    next_master = MEM_READ;
                end
            end
            MEM_WRITE: begin
                if ((io_master_bvalid && io_master_bready) || (clint_bvalid && clint_bready)) begin 
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
        if(reset) begin
            io_master_araddr  = 32'h0;
            io_master_arvalid = 1'b0;
            clint_araddr      = 32'h0; 
            clint_arvalid     = 1'b0;  
            ifu_arready       = 1'b0;
            mem_arready       = 1'b0;
        end
        else begin
            case (current_master)
                IFU: begin
                    case (decode_address(ifu_araddr))
                        CLINT: begin 
                            clint_araddr      = ifu_araddr;
                            clint_arvalid     = ifu_arvalid;
                            ifu_arready       = clint_arready;
                            mem_arready       = 1'b0;
                            io_master_araddr  = 32'h0;
                            io_master_arvalid = 1'b0;
                        end
                        default: begin
                            io_master_araddr  = ifu_araddr;
                            io_master_arvalid = ifu_arvalid;
                            ifu_arready       = io_master_arready;
                            clint_araddr      = 32'h0;
                            clint_arvalid     = 1'b0;
                            mem_arready       = 1'b0;
                        end 
                    endcase
                end
                MEM_READ: begin
                    case (decode_address(mem_araddr))
                        CLINT: begin 
                            clint_araddr      = mem_araddr;
                            clint_arvalid     = mem_arvalid;
                            mem_arready       = clint_arready;
                            ifu_arready       = 1'b0;
                            io_master_araddr  = 32'h0;
                            io_master_arvalid = 1'b0;
                        end
                        default: begin
                            io_master_araddr  = mem_araddr;
                            io_master_arvalid = mem_arvalid;
                            mem_arready       = io_master_arready;
                            clint_araddr      = 32'h0;
                            clint_arvalid     = 1'b0;
                            ifu_arready       = 1'b0;
                        end
                    endcase
                end
                ERROR: begin
                    ifu_arready       = ifu_arvalid;
                    mem_arready       = mem_arvalid;
                    io_master_araddr  = 32'h0;
                    io_master_arvalid = 1'b0;
                    clint_araddr      = 32'h0;
                    clint_arvalid     = 1'b0;
                end
                default: begin
                    io_master_araddr  = 32'h0;
                    io_master_arvalid = 1'b0;
                    clint_araddr      = 32'h0;
                    clint_arvalid     = 1'b0;
                    ifu_arready       = 1'b0;
                    mem_arready       = 1'b0;
                end
            endcase
        end
    end

    // 写地址通道处理
    always @(*) begin
        if(reset) begin
            io_master_awaddr  = 32'h0;
            io_master_awvalid = 1'b0;
            clint_awaddr      = 32'h0; 
            clint_awvalid     = 1'b0;  
            mem_awready       = 1'b0;
        end
        else begin
            case (current_master)
                MEM_WRITE: begin
                    case (decode_address(mem_awaddr))
                        CLINT: begin 
                            clint_awaddr      = mem_awaddr;
                            clint_awvalid     = mem_awvalid;
                            mem_awready       = clint_awready;
                            io_master_awaddr  = 32'h0;
                            io_master_awvalid = 1'b0;
                        end
                        default: begin
                            io_master_awaddr  = mem_awaddr;
                            io_master_awvalid = mem_awvalid;
                            mem_awready       = io_master_arready;
                            clint_awaddr      = 32'h0;
                            clint_awvalid     = 1'b0;
                        end
                    endcase
                end
                ERROR: begin
                    mem_awready       = mem_awvalid;
                    io_master_awaddr  = 32'h0;
                    io_master_awvalid = 1'b0;
                    clint_awaddr      = 32'h0;
                    clint_awvalid     = 1'b0;
                end
                default: begin
                    io_master_awaddr  = 32'h0;
                    io_master_awvalid = 1'b0;
                    clint_awaddr      = 32'h0;
                    clint_awvalid     = 1'b0;
                    mem_awready       = 1'b0;
                end
            endcase
        end
    end

    // 写数据通道处理
    always @(*) begin
        if(reset) begin
            io_master_wdata  = 32'h0;
            io_master_wstrb  = 4'b0;
            io_master_wvalid = 1'b0;
            clint_wdata      = 32'h0; 
            clint_wstrb      = 4'b0;  
            clint_wvalid     = 1'b0;   
            mem_wready       = 1'b0;
        end
        else begin
            case (current_master)
                MEM_WRITE: begin
                    case (decode_address(mem_awaddr))
                        CLINT: begin 
                            clint_wdata      = mem_wdata;
                            clint_wstrb      = mem_wstrb;
                            clint_wvalid     = mem_wvalid;
                            mem_wready       = clint_wready;
                            io_master_wdata  = 32'h0;
                            io_master_wstrb  = 4'b0;
                            io_master_wvalid = 1'b0;
                        end
                        default: begin
                            io_master_wdata  = mem_wdata;
                            io_master_wstrb  = mem_wstrb;
                            io_master_wvalid = mem_wvalid;
                            mem_wready       = io_master_wready;
                            clint_wdata      = 32'h0;
                            clint_wstrb      = 4'b0;
                            clint_wvalid     = 1'b0;
                        end
                    endcase
                end
                default: begin
                    io_master_wdata  = 32'h0;
                    io_master_wstrb  = 4'b0;
                    io_master_wvalid = 1'b0;
                    clint_wdata  = 32'h0;
                    clint_wstrb  = 4'b0;
                    clint_wvalid = 1'b0;
                    mem_wready   = 1'b0;
                end
            endcase
        end
    end

    // 读数据通道处理
    always @(*) begin
        if(reset) begin
            io_master_rready = 1'b0;
            clint_rready     = 1'b0;
            ifu_rdata        = 32'h0;
            ifu_rvalid       = 1'b0;
            ifu_rresp        = OKAY;
            mem_rdata        = 32'h0;
            mem_rvalid       = 1'b0;
            mem_rresp        = OKAY;
        end
        else begin
            case (current_master)
                IFU: begin
                    case (decode_address(ifu_araddr))
                        CLINT: begin 
                            ifu_rdata        = clint_rdata;
                            ifu_rvalid       = clint_rvalid;
                            ifu_rresp        = clint_rresp;
                            clint_rready     = ifu_rready;
                            io_master_rready = 1'b0;
                        end
                        default: begin
                            ifu_rdata        = io_master_rdata;
                            ifu_rvalid       = io_master_rvalid;
                            ifu_rresp        = io_master_rresp;
                            io_master_rready = ifu_rready;
                            clint_rready     = 1'b0;
                        end
                    endcase
                end
                MEM_READ: begin
                    case (decode_address(mem_araddr))
                        CLINT: begin 
                            mem_rdata        = clint_rdata;
                            mem_rvalid       = clint_rvalid;
                            mem_rresp        = clint_rresp;
                            clint_rready     = mem_rready;
                            io_master_rready = 1'b0;
                        end
                        default: begin
                            mem_rdata        = io_master_rdata;
                            mem_rvalid       = io_master_rvalid;
                            mem_rresp        = io_master_rresp;
                            io_master_rready = mem_rready;
                            clint_rready     = 1'b0;
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
                    io_master_rready = 1'b0;
                    clint_rready = 1'b0;
                end
                default: begin
                    io_master_rready = 1'b0;
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
    end

    // 写响应通道处理
    always @(*) begin
        if(reset) begin
            io_master_bready = 1'b0;
            clint_bready     = 1'b0; 
            mem_bresp        = OKAY;
            mem_bvalid       = 1'b0;
        end
        else begin
            case (current_master)
                MEM_WRITE: begin
                    case (decode_address(mem_awaddr))
                        CLINT: begin 
                            mem_bresp        = clint_bresp;
                            mem_bvalid       = clint_bvalid;
                            clint_bready     = mem_bready;
                            io_master_bready = 1'b0;
                        end
                        default: begin
                            mem_bresp        = io_master_bresp;
                            mem_bvalid       = io_master_bvalid;
                            io_master_bready = mem_bready;
                            clint_bready     = 1'b0;
                        end
                    endcase
                end
                ERROR: begin
                    if (mem_awvalid) begin
                        mem_bresp    = DECERR; // DECERR
                        mem_bvalid   = 1'b1;
                    end
                    io_master_bready = 1'b0;
                    clint_bready     = 1'b0;
                end
                default: begin
                    io_master_bready = 1'b0;
                    clint_bready     = 1'b0;
                    mem_bresp        = OKAY;
                    mem_bvalid       = 1'b0;
                end
            endcase
        end
    end

endmodule