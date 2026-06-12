package sirius

import chisel3._
import chisel3.util.experimental.decode._
import chisel3.util.MuxLookup
import chisel3.util.Fill
import chisel3.experimental.dataview._
import chisel3.util.Decoupled

// 解析imm
class ImmParser(
  implicit private val cfg: CoreConfig)
    extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(cfg.xlen.W))
    val instType = Input(UInt(InstTypeEnum.getWidth.W))
    val imm = Output(UInt(cfg.xlen.W))
  })

  val inst = io.inst(31, 0)

  val immTypeI = Fill(cfg.xlen - 11, inst(31)) ## inst(30, 20)
  val immTypeS = Fill(cfg.xlen - 11, inst(31)) ## inst(30, 25) ## inst(11, 7)
  val immTypeB =
    Fill(cfg.xlen - 12, inst(31)) ## inst(7) ## inst(30, 25) ##
      inst(11, 8) ## 0.U(1.W)
  val immTypeU = Fill(cfg.xlen - 31, inst(31)) ## inst(30, 12) ## 0.U(12.W)
  val immTypeJ =
    Fill(cfg.xlen - 20, inst(31)) ## inst(19, 12) ## inst(20) ## inst(
      30,
      21
    ) ## 0.U(1.W)
  val immTypeZicsr = inst(19, 15).pad(cfg.xlen)

  val immTypeCLWSP = ZeroExt(inst(3, 2) ## inst(12) ## inst(6, 4) ## 0.U(2.W), cfg.xlen)
  val immTypeCSWSP = ZeroExt(inst(8, 7) ## inst(12, 9) ## 0.U(2.W), cfg.xlen)
  val immTypeCLSW = ZeroExt(inst(5) ## inst(12, 10) ## inst(6) ## 0.U(2.W), cfg.xlen)
  val immTypeCJ = SignExt(
    inst(12) ## inst(8) ## inst(10, 9) ## inst(6) ## inst(7) ## inst(2) ## inst(11) ## inst(
      5,
      3
    ) ## 0.U(1.W),
    cfg.xlen
  )
  val immTypeCB =
    SignExt(inst(12) ## inst(6, 5) ## inst(2) ## inst(11, 10) ## inst(4, 3) ## 0.U(1.W), cfg.xlen)
  val immTypeCLIADDI = SignExt(inst(12) ## inst(6, 2), cfg.xlen)
  val immTypeCLUI = SignExt(inst(12) ## inst(6, 2) ## 0.U(12.W), cfg.xlen)
  val immTypeCADDI16SP =
    SignExt(inst(12) ## inst(4, 3) ## inst(5) ## inst(2) ## inst(6) ## 0.U(4.W), cfg.xlen)
  val immTypeCADDI4SPN =
    ZeroExt(inst(10, 7) ## inst(12, 11) ## inst(5) ## inst(6) ## 0.U(2.W), cfg.xlen)

  io.imm := MuxLookup(io.instType, immTypeI)(
    Seq(
      InstTypeEnum.I.asUInt -> immTypeI,
      InstTypeEnum.S.asUInt -> immTypeS,
      InstTypeEnum.B.asUInt -> immTypeB,
      InstTypeEnum.U.asUInt -> immTypeU,
      InstTypeEnum.J.asUInt -> immTypeJ,
      InstTypeEnum.Zicsr.asUInt -> immTypeZicsr,
      InstTypeEnum.CLWSP.asUInt -> immTypeCLWSP,
      InstTypeEnum.CSWSP.asUInt -> immTypeCSWSP,
      InstTypeEnum.CLSW.asUInt -> immTypeCLSW,
      InstTypeEnum.CJ.asUInt -> immTypeCJ,
      InstTypeEnum.CB.asUInt -> immTypeCB,
      InstTypeEnum.CLIADDI.asUInt -> immTypeCLIADDI,
      InstTypeEnum.CLUI.asUInt -> immTypeCLUI,
      InstTypeEnum.CADDI16SP.asUInt -> immTypeCADDI16SP,
      InstTypeEnum.CADDI4SPN.asUInt -> immTypeCADDI4SPN
    )
  )
}

class DecodeTableBitSet[I <: DecodePatternBitSet](
  patterns: Seq[I],
  fields:   Seq[DecodeField[I, _ <: Data]]) {
  require(
    patterns.map(_.bitSet.getWidth).distinct.size == 1,
    "All instructions must have the same width"
  )

  def bundle: DecodeBundle = new DecodeBundle(fields)

  lazy val table: TruthTable = TruthTable(
    patterns.map { op =>
      val result =
        fields.reverse.map(field => field.genTable(op)).reduce(_ ## _)
      op.bitSet.terms.map(bitPat => bitPat -> result)
    }.flatten,
    fields.reverse.map(_.default).reduce(_ ## _)
  )

  def decode(input: UInt): DecodeBundle =
    chisel3.util.experimental.decode.decoder(input, table).asTypeOf(bundle)
}

// 指令译码
class InstDecoder(
  implicit private val cfg: CoreConfig)
    extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(cfg.xlen.W))
    val ctrlSignals = Output(new CtrlSignals())
  })

  val decodeCollector = InstDecodeCollector()
  val decodeTable =
    new DecodeTableBitSet(decodeCollector.allPatterns, decodeCollector.allFields)
  val decodeResult = decodeTable.decode(io.inst)
  // 连接输出Bundle
  decodeCollector.allFields.foreach { f =>
    io.ctrlSignals.elements(f.stage).asInstanceOf[Bundle].elements(f.name) :=
      decodeResult(f.asInstanceOf[DecodeField[_, _ <: Data]])
  }
}

class Idu(
  implicit private val cfg: CoreConfig)
    extends Module {
  val exte = IO(new Bundle {
    val regFile = new IduToRegFileIO
    val globalCtrl = new GlobalCtrl
    val debugEbreak = Option.when(cfg.isDebug)(Input(Bool()))
  })
  val in = IO(Flipped(Decoupled(new IfuToIduIO)))
  val out = IO(Decoupled(new IduToExuIO))

  // DecoupledIO
  in.ready := out.ready
  out.valid := in.valid
  val inBits = in.bits
  val outBits = out.bits

  outBits.iduPayload.viewAsSupertype(new IfuPayload) := inBits.ifuPayload

  val inst = inBits.ifuPayload.ifu.inst

  // ctrl
  val instDecoder = Module(new InstDecoder())
  instDecoder.io.inst := inst
  val ctrl = instDecoder.io.ctrlSignals

  outBits.ctrl.exuCtrl := ctrl.ex
  outBits.ctrl.lsuCtrl := ctrl.ls
  outBits.ctrl.wbuCtrl := ctrl.wb
  exte.globalCtrl.globalCtrl := ctrl.global

  // Reg
  val rs1 = inst(19, 15)
  val rs2 = inst(24, 20)
  val rd = inst(11, 7)
  val crs2 = inst(6, 2)
  val crdrs1p = 1.U(1.W) ## inst(9, 7)
  val crdrs2p = 1.U(1.W) ## inst(4, 2)

  // rs1
  exte.regFile.rAddr(0) := MuxLookup(ctrl.id.rs1Sel, rs1)(
    Seq(
      RegAddrSelEnum.rs.asUInt -> rs1,
      RegAddrSelEnum.crdrs1p.asUInt -> crdrs1p,
      RegAddrSelEnum.rd.asUInt -> rd,
      RegAddrSelEnum.x2.asUInt -> 2.U
    )
  )
  outBits.iduPayload.idu.rs1Data := exte.regFile.rData(0)

  // rs2
  exte.regFile.rAddr(1) := MuxLookup(ctrl.id.rs2Sel, rs2)(
    Seq(
      RegAddrSelEnum.rs.asUInt -> rs2,
      RegAddrSelEnum.crs2.asUInt -> crs2,
      RegAddrSelEnum.crdrs2p.asUInt -> crdrs2p,
      RegAddrSelEnum.x0.asUInt -> 0.U
    )
  )
  outBits.iduPayload.idu.rs2Data := exte.regFile.rData(1)

  // rd
  outBits.iduPayload.idu.wAddr := MuxLookup(ctrl.id.rdSel, rd)(
    Seq(
      RegAddrSelEnum.rd.asUInt -> rd,
      RegAddrSelEnum.crdrs1p.asUInt -> crdrs1p,
      RegAddrSelEnum.crdrs2p.asUInt -> crdrs2p,
      RegAddrSelEnum.x1.asUInt -> 1.U,
      RegAddrSelEnum.x2.asUInt -> 2.U
    )
  )

  when(!inBits.ifuPayload.trap.isTrap) {
    outBits.iduPayload.trap.isTrap := ctrl.wb.isEcall || ctrl.wb.isEbreak
    outBits.iduPayload.trap.cause := Mux(ctrl.wb.isEcall, 11.U(cfg.mxlen.W), 3.U(cfg.mxlen.W))
  }

  // imm
  val immParser = Module(new ImmParser())
  immParser.io.inst := inst
  immParser.io.instType := ctrl.id.instType
  outBits.iduPayload.idu.imm := immParser.io.imm
  outBits.iduPayload.idu.immNotZero := immParser.io.imm.orR

  // csr encode
  outBits.iduPayload.idu.csrAddr := MuxLookup(inst(31, 20), CsrEnum.all.head)(CsrAddr.getAllMap)
}
