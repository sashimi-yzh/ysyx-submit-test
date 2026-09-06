module exu_test (
  input        clk,
  input        rst_n,

  // Optional observation ports for synthesis/timing analysis
  output [31:0] res_q,
  output [31:0] npc_q,
  output [31:0] pcwritereg_q
);

  // ---------------------------------------------------------------------------
  // Input registers (drive EXU through a registered interface)
  // ---------------------------------------------------------------------------
  reg [2:0]  func3_r;
  reg        btypebranch_r;
  reg        func7_r;
  reg [1:0]  aluop_r;
  reg        jalrsig_r;
  reg        jalsig_r;
  reg [31:0] imm_r;
  reg        muximm_r;
  reg [31:0] regout1_r;
  reg [31:0] regout2_r;
  reg [31:0] pc_r;
  reg        auipcsig_r;
  reg        mretsig_r;
  reg        ecallsig_r;
  reg [31:0] mtvec_r;
  reg [31:0] mepc_r;
  reg        valid_from_r;
  reg        ready_from_r;

  // Simple stimulus pattern to exercise the adder and EXU datapath
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      func3_r       <= 3'b000;
      btypebranch_r <= 1'b0;
      func7_r       <= 1'b0;
      aluop_r       <= 2'b00;
      jalrsig_r     <= 1'b0;
      jalsig_r      <= 1'b0;
      imm_r         <= 32'h0;
      muximm_r      <= 1'b0;
      regout1_r     <= 32'h0;
      regout2_r     <= 32'h0;
      pc_r          <= 32'h0;
      auipcsig_r    <= 1'b0;
      mretsig_r     <= 1'b0;
      ecallsig_r    <= 1'b0;
      mtvec_r       <= 32'h0;
      mepc_r        <= 32'h0;
      valid_from_r  <= 1'b0;
      ready_from_r  <= 1'b0;
    end
    else begin
      // Always-true handshake so the path is always active
      valid_from_r  <= 1'b1;
      ready_from_r  <= 1'b1;

      // Generate changing operands to keep the adder busy
      regout1_r <= regout1_r + 32'd1;
      regout2_r <= regout2_r + 32'd2;
      imm_r     <= imm_r + 32'd4;
      pc_r      <= pc_r + 32'd4;

      // Cycle through some basic ALU operation encodings
      func3_r  <= func3_r + 3'd1;
      aluop_r  <= aluop_r + 2'd1;

      // Keep control-related signals mostly inactive in this simple test
      btypebranch_r <= 1'b0;
      jalrsig_r     <= 1'b0;
      jalsig_r      <= 1'b0;
      muximm_r      <= 1'b0;
      auipcsig_r    <= 1'b0;
      mretsig_r     <= 1'b0;
      ecallsig_r    <= 1'b0;

      // Fixed trap vectors for completeness
      mtvec_r <= 32'h0000_1000;
      mepc_r  <= 32'h0000_2000;
    end
  end

  // ---------------------------------------------------------------------------
  // EXU instance (combinational datapath between input and output registers)
  // ---------------------------------------------------------------------------
  wire [31:0] res_w;
  wire [31:0] npc_w;
  wire [31:0] pcwritereg_w;
  wire        valid_to_w;
  wire        ready_to_w;

  ysyx_24100007_exu u_exu (
    .func3      (func3_r),
    .btypebranch(btypebranch_r),
    .func7      (func7_r),
    .aluop      (aluop_r),
    .jalrsig    (jalrsig_r),
    .jalsig     (jalsig_r),
    .imm        (imm_r),
    .muximm     (muximm_r),
    .regout1    (regout1_r),
    .regout2    (regout2_r),
    .pc         (pc_r),
    .auipcsig   (auipcsig_r),
    .mretsig    (mretsig_r),
    .ecallsig   (ecallsig_r),
    .mtvec      (mtvec_r),
    .mepc       (mepc_r),
    .valid_from (valid_from_r),
    .ready_from (ready_from_r),

    .res        (res_w),
    .npc        (npc_w),
    .pcwritereg (pcwritereg_w),
    .valid_to   (valid_to_w),
    .ready_to   (ready_to_w)
  );

  // ---------------------------------------------------------------------------
  // Output registers (capture EXU results at the clock edge)
  // These define the timing path: input_regs -> EXU -> output_regs.
  // ---------------------------------------------------------------------------
  reg [31:0] res_r_q;
  reg [31:0] npc_r_q;
  reg [31:0] pcwritereg_r_q;

  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      res_r_q        <= 32'h0;
      npc_r_q        <= 32'h0;
      pcwritereg_r_q <= 32'h0;
    end
    else begin
      res_r_q        <= res_w;
      npc_r_q        <= npc_w;
      pcwritereg_r_q <= pcwritereg_w;
    end
  end

  assign res_q        = res_r_q;
  assign npc_q        = npc_r_q;
  assign pcwritereg_q = pcwritereg_r_q;

endmodule


