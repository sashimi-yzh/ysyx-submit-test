module ysyx_26030082_exu (
    input             clock,
    input             reset,

    input             ex_in_valid,
    output            ex_in_ready,
    input      [31:0] ex_pc,
    input      [31:0] ex_inst,

    output            ex_out_valid,

    input      [63:0] ex_mtime,

    output            ex_redirect,
    output reg [31:0] ex_redirect_pc,
    output            ex_fence_i,

    output     [31:0] lsu_master_araddr,
    output     [ 2:0] lsu_master_arsize,
    output            lsu_master_arvalid,
    input             lsu_master_arready,
    input      [31:0] lsu_master_rdata,
    input      [ 1:0] lsu_master_rresp,
    input             lsu_master_rvalid,
    output            lsu_master_rready,
    output     [31:0] lsu_master_awaddr,
    output     [ 2:0] lsu_master_awsize,
    output            lsu_master_awvalid,
    input             lsu_master_awready,
    output reg [31:0] lsu_master_wdata,
    output reg [ 3:0] lsu_master_wstrb,
    output            lsu_master_wvalid,
    input             lsu_master_wready,
    input      [ 1:0] lsu_master_bresp,
    input             lsu_master_bvalid,
    output            lsu_master_bready
);

    localparam [6:0] OPCODE_OP   = 7'b011_0011;
    localparam [6:0] OPCODE_OP_IMM   = 7'b001_0011;
    localparam [6:0] OPCODE_LOAD  = 7'b000_0011;
    localparam [6:0] OPCODE_JALR  = 7'b110_0111;
    localparam [6:0] OPCODE_STORE   = 7'b010_0011;
    localparam [6:0] OPCODE_BRANCH   = 7'b110_0011;
    localparam [6:0] OPCODE_LUI   = 7'b011_0111;
    localparam [6:0] OPCODE_AUIPC  = 7'b001_0111;
    localparam [6:0] OPCODE_JAL   = 7'b110_1111;
    localparam [6:0] OPCODE_SYSTEM = 7'b111_0011;
    localparam [6:0] OPCODE_MISC_MEM = 7'b000_1111;

    localparam [11:0] CSR_MSTATUS   = 12'h300;
    localparam [11:0] CSR_MTVEC     = 12'h305;
    localparam [11:0] CSR_MEPC      = 12'h341;
    localparam [11:0] CSR_MCAUSE    = 12'h342;
    localparam [11:0] CSR_MVENDORID = 12'hF11;
    localparam [11:0] CSR_MARCHID   = 12'hF12;

    localparam [11:0] F12_ECALL = 12'h000;
    localparam [11:0] F12_MRET  = 12'h302;

    localparam [2:0] F3_PRIV   = 3'b000;
    localparam [2:0] F3_CSRRW  = 3'b001;
    localparam [2:0] F3_CSRRS  = 3'b010;
    localparam [2:0] F3_CSRRC  = 3'b011;
    localparam [2:0] F3_CSRRWI = 3'b101;
    localparam [2:0] F3_CSRRSI = 3'b110;
    localparam [2:0] F3_CSRRCI = 3'b111;

    localparam [2:0] F3_ADD_SUB = 3'b000;
    localparam [2:0] F3_SLL     = 3'b001;
    localparam [2:0] F3_SLT     = 3'b010;
    localparam [2:0] F3_SLTU    = 3'b011;
    localparam [2:0] F3_XOR     = 3'b100;
    localparam [2:0] F3_SRL_SRA = 3'b101;
    localparam [2:0] F3_OR      = 3'b110;
    localparam [2:0] F3_AND     = 3'b111;

    localparam [2:0] F3_BEQ  = 3'b000;
    localparam [2:0] F3_BNE  = 3'b001;
    localparam [2:0] F3_BLT  = 3'b100;
    localparam [2:0] F3_BGE  = 3'b101;
    localparam [2:0] F3_BLTU = 3'b110;
    localparam [2:0] F3_BGEU = 3'b111;

    localparam [2:0] F3_FENCE   = 3'b000;
    localparam [2:0] F3_FENCE_I = 3'b001;
    localparam [2:0] F3_LB      = 3'b000;
    localparam [2:0] F3_LH      = 3'b001;
    localparam [2:0] F3_LW      = 3'b010;
    localparam [2:0] F3_LBU     = 3'b100;
    localparam [2:0] F3_LHU     = 3'b101;
    localparam [2:0] F3_SB      = 3'b000;
    localparam [2:0] F3_SH      = 3'b001;
    localparam [2:0] F3_SW      = 3'b010;
    localparam [2:0] F3_JALR    = 3'b000;

    localparam [31:0] CAUSE_ECALL = 32'd11;
    localparam R_IDLE    = 1'd0;
    localparam R_WAIT_R  = 1'd1;
    localparam W_IDLE    = 2'd0;
    localparam W_WAIT_AW = 2'd1;
    localparam W_WAIT_W  = 2'd2;
    localparam W_WAIT_B  = 2'd3;
    localparam [15:0] CLINT_BASE_HI     = 16'h0200;
    localparam [15:0] MTIME_OFFSET  = 16'hbff8;
    localparam [15:0] MTIMEH_OFFSET = 16'hbffc;

    reg        branch_redirect;

    // RF.
    reg  [31:0] reg_bank [1:15];
    reg  [31:0] rf_wdata;

    // CSR.
    reg  [31:0] csr_mstatus;
    reg  [31:0] csr_mtvec;
    reg  [31:0] csr_mepc;
    reg  [31:0] csr_mcause;
    reg  [31:0] csr_rdata;

    // Memory.
    reg         rd_state;
    reg  [1:0] wr_state;
    reg  [31:0] clint_rdata;
    reg  [31:0] rdata_decoded;

    wire [6:0]  opcode = ex_inst[6:0];
    wire [2:0]  funct3 = ex_inst[14:12];
    wire        funct7_5 = ex_inst[30];
    wire [4:0]  rf_raddr1 = ex_inst[19:15];
    wire [4:0]  rf_raddr2 = ex_inst[24:20];
    wire [11:0] csr_addr = ex_inst[31:20];

    wire [4:0] rf_waddr = ex_inst[11:7];

/////////////////////////
    // ID: RF read, imm gen, input mux.
    wire [31:0] rf_rdata1 = (rf_raddr1 == 5'd0 || rf_raddr1[4]) ? 32'b0 : reg_bank[rf_raddr1[3:0]];
    wire [31:0] rf_rdata2 = (rf_raddr2 == 5'd0 || rf_raddr2[4]) ? 32'b0 : reg_bank[rf_raddr2[3:0]];

    wire [31:0] imm = ({32{opcode == OPCODE_OP_IMM || opcode == OPCODE_LOAD || opcode == OPCODE_JALR}} & {{20{ex_inst[31]}}, ex_inst[31:20]}) |
                      ({32{opcode == OPCODE_STORE}} & {{20{ex_inst[31]}}, ex_inst[31:25], ex_inst[11:7]}) |
                      ({32{opcode == OPCODE_BRANCH}} & {{20{ex_inst[31]}}, ex_inst[7], ex_inst[30:25], ex_inst[11:8], 1'b0}) |
                      ({32{opcode == OPCODE_LUI || opcode == OPCODE_AUIPC}} & {ex_inst[31:12], 12'b0}) |
                      ({32{opcode == OPCODE_JAL}} & {{12{ex_inst[31]}}, ex_inst[19:12], ex_inst[20], ex_inst[30:21], 1'b0}) |
                      ({32{opcode == OPCODE_SYSTEM}} & {27'b0, ex_inst[19:15]});

    wire [31:0] pc4 = ex_pc + 32'd4;
    wire [31:0] csr_src_data = funct3[2] ? imm : rf_rdata1;
    wire        mem_ren = opcode == OPCODE_LOAD;
    wire        mem_wen = opcode == OPCODE_STORE;
    assign ex_fence_i = opcode == OPCODE_MISC_MEM && funct3 == F3_FENCE_I;

    wire rf_wen = opcode == OPCODE_OP ||
                  opcode == OPCODE_OP_IMM ||
                  opcode == OPCODE_LUI ||
                  opcode == OPCODE_AUIPC ||
                  opcode == OPCODE_LOAD ||
                  opcode == OPCODE_JAL ||
                  opcode == OPCODE_JALR ||
                  opcode == OPCODE_SYSTEM && funct3 != F3_PRIV;

    wire addsub_sub = opcode == OPCODE_OP && funct7_5;
    wire [31:0] addsub_lhs = ({32{opcode == OPCODE_OP || opcode == OPCODE_OP_IMM || opcode == OPCODE_LOAD || opcode == OPCODE_STORE || opcode == OPCODE_JALR}} & rf_rdata1) |
                             ({32{opcode == OPCODE_AUIPC || opcode == OPCODE_JAL || opcode == OPCODE_BRANCH}} & ex_pc);
    wire [31:0] addsub_rhs = opcode == OPCODE_OP ? rf_rdata2 : imm;
    wire [31:0] addsub_rhs_xor = addsub_sub ? ~addsub_rhs : addsub_rhs;

    wire [31:0] bit_lhs = opcode == OPCODE_SYSTEM ? csr_rdata : rf_rdata1;
    wire [31:0] bit_rhs = ({32{opcode == OPCODE_OP}} & rf_rdata2) |
                          ({32{opcode == OPCODE_OP_IMM}} & imm) |
                          ({32{opcode == OPCODE_SYSTEM && (funct3 == F3_CSRRS || funct3 == F3_CSRRSI)}} & csr_src_data) |
                          ({32{opcode == OPCODE_SYSTEM && (funct3 == F3_CSRRC || funct3 == F3_CSRRCI)}} & ~csr_src_data);

    wire [31:0] cmp_rhs = opcode == OPCODE_OP_IMM ? imm : rf_rdata2;


/////////////////////////
    // EX: FU, CSR, redirect.
    
    wire [31:0] addsub_result = addsub_lhs + addsub_rhs_xor + {31'b0, addsub_sub};

    wire [31:0] and_result = bit_lhs & bit_rhs;
    wire [31:0] or_result = bit_lhs | bit_rhs;
    wire [31:0] xor_result = bit_lhs ^ bit_rhs;

    wire [31:0] sll_result = rf_rdata1 << addsub_rhs[4:0];
    wire [31:0] srl_result = rf_rdata1 >> addsub_rhs[4:0];
    wire [31:0] sra_result = ($signed(rf_rdata1)) >>> addsub_rhs[4:0];

    wire        cmp_eq = (rf_rdata1 == cmp_rhs);
    wire        cmp_lt = ($signed(rf_rdata1) < $signed(cmp_rhs));
    wire        cmp_ltu = (rf_rdata1 < cmp_rhs);

    always @(*) begin
        case (csr_addr)
            CSR_MSTATUS:   csr_rdata = csr_mstatus;
            CSR_MTVEC:     csr_rdata = csr_mtvec;
            CSR_MEPC:      csr_rdata = csr_mepc;
            CSR_MCAUSE:    csr_rdata = csr_mcause;
            CSR_MVENDORID: csr_rdata = 32'h7973_7978;
            CSR_MARCHID:   csr_rdata = 32'd26030082;
            default:       csr_rdata = 32'b0;
        endcase
    end

    always @(*) begin
        case (funct3)
            F3_BEQ:  branch_redirect = cmp_eq;
            F3_BNE:  branch_redirect = ~cmp_eq;
            F3_BLT:  branch_redirect = cmp_lt;
            F3_BGE:  branch_redirect = ~cmp_lt;
            F3_BLTU: branch_redirect = cmp_ltu;
            F3_BGEU: branch_redirect = ~cmp_ltu;
            default: branch_redirect = 1'b0;
        endcase
    end

    assign ex_redirect = opcode == OPCODE_BRANCH && branch_redirect ||
                         opcode == OPCODE_JAL ||
                         opcode == OPCODE_JALR ||
                         opcode == OPCODE_SYSTEM && funct3 == F3_PRIV ||
                         ex_fence_i;

    // Redirect mux.
    always @(*) begin
        ex_redirect_pc = 32'bx;
        case (opcode)
            OPCODE_BRANCH, OPCODE_JAL, OPCODE_JALR: ex_redirect_pc = {addsub_result[31:1], 1'b0};
            OPCODE_SYSTEM: begin
                case (funct3)
                    F3_PRIV: begin
                        case (csr_addr)
                            F12_ECALL: ex_redirect_pc = {csr_mtvec[31:2], 2'b0};
                            F12_MRET:  ex_redirect_pc = csr_mepc;
                            default:;
                        endcase
                    end
                    default:;
                endcase
            end
            OPCODE_MISC_MEM: ex_redirect_pc = pc4;
            default:;
        endcase
    end

    always @(posedge clock) begin
        if (reset) begin
            csr_mstatus <= 32'h1800;
            csr_mtvec   <= 32'h1;
            csr_mepc    <= 32'h0;
            csr_mcause  <= 32'h0;
        end else if (ex_out_valid && opcode == OPCODE_SYSTEM) begin
            case (funct3)
                F3_PRIV: begin
                    case (csr_addr)
                        F12_ECALL: begin
                            csr_mstatus[3] <= 1'b0;
                            csr_mstatus[7] <= csr_mstatus[3];
                            csr_mstatus[12:11] <= 2'b11;
                            csr_mepc <= ex_pc;
                            csr_mcause <= CAUSE_ECALL;
                        end
                        F12_MRET: begin
                            csr_mstatus[3] <= csr_mstatus[7];
                            csr_mstatus[7] <= 1'b1;
                            csr_mstatus[12:11] <= 2'b00;
                        end
                        default:;
                    endcase
                end

                F3_CSRRW, F3_CSRRWI: begin
                    case (csr_addr)
                        CSR_MSTATUS: csr_mstatus <= csr_src_data;
                        CSR_MTVEC:   csr_mtvec   <= csr_src_data;
                        CSR_MEPC:    csr_mepc    <= csr_src_data;
                        CSR_MCAUSE:  csr_mcause  <= csr_src_data;
                        default:;
                    endcase
                end

                F3_CSRRS, F3_CSRRSI: begin
                    case (csr_addr)
                        CSR_MSTATUS: csr_mstatus <= or_result;
                        CSR_MTVEC:   csr_mtvec   <= or_result;
                        CSR_MEPC:    csr_mepc    <= or_result;
                        CSR_MCAUSE:  csr_mcause  <= or_result;
                        default:;
                    endcase
                end

                F3_CSRRC, F3_CSRRCI: begin
                    case (csr_addr)
                        CSR_MSTATUS: csr_mstatus <= and_result;
                        CSR_MTVEC:   csr_mtvec   <= and_result;
                        CSR_MEPC:    csr_mepc    <= and_result;
                        CSR_MCAUSE:  csr_mcause  <= and_result;
                        default:;
                    endcase
                end

                default: begin
                end
            endcase
        end
    end

/////////////////////////
    // LS: lsu_master.

    always @(*) begin
        lsu_master_wstrb = 4'b0000;
        lsu_master_wdata = rf_rdata2;
        case (funct3)
            F3_SB: begin
                case (addsub_result[1:0])
                    2'b00: begin
                        lsu_master_wstrb = 4'b0001;
                        lsu_master_wdata = {24'b0, rf_rdata2[7:0]};
                    end
                    2'b01: begin
                        lsu_master_wstrb = 4'b0010;
                        lsu_master_wdata = {16'b0, rf_rdata2[7:0], 8'b0};
                    end
                    2'b10: begin
                        lsu_master_wstrb = 4'b0100;
                        lsu_master_wdata = {8'b0, rf_rdata2[7:0], 16'b0};
                    end
                    2'b11: begin
                        lsu_master_wstrb = 4'b1000;
                        lsu_master_wdata = {rf_rdata2[7:0], 24'b0};
                    end
                endcase
            end
            F3_SH: begin
                case (addsub_result[1])
                    1'b0: begin
                        lsu_master_wstrb = 4'b0011;
                        lsu_master_wdata = {16'b0, rf_rdata2[15:0]};
                    end
                    1'b1: begin
                        lsu_master_wstrb = 4'b1100;
                        lsu_master_wdata = {rf_rdata2[15:0], 16'b0};
                    end
                endcase
            end
            default: begin
                lsu_master_wstrb = 4'b1111;
                lsu_master_wdata = rf_rdata2;
            end
        endcase
    end

    wire is_clint = (addsub_result[31:16] == CLINT_BASE_HI);

    always @(*) begin
        case (addsub_result[15:2])
            MTIME_OFFSET[15:2]:  clint_rdata = ex_mtime[31:0];
            MTIMEH_OFFSET[15:2]: clint_rdata = ex_mtime[63:32];
            default:            clint_rdata = 32'b0;
        endcase
    end

    wire ext_load_req = ex_in_valid && mem_ren && ~is_clint;
    wire ext_store_req = ex_in_valid && mem_wen && ~is_clint;

    wire ar_fire = lsu_master_arvalid && lsu_master_arready;
    wire r_fire = lsu_master_rvalid && lsu_master_rready;
    wire aw_fire = lsu_master_awvalid && lsu_master_awready;
    wire w_fire = lsu_master_wvalid && lsu_master_wready;
    wire b_fire = lsu_master_bvalid && lsu_master_bready;

    assign ex_in_ready = ~(ext_load_req || ext_store_req) || r_fire || b_fire;
    assign ex_out_valid = ex_in_valid && ex_in_ready;

    assign lsu_master_araddr = addsub_result;
    assign lsu_master_arsize = {1'b0, funct3[1:0]};
    assign lsu_master_arvalid = rd_state == R_IDLE && ext_load_req;
    assign lsu_master_rready = rd_state == R_WAIT_R;
    assign lsu_master_awaddr = addsub_result;
    assign lsu_master_awsize = {1'b0, funct3[1:0]};
    assign lsu_master_awvalid = wr_state == W_IDLE && ext_store_req || wr_state == W_WAIT_AW;
    assign lsu_master_wvalid = wr_state == W_IDLE && ext_store_req || wr_state == W_WAIT_W;
    assign lsu_master_bready = wr_state == W_WAIT_B;

    always @(posedge clock) begin
        if (reset) begin
            rd_state <= R_IDLE;
        end else begin
            case (rd_state)
                R_IDLE:   if (ar_fire) rd_state <= R_WAIT_R;
                R_WAIT_R: if (r_fire)  rd_state <= R_IDLE;
            endcase
        end
    end

    always @(posedge clock) begin
        if (reset) begin
            wr_state <= W_IDLE;
        end else begin
            case (wr_state)
                W_IDLE: begin
                    case ({aw_fire, w_fire})
                        2'b00: wr_state <= W_IDLE;
                        2'b01: wr_state <= W_WAIT_AW;
                        2'b10: wr_state <= W_WAIT_W;
                        2'b11: wr_state <= W_WAIT_B;  
                    endcase
                end
                W_WAIT_AW: if (aw_fire) wr_state <= W_WAIT_B;
                W_WAIT_W:  if (w_fire)  wr_state <= W_WAIT_B;
                W_WAIT_B:  if (b_fire)  wr_state <= W_IDLE;
            endcase
        end
    end

    wire [31:0] load_raw_data = is_clint ? clint_rdata : lsu_master_rdata;

    always @(*) begin
        rdata_decoded = load_raw_data;
        case (funct3)
            F3_LB: begin
                case (addsub_result[1:0])
                    2'b00: rdata_decoded = {{24{load_raw_data[7]}}, load_raw_data[7:0]};
                    2'b01: rdata_decoded = {{24{load_raw_data[15]}}, load_raw_data[15:8]};
                    2'b10: rdata_decoded = {{24{load_raw_data[23]}}, load_raw_data[23:16]};
                    2'b11: rdata_decoded = {{24{load_raw_data[31]}}, load_raw_data[31:24]};
                endcase
            end
            F3_LH: begin
                case (addsub_result[1])
                    1'b0: rdata_decoded = {{16{load_raw_data[15]}}, load_raw_data[15:0]};
                    1'b1: rdata_decoded = {{16{load_raw_data[31]}}, load_raw_data[31:16]};
                endcase
            end
            F3_LBU: begin
                case (addsub_result[1:0])
                    2'b00: rdata_decoded = {24'b0, load_raw_data[7:0]};
                    2'b01: rdata_decoded = {24'b0, load_raw_data[15:8]};
                    2'b10: rdata_decoded = {24'b0, load_raw_data[23:16]};
                    2'b11: rdata_decoded = {24'b0, load_raw_data[31:24]};
                endcase
            end
            F3_LHU: begin
                case (addsub_result[1])
                    1'b0: rdata_decoded = {16'b0, load_raw_data[15:0]};
                    1'b1: rdata_decoded = {16'b0, load_raw_data[31:16]};
                endcase
            end
            default: rdata_decoded = load_raw_data;
        endcase
    end


/////////////////////////
    // WB: output mux and RF write.
    wire rf_write = ex_out_valid && rf_wen && (rf_waddr != 5'b0) && ~rf_waddr[4];

    always @(*) begin
        rf_wdata = 32'bx;
        case (opcode)
            OPCODE_OP, OPCODE_OP_IMM: begin
                case (funct3)
                    F3_ADD_SUB:         rf_wdata = addsub_result;
                    F3_SLL:             rf_wdata = sll_result;
                    F3_SLT:             rf_wdata = {31'b0, cmp_lt};
                    F3_SLTU:            rf_wdata = {31'b0, cmp_ltu};
                    F3_XOR:             rf_wdata = xor_result;
                    F3_SRL_SRA:         rf_wdata = funct7_5 ? sra_result : srl_result;
                    F3_OR:              rf_wdata = or_result;
                    F3_AND:             rf_wdata = and_result;
                    default:;
                endcase
            end
            OPCODE_LUI:                 rf_wdata = imm;
            OPCODE_AUIPC:               rf_wdata = addsub_result;
            OPCODE_LOAD:                rf_wdata = rdata_decoded;
            OPCODE_JAL, OPCODE_JALR:    rf_wdata = pc4;
            OPCODE_SYSTEM:              rf_wdata = csr_rdata;
            default:;
        endcase
    end

    always @(posedge clock) begin
        if (rf_write) begin
            reg_bank[rf_waddr[3:0]] <= rf_wdata;
        end
    end

`ifdef NPC_SIMULATION
`ifndef SYNTHESIS
`ifndef __ICARUS__
    wire csr_supported = csr_addr == CSR_MSTATUS ||
                         csr_addr == CSR_MTVEC ||
                         csr_addr == CSR_MEPC ||
                         csr_addr == CSR_MCAUSE ||
                         csr_addr == CSR_MVENDORID ||
                         csr_addr == CSR_MARCHID;
    wire csr_readonly = csr_addr == CSR_MVENDORID || csr_addr == CSR_MARCHID;
    wire csr_write_req = funct3 == F3_CSRRW || funct3 == F3_CSRRWI ||
                         ((funct3 == F3_CSRRS || funct3 == F3_CSRRSI ||
                           funct3 == F3_CSRRC || funct3 == F3_CSRRCI) && rf_raddr1 != 5'd0);
    wire load_funct3_ok = funct3 == F3_LB || funct3 == F3_LH || funct3 == F3_LW ||
                          funct3 == F3_LBU || funct3 == F3_LHU;
    wire store_funct3_ok = funct3 == F3_SB || funct3 == F3_SH || funct3 == F3_SW;

    always @(posedge clock) begin
        if (!reset && ex_in_valid) begin
            if (ex_pc[1:0] != 2'b00) begin
                $fatal(1, "exu: unaligned commit pc pc=%08x inst=%08x", ex_pc, ex_inst);
            end
            if (ex_out_valid && ex_redirect && (ex_inst != 32'h0010_0073) &&
                (ex_redirect_pc[1:0] != 2'b00)) begin
                $fatal(1, "exu: unaligned redirect pc=%08x inst=%08x target=%08x",
                    ex_pc, ex_inst, ex_redirect_pc);
            end
            if (opcode == OPCODE_SYSTEM && funct3 == F3_PRIV &&
                csr_addr != F12_ECALL && csr_addr != F12_MRET && ex_inst != 32'h0010_0073) begin
                $fatal(1, "exu: unsupported privileged system inst pc=%08x inst=%08x funct12=%03x",
                    ex_pc, ex_inst, csr_addr);
            end
            if (opcode == OPCODE_SYSTEM && funct3 != F3_PRIV && !csr_supported) begin
                $fatal(1, "exu: unsupported CSR pc=%08x inst=%08x csr=%03x",
                    ex_pc, ex_inst, csr_addr);
            end
            if (opcode == OPCODE_SYSTEM && csr_write_req && csr_readonly) begin
                $fatal(1, "exu: write read-only CSR pc=%08x inst=%08x csr=%03x",
                    ex_pc, ex_inst, csr_addr);
            end
            if (mem_ren && !load_funct3_ok) begin
                $fatal(1, "exu: unsupported load funct3 pc=%08x inst=%08x funct3=%0d",
                    ex_pc, ex_inst, funct3);
            end
            if (mem_wen && !store_funct3_ok) begin
                $fatal(1, "exu: unsupported store funct3 pc=%08x inst=%08x funct3=%0d",
                    ex_pc, ex_inst, funct3);
            end
            if (lsu_master_arvalid && lsu_master_arsize > 3'd2) begin
                $fatal(1, "exu: bad LSU read size pc=%08x inst=%08x addr=%08x size=%0d",
                    ex_pc, ex_inst, lsu_master_araddr, lsu_master_arsize);
            end
            if (lsu_master_awvalid && lsu_master_awsize > 3'd2) begin
                $fatal(1, "exu: bad LSU write size pc=%08x inst=%08x addr=%08x size=%0d",
                    ex_pc, ex_inst, lsu_master_awaddr, lsu_master_awsize);
            end
            if (lsu_master_wvalid && lsu_master_wstrb == 4'b0000) begin
                $fatal(1, "exu: zero LSU write strobe pc=%08x inst=%08x addr=%08x",
                    ex_pc, ex_inst, lsu_master_awaddr);
            end
        end
    end
`endif
`endif
`endif

endmodule
