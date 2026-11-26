module ICache(
  input clk,
  input rst,
  input flush,

  input  [31:0] cpu_addr,
  input         cpu_req,
  output        cpu_ready,
  output [31:0] cpu_inst,

  output        arvalid,
  input         arready,
  output [31:0] araddr,
  output [7:0]  arlen,
  output [1:0]  arburst,

  input         rvalid,
  output        rready,
  input  [31:0] rdata,
  input         rlast,

  output        idle
`ifndef SYNTHESIS
  ,
  output        perf_cacheable,
  output        perf_hit,
  output        perf_fill_start,
  output        perf_victim_valid,
  output        perf_fill_ar,
  output        perf_bypass_ar
`endif
);

  localparam [1:0] BURST_INCR = 2'b01;
`ifdef SOC_MODE
  localparam [1:0] BURST_WRAP = 2'b10;
`endif

  localparam S_BOOT    = 3'd5;
  localparam S_IDLE    = 3'd0;
  localparam S_FILL_AR = 3'd1;
  localparam S_FILL_R  = 3'd2;
  localparam S_BYP_AR  = 3'd3;
  localparam S_BYP_R   = 3'd4;

  reg [31:0] data [0:15];
  reg [25:0] tag [0:3];
  reg [3:0] valid;

  reg [2:0] state;
  reg [1:0] fill_idx;
  reg [25:0] fill_tag;
  reg [1:0] fill_cnt;
`ifdef SOC_MODE
  reg [1:0] fill_start; 
`endif
  reg [29:0] byp_addr;             

  wire [1:0]  req_word = cpu_addr[3:2];
  wire [1:0]  req_idx  = cpu_addr[5:4];
  wire [25:0] req_tag  = cpu_addr[31:6];
  wire [31:0] req_data = data[{req_idx, req_word}];

`ifdef SOC_MODE
  wire [31:0] fill_addr = {fill_tag, fill_idx, fill_start, 2'b00};
  wire [1:0]  fill_wr_word = fill_start + fill_cnt;
`else
  wire [31:0] fill_addr = {fill_tag, fill_idx, 4'b0};
  wire [1:0]  fill_wr_word = fill_cnt;
`endif

  wire is_flash = (cpu_addr[31:24] == 8'h30);
  wire is_sdram = (cpu_addr[31:25] == 7'b1010000);
`ifdef SOC_MODE
  wire cacheable = is_flash || is_sdram;
`else
  wire is_pmem   = (cpu_addr[31:27] == 5'b10000);
  wire cacheable = is_flash || is_sdram || is_pmem;
`endif

  wire hit = valid[req_idx] && (tag[req_idx] == req_tag);

  wire fill_match = (state == S_FILL_R) &&
                    (req_idx == fill_idx) &&
                    (req_tag == fill_tag);
`ifdef SOC_MODE
  wire [1:0] req_dist = req_word - fill_start;  // WRAP: beats until req_word
`else
  wire [1:0] req_dist = req_word;               // INCR: burst starts at 0
`endif
  wire fill_has_word   = fill_match &&
                         ((req_dist < fill_cnt) ||
                          (rvalid && (req_dist == fill_cnt)));
  wire [31:0] fill_stream_data = (req_dist == fill_cnt) ? rdata : req_data;

  assign cpu_ready = !rst && (cacheable ? (hit || fill_has_word)
                                        : ((state == S_BYP_R) && rvalid &&
                                           (cpu_addr[31:2] == byp_addr)));
  assign cpu_inst  = cacheable ? (hit ? req_data : fill_stream_data) : rdata;

  wire demand_miss = cpu_req && cacheable && !hit;

  assign arvalid = !rst && ((state == S_FILL_AR) || (state == S_BYP_AR));
  assign araddr  = (state == S_BYP_AR) ? {byp_addr, 2'b00} : fill_addr;
  assign arlen   = (state == S_BYP_AR) ? 8'd0 : 8'd3;
`ifdef SOC_MODE
  assign arburst = (state == S_BYP_AR) ? BURST_INCR : BURST_WRAP;
`else
  assign arburst = BURST_INCR;
`endif
  assign rready  = !rst && ((state == S_FILL_R) || (state == S_BYP_R));
  assign idle    = (state == S_IDLE);

  wire ar_fire = arvalid && arready;

`ifndef SYNTHESIS
  assign perf_cacheable    = cacheable;
  assign perf_hit          = hit;
  assign perf_fill_start   = (state == S_IDLE) && demand_miss;
  assign perf_victim_valid = valid[req_idx];
  assign perf_fill_ar      = (state == S_FILL_AR);
  assign perf_bypass_ar    = (state == S_BYP_AR);
`endif

  always @(posedge clk) begin
    if (rst) begin
      state <= S_BOOT;
      valid <= 4'b0;
      fill_cnt <= 2'b0;
`ifdef SOC_MODE
      fill_start <= 2'b0;
`endif
    end else if (flush) begin
      state <= S_IDLE;
      valid <= 4'b0;
      fill_cnt <= 2'b0;
`ifdef SOC_MODE
      fill_start <= 2'b0;
`endif
    end else begin
      case (state)
        S_BOOT: begin
          state <= S_IDLE;
        end
        S_IDLE: begin
          if (cpu_req && !cacheable) begin
            state <= S_BYP_AR;
            byp_addr <= cpu_addr[31:2];
          end else if (demand_miss) begin
            state <= S_FILL_AR;
            fill_idx  <= req_idx;
            fill_tag  <= req_tag;
`ifdef SOC_MODE
            fill_start <= req_word;   // critical word first
`endif
            fill_cnt  <= 2'b0;
            valid[req_idx] <= 1'b0;
          end
        end

        S_FILL_AR: begin
          if (ar_fire) state <= S_FILL_R;
        end

        S_FILL_R: begin
          if (rvalid && rready) begin
            data[{fill_idx, fill_wr_word}] <= rdata;
            if (rlast) begin
              tag[fill_idx]   <= fill_tag;
              valid[fill_idx] <= 1'b1;
              state <= S_IDLE;
            end else begin
              fill_cnt <= fill_cnt + 1'b1;
            end
          end
        end

        S_BYP_AR: begin
          if (ar_fire) state <= S_BYP_R;
        end

        S_BYP_R: begin
          if (rvalid && rready) state <= S_IDLE;
        end

        default: state <= S_IDLE;
      endcase
    end
  end

endmodule
