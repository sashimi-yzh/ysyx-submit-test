package btb

import chisel3._
import chisel3.util._

import common_def._

object BTBParameters {
  val ENTRY_NUM   = 2
  val INDEX_WIDTH = log2Ceil(ENTRY_NUM)
  val TAG_WIDTH   = Types.BitWidth.word - INDEX_WIDTH - 2 // 2 for word-alignment

  def extractTag(addr: UInt):   UInt = {
    addr(31, 32 - TAG_WIDTH)
  }
  def extractIndex(addr: UInt): UInt = {
    addr(32 - TAG_WIDTH - 1, 2)
  }
}

class BTBEntry extends Bundle {
  val valid  = Bool()
  val isJAL  = Bool()
  val tag    = UInt(BTBParameters.TAG_WIDTH.W)
  val target = Types.UWord
}

class BranchTargetBuffer extends Module {
  val io = IO(new Bundle {
    val query  = new Bundle {
      val addr   = Input(Types.UWord)
      val hit    = Output(Bool())
      val target = Output(Types.UWord)
      val isJAL  = Output(Bool())
    }
    val update = new Bundle {
      val en     = Input(Bool())
      val addr   = Input(Types.UWord)
      val isJAL  = Input(Bool())
      val target = Input(Types.UWord)
    }
  })

  val entries = RegInit(VecInit.fill(BTBParameters.ENTRY_NUM)(0.U.asTypeOf(new BTBEntry)))

  // Query logic
  val queryTag   = BTBParameters.extractTag(io.query.addr)
  val queryIndex = BTBParameters.extractIndex(io.query.addr)
  val queryEntry = entries(queryIndex)

  io.query.hit    := queryEntry.valid && (queryEntry.tag === queryTag)
  io.query.target := queryEntry.target
  io.query.isJAL  := queryEntry.isJAL

  // Update logic
  when(io.update.en) {
    val updateTag   = BTBParameters.extractTag(io.update.addr)
    val updateIndex = BTBParameters.extractIndex(io.update.addr)

    entries(updateIndex).valid  := true.B
    entries(updateIndex).tag    := updateTag
    entries(updateIndex).target := io.update.target
    entries(updateIndex).isJAL  := io.update.isJAL
  }
}
