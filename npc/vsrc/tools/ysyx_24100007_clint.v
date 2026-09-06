module ysyx_24100007_clint (
    input clk,
    input reset,

    input  awvalid,
    output awready,
    input  wvalid,
    output wready,
    input  arvalid,
    output arready,
    input  rready,
    output rvalid,
    input  bready,
    output bvalid,

    input  [31:0] araddr,
    input  [31:0] awaddr,
    input  [31:0] wdata,
    output [31:0] rdata,
    input  [ 3:0] wstrb,
    output [ 1:0] bresp,
    input  [ 2:0] awsize,
    input  [ 2:0] arsize
);

  // 仅仅作为slave模块存在，返回一个mtime，代表时间的流速
  reg [63:0] mtime;
  wire is_penable = (araddr >= 32'h02000000) && (araddr <= 32'h0200ffff);

  always @(posedge clk) begin
    if (reset) begin
      mtime <= 64'b0;
    end else begin
      mtime <= mtime + 1;
    end
  end

  // ---------------------------------
  // STATE MACHINE
  // ---------------------------------
  typedef enum logic [1:0] {
    ST_IDLE,
    ST_ACCEPT,
    ST_VALID
  } state_t;

  reg [1:0] state_next_r;
  reg [1:0] state_current_q;

  always @(posedge clk) begin
    if (reset) begin
      state_current_q <= ST_IDLE;
    end else begin
      state_current_q <= state_next_r;
    end
  end

  wire arvalid_match = is_penable & arvalid;
  wire rready_match = (state_current_q == ST_VALID) & rready;
  always @(*) begin
    state_next_r = ST_IDLE;

    case (state_current_q)
      ST_IDLE: begin
        if (arvalid_match) state_next_r = ST_ACCEPT;
      end

      ST_ACCEPT: begin
        state_next_r = ST_VALID;
      end

      ST_VALID: begin
        if (rready_match) state_next_r = ST_IDLE;
        else state_next_r = ST_VALID;
      end

      default: begin
        // synopsys translate_off
        $error("unkonw state in clint");
        // synopsys translate_on
      end
    endcase
  end

  reg [31:0] rdata_out_r;
  reg [31:0] rdata_out_q;
  reg [31:0] addr_q;
  reg addr_capture_en_r;

  // 地址捕获逻辑（组合逻辑）
  always @(*) begin
    addr_capture_en_r = 1'b0;
    rdata_out_r = 32'b0;

    // 在ST_IDLE状态且收到有效读请求时，准备捕获地址
    if (state_current_q == ST_IDLE && arvalid_match) begin
      addr_capture_en_r = 1'b1;
    end

    // 在ST_ACCEPT状态时，根据地址选择要读取的数据
    // CLINT地址映射：
    // 0x02000000 (offset 0x0): mtime[31:0]  低32位
    // 0x02000004 (offset 0x4): mtime[63:32] 高32位
    if (state_current_q == ST_ACCEPT) begin
      // 根据地址的第2位（addr_q[2]）选择mtime的低32位或高32位
      if (addr_q[2] == 1'b0) begin
        rdata_out_r = mtime[31:0];  // 低32位
      end else begin
        rdata_out_r = mtime[63:32];  // 高32位
      end
    end
  end

  always @(posedge clk) begin
    if (reset) begin
      addr_q <= 32'b0;
    end else if (addr_capture_en_r) begin
      addr_q <= araddr;
    end
  end

  always @(posedge clk) begin
    if (reset) begin
      rdata_out_q <= 32'b0;
    end else if (state_current_q == ST_ACCEPT) begin
      rdata_out_q <= rdata_out_r;
    end
  end

  assign arready = (state_current_q == ST_ACCEPT);
  assign rvalid  = (state_current_q == ST_VALID);
  assign rdata   = rdata_out_q;

  assign awready = 0;
  assign wready  = 0;
  assign bvalid  = 0;
  assign bresp   = 2'b00;
endmodule
