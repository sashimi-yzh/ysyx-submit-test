package sirius

import chisel3._
import chisel3.util._

object PipelineConnect {
  def apply[T <: Data](
    prevOut: DecoupledIO[T],
    thisIn:  DecoupledIO[T],
    stall:   Bool = false.B,
    flush:   Bool = false.B
  ) = {
    val thisInReady = thisIn.ready || !thisIn.valid
    val valid = RegInit(false.B)
    when(thisInReady) {
      valid := prevOut.valid && !stall
    }
    when(flush) {
      valid := false.B
    }

    prevOut.ready := thisInReady && !stall
    thisIn.valid := valid
    thisIn.bits := RegEnable(prevOut.bits, prevOut.fire)
  }
}

class PipelineConnectModule[T <: Data](prevOut: DecoupledIO[T], thisIn: DecoupledIO[T])
    extends Module {
  val io = IO(new Bundle {
    val in = Flipped(chiselTypeOf(prevOut))
    val out = Flipped(chiselTypeOf(thisIn))
    val stall = Input(Bool())
    val flush = Input(Bool())
  })
  PipelineConnect(io.in, io.out, io.stall, io.flush)
}

object PipelineConnectModule {
  def apply[T <: Data](
    prevOut: DecoupledIO[T],
    thisIn:  DecoupledIO[T],
    stall:   Bool = false.B,
    flush:   Bool = false.B
  ): PipelineConnectModule[T] = {
    val p = Module(new PipelineConnectModule(prevOut, thisIn))
    p.io.in :<>= prevOut
    thisIn :<>= p.io.out
    p.io.stall := stall
    p.io.flush := flush
    p
  }
}
