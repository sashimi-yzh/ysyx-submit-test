`include "ysyx_26010007_defines.v"
module ysyx_26010007_icache (
  input clock,
  input reset,

  // icache与IFU的握手接口
  input                     ifu_arvalid,
  input  [`PADDR_WIDTH-1:0] ifu_araddr,
  output                    icache_irvalid, // 指令有效信号
  output [`WORD_WIDTH-1:0]  icache_irdata, // 指令数据

  // IROM AXI BUS (只读接口)
  output                    icache_arvalid,
  input                     icache_arready,
  output [`PADDR_WIDTH-1:0] icache_araddr,
  output [7:0]              icache_arlen,
  output [2:0]              icache_arsize,
  output [3:0]              icache_arid,
  output [1:0]              icache_arburst,
  input                     icache_rvalid,
  output                    icache_rready,
  input [`WORD_WIDTH-1:0]   icache_rdata,
  input [1:0]               icache_rresp,
  input                     icache_rlast,
  input [3:0]               icache_rid,

  // flush_icache
  input flush_icache
);
  // 256KB - 直接映射
  localparam BLOCK_SIZE = 16;
  localparam BLOCK_DATA_WIDTH = 128; // 16B
  localparam BLOCK_NUM = 4;
  localparam BLOCK_WAY = 4;
  localparam BLOCK_OFFSET_WIDTH = 2;
  localparam BLOCK_INDEX_WIDTH = 2;
  localparam BLOCK_WAY_WIDTH = 2;
  localparam BLOCK_TAG_WIDTH = 26; // 32 - log16 - log16
  localparam LRU_WIDTH = 8;

  /*
    |- valid -|- tag -|- index -|- data -|
  */
  reg [BLOCK_WAY-1:0]         icache_valid[BLOCK_NUM-1:0];
  reg [BLOCK_TAG_WIDTH-1:0]   icache_tag[BLOCK_NUM-1:0][BLOCK_WAY-1:0];
  reg [BLOCK_DATA_WIDTH-1:0]  icache_data[BLOCK_NUM-1:0][BLOCK_WAY-1:0];

  reg [2:0] state;
  localparam S0 = 3'd0; // 接收来自IFU的请求
  localparam S1 = 3'd1; // 返回命中数据
  localparam S2 = 3'd2; // 发起总线请求
  localparam S3 = 3'd3; // 等待数据返回
  localparam S4 = 3'd4;
  
  wire [BLOCK_TAG_WIDTH-1:0] tag = ifu_araddr[31:6];
  wire [BLOCK_INDEX_WIDTH-1:0] index = ifu_araddr[5:4];
  wire [BLOCK_OFFSET_WIDTH-1:0] offset = ifu_araddr[3:2];
  reg hit;
  reg [BLOCK_WAY_WIDTH-1:0] hit_way;

  reg [LRU_WIDTH-1:0] lru_counter [BLOCK_NUM-1:0][BLOCK_WAY-1:0];
  wire [BLOCK_WAY_WIDTH-1:0] maxLru_01 = (lru_counter[index][0] > lru_counter[index][1]) ? 2'd0 : 2'd1;
  wire [BLOCK_WAY_WIDTH-1:0] maxLru_23 = (lru_counter[index][2] > lru_counter[index][3]) ? 2'd2 : 2'd3;
  wire [BLOCK_WAY_WIDTH-1:0] maxLru = (lru_counter[index][maxLru_01] > lru_counter[index][maxLru_23]) ? maxLru_01 : maxLru_23;
  integer ihit;
  reg [BLOCK_WAY_WIDTH-1:0] tarLru;
  always @(posedge clock) begin
    if(state == S1 && !hit) begin
      if(&icache_valid[index] == 0) begin
        for(ihit = BLOCK_WAY - 1; ihit >= 0; ihit = ihit - 1) begin
          if(!icache_valid[index][ihit]) begin
            tarLru = ihit[1:0];
          end
        end 
      end
      else tarLru = maxLru;
    end
  end

  integer i0, j0;
  always @(posedge clock) begin
    if(reset) begin
      for(i0 = 0; i0 < BLOCK_NUM; i0 = i0 + 1) begin
        for(j0 = 0; j0 < BLOCK_WAY; j0 = j0 + 1) begin
          lru_counter[i0][j0] <= 0;
        end
      end
    end
    else begin
      for(j0 = 0; j0 < BLOCK_WAY; j0 = j0 + 1) begin
        if(icache_valid[index][j0]) lru_counter[index][j0] <= lru_counter[index][j0] + 1;
        else lru_counter[index][j0] <= 0;
      end
      lru_counter[index][maxLru] <= 0;
    end
  end

  integer i1;
  always @(*) begin
    hit_way = 0;
    hit = 0;
    for(i1 = 0; i1 < BLOCK_WAY ;i1 = i1 + 1) begin
      if(icache_valid[index][i1] && (icache_tag[index][i1] == tag)) begin
        hit_way = i1[1:0];
        hit = 1'b1;
      end
    end
  end
  
  wire rvalid_flag = (icache_rresp == 2'b00) && (icache_rid == 4'b0000) && icache_rvalid && icache_rlast;

  // reg [3:0]counter;
  // always @(posedge clock) begin
  //   if(reset) counter <= 0;
  //   else begin
  //     if((state == S3) && rvalid_flag) counter <= counter + 4'd1;
  //     else if(state == S0) counter <= 4'd0;
  //   end
  // end
  wire sram_flag = ifu_araddr >= 32'hf000000 && ifu_araddr < 32'h10000000;

  always @(posedge clock) begin
    if(reset) state <= S0;
    else begin
      case (state)
        S0 : state <= ifu_arvalid ? S1 : S0;
        S1 : state <= hit ? S0 : S2;
        S2 : state <= icache_arready ? S3 : S2;
        S3 : state <= rvalid_flag ? S4 : S3;
        S4 : state <= S0;
        default: state <= S0;
      endcase
    end
  end
  integer i2;
  always @(posedge clock) begin
    if(reset || flush_icache) begin
      for(i2 = 0; i2 < BLOCK_NUM; i2 = i2 + 1) icache_valid[i2] <= 0;
    end
    else begin
      // 0x0f00_0000~0x0fff_ffff
      if(state == S3 && icache_rvalid && (!sram_flag)) begin
        icache_valid[index][tarLru] <= 1'b1;
        icache_data[index][tarLru]  <= {icache_data[index][tarLru] >> 32} | {icache_rdata, 96'd0};
        icache_tag[index][tarLru]   <= tag;
      end
    end
  end

  assign icache_irvalid = ((state == S1) & hit) || ((state == S4) & hit) || (sram_flag && (state == S3) && rvalid_flag); // 命中 或 缺失后从总线收到数据
  assign icache_irdata = (({32{((state == S1) || (state == S4)) & hit}} & icache_data[index][hit_way][{offset, 5'd0} +: 32])) | (({32{(sram_flag && (state == S3) && rvalid_flag)}}) & icache_rdata);

  assign icache_araddr = sram_flag ? ifu_araddr : (ifu_araddr & 32'hfffffff0);
  assign icache_arvalid = ((state == S1) && ~hit) || (state == S2);
  assign icache_arlen = sram_flag ? 8'd0 : 8'd3;
  assign icache_arsize = 3'b010;
  assign icache_arid = 4'b0000;
  assign icache_arburst = 2'b01;

  assign icache_rready = (state == S3);
`ifdef debug
  always @(posedge clock) begin
    if((state == S0) && ifu_arvalid) begin
      event_count(17);
    end
    if((state == S1) && hit) begin 
      event_count(18);
    end
    if((state == S2) || (state == S3) || (state == S4)) begin
      event_count(19);
    end
  end
`endif

endmodule