`include "/home/furina/ysyx-workbench/npc/mul-vsrc/defines.v"
// 内存模块
module MEM (
    input             clk,
    input             reset,
    input             ex_valid,//上游ex输出是否有效
    output reg        mem_ready,//mem就绪状态
    input             wb_ready,//下游wb写回是否就绪
    output reg        mem_valid,//mem模块输出是否有效
    input             MemRead,
    input             MemWrite,
    input      [31:0] addr,
    input      [31:0] data_in,
    input      [2:0]  MemLen,
    output reg [31:0] data_out,
    output reg        load_access_fault,//异常访问
    output reg        store_access_fault,//异常写入
    output reg [31:0] mem_fault_addr,//异常地址

    output reg [31:0] sram_araddr,
    output reg        sram_arvalid,
    input wire        sram_arready,
    input wire [31:0] sram_rdata,
    input wire        sram_rvalid,
    output reg        sram_rready,
    input wire [1:0]  sram_rresp,
    output reg [31:0] sram_awaddr,
    output reg        sram_awvalid,
    input wire        sram_awready,
    output reg [31:0] sram_wdata,
    output reg [3:0]  sram_wstrb,
    output reg        sram_wvalid,
    input wire        sram_wready,
    input wire [1:0]  sram_bresp,
    input wire        sram_bvalid,
    output reg        sram_bready
);
    //====状态机定义====//  
    typedef enum {IDLE, READ_ADDR, READ_DATA, 
    WRITE_ADDR, WRITE_DATA, WRITE_RESP, STALL} state_t;//将之前的BUSY状态分为READ_ADDR、READ_DATA、WRITE
    state_t state,next_state;
    
    reg [1:0] delay;
    parameter DELAY_CYCLES = 3;//处理周期
    
    // //====SRAM读写接口====//
    // //AR channel
    // reg [31:0]  sram_araddr;//读地址
    // reg         sram_arvalid;//读地址有效
    // wire        sram_arready;//sram读地址准备好
    // //R channel
    // wire [1:0]  sram_rresp;//读响应信号
    // wire [31:0] sram_rdata;//读数据
    // wire        sram_rvalid;//读数据有效
    // reg         sram_rready;//CPU读数据准备好
    // //AW channel
    // reg [31:0]  sram_awaddr;//写地址
    // wire        sram_awready;//sram写地址准备好
    // reg         sram_awvalid;//写地址有效
    // //W channel
    // reg [31:0]  sram_wdata;//写数据
    // reg [3:0]   sram_wstrb;//写掩码
    // reg         sram_wvalid;//写请求有效
    // wire        sram_wready;//sram写请求准备好
    // //B channel
    // wire [1:0]  sram_bresp;//写响应信号
    // wire        sram_bvalid;//写响应有效
    // reg         sram_bready;//写响应准备好
    // //===================//

    // SRAM msram(
    //     .clk(clk),
    //     .reset(reset),
    //     //AR channel
    //     .araddr(sram_araddr),
    //     .arvalid(sram_arvalid),
    //     .arready(sram_arready),
    //     //R channel
    //     .rdata(sram_rdata),
    //     .rresp(sram_rresp),
    //     .rvalid(sram_rvalid),
    //     .rready(sram_rready),
    //     //AW channel
    //     .awaddr(sram_awaddr),
    //     .awvalid(sram_awvalid),
    //     .awready(sram_awready),
    //     //W channel
    //     .wdata(sram_wdata),
    //     .wstrb(sram_wstrb),
    //     .wvalid(sram_wvalid),
    //     .wready(sram_wready),
    //     //B channel
    //     .bresp(sram_bresp),
    //     .bvalid(sram_bvalid),
    //     .bready(sram_bready)
    // );

    always @(posedge clk or posedge reset) begin
        if(reset) begin
            state = IDLE;
            delay <= DELAY_CYCLES;
            mem_ready <= 1'b1;
            mem_valid <= 1'b0;
            data_out <= 32'h0;
            next_state = IDLE;

            sram_arvalid <= 1'b0;
            sram_rready <= 1'b0;
            sram_wvalid <= 1'b0;
            sram_araddr <= 32'h0;
            sram_awaddr <= 32'h0;
            sram_awvalid <= 1'b0;
            sram_wdata <= 32'h0;
            sram_wstrb <= 4'b1111;
            sram_bready <= 1'b0;
            load_access_fault <= 1'b0;
            store_access_fault <= 1'b0;
            mem_fault_addr <= 32'h0;
        end
        else begin
            state = next_state;
            case(state)
                IDLE: begin
                    mem_ready <= 1'b1;
                    mem_valid <= 1'b0;
                    sram_arvalid <= 1'b0;
                    sram_rready <= 1'b0;
                    sram_awvalid <= 1'b0;
                    sram_bready <= 1'b0;
                    load_access_fault <= 1'b0;
                    store_access_fault <= 1'b0;
                    if(ex_valid && mem_ready) begin//mem和上游ex握手
                        if(MemRead) begin
                            sram_araddr <= addr;
                            sram_arvalid <= 1'b1;//发送sram读请求
                            next_state = READ_ADDR;
                        end
                        else if(MemWrite) begin
                            sram_awaddr <= addr;
                            sram_awvalid <= 1'b1;//发送sram写地址请求
                            sram_wdata <= data_in;
                            // sram_wvalid <= 1'b1;//发送sram写请求
                            case(MemLen)
                                `Mem_Bit:  sram_wstrb <= 4'b0001;//sb
                                `Mem_Half: sram_wstrb <= 4'b0011;//sh
                                `Mem_Word: sram_wstrb <= 4'b1111;//sw
                                default:   sram_wstrb <= 4'b1111;
                            endcase
                            next_state = WRITE_ADDR;
                        end
                        else begin
                            next_state = STALL;
                        end
                    end
                    else begin
                        next_state = IDLE;
                    end
                end

                READ_ADDR: begin
                    mem_ready <= 1'b0;
                    mem_valid <= 1'b0;
                    // sram_arvalid <= 1'b1;//发送sram读请求
                    if(sram_arready && sram_arvalid) begin//读地址有效且sram准备好读取数据
                        // sram_arvalid <= 1'b0;//地址被接受，撤销读地址请求
                        //  $display("\033[31m[MEM]: READ_ADDR状态握手成功\033[0m");
                        // sram_rready <= 1'b1;//准备接受数据
                        next_state = READ_DATA;
                    end
                    else begin
                        next_state = READ_ADDR;
                    end
                end

                READ_DATA: begin
                    mem_ready <= 1'b0;
                    mem_valid <= 1'b0;
                    sram_rready <= 1'b1;//准备接受数据
                    // $display("FUCKING ERROR IS HERE");
                    if(sram_rvalid && sram_rready) begin//当读数据有效且cpu准备接受读数据
                        sram_arvalid <= 1'b0;//撤掉arvalid地址有效信号
                        // sram_rready <= 1'b0;//数据被接受，撤销rready接受读数据信号
                        // $display("\033[31m[MEM]: READ_DATA状态握手成功\033[0m");
                        // $display("\n************FUCKING ERROR IS HERE*************\n");
                        case(MemLen)
                            `Mem_Bit:   data_out <= {{24{sram_rdata[7]}},sram_rdata[7:0]}; 
                            `Mem_UBit:  data_out <= {24'b0,sram_rdata[7:0]};
                            `Mem_UHalf: data_out <= {16'b0,sram_rdata[15:0]};
                            `Mem_Half:  data_out <= {{16{sram_rdata[15]}},sram_rdata[15:0]};
                            `Mem_Word:  data_out <= sram_rdata;
                            default:    data_out <= 32'h0;
                        endcase
                        if(sram_rresp != `OKAY) begin
                            load_access_fault <= 1'b1;
                            mem_fault_addr <= sram_araddr;
                        end
                        else begin
                            load_access_fault <= 1'b0;
                            mem_fault_addr <= 32'h0;
                        end
                        next_state = STALL;
                    end
                    else begin
                        next_state = READ_DATA;
                    end
                end

                WRITE_ADDR: begin
                    mem_ready <= 1'b0;
                    mem_valid <= 1'b0;
                    if(sram_awready && sram_awvalid) begin
                        // sram_awvalid <= 1'b0;//地址被接受，撤销awvalid信号
                        // $display("\033[31m[MEM]: WRITE_ADDR状态握手成功\033[0m");
                        sram_wvalid <= 1'b1;//发送写请求
                        next_state = WRITE_DATA;
                    end
                    else begin
                        next_state = WRITE_ADDR;
                    end
                end

                WRITE_DATA: begin
                    mem_ready <= 1'b0;
                    mem_valid <= 1'b0;
                    // sram_wvalid <= 1'b1;//发送写请求
                    if(sram_wready && sram_wvalid) begin
                        sram_awvalid <= 1'b0;
                        sram_bready <= 1'b1;//准备接受写响应
                        // mem_valid <= 1'b1;
                        
                        // $display("\033[31m[MEM]: WRITE_DATA状态握手成功\033[0m");
                        next_state = WRITE_RESP;
                    end
                    else begin
                        next_state = WRITE_DATA;
                    end
                end
                
                WRITE_RESP: begin
                    mem_ready <= 1'b0;
                    mem_valid <= 1'b0;
                    if(sram_bvalid && sram_bready) begin
                        if(sram_bresp != `OKAY) begin
                            store_access_fault <= 1'b1;
                            mem_fault_addr <= sram_awaddr;
                        end
                        else begin
                            store_access_fault <= 1'b0;
                            mem_fault_addr <= 32'h0;
                        end
                        next_state = STALL;
                    end
                    else begin
                        next_state = WRITE_RESP;
                    end
                end
                STALL: begin
                    mem_ready <= 1'b0;
                    mem_valid <= 1'b1;
                    sram_wvalid <= 1'b0;
                    sram_rready <= 1'b0;
                    sram_arvalid <= 1'b0;
                    sram_bready <= 1'b0;
                    sram_awvalid <= 1'b0;
                    if(wb_ready) begin
                        next_state = IDLE;
                    end
                    else begin
                        next_state = STALL;
                    end
                end

                default: begin
                    mem_ready <= 1'b0;
                    mem_valid <= 1'b0;
                    next_state = IDLE;
                end
            endcase
        end
    end

    // // 调试日志
    // always @(posedge clk) begin
    //     $display("[MEM] state=%d, arvalid=%b, arready=%b, rvalid=%b, rready=%b, awvalid=%b, awready=%b, wvalid=%b, wready=%b, bvalid=%b, bready=%b, mem_valid=%b, wb_ready=%b, ex_valid=%b, addr=0x%h",
    //              state, sram_arvalid, sram_arready, sram_rvalid, sram_rready, sram_awvalid, sram_awready, sram_wvalid, sram_wready, sram_bvalid, sram_bready, mem_valid, wb_ready, ex_valid, sram_araddr);
    // end

    // 协议断言
    always @(posedge clk) begin
        assert(!(sram_arvalid && sram_arready && state != READ_ADDR)) else $error("[MEM] AR channel handshake in wrong state");
        assert(!(sram_rvalid && sram_rready && state != READ_DATA)) else $error("[MEM] R channel handshake in wrong state");
        assert(!(sram_awvalid && sram_awready && state != WRITE_ADDR)) else $error("[MEM] AW channel handshake in wrong state");
        assert(!(sram_wvalid && sram_wready && state != WRITE_DATA)) else $error("[MEM] W channel handshake in wrong state");
        assert(!(sram_bvalid && sram_bready && state != WRITE_RESP)) else $error("[MEM] B channel handshake in wrong state");
    end
endmodule