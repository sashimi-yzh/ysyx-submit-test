`ifndef VERILATOR
module testbench;
  reg [4095:0] vcdfile;
  reg clock;
`else
module testbench(input clock, output reg genclock);
  initial genclock = 1;
`endif
  reg genclock = 1;
  reg [31:0] cycle = 0;
  reg [31:0] PI_ifu_icache_pc;
  reg [0:0] PI_reset;
  wire [0:0] PI_clock = clock;
  formal_verification_top UUT (
    .ifu_icache_pc(PI_ifu_icache_pc),
    .reset(PI_reset),
    .clock(PI_clock)
  );
`ifndef VERILATOR
  initial begin
    if ($value$plusargs("vcd=%s", vcdfile)) begin
      $dumpfile(vcdfile);
      $dumpvars(0, testbench);
    end
    #5 clock = 0;
    while (genclock) begin
      #5 clock = 0;
      #5 clock = 1;
    end
  end
`endif
  initial begin
`ifndef VERILATOR
    #1;
`endif
    // UUT.$auto$async2sync.\cc:101:execute$125  = 1'b0;
    // UUT.$auto$async2sync.\cc:110:execute$129  = 1'b1;
    UUT.icache_inst.icache_Xbar_ar_valid = 1'b0;
    UUT.icache_inst.icache_Xbar_r_ready = 1'b0;
    UUT.icache_inst.reg_icache_r_handshake = 1'b0;
    UUT.icache_inst.state = 2'b10;
    UUT.icache_inst.data_array[3'b000] = 32'b00000000000000000000000000000000;
    UUT.icache_inst.tag_array[3'b000] = 28'b0000000000000000000000000000;
    UUT.memory[1'b0] = 32'b10000000000000000000000000000000;

    // state 0
    PI_ifu_icache_pc = 32'b00000000000000000000000000000000;
    PI_reset = 1'b0;
  end
  always @(posedge clock) begin
    // state 1
    if (cycle == 0) begin
      PI_ifu_icache_pc <= 32'b00000000000000000000000000000000;
      PI_reset <= 1'b0;
    end

    genclock <= cycle < 1;
    cycle <= cycle + 1;
  end
endmodule
