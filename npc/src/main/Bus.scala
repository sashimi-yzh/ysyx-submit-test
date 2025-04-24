package npc
import chisel3._
import chisel3.util._

class DMEM extends AXI4Lite

class IF2ID extends NPCBundle {
  val pc = Output(UInt(PALEN.W))
  val inst = Output(UInt(32.W))
}

class InstDecode extends Bundle {
  val funct3 = Output(UInt(3.W))
  val aluop_isAdd = Output(Bool())
  val isArithShift = Output(Bool())
  val isLoad = Output(Bool())
  val isStore = Output(Bool())
  val isJmp = Output(Bool())
  val isBranch = Output(Bool())
  val isWord = Output(Bool())
  val isEcall = Output(Bool())
  val isMret  = Output(Bool())
  val isCSR   = Output(Bool())
  val isFencei = Output(Bool())
  val illegal = Output(Bool())
  val csrRen = Output(Bool())
  val csrWen = Output(Bool())
}

class ID2EX extends NPCBundle {
  val src1 = Output(UInt(XLEN.W))
  val src2 = Output(UInt(XLEN.W))
  val src3 = Output(UInt(XLEN.W))
  val wen = Output(Bool())
  val rd  = Output(UInt(GPRIdxBits.W))
  val decode = new InstDecode
  val npctrap = new NPCTrapIO
}

class RedirectIO extends NPCBundle {
  val valid = Output(Bool())
  val dnpc = Output(UInt(PALEN.W))
}

class NPCTrapIO extends NPCBundle {
  val valid = Output(Bool())
  val pc = Output(UInt(PALEN.W))
  val dnpc = Output(UInt(PALEN.W))
  val isEbreak = Output(Bool())
  val code = Output(UInt(XLEN.W))
  val isMMIO = Output(Bool())
  val memAddr = Output(UInt(PALEN.W))
  val skip = Output(Bool())
}

class WriteBack extends NPCBundle {
  val res = Output(UInt(XLEN.W))
  val wen = Output(Bool())
  val rd  = Output(UInt(GPRIdxBits.W))
}

class Forward extends WriteBack {
  val notReady = Output(Bool())
}

class EX2LS extends WriteBack {
  val res2  = Output(UInt(XLEN.W))
  val decode = new InstDecode
  val redirect = Output(Bool())
  val npctrap = new NPCTrapIO
}

class LS2WB extends WriteBack {
  val npctrap = new NPCTrapIO
}

class MemSinglePortReqBundle extends NPCBundle {
  val addr  = Output(UInt(PALEN.W))
  val size  = Output(UInt(2.W))
  val wen   = Output(Bool())
  val wdata = Output(UInt(XLEN.W))
  val wmask = Output(UInt((XLEN / 8).W))
}

class MemBundle extends MemSinglePortReqBundle {
  val valid = Output(Bool())
  val rdata = Input(UInt(XLEN.W))
}

class MemRWPortBundle extends NPCBundle {
  val clock = Output(Bool())
  val ren   = Output(Bool())
  val raddr = Output(UInt(PALEN.W))
  val rdata = Input(UInt(XLEN.W))
  val wen   = Output(Bool())
  val waddr = Output(UInt(PALEN.W))
  val wdata = Output(UInt(XLEN.W))
  val wmask = Output(UInt((XLEN / 8).W))
}

class CacheBundle extends NPCBundle {
  val resp = Flipped(Decoupled(new Bundle {
    val addr = Output(UInt(PALEN.W))
    val data = Output(UInt(XLEN.W))
  }))
  val req = Decoupled(new MemSinglePortReqBundle)
}
