/**
    使用DPI-C进行内存读写
*/
module ysyx_24100006_mem(
    input               clk,
    input               reset,

    // axi 写入和读取地址
    input [31:0]        axi_araddr,
    input [31:0]        axi_awaddr,
    // axi 写入数据和写入使用的掩码
    input [31:0]        axi_wdata,
    input [3:0]         axi_wstrb,

    // axi控制信号
    // read data addr
    input               axi_arvalid,
    output  reg         axi_arready,
    // read data
    input               axi_rready,
    output  reg         axi_rvalid,
    // write data addr
	input               axi_awvalid,
	output  reg         axi_awready,
	// write data
	input               axi_wvalid,
	output  reg         axi_wready,
	// response
    input               axi_bready,
	output  reg         axi_bvalid,
    output  reg [1:0]   axi_bresp,

    // axi 读取的回应
    output  reg [1:0]   axi_rresp,
    output  reg [31:0]  axi_rdata,

    // 新增信号
    input   [7:0]       axi_arlen,
    input   [2:0]       axi_arsize,
    output  reg         axi_rlast,
    input   [7:0]       axi_awlen,
    input   [2:0]       axi_awsize,
    input               axi_wlast
    
);

`ifdef __ICARUS__
    // ------------------------------
    // Icarus: 纯 Verilog 行为内存
    // ------------------------------
    localparam BASE_ADDR = 32'h8000_0000;
    localparam MEM_BYTES = 256*1024*1024;   // 16MB
    reg [7:0] mem [0:MEM_BYTES-1];         // 字节寻址

    // 运行时通过 +img=xxx.hex 指定镜像；默认 "program.hex"
    string IMG;
    initial begin
        if (!$value$plusargs("img=%s", IMG)) IMG = "program.hex";
        $display("[mem] loading image: %0s", IMG);
        // 注意：objcopy 需 --adjust-vma -0x80000000 让地址从 0 开始
        $readmemh(IMG, mem);
    end

    // 内部信号用于直接内存访问
    reg [31:0] mem_read_data;
    reg [31:0] mem_idx;
`else
    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata,input byte wmask);
`endif

    parameter   S_IDLE          = 0,
                S_READ_ADDR     = 1, 
                S_READ_DATA     = 2, 
                S_WRITE_ADDR    = 3, 
                S_WRITE_DATA    = 4, 
                S_WRITE_RESP    = 5;


    reg [3:0] state;

    // 突发读取相关寄存器
    reg [31:0]  current_raddr;   // 当前读取地址
    reg [7:0]   burst_counter;   // 突发计数器
    reg [7:0]   burst_length;    // 突发长度

    always @(posedge clk) begin
        if(reset) begin
            state           <= S_IDLE;
            axi_arready     <= 1'b0;
            axi_awready     <= 1'b0;
            axi_wready      <= 1'b0;
            axi_rvalid      <= 1'b0;
            axi_bvalid      <= 1'b0;
            axi_rlast       <= 1'b0;
            axi_rdata       <= 32'h00000000;

            // 突发相关复位
            burst_counter   <= 8'b0;
            burst_length    <= 8'b0;
            current_raddr   <= 32'b0;
        end else begin
            case(state)
                S_IDLE: begin
                    axi_rlast           <= 1'b0;  // 确保rlast在空闲状态为低
                    if(axi_arvalid == 1'b1) begin
                        axi_arready     <= 1'b1;
                        state           <= S_READ_ADDR;
                    end else if(axi_awvalid == 1'b1 && axi_wvalid == 1'b1) begin
                        axi_awready     <= 1'b1;
                        axi_wready      <= 1'b1;
                        state           <= S_WRITE_ADDR;
                    end
                end
                S_READ_ADDR: begin
                    axi_arready         <= 1'b0;
                    if(axi_arvalid == 1'b1 && axi_arready == 1'b1) begin
                        // 锁存地址和突发参数
                        current_raddr   <= axi_araddr & (~32'd3) ;
                        burst_length    <= axi_arlen;
                        burst_counter   <= 8'b0;
                        
                        axi_rvalid      <= 1'b1;
`ifdef __ICARUS__
                        if (axi_araddr >= BASE_ADDR && axi_araddr < BASE_ADDR + MEM_BYTES - 3) begin
                            mem_idx = axi_araddr & (~32'd3)  - BASE_ADDR;
                            axi_rdata <= {mem[mem_idx+3], mem[mem_idx+2], mem[mem_idx+1], mem[mem_idx+0]};
                        end else begin
                            axi_rdata <= 32'h0;
                        end
`else
                        // 读取第一个数据
                        axi_rdata       <= pmem_read(axi_araddr);
`endif
                        // 检查是否是单次传输
                        if (axi_arlen == 8'b0) begin
                            axi_rlast   <= 1'b1;
                        end

                        state           <= S_READ_DATA;
                    end
                end
                S_READ_DATA: begin
                    if(axi_rready == 1'b1 && axi_rvalid == 1'b1) begin
                        // 完成当前数据传输
                        burst_counter       <= burst_counter + 1;

                        // 检查是否达到突发长度
                        if (burst_counter == burst_length) begin
                            // 突发结束
                            axi_rvalid      <= 1'b0;
                            axi_rlast       <= 1'b0;
                            state           <= S_IDLE;
                        end else begin
                            // 递增地址 (假设递增突发)
                            current_raddr   <= current_raddr + 4; // 4字节递增
                            
`ifdef __ICARUS__
                            if (current_raddr + 4 >= BASE_ADDR && current_raddr + 4 < BASE_ADDR + MEM_BYTES - 3) begin
                                mem_idx = current_raddr + 4 - BASE_ADDR;
                                axi_rdata <= {mem[mem_idx+3], mem[mem_idx+2], mem[mem_idx+1], mem[mem_idx+0]};
                            end else begin
                                axi_rdata <= 32'h0;
                            end
`else
                            // 读取下一个数据
                            axi_rdata       <= pmem_read(current_raddr + 4);
`endif

                            // 检查是否是最后一个数据
                            if (burst_counter == burst_length - 1) begin
                                axi_rlast   <= 1'b1;
                            end
                        end
                    end
                end
                // 写入地址握手和数据握手放在一起
                S_WRITE_ADDR: begin
                    axi_awready         <= 1'b0;
                    axi_wready          <= 1'b0;
                    if(axi_awvalid == 1'b1 && axi_awready == 1'b1 && axi_wvalid == 1'b1 && axi_wready == 1'b1) begin
`ifdef __ICARUS__
                        if (axi_awaddr >= BASE_ADDR && axi_awaddr < BASE_ADDR + MEM_BYTES - 3) begin
                            mem_idx = axi_awaddr & (~32'd3)  - BASE_ADDR;
                            if (axi_wstrb[0]) mem[mem_idx+0] <= axi_wdata[7:0];
                            if (axi_wstrb[1]) mem[mem_idx+1] <= axi_wdata[15:8];
                            if (axi_wstrb[2]) mem[mem_idx+2] <= axi_wdata[23:16];
                            if (axi_wstrb[3]) mem[mem_idx+3] <= axi_wdata[31:24];
                        end
`else
                        // 写入数据
                        pmem_write(axi_awaddr,axi_wdata,{4'b0, axi_wstrb});
`endif
                        axi_bvalid      <= 1'b1;
                        axi_bresp       <= 2'b00;
                        state           <= S_WRITE_RESP;
                    end
                end
                S_WRITE_RESP: begin
                    if(axi_bready == 1'b1 && axi_bvalid == 1'b1)begin
                        axi_bvalid      <= 1'b0;
                        state           <= S_IDLE;
                    end
                end

                default: state          <= S_IDLE;
            endcase
        end
    end


endmodule

