module ysyx_26030092_PerfCounterArray(
    input io_clock,
    input io_reset,
    input io_event
);
`ifdef NPC_DPI
    reg [63:0] counter;

    always @(posedge io_clock) begin
        if (io_reset) counter <= 64'h0;
        else if (io_event) counter <= counter + 64'h1;
    end

    export "DPI-C" task perf_read;
    task perf_read(output longint data);
        data = counter;
    endtask
`endif
endmodule
