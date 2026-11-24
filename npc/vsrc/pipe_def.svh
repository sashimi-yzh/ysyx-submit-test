typedef struct packed {
  logic [31:0] pc;
  logic [31:0] inst;
  logic        cycle_done;
} if_id_packet_t;

typedef struct packed {
  logic [31:0] pc;
`ifndef SYNTHESIS
  logic [31:0] inst;
`endif
  logic [6:0]  opcode;
  logic [2:0]  func3;
  logic [6:0]  func7;
  logic [31:0] imm;
  logic [31:0] rs1;
  logic [31:0] rs2;
  logic [3:0]  rd_idx;
  logic [11:0] csr_idx;
  logic [31:0] csr_rdata;
  logic        ecall;
  logic        mret;
  logic        fencei;
  logic        cycle_done;
} id_ex_packet_t;

typedef struct packed {
`ifndef SYNTHESIS
  logic [31:0] pc;
  logic [31:0] inst;
`endif
  logic        reg_wen;
  logic        mem_w;
  logic        mem_r;         // whether read mem
  logic        mem_sign_ext;  // whether sign extend for mem read
  logic [2:0]  mem_mask;      // mem width for read/write
  logic [2:0]  func3;
  logic [31:0] result;
  logic [31:0] rs2;
  logic [3:0]  rd_idx;
  logic [11:0] csr_idx;
  logic [31:0] csr_rdata;
  logic        ecall;
  logic        mret;
  logic        fencei;
  logic        branch;        // whether branch instruction
  logic        jump;          // whether JAL/JALR
  logic        wb_from_mem;   // 1 for mem, 0 for ALU
  logic        csr_wen;       // CSR write enable
  logic [31:0] npc;
  logic        cycle_done;
} ex_ls_packet_t;


typedef struct packed {
`ifndef SYNTHESIS
  logic [31:0] pc;
  logic [31:0] inst;
`endif
  logic        reg_wen;
  logic [2:0]  func3;
  logic [31:0] wdata;
  logic [3:0]  rd_idx;
  logic [11:0] csr_idx;
  logic [31:0] csr_rdata;
  logic        ecall;
  logic        mret;
  logic        fencei;
  logic        branch;
  logic        jump;
  logic        csr_wen;
  logic [31:0] npc;
  logic        cycle_done;
} ls_wb_packet_t;
