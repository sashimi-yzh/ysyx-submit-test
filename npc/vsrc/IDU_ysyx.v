`include "npc_config.vh"

module ysyx_25040102_IDU_ysyx(
    input           clk,
    input           reset,

    input  [31:0]   pc,
    input  [31:0]   snpc,
    output [31:0]   pc_out,
    output [31:0]   snpc_out,

    input           inst_valid,
    output          inst_ready,

    input           pc_valid,

    input           decode_ready,
    output          decode_valid, // to EXU

    // input           Reg_wr_exu,
    input  [3:0]    Rw_exu,
    input  [1:0]    load_exu,
    // input           Reg_wr_lsu,
    input  [3:0]    Rw_lsu,
    input  [1:0]    load_lsu,

    input  [31:0]   inst,
    input           in_pslverr,
    input           flush_finish,
    output          flush_finish_out,

    // output          ebreak,
    output [31:0]   imm,
    
    output          RegWr,
    output [2:0]    Branch,
    output          MemtoReg,
    output          MemWr,
    output [2:0]    MemOp,
    output          ALUAsrc,
    output          ALUBsrc,
    output [3:0]    ALUctr,
    
    // mreg
    output [1:0]    mRegWr,
    output [3:0]    mcause,
    output          mcause_wr,
    output          mret,

    output [3:0]    Ra,
    output [3:0]    Rb,
    output [3:0]    Rw
);

    wire    [4:0]       op;
    wire    [2:0]       fun3;
    wire    [6:0]       fun7;

    wire    [31:0]      immU;
    wire    [31:0]      immI;
    wire    [31:0]      immS;
    wire    [31:0]      immB;
    wire    [31:0]      immJ;
    reg     [31:0]      pc_r;
    reg     [1:0]       val_m;
    reg     [31:0]      instr;
    reg     [31:0]      snpc_r;
    reg                 pslverr;

    assign Ra           = instr[18:15];
    assign Rb           = instr[23:20];
    assign Rw           = instr[10:7];



    assign  mRegWr = val_m;

    assign op   = instr[6:2];
    assign fun3 = instr[14:12];
    assign fun7 = instr[31:25];

    assign immU = {{instr[31:12]}, 12'h000};
    assign immI = {{20{instr[31]}}, instr[31:20]};
    assign immS = {{20{instr[31]}}, instr[31:25], instr[11:7]};
    assign immB = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
    assign immJ = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};

    reg             RegWr_r, ALUAsrc_r, ALUBsrc_r;
    reg [2:0]       Branch_r;
    reg [3:0]       ALUctr_r;

    ysyx_25040102_MuxKeyWithDefault #(10, 5, 32) u_extop // 通过操作码识别指令类型
    (
        imm,
        op,
        32'h0,
        {
            5'b01101, immU,
            5'b00101, immU,
            5'b11011, immJ,
            5'b11001, immI,
            5'b00000, immI,
            5'b00100, immI,
            5'b01100, immI,
            5'b11000, immB,
            5'b01000, immS,
            5'b11100, immI
        }
    );

    wire    illegal;

    ysyx_25040102_MuxKeyWithDefault #(11, 5, 1) u_ill_inst // 无效指令
    (
        illegal,
        op,
        1'h1,
        {
            5'b01101, 1'b0,
            5'b00101, 1'b0,
            5'b11011, 1'b0,
            5'b11001, 1'b0,
            5'b00000, 1'b0,
            5'b00100, 1'b0,
            5'b01100, 1'b0,
            5'b11000, 1'b0,
            5'b01000, 1'b0,
            5'b11100, 1'b0,
            5'b00011, 1'b0
        }
    );

    wire    ebreak;
    wire    ecall   = (op == 5'b11100 && fun3 == 3'b000 && fun7 == 7'b0000000);

    assign  mret    = (op == 5'b11100 && fun3 == 3'b000 && fun7 == 7'b0011000);

    reg     [3:0]   mcause_r;
    reg     cause_wr;

    assign  mcause      = mcause_r;
    assign  mcause_wr   = cause_wr;

    always @(*) begin
        if(pc_r[1:0] != 2'b00) begin // Instruction address misaligned
            mcause_r    = 4'h0;
            cause_wr    = 1'b1;
        end
        else if(pslverr == 1'b1) begin // Instruction access fault
            mcause_r    = 4'h1;
            cause_wr    = 1'b1;
        end
        else if(illegal == 1'b1) begin // Illegal Instruction
            mcause_r    = 4'h2;
            cause_wr    = 1'b1;
        end
        else if(ebreak == 1'b1) begin // ebreak
            mcause_r    = 4'h3;
            cause_wr    = 1'b1;
        end
        else if(ecall == 1'b1) begin // Environment call from M-mode
            mcause_r    = 4'hb;
            cause_wr    = 1'b1;
        end
        else begin
            mcause_r    = 4'h0;
            cause_wr    = 1'b0;
        end
    end

    // 特权
    always @(*) begin
        if(op == 5'b11100) begin 
            if(fun3 == 3'b001) begin // csrrw
                val_m = 2'b01;
            end
            else if(fun3 == 3'b010) begin // csrrs |=
                val_m = 2'b11;
            end
            else begin
                val_m = 2'b00;
            end
        end
        else begin
            val_m   = 2'b00;
        end
    end

    // Regwr
    always @(*) begin
        case(op)
            5'b01101: RegWr_r = 1'b1; // lui
            5'b00101: RegWr_r = 1'b1; // auipc
            5'b00100: RegWr_r = 1'b1; // alu_i
            5'b01100: RegWr_r = 1'b1; // alu
            5'b11011: RegWr_r = 1'b1; // jal
            5'b11001: RegWr_r = 1'b1; // jalr
            5'b00000: RegWr_r = 1'b1; // load
            default: RegWr_r = 1'b0;
        endcase
    end

    assign  RegWr       = RegWr_r | mRegWr[0];

    always @(*) begin
        case(op)
            5'b11011: Branch_r = 3'b001;
            5'b11001: Branch_r = 3'b010;
            5'b11000: begin
                case(fun3)
                    3'b000: Branch_r = 3'b100;
                    3'b001: Branch_r = 3'b101;
                    3'b010: Branch_r = 3'b000;
                    3'b011: Branch_r = 3'b000;
                    3'b100: Branch_r = 3'b110;
                    3'b101: Branch_r = 3'b111;
                    3'b110: Branch_r = 3'b110;
                    3'b111: Branch_r = 3'b111;
                endcase
            end
            default: Branch_r = 3'b000;
        endcase
    end

    assign  MemtoReg    = (op == 5'b00000); // load

    assign  MemWr       = (op == 5'b01000);

    // // ALUAsrc
    always @(*) begin  // 1'b0, rs1, 1'b1, pc
        case(op)
            5'b00101: ALUAsrc_r = 1'b1; // auipc    R(rd) = s -> pc + imm
            5'b11011: ALUAsrc_r = 1'b1; // jal      R(rd) = s -> pc + 4; s -> dnpc += imm - 4;
            default: ALUAsrc_r = 1'b0;
        endcase
    end

    // // ALUBsrc
    always @(*) begin // 1'b0, rs2, 1'b1, imm
        case(op)
            5'b01100: ALUBsrc_r = 1'b0; // alu
            5'b11000: ALUBsrc_r = 1'b0; // branch  s -> dnpc += ((uint32_t)src1 < (uint32_t)src2) ? (imm - 4) : 0
            default: ALUBsrc_r = 1'b1;
        endcase
    end

    assign  ebreak  = (instr == 32'h00100073);
    // // ALUctr
    always @(*) begin
        if(op == 5'b01101) begin // lui
            ALUctr_r = 4'b1010;
        end
        else if(op == 5'b00100) begin // alu_i
            if(fun3 == 3'b101) begin
                ALUctr_r = {fun7[5], fun3};
            end
            else begin
                ALUctr_r = {1'b0, fun3};
            end
        end
        else if(op == 5'b01100) begin // alu
            ALUctr_r = {fun7[5], fun3};
        end
        else if(op == 5'b11000) begin // branch
            if(fun3[2:1] == 2'b11) begin
                ALUctr_r = 4'b0011; // bltu bgeu
            end
            else begin
                ALUctr_r = 4'b0010; // beq, bne, blt, bge
            end
        end
        else begin
            ALUctr_r = 4'b0000;
        end
    end

    assign Branch   = Branch_r;
    assign MemOp    = fun3;
    assign ALUAsrc  = ALUAsrc_r;
    assign ALUBsrc  = ALUBsrc_r;
    assign ALUctr   = ALUctr_r;

    localparam WAIT_INST_VALID      = 0;
    localparam WAIT_DECODE_READY    = 1;

    reg           current_state;
    reg           next_state;

    always @(posedge clk) begin
        if(reset == 1'b1) begin
            current_state <= WAIT_INST_VALID;
        end
        else begin
            current_state <= next_state;
        end
    end

    always @(*) begin
        case(current_state)

            WAIT_INST_VALID: begin
                if(inst_valid == 1'b1 && pc_valid == 1'b0) begin // in_pready
                    next_state = WAIT_DECODE_READY;
                end
                else begin
                    next_state = WAIT_INST_VALID;
                end
            end

            WAIT_DECODE_READY: begin
                 if((decode_ready == 1'b1 && decode_valid == 1'b1) || pc_valid == 1'b1) begin
                    next_state = WAIT_INST_VALID;
                end
                else begin
                    next_state = WAIT_DECODE_READY;
                end
            end

        endcase
    end

    wire            conflict;
    reg             finish_r;

    assign  inst_ready      = (current_state == WAIT_INST_VALID);
    assign  decode_valid    = (current_state == WAIT_DECODE_READY && conflict == 1'b0);

    assign  snpc_out        = snpc_r;
    assign  pc_out          = pc_r;

    always @(posedge clk) begin
        if(inst_valid && inst_ready) begin
            instr       <= inst;
            pslverr     <= in_pslverr;
            pc_r        <= pc;
            snpc_r      <= snpc;
        end
    end

    // RAW阻塞


    always @(posedge clk) begin
        if(reset == 1'b1) begin
            finish_r     <= 1'b0;
        end
        else begin
            if(inst_valid && inst_ready) begin
                finish_r     <= flush_finish;
            end
        end
    end

    assign  flush_finish_out   = finish_r;

    assign  conflict =  (((ALUAsrc_r == 1'b0 && Ra != 0 && Rw_exu == Ra) || ((MemWr == 1'b1 || ALUBsrc_r == 1'b0) && Rb != 0 && Rw_exu == Rb)) && load_exu == 2'b01)  // exu
                        || (((ALUAsrc_r == 1'b0 && Ra != 0 && Rw_lsu == Ra) || ((MemWr == 1'b1 || ALUBsrc_r == 1'b0) && Rb != 0 && Rw_lsu == Rb)) && load_lsu == 2'b01); // lsu


`ifdef ysyx_25040102_SIM
    reg     conf_delay;
    wire    conf_edge   = !conf_delay & conflict;

    always @(posedge clk) begin
        conf_delay      <= conflict;
    end
    
    always @(posedge clk) begin
        if(conf_edge == 1'b1 && op == 5'b00000) begin
            time_add(5); // raw_conflict
        end
    end

    always @(posedge clk) begin
        if(conflict && op == 5'b00000) begin
            cycle_add(5);
        end
    end

    always @(posedge clk) begin
        if(conf_edge == 1'b1 && op != 5'b00000) begin
            time_add(4); // raw_conflict
        end
    end

    always @(posedge clk) begin
        if(conflict && op != 5'b00000) begin
            cycle_add(4);
        end
    end
    
`endif
endmodule
