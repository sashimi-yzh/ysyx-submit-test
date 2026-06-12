package sirius

import chisel3._

object CntWhen {
  def apply(cond: Bool, width: Int = 64): UInt = {
    val cntReg = RegInit(0.U(width.W))
    when(cond) {
      cntReg := cntReg + 1.U
    }
    cntReg
  }
}

object PerfWhen {
  def apply(
    name:      => String,
    cntCond:   => Bool,
    printCond: => Option[Bool],
    width:     => Int = 64
  )(
    implicit cfg: CoreConfig
  ): Option[UInt] = {
    if (cfg.perf) {
      val eventCntReg = CntWhen(cntCond, width)
      if (printCond.isDefined) {
        when(printCond.get) {
          printf("[perf %m] " + name.padTo(24, ' ') + " = %d\n", eventCntReg)
        }
      }
      Some(eventCntReg)
    } else {
      None
    }
  }
}
