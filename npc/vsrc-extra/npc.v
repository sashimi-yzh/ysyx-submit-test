module npc (
    input clock,
    input reset
);

  // 暂时不处理外部中断，拉低
  wire        io_interrupt = 1'b0;

  // -----------------------------
  // AXI master 侧信号声明（从 axi_memory 输出）
  // -----------------------------
  wire        io_master_awready;
  wire        io_master_wready;
  wire        io_master_arready;
  wire        io_master_rvalid;
  wire [ 1:0] io_master_rresp;
  wire [31:0] io_master_rdata;
  wire        io_master_rlast;
  wire        io_master_bvalid;
  wire [ 1:0] io_master_bresp;
  wire [ 3:0] io_master_bid;
  wire [ 3:0] io_master_rid;  // 修复：添加rid信号

  // -----------------------------
  // AXI master 侧：来自 core 的输出（wire）
  // -----------------------------
  wire        io_master_awvalid;
  wire [31:0] io_master_awaddr;
  wire [ 3:0] io_master_awid;
  wire [ 7:0] io_master_awlen;
  wire [ 2:0] io_master_awsize;
  wire [ 1:0] io_master_awburst;

  wire        io_master_wvalid;
  wire [31:0] io_master_wdata;
  wire [ 3:0] io_master_wstrb;
  wire        io_master_wlast;

  wire        io_master_bready;

  wire        io_master_arvalid;
  wire [31:0] io_master_araddr;
  wire [ 3:0] io_master_arid;
  wire [ 7:0] io_master_arlen;
  wire [ 2:0] io_master_arsize;
  wire [ 1:0] io_master_arburst;

  wire        io_master_rready;

  // -----------------------------
  // AXI slave 侧：给 ysyx_24100007 的输入，先全部拉 0
  // -----------------------------
  reg         io_slave_awvalid;
  reg  [31:0] io_slave_awaddr;
  reg  [ 3:0] io_slave_awid;
  reg  [ 7:0] io_slave_awlen;
  reg  [ 2:0] io_slave_awsize;
  reg  [ 1:0] io_slave_awburst;

  reg         io_slave_wvalid;
  reg  [31:0] io_slave_wdata;
  reg  [ 3:0] io_slave_wstrb;
  reg         io_slave_wlast;

  reg         io_slave_bready;

  reg         io_slave_arvalid;
  reg  [31:0] io_slave_araddr;
  reg  [ 3:0] io_slave_arid;
  reg  [ 7:0] io_slave_arlen;
  reg  [ 2:0] io_slave_arsize;
  reg  [ 1:0] io_slave_arburst;

  reg         io_slave_rready;

  // -----------------------------
  // 打桩的简单初始化逻辑
  // -----------------------------
  always @(posedge clock or posedge reset) begin
    if (reset) begin
      // slave 侧输入全部清零
      io_slave_awvalid <= 1'b0;
      io_slave_awaddr  <= 32'b0;
      io_slave_awid    <= 4'b0;
      io_slave_awlen   <= 8'b0;
      io_slave_awsize  <= 3'b0;
      io_slave_awburst <= 2'b0;

      io_slave_wvalid  <= 1'b0;
      io_slave_wdata   <= 32'b0;
      io_slave_wstrb   <= 4'b0;
      io_slave_wlast   <= 1'b0;

      io_slave_bready  <= 1'b0;

      io_slave_arvalid <= 1'b0;
      io_slave_araddr  <= 32'b0;
      io_slave_arid    <= 4'b0;
      io_slave_arlen   <= 8'b0;
      io_slave_arsize  <= 3'b0;
      io_slave_arburst <= 2'b0;

      io_slave_rready  <= 1'b0;
    end else begin
      io_slave_awvalid <= io_slave_awvalid;
      io_slave_awaddr  <= io_slave_awaddr;
      io_slave_awid    <= io_slave_awid;
      io_slave_awlen   <= io_slave_awlen;
      io_slave_awsize  <= io_slave_awsize;
      io_slave_awburst <= io_slave_awburst;

      io_slave_wvalid  <= io_slave_wvalid;
      io_slave_wdata   <= io_slave_wdata;
      io_slave_wstrb   <= io_slave_wstrb;
      io_slave_wlast   <= io_slave_wlast;

      io_slave_bready  <= io_slave_bready;

      io_slave_arvalid <= io_slave_arvalid;
      io_slave_araddr  <= io_slave_araddr;
      io_slave_arid    <= io_slave_arid;
      io_slave_arlen   <= io_slave_arlen;
      io_slave_arsize  <= io_slave_arsize;
      io_slave_arburst <= io_slave_arburst;

      io_slave_rready  <= io_slave_rready;
    end
  end

  wire        io_slave_awready;
  wire        io_slave_wready;
  wire        io_slave_bvalid;
  wire [ 1:0] io_slave_bresp;
  wire [ 3:0] io_slave_bid;
  wire        io_slave_arready;
  wire        io_slave_rvalid;
  wire [ 1:0] io_slave_rresp;
  wire [31:0] io_slave_rdata;
  wire        io_slave_rlast;
  wire [ 3:0] io_slave_rid;



  ysyx_24100007 u_core (
      .clock       (clock),
      .reset       (reset),
      .io_interrupt(io_interrupt),

      .io_master_awready(io_master_awready),
      .io_master_awvalid(io_master_awvalid),
      .io_master_awaddr (io_master_awaddr),
      .io_master_awid   (io_master_awid),
      .io_master_awlen  (io_master_awlen),
      .io_master_awsize (io_master_awsize),
      .io_master_awburst(io_master_awburst),

      .io_master_wready(io_master_wready),
      .io_master_wvalid(io_master_wvalid),
      .io_master_wdata (io_master_wdata),
      .io_master_wstrb (io_master_wstrb),
      .io_master_wlast (io_master_wlast),

      .io_master_bready(io_master_bready),
      .io_master_bvalid(io_master_bvalid),
      .io_master_bresp (io_master_bresp),
      .io_master_bid   (io_master_bid),

      .io_master_arready(io_master_arready),
      .io_master_arvalid(io_master_arvalid),
      .io_master_araddr (io_master_araddr),
      .io_master_arid   (io_master_arid),
      .io_master_arlen  (io_master_arlen),
      .io_master_arsize (io_master_arsize),
      .io_master_arburst(io_master_arburst),

      .io_master_rready(io_master_rready),
      .io_master_rvalid(io_master_rvalid),
      .io_master_rresp (io_master_rresp),
      .io_master_rdata (io_master_rdata),
      .io_master_rlast (io_master_rlast),
      .io_master_rid   (io_master_rid),     // 修复：使用io_master_rid而不是io_master_bid

      .io_slave_awready(io_slave_awready),
      .io_slave_awvalid(io_slave_awvalid),
      .io_slave_awaddr (io_slave_awaddr),
      .io_slave_awid   (io_slave_awid),
      .io_slave_awlen  (io_slave_awlen),
      .io_slave_awsize (io_slave_awsize),
      .io_slave_awburst(io_slave_awburst),

      .io_slave_wready(io_slave_wready),
      .io_slave_wvalid(io_slave_wvalid),
      .io_slave_wdata (io_slave_wdata),
      .io_slave_wstrb (io_slave_wstrb),
      .io_slave_wlast (io_slave_wlast),

      .io_slave_bready(io_slave_bready),
      .io_slave_bvalid(io_slave_bvalid),
      .io_slave_bresp (io_slave_bresp),
      .io_slave_bid   (io_slave_bid),

      .io_slave_arready(io_slave_arready),
      .io_slave_arvalid(io_slave_arvalid),
      .io_slave_araddr (io_slave_araddr),
      .io_slave_arid   (io_slave_arid),
      .io_slave_arlen  (io_slave_arlen),
      .io_slave_arsize (io_slave_arsize),
      .io_slave_arburst(io_slave_arburst),

      .io_slave_rready(io_slave_rready),
      .io_slave_rvalid(io_slave_rvalid),
      .io_slave_rresp (io_slave_rresp),
      .io_slave_rdata (io_slave_rdata),
      .io_slave_rlast (io_slave_rlast),
      .io_slave_rid   (io_slave_rid)
  );

  // -----------------------------
  // 实例化 axi_memory 模块
  // -----------------------------
  axi_memory u_memory (
      .clk(clock),
      .rst(reset),

      // Write Address Channel
      .io_awready(io_master_awready),
      .io_awvalid(io_master_awvalid),
      .io_awaddr (io_master_awaddr),
      .io_awid   (io_master_awid),
      .io_awlen  (io_master_awlen),
      .io_awsize (io_master_awsize),
      .io_awburst(io_master_awburst),

      // Write Data Channel
      .io_wready(io_master_wready),
      .io_wvalid(io_master_wvalid),
      .io_wdata (io_master_wdata),
      .io_wstrb (io_master_wstrb),
      .io_wlast (io_master_wlast),

      // Write Response Channel
      .io_bready(io_master_bready),
      .io_bvalid(io_master_bvalid),
      .io_bresp (io_master_bresp),
      .io_bid   (io_master_bid),

      // Read Address Channel
      .io_arready(io_master_arready),
      .io_arvalid(io_master_arvalid),
      .io_araddr (io_master_araddr),
      .io_arid   (io_master_arid),
      .io_arlen  (io_master_arlen),
      .io_arsize (io_master_arsize),
      .io_arburst(io_master_arburst),

      // Read Data Channel
      .io_rready(io_master_rready),
      .io_rvalid(io_master_rvalid),
      .io_rresp (io_master_rresp),
      .io_rdata (io_master_rdata),
      .io_rlast (io_master_rlast),
      .io_rid   (io_master_rid)
  );
endmodule

`ifdef __ICARUS__
`ifndef BIN_IVG
`define BIN_IVG "bin.ivg"
`endif
module axi_memory (
    input clk,
    input rst,

    output        io_awready,
    input         io_awvalid,
    input  [31:0] io_awaddr,
    input  [ 3:0] io_awid,
    input  [ 7:0] io_awlen,
    input  [ 2:0] io_awsize,
    input  [ 1:0] io_awburst,

    output        io_wready,
    input         io_wvalid,
    input  [31:0] io_wdata,
    input  [ 3:0] io_wstrb,
    input         io_wlast,

    input        io_bready,
    output       io_bvalid,
    output [1:0] io_bresp,
    output [3:0] io_bid,

    output        io_arready,
    input         io_arvalid,
    input  [31:0] io_araddr,
    input  [ 3:0] io_arid,
    input  [ 7:0] io_arlen,
    input  [ 2:0] io_arsize,
    input  [ 1:0] io_arburst,

    input         io_rready,
    output        io_rvalid,
    output [ 1:0] io_rresp,
    output [31:0] io_rdata,
    output        io_rlast,
    output [ 3:0] io_rid
);

  typedef enum logic [1:0] {
    IDLE,
    READ,
    WRITE,
    B_VALID
  } state_t;

  state_t state_current;
  state_t state_next;
  reg [1:0] arburst_i;
  reg [7:0] arlen_i;
  reg [2:0] arsize_i;
  reg [31:0] current_addr;
  reg read_done;
  reg write_done;
  wire [31:0] pmem_read_data_mux;

  always @(posedge clk) begin
    if (rst) begin
      state_current <= IDLE;
    end else begin
      state_current <= state_next;
    end
  end

  always @(*) begin
    state_next = IDLE;
    case (state_current)
      IDLE: begin
        if (io_awvalid && io_wvalid) begin
          state_next = WRITE;
        end else if (io_arvalid) begin
          state_next = READ;
        end
      end

      READ: begin
        state_next = READ;
        if (read_done) begin
          state_next = IDLE;
        end
      end

      WRITE: begin
        state_next = WRITE;
        if (write_done) begin
          state_next = B_VALID;
        end
      end

      B_VALID: begin
        state_next = B_VALID;
        if (io_bready) begin
          state_next = IDLE;
        end
      end

      default: begin
        $display("[axi_memory] ERROR: invalid state");
        $stop;
      end
    endcase
  end

  wire is_read = (state_current == IDLE) && io_arvalid;
  wire is_write = (state_current == IDLE) && (io_awvalid && io_wvalid);

  // -----------------------------
  // hand shake reply
  // -----------------------------
  reg io_arready_o_q, io_awready_o_q, io_wready_o_q;
  always @(posedge clk) begin
    if (rst) begin
      io_arready_o_q <= 1'b0;
      io_awready_o_q <= 1'b0;
      io_wready_o_q  <= 1'b0;
    end else if (is_write) begin
      io_awready_o_q <= 1'b1;
      io_wready_o_q  <= 1'b1;
      io_arready_o_q <= 1'b0;
    end else if (is_read) begin
      io_arready_o_q <= 1'b1;
      io_awready_o_q <= 1'b0;
      io_wready_o_q  <= 1'b0;
    end else begin
      io_arready_o_q <= 1'b0;
      io_awready_o_q <= 1'b0;
      io_wready_o_q  <= 1'b0;
    end
  end

  assign io_arready = io_arready_o_q;
  assign io_awready = io_awready_o_q;
  assign io_wready  = io_wready_o_q;

  // --------------------------
  // READ PART
  // --------------------------
  // AXI协议：根据size对齐地址
  // size=0 (1字节): 不需要对齐
  // size=1 (2字节): 地址[0]必须为0
  // size=2 (4字节): 地址[1:0]必须为0
  // wire [31:0] addr_align_mask = (arsize_i == 3'd0) ? 32'hFFFFFFFF :  // 1字节：不掩码
  //                               (arsize_i == 3'd1) ? 32'hFFFFFFFE :  // 2字节：清除bit[0]
  //                               32'hFFFFFFFC;                        // 4字节：清除bit[1:0]
  localparam [1:0] FIXED = 2'b00, INCR = 2'b01, WRAP = 2'b10, RESERVED = 2'b11;

  wire [31:0] addr_align_mask = 32'hFFFFFFFC;
  wire [31:0] addr_aligned = current_addr & addr_align_mask;
  wire [ 7:0] trans_time = arlen_i + 8'b1;

  wire [31:0] wrap_size = (({24'b0, arlen_i} + 1) << 2);
  wire [31:0] wrap_boundary = current_addr & ~(wrap_size - 1);
  wire [31:0] wrap_end = wrap_boundary + wrap_size;


  always @(posedge clk) begin
    if (rst) begin
      arsize_i  <= 3'b0;
      arlen_i   <= 8'b0;
      arburst_i <= 2'b0;
    end else if (is_read) begin
      arsize_i  <= io_arsize;
      arlen_i   <= io_arlen;
      arburst_i <= io_arburst;
    end
  end

  always @(posedge clk) begin
    if (rst) begin
      current_addr <= 32'b0;
    end else begin
      case (state_current)
        IDLE: begin
          if (is_read) begin
            current_addr <= io_araddr;
          end else if (is_write) begin
            current_addr <= io_awaddr;
          end
        end

        READ: begin
          if (io_rready) begin
            // update the current addr when read data handshake
            case (arburst_i)
              FIXED: begin
              end
              INCR: begin
                current_addr <= current_addr + 32'd4;
              end
              WRAP: begin
                if ((current_addr + 4) >= wrap_end) begin
                  current_addr <= wrap_boundary;
                end else begin
                  current_addr <= current_addr + 4;
                end
              end
              RESERVED: begin
                $display("[axi_memory] ERROR: arburst RESERVED not supported");
                $stop;
              end
            endcase
          end
        end

        default: begin
        end
      endcase
    end
  end

  reg read_valid;
  reg [31:0] data_output;
  reg [7:0] read_burst_counter;

  // 读数据：pmem / UART 等按地址选择
  wire [31:0] mem_read_data = pmem_read_data_mux;

  always @(posedge clk) begin
    if (state_current == READ & ~read_done) begin
      if (io_rready) begin
        data_output <= mem_read_data;
        if (read_burst_counter == trans_time - 1'b1) begin
          read_done  <= 1'b1;
          read_valid <= 1'b1;
        end else if (read_burst_counter < trans_time) begin
          read_valid <= 1'b1;
          read_burst_counter <= read_burst_counter + 1;
        end
      end
    end else begin
      read_burst_counter <= 8'b0;
      read_done <= 1'b0;
      read_valid <= 1'b0;
    end
  end

  assign io_rdata  = (read_valid) ? data_output : 32'b0;
  assign io_rvalid = read_valid;
  assign io_rlast  = read_done;

  // --------------------------
  // 内存映射
  // --------------------------
  localparam PMEM_BASE = 32'h80000000;
  // localparam PMEM_SIZE = 32'h20000000;  // 512MB
  localparam PMEM_SIZE = 32'h01000000;
  localparam PMEM_END = PMEM_BASE + PMEM_SIZE;

  localparam SERIAL_BASE = 32'ha00003f8;
  localparam SERIAL_SIZE = 32'd8;
  localparam SERIAL_END = SERIAL_BASE + SERIAL_SIZE;

  localparam RTC_BASE = 32'ha0000048;
  localparam RTC_SIZE = 32'd8;
  localparam RTC_END = RTC_BASE + RTC_SIZE;

  wire in_pmem = (addr_aligned >= PMEM_BASE) && (addr_aligned < PMEM_END);
  wire in_uart = (addr_aligned >= SERIAL_BASE) && (addr_aligned < SERIAL_END);
  wire in_rtc = (addr_aligned >= RTC_BASE) && (addr_aligned < RTC_END);
  wire [28:0] pmem_offset = addr_aligned[28:0];

  // reg [7:0] pmem[536870911:0];
  reg [7:0] pmem[0:16777215];
  initial begin
    $readmemh(`BIN_IVG, pmem);
  end

  reg [31:0] data_i;
  reg [ 3:0] wstrb_i;

  always @(posedge clk) begin
    if (rst) begin
      data_i  <= 32'b0;
      wstrb_i <= 4'b0;
    end else if (is_write) begin
      data_i  <= io_wdata;
      wstrb_i <= io_wstrb;
    end
  end

  // --------------------------
  // READ: pmem / UART 多路选择
  // --------------------------
  wire [7:0] pmem_b0 = pmem[pmem_offset];
  wire [7:0] pmem_b1 = pmem[pmem_offset+32'd1];
  wire [7:0] pmem_b2 = pmem[pmem_offset+32'd2];
  wire [7:0] pmem_b3 = pmem[pmem_offset+32'd3];

  wire [31:0] pmem_read_data = in_pmem ? {
    (^pmem_b3 === 1'bx) ? 8'h0 : pmem_b3,
    (^pmem_b2 === 1'bx) ? 8'h0 : pmem_b2,
    (^pmem_b1 === 1'bx) ? 8'h0 : pmem_b1,
    (^pmem_b0 === 1'bx) ? 8'h0 : pmem_b0
  } : 32'h0;
  wire [31:0] uart_read_data = 32'h0;
  wire [31:0] rtc_read_data = (addr_aligned[2] == 1'b0) ? $timel() : $timeh();

  assign pmem_read_data_mux = in_uart ? uart_read_data : in_rtc ? rtc_read_data : pmem_read_data;

  // 这样有点堆史山,但是我没招了
  always @(posedge clk) begin
    if (!rst && ((state_current == READ & ~read_done) || state_current == WRITE) &&
        !in_pmem && !in_uart && !in_rtc) begin
      $display("[axi_memory] ERROR: unmapped access, addr=0x%h", addr_aligned);
      $finish();
    end
  end

  // --------------------------
  // WRITE: pmem
  // --------------------------
  always @(posedge clk) begin
    if (state_current == WRITE && in_pmem) begin
      // $display("[pmem write] addr=0x%h data=0x%h wstrb=%b", addr_aligned, data_i, wstrb_i);
      if (wstrb_i[0]) pmem[pmem_offset+32'd0] <= data_i[7:0];
      if (wstrb_i[1]) pmem[pmem_offset+32'd1] <= data_i[15:8];
      if (wstrb_i[2]) pmem[pmem_offset+32'd2] <= data_i[23:16];
      if (wstrb_i[3]) pmem[pmem_offset+32'd3] <= data_i[31:24];
    end
  end

  // --------------------------
  // WRITE: UART (0xa00003f8 数据寄存器，仅 offset 0)
  // --------------------------
  // 用来避免一个字符打印两次
  reg uart_write_done;
  always @(posedge clk) begin
    if (rst) begin
      uart_write_done <= 1'b0;
    end else if (state_current == WRITE && in_uart && (addr_aligned == SERIAL_BASE) && wstrb_i[0]) begin
      if (!uart_write_done) begin
        $write("%c", data_i[7:0]);
        $fflush;
        uart_write_done <= 1'b1;
      end
    end else begin
      uart_write_done <= 1'b0;
    end
  end

  always @(posedge clk) begin
    if (state_current == WRITE) begin
      write_done <= 1'b1;
    end else begin
      write_done <= 1'b0;
    end
  end

  assign io_bvalid = (state_current == B_VALID) ? 1'b1 : 1'b0;

  assign io_rresp = 2'b00;
  assign io_rid = 4'b0;
  assign io_bid = 4'b0;
  assign io_bresp = 2'b00;
endmodule
`endif

`ifdef VERILATOR
// 仿真的 axi_memory 模块（包含 DPI-C，不参与综合）
module axi_memory (
    input clk,
    input rst,

    output        io_awready,
    input         io_awvalid,
    input  [31:0] io_awaddr,
    input  [ 3:0] io_awid,
    input  [ 7:0] io_awlen,
    input  [ 2:0] io_awsize,
    input  [ 1:0] io_awburst,

    output        io_wready,
    input         io_wvalid,
    input  [31:0] io_wdata,
    input  [ 3:0] io_wstrb,
    input         io_wlast,

    input        io_bready,
    output       io_bvalid,
    output [1:0] io_bresp,
    output [3:0] io_bid,

    output        io_arready,
    input         io_arvalid,
    input  [31:0] io_araddr,
    input  [ 3:0] io_arid,
    input  [ 7:0] io_arlen,
    input  [ 2:0] io_arsize,
    input  [ 1:0] io_arburst,

    input         io_rready,
    output        io_rvalid,
    output [ 1:0] io_rresp,
    output [31:0] io_rdata,
    output        io_rlast,
    output [ 3:0] io_rid
);

  typedef enum logic [1:0] {
    IDLE,
    READ,
    WRITE,
    B_VALID
  } state_t;

  state_t state_current;
  state_t state_next;
  reg [1:0] arburst_i;
  reg [7:0] arlen_i;
  reg [2:0] arsize_i;
  reg [31:0] current_addr;
  reg read_done;
  reg write_done;

  always @(posedge clk) begin
    if (rst) begin
      state_current <= IDLE;
    end else begin
      state_current <= state_next;
    end
  end

  always @(*) begin
    state_next = IDLE;
    case (state_current)
      IDLE: begin
        if (io_awvalid && io_wvalid) begin
          state_next = WRITE;
        end else if (io_arvalid) begin
          state_next = READ;
        end
      end

      READ: begin
        state_next = READ;
        if (read_done) begin
          state_next = IDLE;
        end
      end

      WRITE: begin
        state_next = WRITE;
        if (write_done) begin
          state_next = B_VALID;
        end
      end

      B_VALID: begin
        state_next = B_VALID;
        if (io_bready) begin
          state_next = IDLE;
        end
      end

      default: begin
        $display("[axi_memory] ERROR: invalid state");
        $stop;
      end
    endcase
  end

  wire is_read = (state_current == IDLE) && io_arvalid;
  wire is_write = (state_current == IDLE) && (io_awvalid && io_wvalid);

  // -----------------------------
  // hand shake reply
  // -----------------------------
  reg io_arready_o_q, io_awready_o_q, io_wready_o_q;
  always @(posedge clk) begin
    if (rst) begin
      io_arready_o_q <= 1'b0;
      io_awready_o_q <= 1'b0;
      io_wready_o_q  <= 1'b0;
    end else if (is_write) begin
      io_awready_o_q <= 1'b1;
      io_wready_o_q  <= 1'b1;
      io_arready_o_q <= 1'b0;
    end else if (is_read) begin
      io_arready_o_q <= 1'b1;
      io_awready_o_q <= 1'b0;
      io_wready_o_q  <= 1'b0;
    end else begin
      io_arready_o_q <= 1'b0;
      io_awready_o_q <= 1'b0;
      io_wready_o_q  <= 1'b0;
    end
  end

  assign io_arready = io_arready_o_q;
  assign io_awready = io_awready_o_q;
  assign io_wready  = io_wready_o_q;

  // --------------------------
  // READ PART
  // --------------------------
  // AXI协议：根据size对齐地址
  // size=0 (1字节): 不需要对齐
  // size=1 (2字节): 地址[0]必须为0
  // size=2 (4字节): 地址[1:0]必须为0
  // wire [31:0] addr_align_mask = (arsize_i == 3'd0) ? 32'hFFFFFFFF :  // 1字节：不掩码
  //                               (arsize_i == 3'd1) ? 32'hFFFFFFFE :  // 2字节：清除bit[0]
  //                               32'hFFFFFFFC;                        // 4字节：清除bit[1:0]
  localparam [1:0] FIXED = 2'b00, INCR = 2'b01, WRAP = 2'b10, RESERVED = 2'b11;

  wire [31:0] addr_align_mask = 32'hFFFFFFFC;
  wire [31:0] addr_aligned = current_addr & addr_align_mask;
  wire [ 7:0] trans_time = arlen_i + 8'b1;

  wire [31:0] wrap_size = (({24'b0, arlen_i} + 1) << 2);
  wire [31:0] wrap_boundary = current_addr & ~(wrap_size - 1);
  wire [31:0] wrap_end = wrap_boundary + wrap_size;

  import "DPI-C" function void npc_pmem_read(
    input  int addr,
    input  int len,
    output int data
  );

  always @(posedge clk) begin
    if (rst) begin
      arsize_i  <= 3'b0;
      arlen_i   <= 8'b0;
      arburst_i <= 2'b0;
    end else if (is_read) begin
      arsize_i  <= io_arsize;
      arlen_i   <= io_arlen;
      arburst_i <= io_arburst;
    end
  end

  always @(posedge clk) begin
    if (rst) begin
      current_addr <= 32'b0;
    end else begin
      case (state_current)
        IDLE: begin
          if (is_read) begin
            current_addr <= io_araddr;
          end else if (is_write) begin
            current_addr <= io_awaddr;
          end
        end

        READ: begin
          if (io_rready) begin
            // update the current addr when read data handshake
            case (arburst_i)
              FIXED: begin
              end
              INCR: begin
                current_addr <= current_addr + 32'd4;
              end
              WRAP: begin
                if ((current_addr + 4) >= wrap_end) begin
                  current_addr <= wrap_boundary;
                end else begin
                  current_addr <= current_addr + 4;
                end
              end
              RESERVED: begin
                $display("[axi_memory] ERROR: arburst RESERVED not supported");
                $stop;
              end
            endcase
          end
        end

        default: begin
        end
      endcase
    end
  end

  reg read_valid;
  reg [31:0] data_output;
  reg [7:0] read_burst_counter;
  // 其实我觉得这里没有必要设置这个valid， 但是反正这个部分也不
  // 参与综合，就感觉无所谓了
  always @(posedge clk) begin
    if (state_current == READ & ~read_done) begin
      if (io_rready) begin
        npc_pmem_read(addr_aligned, 32'd4, data_output);
        if (read_burst_counter == trans_time - 1'b1) begin
          read_done  <= 1'b1;
          read_valid <= 1'b1;
        end else if (read_burst_counter < trans_time) begin
          read_valid <= 1'b1;
          read_burst_counter <= read_burst_counter + 1;
        end
      end
    end else begin
      read_burst_counter <= 8'b0;
      read_done <= 1'b0;
      read_valid <= 1'b0;
    end
  end

  assign io_rdata  = (read_valid) ? data_output : 32'b0;
  assign io_rvalid = read_valid;
  assign io_rlast  = read_done;

  // --------------------------
  // WRITE PART
  // --------------------------
  import "DPI-C" function void npc_pmem_write(
    input int addr,
    input int len,
    input int data
  );
  reg [31:0] data_i;
  reg [ 3:0] wstrb_i;

  always @(posedge clk) begin
    if (rst) begin
      data_i  <= 32'b0;
      wstrb_i <= 4'b0;
    end else if (is_write) begin
      data_i  <= io_wdata;
      wstrb_i <= io_wstrb;
    end
  end

  always @(negedge clk) begin
    if (state_current == WRITE) begin
      if (wstrb_i[0]) begin
        npc_pmem_write(addr_aligned, 32'd1, {24'b0, data_i[7:0]});
      end
      if (wstrb_i[1]) begin
        npc_pmem_write(addr_aligned + 32'd1, 32'd1, {24'b0, data_i[15:8]});
      end
      if (wstrb_i[2]) begin
        npc_pmem_write(addr_aligned + 32'd2, 32'd1, {24'b0, data_i[23:16]});
      end
      if (wstrb_i[3]) begin
        npc_pmem_write(addr_aligned + 32'd3, 32'd1, {24'b0, data_i[31:24]});
      end
      write_done <= 1'b1;
    end else begin
      write_done <= 1'b0;
    end
  end

  assign io_bvalid = (state_current == B_VALID) ? 1'b1 : 1'b0;

  assign io_rresp = 2'b00;
  assign io_rid = 4'b0;
  assign io_bid = 4'b0;
  assign io_bresp = 2'b00;
endmodule
`endif
