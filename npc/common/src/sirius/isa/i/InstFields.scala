package sirius

import chisel3._
import chisel3.util.experimental.decode._
import chisel3.util.BitPat
import org.chipsalliance.rvdecoderdb
import cpuutil.CanAutoGenSig

object InstFieldsRvI {
  val fields = Seq(
    MakeBoolField("readRs1", "global", _.rs1Sel match {
      case _: RegAddrSelEnum.Type => true
      case _ => false
    }),
    MakeBoolField("readRs2", "global", _.rs2Sel match {
      case _: RegAddrSelEnum.Type => true
      case _ => false
    }),
    MakeEnumField("instType", "id", InstTypeEnum, _.instType),
    MakeEnumField("rs1Sel", "id", RegAddrSelEnum, _.rs1Sel),
    MakeEnumField("rs2Sel", "id", RegAddrSelEnum, _.rs2Sel),
    MakeEnumField("rdSel", "id", RegAddrSelEnum, _.rdSel),
    MakeEnumField("aluIn1Sel", "ex", AluInSelEnum, _.aluIn1Sel),
    MakeEnumField("aluIn2Sel", "ex", AluInSelEnum, _.aluIn2Sel),
    MakeEnumField("aluOp", "ex", AluOpEnum, _.aluOp),
    // MakeEnumField("exuOutSel", "ex", ExuOutSelEnum, _.exuOutSel),
    MakeBoolField(
      "isLoad",
      "ls",
      _.loadStoreType match {
        case LoadStoreTypeEnum.signedLoad   => true
        case LoadStoreTypeEnum.unsignedLoad => true
        case _                              => false
      }
    ),
    MakeBoolField(
      "isStore",
      "ls",
      _.loadStoreType match {
        case LoadStoreTypeEnum.store => true
        case _                       => false
      }
    ),
    MakeTriField(
      "isUnsignedLoad",
      "ls",
      _.loadStoreType match {
        case LoadStoreTypeEnum.unsignedLoad => TriState.True
        case LoadStoreTypeEnum.signedLoad   => TriState.False
        case _                              => TriState.DontCare
      }
    ),
    MakeEnumField(
      "loadStoreLength",
      "ls",
      LoadStoreLengthEnum,
      _.loadStoreLength
    ),
    MakeEnumField("jumpTargetSel", "wb", JumpTargetSelEnum, _.jumpTargetSel),
    MakeBoolField("isWriteBackReg", "wb", _.isWriteBackReg),
    MakeEnumField("writeBackSel", "wb", WriteBackSelEnum, _.writeBackSel),
    MakeBoolField("isBranch", "wb", _.isBranch),
    MakeBoolField("isJump", "wb", _.isJump),
    MakeBoolField("isJumpCsr", "wb", _.isJumpCsr),
    MakeBoolField("isEbreak", "wb", p => Set("ebreak", "c.ebreak").contains(p.name)),
    MakeBoolField("isEcall", "wb", _.name == "ecall"),
  )
}
