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
