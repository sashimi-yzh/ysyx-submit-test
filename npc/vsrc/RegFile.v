`ifdef __VERILATOR__
import "DPI-C" function void set_regs_ptr(input logic [31:0] ptr[]);
import "DPI-C" function void wbu_record(
  int pc,
  int npc
);
import "DPI-C" function void inst_done();
`endif

module ysyx_25010008_RegFile (
    input clock,
    input reset,

    input [4:0] rs1,
    input [4:0] rs2,
    input [4:0] rd,

    input wen,
    input [31:0] wdata,

    input [11:0] csr_s,
    input [11:0] csr_d,

    input csr_wen,
    input [31:0] csr_wdata,

    output [31:0] src1,
    output [31:0] src2,
    output reg [31:0] csr_src,

    input ls_valid,
    input inst_addr_misaligned,
    input ecall,
    input ebreak,
    input mret,
    input fence_i,
    input load_addr_misaligned,
    input store_addr_misaligned,
    input is_wrong_prediction,
    output reg clear_pipeline,
    output reg clear_cache,

    input [31:0] lsu_pc,
    input [31:0] exu_npc,
    output reg [31:0] npc,
    output reg npc_valid
);

  reg [31:0] regs[15:0];
  reg [31:0] mstatus, mtvec, mepc, mcause;
  reg [31:0] mvendorid;
  reg [31:0] marchid;

  assign src1 = regs[rs1[3:0]];
  assign src2 = regs[rs2[3:0]];

`ifdef __VERILATOR__
  initial begin
    set_regs_ptr(regs);
  end
`endif

  integer i;

  wire exception = inst_addr_misaligned | ecall | ebreak |load_addr_misaligned | store_addr_misaligned;

  always @(posedge clock) begin
    if (reset) begin
      for (i = 0; i < 16; i = i + 1) regs[i] <= 0;
      mstatus <= 32'h1800;
      mvendorid <= 32'h7973_7978;
      marchid <= 32'h17D_9F58;
      clear_pipeline <= 0;
    end else begin
      if (clear_pipeline) begin
        clear_pipeline <= 0;
        npc_valid <= 0;
      end else begin
        npc_valid <= ls_valid;
        if (wen && rd[3:0] != 0) begin
          regs[rd[3:0]] <= wdata;
        end
        if (exception) begin
          mcause <= inst_addr_misaligned ? 0 : ecall ? 11 : ebreak ? 3 : load_addr_misaligned ? 4 : 6;
          mepc <= lsu_pc;
          npc <= mtvec;
          clear_pipeline <= 1;

`ifdef __VERILATOR__
          wbu_record(lsu_pc, mtvec);
`endif
        end else begin
          clear_pipeline <= (fence_i | mret) ? 1 : is_wrong_prediction;
          clear_cache <= fence_i;
          npc <= mret ? mepc : exu_npc;
          if (csr_wen) begin
            case (csr_d)
              12'h300: mstatus <= csr_wdata;
              12'h305: mtvec <= csr_wdata;
              12'h341: mepc <= csr_wdata;
              default: ;
            endcase
          end
`ifdef __VERILATOR__
          wbu_record(lsu_pc, mret ? mepc : exu_npc);
`endif
        end
`ifdef __VERILATOR__
        if (ls_valid) inst_done();
`endif
      end
    end
  end

  always @(*) begin
    case (csr_s)
      12'h300: csr_src = mstatus;
      12'h305: csr_src = mtvec;
      12'h341: csr_src = mepc;
      12'h342: csr_src = mcause;
      12'hF11: csr_src = mvendorid;
      12'hF12: csr_src = marchid;
      default: csr_src = 0;
    endcase
  end

endmodule
