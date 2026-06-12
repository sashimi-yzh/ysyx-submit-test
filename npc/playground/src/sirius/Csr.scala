package sirius

import chisel3._
import chisel3.util._
import sirius.JumpTargetSelEnum.mepc

class CsrIO(
  implicit private val cfg: CoreConfig)
    extends Bundle {
  val wEn = Bool()
  val wData = UInt(cfg.mxlen.W)
  val rData = Flipped(UInt(cfg.mxlen.W))
}

class CsrParent(
  implicit private val cfg: CoreConfig)
    extends Module {
  val csrIO = IO(Flipped(new CsrIO))
}

class CsrParent32(
  implicit private val cfg: CoreConfig)
    extends Module {
  val csrIOHi = IO(Flipped(new CsrIO))
  val csrIOLo = IO(Flipped(new CsrIO))
}

class CsrMcycle32(
  implicit private val cfg: CoreConfig)
    extends CsrParent32 {
  val cycleCntReg = Reg(new Bundle {
    val hi = UInt(32.W)
    val lo = UInt(32.W)
  })
  when(csrIOHi.wEn) {
    cycleCntReg.hi := csrIOHi.wData
  }
  when(csrIOLo.wEn) {
    cycleCntReg.lo := csrIOLo.wData
  }
  if (!cfg.formal) {
    when(!(csrIOHi.wEn || csrIOLo.wEn)) {
      cycleCntReg :=
        (cycleCntReg.asUInt + 1.U).asTypeOf(chiselTypeOf(cycleCntReg))
    }
  } else {
    when(reset.asBool) {
      cycleCntReg := 0.U.asTypeOf(chiselTypeOf(cycleCntReg))
    }
  }
  csrIOHi.rData := cycleCntReg.hi
  csrIOLo.rData := cycleCntReg.lo
}

class CsrMvendorid(
  implicit private val cfg: CoreConfig)
    extends CsrParent {
  csrIO.rData := cfg.mvendorid.U
}

class CsrMarchid(
  implicit private val cfg: CoreConfig)
    extends CsrParent {
  csrIO.rData := cfg.marchid.U
}

class CsrMtvec(
  implicit private val cfg: CoreConfig)
    extends CsrParent {
  class MtvecBundle extends Bundle {
    val base = UInt((cfg.mxlen - 2).W)
    val reserve = UInt(1.W)
    val mode = UInt(1.W)
  }
  val mtvecReg = RegInit(0.U.asTypeOf(new MtvecBundle))
  when(csrIO.wEn) {
    mtvecReg := csrIO.wData.asTypeOf(mtvecReg)
  }
  csrIO.rData := mtvecReg.asUInt
  mtvecReg.reserve := 0.U
}

class CsrMepc(
  implicit private val cfg: CoreConfig)
    extends CsrParent {
  val pc = IO(Input(UInt(cfg.xlen.W)))
  val isTrap = IO(Input(Bool()))

  val mepcReg = if (cfg.formal) {
    RegInit(MixedVecInit(0.U(1.W), 0.U(1.W), 0.U((cfg.mxlen - 2).W)))
  } else { Reg(MixedVec(UInt(1.W), UInt(1.W), UInt((cfg.mxlen - 2).W))) }

  when(csrIO.wEn || isTrap) {
    mepcReg := Mux(isTrap, pc, csrIO.wData).asTypeOf(chiselTypeOf(mepcReg))
  }
  // when(csrIO.wEn) {
  //   mepcReg := csrIO.wData.asTypeOf(chiselTypeOf(mepcReg))
  // }
  // when(isTrap) {
  //   mepcReg := pc.asTypeOf(chiselTypeOf(mepcReg))
  // }

  csrIO.rData := mepcReg.asUInt
  mepcReg(0) := 0.U(1.W)
  if (!cfg.extensions().contains(ExtTypeEnum.C)) {
    mepcReg(1) := 0.U(1.W)
  }
}

class CsrMcause(
  implicit private val cfg: CoreConfig)
    extends CsrParent {
  val causeNum = IO(Input(UInt(5.W)))
  val isTrap = IO(Input(Bool()))

  val mcauseReg = if (cfg.formal) RegInit(0.U(5.W)) else Reg(UInt(5.W))

  when(csrIO.wEn || isTrap) {
    mcauseReg := Mux(isTrap, causeNum, csrIO.wData)
  }
  csrIO.rData := mcauseReg
}

class CsrMstatus(
  implicit private val cfg: CoreConfig)
    extends CsrParent {
  // val mstatusReg = RegInit(0x1800.U(cfg.mxlen.W))
  // when(csrIO.wEn) {
  //   mstatusReg := csrIO.wData
  // }
  // csrIO.rData := mstatusReg
  csrIO.rData := "h1800".U
}

class Csr(
  implicit private val cfg:  CoreConfig,
  implicit private val ucfg: UnitConfig)
    extends Module {
  val exuIn = IO(Flipped(new ExuToCsrIO))
  val wbuIn = IO(Flipped(new WbuToCsrIO))

  // 实例化
  val csrs = ucfg.csrMap.map { case (addr, gen) => addr -> Module(gen(cfg)) }
  val csrs32 = ucfg.csr32Map.map { case ((hi, lo), gen) => ((hi, lo) -> Module(gen(cfg))) }

  // 读数据Lut
  val readMap = csrs.map { case (addr, mod) =>
    addr -> mod.csrIO.rData
  }.toSeq ++ csrs32.flatMap { case ((hi, lo), mod) =>
    Seq(hi -> mod.csrIOHi.rData, lo -> mod.csrIOLo.rData)
  }.toSeq

  exuIn.rData := MuxLookup(exuIn.rAddr, readMap.head._2)(readMap)
  wbuIn.rData := MuxLookup(wbuIn.rAddr, readMap.head._2)(readMap)

  // WriteRaw Set Clear
  // val wData = MuxLookup(io.wOpCode, io.wOperand)(Seq(
  //     CsrWOpCode.write.asUInt -> io.wOperand,
  //     CsrWOpCode.set.asUInt -> (io.rData | io.wOperand),
  //     CsrWOpCode.clear.asUInt -> (io.rData & ~io.wOperand),
  //   ))

  // 写使能 写数据
  csrs.foreach { case (addr, mod) =>
    mod.csrIO.wEn := wbuIn.wEn && (wbuIn.wAddr === addr)
    mod.csrIO.wData := wbuIn.wData
  }

  csrs32.foreach { case ((hi, lo), mod) =>
    mod.csrIOHi.wEn := wbuIn.wEn && (wbuIn.wAddr === hi)
    mod.csrIOHi.wData := wbuIn.wData

    mod.csrIOLo.wEn := wbuIn.wEn && (wbuIn.wAddr === lo)
    mod.csrIOLo.wData := wbuIn.wData
  }

  def csrForeach[T <: CsrParent](key: CsrEnum.Type)(f: T => Unit) = {
    csrs.get(key).foreach(csr => f(csr.asInstanceOf[T]))
  }

  csrForeach[CsrMtvec](CsrEnum.mtvec) { wbuIn.mtvec := _.csrIO.rData }
  csrForeach[CsrMepc](CsrEnum.mepc) { mepc =>
    mepc.pc := wbuIn.pc
    mepc.isTrap := wbuIn.isTrap
    wbuIn.mepc := mepc.csrIO.rData
  }
  csrForeach[CsrMcause](CsrEnum.mcause) { mcause =>
    mcause.causeNum := wbuIn.causeNum
    mcause.isTrap := wbuIn.isTrap
  }
}
