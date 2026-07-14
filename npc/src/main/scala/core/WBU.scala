package top
import chisel3._
import chisel3.util._

class WBU extends Module {
  val io = IO(new Bundle {
    val in       = Flipped(Decoupled(new LSU2WBU))
    val rd       = Output(UInt(5.W))
    val wen      = Output(Bool())
    val wdata    = Output(UInt(32.W))
    val csrWen   = Output(Bool())
    val csrWdata = Output(UInt(32.W))

    val wbuRedirectPc = Input(UInt(32.W))
    val excType     = Output(ExceptionType())
    val excValid    = Output(Bool())
    val mret        = Output(Bool())

    val redirectEn = Output(Bool())
    val redirectPc = Output(UInt(32.W))

    val dpic_pc        = Output(UInt(32.W))
    val dpic_tag       = Output(UInt(8.W))
    val dpic_inst      = Output(UInt(32.W))
    val dpic_memAddr   = Output(UInt(32.W))
    val dpic_memRdata  = Output(UInt(32.W))
    val dpic_memWdata  = Output(UInt(32.W))
    val dpic_memRValid = Output(Bool())
    val dpic_memWValid = Output(Bool())
  })

  val ctrl = io.in.bits.ctrl

  io.wen      := false.B
  io.csrWen   := false.B
  io.mret     := false.B
  io.excValid := false.B

  when(io.in.valid) {
    when(!ctrl.excValid) {
      io.wen    := ctrl.regWen
      io.csrWen := ctrl.csrWen
      io.mret   := ctrl.mret
    }.otherwise {
      io.excValid := true.B
    }
  }

  io.rd    := io.in.bits.rd
  io.wdata := io.in.bits.gprWdata

  io.redirectPc := io.wbuRedirectPc

  // io.csrWdata := MuxLookup(ctrl.csrSel, 0.U)(
  //   Seq(
  //     CsrSel.RS1 -> io.in.bits.rdata1,
  //     CsrSel.ALU -> io.in.bits.result
  //   )
  // )
  io.csrWdata := io.in.bits.csrWdata
  io.excType  := ctrl.excType

  io.in.ready := true.B

  io.redirectEn := (ctrl.mret || ctrl.excValid) && io.in.valid

  io.dpic_pc        := io.in.bits.pc
  io.dpic_inst      := io.in.bits.inst
  io.dpic_tag       := io.in.bits.dpic_tag
  io.dpic_memAddr   := io.in.bits.dpic_memAddr
  io.dpic_memRdata  := io.in.bits.dpic_memRdata
  io.dpic_memWdata  := io.in.bits.dpic_memWdata
  io.dpic_memRValid := io.in.bits.dpic_memRValid
  io.dpic_memWValid := io.in.bits.dpic_memWValid
}
