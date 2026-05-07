`timescale 1ps/1ps

module sram #(
    parameter MEM_BASE = 32'h8000_0000,
    parameter CPU_WIDTH = 32,
    parameter R_DELAY = 1,
    parameter W_DELAY = 1,
    parameter MEM_SIZE = 2**20         // 1MB
)(
    input clk,
    input rst_n,

    input [CPU_WIDTH-1:0] araddr_i,
    input [3:0] arid_i,
    input [7:0] arlen_i,
    input [2:0] arsize_i,
    input [1:0] arburst_i,
    input arvalid_i,
    output reg arready_o,

    output reg [CPU_WIDTH-1:0] rdata_o,
    output reg [1:0] rresp_o,
    output reg rlast_o,
    output reg [3:0] rid_o,
    output reg rvalid_o,
    input rready_i,

    input [CPU_WIDTH-1:0] awaddr_i,
    input [3:0] awid_i,
    input [7:0] awlen_i,
    input [2:0] awsize_i,
    input [1:0] awburst_i,
    input awvalid_i,
    output reg awready_o,

    input [CPU_WIDTH-1:0] wdata_i,
    input [3:0] wstrb_i,
    input wlast_i,
    input wvalid_i,
    output reg wready_o,

    output reg [1:0] bresp_o,
    output reg [3:0] bid_o,
    output reg bvalid_o,
    input bready_i
);

    // ============ 内存定义 ============
    reg [7:0] mem [0:2**17-1];  // 1MB 字节寻址内存，按需调整大小
    // 在模块顶部声明
    reg [63:0] sim_time_us;

    reg ar_state;
    reg r_state;
    reg aw_state;
    reg w_state;
    reg b_state;
    reg [CPU_WIDTH-1:0] araddr;
    reg [CPU_WIDTH-1:0] awaddr;
    reg [CPU_WIDTH-1:0] wdata;
    reg [3:0] wstrb;
    reg wvalid;
    reg flag_waddr,flag_wdata,flag_rdata,flag_raddr,flag_write;
    reg [4:0] rdata_counter,wdata_counter,w_delay,r_delay;
    reg [4:0] LFSR;
    reg lfsr_in;
    reg [1:0] write_box;

    assign rid_o = 0;
    assign bid_o = 0;

    // 字对齐地址（去掉低2位）
    wire [19:0] rd_base = {araddr[31:2], 2'b00} - MEM_BASE;  // 低2位清零，字对齐
    wire [19:0] wr_base = {awaddr[31:2], 2'b00} - MEM_BASE;  // 低2位清零，字对齐

    wire write_uart;
    assign write_uart = (awaddr==32'ha00003f8);

    // ============ AR 通道 ============
    always@(posedge clk, negedge rst_n) begin
        if(rst_n == 0) begin
            arready_o <= 0;
            ar_state <= 0;
            araddr <= 0;
        end
        else begin
            if(ar_state == 0 && arvalid_i == 1) begin
                arready_o <= 1;
                ar_state <= 1;
            end
            else if(ar_state == 1) begin
                if(arvalid_i == 0) ar_state <= 0;
                arready_o <= 0;
            end

            if(arready_o == 1 && arvalid_i == 1) begin
                araddr <= araddr_i;
                flag_raddr <= 1;
            end
            else 
                flag_raddr <= 0;
        end
    end
    
    // ============ R 通道 — 用 mem[] 读取 ============
    always@(posedge clk, negedge rst_n) begin
        if(rst_n == 0) begin
            r_state <= 0;
            rvalid_o <= 0;
            rdata_counter <= 0;
            flag_rdata <= 0;
            rlast_o <= 0;
        end
        else begin
            if(flag_raddr == 1) flag_rdata <= 1;
            else if(flag_rdata == 1) begin
                // ==== 替换 pmem_read：小端序拼接4字节 ====
                rdata_o <= {mem[rd_base+3], mem[rd_base+2],
                            mem[rd_base+1], mem[rd_base+0]};

                rresp_o <= 2'b00;
                rlast_o <= 1;
                rvalid_o <= 1;
                flag_rdata <= 0;
                
            end
            else begin
                rvalid_o <= 0;
                rdata_counter <= 0;
                rresp_o <= 2'b10;
                rlast_o <= 0;
            end
        end
    end

    // ============ AW 通道 ============
    always@(posedge clk, negedge rst_n) begin
        if(rst_n == 0) begin
            awready_o <= 0;
            aw_state <= 0;
            awaddr <= 0;
            flag_waddr <= 0;
        end
        else begin
            if(aw_state == 0 && awvalid_i == 1) begin
                awready_o <= 1;
                aw_state <= 1;
            end
            else if(aw_state == 1) begin
                if(awvalid_i == 0) aw_state <= 0;
                awready_o <= 0;
            end

            if(awready_o == 1 && awvalid_i == 1) begin
                awaddr <= awaddr_i;
                flag_waddr <= 1; 
            end 
            else if(bresp_o == 0) begin
                flag_waddr <= 0;
            end else flag_waddr <= 0;
        end
    end

    // ============ W 通道 ============
    always@(posedge clk, negedge rst_n) begin
        if(rst_n == 0) begin
            wready_o <= 0;
            w_state <= 0;
            wdata <= 0;
            wstrb <= 0;
            flag_wdata <= 0;
        end
        else begin
            if(w_state == 0 && wvalid_i == 1) begin
                wready_o <= 1;
                w_state <= 1;
            end else if(w_state == 1) begin
                if(wvalid_i == 0) w_state <= 0;
                wready_o <= 0;
            end

            if(bresp_o == 0) 
                flag_wdata <= 0;
            else if(wready_o == 1 && wvalid_i == 1) begin
                wdata <= wdata_i;
                wstrb <= wstrb_i;
                flag_wdata <= 1;
            end else flag_wdata <= 0;
        end
    end

    // ============ B 通道 — 用 mem[] 写入（带 wstrb 掩码） ============
    always@(posedge clk, negedge rst_n) begin
        if(rst_n == 0) begin
            bresp_o <= 2'b10;
            bvalid_o <= 0;
            wdata_counter <= 0;
        end
        else begin 
            if(flag_waddr == 1) write_box[0] <= 1;
            if(flag_wdata == 1) write_box[1] <= 1;

            if(write_box == 2'b11) begin
                // ==== 替换 pmem_write：按 wstrb 逐字节写入 ====
                if(write_uart) begin
                    $write("%c", wdata[7:0]);
                    //$fflush();
                end
                else begin
                    if(wstrb[0]) mem[wr_base+0] <= wdata[ 7: 0];
                    if(wstrb[1]) mem[wr_base+1] <= wdata[15: 8];
                    if(wstrb[2]) mem[wr_base+2] <= wdata[23:16];
                    if(wstrb[3]) mem[wr_base+3] <= wdata[31:24];
                end
                bresp_o <= 0;
                bvalid_o <= 1;
                write_box <= 0;
                
            end else begin
                bresp_o <= 2'b10;
                bvalid_o <= 0;
            end
        end
    end

    // 加载程序
    integer i;
    initial begin
        //for (i = 0; i < MEM_SIZE; i = i + 1) mem[i] = 8'h0;
        $readmemh("mem.hex", mem);
    end
    
   

endmodule

module sim_top;

    reg clk = 0;
    reg rst = 1;

    always #1 clk = ~clk;

    // AXI4 信号
    // AW 通道
    wire        awvalid;
    wire [31:0] awaddr;
    wire [3:0]  awid;
    wire [7:0]  awlen;
    wire [2:0]  awsize;
    wire [1:0]  awburst;
    reg         awready;

    // W 通道
    wire        wvalid;
    wire [31:0] wdata;
    wire [3:0]  wstrb;
    wire        wlast;
    reg         wready;

    // B 通道
    reg         bvalid;
    reg  [1:0]  bresp;
    reg  [3:0]  bid;
    wire        bready;

    // AR 通道
    wire        arvalid;
    wire [31:0] araddr;
    wire [3:0]  arid;
    wire [7:0]  arlen;
    wire [2:0]  arsize;
    wire [1:0]  arburst;
    reg         arready;

    // R 通道
    reg         rvalid;
    reg  [1:0]  rresp;
    reg  [31:0] rdata;
    reg         rlast;
    reg  [3:0]  rid;
    wire        rready;

    // 实例化处理器
    ysyx_25050137 u_cpu(
        .clock              (clk),
        .reset              (rst),
        .io_interrupt       (1'b0),
        // master 端口
        .io_master_awready  (awready),
        .io_master_awvalid  (awvalid),
        .io_master_awaddr   (awaddr),
        .io_master_awid     (awid),
        .io_master_awlen    (awlen),
        .io_master_awsize   (awsize),
        .io_master_awburst  (awburst),
        .io_master_wready   (wready),
        .io_master_wvalid   (wvalid),
        .io_master_wdata    (wdata),
        .io_master_wstrb    (wstrb),
        .io_master_wlast    (wlast),
        .io_master_bready   (bready),
        .io_master_bvalid   (bvalid),
        .io_master_bresp    (bresp),
        .io_master_bid      (bid),
        .io_master_arready  (arready),
        .io_master_arvalid  (arvalid),
        .io_master_araddr   (araddr),
        .io_master_arid     (arid),
        .io_master_arlen    (arlen),
        .io_master_arsize   (arsize),
        .io_master_arburst  (arburst),
        .io_master_rready   (rready),
        .io_master_rvalid   (rvalid),
        .io_master_rresp    (rresp),
        .io_master_rdata    (rdata),
        .io_master_rlast    (rlast),
        .io_master_rid      (rid),
        // slave 端口 (未使用，绑定默认值)
        .io_slave_awready   (),
        .io_slave_awvalid   (1'b0),
        .io_slave_awaddr    (32'b0),
        .io_slave_awid      (4'b0),
        .io_slave_awlen     (8'b0),
        .io_slave_awsize    (3'b0),
        .io_slave_awburst   (2'b0),
        .io_slave_wready    (),
        .io_slave_wvalid    (1'b0),
        .io_slave_wdata     (32'b0),
        .io_slave_wstrb     (4'b0),
        .io_slave_wlast     (1'b0),
        .io_slave_bready    (1'b0),
        .io_slave_bvalid    (),
        .io_slave_bresp     (),
        .io_slave_bid       (),
        .io_slave_arready   (),
        .io_slave_arvalid   (1'b0),
        .io_slave_araddr    (32'b0),
        .io_slave_arid      (4'b0),
        .io_slave_arlen     (8'b0),
        .io_slave_arsize    (3'b0),
        .io_slave_arburst   (2'b0),
        .io_slave_rready    (1'b0),
        .io_slave_rvalid    (),
        .io_slave_rresp     (),
        .io_slave_rdata     (),
        .io_slave_rlast     (),
        .io_slave_rid       ()
    );

    sram u_sram(
        .clk        (clk        ),
        .rst_n      (!rst      ),

        // AR channel
        .araddr_i   (araddr     ),
        .arid_i     (arid       ),
        .arlen_i    (arlen      ),
        .arsize_i   (arsize     ),
        .arburst_i  (arburst    ),
        .arvalid_i  (arvalid    ),
        .arready_o  (arready    ),

        // R channel
        .rdata_o    (rdata      ),
        .rresp_o    (rresp      ),
        .rlast_o    (rlast      ),
        .rid_o      (rid        ),
        .rvalid_o   (rvalid     ),
        .rready_i   (rready     ),

        // AW channel
        .awaddr_i   (awaddr     ),
        .awid_i     (awid       ),
        .awlen_i    (awlen      ),
        .awsize_i   (awsize     ),
        .awburst_i  (awburst    ),
        .awvalid_i  (awvalid    ),
        .awready_o  (awready    ),

        // W channel
        .wdata_i    (wdata      ),
        .wstrb_i    (wstrb      ),
        .wlast_i    (wlast      ),
        .wvalid_i   (wvalid     ),
        .wready_o   (wready     ),

        // B channel
        .bresp_o    (bresp      ),
        .bid_o      (bid        ),
        .bvalid_o   (bvalid     ),
        .bready_i   (bready     )
    );

    //initial
    ///begin            
    //    $dumpfile("wave.vcd");        //生成的vcd文件名称
    //    $dumpvars(0, sim_top);    //tb模块名称
    //end

    // ---------- 控制 ----------
    initial begin
        rst = 1;
        #10;
        rst = 0;
        //#1000000000; // 超时退出
        //$display("TIMEOUT");
        //$finish;
    end

//`ifdef __ICARUS__
    // 路径根据你的层级: sim_top -> u_cpu -> Rgefile -> regs
//    always@(*) begin       
//        if(u_cpu.inst_ifu_to_idu == 32'h00100073) begin
//            $display("EBREAK hit!");
//            $display("  a0 (x10) = 0x%h", u_cpu.Rgefile.regs[10]);
//            $display("  PC (IFU) = 0x%h", u_cpu.pc_ifu_to_idu);
//            $display("  ra (x1) = 0x%h", u_cpu.Rgefile.regs[1]);
 //           $finish;
 //       end
 //   end
//`endif

endmodule