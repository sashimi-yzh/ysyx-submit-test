`timescale 1ns/1ps
module ysyx_26040117_iverilog_tb;
    reg clock=0;
    reg reset=1;

    always #5 clock=~clock;

    initial begin
        repeat(10) @(negedge clock);
        reset=0;
    end

    ysyx_26040117_iverilog dut(
        .clock(clock),
        .reset(reset)
    );
endmodule
