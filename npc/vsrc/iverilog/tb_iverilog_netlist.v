`timescale 1ns / 1ns

module tb_iverilog_netlist;

    localparam [31:0] DEFAULT_BOOT_FETCH_PC = 32'h3000_0000;
    localparam integer DEFAULT_MAX_CYCLES = 2000000;

    reg clock;
    reg reset;
    reg [31:0] boot_fetch_pc;
    integer max_cycles;

    integer cycle_count;
    reg dump_started;
    reg first_ifu_seen;

    wire ifu_ar_fire;

    assign ifu_ar_fire = dut.axi_arvalid && dut.axi_arready;

    top dut (
        .clock                  (clock),
        .reset                  (reset)
    );

    initial begin
        clock = 1'b0;
        forever #5 clock = ~clock;
    end

    initial begin
        reset = 1'b1;
        boot_fetch_pc = DEFAULT_BOOT_FETCH_PC;
        max_cycles = DEFAULT_MAX_CYCLES;
        cycle_count = 0;
        dump_started = 1'b0;
        first_ifu_seen = 1'b0;

        if (!$value$plusargs("BOOT_FETCH_PC=%h", boot_fetch_pc)) begin
            boot_fetch_pc = DEFAULT_BOOT_FETCH_PC;
        end
        if (!$value$plusargs("MAX_CYCLES=%d", max_cycles)) begin
            max_cycles = DEFAULT_MAX_CYCLES;
        end

        repeat (10) @(posedge clock);
        reset = 1'b0;
    end

    always @(posedge clock) begin
        if (reset) begin
            first_ifu_seen = 1'b0;
        end else begin
            cycle_count = cycle_count + 1;

            if ($test$plusargs("WAVE") && !dump_started) begin
                dump_started = 1'b1;
                $dumpfile("build/iverilog-netlist/wave.vcd");
                $dumpvars(0, tb_iverilog_netlist);
                $dumpvars(0, dut);
            end

            if (ifu_ar_fire && !first_ifu_seen) begin
                first_ifu_seen = 1'b1;
                if (dut.axi_araddr !== boot_fetch_pc) begin
                    $display("BAD RESET FETCH at pc = 0x%08x expected = 0x%08x",
                        dut.axi_araddr, boot_fetch_pc);
                    $finish;
                end
            end

            if ((max_cycles > 0) && (cycle_count >= max_cycles)) begin
                $display("TIMEOUT at cycle %0d", cycle_count);
                $finish;
            end

        end
    end

endmodule
