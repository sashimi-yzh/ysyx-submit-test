// iverilog 四值仿真顶层：单独仿真 NPC
// 程序从 0x80000000 开始，存储器用 axi_mem 行为模型，$readmemh 初始化
`timescale 1ns/1ps
module tb_npc;
  reg clock = 1'b0;
  reg reset = 1'b1;
  always #0.625 clock = ~clock;          // 800MHz

  wire        m_awready, m_awvalid, m_wready, m_wvalid, m_bvalid, m_bready;
  wire        m_arready, m_arvalid, m_rvalid, m_rready;
  wire [31:0] m_awaddr, m_wdata, m_araddr, m_rdata;
  wire [3:0]  m_awid, m_bid, m_arid, m_rid, m_wstrb;
  wire [7:0]  m_awlen, m_arlen;
  wire [2:0]  m_awsize, m_arsize;
  wire [1:0]  m_awburst, m_arburst, m_bresp, m_rresp;
  wire        m_wlast, m_rlast;

  reg  s_awvalid = 1'b0, s_wvalid = 1'b0, s_bready = 1'b0, s_arvalid = 1'b0, s_rready = 1'b0;
  reg  [31:0] s_awaddr = 0, s_wdata = 0, s_araddr = 0;
  reg  [3:0]  s_awid = 0, s_wstrb = 0, s_arid = 0;
  reg  [7:0]  s_awlen = 0, s_arlen = 0;
  reg  [2:0]  s_awsize = 0, s_arsize = 0;
  reg  [1:0]  s_awburst = 0, s_arburst = 0;
  reg         s_wlast = 1'b0;
  wire        s_awready, s_wready, s_bvalid, s_arready, s_rvalid;
  wire [1:0]  s_bresp, s_rresp;
  wire [31:0] s_rdata;
  wire [3:0]  s_bid, s_rid;
  wire        s_rlast;

  ysyx_26030092 dut(
    .clock(clock), .reset(reset), .io_interrupt(1'b0),
    .io_master_awready(m_awready), .io_master_awvalid(m_awvalid), .io_master_awaddr(m_awaddr),
    .io_master_awid(m_awid), .io_master_awlen(m_awlen), .io_master_awsize(m_awsize),
    .io_master_awburst(m_awburst),
    .io_master_wready(m_wready), .io_master_wvalid(m_wvalid), .io_master_wdata(m_wdata),
    .io_master_wstrb(m_wstrb), .io_master_wlast(m_wlast),
    .io_master_bready(m_bready), .io_master_bvalid(m_bvalid), .io_master_bresp(m_bresp),
    .io_master_bid(m_bid),
    .io_master_arready(m_arready), .io_master_arvalid(m_arvalid), .io_master_araddr(m_araddr),
    .io_master_arid(m_arid), .io_master_arlen(m_arlen), .io_master_arsize(m_arsize),
    .io_master_arburst(m_arburst),
    .io_master_rready(m_rready), .io_master_rvalid(m_rvalid), .io_master_rresp(m_rresp),
    .io_master_rdata(m_rdata), .io_master_rid(m_rid), .io_master_rlast(m_rlast)
`ifndef NETLIST_SIM
    // 网表仿真时 yosys 会把没用的 slave 口优化掉
    ,.io_slave_awready(s_awready), .io_slave_awvalid(s_awvalid), .io_slave_awaddr(s_awaddr),
    .io_slave_awid(s_awid), .io_slave_awlen(s_awlen), .io_slave_awsize(s_awsize),
    .io_slave_awburst(s_awburst),
    .io_slave_wready(s_wready), .io_slave_wvalid(s_wvalid), .io_slave_wdata(s_wdata),
    .io_slave_wstrb(s_wstrb), .io_slave_wlast(s_wlast),
    .io_slave_bready(s_bready), .io_slave_bvalid(s_bvalid), .io_slave_bresp(s_bresp),
    .io_slave_bid(s_bid),
    .io_slave_arready(s_arready), .io_slave_arvalid(s_arvalid), .io_slave_araddr(s_araddr),
    .io_slave_arid(s_arid), .io_slave_arlen(s_arlen), .io_slave_arsize(s_arsize),
    .io_slave_arburst(s_arburst),
    .io_slave_rready(s_rready), .io_slave_rvalid(s_rvalid), .io_slave_rresp(s_rresp),
    .io_slave_rdata(s_rdata), .io_slave_rid(s_rid), .io_slave_rlast(s_rlast)
`endif
  );

  axi_mem mem(
    .clock(clock), .reset(reset),
    .awready(m_awready), .awvalid(m_awvalid), .awaddr(m_awaddr), .awid(m_awid),
    .awlen(m_awlen), .awsize(m_awsize), .awburst(m_awburst),
    .wready(m_wready), .wvalid(m_wvalid), .wdata(m_wdata), .wstrb(m_wstrb), .wlast(m_wlast),
    .bready(m_bready), .bvalid(m_bvalid), .bresp(m_bresp), .bid(m_bid),
    .arready(m_arready), .arvalid(m_arvalid), .araddr(m_araddr), .arid(m_arid),
    .arlen(m_arlen), .arsize(m_arsize), .arburst(m_arburst),
    .rready(m_rready), .rvalid(m_rvalid), .rresp(m_rresp), .rdata(m_rdata),
    .rid(m_rid), .rlast(m_rlast)
  );

  // ---- 装载程序镜像 ----
  reg [1023:0] hexfile;
  initial begin
    if ($value$plusargs("HEX=%s", hexfile)) begin
      $readmemh(hexfile, mem.mem);              // 运行时指定镜像，便于一次编译多次运行
    end else begin
`ifdef SIM_HEX
      $readmemh(`SIM_HEX, mem.mem);
`else
      $readmemh("img.hex", mem.mem);
`endif
    end
    $display("[iverilog] 已装载镜像，开始仿真");
    #20 reset = 1'b0;
  end


`ifndef NETLIST_SIM
  integer cycles = 0;
  integer max_cycles = 2000000;
  initial begin
    void'($value$plusargs("CYCLES=%d", max_cycles));
  end
  always @(posedge clock) begin
    cycles <= cycles + 1;
    if (!reset && dut.WBU_u.ebreak.ebreak_trap) begin
      $display("[iverilog] EBREAK: 程序结束, a0 = 0x%08x, pc = 0x%08x, cycles = %0d",
               dut.RFS_u.Reg_u.rf[10], dut.IFU_u.PC_reg.u.PC, cycles);
      $finish;
    end
    if (cycles > max_cycles) begin
      $display("[iverilog] TIMEOUT: 超过周期上限未结束 (cycles=%0d)", cycles);
      $finish;
    end
  end
`else

  integer cycles = 0;
  integer idle = 0;
  integer max_cycles = 2000000;
  initial begin
    void'($value$plusargs("CYCLES=%d", max_cycles));
  end
  wire axi_active = (m_arvalid & m_arready) | (m_awvalid & m_awready) |
                    (m_wvalid & m_wready) | (m_rvalid & m_rready) | (m_bvalid & m_bready);
  always @(posedge clock) begin
    cycles <= cycles + 1;
    idle <= axi_active ? 0 : idle + 1;
    if (cycles > max_cycles) begin
      $display("[iverilog] 网表仿真结束: 达到周期上限 %0d", cycles);
      $finish;
    end
    if (idle > 200000) begin
      $display("[iverilog] 网表仿真结束: AXI 已静止 %0d 拍（程序已停）, 总 %0d 拍", idle, cycles);
      $finish;
    end
  end
`endif
endmodule
