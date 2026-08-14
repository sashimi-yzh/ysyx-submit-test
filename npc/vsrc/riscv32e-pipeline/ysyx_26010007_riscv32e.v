`include "ysyx_26010007_defines.v"
module ysyx_26010007_riscv32e(
  input clock,
  input reset,

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

  output                    lsu_arvalid,
  input                     lsu_arready,
  output [`ysyx_26010007_PADDR_WIDTH-1:0] lsu_araddr,
  output [7:0]              lsu_arlen,
  output [2:0]              lsu_arsize,
  output [3:0]              lsu_arid,
  output [1:0]              lsu_arburst,

  input                     lsu_rvalid,
  output                    lsu_rready,
  input [`ysyx_26010007_WORD_WIDTH-1:0]   lsu_rdata,
  input [1:0]               lsu_rresp,
  input                     lsu_rlast,
  input [3:0]               lsu_rid,

  output                    lsu_awvalid,
  input                     lsu_awready,
  output [`ysyx_26010007_PADDR_WIDTH-1:0] lsu_awaddr,
  output [7:0]              lsu_awlen,
  output [2:0]              lsu_awsize,
  output [3:0]              lsu_awid,
  output [1:0]              lsu_awburst,

  output                    lsu_wvalid,
  input                     lsu_wready,
  output [`ysyx_26010007_WORD_WIDTH-1:0]  lsu_wdata,
  output [3:0]              lsu_wstrb,
  output                    lsu_wlast,

  input                     lsu_bvalid,
  output                    lsu_bready,
  input  [1:0]              lsu_bresp,
  input  [3:0]              lsu_bid
);
`ifdef ysyx_26010007_debug
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_idu_pc;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_idu_inst;
  wire                      debug_idu_is_ret;   
  wire                      debug_idu_is_call;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_exu_pc;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_exu_inst;
  wire                      debug_exu_is_ret;
  wire                      debug_exu_is_call;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_lsu_pc;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_lsu_inst;
  wire                      debug_lsu_is_ret;
  wire                      debug_lsu_is_call;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_wbu_pc;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_wbu_inst;
  wire                      debug_wbu_is_ret;
  wire                      debug_wbu_is_call;
  
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_exu_jaddr;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_lsu_jaddr;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_wbu_jaddr;
`endif

  // 握手信号
  wire ifu_valid_o;
  wire ifu_ready_o;

  wire idu_valid_i;
  wire idu_ready_i;
  wire idu_ready_o;
  wire idu_valid_o;

  wire exu_ready_i;
  wire exu_valid_i;
  wire exu_ready_o;
  wire exu_valid_o;

  wire lsu_ready_i;
  wire lsu_valid_i;
  wire lsu_ready_o;
  wire lsu_valid_o;

  wire wbu_valid_i;

  // ifu - icache
  wire                    ifu_arvalid;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]  ifu_araddr;
  
  wire                    icache_iarready;
  wire                    icache_irvalid;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]  icache_irdata;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]  icache_ipc;
  // fence
  wire                    fence_flush;

  // ifu - idu
  wire [`ysyx_26010007_PADDR_WIDTH-1:0] ifu_pc;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]  ifu_inst;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]  idu_pc;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]  idu_inst;
  // exu - ifu
  wire [`ysyx_26010007_PADDR_WIDTH-1:0] jump_addr;
  wire                    jump_flag;
  // CSR - ifu
  wire [`ysyx_26010007_PADDR_WIDTH-1:0] exc_jump_addr;
  wire                    exc_jump_flag;

  // idu - RegsFile
  wire [`ysyx_26010007_WORD_WIDTH-1:0]      rd1;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]      rd2;
  wire [`ysyx_26010007_REG_ADDR_WIDTH-1:0]  ra1;
  wire [`ysyx_26010007_REG_ADDR_WIDTH-1:0]  ra2;
  // idu - CsrsFile
  wire [`ysyx_26010007_CSR_ADDR_WIDTH-1:0]  csra;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]      csrrd;
  // idu - exu
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    idu_SrcA;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    idu_SrcB;
  wire [`ysyx_26010007_ALU_OP_WIDTH-1:0]  idu_ALU_OP;
  wire                      idu_wreg;
  wire [`ysyx_26010007_REG_ADDR_WIDTH-1:0]idu_wa;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    idu_plusImm;
  wire [1:0]                idu_jump_op;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    idu_MemWdata;
  wire [`ysyx_26010007_MEMMASK_WIDTH-1:0] idu_MemMask;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    idu_csrwd;
  wire                      idu_csrwen;
  wire [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] idu_exc_event;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    exu_SrcA;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    exu_SrcB;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    exu_pc;
  wire [`ysyx_26010007_ALU_OP_WIDTH-1:0]  exu_ALU_OP;
  wire                      exu_wreg;
  wire [`ysyx_26010007_REG_ADDR_WIDTH-1:0]exu_wa;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    exu_plusImm;
  wire [1:0]                exu_jump_op;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    exu_MemWdata;
  wire [`ysyx_26010007_MEMMASK_WIDTH-1:0] exu_MemMask;
  wire [`ysyx_26010007_CSR_ADDR_WIDTH-1:0]exu_csra;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    exu_csrwd;
  wire                      exu_csrwen;
  wire [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] exu_exc_event;

  // exu - lsu
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    exu_res;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    lsu_pc;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    lsu_addr;
  wire                      lsu_wreg;
  wire [`ysyx_26010007_REG_ADDR_WIDTH-1:0]lsu_wa;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    lsu_MemWdata;
  wire [`ysyx_26010007_MEMMASK_WIDTH-1:0] lsu_MemMask;
  wire [`ysyx_26010007_CSR_ADDR_WIDTH-1:0]lsu_csra;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    lsu_csrwd;
  wire                      lsu_csrwen;
  wire [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] lsu_exc_event;

  // lsu - wbu
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    lsu_wd;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    wbu_pc;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    wbu_wd;
  wire                      wbu_wreg;
  wire [`ysyx_26010007_REG_ADDR_WIDTH-1:0]wbu_wa;
  wire [`ysyx_26010007_CSR_ADDR_WIDTH-1:0]wbu_csra;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]    wbu_csrwd;
  wire                      wbu_csrwen;
  wire [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] wbu_exc_event;

  ysyx_26010007_icache ICACHE0(
    .clock(clock),
    .reset(reset),
    .fence_flush(fence_flush & idu_valid_o),

    .ifu_arvalid(ifu_arvalid),
    .ifu_araddr(ifu_araddr),
    .icache_iarready(icache_iarready),
    .icache_irvalid(icache_irvalid),
    .icache_irdata(icache_irdata),
    .icache_ipc(icache_ipc),

    .icache_arvalid(icache_arvalid),
    .icache_arready(icache_arready),
    .icache_araddr(icache_araddr),
    .icache_arlen(icache_arlen),
    .icache_arsize(icache_arsize),
    .icache_arid(icache_arid),
    .icache_arburst(icache_arburst),
    .icache_rvalid(icache_rvalid),
    .icache_rready(icache_rready),
    .icache_rdata(icache_rdata),
    .icache_rresp(icache_rresp),
    .icache_rlast(icache_rlast),
    .icache_rid(icache_rid)
  );
  
  ysyx_26010007_IFU IFU0(
    .clock(clock),
    .reset(reset),
    // 握手信号
    .ifu_valid_o(ifu_valid_o),
    .ifu_ready_o(ifu_ready_o),
    // ifu - icache
    .ifu_arvalid(ifu_arvalid),
    .ifu_araddr(ifu_araddr),
    .icache_iarready(icache_iarready),
    .icache_irvalid(icache_irvalid),
    .icache_irdata(icache_irdata),
    .icache_ipc(icache_ipc),
    // 传输至idu的数据
    .ifu_inst(ifu_inst),
    .ifu_pc(ifu_pc),
    // Jump Target
    .jump_addr(jump_addr),
    .jump_flag(jump_flag & exu_valid_o & exu_ready_o),
    
    .exc_jump_addr(exc_jump_addr),
    .exc_jump_flag(exc_jump_flag & wbu_valid_i),

    .idu_pc(idu_pc),
    .fence_flush(fence_flush & idu_valid_o)
  );

  ysyx_26010007_ifu2idu pipeline_ifu2idu(
    .clock(clock),
    .reset(reset),
    .flush(jump_flag & exu_valid_o & exu_ready_o | exc_jump_flag & wbu_valid_i | fence_flush & idu_valid_o),

    .ifu_valid_o(ifu_valid_o),
    .ifu_ready_o(ifu_ready_o),
    .idu_ready_i(idu_ready_i),
    .idu_valid_i(idu_valid_i),
    .ifu_pc(ifu_pc),
    .ifu_inst(ifu_inst),
    .idu_pc(idu_pc),
    .idu_inst(idu_inst)
  );

  ysyx_26010007_CSR CSR0(
    .clock(clock),
    .reset(reset),

    .pc(wbu_pc),
    .csrwdata(wbu_csrwd),
    .csrwen(wbu_valid_i & wbu_csrwen),
    .csrwaddr(wbu_csra),
    .csrraddr(csra),
    .csrrdata(csrrd),
    .exc_event(wbu_exc_event),
    .exc_jump_addr(exc_jump_addr),
    .exc_jump_flag(exc_jump_flag)
  );

  ysyx_26010007_RegisterFile RegisterFile0(
    .clock(clock),
    .wdata(wbu_wd),
    .waddr(wbu_wa),
    .wen(wbu_valid_i & wbu_wreg),
    .r1addr(ra1),
    .r2addr(ra2),
    .r1data(rd1),
    .r2data(rd2)
  );

  ysyx_26010007_IDU IDU0(
`ifdef ysyx_26010007_debug
    .clock(clock),
    .debug_idu_pc(debug_idu_pc),
    .debug_idu_inst(debug_idu_inst),
    .debug_idu_is_call(debug_idu_is_call),
    .debug_idu_is_ret(debug_idu_is_ret),
`endif
    // 握手信号
    .idu_valid_i(idu_valid_i),
    .idu_ready_i(idu_ready_i),
    .idu_valid_o(idu_valid_o),
    .idu_ready_o(idu_ready_o),

    // 来自ifu的数据
    .idu_inst(idu_inst),
    .idu_pc(idu_pc),

    // forwarding
    .exu_wd(exu_res),
    .exu_wa(exu_wa),
    .exu_wen(exu_valid_i & exu_wreg),
    .exu_Mem2reg(exu_MemMask[4] & exu_valid_i),
    .lsu_wd(lsu_wd),
    .lsu_wa(lsu_wa),
    .lsu_wen(lsu_valid_i & lsu_wreg),
    .lsu_Mem2reg(lsu_MemMask[4] & lsu_valid_i),

    .exu_csrwd  (exu_csrwd  ),
    .exu_csra   (exu_csra   ),
    .exu_csrwen (exu_valid_i & exu_csrwen ),
    .lsu_csrwd  (lsu_csrwd  ),
    .lsu_csra   (lsu_csra   ),
    .lsu_csrwen (lsu_valid_i & lsu_csrwen ),

    // 读通用寄存器的信号
    .rd1(rd1),
    .rd2(rd2),
    .ra1(ra1),
    .ra2(ra2),

    // 传输到exu的数据
    .SrcA(idu_SrcA),
    .SrcB(idu_SrcB),
    .ALU_OP(idu_ALU_OP),
    .plusImm(idu_plusImm),
    .jump_op(idu_jump_op),
    .wreg(idu_wreg),
    .wa(idu_wa),
    .MemWdata(idu_MemWdata),
    .MemMask(idu_MemMask),

    // 读写CSR的信号
    .csrrd(csrrd),
    .csra(csra),
    .csrwd(idu_csrwd),
    .csrwen(idu_csrwen),
    .exc_event(idu_exc_event),
    
    // fence
    .exu_MemWrite(exu_valid_i & exu_MemMask[3]),
    .lsu_MemWrite(lsu_valid_i & lsu_MemMask[3]),
    .fence_flush(fence_flush)
  );

  ysyx_26010007_idu2exu pipeline_idu2exu(
`ifdef ysyx_26010007_debug
  .debug_idu_pc(debug_idu_pc),
  .debug_idu_inst(debug_idu_inst),
  .debug_idu_is_call(debug_idu_is_call),
  .debug_idu_is_ret(debug_idu_is_ret),
  .debug_exu_pc(debug_exu_pc),
  .debug_exu_inst(debug_exu_inst),
  .debug_exu_is_call(debug_exu_is_call),
  .debug_exu_is_ret(debug_exu_is_ret),
`endif
    .clock(clock),
    .reset(reset),
    .flush(jump_flag & exu_valid_o & exu_ready_o | exc_jump_flag & wbu_valid_i),

    .idu_valid_o(idu_valid_o),
    .idu_ready_o(idu_ready_o),
    .exu_ready_i(exu_ready_i),
    .exu_valid_i(exu_valid_i),

    .idu_SrcA(idu_SrcA),
    .idu_SrcB(idu_SrcB),
    .idu_ALU_OP(idu_ALU_OP),
    .idu_plusImm(idu_plusImm),
    .idu_jump_op(idu_jump_op),
    .idu_pc(idu_pc),
    .idu_wreg(idu_wreg),
    .idu_wa(idu_wa),
    .idu_MemMask(idu_MemMask),
    .idu_MemWdata(idu_MemWdata),
    .idu_csrwen(idu_csrwen),
    .idu_csra(csra),
    .idu_csrwd(idu_csrwd),
    .idu_exc_event(idu_exc_event),

    .exu_SrcA(exu_SrcA),
    .exu_SrcB(exu_SrcB),
    .exu_ALU_OP(exu_ALU_OP),
    .exu_plusImm(exu_plusImm),
    .exu_jump_op(exu_jump_op),
    .exu_pc(exu_pc),
    .exu_wreg(exu_wreg),
    .exu_wa(exu_wa),
    .exu_MemMask(exu_MemMask),
    .exu_MemWdata(exu_MemWdata),
    .exu_csrwen(exu_csrwen),
    .exu_csra(exu_csra),
    .exu_csrwd(exu_csrwd),
    .exu_exc_event(exu_exc_event)
  );

  ysyx_26010007_EXU EXU0(
`ifdef ysyx_26010007_debug
  .debug_exu_jaddr(debug_exu_jaddr),
`endif
    // 握手信号
    .exu_valid_i(exu_valid_i),
    .exu_ready_i(exu_ready_i),
    .exu_valid_o(exu_valid_o),
    .exu_ready_o(exu_ready_o),

    // 来自idu的信号
    .exu_SrcA(exu_SrcA),
    .exu_SrcB(exu_SrcB),
    .exu_ALU_OP(exu_ALU_OP),
    .exu_pc(exu_pc),
    .exu_plusImm(exu_plusImm),
    .exu_jump_op(exu_jump_op),

    // 传输到lsu的信号
    .res(exu_res),

    // 传输到ifu的信号
    .jump_addr(jump_addr),
    .jump_flag(jump_flag)
  );

  ysyx_26010007_exu2lsu pipeline_exu2lsu(
`ifdef ysyx_26010007_debug
    .debug_exu_pc(debug_exu_pc),
    .debug_exu_inst(debug_exu_inst),
    .debug_exu_jaddr(debug_exu_jaddr),
    .debug_exu_is_call(debug_exu_is_call),
    .debug_exu_is_ret(debug_exu_is_ret),
    .debug_lsu_pc(debug_lsu_pc),
    .debug_lsu_inst(debug_lsu_inst),
    .debug_lsu_jaddr(debug_lsu_jaddr),
    .debug_lsu_is_call(debug_lsu_is_call),
    .debug_lsu_is_ret(debug_lsu_is_ret),
`endif
    .clock(clock),
    .reset(reset),
    .flush(exc_jump_flag & wbu_valid_i),

    .exu_valid_o(exu_valid_o),
    .exu_ready_o(exu_ready_o),
    .lsu_ready_i(lsu_ready_i),
    .lsu_valid_i(lsu_valid_i),

    .exu_res(exu_res),
    .exu_pc(exu_pc),
    .exu_wreg(exu_wreg),
    .exu_wa(exu_wa),
    .exu_MemMask(exu_MemMask),
    .exu_MemWdata(exu_MemWdata),
    .exu_csrwen(exu_csrwen),
    .exu_csra(exu_csra),
    .exu_csrwd(exu_csrwd),
    .exu_exc_event(exu_exc_event),

    .lsu_addr(lsu_addr),
    .lsu_pc(lsu_pc),
    .lsu_wreg(lsu_wreg),
    .lsu_wa(lsu_wa),
    .lsu_MemMask(lsu_MemMask),
    .lsu_MemWdata(lsu_MemWdata),
    .lsu_csrwen(lsu_csrwen),
    .lsu_csra(lsu_csra),
    .lsu_csrwd(lsu_csrwd),
    .lsu_exc_event(lsu_exc_event)
  );

  ysyx_26010007_LSU LSU0(
    .clock(clock),
    .reset(reset),
    // 握手信号
    .lsu_valid_i(lsu_valid_i),
    .lsu_ready_i(lsu_ready_i),
    .lsu_valid_o(lsu_valid_o),
    .lsu_ready_o(lsu_ready_o),
    // 来自exu的信号
    .lsu_addr(lsu_addr),
    .lsu_MemMask(lsu_MemMask),
    .lsu_MemWdata(lsu_MemWdata),
    // 传输到wbu的信号
    .lsu_wd(lsu_wd),

    // DRAM
    .lsu_arvalid(lsu_arvalid),
    .lsu_arready(lsu_arready),
    .lsu_araddr(lsu_araddr),
    .lsu_arlen(lsu_arlen),
    .lsu_arsize(lsu_arsize),
    .lsu_arid(lsu_arid),
    .lsu_arburst(lsu_arburst),
    .lsu_rvalid(lsu_rvalid),
    .lsu_rready(lsu_rready),
    .lsu_rdata(lsu_rdata),
    .lsu_rresp(lsu_rresp),
    .lsu_rlast(lsu_rlast),
    .lsu_rid(lsu_rid),
    .lsu_awvalid(lsu_awvalid),
    .lsu_awready(lsu_awready),
    .lsu_awaddr(lsu_awaddr),
    .lsu_awlen(lsu_awlen),
    .lsu_awsize(lsu_awsize),
    .lsu_awid(lsu_awid),
    .lsu_awburst(lsu_awburst),
    .lsu_wvalid(lsu_wvalid),
    .lsu_wready(lsu_wready),
    .lsu_wdata(lsu_wdata),
    .lsu_wstrb(lsu_wstrb),
    .lsu_wlast(lsu_wlast),
    .lsu_bvalid(lsu_bvalid),
    .lsu_bready(lsu_bready),
    .lsu_bresp(lsu_bresp),
    .lsu_bid(lsu_bid)
  );

  ysyx_26010007_lsu2wbu pipeline_lsu2wbu(
`ifdef ysyx_26010007_debug
    .debug_lsu_pc(debug_lsu_pc),
    .debug_lsu_inst(debug_lsu_inst),
    .debug_lsu_jaddr(debug_lsu_jaddr),
    .debug_lsu_is_call(debug_lsu_is_call),
    .debug_lsu_is_ret(debug_lsu_is_ret),
    .debug_wbu_pc(debug_wbu_pc),
    .debug_wbu_inst(debug_wbu_inst),
    .debug_wbu_jaddr(debug_wbu_jaddr),
    .debug_wbu_is_call(debug_wbu_is_call),
    .debug_wbu_is_ret(debug_wbu_is_ret),
`endif
    .clock(clock),
    .reset(reset),
    .flush(exc_jump_flag & wbu_valid_i),

    .lsu_valid_o(lsu_valid_o),
    .lsu_ready_o(lsu_ready_o),
    .wbu_valid_i(wbu_valid_i),
    .wbu_ready_i(1'b1),

    .lsu_pc(lsu_pc),
    .lsu_wa(lsu_wa),
    .lsu_wreg(lsu_wreg),
    .lsu_wd(lsu_wd),
    .lsu_csrwen(lsu_csrwen),
    .lsu_csra(lsu_csra),
    .lsu_csrwd(lsu_csrwd),
    .lsu_exc_event(lsu_exc_event),

    .wbu_pc(wbu_pc),
    .wbu_wa(wbu_wa),
    .wbu_wreg(wbu_wreg),
    .wbu_wd(wbu_wd),
    .wbu_csrwen(wbu_csrwen),
    .wbu_csra(wbu_csra),
    .wbu_csrwd(wbu_csrwd),
    .wbu_exc_event(wbu_exc_event)
  );
`ifdef ysyx_26010007_debug
  always @(posedge clock) begin
    if(lsu_rready && lsu_rvalid) event_count(1);
    if(lsu_bready && lsu_bvalid) event_count(2);
    if(exu_valid_o && exu_ready_o) event_count(3);
    if(exu_valid_o && exu_ready_o && jump_flag) event_count(20);
  end
  export "DPI-C" function npc_inst;
  function int npc_inst();
    npc_inst = debug_wbu_inst;
  endfunction

  export "DPI-C" function npc_pc;
  function int npc_pc();
    npc_pc = debug_wbu_pc;
  endfunction

  export "DPI-C" function npc_npc;
  function int npc_npc();
    npc_npc = exc_jump_flag ? exc_jump_addr : debug_wbu_jaddr;
  endfunction

  export "DPI-C" function npc_wbu_valid;
  function int npc_wbu_valid();
    npc_wbu_valid = {31'd0, wbu_valid_i};
  endfunction

  export "DPI-C" function npc_wbu_is_call;
  function int npc_wbu_is_call();
    npc_wbu_is_call = {31'd0, debug_wbu_is_call};
  endfunction

  export "DPI-C" function npc_wbu_is_ret;
  function int npc_wbu_is_ret();
    npc_wbu_is_ret = {31'd0, debug_wbu_is_ret};
  endfunction
`endif
endmodule