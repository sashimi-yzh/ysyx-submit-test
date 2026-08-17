`timescale 1ns / 100ps
module tb_npc;
  reg clock, reset;
  reg [31:0] mem[0:32'h1FFFFFF];
  always #0.5 clock = ~clock;

  wire [31:0] pc;
  wire step, ebreak;
  wire [31:0] raddr;
  wire [31:0] waddr;
  wire [31:0] wdata;
  wire [3:0] wmask;
  wire [31:0] wmask32;
  wire wen;
  wire valid;
  reg [31:0] rdata;
  integer inst_cnt;
  initial begin : init
    $readmemh("build/iv/temp.hex", mem);
    for (integer i = 0; i < 32'h2FFFF; i = i + 1) begin : convert_endian
      reg [31:0] raw;
      raw = mem[i];
      mem[i] = {raw[7-:8], raw[15-:8], raw[23-:8], raw[31-:8]};
    end
    $display("First 8 instructions :");
    $display("%08x %08x %08x %08x", mem[0], mem[1], mem[2], mem[3]);
    $display("%08x %08x %08x %08x", mem[4], mem[5], mem[6], mem[7]);

    inst_cnt = 0;
    clock = 1'b1;
    reset = 1'b1;
    repeat (3) @(negedge clock);
    reset = 1'b0;
  end

  npc_top_iverilog dut (
      .clock(clock),
      .reset(reset),
      .io_pc(pc),
      .io_ebreak(ebreak),
      .io_ok_to_step(step),
      .tb_io_raddr(raddr),
      .tb_io_waddr(waddr),
      .tb_io_wdata(wdata),
      .tb_io_valid(valid),
      .tb_io_wen(wen),
      .tb_io_wmask(wmask),
      .tb_io_rdata(rdata)
  );

  assign wmask32 = {{8{wmask[3]}}, {8{wmask[2]}}, {8{wmask[1]}}, {8{wmask[0]}}};

  always @(posedge clock) if (valid && !reset) rdata <= mem[(raddr-32'h80000000)>>2];

  always @(posedge clock) begin
    if (reset) inst_cnt <= 0;
    else if (step) begin
      inst_cnt = inst_cnt + 1;
      //   $display("PC = %08x", pc);
    end
  end

  always @(posedge clock) begin
    if (ebreak && !reset) begin
      $display("HALT@PC=%08h, inst count : %0d", pc, inst_cnt);
      $display("a0 = %08h", dut.cpu.gpr.register_bank_regs_9_r);
      if (dut.cpu.gpr.register_bank_regs_9_r === 32'h0) begin
        $display("HIT GOOD TRAP");
        $finish;
      end else begin
        $display("HIT BAD TRAP");
        $fatal;
      end

    end
  end

  always @(posedge clock) begin
    if (wen && !reset) begin
      mem[(waddr-32'h80000000)>>2] = (mem[(waddr-32'h80000000)>>2] & ~wmask32) | (wdata & wmask32);
    end

  end



endmodule
