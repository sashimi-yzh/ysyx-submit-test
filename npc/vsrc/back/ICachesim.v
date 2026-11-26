`ifndef IC_BLOCK
`define IC_BLOCK 4
`endif

`ifndef IC_SETS
`define IC_SETS 16
`endif

`ifndef IC_WAYS
`define IC_WAYS 1
`endif

`ifndef IC_BURST
`define IC_BURST 0
`endif

module ICachesim(
  input clk,
  input rst,
  input flush,

  // IFU 侧：Phase 1 简化后的接口（地址 + 握手 + 32 位数据）
  input  ifu_arvalid,
  output ifu_arready,
  input  [31:0] ifu_araddr,

  output ifu_rvalid,
  input  ifu_rready,
  output [31:0] ifu_rdata,

  // Arbiter 侧：arid/arsize/arburst 由 Arbiter 补常量，这里只留会变化的部分
  output        arvalid,
  input         arready,
  output [31:0] araddr,
  output [ 7:0] arlen,

  input         rvalid,
  output        rready,
  input  [31:0] rdata,
  input         rlast
);

  // ------------------------------------------------------------------
  // 参数与地址切分
  // ------------------------------------------------------------------
  function integer clog2;
    input integer value;
    integer i;
    begin
      clog2 = 0;
      for (i = value - 1; i > 0; i = i >> 1) clog2 = clog2 + 1;
    end
  endfunction

  localparam BLOCK  = `IC_BLOCK;
  localparam SETS   = `IC_SETS;
  localparam WAYS   = `IC_WAYS;
  localparam BURST  = `IC_BURST;

  localparam BLOCKS      = SETS * WAYS;      // cache 块总数
  localparam BEATS       = BLOCK / 4;        // 每块的 32 位字数（>= 1）
  localparam OFFSET_BITS = clog2(BLOCK);     // 块内字节偏移位宽
  localparam INDEX_BITS  = clog2(SETS);      // 组索引位宽
  localparam TAG_SHIFT   = OFFSET_BITS + INDEX_BITS;

  // 用 32 位掩码做索引/标签提取，避免 SETS=1 时出现零宽位选
  localparam [31:0] INDEX_MASK = (SETS == 1) ? 32'h0
                                             : (((SETS - 1) << OFFSET_BITS) & 32'hffff_ffff);

  // ------------------------------------------------------------------
  // 存储阵列（全部为触发器）
  //   data  : 每块 BLOCK 字节
  //   tag   : 块标签（高位有效）
  //   valid : 有效位
  //   lru   : 上次访问的单调时间戳，替换时取最小者
  // ------------------------------------------------------------------
  reg [BLOCK*8-1:0] blk_data [0:BLOCKS-1];
  reg [31:0]        blk_tag  [0:BLOCKS-1];
  reg               blk_valid[0:BLOCKS-1];
  reg [31:0]        blk_lru  [0:BLOCKS-1];

  reg [31:0] lru_clock;

  // 当前请求的地址分解
  wire [31:0] idx_in  = (ifu_araddr & INDEX_MASK) >> OFFSET_BITS;
  wire [31:0] tag_in  = ifu_araddr >> TAG_SHIFT;
  wire [31:0] off_in  = (ifu_araddr >> 2) & (BEATS - 1);   // 块内第几个 32 位字
  wire [31:0] base_in = idx_in * WAYS;                     // 组基址

  // ------------------------------------------------------------------
  // 组内命中查找与替换路选择
  // ------------------------------------------------------------------
  integer w;

  reg        hit_r;
  reg [31:0] hit_way;
  always @(*) begin
    hit_r   = 1'b0;
    hit_way = 32'd0;
    for (w = 0; w < WAYS; w = w + 1) begin
      if (!hit_r && blk_valid[base_in + w] && (blk_tag[base_in + w] == tag_in)) begin
        hit_r   = 1'b1;
        hit_way = w;
      end
    end
  end

  reg        set_has_invalid;   // 组内存在无效路 => 本次缺失为强制缺失
  reg [31:0] victim_way;
  always @(*) begin
    set_has_invalid = 1'b0;
    victim_way      = 32'd0;
    // 优先填充第一条无效路（WAYS=1 时等价于 ICache.v 的 valid 判定）
    for (w = 0; w < WAYS; w = w + 1) begin
      if (!set_has_invalid && !blk_valid[base_in + w]) begin
        set_has_invalid = 1'b1;
        victim_way      = w;
      end
    end
    // 组内全有效：替换最久未用的那一路
    if (!set_has_invalid) begin
      for (w = 1; w < WAYS; w = w + 1) begin
        if (blk_lru[base_in + w] < blk_lru[base_in + victim_way]) victim_way = w;
      end
    end
  end

  // ------------------------------------------------------------------
  // 状态机
  //   IDLE -> (hit ? RETURN : MISS_AR -> MISS_R -> ... -> RETURN) -> IDLE
  //   BURST=1：一次 AR（arlen=BEATS-1），按 rlast 收满整块
  //   BURST=0：逐字发起 BEATS 次 arlen=0 的独立事务
  // ------------------------------------------------------------------
  localparam S_IDLE    = 2'd0;
  localparam S_MISS_AR = 2'd1;
  localparam S_MISS_R  = 2'd2;
  localparam S_RETURN  = 2'd3;

  reg [1:0]  state;
  reg [31:0] req_tag, req_index, req_off, req_base, req_way;
  reg [31:0] beat_cnt;

  wire [31:0] fill_base = req_base + req_way;     // 本块的物理块号

  // 读数据：从命中/填充块的第 req_off 个 32 位字取出
  reg [31:0] ret_data;
  integer k;
  always @(*) begin
    ret_data = 32'b0;
    for (k = 0; k < BEATS; k = k + 1) begin
      if (req_off == k) ret_data = blk_data[fill_base][k*32 +: 32];
    end
  end

  assign ifu_arready = !rst && (state == S_IDLE);
  assign ifu_rvalid  = !rst && (state == S_RETURN);
  assign ifu_rdata   = ret_data;

  // 块首地址 = {tag, index, offset=0}
  wire [31:0] blk_addr = (req_tag << TAG_SHIFT) | (req_index << OFFSET_BITS);

  assign arvalid = !rst && (state == S_MISS_AR);
  assign araddr  = blk_addr + (BURST ? 32'd0 : (beat_cnt << 2));
  assign arlen   = BURST ? (BEATS - 1) : 8'd0;

  assign rready  = !rst && (state == S_MISS_R);

  wire r_fire    = rvalid && rready;
  wire last_beat = BURST ? rlast : (beat_cnt == (BEATS - 1));

  // ------------------------------------------------------------------
  // 主状态更新
  // ------------------------------------------------------------------
  integer i;
  always @(posedge clk) begin
    if (rst) begin
      state     <= S_IDLE;
      req_tag   <= 32'b0;
      req_index <= 32'b0;
      req_off   <= 32'b0;
      req_base  <= 32'b0;
      req_way   <= 32'b0;
      beat_cnt  <= 32'b0;
      lru_clock <= 32'b0;
      for (i = 0; i < BLOCKS; i = i + 1) begin
        blk_valid[i] <= 1'b0;
        blk_tag[i]   <= 32'b0;
        blk_lru[i]   <= 32'b0;
      end
    end else if (flush) begin
      for (i = 0; i < BLOCKS; i = i + 1) begin
        blk_valid[i] <= 1'b0;
      end
      state <= S_IDLE;
      beat_cnt <= 32'b0;
    end else begin
      case (state)
        S_IDLE: begin
          if (ifu_arvalid && ifu_arready) begin
            req_tag   <= tag_in;
            req_index <= idx_in;
            req_off   <= off_in;
            req_base  <= base_in;
            beat_cnt  <= 32'b0;
            if (hit_r) begin
              req_way <= hit_way;
              blk_lru[base_in + hit_way] <= lru_clock + 32'd1;
              lru_clock <= lru_clock + 32'd1;
              state <= S_RETURN;
            end else begin
              // 缺失：victim 在 IDLE 当拍已由组合逻辑选好
              req_way <= victim_way;
              state   <= S_MISS_AR;
            end
          end
        end

        S_MISS_AR: begin
          if (arvalid && arready) begin
            // 注意：不要在这里清零 beat_cnt —— 非突发模式下它是「整块第几个字」
            // 的进度指示，清零会让后续 AR 重复读同一地址并永不结束。
            state <= S_MISS_R;
          end
        end

        S_MISS_R: begin
          if (r_fire) begin
            // 按 beat 序号写入块内对应字（循环变量为常量，位选静态）
            for (i = 0; i < BEATS; i = i + 1) begin
              if (beat_cnt == i) blk_data[fill_base][i*32 +: 32] <= rdata;
            end
            beat_cnt <= beat_cnt + 32'd1;
            if (last_beat) begin
              blk_valid[fill_base] <= 1'b1;
              blk_tag[fill_base]   <= req_tag;
              blk_lru[fill_base]   <= lru_clock + 32'd1;
              lru_clock <= lru_clock + 32'd1;
              state     <= S_RETURN;
            end else if (!BURST) begin
              // 独立事务模式：继续发起下一个字的 AR
              state <= S_MISS_AR;
            end
          end
        end

        S_RETURN: begin
          if (ifu_rvalid && ifu_rready) state <= S_IDLE;
        end

        default: state <= S_IDLE;
      endcase
    end
  end

endmodule
