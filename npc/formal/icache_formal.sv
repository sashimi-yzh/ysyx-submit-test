module icache_formal;
  localparam integer BLOCK_BYTES = 4;
  localparam integer NUM_LINES   = 16;
  localparam integer MEM_WORDS   = 256;
  localparam integer MEM_AW      = 8;

  (* gclk *) reg clk = 1'b0;
  reg reset = 1'b1;

  (* anyseq *) reg        ifu_req_valid;
  (* anyseq *) reg [31:0] ifu_req_addr;
  (* anyseq *) reg        ifu_resp_ready;

  wire        ifu_req_ready;
  wire        ifu_resp_valid;
  wire [31:0] ifu_resp_data;

  wire [31:0] mem_araddr;
  wire        mem_arvalid;
  wire [ 2:0] mem_arsize;
  wire        mem_arready = 1'b1;

  reg  [31:0] mem_rdata = 32'b0;
  reg         mem_rvalid = 1'b0;
  wire        mem_rready;

  reg         f_pending = 1'b0;
  reg [31:0]  f_pending_data = 32'b0;
  reg [31:0]  f_mem [MEM_WORDS];
  reg         f_req_pending = 1'b0;
  reg [31:0]  f_req_addr = 32'b0;

  ysyx_24110012_icache #(
    .BLOCK_BYTES(BLOCK_BYTES),
    .NUM_LINES  (NUM_LINES)
  ) dut (
    .clk           (clk),
    .reset         (reset),
    .ifu_req_valid (ifu_req_valid),
    .ifu_req_ready (ifu_req_ready),
    .ifu_req_addr  (ifu_req_addr),
    .ifu_resp_valid(ifu_resp_valid),
    .ifu_resp_ready(ifu_resp_ready),
    .ifu_resp_data (ifu_resp_data),
    .mem_araddr    (mem_araddr),
    .mem_arvalid   (mem_arvalid),
    .mem_arsize    (mem_arsize),
    .mem_arready   (mem_arready),
    .mem_rdata     (mem_rdata),
    .mem_rvalid    (mem_rvalid),
    .mem_rready    (mem_rready)
  );

  always @(posedge clk) begin
    reset <= 1'b0;

    if (reset) begin
      f_pending   <= 1'b0;
      mem_rvalid  <= 1'b0;
      mem_rdata   <= 32'b0;
    end else begin
      if (mem_rvalid && mem_rready) begin
        f_pending <= 1'b0;
      end else if (mem_arvalid && mem_arready) begin
        f_pending      <= 1'b1;
        f_pending_data <= f_mem[mem_araddr[MEM_AW+1:2]];
      end

      mem_rvalid <= f_pending;
      mem_rdata  <= f_pending_data;

      if (ifu_req_valid && ifu_req_ready) begin
        f_req_pending <= 1'b1;
        f_req_addr    <= ifu_req_addr;
      end

      if (ifu_resp_valid && ifu_resp_ready) begin
        f_req_pending <= 1'b0;
      end
    end
  end

  always @(posedge clk) begin
    if (!reset) begin
      if (ifu_resp_valid) begin
        assert(f_req_pending);
        assert(ifu_resp_data == f_mem[f_req_addr[MEM_AW+1:2]]);
      end
    end
  end
endmodule
