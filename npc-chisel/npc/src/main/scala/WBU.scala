package npc

import chisel3._
import chisel3.util._

import npc.common._
import npc.Constants._

class WBUDebugPort(implicit val conf: Config) extends Bundle {
    val wbCount = Output(UInt(conf.perfCountBits.W))
}

class WBToRegIo(implicit val conf: Config) extends Bundle {
    val rf_wen = Output(Bool())
    val data = Output(UInt(conf.xprlen.W))
    val wbaddr = Output(UInt(5.W))
}
class WBToCTLIO (implicit val conf: Config) extends Bundle() {
   val wbdata       = Output(UInt(conf.xlen.W))
   val wbaddr       = Output(UInt(5.W))
   val ctrl_rf_wen  = Output(Bool())
}


class WBU(implicit val conf: Config) extends Module {
    val io = IO(new Bundle {
        val mem_wb = Flipped(new DecoupledIO (new LSUPipeIO()))
        val reg = new DecoupledIO(new WBToRegIo())
        val debug = new WBUDebugPort()
        val ebreak = Output(Bool())
        val wb_pc = Output(UInt(conf.xprlen.W))
        val wb_inst = Output(UInt(conf.xlen.W))
        val to_ctl = new WBToCTLIO()
    })
    val reg_pc = RegEnable(io.mem_wb.bits.pc,io.mem_wb.bits.pc_valid)

    io := DontCare
    io.ebreak            := io.mem_wb.bits.ebreak
    io.wb_pc             := Mux(io.mem_wb.bits.pc_valid, io.mem_wb.bits.pc, reg_pc)
    io.mem_wb.ready := true.B

    io.to_ctl.wbdata        := io.mem_wb.bits.data
    io.to_ctl.wbaddr        := io.mem_wb.bits.wbaddr
    io.to_ctl.ctrl_rf_wen   := io.mem_wb.bits.ctrl_rf_wen

    io.reg.valid         := io.mem_wb.valid && !io.mem_wb.bits.ebreak
    io.reg.bits.data     := io.mem_wb.bits.data
    io.reg.bits.wbaddr   := io.mem_wb.bits.wbaddr
    io.reg.bits.rf_wen   := io.mem_wb.bits.ctrl_rf_wen
    
    ///////// DEBUG PORT
    val wbCount = RegInit(0.U(conf.perfCountBits.W))
    when(io.mem_wb.bits.ctrl_rf_wen === WB_MEM) {
        wbCount := wbCount + 1.U
    }
    io.debug.wbCount := wbCount
    ///////// END DEBUG
}
