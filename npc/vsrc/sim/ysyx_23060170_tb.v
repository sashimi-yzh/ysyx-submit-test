`define ANSI_FG_BLACK "\33[1;30m"
`define ANSI_FG_RED "\33[1;31m"
`define ANSI_FG_GREEN "\33[1;32m"
`define ANSI_FG_YELLOW "\33[1;33m"
`define ANSI_FG_BLUE "\33[1;34m"
`define ANSI_FG_MAGENTA "\33[1;35m"
`define ANSI_FG_CYAN "\33[1;36m"
`define ANSI_FG_WHITE "\33[1;37m"
`define ANSI_BG_BLACK "\33[1;40m"
`define ANSI_BG_RED "\33[1;41m"
`define ANSI_BG_GREEN "\33[1;42m"
`define ANSI_BG_YELLOW "\33[1;43m"
`define ANSI_BG_BLUE "\33[1;44m"
`define ANSI_BG_MAGENTA "\33[1;35m"
`define ANSI_BG_CYAN "\33[1;46m"
`define ANSI_BG_WHITE "\33[1;47m"
`define ANSI_NONE "\33[0m"

// switch
// `define WAVE
// `define DIFFTEST
// `define INST_TRACE
// `define PRINT_CPU

module ysyx_23060170_tb;

reg         clk;
reg         rst;
reg  [63:0] inst_cnt;
reg  [63:0] stall_cnt;
reg  [63:0] cycle_cnt;

wire [31:0] rf_a0;
wire        lsu_ebreak;  
wire        lsu_valid;
wire [31:0] lsu_pc;

//-----------------------------------------------------------------
// Drive && DUT
//-----------------------------------------------------------------
initial begin
    clk = 0;
    forever #5 clk = ~clk;  // 每 5ns 翻转一次，周期 10ns
end

initial begin
    rst = 1;        // 初始复位
    #100 rst = 0;    // 100ns 后释放复位
end

ysyxSoCFull soc (
    .clock(clk),
    .reset(rst)
);

//-----------------------------------------------------------------
// Config Print
//-----------------------------------------------------------------
initial begin
    `ifdef MEM_FILE
        $display("%sThe image is %s%s", `ANSI_FG_BLUE, `MEM_FILE, `ANSI_NONE);
    `endif
    `ifdef WAVE
        $display("%sWave: %sON%s", `ANSI_FG_BLUE, `ANSI_FG_GREEN, `ANSI_NONE);
    `endif
    `ifdef DIFFTEST
        $display("%sDifftest: %sON%s", `ANSI_FG_BLUE, `ANSI_FG_GREEN, `ANSI_NONE);
    `endif
    `ifdef INST_TRACE
        $display("%sInst Trace: %sON%s", `ANSI_FG_BLUE, `ANSI_FG_GREEN, `ANSI_NONE);
    `endif
    `ifdef PRINT_CPU
        $display("%sPrint CPU: %sON%s", `ANSI_FG_BLUE, `ANSI_FG_GREEN, `ANSI_NONE);
    `endif
end


//-----------------------------------------------------------------
// Dump Wave
//-----------------------------------------------------------------
`ifdef WAVE

initial begin
    $dumpfile("build/test.vcd");
    $dumpvars(0, ysyx_23060170_tb);
end

`endif

//-----------------------------------------------------------------
// Difftest
//-----------------------------------------------------------------
`ifdef DIFFTEST
`ifdef REF_FILE

integer ref_fd;
reg [1023:0] line;
reg [31:0] ref_pc, ref_wdata;
integer n, lineno;

initial begin
    ref_fd = $fopen(`REF_FILE, "r");   // 打开文件读模式
    if (ref_fd == 0) begin
        $display("%sERROR: cannot open ref file %s%s", `ANSI_FG_RED, `REF_FILE, `ANSI_NONE);
        $finish;
    end
    lineno = 0;
end

always @(posedge clk) begin
    if (soc.asic.cpu.cpu.lsu_valid) begin
        if ($feof(ref_fd)) begin $display("EOF"); $finish; end
        void'($fgets(line, ref_fd));
        lineno = lineno + 1;

        n = $sscanf(line, "0x%x: %*s %*s %*s %*s res: %x", ref_pc, ref_wdata);
        if (n < 1) begin
            $display("%sLine %0d: no PC: %s%s", `ANSI_FG_RED, lineno, line, `ANSI_NONE); $finish;
        end

        if (soc.asic.cpu.cpu.lsu_wbu_pc !== ref_pc) begin
            $display("%sPC mismatch at line %0d, ref=0x%08x dut=0x%08x%s", `ANSI_FG_RED, lineno, ref_pc, soc.asic.cpu.cpu.lsu_wbu_pc, `ANSI_NONE); $finish;
        end

        if (soc.asic.cpu.cpu.lsu_gpr_wen && (soc.asic.cpu.cpu.lsu_gpr_waddr != 5'd0)) begin
            if (n < 2) begin
                $display("%sline %0d: writeback expected but no value in ref%s", `ANSI_FG_RED, lineno, `ANSI_NONE); $finish;
            end
            if (soc.asic.cpu.cpu.lsu_out !== ref_wdata) begin
                $display("%sdest mismatch at line %0d rd=%0d ref=0x%08x dut=0x%08x%s",
                        `ANSI_FG_RED, lineno, soc.asic.cpu.cpu.lsu_gpr_waddr, ref_wdata, soc.asic.cpu.cpu.lsu_out, `ANSI_NONE); $finish;
            end
        end
    end
end

`endif
`endif

//-----------------------------------------------------------------
// Inst Trace
//-----------------------------------------------------------------
`ifdef INST_TRACE
`ifdef LOG_FILE

integer fd;

initial begin
    fd = $fopen(`LOG_FILE, "w");   // 打开文件写模式
    if (fd == 0) begin
        $display("%sERROR: cannot open log file %s%s", `ANSI_FG_RED, `LOG_FILE, `ANSI_NONE);
        $finish;
    end
end

always @(posedge clk) begin
    if (soc.asic.cpu.cpu.lsu_valid) begin
        if (soc.asic.cpu.cpu.lsu_gpr_wen) begin
            $fdisplay(fd, "0x%08x, 0x%08x, 0x%08x", soc.asic.cpu.cpu.lsu_wbu_pc, soc.asic.cpu.cpu.lsu_wbu_inst, soc.asic.cpu.cpu.lsu_out);
        end else begin
            $fdisplay(fd, "0x%08x, 0x%08x", soc.asic.cpu.cpu.lsu_wbu_pc, soc.asic.cpu.cpu.lsu_wbu_inst);
        end
    end
end

final begin
    $fclose(fd);   // 仿真结束时关闭文件
end

`endif
`endif

//-----------------------------------------------------------------
// Print CPU Information
//-----------------------------------------------------------------
`ifdef PRINT_CPU

always @(posedge clk) begin
    if (soc.asic.cpu.cpu.lsu_valid && (inst_cnt%100 == 0)) begin
        $display("PC: 0x%08x, inst cnt: %0d", soc.asic.cpu.cpu.lsu_wbu_pc, inst_cnt);
    end
end

`endif

//-----------------------------------------------------------------
// Exit
//-----------------------------------------------------------------
assign lsu_ebreak = soc.asic.cpu.cpu.exu_valid && soc.asic.cpu.cpu.lsu_ready && soc.asic.cpu.cpu.exu_lsu_excp && (soc.asic.cpu.cpu.exu_lsu_excp_code == 4'd3);

always @(posedge clk) begin
    if (rst) begin
        inst_cnt <= 0;
        stall_cnt <= 0;
    end else if (soc.asic.cpu.cpu.exu_valid && soc.asic.cpu.cpu.lsu_ready) begin
        inst_cnt <= inst_cnt + 1;
        stall_cnt <= 'b0;
    end else begin
        stall_cnt <= stall_cnt + 1;
    end
end

always @(posedge clk) begin
    if (rst) begin
        cycle_cnt <= 0;
    end else begin
        cycle_cnt <= cycle_cnt + 1;
    end
end

`ifdef ysyx_23060170_NETLIST
reg [31:0] rf_a0_r;

always @(posedge clk) begin
    if (rst)
        rf_a0_r <= 32'b0;
    else if (soc.asic.cpu.cpu.lsu_gpr_wen && (soc.asic.cpu.cpu.lsu_gpr_waddr == 10))  // x10 is a0
        rf_a0_r <= soc.asic.cpu.cpu.lsu_out;
end

assign rf_a0  = rf_a0_r;
`else
assign rf_a0 = soc.asic.cpu.cpu.gpr.rf[10-1];
`endif

`ifndef ysyx_23060170_SIM_INFO
reg [31:0] lsu_pc_r;

always @(posedge clk) begin
    if (rst)
        lsu_pc_r <= 32'b0;
    else if (soc.asic.cpu.cpu.exu_valid && soc.asic.cpu.cpu.lsu_ready)
        lsu_pc_r <= soc.asic.cpu.cpu.exu_lsu_pc;
end

assign lsu_pc = lsu_pc_r;
`else
assign lsu_pc = soc.asic.cpu.cpu.lsu_wbu_pc;
`endif

always @(posedge clk) begin
    if (lsu_ebreak) exit(rf_a0, 0);
    if (stall_cnt == 1000) exit(0, 1);
end

function void exit;
    input exit_code;
    input time_out;
    $display("%sTotal instructions = %0d%s", `ANSI_FG_BLUE, inst_cnt, `ANSI_NONE);
    $display("%sCPU IPC = %0f%s", `ANSI_FG_BLUE, $itor(inst_cnt) / $itor(cycle_cnt), `ANSI_NONE);
    if (time_out) begin
        $display("%sTime out!!!%s, at pc = 0x%08x", `ANSI_FG_RED, `ANSI_NONE, lsu_pc);
        $fatal(1);
    end else if (exit_code == 0) begin
        $display("%sHIT GOOD TRAP%s, halt_ret = %0d, at pc = 0x%08x", `ANSI_FG_GREEN, `ANSI_NONE, exit_code, lsu_pc);
        $finish;
    end else begin
        $display("%sHIT BAD TRAP%s, halt_ret = %0d, at pc = 0x%08x", `ANSI_FG_RED, `ANSI_NONE, exit_code, lsu_pc);
        $fatal(1);
    end
endfunction

endmodule
