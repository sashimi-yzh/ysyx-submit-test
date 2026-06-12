package sirius

import chisel3._
import chisel3.util.experimental.decode._
import chisel3.util.BitPat
import org.chipsalliance.rvdecoderdb

case class InstPatternRvC(
)(
  implicit private val insts: Iterable[rvdecoderdb.Instruction],
  implicit private val cfg:   CoreConfig) {
  // Dont care RES
  // private val Seq(_, bsAddi4spn) = PriorityBitSet(Seq(
  //   BitPat("b000 0 00 000 00 ??? 00"),
  //   GetInstBitPat("c.addi4spn")
  // ))

  // private val Seq(_, bsAddi16sp, _, bsLui) = PriorityBitSet(Seq(
  //   BitPat("b011 0 00 010 00 000 01"),
  //   GetInstBitPat("c.addi16sp"),
  //   BitPat("b011 0 ?? ??? 00 000 01"),
  //   GetInstBitPat("c.lui")
  // ))
  private val Seq(bsAddi16sp, bsLui) = PriorityBitSet(Seq(
    GetInstBitPat("c.addi16sp"),
    GetInstBitPat("c.lui")
  ))

  // private val Seq(_, bsLwsp) = PriorityBitSet(Seq(
  //   BitPat("b010 ? 00 000 ?? ??? 10"),
  //   GetInstBitPat("c.lwsp")
  // ))
  
  // private val Seq(_, bsJr, bsMv) = PriorityBitSet(Seq(
  //   BitPat("b100 0 00 000 00 000 10"),
  //   GetInstBitPat("c.jr"),
  //   GetInstBitPat("c.mv"),
  // ))
  private val Seq(bsJr, bsMv) = PriorityBitSet(Seq(
    GetInstBitPat("c.jr"),
    GetInstBitPat("c.mv"),
  ))

  private val Seq(bsEbreak, bsJalr, bsAdd) = PriorityBitSet(Seq(
    GetInstBitPat("c.ebreak"),
    GetInstBitPat("c.jalr"),
    GetInstBitPat("c.add"),
  ))

  val pattern = Seq(
    InstPattern(
      "c.addi4spn",
      ExtTypeEnum.C,
      InstTypeEnum.CADDI4SPN,
      rs1Sel = RegAddrSelEnum.x2,
      rdSel = RegAddrSelEnum.crdrs2p,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.add,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu
    ),
    InstPattern(
      "c.lw",
      ExtTypeEnum.C,
      InstTypeEnum.CLSW,
      rs1Sel = RegAddrSelEnum.crdrs1p,
      rdSel = RegAddrSelEnum.crdrs2p,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.add,
      exuOutSel = ExuOutSelEnum.aluBase,
      loadStoreType = LoadStoreTypeEnum.signedLoad,
      loadStoreLength = LoadStoreLengthEnum.w,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.lsu
    ),
    InstPattern(
      "c.sw",
      ExtTypeEnum.C,
      InstTypeEnum.CLSW,
      rs1Sel = RegAddrSelEnum.crdrs1p,
      rs2Sel = RegAddrSelEnum.crdrs2p,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.add,
      exuOutSel = ExuOutSelEnum.aluBase,
      loadStoreType = LoadStoreTypeEnum.store,
      loadStoreLength = LoadStoreLengthEnum.w
    ),
    InstPattern(
      "c.addi",
      ExtTypeEnum.C,
      InstTypeEnum.CLIADDI,
      rs1Sel = RegAddrSelEnum.rd,
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.add,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu
    ),
    InstPattern(
      "c.jal",
      ExtTypeEnum.C,
      InstTypeEnum.CJ,
      rdSel = RegAddrSelEnum.x1,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.staticNextPc,
      isJump = true,
      jumpTargetSel = JumpTargetSelEnum.pcPlusImm
    ),
    InstPattern(
      "c.li",
      ExtTypeEnum.C,
      InstTypeEnum.CLIADDI,
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.direct1,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu,
    ),
    InstPattern(
      "c.addi16sp",
      ExtTypeEnum.C,
      InstTypeEnum.CADDI16SP,
      bs = Some(bsAddi16sp),
      rs1Sel = RegAddrSelEnum.x2,
      rdSel = RegAddrSelEnum.x2,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.add,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu,
    ),
    InstPattern(
      "c.lui",
      ExtTypeEnum.C,
      InstTypeEnum.CLUI,
      bs = Some(bsLui),
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.direct1,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu,
    ),
    InstPattern(
      "c.srli",
      ExtTypeEnum.C,
      InstTypeEnum.CLIADDI,
      rs1Sel = RegAddrSelEnum.crdrs1p,
      rdSel = RegAddrSelEnum.crdrs1p,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.srl,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu,
    ),
    InstPattern(
      "c.srai",
      ExtTypeEnum.C,
      InstTypeEnum.CLIADDI,
      rs1Sel = RegAddrSelEnum.crdrs1p,
      rdSel = RegAddrSelEnum.crdrs1p,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.sra,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu,
    ),
    InstPattern(
      "c.andi",
      ExtTypeEnum.C,
      InstTypeEnum.CLIADDI,
      rs1Sel = RegAddrSelEnum.crdrs1p,
      rdSel = RegAddrSelEnum.crdrs1p,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.and,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu,
    ),
    InstPattern(
      "c.sub",
      ExtTypeEnum.C,
      DontCare,
      rs1Sel = RegAddrSelEnum.crdrs1p,
      rs2Sel = RegAddrSelEnum.crdrs2p,
      rdSel = RegAddrSelEnum.crdrs1p,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.rs,
      aluOp = AluOpEnum.sub,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu,
    ),
    InstPattern(
      "c.xor",
      ExtTypeEnum.C,
      DontCare,
      rs1Sel = RegAddrSelEnum.crdrs1p,
      rs2Sel = RegAddrSelEnum.crdrs2p,
      rdSel = RegAddrSelEnum.crdrs1p,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.rs,
      aluOp = AluOpEnum.xor,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu,
    ),
    InstPattern(
      "c.or",
      ExtTypeEnum.C,
      DontCare,
      rs1Sel = RegAddrSelEnum.crdrs1p,
      rs2Sel = RegAddrSelEnum.crdrs2p,
      rdSel = RegAddrSelEnum.crdrs1p,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.rs,
      aluOp = AluOpEnum.or,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu,
    ),
    InstPattern(
      "c.and",
      ExtTypeEnum.C,
      DontCare,
      rs1Sel = RegAddrSelEnum.crdrs1p,
      rs2Sel = RegAddrSelEnum.crdrs2p,
      rdSel = RegAddrSelEnum.crdrs1p,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.rs,
      aluOp = AluOpEnum.and,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu,
    ),
    InstPattern(
      "c.j",
      ExtTypeEnum.C,
      InstTypeEnum.CJ,
      isJump = true,
      jumpTargetSel = JumpTargetSelEnum.pcPlusImm
    ),
    InstPattern(
      "c.beqz",
      ExtTypeEnum.C,
      InstTypeEnum.CB,
      rs1Sel = RegAddrSelEnum.crdrs1p,
      rs2Sel = RegAddrSelEnum.x0,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.rs,
      aluOp = AluOpEnum.eql,
      exuOutSel = ExuOutSelEnum.aluBase,
      isBranch = true,
      jumpTargetSel = JumpTargetSelEnum.pcPlusImm
    ),
    InstPattern(
      "c.bnez",
      ExtTypeEnum.C,
      InstTypeEnum.CB,
      rs1Sel = RegAddrSelEnum.crdrs1p,
      rs2Sel = RegAddrSelEnum.x0,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.rs,
      aluOp = AluOpEnum.neq,
      exuOutSel = ExuOutSelEnum.aluBase,
      isBranch = true,
      jumpTargetSel = JumpTargetSelEnum.pcPlusImm
    ),
    InstPattern(
      "c.slli",
      ExtTypeEnum.C,
      InstTypeEnum.CLIADDI,
      rs1Sel = RegAddrSelEnum.rd,
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.sll,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu,
    ),
    InstPattern(
      "c.lwsp",
      ExtTypeEnum.C,
      InstTypeEnum.CLWSP,
      rs1Sel = RegAddrSelEnum.x2,
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.add,
      exuOutSel = ExuOutSelEnum.aluBase,
      loadStoreType = LoadStoreTypeEnum.signedLoad,
      loadStoreLength = LoadStoreLengthEnum.w,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.lsu
    ),
    InstPattern(
      "c.jr",
      ExtTypeEnum.C,
      DontCare,
      bs = Some(bsJr),
      rs1Sel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.rs,
      aluOp = AluOpEnum.direct1,
      exuOutSel = ExuOutSelEnum.aluBase,
      isJump = true,
      jumpTargetSel = JumpTargetSelEnum.alu
    ),
    InstPattern(
      "c.mv",
      ExtTypeEnum.C,
      DontCare,
      bs = Some(bsMv),
      rs2Sel = RegAddrSelEnum.crs2,
      rdSel = RegAddrSelEnum.rd,
      aluIn2Sel = AluInSelEnum.rs,
      aluOp = AluOpEnum.direct2,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu
    ),
    InstPattern(
      "c.ebreak",
      ExtTypeEnum.C,
      DontCare,
      bs = Some(bsEbreak)
    ),
    InstPattern(
      "c.jalr",
      ExtTypeEnum.C,
      DontCare,
      bs = Some(bsJalr),
      rs1Sel = RegAddrSelEnum.rd,
      rdSel = RegAddrSelEnum.x1,
      aluIn1Sel = AluInSelEnum.rs,
      aluOp = AluOpEnum.direct1,
      exuOutSel = ExuOutSelEnum.aluBase,
      isJump = true,
      jumpTargetSel = JumpTargetSelEnum.alu,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.staticNextPc
    ),
    InstPattern(
      "c.add",
      ExtTypeEnum.C,
      DontCare,
      bs = Some(bsAdd),
      rs1Sel = RegAddrSelEnum.rd,
      rs2Sel = RegAddrSelEnum.crs2,
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.rs,
      aluOp = AluOpEnum.add,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.alu
    ),
    InstPattern(
      "c.swsp",
      ExtTypeEnum.C,
      InstTypeEnum.CSWSP,
      rs1Sel = RegAddrSelEnum.x2,
      rs2Sel = RegAddrSelEnum.crs2,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.add,
      exuOutSel = ExuOutSelEnum.aluBase,
      loadStoreType = LoadStoreTypeEnum.store,
      loadStoreLength = LoadStoreLengthEnum.w,
    ),
  )
}
