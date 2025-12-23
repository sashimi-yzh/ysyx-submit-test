module tb_top();

reg clock = 1;
reg reset = 1;

always #5 clock = ~clock;

initial begin
		repeat (100) @(posedge clock);
		reset <= 0;
end

initial begin
	// $dumpfile("/home/yangpengcheng/ysyx/ysyx/ysyx-workbench/npc-chisel-soc/single_cycle_riscv32i/iverilog/wave/top.vcd");
	// $dumpvars(0, tb_top);
	// repeat (1000000) @(posedge clock);
	// $display("TIMEOUT");
	// $finish;
end


reg [1023:0] hex_file;
initial begin
    hex_file = "./iverilog/hex/code.hex";
    $readmemh(hex_file, u_Mem.memory);
end




// 检测退出
`ifndef NETLIST
always @(posedge clock) begin
    if(cpu.core.wbu.io_pipe_out_valid && cpu.core.idu.ebreak.isEbreak) begin
        if(cpu.core.isu.gpr_ext.Memory[10] == 32'h0) begin
            $display("hit good trap!");
            $finish();
        end
        else begin
            $display("hit bad trap!");
            $finish();
        end
    end
end
`endif


wire        auto_master_out_awready;
wire        auto_master_out_awvalid;
wire [3:0]  auto_master_out_awid;//
wire [31:0] auto_master_out_awaddr;
wire [7:0]  auto_master_out_awlen;//
wire [2:0]  auto_master_out_awsize;//
wire [1:0]  auto_master_out_awburst;//
wire        auto_master_out_wready;
wire        auto_master_out_wvalid;
wire [31:0] auto_master_out_wdata;
wire [3:0]  auto_master_out_wstrb;
wire        auto_master_out_wlast;//
wire        auto_master_out_bready;
wire        auto_master_out_bvalid;
wire [3:0]  auto_master_out_bid;//
wire [1:0]  auto_master_out_bresp;//
wire        auto_master_out_arready;
wire        auto_master_out_arvalid;
wire [3:0]  auto_master_out_arid;//
wire [31:0] auto_master_out_araddr;
wire [7:0]  auto_master_out_arlen;//
wire [2:0]  auto_master_out_arsize;//
wire [1:0]  auto_master_out_arburst;//
wire        auto_master_out_rready;
wire        auto_master_out_rvalid;
wire [3:0]  auto_master_out_rid;//
wire [31:0] auto_master_out_rdata;
wire [1:0]  auto_master_out_rresp;//
wire        auto_master_out_rlast;//

ysyx_24080032 cpu (
    .clock                          (clock                      ),
    .reset                          (reset                      ),
    .io_interrupt                   (1'h0                       ),
    .io_master_awready              (auto_master_out_awready    ),
    .io_master_awvalid              (auto_master_out_awvalid    ),
    .io_master_awid                 (auto_master_out_awid       ),
    .io_master_awaddr               (auto_master_out_awaddr     ),
    .io_master_awlen                (auto_master_out_awlen      ),
    .io_master_awsize               (auto_master_out_awsize     ),
    .io_master_awburst              (auto_master_out_awburst    ),
    .io_master_wready               (auto_master_out_wready     ),
    .io_master_wvalid               (auto_master_out_wvalid     ),
    .io_master_wdata                (auto_master_out_wdata      ),
    .io_master_wstrb                (auto_master_out_wstrb      ),
    .io_master_wlast                (auto_master_out_wlast      ),
    .io_master_bready               (auto_master_out_bready     ),
    .io_master_bvalid               (auto_master_out_bvalid     ),
    .io_master_bid                  (4'b0000                    ),
    .io_master_bresp                (2'b00                      ),
    .io_master_arready              (auto_master_out_arready    ),
    .io_master_arvalid              (auto_master_out_arvalid    ),
    .io_master_arid                 (auto_master_out_arid       ),
    .io_master_araddr               (auto_master_out_araddr     ),
    .io_master_arlen                (auto_master_out_arlen      ),
    .io_master_arsize               (auto_master_out_arsize     ),
    .io_master_arburst              (auto_master_out_arburst    ),
    .io_master_rready               (auto_master_out_rready     ),
    .io_master_rvalid               (auto_master_out_rvalid     ),
    .io_master_rid                  (4'b0000                    ),
    .io_master_rdata                (auto_master_out_rdata      ),
    .io_master_rresp                (2'b00                      ),
    .io_master_rlast                (1'b1                       ),
    .io_slave_awready               (/* unused */               ),
    .io_slave_awvalid               (1'h0                       ),
    .io_slave_awid                  (4'h0                       ),
    .io_slave_awaddr                (32'h0                      ),
    .io_slave_awlen                 (8'h0                       ),
    .io_slave_awsize                (3'h0                       ),
    .io_slave_awburst               (2'h0                       ),
    .io_slave_wready                (/* unused */               ),
    .io_slave_wvalid                (1'h0                       ),
    .io_slave_wdata                 (32'h0                      ),
    .io_slave_wstrb                 (4'h0                       ),
    .io_slave_wlast                 (1'h0                       ),
    .io_slave_bready                (1'h0                       ),
    .io_slave_bvalid                (/* unused */               ),
    .io_slave_bid                   (/* unused */               ),
    .io_slave_bresp                 (/* unused */               ),
    .io_slave_arready               (/* unused */               ),
    .io_slave_arvalid               (1'h0                       ),
    .io_slave_arid                  (4'h0                       ),
    .io_slave_araddr                (32'h0                      ),
    .io_slave_arlen                 (8'h0                       ),
    .io_slave_arsize                (3'h0                       ),
    .io_slave_arburst               (2'h0                       ),
    .io_slave_rready                (1'h0                       ),
    .io_slave_rvalid                (/* unused */               ),
    .io_slave_rid                   (/* unused */               ),
    .io_slave_rdata                 (/* unused */               ),
    .io_slave_rresp                 (/* unused */               ),
    .io_slave_rlast                 (/* unused */               )
);

wire [31:0] araddr_shift;
assign araddr_shift = auto_master_out_araddr >> 28;
wire [31:0] awaddr_shift;
assign awaddr_shift = auto_master_out_awaddr >> 28;

wire [31:0] araddr_pro;
assign araddr_pro = araddr_shift == 32'ha ? auto_master_out_araddr : (auto_master_out_araddr - (araddr_shift << 28));
wire [31:0] awaddr_pro;
assign awaddr_pro = awaddr_shift == 32'ha ? auto_master_out_awaddr : (auto_master_out_awaddr - (awaddr_shift << 28));

Mem u_Mem (
        .clk                            (clock                     ),
        // AW Channel
        .mem_axi_awvalid                (auto_master_out_awvalid   ),
        .mem_axi_awready                (auto_master_out_awready   ),
        .mem_axi_awaddr                 (awaddr_pro                ),
        .mem_axi_awprot                 (3'b000                    ),

        // W Channel
        .mem_axi_wvalid                 (auto_master_out_wvalid    ),
        .mem_axi_wready                 (auto_master_out_wready    ),
        .mem_axi_wdata                  (auto_master_out_wdata     ),
        .mem_axi_wstrb                  (auto_master_out_wstrb     ),

        // B Channel
        .mem_axi_bvalid                 (auto_master_out_bvalid    ),
        .mem_axi_bready                 (auto_master_out_bready    ),

        // AR Channel
        .mem_axi_arvalid                (auto_master_out_arvalid   ),
        .mem_axi_arready                (auto_master_out_arready   ),
        .mem_axi_araddr                 (araddr_pro                ),
        .mem_axi_arprot                 (3'b100                    ),

        // R Channel
        .mem_axi_rvalid                 (auto_master_out_rvalid    ),
        .mem_axi_rready                 (auto_master_out_rready    ),
        .mem_axi_rdata                  (auto_master_out_rdata     )
);

endmodule