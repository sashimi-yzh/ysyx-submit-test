`timescale 1ns / 1ns

module tb_iverilog_netlist;
    localparam integer DEFAULT_MAX_CYCLES = 6_000_000;

    reg clock;
    reg reset;

    wire        halt_seen;
    wire [31:0] halt_status;

    wire        retire_valid;
    wire [31:0] retire_pc;
    wire [31:0] retire_inst;

    wire rd_hs = dut.bus_arvalid && dut.bus_arready;
    wire rd_rsp_hs  = dut.bus_rvalid  && dut.bus_rready;
    wire wr_addr_hs = dut.bus_awvalid && dut.bus_awready;
    wire wr_data_hs  = dut.bus_wvalid  && dut.bus_wready;
    wire wr_rsp_hs  = dut.bus_bvalid  && dut.bus_bready;

    integer cycles;
    integer max_cycles;
    integer trace_count;
    integer trace_limit;
    reg     wave_started;
    reg     first_fetch_seen;
    reg [31:0] read_addr_q;
    reg [31:0] last_retire_pc;

    npc_top dut (
        .clock          (clock),
        .reset          (reset),
        .halt_seen (halt_seen),
        .halt_status  (halt_status)
    );

    assign retire_valid = dut.retire_seen;
    assign retire_pc    = dut.retire_pc;
    assign retire_inst  = dut.retire_word;

    initial begin
        clock = 1'b0;
        forever #5 clock = ~clock;
    end

    initial begin
        reset            = 1'b1;
        cycles           = 0;
        max_cycles       = DEFAULT_MAX_CYCLES;
        trace_count      = 0;
        trace_limit      = 64;
        wave_started     = 1'b0;
        first_fetch_seen = 1'b0;
        read_addr_q      = 32'b0;
        last_retire_pc   = 32'b0;

        if (!$value$plusargs("MAX_CYCLES=%d", max_cycles)) begin
            max_cycles = DEFAULT_MAX_CYCLES;
        end
        if (!$value$plusargs("TRACE_LIMIT=%d", trace_limit)) begin
            trace_limit = 64;
        end

        repeat (10) @(posedge clock);
        #1 reset = 1'b0;
    end

    always @(posedge clock) begin
        if (reset) begin
            cycles           = 0;
            trace_count      = 0;
            first_fetch_seen = 1'b0;
            read_addr_q      = 32'b0;
            last_retire_pc   = 32'b0;
        end else begin
            cycles = cycles + 1;

            if ($test$plusargs("WAVE") && !wave_started) begin
                wave_started = 1'b1;
                $dumpfile("build/iverilog-netlist/wave.vcd");
                $dumpvars(0, tb_iverilog_netlist);
            end

            if (rd_hs) begin
                read_addr_q = dut.bus_araddr;
                if (!first_fetch_seen) begin
                    first_fetch_seen = 1'b1;
                    $display("RESET FETCH at pc = 0x%08x", dut.bus_araddr);
                end
            end

            if (retire_valid) begin
                last_retire_pc = retire_pc;
                if ($test$plusargs("TRACE_INST") &&
                    (trace_count < trace_limit)) begin
                    $display("TRACE: pc=0x%08x inst=0x%08x cycle=%0d",
                        retire_pc, retire_inst, cycles);
                    trace_count = trace_count + 1;
                end
            end

            if ($test$plusargs("TRACE_LOAD") && rd_rsp_hs &&
                (trace_count < trace_limit)) begin
                $display("AXI-R: addr=0x%08x data=0x%08x resp=%0d cycle=%0d",
                    read_addr_q, dut.bus_rdata, dut.bus_rresp, cycles);
                trace_count = trace_count + 1;
            end

            if ($test$plusargs("TRACE_STORE") &&
                (trace_count < trace_limit)) begin
                if (wr_addr_hs) begin
                    $display("AXI-AW: addr=0x%08x size=%0d cycle=%0d",
                        dut.bus_awaddr, dut.bus_awsize, cycles);
                end
                if (wr_data_hs) begin
                    $display("AXI-W: data=0x%08x strb=0x%x cycle=%0d",
                        dut.bus_wdata, dut.bus_wstrb, cycles);
                end
                if (wr_rsp_hs) begin
                    $display("AXI-B: resp=%0d cycle=%0d", dut.bus_bresp, cycles);
                    trace_count = trace_count + 1;
                end
            end

            if (halt_seen === 1'b1) begin
                if (halt_status === 32'b0) begin
                    $display("HIT GOOD TRAP at pc = 0x%08x cycle = %0d",
                        last_retire_pc, cycles);
                end else begin
                    $display("HIT BAD TRAP at pc = 0x%08x code = 0x%08x cycle = %0d",
                        last_retire_pc, halt_status, cycles);
                end
                $finish;
            end

            if ((max_cycles > 0) && (cycles >= max_cycles)) begin
                if (!first_fetch_seen) begin
                    $display("NO RESET FETCH before timeout at cycle %0d", cycles);
                end else begin
                    $display("TIMEOUT waiting for AM exit at cycle %0d", cycles);
                end
                $finish;
            end
        end
    end
endmodule
