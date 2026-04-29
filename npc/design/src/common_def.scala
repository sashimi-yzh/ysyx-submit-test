package common_def

import chisel3._
import chisel3.util._

import config._

import chisel3.layer._
object InlinePrintfLayer extends Layer(LayerConfig.Inline)

// generate printf inside module, unlike normal printf which will be
// generated at verification layer
object InlinePrintf {
  def apply(pable: Printable) = {
    layer.block(InlinePrintfLayer) {
      printf(pable)
    }
  }
}

object AddrSpace {
  val CLINT  = ("h02000000".U(32.W), "h0200ffff".U(32.W))
  val SPI    = ("h10001000".U(32.W), "h10002000".U(32.W))
  val SERIAL = ("h10000000".U(32.W), "h10001000".U(32.W))

  val SRAM = ("h0f000000".U(32.W), "h10000000".U(32.W))

  val VGA = ("h21000000".U(32.W), "h21200000".U(32.W))
  val PS2 = ("h10011000".U(32.W), "h10011007".U(32.W))

  val SOC_ExceptSRAM = ("h10000000".U(32.W), "hffffffff".U(32.W))

  val SOC = ("h0f000000".U(32.W), "hffffffff".U(32.W))

  val FLASH = ("h30000000".U(32.W), "h3fffffff".U(32.W))

  val NPCMEM = ("h80000000".U(32.W), "h8fffffff".U(32.W))

  def inRng(addr: UInt, rng: (UInt, UInt)): Bool = {
    (addr >= rng._1) && (addr < rng._2)
  }

  def needSkipDifftestGroup = Seq(
    SERIAL,
    SPI,
    CLINT,
    VGA,
    PS2
  )
}

case class CPUParameters(
  gprAddrWidth:      Int = 4,
  skipDifftestAddrs: Seq[(UInt, UInt)] = AddrSpace.needSkipDifftestGroup,
  resetVector: UInt = "h30000000".U(32.W)) {
  def GPRAddr = UInt(gprAddrWidth.W)
  def GPRNum  = 1 << gprAddrWidth
}

object Types {
  object BitWidth {
    val csr_addr = 12
    val word     = 32

    val inst_id = if (Config.genStageLog) 32 else 0
  }
  def UWord = UInt(BitWidth.word.W)

  def InstID = UInt(BitWidth.inst_id.W)

  def PredictedTarget = if (Config.useBTBAndBP) UWord else UInt(0.W)

  def InstCodeNoCExt = new InstCodeNoCExt

  object Ops {
    implicit class StringOps(val s: String) extends AnyVal {
      def UWord = s.U(BitWidth.word.W)
    }
    implicit class IntOps(val s: Int)       extends AnyVal {
      def UWord = s.U(BitWidth.word.W)
    }
  }
}
import Types.Ops._

object DbgVal {
  val UNINITIALIZED = 0xcccccccc.UWord
  val BADCALL       = 0xbaddca11.UWord
}

object InstFmt  extends ChiselEnum {
  val imm, reg, store, upper, jump, branch = Value(nextValue)
  private def nextValue: UInt = (1 << (all.size)).U

  def hasSame(a: InstFmt.Type, b: InstFmt.Type): Bool = {
    (a.asUInt & b.asUInt).orR
    // a === b
  }
}
object InstType extends ChiselEnum {
  val branch, arithmetic, load, store, jalr, jal, lui, auipc, system, fencei = Value(nextValue)
  private def nextValue: UInt = (1 << (all.size)).U

  def hasSame(a: InstType.Type, b: InstType.Type): Bool = {
    (a.asUInt & b.asUInt).orR
    // a === b
  }
}

class InstCodeNoCExt extends Bundle {
  // no support for compressed instruction,
  // the 2 least significant bits of instruction code are always 11b
  val raw = UInt(30.W)
  def get = {
    val dbgRaw = WireDefault(Cat(raw, "b11".U(2.W)))
    dontTouch(dbgRaw)
    dbgRaw
  }
  def eq(that: UInt) = this.get === that

  def func3t = this.get(14, 12)
  def func7t = this.get(31, 25)
}

class AlignedPC extends Bundle {
  val pc30b = UInt(30.W)
  def get   = {
    val dbgRaw = WireDefault(Cat(pc30b, 0.U(2.W)))
    dontTouch(dbgRaw)
    dbgRaw
  }
}

class Inst extends Bundle {
  val code            = Output(new InstCodeNoCExt())
  val pc              = Output(new AlignedPC())
  val iid             = Output(Types.InstID)
  val predictedNextPC = Output(Types.PredictedTarget)
}

class InstMetaInfo extends Bundle {
  val fmt = InstFmt()
  val typ = InstType()
}

class DecodedInstInfo(
  implicit p: CPUParameters)
    extends InstMetaInfo {
  val imm = Types.UWord
  // val rd  = p.GPRAddr

  val rdWrEn = Bool()

  val reg1 = Types.UWord
  val reg2 = Types.UWord

  // val snpc = Types.UWord
}

class DecodedInst(
  implicit p: CPUParameters)
    extends Inst {
  val info = new DecodedInstInfo
  def rd   = code.get(11, 7)
  def imm  = info.imm
  // def imm  = {
  //   val inst = code
  //
  //   val immI = Cat(Fill(21, inst(31)), inst(30, 20))
  //   val immS = Cat(immI(31, 5), inst(11, 8), inst(7))
  //   val immB = Cat(immI(31, 12), inst(7), immS(10, 1), 0.U(1.W))
  //   val immU = Cat(inst(31, 12), 0.U(12.W))
  //   val immJ = Cat(immI(31, 20), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W))
  //
  //   val dontcareImm = Wire(Types.UWord)
  //   dontcareImm := DontCare
  //
  //   WireDefault(MuxLookup(info.fmt, dontcareImm)(
  //     Seq(
  //       InstFmt.imm    -> immI,
  //       InstFmt.jump   -> immJ,
  //       InstFmt.store  -> immS,
  //       InstFmt.branch -> immB,
  //       InstFmt.upper  -> immU
  //     )
  //   ))
  // }
}

// update reg when enable,
// and output the new value immediately
object RegEnableReadNew {
  def apply[T <: Data](nxt: T, en: Bool): T = {
    val reg = RegEnable(nxt, en)
    Mux(en, nxt, reg)
  }
}

object EmptyDecoupledData {
  def apply() = {
    val out = Wire(Decoupled(UInt(0.W)))
    out.ready := true.B
    out.valid := true.B
    out.bits  := DontCare
    out
  }
}

object pipelineConnect {
  def apply[T <: Data, T2 <: Data](
    prevOut: DecoupledIO[T],
    thisIn:  DecoupledIO[T],
    thisOut: DecoupledIO[T2] = EmptyDecoupledData()
  ) = {

    val thisInReady = thisIn.ready

    val dataValid   = RegInit(false.B)
    val readyToPrev = (!dataValid) || thisInReady

    when(readyToPrev) {
      dataValid := prevOut.valid
    }
    prevOut.ready := readyToPrev

    thisIn.bits  := RegEnable(prevOut.bits, prevOut.fire)
    thisIn.valid := dataValid
  }
}
