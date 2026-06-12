package sirius

import chisel3._
import chisel3.util.experimental.decode._
import chisel3.util.BitPat
import cpuutil.CanAutoGenSig

object InstFieldsRvZifencei {
  val fields = Seq(
    MakeBoolField("isFlushIcache", "ls", _.isFlushIcache),
  )
}
