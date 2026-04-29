package icache

import chisel3._
import chisel3.util._

import common_def._
import axi4._

import xbar._
import cpu.EXUIFU_MemVisitArbiter

class ICacheWithManyReg extends Module {
  val io = IO(new ICacheIO)

  io.cpu.dontCareAW()
  io.cpu.dontCareW()
  io.cpu.dontCareB()

  io.mem.dontCareAW()
  io.mem.dontCareW()
  io.mem.dontCareB()

  val memIOMeetLast = io.mem.rvalid && io.mem.rlast

  val cacheRAM       = Module(new ICacheSRAMDirectlyWrBlock)
  val cacheRdData    = cacheRAM.io.rdata
  val cacheHit       = cacheRdData.matchAddr(io.cpu.araddr)
  val cacheRdDataVec = cacheRdData.data.asTypeOf(ICacheParameters.cacheLineVecType)

  object State extends ChiselEnum {
    val idle, checkHit, sendFetch, waitMem = Value
  }
  val state = RegInit(State.idle)

  val destAddrIdx     = RegEnableReadNew(
    ICacheParameters.extractIndex(io.cpu.araddr),
    io.cpu.arvalid && io.cpu.arready
  )
  val destAddrOffset  = RegEnable(
    ICacheParameters.extractWordOffset(io.cpu.araddr),
    io.cpu.arvalid && io.cpu.arready
  )
  val destAddrTag     = RegEnable(
    ICacheParameters.extractTag(io.cpu.araddr),
    io.cpu.arvalid && io.cpu.arready
  )
  val destAddrAligned = destAddrTag ## destAddrIdx ## 0.U(log2Ceil(ICacheParameters.BLOCK_SIZE).W)

  val hasMultiWordInline = ICacheParameters.BLOCK_SIZE_INWORDS > 1

  val memIOCurRdOffset  =
    if (hasMultiWordInline) RegInit(0.U(log2Ceil(ICacheParameters.BLOCK_SIZE_INWORDS - 1).W)) else 0.U
  val memIORdDataVecReg = Reg(Vec(ICacheParameters.BLOCK_SIZE_INWORDS - 1, Types.UWord))
  when(io.mem.rvalid && io.mem.rready) {
    if (hasMultiWordInline) {
      when(memIOMeetLast) {
        memIOCurRdOffset := 0.U
      }.otherwise {
        memIORdDataVecReg(memIOCurRdOffset) := io.mem.rdata
        memIOCurRdOffset                    := memIOCurRdOffset + 1.U
      }
    } else {
      sys.error("ICache not support sigle-word line now")
    }
  }

  // newest (rlast) data is direct from mem
  val memIORdDataVec = (io.mem.rdata ## memIORdDataVecReg.asUInt).asTypeOf(ICacheParameters.cacheLineVecType)

  cacheRAM.io.flush       := io.flush
  cacheRAM.io.addr        := destAddrIdx
  cacheRAM.io.wen         := (state === State.waitMem) && memIOMeetLast
  cacheRAM.io.wdata.valid := true.B
  cacheRAM.io.wdata.tag   := destAddrTag
  cacheRAM.io.wdata.data  := memIORdDataVec.asUInt

  state := MuxLookup(state, State.idle)(
    Seq(
      State.idle      -> Mux(io.cpu.arvalid && io.cpu.arready, State.checkHit, State.idle),
      State.checkHit  -> Mux(cacheHit, State.idle, State.sendFetch),
      State.sendFetch -> Mux(io.mem.arready, State.waitMem, State.sendFetch),
      State.waitMem   -> Mux(memIOMeetLast, State.idle, State.waitMem)
    )
  )

  io.cpu.arready := (state === State.idle)
  io.cpu.rvalid  := (state === State.waitMem && memIOMeetLast) || (state === State.checkHit && cacheHit)
  io.cpu.rresp   := AXI4IO.RResp.OKAY
  io.cpu.rid     := io.mem.rid
  io.cpu.rlast   := true.B
  io.cpu.rdata   := Mux(state === State.waitMem, memIORdDataVec(destAddrOffset), cacheRdDataVec(destAddrOffset))

  io.mem.arvalid := (state === State.sendFetch)
  io.mem.arid    := io.cpu.arid
  io.mem.araddr  := destAddrAligned
  io.mem.arlen   := ICacheParameters.ARLEN.U
  io.mem.arsize  := AXI4IO.SizeType.WORD
  io.mem.arburst := AXI4IO.BurstType.INCR

  io.mem.rready := (state === State.waitMem)

}

class ICacheRegMem extends Module {
  val io = IO(new ICacheIO)

  io.cpu.dontCareAW()
  io.cpu.dontCareW()
  io.cpu.dontCareB()

  io.mem.dontCareAW()
  io.mem.dontCareW()
  io.mem.dontCareB()

  val blocks = RegInit(VecInit(Seq.fill(ICacheParameters.BLOCK_NUM)(0.U.asTypeOf(new ICacheBlock))))

  object State extends ChiselEnum {
    val idle, sendFetch, waitMem = Value
  }
  val state = RegInit(State.idle)

  val rdAddrReg = Reg(Types.UWord)

  when(io.cpu.arvalid && io.cpu.arready) {
    rdAddrReg := io.cpu.araddr
  }
  val rdAddr = Mux(io.cpu.arvalid && io.cpu.arready, io.cpu.araddr, rdAddrReg)

  val rdIdx        = ICacheParameters.extractIndex(rdAddr)
  val rdCacheBlock = blocks(rdIdx)
  val cacheHit     = rdCacheBlock.matchAddr(rdAddr)

  val dbgRdCacheBlock = WireDefault(rdCacheBlock)
  dontTouch(dbgRdCacheBlock)
  dontTouch(rdIdx)
  dontTouch(cacheHit)

  io.cpu.arready := (state === State.idle) && (!reset.asBool)
  io.mem.arvalid := (state === State.sendFetch)
  // AXI4IO.noShakeConnectAR(io.cpu, io.mem)

  io.mem.arid    := io.cpu.arid
  io.mem.araddr  := ICacheParameters.alignToBlock(rdAddr)
  io.mem.arlen   := ICacheParameters.ARLEN.U
  io.mem.arsize  := AXI4IO.SizeType.WORD
  io.mem.arburst := AXI4IO.BurstType.INCR

  io.mem.rready := (state === State.waitMem)

  val nxtCacheData = Wire(UInt(ICacheParameters.BLOCK_SIZE_INBITS.W))
  dontTouch(nxtCacheData)

  nxtCacheData := {
    if (ICacheParameters.BLOCK_SIZE_INBITS > 32)
      // Cat(io.mem.rdata, rdCacheBlock.data(ICacheParameters.BLOCK_SIZE_INBITS - 1, 32))
      Cat(io.mem.rdata, rdCacheBlock.data.asUInt(ICacheParameters.BLOCK_SIZE_INBITS - 1, 32))
    else
      io.mem.rdata
  }

  when(state === State.waitMem && io.mem.rvalid) {
    // fill cache
    rdCacheBlock.valid := true.B
    rdCacheBlock.tag   := ICacheParameters.extractTag(rdAddr)
    rdCacheBlock.data  := nxtCacheData
  }
  when(io.flush) {
    for (i <- 0 until ICacheParameters.BLOCK_NUM) {
      blocks(i).valid := false.B
    }
  }

  io.cpu.rvalid := (state === State.waitMem && io.mem.rlast && io.mem.rvalid) || (state === State.idle && cacheHit && io.cpu.arvalid && io.cpu.arready)
  val wordOffset = ICacheParameters.extractWordOffset(rdAddr)

  io.cpu.rresp := AXI4IO.RResp.OKAY
  // TODO: support burst read
  io.cpu.rid   := io.mem.rid
  io.cpu.rlast := true.B

  // when not hit, since rvaild at the end of waitMem, the data is from nxtCacheData
  val rdData = Mux(io.mem.rvalid || (!cacheHit), nxtCacheData, rdCacheBlock.data)
  dontTouch(rdData)

  val rdDataAsVec = rdData.asTypeOf(Vec(ICacheParameters.BLOCK_SIZE_INWORDS, Types.UWord))
  val destData    = Wire(UInt(32.W))
  dontTouch(destData)
  destData     := rdDataAsVec(wordOffset)
  io.cpu.rdata := destData

  state := MuxLookup(state, State.idle)(
    Seq(
      State.idle      -> Mux(io.cpu.arvalid && io.cpu.arready && (!cacheHit), State.sendFetch, State.idle),
      State.sendFetch -> Mux(io.mem.arready, State.waitMem, State.sendFetch),
      State.waitMem   -> Mux(io.mem.rvalid && io.mem.rlast, State.idle, State.waitMem)
    )
  )

}

class ICacheWithDirectVisit extends Module {
  val io = IO(new ICacheIO)

  val cache = Module(new ICache)
  cache.io.flush := io.flush

  val directWire = Wire(AXI4IO.Slave)

  val xbar = Module(
    new AXI4LiteXBar(
      Seq(
        AddrSpace.SRAM           -> directWire,
        AddrSpace.SOC_ExceptSRAM -> cache.io.cpu
      )
    )
  )

  xbar.io.in <> io.cpu
  xbar.connect()

  val memArbiter = Module(new EXUIFU_MemVisitArbiter)
  memArbiter.io.ifu <> directWire
  memArbiter.io.exu <> cache.io.mem

  io.mem <> memArbiter.io.out

}
