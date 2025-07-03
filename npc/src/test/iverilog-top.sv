module iverilog_top();
  reg clock;
  reg reset;
  initial begin
    //$dumpfile("test.vcd");
    //$dumpvars(0,top);

    clock = 0;
    reset = 1;
    # 10
    reset = 0;
  end
  always begin
    # 1 clock = ~clock;
  end
  ysyx_88888888_Top top(clock, reset);
endmodule
