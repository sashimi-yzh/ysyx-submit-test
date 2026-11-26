module Core(
  input clk,
  input rst,

  output [31:0] fetch_pc,
  output        fetch_req,
  input         fetch_ready,
  input  [31:0] fetch_inst,
  input         fetch_idle,
  output        fetch_accept,

  output        mem_valid,
  output        mem_wen,
  output [2:0]  mem_f3,
  output [31:0] mem_addr,
  output [31:0] mem_wdata,
  input  [31:0] mem_rdata,
  input         mem_done,
  output        mem_is_load,
  output        mem_is_store,

  output [11:0] csr_addr,
  output [31:0] csr_wdata,
  output        csr_wen,
  output        csr_ecall,
  output [31:0] csr_pc,
  input  [31:0] csr_rdata,
  input  [31:0] mepc,
  input  [31:0] mtvec,
  output        icache_flush,

  output [31:0] cur_pc,
  output [31:0] cur_inst
`ifndef SYNTHESIS
  ,
  output [31:0] a0_value,
  output        retire,
  output [31:0] retire_pc,
  output [31:0] retire_inst,
  output [31:0] retire_next_pc,
  output [31:0] retire_addr,
  output [31:0] retire_wdata,
  output        retire_is_mem,
  output        retire_is_store,
  output        retire_branch_taken
`endif
);

`ifdef SYNTHESIS
  wire [31:0] a0_value;
`endif

  localparam [31:0] RESET_PC =
`ifdef SIM_IVERILOG
    // iverilog RTL/netlist simulation starts at the standalone program base.
    32'h8000_0000;
`elsif SOC_MODE
    32'h3000_0000;
`else
    32'h8000_0000;
`endif

  localparam ALU_ADD  = 4'd0;
  localparam ALU_SUB  = 4'd1;
  localparam ALU_SLL  = 4'd2;
  localparam ALU_SLT  = 4'd3;
  localparam ALU_SLTU = 4'd4;
  localparam ALU_XOR  = 4'd5;
  localparam ALU_SRL  = 4'd6;
  localparam ALU_SRA  = 4'd7;
  localparam ALU_OR   = 4'd8;
  localparam ALU_AND  = 4'd9;

  localparam [1:0] A_RS1 = 2'd0, A_PC = 2'd1, A_ZERO = 2'd2;
  localparam [1:0] B_RS2 = 2'd0, B_IMM = 2'd1, B_FOUR = 2'd2;

  // ---------------- state ----------------
  reg [31:0] pc;
  reg        id_valid;
  reg [31:0] id_pc, id_inst;

  reg        ex_valid;
  reg [31:0] ex_pc, ex_rs1, ex_rs2, ex_imm;
  reg [3:0]  ex_rd;
  reg [2:0]  ex_f3;
  reg [3:0]  ex_alu_op;
  reg [1:0]  ex_a_sel, ex_b_sel;
  reg        ex_reg_wen, ex_is_load, ex_is_store;
  reg        ex_is_branch, ex_is_jal, ex_is_jalr;

  reg        m_valid;
  reg [31:0] m_result, m_store_data;
  reg [3:0]  m_rd;
  reg [2:0]  m_f3;
  reg        m_reg_wen, m_is_load, m_is_store;

`ifndef SYNTHESIS
  reg [31:0] ex_inst, ex_next_pc;
  reg [31:0] m_pc, m_inst, m_next_pc;
  reg        m_branch_taken;
`endif

  // ---------------- decode ----------------
  wire [6:0] opcode = id_inst[6:0];
  wire [2:0] f3     = id_inst[14:12];
  wire [6:0] f7     = id_inst[31:25];
  wire [4:0] rd5    = id_inst[11:7];
  wire [4:0] rs1_5  = id_inst[19:15];
  wire [4:0] rs2_5  = id_inst[24:20];
  wire [3:0] rd_id  = rd5[3:0];
  wire [3:0] rs1_id = rs1_5[3:0];
  wire [3:0] rs2_id = rs2_5[3:0];

  wire [31:0] imm_i = {{20{id_inst[31]}}, id_inst[31:20]};
  wire [31:0] imm_s = {{20{id_inst[31]}}, id_inst[31:25], id_inst[11:7]};
  wire [31:0] imm_b = {{19{id_inst[31]}}, id_inst[31], id_inst[7], id_inst[30:25], id_inst[11:8], 1'b0};
  wire [31:0] imm_u = {id_inst[31:12], 12'b0};
  wire [31:0] imm_j = {{11{id_inst[31]}}, id_inst[31], id_inst[19:12], id_inst[20], id_inst[30:21], 1'b0};

  wire is_op     = (opcode == 7'b0110011);
  wire is_opimm  = (opcode == 7'b0010011);
  wire is_load   = (opcode == 7'b0000011);
  wire is_store  = (opcode == 7'b0100011);
  wire is_branch = (opcode == 7'b1100011);
  wire is_jal    = (opcode == 7'b1101111);
  wire is_jalr   = (opcode == 7'b1100111) && (f3 == 3'b000);
  wire is_lui    = (opcode == 7'b0110111);
  wire is_auipc  = (opcode == 7'b0010111);
  wire is_fencei = (id_inst == 32'h0000_100F);
  wire is_ecall  = (id_inst == 32'h0000_0073);
  wire is_ebreak = (id_inst == 32'h0010_0073);
  wire is_mret   = (id_inst == 32'h3020_0073);
  wire is_csrrw  = (opcode == 7'b1110011) && (f3 == 3'b001);
  wire is_csrrs  = (opcode == 7'b1110011) && (f3 == 3'b010);
  wire is_csr    = is_csrrw || is_csrrs;

  wire uses_rs1 = is_op || is_opimm || is_load || is_store || is_branch || is_jalr || is_csr;
  wire uses_rs2 = is_op || is_store || is_branch;
  wire reg_wen  = is_op || is_opimm || is_load || is_lui ||
                  is_auipc || is_jal || is_jalr;

  reg [3:0] alu_op;
  reg [1:0] alu_a_sel, alu_b_sel;
  reg [31:0] imm_sel;
  always @(*) begin
    alu_op    = ALU_ADD;
    alu_a_sel = A_RS1;
    alu_b_sel = B_IMM;
    imm_sel   = imm_i;
    if (is_op || is_opimm) begin
      alu_a_sel = A_RS1;
      alu_b_sel = is_op ? B_RS2 : B_IMM;
      case (f3)
        3'b000: alu_op = (is_op && f7[5]) ? ALU_SUB : ALU_ADD;
        3'b001: alu_op = ALU_SLL;
        3'b010: alu_op = ALU_SLT;
        3'b011: alu_op = ALU_SLTU;
        3'b100: alu_op = ALU_XOR;
        3'b101: alu_op = f7[5] ? ALU_SRA : ALU_SRL;
        3'b110: alu_op = ALU_OR;
        3'b111: alu_op = ALU_AND;
      endcase
    end else if (is_load) begin
      alu_op = ALU_ADD; alu_a_sel = A_RS1; alu_b_sel = B_IMM; imm_sel = imm_i;
    end else if (is_store) begin
      alu_op = ALU_ADD; alu_a_sel = A_RS1; alu_b_sel = B_IMM; imm_sel = imm_s;
    end else if (is_branch) begin
      alu_op = ALU_ADD; alu_a_sel = A_RS1; alu_b_sel = B_IMM; imm_sel = imm_b;
    end else if (is_lui) begin
      alu_op = ALU_ADD; alu_a_sel = A_ZERO; alu_b_sel = B_IMM; imm_sel = imm_u;
    end else if (is_auipc) begin
      alu_op = ALU_ADD; alu_a_sel = A_PC; alu_b_sel = B_IMM; imm_sel = imm_u;
    end else if (is_jal) begin
      alu_op = ALU_ADD; alu_a_sel = A_PC; alu_b_sel = B_FOUR; imm_sel = imm_j;
    end else if (is_jalr) begin
      alu_op = ALU_ADD; alu_a_sel = A_PC; alu_b_sel = B_FOUR; imm_sel = imm_i;
    end
  end

  // ---------------- MEM/EX status ----------------
  wire mem_busy  = m_valid && (m_is_load || m_is_store) && !mem_done;
  wire adv       = !mem_busy;
  wire m_done_wb = !mem_busy;
  wire [31:0] m_wb_data = m_is_load ? mem_rdata : m_result;

  // ---------------- EX datapath ----------------
  wire [31:0] ex_alu_a = (ex_a_sel == A_PC) ? ex_pc :
                         (ex_a_sel == A_ZERO) ? 32'b0 : ex_rs1;
  wire [31:0] ex_alu_b = (ex_b_sel == B_RS2) ? ex_rs2 :
                         (ex_b_sel == B_FOUR) ? 32'd4 : ex_imm;
  reg [31:0] ex_alu_r;
  always @(*) begin
    case (ex_alu_op)
      ALU_ADD:  ex_alu_r = ex_alu_a + ex_alu_b;
      ALU_SUB:  ex_alu_r = ex_alu_a - ex_alu_b;
      ALU_SLL:  ex_alu_r = ex_alu_a << ex_alu_b[4:0];
      ALU_SLT:  ex_alu_r = {31'b0, $signed(ex_alu_a) < $signed(ex_alu_b)};
      ALU_SLTU: ex_alu_r = {31'b0, ex_alu_a < ex_alu_b};
      ALU_XOR:  ex_alu_r = ex_alu_a ^ ex_alu_b;
      ALU_SRL:  ex_alu_r = ex_alu_a >> ex_alu_b[4:0];
      ALU_SRA:  ex_alu_r = $signed(ex_alu_a) >>> ex_alu_b[4:0];
      ALU_OR:   ex_alu_r = ex_alu_a | ex_alu_b;
      ALU_AND:  ex_alu_r = ex_alu_a & ex_alu_b;
      default:  ex_alu_r = 32'b0;
    endcase
  end
  wire [31:0] ex_result = ex_alu_r;

  // branch / jump resolution in EX
  reg ex_branch_taken;
  always @(*) begin
    case (ex_f3)
      3'b000: ex_branch_taken = (ex_rs1 == ex_rs2);
      3'b001: ex_branch_taken = (ex_rs1 != ex_rs2);
      3'b100: ex_branch_taken = ($signed(ex_rs1) <  $signed(ex_rs2));
      3'b101: ex_branch_taken = ($signed(ex_rs1) >= $signed(ex_rs2));
      3'b110: ex_branch_taken = (ex_rs1 <  ex_rs2);
      3'b111: ex_branch_taken = (ex_rs1 >= ex_rs2);
      default: ex_branch_taken = 1'b0;
    endcase
  end

  wire [31:0] ex_br_a   = ex_is_jalr ? ex_rs1 : ex_pc;
  wire [31:0] ex_br_sum = ex_br_a + ex_imm;
  wire ex_redirect = ex_valid && ((ex_is_branch && ex_branch_taken) ||
                                  ex_is_jal || ex_is_jalr);
  wire [31:0] ex_redirect_target = ex_is_jalr ? (ex_br_sum & ~32'h1) : ex_br_sum;
`ifndef SYNTHESIS
  wire [31:0] ex_next_pc_w = ex_redirect ? ex_redirect_target : (ex_pc + 32'd4);
`endif

  // ---------------- ID forwarding ----------------
  wire ex_fwd = ex_valid && ex_reg_wen && (ex_rd != 4'd0);
  wire m_fwd  = m_valid && m_reg_wen && (m_rd != 4'd0) &&
                (!m_is_load || mem_done);
  wire ex_m1 = ex_fwd && (ex_rd == rs1_id);
  wire ex_m2 = ex_fwd && (ex_rd == rs2_id);
  wire m_m1  = m_fwd  && (m_rd  == rs1_id);
  wire m_m2  = m_fwd  && (m_rd  == rs2_id);

  wire [31:0] rf_rs1, rf_rs2;
  wire [31:0] id_rs1_val = (ex_m1 && !ex_is_load) ? ex_result :
                           (m_m1 ? m_wb_data : rf_rs1);
  wire [31:0] id_rs2_val = (ex_m2 && !ex_is_load) ? ex_result :
                           (m_m2 ? m_wb_data : rf_rs2);

  // ---------------- hazards / flow ----------------
  wire ex_load_use = id_valid && ex_is_load && ex_fwd &&
      ((uses_rs1 && ex_rd == rs1_id) ||
       (uses_rs2 && ex_rd == rs2_id));
  wire m_load_pending = m_valid && m_is_load && m_reg_wen &&
                        (m_rd != 4'd0) && !mem_done;
  wire m_load_use = id_valid && m_load_pending &&
      ((uses_rs1 && m_rd == rs1_id) ||
       (uses_rs2 && m_rd == rs2_id));
  wire id_hazard = ex_load_use || m_load_use;

  wire id_is_serial = is_csr || is_ecall || is_ebreak || is_mret || is_fencei;
  wire id_serial_go = id_valid && id_is_serial && adv && !id_hazard &&
                      !ex_valid && !m_valid && (!is_fencei || fetch_idle);
  wire [31:0] serial_target = is_ecall ? mtvec : is_mret ? mepc : (id_pc + 32'd4);

  wire id_issue = id_valid && !id_hazard && !id_is_serial && adv && !ex_redirect;
  assign fetch_accept = fetch_ready && adv && (!id_valid || id_issue) &&
                        !ex_redirect && !id_serial_go;

  // ---------------- register file ----------------
  // Keep rf_wen asserted for x0 as well; RegisterFile owns the x0 write mask.
  wire csr_wb = id_serial_go && is_csr;
  wire [3:0] rf_waddr  = csr_wb ? rd_id : m_rd;
  wire [31:0] rf_wdata = csr_wb ? csr_rdata : m_wb_data;
  wire rf_wen = (m_valid && m_reg_wen && m_done_wb) || csr_wb;

  RegisterFile u_rf(
    .clk(clk), .rst(rst),
    .wdata(rf_wdata), .waddr({1'b0, rf_waddr}), .wen(rf_wen),
    .raddr1(rs1_5), .rdata1(rf_rs1),
    .raddr2(rs2_5), .rdata2(rf_rs2),
    .a0_value(a0_value)
  );

  // ---------------- pipeline registers ----------------
  always @(posedge clk) begin
    if (rst) begin
      pc       <= RESET_PC;
      id_valid <= 1'b0;
      ex_valid <= 1'b0;
      m_valid  <= 1'b0;
    end else if (adv) begin
      m_valid        <= ex_valid;
      m_result       <= ex_result;
      m_store_data   <= ex_rs2;
      m_rd           <= ex_rd;
      m_f3           <= ex_f3;
      m_reg_wen      <= ex_reg_wen;
      m_is_load      <= ex_is_load;
      m_is_store     <= ex_is_store;
`ifndef SYNTHESIS
      m_branch_taken <= ex_branch_taken;
      m_pc           <= ex_pc;
      m_inst         <= ex_inst;
      m_next_pc      <= ex_next_pc_w;
`endif

      ex_valid       <= id_issue;
      if (id_issue) begin
        ex_pc           <= id_pc;
        ex_rs1          <= id_rs1_val;
        ex_rs2          <= id_rs2_val;
        ex_imm          <= imm_sel;
        ex_rd           <= rd_id;
        ex_f3           <= f3;
        ex_alu_op       <= alu_op;
        ex_a_sel        <= alu_a_sel;
        ex_b_sel        <= alu_b_sel;
        ex_reg_wen      <= reg_wen;
        ex_is_load      <= is_load;
        ex_is_store     <= is_store;
        ex_is_branch    <= is_branch;
        ex_is_jal       <= is_jal;
        ex_is_jalr      <= is_jalr;
`ifndef SYNTHESIS
        ex_inst         <= id_inst;
        ex_next_pc      <= ex_next_pc_w;
`endif
      end

      if (ex_redirect) begin
        pc <= ex_redirect_target;
        id_valid <= 1'b0;
      end else if (id_serial_go) begin
        pc <= serial_target;
        id_valid <= 1'b0;
      end else if (fetch_accept) begin
        id_valid <= 1'b1;
        id_pc    <= pc;
        id_inst  <= fetch_inst;
        pc       <= pc + 32'd4;
      end else if (id_issue) begin
        id_valid <= 1'b0;
      end
    end
  end

  // ---------------- outputs ----------------
  assign fetch_pc  = pc;
  assign fetch_req = !rst && adv && (!id_valid || id_issue) &&
                     !(id_valid && id_is_serial && !id_serial_go);

  assign mem_valid    = m_valid && (m_is_load || m_is_store);
  assign mem_wen      = m_is_store;
  assign mem_f3       = m_f3;
  assign mem_addr     = m_result;
  assign mem_wdata    = m_store_data;
  assign mem_is_load  = m_is_load;
  assign mem_is_store = m_is_store;

  assign csr_addr  = id_inst[31:20];
  assign csr_wdata = is_csrrw ? rf_rs1 : (rf_rs1 | csr_rdata);
  assign csr_wen   = id_serial_go &&
                     (is_csrrw || (is_csrrs && (rs1_5 != 5'd0)));
  assign csr_ecall = id_serial_go && is_ecall;
  assign csr_pc    = id_pc;

  assign icache_flush = id_serial_go && is_fencei;

  assign cur_pc   = pc;
  assign cur_inst = id_inst;

`ifndef SYNTHESIS
  assign retire = (m_valid && m_done_wb) || id_serial_go;
  assign retire_pc = id_serial_go ? id_pc : m_pc;
  assign retire_inst = id_serial_go ? id_inst : m_inst;
  assign retire_next_pc = id_serial_go ? serial_target : m_next_pc;
  assign retire_addr = m_result;
  assign retire_wdata = m_is_store ? m_store_data : mem_rdata;
  assign retire_is_mem = m_valid && (m_is_load || m_is_store);
  assign retire_is_store = m_valid && m_is_store;
  assign retire_branch_taken = m_valid && m_branch_taken;
`endif

endmodule
