package sirius

import chisel3._

object ExtTypeEnum extends ChiselEnum {
  val I, Zicsr, Zifencei, M, C = Value
}

object InstTypeEnum extends ChiselEnum {
  val R, I, S, B, U, J, Zicsr = Value
  val CLWSP, CSWSP, CLSW, CJ, CB, CLIADDI, CLUI, CADDI16SP, CADDI4SPN = Value
}

object AluInSelEnum extends ChiselEnum {
  val imm, rs, pc, csr = Value
}

object RegAddrSelEnum extends ChiselEnum {
  val rd, rs, crs2, crdrs1p, crdrs2p, x0, x1, x2 = Value
}

object AluOpEnum extends ChiselEnum {
  val add, sub, 
    and, or, xor,
    eql, neq, lt, ltu, ge, geu, 
    sll, srl, sra,
    direct1, direct2, clear = Value
}

object ExuOutSelEnum extends ChiselEnum {
  val aluBase = Value
}

object JumpTargetSelEnum extends ChiselEnum {
  val alu, pcPlusImm, mepc = Value
}

object WriteBackSelEnum extends ChiselEnum {
  val alu, staticNextPc, lsu, csr = Value
}

object LoadStoreTypeEnum extends ChiselEnum {
  val signedLoad, unsignedLoad, store = Value
}

object LoadStoreLengthEnum extends ChiselEnum {
  val b, h, w = Value
}

object CsrEnum extends ChiselEnum {
  val mvendorid, marchid, mtvec, mepc, mcause, mstatus = Value
}

object CsrAddr {
  val mvendorid = "hF11".U
  val marchid = "hF12".U
  val mtvec = "h305".U
  val mepc = "h341".U
  val mcause = "h342".U
  val mstatus = "h300".U
  // val mcycle = "hB00".U
  // val mcycleh = "hB80".U

  def getAllMap: Seq[(UInt, CsrEnum.Type)] = Seq(
    mvendorid -> CsrEnum.mvendorid,
    marchid -> CsrEnum.marchid,
    mtvec -> CsrEnum.mtvec,
    mepc -> CsrEnum.mepc,
    mcause -> CsrEnum.mcause,
    mstatus -> CsrEnum.mstatus
  )
}

object CsrWOpCode extends ChiselEnum {
  val write, set, clear = Value
}

object McauseEnum {
  val LoadAddressMisaligned: BigInt = 4
  val LoadAccessFault: BigInt = 5
  val StoreOrAmoAddressMisaligned: BigInt = 6
  val StoreOrAmoAccessFault: BigInt = 7
  val EnvironmentCallFromM: BigInt = 11
}
