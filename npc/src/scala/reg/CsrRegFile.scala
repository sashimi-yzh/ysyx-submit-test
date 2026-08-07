package reg

import chisel3._
import chisel3.util._
import table.csrRegTable
import diplomatic._
import org.chipsalliance.cde.config.Parameters
import org.chipsalliance.diplomacy.lazymodule.{LazyModule, LazyModuleImp}
import enums._
import dto.PcRedirect
import config.Configs
class CsrRegFile(
  implicit p: Parameters)
    extends LazyModule {
  val node                 = new CsrRegNexusNode
  override lazy val module = new Impl
  class Impl extends LazyModuleImp(this) {
    val mepc             = if (p(Configs.DebugMode)) IO(Output(UInt(32.W))) else null
    val mtvec            = if (p(Configs.DebugMode)) IO(Output(UInt(32.W))) else null
    val mret             = IO(Input(Bool()))
    val pc               = IO(Input(UInt(32.W)))
    val exception        = IO(Input(Bool()))
    val exceptionNum     = IO(Input(SynchronousException()))
    val pcRedirect       = IO(Output(new PcRedirect))
    val mvendoridWire    = WireDefault("h79737978".U(32.W))
    val marchidWire      = WireDefault("d25060161".U(32.W))
    val mtvecReg         = RegInit(0.U(32.W))
    val mstatusReg       = RegInit("h1800".U(32.W))
    val mepcReg          = RegInit(0.U(32.W))
    val mcauseReg        = RegInit(0.U(32.W))
    val csrMap           = Seq(
      csrRegTable.mvendorid -> mvendoridWire,
      csrRegTable.marchid   -> marchidWire,
      csrRegTable.mtvec     -> mtvecReg,
      csrRegTable.mstatus   -> mstatusReg,
      csrRegTable.mepc      -> mepcReg,
      csrRegTable.mcause    -> mcauseReg
    )
    if (p(Configs.DebugMode)) {
      mepc  := mepcReg
      mtvec := mtvecReg
    }
    val (io_in, edgesIn) = node.in.unzip

    for (op <- io_in) {
      op.regReadData := 0.U
      csrMap.foreach { case (addr, reg) =>
        when(op.regAddr === addr) {
          op.regReadData := reg
          when(op.regWriteEn) {
            reg := op.regWriteData
          }
        }
      }
    }
    when(mret) {
      mstatusReg := Cat(mstatusReg(31, 13), 0.U(2.W), mstatusReg(10, 8), 1.U(1.W), mstatusReg(6, 4), mstatusReg(7), mstatusReg(2, 0))
    }
    pcRedirect.valid := io_in.foldLeft(exception)(_ || _.regWriteEn) || mret
    pcRedirect.npc := Mux(exception, mtvecReg, Mux(mret, mepcReg, pc + 4.U))
    when(exception) {
      mcauseReg := false.B ## exceptionNum.asUInt.pad(31)
      mepcReg   := pc
      when(exceptionNum === SynchronousException.EnvironmentCallFrom_M_mode) {
        mstatusReg := Cat(mstatusReg(31, 13), 3.U(2.W), mstatusReg(10, 8), mstatusReg(3), mstatusReg(6, 4), 0.U(1.W), mstatusReg(2, 0))
      }
    }
  }
}
