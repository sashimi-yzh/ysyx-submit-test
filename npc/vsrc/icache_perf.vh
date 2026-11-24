// PERF-only icache hit/miss stats. Keep this in a separate include so the
// functional FSM/data path in icache.v stays focused.
`ifndef SYNTHESIS
longint unsigned ihit_cnt;
longint unsigned imiss_cnt;
longint unsigned ihit_lat_cycles;
longint unsigned imiss_lat_cycles;

reg              perf_miss_pending;
reg [31:0]       perf_miss_lat_ctr;

wire perf_req_fire;
wire perf_cached_req_fire;
wire perf_miss_resp_issue;

assign perf_req_fire = ifu_req_valid && ifu_req_ready;
assign perf_cached_req_fire = perf_req_fire && !uncached;
assign perf_miss_resp_issue = (state == STATE_MISS_R) && mem_rvalid && mem_rready &&
                              (miss_fill_cnt == WORD_OFFSET_BITS'(WORDS_PER_LINE - 1));

always @(posedge clk) begin
  if (reset) begin
    ihit_cnt          <= 64'd0;
    imiss_cnt         <= 64'd0;
    ihit_lat_cycles   <= 64'd0;
    imiss_lat_cycles  <= 64'd0;
    perf_miss_pending <= 1'b0;
    perf_miss_lat_ctr <= 32'd0;
  end else begin
    // Count requests only when a cached request is accepted.
    if (perf_cached_req_fire) begin
      if (hit) begin
        ihit_cnt        <= ihit_cnt + 64'd1;
        ihit_lat_cycles <= ihit_lat_cycles + 64'd1;
      end else begin
        imiss_cnt         <= imiss_cnt + 64'd1;
        perf_miss_pending <= 1'b1;
        perf_miss_lat_ctr <= 32'd1;
      end
    end

    // Miss latency is measured from miss request accept to response issue.
    if (perf_miss_pending && !perf_miss_resp_issue) begin
      perf_miss_lat_ctr <= perf_miss_lat_ctr + 32'd1;
    end

    if (perf_miss_pending && perf_miss_resp_issue) begin
      imiss_lat_cycles  <= imiss_lat_cycles + perf_miss_lat_ctr;
      perf_miss_pending <= 1'b0;
    end
  end
end

  export "DPI-C" function get_imiss_cnt;
  function automatic longint unsigned get_imiss_cnt();
    return imiss_cnt;
  endfunction

  export "DPI-C" function get_ihit_cnt;
  function automatic longint unsigned get_ihit_cnt();
    return ihit_cnt;
  endfunction

  export "DPI-C" function get_imiss_lat_cycles;
  function automatic longint unsigned get_imiss_lat_cycles();
    return imiss_lat_cycles;
  endfunction

  export "DPI-C" function get_ihit_lat_cycles;
  function automatic longint unsigned get_ihit_lat_cycles();
    return ihit_lat_cycles;
  endfunction
`endif
