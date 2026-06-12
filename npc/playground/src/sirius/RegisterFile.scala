package sirius

import chisel3._

class RegisterFile(
  implicit private val cfg: CoreConfig)
    extends Module {
  val iduIn = IO(Flipped(new IduToRegFileIO))
  val wbuIn = IO(Flipped(new WbuToRegFileIO))
  val debug = Option.when(cfg.isDebug)(IO(Output(Vec(cfg.registerNum, UInt(cfg.xlen.W)))))

  val regFile = if (cfg.formal) { RegInit(rvspeccore.checker.ArbitraryRegFile.gen(cfg.xlen)) }
  else { Reg(Vec(cfg.registerNum, UInt(cfg.xlen.W))) }

  when(wbuIn.wEn) {
    regFile(wbuIn.wAddr) := wbuIn.wData
  }
  regFile(0) := 0.U
  iduIn.rData(0) := regFile(iduIn.rAddr(0))
  iduIn.rData(1) := regFile(iduIn.rAddr(1))

  if (cfg.formal) {
    require(cfg.registerNum == 32)
    rvspeccore.checker.ConnectHelper.setRegSource(regFile)
  }

  if (cfg.isDebug) {
    debug.get := regFile
  }

  // trait HasReadWrite {
  //   def read(idx:  UInt):             UInt
  //   def readAll:                      Seq[UInt]
  //   def write(idx: UInt, data: UInt): Unit
  // }
  // class RegReg extends HasReadWrite {
  //   val rf = if (cfg.formal) { RegInit(rvspeccore.checker.ArbitraryRegFile.gen(cfg.xlen)) }
  //   else { Reg(Vec(cfg.registerNum, UInt(cfg.xlen.W))) }
  //   def read(addr:  UInt): UInt = rf(addr)
  //   def readAll:           Seq[UInt] = (0 until cfg.registerNum).map { idx => rf(idx) }
  //   def write(addr: UInt, data: UInt) = { rf(addr) := data }
  // }
  // class RegMem extends HasReadWrite {
  //   val rf = Mem(cfg.registerNum, UInt(cfg.xlen.W))
  //   def read(addr:  UInt): UInt = rf(addr)
  //   def readAll:           Seq[UInt] = (0 until cfg.registerNum).map { idx => rf(idx) }
  //   def write(addr: UInt, data: UInt) = { rf(addr) := data }
  // }
  //
  // // val regFile = if (cfg.formal) { new RegReg } else { new RegMem }
  // val regFile = new RegMem
  // when(wbuIn.wEn && (wbuIn.wAddr =/= 0.U)) {
  //   regFile.write(wbuIn.wAddr, wbuIn.wData)
  // }
  // iduIn.rData(0) := regFile.read(iduIn.rAddr(0))
  // iduIn.rData(1) := regFile.read(iduIn.rAddr(1))
  // when(iduIn.rAddr(0) === 0.U) {
  //   iduIn.rData(0) := 0.U
  // }
  // when(iduIn.rAddr(1) === 0.U) {
  //   iduIn.rData(1) := 0.U
  // }
  //
  // if (cfg.formal) {
  //   require(cfg.registerNum == 32)
  //   val rfFormal = VecInit(regFile.readAll)
  //   rvspeccore.checker.ConnectHelper.setRegSource(rfFormal)
  // }
  //
  // if (cfg.isDebug) {
  //   val rfDebug = VecInit(regFile.readAll)
  //   debug.get := rfDebug
  // }
}
