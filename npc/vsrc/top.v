module top(
  input clk,
  input rst,
  input [31:0] imem_rdata,
  output [31:0] pc,
  output [31:0] inst,
  output [31:0] imem_addr

`ifdef SOC_MODE
  ,
  output        mem_arvalid,
  input         mem_arready,
  output [31:0] mem_araddr,
  output [ 3:0] mem_arid,
  output [ 7:0] mem_arlen,
  output [ 2:0] mem_arsize,
  output [ 1:0] mem_arburst,
  input         mem_rvalid,
  output        mem_rready,
  input  [ 1:0] mem_rresp,
  input  [31:0] mem_rdata,
  input         mem_rlast,
  input  [ 3:0] mem_rid,
  output        mem_awvalid,
  input         mem_awready,
  output [31:0] mem_awaddr,
  output [ 3:0] mem_awid,
  output [ 7:0] mem_awlen,
  output [ 2:0] mem_awsize,
  output [ 1:0] mem_awburst,
  output        mem_wvalid,
  input         mem_wready,
  output [31:0] mem_wdata,
  output [ 3:0] mem_wstrb,
  output        mem_wlast,
  input         mem_bvalid,
  output        mem_bready,
  input  [ 1:0] mem_bresp,
  input  [ 3:0] mem_bid
`endif
);

`ifndef SOC_MODE
  wire        mem_arvalid;
  wire        mem_arready;
  wire [31:0] mem_araddr;
  wire [ 3:0] mem_arid;
  wire [ 7:0] mem_arlen;
  wire [ 2:0] mem_arsize;
  wire [ 1:0] mem_arburst;
  wire        mem_rvalid;
  wire        mem_rready;
  wire [ 1:0] mem_rresp;
  wire [31:0] mem_rdata;
  wire        mem_rlast;
  wire [ 3:0] mem_rid;
  wire        mem_awvalid;
  wire        mem_awready;
  wire [31:0] mem_awaddr;
  wire [ 3:0] mem_awid;
  wire [ 7:0] mem_awlen;
  wire [ 2:0] mem_awsize;
  wire [ 1:0] mem_awburst;
  wire        mem_wvalid;
  wire        mem_wready;
  wire [31:0] mem_wdata;
  wire [ 3:0] mem_wstrb;
  wire        mem_wlast;
  wire        mem_bvalid;
  wire        mem_bready;
  wire [ 1:0] mem_bresp;
  wire [ 3:0] mem_bid;
`endif

  // ---------------- Core <-> fetch ----------------
  wire [31:0] fetch_pc, fetch_inst;
  wire        fetch_req, fetch_ready, fetch_idle, fetch_accept;
  wire        icache_flush;

  // ---------------- ICache <-> Arbiter ----------------
  wire        ic_arvalid, ic_arready;
  wire [31:0] ic_araddr;
  wire [ 7:0] ic_arlen;
  wire [ 1:0] ic_arburst;
  wire        ic_rvalid, ic_rready;
  wire [31:0] ic_rdata;
  wire        ic_rlast;
`ifndef SYNTHESIS
  wire        ic_cacheable, ic_hit, ic_fill_start, ic_victim_valid;
  wire        ic_fill_ar, ic_bypass_ar;
`endif

  // ---------------- LSU <-> Arbiter ----------------
  wire        lsu_arvalid, lsu_arready;
  wire [31:0] lsu_araddr;
  wire [ 3:0] lsu_arid;
  wire [ 7:0] lsu_arlen;
  wire [ 2:0] lsu_arsize;
  wire [ 1:0] lsu_arburst;
  wire        lsu_rvalid, lsu_rready;
  wire [ 1:0] lsu_rresp;
  wire [31:0] lsu_rdata;
  wire        lsu_rlast;
  wire [ 3:0] lsu_rid;
  wire        lsu_awvalid, lsu_awready;
  wire [31:0] lsu_awaddr;
  wire [ 3:0] lsu_awid;
  wire [ 7:0] lsu_awlen;
  wire [ 2:0] lsu_awsize;
  wire [ 1:0] lsu_awburst;
  wire        lsu_wvalid, lsu_wready;
  wire [31:0] lsu_wdata;
  wire [ 3:0] lsu_wstrb;
  wire        lsu_wlast;
  wire        lsu_bvalid, lsu_bready;
  wire [ 1:0] lsu_bresp;
  wire [ 3:0] lsu_bid;

  // ---------------- CLINT slave (read-only AXI4-Lite subset) ----------------
  wire        clint_arvalid, clint_arready;
  wire [31:0] clint_araddr;
  wire [ 3:0] clint_arid;
  wire [ 7:0] clint_arlen;
  wire [ 2:0] clint_arsize;
  wire [ 1:0] clint_arburst;
  wire        clint_rvalid, clint_rready;
  wire [ 1:0] clint_rresp;
  wire [31:0] clint_rdata;
  wire        clint_rlast;
  wire [ 3:0] clint_rid;

  // ---------------- Core <-> LSU ----------------
  wire        dmem_valid, dmem_wen;
  wire [ 2:0] dmem_f3;
  wire [31:0] dmem_addr, dmem_wdata, dmem_rdata;
  wire        dmem_done, dmem_is_load, dmem_is_store;

  // ---------------- CSR ----------------
  wire [11:0] csr_addr;
  wire [31:0] csr_wdata, csr_rdata, csr_pc;
  wire        csr_wen, csr_ecall;
  wire [31:0] mepc, mtvec, mstatus, mcause, mcycle_lo, mcycle_hi;
  wire [63:0] mtime_shared = {mcycle_hi, mcycle_lo};

  // ---------------- core ----------------
  wire [31:0] cur_pc, cur_inst;
`ifndef SYNTHESIS
  wire [31:0] a0_value;
  wire        retire;
  wire [31:0] retire_pc, retire_inst, retire_next_pc, retire_addr, retire_wdata;
  wire        retire_is_mem, retire_is_store, retire_branch_taken;
`endif

  Core u_core(
    .clk(clk), .rst(rst),
    .fetch_pc(fetch_pc), .fetch_req(fetch_req), .fetch_ready(fetch_ready),
    .fetch_inst(fetch_inst), .fetch_idle(fetch_idle), .fetch_accept(fetch_accept),
    .mem_valid(dmem_valid), .mem_wen(dmem_wen), .mem_f3(dmem_f3),
    .mem_addr(dmem_addr), .mem_wdata(dmem_wdata), .mem_rdata(dmem_rdata),
    .mem_done(dmem_done), .mem_is_load(dmem_is_load), .mem_is_store(dmem_is_store),
    .csr_addr(csr_addr), .csr_wdata(csr_wdata), .csr_wen(csr_wen),
    .csr_ecall(csr_ecall), .csr_pc(csr_pc), .csr_rdata(csr_rdata),
    .mepc(mepc), .mtvec(mtvec), .icache_flush(icache_flush),
    .cur_pc(cur_pc), .cur_inst(cur_inst)
`ifndef SYNTHESIS
    ,
    .a0_value(a0_value),
    .retire(retire), .retire_pc(retire_pc), .retire_inst(retire_inst),
    .retire_next_pc(retire_next_pc), .retire_addr(retire_addr),
    .retire_wdata(retire_wdata), .retire_is_mem(retire_is_mem),
    .retire_is_store(retire_is_store), .retire_branch_taken(retire_branch_taken)
`endif
  );

  ICache u_icache(
    .clk(clk), .rst(rst), .flush(icache_flush),
    .cpu_addr(fetch_pc), .cpu_req(fetch_req), .cpu_ready(fetch_ready),
    .cpu_inst(fetch_inst)
`ifndef SYNTHESIS
    , .perf_cacheable(ic_cacheable), .perf_hit(ic_hit),
    .perf_fill_start(ic_fill_start), .perf_victim_valid(ic_victim_valid),
    .perf_fill_ar(ic_fill_ar), .perf_bypass_ar(ic_bypass_ar)
`endif
    , .arvalid(ic_arvalid), .arready(ic_arready), .araddr(ic_araddr),
    .arlen(ic_arlen), .arburst(ic_arburst),
    .rvalid(ic_rvalid), .rready(ic_rready), .rdata(ic_rdata), .rlast(ic_rlast),
    .idle(fetch_idle)
  );

  LSU u_lsu(
    .clk(clk), .rst(rst),
    .req(dmem_valid), .wen(dmem_wen), .f3(dmem_f3),
    .addr(dmem_addr), .wdata(dmem_wdata), .rdata(dmem_rdata), .done(dmem_done),
    .lsu_arvalid(lsu_arvalid), .lsu_arready(lsu_arready), .lsu_araddr(lsu_araddr),
    .lsu_arid(lsu_arid), .lsu_arlen(lsu_arlen), .lsu_arsize(lsu_arsize),
    .lsu_arburst(lsu_arburst),
    .lsu_rvalid(lsu_rvalid), .lsu_rready(lsu_rready), .lsu_rresp(lsu_rresp),
    .lsu_rdata(lsu_rdata), .lsu_rlast(lsu_rlast), .lsu_rid(lsu_rid),
    .lsu_awvalid(lsu_awvalid), .lsu_awready(lsu_awready), .lsu_awaddr(lsu_awaddr),
    .lsu_awid(lsu_awid), .lsu_awlen(lsu_awlen), .lsu_awsize(lsu_awsize),
    .lsu_awburst(lsu_awburst),
    .lsu_wvalid(lsu_wvalid), .lsu_wready(lsu_wready), .lsu_wdata(lsu_wdata),
    .lsu_wstrb(lsu_wstrb), .lsu_wlast(lsu_wlast),
    .lsu_bvalid(lsu_bvalid), .lsu_bready(lsu_bready), .lsu_bresp(lsu_bresp),
    .lsu_bid(lsu_bid)
  );

  Arbiter u_arbiter(
    .clk(clk), .rst(rst),
    .ifu_arvalid(ic_arvalid), .ifu_arready(ic_arready), .ifu_araddr(ic_araddr),
    .ifu_arlen(ic_arlen), .ifu_arburst(ic_arburst),
    .ifu_rvalid(ic_rvalid), .ifu_rready(ic_rready), .ifu_rdata(ic_rdata),
    .ifu_rlast(ic_rlast),
    .lsu_arvalid(lsu_arvalid), .lsu_arready(lsu_arready), .lsu_araddr(lsu_araddr),
    .lsu_arid(lsu_arid), .lsu_arlen(lsu_arlen), .lsu_arsize(lsu_arsize),
    .lsu_arburst(lsu_arburst),
    .lsu_rvalid(lsu_rvalid), .lsu_rready(lsu_rready), .lsu_rresp(lsu_rresp),
    .lsu_rdata(lsu_rdata), .lsu_rlast(lsu_rlast), .lsu_rid(lsu_rid),
    .lsu_awvalid(lsu_awvalid), .lsu_awready(lsu_awready), .lsu_awaddr(lsu_awaddr),
    .lsu_awid(lsu_awid), .lsu_awlen(lsu_awlen), .lsu_awsize(lsu_awsize),
    .lsu_awburst(lsu_awburst),
    .lsu_wvalid(lsu_wvalid), .lsu_wready(lsu_wready), .lsu_wdata(lsu_wdata),
    .lsu_wstrb(lsu_wstrb), .lsu_wlast(lsu_wlast),
    .lsu_bvalid(lsu_bvalid), .lsu_bready(lsu_bready), .lsu_bresp(lsu_bresp),
    .lsu_bid(lsu_bid),
    .clint_arvalid(clint_arvalid), .clint_arready(clint_arready),
    .clint_araddr(clint_araddr), .clint_arid(clint_arid),
    .clint_arlen(clint_arlen), .clint_arsize(clint_arsize),
    .clint_arburst(clint_arburst),
    .clint_rvalid(clint_rvalid), .clint_rready(clint_rready),
    .clint_rdata(clint_rdata), .clint_rresp(clint_rresp),
    .clint_rlast(clint_rlast), .clint_rid(clint_rid),
    .mem_arvalid(mem_arvalid), .mem_arready(mem_arready), .mem_araddr(mem_araddr),
    .mem_arid(mem_arid), .mem_arlen(mem_arlen), .mem_arsize(mem_arsize),
    .mem_arburst(mem_arburst),
    .mem_rvalid(mem_rvalid), .mem_rready(mem_rready), .mem_rresp(mem_rresp),
    .mem_rdata(mem_rdata), .mem_rlast(mem_rlast), .mem_rid(mem_rid),
    .mem_awvalid(mem_awvalid), .mem_awready(mem_awready), .mem_awaddr(mem_awaddr),
    .mem_awid(mem_awid), .mem_awlen(mem_awlen), .mem_awsize(mem_awsize),
    .mem_awburst(mem_awburst),
    .mem_wvalid(mem_wvalid), .mem_wready(mem_wready), .mem_wdata(mem_wdata),
    .mem_wstrb(mem_wstrb), .mem_wlast(mem_wlast),
    .mem_bvalid(mem_bvalid), .mem_bready(mem_bready), .mem_bresp(mem_bresp),
    .mem_bid(mem_bid)
  );

  CLINT u_clint(
    .clk(clk), .rst(rst),
    .mtime(mtime_shared),
    .clint_arvalid(clint_arvalid), .clint_arready(clint_arready),
    .clint_araddr(clint_araddr), .clint_arid(clint_arid),
    .clint_arlen(clint_arlen), .clint_arsize(clint_arsize),
    .clint_arburst(clint_arburst),
    .clint_rvalid(clint_rvalid), .clint_rready(clint_rready),
    .clint_rdata(clint_rdata), .clint_rresp(clint_rresp),
    .clint_rlast(clint_rlast), .clint_rid(clint_rid)
  );

  CSR u_csr(
    .clk(clk), .rst(rst),
    .csr_addr(csr_addr), .csr_wdata(csr_wdata), .csr_wen(csr_wen),
    .csr_rdata(csr_rdata), .is_ecall(csr_ecall), .pc(csr_pc),
    .mepc(mepc), .mtvec(mtvec),
    .mstatus_out(mstatus), .mcause_out(mcause),
    .mcycle_lo_out(mcycle_lo), .mcycle_hi_out(mcycle_hi)
  );

  assign pc = cur_pc;
  assign inst = cur_inst;
  assign imem_addr = fetch_pc;

`ifndef SOC_MODE
`ifndef SYNTHESIS
  PMEM u_pmem(
    .clk(clk), .rst(rst),
    .mem_arvalid(mem_arvalid), .mem_arready(mem_arready), .mem_araddr(mem_araddr),
    .mem_arid(mem_arid), .mem_arlen(mem_arlen), .mem_arsize(mem_arsize),
    .mem_arburst(mem_arburst),
    .mem_rvalid(mem_rvalid), .mem_rready(mem_rready), .mem_rresp(mem_rresp),
    .mem_rdata(mem_rdata), .mem_rlast(mem_rlast), .mem_rid(mem_rid),
    .mem_awvalid(mem_awvalid), .mem_awready(mem_awready), .mem_awaddr(mem_awaddr),
    .mem_awid(mem_awid), .mem_awlen(mem_awlen), .mem_awsize(mem_awsize),
    .mem_awburst(mem_awburst),
    .mem_wvalid(mem_wvalid), .mem_wready(mem_wready), .mem_wdata(mem_wdata),
    .mem_wstrb(mem_wstrb), .mem_wlast(mem_wlast),
    .mem_bvalid(mem_bvalid), .mem_bready(mem_bready), .mem_bresp(mem_bresp),
    .mem_bid(mem_bid)
  );
`endif

`ifdef SYNTHESIS
  reg        syn_rvalid;
  reg [ 7:0] syn_left;
  reg [ 3:0] syn_rid;

  assign mem_arready = !syn_rvalid || mem_rready;
  assign mem_rvalid  = syn_rvalid;
  assign mem_rresp   = 2'b00;
  assign mem_rdata   = imem_rdata;
  assign mem_rlast   = syn_rvalid && (syn_left == 8'd0);
  assign mem_rid     = syn_rid;
  assign mem_awready = 1'b1;
  assign mem_wready  = 1'b1;
  assign mem_bvalid  = 1'b1;
  assign mem_bresp   = 2'b00;
  assign mem_bid     = 4'b0010;

  always @(posedge clk) begin
    if (rst) begin
      syn_rvalid <= 1'b0;
      syn_left   <= 8'd0;
      syn_rid    <= 4'b0;
    end else begin
      if (mem_rvalid && mem_rready) begin
        if (syn_left != 8'd0) syn_left <= syn_left - 8'd1;
        else                  syn_rvalid <= 1'b0;
      end
      if (mem_arvalid && mem_arready) begin
        syn_rvalid <= 1'b1;
        syn_left   <= mem_arlen;
        syn_rid    <= mem_arid;
      end
    end
  end
`endif
`else
`endif

  // ======================= simulation-only tracing / perf =======================
`ifndef SYNTHESIS
  import "DPI-C" function void ebreak_handler(input int a0_value);
  import "DPI-C" function void ftrace_call_handler(input int pc_val, input int target_val);
  import "DPI-C" function void ftrace_ret_handler(input int pc_val);
  import "DPI-C" function void mtrace_event(input int pc_val, input int addr, input int data, input int len, input int is_store);
  import "DPI-C" function void commit_instruction(input int pc_val, input int inst_val, input int next_pc_val);
  import "DPI-C" function void update_pc_value(input int pc_val);
  import "DPI-C" function void update_csr_values(input int mstatus, input int mtvec, input int mepc, input int mcause, input int mcycle_lo, input int mcycle_hi);
  import "DPI-C" function void difftest_skip_ref();

`ifdef ENABLE_PERF
  localparam PERF_COMMIT       = 0;
  localparam PERF_IF_FETCH     = 1;
  localparam PERF_IF_STALL_BUS = 2;
  localparam PERF_IF_STALL_MEM = 3;
  localparam PERF_LD_DONE      = 4;
  localparam PERF_ST_DONE      = 5;
  localparam PERF_LD_WAIT      = 6;
  localparam PERF_ALU          = 7;
  localparam PERF_LOAD         = 8;
  localparam PERF_STORE        = 9;
  localparam PERF_BRANCH       = 10;
  localparam PERF_JUMP         = 11;
  localparam PERF_UPPER        = 12;
  localparam PERF_CSR          = 13;
  localparam PERF_ECALL        = 14;
  localparam PERF_MRET         = 15;
  localparam PERF_EBREAK       = 16;
  localparam PERF_IC_ACCESS    = 17;
  localparam PERF_IC_HIT       = 18;
  localparam PERF_IC_MISS      = 19;
  localparam PERF_IC_REFILL    = 20;
  localparam PERF_IC_BYPASS_AR = 21;
  localparam PERF_LSU_AR       = 22;
  localparam PERF_IF_BYPASS    = 23;
  localparam PERF_BRANCH_TAKEN = 24;
  localparam PERF_BRANCH_NOT_TAKEN = 25;
  localparam PERF_JAL          = 26;
  localparam PERF_JALR         = 27;
  localparam PERF_LD_BYTE      = 28;
  localparam PERF_LD_HALF      = 29;
  localparam PERF_LD_WORD      = 30;
  localparam PERF_ST_BYTE      = 31;
  localparam PERF_ST_HALF      = 32;
  localparam PERF_ST_WORD      = 33;
  localparam PERF_BUS_AR       = 34;
  localparam PERF_BUS_R        = 35;
  localparam PERF_BUS_AW       = 36;
  localparam PERF_BUS_W        = 37;
  localparam PERF_BUS_B        = 38;
  localparam PERF_BUS_AR_STALL = 39;
  localparam PERF_IC_COMPULSORY = 40;
  localparam PERF_IC_REPLACE   = 41;
  localparam PERF_ALU_R        = 42;
  localparam PERF_ALU_I        = 43;
  localparam PERF_CSRRW        = 44;
  localparam PERF_CSRRS        = 45;
  localparam PERF_ST_WAIT      = 46;
  localparam PERF_FENCE_I      = 47;

  import "DPI-C" function void perf_event(input int event_id);

  wire [6:0] r_op = retire_inst[6:0];
  wire [2:0] r_f3 = retire_inst[14:12];
  wire r_is_op    = (r_op == 7'b0110011);
  wire r_is_opimm = (r_op == 7'b0010011);
  wire r_is_load  = (r_op == 7'b0000011);
  wire r_is_store = (r_op == 7'b0100011);
  wire r_is_branch= (r_op == 7'b1100011);
  wire r_is_jal   = (r_op == 7'b1101111);
  wire r_is_jalr  = (r_op == 7'b1100111);
  wire r_is_upper = (r_op == 7'b0110111) || (r_op == 7'b0010111);
  wire r_is_csr   = (r_op == 7'b1110011) && ((r_f3 == 3'b001) || (r_f3 == 3'b010));
  wire r_is_ecall = (retire_inst == 32'h0000_0073);
  wire r_is_mret  = (retire_inst == 32'h3020_0073);
  wire r_is_ebreak= (retire_inst == 32'h0010_0073);
  wire r_is_fencei= (retire_inst == 32'h0000_100F);

  wire perf_if_stall_mem = fetch_req && !fetch_ready && !(ic_arvalid && !ic_arready);
  wire perf_ld_wait = dmem_valid && dmem_is_load  && !dmem_done;
  wire perf_st_wait = dmem_valid && dmem_is_store && !dmem_done;
  wire perf_ld_done = retire && retire_is_mem && !retire_is_store;
  wire perf_st_done = retire && retire_is_mem &&  retire_is_store;

  wire perf_ic_access     = fetch_accept && ic_cacheable;
  wire perf_ic_refill     = ic_arvalid && ic_arready && ic_fill_ar;
  wire perf_ic_bypass_ar  = ic_arvalid && ic_arready && ic_bypass_ar;
  wire perf_ic_compulsory = !icache_flush && ic_fill_start && !ic_victim_valid;
  wire perf_ic_replace    = !icache_flush && ic_fill_start &&  ic_victim_valid;
  wire perf_lsu_ar        = lsu_arvalid && lsu_arready;

  always @(posedge clk) begin
    if (!rst) begin
      if (retire)           perf_event(PERF_COMMIT);
      if (fetch_accept)     perf_event(PERF_IF_FETCH);
      if (ic_arvalid && !ic_arready) perf_event(PERF_IF_STALL_BUS);
      if (perf_if_stall_mem) perf_event(PERF_IF_STALL_MEM);
      if (perf_ld_done)     perf_event(PERF_LD_DONE);
      if (perf_st_done)      perf_event(PERF_ST_DONE);
      if (perf_ld_wait)      perf_event(PERF_LD_WAIT);
      if (perf_st_wait)      perf_event(PERF_ST_WAIT);

      if (perf_ic_access) begin
        perf_event(PERF_IC_ACCESS);
        if (ic_hit) perf_event(PERF_IC_HIT);
        else        perf_event(PERF_IC_MISS);
      end
      if (fetch_accept && !ic_cacheable) perf_event(PERF_IF_BYPASS);
      if (perf_ic_refill)     perf_event(PERF_IC_REFILL);
      if (perf_ic_bypass_ar)  perf_event(PERF_IC_BYPASS_AR);
      if (perf_ic_compulsory) perf_event(PERF_IC_COMPULSORY);
      if (perf_ic_replace)    perf_event(PERF_IC_REPLACE);
      if (perf_lsu_ar)        perf_event(PERF_LSU_AR);

      if (mem_arvalid && mem_arready)  perf_event(PERF_BUS_AR);
      if (mem_rvalid  && mem_rready)   perf_event(PERF_BUS_R);
      if (mem_awvalid && mem_awready)  perf_event(PERF_BUS_AW);
      if (mem_wvalid  && mem_wready)   perf_event(PERF_BUS_W);
      if (mem_bvalid  && mem_bready)   perf_event(PERF_BUS_B);
      if (mem_arvalid && !mem_arready) perf_event(PERF_BUS_AR_STALL);

      if (retire) begin
        if (r_is_op || r_is_opimm) begin
          perf_event(PERF_ALU);
          if (r_is_op) perf_event(PERF_ALU_R); else perf_event(PERF_ALU_I);
        end
        if (r_is_load) begin
          perf_event(PERF_LOAD);
          if (r_f3 == 3'b000 || r_f3 == 3'b100) perf_event(PERF_LD_BYTE);
          else if (r_f3 == 3'b001 || r_f3 == 3'b101) perf_event(PERF_LD_HALF);
          else perf_event(PERF_LD_WORD);
        end
        if (r_is_store) begin
          perf_event(PERF_STORE);
          if (r_f3 == 3'b000) perf_event(PERF_ST_BYTE);
          else if (r_f3 == 3'b001) perf_event(PERF_ST_HALF);
          else perf_event(PERF_ST_WORD);
        end
        if (r_is_branch) begin
          perf_event(PERF_BRANCH);
          if (retire_branch_taken) perf_event(PERF_BRANCH_TAKEN);
          else                     perf_event(PERF_BRANCH_NOT_TAKEN);
        end
        if (r_is_jal || r_is_jalr) begin
          perf_event(PERF_JUMP);
          if (r_is_jal)  perf_event(PERF_JAL);
          if (r_is_jalr) perf_event(PERF_JALR);
        end
        if (r_is_upper) perf_event(PERF_UPPER);
        if (r_is_csr) begin
          perf_event(PERF_CSR);
          if (r_f3 == 3'b001) perf_event(PERF_CSRRW);
          if (r_f3 == 3'b010) perf_event(PERF_CSRRS);
        end
        if (r_is_ecall)  perf_event(PERF_ECALL);
        if (r_is_mret)   perf_event(PERF_MRET);
        if (r_is_ebreak) perf_event(PERF_EBREAK);
        if (r_is_fencei) perf_event(PERF_FENCE_I);
      end
    end
  end
`endif

  wire [31:0] data_len = (retire_inst[13:12] == 2'b00) ? 32'd1 :
                         (retire_inst[13:12] == 2'b01) ? 32'd2 : 32'd4;

  always @(posedge clk) begin
    if (rst) begin
`ifdef SOC_MODE
      update_pc_value(32'h30000000);
`else
      update_pc_value(32'h80000000);
`endif
      update_csr_values(32'h00001800, 32'b0, 32'b0, 32'b0, 32'b0, 32'b0);
    end else begin
      update_csr_values(mstatus, mtvec, mepc, mcause, mcycle_lo, mcycle_hi);

      if (retire) begin
        commit_instruction(retire_pc, retire_inst, retire_next_pc);

        if (retire_is_mem) begin
          mtrace_event(retire_pc, retire_addr, retire_wdata,
                       data_len, {31'b0, retire_is_store});
        end

`ifdef SOC_MODE
        if (retire_is_mem &&
            ((retire_addr >= 32'h02000000 && retire_addr < 32'h02010000) ||
             (retire_addr >= 32'h10000000 && retire_addr < 32'h10020000) ||
             (retire_addr >= 32'h21000000 && retire_addr < 32'h22000000))) begin
          difftest_skip_ref();
        end
`endif

        if (retire_inst == 32'h00100073) begin
          $display("EBREAK detected at PC=0x%08x, a0=0x%08x", retire_pc, a0_value);
          ebreak_handler(a0_value);
        end

        if (retire_inst[6:0] == 7'b1100111) begin
          if (retire_inst[11:7] == 5'd1)
            ftrace_call_handler(retire_pc, retire_next_pc);
          else if (retire_inst[11:7] == 5'd0 && retire_inst[19:15] == 5'd1)
            ftrace_ret_handler(retire_pc);
        end
        if (retire_inst[6:0] == 7'b1101111 && retire_inst[11:7] == 5'd1)
          ftrace_call_handler(retire_pc, retire_next_pc);
      end
    end
  end
`endif

endmodule
