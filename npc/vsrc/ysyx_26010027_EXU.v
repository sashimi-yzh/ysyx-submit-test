module ysyx_26010027_EXU (
    input               clock,
    input               reset,

    // IDU - EXU
    input             idu_exu_valid,
    output            exu_idu_ready,
    input      [31:0] idu_exu_pc,
    input      [31:0] idu_exu_inst,

    input      [31:0] idu_exu_target,
    input      [31:0] idu_exu_imm,
    input      [ 3:0] idu_exu_alu_op,
    input      [ 1:0] idu_exu_mem_w,
    input      [ 2:0] idu_exu_mem_r,
    input             idu_exu_alu_arc1, idu_exu_alu_arc2, // 操作数选择
    input             idu_exu_reg_w,
    input      [ 1:0] idu_exu_rf_res, // reg 的 wdata 选择
    input      [ 3:0] idu_exu_waddr,

    input      [ 1:0] idu_exu_jump,
    input      [ 2:0] idu_exu_branch,
    input             idu_exu_fencei,

    input      [11:0] idu_exu_csr_addr,
    input             idu_exu_csr_we,
    input             idu_exu_csr_ecall,
    input             idu_exu_csr_mret,

    // EXU - LSU
    input             lsu_exu_ready,
    output reg        exu_lsu_valid,
    output reg [31:0] exu_lsu_pc,
    output reg [31:0] exu_lsu_snpc,
    output reg [31:0] exu_lsu_inst,

    output reg [ 1:0] exu_lsu_mem_w, 
    output reg [ 2:0] exu_lsu_mem_r,
    output reg [31:0] exu_lsu_mem_addr,
    output reg [31:0] exu_lsu_wdata,
    output reg        exu_lsu_reg_w,
    output reg [ 1:0] exu_lsu_rf_res,
    output reg [ 3:0] exu_lsu_waddr,
    output reg [31:0] exu_lsu_alu_result,

    output reg [11:0] exu_lsu_csr_waddr,
    output reg        exu_lsu_csr_we,
    output reg        exu_lsu_csr_ecall,
    output reg        exu_lsu_csr_mret,
    output reg [31:0] exu_lsu_csr_wdata,

    // flush
    output reg        exu_flush,
    output reg [31:0] exu_flush_pc,

`ifdef NPC_SIM
    output reg [31:0] exu_lsu_dnpc,
`endif

    // data forwarding 旁路转发
    input             lsu_wbu_valid,
    input             lsu_exu_inflight,
    input             lsu_wbu_reg_w,
    input      [ 1:0] lsu_wbu_rf_res,
    input      [ 3:0] idu_exu_raddr1, idu_exu_raddr2,
    input      [ 3:0] lsu_wbu_waddr,
    input      [31:0] lsu_wbu_alu_result, // RAW 前递
    input      [31:0] lsu_wbu_mem_result, // Load-Use 前递
    input      [31:0] lsu_wbu_snpc, // SNPC 跳转前递
    input      [31:0] wbu_exu_rdata1, wbu_exu_rdata2, wbu_exu_csr_rdata,// Normal
    input      [31:0] exu_mtvec, exu_mepc // ecall/mret

);

    wire [31:0] rdata1, rdata2;
    wire [31:0] csr_rdata;
    reg  [31:0] src1, src2;
    reg  [31:0] alu_result;
    wire [31:0] snpc = idu_exu_pc + 4;

    // ----- data forwarding -----
    wire [2:0] fwd_1; // 1拍与2拍 RAW 和 1拍load-use
    wire [2:0] fwd_2;
    wire load_use_stall;

    // raw 前递
    wire lsu_fwd_raw = exu_lsu_valid && exu_lsu_reg_w && (exu_lsu_rf_res != 2'b01); // rf_res选ALU/SNPC-00/11
    wire wbu_fwd_raw = lsu_wbu_valid && lsu_wbu_reg_w && (lsu_wbu_rf_res != 2'b01);
    assign fwd_1[0] = (|idu_exu_raddr1 && idu_exu_raddr1 == exu_lsu_waddr && lsu_fwd_raw);
    assign fwd_2[0] = (|idu_exu_raddr2 && idu_exu_raddr2 == exu_lsu_waddr && lsu_fwd_raw);
    assign fwd_1[1] = (|idu_exu_raddr1 && idu_exu_raddr1 == lsu_wbu_waddr && wbu_fwd_raw);
    assign fwd_2[1] = (|idu_exu_raddr2 && idu_exu_raddr2 == lsu_wbu_waddr && wbu_fwd_raw);

    // load-use 前递
    wire lsu_fwd_mem = exu_lsu_valid && exu_lsu_reg_w && (exu_lsu_rf_res == 2'b01); // rf_res选MEM-01
    wire wbu_fwd_mem = lsu_wbu_valid && lsu_wbu_reg_w && (lsu_wbu_rf_res == 2'b01);
    assign fwd_1[2] = (|idu_exu_raddr1 && idu_exu_raddr1 == lsu_wbu_waddr && wbu_fwd_mem);
    assign fwd_2[2] = (|idu_exu_raddr2 && idu_exu_raddr2 == lsu_wbu_waddr && wbu_fwd_mem);

    assign load_use_stall = (|idu_exu_raddr1 && idu_exu_raddr1 == exu_lsu_waddr && lsu_fwd_mem)
                         || (|idu_exu_raddr2 && idu_exu_raddr2 == exu_lsu_waddr && lsu_fwd_mem);
    // ----------------------------

    // 前递值
    wire [31:0] lsu_fwd_data = (exu_lsu_rf_res == 2'b11) ? exu_lsu_snpc : exu_lsu_alu_result; // 一拍：SNPC 写 snpc，其余写 alu_result
    wire [31:0] wbu_fwd_data = (lsu_wbu_rf_res == 2'b11) ? lsu_wbu_snpc : lsu_wbu_alu_result; // 两拍：同上

    assign rdata1 = fwd_1[0] ? lsu_fwd_data : 
                    fwd_1[1] ? wbu_fwd_data : 
                    fwd_1[2] ? lsu_wbu_mem_result : wbu_exu_rdata1;
    assign rdata2 = fwd_2[0] ? lsu_fwd_data :
                    fwd_2[1] ? wbu_fwd_data : 
                    fwd_2[2] ? lsu_wbu_mem_result : wbu_exu_rdata2;
    assign csr_rdata = wbu_exu_csr_rdata;

    // 源操作数选择与处理
    assign src1 = idu_exu_alu_arc1 ? idu_exu_pc  : rdata1;
    assign src2 = idu_exu_alu_arc2 ? idu_exu_imm : rdata2;

    // branch
    wire eq  = (src1 == src2);
    wire lts = ($signed(src1) < $signed(src2));
    wire ltu = (src1 < src2);
    wire taken = (idu_exu_branch == 3'd0) ? !eq  :  // bne
                 (idu_exu_branch == 3'd1) ? eq   :  // beq
                 (idu_exu_branch == 3'd2) ? lts  :  // blt
                 (idu_exu_branch == 3'd3) ? !lts :  // bge
                 (idu_exu_branch == 3'd4) ? ltu  :  // bltu
                 (idu_exu_branch == 3'd5) ? !ltu :  // bgeu
                 1'b0;

    // module ALU
    always @(*) begin
        case (idu_exu_alu_op)
            4'd0:  alu_result = src1 + src2;
            4'd1:  alu_result = src1 - src2; // sub
            4'd2:  alu_result = idu_exu_imm; // lui
            4'd3:  alu_result = src1 << src2[4:0]; // sll/slli
            4'd4:  alu_result = src1 >> src2[4:0]; // srl/srli
            4'd5:  alu_result = $signed(src1) >>> src2[4:0]; // sra/srai
            4'd6:  alu_result = {31'b0, (lts)}; // slt/slti
            4'd7:  alu_result = {31'b0, (ltu)}; // sltiu/sltu
            4'd8:  alu_result = src1 ^ src2; // xor/xori
            4'd9:  alu_result = src1 & src2; // and/andi
            4'd10: alu_result = src1 | src2; // or/ori
            4'd11: alu_result = taken ? idu_exu_target : snpc; // branch
            4'd12: alu_result = src1; // csrrw
            4'd13: alu_result = src1 | csr_rdata; // csrrs
            default: alu_result = 0;
        endcase
    end

    // flush handle
    wire [31:0] trap_pc = idu_exu_csr_ecall ? exu_mtvec : exu_mepc;
    always @(*) begin
        if (reset) begin
            exu_flush    = 1'b0;
            exu_flush_pc = 32'b0;
        end 
        else if (idu_exu_valid && exu_idu_ready) begin
            // 正常跳转
            if (idu_exu_branch != 3'd6) begin // branch
                exu_flush    = !taken; // no_taken 不中就 flush
                exu_flush_pc = snpc; // 正常pc+4
            end
            else if (idu_exu_jump == 2'b01) begin // jalr
                exu_flush    = 1'b1; // 包冲刷
                exu_flush_pc = alu_result;
            end
            // 异常跳转
            else if ((idu_exu_csr_ecall || idu_exu_csr_mret)) begin
                exu_flush    = 1'b1;
                exu_flush_pc = trap_pc;
            end
            // fence.i 冲刷
            else if (idu_exu_fencei) begin
                exu_flush    = 1'b1;
                exu_flush_pc = snpc;
            end
            else begin
                exu_flush    = 1'b0;
                exu_flush_pc = 32'b0;
            end
        end
        else begin
            exu_flush    = 1'b0;
            exu_flush_pc = 32'b0;
        end
    end

    // handshake
    assign exu_idu_ready = (lsu_exu_ready | !exu_lsu_valid) && !(load_use_stall | lsu_exu_inflight); // stall 反压
    always @(posedge clock, posedge reset) begin
        if (reset) begin
            exu_lsu_valid <= 1'b0;
        end
        else if (idu_exu_valid && exu_idu_ready) begin
            exu_lsu_valid <= 1'b1;
        end
        else if (lsu_exu_ready) begin
            exu_lsu_valid <= 1'b0;
        end
    end

    always @(posedge clock) begin
        if (idu_exu_valid && exu_idu_ready) begin
            exu_lsu_pc       <= idu_exu_pc;
            exu_lsu_snpc     <= snpc;
            exu_lsu_inst     <= idu_exu_inst;
            exu_lsu_mem_w    <= idu_exu_mem_w;
            exu_lsu_mem_r    <= idu_exu_mem_r;
            exu_lsu_mem_addr <= alu_result; // ALU-访存地址
            exu_lsu_wdata    <= rdata2; // rdata2寄存器

            exu_lsu_reg_w      <= idu_exu_reg_w;
            exu_lsu_rf_res     <= idu_exu_rf_res;
            exu_lsu_waddr      <= idu_exu_waddr; // rf 地址
            exu_lsu_alu_result <= alu_result; // ALU结果

            exu_lsu_csr_waddr  <= idu_exu_csr_addr;
            exu_lsu_csr_we     <= idu_exu_csr_we;
            exu_lsu_csr_ecall  <= idu_exu_csr_ecall;
            exu_lsu_csr_mret   <= idu_exu_csr_mret;
            exu_lsu_csr_wdata  <= alu_result; // ALU-csr写数据
        end

    end


// DIFFTEST
`ifdef NPC_SIM    
    reg  [31:0] dnpc;
    wire [ 6:0] opcode = idu_exu_inst[6:0];
    wire branch = (opcode == 7'b1100011);
    wire jump   = (opcode == 7'b1101111 | opcode == 7'b1100111);
    assign dnpc = (branch | jump) ? alu_result : 
                  (idu_exu_csr_ecall | idu_exu_csr_mret) ? trap_pc : snpc;
                  
    always @(posedge clock, posedge reset) begin
        if (reset) exu_lsu_dnpc <= 32'b0;
        else if (idu_exu_valid && exu_idu_ready) exu_lsu_dnpc <= dnpc;
    end

`endif

endmodule
