package npc
import chisel3._
import chisel3.util._
import utils._

class AXI4CLINT extends Module {
  val io = IO(Flipped(new AXI4Lite))

  val cnt = RegInit(0.U(64.W))
  val incCond = if (Global.mode == "syn") { true.B } else {
    val freqMHz = if (!(new java.io.File(Global.freqFile)).exists()) 100.0
                  else scala.io.Source.fromFile(Global.freqFile).mkString.trim.toFloat
    println("Using freq = " + freqMHz + "MHz")
    val incCnt = freqMHz.toInt
    Counter(true.B, incCnt)._2
  }
  when (incCond) { cnt := cnt + 1.U }
  
  val araddr = io.ar.bits.addr(15,0)
  val isMtime  = (araddr === 0xbff8.U)
  val isMtimeh = (araddr === 0xbffc.U)

  object State extends ChiselEnum {
    val idle, waitRready = Value
  }

  val state = RegInit(State.idle)
  state := Lookup1H(state, Seq(
    State.idle        -> Mux(io.ar.valid, State.waitRready, State.idle),
    State.waitRready  -> Mux(io. r.ready, State.idle,       State.waitRready),
  ))

  io.ar.ready := (state === State.idle)

  io.r.valid := (state === State.waitRready)
  val isMtimeReg = RegEnable(isMtime, io.ar.valid)
  val isMtimehReg = RegEnable(isMtimeh, io.ar.valid)
  io.r.bits.data := (Fill(32, isMtimeReg) & cnt(31, 0)) | (Fill(32, isMtimehReg) & cnt(63, 32))
  io.r.bits.resp := Mux(!isMtimeReg && !isMtimehReg, AXI4Parameters.RESP_SLVERR, AXI4Parameters.RESP_OKAY)

  io.aw.ready := true.B
  io. w.ready := true.B
  io. b.valid := true.B
  io. b.bits.resp := AXI4Parameters.RESP_SLVERR
}
