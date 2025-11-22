`include "/home/furina/ysyx-workbench/npc/soc-vsrc/defines.v"
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
    output reg        sram_bready,

    input      [31:0] ex_inst_type,
    input      [31:0] ex_start_cycle,
    output reg [31:0] mem_inst_type,
    output reg [31:0] mem_start_cycle
);
`ifdef VERILATOR
    import "DPI-C" function void counter(input int inst_type, input int cycles, input int ifu_inc, input int lsu_inc, input int exu_inc);
`endif

    //====状态机定义====//  
    typedef enum {IDLE, READ_ADDR, READ_DATA, 
    WRITE_ADDR, WRITE_DATA, WRITE_RESP, STALL} state_t;//将之前的BUSY状态分为READ_ADDR、READ_DATA、WRITE
    state_t state,next_state;
    
    reg [1:0] delay;
    parameter DELAY_CYCLES = 3;//处理周期
    
    function [3:0] generate_aligned_wstrb;
        input [2:0] mem_len;
        input [1:0] addr_low;
        begin
            case (mem_len)
                `Mem_Bit: begin
                    // 字节访问：根据地址低2位选择对应字节
                    case (addr_low)
                        2'b00: generate_aligned_wstrb = 4'b0001;
                        2'b01: generate_aligned_wstrb = 4'b0010;
                        2'b10: generate_aligned_wstrb = 4'b0100;
                        2'b11: generate_aligned_wstrb = 4'b1000;
                        default: generate_aligned_wstrb = 4'b0001;
                    endcase
                end
                `Mem_Half, `Mem_UHalf: begin
                    // 半字访问：地址必须对齐到2字节边界
                    case (addr_low)
                        2'b00: generate_aligned_wstrb = 4'b0011; // 低16位
                        2'b10: generate_aligned_wstrb = 4'b1100; // 高16位
                        default: generate_aligned_wstrb = 4'b0000; // 非对齐访问
                    endcase
                end
                `Mem_Word: begin
                    // 字访问：地址必须对齐到4字节边界
                    if (addr_low == 2'b00)
                        generate_aligned_wstrb = 4'b1111; // 全32位
                    else
                        generate_aligned_wstrb = 4'b0000; // 非对齐访问
                end
                default: generate_aligned_wstrb = 4'b1111;
            endcase
        end
    endfunction

    function [31:0] align_write_data;
        input [2:0] mem_len;
        input [1:0] addr_low;
        input [31:0] data_in;
        begin
            case (mem_len)
                `Mem_Bit: begin
                    // 字节访问：将数据移动到对应位置
                    case (addr_low)
                        2'b00: align_write_data = {24'b0, data_in[7:0]};
                        2'b01: align_write_data = {16'b0, data_in[7:0], 8'b0};
                        2'b10: align_write_data = {8'b0, data_in[7:0], 16'b0};
                        2'b11: align_write_data = {data_in[7:0], 24'b0};
                        default: align_write_data = data_in;
                    endcase
                end
                `Mem_Half, `Mem_UHalf: begin
                    // 半字访问：将数据移动到对应位置
                    case (addr_low)
                        2'b00: align_write_data = {16'b0, data_in[15:0]}; // 低16位
                        2'b10: align_write_data = {data_in[15:0], 16'b0};  // 高16位
                        default: align_write_data = data_in; // 非对齐访问保持原样
                    endcase
                end
                `Mem_Word: begin
                    // 字访问：数据不需要移动
                    align_write_data = data_in;
                end
                default: align_write_data = data_in;
            endcase
        end
    endfunction

    function [31:0] extract_read_data;
        input [2:0] mem_len;
        input [1:0] addr_low;
        input [31:0] rdata;
        begin
            case (mem_len)
                `Mem_Bit: begin
                    // 有符号字节：提取对应字节并进行符号扩展
                    case (addr_low)
                        2'b00: extract_read_data = {{24{rdata[7]}}, rdata[7:0]};
                        2'b01: extract_read_data = {{24{rdata[15]}}, rdata[15:8]};
                        2'b10: extract_read_data = {{24{rdata[23]}}, rdata[23:16]};
                        2'b11: extract_read_data = {{24{rdata[31]}}, rdata[31:24]};
                        default: extract_read_data = {{24{rdata[7]}}, rdata[7:0]};
                    endcase
                end
                `Mem_UBit: begin
                    // 无符号字节：提取对应字节并进行零扩展
                    case (addr_low)
                        2'b00: extract_read_data = {24'b0, rdata[7:0]};
                        2'b01: extract_read_data = {24'b0, rdata[15:8]};
                        2'b10: extract_read_data = {24'b0, rdata[23:16]};
                        2'b11: extract_read_data = {24'b0, rdata[31:24]};
                        default: extract_read_data = {24'b0, rdata[7:0]};
                    endcase
                end
                `Mem_Half: begin
                    // 有符号半字：提取对应半字并进行符号扩展
                    case (addr_low)
                        2'b00: extract_read_data = {{16{rdata[15]}}, rdata[15:0]};
                        2'b10: extract_read_data = {{16{rdata[31]}}, rdata[31:16]};
                        default: extract_read_data = {{16{rdata[15]}}, rdata[15:0]}; // 非对齐使用低半字
                    endcase
                end
                `Mem_UHalf: begin
                    // 无符号半字：提取对应半字并进行零扩展
                    case (addr_low)
                        2'b00: extract_read_data = {16'b0, rdata[15:0]};
                        2'b10: extract_read_data = {16'b0, rdata[31:16]};
                        default: extract_read_data = {16'b0, rdata[15:0]}; // 非对齐使用低半字
                    endcase
                end
                `Mem_Word: begin
                    // 字访问：直接使用全部数据
                    extract_read_data = rdata;
                end
                default: extract_read_data = rdata;
            endcase
        end
    endfunction

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

            mem_start_cycle <= 32'b0;
            mem_inst_type <= 32'd7;
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
                            // sram_wdata <= data_in;
                            sram_wdata <= align_write_data(MemLen, addr[1:0], data_in);
                            // sram_wvalid <= 1'b1;//发送sram写请求
                            // case(MemLen)
                            //     `Mem_Bit:  sram_wstrb <= 4'b0001;//sb
                            //     `Mem_Half: sram_wstrb <= 4'b0011;//sh
                            //     `Mem_Word: sram_wstrb <= 4'b1111;//sw
                            //     default:   sram_wstrb <= 4'b1111;
                            // endcase
                            sram_wstrb <= generate_aligned_wstrb(MemLen, addr[1:0]);
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
                    if(sram_arready && sram_arvalid) begin
                        sram_arvalid <= 1'b0;
                        //  $display("\033[31m[MEM]: READ_ADDR状态握手成功\033[0m");
                        sram_rready <= 1'b1;
                        next_state = READ_DATA;
                    end
                    else begin
                        next_state = READ_ADDR;
                    end
                end

                READ_DATA: begin
                    mem_ready <= 1'b0;
                    mem_valid <= 1'b0;
                    // sram_rready <= 1'b1;//准备接受数据
                    // $display("FUCKING ERROR IS HERE");
                    if(sram_rvalid && sram_rready) begin
                    `ifdef VERILATOR
                        counter(7, 0, 0, 1, 0);
                    `endif
                        // sram_arvalid <= 1'b0;
                        sram_rready <= 1'b0;
                        // $display("\033[31m[MEM]: READ_DATA状态握手成功\033[0m");
                        data_out <= extract_read_data(MemLen, addr[1:0], sram_rdata);
                        // case(MemLen)
                        //     `Mem_Bit:   data_out <= {{24{sram_rdata[7]}},sram_rdata[7:0]}; 
                        //     `Mem_UBit:  data_out <= {24'b0,sram_rdata[7:0]};
                        //     `Mem_UHalf: data_out <= {16'b0,sram_rdata[15:0]};
                        //     `Mem_Half:  data_out <= {{16{sram_rdata[15]}},sram_rdata[15:0]};
                        //     `Mem_Word:  data_out <= sram_rdata;
                        //     default:    data_out <= 32'h0;
                        // endcase
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
                        sram_awvalid <= 1'b0;//地址被接受，撤销awvalid信号
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
                        sram_wvalid <= 1'b0;
                        // sram_awvalid <= 1'b0;
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

                    mem_inst_type <= ex_inst_type;
                    mem_start_cycle <= ex_start_cycle;
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