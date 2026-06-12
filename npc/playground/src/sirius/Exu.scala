package sirius

import chisel3._
import chisel3.util._
import scala.collection.immutable.ListMap
import chisel3.experimental.dataview._
import sirius.ExuOutSelEnum.aluBase

class AluIO(
  implicit private val cfg: CoreConfig)
    extends Bundle {
  val src1 = Output(UInt(cfg.xlen.W))
  val src2 = Output(UInt(cfg.xlen.W))
  val aluOp = Output(UInt(AluOpEnum.getWidth.W))
  val out = Input(UInt(cfg.xlen.W))
}

// Alu父类
class AluParent(
  implicit private val cfg: CoreConfig)
    extends Module {
  val io = IO(Flipped(new AluIO()))
}

// 主Alu
class AluBase(
  implicit private val cfg: CoreConfig)
    extends AluParent {
  import AluOpEnum._

  val useSub = Seq(sub, eql, neq, lt, ltu, ge, geu, clear)
    .map(io.aluOp === _.asUInt)
    .reduce(_ || _)
  val xorSrc2 = io.src2 ^ Fill(io.src2.getWidth, useSub)
  val addSub = io.src1 +& xorSrc2 + useSub.asUInt
  val addSubResult = addSub.tail(1)
  val addResult = addSubResult
  val subResult = addSubResult
  val eqlResult = addSubResult === 0.U
  val overflow = io.src1.head(1) === xorSrc2.head(1) && io.src1.head(1) =/= addSubResult.head(1)
  val ltResult = addSubResult.head(1) ^ overflow
  val geResult = !ltResult
  val geuResult = addSub.head(1)
  val ltuResult = !geuResult

  val neqResult = !eqlResult
  val andResult = io.src1 & io.src2
  val orResult = io.src1 | io.src2
  val xorResult = io.src1 ^ io.src2
  val direct1Result = io.src1
  val direct2Result = io.src2
  val clearResult = io.src2 & ~io.src1 // reversal

  // Shift
  def rightShiftN(data: UInt, n: Int, fillBit: Bool): UInt = {
    require(n >= 0)
    val dataWidth = data.getWidth
    Fill(n, fillBit) ## data(dataWidth - 1, n)
  }

  def rightShiftDynamic(data: UInt, shamt: UInt, fillBit: Bool): UInt = {
    if (shamt.getWidth == 1) {
      Mux(shamt(0), rightShiftN(data, 1, fillBit), data)
    } else {
      val lastStage = rightShiftDynamic(data, shamt.tail(1), fillBit)
      Mux(shamt.head(1).asBool, rightShiftN(lastStage, 1 << (shamt.getWidth - 1), fillBit), lastStage)
    }
  }

  val shamt = io.src2(log2Ceil(cfg.xlen) - 1, 0)
  val isLeftShift = io.aluOp === AluOpEnum.sll.asUInt
  val shiftData = Mux(isLeftShift, Reverse(io.src1), io.src1)
  val shiftFillBit = Mux(io.aluOp === AluOpEnum.sra.asUInt, io.src1(io.src1.getWidth - 1), false.B)
  val rawShiftResult = rightShiftDynamic(shiftData, shamt, shiftFillBit)
  val shiftResult = Mux(isLeftShift, Reverse(rawShiftResult), rawShiftResult)

  // Output sel
  io.out := direct1Result
  switch(io.aluOp) {
    is(eql.asUInt) {io.out := eqlResult; assert(io.out === (io.src1 === io.src2))}
    is(neq.asUInt) {io.out := neqResult; assert(io.out === (io.src1 =/= io.src2))}
    is(lt.asUInt) {io.out := ltResult; assert(io.out === (io.src1.asSInt < io.src2.asSInt))}
    is(ltu.asUInt) {io.out := ltuResult; assert(io.out === (io.src1 < io.src2))}
    is(ge.asUInt) {io.out := geResult; assert(io.out === (io.src1.asSInt >= io.src2.asSInt))}
    is(geu.asUInt) {io.out := geuResult; assert(io.out === (io.src1 >= io.src2))}
    is(add.asUInt) {io.out := addResult; assert(io.out === (io.src1 + io.src2))}
    is(sub.asUInt) {io.out := subResult; assert(io.out === (io.src1 - io.src2))}
    is(sll.asUInt) {io.out := shiftResult; assert(io.out === (io.src1 << shamt)(io.out.getWidth - 1, 0))}
    is(srl.asUInt) {io.out := shiftResult; assert(io.out === (io.src1 >> shamt))}
    is(sra.asUInt) {io.out := shiftResult; assert(io.out === (io.src1.asSInt >> shamt).asUInt)}
    is(clear.asUInt) {io.out := clearResult}
    is(and.asUInt) {io.out := andResult}
    is(or.asUInt) {io.out := orResult}
    is(xor.asUInt) {io.out := xorResult}
    is(direct1.asUInt) {io.out := direct1Result}
    is(direct2.asUInt) {io.out := direct2Result}
  }
}

class JumpTargetGenerator(
  implicit private val cfg: CoreConfig)
    extends Module {
  val io = IO(new Bundle {
    val jumpTargetSel = Input(UInt(JumpTargetSelEnum.getWidth.W))
    val pc = Input(UInt(cfg.xlen.W))
    val imm = Input(UInt(cfg.xlen.W))
    val aluResult = Input(UInt(cfg.xlen.W))
    val jumpTarget = Output(UInt(cfg.xlen.W))
  })

  val pcPlusImm = io.pc + io.imm
  val unalignTarget = MuxLookup(io.jumpTargetSel, pcPlusImm)(
    Seq(
      JumpTargetSelEnum.pcPlusImm.asUInt -> pcPlusImm,
      JumpTargetSelEnum.alu.asUInt -> io.aluResult
    )
  )
  io.jumpTarget := unalignTarget(cfg.xlen - 1, 1) ## 0.U(1.W)
}

class Exu(
  implicit private val cfg:  CoreConfig,
  implicit private val ucfg: UnitConfig)
    extends Module {
  val exte = IO(new Bundle {
    val pcHi = Input(UInt(cfg.pcHiWidth.W))
    val csr = new ExuToCsrIO
    val stall = Input(Bool())
    val debugEbreak = Option.when(cfg.isDebug)(Input(Bool()))
  })
  val in = IO(Flipped(Decoupled(new IduToExuIO)))
  val out = IO(Decoupled(new ExuToLsuIO))

  // DecoupledIO
  // val isCsrInst = in.bits.ctrl.wbuCtrl.isWriteBackCsr
  // val csrValid = !isCsrInst || RegNext(in.valid && !exte.stall && !in.fire)
  in.ready := out.fire
  // out.valid := in.valid && csrValid
  out.valid := in.valid
  val inBits = in.bits
  val outBits = out.bits

  outBits.exuPayload.viewAsSupertype(new IduPayload) := inBits.iduPayload
  outBits.ctrl := inBits.ctrl.viewAsSupertype(new LsuCtrl)

  val ctrl = inBits.ctrl.exuCtrl
  val imm = inBits.iduPayload.idu.imm
  val rs1Data = inBits.iduPayload.idu.rs1Data
  val rs2Data = inBits.iduPayload.idu.rs2Data
  val pc = PcCat(cfg.hasC, exte.pcHi, inBits.iduPayload.ifu.pcLo)

  // csr
  exte.csr.rAddr := inBits.iduPayload.idu.csrAddr
  // val csrData = RegNext(exte.csr.rData)
  val csrData = exte.csr.rData
  // outBits.exuPayload.exu.csrData := csrData

  // 根据扩展实例化Alu
  // val alus: ListMap[ExuOutSelEnum.Type, AluParent] = ucfg.aluMap().flatten.map {
  //   case (outSel: ExuOutSelEnum.Type, alu: (() => AluParent)) =>
  //     (outSel -> Module(alu()))
  // }
  val alu = Module(new AluBase)

  // 连接Alu输入
  val src1 = MuxLookup(ctrl.aluIn1Sel, rs1Data)(
    Seq(
      AluInSelEnum.imm.asUInt -> imm,
      AluInSelEnum.rs.asUInt -> rs1Data,
      AluInSelEnum.pc.asUInt -> pc
    )
  )
  val src2 = MuxLookup(ctrl.aluIn2Sel, imm)(
    Seq(
      AluInSelEnum.imm.asUInt -> imm,
      AluInSelEnum.rs.asUInt -> rs2Data,
      AluInSelEnum.csr.asUInt -> csrData
    )
  )
  val aluIn = Wire(new AluIO)
  aluIn.out := DontCare
  aluIn.aluOp := ctrl.aluOp
  aluIn.src1 := src1
  aluIn.src2 := src2
  // alus.foreach(alu => alu._2.io :<= aluIn)
  alu.io :<= aluIn

  // 根据扩展选择输出
  // val outTable: Seq[(UInt, UInt)] =
  //   alus.map { case (outSel: ExuOutSelEnum.Type, alu: AluParent) =>
  //     outSel.asUInt -> alu.io.out
  //   }.toSeq
  // val aluOut = MuxLookup(ctrl.exuOutSel, outTable.head._2)(
  //   outTable
  // )
  val aluOut = alu.io.out
  outBits.exuPayload.exu.aluOut := aluOut

  // 计算跳转地址
  val jumpTargetGenerator = Module(new JumpTargetGenerator)
  jumpTargetGenerator.io.jumpTargetSel := inBits.ctrl.wbuCtrl.jumpTargetSel
  jumpTargetGenerator.io.pc := pc
  jumpTargetGenerator.io.imm := imm
  jumpTargetGenerator.io.aluResult := aluOut
  outBits.exuPayload.exu.jumpTarget := jumpTargetGenerator.io.jumpTarget
  val predTarget = PcCat(cfg.hasC, exte.pcHi, inBits.iduPayload.ifu.predTarget)
  outBits.exuPayload.exu.predTargetMayErr := 
    predTarget =/= jumpTargetGenerator.io.jumpTarget

  PerfWhen(
    "calcFinish",
    out.fire,
    exte.debugEbreak
  )
}
