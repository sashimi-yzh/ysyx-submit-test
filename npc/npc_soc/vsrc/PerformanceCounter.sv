import "DPI-C" function void notify_ifu_r_event();
import "DPI-C" function void notify_lsu_r_event();
import "DPI-C" function void notify_ifu_ar_event();
import "DPI-C" function void notify_lsu_ar_event();
import "DPI-C" function void notify_exu_event();
import "DPI-C" function void notify_idu_event();
import "DPI-C" function void notify_wbu_event();
import "DPI-C" function void notify_inst_type_is_arithmetic_imm();
import "DPI-C" function void notify_inst_type_is_arithmetic_reg();
import "DPI-C" function void notify_inst_type_is_store();
import "DPI-C" function void notify_inst_type_is_load();
import "DPI-C" function void notify_inst_type_is_branch();
import "DPI-C" function void notify_inst_type_is_jal();
import "DPI-C" function void notify_inst_type_is_jalr();
import "DPI-C" function void notify_inst_type_is_lui();
import "DPI-C" function void notify_inst_type_is_auipc();
import "DPI-C" function void notify_inst_type_is_ebreak();
import "DPI-C" function void notify_inst_type_is_ecall();
import "DPI-C" function void notify_inst_type_is_mret();
import "DPI-C" function void notify_inst_type_is_csrop();
import "DPI-C" function void notify_inst_type_is_fence();
import "DPI-C" function void notify_new_cycle_not_on_flash();
import "DPI-C" function void notify_new_inst_not_on_flash();
import "DPI-C" function void notify_stalled();
import "DPI-C" function void notify_flushed();




module PerformanceCounter (
    input clock,
    input reset,
    input [31:0] pc,
    input ifu_arready,
    input ifu_arvalid,
    input ifu_rready,
    input ifu_rvalid,
    input lsu_arready,
    input lsu_arvalid,
    input lsu_rready,
    input lsu_rvalid,
    input exu_ready,
    input exu_valid,
    input idu_ready,
    input idu_valid,
    input wbu_valid,
    input inst_type_is_arithmetic_imm,
    input inst_type_is_arithmetic_reg,
    input inst_type_is_store,
    input inst_type_is_load,
    input inst_type_is_branch,
    input inst_type_is_jal,
    input inst_type_is_jalr,
    input inst_type_is_lui,
    input inst_type_is_auipc,
    input inst_type_is_ebreak,
    input inst_type_is_ecall,
    input inst_type_is_mret,
    input inst_type_is_csrop,
    input inst_type_is_fence,

    input stalled,
    input flushed
);

  reg exu_clear, idu_clear;

  function reg next_clear(input old_clear, input ready, input valid);
    if (old_clear) return ready ? 1'b0 : 1'b1;
    else return {ready, valid} == 2'b01;
  endfunction

  always @(posedge clock) begin
    if (reset) begin
      exu_clear <= 1'b0;
      idu_clear <= 1'b0;
    end else begin

      if (stalled) notify_stalled();
      if (flushed) notify_flushed();

      if (ifu_rready && ifu_rvalid) notify_ifu_r_event();
      if (lsu_rready && lsu_rvalid) notify_lsu_r_event();
      if (ifu_arready && ifu_arvalid) notify_ifu_ar_event();
      if (lsu_arready && lsu_arvalid) notify_lsu_ar_event();
      if (!exu_clear && exu_valid) notify_exu_event();
      if (!idu_clear && idu_valid) notify_idu_event();
      if (wbu_valid) notify_wbu_event();
      if (pc[31:28] == 4'ha) notify_new_cycle_not_on_flash();
      if (pc[31:28] == 4'ha && wbu_valid) notify_new_inst_not_on_flash();

      exu_clear <= next_clear(exu_clear, exu_ready, exu_valid);
      idu_clear <= next_clear(idu_clear, idu_ready, idu_valid);
      if (wbu_valid) begin
        if (inst_type_is_arithmetic_imm) notify_inst_type_is_arithmetic_imm();
        if (inst_type_is_arithmetic_reg) notify_inst_type_is_arithmetic_reg();
        if (inst_type_is_store) notify_inst_type_is_store();
        if (inst_type_is_load) notify_inst_type_is_load();
        if (inst_type_is_branch) notify_inst_type_is_branch();
        if (inst_type_is_jal) notify_inst_type_is_jal();
        if (inst_type_is_jalr) notify_inst_type_is_jalr();
        if (inst_type_is_lui) notify_inst_type_is_lui();
        if (inst_type_is_auipc) notify_inst_type_is_auipc();
        if (inst_type_is_ebreak) notify_inst_type_is_ebreak();
        if (inst_type_is_ecall) notify_inst_type_is_ecall();
        if (inst_type_is_mret) notify_inst_type_is_mret();
        if (inst_type_is_fence) notify_inst_type_is_fence();
        if (inst_type_is_csrop && !inst_type_is_mret && !inst_type_is_ecall && !inst_type_is_ebreak)
          notify_inst_type_is_csrop();
      end

    end
  end

endmodule
