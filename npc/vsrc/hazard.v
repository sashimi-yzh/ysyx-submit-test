//`define NO_FORWARD

module hazard #(
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

  wire rs1_ex_hit = ex_valid && ex_wen &&
                    (ex_rd_idx != {ADDR_WIDTH{1'b0}}) && (ex_rd_idx == rs1_idx);
  wire rs2_ex_hit = ex_valid && ex_wen &&
                    (ex_rd_idx != {ADDR_WIDTH{1'b0}}) && (ex_rd_idx == rs2_idx);

  wire rs1_ls_hit = ls_valid && ls_wen &&
                    (ls_rd_idx != {ADDR_WIDTH{1'b0}}) && (ls_rd_idx == rs1_idx);
  wire rs2_ls_hit = ls_valid && ls_wen &&
                    (ls_rd_idx != {ADDR_WIDTH{1'b0}}) && (ls_rd_idx == rs2_idx);

  wire rs1_wb_hit = wb_valid && wb_wen &&
                    (wb_rd_idx != {ADDR_WIDTH{1'b0}}) && (wb_rd_idx == rs1_idx);
  wire rs2_wb_hit = wb_valid && wb_wen &&
                    (wb_rd_idx != {ADDR_WIDTH{1'b0}}) && (wb_rd_idx == rs2_idx);

  // For the default forward-enabled pipeline, only load-use hazards need a stall because
  // EX/LS load data is not ready before memory response arrives.
  // For the no-forward baseline, any producer still in EX/LS is not yet visible in RF, so the
  // dependent instruction must stall as soon as it hits.
`ifdef NO_FORWARD
  assign raw_stall = (rs1_ex_hit || rs2_ex_hit || rs1_ls_hit || rs2_ls_hit);
`else
  assign raw_stall = (rs1_ex_hit && ex_is_load) ||
                     (rs2_ex_hit && ex_is_load) ||
                     (rs1_ls_hit && ls_is_load) ||
                     (rs2_ls_hit && ls_is_load);
`endif

`ifdef NO_FORWARD
  assign rs1_fwd = rs1_rf;
  assign rs2_fwd = rs2_rf;
`else
  assign rs1_fwd = rs1_ex_hit ? ex_wdata :
                   rs1_ls_hit ? ls_wdata :
                   rs1_wb_hit ? wb_wdata : rs1_rf;

  assign rs2_fwd = rs2_ex_hit ? ex_wdata :
                   rs2_ls_hit ? ls_wdata :
                   rs2_wb_hit ? wb_wdata : rs2_rf;
`endif

endmodule
