package sirius

import chisel3._
import chisel3.util.experimental.decode._
import chisel3.util.BitPat
import org.chipsalliance.rvdecoderdb

case class InstPatternRvZicsr(
)(
  implicit private val insts: Iterable[rvdecoderdb.Instruction],
  implicit private val cfg:   CoreConfig) {
  val pattern = Seq(
    InstPattern(
      "csrrw",
      ExtTypeEnum.Zicsr,
      InstTypeEnum.Zicsr,
      rs1Sel = RegAddrSelEnum.rs,
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.rs,
      aluOp = AluOpEnum.direct1,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.csr,
      isWriteBackCsr = true,
      isCsrWriteCheck = false,
    ),
    InstPattern(
      "csrrs",
      ExtTypeEnum.Zicsr,
      InstTypeEnum.Zicsr,
      rs1Sel = RegAddrSelEnum.rs,
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.csr,
      aluOp = AluOpEnum.or,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.csr,
      isWriteBackCsr = true,
      isCsrWriteCheck = true,
    ),
    InstPattern(
      "csrrc",
      ExtTypeEnum.Zicsr,
      InstTypeEnum.Zicsr,
      rs1Sel = RegAddrSelEnum.rs,
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.rs,
      aluIn2Sel = AluInSelEnum.csr,
      aluOp = AluOpEnum.clear,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.csr,
      isWriteBackCsr = true,
      isCsrWriteCheck = true,
    ),
    InstPattern(
      "csrrwi",
      ExtTypeEnum.Zicsr,
      InstTypeEnum.Zicsr,
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.imm,
      aluOp = AluOpEnum.direct1,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.csr,
      isWriteBackCsr = true,
      isCsrWriteCheck = false,
    ),
    InstPattern(
      "csrrsi",
      ExtTypeEnum.Zicsr,
      InstTypeEnum.Zicsr,
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.imm,
      aluIn2Sel = AluInSelEnum.csr,
      aluOp = AluOpEnum.or,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.csr,
      isWriteBackCsr = true,
      isCsrWriteCheck = true,
    ),
    InstPattern(
      "csrrci",
      ExtTypeEnum.Zicsr,
      InstTypeEnum.Zicsr,
      rdSel = RegAddrSelEnum.rd,
      aluIn1Sel = AluInSelEnum.imm,
      aluIn2Sel = AluInSelEnum.csr,
      aluOp = AluOpEnum.clear,
      exuOutSel = ExuOutSelEnum.aluBase,
      isWriteBackReg = true,
      writeBackSel = WriteBackSelEnum.csr,
      isWriteBackCsr = true,
      isCsrWriteCheck = true,
    ),
  )
}
