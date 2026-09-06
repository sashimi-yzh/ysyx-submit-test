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
  wire        wbu_read_full_word;

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

      .araddr (wbu_araddr),
      .awaddr (wbu_awaddr),
      .arsize (wbu_arsize),
      .awsize (wbu_awsize),
      .arlen  (wbu_arlen),
      .awlen  (wbu_awlen),
      .arburst(wbu_arburst),
      .awburst(wbu_awburst),
      .wdata  (wbu_wdata),
      .wstrb  (wbu_wstrb),
      .read_full_word(wbu_read_full_word)
  );

  wire is_read = (master == IFU) | (master == WBU_R);
  wire is_write = (master == WBU_W);
  reg  aw_done;
  reg  w_done;

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
  assign awvalid = is_write & (state == WAIT_HANDSHAKE) & !aw_done;
  assign wvalid  = is_write & (state == WAIT_HANDSHAKE) & !w_done;
  assign rready  = is_read & (state == WAIT_SLAVE);
  assign bready  = is_write & (state == WAIT_SLAVE);

  wire aw_fire = awvalid & awready;
  wire w_fire = wvalid & wready;

  always @(posedge clk) begin
    if (rst) begin
      state <= READY;
      aw_done <= 1'b0;
      w_done <= 1'b0;
    end else begin
      case (state)
        READY: begin
          aw_done <= 1'b0;
          w_done <= 1'b0;
          if (has_req) state <= WAIT_HANDSHAKE;
        end

        WAIT_HANDSHAKE: begin
          if (is_write) begin
            if (aw_fire) aw_done <= 1'b1;
            if (w_fire) w_done <= 1'b1;
            if ((aw_done || aw_fire) && (w_done || w_fire)) begin
              state <= WAIT_SLAVE;
              aw_done <= 1'b0;
              w_done <= 1'b0;
            end
          end else if (is_read && arready) begin
            state <= WAIT_SLAVE;
          end
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

  wire [31:0] memread;
  ysyx_24100007_memreadlen memreadlen_u (
      .data       (rdata),
      .memmask    (mem_mask),
      .memsextsig (mem_sext),
      .read_full_word(wbu_read_full_word),
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
