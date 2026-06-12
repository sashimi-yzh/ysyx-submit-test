package sirius

import chisel3._

// class PcReg(
//   implicit private val cfg: CoreConfig)
//     extends Module {
//   val ifuIn = IO(Flipped(new IfuToPcRegIO))
//   val lsuIn = IO(Flipped(new LsuToPcRegIO))
//   val wbuIn = IO(Flipped(new WbuToPcRegIO))
//   val debug = Option.when(cfg.isDebug)(IO(new Bundle {
//     val pc = Output(UInt(cfg.xlen.W))
//   }))
//
//   val pcReg = RegInit(cfg.pcInit.U(cfg.xlen.W))
//   when (ifuIn.update) {
//     pcReg := ifuIn.nextPc
//   }
//   when (wbuIn.isJump || lsuIn.isJump) {
//     assert(!(wbuIn.isJump && lsuIn.isJump))
//     pcReg := Mux(wbuIn.isJump, wbuIn.target, lsuIn.target)
//   }
//   ifuIn.pc := pcReg
//
//   if (cfg.isDebug) {
//     debug.get.pc := pcReg
//   }
// }

class GlobalPcHi(implicit private val cfg: CoreConfig) extends Module {
  val trivialBits = if (cfg.hasC) 1 else 2
  val pcLoWidth = cfg.predTargetWidth + trivialBits
  val pcHiWidth = cfg.xlen - pcLoWidth

  val io = IO(new Bundle {
    val pcHi = Output(UInt(pcHiWidth.W))
    val wEn = Input(Bool())
    val wData = Input(UInt(pcHiWidth.W))
  })

  val pcHi = RegInit((cfg.pcInit >> pcLoWidth).U(pcHiWidth.W))

  when(io.wEn) {
    pcHi := io.wData
  }

  io.pcHi := pcHi
}
