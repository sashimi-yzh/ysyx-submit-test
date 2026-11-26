`timescale 1ns/1ps

module tb_iverilog;

`ifdef SIM_NETLIST
  initial $display("[tb] netlist simulation mode");
`endif

  reg clock = 1'b0;
  reg reset = 1'b1;
  reg io_interrupt = 1'b0;

  always #5 clock = ~clock;

  initial begin
    reset = 1'b1;
    #1000;
    reset = 1'b0;
  end

  wire        m_awvalid;
  reg         m_awready;
  wire [31:0] m_awaddr;
  wire [ 3:0] m_awid;
  wire [ 7:0] m_awlen;
  wire [ 2:0] m_awsize;
  wire [ 1:0] m_awburst;

  wire        m_wvalid;
  reg         m_wready;
  wire [31:0] m_wdata;
  wire [ 3:0] m_wstrb;
  wire        m_wlast;

  wire        m_bready;
  reg         m_bvalid;
  reg  [ 1:0] m_bresp;
  reg  [ 3:0] m_bid;

  wire        m_arvalid;
  reg         m_arready;
  wire [31:0] m_araddr;
  wire [ 3:0] m_arid;
  wire [ 7:0] m_arlen;
  wire [ 2:0] m_arsize;
  wire [ 1:0] m_arburst;

  reg         m_rvalid;
  wire        m_rready;
  reg  [ 1:0] m_rresp;
  reg  [31:0] m_rdata;
  reg         m_rlast;
  reg  [ 3:0] m_rid;

  ysyx_26020070 dut (
    .clock(clock),
    .reset(reset),
    .io_interrupt(io_interrupt),

    .io_master_awvalid(m_awvalid),
    .io_master_awready(m_awready),
    .io_master_awaddr (m_awaddr),
    .io_master_awid   (m_awid),
    .io_master_awlen  (m_awlen),
    .io_master_awsize (m_awsize),
    .io_master_awburst(m_awburst),

    .io_master_wvalid(m_wvalid),
    .io_master_wready(m_wready),
    .io_master_wdata (m_wdata),
    .io_master_wstrb (m_wstrb),
    .io_master_wlast (m_wlast),

    .io_master_bready(m_bready),
    .io_master_bvalid(m_bvalid),
    .io_master_bresp (m_bresp),
    .io_master_bid   (m_bid),

    .io_master_arvalid(m_arvalid),
    .io_master_arready(m_arready),
    .io_master_araddr (m_araddr),
    .io_master_arid   (m_arid),
    .io_master_arlen  (m_arlen),
    .io_master_arsize (m_arsize),
    .io_master_arburst(m_arburst),

    .io_master_rready(m_rready),
    .io_master_rvalid(m_rvalid),
    .io_master_rresp (m_rresp),
    .io_master_rdata (m_rdata),
    .io_master_rlast (m_rlast),
    .io_master_rid   (m_rid),

    .io_slave_awvalid(1'b0),
    .io_slave_awaddr (32'b0),
    .io_slave_awid   (4'b0),
    .io_slave_awlen  (8'b0),
    .io_slave_awsize (3'b0),
    .io_slave_awburst(2'b0),
    .io_slave_wvalid (1'b0),
    .io_slave_wdata  (32'b0),
    .io_slave_wstrb  (4'b0),
    .io_slave_wlast  (1'b0),
    .io_slave_bready (1'b0),
    .io_slave_arvalid(1'b0),
    .io_slave_araddr (32'b0),
    .io_slave_arid   (4'b0),
    .io_slave_arlen  (8'b0),
    .io_slave_arsize (3'b0),
    .io_slave_arburst(2'b0),
    .io_slave_rready (1'b0)
  );

  localparam FLASH_WORDS = 1 << 8;
  localparam PROG_WORDS  = 1 << 25;

  reg [31:0] boot_mem [0:FLASH_WORDS-1];
  reg [31:0] prog_mem  [0:PROG_WORDS-1];

  function [31:0] read_mem;
    input [31:0] addr;
    begin
      if (addr[31:20] == 12'h300)
        read_mem = boot_mem[addr[19:2]];
      else if (addr[31:27] == 5'b10000)
        read_mem = prog_mem[addr[26:2]];
      else begin
        read_mem = 32'b0;
        $display("WARNING: read from unimplemented address %08x", addr);
      end
    end
  endfunction

  task write_mem;
    input [31:0] addr;
    input [31:0] data;
    input [ 3:0] strb;
    reg   [31:0] word;
    begin
      if (addr == 32'h1000_0000) begin
        if (strb[0]) $write("%c", data[7:0]);
      end else if (addr[31:27] == 5'b10000) begin
        word = prog_mem[addr[26:2]];
        if (strb[0]) word[ 7: 0] = data[ 7: 0];
        if (strb[1]) word[15: 8] = data[15: 8];
        if (strb[2]) word[23:16] = data[23:16];
        if (strb[3]) word[31:24] = data[31:24];
        prog_mem[addr[26:2]] = word;
      end
    end
  endtask

  reg [1023:0] hex_file;
  integer max_cycles;
  integer i;
  integer fd;
  integer loaded;
  reg [31:0] load_word;

  initial begin
    if (!$value$plusargs("hex=%s", hex_file)) begin
      $display("ERROR: +hex=FILE is required");
      $fatal;
    end

    if (!$value$plusargs("max_cycles=%d", max_cycles)) max_cycles = 5000000;

    for (i = 0; i < PROG_WORDS; i = i + 1) prog_mem[i] = 32'b0;

    boot_mem[0] = 32'h800002b7;
    boot_mem[1] = 32'h00028067;

    for (i = 2; i < 8; i = i + 1) boot_mem[i] = 32'b0;

    fd = $fopen(hex_file, "r");
    if (fd == 0) begin
      $display("ERROR: cannot open %0s", hex_file);
      $fatal;
    end
    loaded = 0;
    while (!$feof(fd) && loaded < PROG_WORDS) begin
      if ($fscanf(fd, "%h", load_word) == 1) begin
        prog_mem[loaded] = load_word;
        loaded = loaded + 1;
      end
    end
    $fclose(fd);
    $display("[tb] loaded %0d words from %0s at 0x80000000, max_cycles=%0d",
             loaded, hex_file, max_cycles);
  end

  // ---------------------------------------------------------------------------
  // AXI4 read channel
  // ---------------------------------------------------------------------------
  reg [31:0] r_addr;
  reg [ 7:0] r_len;
  reg [ 3:0] r_id;
  reg [ 2:0] r_size;
  reg [ 1:0] r_burst;
  reg [ 7:0] r_progress;
  reg        r_valid;
  reg [31:0] r_data;
  reg        r_last;

  wire [ 8:0] r_beats       = {1'b0, r_len} + 9'd1;
  wire [31:0] r_beat_bytes  = 32'd1 << r_size;
  wire [31:0] r_burst_bytes = r_beats * r_beat_bytes;
  wire [31:0] r_wrap_base   = r_addr & ~(r_burst_bytes - 32'd1);
  wire [31:0] r_start_off   = r_addr - r_wrap_base;
  wire [31:0] r_start_idx   = r_start_off >> r_size;

  assign m_arready = !r_valid;
  assign m_rvalid  = r_valid;
  assign m_rresp   = 2'b00;
  assign m_rdata   = r_data;
  assign m_rlast   = r_last;
  assign m_rid     = r_id;

  // ---------------------------------------------------------------------------
  // AXI4 write channel
  // ---------------------------------------------------------------------------
  reg [31:0] aw_addr;
  reg [ 7:0] aw_len;
  reg [ 3:0] aw_id;
  reg        aw_done;

  reg [31:0] w_data;
  reg [ 3:0] w_strb;
  reg        w_last;
  reg        w_done;

  reg        b_valid;
  reg [ 1:0] b_resp;
  reg [ 3:0] b_id;

  assign m_awready = !aw_done && !b_valid;
  assign m_wready  = !w_done  && !b_valid;
  assign m_bvalid  = b_valid;
  assign m_bresp   = b_resp;
  assign m_bid     = b_id;

  // ---------------------------------------------------------------------------
  // AXI slave state
  // ---------------------------------------------------------------------------
  reg        seen_ebreak;
  integer    ebreak_wait;
  integer    cycles;

  always @(posedge clock) begin
    if (reset) begin
      r_valid    <= 1'b0;
      r_data     <= 32'b0;
      r_last     <= 1'b0;
      r_id       <= 4'b0;
      r_progress <= 8'b0;
      r_len      <= 8'b0;
      r_addr     <= 32'b0;
      r_size     <= 3'b0;
      r_burst    <= 2'b0;

      aw_done    <= 1'b0;
      w_done     <= 1'b0;
      b_valid    <= 1'b0;
      b_resp     <= 2'b0;
      b_id       <= 4'b0;
      aw_addr    <= 32'b0;
      aw_len     <= 8'b0;
      aw_id      <= 4'b0;
      w_data     <= 32'b0;
      w_strb     <= 4'b0;
      w_last     <= 1'b0;

      seen_ebreak <= 1'b0;
      ebreak_wait <= 0;
      cycles      <= 0;
    end else begin
      cycles <= cycles + 1;

      if (cycles > max_cycles) begin
        $display("SIM TIMEOUT after %0d cycles", cycles);
        $fatal;
      end

      // ---- AR ----
      if (m_arvalid && m_arready) begin
        r_addr     <= m_araddr;
        r_len      <= m_arlen;
        r_id       <= m_arid;
        r_size     <= m_arsize;
        r_burst    <= m_arburst;
        r_progress <= 8'b0;
        r_data     <= read_mem(m_araddr);
        r_last     <= (m_arlen == 8'b0);
        r_valid    <= 1'b1;
      end

      // ---- R ----
      if (r_valid && m_rready) begin
        if (r_progress == r_len) begin
          r_valid <= 1'b0;
        end else begin
          r_progress <= r_progress + 8'd1;
          r_last     <= ((r_progress + 8'd1) == r_len);
          if (r_burst == 2'b10) begin
            // WRAP: critical word first, then wrap within the burst block.
            r_data <= read_mem(r_wrap_base +
                               (((r_start_idx + r_progress + 32'd1) %
                                 r_beats) * r_beat_bytes));
          end else begin
            // INCR / FIXED-as-INCR.
            r_data <= read_mem(r_addr +
                               ((r_progress + 32'd1) * r_beat_bytes));
          end
        end
      end

      // ---- AW / W / B ----
      if (m_awvalid && m_awready) begin
        aw_addr <= m_awaddr;
        aw_len  <= m_awlen;
        aw_id   <= m_awid;
        aw_done <= 1'b1;
      end

      if (m_wvalid && m_wready) begin
        w_data <= m_wdata;
        w_strb <= m_wstrb;
        w_last <= m_wlast;
        w_done <= 1'b1;
      end

      if (aw_done && w_done && !b_valid) begin
        write_mem(aw_addr, w_data, w_strb);
        b_id    <= aw_id;
        b_resp  <= 2'b00;
        b_valid <= 1'b1;
        aw_done <= 1'b0;
        w_done  <= 1'b0;
      end

      if (b_valid && m_bready)
        b_valid <= 1'b0;

      if (r_valid && m_rready && (r_id == 4'b0001) &&
          (r_progress == 8'd0) && (r_data == 32'h00100073)) begin
        seen_ebreak <= 1'b1;
        ebreak_wait <= 500;
      end

      if (seen_ebreak) begin
        if (ebreak_wait > 0)
          ebreak_wait <= ebreak_wait - 1;
        else begin
          $display("SIM PASS: ebreak fetched after %0d cycles", cycles);
          $finish;
        end
      end
    end
  end

endmodule
