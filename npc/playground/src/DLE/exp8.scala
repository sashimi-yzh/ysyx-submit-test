package dle.exp8

import chisel3._
import chisel3.util._
import chisel3.util.experimental.loadMemoryFromFileInline

class VgaSignal() extends Bundle {
  val hs = Output(Bool())
  val vs = Output(Bool())
  val blankN = Output(Bool())
  val rgbOut = Output(UInt(24.W))
}

case class VgaCfg(
  hFrontPorchWidth: Int = 16,
  hSyncWidth:       Int = 96,
  hBackPorchWidth:  Int = 48,
  hDataWidth:       Int = 640,
  vFrontPorchWidth: Int = 10,
  vSyncWidth:       Int = 2,
  vBackPorchWidth:  Int = 33,
  vDataWidth:       Int = 480) {
  val hBlankWidth = hFrontPorchWidth + hSyncWidth + hBackPorchWidth
  val hTotal: Int = hFrontPorchWidth + hSyncWidth + hBackPorchWidth + hDataWidth
  val vBlankWidth = vFrontPorchWidth + vSyncWidth + vBackPorchWidth
  val vTotal: Int = vFrontPorchWidth + vSyncWidth + vBackPorchWidth + vDataWidth
}

object VgaCfg {
  implicit val default: VgaCfg = VgaCfg()
}

class VgaCtrl(
  implicit val cfg: VgaCfg)
    extends Module {
  val io = IO(new Bundle {
    val rgbIn = Input(UInt(24.W))
    val vga = new VgaSignal
    val hAddr = Output(UInt(log2Ceil(cfg.hTotal).W))
    val vAddr = Output(UInt(log2Ceil(cfg.vTotal).W))
  })

  val hCntReg = RegInit(0.U(10.W))
  val vCntReg = RegInit(0.U(10.W))
  val hMax = cfg.hTotal - 1
  val vMax = cfg.vTotal - 1
  hCntReg := Mux(hCntReg === hMax.U, 0.U, hCntReg + 1.U)
  vCntReg := Mux(
    hCntReg === hMax.U,
    Mux(vCntReg === vMax.U, 0.U, vCntReg + 1.U),
    vCntReg
  )

  io.vga.rgbOut := io.rgbIn
  io.vga.hs := RegNext(
    hCntReg < cfg.hFrontPorchWidth.U ||
      hCntReg > (cfg.hFrontPorchWidth + cfg.hSyncWidth - 1).U
  )
  io.vga.vs := RegNext(
    hCntReg < cfg.vFrontPorchWidth.U ||
      vCntReg > (cfg.vFrontPorchWidth + cfg.vSyncWidth - 1).U
  )
  val isData = (hCntReg > (cfg.hBlankWidth - 1).U &&
    vCntReg > (cfg.vBlankWidth - 1).U)
  io.vga.blankN := RegNext(isData)
  io.hAddr := Mux(isData, hCntReg - cfg.hBlankWidth.U, 0.U)
  io.vAddr := Mux(isData, vCntReg - cfg.vBlankWidth.U, 0.U)
}

class Exp8(
  memFile: String = "/home/waterblock/ysyx-workbench/npc/util/output.hex.txt"
)(
  implicit val cfg: VgaCfg)
    extends Module {
  val io = IO(new Bundle {
    val vga = new VgaSignal
  })

  val mem = SyncReadMem(cfg.vDataWidth * cfg.hDataWidth, UInt(12.W))
  // val mem = SyncReadMem(cfg.vDataWidth * cfg.hDataWidth, UInt(24.W))
  if (memFile.trim().nonEmpty) {
    loadMemoryFromFileInline(mem, memFile)
  }

  val vgaCtrl = Module(new VgaCtrl)
  vgaCtrl.io.vga <> io.vga
  vgaCtrl.io.rgbIn := (
    mem.read(vgaCtrl.io.vAddr * cfg.hDataWidth.U + vgaCtrl.io.hAddr)(11, 8) ## 0
      .U(4.W) ##
      mem.read(vgaCtrl.io.vAddr * cfg.hDataWidth.U + vgaCtrl.io.hAddr)(
        7,
        4
      ) ## 0.U(4.W) ##
      mem.read(vgaCtrl.io.vAddr * cfg.hDataWidth.U + vgaCtrl.io.hAddr)(
        3,
        0
      ) ## 0.U(4.W)
  )
  // vgaCtrl.io.rgbIn := mem.read(vgaCtrl.io.vAddr * cfg.hDataWidth.U + vgaCtrl.io.hAddr)
}
