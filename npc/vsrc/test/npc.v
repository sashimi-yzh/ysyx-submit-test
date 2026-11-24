`timescale 1ns / 100ps
//`define WAVE_DUMP

module tb_ysyxSoCFull;

  // 1. Declare signals to connect with the Device Under Test (DUT)
  reg clock;
  reg reset;
  reg io_interrupt;
  reg [31:0] last_done_pc;
  reg [31:0] last_done_inst;

  // 2. Instantiate the Device Under Test (DUT)
  ysyxSoCFull u_dut (
  .clock       (clock),
  .reset       (reset),
  .io_interrupt(io_interrupt)
  );

  // 3. Generate clock signal (10ns period -> 100MHz clock frequency)
  always #5 clock = ~clock;

  integer fd;

  initial begin
    fd = $fopen("build/exec_trace.txt", "w");
    if (fd == 0) begin
      $display("Failed to open trace file");
      $finish;
    end
  end

  // 4. Control reset assertion for exactly 10 clock cycles
  initial begin
    // Initialize inputs
    clock        = 0;
    io_interrupt = 0;
    last_done_pc = 32'h0;
    last_done_inst = 32'h0;

    // Assert active-high reset at the very beginning
    reset        = 1;

    // Wait for exactly 10 rising edges of the clock
    repeat (10) begin
      @(posedge clock);
    end

    // Add a small delay (1ns) after the 10th clock edge to prevent
    // clock-to-signal race conditions in simulation (Hold time safety)
    #1;
    reset = 0;  // Deassert reset, allowing the system to start running

    $display("[TB INFO] Reset released after 10 clock cycles at time %t", $time);
  end

  // 5. Simulation control and waveform dumping
  initial begin
    // Create VCD waveform file
`ifdef WAVE_DUMP
    $dumpfile("build/riscv-iverilog.fsd");
    $dumpvars(0, tb_ysyxSoCFull);
`endif

    // Normal end: halt() in AM writes the exit code to the finisher
    // (npc_soc.v vuart offset 0x4), which prints GOOD/BAD TRAP and calls $finish.
    // This is only a safety net for programs that never halt (e.g. yield).
    repeat (8000000) @(posedge clock);
    $display("[TB INFO] cycle limit reached before halt; simulation finished.");
    $finish;
  end

  final begin
    $fclose(fd);
  end

endmodule
