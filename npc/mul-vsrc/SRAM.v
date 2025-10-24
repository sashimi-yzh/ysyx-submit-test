`include "/home/furina/ysyx-workbench/npc/mul-vsrc/defines.v"
// ====== SRAM接口定义 ======
module SRAM #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter MAX_DELAY  = 4,
    parameter MIN_DELAY  = 1
)(
    input  wire                   clk,
    input  wire                   reset,

    //AXI4-Lite 读地址通道
    input  wire [ADDR_WIDTH-1:0]  araddr,
    input  wire                   arvalid,
    output reg                    arready,
    //AXI4-Lite读数据通道
    output reg   [DATA_WIDTH-1:0] rdata,
    output reg                    rvalid,
    input  wire                   rready,
    output reg   [1:0]            rresp,//读响应信号
    //AXI4-Lite写地址通道
    input  wire [ADDR_WIDTH-1:0]  awaddr,
    input  wire                   awvalid,
    output reg                    awready,
    //AXI4-Lite写数据通道
    input  wire [DATA_WIDTH-1:0]  wdata,
    input  wire [3:0]             wstrb,
    input  wire                   wvalid,
    output reg                    wready,
    //写响应通道
    output reg   [1:0]            bresp,//写回复信号
    output reg                    bvalid,
    input  wire                   bready
);
    import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
    import "DPI-C" function void pmem_write(input int unsigned waddr, input int unsigned wdata, input int len);

    //状态机定义
    typedef enum {IDLE, READ_ADDR, READ_DATA, WRITE_ADDR, WRITE_DATA, WRITE_RESP} state_t;
    state_t sram_state, next_sram_state;
    reg [31:0] LFSR;//模拟读延迟计数器
    reg [31:0] random_delay; 
    
    reg [ADDR_WIDTH-1:0] araddr_reg,awaddr_reg;
    reg [DATA_WIDTH-1:0] rdata_reg,wdata_reg;
    reg [3:0] wstrb_reg;
    reg addr_valid;

    //检查地址是否有效
    always @(*) begin
        if(`DEVICE) begin
            addr_valid = (araddr >= 32'h8000_0000 && araddr <= 32'h8fff_ffff) ||
                    (awaddr >= 32'h8000_0000 && awaddr <= 32'h8fff_ffff) ||
                    (araddr >= 32'ha000_0000 && araddr <= 32'ha000_0007) ||
                    (awaddr >= 32'ha000_1000 && awaddr <= 32'ha000_1003) ||
                    (awaddr >= 32'ha000_2000 && awaddr <= 32'ha000_2007);
        end
        else begin
            addr_valid = (araddr >= 32'h8000_0000 && araddr <= 32'h8fff_ffff) ||
                    (awaddr >= 32'h8000_0000 && awaddr <= 32'h8fff_ffff);
        end
    end

    //随机生成延迟
    // always @(posedge clk) begin
    //     if(reset) begin
    //         random_delay <= MIN_DELAY;
    //     end
    //     else if(sram_state == IDLE && ((arvalid && arready) || (awvalid && awready))) begin
    //         random_delay <= ($random % (MAX_DELAY - MIN_DELAY + 1)) + MIN_DELAY;
    //     end
    // end
    
    always @(posedge clk) begin
        if(reset) begin
            sram_state <= IDLE;
            arready <= 1'b0;
            rvalid <= 1'b0;
            wready <= 1'b0;
            rdata <= 32'h0;
            LFSR <= MIN_DELAY;
            araddr_reg <= 32'h0;
            rdata_reg <= 32'h0;
            rresp <= `OKAY;
            bresp <= `OKAY;
            bvalid <= 1'b0;
            awaddr_reg <= 32'h0;
            wstrb_reg <= 4'b0000;
            wdata_reg <= 32'h0;
        end
        else begin
            sram_state <= next_sram_state;
            case(sram_state)
                IDLE:begin
                    arready <= 1'b1;//初始化时准备好接受读地址
                    awready  <= 1'b1;//初始化时准备好接受写地址
                    rvalid  <= 1'b0;
                    bvalid  <= 1'b0;
                    // LFSR <= ($random % (MAX_DELAY - MIN_DELAY + 1)) + MIN_DELAY;
                    LFSR <= $urandom_range(1, 10);//随机生成1~10的读写延迟
                    // LFSR <= MIN_DELAY;
                    if(arvalid && arready) begin//读握手
                        araddr_reg <= araddr;
                        arready <= 1'b0;//接收地址后不再准备
                        // LFSR <= random_delay;
                        next_sram_state <= READ_ADDR;
                    end
                    else if(awvalid && awready) begin//写地址握手
                        wdata_reg <= wdata;
                        wstrb_reg <= wstrb;
                        awaddr_reg <= awaddr;
                        awready <= 1'b0;
                        // LFSR <= random_delay;
                        next_sram_state <= WRITE_ADDR;
                    end
                    // else begin
                    //     next_sram_state <= IDLE;
                    // end
                end
                READ_ADDR:begin
                    if(LFSR > 0) begin
                        // araddr_reg <= araddr;
                        LFSR <= LFSR - 1;
                        next_sram_state <= READ_ADDR;
                    end
                    else begin
                        if(addr_valid) begin
                            rdata_reg <= pmem_read(araddr_reg, 4);
                            rresp <= `OKAY;
                        end
                        else begin
                            rdata_reg <= 32'h0;
                            rresp <= `SLVERR;
                        end
                        next_sram_state <= READ_DATA;
                    end
                end
                READ_DATA: begin
                    if(rready) begin
                        rdata <= rdata_reg;
                        rvalid <= 1'b1;
                        araddr_reg <= 32'h0;//清空读地址寄存器
                        // rvalid <= 1'b0;//数据被接受后关闭rvalid
                        next_sram_state <= IDLE;
                    end
                    else next_sram_state <= READ_DATA;
                end
                WRITE_ADDR: begin
                    if(LFSR > 0) begin
                        LFSR <= LFSR - 1;
                        next_sram_state <= WRITE_ADDR;
                    end
                    else begin
                        wready <= 1'b1;
                        next_sram_state <= WRITE_DATA;
                    end
                end
                WRITE_DATA: begin
                    if(wvalid && wready) begin//写握手
                        wready <= 1'b0;//接收地址后不再准备
                        if(addr_valid) begin
                            case(wstrb_reg)
                                4'b0001: pmem_write(awaddr_reg,wdata_reg,1);//sb
                                4'b0011: pmem_write(awaddr_reg,wdata_reg,2);//sh
                                4'b1111: pmem_write(awaddr_reg,wdata_reg,4);//sw
                                default: pmem_write(awaddr_reg,wdata_reg,4);
                            endcase
                            bresp <= `OKAY;
                            // wready <= 1'b0;
                        end
                        else begin
                            bresp <= `SLVERR;
                        end
                        bvalid <= 1'b1;
                        next_sram_state <= WRITE_RESP;
                    end
                    // else begin
                    //     next_sram_state <= WRITE_DATA;
                    // end
                end
                WRITE_RESP: begin
                    if(bvalid && bready) begin
                        // wready <= 1'b1;
                        // awready <= 1'b1;
                        // bvalid <= 1'b0;
                        // next_sram_state <= IDLE;
                    end
                    awready <= 1'b1;
                    bvalid <= 1'b0;
                    next_sram_state <= IDLE;
                    // else begin
                    //     next_sram_state <= WRITE_RESP;
                    // end
                end
                default: begin
                    next_sram_state <= IDLE;
                end
            endcase
        end
    end

    // // 调试日志
    // always @(posedge clk) begin
    //     $display("[mem_sram] state=%d, arvalid=%b, arready=%b, rvalid=%b, rready=%b, awvalid=%b, awready=%b, wvalid=%b, wready=%b, bvalid=%b, bready=%b, raddr=0x%h, waddr=0x%h, wstrb=%b,wdata=0x%h",
    //              sram_state, arvalid, arready, rvalid, rready, awvalid, awready, wvalid, wready, bvalid, bready, araddr_reg, awaddr_reg, wstrb_reg,  wdata_reg);
    // end

    // 协议断言
    always @(posedge clk) begin
        assert(!(arvalid && arready && sram_state != IDLE)) else $error("[mem_sram] AR channel handshake in wrong state");
        assert(!(rvalid && rready && sram_state != READ_DATA)) else $error("[mem_sram] R channel handshake in wrong state");
        assert(!(awvalid && awready && sram_state != IDLE)) else $error("[mem_sram] AW channel handshake in wrong state");
        assert(!(wvalid && wready && sram_state != WRITE_DATA)) else $error("[mem_sram] W channel handshake in wrong state");
        assert(!(bvalid && bready && sram_state != WRITE_RESP)) else $error("[mem_sram] B channel handshake in wrong state");
    end
endmodule