//lui
`define ysyx_24110012_OPT_U_LUI 7'b0110111

//auipc
`define ysyx_24110012_OPT_U_AUIPC 7'b0010111

//jal
`define ysyx_24110012_OPT_J_JAL 7'b1101111

//jalr
`define ysyx_24110012_OPT_I_JALR 7'b1100111

//beq, bne, blt, bge, bltu, bgeu
`define ysyx_24110012_OPT_B 7'b1100011

//lb, lh, lw, lbu, lhu
`define ysyx_24110012_OPT_I_LOAD 7'b0000011

//sb, sh, sw
`define ysyx_24110012_OPT_S_STORE 7'b0100011

//addi, slti, sltiu, xori, ori, andi, slli，srli, srai
`define ysyx_24110012_OPT_I_LOGIC 7'b0010011

//add, sub, sll, slt, sltu, xor, srl, sra, or, and
`define ysyx_24110012_OPT_R_LOGIC 7'b0110011

//fence, fence.i
`define ysyx_24110012_OPT_I_FENCE 7'b0001111

//ecall, ebreak, csrrw, csrrs, csrrc, csrrwi, csrrsi, csrrci
`define ysyx_24110012_OPT_I_EC 7'b1110011

`define ysyx_24110012_FUNC_ADD 4'b0000
`define ysyx_24110012_FUNC_SUB 4'b0001
`define ysyx_24110012_FUNC_AND 4'b0010
`define ysyx_24110012_FUNC_OR 4'b0011
`define ysyx_24110012_FUNC_XOR 4'b0100
`define ysyx_24110012_FUNC_NOR 4'b0101
`define ysyx_24110012_FUNC_LESS 4'b0110
`define ysyx_24110012_FUNC_LESS_SIGN 4'b0111
`define ysyx_24110012_FUNC_BGE 4'b1000
`define ysyx_24110012_FUNC_BGE_SIGN 4'b1001
`define ysyx_24110012_FUNC_EQ 4'b1010
`define ysyx_24110012_FUNC_NEQ 4'b1011
`define ysyx_24110012_FUNC_SH_L 4'b1100
`define ysyx_24110012_FUNC_SH_R 4'b1101
`define ysyx_24110012_FUNC_SH_AR 4'b1110

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
`ifndef SYNTHESIS
  logic [31:0] npc;           // only for difftest (done_npc)
`endif
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
//  logic        jump;
  logic        csr_wen;
`ifndef SYNTHESIS
  logic [31:0] npc;           // only for difftest (done_npc)
`endif
  logic        cycle_done;
} ls_wb_packet_t;

module ysyx_24110012_GPR_CSR_File #(
  parameter GPR_ADDR_WIDTH     = 1,
  parameter GPR_DATA_WIDTH     = 1,
  parameter CSR_ADDR_WIDTH     = 1,
  parameter CSR_DATA_WIDTH     = 1
) (
  input clk,
  input reset,

  input rf_wen,
  input [GPR_ADDR_WIDTH-1:0] rd_idx,
  input [GPR_DATA_WIDTH-1:0] rd,
  input [GPR_ADDR_WIDTH-1:0] rs1_idx,
  rs2_idx,
  output [GPR_DATA_WIDTH-1:0] rs1,
  rs2,
  rdata_x,

  input csr_wen,
  input [CSR_ADDR_WIDTH-1:0] csr_r_idx,
  input [CSR_ADDR_WIDTH-1:0] csr_w_idx,
  input [CSR_DATA_WIDTH-1:0] csr_wdata,
  output reg [CSR_DATA_WIDTH-1:0] csr_rdata
);

  // GPR registers: x0 is hard-wired to zero, so only x1..x15 are stored
  reg [GPR_DATA_WIDTH-1:0] rf[2**GPR_ADDR_WIDTH-1:1];

  // write: CSR instructions also write rd through rf_wen (reg_wen set in EXU)
  always @(posedge clk) begin
    if (rf_wen && (rd_idx != {GPR_ADDR_WIDTH{1'b0}})) begin
      rf[rd_idx] <= rd;
    end
  end

  // read: WB->ID same-cycle forwarding is handled by the hazard unit (rs*_wb_hit)
  assign rs1 = (rs1_idx == {GPR_ADDR_WIDTH{1'b0}}) ? {GPR_DATA_WIDTH{1'b0}} : rf[rs1_idx];
  assign rs2 = (rs2_idx == {GPR_ADDR_WIDTH{1'b0}}) ? {GPR_DATA_WIDTH{1'b0}} : rf[rs2_idx];
  assign rdata_x = rf[10];


  // CSR registers
  parameter CSR_MVENDORID = 12'hF11;
  parameter CSR_MARCHID = 12'hF12;
  parameter CSR_MSTATUS = 12'h300;
  parameter CSR_MTVEC = 12'h305;
  parameter CSR_MEPC = 12'h341;
  parameter CSR_MCAUSE = 12'h342;
  parameter CSR_MSTATUS_DIFF = 32'h00001800;
  parameter [CSR_DATA_WIDTH-1:0] CSR_MVENDORID_VAL = 32'h79737978;
  parameter [CSR_DATA_WIDTH-1:0] CSR_MARCHID_VAL = 32'h24110012;

  reg [CSR_DATA_WIDTH-1:0] csr_mstatus;
  reg [CSR_DATA_WIDTH-1:0] csr_mtvec;
  reg [CSR_DATA_WIDTH-1:0] csr_mepc;
  reg [CSR_DATA_WIDTH-1:0] csr_mcause;

  always @(posedge clk) begin
    if (reset) begin
      csr_mstatus <= CSR_MSTATUS_DIFF;
    end else begin
      if (csr_wen) begin
        case (csr_w_idx)
          CSR_MSTATUS: begin
            csr_mstatus <= csr_wdata;
          end
          CSR_MTVEC: csr_mtvec <= csr_wdata;
          CSR_MEPC: begin
            csr_mepc   <= csr_wdata;
            csr_mcause <= {28'b0, 4'b1011};  // set mcause to 1 for ecall
          end
          CSR_MCAUSE: begin
            csr_mcause <= csr_wdata;
          end
          default:   ;
        endcase
      end
    end
  end

  always @(*) begin
    case (csr_r_idx)
      CSR_MSTATUS:   csr_rdata = CSR_MSTATUS_DIFF;
      CSR_MTVEC:     csr_rdata = (csr_wen && (csr_w_idx == CSR_MTVEC)) ? csr_wdata : csr_mtvec;
      CSR_MEPC:      csr_rdata = (csr_wen && (csr_w_idx == CSR_MEPC)) ? csr_wdata : csr_mepc;
      CSR_MCAUSE:    csr_rdata = (csr_wen && (csr_w_idx == CSR_MCAUSE)) ? csr_wdata : csr_mcause;
      CSR_MVENDORID: csr_rdata = CSR_MVENDORID_VAL;
      CSR_MARCHID:   csr_rdata = CSR_MARCHID_VAL;
      default:       csr_rdata = {CSR_DATA_WIDTH{1'b0}};
    endcase
  end



`ifndef __ICARUS__
`ifndef SYNTHESIS
  // DPI-C function to access rf
  export "DPI-C" function get_gpr_npc;

  // Task to provide rf value to C++
  function int get_gpr_npc(input int index);
    if (index == 0) begin
      return 0;  // return 0 for x0
    end else if (index >= 0 && index < 2 ** GPR_ADDR_WIDTH) begin
      return rf[index];
    end else begin
      return 0;  // Return 0 for invalid index
    end
  endfunction

  // DPI-C function to access csr
  export "DPI-C" function get_csr_npc;

  // Task to provide csr value to C++
  function int get_csr_npc(input int index);
    case (index)
      0:       return csr_mstatus;
      1:       return csr_mtvec;
      2:       return csr_mepc;
      3:       return csr_mcause;
      default: return 0;
    endcase
  endfunction
`endif
`endif

endmodule
//`include "opcode_defines.v"

module ysyx_24110012_adder (
  input  wire [31:0] a,     // operator 1
  input  wire [31:0] b,     // operator 2
  input  wire        cin,
  output wire [31:0] sum,   // result
  output wire        carry  // carry out
);
  assign {carry, sum} = {1'b0, a} + {1'b0, b} + {32'b0, cin};
endmodule

module ysyx_24110012_shifter (
  input [3:0] shift_type,
  input wire [31:0] shift_input,
  input wire [31:0] shift_count,
  output wire [31:0] shift_output
);
  // Only ONE right shifter is used for SLL / SRL / SRA:
  //   SLL: a << n == reverse( reverse(a) >> n )   (bit reverse is just wiring, no gates)
  //   SRA: put sign bit on top of a 33-bit value, then arithmetic right shift
  //   SRL: top bit is 0, so the same 33-bit shift becomes a logical shift
  wire is_left  = (shift_type == `ysyx_24110012_FUNC_SH_L);
  wire is_arith = (shift_type == `ysyx_24110012_FUNC_SH_AR);

  wire [31:0] input_rev;   // shift_input with bit order reversed
  wire [31:0] result_rev;  // right_result with bit order reversed

  wire [31:0] right_in     = is_left ? input_rev : shift_input;
  wire [32:0] right_ext    = {is_arith & shift_input[31], right_in};  // bit32 = fill bit
  wire [32:0] right_shift  = $signed(right_ext) >>> shift_count[4:0];
  wire [31:0] right_result = right_shift[31:0];

  // bit reverse: pure wiring. Use separate assigns (not one always block) so the
  // simulator does not see a false combinational loop through input_rev/result_rev.
  genvar g;
  generate
    for (g = 0; g < 32; g = g + 1) begin : gen_bit_rev
      assign input_rev[g]  = shift_input[31-g];
      assign result_rev[g] = right_result[31-g];
    end
  endgenerate

  assign shift_output = is_left ? result_rev : right_result;
endmodule

module ysyx_24110012_logicer (
  input [3:0] logic_type,
  input [31:0] a,
  input [31:0] b,
  output reg [31:0] logic_out
);

  always @(*) begin
    logic_out = 32'b0;  // Default output
    if (logic_type == `ysyx_24110012_FUNC_AND) begin  // AND
      logic_out = a & b;
    end else if (logic_type == `ysyx_24110012_FUNC_OR) begin  // OR
      logic_out = a | b;
    end else if (logic_type == `ysyx_24110012_FUNC_XOR) begin  // XOR
      logic_out = a ^ b;
    end else if (logic_type == `ysyx_24110012_FUNC_NOR) begin  // NOR
      logic_out = ~(a | b);
    end
  end
endmodule

//module ysyx_24110012_comparator (
//     input  [3:0] cmp_type,      // compare type
//     input wire [31:0] a,        // op1
//     input wire [31:0] b,        // op2
//     output reg [31:0] cmp_out   // result of comparison
// );
//     // use extra bit [32] for overflow handling
//     // this will happen when rs1 is 0x0, and rs2 is 0x80000000
//     // in this case, the cmp_out will overflow to 0x80000000, which is negative
//     reg signed [32:0] diff;
//     reg cmp_imter;

//     always @(*) begin
//         diff = $signed(a) - $signed(b);
//         case (cmp_type)
//             `ysyx_24110012_FUNC_EQ: cmp_imter = (diff == 0);      // BEQ: rs1 == rs2
//             `ysyx_24110012_FUNC_NEQ: cmp_imter = (diff != 0);      // BNE: rs1 != rs2
//             `ysyx_24110012_FUNC_LESS_SIGN: cmp_imter = (diff < 0);       // BLT: rs1 < rs2 (signed)
//             `ysyx_24110012_FUNC_LESS: cmp_imter = (a < b);      // BLTU: rs1 < rs2 (unsigned)
//             `ysyx_24110012_FUNC_BGE_SIGN: cmp_imter = (diff >= 0);       // BGE: rs1 >= rs2 (signed)
//             `ysyx_24110012_FUNC_BGE: cmp_imter = (a >= b);      // BGEU: rs1 >= rs2 (unsigned)
//             default: cmp_imter = 1'b0;            // Default case
//         endcase
//         cmp_out = {31'b0, cmp_imter}; // Set the output to 32 bits
//     end
// endmodule

module ysyx_24110012_comparator (
  input       [ 3:0] cmp_type,  // compare type
  input  wire [31:0] a,         // op A
  input  wire [31:0] b,         // op B
  input  wire [31:0] sub_sum,   // A - B = A + ~B + 1, from the ALU's shared adder
  input  wire        sub_carry, // carry-out of A + ~B + 1, from the ALU's shared adder
  output reg  [31:0] cmp_out    // Comparison result (1 for True, 0 for False)
);

  // 1. Subtraction is done by the ALU's shared adder (no private subtractor here)

  // 2. Extract status flags

  // Zero Flag: High if the subtraction result is exactly zero
  wire zero = (sub_sum == 32'b0);

  // Unsigned Less Than Flag:
  // For A + ~B + 1, if A < B, no carry-out is generated (i.e., sub_carry == 0)
  wire unsigned_lt = ~sub_carry;

  // Signed Less Than Flag:
  // Requires overflow correction.
  // Overflow occurs when operands A and B have different signs,
  // and the result sign differs from operand A's sign.
  wire sign_a = a[31];
  wire sign_b = b[31];
  wire sign_res = sub_sum[31];
  wire overflow = (sign_a ^ sign_b) & (sign_res ^ sign_a);

  // Signed Less Than: Negative result without overflow, or positive result with overflow

  wire signed_lt = sign_res ^ overflow;

  // 3. Select output based on comparison type

  always @(*) begin
    case (cmp_type)
      `ysyx_24110012_FUNC_EQ:        cmp_out = {31'b0, zero};  // A == B
      `ysyx_24110012_FUNC_NEQ:       cmp_out = {31'b0, ~zero};  // A != B
      `ysyx_24110012_FUNC_LESS:      cmp_out = {31'b0, unsigned_lt};  // A < B  (unsigned)
      `ysyx_24110012_FUNC_BGE:       cmp_out = {31'b0, ~unsigned_lt};  // A >= B (unsigned)
      `ysyx_24110012_FUNC_LESS_SIGN: cmp_out = {31'b0, signed_lt};  // A < B  (signed)
      `ysyx_24110012_FUNC_BGE_SIGN:  cmp_out = {31'b0, ~signed_lt};  // A >= B (signed)
      default:                       cmp_out = 32'b0;
    endcase
  end
endmodule

module ysyx_24110012_alu (
  input [3:0] alu_type,
  input [31:0] alu_p1,
  input [31:0] alu_p2,
  output reg [31:0] alu_out
);

  wire [31:0] add_out;
  reg [31:0] logic_out;
  reg [31:0] shift_out;
  wire [31:0] cmp_out;
  wire add_carry;

  // One shared adder: a + b (ADD) or a - b = a + ~b + 1 (SUB and all compares).
  // For logic/shift types the adder output is not selected, so is_sub is don't-care.
  wire is_sub = (alu_type != `ysyx_24110012_FUNC_ADD);

  ysyx_24110012_adder my_adder (
  .a    (alu_p1),
  .b    (alu_p2 ^ {32{is_sub}}),  // invert b for subtraction
  .cin  (is_sub),                 // +1 for subtraction
  .sum  (add_out),
  .carry(add_carry)
  );

  ysyx_24110012_comparator u_comparator (
  .cmp_type (alu_type),
  .a        (alu_p1),
  .b        (alu_p2),
  .sub_sum  (add_out),
  .sub_carry(add_carry),
  .cmp_out  (cmp_out)
  );

  ysyx_24110012_logicer u_logicer (
  .logic_type(alu_type),
  .a         (alu_p1),
  .b         (alu_p2),
  .logic_out (logic_out)
  );

  ysyx_24110012_shifter u_shifter (
  .shift_type  (alu_type),
  .shift_input (alu_p1),
  .shift_count (alu_p2),
  .shift_output(shift_out)
  );

  always @(*) begin
    case (alu_type)
      `ysyx_24110012_FUNC_ADD: alu_out = add_out;
      `ysyx_24110012_FUNC_SUB: alu_out = add_out;
      `ysyx_24110012_FUNC_AND, `ysyx_24110012_FUNC_OR, `ysyx_24110012_FUNC_XOR,
      `ysyx_24110012_FUNC_NOR:
      alu_out = logic_out;
      `ysyx_24110012_FUNC_EQ, `ysyx_24110012_FUNC_NEQ, `ysyx_24110012_FUNC_LESS,
      `ysyx_24110012_FUNC_LESS_SIGN, `ysyx_24110012_FUNC_BGE, `ysyx_24110012_FUNC_BGE_SIGN:
      alu_out = cmp_out;
      `ysyx_24110012_FUNC_SH_L, `ysyx_24110012_FUNC_SH_R, `ysyx_24110012_FUNC_SH_AR:
      alu_out = shift_out;
      default: alu_out = 32'b0;
    endcase
  end
endmodule
//`define NO_FORWARD

module ysyx_24110012_hazard #(
  parameter integer ADDR_WIDTH = 4,
  parameter integer DATA_WIDTH = 32
) (
  input wire [ADDR_WIDTH-1:0] rs1_idx,
  input wire [ADDR_WIDTH-1:0] rs2_idx,
  input wire [DATA_WIDTH-1:0] rs1_rf,
  input wire [DATA_WIDTH-1:0] rs2_rf,

  input wire ex_valid,
  input wire ex_wen,
  input wire ex_is_load,
  input wire [ADDR_WIDTH-1:0] ex_rd_idx,
  input wire [DATA_WIDTH-1:0] ex_wdata,

  input wire ls_valid,
  input wire ls_wen,
  input wire ls_is_load,
  input wire [ADDR_WIDTH-1:0] ls_rd_idx,
  input wire [DATA_WIDTH-1:0] ls_wdata,

  input wire wb_valid,
  input wire wb_wen,
  input wire [ADDR_WIDTH-1:0] wb_rd_idx,
  input wire [DATA_WIDTH-1:0] wb_wdata,

  output wire [DATA_WIDTH-1:0] rs1_fwd,
  output wire [DATA_WIDTH-1:0] rs2_fwd,
  output wire raw_stall
);

  wire
  rs1_ex_hit = ex_valid && ex_wen && (ex_rd_idx != {ADDR_WIDTH{1'b0}}) && (ex_rd_idx == rs1_idx);
  wire
  rs2_ex_hit = ex_valid && ex_wen && (ex_rd_idx != {ADDR_WIDTH{1'b0}}) && (ex_rd_idx == rs2_idx);

  wire
  rs1_ls_hit = ls_valid && ls_wen && (ls_rd_idx != {ADDR_WIDTH{1'b0}}) && (ls_rd_idx == rs1_idx);
  wire
  rs2_ls_hit = ls_valid && ls_wen && (ls_rd_idx != {ADDR_WIDTH{1'b0}}) && (ls_rd_idx == rs2_idx);

  wire
  rs1_wb_hit = wb_valid && wb_wen && (wb_rd_idx != {ADDR_WIDTH{1'b0}}) && (wb_rd_idx == rs1_idx);
  wire
  rs2_wb_hit = wb_valid && wb_wen && (wb_rd_idx != {ADDR_WIDTH{1'b0}}) && (wb_rd_idx == rs2_idx);

  // For the default forward-enabled pipeline, only load-use hazards need a stall because
  // EX/LS load data is not ready before memory response arrives.
  // For the no-forward baseline, any producer still in EX/LS is not yet visible in RF, so the
  // dependent instruction must stall as soon as it hits.
`ifdef NO_FORWARD
  assign raw_stall = (rs1_ex_hit || rs2_ex_hit || rs1_ls_hit || rs2_ls_hit);
`else
  assign raw_stall = (rs1_ex_hit && ex_is_load) || (rs2_ex_hit && ex_is_load) ||
  (rs1_ls_hit && ls_is_load) || (rs2_ls_hit && ls_is_load);
`endif

`ifdef NO_FORWARD
  assign rs1_fwd = rs1_rf;
  assign rs2_fwd = rs2_rf;
`else
  assign rs1_fwd = rs1_ex_hit ? ex_wdata : rs1_ls_hit ? ls_wdata : rs1_wb_hit ? wb_wdata : rs1_rf;

  assign rs2_fwd = rs2_ex_hit ? ex_wdata : rs2_ls_hit ? ls_wdata : rs2_wb_hit ? wb_wdata : rs2_rf;
`endif

endmodule

//`include "opcode_defines.v"
module ysyx_24110012_idu #(
  parameter ADDR_WIDTH = 4
) (
  input [31:0] ifu_idu_inst,
  input [31:0] ifu_idu_pc,
  input ifu_idu_cycle_done,

  input  wire ifu_idu_valid,
  output wire idu_ifu_ready,

  output reg [ADDR_WIDTH-1:0] idu_rf_rs1_idx,
  output reg [ADDR_WIDTH-1:0] idu_rf_rs2_idx,
  output reg [11:0] idu_rf_csr_idx,
  input wire [31:0] rf_idu_rs1,
  input wire [31:0] rf_idu_rs2,
  input [31:0] rf_idu_csr_rdata,

  output reg [31:0] idu_exu_pc,
  output reg [6:0] idu_exu_opcode,
  output reg [2:0] idu_exu_func3,
  output reg [6:0] idu_exu_func7,
  output reg [31:0] idu_exu_imm,
  output reg [31:0] idu_exu_rs1,
  output reg [31:0] idu_exu_rs2,
  output reg [3:0] idu_exu_rd_idx,
  output reg [11:0] idu_exu_csr_idx,
  output reg [31:0] idu_exu_csr_rdata,
  output reg idu_exu_ecall,
  output reg idu_exu_mret,
  output reg idu_exu_fencei,
  output reg idu_exu_cycle_done,

  output wire idu_exu_valid,
  input  wire exu_idu_ready
);

  parameter MRET = 32'h30200073;
  parameter EBREAK = 32'h00100073;
  parameter ECALL = 32'h00000073;
  parameter FENCEI = 32'h0000100f;

  parameter CSR_MEPC = 12'h341;
  parameter CSR_MTVEC = 12'h305;

  assign idu_exu_pc        = ifu_idu_pc;
  assign idu_exu_rs1       = rf_idu_rs1;
  assign idu_exu_rs2       = rf_idu_rs2;
  assign idu_exu_csr_rdata = rf_idu_csr_rdata;

  // valid/ready
  assign idu_exu_valid     = ifu_idu_valid;
  assign idu_ifu_ready     = exu_idu_ready;  // only combinational logic here

  reg [2:0] imm_type;

  always @(*) begin
    idu_exu_opcode = ifu_idu_inst[6:0];
    idu_rf_rs1_idx = ifu_idu_inst[18:15];  // rs1 index where only support 16 regs
    idu_rf_rs2_idx =
    ifu_idu_inst[23:20];  // rs2 index（only R/S/B type）where only support 16 regs
    idu_exu_rd_idx = ifu_idu_inst[10:7];  // rd index（R/I/U/J type）
    idu_exu_func3 = ifu_idu_inst[14:12];  // func3 for R/I/S/B
    idu_exu_func7 = ifu_idu_inst[31:25];  // func7 for I type
    idu_rf_csr_idx = (ifu_idu_inst == MRET) ? CSR_MEPC : (ifu_idu_inst == ECALL) ? CSR_MTVEC :
    ifu_idu_inst[31:20];  // CSR address for CSR instructions
    idu_exu_csr_idx = ifu_idu_inst[31:20];  // pass CSR address to EXU
  end

  always @(*) begin
    imm_type = 3'b000;
    case (idu_exu_opcode)
      `ysyx_24110012_OPT_R_LOGIC:                           imm_type = 3'b000;  // R-Type
      `ysyx_24110012_OPT_I_LOGIC:                           imm_type = 3'b000;  // I-Type
      `ysyx_24110012_OPT_S_STORE:                           imm_type = 3'b001;  // S-Type
      `ysyx_24110012_OPT_B:                                 imm_type = 3'b010;  // B-Type
      `ysyx_24110012_OPT_U_LUI, `ysyx_24110012_OPT_U_AUIPC: imm_type = 3'b011;  // U-Type
      `ysyx_24110012_OPT_J_JAL:                             imm_type = 3'b100;  // J-Type
      default:                                              imm_type = 3'b000;  // Default value
    endcase
  end

  // imm generation
  always @(*) begin
    case (imm_type)
      3'b000: begin  // I-Type
        if (idu_exu_opcode == `ysyx_24110012_OPT_I_LOGIC &&
            (idu_exu_func3 == 3'b001 || idu_exu_func3 == 3'b101)) begin
          // For shift instructions (slli, srli, srai)
          idu_exu_imm = {27'b0, ifu_idu_inst[24:20]};  // only use shamt field
        end else begin
          // For other I-Type instructions
          idu_exu_imm = {{20{ifu_idu_inst[31]}}, ifu_idu_inst[31:20]};
        end
      end
      3'b001:
      idu_exu_imm = {
        {20{ifu_idu_inst[31]}}, ifu_idu_inst[31:25], ifu_idu_inst[11:7]
      };  // S-Type（sw, sb, sh）
      3'b010:
      idu_exu_imm = {
        {19{ifu_idu_inst[31]}},
        ifu_idu_inst[31],
        ifu_idu_inst[7],
        ifu_idu_inst[30:25],
        ifu_idu_inst[11:8],
        1'b0
      };  // B-Type（beq, bne, blt, bge）
      3'b011: idu_exu_imm = {ifu_idu_inst[31:12], 12'b0};  // U-Type（lui, auipc）
      3'b100:
      idu_exu_imm = {
        {12{ifu_idu_inst[31]}}, ifu_idu_inst[19:12], ifu_idu_inst[20], ifu_idu_inst[30:21], 1'b0
      };  // J-Type（jal）
      default: idu_exu_imm = 32'b0;
    endcase
  end

  // handle ebreak
  always @(*) begin
    idu_exu_ecall      = 1'b0;  // default no ecall
    idu_exu_mret       = 1'b0;
    idu_exu_fencei     = 1'b0;
    idu_exu_cycle_done = ifu_idu_cycle_done;
    if (ifu_idu_inst == EBREAK) begin
      // mark cycle done for ebreak; trap handling is retired in WBU
      idu_exu_cycle_done = 1'b1;
    end else if (ifu_idu_inst == ECALL) begin
      idu_exu_ecall = 1'b1;  // ecall instruction flag
    end else if (ifu_idu_inst == MRET) begin
      idu_exu_mret = 1'b1;  // mret instruction flag
    end else if (ifu_idu_inst == FENCEI) begin
      idu_exu_fencei = 1'b1;  // fence.i instruction flag
    end
    // others handled by 1st always block
  end

endmodule
//`define LFSR_SIM

module ysyx_24110012_ifu (
  input wire clk,
  input wire reset,
  input wire cycle_done,


  output reg [31:0] ifu_idu_pc,
  output reg [31:0] ifu_idu_inst,
  output reg ifu_idu_cycle_done,

  output reg ifu_idu_valid,
  input  wire idu_ifu_ready,

  input wire [31:0] wbu_ifu_npc,
  input wire wbu_redirect,
  input wire flush,

  // AR
  output reg [31:0] araddr,
  output reg arvalid,
  output reg [2:0] arsize,
  input wire arready,
  // R
  input wire [31:0] rdata,
  input wire rvalid,
  output reg rready,

  // AW
  output reg [31:0] awaddr,
  output reg awvalid,
  output reg [2:0] awsize,
  input wire awready,

  // W
  output reg [31:0] wdata,
  output reg [3:0] wstrb,
  output reg wvalid,
  input wire wready,

  // B
  input wire [1:0] bresp,
  input wire bvalid,
  output wire bready
);

  parameter RESET_PC_MROM = 32'h20000000;
  parameter RESET_PC_FLASH = 32'h30000000;
  parameter RESET_BASE = 32'h80000000;
`ifdef NPC
  parameter RESET_PC = RESET_BASE;  // Initial PC value
`else
  parameter RESET_PC = RESET_PC_FLASH;  // Initial PC value
`endif
  reg inst_fetch;
  reg [31:0] req_pc;

  assign awaddr  = 32'b0;
  assign awvalid = 1'b0;
  assign wdata   = 32'b0;
  assign wstrb   = 4'b0;
  assign wvalid  = 1'b0;
  assign bready  = 1'b0;
  assign awsize  = 3'b010;
  assign arsize  = 3'b010;

  reg redirect_q, flush_q;
  //reg [31:0] inflight_pc;

`ifndef __ICARUS__
`ifndef SYNTHESIS
  assert property (@(posedge clk) disable iff (reset) awready == 1'b0)
  else $error("AWR should be 0 in PC update module");
`endif
`endif

 assign araddr = req_pc;
 assign ifu_idu_pc = req_pc;
 assign ifu_idu_inst = rdata;

  localparam S_IDLE = 2'b00, S_AR = 2'b01, S_R = 2'b10, S_PUT = 2'b11;
  reg [1:0] state, next_state;

  always @(posedge clk) begin
    if (reset) begin
      state <= S_IDLE;
    end else begin
      state <= next_state;
    end
  end

  always @(*) begin
    case (state)
      S_IDLE: begin
        if (inst_fetch) begin
          next_state = S_AR;
        end else begin
          next_state = S_IDLE;
        end
      end
      S_AR: begin
        if (arvalid && arready) begin
          next_state = S_R;
        end else begin
          next_state = S_AR;
        end
      end
      S_R: begin
       if (rvalid && rready) begin
          next_state = S_PUT;
        end else begin
          next_state = S_R;
        end
      end
      S_PUT: begin
         if (wbu_redirect || flush || redirect_q || flush_q) begin
          next_state = S_IDLE;
        end else if (ifu_idu_valid && idu_ifu_ready) begin
          next_state = S_IDLE;
        end else begin
          next_state = S_PUT;
        end
      end
      default: next_state = S_IDLE;
    endcase
  end

  always @(posedge clk) begin
    if (reset) begin
      ifu_idu_valid <= 1'b0;
      arvalid       <= 1'b0;
      rready        <= 1'b0;
      req_pc        <= RESET_PC;
      inst_fetch    <= 1'b1;
      redirect_q    <= 1'b0;
      flush_q       <= 1'b0;
    end else begin
      case (next_state)
        S_IDLE: begin
          ifu_idu_valid <= 1'b0;
          arvalid       <= 1'b0;
          rready        <= 1'b0;
          inst_fetch    <= 1'b1;
          redirect_q    <= 1'b0;
          flush_q       <= 1'b0;
          if (wbu_redirect) begin
            req_pc <= wbu_ifu_npc;
          end else if (!flush && !flush_q && !redirect_q) begin
            req_pc <= req_pc + 4;
          end
        end
        S_AR: begin
          arvalid    <= 1'b1;
          inst_fetch <= 1'b0;
          if (wbu_redirect) begin
            redirect_q <= 1'b1;
            req_pc <= wbu_ifu_npc;
          end
          if (flush) begin
            flush_q <= 1'b1;
          end
        end
        S_R: begin
          arvalid <= 1'b0;
          if (rvalid) begin
            rready        <= 1'b1;
          end
          if (wbu_redirect) begin
            redirect_q <= 1'b1;
            req_pc     <= wbu_ifu_npc;
          end
          if (flush) begin
            flush_q <= 1'b1;
          end
        end
        S_PUT: begin
          if (!flush_q && !redirect_q && !wbu_redirect && !flush) begin
            ifu_idu_valid <= 1'b1;
          end
          if (wbu_redirect) begin
            redirect_q <= 1'b1;
            req_pc <= wbu_ifu_npc;
          end
        end
        default: begin
          ifu_idu_valid <= 1'b0;
          arvalid       <= 1'b0;
          rready        <= 1'b0;
          req_pc        <= RESET_PC;
          inst_fetch    <= 1'b1;
        end
      endcase
    end
  end

`ifndef __ICARUS__
`ifndef SYNTHESIS
  // Function to get PC value from C++
  export "DPI-C" function get_pc_npc;
  function int get_pc_npc();
    return ifu_idu_pc;
  endfunction
`endif
`endif

endmodule

//`include "opcode_defines.v"
module ysyx_24110012_exu (
  // input
  input wire [31:0] idu_exu_pc,         // program counter
  input wire [ 6:0] idu_exu_opcode,     // opcode
  input wire [ 2:0] idu_exu_func3,      // func3
  input wire [ 6:0] idu_exu_func7,      // func7
  input wire [31:0] idu_exu_imm,
  input wire [31:0] idu_exu_rs1,
  input wire [31:0] idu_exu_rs2,
  input wire [ 3:0] idu_exu_rd_idx,
  input wire [11:0] idu_exu_csr_idx,
  input wire [31:0] idu_exu_csr_rdata,
  input wire        idu_exu_ecall,
  input wire        idu_exu_mret,
  input wire        idu_exu_fencei,
  input wire        idu_exu_cycle_done,

  input  wire idu_exu_valid,
  output wire exu_idu_ready,

  // output
  output reg         exu_lsu_reg_wen,       // whether write reg
  output reg         exu_lsu_mem_w,         // whether write mem
  output reg         exu_lsu_mem_r,         // whether read mem
  output reg         exu_lsu_mem_sign_ext,  // whether sign extend for mem read
  output reg  [ 2:0] exu_lsu_mem_mask,      // mem width for read/write
  output reg  [ 2:0] exu_lsu_func3,
  output reg  [31:0] exu_lsu_result,
  output reg  [31:0] exu_lsu_rs2,
  output reg  [ 3:0] exu_lsu_rd_idx,
  output reg  [11:0] exu_lsu_csr_idx,
  output reg  [31:0] exu_lsu_csr_rdata,
  output reg         exu_lsu_ecall,
  output reg         exu_lsu_mret,
  output reg         exu_lsu_fencei,
  output reg         exu_lsu_branch,        // whether branch instruction
  output reg         exu_lsu_jump,          // whether JAL/JALR
  output reg         exu_lsu_wb_from_mem,   // 1 for mem, 0 for ALU
  output reg         exu_lsu_csr_wen,       // CSR write enable
  output reg  [31:0] exu_lsu_npc,
  output reg         exu_lsu_cycle_done,

  output wire exu_lsu_valid,
  input  wire lsu_exu_ready

);

  // imm type for 000=I, 001=S, 010=B, 011=U, 100=J
  reg  [ 3:0] alu_type;  // alu type
  reg  [31:0] alu_p1;  // alu parameter 1
  reg  [31:0] alu_p2;  // alu parameter 2
  wire [31:0] alu_out;  // alu output from submodule

  wire alu_uses_rs2 = (idu_exu_opcode == `ysyx_24110012_OPT_R_LOGIC) ||
  (idu_exu_opcode == `ysyx_24110012_OPT_B);
  wire [31:0] alu_rs2 = alu_uses_rs2 ? idu_exu_rs2 : 32'b0;

  assign exu_lsu_csr_idx   = idu_exu_csr_idx;
  // CSR instructions (csrrw/csrrs): rd gets the old CSR value through exu_lsu_result
  // (ALU passes csr_rdata through), and the new CSR value travels in the csr_rdata
  // field, which is otherwise only used by ecall/mret as the redirect target.
  wire        is_csr_op = (idu_exu_opcode == `ysyx_24110012_OPT_I_EC) && (idu_exu_func3 != 3'b000);
  wire [31:0] csr_new   = (idu_exu_func3 == 3'b010) ? (idu_exu_rs1 | idu_exu_csr_rdata) :  // csrrs
                          idu_exu_rs1;                                                    // csrrw
  assign exu_lsu_csr_rdata = is_csr_op ? csr_new : idu_exu_csr_rdata;
  assign exu_lsu_ecall     = idu_exu_ecall;
  assign exu_lsu_mret      = idu_exu_mret;
  assign exu_lsu_fencei    = idu_exu_fencei;
  assign exu_lsu_rd_idx    = idu_exu_rd_idx;
  assign exu_lsu_rs2       = idu_exu_rs2;
  assign exu_lsu_func3     = idu_exu_func3;

  //valid/ready
  assign exu_lsu_valid     = idu_exu_valid;
  assign exu_idu_ready     = lsu_exu_ready;  // only combinational logic here

  // parse control logic
  always @(*) begin

    // provide default value
    exu_lsu_reg_wen      = 1'b0;
    exu_lsu_mem_w        = 1'b0;
    exu_lsu_mem_r        = 1'b0;
    exu_lsu_mem_mask     = 3'b000;
    exu_lsu_mem_sign_ext = 1'b0;

    exu_lsu_jump         = 1'b0;
    exu_lsu_wb_from_mem  = 1'b0;
    exu_lsu_csr_wen      = 1'b0;

    case (idu_exu_opcode)
      `ysyx_24110012_OPT_R_LOGIC: begin  // R-Type
        exu_lsu_reg_wen = 1;
      end
      `ysyx_24110012_OPT_I_LOGIC: begin  // I-Type (addi)
        exu_lsu_reg_wen = 1;
      end
      `ysyx_24110012_OPT_I_LOAD: begin  // I-Type (lw)
        exu_lsu_reg_wen = 1;
        exu_lsu_mem_r   = 1;  // read result from memory
        case (idu_exu_func3)
          3'b000: begin
            exu_lsu_mem_mask     = 3'b001;
            exu_lsu_mem_sign_ext = 1'b1;
          end  // lb
          3'b001: begin
            exu_lsu_mem_mask     = 3'b011;
            exu_lsu_mem_sign_ext = 1'b1;
          end  // lh
          3'b010: begin
            exu_lsu_mem_mask     = 3'b111;
            exu_lsu_mem_sign_ext = 1'b1;
          end  // lw
          3'b100: exu_lsu_mem_mask = 3'b001;  // lbu
          3'b101: exu_lsu_mem_mask = 3'b011;  // lhu
          default: begin
            exu_lsu_mem_mask     = 3'b000;
            exu_lsu_mem_sign_ext = 1'b0;
          end  // default to lb
        endcase
        exu_lsu_wb_from_mem = 1;  // mem result
      end
      `ysyx_24110012_OPT_I_JALR: begin  // I-Type (jalr)
        exu_lsu_reg_wen = 1;
        exu_lsu_jump    = 1;  // jalr
      end
      `ysyx_24110012_OPT_I_EC: begin  // I-Type (ecall/ebreak/csr)
        if (idu_exu_func3 != 3'b000) begin
          exu_lsu_csr_wen = 1'b1;
          exu_lsu_reg_wen = 1'b1;  // rd <= old CSR value, visible to hazard forwarding
        end
      end
      `ysyx_24110012_OPT_S_STORE: begin  // S-Type (sw)
        exu_lsu_mem_w = 1;
        case (idu_exu_func3)
          3'b000:  exu_lsu_mem_mask = 3'b001;  // sb
          3'b001:  exu_lsu_mem_mask = 3'b011;  // sh
          3'b010:  exu_lsu_mem_mask = 3'b111;  // sw
          default: exu_lsu_mem_mask = 3'b000;  // default to sb
        endcase
      end
      `ysyx_24110012_OPT_B: begin  // B-Type (beq, bne)
        // let it be decided later with alu result
      end
      `ysyx_24110012_OPT_U_LUI, `ysyx_24110012_OPT_U_AUIPC: begin  // U-Type (lui, auipc)
        exu_lsu_reg_wen = 1;
      end
      `ysyx_24110012_OPT_J_JAL: begin  // J-Type (jal)
        exu_lsu_reg_wen = 1;
        exu_lsu_jump    = 1;
      end
      default: begin
        exu_lsu_reg_wen      = 1'b0;
        exu_lsu_mem_w        = 1'b0;
        exu_lsu_mem_r        = 1'b0;
        exu_lsu_mem_mask     = 3'b000;
        exu_lsu_mem_sign_ext = 1'b0;
        exu_lsu_jump         = 1'b0;
        exu_lsu_wb_from_mem  = 1'b0;
        exu_lsu_csr_wen      = 1'b0;
      end
    endcase
  end

  // parse alu parameters and type
  always @(*) begin

    // provide default value
    alu_type = 4'b0000;
    alu_p1   = 32'b0;
    alu_p2   = 32'b0;

    case (idu_exu_opcode)
      `ysyx_24110012_OPT_R_LOGIC: begin  // R-Type
        alu_p1 = idu_exu_rs1;
        alu_p2 = alu_rs2;
        if (idu_exu_func3 == 3'b000) begin
          alu_type = `ysyx_24110012_FUNC_ADD;  // add
          if (idu_exu_func7[5]) begin  // sub: ALU's shared adder computes rs1 + ~rs2 + 1
            alu_type = `ysyx_24110012_FUNC_SUB;
          end
        end else if (idu_exu_func3 == 3'b001) begin
          alu_type = `ysyx_24110012_FUNC_SH_L;  // sll
        end else if (idu_exu_func3 == 3'b010) begin
          alu_type = `ysyx_24110012_FUNC_LESS_SIGN;  // slt
        end else if (idu_exu_func3 == 3'b011) begin
          alu_type = `ysyx_24110012_FUNC_LESS;  // sltu
        end else if (idu_exu_func3 == 3'b100) begin
          alu_type = `ysyx_24110012_FUNC_XOR;  // xor
        end else if (idu_exu_func3 == 3'b101) begin
          alu_type = `ysyx_24110012_FUNC_SH_R;  // srl/sra
          if (idu_exu_func7[5]) begin  // sra
            alu_type = `ysyx_24110012_FUNC_SH_AR;
          end
        end else if (idu_exu_func3 == 3'b110) begin
          alu_type = `ysyx_24110012_FUNC_OR;  // or
        end else if (idu_exu_func3 == 3'b111) begin
          alu_type = `ysyx_24110012_FUNC_AND;  // and
        end
      end
      `ysyx_24110012_OPT_I_LOGIC: begin  // I-Type
        alu_p1 = idu_exu_rs1;
        alu_p2 = idu_exu_imm;
        case (idu_exu_func3)
          3'b000: alu_type = `ysyx_24110012_FUNC_ADD;  // addi
          3'b010: alu_type = `ysyx_24110012_FUNC_LESS_SIGN;  // slti
          3'b011: alu_type = `ysyx_24110012_FUNC_LESS;  // sltiu
          3'b100: alu_type = `ysyx_24110012_FUNC_XOR;  // xori
          3'b110: alu_type = `ysyx_24110012_FUNC_OR;  // ori
          3'b111: alu_type = `ysyx_24110012_FUNC_AND;  // andi
          3'b001: alu_type = `ysyx_24110012_FUNC_SH_L;  // slli
          3'b101: begin
            alu_type = `ysyx_24110012_FUNC_SH_R;  // srli
            if (idu_exu_func7[5] == 1'b1)  // srai
              alu_type = `ysyx_24110012_FUNC_SH_AR;
          end
        endcase
      end
      `ysyx_24110012_OPT_I_LOAD: begin  // I-load Type
        alu_p1   = idu_exu_rs1;
        alu_p2   = idu_exu_imm;
        alu_type = `ysyx_24110012_FUNC_ADD;
      end
      `ysyx_24110012_OPT_I_JALR: begin  // I-jalr Type
        alu_p1   = idu_exu_pc;
        alu_p2   = 32'h4;
        alu_type = `ysyx_24110012_FUNC_ADD;
      end
      `ysyx_24110012_OPT_S_STORE: begin  // S-Type
        alu_p1   = idu_exu_rs1;
        alu_p2   = idu_exu_imm;
        alu_type = `ysyx_24110012_FUNC_ADD;
      end
      `ysyx_24110012_OPT_I_EC: begin  // csr: result = old CSR value (written to rd)
        // ecall does not write rd, so result carries pc to WBU (written to mepc)
        alu_p1   = idu_exu_ecall ? idu_exu_pc : idu_exu_csr_rdata;
        alu_p2   = 32'b0;
        alu_type = `ysyx_24110012_FUNC_ADD;
      end
      `ysyx_24110012_OPT_B: begin  // B-Type
        alu_p1 = idu_exu_rs1;
        alu_p2 = alu_rs2;
        case (idu_exu_func3)
          3'b000: alu_type = `ysyx_24110012_FUNC_EQ;  // beq
          3'b001: alu_type = `ysyx_24110012_FUNC_NEQ;  // bne
          3'b100: alu_type = `ysyx_24110012_FUNC_LESS_SIGN;  // blt
          3'b101: alu_type = `ysyx_24110012_FUNC_BGE_SIGN;  //bge
          3'b110: alu_type = `ysyx_24110012_FUNC_LESS;  // bltu
          3'b111: alu_type = `ysyx_24110012_FUNC_BGE;  //bgeu
          default: begin
            alu_p1   = idu_exu_rs1;
            alu_p2   = alu_rs2;
            alu_type = `ysyx_24110012_FUNC_EQ;
          end
        endcase
      end
      `ysyx_24110012_OPT_I_FENCE: begin  // fence.i: no rd, result = pc + 4 for refetch in WBU
        alu_p1   = idu_exu_pc;
        alu_p2   = 32'h4;
        alu_type = `ysyx_24110012_FUNC_ADD;
      end
      `ysyx_24110012_OPT_U_LUI: begin  // U-Type, use add to implement lui
        alu_p1   = idu_exu_imm;
        alu_p2   = 32'b0;
        alu_type = `ysyx_24110012_FUNC_ADD;
      end
      `ysyx_24110012_OPT_U_AUIPC: begin  // U-Type
        alu_p1   = idu_exu_pc;
        alu_p2   = idu_exu_imm;
        alu_type = `ysyx_24110012_FUNC_ADD;
      end
      `ysyx_24110012_OPT_J_JAL: begin  // J-Type
        alu_p1   = idu_exu_pc;
        alu_p2   = 32'h4;
        alu_type = `ysyx_24110012_FUNC_ADD;
      end
      default: begin
        alu_type = 4'b0000;
        alu_p1   = 32'b0;
        alu_p2   = 32'b0;
      end
    endcase
  end

  ysyx_24110012_alu u_alu (
  .alu_type(alu_type),
  .alu_p1  (alu_p1),
  .alu_p2  (alu_p2),
  .alu_out (alu_out)
  );

  assign exu_lsu_result = alu_out;

  // jump/branch target: one shared adder, base = rs1 for jalr, pc for jal/branch.
  // bit0 is cleared unconditionally: required for jalr, and already 0 for pc+imm
  // (pc is 4-byte aligned, B/J immediates are even).
  wire        is_jalr = (idu_exu_opcode == `ysyx_24110012_OPT_I_JALR);
  wire [31:0] tgt_base = is_jalr ? idu_exu_rs1 : idu_exu_pc;
  wire [31:0] tgt_sum = tgt_base + idu_exu_imm;
  wire [31:0] jump_target = {tgt_sum[31:1], 1'b0};

  // update dynamic next pc
  always @(*) begin
    exu_lsu_cycle_done = idu_exu_cycle_done;
    exu_lsu_branch     = 0;
    exu_lsu_npc        = idu_exu_pc;
    if (idu_exu_valid) begin
      case (idu_exu_opcode)
        `ysyx_24110012_OPT_B: begin  // B-Type
          if (alu_out == 32'b1) exu_lsu_branch = 1;  // branch taken
          else exu_lsu_branch = 0;  // branch not taken
          exu_lsu_npc        = jump_target;
          exu_lsu_cycle_done = idu_exu_cycle_done | 1'b1;
        end
        `ysyx_24110012_OPT_I_JALR, `ysyx_24110012_OPT_J_JAL: begin
          exu_lsu_npc = jump_target;
        end
        default: begin
          exu_lsu_branch = 0;  // not a branch instruction
          exu_lsu_npc    = idu_exu_pc;
        end
      endcase
    end
  end

endmodule
//`define LFSR_SIM_LSU

`ifdef DIFF_TEST
import "DPI-C" function void difftest_skip_ref();
`endif

module ysyx_24110012_lsu (
  input clk,
  input reset,

  input exu_lsu_reg_wen,
  input exu_lsu_mem_r,
  input exu_lsu_mem_w,
  input exu_lsu_mem_sign_ext,
  input [2:0] exu_lsu_mem_mask,
  input [31:0] exu_lsu_mem_addr,
  input [2:0] exu_lsu_func3,
  input [31:0] exu_lsu_result,
  input [31:0] exu_lsu_mem_wdata,
  input [3:0] exu_lsu_rd_idx,
  input [11:0] exu_lsu_csr_idx,
  input [31:0] exu_lsu_csr_rdata,
  input exu_lsu_ecall,
  input exu_lsu_mret,
  input exu_lsu_fencei,
  input exu_lsu_branch,
  input exu_lsu_jump,
  input exu_lsu_wb_from_mem,
  input exu_lsu_csr_wen,
  input exu_lsu_cycle_done,

  input  wire exu_lsu_valid,
  output wire lsu_exu_ready,

  output wire lsu_wbu_reg_wen,
  output wire [2:0] lsu_wbu_func3,
  output wire [31:0] lsu_wbu_wdata,
  output wire [3:0] lsu_wbu_rd_idx,
  output wire [11:0] lsu_wbu_csr_idx,
  output wire [31:0] lsu_wbu_csr_rdata,
  output wire lsu_wbu_ecall,
  output wire lsu_wbu_mret,
  output wire lsu_wbu_fencei,
  output wire lsu_wbu_branch,
  //output wire lsu_wbu_jump,
  output wire lsu_wbu_csr_wen,
  output wire lsu_wbu_cycle_done,

  output wire lsu_wbu_valid,
  input  wire wbu_lsu_ready,

  // AR
  output reg [31:0] araddr,
  output reg arvalid,
  output reg [2:0] arsize,
  input wire arready,
  // R
  input wire [31:0] rdata,
  input wire rvalid,
  output reg rready,
  // AW
  output reg [31:0] awaddr,
  output reg awvalid,
  output reg [2:0] awsize,
  input wire awready,
  // W
  output reg [31:0] wdata,
  output reg [3:0] wstrb,
  output reg wvalid,
  input wire wready,
  // B
  input wire [1:0] bresp,
  input wire bvalid,
  output reg bready
);

  reg [31:0] rdata_ext;

  reg io_r_done;
  reg io_w_done;
  reg w_active, r_active;

  // the device(sram/flash) value is returned by 4byte aligned
  wire [ 4:0] offset = {araddr[1:0], 3'b000};
  wire [31:0] rdata_sh = rdata >> offset;

  assign araddr = exu_lsu_mem_addr;
  assign awaddr = exu_lsu_mem_addr;
  assign wdata  = (exu_lsu_mem_mask == 3'b111) ?
          exu_lsu_mem_wdata : (exu_lsu_mem_wdata << {exu_lsu_mem_addr[1:0], 3'b000});
  assign wstrb = (exu_lsu_mem_mask == 3'b111) ?
          4'b1111 : ({1'b0, exu_lsu_mem_mask} << exu_lsu_mem_addr[1:0]);

  assign io_r_done          = rvalid && rready;
  assign lsu_wbu_reg_wen    = exu_lsu_reg_wen;
  assign lsu_wbu_func3      = exu_lsu_func3;
  assign lsu_wbu_wdata      = exu_lsu_wb_from_mem ? rdata_ext : exu_lsu_result;
  assign lsu_wbu_rd_idx     = exu_lsu_rd_idx;
  assign lsu_wbu_csr_idx    = exu_lsu_csr_idx;
  assign lsu_wbu_csr_rdata  = exu_lsu_csr_rdata;
  assign lsu_wbu_ecall      = exu_lsu_ecall;
  assign lsu_wbu_mret       = exu_lsu_mret;
  assign lsu_wbu_fencei     = exu_lsu_fencei;
  assign lsu_wbu_branch     = exu_lsu_branch;
  //assign lsu_wbu_jump       = exu_lsu_jump;
  assign lsu_wbu_csr_wen    = exu_lsu_csr_wen;
  // read data will be set to rd regs so it does not affect cycle_done signal
  assign lsu_wbu_cycle_done = exu_lsu_cycle_done | io_w_done;

  task automatic set_mem_sizes(input [2:0] mem_mask);
    begin
      case (mem_mask)
        3'b001: begin  // lb
          awsize = 3'b000;
          arsize = 3'b000;
        end
        3'b011: begin  // lu
          awsize = 3'b001;
          arsize = 3'b001;
        end
        default: begin  // lw
          awsize = 3'b010;
          arsize = 3'b010;
        end
      endcase
    end
  endtask

  always @(*) begin
    case (exu_lsu_mem_mask)
      3'b001: begin  // lb
        rdata_ext = exu_lsu_mem_sign_ext ? {{24{rdata_sh[7]}}, rdata_sh[7:0]} : {24'b0, rdata_sh[7:0]};
      end
      3'b011: begin  // lu
        rdata_ext = exu_lsu_mem_sign_ext ? {{16{rdata_sh[15]}}, rdata_sh[15:0]} : {16'b0, rdata_sh[15:0]};
      end
      default: begin  // lw
        rdata_ext = rdata;
      end
    endcase
    set_mem_sizes(exu_lsu_mem_mask);
  end

  //valid/ready
  // Check whether LSU current task is completed (read done / write done / non-memory inst directly done)
  wire lsu_done = exu_lsu_mem_r ? io_r_done : exu_lsu_mem_w ? io_w_done : 1'b1;

  // LSU output is valid only when upstream input is valid/ready recieved and current stage execution is done
  assign lsu_wbu_valid = exu_lsu_valid && lsu_done;

  // Ready to accept next request only when current task is done and downstream is ready
  assign lsu_exu_ready = lsu_done && wbu_lsu_ready;

`ifdef DIFF_TEST

`ifndef NPC
  localparam [31:0] SKIP_START = 32'h02000000;
  localparam [31:0] SKIP_R1 = 32'h0200ffff;
`else
  localparam [31:0] SKIP_START = 32'ha0000000;
  localparam [31:0] SKIP_R1 = 32'ha00000ff;
`endif

  localparam [31:0] SKIP_R2 = 32'h10000000;
  localparam [31:0] SKIP_END = 32'h22000000;

  wire ar_skip_region = (araddr >= SKIP_START && araddr <= SKIP_R1) ||
  (araddr >= SKIP_R2 && araddr <= SKIP_END);
  wire aw_skip_region = (awaddr >= SKIP_START && awaddr <= SKIP_R1) ||
  (awaddr >= SKIP_R2 && awaddr <= SKIP_END);

  always @(posedge clk) begin
    // Skip only when this LSU instruction is actually accepted by downstream.
    if (lsu_wbu_valid && wbu_lsu_ready) begin
      if ((exu_lsu_mem_r && ar_skip_region) || (exu_lsu_mem_w && aw_skip_region)) begin
        difftest_skip_ref();
      end
    end
  end
`endif

 localparam S_IDLE = 2'b00, S_AR = 2'b01, S_R = 2'b10;
  reg [1:0] state, next_state;

  always @(posedge clk) begin
    if (reset) begin
      state <= S_IDLE;
    end else begin
      state <= next_state;
    end
  end

  always @(*) begin
    case (state)
      S_IDLE: begin
        if (exu_lsu_valid && exu_lsu_mem_r && !r_active) begin
          next_state = S_AR;
        end else begin
          next_state = S_IDLE;
        end
      end
      S_AR: begin
        if (arvalid && arready) begin
          next_state = S_R;
        end else begin
          next_state = S_AR;
        end
      end
      S_R: begin
        if (rvalid && rready) begin
          next_state = S_IDLE;
        end else begin
          next_state = S_R;
        end
      end
      default: next_state = S_IDLE;
    endcase
  end

  always @(posedge clk) begin
    if (reset) begin
      arvalid        <= 1'b0;
      rready         <= 1'b0;
      r_active       <= 1'b0;
    end else begin
      case (next_state)
        S_IDLE: begin
          arvalid        <= 1'b0;
          rready         <= 1'b0;
          r_active       <= 1'b0;
        end
        S_AR: begin
          arvalid        <= 1'b1;
        end
        S_R: begin
          r_active          <= 1'b1;
          arvalid           <= 1'b0;
          if (rvalid) begin
            rready            <= 1'b1;
          end
        end
        default: begin
          rready         <= 1'b0;
          r_active       <= 1'b0;
        end
      endcase
    end
  end

  // S_W_AW: AW and W both pending; S_W_W: AW done, W pending;
  // S_W_WAIT_AW: W done, AW pending (slave may accept W before AW)
  localparam S_W_IDLE = 3'd0, S_W_AW = 3'd1, S_W_W = 3'd2, S_W_B = 3'd3, S_W_WAIT_AW = 3'd4;
  reg [2:0] w_state, w_next_state;

  always @(posedge clk) begin
    if (reset) begin
      w_state <= S_W_IDLE;
    end else begin
      w_state <= w_next_state;
    end
  end

  always @(*) begin
    case (w_state)
      S_W_IDLE: begin
        if (exu_lsu_valid && exu_lsu_mem_w && !w_active) begin
          w_next_state = S_W_AW;
        end else begin
          w_next_state = S_W_IDLE;
        end
      end
      S_W_AW: begin
        if ((awvalid && awready) && (wvalid && wready)) begin
          w_next_state = S_W_B;
        end else if (awvalid && awready) begin
          w_next_state = S_W_W;
        end else if (wvalid && wready) begin
          w_next_state = S_W_WAIT_AW;
        end else begin
          w_next_state = S_W_AW;
        end
      end
      S_W_WAIT_AW: begin
        if (awvalid && awready) begin
          w_next_state = S_W_B;
        end else begin
          w_next_state = S_W_WAIT_AW;
        end
      end
      S_W_W: begin
        if (wvalid && wready) begin
          w_next_state = S_W_B;
        end else begin
          w_next_state = S_W_W;
        end
      end
      S_W_B: begin
        if (bvalid && bready) begin
          w_next_state = S_W_IDLE;
        end else begin
          w_next_state = S_W_B;
        end
      end
      default: w_next_state = S_W_IDLE;
    endcase
  end

  always @(posedge clk) begin
    if (reset) begin
      awvalid   <= 1'b0;
      wvalid    <= 1'b0;
      bready    <= 1'b0;
      w_active  <= 1'b0;
      io_w_done <= 1'b0;
    end else begin
      case (w_next_state)
        S_W_IDLE: begin
          awvalid   <= 1'b0;
          wvalid    <= 1'b0;
          bready    <= 1'b0;
          w_active  <= 1'b0;
          io_w_done <= 1'b0;
        end
        S_W_AW: begin
          awvalid <= 1'b1;
          w_active <= 1'b1;
          if (awvalid) begin
            wvalid <= 1'b1;
          end
        end
        S_W_W: begin
          wvalid <= 1'b1;
          awvalid <= 1'b0;
        end
        S_W_WAIT_AW: begin
          wvalid <= 1'b0;
          awvalid <= 1'b1;
        end
        S_W_B: begin
          awvalid <= 1'b0;
          wvalid <= 1'b0;
          if (bvalid) begin
            bready    <= 1'b1;
            io_w_done <= 1'b1;
          end
        end
        default: begin
          awvalid   <= 1'b0;
          wvalid    <= 1'b0;
          bready    <= 1'b0;
          w_active  <= 1'b0;
          io_w_done <= 1'b0;
        end
      endcase
    end
  end

endmodule

module ysyx_24110012_wbu (
  input wire clk,
  input wire reset,

  input wire lsu_wbu_reg_wen,
  input wire [2:0] lsu_wbu_func3,
  input wire [31:0] lsu_wbu_wdata,
  input wire [3:0] lsu_wbu_rd_idx,
  input wire [11:0] lsu_wbu_csr_idx,
  input wire [31:0] lsu_wbu_csr_rdata,
  input wire lsu_wbu_ecall,
  input wire lsu_wbu_mret,
  input wire lsu_wbu_fencei,
  input wire lsu_wbu_branch,
  //input wire lsu_wbu_jump,
  input wire lsu_wbu_csr_wen,
  input wire lsu_wbu_cycle_done,

  input  wire lsu_wbu_valid,
  output wire wbu_lsu_ready,

  output reg [31:0] wbu_rf_wdata,
  output reg [31:0] wbu_csr_wdata,
  output wire [3:0] wbu_rf_idx,
  output reg [11:0] wbu_rf_csr_idx,
  output wire wbu_rf_csr_wen,
  output wire wbu_rf_reg_wen,
  output reg [31:0] wbu_ifu_pc,
  output reg wbu_redirect,
  output wire wbu_fencei,
  output wire wbu_cycle_done,

  input wire icache_flush_done
);
  wire wbu_redirect_i;

  assign wbu_rf_idx     = lsu_wbu_rd_idx;
  // ecall needs to commit trap CSRs (mepc/mcause) even though it is not a CSR instruction.
  assign wbu_rf_csr_wen = lsu_wbu_valid && wbu_lsu_ready && (lsu_wbu_csr_wen || lsu_wbu_ecall);
  assign wbu_rf_reg_wen = lsu_wbu_valid && wbu_lsu_ready && lsu_wbu_reg_wen;
  assign wbu_fencei     = lsu_wbu_valid && lsu_wbu_fencei;
  // fence.i also redirects (to pc+4) so that younger instructions flushed from the
  // pipeline are refetched from the freshly invalidated icache
  assign wbu_redirect_i = lsu_wbu_valid && wbu_lsu_ready &&
                          (lsu_wbu_ecall || lsu_wbu_mret || lsu_wbu_fencei);
  assign wbu_redirect   = lsu_wbu_valid ? wbu_redirect_i : 1'b0;

  localparam CSR_MEPC = 12'h341;

  reg cycle_done_r;

  //valid/ready
  assign wbu_lsu_ready = lsu_wbu_fencei ? icache_flush_done : 1'b1;

  always @(posedge clk) begin
    if (reset) begin
      cycle_done_r <= 1'b0;
    end else begin
      cycle_done_r <= lsu_wbu_valid && wbu_lsu_ready;
    end
  end

  assign wbu_cycle_done = cycle_done_r;

  always @(*) begin
    // Jump/Branch are redirected in EXU; WBU only redirects on ecall/mret,
    // and in both cases the target comes from csr_rdata (mtvec/mepc)
    wbu_ifu_pc     = lsu_wbu_csr_rdata;

    // Provide default value: new CSR value is carried in csr_rdata field (see EXU)
    wbu_csr_wdata  = lsu_wbu_csr_rdata;
    wbu_rf_csr_idx = lsu_wbu_csr_idx;

    // Ecall:
    // The PC should get from mtvec from CSR
    // And the PC should store to mepc
    if (lsu_wbu_ecall) begin
      wbu_csr_wdata  = lsu_wbu_wdata;  // pc of ecall, carried in result (see EXU)
      wbu_rf_csr_idx = CSR_MEPC;
      wbu_ifu_pc     = lsu_wbu_csr_rdata;
    end
    if (lsu_wbu_mret) begin
      // Eret:
      // The PC should get from mepc from CSR
      wbu_ifu_pc = lsu_wbu_csr_rdata;
    end
    if (lsu_wbu_fencei) begin
      // Fence.i:
      // Refetch from pc+4, carried in result (see EXU)
      wbu_ifu_pc = lsu_wbu_wdata;
    end

  end

  // rd data: ALU/mem result; for CSR instructions EXU already put the old CSR value here
  always @(*) begin
    wbu_rf_wdata = lsu_wbu_wdata;
  end
endmodule

module ysyx_24110012_arbiter #(
  parameter ADDR_WIDTH  = 32,
  parameter DATA_WIDTH  = 32,
  parameter NUM_MASTERS = 2
) (
  input clk,
  input reset,

  //output wire [MASTER_INDEX_WIDTH-1:0] mem_r_grant,

  input wire [NUM_MASTERS-1:0] m_awvalid,
  input wire [NUM_MASTERS-1:0][2:0] m_awsize,
  output wire [NUM_MASTERS-1:0] m_awready,
  input wire [NUM_MASTERS-1:0][ADDR_WIDTH-1:0] m_awaddr,
  input wire [NUM_MASTERS-1:0] m_wvalid,
  output reg [NUM_MASTERS-1:0] m_wready,
  input wire [NUM_MASTERS-1:0][DATA_WIDTH-1:0] m_wdata,
  input wire [NUM_MASTERS-1:0][DATA_WIDTH/8-1:0] m_wstrb,
  output wire [NUM_MASTERS-1:0][1:0] m_bresp,
  output reg [NUM_MASTERS-1:0] m_bvalid,
  input wire [NUM_MASTERS-1:0] m_bready,
  input wire [NUM_MASTERS-1:0] m_arvalid,
  input wire [NUM_MASTERS-1:0][2:0] m_arsize,
  input wire [NUM_MASTERS-1:0][1:0] m_arburst,
  input wire [NUM_MASTERS-1:0][7:0] m_arlen,
  output reg [NUM_MASTERS-1:0] m_arready,
  input wire [NUM_MASTERS-1:0][ADDR_WIDTH-1:0] m_araddr,
  output wire [NUM_MASTERS-1:0] m_rvalid,
  input wire [NUM_MASTERS-1:0] m_rready,
  output wire [NUM_MASTERS-1:0][DATA_WIDTH-1:0] m_rdata,
  output wire [NUM_MASTERS-1:0] m_rlast,

  output wire                    s_awvalid,
  output wire [             2:0] s_awsize,
  input  wire                    s_awready,
  output wire [  ADDR_WIDTH-1:0] s_awaddr,
  output wire                    s_wvalid,
  input  wire                    s_wready,
  output reg  [  DATA_WIDTH-1:0] s_wdata,
  output reg  [DATA_WIDTH/8-1:0] s_wstrb,
  input  wire [             1:0] s_bresp,
  input  wire                    s_bvalid,
  output reg                     s_bready,
  output reg                     s_arvalid,
  output wire [             2:0] s_arsize,
  output wire [             1:0] s_arburst,
  output wire [             7:0] s_arlen,
  input  wire                    s_arready,
  output reg  [  ADDR_WIDTH-1:0] s_araddr,
  input  wire                    s_rvalid,
  output reg                     s_rready,
  input  wire [  DATA_WIDTH-1:0] s_rdata,
  input  wire                    s_rlast
);

  localparam MASTER_INDEX_WIDTH = $clog2(NUM_MASTERS);

  reg [MASTER_INDEX_WIDTH-1:0] aw_grant, ar_grant;
  reg [MASTER_INDEX_WIDTH-1:0] aw_grant_next, ar_grant_next;
  reg [NUM_MASTERS-1:0] aw_grant_oh, ar_grant_oh;  // one-hot
  reg ar_active, aw_active;
  integer aw_grant_i, ar_grant_i;

  // ar_grant to know which host is using mem and send to regfile to use
  //assign mem_r_grant = ar_grant;

  // Lower-index master has higher priority for write channel.
  // At the top level, master 0 is LSU and master 1 is IFU/icache.
  always @(*) begin
    aw_grant_next = aw_grant;
    for (aw_grant_i = NUM_MASTERS - 1; aw_grant_i >= 0; aw_grant_i = aw_grant_i - 1) begin
      if (m_awvalid[aw_grant_i]) begin
        aw_grant_next = aw_grant_i[MASTER_INDEX_WIDTH-1:0];
      end
    end
  end

  // Lower-index master has higher priority for read channel.
  always @(*) begin
    ar_grant_next = ar_grant;
    for (ar_grant_i = NUM_MASTERS - 1; ar_grant_i >= 0; ar_grant_i = ar_grant_i - 1) begin
      if (m_arvalid[ar_grant_i]) begin
        ar_grant_next = ar_grant_i[MASTER_INDEX_WIDTH-1:0];
      end
    end
  end

  // transaction finished: last read beat / write response handshake
  wire r_done = s_rvalid && s_rready && (s_rlast || s_arlen == 0);
  wire b_done = s_bvalid && s_bready;

  always @(posedge clk) begin
    if (reset) begin
      ar_active <= 1'b0;
      aw_active <= 1'b0;
    end else begin
      if (s_arvalid && !ar_active) begin
        ar_active <= 1'b1;
      end else if (r_done && ar_active) begin
        ar_active <= 1'b0;
      end

      if (s_awvalid && !aw_active) begin
        aw_active <= 1'b1;
      end else if (b_done && aw_active) begin
        aw_active <= 1'b0;
      end
    end
  end

  // update grants
  // grant may change only when the channel is free: no transaction in progress
  // and no request being issued (AXI: addr must stay stable while valid is high),
  // or at the end of a transaction.
  always @(posedge clk) begin
    if (reset) begin
      aw_grant <= 0;
      ar_grant <= 0;
    end else begin
      if (b_done || (!aw_active && !s_awvalid)) begin
        aw_grant <= aw_grant_next;
      end
      if (r_done || (!ar_active && !s_arvalid)) begin
        ar_grant <= ar_grant_next;
      end
    end
  end

  // one-hot encoding
  always @(*) begin
    aw_grant_oh           = 0;
    ar_grant_oh           = 0;
    aw_grant_oh[aw_grant] = 1'b1;
    ar_grant_oh[ar_grant] = 1'b1;
  end

  wire write_req = |m_awvalid;
  wire read_req = |m_arvalid;

  // Read/Write mutual exclusion and arbitration logic:
  // 1. While a read transaction is in progress (ar_active), write requests are blocked;
  //    while a write transaction is in progress (aw_active), read requests are blocked.
  // 2. When idle and both read and write are requested simultaneously, read wins.
  //    Once a write has started (aw_active), it keeps the bus until it finishes.
  wire aw_enable = !ar_active && write_req && (!read_req || aw_active);
  wire ar_enable = !aw_active && read_req;

  assign s_awaddr  = m_awaddr[aw_grant];
  assign s_awsize  = m_awsize[aw_grant];
  assign s_awvalid = aw_enable ? m_awvalid[aw_grant] : 1'b0;

  // awready signal distribution
  genvar i;
  generate
    for (i = 0; i < NUM_MASTERS; i = i + 1) begin : gen_aw_ready
      assign m_awready[i] = aw_grant_oh[i] & s_awready & aw_enable;
    end
  endgenerate

  // write data channel multiplexer
  assign s_wdata  = m_wdata[aw_grant];
  assign s_wstrb  = m_wstrb[aw_grant];
  assign s_wvalid = m_wvalid[aw_grant];

  // wready signal distribution
  generate
    for (i = 0; i < NUM_MASTERS; i = i + 1) begin : gen_w_ready
      assign m_wready[i] = aw_grant_oh[i] & s_wready;
    end
  endgenerate

  // write response channel demultiplexer
  generate
    for (i = 0; i < NUM_MASTERS; i = i + 1) begin : gen_b_channel
      assign m_bresp[i]  = s_bresp;
      assign m_bvalid[i] = aw_grant_oh[i] & s_bvalid;
    end
  endgenerate

  assign s_bready  = m_bready[aw_grant];

  // read address channel multiplexer
  assign s_araddr  = m_araddr[ar_grant];
  assign s_arsize  = m_arsize[ar_grant];
  assign s_arvalid = ar_enable ? m_arvalid[ar_grant] : 1'b0;
  assign s_arburst = m_arburst[ar_grant];
  assign s_arlen   = m_arlen[ar_grant];

  // arready signal distribution
  generate
    for (i = 0; i < NUM_MASTERS; i = i + 1) begin : gen_ar_ready
      assign m_arready[i] = ar_grant_oh[i] & s_arready & ar_enable;
    end
  endgenerate

  // read data channel demultiplexer (data return phase is not gated by ar_enable; routed by latched ar_grant)
  generate
    for (i = 0; i < NUM_MASTERS; i = i + 1) begin : gen_r_channel
      assign m_rdata[i]  = s_rdata;
      assign m_rvalid[i] = ar_grant_oh[i] & s_rvalid;
      assign m_rlast[i]  = ar_grant_oh[i] & s_rlast;
    end
  endgenerate

  assign s_rready = m_rready[ar_grant];

  // function [MASTER_INDEX_WIDTH-1:0] priority_arbiter;
  //     input [NUM_MASTERS-1:0] req;

  //     integer i;
  //     begin
  //         priority_arbiter = 0;
  //         for (i = 0; i < NUM_MASTERS; i = i + 1) begin
  //             if (req[i]) begin
  //                 priority_arbiter = MASTER_INDEX_WIDTH'(i);
  //                 break;
  //             end
  //         end
  //     end
  // endfunction

endmodule

module ysyx_24110012_xbar #(
  parameter ADDR_WIDTH  = 32,
  parameter DATA_WIDTH  = 32,
  parameter NUM_MASTERS = 2
) (
  input clk,

  // slave interface
  input wire s_awvalid,
  output wire s_awready,
  input wire [ADDR_WIDTH-1:0] s_awaddr,
  input wire [2:0] s_awsize,
  input wire s_wvalid,
  output reg s_wready,
  input wire [DATA_WIDTH-1:0] s_wdata,
  input wire [DATA_WIDTH/8-1:0] s_wstrb,
  output wire [1:0] s_bresp,
  output reg s_bvalid,
  input wire s_bready,
  input wire s_arvalid,
  output reg s_arready,
  input wire [ADDR_WIDTH-1:0] s_araddr,
  input wire [2:0] s_arsize,
  input wire [1:0] s_arburst,
  input wire [7:0] s_arlen,
  output wire s_rvalid,
  input wire s_rready,
  output wire [DATA_WIDTH-1:0] s_rdata,
  output wire s_rlast,

  // master interface
  output wire [NUM_MASTERS-1:0] m_awvalid,
  input wire [NUM_MASTERS-1:0] m_awready,
  output wire [NUM_MASTERS-1:0][ADDR_WIDTH-1:0] m_awaddr,
  output wire [NUM_MASTERS-1:0][2:0] m_awsize,
  output wire [NUM_MASTERS-1:0] m_wvalid,
  input wire [NUM_MASTERS-1:0] m_wready,
  output wire [NUM_MASTERS-1:0][DATA_WIDTH-1:0] m_wdata,
  output wire [NUM_MASTERS-1:0][DATA_WIDTH/8-1:0] m_wstrb,
  input wire [NUM_MASTERS-1:0][1:0] m_bresp,
  input wire [NUM_MASTERS-1:0] m_bvalid,
  output wire [NUM_MASTERS-1:0] m_bready,
  output wire [NUM_MASTERS-1:0] m_arvalid,
  input wire [NUM_MASTERS-1:0] m_arready,
  output wire [NUM_MASTERS-1:0][ADDR_WIDTH-1:0] m_araddr,
  output wire [NUM_MASTERS-1:0][2:0] m_arsize,
  output wire [NUM_MASTERS-1:0][1:0] m_arburst,
  output wire [NUM_MASTERS-1:0][7:0] m_arlen,
  input wire [NUM_MASTERS-1:0] m_rvalid,
  output wire [NUM_MASTERS-1:0] m_rready,
  input wire [NUM_MASTERS-1:0][DATA_WIDTH-1:0] m_rdata,
  input wire [NUM_MASTERS-1:0] m_rlast

);

`ifdef NPC
  parameter P_MEM_START = 32'h8000_0000;
  parameter P_MEM_END = 32'h8100_0000;
  parameter P_DEV_BASE = 32'ha000_0000;

  parameter P_PDEV_START = P_DEV_BASE + 32'h0000_0060;
  parameter P_PDEV_END = P_PDEV_START + 32'h130_0000;

  parameter P_CLINT_START = P_DEV_BASE + 32'h0000_0048;
  parameter P_CLINT_END = P_CLINT_START + 32'h0008;  // mtime only: 0x48~0x4f, must not cover VGACTL(0x100)

`else
  parameter P_SRAM_START = 32'h0f00_0000;
  parameter P_SRAM_END = 32'h0fff_ffff;

  parameter P_SDRAM_START = 32'ha000_0000;
  parameter P_SDRAM_END = 32'hbfff_ffff;

  parameter P_FLASH_START = 32'h3000_0000;
  parameter P_FLASH_END = 32'h3fff_ffff;

  parameter P_UART_START = 32'h1000_0000;
  parameter P_UART_END = P_UART_START + 32'h8;

  parameter P_CLINT_START = 32'h0200_0000;
  // whole CLINT space 0x0200_0000~0x0200_ffff (end exclusive): covers both
  // mtime at 0x0200_0000/4 and the standard layout mtime at 0x0200_bff8/c
  parameter P_CLINT_END = P_CLINT_START + 32'h0001_0000;
`endif

  function automatic logic addr_is_soc(input [DATA_WIDTH-1:0] addr);
`ifdef NPC
    addr_is_soc = ((addr >= P_MEM_START) && (addr < P_MEM_END) ||
                   (addr >= P_PDEV_START) && (addr < P_PDEV_END));
`else
    addr_is_soc = ((addr >= P_SRAM_START) && (addr < P_SRAM_END) ||
                   (addr >= P_SDRAM_START) && (addr < P_SDRAM_END) ||
                   (addr >= P_FLASH_START) && (addr < P_FLASH_END) ||
                   (addr >= P_UART_START) && (addr <= P_UART_END));
`endif
  endfunction

  // 0 -> soc, 1 -> clint
  function automatic logic addr_is_clint(input [DATA_WIDTH-1:0] addr);
    addr_is_clint = (addr >= P_CLINT_START) && (addr < P_CLINT_END);
  endfunction

  localparam MASTER_INDEX_WIDTH = $clog2(NUM_MASTERS);

  wire [MASTER_INDEX_WIDTH-1:0] master_index_aw;
  wire [MASTER_INDEX_WIDTH-1:0] master_index_ar;

  // write op
  // this to consider the s_awaddr no change
  wire aw_sel_soc = addr_is_soc(s_awaddr);
  wire aw_sel_clint = addr_is_clint(s_awaddr);

  // 0 stands for soc, 1 stands for clint
  assign master_index_aw = aw_sel_clint ? 1'b1 : (aw_sel_soc ? 1'b0 : 1'b0);

  genvar i_aw;
  generate
    for (i_aw = 0; i_aw < NUM_MASTERS; i_aw = i_aw + 1) begin : gen_xbar_w
      assign m_awaddr[i_aw]  = (i_aw == master_index_aw) ? s_awaddr : '0;
      assign m_awsize[i_aw]  = (i_aw == master_index_aw) ? s_awsize : '0;
      assign m_awvalid[i_aw] = (i_aw == master_index_aw) ? s_awvalid : 1'b0;
      assign m_wdata[i_aw]   = (i_aw == master_index_aw) ? s_wdata : '0;
      assign m_wstrb[i_aw]   = (i_aw == master_index_aw) ? s_wstrb : '0;
      assign m_wvalid[i_aw]  = (i_aw == master_index_aw) ? s_wvalid : 1'b0;
      assign m_bready[i_aw]  = (i_aw == master_index_aw) ? s_bready : 1'b0;
    end
  endgenerate

  assign s_awready = m_awready[master_index_aw];
  assign s_wready  = m_wready[master_index_aw];
  assign s_bresp   = m_bresp[master_index_aw];
  assign s_bvalid  = m_bvalid[master_index_aw];

  // read op
  // this to consider the s_araddr no change
  wire ar_sel_soc = addr_is_soc(s_araddr);
  wire ar_sel_clint = addr_is_clint(s_araddr);

  // 0 stands for mem, 1 stands for uart
  assign master_index_ar = ar_sel_clint ? 1'b1 : (ar_sel_soc ? 1'b0 : 1'b0);

  genvar i_ar;
  generate
    for (i_ar = 0; i_ar < NUM_MASTERS; i_ar = i_ar + 1) begin : gen_xbar_r
      assign m_araddr[i_ar]  = (i_ar == master_index_ar) ? s_araddr : '0;
      assign m_arsize[i_ar]  = (i_ar == master_index_ar) ? s_arsize : '0;
      assign m_arvalid[i_ar] = (i_ar == master_index_ar) ? s_arvalid : 1'b0;
      assign m_rready[i_ar]  = (i_ar == master_index_ar) ? s_rready : 1'b0;
      assign m_arburst[i_ar] = (i_ar == master_index_ar) ? s_arburst : 2'b0;
      assign m_arlen[i_ar]   = (i_ar == master_index_ar) ? s_arlen : 8'b0;
    end
  endgenerate

  assign s_arready = m_arready[master_index_ar];
  assign s_rdata   = m_rdata[master_index_ar];
  assign s_rlast   = m_rlast[master_index_ar];
  assign s_rvalid  = m_rvalid[master_index_ar];

endmodule

module ysyx_24110012_icache #(
  parameter integer BLOCK_BYTES = 4,
  parameter integer NUM_LINES   = 16
) (
  input  wire clk,
  input  wire reset,
  input  wire flush,
  output reg  flush_done,

  // IFU side request/response
  input  wire        ifu_req_valid,
  output wire        ifu_req_ready,
  input  wire [31:0] ifu_req_addr,
  output reg         ifu_resp_valid,
  input  wire        ifu_resp_ready,
  output reg  [31:0] ifu_resp_data,

  // Downstream memory read channel (AXI-lite style AR/R subset)
  output reg  [31:0] mem_araddr,
  output reg         mem_arvalid,
  output reg  [ 1:0] mem_arburst,
  output reg  [ 7:0] mem_arlen,
  output wire [ 2:0] mem_arsize,
  input  wire        mem_arready,

  input  wire [31:0] mem_rdata,
  input  wire        mem_rvalid,
  input  wire        mem_rlast,
  output reg         mem_rready
);

  localparam integer OFFSET_BITS = $clog2(BLOCK_BYTES);
  localparam integer INDEX_BITS = $clog2(NUM_LINES);
  localparam integer WORDS_PER_LINE = BLOCK_BYTES / 4;
  localparam integer WORD_OFFSET_BITS = (WORDS_PER_LINE <= 1) ? 1 : $clog2(WORDS_PER_LINE);
  localparam integer TAG_BITS = 32 - OFFSET_BITS - INDEX_BITS;

  localparam logic [2:0] STATE_IDLE = 3'b000;
  localparam logic [2:0] STATE_MISS_AR = 3'b001;
  localparam logic [2:0] STATE_MISS_R = 3'b010;
  localparam logic [2:0] STATE_UNCACHED_AR = 3'b011;
  localparam logic [2:0] STATE_UNCACHED_R = 3'b100;

  reg     [                 2:0] state;

  reg     [        TAG_BITS-1:0] tag_array          [NUM_LINES];
  reg                            valid_array        [NUM_LINES];
  reg     [                31:0] data_array         [NUM_LINES] [WORDS_PER_LINE];

  reg     [        TAG_BITS-1:0] miss_tag;
  reg     [      INDEX_BITS-1:0] miss_index;
  reg     [WORD_OFFSET_BITS-1:0] miss_word_off;
  reg     [WORD_OFFSET_BITS-1:0] miss_fill_cnt;
  reg     [                31:0] miss_base_addr;

  wire    [      INDEX_BITS-1:0] req_index;
  wire    [        TAG_BITS-1:0] req_tag;
  wire    [WORD_OFFSET_BITS-1:0] req_word_off;
  wire    [WORD_OFFSET_BITS-1:0] miss_fill_cnt_next;
  wire    [                31:0] miss_next_araddr;
  wire                           hit;
  wire                           uncached;
  wire    [                31:0] hit_word;

  integer                        i;
  //integer                        j;

  task automatic invalidate_cache_arrays;
    begin
      for (i = 0; i < NUM_LINES; i = i + 1) begin
        valid_array[i] <= 1'b0;
        //tag_array[i]   <= {TAG_BITS{1'b0}};
        // for (j = 0; j < WORDS_PER_LINE; j = j + 1) begin
        //   data_array[i][j] <= 32'b0;
        // end
      end
    end
  endtask

  // SRAM don't need to be cached which start from 0x0f000000;
  // FLASH also don't need to be cached which start from 0x30000000 in 256M;
  localparam logic [31:0] SRAM_BASE = 32'h0f000000;
  localparam logic [31:0] FLASH_BASE = 32'h30000000;
  //assign uncached = (ifu_req_addr & 32'hffffe000) == SRAM_BASE || (ifu_req_addr & 32'hf0000000) == FLASH_BASE;
  assign uncached   = (ifu_req_addr & 32'hffffe000) == SRAM_BASE;

  assign mem_arsize = 3'b010;  // 4 bytes (32 bits) per beat

  // Address breakdown for cache indexing and tag comparison
  // 31    m+n m+n-1   m m-1    0
  // +---------+---------+--------+
  // |   tag   |  index  | offset |
  // +---------+---------+--------+

  assign req_index  = ifu_req_addr[OFFSET_BITS+INDEX_BITS-1 : OFFSET_BITS];
  assign req_tag    = ifu_req_addr[31 : OFFSET_BITS+INDEX_BITS];

  generate
    if (WORDS_PER_LINE == 1) begin : gen_single_word_line
      assign req_word_off = {WORD_OFFSET_BITS{1'b0}};
    end else begin : gen_multi_word_line
      assign req_word_off = ifu_req_addr[OFFSET_BITS-1 : 2];
    end
  endgenerate

  assign hit = valid_array[req_index] && (tag_array[req_index] == req_tag);
  assign hit_word = data_array[req_index][req_word_off];
  assign miss_fill_cnt_next = miss_fill_cnt + {{(WORD_OFFSET_BITS - 1) {1'b0}}, 1'b1};
  assign miss_next_araddr = miss_base_addr +
  {{(32 - WORD_OFFSET_BITS - 2) {1'b0}}, miss_fill_cnt_next, 2'b00};

  assign ifu_req_ready = (state == STATE_IDLE) && !ifu_resp_valid;

  always @(posedge clk) begin
    if (reset) begin
      state              <= STATE_IDLE;
      ifu_resp_valid     <= 1'b0;
      ifu_resp_data      <= 32'b0;

      mem_araddr         <= 32'b0;
      mem_arvalid        <= 1'b0;
      mem_arlen          <= 8'b0;
      mem_arburst        <= 2'b00;
      mem_rready         <= 1'b0;

      miss_tag           <= {TAG_BITS{1'b0}};
      miss_index         <= {INDEX_BITS{1'b0}};
      miss_word_off      <= {WORD_OFFSET_BITS{1'b0}};
      miss_fill_cnt      <= {WORD_OFFSET_BITS{1'b0}};
      miss_base_addr     <= 32'b0;

      invalidate_cache_arrays();
    end else begin

      if (flush) begin
        invalidate_cache_arrays();
        flush_done <= 1'b1;
      end else begin
        flush_done <= 1'b0;
      end

      if (ifu_resp_valid && ifu_resp_ready) begin
        ifu_resp_valid <= 1'b0;
      end

      case (state)
        STATE_IDLE: begin
          mem_arvalid <= 1'b0;
          mem_rready  <= 1'b0;
          mem_arlen   <= uncached ? 8'd0 : 8'(WORDS_PER_LINE - 1);  // Number of beats in a burst (0-based)
          mem_arburst <= uncached ? 2'b00 : 2'b10;  // WRAP burst

          if (ifu_req_valid && ifu_req_ready) begin
            if (uncached) begin
              mem_araddr  <= ifu_req_addr;
              mem_arvalid <= 1'b1;
              state       <= STATE_UNCACHED_AR;
            end else if (hit) begin
              ifu_resp_data  <= hit_word;
              ifu_resp_valid <= 1'b1;
            end else begin
              miss_tag               <= req_tag;
              miss_index             <= req_index;
              miss_word_off          <= req_word_off;
              miss_fill_cnt          <= {WORD_OFFSET_BITS{1'b0}};
              miss_base_addr         <= {ifu_req_addr[31:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
              valid_array[req_index] <= 1'b0;

              mem_araddr             <= {ifu_req_addr[31:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
              mem_arvalid            <= 1'b1;
              state                  <= STATE_MISS_AR;
            end
          end
        end

        STATE_MISS_AR: begin
          if (mem_arvalid && mem_arready) begin
            mem_arvalid <= 1'b0;
            mem_rready  <= 1'b1;
            state       <= STATE_MISS_R;
          end
        end

        STATE_MISS_R: begin
          if (mem_rvalid && mem_rready) begin
            data_array[miss_index][miss_fill_cnt] <= mem_rdata;

            if (miss_fill_cnt == miss_word_off) begin
              ifu_resp_data <= mem_rdata;
            end

            if (mem_rlast || mem_arlen == 0) begin
              mem_rready <= 1'b0;
            end

            // WORDS_PER_LINE perhaps bigger than 1 so need loop here
            if (miss_fill_cnt == WORD_OFFSET_BITS'(WORDS_PER_LINE - 1)) begin
              tag_array[miss_index] <= miss_tag;
              if (flush) begin
                valid_array[miss_index] <= 1'b0;
              end else begin
                valid_array[miss_index] <= 1'b1;
              end
              ifu_resp_valid <= 1'b1;
              state          <= STATE_IDLE;
            end else if (mem_arlen > 0) begin
              miss_fill_cnt <= miss_fill_cnt + 1'b1;
              state         <= STATE_MISS_R;
            end else begin
              miss_fill_cnt <= miss_fill_cnt_next;
              mem_araddr    <= miss_next_araddr;
              mem_arvalid   <= 1'b1;
              state         <= STATE_MISS_AR;
            end
          end
        end
        STATE_UNCACHED_AR: begin
          if (mem_arvalid && mem_arready) begin
            mem_arvalid <= 1'b0;
            mem_rready  <= 1'b1;
            state       <= STATE_UNCACHED_R;
          end
        end

        STATE_UNCACHED_R: begin
          if (mem_rvalid && mem_rready) begin
            ifu_resp_data  <= mem_rdata;
            ifu_resp_valid <= 1'b1;
            mem_rready     <= 1'b0;
            state          <= STATE_IDLE;
          end
        end

        default: begin
          state <= STATE_IDLE;
        end
      endcase
    end
  end

`ifdef PERF
  // PERF-only icache hit/miss stats. Keep this in a separate include so the
  // functional FSM/data path in icache.v stays focused.
`ifndef SYNTHESIS
  longint unsigned        ihit_cnt;
  longint unsigned        imiss_cnt;
  longint unsigned        ihit_lat_cycles;
  longint unsigned        imiss_lat_cycles;

  reg                     perf_miss_pending;
  reg              [31:0] perf_miss_lat_ctr;

  wire                    perf_req_fire;
  wire                    perf_cached_req_fire;
  wire                    perf_miss_resp_issue;

  assign perf_req_fire = ifu_req_valid && ifu_req_ready;
  assign perf_cached_req_fire = perf_req_fire && !uncached;
  assign perf_miss_resp_issue = (state == STATE_MISS_R) && mem_rvalid && mem_rready &&
  (miss_fill_cnt == WORD_OFFSET_BITS'(WORDS_PER_LINE - 1));

  always @(posedge clk) begin
    if (reset) begin
      ihit_cnt          <= 64'd0;
      imiss_cnt         <= 64'd0;
      ihit_lat_cycles   <= 64'd0;
      imiss_lat_cycles  <= 64'd0;
      perf_miss_pending <= 1'b0;
      perf_miss_lat_ctr <= 32'd0;
    end else begin
      // Count requests only when a cached request is accepted.
      if (perf_cached_req_fire) begin
        if (hit) begin
          ihit_cnt        <= ihit_cnt + 64'd1;
          ihit_lat_cycles <= ihit_lat_cycles + 64'd1;
        end else begin
          imiss_cnt         <= imiss_cnt + 64'd1;
          perf_miss_pending <= 1'b1;
          perf_miss_lat_ctr <= 32'd1;
        end
      end

      // Miss latency is measured from miss request accept to response issue.
      if (perf_miss_pending && !perf_miss_resp_issue) begin
        perf_miss_lat_ctr <= perf_miss_lat_ctr + 32'd1;
      end

      if (perf_miss_pending && perf_miss_resp_issue) begin
        imiss_lat_cycles  <= imiss_lat_cycles + perf_miss_lat_ctr;
        perf_miss_pending <= 1'b0;
      end
    end
  end

  export "DPI-C" function get_imiss_cnt;
  function automatic longint unsigned get_imiss_cnt();
    return imiss_cnt;
  endfunction

  export "DPI-C" function get_ihit_cnt;
  function automatic longint unsigned get_ihit_cnt();
    return ihit_cnt;
  endfunction

  export "DPI-C" function get_imiss_lat_cycles;
  function automatic longint unsigned get_imiss_lat_cycles();
    return imiss_lat_cycles;
  endfunction

  export "DPI-C" function get_ihit_lat_cycles;
  function automatic longint unsigned get_ihit_lat_cycles();
    return ihit_lat_cycles;
  endfunction
`endif
`endif

`ifdef FORMAL
  reg f_past_valid = 1'b0;

  always @(posedge clk) begin
    f_past_valid <= 1'b1;

    if (f_past_valid && $past(reset)) begin
      assert (state == STATE_IDLE);
      assert (!ifu_resp_valid);
      assert (!mem_arvalid);
      assert (!mem_rready);
    end

    if (f_past_valid && !$past(reset)) begin
      assert (ifu_req_ready == (state == STATE_IDLE && !ifu_resp_valid));
      assert (mem_arsize == 3'b010);
      assert (state == STATE_IDLE || state == STATE_MISS_AR || state == STATE_MISS_R ||
              state == STATE_UNCACHED_AR || state == STATE_UNCACHED_R);
      assert (!mem_rready || state == STATE_MISS_R || state == STATE_UNCACHED_R);
    end

    if (f_past_valid && !$past(
    reset
    ) && $past(
    state == STATE_IDLE && ifu_req_valid && ifu_req_ready && uncached
    )) begin
      assert (state == STATE_UNCACHED_AR);
      assert (mem_arvalid);
      assert (mem_araddr == $past(ifu_req_addr));
    end

    if (f_past_valid && !$past(
    reset
    ) && $past(
    state == STATE_IDLE && ifu_req_valid && ifu_req_ready && hit
    )) begin
      assert (ifu_resp_valid);
      assert (ifu_resp_data == $past(hit_word));
    end
  end
`endif

endmodule

module ysyx_24110012_vclint (
  input clk,
  input reset,

  // AR
  input wire [31:0] araddr,
  input wire arvalid,
  output reg arready,

  // R
  output wire [31:0] rdata,
  output reg rvalid,
  output reg rlast,
  input wire rready,

  // AW
  input wire [31:0] awaddr,
  input wire awvalid,
  output reg awready,

  // W
  input wire [31:0] wdata,
  input wire [3:0] wstrb,
  input wire wvalid,
  output reg wready,

  // B
  output reg [1:0] bresp,
  output reg bvalid,
  input wire bready
);

  always @(posedge clk) begin
    if (reset) begin
      awready <= 1'b0;
      wready  <= 1'b0;
      bvalid  <= 1'b0;
      bresp   <= 2'b00;
    end else begin
`ifndef SYNTHESIS
      if (awvalid) begin
        assert (awaddr[1:0] == 2'b00)
        else $error("awaddr is %h not 4-byte aligned.", awaddr);
      end
`endif

      if (awvalid) begin
        awready <= 1'b1;
      end else begin
        awready <= 1'b0;
      end

      if (wvalid) begin
        wready <= 1'b1;
      end

      if (wready) begin
        bresp   <= 2'b00;  // OKAY response
        bvalid  <= 1'b1;  // indicate write response is valid
        wready  <= 1'b0;
        awready <= 1'b0;
      end else if (bready) begin
        wready <= 1'b0;
        bvalid <= 1'b0;  // clear bvalid when bready is asserted
      end
    end
  end

  // mtime low word is at 0x48, high word at 0x4c: they differ only in addr bit 2,
  // so only that bit is latched. rdata is driven directly from mtime (no 32-bit
  // rdata register); the LSU samples it at the R handshake.
  reg araddr_hi;
  reg [63:0] mtime;

  assign rdata = araddr_hi ? mtime[63:32] : mtime[31:0];

  // should not be used for uart read in current design
  always @(posedge clk) begin
    if (reset) begin
      arready   <= 1'b0;
      rvalid    <= 1'b0;
      rlast     <= 1'b0;
      araddr_hi <= 1'b0;
      mtime     <= 64'b0;
    end else begin
      mtime <= mtime + 1;
      if (arvalid) begin
        arready   <= 1'b1;
        araddr_hi <= araddr[2];
      end else begin
        arready <= 1'b0;
      end

      if (arvalid && arready) begin
        rvalid  <= 1'b1;
        rlast   <= 1'b1;
        arready <= 1'b0;
      end

      if (rvalid && rready) begin
        rvalid <= 1'b0;
        rlast  <= 1'b0;
      end
    end
  end

endmodule

module ysyx_24110012_ppconn #(
  parameter WIDTH = 32
) (
  input wire clk,
  input wire reset,
  input wire flush,

  //upstream
  input  wire             in_valid,
  output wire             in_ready,
  input  wire [WIDTH-1:0] in_data,

  //downstream
  output reg              out_valid,
  input  wire             out_ready,
  output reg  [WIDTH-1:0] out_data
);

  assign in_ready = !out_valid || out_ready;

  always @(posedge clk) begin
    if (reset || flush) begin
      out_valid <= 1'b0;
    end else if (in_ready) begin
      out_valid <= in_valid;
      if (in_valid) begin
        out_data <= in_data;
      end
    end
  end

endmodule
//`include "pipe_def.svh"

module ysyx_24110012 (
  input clock,
  input reset,
  input io_interrupt,

  // AXI4 Master Interface
  // Write Address Channel
  input         io_master_awready,
  output        io_master_awvalid,
  output [31:0] io_master_awaddr,
  output [ 3:0] io_master_awid,
  output [ 7:0] io_master_awlen,
  output [ 2:0] io_master_awsize,
  output [ 1:0] io_master_awburst,

  // Write Data Channel
  input         io_master_wready,
  output        io_master_wvalid,
  output [31:0] io_master_wdata,
  output [ 3:0] io_master_wstrb,
  output        io_master_wlast,

  // Write Response Channel
  output       io_master_bready,
  input        io_master_bvalid,
  input  [1:0] io_master_bresp,
  input  [3:0] io_master_bid,

  // Read Address Channel
  input         io_master_arready,
  output        io_master_arvalid,
  output [31:0] io_master_araddr,
  output [ 3:0] io_master_arid,
  output [ 7:0] io_master_arlen,
  output [ 2:0] io_master_arsize,
  output [ 1:0] io_master_arburst,

  // Read Data Channel
  output        io_master_rready,
  input         io_master_rvalid,
  input  [ 1:0] io_master_rresp,
  input  [31:0] io_master_rdata,
  input         io_master_rlast,
  input  [ 3:0] io_master_rid,

  // AXI4 Slave Interface
  // Write Address Channel
  output        io_slave_awready,
  input         io_slave_awvalid,
  input  [31:0] io_slave_awaddr,
  input  [ 3:0] io_slave_awid,
  input  [ 7:0] io_slave_awlen,
  input  [ 2:0] io_slave_awsize,
  input  [ 1:0] io_slave_awburst,

  // Write Data Channel
  output        io_slave_wready,
  input         io_slave_wvalid,
  input  [31:0] io_slave_wdata,
  input  [ 3:0] io_slave_wstrb,
  input         io_slave_wlast,

  // Write Response Channel
  input        io_slave_bready,
  output       io_slave_bvalid,
  output [1:0] io_slave_bresp,
  output [3:0] io_slave_bid,

  // Read Address Channel
  output        io_slave_arready,
  input         io_slave_arvalid,
  input  [31:0] io_slave_araddr,
  input  [ 3:0] io_slave_arid,
  input  [ 7:0] io_slave_arlen,
  input  [ 2:0] io_slave_arsize,
  input  [ 1:0] io_slave_arburst,

  // Read Data Channel
  input         io_slave_rready,
  output        io_slave_rvalid,
  output [ 1:0] io_slave_rresp,
  output [31:0] io_slave_rdata,
  output        io_slave_rlast,
  output [ 3:0] io_slave_rid
);

  wire cycle_done, wbu_cycle_done;
  wire lsu_wbu_valid_o, wbu_lsu_ready_i;

`ifndef SYNTHESIS
  reg [31:0] done_inst;
  reg [31:0] done_pc;
  reg [31:0] done_npc;
`ifndef __ICARUS__
  // DPI-C
  // Function to get PC value from C++
  export "DPI-C" function get_pc;
  function int get_pc();
    return done_pc;
  endfunction

  // Function to get NPC value from C++
  export "DPI-C" function get_npc;
  function int get_npc();
    return done_npc;
  endfunction

  // Function to get instruction value from C++
  export "DPI-C" function get_inst;
  function int get_inst();
    return done_inst;
  endfunction


  export "DPI-C" function get_cycle_done;
  function bit get_cycle_done();
    return cycle_done;
  endfunction

  export "DPI-C" function get_lsu_wbu_valid_o;
  function bit get_lsu_wbu_valid_o();
    return lsu_wbu_valid_o;
  endfunction

  import "DPI-C" function void ebreak_catch(
    input int pc,
    input int rdata_x
  );
  // DPI-C end

  // add error handler for AXI illegal access
  always @(posedge clock) begin
    // AXI4 Master Write Response
    if (io_master_bvalid && io_master_bready && io_master_bresp != 2'b00) begin
      $fatal(1, "AXI4 Master Write Response Error: io_master_bresp = %b", io_master_bresp);
    end

    // AXI4 Master Read Response
    if (io_master_rvalid && io_master_rready && io_master_rresp != 2'b00) begin
      $fatal(1, "AXI4 Master Read Response Error: io_master_rresp = %b", io_master_rresp);
    end

    // AXI4 Slave Write Response
    if (io_slave_bvalid && io_slave_bready && io_slave_bresp != 2'b00) begin
      $fatal(1, "AXI4 Slave Write Response Error: io_slave_bresp = %b", io_slave_bresp);
    end

    // AXI4 Slave Read Response
    if (io_slave_rvalid && io_slave_rready && io_slave_rresp != 2'b00) begin
      $fatal(1, "AXI4 Slave Read Response Error: io_slave_rresp = %b", io_slave_rresp);
    end
  end
`endif
`endif

  assign cycle_done = wbu_cycle_done;

  // IFU AR/R
  wire [31:0] ifu_araddr, ifu_rdata;
  wire ifu_arvalid, ifu_arready, ifu_rvalid, ifu_rready;
  wire [2:0] ifu_arsize;

  // IFU AW/W/B
  wire [31:0] ifu_awaddr, ifu_wdata;
  wire ifu_awvalid, ifu_awready, ifu_wvalid, ifu_wready, ifu_bvalid, ifu_bready;
  wire [3:0] ifu_wstrb;
  wire [1:0] ifu_bresp;
  wire [2:0] ifu_awsize;

  // pipeline stage handshake
  wire ifu_idu_valid_i, idu_ifu_ready_i;
  wire ifu_idu_valid_o, idu_ifu_ready_o;

  // wires from WBU & EXU for redirect
  wire wbu_redirect;
  wire [31:0] wbu_ifu_npc;
  wire exu_redirect;
  wire [31:0] exu_redirect_pc;

  wire redirect = wbu_redirect | exu_redirect;
  wire [31:0] redirect_pc = wbu_redirect ? wbu_ifu_npc : exu_redirect_pc;

  wire [31:0] ifu_idu_pc_o;
  wire [31:0] ifu_idu_inst_o;
  wire ifu_idu_cycle_done_o;
  wire icache_flush_done;

  // Wires from WBU
  wire wbu_fencei;

  ysyx_24110012_ifu my_ifu (
  .clk       (clock),
  .reset     (reset),
  .cycle_done(cycle_done),


  .ifu_idu_pc        (ifu_idu_pc_o),
  .ifu_idu_inst      (ifu_idu_inst_o),
  .ifu_idu_cycle_done(ifu_idu_cycle_done_o),

  .ifu_idu_valid(ifu_idu_valid_i),
  .idu_ifu_ready(idu_ifu_ready_o),

  .wbu_ifu_npc (redirect_pc),
  .wbu_redirect(redirect),
  .flush       (wbu_fencei),

  .araddr (ifu_araddr),
  .arvalid(ifu_arvalid),
  .arsize (ifu_arsize),
  .arready(ifu_arready),
  .rdata  (ifu_rdata),
  .rvalid (ifu_rvalid),
  .rready (ifu_rready),
  .awaddr (ifu_awaddr),
  .awvalid(ifu_awvalid),
  .awsize (ifu_awsize),
  .awready(ifu_awready),
  .wdata  (ifu_wdata),
  .wstrb  (ifu_wstrb),
  .wvalid (ifu_wvalid),
  .wready (ifu_wready),
  .bresp  (ifu_bresp),
  .bvalid (ifu_bvalid),
  .bready (ifu_bready)
  );

  // ICACHE <-> MEM AR/R
  wire [31:0] icache_araddr, icache_rdata;
  wire icache_arvalid, icache_arready, icache_rvalid, icache_rready, icache_rlast;
  wire [2:0] icache_arsize;
  wire [1:0] icache_arburst;
  wire [7:0] icache_arlen;

// synthesis should never defines it
`ifdef ICACHE_SIM_LARGE
  localparam integer ICACHE_BLOCK_BYTES = 32;
  localparam integer ICACHE_NUM_LINES = 128;
`else
  localparam integer ICACHE_BLOCK_BYTES = 8;
  localparam integer ICACHE_NUM_LINES = 4;
`endif

  ysyx_24110012_icache #(
  .BLOCK_BYTES(ICACHE_BLOCK_BYTES),
  .NUM_LINES  (ICACHE_NUM_LINES)
  ) my_icache (
  .clk           (clock),
  .reset         (reset),
  .flush         (wbu_fencei),
  .flush_done    (icache_flush_done),
  .ifu_req_valid (ifu_arvalid),
  .ifu_req_ready (ifu_arready),
  .ifu_req_addr  (ifu_araddr),
  .ifu_resp_valid(ifu_rvalid),
  .ifu_resp_ready(ifu_rready),
  .ifu_resp_data (ifu_rdata),
  .mem_araddr    (icache_araddr),
  .mem_arvalid   (icache_arvalid),
  .mem_arburst   (icache_arburst),
  .mem_arlen     (icache_arlen),
  .mem_arsize    (icache_arsize),
  .mem_arready   (icache_arready),
  .mem_rdata     (icache_rdata),
  .mem_rvalid    (icache_rvalid),
  .mem_rlast     (icache_rlast),
  .mem_rready    (icache_rready)
  );

  wire [31:0] rf_idu_rs1, rf_idu_rs2, rf_idu_reg_x;
  wire [31:0] hazard_idu_rs1, hazard_idu_rs2;
  wire [31:0] rf_idu_csr_rdata;
  wire [11:0] idu_rf_csr_idx;
  wire [3:0] idu_rs1_idx, idu_rs2_idx;

  // wires from WBU
  wire [11:0] wbu_rf_csr_idx;
  wire [3:0] wbu_rf_idx;
  wire [31:0] wbu_rf_wdata;
  wire [31:0] wbu_csr_wdata;
  wire wbu_rf_reg_wen;
  wire wbu_rf_csr_wen;

  wire [31:0] exu_lsu_result_o;
  wire [31:0] lsu_wbu_wdata_o;
  wire hazard_raw_stall;
  wire [31:0] hazard_ex_wdata = exu_lsu_result_o;
  wire [31:0] hazard_ls_wdata = lsu_wbu_wdata_o;
  wire [31:0] hazard_wb_wdata = wbu_rf_wdata;

  ysyx_24110012_GPR_CSR_File #(4, 32, 12, 32) regfile (
  .clk  (clock),
  .reset(reset),

  .rf_wen (wbu_rf_reg_wen),
  .rd_idx (wbu_rf_idx),
  .rd     (wbu_rf_wdata),
  .rs1_idx(idu_rs1_idx),
  .rs2_idx(idu_rs2_idx),
  .rs1    (rf_idu_rs1),
  .rs2    (rf_idu_rs2),
  .rdata_x(rf_idu_reg_x),

  .csr_wen  (wbu_rf_csr_wen),
  .csr_w_idx(wbu_rf_csr_idx),
  .csr_r_idx(idu_rf_csr_idx),
  .csr_wdata(wbu_csr_wdata),
  .csr_rdata(rf_idu_csr_rdata)
  );

  wire idu_exu_valid_o, exu_idu_ready_o;
  wire exu_lsu_reg_wen_o;
  wire exu_lsu_branch_o, exu_lsu_jump_o, exu_lsu_wb_from_mem_o, exu_lsu_csr_wen_o;
  wire exu_lsu_valid_o, lsu_exu_ready_i;
  wire exu_lsu_branch_i, exu_lsu_jump_i, exu_lsu_wb_from_mem_i, exu_lsu_csr_wen_i;
  wire exu_lsu_reg_wen_i;
  wire [ 3:0] exu_lsu_rd_idx_i;

  id_ex_packet_t id_ex_packet_i, id_ex_packet_o;

  ysyx_24110012_hazard #(
  .ADDR_WIDTH(4),
  .DATA_WIDTH(32)
  ) my_hazard (
  .rs1_idx(idu_rs1_idx),
  .rs2_idx(idu_rs2_idx),
  .rs1_rf (rf_idu_rs1),
  .rs2_rf (rf_idu_rs2),

  .ex_valid  (idu_exu_valid_o),
  .ex_wen    (exu_lsu_reg_wen_o),
  .ex_is_load(exu_lsu_wb_from_mem_o),
  .ex_rd_idx (id_ex_packet_o.rd_idx),
  .ex_wdata  (hazard_ex_wdata),

  .ls_valid  (exu_lsu_valid_o),
  .ls_wen    (exu_lsu_reg_wen_i),
  .ls_is_load(exu_lsu_wb_from_mem_i),
  .ls_rd_idx (exu_lsu_rd_idx_i),
  .ls_wdata  (hazard_ls_wdata),

  .wb_valid (lsu_wbu_valid_o),
  .wb_wen   (wbu_rf_reg_wen),
  .wb_rd_idx(wbu_rf_idx),
  .wb_wdata (hazard_wb_wdata),

  .rs1_fwd  (hazard_idu_rs1),
  .rs2_fwd  (hazard_idu_rs2),
  .raw_stall(hazard_raw_stall)
  );

  wire [31:0] ifu_idu_pc_i;
  wire [31:0] ifu_idu_inst_i;
  wire ifu_idu_cycle_done_i;

  if_id_packet_t if_id_packet_i, if_id_packet_o;

  assign if_id_packet_i.pc         = ifu_idu_pc_o;
  assign if_id_packet_i.inst       = ifu_idu_inst_o;
  assign if_id_packet_i.cycle_done = ifu_idu_cycle_done_o;
  ysyx_24110012_ppconn #(
  .WIDTH($bits(if_id_packet_i))
  ) if_id_ppconn (
  .clk  (clock),
  .reset(reset),
  .flush(redirect | wbu_fencei),

  .in_valid(ifu_idu_valid_i),
  .in_ready(idu_ifu_ready_o),
  .in_data (if_id_packet_i),

  .out_valid(ifu_idu_valid_o),
  .out_ready(idu_ifu_ready_i),
  .out_data (if_id_packet_o)
  );

  assign ifu_idu_pc_i         = if_id_packet_o.pc;
  assign ifu_idu_inst_i       = if_id_packet_o.inst;
  assign ifu_idu_cycle_done_i = if_id_packet_o.cycle_done;

  // pipeline stage handshake for idu/exu
  wire idu_exu_valid_i, exu_idu_ready_i;
  wire my_idu_exu_valid, my_idu_ifu_ready;

  wire [31:0] idu_exu_pc_o;
  wire [ 6:0] idu_exu_opcode_o;
  wire [ 2:0] idu_exu_func3_o;
  wire [ 6:0] idu_exu_func7_o;
  wire [31:0] idu_exu_rs1_o, idu_exu_rs2_o;
  wire [ 3:0] idu_exu_rd_idx_o;
  wire [31:0] idu_exu_imm_o;
  wire [11:0] idu_exu_csr_idx_o;
  wire [31:0] idu_exu_csr_rdata_o;
  wire idu_exu_ecall_o, idu_exu_mret_o, idu_exu_fencei_o, idu_exu_cycle_done_o;

  /* generate addr for rs1 rs2 rd and
   * func imm values */
  ysyx_24110012_idu my_idu (

  .ifu_idu_pc        (ifu_idu_pc_i),
  .ifu_idu_inst      (ifu_idu_inst_i),
  .ifu_idu_cycle_done(ifu_idu_cycle_done_i),

  .ifu_idu_valid(ifu_idu_valid_o),
  .idu_ifu_ready(my_idu_ifu_ready),

  // get rs values from rf
  .idu_rf_rs1_idx  (idu_rs1_idx),
  .idu_rf_rs2_idx  (idu_rs2_idx),
  .idu_rf_csr_idx  (idu_rf_csr_idx),
  .rf_idu_rs1      (hazard_idu_rs1),
  .rf_idu_rs2      (hazard_idu_rs2),
  .rf_idu_csr_rdata(rf_idu_csr_rdata),

  .idu_exu_pc        (idu_exu_pc_o),
  .idu_exu_opcode    (idu_exu_opcode_o),
  .idu_exu_func3     (idu_exu_func3_o),
  .idu_exu_func7     (idu_exu_func7_o),
  .idu_exu_imm       (idu_exu_imm_o),
  .idu_exu_rs1       (idu_exu_rs1_o),
  .idu_exu_rs2       (idu_exu_rs2_o),
  .idu_exu_rd_idx    (idu_exu_rd_idx_o),
  .idu_exu_csr_idx   (idu_exu_csr_idx_o),
  .idu_exu_csr_rdata (idu_exu_csr_rdata_o),
  .idu_exu_ecall     (idu_exu_ecall_o),
  .idu_exu_mret      (idu_exu_mret_o),
  .idu_exu_fencei    (idu_exu_fencei_o),
  .idu_exu_cycle_done(idu_exu_cycle_done_o),

  .idu_exu_valid(my_idu_exu_valid),
  .exu_idu_ready(exu_idu_ready_o)
  );

  ex_ls_packet_t ex_ls_packet_i, ex_ls_packet_o;
  ls_wb_packet_t ls_wb_packet_i, ls_wb_packet_o;

  wire priv_stall = (idu_exu_valid_o && (id_ex_packet_o.ecall || id_ex_packet_o.mret)) ||
  (exu_lsu_valid_o && (ex_ls_packet_o.ecall || ex_ls_packet_o.mret)) ||
  (lsu_wbu_valid_o && (ls_wb_packet_o.ecall || ls_wb_packet_o.mret));

  wire hazard_stall = hazard_raw_stall;

  assign idu_ifu_ready_i = my_idu_ifu_ready & !priv_stall & !hazard_stall;
  assign idu_exu_valid_i = my_idu_exu_valid & !priv_stall & !hazard_stall;


  assign id_ex_packet_i.pc = idu_exu_pc_o;
`ifndef SYNTHESIS
  assign id_ex_packet_i.inst = ifu_idu_inst_i;
`endif
  assign id_ex_packet_i.opcode     = idu_exu_opcode_o;
  assign id_ex_packet_i.func3      = idu_exu_func3_o;
  assign id_ex_packet_i.func7      = idu_exu_func7_o;
  assign id_ex_packet_i.imm        = idu_exu_imm_o;
  assign id_ex_packet_i.rs1        = idu_exu_rs1_o;
  assign id_ex_packet_i.rs2        = idu_exu_rs2_o;
  assign id_ex_packet_i.rd_idx     = idu_exu_rd_idx_o;
  assign id_ex_packet_i.csr_idx    = idu_exu_csr_idx_o;
  assign id_ex_packet_i.csr_rdata  = idu_exu_csr_rdata_o;
  assign id_ex_packet_i.ecall      = idu_exu_ecall_o;
  assign id_ex_packet_i.mret       = idu_exu_mret_o;
  assign id_ex_packet_i.fencei     = idu_exu_fencei_o;
  assign id_ex_packet_i.cycle_done = idu_exu_cycle_done_o;

  ysyx_24110012_ppconn #(
  .WIDTH($bits(id_ex_packet_i))
  ) id_ex_ppconn (
  .clk  (clock),
  .reset(reset),
  .flush(redirect | wbu_fencei),

  .in_valid(idu_exu_valid_i),
  .in_ready(exu_idu_ready_o),
  .in_data (id_ex_packet_i),

  .out_valid(idu_exu_valid_o),
  .out_ready(exu_idu_ready_i),
  .out_data (id_ex_packet_o)
  );

  wire [31:0] idu_exu_pc_i;
  wire [ 6:0] idu_exu_opcode_i;
  wire [ 2:0] idu_exu_func3_i;
  wire [ 6:0] idu_exu_func7_i;
  wire [31:0] idu_exu_rs1_i, idu_exu_rs2_i;
  wire [ 3:0] idu_exu_rd_idx_i;
  wire [31:0] idu_exu_imm_i;
  wire [11:0] idu_exu_csr_idx_i;
  wire [31:0] idu_exu_csr_rdata_i;
  wire idu_exu_ecall_i, idu_exu_mret_i, idu_exu_fencei_i, idu_exu_cycle_done_i;

  assign idu_exu_pc_i         = id_ex_packet_o.pc;
  assign idu_exu_opcode_i     = id_ex_packet_o.opcode;
  assign idu_exu_func3_i      = id_ex_packet_o.func3;
  assign idu_exu_func7_i      = id_ex_packet_o.func7;
  assign idu_exu_imm_i        = id_ex_packet_o.imm;
  assign idu_exu_rs1_i        = id_ex_packet_o.rs1;
  assign idu_exu_rs2_i        = id_ex_packet_o.rs2;
  assign idu_exu_rd_idx_i     = id_ex_packet_o.rd_idx;
  assign idu_exu_csr_idx_i    = id_ex_packet_o.csr_idx;
  assign idu_exu_csr_rdata_i  = id_ex_packet_o.csr_rdata;
  assign idu_exu_ecall_i      = id_ex_packet_o.ecall;
  assign idu_exu_mret_i       = id_ex_packet_o.mret;
  assign idu_exu_fencei_i     = id_ex_packet_o.fencei;
  assign idu_exu_cycle_done_i = id_ex_packet_o.cycle_done;

  wire exu_lsu_valid_i, lsu_exu_ready_o;
  wire [31:0] exu_lsu_rs2_o, exu_lsu_npc_o;
  wire [ 3:0] exu_lsu_rd_idx_o;
  wire [11:0] exu_lsu_csr_idx_o;
  wire [31:0] exu_lsu_csr_rdata_o;
  wire exu_lsu_ecall_o, exu_lsu_mret_o, exu_lsu_fencei_o, exu_lsu_cycle_done_o;
  wire exu_lsu_mem_w_o, exu_lsu_mem_r_o;
  wire [2:0] exu_lsu_mem_mask_o;
  wire exu_lsu_mem_sign_ext_o;
  wire [2:0] exu_lsu_func3_o;

  ysyx_24110012_exu my_exu (

  .idu_exu_pc        (idu_exu_pc_i),
  .idu_exu_opcode    (idu_exu_opcode_i),
  .idu_exu_func3     (idu_exu_func3_i),
  .idu_exu_func7     (idu_exu_func7_i),
  .idu_exu_imm       (idu_exu_imm_i),
  .idu_exu_rs1       (idu_exu_rs1_i),
  .idu_exu_rs2       (idu_exu_rs2_i),
  .idu_exu_rd_idx    (idu_exu_rd_idx_i),
  .idu_exu_csr_idx   (idu_exu_csr_idx_i),
  .idu_exu_csr_rdata (idu_exu_csr_rdata_i),
  .idu_exu_ecall     (idu_exu_ecall_i),
  .idu_exu_mret      (idu_exu_mret_i),
  .idu_exu_fencei    (idu_exu_fencei_i),
  .idu_exu_cycle_done(idu_exu_cycle_done_i),

  .idu_exu_valid(idu_exu_valid_o),
  .exu_idu_ready(exu_idu_ready_i),

  .exu_lsu_reg_wen     (exu_lsu_reg_wen_o),
  .exu_lsu_mem_w       (exu_lsu_mem_w_o),
  .exu_lsu_mem_r       (exu_lsu_mem_r_o),
  .exu_lsu_mem_sign_ext(exu_lsu_mem_sign_ext_o),
  .exu_lsu_mem_mask    (exu_lsu_mem_mask_o),
  .exu_lsu_func3       (exu_lsu_func3_o),
  .exu_lsu_result      (exu_lsu_result_o),
  .exu_lsu_rs2         (exu_lsu_rs2_o),
  .exu_lsu_rd_idx      (exu_lsu_rd_idx_o),
  .exu_lsu_csr_idx     (exu_lsu_csr_idx_o),
  .exu_lsu_csr_rdata   (exu_lsu_csr_rdata_o),
  .exu_lsu_ecall       (exu_lsu_ecall_o),
  .exu_lsu_mret        (exu_lsu_mret_o),
  .exu_lsu_fencei      (exu_lsu_fencei_o),
  .exu_lsu_branch      (exu_lsu_branch_o),
  .exu_lsu_jump        (exu_lsu_jump_o),
  .exu_lsu_wb_from_mem (exu_lsu_wb_from_mem_o),
  .exu_lsu_csr_wen     (exu_lsu_csr_wen_o),
  .exu_lsu_npc         (exu_lsu_npc_o),
  .exu_lsu_cycle_done  (exu_lsu_cycle_done_o),

  .exu_lsu_valid(exu_lsu_valid_i),
  .lsu_exu_ready(lsu_exu_ready_o)
  );

  assign exu_redirect = idu_exu_valid_o && lsu_exu_ready_o && (exu_lsu_branch_o || exu_lsu_jump_o);
  assign exu_redirect_pc = exu_lsu_npc_o;

  wire lsu_arvalid, lsu_arready, lsu_rvalid, lsu_rready;
  wire [31:0] lsu_araddr, lsu_rdata;
  wire lsu_awrvalid, lsu_awrready, lsu_wvalid, lsu_wready;
  wire [31:0] lsu_awaddr, lsu_wdata;
  wire [3:0] lsu_wstrb;
  wire [1:0] lsu_bresp;
  wire [2:0] lsu_arsize, lsu_awsize;
  wire lsu_bvalid, lsu_bready;


`ifndef SYNTHESIS
  assign ex_ls_packet_i.pc   = idu_exu_pc_i;
  assign ex_ls_packet_i.inst = id_ex_packet_o.inst;
`endif
  assign ex_ls_packet_i.reg_wen      = exu_lsu_reg_wen_o;
  assign ex_ls_packet_i.mem_w        = exu_lsu_mem_w_o;
  assign ex_ls_packet_i.mem_r        = exu_lsu_mem_r_o;
  assign ex_ls_packet_i.mem_sign_ext = exu_lsu_mem_sign_ext_o;
  assign ex_ls_packet_i.mem_mask     = exu_lsu_mem_mask_o;
  assign ex_ls_packet_i.func3        = exu_lsu_func3_o;
  assign ex_ls_packet_i.result       = exu_lsu_result_o;
  assign ex_ls_packet_i.rs2          = exu_lsu_rs2_o;
  assign ex_ls_packet_i.rd_idx       = exu_lsu_rd_idx_o;
  assign ex_ls_packet_i.csr_idx      = exu_lsu_csr_idx_o;
  assign ex_ls_packet_i.csr_rdata    = exu_lsu_csr_rdata_o;
  assign ex_ls_packet_i.ecall        = exu_lsu_ecall_o;
  assign ex_ls_packet_i.mret         = exu_lsu_mret_o;
  assign ex_ls_packet_i.fencei       = exu_lsu_fencei_o;
  assign ex_ls_packet_i.branch       = exu_lsu_branch_o;
  assign ex_ls_packet_i.jump         = exu_lsu_jump_o;
  assign ex_ls_packet_i.wb_from_mem  = exu_lsu_wb_from_mem_o;
  assign ex_ls_packet_i.csr_wen      = exu_lsu_csr_wen_o;
`ifndef SYNTHESIS
  assign ex_ls_packet_i.npc          = exu_lsu_npc_o;
`endif
  assign ex_ls_packet_i.cycle_done   = exu_lsu_cycle_done_o;

  ysyx_24110012_ppconn #(
  .WIDTH($bits(ex_ls_packet_i))
  ) ex_ls_ppconn (
  .clk  (clock),
  .reset(reset),
  .flush(wbu_redirect | wbu_fencei),

  .in_valid(exu_lsu_valid_i),
  .in_ready(lsu_exu_ready_o),
  .in_data (ex_ls_packet_i),

  .out_valid(exu_lsu_valid_o),
  .out_ready(lsu_exu_ready_i),
  .out_data (ex_ls_packet_o)
  );

  wire [31:0] exu_lsu_rs2_i;
  wire [31:0] exu_lsu_result_i;
  wire [11:0] exu_lsu_csr_idx_i;
  wire [31:0] exu_lsu_csr_rdata_i;
  wire exu_lsu_ecall_i, exu_lsu_mret_i, exu_lsu_fencei_i, exu_lsu_cycle_done_i;
  wire exu_lsu_mem_w_i, exu_lsu_mem_r_i;
  wire [2:0] exu_lsu_mem_mask_i;
  wire exu_lsu_mem_sign_ext_i;
  wire [2:0] exu_lsu_func3_i;

  assign exu_lsu_reg_wen_i      = ex_ls_packet_o.reg_wen;
  assign exu_lsu_mem_w_i        = ex_ls_packet_o.mem_w;
  assign exu_lsu_mem_r_i        = ex_ls_packet_o.mem_r;
  assign exu_lsu_mem_sign_ext_i = ex_ls_packet_o.mem_sign_ext;
  assign exu_lsu_mem_mask_i     = ex_ls_packet_o.mem_mask;
  assign exu_lsu_func3_i        = ex_ls_packet_o.func3;
  assign exu_lsu_result_i       = ex_ls_packet_o.result;
  assign exu_lsu_rs2_i          = ex_ls_packet_o.rs2;
  assign exu_lsu_rd_idx_i       = ex_ls_packet_o.rd_idx;
  assign exu_lsu_csr_idx_i      = ex_ls_packet_o.csr_idx;
  assign exu_lsu_csr_rdata_i    = ex_ls_packet_o.csr_rdata;
  assign exu_lsu_ecall_i        = ex_ls_packet_o.ecall;
  assign exu_lsu_mret_i         = ex_ls_packet_o.mret;
  assign exu_lsu_fencei_i       = ex_ls_packet_o.fencei;
  assign exu_lsu_branch_i       = ex_ls_packet_o.branch;
  assign exu_lsu_jump_i         = ex_ls_packet_o.jump;
  assign exu_lsu_wb_from_mem_i  = ex_ls_packet_o.wb_from_mem;
  assign exu_lsu_csr_wen_i      = ex_ls_packet_o.csr_wen;
  assign exu_lsu_cycle_done_i   = ex_ls_packet_o.cycle_done;

  wire lsu_wbu_valid_i, wbu_lsu_ready_o;
  wire [31:0] lsu_wbu_csr_rdata_o;
  wire [ 3:0] lsu_wbu_rd_idx_o;
  wire [11:0] lsu_wbu_csr_idx_o;
  wire [ 2:0] lsu_wbu_func3_o;
  wire lsu_wbu_reg_wen_o, lsu_wbu_ecall_o, lsu_wbu_mret_o, lsu_wbu_fencei_o, lsu_wbu_cycle_done_o;
  wire lsu_wbu_branch_o, lsu_wbu_csr_wen_o; //lsu_wbu_jump_o,

  ysyx_24110012_lsu my_lsu (
  .clk(clock),
  .reset(reset),

  .exu_lsu_reg_wen     (exu_lsu_reg_wen_i),
  .exu_lsu_mem_w       (exu_lsu_mem_w_i),
  .exu_lsu_mem_r       (exu_lsu_mem_r_i),
  .exu_lsu_mem_sign_ext(exu_lsu_mem_sign_ext_i),
  .exu_lsu_mem_mask    (exu_lsu_mem_mask_i),
  .exu_lsu_mem_addr    (exu_lsu_result_i),
  .exu_lsu_func3       (exu_lsu_func3_i),
  .exu_lsu_result      (exu_lsu_result_i),
  .exu_lsu_mem_wdata   (exu_lsu_rs2_i),
  .exu_lsu_rd_idx      (exu_lsu_rd_idx_i),
  .exu_lsu_csr_idx     (exu_lsu_csr_idx_i),
  .exu_lsu_csr_rdata   (exu_lsu_csr_rdata_i),
  .exu_lsu_ecall       (exu_lsu_ecall_i),
  .exu_lsu_mret        (exu_lsu_mret_i),
  .exu_lsu_fencei      (exu_lsu_fencei_i),
  .exu_lsu_branch      (exu_lsu_branch_i),
  .exu_lsu_jump        (exu_lsu_jump_i),
  .exu_lsu_wb_from_mem (exu_lsu_wb_from_mem_i),
  .exu_lsu_csr_wen     (exu_lsu_csr_wen_i),
  .exu_lsu_cycle_done  (exu_lsu_cycle_done_i),

  .exu_lsu_valid(exu_lsu_valid_o),
  .lsu_exu_ready(lsu_exu_ready_i),

  .lsu_wbu_reg_wen   (lsu_wbu_reg_wen_o),
  .lsu_wbu_func3     (lsu_wbu_func3_o),
  .lsu_wbu_wdata     (lsu_wbu_wdata_o),
  .lsu_wbu_rd_idx    (lsu_wbu_rd_idx_o),
  .lsu_wbu_csr_idx   (lsu_wbu_csr_idx_o),
  .lsu_wbu_csr_rdata (lsu_wbu_csr_rdata_o),
  .lsu_wbu_ecall     (lsu_wbu_ecall_o),
  .lsu_wbu_mret      (lsu_wbu_mret_o),
  .lsu_wbu_fencei    (lsu_wbu_fencei_o),
  .lsu_wbu_branch    (lsu_wbu_branch_o),
  //.lsu_wbu_jump      (lsu_wbu_jump_o),
  .lsu_wbu_csr_wen   (lsu_wbu_csr_wen_o),
  .lsu_wbu_cycle_done(lsu_wbu_cycle_done_o),

  .lsu_wbu_valid(lsu_wbu_valid_i),
  .wbu_lsu_ready(wbu_lsu_ready_o),

  .araddr (lsu_araddr),
  .arvalid(lsu_arvalid),
  .arsize (lsu_arsize),
  .arready(lsu_arready),
  .rdata  (lsu_rdata),
  .rvalid (lsu_rvalid),
  .rready (lsu_rready),
  .awaddr (lsu_awaddr),
  .awvalid(lsu_awrvalid),
  .awsize (lsu_awsize),
  .awready(lsu_awrready),
  .wdata  (lsu_wdata),
  .wstrb  (lsu_wstrb),
  .wvalid (lsu_wvalid),
  .wready (lsu_wready),
  .bresp  (lsu_bresp),
  .bvalid (lsu_bvalid),
  .bready (lsu_bready)
  );


`ifndef SYNTHESIS
  assign ls_wb_packet_i.pc   = ex_ls_packet_o.pc;
  assign ls_wb_packet_i.inst = ex_ls_packet_o.inst;
`endif
  assign ls_wb_packet_i.reg_wen    = lsu_wbu_reg_wen_o;
  assign ls_wb_packet_i.func3      = lsu_wbu_func3_o;
  assign ls_wb_packet_i.wdata      = lsu_wbu_wdata_o;
  assign ls_wb_packet_i.rd_idx     = lsu_wbu_rd_idx_o;
  assign ls_wb_packet_i.csr_idx    = lsu_wbu_csr_idx_o;
  assign ls_wb_packet_i.csr_rdata  = lsu_wbu_csr_rdata_o;
  assign ls_wb_packet_i.ecall      = lsu_wbu_ecall_o;
  assign ls_wb_packet_i.mret       = lsu_wbu_mret_o;
  assign ls_wb_packet_i.fencei     = lsu_wbu_fencei_o;
  assign ls_wb_packet_i.branch     = lsu_wbu_branch_o;
  //assign ls_wb_packet_i.jump       = lsu_wbu_jump_o;
  assign ls_wb_packet_i.csr_wen    = lsu_wbu_csr_wen_o;
`ifndef SYNTHESIS
  assign ls_wb_packet_i.npc        = ex_ls_packet_o.npc;  // npc bypasses LSU, difftest only
`endif
  assign ls_wb_packet_i.cycle_done = lsu_wbu_cycle_done_o;

  ysyx_24110012_ppconn #(
  .WIDTH($bits(ls_wb_packet_i))
  ) ls_wb_ppconn (
  .clk  (clock),
  .reset(reset),
  // not flushed by fence.i: fence.i stays in WB until icache flush is done,
  // then retires normally and redirects to pc+4
  .flush(wbu_redirect),

  .in_valid(lsu_wbu_valid_i),
  .in_ready(wbu_lsu_ready_o),
  .in_data (ls_wb_packet_i),

  .out_valid(lsu_wbu_valid_o),
  .out_ready(wbu_lsu_ready_i),
  .out_data (ls_wb_packet_o)
  );

  wire [31:0] lsu_wbu_wdata_i, lsu_wbu_csr_rdata_i;
  wire [ 3:0] lsu_wbu_rd_idx_i;
  wire [11:0] lsu_wbu_csr_idx_i;
  wire [ 2:0] lsu_wbu_func3_i;
  wire lsu_wbu_reg_wen_i, lsu_wbu_ecall_i, lsu_wbu_mret_i, lsu_wbu_fencei_i, lsu_wbu_cycle_done_i;
  wire lsu_wbu_branch_i, lsu_wbu_csr_wen_i; //lsu_wbu_jump_i;

  assign lsu_wbu_reg_wen_i    = ls_wb_packet_o.reg_wen;
  assign lsu_wbu_func3_i      = ls_wb_packet_o.func3;
  assign lsu_wbu_wdata_i      = ls_wb_packet_o.wdata;
  assign lsu_wbu_rd_idx_i     = ls_wb_packet_o.rd_idx;
  assign lsu_wbu_csr_idx_i    = ls_wb_packet_o.csr_idx;
  assign lsu_wbu_csr_rdata_i  = ls_wb_packet_o.csr_rdata;
  assign lsu_wbu_ecall_i      = ls_wb_packet_o.ecall;
  assign lsu_wbu_mret_i       = ls_wb_packet_o.mret;
  assign lsu_wbu_fencei_i     = ls_wb_packet_o.fencei;
  assign lsu_wbu_branch_i     = ls_wb_packet_o.branch;
  //assign lsu_wbu_jump_i       = ls_wb_packet_o.jump;
  assign lsu_wbu_csr_wen_i    = ls_wb_packet_o.csr_wen;
  assign lsu_wbu_cycle_done_i = ls_wb_packet_o.cycle_done;

  ysyx_24110012_wbu my_wbu (
  .clk  (clock),
  .reset(reset),

  .lsu_wbu_reg_wen   (lsu_wbu_reg_wen_i),
  .lsu_wbu_func3     (lsu_wbu_func3_i),
  .lsu_wbu_wdata     (lsu_wbu_wdata_i),
  .lsu_wbu_rd_idx    (lsu_wbu_rd_idx_i),
  .lsu_wbu_csr_idx   (lsu_wbu_csr_idx_i),
  .lsu_wbu_csr_rdata (lsu_wbu_csr_rdata_i),
  .lsu_wbu_ecall     (lsu_wbu_ecall_i),
  .lsu_wbu_mret      (lsu_wbu_mret_i),
  .lsu_wbu_fencei    (lsu_wbu_fencei_i),
  .lsu_wbu_branch    (lsu_wbu_branch_i),
  //.lsu_wbu_jump      (lsu_wbu_jump_i),
  .lsu_wbu_csr_wen   (lsu_wbu_csr_wen_i),
  .lsu_wbu_cycle_done(lsu_wbu_cycle_done_i),

  .lsu_wbu_valid(lsu_wbu_valid_o),
  .wbu_lsu_ready(wbu_lsu_ready_i),

  .wbu_rf_wdata  (wbu_rf_wdata),
  .wbu_csr_wdata (wbu_csr_wdata),
  .wbu_rf_idx    (wbu_rf_idx),
  .wbu_rf_csr_idx(wbu_rf_csr_idx),
  .wbu_rf_csr_wen(wbu_rf_csr_wen),
  .wbu_rf_reg_wen(wbu_rf_reg_wen),
  .wbu_ifu_pc    (wbu_ifu_npc),
  .wbu_redirect  (wbu_redirect),
  .wbu_fencei    (wbu_fencei),
  .wbu_cycle_done(wbu_cycle_done),

  .icache_flush_done(icache_flush_done)
  );

`ifndef SYNTHESIS
  localparam [31:0] EBREAK = 32'h00100073;
  always @(posedge clock) begin
    if (lsu_wbu_valid_o && wbu_lsu_ready_i) begin
      done_inst <= ls_wb_packet_o.inst;
      done_pc   <= ls_wb_packet_o.pc;
      if (ls_wb_packet_o.ecall || ls_wb_packet_o.mret) begin
        done_npc <= ls_wb_packet_o.csr_rdata;
      end else begin
        done_npc <= ls_wb_packet_o.npc + 32'd4;
      end
      if (ls_wb_packet_o.inst == EBREAK) begin
`ifndef __ICARUS__
        ebreak_catch(ls_wb_packet_o.pc, rf_idu_reg_x);
`endif
      end
    end
    // if (cycle_done) begin
    //   $display("done_pc = 0x%08h, done_inst = 0x%08h", done_pc, done_inst);
    // end
  end
`endif

  // AXI arbiter
  parameter NUM_MASTERS = 2'b10;
  //parameter MASTER_INDEX_WIDTH = NUM_MASTERS == 1 ? 1 : $clog2(NUM_MASTERS);
  //wire [MASTER_INDEX_WIDTH-1:0] mem_r_grant;

  wire [NUM_MASTERS-1:0] m_arb_awvalid, m_arb_awready, m_arb_wvalid, m_arb_wready, m_arb_bvalid,
  m_arb_bready;
  wire [NUM_MASTERS-1:0][1:0] m_arb_bresp;
  wire [NUM_MASTERS-1:0][31:0] m_arb_awaddr, m_arb_wdata;
  wire [NUM_MASTERS-1:0][3:0] m_arb_wstrb;
  wire [NUM_MASTERS-1:0] m_arb_arvalid, m_arb_arready, m_arb_rvalid, m_arb_rready;
  wire [NUM_MASTERS-1:0][31:0] m_arb_araddr, m_arb_rdata;
  wire [NUM_MASTERS-1:0][2:0] m_arb_arsize, m_arb_awsize;
  wire [NUM_MASTERS-1:0][1:0] m_arb_arburst;
  wire [NUM_MASTERS-1:0][7:0] m_arb_arlen;
  wire [NUM_MASTERS-1:0] m_arb_rlast;

  assign m_arb_awvalid                 = {ifu_awvalid, lsu_awrvalid};
  assign m_arb_awsize                  = {ifu_awsize, lsu_awsize};
  assign m_arb_awaddr                  = {ifu_awaddr, lsu_awaddr};
  assign {ifu_awready, lsu_awrready}   = m_arb_awready;
  assign m_arb_wvalid                  = {ifu_wvalid, lsu_wvalid};
  assign m_arb_wdata                   = {ifu_wdata, lsu_wdata};
  assign m_arb_wstrb                   = {ifu_wstrb, lsu_wstrb};
  assign {ifu_wready, lsu_wready}      = m_arb_wready;
  assign {ifu_bvalid, lsu_bvalid}      = m_arb_bvalid;
  assign {ifu_bresp, lsu_bresp}        = m_arb_bresp;
  assign m_arb_bready                  = {ifu_bready, lsu_bready};

  // read channel go with icache first
  assign m_arb_arvalid                 = {icache_arvalid, lsu_arvalid};
  assign m_arb_arsize                  = {icache_arsize, lsu_arsize};
  assign m_arb_arburst                 = {icache_arburst, 2'b00};  // Only icache uses burst
  assign m_arb_arlen                   = {icache_arlen, 8'b0};  // Only icache uses burst
  assign icache_rlast                  = m_arb_rlast[1];
  assign {icache_arready, lsu_arready} = m_arb_arready;
  assign m_arb_araddr                  = {icache_araddr, lsu_araddr};
  assign {icache_rvalid, lsu_rvalid}   = m_arb_rvalid;
  assign m_arb_rready                  = {icache_rready, lsu_rready};
  assign {icache_rdata, lsu_rdata}     = m_arb_rdata;

  wire s_arb_awvalid, s_arb_awready, s_arb_wvalid, s_arb_wready, s_arb_bvalid, s_arb_bready;
  wire [1:0] s_arb_bresp;
  wire [31:0] s_arb_awaddr, s_arb_wdata;
  wire [3:0] s_arb_wstrb;
  wire [2:0] s_arb_awsize, s_arb_arsize;
  wire [1:0] s_arb_arburst;
  wire [7:0] s_arb_arlen;
  wire s_arb_arvalid, s_arb_arready, s_arb_rvalid, s_arb_rready, s_arb_rlast;
  wire [31:0] s_arb_araddr, s_arb_rdata;

  ysyx_24110012_arbiter #(32, 32, 2) mem_arbiter (
  .clk        (clock),
  .reset      (reset),
  //.mem_r_grant(mem_r_grant),
  .m_awvalid  (m_arb_awvalid),
  .m_awsize   (m_arb_awsize),
  .m_awready  (m_arb_awready),
  .m_awaddr   (m_arb_awaddr),
  .m_wvalid   (m_arb_wvalid),
  .m_wready   (m_arb_wready),
  .m_wdata    (m_arb_wdata),
  .m_wstrb    (m_arb_wstrb),
  .m_bresp    (m_arb_bresp),
  .m_bvalid   (m_arb_bvalid),
  .m_bready   (m_arb_bready),
  .m_arvalid  (m_arb_arvalid),
  .m_arsize   (m_arb_arsize),
  .m_arburst  (m_arb_arburst),
  .m_arlen    (m_arb_arlen),
  .m_arready  (m_arb_arready),
  .m_araddr   (m_arb_araddr),
  .m_rvalid   (m_arb_rvalid),
  .m_rready   (m_arb_rready),
  .m_rdata    (m_arb_rdata),
  .m_rlast    (m_arb_rlast),
  .s_awvalid  (s_arb_awvalid),
  .s_awsize   (s_arb_awsize),
  .s_awready  (s_arb_awready),
  .s_awaddr   (s_arb_awaddr),
  .s_wvalid   (s_arb_wvalid),
  .s_wready   (s_arb_wready),
  .s_wdata    (s_arb_wdata),
  .s_wstrb    (s_arb_wstrb),
  .s_bresp    (s_arb_bresp),
  .s_bvalid   (s_arb_bvalid),
  .s_bready   (s_arb_bready),
  .s_arvalid  (s_arb_arvalid),
  .s_arsize   (s_arb_arsize),
  .s_arburst  (s_arb_arburst),
  .s_arlen    (s_arb_arlen),
  .s_arready  (s_arb_arready),
  .s_araddr   (s_arb_araddr),
  .s_rvalid   (s_arb_rvalid),
  .s_rready   (s_arb_rready),
  .s_rdata    (s_arb_rdata),
  .s_rlast    (s_arb_rlast)
  );

  // XBAR
  localparam integer NUM_XBAR_MASTERS = 2;
  wire [NUM_XBAR_MASTERS-1:0] m_xbar_awvalid, m_xbar_awready, m_xbar_wvalid, m_xbar_wready,
  m_xbar_bvalid, m_xbar_bready;
  wire [NUM_XBAR_MASTERS-1:0][1:0] m_xbar_bresp;
  wire [NUM_XBAR_MASTERS-1:0][31:0] m_xbar_awaddr, m_xbar_wdata;
  wire [NUM_XBAR_MASTERS-1:0][3:0] m_xbar_wstrb;
  wire [NUM_XBAR_MASTERS-1:0][2:0] m_xbar_awsize, m_xbar_arsize;
  wire [NUM_XBAR_MASTERS-1:0] m_xbar_arvalid, m_xbar_arready, m_xbar_rvalid, m_xbar_rready;
  wire [NUM_XBAR_MASTERS-1:0][31:0] m_xbar_araddr, m_xbar_rdata;
  wire [NUM_XBAR_MASTERS-1:0][1:0] m_xbar_arburst;
  wire [NUM_XBAR_MASTERS-1:0][7:0] m_xbar_arlen;
  wire [NUM_XBAR_MASTERS-1:0] m_xbar_rlast;
  // XBAR end

  // write address channel
  assign m_xbar_awready[0] = io_master_awready;
  assign io_master_awvalid = m_xbar_awvalid[0];
  assign io_master_awaddr  = m_xbar_awaddr[0];
  assign io_master_awid    = 4'b0;
  assign io_master_awlen   = 8'b0;
  assign io_master_awsize  = m_xbar_awsize[0];
  assign io_master_awburst = 2'b00;

  // write data channel
  assign m_xbar_wready[0]  = io_master_wready;
  assign io_master_wvalid  = m_xbar_wvalid[0];
  assign io_master_wdata   = m_xbar_wdata[0];
  assign io_master_wstrb   = m_xbar_wstrb[0];
  assign io_master_wlast   = 1'b1;

  // write response channel
  assign io_master_bready  = m_xbar_bready[0];
  assign m_xbar_bvalid[0]  = io_master_bvalid;
  assign m_xbar_bresp[0]   = io_master_bresp;

  // read address channel
  assign m_xbar_arready[0] = io_master_arready;
  assign io_master_arvalid = m_xbar_arvalid[0];
  assign io_master_araddr  = m_xbar_araddr[0];
  assign io_master_arid    = 4'b0;
  assign io_master_arlen   = m_xbar_arlen[0];
  assign io_master_arsize  = m_xbar_arsize[0];
  assign io_master_arburst = m_xbar_arburst[0];

  // read data channel
  assign io_master_rready  = m_xbar_rready[0];
  assign m_xbar_rvalid[0]  = io_master_rvalid;
  assign m_xbar_rdata[0]   = io_master_rdata;
  assign m_xbar_rlast[0]   = io_master_rlast;
  // AXI arbiter end

  ysyx_24110012_xbar #(32, 32, NUM_XBAR_MASTERS) u_xbar (
  .clk      (clock),
  .s_awvalid(s_arb_awvalid),
  .s_awready(s_arb_awready),
  .s_awaddr (s_arb_awaddr),
  .s_awsize (s_arb_awsize),
  .s_wvalid (s_arb_wvalid),
  .s_wready (s_arb_wready),
  .s_wdata  (s_arb_wdata),
  .s_wstrb  (s_arb_wstrb),
  .s_bresp  (s_arb_bresp),
  .s_bvalid (s_arb_bvalid),
  .s_bready (s_arb_bready),
  .s_arvalid(s_arb_arvalid),
  .s_arsize (s_arb_arsize),
  .s_arburst(s_arb_arburst),
  .s_arlen  (s_arb_arlen),
  .s_arready(s_arb_arready),
  .s_araddr (s_arb_araddr),
  .s_rvalid (s_arb_rvalid),
  .s_rready (s_arb_rready),
  .s_rdata  (s_arb_rdata),
  .s_rlast  (s_arb_rlast),
  .m_awvalid(m_xbar_awvalid),
  .m_awready(m_xbar_awready),
  .m_awaddr (m_xbar_awaddr),
  .m_awsize (m_xbar_awsize),
  .m_wvalid (m_xbar_wvalid),
  .m_wready (m_xbar_wready),
  .m_wdata  (m_xbar_wdata),
  .m_wstrb  (m_xbar_wstrb),
  .m_bresp  (m_xbar_bresp),
  .m_bvalid (m_xbar_bvalid),
  .m_bready (m_xbar_bready),
  .m_arvalid(m_xbar_arvalid),
  .m_arready(m_xbar_arready),
  .m_araddr (m_xbar_araddr),
  .m_arsize (m_xbar_arsize),
  .m_arburst(m_xbar_arburst),
  .m_arlen  (m_xbar_arlen),
  .m_rvalid (m_xbar_rvalid),
  .m_rready (m_xbar_rready),
  .m_rdata  (m_xbar_rdata),
  .m_rlast  (m_xbar_rlast)
  );

  ysyx_24110012_vclint u_vclint (
  .clk    (clock),
  .reset  (reset),
  .araddr (m_xbar_araddr[1]),
  .arvalid(m_xbar_arvalid[1]),
  .arready(m_xbar_arready[1]),
  .rdata  (m_xbar_rdata[1]),
  .rlast  (m_xbar_rlast[1]),
  .rvalid (m_xbar_rvalid[1]),
  .rready (m_xbar_rready[1]),
  .awaddr (m_xbar_awaddr[1]),
  .awvalid(m_xbar_awvalid[1]),
  .awready(m_xbar_awready[1]),
  .wdata  (m_xbar_wdata[1]),
  .wstrb  (m_xbar_wstrb[1]),
  .wvalid (m_xbar_wvalid[1]),
  .wready (m_xbar_wready[1]),
  .bresp  (m_xbar_bresp[1]),
  .bvalid (m_xbar_bvalid[1]),
  .bready (m_xbar_bready[1])
  );



 // idu/exu is combinational, so we calc their cnt here.
`ifdef PERF
`ifndef SYNTHESIS
  reg  [63:0] lsu_cnt = 64'b0;
  reg  [63:0] ifu_cnt = 64'b0;
  reg  [63:0] idu_cnt = 64'b0;
  reg  [63:0] idu_calc_cnt = 64'b0;
  reg  [63:0] idu_mem_cnt = 64'b0;
  reg  [63:0] idu_csr_cnt = 64'b0;
  reg  [63:0] idu_br_cnt = 64'b0;
  reg  [63:0] exu_cnt = 64'b0;
  reg  [63:0] redirect_cnt = 64'b0;
  reg  [63:0] exu_redirect_cnt = 64'b0;
  reg  [63:0] branch_redirect_cnt = 64'b0;
  reg  [63:0] jump_redirect_cnt = 64'b0;
  reg  [63:0] jal_redirect_cnt = 64'b0;
  reg  [63:0] jalr_redirect_cnt = 64'b0;
  reg  [63:0] wbu_redirect_cnt = 64'b0;
  reg  [63:0] redirect_cycles = 64'b0;
  reg  [63:0] exu_redirect_cycles = 64'b0;
  reg  [63:0] branch_redirect_cycles = 64'b0;
  reg  [63:0] jump_redirect_cycles = 64'b0;
  reg  [63:0] jal_redirect_cycles = 64'b0;
  reg  [63:0] jalr_redirect_cycles = 64'b0;
  reg  [63:0] wbu_redirect_cycles = 64'b0;
  reg         exu_redirect_busy = 1'b0;
  reg  [ 1:0] exu_redirect_type = 2'b00;
  reg         wbu_redirect_busy = 1'b0;
  reg  [63:0] hazard_event_cnt = 64'b0;
  reg  [63:0] hazard_cycles = 64'b0;
  reg         hazard_raw_stall_prev = 1'b0;

  reg  [63:0] calc_cycles = 64'b0;
  reg  [63:0] mem_cycles = 64'b0;
  reg  [63:0] csr_cycles = 64'b0;
  reg  [63:0] br_cycles = 64'b0;
  reg  [63:0] ifu_cycles = 64'b0;
  reg  [63:0] lsu_cycles = 64'b0;

  reg         calc_busy = 1'b0;
  reg         mem_busy = 1'b0;
  reg         csr_busy = 1'b0;
  reg         br_busy = 1'b0;
  reg         ifu_busy = 1'b0;
  reg         lsu_busy = 1'b0;

  wire        ifu_req_fire = ifu_arvalid && ifu_arready;
  wire        ifu_rsp_fire = ifu_rvalid && ifu_rready;
  wire        lsu_req_fire = (lsu_arvalid && lsu_arready) || (lsu_awrvalid && lsu_awrready);
  wire        lsu_rsp_fire = (lsu_rvalid && lsu_rready) || (lsu_bvalid && lsu_bready);

  always @(posedge clock) begin
    if (reset) begin
      exu_redirect_busy <= 1'b0;
      exu_redirect_type <= 2'b00;
      wbu_redirect_busy <= 1'b0;
    end else begin
      if (wbu_redirect) begin
        wbu_redirect_busy <= 1'b1;
        exu_redirect_busy <= 1'b0;
        exu_redirect_type <= 2'b00;
      end else if (exu_redirect) begin
        exu_redirect_busy <= 1'b1;
        if (exu_lsu_branch_o) begin
          exu_redirect_type <= 2'b01;
        end else if (idu_exu_opcode_i == `ysyx_24110012_OPT_J_JAL) begin
          exu_redirect_type <= 2'b10;
        end else begin
          exu_redirect_type <= 2'b11;
        end
      end else if (idu_exu_valid_o) begin
        exu_redirect_busy <= 1'b0;
        exu_redirect_type <= 2'b00;
        wbu_redirect_busy <= 1'b0;
      end
    end
  end

  always @(posedge clock) begin
    if (!reset) begin
      if (wbu_redirect_busy && !idu_exu_valid_o) begin
        wbu_redirect_cycles <= wbu_redirect_cycles + 64'd1;
      end
      if (exu_redirect_busy && !idu_exu_valid_o) begin
        exu_redirect_cycles <= exu_redirect_cycles + 64'd1;
        if (exu_redirect_type == 2'b01) begin
          branch_redirect_cycles <= branch_redirect_cycles + 64'd1;
        end else begin
          jump_redirect_cycles <= jump_redirect_cycles + 64'd1;
          if (exu_redirect_type == 2'b10) begin
            jal_redirect_cycles <= jal_redirect_cycles + 64'd1;
          end else if (exu_redirect_type == 2'b11) begin
            jalr_redirect_cycles <= jalr_redirect_cycles + 64'd1;
          end
        end
      end
      if ((wbu_redirect_busy || exu_redirect_busy) && !idu_exu_valid_o) begin
        redirect_cycles <= redirect_cycles + 64'd1;
      end
    end

    if (redirect) begin
      redirect_cnt <= redirect_cnt + 64'd1;
    end
    if (exu_redirect) begin
      exu_redirect_cnt <= exu_redirect_cnt + 64'd1;
      if (exu_lsu_branch_o) begin
        branch_redirect_cnt <= branch_redirect_cnt + 64'd1;
      end
      if (exu_lsu_jump_o) begin
        jump_redirect_cnt <= jump_redirect_cnt + 64'd1;
        if (idu_exu_opcode_i == `ysyx_24110012_OPT_J_JAL) begin
          jal_redirect_cnt <= jal_redirect_cnt + 64'd1;
        end else if (idu_exu_opcode_i == `ysyx_24110012_OPT_I_JALR) begin
          jalr_redirect_cnt <= jalr_redirect_cnt + 64'd1;
        end
      end
    end
    if (wbu_redirect) begin
      wbu_redirect_cnt <= wbu_redirect_cnt + 64'd1;
    end

    if (hazard_raw_stall && !hazard_raw_stall_prev) begin
      hazard_event_cnt <= hazard_event_cnt + 64'd1;
    end
    if (hazard_raw_stall) begin
      hazard_cycles <= hazard_cycles + 64'd1;
    end
    hazard_raw_stall_prev <= hazard_raw_stall;
  end

  always @(posedge clock) begin
    if (ifu_rvalid && ifu_rready) begin
      ifu_cnt <= ifu_cnt + 64'd1;
      idu_cnt <= idu_cnt + 64'd1;
      exu_cnt <= exu_cnt + 64'd1;
      case (ifu_rdata[6:0])
        `ysyx_24110012_OPT_U_AUIPC, `ysyx_24110012_OPT_I_LOGIC, `ysyx_24110012_OPT_U_LUI,
        `ysyx_24110012_OPT_R_LOGIC: begin
          idu_calc_cnt <= idu_calc_cnt + 64'd1;
          calc_busy    <= 1'b1;
        end
        `ysyx_24110012_OPT_I_LOAD, `ysyx_24110012_OPT_S_STORE: begin
          idu_mem_cnt <= idu_mem_cnt + 64'd1;
          mem_busy    <= 1'b1;
        end
        `ysyx_24110012_OPT_I_EC: begin
          if (ifu_rdata[14:12] != 3'b000) begin
            idu_csr_cnt <= idu_csr_cnt + 64'd1;
            csr_busy    <= 1'b1;
          end
        end
        `ysyx_24110012_OPT_B, `ysyx_24110012_OPT_J_JAL, `ysyx_24110012_OPT_I_JALR: begin
          idu_br_cnt <= idu_br_cnt + 64'd1;
          br_busy    <= 1'b1;
        end
        default: begin
          // do nothing
        end
      endcase
    end else if (lsu_rvalid && lsu_rready) begin
      lsu_cnt <= lsu_cnt + 64'd1;
    end
  end

  always @(posedge clock) begin
    // IFU cycles: from fetch request handshake to fetch response handshake.
    if (ifu_busy || ifu_req_fire) begin
      ifu_cycles <= ifu_cycles + 64'd1;
    end
    if (ifu_req_fire) begin
      ifu_busy <= 1'b1;
    end
    if (ifu_rsp_fire) begin
      ifu_busy <= 1'b0;
    end

    // LSU cycles: from LSU request handshake to LSU response handshake.
    if (lsu_busy || lsu_req_fire) begin
      lsu_cycles <= lsu_cycles + 64'd1;
    end
    if (lsu_req_fire) begin
      lsu_busy <= 1'b1;
    end
    if (lsu_rsp_fire) begin
      lsu_busy <= 1'b0;
    end
  end

  always @(posedge clock) begin
    if (!cycle_done) begin
      if (calc_busy) begin
        calc_cycles <= calc_cycles + 64'd1;
      end
      if (mem_busy) begin
        mem_cycles <= mem_cycles + 64'd1;
      end
      if (csr_busy) begin
        csr_cycles <= csr_cycles + 64'd1;
      end
      if (br_busy) begin
        br_cycles <= br_cycles + 64'd1;
      end
    end else begin
      calc_busy <= 1'b0;
      mem_busy  <= 1'b0;
      csr_busy  <= 1'b0;
      br_busy   <= 1'b0;
    end
  end

  export "DPI-C" function get_lsu_cnt;
  function longint unsigned get_lsu_cnt();
    return lsu_cnt;
  endfunction

  export "DPI-C" function get_ifu_cnt;
  function longint unsigned get_ifu_cnt();
    return ifu_cnt;
  endfunction

  export "DPI-C" function get_idu_cnt;
  function longint unsigned get_idu_cnt();
    return idu_cnt;
  endfunction

  export "DPI-C" function get_exu_cnt;
  function longint unsigned get_exu_cnt();
    return exu_cnt;
  endfunction

  export "DPI-C" function get_redirect_cnt;
  function longint unsigned get_redirect_cnt();
    return redirect_cnt;
  endfunction

  export "DPI-C" function get_exu_redirect_cnt;
  function longint unsigned get_exu_redirect_cnt();
    return exu_redirect_cnt;
  endfunction

  export "DPI-C" function get_branch_redirect_cnt;
  function longint unsigned get_branch_redirect_cnt();
    return branch_redirect_cnt;
  endfunction

  export "DPI-C" function get_jump_redirect_cnt;
  function longint unsigned get_jump_redirect_cnt();
    return jump_redirect_cnt;
  endfunction

  export "DPI-C" function get_jal_redirect_cnt;
  function longint unsigned get_jal_redirect_cnt();
    return jal_redirect_cnt;
  endfunction

  export "DPI-C" function get_jalr_redirect_cnt;
  function longint unsigned get_jalr_redirect_cnt();
    return jalr_redirect_cnt;
  endfunction

  export "DPI-C" function get_wbu_redirect_cnt;
  function longint unsigned get_wbu_redirect_cnt();
    return wbu_redirect_cnt;
  endfunction

  export "DPI-C" function get_redirect_cycles;
  function longint unsigned get_redirect_cycles();
    return redirect_cycles;
  endfunction

  export "DPI-C" function get_exu_redirect_cycles;
  function longint unsigned get_exu_redirect_cycles();
    return exu_redirect_cycles;
  endfunction

  export "DPI-C" function get_branch_redirect_cycles;
  function longint unsigned get_branch_redirect_cycles();
    return branch_redirect_cycles;
  endfunction

  export "DPI-C" function get_jump_redirect_cycles;
  function longint unsigned get_jump_redirect_cycles();
    return jump_redirect_cycles;
  endfunction

  export "DPI-C" function get_jal_redirect_cycles;
  function longint unsigned get_jal_redirect_cycles();
    return jal_redirect_cycles;
  endfunction

  export "DPI-C" function get_jalr_redirect_cycles;
  function longint unsigned get_jalr_redirect_cycles();
    return jalr_redirect_cycles;
  endfunction

  export "DPI-C" function get_wbu_redirect_cycles;
  function longint unsigned get_wbu_redirect_cycles();
    return wbu_redirect_cycles;
  endfunction

  export "DPI-C" function get_idu_calc_cnt;
  function longint unsigned get_idu_calc_cnt();
    return idu_calc_cnt;
  endfunction

  export "DPI-C" function get_idu_mem_cnt;
  function longint unsigned get_idu_mem_cnt();
    return idu_mem_cnt;
  endfunction

  export "DPI-C" function get_idu_csr_cnt;
  function longint unsigned get_idu_csr_cnt();
    return idu_csr_cnt;
  endfunction

  export "DPI-C" function get_idu_br_cnt;
  function longint unsigned get_idu_br_cnt();
    return idu_br_cnt;
  endfunction

  export "DPI-C" function get_calc_cycles;
  function longint unsigned get_calc_cycles();
    return calc_cycles;
  endfunction

  export "DPI-C" function get_mem_cycles;
  function longint unsigned get_mem_cycles();
    return mem_cycles;
  endfunction

  export "DPI-C" function get_csr_cycles;
  function longint unsigned get_csr_cycles();
    return csr_cycles;
  endfunction

  export "DPI-C" function get_br_cycles;
  function longint unsigned get_br_cycles();
    return br_cycles;
  endfunction

  export "DPI-C" function get_ifu_cycles;
  function longint unsigned get_ifu_cycles();
    return ifu_cycles;
  endfunction

  export "DPI-C" function get_lsu_cycles;
  function longint unsigned get_lsu_cycles();
    return lsu_cycles;
  endfunction

  export "DPI-C" function get_hazard_event_cnt;
  function longint unsigned get_hazard_event_cnt();
    return hazard_event_cnt;
  endfunction

  export "DPI-C" function get_hazard_cycles;
  function longint unsigned get_hazard_cycles();
    return hazard_cycles;
  endfunction
`endif
`endif
endmodule
