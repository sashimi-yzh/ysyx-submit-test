`timescale 1ns / 1ns

module tb_iverilog_net;
    localparam integer MAX_CYCLES = 4000000;

    reg clock;
    reg reset;
    integer max_cycles;
    integer cycle_count;
    reg [63:0] uart_tail;   // UART 写出字符的滑动窗口

    top dut (
        .clock (clock),
        .reset (reset)
    );

    initial begin
        clock = 1'b0;
        forever #5 clock = ~clock;
    end

    initial begin
        reset = 1'b1;
        max_cycles = MAX_CYCLES;
        uart_tail = 64'b0;

        if (!$value$plusargs("MAX_CYCLES=%d", max_cycles)) begin
            max_cycles = MAX_CYCLES;
        end

        repeat (10) @(posedge clock);
        reset = 1'b0;
    end

    wire uart_wr = dut.axi_awvalid && dut.axi_awready &&
                   dut.axi_wvalid  && dut.axi_wready  &&
                   (dut.axi_awaddr >= 32'h1000_0000) &&
                   (dut.axi_awaddr <= 32'h1000_0fff);

    always @(posedge clock) begin
        if (reset) begin
            cycle_count = 0;
            uart_tail   = 64'b0;
        end else begin
            cycle_count = cycle_count + 1;
            if (uart_wr) uart_tail = {uart_tail[55:0], dut.axi_wdata[7:0]};

            // "PASS\n" / "FAIL\n"
            // "huge}\n"
            if ((uart_tail[39:0] == 40'h50_41_53_53_0A) ||
                (uart_tail[39:0] == 40'h46_41_49_4C_0A) ||
                (uart_tail[47:0] == 48'h68_75_67_65_7D_0A)) begin
                $display("[TB] UART done at cycle %0d", cycle_count);
                $finish;
            end
            if ((max_cycles > 0) && (cycle_count >= max_cycles)) begin
                $display("TIMEOUT at cycle %0d", cycle_count);
                $finish;
            end
        end
    end

endmodule
