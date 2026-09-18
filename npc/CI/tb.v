`timescale 1ns/1ps

module tb_ysyx_26010027;

  reg clock;
  reg reset;

  top dut (
    .clock   (clock),
    .reset   (reset)
  );

  // 100MHz clock (10ns period)
  initial begin
    clock = 1'b0;
    forever #1 clock = ~clock;
  end

  // reset sequence
  initial begin
    reset = 1'b1;
    repeat (1) @(posedge clock);
    reset = 1'b0;
  end

  // wave
  // initial begin
  //   $dumpfile("wave.vcd");
  //   $dumpvars(0, tb_ysyx_26010027);
  // end

  // finish sim
  reg [31:0] a0;
  always @(*) a0 = dut.my_cpu.my_WBU.my_gpr.rf[10];
  always @(posedge clock) begin
    if (!reset) begin
      // $display("pc: 0x%08x, inst=0x%08x, a0=0x%08x", dut.my_cpu.my_IFU.ifu_idu_pc, dut.my_cpu.my_IFU.ifu_idu_inst, a0);
      if (dut.my_cpu.lsu_wbu_valid && dut.my_cpu.lsu_wbu_inst == 32'h0010_0073) begin
        if (a0 == 32'd0) $display("[TB] -HIT GOOD TRAP- EBREAK committed at time=%0t, pc=0x%08x",
                 $time, dut.my_cpu.lsu_wbu_pc);
        else $display("[TB] -HIT BAD TRAP- EBREAK committed at time=%0t, pc=0x%08x,",
                 $time, dut.my_cpu.lsu_wbu_pc);
        $finish;
      end
    end
  end

  // timeout
  initial begin
    #10000000;
    $display("[TB] TIMEOUT at %0t, pc=0x%08x", $time, dut.my_cpu.lsu_wbu_pc);
    $finish;
  end

endmodule
