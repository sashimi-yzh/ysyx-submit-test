package enums
import chisel3._
import chisel3.util._
object SynchronousException extends ChiselEnum {
  val InstructionAddressMisaligned = Value(0.U);
  val InstructionAccessFault       = Value(1.U);
  val IllegalInstruction           = Value(2.U);
  val Breakpoint                   = Value(3.U);
  val LoadAddressMisaligned        = Value(4.U);
  val LoadAccessFault              = Value(5.U);
  val Store_AMO_AddressMisaligned  = Value(6.U);
  val Store_AMO_Access_Fault       = Value(7.U);
  val EnvironmentCallFrom_U_mode   = Value(8.U);
  val EnvironmentCallFrom_S_mode   = Value(9.U);
  val EnvironmentCallFrom_M_mode   = Value(11.U);
  val InstructionPageFault         = Value(12.U);
  val LoadPageFault                = Value(13.U);
  val Store_AMO_Page_Fault         = Value(15.U);
}
