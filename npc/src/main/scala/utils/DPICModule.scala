package top
import chisel3._
import chisel3.util._

import chisel3._
import chisel3.util._

class ysyx_26010036_DPICModule extends ExtModule {
  val io = IO(new Bundle {
    val clk    = Input(Bool())
    val ebreak = Input(Bool())

    // difftest
    val difftest_step = Input(Bool())
    val gpr           = Input(Vec(16, UInt(32.W)))
    val csr           = Input(Vec(4, UInt(32.W)))
    val nextPC        = Input(UInt(32.W))
    val pc            = Input(UInt(32.W))
    val inst          = Input(UInt(32.W))
    val memAddr       = Input(UInt(32.W))
    val memRdata      = Input(UInt(32.W))
    val memWdata      = Input(UInt(32.W))
    val memRValid     = Input(Bool())
    val memWValid     = Input(Bool())
    val tag           = Input(UInt(8.W))

    // performance counter
    val pfm_begin     = Input(Bool())
    val if_miss       = Input(Bool())
    val if_finish     = Input(Bool())
    val ifu_i_flushed = Input(Bool())
    val ifu_nvalid    = Input(Bool())
    val if_bus_req    = Input(Bool())
    val if_bus_resp   = Input(Bool())
    val ifu_tag       = Input(UInt(8.W))

    val idu_raw = Input(Bool())
    val branch_correct = Input(Bool())

    val lsu_r_begin  = Input(Bool())
    val lsu_r_finish = Input(Bool())
    val lsu_w_begin  = Input(Bool())
    val lsu_w_finish = Input(Bool())
    val lsu_nvalid   = Input(Bool())

    val wbu_valid = Input(Bool())
    val wbu_tag   = Input(UInt(8.W))

    val inst_r   = Input(Bool())
    val inst_i   = Input(Bool())
    val inst_l   = Input(Bool())
    val inst_s   = Input(Bool())
    val inst_b   = Input(Bool())
    val inst_u   = Input(Bool())
    val inst_j   = Input(Bool())
    val inst_csr = Input(Bool())
    val inst_sys = Input(Bool())
  })

  setInline(
    "ysyx_26010036_DPICModule.v",
    """
      module ysyx_26010036_DPICModule (
          input        io_clk,
          input        io_ebreak,
          input        io_difftest_step,
          input [31:0] io_gpr_0,
          input [31:0] io_gpr_1,
          input [31:0] io_gpr_2,
          input [31:0] io_gpr_3,
          input [31:0] io_gpr_4,
          input [31:0] io_gpr_5,
          input [31:0] io_gpr_6,
          input [31:0] io_gpr_7,
          input [31:0] io_gpr_8,
          input [31:0] io_gpr_9,
          input [31:0] io_gpr_10,
          input [31:0] io_gpr_11,
          input [31:0] io_gpr_12,
          input [31:0] io_gpr_13,
          input [31:0] io_gpr_14,
          input [31:0] io_gpr_15,
          input [31:0] io_csr_0,
          input [31:0] io_csr_1,
          input [31:0] io_csr_2,
          input [31:0] io_csr_3,
          input [31:0] io_nextPC,
          input [31:0] io_pc,
          input [31:0] io_inst,
          input [31:0] io_memAddr,
          input [31:0] io_memRdata,
          input [31:0] io_memWdata,
          input io_memRValid,
          input io_memWValid,
          input [7:0] io_tag,

          input io_pfm_begin,
          input io_if_miss,
          input io_if_finish,
          input io_ifu_i_flushed,
          input io_ifu_nvalid,
          input io_if_bus_req,
          input io_if_bus_resp,
          input [7:0] io_ifu_tag,

          input io_idu_raw,

          input io_branch_correct,

          input io_lsu_r_begin,
          input io_lsu_r_finish,
          input io_lsu_w_begin,
          input io_lsu_w_finish,
          input io_lsu_nvalid,

          input io_wbu_valid,
          input [7:0] io_wbu_tag,

          input io_inst_r,
          input io_inst_i,
          input io_inst_l,
          input io_inst_s,
          input io_inst_u,
          input io_inst_b,
          input io_inst_j,
          input io_inst_csr,
          input io_inst_sys
      );
          import "DPI-C" function void dpic_ebreak();
          import "DPI-C" function void dpic_inst_finish();
          import "DPI-C" function void dpic_save_cpu_state(
              input int nextPC,
              input int pc,
              input byte pc_tag,
              input int inst,
              input int memAddr,
              input int memRdata,
              input int memWdata,
              input bit memRValid,
              input bit memWValid,
              input int csr_0,
              input int csr_1,
              input int csr_2,
              input int csr_3
          );
          import "DPI-C" function void dpic_save_gprs(
              input int gpr0,  input int gpr1,  input int gpr2,  input int gpr3,
              input int gpr4,  input int gpr5,  input int gpr6,  input int gpr7,
              input int gpr8,  input int gpr9,  input int gpr10, input int gpr11,
              input int gpr12, input int gpr13, input int gpr14, input int gpr15
          );
          import "DPI-C" function void dpic_save_performance_event(
              input bit pfm_begin,
              input bit if_miss,
              input bit if_finish,
              input bit ifu_i_flushed,
              input bit ifu_nvalid,
              input bit if_bus_req,
              input bit if_bus_resp,
              input byte ifu_tag,

              input bit idu_raw,
              input bit branch_correct,

              input bit lsu_r_begin,
              input bit lsu_r_finish,
              input bit lsu_w_begin,
              input bit lsu_w_finish,
              input bit lsu_nvalid,

              input bit wbu_valid,
              input byte wbu_tag,

              input bit inst_r,
              input bit inst_i,
              input bit inst_l,
              input bit inst_s,
              input bit inst_u,
              input bit inst_b,
              input bit inst_j,
              input bit inst_csr,
              input bit inst_sys
          );
      
          always @(*) begin
              if (io_ebreak) begin
                  dpic_ebreak();
              end
              if (io_difftest_step) begin
                  dpic_save_cpu_state(io_nextPC, io_pc,io_tag, io_inst, io_memAddr, io_memRdata, io_memWdata, io_memRValid, io_memWValid, io_csr_0, io_csr_1, io_csr_2, io_csr_3);
                  dpic_save_gprs(
                      io_gpr_0,  io_gpr_1,  io_gpr_2,  io_gpr_3,
                      io_gpr_4,  io_gpr_5,  io_gpr_6,  io_gpr_7,
                      io_gpr_8,  io_gpr_9,  io_gpr_10, io_gpr_11,
                      io_gpr_12, io_gpr_13, io_gpr_14, io_gpr_15
                  );
                  dpic_inst_finish();
              end
          end
      
          always @(posedge io_clk) begin
              dpic_save_performance_event(
                  io_pfm_begin,
                  io_if_miss,
                  io_if_finish,
                  io_ifu_i_flushed,
                  io_ifu_nvalid,
                  io_if_bus_req,
                  io_if_bus_resp,
                  io_ifu_tag,

                  io_idu_raw,
                  io_branch_correct,

                  io_lsu_r_begin,
                  io_lsu_r_finish,
                  io_lsu_w_begin,
                  io_lsu_w_finish,
                  io_lsu_nvalid,

                  io_wbu_valid,
                  io_wbu_tag,

                  io_inst_r,
                  io_inst_i,
                  io_inst_l,
                  io_inst_s,
                  io_inst_u,
                  io_inst_b,
                  io_inst_j,
                  io_inst_csr,
                  io_inst_sys
              );
          end
      
      endmodule
    """.stripMargin
  )
}
