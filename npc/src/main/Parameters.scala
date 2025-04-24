package npc
import chisel3._
import chisel3.util._

object Global {
  var mode = "sim"
  var debug = false
  var xlen = 32
  var rve = true
  var freqFile = ""
}

trait NPCParameters {
  def XLEN = Global.xlen
  def isRV32E = Global.rve

  val PALEN = 32
  val GPRIdxBits = if (isRV32E) 4 else 5
  val NRregs = 1 << GPRIdxBits
}

object MemMap extends NPCParameters {
  val sram  = (0x0f000000L, 0x0fffffffL)
  //val mrom  = (0x20000000L, 0x20000fffL)
  val flash = (0x30000000L, 0x3fffffffL)

  def getMask(start: Long, end: Long): Long = end - start
  def isCachable(addr: UInt) = addr(31) ||
    List(flash).map(x => ((addr & ~getMask(x._1, x._2).U(PALEN.W)) === x._1.U)).reduce(_ || _)
}

class NPCBundle extends Bundle with NPCParameters
class NPCModule extends Module with NPCParameters with RequireAsyncReset

object InstType extends ChiselEnum { val R, I, S, B, U, J, N = Value }
object SpecialInst extends ChiselEnum {
  val none, ill, auipc, jmp, br, ld, st, ecall, csr, mret, word = Value
}

trait HasCheckEnumSeq {
  def checkSeq[T <: EnumType](l: List[T]) = l.zipWithIndex.map { case (v, i) =>
    require((v.litValue & 0x7) == i," the lower 3 bits of " + v.toString + " is not " + i)
  }
}

object ALUType extends ChiselEnum with HasCheckEnumSeq {
  val add, sll, slt, sltu, xor, srl, or, and = Value
  checkSeq(List(add, sll, slt, sltu, xor, srl, or, and))
//  all.foreach(println)
}

object LoadType extends ChiselEnum with HasCheckEnumSeq {
  val lb, lh, lw, ld, lbu, lhu, lwu, pad1 = Value
  checkSeq(List(lb, lh, lw, ld, lbu, lhu, lwu))
}

object StoreType extends ChiselEnum with HasCheckEnumSeq {
  val sb, sh, sw, sd = Value
  checkSeq(List(sb, sh, sw, sd))
}

object BranchType extends ChiselEnum with HasCheckEnumSeq {
  val beq, bne, pad4, pad5, blt, bge, bltu, bgeu = Value
  checkSeq(List(beq, bne, pad4, pad5, blt, bge, bltu, bgeu))
}

object CSRType extends ChiselEnum with HasCheckEnumSeq {
  val pad, csrrw, csrrs, csrrc, pad1, csrrwi, csrrsi, csrrci = Value
  checkSeq(List(pad, csrrw, csrrs, csrrc, pad1, csrrwi, csrrsi, csrrci))
}

object CSRAddr extends ChiselEnum {
  val mstatus = Value(0x300.U)
  val misa, medeleg, mideleg, mie, mtvec, mcounteren = Value
  val mscratch = Value(0x340.U)
  val mepc, mcause, mtval, mip = Value
  val cycle = Value(0xc00.U)
  val mvendorid = Value(0xf11.U)
  val marchid = Value

  val last = Value(0xfff.U)
}
