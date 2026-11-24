module ysyx_24110012_icache #(
  parameter integer BLOCK_BYTES = 4,
  parameter integer NUM_LINES   = 16
) (
  input  wire clk,
  input  wire reset,
  input  wire flush,
  output reg flush_done,

  // IFU side request/response
  input  wire        ifu_req_valid,
  output wire        ifu_req_ready,
  input  wire [31:0] ifu_req_addr,
  output reg         ifu_resp_valid,
  input  wire        ifu_resp_ready,
  output reg  [31:0] ifu_resp_data,

  // Downstream memory read channel (AXI-lite style AR/R subset)
  output reg  [31:0] mem_araddr,
  output reg         mem_arvalid,
  output reg  [ 1:0] mem_arburst,
  output reg  [ 7:0] mem_arlen,
  output wire [ 2:0] mem_arsize,
  input  wire        mem_arready,

  input  wire [31:0] mem_rdata,
  input  wire        mem_rvalid,
  input  wire        mem_rlast,
  output reg         mem_rready
);

  localparam integer OFFSET_BITS = $clog2(BLOCK_BYTES);
  localparam integer INDEX_BITS = $clog2(NUM_LINES);
  localparam integer WORDS_PER_LINE = BLOCK_BYTES / 4;
  localparam integer WORD_OFFSET_BITS = (WORDS_PER_LINE <= 1) ? 1 : $clog2(WORDS_PER_LINE);
  localparam integer TAG_BITS = 32 - OFFSET_BITS - INDEX_BITS;

  localparam logic [2:0] STATE_IDLE = 3'b000;
  localparam logic [2:0] STATE_MISS_AR = 3'b001;
  localparam logic [2:0] STATE_MISS_R = 3'b010;
  localparam logic [2:0] STATE_UNCACHED_AR = 3'b011;
  localparam logic [2:0] STATE_UNCACHED_R = 3'b100;

  reg     [                 2:0] state;

  reg     [        TAG_BITS-1:0] tag_array          [NUM_LINES];
  reg                            valid_array        [NUM_LINES];
  reg     [                31:0] data_array         [NUM_LINES] [WORDS_PER_LINE];

  reg     [                31:0] miss_addr;
  reg     [        TAG_BITS-1:0] miss_tag;
  reg     [      INDEX_BITS-1:0] miss_index;
  reg     [WORD_OFFSET_BITS-1:0] miss_word_off;
  reg     [WORD_OFFSET_BITS-1:0] miss_fill_cnt;
  reg     [                31:0] miss_base_addr;
  reg     [                31:0] miss_req_word_data;

  wire    [      INDEX_BITS-1:0] req_index;
  wire    [        TAG_BITS-1:0] req_tag;
  wire    [WORD_OFFSET_BITS-1:0] req_word_off;
  wire    [WORD_OFFSET_BITS-1:0] miss_fill_cnt_next;
  wire    [                31:0] miss_next_araddr;
  wire                           hit;
  wire                           uncached;
  wire    [                31:0] hit_word;

  integer                        i;
  integer                        j;

  task automatic invalidate_cache_arrays;
    begin
      for (i = 0; i < NUM_LINES; i = i + 1) begin
        valid_array[i] <= 1'b0;
        tag_array[i]   <= {TAG_BITS{1'b0}};
        // for (j = 0; j < WORDS_PER_LINE; j = j + 1) begin
        //   data_array[i][j] <= 32'b0;
        // end
      end
    end
  endtask

  // SRAM don't need to be cached which start from 0x0f000000;
  // FLASH also don't need to be cached which start from 0x30000000 in 256M;
  localparam logic [31:0] SRAM_BASE = 32'h0f000000;
  localparam logic [31:0] FLASH_BASE = 32'h30000000;
  //assign uncached = (ifu_req_addr & 32'hffffe000) == SRAM_BASE || (ifu_req_addr & 32'hf0000000) == FLASH_BASE;
  assign uncached = (ifu_req_addr & 32'hffffe000) == SRAM_BASE;

  assign mem_arsize = 3'b010; // 4 bytes (32 bits) per beat

  // Address breakdown for cache indexing and tag comparison
  // 31    m+n m+n-1   m m-1    0
  // +---------+---------+--------+
  // |   tag   |  index  | offset |
  // +---------+---------+--------+

  assign req_index = ifu_req_addr[OFFSET_BITS+INDEX_BITS-1 : OFFSET_BITS];
  assign req_tag = ifu_req_addr[31 : OFFSET_BITS+INDEX_BITS];

  generate
    if (WORDS_PER_LINE == 1) begin : gen_single_word_line
      assign req_word_off = {WORD_OFFSET_BITS{1'b0}};
    end else begin : gen_multi_word_line
      assign req_word_off = ifu_req_addr[OFFSET_BITS-1 : 2];
    end
  endgenerate

  assign hit = valid_array[req_index] && (tag_array[req_index] == req_tag);
  assign hit_word = data_array[req_index][req_word_off];
  assign miss_fill_cnt_next = miss_fill_cnt + {{(WORD_OFFSET_BITS-1){1'b0}}, 1'b1};
  assign miss_next_araddr = miss_base_addr +
                            {{(32-WORD_OFFSET_BITS-2){1'b0}}, miss_fill_cnt_next, 2'b00};

  assign ifu_req_ready = (state == STATE_IDLE) && !ifu_resp_valid;

  always @(posedge clk) begin
    if (reset) begin
      state              <= STATE_IDLE;
      ifu_resp_valid     <= 1'b0;
      ifu_resp_data      <= 32'b0;

      mem_araddr         <= 32'b0;
      mem_arvalid        <= 1'b0;
      mem_arlen          <= 8'b0;
      mem_arburst        <= 2'b00;
      mem_rready         <= 1'b0;

      miss_addr          <= 32'b0;
      miss_tag           <= {TAG_BITS{1'b0}};
      miss_index         <= {INDEX_BITS{1'b0}};
      miss_word_off      <= {WORD_OFFSET_BITS{1'b0}};
      miss_fill_cnt      <= {WORD_OFFSET_BITS{1'b0}};
      miss_base_addr     <= 32'b0;
      miss_req_word_data <= 32'b0;

      invalidate_cache_arrays();
    end else begin

      if (flush) begin
        invalidate_cache_arrays();
        flush_done <= 1'b1;
      end else begin
        flush_done <= 1'b0;
      end

      if (ifu_resp_valid && ifu_resp_ready) begin
        ifu_resp_valid <= 1'b0;
      end

      case (state)
        STATE_IDLE: begin
          mem_arvalid <= 1'b0;
          mem_rready  <= 1'b0;
          mem_arlen   <= uncached ? 0 : WORDS_PER_LINE - 1;  // Number of beats in a burst (0-based)
          mem_arburst <= uncached ? 2'b00 : 2'b10;           // WRAP burst

          if (ifu_req_valid && ifu_req_ready) begin
            if (uncached) begin
              mem_araddr  <= ifu_req_addr;
              mem_arvalid <= 1'b1;
              state       <= STATE_UNCACHED_AR;
            end else if (hit) begin
              ifu_resp_data  <= hit_word;
              ifu_resp_valid <= 1'b1;
            end else begin
              miss_addr              <= ifu_req_addr;
              miss_tag               <= req_tag;
              miss_index             <= req_index;
              miss_word_off          <= req_word_off;
              miss_fill_cnt          <= {WORD_OFFSET_BITS{1'b0}};
              miss_base_addr         <= {ifu_req_addr[31:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
              valid_array[req_index] <= 1'b0;

              mem_araddr             <= {ifu_req_addr[31:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
              mem_arvalid            <= 1'b1;
              state                  <= STATE_MISS_AR;
            end
          end
        end

        STATE_MISS_AR: begin
          if (mem_arvalid && mem_arready) begin
            mem_arvalid <= 1'b0;
            mem_rready  <= 1'b1;
            state       <= STATE_MISS_R;
          end
        end

        STATE_MISS_R: begin
          if (mem_rvalid && mem_rready) begin
            data_array[miss_index][miss_fill_cnt] <= mem_rdata;

            if (miss_fill_cnt == miss_word_off) begin
              miss_req_word_data <= mem_rdata;
            end

            if (mem_rlast || mem_arlen == 0) begin
              mem_rready <= 1'b0;
            end

            // WORDS_PER_LINE perhaps bigger than 1 so need loop here
            if (miss_fill_cnt == WORDS_PER_LINE - 1) begin
              tag_array[miss_index]   <= miss_tag;
              if (flush) begin
                valid_array[miss_index] <= 1'b0;
              end else begin
                valid_array[miss_index] <= 1'b1;
              end

              ifu_resp_data           <= miss_req_word_data;
              if (miss_word_off == miss_fill_cnt) begin
                ifu_resp_data <= mem_rdata;
              end
              ifu_resp_valid <= 1'b1;
              state          <= STATE_IDLE;
            end else if (mem_arlen > 0) begin
              miss_fill_cnt <= miss_fill_cnt + 1'b1;
              state <= STATE_MISS_R;
            end else begin
              miss_fill_cnt <= miss_fill_cnt_next;
              mem_araddr <= miss_next_araddr;
              mem_arvalid <= 1'b1;
              state <= STATE_MISS_AR;
            end
          end
        end
        STATE_UNCACHED_AR: begin
          if (mem_arvalid && mem_arready) begin
            mem_arvalid <= 1'b0;
            mem_rready  <= 1'b1;
            state       <= STATE_UNCACHED_R;
          end
        end

        STATE_UNCACHED_R: begin
          if (mem_rvalid && mem_rready) begin
            ifu_resp_data  <= mem_rdata;
            ifu_resp_valid <= 1'b1;
            mem_rready     <= 1'b0;
            state <= STATE_IDLE;
          end
        end

        default: begin
          state <= STATE_IDLE;
        end
      endcase
    end
  end

`ifdef PERF
`include "icache_perf.vh"
`endif

`ifdef FORMAL
  reg f_past_valid = 1'b0;

  always @(posedge clk) begin
    f_past_valid <= 1'b1;

    if (f_past_valid && $past(reset)) begin
      assert(state == STATE_IDLE);
      assert(!ifu_resp_valid);
      assert(!mem_arvalid);
      assert(!mem_rready);
    end

    if (f_past_valid && !$past(reset)) begin
      assert(ifu_req_ready == (state == STATE_IDLE && !ifu_resp_valid));
      assert(mem_arsize == 3'b010);
      assert(state == STATE_IDLE || state == STATE_MISS_AR || state == STATE_MISS_R ||
             state == STATE_UNCACHED_AR || state == STATE_UNCACHED_R);
      assert(!mem_rready || state == STATE_MISS_R || state == STATE_UNCACHED_R);
    end

    if (f_past_valid && !$past(reset) &&
        $past(state == STATE_IDLE && ifu_req_valid && ifu_req_ready && uncached)) begin
      assert(state == STATE_UNCACHED_AR);
      assert(mem_arvalid);
      assert(mem_araddr == $past(ifu_req_addr));
    end

    if (f_past_valid && !$past(reset) &&
        $past(state == STATE_IDLE && ifu_req_valid && ifu_req_ready && hit)) begin
      assert(ifu_resp_valid);
      assert(ifu_resp_data == $past(hit_word));
    end
  end
`endif

endmodule
