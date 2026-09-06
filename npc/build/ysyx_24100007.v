module ysyx_24100007(
    input clock,
    input reset,
    input io_interrupt,

    input               io_master_awready,
    output              io_master_awvalid,
    output [31:0]       io_master_awaddr,
    output [3:0]        io_master_awid,
    output [7:0]        io_master_awlen,
    output [2:0]        io_master_awsize,
    output [1:0]        io_master_awburst,

    input               io_master_wready,
    output              io_master_wvalid,
    output [31:0]       io_master_wdata,
    output [3:0]        io_master_wstrb,
    output              io_master_wlast,

    output              io_master_bready,
    input               io_master_bvalid,
    input  [1:0]        io_master_bresp,
    input  [3:0]        io_master_bid,

    input               io_master_arready,
    output              io_master_arvalid,
    output [31:0]       io_master_araddr,
    output [3:0]        io_master_arid,
    output [7:0]        io_master_arlen,
    output [2:0]        io_master_arsize,
    output [1:0]        io_master_arburst,

    output              io_master_rready,
    input               io_master_rvalid,
    input  [1:0]        io_master_rresp,
    input  [31:0]       io_master_rdata,
    input               io_master_rlast,
    input  [3:0]        io_master_rid,

    // the signal below not used
    output              io_slave_awready,
    input               io_slave_awvalid,
    input  [31:0]       io_slave_awaddr,
    input  [3:0]        io_slave_awid,
    input  [7:0]        io_slave_awlen,
    input  [2:0]        io_slave_awsize,
    input  [1:0]        io_slave_awburst,

    output              io_slave_wready,
    input               io_slave_wvalid,
    input  [31:0]       io_slave_wdata,
    input  [3:0]        io_slave_wstrb,
    input               io_slave_wlast,

    input               io_slave_bready,
    output              io_slave_bvalid,
    output [1:0]        io_slave_bresp,
    output [3:0]        io_slave_bid,

    output              io_slave_arready,
    input               io_slave_arvalid,
    input  [31:0]       io_slave_araddr,
    input  [3:0]        io_slave_arid,
    input  [7:0]        io_slave_arlen,
    input  [2:0]        io_slave_arsize,
    input  [1:0]        io_slave_arburst,

    input               io_slave_rready,
    output              io_slave_rvalid,
    output [1:0]        io_slave_rresp,
    output [31:0]       io_slave_rdata,
    output              io_slave_rlast,
    output [3:0]        io_slave_rid
);

  wire core_awvalid;
  wire core_wvalid;
  wire core_arvalid;
  wire core_rready;
  wire core_bready;
  wire core_bvalid;
  wire core_rvalid;
  wire core_awready;
  wire core_wready;
  wire core_arready;
  wire [31:0] core_araddr;
  wire [31:0] core_awaddr;
  wire [31:0] core_wdata;
  wire [31:0] core_rdata;
  wire [3:0] core_wstrb;
  wire [1:0] core_bresp;
  wire [2:0] core_awsize;
  wire [2:0] core_arsize;
  wire [7:0] core_awlen;
  wire [7:0] core_arlen;
  wire [1:0] core_awburst;
  wire [1:0] core_arburst;
  wire core_wlast;
  wire core_rlast;
  wire [1:0] core_rresp;

  ysyx_24100007_core #(.PORT_NUM(1)) core0(
    .clock(clock),
    .reset(reset),
    .io_interrupt(io_interrupt),

    // AXI接口连接到arbiter
    .awvalid(core_awvalid),
    .wvalid(core_wvalid),
    .arvalid(core_arvalid),
    .rready(core_rready),
    .bready(core_bready),
    .bvalid(core_bvalid),
    .rvalid(core_rvalid),
    .awready(core_awready),
    .wready(core_wready),
    .arready(core_arready),
    .araddr(core_araddr),
    .awaddr(core_awaddr),
    .wdata(core_wdata),
    .rdata(core_rdata),
    .wstrb(core_wstrb),
    .bresp(core_bresp),
    .awsize(core_awsize),
    .arsize(core_arsize),
    .awlen(core_awlen),
    .arlen(core_arlen),
    .awburst(core_awburst),
    .arburst(core_arburst),
    .wlast(core_wlast),
    .rlast(core_rlast),
    .rresp(core_rresp)
  );

  assign core_rresp = io_master_rresp;

  // Arbiter模块
  wire [63:0] arbiter_araddr_out, arbiter_awaddr_out;
  wire [63:0] arbiter_wdata_out;
  wire [7:0] arbiter_wstrb_out;
  wire [5:0] arbiter_awsize_out, arbiter_arsize_out;
  wire [15:0] arbiter_awlen_out, arbiter_arlen_out;
  wire [3:0] arbiter_awburst_out, arbiter_arburst_out;
  wire [1:0] arbiter_wlast_out;
  wire [1:0] arbiter_awvalid_out, arbiter_wvalid_out, arbiter_arvalid_out;
  wire [1:0] arbiter_rready_out, arbiter_bready_out;
  wire [1:0] arbiter_bvalid_in, arbiter_rvalid_in;
  wire [1:0] arbiter_awready_in, arbiter_wready_in, arbiter_arready_in;
  wire [63:0] arbiter_rdata_in;
  wire [3:0] arbiter_bresp_in;
  wire [1:0] arbiter_rlast_in;

  ysyx_24100007_arbiter #(.SLAVE_NUM(2)) arbiter0(
    .clk(clock),
    .rst(reset),

    // Master接口 - 来自core
    .awvalid(core_awvalid),
    .wvalid(core_wvalid),
    .arvalid(core_arvalid),
    .rready(core_rready),
    .bready(core_bready),
    .bvalid(core_bvalid),
    .rvalid(core_rvalid),
    .awready(core_awready),
    .wready(core_wready),
    .arready(core_arready),
    .araddr(core_araddr),
    .awaddr(core_awaddr),
    .wdata(core_wdata),
    .rdata(core_rdata),
    .wstrb(core_wstrb),
    .bresp(core_bresp),
    .awsize(core_awsize),
    .arsize(core_arsize),
    .awlen(core_awlen),
    .arlen(core_arlen),
    .awburst(core_awburst),
    .arburst(core_arburst),
    .wlast(core_wlast),
    .rlast(core_rlast),

    // Slave接口 - 连接到CLINT和外部AXI
    .awvalid_out(arbiter_awvalid_out),
    .wvalid_out(arbiter_wvalid_out),
    .arvalid_out(arbiter_arvalid_out),
    .rready_out(arbiter_rready_out),
    .bready_out(arbiter_bready_out),
    .bvalid_in(arbiter_bvalid_in),
    .rvalid_in(arbiter_rvalid_in),
    .awready_in(arbiter_awready_in),
    .wready_in(arbiter_wready_in),
    .arready_in(arbiter_arready_in),
    .araddr_out(arbiter_araddr_out),
    .awaddr_out(arbiter_awaddr_out),
    .wdata_out(arbiter_wdata_out),
    .wstrb_out(arbiter_wstrb_out),
    .rdata_in(arbiter_rdata_in),
    .bresp_in(arbiter_bresp_in),
    .awsize_out(arbiter_awsize_out),
    .arsize_out(arbiter_arsize_out),
    .awlen_out(arbiter_awlen_out),
    .arlen_out(arbiter_arlen_out),
    .awburst_out(arbiter_awburst_out),
    .arburst_out(arbiter_arburst_out),
    .wlast_out(arbiter_wlast_out),
    .rlast_in(arbiter_rlast_in)
  );

  // ---------------------------------
  // CLINT (Core Local Interruptor)
  // ---------------------------------
  // CLINT地址范围：0x02000000 - 0x0200ffff
    ysyx_24100007_clint clint0(
    .clk(clock),
    .reset(reset),
    .awvalid(arbiter_awvalid_out[1]),
    .awready(arbiter_awready_in[1]),
    .awaddr(arbiter_awaddr_out[63:32]),
    .awsize(arbiter_awsize_out[5:3]),
    .wvalid(arbiter_wvalid_out[1]),
    .wready(arbiter_wready_in[1]),
    .wdata(arbiter_wdata_out[63:32]),
    .wstrb(arbiter_wstrb_out[7:4]),
    .arvalid(arbiter_arvalid_out[1]),
    .arready(arbiter_arready_in[1]),
    .araddr(arbiter_araddr_out[63:32]),
    .arsize(arbiter_arsize_out[5:3]),
    .rvalid(arbiter_rvalid_in[1]),
    .rready(arbiter_rready_out[1]),
    .rdata(arbiter_rdata_in[63:32]),
    .bvalid(arbiter_bvalid_in[1]),
    .bready(arbiter_bready_out[1]),
    .bresp(arbiter_bresp_in[3:2])
  );

    // 外部AXI接口直接连接到arbiter slave[0]
  assign io_master_awvalid = arbiter_awvalid_out[0];
  assign io_master_wvalid = arbiter_wvalid_out[0];
  assign io_master_arvalid = arbiter_arvalid_out[0];
  assign io_master_rready = arbiter_rready_out[0];
  assign io_master_bready = arbiter_bready_out[0];
  assign io_master_araddr = arbiter_araddr_out[31:0];
  assign io_master_awaddr = arbiter_awaddr_out[31:0];
  assign io_master_wdata = arbiter_wdata_out[31:0];
  assign io_master_wstrb = arbiter_wstrb_out[3:0];
  assign io_master_awsize = arbiter_awsize_out[2:0];
  assign io_master_arsize = arbiter_arsize_out[2:0];
  assign io_master_awlen = arbiter_awlen_out[7:0];
  assign io_master_arlen = arbiter_arlen_out[7:0];
  assign io_master_awburst = arbiter_awburst_out[1:0];
  assign io_master_arburst = arbiter_arburst_out[1:0];
  assign io_master_wlast = arbiter_wlast_out[0];

  // arbiter slave[0]输入来自外部AXI
  assign arbiter_bvalid_in[0] = io_master_bvalid;
  assign arbiter_rvalid_in[0] = io_master_rvalid;
  assign arbiter_awready_in[0] = io_master_awready;
  assign arbiter_wready_in[0] = io_master_wready;
  assign arbiter_arready_in[0] = io_master_arready;
  assign arbiter_rdata_in[31:0] = io_master_rdata;
  assign arbiter_bresp_in[1:0] = io_master_bresp;
  assign arbiter_rlast_in[0] = io_master_rlast;

  assign arbiter_rlast_in[1] = arbiter_rvalid_in[1];

  assign io_master_awid = 4'b0;
  assign io_master_arid = 4'd0;

  assign io_slave_awready = 1'b0;
  assign io_slave_wready  = 1'b0;
  assign io_slave_bvalid  = 1'b0;
  assign io_slave_bresp   = 2'b00;
  assign io_slave_bid     = 4'b0000;
  assign io_slave_arready = 1'b0;
  assign io_slave_rvalid  = 1'b0;
  assign io_slave_rresp   = 2'b00;
  assign io_slave_rdata   = 32'b0;
  assign io_slave_rlast   = 1'b0;
  assign io_slave_rid     = 4'b0000;

endmodule

`define   ysyx_24100007_ADD       4'b0001
`define   ysyx_24100007_SUB       4'b0011
`define   ysyx_24100007_SLL       4'b1100
`define   ysyx_24100007_SLT       4'b1001
`define   ysyx_24100007_SLTU      4'b1000
`define   ysyx_24100007_XOR       4'b0110
`define   ysyx_24100007_SRL       4'b1101
`define   ysyx_24100007_SRA       4'b1110
`define   ysyx_24100007_OR        4'b0101
`define   ysyx_24100007_AND       4'b0100

module ysyx_24100007_alucontrol(
  input [2:0] func3,
  input func7,
  input [1:0] aluop,
  input jalrsig,
  input is_csr,
  
  output [4:0] aluopcode
);
  wire type_I, type_B, type_R;
  wire [3:0] branchop;
  reg [3:0] IRop;
  assign type_I = (aluop == 2'b01);
  assign type_B = (aluop == 2'b11);
  assign type_R = (aluop == 2'b10);
  
  assign branchop=(func3[2] & func3[1])? `ysyx_24100007_SLTU : (func3[2] ^ func3[1])? `ysyx_24100007_SLT : `ysyx_24100007_SUB;

  always @(*) begin
    case(func3)
    3'b000: begin
    if(type_R & func7) begin
      IRop = `ysyx_24100007_SUB;
    end else begin
      IRop = `ysyx_24100007_ADD;
    end
    end
    3'b001: IRop=`ysyx_24100007_SLL;
    3'b010: begin
      if(jalrsig)
        IRop = `ysyx_24100007_ADD;
      else
        IRop=`ysyx_24100007_SLT;
    end
		3'b011: IRop=`ysyx_24100007_SLTU;
		3'b100: IRop=`ysyx_24100007_XOR;
		3'b101: begin
    if(func7) begin
			IRop=`ysyx_24100007_SRA;
    end else
			IRop=`ysyx_24100007_SRL;
    end
		3'b110: IRop=`ysyx_24100007_OR;
		3'b111: IRop=`ysyx_24100007_AND;
		default:IRop=`ysyx_24100007_ADD;
    endcase
  end

  wire [4:0] aluopcode_I = {(type_I)? 1'b1:1'b0,(type_B==1)?branchop:(type_R|type_I == 1)?IRop:`ysyx_24100007_ADD};
  wire [4:0] aluopcode_csr = {1'b0, `ysyx_24100007_ADD};
  assign aluopcode = (is_csr) ? aluopcode_csr : aluopcode_I;
endmodule

module ysyx_24100007_alu (
    input [31:0] A,
    input [31:0] B,
    input [4:0] op,
    output reg [31:0] res,
    output zero,
    output signal,
    output carry
);
  wire addsig, logsig, shfsig, sltsig;
  reg carry_tmp;

  assign addsig = !(op[3] | op[2]);
  assign logsig = (op[3] == 0) & (op[2] == 1);
  assign shfsig = (op[3] & op[2]);
  assign sltsig = (op[3] == 1) & (op[2] == 0);

  wire type_I = op[4];
  // logic part
  reg [31:0] logres;
  always @(*) begin
    case (op[1:0])
      2'b00: logres = (type_I) ? A & $signed(B) : A & B;
      2'b01: logres = A | B;
      2'b10: logres = A ^ B;
      2'b11: logres = ~(A | B);
    endcase
  end

  // add part
  reg [31:0] addres;
  always @(*) begin
    case (op[0] ^ op[1])
      1'b1: {carry_tmp, addres} = {1'b0, A} + {1'b0, B};
      1'b0: {carry_tmp, addres} = {1'b0, A} + {1'b0, (~B)} + 1;
    endcase
    // $display("%x + %x = %x", A, B, addres);
  end

  // shift part
  reg [31:0] shfres;
  always @(*) begin
    case (op[1:0])
      2'b00:   shfres = (type_I) ? A << B[4:0] : A << B[4:0];
      2'b01:   shfres = (type_I) ? A >> B[4:0] : A >> B[4:0];
      2'b10:   shfres = (type_I) ? ($signed(A)) >>> B[4:0] : ($signed(A)) >>> B[4:0];
      default: shfres = 32'b0;
    endcase
  end

  // stl part
  reg [31:0] sltres;
  wire signed [31:0] A_s = A;
  wire signed [31:0] B_s = B;
  always @(*) begin
    case (op[0])
      1'b0: sltres = (A < B) ? 32'd1 : 32'b0;
      1'b1: sltres = (A_s < B_s) ? 32'd1 : 32'b0;
    endcase
  end

  assign res = addsig ? addres : logsig ? logres : shfsig ? shfres : sltsig ? sltres : 32'b0;
  assign zero = (res == 0);
  assign signal = res[31];
  assign carry = carry_tmp;

endmodule

module ysyx_24100007_branchcontrol (
    input btypebranch,
    input [2:0] func3,
    input zero,
    input signal,
    input carry,
    input [31:0] res,
    input [31:0] pcadd4,
    input [31:0] pcaddimm,
    input [31:0] pc,
    input jalsig,
    input jalrsig,
    input auipcsig,
    input mretsig,
    input ecallsig,
    input [31:0] mtvec,
    input [31:0] mepc,

    output [31:0] npc,
    output reg [31:0] pcwritereg,
    output is_jmp
);
  assign pcwritereg = (jalsig || jalrsig) ? pcadd4 : auipcsig ? pcaddimm : (ecallsig) ? pc : 0;

  wire npc_is_pcaddimm = (jalsig) || (btypebranch && func3 == 3'b000 && zero) ||
                        (btypebranch && func3 == 3'b001 && !zero) || 
                        (btypebranch && func3 == 3'b100 && res[0]) || 
                        (btypebranch && func3 == 3'b101 && (!res[0] || zero)) || 
                        (btypebranch && func3 == 3'b110 && res[0]) || 
                        (btypebranch && func3 == 3'b111 && (!res[0] || zero));

  wire npc_is_mepc = (mretsig == 1'b1);
  wire npc_is_mtvec = (ecallsig == 1'b1);
  wire npc_is_res = (jalrsig);

  assign npc = (jalsig) ? pcaddimm :
             (jalrsig) ? {res[31:1], 1'b0} :
             (btypebranch && func3 == 3'b000 && zero)    ? pcaddimm :
             (btypebranch && func3 == 3'b001 && !zero)   ? pcaddimm :
             (btypebranch && func3 == 3'b100 && res[0])  ? pcaddimm :
             (btypebranch && func3 == 3'b101 && (!res[0] || zero)) ? pcaddimm :
             (btypebranch && func3 == 3'b110 && res[0])  ? pcaddimm :
             (btypebranch && func3 == 3'b111 && (!res[0] || zero))   ? pcaddimm :
             (mretsig == 1'b1) ? mepc :
             (ecallsig == 1'b1) ? mtvec:
             pcadd4;

  assign is_jmp = (npc_is_mepc) | (npc_is_mtvec) | (npc_is_pcaddimm) | (npc_is_res);
endmodule

module ysyx_24100007_exu (
    input clk,
    input rst,

    input  in_valid,
    output in_ready,
    input  out_ready,
    output out_valid,

    // need sig
    input [2:0] func3_in,
    input btypebranch_in,
    input func7_in,
    input [1:0] aluop_in,
    input jalrsig_in,
    input jalsig_in,
    input [31:0] imm_in,
    input muximm_in,
    input [31:0] pc_in,
    input auipcsig_in,
    input mretsig_in,
    input ecallsig_in,
    input fence_i_in,
    input [31:0] mtvec_in,
    input [31:0] mepc_in,

    // pass sig
    input memew_in,
    input memer_in,
    input [2:0] muxsig_in,
    input regew_control_in,
    input [4:0] rd_in,
    input csrrw_in,
    input csrrs_in,
    input [11:0] csr_addr_in,
    input wbu_write_csr,
    input flush_in,
    input fence_block_in,

    input [31:0] src1_in,
    input [31:0] src2_in,

    output [31:0] emit_out,
    output [31:0] npc,
    output [31:0] src2_out,   // src2 output to WBU

    output memew_out,
    output memer_out,
    output [2:0] func3_out,
    output regew_control_out,
    output [4:0] rd_out,
    output csrrw_out,
    output csrrs_out,
    output [11:0] csr_addr_out,
    output ecallsig_out,
    output fence_i_out,

    output is_jmp,  // tell ifu flush the pipline

    // EXU 向 IDU 转发的旁路信号
    output [4:0] exu_rd,  // EXU 阶段的 rd（用于旁路）
    output exu_regew,  // EXU 阶段的写使能（用于旁路）
    output [31:0] exu_transmit_data,  // EXU 阶段的计算结果（用于旁路）
    output exu_transmit_data_valid,  // EXU 阶段的旁路数据有效信号
    output exu_memer_bypass  // EXU 阶段是否是 load 指令（用于处理 load-use 冲突）
);

  wire exu_valid_sig;
  wire exu_csr_delay;
  wire exu_wbu_handshake = exu_valid_sig & out_ready;
  wire avaliable;
  wire fence_i_pipe;
  wire current_fence = avaliable && fence_i_pipe;

  assign exu_valid_sig = avaliable & !exu_csr_delay &
                         !flush_in & !fence_block_in;
  // A fence already in EXU must leave before a younger instruction can
  // replace it.  A fence in WBU blocks all new EXU input as well.
  wire accept = ((!avaliable) || exu_wbu_handshake) && in_valid &&
                !flush_in && !fence_block_in && !current_fence;
  wire idu_valid = in_valid & !is_jmp;

  assign out_valid = exu_valid_sig;
  assign in_ready  = accept;

  wire pipline_valid = accept & !(avaliable & is_jmp);
  wire flush = (exu_wbu_handshake & !idu_valid) | flush_in;

  wire [2:0] func3;
  wire btypebranch;
  wire func7;
  wire [1:0] aluop;
  wire jalrsig;
  wire jalsig;
  wire [31:0] imm;
  wire muximm;
  wire [31:0] src1;
  wire [31:0] src2;
  wire [31:0] pc;
  wire auipcsig;
  wire mretsig;
  wire ecallsig;
  wire [31:0] mtvec;
  wire [31:0] mepc;
  wire [2:0] muxsig;
  wire csrrs, csrrw;

  ysyx_24100007_exu_pipline_connect exu_pipeline_u (
      .clk(clk),
      .rst(rst),

      // need sig inputs
      .func3_in(func3_in),
      .btypebranch_in(btypebranch_in),
      .func7_in(func7_in),
      .aluop_in(aluop_in),
      .jalrsig_in(jalrsig_in),
      .jalsig_in(jalsig_in),
      .imm_in(imm_in),
      .muximm_in(muximm_in),
      .src1_in(src1_in),
      .src2_in(src2_in),
      .pc_in(pc_in),
      .auipcsig_in(auipcsig_in),
      .mretsig_in(mretsig_in),
      .ecallsig_in(ecallsig_in),
      .fence_i_in(fence_i_in),
      .mtvec_in(mtvec_in),
      .mepc_in(mepc_in),

      // pass sig inputs
      .memew_in(memew_in),
      .memer_in(memer_in),
      .muxsig_in(muxsig_in),
      .regew_control_in(regew_control_in),
      .rd_in(rd_in),
      .csrrw_in(csrrw_in),
      .csrrs_in(csrrs_in),
      .csr_addr_in(csr_addr_in),

      // need sig outputs
      .func3_out(func3),
      .btypebranch_out(btypebranch),
      .func7_out(func7),
      .aluop_out(aluop),
      .jalrsig_out(jalrsig),
      .jalsig_out(jalsig),
      .imm_out(imm),
      .muximm_out(muximm),
      .src1_out(src1),
      .src2_out(src2),
      .pc_out(pc),
      .auipcsig_out(auipcsig),
      .mretsig_out(mretsig),
      .ecallsig_out(ecallsig),
      .fence_i_out(fence_i_pipe),
      .mtvec_out(mtvec),
      .mepc_out(mepc),
      .muxsig_out(muxsig),

      // pass sig outputs
      .memew_out(memew_out),
      .memer_out(memer_out),
      .regew_control_out(regew_control_out),
      .rd_out(rd_out),
      .csrrw_out(csrrw),
      .csrrs_out(csrrs),
      .csr_addr_out(csr_addr_out),

      .avaliable(avaliable),
      .pipline_valid(pipline_valid),
      .flush(flush)
  );

  assign csrrs_out = csrrs;
  assign csrrw_out = csrrw;
  assign ecallsig_out = ecallsig;
  assign func3_out = func3;

  wire [31:0] pc_plus_4, pc_plus_imm;
  assign pc_plus_4   = pc + 32'd4;
  assign pc_plus_imm = pc + imm;


  wire [4:0] alu_opcode;
  ysyx_24100007_alucontrol alucontrol0 (
      .func3(func3),
      .func7(func7),
      .aluop(aluop),
      .jalrsig(jalrsig),
      .is_csr(csrrw || csrrs),
      .aluopcode(alu_opcode)
  );

  reg [31:0] alu_arg2;
  always @(*) begin
    case (muximm)
      1'b0: alu_arg2 = src2;
      1'b1: alu_arg2 = imm;
      default: alu_arg2 = src2;
    endcase
  end

  wire zero_flag, sign_flag, carry_flag;
  wire [31:0] res_r;
  ysyx_24100007_alu alu0 (
      .A(src1),
      .B(alu_arg2),
      .op(alu_opcode),
      .res(res_r),
      .zero(zero_flag),
      .signal(sign_flag),
      .carry(carry_flag)
  );

  // ------------------------------------
  //  BRANCH CONTROL
  // ------------------------------------
  wire is_jmp_r_1;
  wire is_jmp_r;
  wire [31:0] res;
  wire [31:0] link_addr;
  ysyx_24100007_branchcontrol branchcontrol0 (
      .btypebranch(btypebranch),
      .func3(func3),
      .zero(zero_flag),
      .signal(sign_flag),
      .carry(carry_flag),
      .res(res_r),
      .pcadd4(pc_plus_4),
      .pcaddimm(pc_plus_imm),
      .pc(pc),
      .jalsig(jalsig),
      .jalrsig(jalrsig),
      .auipcsig(auipcsig),
      .mretsig(mretsig),
      .ecallsig(ecallsig),
      .mtvec(mtvec),
      .mepc(mepc),

      .npc(npc),
      .pcwritereg(link_addr),
      .is_jmp(is_jmp_r_1)
  );
  reg is_jmp_mask;
  always @(posedge clk) begin
    if ((in_valid & in_ready) | exu_csr_delay) begin
      is_jmp_mask <= 1'b1;
    end else begin
      is_jmp_mask <= 1'b0;
    end
  end
  assign is_jmp_r = is_jmp_r_1 & is_jmp_mask & !exu_csr_delay;
  assign is_jmp = is_jmp_r & !flush_in & !fence_block_in;

  assign res = (csrrw || csrrs) ? src1 : res_r;
  assign src2_out = src2;

  reg [31:0] exu_emit;
  always @(*) begin
    case (muxsig)
      3'b010:  exu_emit = imm;
      3'b100:  exu_emit = link_addr;
      default: exu_emit = res;
    endcase
  end

  assign emit_out = exu_emit;
  assign fence_i_out = current_fence && !flush_in;

  // EXU 向 IDU 转发的旁路信号
  assign exu_rd = rd_out;
  assign exu_regew = regew_control_out;
  assign exu_transmit_data = exu_emit;
  assign exu_transmit_data_valid = out_valid && !memer_out;

  // load-use
  assign exu_memer_bypass = memer_out;
  wire exu_need_mepc_mtvec = ecallsig || mretsig;
  assign exu_csr_delay = wbu_write_csr & exu_need_mepc_mtvec;

  // synopsys translate_off
`ifdef VERILATOR
  import "DPI-C" function void get_exu_state(int state);
  always @(posedge clk) begin
    get_exu_state({31'b0, avaliable});
  end
`endif
  // synopsys translate_on

endmodule

module ysyx_24100007_exu_pipline_connect (
    input clk,
    input rst,

    input [2:0] func3_in,
    input btypebranch_in,
    input func7_in,
    input [1:0] aluop_in,
    input jalrsig_in,
    input jalsig_in,
    input [31:0] imm_in,
    input muximm_in,
    input [31:0] src1_in,
    input [31:0] src2_in,
    input [31:0] pc_in,
    input auipcsig_in,
    input mretsig_in,
    input ecallsig_in,
    input fence_i_in,
    input [31:0] mtvec_in,
    input [31:0] mepc_in,

    input memew_in,
    input memer_in,
    input [2:0] muxsig_in,
    input regew_control_in,
    input [4:0] rd_in,
    input csrrw_in,
    input csrrs_in,
    input [11:0] csr_addr_in,

    output [2:0] func3_out,
    output btypebranch_out,
    output func7_out,
    output [1:0] aluop_out,
    output jalrsig_out,
    output jalsig_out,
    output [31:0] imm_out,
    output muximm_out,
    output [31:0] src1_out,
    output [31:0] src2_out,
    output [31:0] pc_out,
    output auipcsig_out,
    output mretsig_out,
    output ecallsig_out,
    output fence_i_out,
    output [31:0] mtvec_out,
    output [31:0] mepc_out,

    output memew_out,
    output memer_out,
    output [2:0] muxsig_out,
    output regew_control_out,
    output [4:0] rd_out,
    output csrrw_out,
    output csrrs_out,
    output [11:0] csr_addr_out,

    output avaliable,
    input  pipline_valid,
    input  flush
);
  reg avaliable_r;
  always @(posedge clk) begin
    if (rst) begin
      avaliable_r <= 1'b0;
    end else begin
      if (pipline_valid) begin
        avaliable_r <= 1'b1;
      end else if (flush) begin
        avaliable_r <= 1'b0;
      end
    end
  end

  assign avaliable = avaliable_r;

  reg [2:0] func3_r;
  reg btypebranch_r;
  reg func7_r;
  reg [1:0] aluop_r;
  reg jalrsig_r;
  reg jalsig_r;
  reg [31:0] imm_r;
  reg muximm_r;
  reg [31:0] src1_r;
  reg [31:0] src2_r;
  reg [31:0] pc_r;
  reg auipcsig_r;
  reg mretsig_r;
  reg ecallsig_r;
  reg fence_i_r;
  reg [31:0] mtvec_r;
  reg [31:0] mepc_r;

  reg memew_r;
  reg memer_r;
  reg [2:0] muxsig_r;
  reg regew_control_r;
  reg [4:0] rd_r;
  reg csrrw_r;
  reg csrrs_r;
  reg [11:0] csr_addr_r;

  always @(posedge clk) begin
    if (pipline_valid) begin
      func3_r <= func3_in;
      func7_r <= func7_in;
      aluop_r <= aluop_in;
      imm_r <= imm_in;
      muximm_r <= muximm_in;
      src1_r <= src1_in;
      src2_r <= src2_in;
      pc_r <= pc_in;
      auipcsig_r <= auipcsig_in;
      mtvec_r <= mtvec_in;
      mepc_r <= mepc_in;
      muxsig_r <= muxsig_in;
      rd_r <= rd_in;
      csr_addr_r <= csr_addr_in;
    end
  end

  always @(posedge clk) begin
    if (rst) begin
      btypebranch_r <= 1'b0;
      jalrsig_r <= 1'b0;
      jalsig_r <= 1'b0;
      mretsig_r <= 1'b0;
      ecallsig_r <= 1'b0;
      fence_i_r <= 1'b0;
      memew_r <= 1'b0;
      memer_r <= 1'b0;
      regew_control_r <= 1'b0;
      csrrw_r <= 1'b0;
      csrrs_r <= 1'b0;
    end else if (pipline_valid) begin
      btypebranch_r <= btypebranch_in;
      jalrsig_r <= jalrsig_in;
      jalsig_r <= jalsig_in;
      mretsig_r <= mretsig_in;
      ecallsig_r <= ecallsig_in;
      fence_i_r <= fence_i_in;
      memew_r <= memew_in;
      memer_r <= memer_in;
      regew_control_r <= regew_control_in;
      csrrw_r <= csrrw_in;
      csrrs_r <= csrrs_in;
    end else if (flush) begin
      btypebranch_r <= 1'b0;
      jalrsig_r <= 1'b0;
      jalsig_r <= 1'b0;
      mretsig_r <= 1'b0;
      ecallsig_r <= 1'b0;
      fence_i_r <= 1'b0;
      memew_r <= 1'b0;
      memer_r <= 1'b0;
      regew_control_r <= 1'b0;
      csrrw_r <= 1'b0;
      csrrs_r <= 1'b0;
    end
  end

  // 输出连接到寄存器
  assign func3_out = func3_r;
  assign btypebranch_out = btypebranch_r;
  assign func7_out = func7_r;
  assign aluop_out = aluop_r;
  assign jalrsig_out = jalrsig_r;
  assign jalsig_out = jalsig_r;
  assign imm_out = imm_r;
  assign muximm_out = muximm_r;
  assign src1_out = src1_r;
  assign src2_out = src2_r;
  assign pc_out = pc_r;
  assign auipcsig_out = auipcsig_r;
  assign mretsig_out = mretsig_r;
  assign ecallsig_out = ecallsig_r;
  assign fence_i_out = fence_i_r;
  assign mtvec_out = mtvec_r;
  assign mepc_out = mepc_r;
  assign memew_out = memew_r;
  assign memer_out = memer_r;
  assign muxsig_out = muxsig_r;
  assign regew_control_out = regew_control_r;
  assign rd_out = rd_r;
  assign csrrw_out = csrrw_r;
  assign csrrs_out = csrrs_r;
  assign csr_addr_out = csr_addr_r;

endmodule

`ifdef VERILATOR
// synopsys translate_off
import "DPI-C" function void ret(int pc);
// synopsys translate_on
`endif
module ysyx_24100007_control_unit(
  input [6:0] opcode,
  input [2:0] func3,
  input func7,

  input ebreaksig,
  input ecallsig,
  input mretsig,
  input [5:0] inst_type,
  output memew,
  output [2:0] muxsig,
  output memer,
  output regew,
  output muximm,
  output btypebranch,
  output jalrsig,
  output jalsig,
  output [1:0] aluop,
  output auipcsig,
  output csrrw,
  output csrrs,
  output [2:0] memmask,
  output memsextsig
);
  wire type_I, type_R, type_U, type_S, type_J, type_B;
  assign {type_I, type_B, type_J, type_S, type_R, type_U} = inst_type;
  
  wire load, store;
  wire regwritepc, regwritemem, luisig;

  assign load = (opcode == 7'b0000011);
  assign store = (opcode == 7'b0100011);

  assign btypebranch = type_B;
  assign memew = store;
  assign memer = load;
  assign regew = (type_I | type_R | type_J | type_U);
  assign jalsig = type_J;
  assign jalrsig = (opcode == 7'b1100111);
  assign muximm = (load | store | type_I | jalrsig) & !(csrrs | csrrw);
  assign regwritemem = load;
  assign regwritepc = jalrsig | jalsig | auipcsig | ecallsig;
  assign auipcsig = (opcode == 7'b0010111);
  assign luisig = (opcode == 7'b0110111);

  assign aluop[1] = type_R | type_B;
  assign aluop[0] = (type_I | type_B) & ~load;

  assign muxsig = {regwritepc, luisig, regwritemem};

  assign csrrs = (opcode == 7'b1110011) & (func3 == 3'b010);
  assign csrrw = (opcode == 7'b1110011) & (func3 == 3'b001);

  assign memmask = (func3 == 3'b000) ? 3'b001 :
               (func3 == 3'b001) ? 3'b010 :
               (func3 == 3'b010) ? 3'b100 :
               (func3 == 3'b100) ? 3'b001 :
               (func3 == 3'b101) ? 3'b010 :
               3'b000;

  assign memsextsig = (func3 == 3'b100) ? 1'b0 :
                      (func3 == 3'b101) ? 1'b0 :
                      1'b1;
  
  // synopsys translate_off
  `ifdef VERILATOR
  always @(*) begin
    if(ebreaksig)
      ret(0);
  end
  `endif
  
  // `ifdef __ICARUS__
  // always @(*) begin
  //   if(ebreak)
  //     $finish;
  // end
  // `endif
  // synopsys translate_on
endmodule




module ysyx_24100007_decoder(
  input [31:0] inst,
  
  output ebreaksig,
  output ecallsig,
  output mretsig,
  output fenceisig,
  output [31:0] imm,
  output [6:0] opcode,
  output [2:0] func3,
  output func7,
  output [4:0] src1,
  output [4:0] src2,
  output [4:0] rd,
  output [5:0] inst_type
);
  
  wire type_I, type_R, type_U, type_S, type_J, type_B;
  wire [31:0] I_imm, U_imm, S_imm, J_imm, B_imm;
  
  assign opcode = inst[6:0];
  assign func3 = inst[14:12];
  assign func7 = inst[30];
  assign src1 = inst[19:15];
  assign src2 = inst[24:20];
  assign rd = inst[11:7];

  // Instruction type classification:
  // type_I: I-type instructions - immediate arithmetic/logic operations, load instructions,
  //         jump and link register (JALR), and system instructions (CSR, ECALL, EBREAK)
  //         Examples: ADDI, ANDI, LW, LB, JALR, CSRRW, CSRRW, ECALL, EBREAK
  assign type_I = (opcode == 7'b0000011) | (opcode == 7'b1100111) |
                  (opcode == 7'b0010011) | (opcode == 7'b0000111) |
                  (opcode == 7'b1110011);
  // type_B: B-type instructions - conditional branch instructions
  //         Examples: BEQ, BNE, BLT, BGE, BLTU, BGEU
  assign type_B = (opcode == 7'b1100011);
  // type_S: S-type instructions - store instructions to memory
  //         Examples: SW, SH, SB
  assign type_S = (opcode == 7'b0100011);
  // type_R: R-type instructions - register-to-register arithmetic and logic operations
  //         Examples: ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU
  assign type_R = (opcode == 7'b0110011);
  // type_U: U-type instructions - upper immediate instructions for loading constants
  //         Examples: LUI (load upper immediate), AUIPC (add upper immediate to PC)
  assign type_U = (opcode == 7'b0110111) | (opcode == 7'b0010111);
  // type_J: J-type instructions - unconditional jump instructions
  //         Examples: JAL (jump and link)
  assign type_J = (opcode == 7'b1101111);
  assign inst_type = {type_I, type_B, type_J, type_S, type_R, type_U};

  assign I_imm={{20{inst[31]}},inst[31:20]}; 
	assign U_imm={inst[31:12],{12{1'b0}}};
	assign S_imm={{20{inst[31]}},inst[31:25],inst[11:7]};
  assign J_imm={{12{inst[31]}},inst[19:12],inst[20],inst[30:21],1'b0};
	assign B_imm={{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0};
  
  assign imm = type_I ? I_imm :
               type_J ? J_imm :
               type_S ? S_imm :
               type_B ? B_imm :
               type_U ? U_imm :
               32'b0;

  assign ebreaksig = (inst == 32'b00000000000100000000000001110011);
  assign ecallsig = (inst == 32'b00000000000000000000000001110011);
  assign mretsig = (inst == 32'b00110000001000000000000001110011);
  // FENCE.I is a serializing instruction.  Keep it out of the generic
  // arithmetic classes so it cannot acquire a register or memory side effect.
  assign fenceisig = (opcode == 7'b0001111) && (func3 == 3'b001);

endmodule


module ysyx_24100007_idu(
  input clk,
  input rst,
  input [31:0] inst_in,
  input [31:0] pc_in,

  output in_ready,
  input in_valid,
  output out_valid,
  input out_ready,

  input is_jmp,
  input flush_in,
  input fence_block_in,

  input [31:0] regout1,
  input [31:0] regout2,

  // WBU 旁路接口
  input [4:0] wbu_rd,
  input wbu_regew,
  input [31:0] wbu_transmit_data,
  input wbu_transmit_data_valid,

  // EXU 旁路接口
  input [4:0] exu_rd,
  input exu_regew,
  input [31:0] exu_transmit_data,
  input exu_transmit_data_valid,
  input exu_memer_bypass,    // EXU 是否是 load 指令（用于处理 load-use 冲突）

  // 经过旁路选择后的数据
  output [31:0] src1_data,
  output [31:0] src2_data,
  
  output ebreaksig,
  output ecallsig,
  output mretsig,
  output [31:0] imm,
  output [2:0] func3,
  output func7,
  output [4:0] src1_addr,
  output [4:0] src2_addr,
  output [4:0] rd,
  output memew,
  output [2:0] muxsig,
  output memer,
  output muximm,
  output btypebranch,
  output jalrsig,
  output jalsig,
  output regew_control,
  output [1:0] aluop,
  output auipcsig,
  output csrrw,
  output csrrs,
  output [11:0] csr_addr,
  output [2:0] memmask,
  output memsextsig,
  output fence_i,
  output [31:0] pc_out
);

  wire avaliable;
  wire src_data_valid;
  wire fence_i_dec;
  wire current_fence = avaliable && fence_i_dec;

  // A fence already held by IDU may leave, but it must not be replaced by a
  // younger instruction in the same cycle.
  wire accept = ((!avaliable) || out_ready) &&
                in_valid && !flush_in && !fence_block_in && !current_fence;
  assign out_valid = avaliable & src_data_valid & !is_jmp &
                     !flush_in & !fence_block_in;
  assign in_ready = accept; 

  wire [31:0] inst;
  wire pipline_valid;
  wire flush;
  ysyx_24100007_idu_pipline_connect idu_connect(
    .clk(clk),
    .rst(rst),

    .inst_in(inst_in),
    .inst_out(inst),
    .pc_in(pc_in),
    .pc_out(pc_out),

    .avaliable(avaliable),

    .valid(pipline_valid),
    .flush(flush)
  );

  assign pipline_valid = accept & !is_jmp;
  assign flush = (avaliable & out_ready & !in_valid) |
                 is_jmp | flush_in;
  
  wire ebreak, ecall, mret;
  wire [2:0] func3bridge;
  wire func7bridge;
  wire [6:0] opcode;
  wire [5:0] inst_type;  // 添加type信号
  wire [4:0] src1_dec;
  wire [4:0] src2_dec;

  ysyx_24100007_decoder decoder0(
    .inst(inst),
    .ebreaksig(ebreak),
    .mretsig(mret),
    .ecallsig(ecall),
    .fenceisig(fence_i_dec),
    .imm(imm),
    .src1(src1_dec),
    .src2(src2_dec),
    .rd(rd),
    .opcode(opcode),
    .func3(func3bridge),
    .func7(func7bridge),
    .inst_type(inst_type)  // 从decoder获取type
  );

  ysyx_24100007_control_unit control_unit0(
    .opcode(opcode),
    .func3(func3bridge),
    .func7(func7bridge),
    .ebreaksig(ebreak),
    .ecallsig(ecall),
    .mretsig(mret),
    .inst_type(inst_type),  // 传递type给control_unit

    .memew(memew),
    .muxsig(muxsig),
    .memer(memer),
    .regew(regew_control),
    .muximm(muximm),
    .btypebranch(btypebranch),
    .jalrsig(jalrsig),
    .jalsig(jalsig),
    .aluop(aluop),
    .auipcsig(auipcsig),
    .csrrs(csrrs),
    .csrrw(csrrw),
    .memmask(memmask),     
    .memsextsig(memsextsig)
  );

  assign ecallsig = ecall;
  assign mretsig = mret;
  assign ebreaksig = ebreak;
  assign func7 = func7bridge;
  assign func3 = func3bridge;
  // FENCE.I does not consume register operands; ignore its reserved fields
  // so forwarding/load-use logic cannot stall the serializing instruction.
  assign src1_addr = fence_i_dec ? 5'b0 : src1_dec;
  assign src2_addr = fence_i_dec ? 5'b0 : src2_dec;
  assign csr_addr = inst[31:20];  // Extract CSR address from instruction
  assign fence_i = current_fence && !flush_in;

  ysyx_24100007_transmit transmit0(
    .clk(clk),
    .rst(rst),
    .src1_addr_in(src1_addr),
    .src2_addr_in(src2_addr),
    .exu_rd(exu_rd),
    .wbu_rd(wbu_rd),
    .exu_res_valid(exu_transmit_data_valid),
    .exu_regew(exu_regew),
    .wbu_res_valid(wbu_transmit_data_valid),
    .wbu_regew(wbu_regew),
    .exu_memer_bypass(exu_memer_bypass),  // EXU 是否是 load 指令
    .regout1_in(regout1),
    .regout2_in(regout2),
    .exu_transmit_data(exu_transmit_data),
    .wbu_transmit_data(wbu_transmit_data),
    .src1(src1_data),
    .src2(src2_data),
    .valid(src_data_valid)
  );
  
  // synopsys translate_off
  `ifdef VERILATOR
  import "DPI-C" function void get_idu_state(int state);
  always @(posedge clk) begin 
    get_idu_state({31'b0, avaliable});
  end
  `endif
  // synopsys translate_on
endmodule

module ysyx_24100007_idu_pipline_connect(
  input clk,
  input rst,

  input [31:0] inst_in,
  output [31:0] inst_out,
  input [31:0] pc_in,
  output [31:0] pc_out,

  output avaliable,

  input valid,
  input flush // 插入一个nop
);
  reg avaliable_r;
  always @(posedge clk) begin
    if(rst) begin
      avaliable_r <= 1'b0;
    end else begin
      if(valid) begin
        avaliable_r <= 1'b1;
      end else if(flush) begin
        avaliable_r <= 1'b0;
      end
    end
  end

  assign avaliable = avaliable_r;

  reg [31:0] inst_r;
  reg [31:0] pc_r;

  // 只在 valid 时更新，去掉 flush 清零，依靠 avaliable 指示有效性以节省面积
  always @(posedge clk) begin
    if(valid) begin
      inst_r <= inst_in;
      pc_r <= pc_in;
    end
  end

  assign inst_out = inst_r;
  assign pc_out = pc_r;

endmodule

module ysyx_24100007_transmit(
    input clk,
    input rst,

    input [4:0] src1_addr_in,
    input [4:0] src2_addr_in,
    input [4:0] exu_rd,
    input [4:0] wbu_rd,

    input exu_res_valid,
    input exu_regew,
    input wbu_res_valid,
    input wbu_regew,
    input exu_memer_bypass,              // EXU 是否是 load 指令（用于处理 load-use 冲突）

    input [31:0] regout1_in,
    input [31:0] regout2_in,
    input [31:0] exu_transmit_data,
    input [31:0] wbu_transmit_data,

    output [31:0] src1,
    output [31:0] src2,
    output valid
);  
  wire src1_valid, src2_valid;

  // 实例化两次旁路选择模块，分别用于 src1 和 src2（纯组合逻辑）
  ysyx_24100007_bypass_sel bypass_src1 (
    .src_addr_in           (src1_addr_in),
    .reg_data_in           (regout1_in),
    .wbu_rd                (wbu_rd),
    .wbu_regew             (wbu_regew),
    .wbu_transmit_data     (wbu_transmit_data),
    .wbu_transmit_data_valid(wbu_res_valid),
    .exu_rd                (exu_rd),
    .exu_regew             (exu_regew),
    .exu_transmit_data     (exu_transmit_data),
    .exu_transmit_data_valid(exu_res_valid),
    .exu_memer_bypass      (exu_memer_bypass),
    .src_data_out          (src1),
    .src_valid             (src1_valid)
  );

  ysyx_24100007_bypass_sel bypass_src2 (
    .src_addr_in           (src2_addr_in),
    .reg_data_in           (regout2_in),
    .wbu_rd                (wbu_rd),
    .wbu_regew             (wbu_regew),
    .wbu_transmit_data     (wbu_transmit_data),
    .wbu_transmit_data_valid(wbu_res_valid),
    .exu_rd                (exu_rd),
    .exu_regew             (exu_regew),
    .exu_transmit_data     (exu_transmit_data),
    .exu_transmit_data_valid(exu_res_valid),
    .exu_memer_bypass      (exu_memer_bypass),
    .src_data_out          (src2),
    .src_valid             (src2_valid)
  );

  // 整体有效信号：两个源都有效时才有效
  assign valid = src1_valid && src2_valid;
endmodule

module ysyx_24100007_bypass_sel(
  input [4:0] src_addr_in,          // 源寄存器地址（src1 或 src2）
  input [31:0] reg_data_in,          // 从寄存器堆读出的数据

  // WBU 旁路接口
  input [4:0] wbu_rd,
  input wbu_regew,
  input [31:0] wbu_transmit_data,
  input wbu_transmit_data_valid,

  // EXU 旁路接口
  input [4:0] exu_rd,
  input exu_regew,
  input [31:0] exu_transmit_data,
  input exu_transmit_data_valid,
  input exu_memer_bypass,              // EXU 是否是 load 指令（用于处理 load-use 冲突）

  output [31:0] src_data_out,        // 选择后的数据
  output src_valid                   // 数据有效信号
);

  // 优先级：EXU > WBU（EXU是上一级指令，更接近当前指令）
  wire need_exu_forward = (src_addr_in != 5'b0) && (src_addr_in == exu_rd) && exu_regew;
  wire need_wbu_forward = (src_addr_in != 5'b0) && (src_addr_in == wbu_rd) && wbu_regew && !need_exu_forward;

  // 检测 load-use 冲突：需要 EXU 转发，但 EXU 是 load（数据未就绪）
  // 简化方案：直接 stall，等 load 进 WBU 后走 need_wbu_forward，无需 load_use_wait 和锁存
  wire load_use_hazard = need_exu_forward && exu_memer_bypass;

  // 有效条件：遇到 load-use 则 invalid（IDU 被 stall）
  assign src_valid = load_use_hazard ? 1'b0 :
                   need_exu_forward && !exu_memer_bypass ? exu_transmit_data_valid :
                   need_wbu_forward ? wbu_transmit_data_valid : 1'b1;

  // 数据选择：load-use 时数据无效不会被使用；否则 EXU > WBU > 寄存器堆
  assign src_data_out = need_exu_forward && !exu_memer_bypass ? exu_transmit_data :
                        need_wbu_forward ? wbu_transmit_data : reg_data_in;

endmodule

module ysyx_24100007_icache (
    input clk,
    input rst,
    input [31:0] addr,
    input w_valid,
    input [127:0] w_data,
    input set_invalid,
    output hit,
    output [31:0] data_r
);
  localparam INDEX_LEN = 0;
  localparam TAG_LEN = 32 - INDEX_LEN - 4;
  localparam OFFSET_LEN = 4;

  wire [OFFSET_LEN-1:0] offset = addr[OFFSET_LEN-1:0];
  wire [TAG_LEN-1:0] tag = addr[31:OFFSET_LEN+INDEX_LEN];

  wire line_hit;
  wire [31:0] line_data_r;
  wire line_w_valid;
  wire [127:0] line_data_w;

  assign line_w_valid = w_valid;
  assign line_data_w  = w_data;

  // Manually expanded cache lines (4 instances)
  ysyx_24100007_icahce_line #(
      .TAG_LEN(TAG_LEN),
      .OFFSET_LEN(OFFSET_LEN)
  ) u_cacheline_0 (
      .clk(clk),
      .rst(rst),
      .tag(tag),
      .offset(offset),
      .set_invalid(set_invalid),
      .w_valid(line_w_valid),
      .data_w(line_data_w),
      .hit(line_hit),
      .data_r(line_data_r)
  );

  assign hit = line_hit;
  assign data_r = line_data_r;
endmodule

module ysyx_24100007_icahce_line #(
    parameter TAG_LEN = 26,
    parameter OFFSET_LEN = 4
) (
    input clk,
    input rst,
    input [TAG_LEN-1:0] tag,
    input [OFFSET_LEN-1:0] offset,
    input set_invalid,
    input w_valid,
    input [127:0] data_w,
    output hit,
    output [31:0] data_r
);
  localparam DATABLOCK_SIZE = (2 ** OFFSET_LEN) * 8;
  localparam DATABLOCK_NUMB = DATABLOCK_SIZE / 32;

  reg [DATABLOCK_NUMB-1:0][31:0] data_block;
  reg valid_r;
  reg [TAG_LEN-1:0] tag_r;

  wire [OFFSET_LEN-3:0] word_idx = offset[OFFSET_LEN-1:2];
  assign data_r = data_block[word_idx];
  assign hit = (valid_r && (tag == tag_r));

  always @(posedge clk) begin
    if (rst) begin
      valid_r <= 1'b0;
    end else begin
      if (set_invalid) begin
        valid_r <= 1'b0;
      end else if (w_valid) begin
        valid_r <= 1'b1;
        tag_r <= tag;
        data_block <= data_w;
      end
    end
  end

endmodule

module ysyx_24100007_ifu(
  input clk,
  input rst,
  input [31:0] exu_npc,

  output [31:0] pc,
  output [31:0] inst,
  output valid,
  input ready,

  input is_jmp,
  input fence_active,
  input fence_commit,

  // LSU handshake
  output        ifu_read_req,
  input         ifu_req_acp,
  input         ifu_req_finish,
  output        ifu_req_ready,
  output [31:0] ifu_addr,
  input  [127:0] ifu_line_data
);

  localparam [2:0] INIT            = 3'd0;
  localparam [2:0] VALID           = 3'd1;
  localparam [2:0] CHECK_CACHE     = 3'd2;
  localparam [2:0] BUS_HANDSHAKE   = 3'd3;
  localparam [2:0] BUS_TRANSACTION = 3'd4;
  localparam [2:0] UPDATE_CACHE    = 3'd5;
  localparam [2:0] BUS_INVALID     = 3'd6;
  localparam [2:0] UPDATE_PC       = 3'd7;

  reg [2:0] ifu_state;
  reg [31:0] inst_reg;

  wire [31:0] pcbridge;
  wire infetch_req = is_jmp | (ready & valid); // update pc
  // Keep the PC register clock-enabled during reset so a synthesized
  // clock-gate cannot block the synchronous reset value from loading.
  wire pcreg_en = infetch_req | rst;
  wire [31:0] pc_add_4 = pc + 32'd4;
  wire [31:0] npc = is_jmp ? exu_npc : pc_add_4;

  // PC register module
  ysyx_24100007_pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge),
    .ready_from(pcreg_en)
  );

  // ------------------------------------
  // ICACHE
  // ------------------------------------
  localparam OFFSET_LEN = 4;
  localparam DATABLOCK_SIZE = (2 ** OFFSET_LEN) * 8;
  localparam ARLEN = (2 ** OFFSET_LEN) / 4 - 1;
  wire w_valid, cache_hit;
  wire [31:0] cache_rdata;
  wire set_invalid;
  ysyx_24100007_icache icache_u (
    .clk(clk),
    .rst(rst),

    .addr(pcbridge),
    .w_valid(w_valid),
    .w_data(ifu_line_data),
    .set_invalid(set_invalid),
    .hit(cache_hit),
    .data_r(cache_rdata)
  );
  wire hit = cache_hit && (ifu_state == CHECK_CACHE) && !fence_active;
  assign w_valid = (ifu_state == UPDATE_CACHE) && !fence_active;
  assign set_invalid = fence_commit;

  // ------------------------------------
  // PERFORMANCE COUNTER LOGIC
  // ------------------------------------
  // divide it so it couldnot disrupt the synthetic
  // synopsys translate_off
  `ifdef VERILATOR
  import "DPI-C" function void host_get_ifu_start();
  import "DPI-C" function void host_get_ifu_finish();
  import "DPI-C" function void host_get_ifu_giveup();
  import "DPI-C" function void host_get_icache_miss();
  always @(posedge clk) begin
    if (!rst) begin
      if (is_jmp) begin
        host_get_ifu_giveup();   // 立即放弃当前取指流
      end else begin
        case (ifu_state)
          INIT: begin
            if (ready) begin
              host_get_ifu_start();
            end
          end

          VALID: begin
            if (ready) begin
              host_get_ifu_start();
            end
          end

          CHECK_CACHE: begin
            if (hit) begin
              host_get_ifu_finish();
            end
          end

          UPDATE_CACHE: begin
            host_get_icache_miss();
          end

          default: begin end
        endcase
      end
    end
  end
  `endif
  // synopsys translate_on

  // ------------------------------------
  // IFU STATE MACHINE
  // ------------------------------------
  // Accepting FENCE.I has already advanced PC to fence_pc + 4. Since this IFU
  // has no prefetch queue, UPDATE_PC can also hold that PC until retirement.
  always @(posedge clk) begin
    if(rst) begin
      ifu_state <= INIT;
    end else begin
      case(ifu_state) 
        INIT: begin
          if (fence_active) begin
            ifu_state <= UPDATE_PC;
          end else begin
            ifu_state <= BUS_HANDSHAKE;
          end
        end

        VALID: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if (fence_active) begin
            ifu_state <= UPDATE_PC;
          end else if(ready) begin
            ifu_state <= CHECK_CACHE;
          end else begin
            ifu_state <= VALID;
          end
        end

        CHECK_CACHE: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if (fence_active) begin
            ifu_state <= UPDATE_PC;
          end else if(hit)begin
            ifu_state <= VALID;
          end else begin
            ifu_state <= BUS_HANDSHAKE;
          end
        end

        BUS_HANDSHAKE: begin
          if(is_jmp) begin
            if(ifu_req_acp) begin
              ifu_state <= BUS_INVALID;
            end else begin
              ifu_state <= UPDATE_PC;
            end
          end else if (fence_active) begin
            ifu_state <= UPDATE_PC;
          end else if(ifu_req_acp) begin
            ifu_state <= BUS_TRANSACTION;
          end else begin
            ifu_state <= BUS_HANDSHAKE;
          end
        end

        BUS_TRANSACTION: begin
          if(is_jmp) begin
            ifu_state <= BUS_INVALID;
          end else if (fence_active) begin
            ifu_state <= UPDATE_PC;
          end else if(ifu_req_finish) begin
            ifu_state <= UPDATE_CACHE;
          end else begin
            ifu_state <= BUS_TRANSACTION;
          end
        end

        UPDATE_CACHE: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if (fence_active) begin
            ifu_state <= UPDATE_PC;
          end else begin
            ifu_state <= CHECK_CACHE;
          end
        end

        BUS_INVALID: begin
          if(is_jmp) begin
            if(ifu_req_ready & ifu_req_finish) begin
              ifu_state <= UPDATE_PC;
            end else begin
              ifu_state <= BUS_INVALID;
            end
          end else if (fence_active) begin
            ifu_state <= UPDATE_PC;
          end else if(ifu_req_ready & ifu_req_finish) begin
            ifu_state <= UPDATE_PC;
          end else begin
            ifu_state <= BUS_INVALID;
          end
        end

        UPDATE_PC: begin
          if (is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if (fence_active) begin
            ifu_state <= UPDATE_PC;
          end else begin
            ifu_state <= CHECK_CACHE;
          end
        end

        default: begin
          // synopsys translate_off
          $error("ifu state machine Invalid state error");
          // synopsys translate_on
          ifu_state <= INIT;
        end
      endcase
    end
  end

  assign ifu_addr     = pcbridge;
  assign ifu_read_req = (ifu_state == BUS_HANDSHAKE) &&
                        !fence_active;
  assign ifu_req_ready = (ifu_state == UPDATE_CACHE) |
                         (ifu_state == BUS_INVALID);

  // ------------------------------------
  // INST UPDATE LOGIC
  // ------------------------------------
  wire icache_hit = (ifu_state == CHECK_CACHE) && hit;
  always @(posedge clk) begin
    if(rst) begin
      inst_reg <= 32'b0;
    end else begin
      if (fence_active) begin
        inst_reg <= 32'b0;
      end else if(icache_hit) begin
        inst_reg <= cache_rdata;
      end else if(ifu_state == VALID && ready) begin
        inst_reg <= 32'b0;
      end 
    end
  end

  // Assign outputs
  assign pc = pcbridge;
  assign inst = inst_reg;
  assign valid = (ifu_state == VALID) && !fence_active;
endmodule

module ysyx_24100007_pcreg (
    input clk,
    input [31:0] npc,
    input rst,
    input ready_from,
    output reg [31:0] pcout
);

`ifndef SYNTHESIS
`ifdef __NPC__
  localparam init = 32'h80000000;
`else
  localparam init = 32'h30000000;
`endif
`else
  localparam init = 32'h80000000;
`endif

  // synopsys translate_off
  initial begin
    pcout = init;
`ifdef __ICARUS__
    $display("[Init] Start PC: 0x%h", pcout);
`endif
  end
  // synopsys translate_on
  // 综合时仅依赖 reset 初始化，initial 块已被 translate_off 排除

  always @(posedge clk) begin
    if (rst) begin
      pcout <= init;
    end else if (ready_from == 1) begin
      pcout <= npc;
    end
  end

endmodule

module ysyx_24100007_ifucfg (
    input  [31:0] addr,

    output [31:0] araddr,
    output [7:0]  arlen,
    output [2:0]  arsize,
    output [1:0]  arburst
);

  localparam [7:0] ARLEN = 8'd3;   // 4 beats (arlen=3)
  localparam [1:0] WRAP = 2'b10;

  assign araddr  = addr;           // IFU 传入的 PC，对 WRAP 可直接使用
  assign arlen   = ARLEN;          // 4 次传输
  assign arsize  = 3'b010;         // 32-bit
  assign arburst = WRAP;           // WRAP 用于 cache line 取指

endmodule

module ysyx_24100007_lsu (
    input clk,
    input rst,

    input         ifu_read_req,
    output        ifu_req_acp,
    input  [31:0] ifu_addr_in,

    input  wbu_read_req,
    input  wbu_write_req,
    output wbu_req_acp,

    input  ifu_req_ready,   // IFU 准备好接收读数据
    output ifu_req_finish,
    input  wbu_req_ready,   // WBU 准备好接收读数据/写响应
    output wbu_req_finish,

    input        mem_we_in,
    input [31:0] mem_addr_in,
    input [31:0] mem_wdata_in,
    input [ 2:0] mem_mask_in,
    input        mem_sext_in,

    output [127:0] data_read,

    output        arvalid,
    input         arready,
    output [31:0] araddr,
    output [ 7:0] arlen,
    output [ 2:0] arsize,
    output [ 1:0] arburst,

    output        awvalid,
    input         awready,
    output [31:0] awaddr,
    output [ 7:0] awlen,
    output [ 2:0] awsize,
    output [ 1:0] awburst,

    output        wvalid,
    input         wready,
    output [31:0] wdata,
    output [ 3:0] wstrb,
    output        wlast,

    input         rvalid,
    output        rready,
    input  [31:0] rdata,
    input         rlast,

    input        bvalid,
    output       bready,
    input  [1:0] bresp
);

  typedef enum logic [1:0] {
    IFU,
    WBU_R,
    WBU_W
  } master_t;

  typedef enum logic [1:0] {
    READY,
    WAIT_HANDSHAKE,
    WAIT_SLAVE,
    PROCESSION
  } axi_state_t;

  master_t master;
  axi_state_t state;
  wire finish_acp;
  wire is_unalign;

  wire has_req = ifu_read_req | wbu_read_req | wbu_write_req;
  wire has_ifu = ifu_read_req;
  wire has_wbu = wbu_read_req | wbu_write_req;
  wire is_wbu_rd = wbu_read_req;
  wire is_wbu_wr = wbu_write_req;

  wire idle = (state == READY) || finish_acp;

  // req_acp: LSU 接受请求（valid-ready 握手时 ready 侧）
  assign ifu_req_acp = idle && ifu_read_req;
  assign wbu_req_acp = idle && !ifu_read_req && (wbu_read_req | wbu_write_req);

  reg [31:0] ifu_addr;
  reg        mem_we;
  reg [31:0] mem_addr;
  reg [31:0] mem_wdata;
  reg [ 2:0] mem_mask;
  reg        mem_sext;

  always @(posedge clk) begin
    if (rst) begin
      ifu_addr  <= 32'b0;
      mem_we    <= 1'b0;
      mem_addr  <= 32'b0;
      mem_wdata <= 32'b0;
      mem_mask  <= 3'b0;
      mem_sext  <= 1'b0;
    end else begin
      if (ifu_req_acp) begin
        ifu_addr <= ifu_addr_in;
      end
      if (wbu_req_acp) begin
        mem_we    <= mem_we_in;
        mem_addr  <= mem_addr_in;
        mem_wdata <= mem_wdata_in;
        mem_mask  <= mem_mask_in;
        mem_sext  <= mem_sext_in;
      end
    end
  end

  wire ifu_finish = (master == IFU) && (state == PROCESSION);
  wire wbu_finish  = (master == WBU_R) && (state == PROCESSION) ||
                     (master == WBU_W) && (state == PROCESSION);
  assign ifu_req_finish = ifu_finish;
  assign wbu_req_finish = wbu_finish;
  wire finish = ifu_finish | wbu_finish;
  assign finish_acp = finish && (ifu_req_ready | wbu_req_ready);

  always @(posedge clk) begin
    if (rst) begin
      master <= IFU;
    end else if (idle && has_req) begin
      if (has_ifu) master <= IFU;
      else if (is_wbu_rd) master <= WBU_R;
      else master <= WBU_W;
    end
  end

  wire [31:0] ifu_araddr;
  wire [ 7:0] ifu_arlen;
  wire [ 2:0] ifu_arsize;
  wire [ 1:0] ifu_arburst;

  wire [31:0] wbu_araddr, wbu_awaddr;
  wire [2:0] wbu_arsize, wbu_awsize;
  wire [7:0] wbu_arlen, wbu_awlen;
  wire [1:0] wbu_arburst, wbu_awburst;
  wire [31:0] wbu_wdata;
  wire [ 3:0] wbu_wstrb;

  ysyx_24100007_ifucfg ifucfg_u (
      .addr   (ifu_addr),
      .araddr (ifu_araddr),
      .arlen  (ifu_arlen),
      .arsize (ifu_arsize),
      .arburst(ifu_arburst)
  );

  ysyx_24100007_wbucfg wbucfg_u (
      .mem_we   (mem_we),
      .mem_addr (mem_addr),
      .mem_wdata(mem_wdata),
      .mem_mask (mem_mask),
      .is_unalign(is_unalign),

      .araddr (wbu_araddr),
      .awaddr (wbu_awaddr),
      .arsize (wbu_arsize),
      .awsize (wbu_awsize),
      .arlen  (wbu_arlen),
      .awlen  (wbu_awlen),
      .arburst(wbu_arburst),
      .awburst(wbu_awburst),
      .wdata  (wbu_wdata),
      .wstrb  (wbu_wstrb)
  );

  wire is_read = (master == IFU) | (master == WBU_R);
  wire is_write = (master == WBU_W);

  assign araddr  = (master == IFU) ? ifu_araddr : wbu_araddr;
  assign arlen   = (master == IFU) ? ifu_arlen : wbu_arlen;
  assign arsize  = (master == IFU) ? ifu_arsize : wbu_arsize;
  assign arburst = (master == IFU) ? ifu_arburst : wbu_arburst;

  assign awaddr  = wbu_awaddr;
  assign awlen   = wbu_awlen;
  assign awsize  = wbu_awsize;
  assign awburst = wbu_awburst;
  assign wdata   = wbu_wdata;
  assign wstrb   = wbu_wstrb;
  assign wlast   = wvalid;

  assign arvalid = is_read & (state == WAIT_HANDSHAKE);
  assign awvalid = is_write & (state == WAIT_HANDSHAKE);
  assign wvalid  = is_write & (state == WAIT_HANDSHAKE);
  assign rready  = is_read & (state == WAIT_SLAVE);
  assign bready  = is_write & (state == WAIT_SLAVE);

  always @(posedge clk) begin
    if (rst) begin
      state <= READY;
    end else begin
      case (state)
        READY: begin
          if (has_req) state <= WAIT_HANDSHAKE;
        end

        WAIT_HANDSHAKE: begin
          if (is_write && awready && wready) state <= WAIT_SLAVE;
          else if (is_read && arready) state <= WAIT_SLAVE;
        end

        WAIT_SLAVE: begin
          if (is_read && rvalid && rlast) state <= PROCESSION;
          else if (is_write && bvalid) state <= PROCESSION;
        end

        PROCESSION: begin
          if (finish_acp) begin
            if (has_req) begin
              state <= WAIT_HANDSHAKE;
            end else begin
              state <= READY;
            end
          end
        end

        default: state <= READY;
      endcase
    end
  end

  // ---------- 读数据缓冲与输出 ----------
  reg [127:0] data_buffer;
  reg [  1:0] buffer_index;

  always @(posedge clk) begin
    if (rst) begin
      buffer_index <= 2'b0;
    end else if (master == IFU) begin
      if (arvalid && arready) begin
        buffer_index <= araddr[3:2];
      end else if (rvalid && rready) begin
        buffer_index <= (buffer_index == 2'd3) ? 2'd0 : buffer_index + 2'd1;
      end
    end
  end

  wire in_sram = (mem_addr >= 32'h0f000000) && (mem_addr <= 32'h0fffffff);
  wire in_psram = (mem_addr >= 32'h80000000) && (mem_addr <= 32'h9fffffff);
  wire in_sdram = (mem_addr >= 32'ha0000000) && (mem_addr <= 32'hbfffffff);
  assign is_unalign = in_psram | in_sdram | in_sram;

  wire [31:0] memread;
  ysyx_24100007_memreadlen memreadlen_u (
      .is_unalign (is_unalign),
      .data       (rdata),
      .memmask    (mem_mask),
      .memsextsig (mem_sext),
      .addr_offset(mem_addr[1:0]),
      .read       (memread)
  );

  // IFU: 4-beat 组装；WBU: 单 beat
  always @(posedge clk) begin
    if (state == WAIT_SLAVE && rvalid && rready) begin
      if (master == IFU) begin
        case (buffer_index)
          2'd0: data_buffer[31:0] <= rdata;
          2'd1: data_buffer[63:32] <= rdata;
          2'd2: data_buffer[95:64] <= rdata;
          2'd3: data_buffer[127:96] <= rdata;
          default: ;
        endcase
      end else if (master == WBU_R) begin
        data_buffer[31:0] <= memread;
      end
    end
  end

  assign data_read = data_buffer;

  // ------------------------------------
  // PERFORMANCE COUNTER LOGIC
  // ------------------------------------
  // synopsys translate_off
`ifdef VERILATOR
  import "DPI-C" function void host_get_io_op(int addr);
  import "DPI-C" function void host_get_wbu_start();
  import "DPI-C" function void host_get_wbu_finish();

  always @(posedge clk) begin
    if (!rst) begin
      case (state)
        READY: begin
          if (has_req && has_wbu) begin
            host_get_wbu_start();
          end
        end

        WAIT_SLAVE: begin
          if ((master == WBU_R && rvalid && rlast) || (master == WBU_W && bvalid)) begin
            host_get_io_op(master == WBU_W ? awaddr : araddr);
          end
        end

        PROCESSION: begin
          if (finish_acp && (master == WBU_R || master == WBU_W)) begin
            host_get_wbu_finish();
          end
        end

        default: begin
        end
      endcase
    end
  end
`endif
  // synopsys translate_on

endmodule

module ysyx_24100007_memreadlen(
  input is_unalign,
  input [31:0] data,      // 从内存中读取的完整32位数据
  input [2:0] memmask,    // 内存掩码，用于确定读取的长度（byte, halfword, word）
  input memsextsig,       // 符号扩展信号，1表示有符号扩展，0表示无符号扩展
  input [1:0] addr_offset, // 地址的最低两位，用于确定偏移量
  output [31:0] read      // 读取并扩展后的数据
);

  wire [31:0] read_u, read_s;
  wire [31:0] read_sb, read_sh;
  wire [7:0]  byte_data;
  wire [15:0] halfword_data;

  wire [15:0] halfword_data_unalign;
  wire [7:0] byte_data_unalign;
  wire [15:0] halfword_data_align;
  wire [7:0] byte_data_align;

  assign byte_data_unalign = (addr_offset == 2'b00) ? data[7:0] :
                             (addr_offset == 2'b01) ? data[15:8] :
                             (addr_offset == 2'b10) ? data[23:16] :
                              data[31:24];
  assign byte_data_align = data[7:0];

  assign halfword_data_unalign = (addr_offset[1] == 1'b0) ? data[15:0] : data[31:16];
  assign halfword_data_align = data[15:0];

  assign byte_data = (is_unalign == 1) ? byte_data_unalign : byte_data_align;
  assign halfword_data = (is_unalign == 1) ? halfword_data_unalign : halfword_data_align;

  // 符号扩展
  ysyx_24100007_sext#(8, 32) sext0(byte_data, read_sb);
  ysyx_24100007_sext#(16, 32) sext1(halfword_data, read_sh);

  assign read_s = (memmask == 3'b001) ? read_sb :  // lb
                  (memmask == 3'b010) ? read_sh :  // lh
                  data;                            // lw

  assign read_u = (memmask == 3'b001) ? {{24{1'b0}}, byte_data} :  // lbu
                  (memmask == 3'b010) ? {{16{1'b0}}, halfword_data} :  // lhu
                  data;  // lw

  // 根据符号扩展信号选择最终的输出
  assign read = (memsextsig == 1) ? read_s : read_u;
endmodule

`define ysyx_24100007_GENERAL 2'b00 // for the device that support Supports arbitrary byte access
`define ysyx_24100007_BYTE 2'b01
`define ysyx_24100007_HALFWORD 2'b10
`define ysyx_24100007_WORD 2'b11

module ysyx_24100007_memwritelen(
    input [31:0] awaddr,
    input [2:0] wirtelen,
    output [3:0] wstrb,
    output reg [2:0] awsize,
    output [1:0] wdata_offset,
    output [1:0] awburst
);
    localparam device_num = 3;
    wire inuart = (awaddr >= 32'h10000000) && (awaddr <= 32'h10000fff);
    wire insram = (awaddr >= 32'h0f000000) && (awaddr <= 32'h0fffffff);
    wire inflash = (awaddr >= 32'h30000000) && (awaddr <= 32'h3fffffff);
    wire inspi = (awaddr >= 32'h10001000) && (awaddr <= 32'h10001fff);
    wire inpsram = (awaddr >= 32'h80000000) && (awaddr <= 32'h9fffffff);
    wire insdram = (awaddr >= 32'ha0000000) && (awaddr <= 32'hbfffffff);

    reg [1:0] bus_size;
    wire [2:0] awsize_general = (wirtelen == 3'b001) ? 3'b000 :
                                (wirtelen == 3'b010) ? 3'b001 :
                                (wirtelen == 3'b100) ? 3'b010 :
                                3'b000;

    always @(*) begin
        case ({insram|inspi|insdram|inpsram, 1'b0, inflash})
            3'b100:  bus_size = `ysyx_24100007_WORD;
            3'b010:  bus_size = `ysyx_24100007_HALFWORD;
            3'b001:  bus_size = `ysyx_24100007_BYTE;
            default: bus_size = `ysyx_24100007_GENERAL;
        endcase
    end

    always @(*) begin
        case (bus_size)
            `ysyx_24100007_BYTE:     awsize = 3'b000;
            `ysyx_24100007_HALFWORD: awsize = 3'b001;
            `ysyx_24100007_WORD:     awsize = 3'b010;
            default:   awsize = awsize_general;
        endcase
    end

    // wstrb
    wire [3:0] wstrb_general;
    assign wstrb_general = (wirtelen == 3'b001) ? 4'b0001 :
                           (wirtelen == 3'b010) ? 4'b0011 :
                           (wirtelen == 3'b100) ? 4'b1111 :
                           4'b0000;

    wire [3:0] wstrb_byte;
    assign wstrb_byte = 4'b0001;

    wire [3:0] wstrb_halfword;

    wire [3:0] wstrb_word;
    wire [4:0] mux = {wirtelen, awaddr[1:0]};
    assign wstrb_word = (mux == 5'b00100) ? 4'b0001 :
                        (mux == 5'b00101) ? 4'b0010 :
                        (mux == 5'b00110) ? 4'b0100 :
                        (mux == 5'b00111) ? 4'b1000 :
                        (mux == 5'b01000) ? 4'b0011 :
                        (mux == 5'b01010) ? 4'b1100 :
                        (mux == 5'b10000) ? 4'b1111 :
                        4'b0000;

    assign wstrb = (bus_size == `ysyx_24100007_GENERAL) ? wstrb_general :
                   (bus_size == `ysyx_24100007_BYTE) ? wstrb_byte :
                   (bus_size == `ysyx_24100007_HALFWORD) ? wstrb_halfword :
                   wstrb_word;

    assign wdata_offset = (bus_size == `ysyx_24100007_WORD || bus_size == `ysyx_24100007_GENERAL) ? awaddr[1:0] : 2'b0;
    assign awburst = inuart ? 2'b00 : 2'b01;

endmodule

/**
 * WBU AXI 配置模块
 * 将 load/store 请求转换为 AXI 通道参数
 * - 单 beat 传输
 * - arsize/awsize 由 mem_mask 决定
 * - awburst 由地址范围决定（UART 用 FIXED，其它用 INCR）
 * - 复用 memwritelen 逻辑处理 wstrb、awsize、wdata 对齐
 */
module ysyx_24100007_wbucfg (
    input        mem_we,
    input [31:0] mem_addr,
    input [31:0] mem_wdata,
    input [ 2:0] mem_mask,
    input        is_unalign,

    output [31:0] araddr,
    output [31:0] awaddr,
    output [ 2:0] arsize,
    output [ 2:0] awsize,
    output [ 7:0] arlen,
    output [ 7:0] awlen,
    output [ 1:0] arburst,
    output [ 1:0] awburst,
    output [31:0] wdata,
    output [ 3:0] wstrb
);

  wire in_sram = (mem_addr >= 32'h0f000000) && (mem_addr <= 32'h0fffffff);
  wire in_psram = (mem_addr >= 32'h80000000) && (mem_addr <= 32'h9fffffff);
  wire in_sdram = (mem_addr >= 32'ha0000000) && (mem_addr <= 32'hbfffffff);

  assign araddr  = (is_unalign) ? {mem_addr[31:2], 2'b00} : mem_addr;

  assign awaddr  = mem_addr;

  assign arlen   = 8'd0;
  assign arburst = 2'b01;  // INCR
  assign arsize  = (mem_mask == 3'b001) ? 3'b000 : (mem_mask == 3'b010) ? 3'b001 : 3'b010;

  assign awlen   = 8'd0;

  wire [1:0] wdata_offset;

  ysyx_24100007_memwritelen strbcontrol (
      .awaddr(mem_addr),
      .wirtelen(mem_mask),
      .wstrb(wstrb),
      .awsize(awsize),
      .wdata_offset(wdata_offset),
      .awburst(awburst)
  );

  assign wdata = mem_wdata << ({3'b0, wdata_offset} << 3);

endmodule

module ysyx_24100007_regheap(
  input clk,
  input rst,
  input ew,
  input [4:0] addr,
  input [4:0] src1,
  input [4:0] src2,
  input [11:0] csr,
  input [31:0] data,
  input csrrw,
  input csrrs,
  input ecallsig,
  output [31:0] regout1,
  output [31:0] regout2,
  output [31:0] mepc,
  output [31:0] mtvec
);

  wire [32*15-1:0] rf_flat;
  wire [32*6-1:0] rf_csr_flat;
  wire [31:0] reg_write_data;
  wire [31:0] rf_src1_word;
  wire [31:0] rf_src2_word;

  assign rf_src1_word = (src1 == 0) ? 32'b0 : rf_flat[({5'b0, src1[3:0]} - 9'd1) * 32 +: 32];
  assign rf_src2_word = (src2 == 0) ? 32'b0 : rf_flat[({5'b0, src2[3:0]} - 9'd1) * 32 +: 32];
  assign reg_write_data = data;

  reg [2:0] csr_choose;
  always @(*) begin
    case (csr)
      12'h300: csr_choose = 3'b000;  // mstatus
      12'h305: csr_choose = 3'b001;  // mtvec
      12'h341: csr_choose = 3'b010;  // mepc
      12'h342: csr_choose = 3'b011;  // mcause
      12'hf11: csr_choose = 3'b100;  // mvendorid
      12'hf12: csr_choose = 3'b101;  // marchid
      default: csr_choose = 3'b000;  // 或保持与 MuxKey 行为一致
    endcase
  end

  ysyx_24100007_registers registers0(
    .clk(clk),
    .rst(rst),
    .ew(ew),
    .csrrs(csrrs),
    .csrrw(csrrw),
    .ecall(ecallsig),
    .addr(addr),
    .csr_choose(csr_choose),
    .data(reg_write_data),
    .gr_flat(rf_flat),
    .csr_flat(rf_csr_flat)
  );

  assign regout1 = (src1 == 0) ? 0 : rf_src1_word;
  assign regout2 = (src2 == 0) ? 0 : rf_src2_word;

  assign mepc = rf_csr_flat[2*32 +: 32];
  assign mtvec = rf_csr_flat[1*32 +: 32];

endmodule

`ifdef VERILATOR
// synopsys translate_off
import "DPI-C" function void host_get_reg(
  int regval,
  int regnum
);
import "DPI-C" function void host_get_csr(
  int csrval,
  int csrnum
);
// synopsys translate_on
`endif
module ysyx_24100007_registers (
    input clk,
    input rst,
    input ew,
    input csrrw,
    input csrrs,
    input ecall,
    input [2:0] csr_choose,
    input [4:0] addr,
    input [31:0] data,
    output [32*15-1:0] gr_flat,
    output [32*6-1:0] csr_flat
);

  reg [31:0] gr[15:1];
  reg [31:0] csr_mstatus;
  reg [31:0] csr_mtvec;
  reg [31:0] csr_mepc;
  reg [31:0] csr_mcause;

  localparam [31:0] CSR_MVENDORID = 32'h79737978;
  localparam [31:0] CSR_MARCHID   = 32'h016FBCA7;

  wire [3:0] reg_addr = addr[3:0];
  reg [31:0] csr_rdata;

  // write op
  always @(*) begin
    case (csr_choose)
      3'b000:  csr_rdata = csr_mstatus;
      3'b001:  csr_rdata = csr_mtvec;
      3'b010:  csr_rdata = csr_mepc;
      3'b011:  csr_rdata = csr_mcause;
      3'b100:  csr_rdata = CSR_MVENDORID;
      3'b101:  csr_rdata = CSR_MARCHID;
      default: csr_rdata = 32'b0;
    endcase
  end

  always @(posedge clk) begin
    if (rst) begin
      gr[1] <= 0;
      gr[2] <= 0;
      gr[3] <= 0;
      gr[4] <= 0;
      gr[5] <= 0;
      gr[6] <= 0;
      gr[7] <= 0;
      gr[8] <= 0;
      gr[9] <= 0;
      gr[10] <= 0;
      gr[11] <= 0;
      gr[12] <= 0;
      gr[13] <= 0;
      gr[14] <= 0;
      gr[15] <= 0;

      csr_mstatus <= 0;
      csr_mtvec <= 0;
      csr_mepc <= 0;
      csr_mcause <= 0;
    end else begin
      if (csrrw) begin
        if (reg_addr != 4'b0) begin
          gr[reg_addr] <= csr_rdata;
        end
        case (csr_choose)
          3'b000:  csr_mstatus <= data;
          3'b001:  csr_mtvec <= data;
          3'b010:  csr_mepc <= data;
          3'b011:  csr_mcause <= data;
          default: ;
        endcase
      end else if (csrrs) begin
        if (reg_addr != 4'b0) begin
          gr[reg_addr] <= csr_rdata;
        end
        case (csr_choose)
          3'b000:  csr_mstatus <= data | csr_mstatus;
          3'b001:  csr_mtvec <= data | csr_mtvec;
          3'b010:  csr_mepc <= data | csr_mepc;
          3'b011:  csr_mcause <= data | csr_mcause;
          default: ;
        endcase
      end else if (ew && reg_addr != 4'b0) begin
        gr[reg_addr] <= data;
      end

      if (ecall) begin
        csr_mepc   <= data;
        csr_mcause <= 32'd11;
      end
    end
  end

  // synopsys translate_off
`ifdef VERILATOR
  always @(*) begin
    integer i;
    host_get_reg(0, 0);
    for (i = 1; i < 16; i = i + 1) begin
      host_get_reg(gr[i], i);
    end

    for (i = 0; i < 4; i++) begin
      case (i)
        0: host_get_csr(csr_mstatus, i);
        1: host_get_csr(csr_mtvec, i);
        2: host_get_csr(csr_mepc, i);
        3: host_get_csr(csr_mcause, i);
      endcase
    end
  end
`endif
  // synopsys translate_on

  genvar gi;
  generate
    for (gi = 1; gi < 16; gi = gi + 1) begin : PACK_GR
      assign gr_flat[(gi-1)*32+:32] = gr[gi];
    end
  endgenerate

  assign csr_flat[0*32+:32] = csr_mstatus;
  assign csr_flat[1*32+:32] = csr_mtvec;
  assign csr_flat[2*32+:32] = csr_mepc;
  assign csr_flat[3*32+:32] = csr_mcause;
  assign csr_flat[4*32+:32] = CSR_MVENDORID;
  assign csr_flat[5*32+:32] = CSR_MARCHID;

endmodule

module ysyx_24100007_sext #(parameter INPUT_WIDTH = 32, parameter OUTPUT_WIDTH = 32) (
  input  wire signed [INPUT_WIDTH-1  : 0] input_number,
  output wire signed [OUTPUT_WIDTH-1 : 0] output_number
);
 assign output_number = {{(OUTPUT_WIDTH - INPUT_WIDTH){input_number[INPUT_WIDTH-1]}}, input_number};
endmodule

// ---------------------------------------------
// version created at 2025/12/20 sunmingyang
// 单 master 版本：仅做地址解码与 slave 路由，无 master 仲裁
// ---------------------------------------------
module ysyx_24100007_arbiter #(
    parameter SLAVE_NUM = 2  // slave设备数量（CLINT, 外部AXI等）
) (
    input wire clk,
    input wire rst,

    // 单 master AXI 接口
    input  awvalid,
    input  wvalid,
    input  arvalid,
    input  rready,
    input  bready,
    output bvalid,
    output rvalid,
    output awready,
    output wready,
    output arready,

    input  [31:0] araddr,
    input  [31:0] awaddr,
    input  [31:0] wdata,
    input  [ 3:0] wstrb,
    output [31:0] rdata,
    output [ 1:0] bresp,
    input  [ 2:0] awsize,
    input  [ 2:0] arsize,
    input  [ 7:0] awlen,
    input  [ 7:0] arlen,
    input  [ 1:0] awburst,
    input  [ 1:0] arburst,
    input         wlast,
    output        rlast,

    // slave 接口
    output [SLAVE_NUM-1:0] awvalid_out,
    output [SLAVE_NUM-1:0] wvalid_out,
    output [SLAVE_NUM-1:0] arvalid_out,
    output [SLAVE_NUM-1:0] rready_out,
    output [SLAVE_NUM-1:0] bready_out,
    input  [SLAVE_NUM-1:0] bvalid_in,
    input  [SLAVE_NUM-1:0] rvalid_in,
    input  [SLAVE_NUM-1:0] awready_in,
    input  [SLAVE_NUM-1:0] wready_in,
    input  [SLAVE_NUM-1:0] arready_in,

    output [SLAVE_NUM*32-1:0] araddr_out,
    output [SLAVE_NUM*32-1:0] awaddr_out,
    output [SLAVE_NUM*32-1:0] wdata_out,
    output [SLAVE_NUM*4-1:0]  wstrb_out,
    input  [SLAVE_NUM*32-1:0] rdata_in,
    input  [SLAVE_NUM*2-1:0]  bresp_in,
    output [SLAVE_NUM*3-1:0]  awsize_out,
    output [SLAVE_NUM*3-1:0]  arsize_out,
    output [SLAVE_NUM*8-1:0]  awlen_out,
    output [SLAVE_NUM*8-1:0]  arlen_out,
    output [SLAVE_NUM*2-1:0]  awburst_out,
    output [SLAVE_NUM*2-1:0]  arburst_out,
    output [SLAVE_NUM-1:0]    wlast_out,
    input  [SLAVE_NUM-1:0]    rlast_in
);

  typedef enum logic {
    ST_IDLE,
    ST_TRANS
  } state_t;
  state_t state;

  wire has_req = arvalid | awvalid;
  wire trans_end = (rvalid & rready & rlast) | (bvalid & bready);

  wire [31:0] current_addr = arvalid ? araddr : awaddr;
  wire is_clint_addr = (current_addr >= 32'h02000000) && (current_addr <= 32'h0200ffff);

  reg slave_owner;
  wire trans_active = (state == ST_TRANS);
  wire owner_external = trans_active & ~slave_owner;
  wire owner_clint = trans_active & slave_owner;
  wire [SLAVE_NUM-1:0] slave_owner_one_hot = {owner_clint, owner_external};

  always @(posedge clk) begin
    if (rst) begin
      state <= ST_IDLE;
      slave_owner <= 1'b0;
    end else begin
      case (state)
        ST_IDLE: begin
          if (has_req) begin
            state <= ST_TRANS;
            slave_owner <= is_clint_addr;
          end
        end

        ST_TRANS: begin
          if (trans_end) begin
            state <= ST_IDLE;
            slave_owner <= 1'b0;
          end
        end

        default: begin
          state <= ST_IDLE;
          slave_owner <= 1'b0;
          // synopsys translate_off
          $error("arbiter Invalid state");
          // synopsys translate_on
        end
      endcase
    end
  end

  // master 信号直通到 slave（由 slave_owner 选通）
  wire [31:0] master_awaddr = awaddr;
  wire [31:0] master_araddr = araddr;
  wire [31:0] master_wdata = wdata;
  wire [ 3:0] master_wstrb = wstrb;
  wire [ 2:0] master_awsize = awsize;
  wire [ 2:0] master_arsize = arsize;
  wire [ 7:0] master_awlen = awlen;
  wire [ 7:0] master_arlen = arlen;
  wire [ 1:0] master_awburst = awburst;
  wire [ 1:0] master_arburst = arburst;
  wire        master_wlast = wlast;

  genvar m;
  generate
    for (m = 0; m < SLAVE_NUM; m = m + 1) begin : gen_slave_route
      assign awvalid_out[m] = slave_owner_one_hot[m] ? awvalid : 1'b0;
      assign awaddr_out[m*32 +: 32] = master_awaddr;
      assign awsize_out[m*3  +: 3 ] = master_awsize;
      assign awlen_out[m*8   +: 8 ] = master_awlen;
      assign awburst_out[m*2 +: 2 ] = master_awburst;

      assign wvalid_out[m] = slave_owner_one_hot[m] ? wvalid : 1'b0;
      assign wdata_out[m*32 +: 32] = master_wdata;
      assign wstrb_out[m*4  +: 4 ] = master_wstrb;
      assign wlast_out[m] = master_wlast;

      assign arvalid_out[m] = slave_owner_one_hot[m] ? arvalid : 1'b0;
      assign araddr_out[m*32 +: 32] = master_araddr;
      assign arsize_out[m*3  +: 3 ] = master_arsize;
      assign arlen_out[m*8   +: 8 ] = master_arlen;
      assign arburst_out[m*2 +: 2 ] = master_arburst;

      assign rready_out[m] = slave_owner_one_hot[m] ? rready : 1'b0;
      assign bready_out[m] = slave_owner_one_hot[m] ? bready : 1'b0;
    end
  endgenerate

  // Return zero while idle instead of implicitly selecting CLINT.
  assign rdata   = owner_external ? rdata_in[0*32+:32] : owner_clint ? rdata_in[1*32+:32] : 32'b0;
  assign bresp   = owner_external ? bresp_in[0*2+:2] : owner_clint ? bresp_in[1*2+:2] : 2'b0;
  assign rvalid  = owner_external ? rvalid_in[0] : owner_clint ? rvalid_in[1] : 1'b0;
  assign bvalid  = owner_external ? bvalid_in[0] : owner_clint ? bvalid_in[1] : 1'b0;
  assign rlast   = owner_external ? rlast_in[0] : owner_clint ? rlast_in[1] : 1'b0;
  assign awready = owner_external ? awready_in[0] : owner_clint ? awready_in[1] : 1'b0;
  assign wready  = owner_external ? wready_in[0] : owner_clint ? wready_in[1] : 1'b0;
  assign arready = owner_external ? arready_in[0] : owner_clint ? arready_in[1] : 1'b0;

endmodule

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

module ysyx_24100007_wbu (
    input clk,
    input rst,
    input [31:0] emit_in,
    input [31:0] regout2_in,
    input memew_in,
    input memer_in,
    input [2:0] func3_in,
    input regew_control_in,
    input [4:0] rd_in,
    input csrrw_in,
    input csrrs_in,
    input [11:0] csr_addr_in,
    input ecallsig_in,
    input fence_i_in,

    output [31:0] regwrite_out,
    output regew_out,
    output [4:0] rd_out,
    output csrrw_out,
    output csrrs_out,
    output [11:0] csr_addr_out,
    output ecallsig_out,
    output fence_i_active,
    output fence_i_commit,
    output wbu_write_csr,

    // wbu is the last model
    input  in_valid,
    output in_ready,

    output wbu_commit,

    // LSU handshake
    output        wbu_read_req,
    output        wbu_write_req,
    input         wbu_req_acp,
    input         wbu_req_finish,
    output        wbu_req_ready,
    input  [31:0] wbu_data_read,   // 来自 LSU.data_read[31:0]

    // 给 LSU 的访问信号
    output        lsu_mem_we,
    output [31:0] lsu_mem_addr,
    output [31:0] lsu_mem_wdata,
    output [ 2:0] lsu_mem_mask,
    output        lsu_mem_sext,

    output [4:0] wbu_rd,
    output wbu_regew,
    output [31:0] transmit_data,
    output transmit_data_valid
);

  localparam [1:0] WAIT_VALID = 2'd0;
  localparam [1:0] BUS_HANDSHAKE = 2'd1;
  localparam [1:0] BUS_TRANSACTION = 2'd2;
  localparam [1:0] WRITE_BACK = 2'd3;

  reg [1:0] wbu_state;
  wire avaliable;

  wire accept = ((wbu_state == WAIT_VALID) || (wbu_state == WRITE_BACK)) && in_valid;
  assign in_ready = (wbu_state == WAIT_VALID);
  wire pipline_valid = accept;
  wire flush = ((wbu_state == WRITE_BACK) & !in_valid);

  // Pipeline connect: 流水线寄存器
  wire [31:0] emit;
  wire [31:0] regout2;
  wire memew;
  wire memer;
  wire [2:0] func3;
  wire regew_control;
  // Derive memmask and memsextsig from func3 (load/store encoding)
  wire [2:0] memmask = (func3 == 3'b000) ? 3'b001 :
               (func3 == 3'b001) ? 3'b010 :
               (func3 == 3'b010) ? 3'b100 :
               (func3 == 3'b100) ? 3'b001 :
               (func3 == 3'b101) ? 3'b010 :
               3'b000;
  wire memsextsig = (func3 == 3'b100) ? 1'b0 : (func3 == 3'b101) ? 1'b0 : 1'b1;
  wire [4:0] rd;
  wire ecallsig;
  wire fence_i;
  wire csrrs, csrrw;

  ysyx_24100007_wbu_pipline_connect wbu_pipeline_u (
      .clk(clk),
      .rst(rst),

      .emit_in(emit_in),
      .regout2_in(regout2_in),
      .memew_in(memew_in),
      .memer_in(memer_in),
      .func3_in(func3_in),
      .regew_control_in(regew_control_in),
      .rd_in(rd_in),
      .csrrw_in(csrrw_in),
      .csrrs_in(csrrs_in),
      .csr_addr_in(csr_addr_in),
      .ecallsig_in(ecallsig_in),
      .fence_i_in(fence_i_in),

      .emit_out(emit),
      .regout2_out(regout2),
      .memew_out(memew),
      .memer_out(memer),
      .func3_out(func3),
      .regew_control_out(regew_control),
      .rd_out(rd),
      .csrrw_out(csrrw),
      .csrrs_out(csrrs),
      .csr_addr_out(csr_addr_out),
      .ecallsig_out(ecallsig),
      .fence_i_out(fence_i),

      .avaliable(avaliable),
      .pipline_valid(pipline_valid),
      .flush(flush)
  );

  // Memory access state machine
  wire mem_access = memew_in | memer_in;
  always @(posedge clk) begin
    if (rst) begin
      wbu_state <= WAIT_VALID;
    end else begin
      case (wbu_state)
        WAIT_VALID: begin
          if (in_valid & in_ready) begin
            if (mem_access) begin
              wbu_state <= BUS_HANDSHAKE;
            end else begin
              wbu_state <= WRITE_BACK;
            end
          end
        end

        BUS_HANDSHAKE: begin
          if (wbu_req_acp) begin
            wbu_state <= BUS_TRANSACTION;
          end
        end

        BUS_TRANSACTION: begin
          if (wbu_req_finish && wbu_req_ready) begin
            wbu_state <= WRITE_BACK;
          end
        end

        WRITE_BACK: begin
          if (in_valid & in_ready) begin
            if (mem_access) begin
              wbu_state <= BUS_HANDSHAKE;
            end else begin
              wbu_state <= WRITE_BACK;
            end
          end else begin
            wbu_state <= WAIT_VALID;
          end
        end
      endcase
    end
  end

  assign wbu_commit = (wbu_state == WRITE_BACK);
  assign ecallsig_out = ecallsig & (wbu_state == WRITE_BACK);
  assign csrrs_out = csrrs & (wbu_state == WRITE_BACK);
  assign csrrw_out = csrrw & (wbu_state == WRITE_BACK);

  wire regew;
  assign regew = (wbu_state == WRITE_BACK) & regew_control;
  reg  [31:0] memread_data_q;

  always @(posedge clk) begin
    if (wbu_req_finish && memer) begin
      memread_data_q <= wbu_data_read;
    end
  end

  wire [31:0] regwrite = memer ? memread_data_q : emit;

  assign transmit_data = regwrite;
  assign wbu_rd = rd;
  assign wbu_regew = regew_control;
  assign transmit_data_valid = regew;
  assign wbu_write_csr = csrrs_out || csrrw_out;

  // FENCE.I is a retirement-side operation.  WBU is in program order, so
  // reaching WRITE_BACK guarantees that all older stores have completed.
  assign fence_i_active = (wbu_state != WAIT_VALID) && fence_i;
  assign fence_i_commit = (wbu_state == WRITE_BACK) && fence_i;

  // Output connections
  assign regwrite_out = regwrite;
  assign regew_out = regew;
  assign rd_out = rd;

  assign lsu_mem_we    = memew;
  assign lsu_mem_addr  = emit;
  assign lsu_mem_wdata = regout2;
  assign lsu_mem_mask  = memmask;
  assign lsu_mem_sext  = memsextsig;

  assign wbu_read_req  = (wbu_state == BUS_HANDSHAKE) && memer;
  assign wbu_write_req = (wbu_state == BUS_HANDSHAKE) && memew;
  assign wbu_req_ready = (wbu_state == BUS_TRANSACTION);
endmodule

module ysyx_24100007_wbu_pipline_connect (
    input clk,
    input rst,

    input [31:0] emit_in,
    input [31:0] regout2_in,
    input memew_in,
    input memer_in,
    input [2:0] func3_in,
    input regew_control_in,
    input [4:0] rd_in,
    input csrrw_in,
    input csrrs_in,
    input [11:0] csr_addr_in,
    input ecallsig_in,
    input fence_i_in,

    output [31:0] emit_out,
    output [31:0] regout2_out,
    output memew_out,
    output memer_out,
    output [2:0] func3_out,
    output regew_control_out,
    output [4:0] rd_out,
    output csrrw_out,
    output csrrs_out,
    output [11:0] csr_addr_out,
    output ecallsig_out,
    output fence_i_out,

    output avaliable,
    input  pipline_valid,
    input  flush
);

  reg avaliable_r;
  always @(posedge clk) begin
    if (rst) begin
      avaliable_r <= 1'b0;
    end else begin
      if (pipline_valid) begin
        avaliable_r <= 1'b1;
      end else if (flush) begin
        avaliable_r <= 1'b0;
      end
    end
  end

  assign avaliable = avaliable_r;

  // 寄存器存储所有输入信号
  reg [31:0] emit_r;
  reg [31:0] regout2_r;
  reg memew_r;
  reg memer_r;
  reg [2:0] func3_r;
  reg regew_control_r;
  reg [4:0] rd_r;
  reg csrrw_r;
  reg csrrs_r;
  reg [11:0] csr_addr_r;
  reg ecallsig_r;
  reg fence_i_r;

  // Datapath fields are ignored unless the WBU stage is valid.
  always @(posedge clk) begin
    if (pipline_valid) begin
      emit_r <= emit_in;
      regout2_r <= regout2_in;
      func3_r <= func3_in;
      rd_r <= rd_in;
      csr_addr_r <= csr_addr_in;
    end
  end

  // Keep reset and flush only on controls that can cause side effects.
  always @(posedge clk) begin
    if (rst) begin
      memew_r <= 1'b0;
      memer_r <= 1'b0;
      regew_control_r <= 1'b0;
      csrrw_r <= 1'b0;
      csrrs_r <= 1'b0;
      ecallsig_r <= 1'b0;
      fence_i_r <= 1'b0;
    end else if (pipline_valid) begin
      memew_r <= memew_in;
      memer_r <= memer_in;
      regew_control_r <= regew_control_in;
      csrrw_r <= csrrw_in;
      csrrs_r <= csrrs_in;
      ecallsig_r <= ecallsig_in;
      fence_i_r <= fence_i_in;
    end else if (flush) begin
      memew_r <= 1'b0;
      memer_r <= 1'b0;
      regew_control_r <= 1'b0;
      csrrw_r <= 1'b0;
      csrrs_r <= 1'b0;
      ecallsig_r <= 1'b0;
      fence_i_r <= 1'b0;
    end
  end

  // 输出连接到寄存器
  assign emit_out = emit_r;
  assign regout2_out = regout2_r;
  assign memew_out = memew_r;
  assign memer_out = memer_r;
  assign func3_out = func3_r;
  assign regew_control_out = regew_control_r;
  assign rd_out = rd_r;
  assign csrrw_out = csrrw_r;
  assign csrrs_out = csrrs_r;
  assign csr_addr_out = csr_addr_r;
  assign ecallsig_out = ecallsig_r;
  assign fence_i_out = fence_i_r;

endmodule

module ysyx_24100007_core #(
  parameter PORT_NUM=2  // 连接到arbiter的端口数量（IFU和WBU）
)(
  input clock,
  input reset,
  input io_interrupt,

  // AXI接口 - 连接到arbiter的master接口
  output [PORT_NUM-1:0] awvalid, 
  output [PORT_NUM-1:0] wvalid,  
  output [PORT_NUM-1:0] arvalid, 
  output [PORT_NUM-1:0] rready,
  output [PORT_NUM-1:0] bready,
  input [PORT_NUM-1:0] bvalid,
  input [PORT_NUM-1:0] rvalid,
  input [PORT_NUM-1:0] awready, 
  input [PORT_NUM-1:0] wready,  
  input [PORT_NUM-1:0] arready, 

  // AXI data channel
  output [PORT_NUM*32-1:0] araddr,
  output [PORT_NUM*32-1:0] awaddr,
  output [PORT_NUM*32-1:0] wdata,
  output [PORT_NUM*4-1:0] wstrb,
  input  [PORT_NUM*32-1:0] rdata,
  input  [PORT_NUM*2-1:0] bresp,
  output [PORT_NUM*3-1:0] awsize,
  output [PORT_NUM*3-1:0] arsize,
  
  // AXI burst transfer signals
  output [PORT_NUM*8-1:0] awlen,
  output [PORT_NUM*8-1:0] arlen,
  output [PORT_NUM*2-1:0] awburst,
  output [PORT_NUM*2-1:0] arburst,
  output [PORT_NUM-1:0] wlast,
  input [PORT_NUM-1:0] rlast,
  input [PORT_NUM*2-1:0]  rresp
);

  // Pipeline handshake signals
  wire ifu_to_idu_valid;
  wire idu_to_exu_valid;
  wire exu_to_wbu_valid;
  
  wire idu_to_ifu_ready;
  wire exu_to_idu_ready;
  wire wbu_to_exu_ready;

  wire [31:0] npc, ifu_pc;
  wire [31:0] inst;

  wire ifu_read_req;
  wire ifu_req_acp;
  wire ifu_req_finish;
  wire ifu_req_ready;
  wire [31:0] ifu_addr;
  wire [127:0] lsu_data_read;
  wire is_jmp;
  wire fence_i_idu;
  wire fence_i_exu;
  wire fence_i_wbu;
  wire fence_i_commit;
  wire fence_active;
  assign fence_active = fence_i_idu | fence_i_exu | fence_i_wbu;
  wire [31:0] regout1, regout2;
  wire [4:0] exu_rd_bypass;
  wire exu_regew_bypass;
  wire [31:0] exu_transmit_data;
  wire exu_transmit_data_valid;
  wire exu_memer_bypass;
  wire regew;
  wire [4:0] wbu_rd_bypass;
  wire wbu_regew_bypass;
  wire [31:0] wbu_transmit_data;
  wire wbu_transmit_data_valid;
  wire [4:0] wbu_reg_rd;
  wire wbu_commit;
  wire wbu_csrrw_out, wbu_csrrs_out;
  wire [11:0] wbu_csr_addr_out;
  wire wbu_ecallsig_out;
  wire wbu_write_csr;

  ysyx_24100007_ifu ifu0(
    .clk(clock),
    .rst(reset),
    .exu_npc(npc),
    .ready(idu_to_ifu_ready), // IDU to IFU ready
    .pc(ifu_pc),
    .inst(inst),
    .valid(ifu_to_idu_valid),
    .is_jmp(is_jmp),
    .fence_active(fence_active),
    .fence_commit(fence_i_commit),

    .ifu_read_req (ifu_read_req),
    .ifu_req_acp  (ifu_req_acp),
    .ifu_req_finish(ifu_req_finish),
    .ifu_req_ready(ifu_req_ready),
    .ifu_addr     (ifu_addr),
    .ifu_line_data(lsu_data_read)
  );

  wire [4:0] src1_addr, src2_addr, idu_rd;
  wire [31:0] imm;
  wire ebreaksig, mretsig, ecallsig;
  wire memew, memer, muximm;
  wire [2:0] func3, muxsig;
  wire func7;
  wire btypebranch, jalsig, jalrsig, auipcsig;
  wire [1:0] aluop;
  wire csrrw, csrrs;
  wire [11:0] csr_addr;
  wire [2:0] memmask;
  wire memsextsig;
  wire regew_control;
  wire [31:0] idu_pc;
  wire [31:0] src1_data, src2_data;
  ysyx_24100007_idu idu0(
  .clk(clock),
  .rst(reset),
  .inst_in(inst),
  .in_valid(ifu_to_idu_valid),
  .in_ready(idu_to_ifu_ready), 
  .out_valid(idu_to_exu_valid),
  .out_ready(exu_to_idu_ready), // IDU to IFU ready
  .is_jmp(is_jmp),
  .flush_in(fence_i_commit),
  .fence_block_in(fence_i_exu | fence_i_wbu),
  .pc_in(ifu_pc),

  .regout1(regout1),              // 从寄存器堆读出的数据
  .regout2(regout2),              // 从寄存器堆读出的数据

  .wbu_rd(wbu_rd_bypass),                // WBU 旁路接口
  .wbu_regew(wbu_regew_bypass),          // WBU 旁路接口
  .wbu_transmit_data(wbu_transmit_data),      // WBU 旁路接口
  .wbu_transmit_data_valid(wbu_transmit_data_valid), // WBU 旁路接口

  .exu_rd(exu_rd_bypass),                // EXU 旁路接口
  .exu_regew(exu_regew_bypass),          // EXU 旁路接口
  .exu_transmit_data(exu_transmit_data), // EXU 旁路接口
  .exu_transmit_data_valid(exu_transmit_data_valid), // EXU 旁路接口
  .exu_memer_bypass(exu_memer_bypass),  // EXU 是否是 load 指令（用于处理 load-use 冲突）

  .src1_data(src1_data),          // 经过旁路选择后的数据
  .src2_data(src2_data),          // 经过旁路选择后的数据

  .ebreaksig(ebreaksig),
  .ecallsig(ecallsig),
  .mretsig(mretsig),
  .imm(imm),
  .func3(func3),
  .func7(func7),
  .src1_addr(src1_addr),
  .src2_addr(src2_addr),
  .rd(idu_rd),
  .regew_control(regew_control),
  .memew(memew),
  .muxsig(muxsig),
  .memer(memer),
  .muximm(muximm),
  .btypebranch(btypebranch),
  .jalrsig(jalrsig),
  .jalsig(jalsig),
  .aluop(aluop),
  .auipcsig(auipcsig),
  .csrrw(csrrw),
  .csrrs(csrrs),
  .csr_addr(csr_addr),
  .memmask(memmask),
  .memsextsig(memsextsig),
  .fence_i(fence_i_idu),
  .pc_out(idu_pc)
);

  wire [31:0] regwrite;
  wire [31:0] mepc, mtvec;
  ysyx_24100007_regheap regfile(
    .clk(clock),
    .rst(reset),
    .ew(regew),
    .addr(wbu_reg_rd),
    .src1(src1_addr),             // 使用 IDU 输出的源寄存器地址
    .src2(src2_addr),             // 使用 IDU 输出的源寄存器地址
    .data(regwrite),
    .csr(wbu_csr_addr_out),       // 使用 WBU 阶段的 CSR 地址
    .csrrw(wbu_csrrw_out),        // 使用 WBU 阶段的 csrrw 信号
    .csrrs(wbu_csrrs_out),        // 使用 WBU 阶段的 csrrs 信号
    .ecallsig(wbu_ecallsig_out),  // 使用 WBU 阶段的 ecallsig 信号
    .regout1(regout1),            // 寄存器堆输出连接到 IDU
    .regout2(regout2),            // 寄存器堆输出连接到 IDU
    .mepc(mepc),
    .mtvec(mtvec)
  ); 
  
  wire [31:0] exu_emit;
  wire [4:0] exu_rd;  // EXU 的 rd_out（用于 WBU）

  // Signals from EXU to WBU
  wire exu_memew, exu_memer, exu_regew_control;
  wire [2:0] exu_func3;
  wire [31:0] exu_src2_out;  // src2 from EXU to WBU
  wire exu_csrrw_out, exu_csrrs_out;
  wire [11:0] exu_csr_addr_out;
  wire exu_ecallsig_out;

  // EXU 向 IDU 转发的旁路信号
  ysyx_24100007_exu exu0(
  .clk(clock),
  .rst(reset),

  .in_valid(idu_to_exu_valid),
  .in_ready(exu_to_idu_ready),  // WBU to EXU ready
  .out_ready(wbu_to_exu_ready), // EXU to IDU ready
  .out_valid(exu_to_wbu_valid),

  .func3_in(func3),
  .btypebranch_in(btypebranch),
  .func7_in(func7),
  .aluop_in(aluop),
  .jalrsig_in(jalrsig),
  .jalsig_in(jalsig),
  .imm_in(imm),
  .muximm_in(muximm),
  .pc_in(idu_pc),
  .auipcsig_in(auipcsig),

  .mretsig_in(mretsig),
  .ecallsig_in(ecallsig),
  .fence_i_in(fence_i_idu),
  .mtvec_in(mtvec),
  .mepc_in(mepc),

  .memew_in(memew),
  .memer_in(memer),
  .muxsig_in(muxsig),
  .regew_control_in(regew_control),
  .rd_in(idu_rd),
  .csrrw_in(csrrw),
  .csrrs_in(csrrs),
  .csr_addr_in(csr_addr),
  .wbu_write_csr(wbu_write_csr),
  .flush_in(fence_i_commit),
  .fence_block_in(fence_i_wbu),

  .src1_in(src1_data),         // 使用 IDU 经过旁路选择后的数据
  .src2_in(src2_data),         // 使用 IDU 经过旁路选择后的数据

  .emit_out(exu_emit),
  .npc(npc),
  .src2_out(exu_src2_out),           // to WBU
  .is_jmp(is_jmp),

  .memew_out(exu_memew),             // to WBU
  .memer_out(exu_memer),             // to WBU
  .func3_out(exu_func3),             // to WBU
  .regew_control_out(exu_regew_control),     // to WBU
  .rd_out(exu_rd),
  .csrrw_out(exu_csrrw_out),            // to WBU
  .csrrs_out(exu_csrrs_out),            // to WBU
  .csr_addr_out(exu_csr_addr_out),      // to WBU
  .ecallsig_out(exu_ecallsig_out),      // to WBU
  .fence_i_out(fence_i_exu),

  // EXU 向 IDU 转发的旁路信号
  .exu_rd(exu_rd_bypass),
  .exu_regew(exu_regew_bypass),
  .exu_transmit_data(exu_transmit_data),
  .exu_transmit_data_valid(exu_transmit_data_valid),
  .exu_memer_bypass(exu_memer_bypass)
);

  // WBU 向 IDU 转发的旁路信号
  wire wbu_read_req, wbu_write_req;
  wire wbu_req_acp, wbu_req_finish, wbu_req_ready;
  wire lsu_mem_we;
  wire [31:0] lsu_mem_addr, lsu_mem_wdata;
  wire [2:0] lsu_mem_mask;
  wire lsu_mem_sext;
  ysyx_24100007_wbu wbu0(
  .clk(clock),
  .rst(reset),
  .emit_in(exu_emit),
  .regout2_in(exu_src2_out),  // 使用从EXU传递的src2（已通过旁路选择）
  .memew_in(exu_memew),
  .memer_in(exu_memer),
  .func3_in(exu_func3),
  .regew_control_in(exu_regew_control),
  .rd_in(exu_rd),
  .csrrw_in(exu_csrrw_out),
  .csrrs_in(exu_csrrs_out),
  .csr_addr_in(exu_csr_addr_out),
  .ecallsig_in(exu_ecallsig_out),
  .fence_i_in(fence_i_exu),

  .regwrite_out(regwrite),
  .regew_out(regew),
  .rd_out(wbu_reg_rd),
  .csrrw_out(wbu_csrrw_out),
  .csrrs_out(wbu_csrrs_out),
  .csr_addr_out(wbu_csr_addr_out),
  .ecallsig_out(wbu_ecallsig_out),
  .fence_i_active(fence_i_wbu),
  .fence_i_commit(fence_i_commit),
  .wbu_write_csr(wbu_write_csr),

  .in_valid(exu_to_wbu_valid),
  .in_ready(wbu_to_exu_ready), // WBU to EXU ready

  .wbu_commit(wbu_commit),

  .wbu_read_req (wbu_read_req),
  .wbu_write_req(wbu_write_req),
  .wbu_req_acp  (wbu_req_acp),
  .wbu_req_finish(wbu_req_finish),
  .wbu_req_ready(wbu_req_ready),
  .wbu_data_read(lsu_data_read[31:0]),

  .lsu_mem_we   (lsu_mem_we),
  .lsu_mem_addr (lsu_mem_addr),
  .lsu_mem_wdata(lsu_mem_wdata),
  .lsu_mem_mask (lsu_mem_mask),
  .lsu_mem_sext (lsu_mem_sext),

  .wbu_rd(wbu_rd_bypass),      // for data forwarding to IDU
  .wbu_regew(wbu_regew_bypass),   // for data forwarding to IDU
  .transmit_data(wbu_transmit_data),     // for data forwarding to IDU
  .transmit_data_valid(wbu_transmit_data_valid) // for data forwarding to IDU
);

ysyx_24100007_lsu lsu0 (
  .clk   (clock),
  .rst   (reset),

  .ifu_read_req (ifu_read_req),
  .ifu_req_acp  (ifu_req_acp),
  .ifu_addr_in  (ifu_addr),

  .wbu_read_req (wbu_read_req),
  .wbu_write_req(wbu_write_req),
  .wbu_req_acp  (wbu_req_acp),

  .ifu_req_ready (ifu_req_ready),
  .ifu_req_finish(ifu_req_finish),
  .wbu_req_ready (wbu_req_ready),
  .wbu_req_finish(wbu_req_finish),

  .mem_we_in    (lsu_mem_we),
  .mem_addr_in  (lsu_mem_addr),
  .mem_wdata_in (lsu_mem_wdata),
  .mem_mask_in  (lsu_mem_mask),
  .mem_sext_in  (lsu_mem_sext),

  .data_read (lsu_data_read),

  // AXI master 接到 core port[1]
  .arvalid (arvalid),
  .arready (arready),
  .araddr  (araddr),
  .arlen   (arlen),
  .arsize  (arsize),
  .arburst (arburst),

  .awvalid (awvalid),
  .awready (awready),
  .awaddr  (awaddr),
  .awlen   (awlen),
  .awsize  (awsize),
  .awburst (awburst),

  .wvalid (wvalid),
  .wready (wready),
  .wdata  (wdata),
  .wstrb  (wstrb),
  .wlast  (wlast),

  .rvalid (rvalid),
  .rready (rready),
  .rdata  (rdata),
  .rlast  (rlast),

  .bvalid (bvalid),
  .bready (bready),
  .bresp  (bresp)
);


// synopsys translate_off
  ysyx_24100007_pipline_tracer tracer0(
    .clk(clock), 
    
    .ifu_to_idu_valid(ifu_to_idu_valid),
    .idu_to_exu_valid(idu_to_exu_valid),
    .exu_to_wbu_valid(exu_to_wbu_valid),
    
    .idu_to_ifu_ready(idu_to_ifu_ready),
    .exu_to_idu_ready(exu_to_idu_ready),
    .wbu_to_exu_ready(wbu_to_exu_ready),
    
    .is_jmp(is_jmp),
    .wbu_commit(wbu_commit), 
    
    .pc(ifu_pc),
    .inst(inst)
  );

// synopsys translate_on

endmodule

// synopsys translate_off
module ysyx_24100007_pipline_tracer(
  input clk,

  input ifu_to_idu_valid,
  input idu_to_exu_valid,
  input exu_to_wbu_valid,
  
  input idu_to_ifu_ready,
  input exu_to_idu_ready,
  input wbu_to_exu_ready,

  input is_jmp,
  input wbu_commit,

  input [31:0] pc,
  input [31:0] inst
);

  reg [31:0] idu_pc, idu_inst;
  reg [31:0] exu_pc, exu_inst;
  reg [31:0] wbu_pc, wbu_inst;

  always @(posedge clk) begin
    if(is_jmp) begin
      idu_pc <= 32'b0;
      idu_inst <= 32'b0;
    end else if(ifu_to_idu_valid && idu_to_ifu_ready) begin
      idu_pc <= pc;
      idu_inst <= inst;
    end

    if(idu_to_exu_valid && exu_to_idu_ready) begin
      exu_pc <= idu_pc;
      exu_inst <= idu_inst;
    end 

    if(exu_to_wbu_valid && wbu_to_exu_ready) begin
      wbu_pc <= exu_pc;
      wbu_inst <= exu_inst;
    end 
  end 

  `ifndef __ICARUS__
  import "DPI-C" function void npc_commit_inst(int valid, int pc, int inst);
  import "DPI-C" function void get_predict_miss(int is_jmp);
  import "DPI-C" function void npc_get_current_pc(int pc);
  `endif

  reg commit_sys;
  reg [31:0] commit_pc_sys;
  reg [31:0] commit_inst_sys;

  always @(posedge clk) begin
    commit_sys <= wbu_commit;
    commit_pc_sys <= wbu_pc;
    commit_inst_sys <= wbu_inst;
  end

  always @(posedge clk) begin
    `ifndef __ICARUS__
    npc_get_current_pc(pc);
    get_predict_miss({31'b0, is_jmp});
    npc_commit_inst({31'b0, commit_sys}, commit_pc_sys, commit_inst_sys); 
    `else
    // if (commit_sys) begin
    //   $display("[Trace] Time: %0t | PC: 0x%h | Inst: 0x%h", $time, commit_pc_sys, commit_inst_sys);
    // end
    `endif
  end

  wire dead_cyc = (wbu_inst == 32'h0000006f);
  always @(posedge clk) begin
    `ifndef __ICARUS__
    if(dead_cyc & wbu_commit) begin
      ret(0);
    end
    `else
    if(dead_cyc & wbu_commit) begin
      $display("HIT GOOD TRAP");
      $finish;
    end
    `endif
  end
endmodule
// synopsys translate_on

