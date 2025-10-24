`timescale 1ns/1ns
`include "/home/furina/ysyx-workbench/npc/pipeline-vsrc/defines/defines.v"

module rv32e (
    input clk,
    input reset
);
    import "DPI-C" function void ebreak(input int station, input int inst);

    // 顶层信号声明
    wire [31:0] IF_ID_pc;         // IF 到 ID：程序计数器
    wire [31:0] IF_ID_inst;       // IF 到 ID：指令
    wire        IF_valid;         // IF 到 ID：有效信号
    wire        id_ready;         // ID 到 IF：就绪信号
    wire [31:0] IF_ID_pc2;        // IF 到 ID：用于分支预测的 PC

    wire [31:0] id_ex_pc;         // ID 到 EX：程序计数器
    wire [31:0] id_ex_pc2;      // ID 到 EX：用于分支预测的 PC
    wire [31:0] id_ex_inst;       // ID 到 EX：指令
    wire        id_valid;         // ID 到 EX：有效信号
    wire        ex_ready;         // EX 到 ID：就绪信号
    wire        id_ex_RegWrite;   // ID 到 EX：寄存器写使能
    wire [4:0]  id_ex_rd;         // ID 到 EX：目标寄存器
    wire [4:0]  id_wb_rs1;        // ID 到 WB：源寄存器 1
    wire [4:0]  id_wb_rs2;        // ID 到 WB：源寄存器 2
    wire [4:0]  id_ex_zimm;       // ID 到 EX：CSR 立即数
    wire [31:0] id_ex_imm;        // ID 到 EX：立即数
    wire [5:0]  id_ex_shamt;      // ID 到 EX：移位量
    wire [3:0]  id_ex_alu_op;     // ID 到 EX：ALU 操作
    wire [2:0]  id_ex_MemLen;     // ID 到 EX：内存访问长度
    wire        id_ex_MemWrite;   // ID 到 EX：内存写使能
    wire        id_ex_MemRead;    // ID 到 EX：内存读使能
    wire [6:0]  id_ex_opcode;     // ID 到 EX：操作码
    wire [2:0]  id_ex_func3;      // ID 到 EX：功能码 3
    wire        id_ex_jal;        // ID 到 EX：JAL 信号
    wire        id_ex_jalr;       // ID 到 EX：JALR 信号
    wire        id_ex_csr;        // ID 到 EX：CSR 指令信号
    wire        id_ex_csr_wen1;   // ID 到 EX：CSR 写使能 1
    wire        id_ex_csr_wen2;   // ID 到 EX：CSR 写使能 2
    wire        id_ex_csr_ecall;  // ID 到 EX：ECALL 信号
    wire        id_ex_csr_mret;   // ID 到 EX：MRET 信号
    wire [1:0]  id_ex_csr_op;
    wire [11:0] id_ex_csr_wr_addr1; // ID 到 EX：CSR 写地址 1
    wire [11:0] id_ex_csr_wr_addr2; // ID 到 EX：CSR 写地址 2
    wire [11:0] id_wb_csr_addr1;  // ID 到 WB：CSR 读地址 1
    wire [11:0] id_wb_csr_addr2;  // ID 到 WB：CSR 读地址 2

    wire [31:0] ex_lsu_pc;        // EX 到 MEM：程序计数器
    wire [31:0] ex_lsu_inst;      // EX 到 MEM：指令
    wire        ex_lsu_valid;     // EX 到 MEM：有效信号
    wire        lsu_ex_ready;     // MEM 到 EX：就绪信号
    wire [31:0] ex_lsu_src2;      // EX 到 MEM：源操作数 2
    wire        ex_lsu_RegWrite;  // EX 到 MEM：寄存器写使能
    wire [4:0]  ex_lsu_rd;        // EX 到 MEM：目标寄存器
    wire        ex_lsu_MemRead;   // EX 到 MEM：内存读使能
    wire        ex_lsu_MemWrite;  // EX 到 MEM：内存写使能
    wire [2:0]  ex_lsu_MemLen;    // EX 到 MEM：内存访问长度
    wire [31:0] ex_lsu_process_result; // EX 到 MEM：ALU/内存地址结果
    wire        ex_flush;         // EX 到 IF：冲刷信号
    wire [31:0] ex_flush_pc;      // EX 到 IF：冲刷目标 PC
    wire        ex_lsu_csr;       // EX 到 MEM：CSR 指令信号
    wire        ex_lsu_csr_wen1;  // EX 到 MEM：CSR 写使能 1
    wire        ex_lsu_csr_wen2;  // EX 到 MEM：CSR 写使能 2
    wire [11:0] ex_lsu_csr_wr_addr1; // EX 到 MEM：CSR 写地址 1
    wire [11:0] ex_lsu_csr_wr_addr2; // EX 到 MEM：CSR 写地址 2
    wire [31:0] ex_lsu_csr_wr_data1; // EX 到 MEM：CSR 写数据 1
    wire [31:0] ex_lsu_csr_wr_data2; // EX 到 MEM：CSR 写数据 2
    wire [31:0] ex_lsu_csr_rdata; // EX 到 MEM：CSR 读数据
    wire        ex_lsu_csr_ecall; // EX 到 MEM：ECALL 信号
    wire        ex_lsu_csr_mret;  // EX 到 MEM：MRET 信号
    wire [31:0] ex_lsu_imm;     // EX 到 MEM：立即数
    wire [6:0]  ex_lsu_opcode; // EX 到 MEM：操作码

    wire [31:0] lsu_wb_pc;        // MEM 到 WB：程序计数器
    wire [31:0] lsu_wb_inst;      // MEM 到 WB：指令
    wire        lsu_wb_valid;     // MEM 到 WB：有效信号
    wire        wb_lsu_ready;     // WB 到 MEM：就绪信号
    wire        lsu_wb_RegWrite;  // MEM 到 WB：寄存器写使能
    wire [4:0]  lsu_wb_rd;        // MEM 到 WB：目标寄存器
    wire [31:0] lsu_wb_write_rd_data; // MEM 到 WB：写回数据
    wire [31:0] lsu_wb_csr_wr_data1;  // MEM 到 WB：CSR 写数据 1
    wire [31:0] lsu_wb_csr_wr_data2;  // MEM 到 WB：CSR 写数据 2
    wire [11:0] lsu_wb_csr_wr_addr1;  // MEM 到 WB：CSR 写地址 1
    wire [11:0] lsu_wb_csr_wr_addr2;  // MEM 到 WB：CSR 写地址 2
    wire        lsu_wb_csr_wen1;      // MEM 到 WB：CSR 写使能 1
    wire        lsu_wb_csr_wen2;      // MEM 到 WB：CSR 写使能 2
    wire        lsu_wb_flush;
    wire        wb_valid;         

    wire [31:0] wb_ex_src1;       // WB 到 EX：源操作数 1（前递）
    wire [31:0] wb_ex_src2;       // WB 到 EX：源操作数 2（前递）
    wire [31:0] wb_ex_csr_num1;   // WB 到 EX：CSR 读数据 1
    wire [31:0] wb_ex_csr_num2;   // WB 到 EX：CSR 读数据 2

    // 前递信号
    wire [4:0]  lsu_ex_forward_rd;        // MEM 到 EX：前递的目标寄存器
    wire        lsu_ex_forward_RegWrite;  // MEM 到 EX：前递写使能
    wire        lsu_ex_forward_MemRead;   // MEM 到 EX：前递读使能
    wire        ex_lsu_forward_las;       // EX 到 MEM：加载后存储前递标志

    // 内存访问信号（暴露在顶层，需外部连接）
    wire [31:0] addr;             // 内存地址
    wire [31:0] wdata;            // 内存写数据
    wire        wen;              // 内存写使能
    wire [1:0]  mask;             // 内存写掩码

    // BPU（分支预测单元）信号
    wire        predict_taken;     // 分支预测是否跳转
    wire [31:0] predict_target;    // 分支预测目标地址
    wire        ex_bpu_update;    // EX 阶段更新信号
    wire [31:0] ex_bpu_pc;         // EX 阶段分
    wire        ex_bpu_taken;      // EX 阶段实际跳转结果
    wire [31:0] ex_bpu_target;     // EX 阶段实际目标地址
    wire        ex_bpu_correct;    // EX 阶段预测是否正确
    wire [31:0] correct_predictions; // 正确预测计数
    wire [31:0] total_predictions;   // 总预测计数
    wire        id_ex_predict_taken; // ID 到 EX：预测是否跳转
    wire [31:0] id_ex_predict_target; // ID 到 EX：预测实际目标地址

    // IF（指令获取）模块
    IF ifu (
        .clk(clk),
        .reset(reset),
        .EX_flush(ex_flush),
        .EX_flush_pc(ex_flush_pc),
        .ID_ready(id_ready),
        .IF_valid(IF_valid),
        .IF_ID_pc(IF_ID_pc),
        .IF_ID_pc2(IF_ID_pc2), // 用于分支预测
        .IF_ID_inst(IF_ID_inst),
        .predict_taken(predict_taken), // 分支预测输入
        .predict_target(predict_target) // 预测目标地址 
    );

    // ID（指令解码）模块
    ID idu (
        .clk(clk),
        .reset(reset),
        .if_id_pc(IF_ID_pc),
        .if_id_pc2(IF_ID_pc2), // 用于分支预测
        .if_id_inst(IF_ID_inst),
        .ex_flush(ex_flush),
        .if_valid(IF_valid),
        .id_ready(id_ready),
        .ex_ready(ex_ready),
        .id_valid(id_valid),
        .id_ex_pc(id_ex_pc),
        .id_ex_pc2(id_ex_pc2), // 用于分支预测
        .id_ex_inst(id_ex_inst),
        .id_ex_RegWrite(id_ex_RegWrite),
        .id_ex_rd(id_ex_rd),
        .id_wb_rs1(id_wb_rs1),
        .id_wb_rs2(id_wb_rs2),
        .id_ex_zimm(id_ex_zimm),
        .id_ex_imm(id_ex_imm),
        .id_ex_shamt(id_ex_shamt),
        .id_ex_alu_op(id_ex_alu_op),
        .id_ex_MemLen(id_ex_MemLen),
        .id_ex_MemWrite(id_ex_MemWrite),
        .id_ex_MemRead(id_ex_MemRead),
        .id_ex_opcode(id_ex_opcode),
        .id_ex_func3(id_ex_func3),
        .id_ex_jal(id_ex_jal),
        .id_ex_jalr(id_ex_jalr),
        .id_ex_csr(id_ex_csr),
        .id_ex_csr_wen1(id_ex_csr_wen1),
        .id_ex_csr_wen2(id_ex_csr_wen2),
        .id_ex_csr_ecall(id_ex_csr_ecall),
        .id_ex_csr_mret(id_ex_csr_mret),
        .id_ex_csr_op(id_ex_csr_op),
        .id_ex_csr_wr_addr1(id_ex_csr_wr_addr1),
        .id_ex_csr_wr_addr2(id_ex_csr_wr_addr2),
        .id_wb_csr_addr1(id_wb_csr_addr1),
        .id_wb_csr_addr2(id_wb_csr_addr2),
        .predict_taken(predict_taken), // 分支预测输入
        .predict_target(predict_target), // 预测目标地址
        .id_ex_predict_target(id_ex_predict_target), // ID 到 EX：预测实际目标地址
        .id_ex_predict_taken(id_ex_predict_taken) // ID 到 EX：预测是否跳转
    );

    // EX（执行）模块
    EX exu (
        .clk(clk),
        .reset(reset),
        .id_ready(id_ready),
        .id_valid(id_valid),
        .ex_ready(ex_ready),
        .lsu_ready(lsu_ex_ready),
        .ex_lsu_valid(ex_lsu_valid),
        .id_wb_rs1(id_wb_rs1),
        .id_wb_rs2(id_wb_rs2),
        .lsu_ex_forward_rd(lsu_ex_forward_rd),
        .lsu_ex_forward_RegWrite(lsu_ex_forward_RegWrite),
        .lsu_ex_forward_MemRead(lsu_ex_forward_MemRead),
        .lsu_wb_wdata(lsu_wb_write_rd_data),
        .lsu_wb_rd(lsu_wb_rd),
        .lsu_wb_RegWrite(lsu_wb_RegWrite),
        .lsu_wb_valid(lsu_wb_valid),
        .ex_lsu_forward_las(ex_lsu_forward_las),
        .id_ex_inst(id_ex_inst),
        .id_ex_pc(id_ex_pc),
        .id_ex_pc2(id_ex_pc2), // 用于分支预测
        .id_ex_imm(id_ex_imm),
        .id_ex_zimm(id_ex_zimm),
        .id_ex_shamt(id_ex_shamt),
        .wb_ex_src1(wb_ex_src1),
        .wb_ex_src2(wb_ex_src2),
        .id_ex_RegWrite(id_ex_RegWrite),
        .id_ex_rd(id_ex_rd),
        .id_ex_opcode(id_ex_opcode),
        .id_ex_func3(id_ex_func3),
        .id_ex_alu_op(id_ex_alu_op),
        .id_ex_jal(id_ex_jal),
        .id_ex_jalr(id_ex_jalr),
        .id_ex_MemRead(id_ex_MemRead),
        .id_ex_MemWrite(id_ex_MemWrite),
        .id_ex_MemLen(id_ex_MemLen),
        .wb_ex_csr_num1(wb_ex_csr_num1),
        .wb_ex_csr_num2(wb_ex_csr_num2),
        .id_ex_csr(id_ex_csr),
        .id_ex_csr_wen1(id_ex_csr_wen1),
        .id_ex_csr_wen2(id_ex_csr_wen2),
        .id_ex_csr_wr_addr1(id_ex_csr_wr_addr1),
        .id_ex_csr_wr_addr2(id_ex_csr_wr_addr2),
        .id_ex_csr_ecall(id_ex_csr_ecall),
        .id_ex_csr_mret(id_ex_csr_mret),
        .id_ex_csr_op(id_ex_csr_op),
        .ex_flush(ex_flush),
        .ex_flush_pc(ex_flush_pc),
        .ex_lsu_inst(ex_lsu_inst),
        .ex_lsu_pc(ex_lsu_pc),
        .ex_lsu_src2(ex_lsu_src2),
        .ex_lsu_RegWrite(ex_lsu_RegWrite),
        .ex_lsu_rd(ex_lsu_rd),
        .ex_lsu_MemRead(ex_lsu_MemRead),
        .ex_lsu_MemWrite(ex_lsu_MemWrite),
        .ex_lsu_MemLen(ex_lsu_MemLen),
        .ex_lsu_opcode(ex_lsu_opcode),
        .ex_lsu_csr(ex_lsu_csr),
        .ex_lsu_csr_wen1(ex_lsu_csr_wen1),
        .ex_lsu_csr_wen2(ex_lsu_csr_wen2),
        .ex_lsu_csr_wr_addr1(ex_lsu_csr_wr_addr1),
        .ex_lsu_csr_wr_addr2(ex_lsu_csr_wr_addr2),
        .ex_lsu_csr_wr_data1(ex_lsu_csr_wr_data1),
        .ex_lsu_csr_wr_data2(ex_lsu_csr_wr_data2),
        .ex_lsu_csr_rdata(ex_lsu_csr_rdata),
        .ex_lsu_csr_ecall(ex_lsu_csr_ecall),
        .ex_lsu_csr_mret(ex_lsu_csr_mret),
        .ex_lsu_imm(ex_lsu_imm),
        .ex_lsu_process_result(ex_lsu_process_result),
        .id_ex_predict_taken(id_ex_predict_taken), // ID 到 EX：预测是否跳转
        .id_ex_predict_target(id_ex_predict_target), // ID 到 EX：预测实际目标地址
        .ex_bpu_update(ex_bpu_update), // EX 阶段更新信号
        .ex_bpu_pc(ex_bpu_pc),         // EX 阶段分支
        .ex_bpu_taken(ex_bpu_taken),   // EX 阶段实际跳转结果
        .ex_bpu_target(ex_bpu_target), // EX 阶段实际目标地址
        .ex_bpu_correct(ex_bpu_correct) // EX 阶段预测是否正确
    );

    // wire        MEM_LSU_write_ready;
    // wire        MEM_LSU_read_ready;
    // MEM（内存访问）模块
    LSU lsu (
        .clk(clk),
        .rst(reset),
        .ex_lsu_imm(ex_lsu_imm),
        // .MEM_LSU_write_ready(MEM_LSU_write_ready),
        // .MEM_LSU_read_ready(MEM_LSU_read_ready),
        .ex_lsu_valid(ex_lsu_valid),
        .lsu_ex_ready(lsu_ex_ready),
        .wb_lsu_ready(wb_lsu_ready),
        .lsu_wb_valid(lsu_wb_valid),
        .ex_lsu_forward_las(ex_lsu_forward_las),
        .ex_lsu_RegWrite(ex_lsu_RegWrite),
        .ex_lsu_rd(ex_lsu_rd),
        .ex_lsu_MemRead(ex_lsu_MemRead),
        .ex_lsu_MemWrite(ex_lsu_MemWrite),
        .ex_lsu_MemLen(ex_lsu_MemLen),
        .ex_lsu_inst(ex_lsu_inst),
        .ex_lsu_pc(ex_lsu_pc),
        .addr(ex_lsu_process_result), // 从 EX 传入的内存地址
        .data_in(ex_lsu_src2),        // 从 EX 传入的写数据
        .ex_lsu_opcode(ex_lsu_opcode),
        .lsu_ex_forward_rd(lsu_ex_forward_rd),
        .lsu_ex_forward_RegWrite(lsu_ex_forward_RegWrite),
        .lsu_ex_forward_MemRead(lsu_ex_forward_MemRead),
        .ex_lsu_csr(ex_lsu_csr),
        .ex_lsu_csr_wen1(ex_lsu_csr_wen1),
        .ex_lsu_csr_wen2(ex_lsu_csr_wen2),
        .ex_lsu_csr_wr_data1(ex_lsu_csr_wr_data1),
        .ex_lsu_csr_wr_data2(ex_lsu_csr_wr_data2),
        .ex_lsu_csr_wr_addr1(ex_lsu_csr_wr_addr1),
        .ex_lsu_csr_wr_addr2(ex_lsu_csr_wr_addr2),
        .ex_lsu_csr_rdata(ex_lsu_csr_rdata),
        .ex_lsu_csr_ecall(ex_lsu_csr_ecall),
        .ex_lsu_csr_mret(ex_lsu_csr_mret),
        .ex_lsu_process_result(ex_lsu_process_result),
        .lsu_wb_inst(lsu_wb_inst),
        .lsu_wb_pc(lsu_wb_pc),
        .lsu_wb_csr_wr_data1(lsu_wb_csr_wr_data1),
        .lsu_wb_csr_wr_data2(lsu_wb_csr_wr_data2),
        .lsu_wb_csr_wr_addr1(lsu_wb_csr_wr_addr1),
        .lsu_wb_csr_wr_addr2(lsu_wb_csr_wr_addr2),
        .lsu_wb_csr_wen1(lsu_wb_csr_wen1),
        .lsu_wb_csr_wen2(lsu_wb_csr_wen2),
        .lsu_wb_RegWrite(lsu_wb_RegWrite),
        .lsu_wb_rd(lsu_wb_rd),
        .lsu_wb_write_rd_data(lsu_wb_write_rd_data)
    );

    // WBU（写回）模块
    WBU wbu (
        .clk(clk),
        .rst(reset),
        .wen(lsu_wb_RegWrite),
        .lsu_wb_valid(lsu_wb_valid),
        .wb_lsu_ready(wb_lsu_ready),
        .wdata(lsu_wb_write_rd_data),
        .waddr(lsu_wb_rd),
        .rs1(id_wb_rs1),
        .rs2(id_wb_rs2),
        .src1(wb_ex_src1),
        .src2(wb_ex_src2),
        .wb_valid(wb_valid),
        .raddr_csr1(id_wb_csr_addr1),
        .raddr_csr2(id_wb_csr_addr2),
        .wen_csr1(lsu_wb_csr_wen1),
        .wen_csr2(lsu_wb_csr_wen2),
        .wdata_csr1(lsu_wb_csr_wr_data1),
        .wdata_csr2(lsu_wb_csr_wr_data2),
        .waddr_csr1(lsu_wb_csr_wr_addr1),
        .waddr_csr2(lsu_wb_csr_wr_addr2),
        .rdata_csr1(wb_ex_csr_num1),
        .rdata_csr2(wb_ex_csr_num2)
    );
    
    Link_BPU lbpu (
        .clk(clk),
        .reset(reset),
        .if_pc(IF_ID_pc),              // 当前取指PC
        .predict_taken(predict_taken), // 预测是否跳转
        .predict_target(predict_target), // 预测目标地址
        .ex_bpu_update(ex_bpu_update), // EX 阶段更新信号
        .ex_bpu_pc(ex_bpu_pc),         // EX 阶段分支指令的PC
        .ex_bpu_taken(ex_bpu_taken),   // EX 阶段实际跳转结果
        .ex_bpu_target(ex_bpu_target), // EX 阶段实际目标地址
        .ex_bpu_correct(ex_bpu_correct), // EX 阶段预测是否正确
        .correct_predictions(correct_predictions), // 正确预测计数
        .total_predictions(total_predictions) // 总预测计数
    );
    // 内存接口赋值
    assign addr = ex_lsu_process_result; // 从 EX 传入的内存地址
    assign wdata = ex_lsu_src2;          // 从 EX 传入的内存写数据
    assign wen = ex_lsu_MemWrite;        // 从 EX 传入的内存写使能
    assign mask = (ex_lsu_MemLen == 3'b001) ? 2'b00 : // 字节
                  (ex_lsu_MemLen == 3'b010) ? 2'b01 : // 半字
                  (ex_lsu_MemLen == 3'b100) ? 2'b11 : // 字
                  2'b00;                      // 默认

    // reg [31:0] inst_cnt;
    // reg [31:0] cycle_cnt;
    // always @(posedge clk) begin
    //     if(reset) begin
    //         inst_cnt <= 0;
    //         cycle_cnt <= 0;
    //     end
    //     else begin
    //         cycle_cnt <= cycle_cnt + 1;
    //         if(wb_valid) begin
    //             inst_cnt <= inst_cnt + 1;
    //         end
    //     end
    // end

    // EBREAK 处理
    always @(posedge clk) begin
        if (IF_ID_inst == 32'h00100073) begin
            // real IPC = (cycle_cnt == 0) ? 0.0 : real'(inst_cnt) / real'(cycle_cnt);
            // $display("\033[33mIPC = %f\033[0m", IPC);
            $display("+-------------------+---------------------+---------------------+");
            $display("| Total predictions | Correct predictions | Prediction accuracy |");
            $display("| %10d        | %10d          | %10.2f%%         |", 
                    total_predictions, correct_predictions, 
                    (total_predictions == 0) ? 0.0 : (real'(correct_predictions) / real'(total_predictions) * 100.0));
            $display("+-------------------+---------------------+---------------------+");
            ebreak(`HIT_TRAP, ex_lsu_inst);
        end
        // if(ex_flush) begin
        //     $display("       [EX] flush pc = %h", ex_flush_pc);
        // end

        // $display("[IF] pc = %h, inst = %h", IF_ID_pc, IF_ID_inst);
    end

endmodule