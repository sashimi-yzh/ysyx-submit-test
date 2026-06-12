package sirius

import chisel3._
import chisel3.util.experimental.decode._
import chisel3.util.BitPat
import cpuutil.CanAutoGenSig

object InstFieldsRvZicsr {
  val fields = Seq(
    MakeBoolField("isWriteBackCsr", "wb", _.isWriteBackCsr),
    MakeBoolField("isCsrWriteCheck", "wb", _.isCsrWriteCheck),
  )
}
