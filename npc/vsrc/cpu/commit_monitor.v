module ysyx_26010028_commit_monitor (
    input              clock,
    input              reset,

    input              retire_valid,
    input       [31:0] retire_pc,
    input       [31:0] retire_inst,
    input       [31:0] retire_next_pc,
    input      [1023:0] gpr_snapshot,
    input       [31:0] csr_mstatus,
    input       [31:0] csr_mtvec,
    input       [31:0] csr_mepc,
    input       [31:0] csr_mcause,

    input              axi_ar_fire,
    input       [31:0] axi_araddr,
    input       [ 7:0] axi_arlen,
    input       [ 2:0] axi_arsize,

    input              axi_r_fire,
    input       [ 1:0] axi_rresp,
    input              axi_rlast,

    input              axi_aw_fire,
    input       [31:0] axi_awaddr,
    input       [ 7:0] axi_awlen,
    input       [ 2:0] axi_awsize,

    input              axi_w_fire,
    input              axi_wlast,

    input              axi_b_fire,
    input       [ 1:0] axi_bresp,

    input              trace_ar_fire,
    input       [31:0] trace_araddr,
    input       [ 2:0] trace_arsize,
    input              trace_r_fire,
    input       [31:0] trace_rdata,
    input              trace_aw_fire,
    input       [31:0] trace_awaddr,
    input       [ 2:0] trace_awsize,
    input              trace_w_fire,
    input       [31:0] trace_store_data,
    input              trace_b_fire
);

`ifdef NPC_SIMULATION
`ifndef SYNTHESIS
    // AXI read master port
    reg [31:0] read_base_q;
    reg [ 7:0] read_len_q;
    reg [ 2:0] read_size_q;
    reg [ 7:0] read_beat_q;
    // AXI write master port
    reg [31:0] write_addr_q;
    reg [ 7:0] write_len_q;
    reg [ 2:0] write_size_q;
    reg        aw_seen_q;
    reg        w_seen_q;
    // Recent retired instruction & pc
    reg [31:0] last_pc_q;
    reg [31:0] last_inst_q;
    // true error address even there is no axi burst but the port still remain
    wire [31:0] read_fault_addr = read_base_q
        + ({{24{1'b0}}, read_beat_q} << read_size_q);

    always @(posedge clock) begin
        if (reset) begin
            read_base_q <= 32'b0;
            read_len_q  <= 8'b0;
            read_size_q <= 3'b0;
            read_beat_q <= 8'b0;

            write_addr_q <= 32'b0;
            write_len_q  <= 8'b0;
            write_size_q <= 3'b0;
            aw_seen_q    <= 1'b0;
            w_seen_q     <= 1'b0;

            last_pc_q   <= 32'b0;
            last_inst_q <= 32'b0;
        end else begin
            if (retire_valid) begin
                last_pc_q   <= retire_pc;
                last_inst_q <= retire_inst;
            end
            if (axi_ar_fire) begin
                read_base_q <= axi_araddr;
                read_len_q  <= axi_arlen;
                read_size_q <= axi_arsize;
                read_beat_q <= 8'b0;
            end else if (axi_r_fire && !axi_rlast) begin
                read_beat_q <= read_beat_q + 8'd1;
            end
            if (axi_r_fire && (axi_rresp !== 2'b00)) begin
                $fatal(1,
                    "cpu: AXI read response=%0b addr=%08x base=%08x beat=%0d/%0d size=%0d last_pc=%08x last_inst=%08x",
                    axi_rresp, read_fault_addr, read_base_q,
                    read_beat_q, read_len_q, read_size_q,
                    last_pc_q, last_inst_q);
            end
            if (axi_aw_fire) begin
                if (aw_seen_q) begin
                    $fatal(1,
                        "cpu: AXI arrived before previous write response: old_addr=%08x new_addr=%08x",
                        write_addr_q,
                        axi_awaddr);
                end
                write_addr_q <= axi_awaddr;
                write_len_q  <= axi_awlen;
                write_size_q <= axi_awsize;
                aw_seen_q    <= 1'b1;
                if (axi_awlen != 8'd0) begin
                    $fatal(1,
                        "cpu: only single-beat writes are supported: addr=%08x len=%0d size=%0d",
                        axi_awaddr,
                        axi_awlen,
                        axi_awsize);
                end
            end
            if (axi_w_fire) begin
                w_seen_q <= 1'b1;

                if (!axi_wlast) begin
                    $fatal(1,
                        "cpu: WLAST is required for a single-beat write: addr=%08x",
                        axi_aw_fire ? axi_awaddr : write_addr_q);
                end
            end
            if (axi_b_fire) begin
                if (!(aw_seen_q || axi_aw_fire)) begin
                    $fatal(1,
                        "cpu: B response arrived before AW handshake");
                end
                if (!(w_seen_q || axi_w_fire)) begin
                    $fatal(1,
                        "cpu: B response arrived before W handshake");
                end
                if (axi_bresp !== 2'b00) begin
                    $fatal(1,
                        "cpu: AXI write response=%0b addr=%08x len=%0d size=%0d last_pc=%08x last_inst=%08x",
                        axi_bresp,
                        axi_aw_fire ? axi_awaddr : write_addr_q,
                        axi_aw_fire ? axi_awlen  : write_len_q,
                        axi_aw_fire ? axi_awsize : write_size_q,
                        last_pc_q,
                        last_inst_q);
                end
                aw_seen_q <= 1'b0;
                w_seen_q  <= 1'b0;
            end
        end
    end

`ifndef __ICARUS__
    import "DPI-C" function void cpu_commit(
        input int unsigned commit_pc,
        input int unsigned commit_inst,
        input int unsigned pc,
        input int unsigned mstatus,
        input int unsigned mtvec,
        input int unsigned mepc,
        input int unsigned mcause,
        input int unsigned gpr[32]
    );

    import "DPI-C" function void trace_bus(
        input int is_write,
        input int addr,
        input int data,
        input int len
    );
    // AR trace
    reg [31:0] bus_raddr_q;
    reg [ 2:0] bus_rsize_q;
    // AW trace
    reg [31:0] bus_waddr_q;
    reg [ 2:0] bus_wsize_q;
    // W trace
    reg [31:0] bus_wdata_q;

    reg        commit_valid_q;
    reg [31:0] commit_pc_q;
    reg [31:0] commit_inst_q;
    reg [31:0] commit_dnpc_q;
    int unsigned commit_gpr[32];
    integer index;

    always @(posedge clock) begin
        if (reset) begin
            bus_raddr_q   <= 32'b0;
            bus_rsize_q   <= 3'b0;
            bus_waddr_q   <= 32'b0;
            bus_wsize_q   <= 3'b0;
            bus_wdata_q   <= 32'b0;
            commit_valid_q <= 1'b0;
        end else begin
            if (trace_ar_fire) begin
                bus_raddr_q <= trace_araddr;
                bus_rsize_q <= trace_arsize;
            end
            if (trace_aw_fire) begin
                bus_waddr_q <= trace_awaddr;
                bus_wsize_q <= trace_awsize;
            end
            if (trace_w_fire) begin
                bus_wdata_q <= trace_store_data;
            end

            if (trace_r_fire) begin
                trace_bus(0, bus_raddr_q, trace_rdata, 1 << bus_rsize_q);
            end
            if (trace_b_fire) begin
                trace_bus(1, bus_waddr_q, bus_wdata_q, 1 << bus_wsize_q);
            end

            if (commit_valid_q) begin
                for (index = 0; index < 32; index = index + 1) begin
                    commit_gpr[index] = gpr_snapshot[index * 32 +: 32];
                end
                cpu_commit(
                    commit_pc_q,
                    commit_inst_q,
                    commit_dnpc_q,
                    csr_mstatus,
                    csr_mtvec,
                    csr_mepc,
                    csr_mcause,
                    commit_gpr
                );
            end

            commit_valid_q <= retire_valid;
            if (retire_valid) begin
                commit_pc_q   <= retire_pc;
                commit_inst_q <= retire_inst;
                commit_dnpc_q <= retire_next_pc;
            end
        end
    end
`endif
`endif
`endif

    wire _unused_ok = &{1'b0, gpr_snapshot, csr_mstatus, csr_mtvec,
        csr_mepc, csr_mcause, trace_araddr, trace_arsize, trace_rdata,
        trace_awaddr, trace_awsize, trace_store_data, axi_araddr, axi_arlen,
        axi_arsize, axi_rlast, axi_awaddr, axi_awlen, axi_awsize};

endmodule
