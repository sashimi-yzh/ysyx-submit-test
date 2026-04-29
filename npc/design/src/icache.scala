package icache

import chisel3._
import chisel3.util._

import common_def._
import axi4._

import xbar._
import cpu.EXUIFU_MemVisitArbiter

class ICacheIO extends Bundle {
  val cpu = AXI4IO.Slave
  val mem = AXI4IO.Master

  val flush = Input(Bool())
}

object ICacheParameters {
  val BLOCK_SIZE         = 8
  val BLOCK_NUM          = 8
  val BLOCK_SIZE_INBITS  = BLOCK_SIZE * 8
  val BLOCK_SIZE_INWORDS = BLOCK_SIZE / 4

  val ARLEN = BLOCK_SIZE_INWORDS - 1

  require(BLOCK_SIZE % 4 == 0)
  require(isPow2(BLOCK_SIZE))
  require(isPow2(BLOCK_NUM))

  val BLOCK_INDEX_WIDTH = log2Ceil(BLOCK_NUM)
  val BLOCK_TAG_WIDTH   = 32 - log2Ceil(BLOCK_SIZE) - BLOCK_INDEX_WIDTH

  def extractTag(addr: UInt):        UInt = {
    addr(31, 32 - BLOCK_TAG_WIDTH)
  }
  def extractIndex(addr: UInt):      UInt = {
    addr(32 - BLOCK_TAG_WIDTH - 1, 32 - BLOCK_TAG_WIDTH - BLOCK_INDEX_WIDTH)
  }
  def extractOffset(addr: UInt):     UInt = {
    addr(log2Ceil(BLOCK_SIZE) - 1, 0)
  }
  def extractWordOffset(addr: UInt): UInt = {
    if (BLOCK_SIZE_INWORDS == 1) 0.U
    else addr(log2Ceil(BLOCK_SIZE) - 1, 2)
  }
  def alignToBlock(addr: UInt):      UInt = {
    addr(31, log2Ceil(BLOCK_SIZE)) ## 0.U(log2Ceil(BLOCK_SIZE).W)
  }

  // for old
  def cacheLineVecType = Vec(BLOCK_SIZE_INWORDS, Types.UWord)
}

class ICacheBlock extends Bundle {
  val valid = Bool()
  val tag   = UInt(ICacheParameters.BLOCK_TAG_WIDTH.W)
  // val data  = UInt(ICacheParameters.BLOCK_SIZE_INBITS.W)
  val data  = Vec(ICacheParameters.BLOCK_SIZE_INWORDS, Types.InstCodeNoCExt)

  // Assume index and offset are correct
  def matchAddr(addr: UInt): Bool = {
    tag === ICacheParameters.extractTag(addr) && valid
  }
}

class ICacheSRAMDirectlyWrBlock extends Module {
  val io  = IO(new Bundle {
    val addr  = Input(UInt(ICacheParameters.BLOCK_INDEX_WIDTH.W))
    val wen   = Input(Bool())
    val wdata = Input(new ICacheBlock)
    val rdata = Output(new ICacheBlock)
    val flush = Input(Bool())
  })
  val mem = RegInit(VecInit(Seq.fill(ICacheParameters.BLOCK_NUM)(0.U.asTypeOf(new ICacheBlock))))

  when(io.flush) {
    for (i <- 0 until ICacheParameters.BLOCK_NUM) {
      mem(i).valid := false.B
    }
  }.elsewhen(io.wen) {
    mem(io.addr) := io.wdata
  }
  io.rdata := RegNext(mem(io.addr))
}

class ICacheSRAM extends Module {
  val io = IO(new Bundle {
    val addr       = Input(UInt(ICacheParameters.BLOCK_INDEX_WIDTH.W))
    val wen        = Input(Bool())
    val wordOffset = Input(UInt(log2Ceil(ICacheParameters.BLOCK_SIZE_INWORDS).W))
    val wdataWord  = Input(Types.UWord)
    val wlast      = Input(Bool())
    val wtag       = Input(UInt(ICacheParameters.BLOCK_TAG_WIDTH.W))
    val rdata      = Output(new ICacheBlock)
    val flush      = Input(Bool())
  })
  
  val mem = RegInit(VecInit(Seq.fill(ICacheParameters.BLOCK_NUM)(0.U.asTypeOf(new ICacheBlock))))

  when(io.flush) {
    for (i <- 0 until ICacheParameters.BLOCK_NUM) {
      mem(i).valid := false.B
    }
  }.elsewhen(io.wen) {
    mem(io.addr).data(io.wordOffset).raw := io.wdataWord(31, 2)
    when(io.wlast) {
      mem(io.addr).tag := io.wtag
      mem(io.addr).valid := true.B
    }
  }

  val raddr = RegNext(io.addr)
  io.rdata := mem(raddr)
}

class ICache extends Module {
  val io = IO(new ICacheIO)

  io.cpu.dontCareAW()
  io.cpu.dontCareW()
  io.cpu.dontCareB()

  io.mem.dontCareAW()
  io.mem.dontCareW()
  io.mem.dontCareB()


  val cacheRAM = Module(new ICacheSRAM)

  object State extends ChiselEnum {
    val idle, checkHit, sendFetch, waitMem = Value
  }
  val state = RegInit(State.idle)

  val cpuAddrIdx    = ICacheParameters.extractIndex(io.cpu.araddr)
  val cpuAddrTag    = ICacheParameters.extractTag(io.cpu.araddr)
  val cpuAddrOffset = ICacheParameters.extractWordOffset(io.cpu.araddr)
  val destAddrAligned = ICacheParameters.alignToBlock(io.cpu.araddr)

  val hasMultiWordInline = ICacheParameters.BLOCK_SIZE_INWORDS > 1

  val memIOCurRdOffset = if (hasMultiWordInline) RegInit(0.U(log2Ceil(ICacheParameters.BLOCK_SIZE_INWORDS).W)) else 0.U
  when(io.mem.rvalid && io.mem.rready) {
    if (hasMultiWordInline) {
      when(io.mem.rlast) {
        memIOCurRdOffset := 0.U
      }.otherwise {
        memIOCurRdOffset := memIOCurRdOffset + 1.U
      }
    } else {
      sys.error("ICache not support single-word line now")
    }
  }

  cacheRAM.io.flush      := io.flush
  cacheRAM.io.addr       := cpuAddrIdx

  cacheRAM.io.wen        := (state === State.waitMem) && io.mem.rvalid
  cacheRAM.io.wordOffset := memIOCurRdOffset
  cacheRAM.io.wdataWord  := io.mem.rdata
  cacheRAM.io.wlast      := io.mem.rlast
  cacheRAM.io.wtag       := cpuAddrTag

  val cacheHit = cacheRAM.io.rdata.matchAddr(io.cpu.araddr)

  val memIOMeetLast = io.mem.rvalid && io.mem.rlast

  state := MuxLookup(state, State.idle)(
    Seq(
      State.idle      -> Mux(io.cpu.arvalid, State.checkHit, State.idle),
      State.checkHit  -> Mux(cacheHit, State.idle, State.sendFetch),
      State.sendFetch -> Mux(io.mem.arready, State.waitMem, State.sendFetch),
      State.waitMem   -> Mux(memIOMeetLast, State.idle, State.waitMem)
    )
  )

  val txnDone = (state === State.waitMem && memIOMeetLast) || (state === State.checkHit && cacheHit)
  
  io.cpu.arready := txnDone
  io.cpu.rvalid  := txnDone
  io.cpu.rresp   := AXI4IO.RResp.OKAY
  io.cpu.rid     := io.mem.rid
  io.cpu.rlast   := true.B

  // rvalid when mem read last beat or cache hit, in rlast case, data not stored
  // in cacheRAM yet, when cpuAddrOffset is same as memIOCurRdOffset, means cpu
  // need the rlast data, so bypass it directly instead of reading from cacheRAM
  // which is not updated
  val bypassData = (state === State.waitMem) && (cpuAddrOffset === memIOCurRdOffset)
  io.cpu.rdata   := Mux(bypassData, io.mem.rdata, cacheRAM.io.rdata.data(cpuAddrOffset).get)

  io.mem.arvalid := (state === State.sendFetch)
  io.mem.arid    := io.cpu.arid
  io.mem.araddr  := destAddrAligned
  io.mem.arlen   := ICacheParameters.ARLEN.U
  io.mem.arsize  := AXI4IO.SizeType.WORD
  io.mem.arburst := AXI4IO.BurstType.INCR
  io.mem.rready  := (state === State.waitMem)
}

