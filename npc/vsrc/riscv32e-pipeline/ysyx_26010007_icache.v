`include "ysyx_26010007_defines.v"
// `define ysyx_26010007_multiset
module ysyx_26010007_icache (
  input clock,
  input reset,

  // icache与IFU的握手接口
  input                       ifu_arvalid,
  input  [`ysyx_26010007_PADDR_WIDTH-1:0]   ifu_araddr,
  output                      icache_iarready,
  output                      icache_irvalid, // 指令有效信号
  output   [`ysyx_26010007_WORD_WIDTH-1:0]  icache_irdata, // 指令数据
  output   [`ysyx_26010007_WORD_WIDTH-1:0]  icache_ipc,

  // IROM AXI BUS (只读接口)
  output                    icache_arvalid,
  input                     icache_arready,
  output [`ysyx_26010007_PADDR_WIDTH-1:0] icache_araddr,
  output [7:0]              icache_arlen,
  output [2:0]              icache_arsize,
  output [3:0]              icache_arid,
  output [1:0]              icache_arburst,
  input                     icache_rvalid,
  output                    icache_rready,
  input [`ysyx_26010007_WORD_WIDTH-1:0]   icache_rdata,
  input [1:0]               icache_rresp,
  input                     icache_rlast,
  input [3:0]               icache_rid,

  // fence_flush
  input fence_flush
);
  // 16B
  localparam BLOCK_SIZE = 16; // 16B
  localparam BLOCK_DATA_WIDTH = 128;
  localparam BLOCK_NUM = 1;
  localparam BLOCK_OFFSET_WIDTH = 2;
  localparam BLOCK_INDEX_WIDTH = 1;
  localparam BLOCK_TAG_WIDTH = 28;
  localparam LRU_WIDTH = 8;

  /* Cache Line
    |- valid -|- tag -|- data -|
  */
`ifdef ysyx_26010007_multiset
  localparam BLOCK_WAY = 2;
  localparam BLOCK_WAY_WIDTH = 1;
  reg [BLOCK_WAY-1:0]         icache_valid[BLOCK_NUM-1:0];
  reg [BLOCK_TAG_WIDTH-1:0]   icache_tag[BLOCK_NUM-1:0][BLOCK_WAY-1:0];
  reg [BLOCK_DATA_WIDTH-1:0]  icache_data[BLOCK_NUM-1:0][BLOCK_WAY-1:0];
`else
  reg                         icache_valid;
  reg [BLOCK_TAG_WIDTH-1:0]   icache_tag;
  reg [BLOCK_DATA_WIDTH-1:0]  icache_data;
`endif

  // 地址翻译
  wire [BLOCK_TAG_WIDTH-1:0] tag = ifu_araddr[31:4];
  // wire [BLOCK_INDEX_WIDTH-1:0] index = ifu_araddr[4:4];
  wire [BLOCK_OFFSET_WIDTH-1:0] offset = ifu_araddr[3:2];

  // 两级流水
  wire i_valid, i_ready, o_ready;
  reg o_valid;
  assign i_valid = ifu_arvalid;
  assign icache_iarready = i_ready;

  // 第一级：判断hit逻辑
`ifdef ysyx_26010007_multiset
  reg hit;
  integer i1;
  always @(*) begin
    hit = 0;
    for(i1 = 0; i1 < BLOCK_WAY ;i1 = i1 + 1) begin
      if(icache_valid[index][i1] && (icache_tag[index][i1] == tag)) begin
        hit = 1'b1;
      end
    end
  end
`else
  wire hit = icache_valid && tag == icache_tag;
`endif

`ifdef ysyx_26010007_multiset
  // 若是多路组相连，还需选出命中的way
  reg [BLOCK_WAY_WIDTH-1:0] hit_way;
  always @(*) begin
    hit_way = 0;
    for(i1 = 0; i1 < BLOCK_WAY ;i1 = i1 + 1) begin
      if(icache_valid[index][i1] && (icache_tag[index][i1] == tag)) begin
        hit_way = i1[BLOCK_WAY_WIDTH-1:0];
      end
    end
  end
  
  // 若是多路组相连，选出最近最少使用的cache line
  reg [BLOCK_WAY_WIDTH-1:0] tarLru;
  reg [LRU_WIDTH-1:0] lru_counter [BLOCK_NUM-1:0][BLOCK_WAY-1:0];
  // way 2
  wire [BLOCK_WAY_WIDTH-1:0] maxLru_01 = (lru_counter[index][0] > lru_counter[index][1]) ? 1'd0 : 1'd1;
  wire [BLOCK_WAY_WIDTH-1:0] maxLru = maxLru_01;
  // way 4
  // wire [BLOCK_WAY_WIDTH-1:0] maxLru_01 = (lru_counter[index][0] > lru_counter[index][1]) ? 2'd0 : 2'd1;
  // wire [BLOCK_WAY_WIDTH-1:0] maxLru_23 = (lru_counter[index][2] > lru_counter[index][3]) ? 2'd2 : 2'd3;
  // wire [BLOCK_WAY_WIDTH-1:0] maxLru = (lru_counter[index][maxLru_01] > lru_counter[index][maxLru_23]) ? maxLru_01 : maxLru_23;
  integer ihit;
  always @(*) begin
    tarLru = 0;
    if(&icache_valid[index] == 0) begin
      for(ihit = BLOCK_WAY - 1; ihit >= 0; ihit = ihit - 1) begin
        if(!icache_valid[index][ihit]) begin
          tarLru = ihit[BLOCK_WAY_WIDTH-1:0];
        end
      end 
    end
    else tarLru = maxLru;
  end
`endif

  reg [`ysyx_26010007_WORD_WIDTH-1:0] ifu_araddr_ff;
  reg hit_ff;
  // reg [BLOCK_INDEX_WIDTH-1:0] index_ff;
  reg [BLOCK_TAG_WIDTH-1:0] tag_ff;
  reg [BLOCK_OFFSET_WIDTH-1:0] offset_ff;
`ifdef ysyx_26010007_multiset
  reg [BLOCK_WAY_WIDTH-1:0] hit_way_ff;
  reg [BLOCK_WAY_WIDTH-1:0] tarLru_ff;
`endif
  always @(posedge clock) begin
    if(i_valid & i_ready) begin
      ifu_araddr_ff <= ifu_araddr;
      hit_ff <= hit;
      // index_ff <= index;
      offset_ff <= offset;
      tag_ff <= tag;
`ifdef ysyx_26010007_multiset
      hit_way_ff <= hit_way;
      tarLru_ff <= tarLru;
`endif
    end
  end
  always @(posedge clock) begin
    if(reset) begin
      o_valid <= 0;
    end
    else if(i_ready)begin
      o_valid <= i_valid;
    end
  end
  assign i_ready = !o_valid || o_ready;
  
  // 第二级：通过状态机控制
  
  reg [1:0] state;
  localparam S0 = 2'd0; // 接收来自IFU的请求
  localparam S1 = 2'd1; // 返回命中数据
  localparam S2 = 2'd2; // 发起总线请求
  localparam S3 = 2'd3; // 等待数据返回
  wire rerror_n = icache_rid == 4'b0000;
  wire rvalid_flag = (rerror_n) && (icache_rid == 4'b0000) && icache_rvalid && icache_rlast;

  reg flush_pending;
  always @(posedge clock) begin
    if(reset) flush_pending <= 0;
    else if(fence_flush && (state == S1 || state == S2)) begin
      flush_pending <= 1'b1;
    end
    else if(state == S0) begin
      flush_pending <= 0;
    end
  end

  always @(posedge clock) begin
    if(reset) state <= S0;
    else begin
      case (state)
        S0 : state <= o_valid & (~hit_ff) ? S1 : S0;
        S1 : state <= icache_arready ? S2 : S1;
        S2 : state <= rvalid_flag ? S3 : S2;
        S3 : state <= S0; // 这一周期是让miss的data加载到cache中
        default: state <= S0;
      endcase
    end
  end
  assign o_ready = (o_valid & hit_ff) | (state == S3);

`ifdef ysyx_26010007_multiset
  // 更新LRU计数器
  integer i0, j0;
  always @(posedge clock) begin
    if(reset || fence_flush) begin
      for(i0 = 0; i0 < BLOCK_NUM; i0 = i0 + 1) begin
        for(j0 = 0; j0 < BLOCK_WAY; j0 = j0 + 1) begin
          lru_counter[i0][j0] <= 0;
        end
      end
    end
    else if(o_ready) begin
      for(j0 = 0; j0 < BLOCK_WAY; j0 = j0 + 1) begin
        if(icache_valid[index_ff][j0]) begin
          lru_counter[index_ff][j0] <= j0[BLOCK_WAY_WIDTH-1:0] == tarLru_ff ? 0 : lru_counter[index_ff][j0] + 1;
        end
        else lru_counter[index_ff][j0] <= 0;
      end
    end
  end
`endif

`ifdef ysyx_26010007_multiset
  integer i2;
  always @(posedge clock) begin
    if(reset || fence_flush) begin
      for(i2 = 0; i2 < BLOCK_NUM; i2 = i2 + 1) icache_valid[i2] <= 0;
    end
    else begin
      // 0x0f00_0000~0x0fff_ffff
      if(state == S2 && icache_rvalid) begin
        icache_valid[index_ff][tarLru_ff] <= 1'b1;
        icache_data[index_ff][tarLru_ff]  <= {icache_data[index_ff][tarLru_ff] >> 32} | {icache_rdata, 96'd0};
        icache_tag[index_ff][tarLru_ff]   <= tag_ff;
      end
    end
  end
  assign icache_irdata = (state == S3) ? icache_data[index_ff][tarLru_ff][{offset_ff, 5'd0} +: 32] : icache_data[index_ff][hit_way_ff][{offset_ff, 5'd0} +: 32]; // hit return
`else
  integer i2;
  reg [1:0] inst_beat_counter;
  always @(posedge clock) begin
    if(reset) inst_beat_counter <= 0;
    else if(state == S2 && icache_rvalid && rerror_n) begin
      inst_beat_counter <= inst_beat_counter + 2'd1;
    end
  end
  
  always @(posedge clock) begin
    if(reset || flush_pending) begin
      icache_valid <= 0;
    end
    else begin
      // 0x0f00_0000~0x0fff_ffff
      if(state == S2 && icache_rvalid && rerror_n) begin
        case (inst_beat_counter)
          2'b00: begin icache_valid<= 1'b1; icache_tag <= tag_ff; icache_data[31:0] <= icache_rdata; end
          2'b01: icache_data[63:32] <= icache_rdata;
          2'b10: icache_data[95:64] <= icache_rdata;
          2'b11: icache_data[127:96] <= icache_rdata;
        endcase
      end
    end
  end
  
  assign icache_irdata = icache_data[{offset_ff, 5'd0} +: 32]; // hit return
`endif

  assign icache_irvalid = o_valid & hit_ff // hit return
                          | (state == S3); // 缺失后从总线收到数据
  assign icache_ipc = ifu_araddr_ff;

  assign icache_araddr = ifu_araddr_ff & 32'hfffffff0;
  assign icache_arvalid = state == S1;
  assign icache_arlen = 8'd3;
  assign icache_arsize = 3'b010;
  assign icache_arid = 4'b0000;
  assign icache_arburst = 2'b01;

  assign icache_rready = (state == S2);
`ifdef ysyx_26010007_debug
  always @(posedge clock) begin
    if(!reset) begin
      if(i_valid && i_ready) begin
        event_count(17);
      end
      if(o_valid && (state == S0) && hit_ff) begin 
        event_count(18);
      end
      if(o_valid && ((state == S2) || (state == S1))) begin
        event_count(19);
      end
    end
  end
`endif

endmodule