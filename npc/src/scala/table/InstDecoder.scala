package table

import chisel3._
import chisel3.util._
import chisel3.util.experimental.decode._
import enums._

case class InstPattern(name: String, pattern: BitPat) extends DecodePattern {
  def bitPat: BitPat = pattern
}

object AllInstructions {
  val all = Seq(
    InstPattern("add", BitPat("b0000000_?????_?????_000_?????_0110011")),
    InstPattern("addi", BitPat("b???????_?????_?????_000_?????_0010011")),
    InstPattern("and", BitPat("b0000000_?????_?????_111_?????_0110011")),
    InstPattern("andi", BitPat("b???????_?????_?????_111_?????_0010011")),
    InstPattern("auipc", BitPat("b???????_?????_?????_???_?????_0010111")),
    InstPattern("beq", BitPat("b???????_?????_?????_000_?????_1100011")),
    InstPattern("bge", BitPat("b???????_?????_?????_101_?????_1100011")),
    InstPattern("bgeu", BitPat("b???????_?????_?????_111_?????_1100011")),
    InstPattern("blt", BitPat("b???????_?????_?????_100_?????_1100011")),
    InstPattern("bltu", BitPat("b???????_?????_?????_110_?????_1100011")),
    InstPattern("bne", BitPat("b???????_?????_?????_001_?????_1100011")),
    InstPattern("csrrs", BitPat("b???????_?????_?????_010_?????_1110011")),
    InstPattern("csrrw", BitPat("b???????_?????_?????_001_?????_1110011")),
    InstPattern("ebreak", BitPat("b0000000_00001_00000_000_00000_1110011")),
    InstPattern("ecall", BitPat("b0000000_00000_00000_000_00000_1110011")),
    InstPattern("fence_i", BitPat("b0000000_00000_00000_001_00000_0001111")),
    InstPattern("jal", BitPat("b???????_?????_?????_???_?????_1101111")),
    InstPattern("jalr", BitPat("b???????_?????_?????_000_?????_1100111")),
    InstPattern("lb", BitPat("b???????_?????_?????_000_?????_0000011")),
    InstPattern("lbu", BitPat("b???????_?????_?????_100_?????_0000011")),
    InstPattern("lh", BitPat("b???????_?????_?????_001_?????_0000011")),
    InstPattern("lhu", BitPat("b???????_?????_?????_101_?????_0000011")),
    InstPattern("lui", BitPat("b???????_?????_?????_???_?????_0110111")),
    InstPattern("lw", BitPat("b???????_?????_?????_010_?????_0000011")),
    InstPattern("mret", BitPat("b0011000_00010_00000_000_00000_1110011")),
    InstPattern("or", BitPat("b0000000_?????_?????_110_?????_0110011")),
    InstPattern("ori", BitPat("b???????_?????_?????_110_?????_0010011")),
    InstPattern("sb", BitPat("b???????_?????_?????_000_?????_0100011")),
    InstPattern("sh", BitPat("b???????_?????_?????_001_?????_0100011")),
    InstPattern("sll", BitPat("b0000000_?????_?????_001_?????_0110011")),
    InstPattern("slli", BitPat("b0000000_?????_?????_001_?????_0010011")),
    InstPattern("slt", BitPat("b0000000_?????_?????_010_?????_0110011")),
    InstPattern("slti", BitPat("b???????_?????_?????_010_?????_0010011")),
    InstPattern("sltiu", BitPat("b???????_?????_?????_011_?????_0010011")),
    InstPattern("sltu", BitPat("b0000000_?????_?????_011_?????_0110011")),
    InstPattern("sra", BitPat("b010000?_?????_?????_101_?????_0110011")),
    InstPattern("srai", BitPat("b010000?_?????_?????_101_?????_0010011")),
    InstPattern("srl", BitPat("b0000000_?????_?????_101_?????_0110011")),
    InstPattern("srli", BitPat("b0000000_?????_?????_101_?????_0010011")),
    InstPattern("sub", BitPat("b0100000_?????_?????_000_?????_0110011")),
    InstPattern("sw", BitPat("b???????_?????_?????_010_?????_0100011")),
    InstPattern("xor", BitPat("b0000000_?????_?????_100_?????_0110011")),
    InstPattern("xori", BitPat("b???????_?????_?????_100_?????_0010011"))
  )
}

object decodeException    extends BoolDecodeField[InstPattern]                        {
  def name                     = "exception"
  def genTable(i: InstPattern) = i.name match {
    case "ecall"  => y
    case "ebreak" => y
    case _        => n
  }
  override def default         = y
}
object decodeMemSignEx    extends BoolDecodeField[InstPattern]                        {
  def name                     = "memSignEx"
  def genTable(i: InstPattern) = i.name match {
    case "lb" | "lh" | "lw" => y
    case _                  => n
  }
  override def default         = n
}
object decodeExceptionNum extends DecodeField[InstPattern, SynchronousException.Type] {
  def name = "exceptionNum"
  def chiselType:               SynchronousException.Type = SynchronousException()
  override def default:         BitPat                    = BitPat(SynchronousException.IllegalInstruction.asUInt)
  def genTable(i: InstPattern): BitPat                    = {
    val exp =
      i.name match {
        case "ebreak" => SynchronousException.Breakpoint
        case "ecall"  => SynchronousException.EnvironmentCallFrom_M_mode
        case _        => SynchronousException.IllegalInstruction
      }
    BitPat(exp.asUInt)
  }
}
object decodeAluOperator  extends DecodeField[InstPattern, AluOperator.Type]          {
  def name = "aluOperator"
  def chiselType:               AluOperator.Type = AluOperator()
  override def default:         BitPat           = BitPat(AluOperator.nop.asUInt)
  def genTable(i: InstPattern): BitPat           = {
    val op = i.name match {
      case "add" | "addi" | "auipc" | "lb" | "lbu" | "lh" | "lhu" | "lui" | "lw" => AluOperator.add
      case "and" | "andi"                                                        => AluOperator.and
      case "or" | "ori"                                                          => AluOperator.or
      case "xor" | "xori"                                                        => AluOperator.xor
      case "sub"                                                                 => AluOperator.sub
      case "sll" | "slli"                                                        => AluOperator.logicalLeftShift
      case "srl" | "srli"                                                        => AluOperator.logicalRightShift
      case "sra" | "srai"                                                        => AluOperator.arithmeticRightShift
      case "slt" | "slti"                                                        => AluOperator.signedLess
      case "sltiu" | "sltu"                                                      => AluOperator.unsignedLess
      case _                                                                     => AluOperator.nop
    }
    BitPat(op.asUInt)
  }
}

object decodeMemSize                                                extends DecodeField[InstPattern, UInt]             {
  def name = "memSize"
  def chiselType:               UInt   = UInt(3.W)
  override def default:         BitPat = BitPat("b000")
  def genTable(i: InstPattern): BitPat = {
    val op = i.name match {
      case "sb" | "lb" | "lbu" => "b000"
      case "sh" | "lh" | "lhu" => "b001"
      case "sw" | "lw"         => "b010"
      case _                   => "b000"
    }
    BitPat(op)
  }
}
object decodeCsrWriteEn                                             extends BoolDecodeField[InstPattern]               {
  def name                     = "csrWriteEn"
  def genTable(i: InstPattern) = i.name match {
    case "csrrs" | "csrrw" => y
    case _                 => n
  }
  override def default         = n
}
object decodeCsrOp                                                  extends DecodeField[InstPattern, AluOperator.Type] {
  def name = "csrOp"
  def chiselType:               AluOperator.Type = AluOperator()
  override def default:         BitPat           = BitPat(AluOperator.nop.asUInt)
  def genTable(i: InstPattern): BitPat           = {
    val op = i.name match {
      case "csrrs" | "csrrw" => AluOperator.or
      case _                 => AluOperator.nop
    }
    BitPat(op.asUInt)
  }
}
object decodeRegWriteEn                                             extends BoolDecodeField[InstPattern]               {
  def name                     = "regWriteEn"
  def genTable(i: InstPattern) = i.name match {
    case "beq" | "bge" | "bgeu" | "blt" | "bltu" | "bne" | "fence_i" | "mret" | "sb" | "sh" | "sw" => n
    case _                                                                                         => y
  }
  override def default         = n
}
object decodeNeedMA                                                 extends BoolDecodeField[InstPattern]               {
  def name                     = "needMA"
  def genTable(i: InstPattern) = i.name match {
    case "lb" | "lbu" | "lh" | "lhu" | "lw" | "sb" | "sh" | "sw" => y
    case _                                                       => n
  }
  override def default         = n
}
object decodeMemWriteEn                                             extends BoolDecodeField[InstPattern]               {
  def name                     = "memWriteEn"
  def genTable(i: InstPattern) = i.name match {
    case "sb" | "sh" | "sw" => y
    case _                  => n
  }
  override def default         = n
}
object decodeIsBranch                                               extends BoolDecodeField[InstPattern]               {
  def name                     = "isBranch"
  def genTable(i: InstPattern) = i.name match {
    case "beq" | "bne" | "blt" | "bge" | "bltu" | "bgeu" => y
    case _                                               => n
  }
  override def default         = n
}
sealed abstract class IsInst(fieldName: String, instNames: String*) extends BoolDecodeField[InstPattern]               {
  def name        = fieldName
  private val set = instNames.toSet
  def genTable(i: InstPattern) = if (set.contains(i.name)) y else n
  override def default = n
}

object decodeFenceI  extends IsInst("fenceI", "fence_i")
object decodeIsJal   extends IsInst("isJal", "jal")
object decodeIsJalr  extends IsInst("isJalr", "jalr")
object decodeIsMret  extends IsInst("isMret", "mret")
object decodeIsEcall extends IsInst("isEcall", "ecall")
object decodeImmFmt  extends DecodeField[InstPattern, ImmFmt.Type] {
  def name = "immFmt"
  def chiselType:               ImmFmt.Type = ImmFmt()
  override def default:         BitPat      = BitPat(ImmFmt.immI.asUInt)
  def genTable(i: InstPattern): BitPat      = {
    val fmt = i.name match {
      case "sb" | "sh" | "sw"                              => ImmFmt.immS
      case "beq" | "bne" | "blt" | "bge" | "bltu" | "bgeu" => ImmFmt.immB
      case "lui" | "auipc"                                 => ImmFmt.immU
      case "jal"                                           => ImmFmt.immJ
      case _                                               => ImmFmt.immI
    }
    BitPat(fmt.asUInt)
  }
}
object decodeRs1Src  extends DecodeField[InstPattern, Rs1Src.Type] {
  def name = "rs1Src"
  def chiselType:               Rs1Src.Type = Rs1Src()
  override def default:         BitPat      = BitPat(Rs1Src.reg.asUInt)
  def genTable(i: InstPattern): BitPat      = {
    val src = i.name match {
      case "auipc" => Rs1Src.pc
      case "lui"   => Rs1Src.zero
      case _       => Rs1Src.reg
    }
    BitPat(src.asUInt)
  }
}
object decodeRs2Src  extends DecodeField[InstPattern, Rs2Src.Type] {
  def name = "rs2Src"
  def chiselType:               Rs2Src.Type = Rs2Src()
  override def default:         BitPat      = BitPat(Rs2Src.reg.asUInt)
  def genTable(i: InstPattern): BitPat      = {
    val src = i.name match {
      case "lui" | "auipc"                                                                                                                                   => Rs2Src.immU
      case "addi" | "slti" | "sltiu" | "xori" | "ori" | "andi" | "slli" | "srli" | "srai" | "lb" | "lh" | "lw" | "lbu" | "lhu" | "jalr" | "ecall" | "ebreak" =>
        Rs2Src.immI
      case "csrrs" | "csrrw"                                                                                                                                 => Rs2Src.csr
      case _                                                                                                                                                 => Rs2Src.reg
    }
    BitPat(src.asUInt)
  }
}
object decodeCsrrw   extends BoolDecodeField[InstPattern]          {
  def name                     = "csrrw"
  override def default         = n
  def genTable(i: InstPattern) = {
    i.name match {
      case "csrrw" => y
      case _       => n
    }
  }
}
