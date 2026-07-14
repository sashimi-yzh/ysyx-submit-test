package top

import chisel3._
import chisel3.util._

object ImmSel   extends ChiselEnum { val I, S, B, U, J = Value                                                 }
object AluOp    extends ChiselEnum { val ADD, SUB, XOR, OR, AND, LL, RL, RA, LT, LTU = Value }
object BranchOp extends ChiselEnum { val EQ, NEQ, LT, GE, LTU, GEU = Value                                     }
object Op1Sel   extends ChiselEnum { val RS1, PC = Value                                                       }
object Op2Sel   extends ChiselEnum { val RS2, IMM, CSR = Value                                                 }
object RdSel    extends ChiselEnum { val ALU, MEM, PC4, IMM, CSR = Value                                       }
object MemLen { val BYTE = "b00".U; val HALF = "b01".U; val WORD = "b10".U }
object PcSel          extends ChiselEnum { val NEXT, IMM, RS1, BRANCH = Value                }
object CsrSel         extends ChiselEnum { val RS1, ALU = Value                               }
object PfmCntInstType extends ChiselEnum { val R, I, L, S, B, U, J, CSR, SYS, Unknown = Value }
object ExceptionType  extends ChiselEnum {
  val InstructionAddressMisaligned = Value(0.U)
  val InstructionAccessFault       = Value(1.U)
  val IllegalInstruction           = Value(2.U)
  val Breakpoint                   = Value(3.U)
  val LoadAddressMisaligned        = Value(4.U)
  val LoadAccessFault              = Value(5.U)
  val StoreAddressMisaligned       = Value(6.U)
  val StoreAccessFault             = Value(7.U)
  val EcallM                       = Value(11.U)
}
class CtrlBundle      extends Bundle     {
  val immSel   = ImmSel()
  val aluOp    = AluOp()
  val brOp     = BranchOp()
  val op1Sel   = Op1Sel()
  val op2Sel   = Op2Sel()
  val rdSel    = RdSel()
  val regWen   = Bool()
  val memR     = Bool()
  val memWen   = Bool()
  val memLen   = UInt(2.W)
  val memSext  = Bool()
  val pcSel    = PcSel()
  val csrWen   = Bool()
  val csrSel   = CsrSel()
  val mret     = Bool()
  val pcit     = PfmCntInstType()
  val fencei   = Bool()
  val excType  = ExceptionType()
  val excValid = Bool()
}

case class Ctrl(
  immSel:  ImmSel.Type = ImmSel.I,
  aluOp:   AluOp.Type = AluOp.ADD,
  brOp:    BranchOp.Type = BranchOp.EQ,
  op1Sel:  Op1Sel.Type = Op1Sel.PC,
  op2Sel:  Op2Sel.Type = Op2Sel.IMM,
  rdSel:   RdSel.Type = RdSel.ALU,
  regWen:  Bool = false.B,
  memR:    Bool = false.B,
  memWen:  Bool = false.B,
  memLen:  UInt = MemLen.BYTE,
  memSext: Bool = false.B,
  pcSel:   PcSel.Type = PcSel.NEXT,
  csrWen:  Bool = false.B,
  csrSel:  CsrSel.Type = CsrSel.ALU,
  mret:    Bool = false.B,
  pcit:    PfmCntInstType.Type = PfmCntInstType.Unknown,
  fencei:  Bool = false.B,
  excType: ExceptionType.Type = ExceptionType.InstructionAddressMisaligned,
  excValid: Bool = false.B) {
  def toList: List[UInt] =
    productIterator.map(_.asInstanceOf[Data].asUInt).toList
}
