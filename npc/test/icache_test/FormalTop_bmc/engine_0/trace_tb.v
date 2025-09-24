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
  wire [0:0] PI_clk = clock;
  reg [0:0] PI_reset;
  FormalTop UUT (
    .clk(PI_clk),
    .reset(PI_reset)
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
    // UUT.$auto$async2sync.\cc:101:execute$181  = 1'b0;
    // UUT.$auto$async2sync.\cc:110:execute$185  = 1'b1;
    UUT.dut.icache_Xbar_ar_valid = 1'b0;
    UUT.dut.icache_Xbar_r_ready = 1'b0;
    UUT.dut.state = 2'b00;
    UUT.last_ref_data = 32'b10000000000000000000000000000000;
    UUT.mem.rdata = 32'b00000000000000000000000000000000;
    UUT.ref_en = 1'b0;
    UUT.req_pc = 32'b00000000000000000000000000000000;
    UUT.req_valid = 1'b0;
    UUT.state = 3'b011;
    UUT.dut.data_array[4'b0000] = 32'b00000000000000000000000000000000;
    UUT.dut.tag_array[4'b0000] = 27'b000000000000000000000000000;
    UUT.mem.mem[7'b0000000] = 32'b00000000000000000000010000010011;

    // state 0
    PI_reset = 1'b0;
  end
  always @(posedge clock) begin
    // state 1
    if (cycle == 0) begin
      PI_reset <= 1'b0;
    end

    genclock <= cycle < 1;
    cycle <= cycle + 1;
  end
endmodule
