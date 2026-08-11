module ysyx_26010028_idu #(
    parameter [31:0] RESET_PC = 32'h3000_0000
) (
    input             clock,
    input             reset,
    // IFU 输入
    input             id_in_valid,
    output            id_in_ready,
    input      [31:0] id_in_pc,
    input      [31:0] id_in_inst,
    // IFU -> IDU flush 信号
    input             id_flush,
    // IDU -> EXU
    output            id_out_valid,
    input             id_out_ready,
    output     [31:0] id_out_pc,
    output     [31:0] id_out_inst,
    output     [ 6:0] id_out_opcode,
    output     [ 2:0] id_out_funct3,
    output     [ 6:0] id_out_funct7,
    output     [ 4:0] id_out_rd,
    output     [11:0] id_out_csr_addr,
    output     [31:0] id_out_rs1_val,
    output     [31:0] id_out_rs2_val,
    output     [31:0] id_out_imm,
    output            id_out_rf_wen,
    output            id_out_mem_ren,
    output            id_out_mem_wen,
    output            id_out_fence_i,

    // EXU -> IDU register-file writeback.
    input             wb_rf_wen,
    input      [ 4:0] wb_rf_waddr,
    input      [31:0] wb_rf_wdata,

    output    [1023:0] gpr_probe_bus
);

    localparam [6:0] OPCODE_OP       = 7'b011_0011;
    localparam [6:0] OPCODE_OP_IMM   = 7'b001_0011;
    localparam [6:0] OPCODE_LOAD     = 7'b000_0011;
    localparam [6:0] OPCODE_JALR     = 7'b110_0111;
    localparam [6:0] OPCODE_STORE    = 7'b010_0011;
    localparam [6:0] OPCODE_BRANCH   = 7'b110_0011;
    localparam [6:0] OPCODE_LUI      = 7'b011_0111;
    localparam [6:0] OPCODE_AUIPC    = 7'b001_0111;
    localparam [6:0] OPCODE_JAL      = 7'b110_1111;
    localparam [6:0] OPCODE_SYSTEM   = 7'b111_0011;
    localparam [6:0] OPCODE_MISC_MEM = 7'b000_1111;

    localparam [2:0] F3_PRIV    = 3'b000;
    localparam [2:0] F3_FENCE_I = 3'b001;

    reg id_valid;
    reg [31:0] id_pc;
    reg [31:0] id_inst;

    reg pipe_valid_q;
    reg [31:0] pipe_pc;
    reg [31:0] pipe_inst;
    reg [6:0] pipe_opcode;
    reg [2:0] pipe_funct3;
    reg [6:0] pipe_funct7;
    reg [4:0] pipe_rd;
    reg [11:0] pipe_csr_addr;
    reg [31:0] pipe_rs1_value;
    reg [31:0] pipe_rs2_value;
    reg [31:0] pipe_imm;
    reg pipe_rf_wen;
    reg pipe_load;
    reg pipe_store;
    reg pipe_fence_i;

    wire pipe_allow_in = ~pipe_valid_q || id_out_ready;

    assign id_in_ready = ~id_valid || pipe_allow_in;

    assign id_out_valid = pipe_valid_q;
    assign id_out_pc = pipe_pc;
    assign id_out_inst = pipe_inst;
    assign id_out_opcode = pipe_opcode;
    assign id_out_funct3 = pipe_funct3;
    assign id_out_funct7 = pipe_funct7;
    assign id_out_rd = pipe_rd;
    assign id_out_csr_addr = pipe_csr_addr;
    assign id_out_rs1_val = pipe_rs1_value;
    assign id_out_rs2_val = pipe_rs2_value;
    assign id_out_imm = pipe_imm;
    assign id_out_rf_wen = pipe_rf_wen;
    assign id_out_mem_ren = pipe_load;
    assign id_out_mem_wen = pipe_store;
    assign id_out_fence_i = pipe_fence_i;
    // decode instruction fields
    wire [6:0]  opcode   = id_inst[6:0];
    wire [2:0]  funct3   = id_inst[14:12];
    wire [6:0]  funct7   = id_inst[31:25];
    wire [4:0]  rs1_addr = id_inst[19:15];
    wire [4:0]  rs2_addr = id_inst[24:20];
    wire [4:0]  rd_addr  = id_inst[11:7];
    wire [11:0] csr_addr = id_inst[31:20];

    reg [31:0] gpr [1:15];
    integer reg_idx;
    // Registerfiles debugger
    assign gpr_probe_bus[31:0] = 32'b0;
    assign gpr_probe_bus[1023:512] = 512'b0;
    genvar debug_reg_idx;
    generate
        for (debug_reg_idx = 1; debug_reg_idx < 16; debug_reg_idx = debug_reg_idx + 1) begin : gen_debug_gpr
            assign gpr_probe_bus[debug_reg_idx * 32 +: 32] = gpr[debug_reg_idx];
        end
    endgenerate
    // Support the data bypass rs tunnels
    wire [31:0] rs1_val = (rs1_addr == 5'd0 || rs1_addr[4]) ? 32'b0 : (wb_rf_wen && wb_rf_waddr == rs1_addr ? wb_rf_wdata : gpr[rs1_addr[3:0]]);
    wire [31:0] rs2_val = (rs2_addr == 5'd0 || rs2_addr[4]) ? 32'b0 : (wb_rf_wen && wb_rf_waddr == rs2_addr ? wb_rf_wdata : gpr[rs2_addr[3:0]]);

    always @(posedge clock) begin
        if (reset) begin
            for (reg_idx = 1; reg_idx < 16; reg_idx = reg_idx + 1) begin
                gpr[reg_idx] <= 32'b0;
            end
        end else if (wb_rf_wen && (wb_rf_waddr != 5'd0) && !wb_rf_waddr[4]) begin
            gpr[wb_rf_waddr[3:0]] <= wb_rf_wdata;
        end
    end
    wire [31:0] decode_imm = (opcode == OPCODE_JALR || opcode == OPCODE_LOAD || opcode == OPCODE_OP_IMM) ? {{20{id_inst[31]}}, id_inst[31:20]} : 
                             opcode == OPCODE_STORE ? {{20{id_inst[31]}}, id_inst[31:25], id_inst[11:7]} : 
                             opcode == OPCODE_BRANCH ? {{20{id_inst[31]}}, id_inst[7], id_inst[30:25], id_inst[11:8], 1'b0} : 
                             opcode == OPCODE_LUI || opcode == OPCODE_AUIPC ? {id_inst[31:12], 12'b0} : 
                             opcode == OPCODE_JAL ? {{12{id_inst[31]}}, id_inst[19:12], id_inst[20], id_inst[30:21], 1'b0} : 
                             opcode == OPCODE_SYSTEM ? {27'b0, id_inst[19:15]} : 32'b0;

    wire decode_mem_ren = (opcode == OPCODE_LOAD);
    wire decode_mem_wen = (opcode == OPCODE_STORE);
    wire decode_fence_i = (opcode == OPCODE_MISC_MEM) && (funct3 == F3_FENCE_I);
    wire decode_rf_wen  = opcode == OPCODE_OP || opcode == OPCODE_OP_IMM || opcode == OPCODE_LUI || opcode == OPCODE_AUIPC || 
                         opcode == OPCODE_LOAD || opcode == OPCODE_JAL || opcode == OPCODE_JALR || (opcode == OPCODE_SYSTEM && funct3 != F3_PRIV);

    always @(posedge clock) begin
        if (reset) begin
            id_valid <= 1'b0;
            id_pc <= RESET_PC;
            id_inst <= 32'h0000_0013;
            pipe_valid_q <= 1'b0;
            pipe_pc <= RESET_PC;
            pipe_inst <= 32'h0000_0013;
        end else if (id_flush) begin
            id_valid <= 1'b0;
            pipe_valid_q <= 1'b0;
        end else begin
            if (pipe_allow_in) begin
                pipe_valid_q <= id_valid;
                if (id_valid) begin
                    pipe_pc       <= id_pc;
                    pipe_inst     <= id_inst;
                    pipe_opcode   <= opcode;
                    pipe_funct3   <= funct3;
                    pipe_funct7   <= funct7;
                    pipe_rd       <= rd_addr;
                    pipe_csr_addr <= csr_addr;
                    pipe_rs1_value  <= rs1_val;
                    pipe_rs2_value  <= rs2_val;
                    pipe_imm      <= decode_imm;
                    pipe_rf_wen   <= decode_rf_wen;
                    pipe_load  <= decode_mem_ren;
                    pipe_store  <= decode_mem_wen;
                    pipe_fence_i <= decode_fence_i;
                end
            end
            if (id_in_ready) begin
                id_valid <= id_in_valid;
                if (id_in_valid) begin
                    id_pc <= id_in_pc;
                    id_inst <= id_in_inst;
                end
            end
        end
    end

`ifdef NPC_SIMULATION
`ifndef SYNTHESIS
`ifndef __ICARUS__
    always @(posedge clock) begin
        if (!reset && id_valid) begin
            if (id_pc[1:0] != 2'b00) begin
                $fatal(1, "idu: unaligned instruction pc=%08x inst=%08x", id_pc, id_inst);
            end
        end
    end
`endif
`endif
`endif

endmodule
