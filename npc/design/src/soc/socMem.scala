package testSoC
import chisel3._
import chisel3.util._

// see https://www.chisel-lang.org/api/latest/chisel3/util/circt/dpi/index.html
// chisel has native dpi interface since
//  https://github.com/chipsalliance/chisel/pull/4158
import chisel3.util.circt.dpi._

import common_def._

import axi4._
import dpiwrap._

import chisel3.probe._
import chisel3._
import chisel3.layer.{Layer, LayerConfig}
import chisel3.probe.{define, Probe, ProbeValue}

// https://www.chisel-lang.org/docs/explanations/memories#masks
// Create a 32-bit wide memory that is byte-masked
class MaskedRdWrMem(sizeInByte: Int, filePath: Option[String] = None) extends Module {
  val width:    Int = 8
  val numBytes: Int = 4

  val dataType = Vec(numBytes, UInt(width.W))
  val io       = IO(new Bundle {
    val write   = Input(Bool())
    val rdAddr  = Input(UInt(log2Ceil(sizeInByte).W))
    val wrAddr  = Input(UInt(log2Ceil(sizeInByte).W))
    val mask    = Input(Vec(numBytes, Bool()))
    val dataIn  = Input(dataType)
    val dataOut = Output(dataType)
  })

  require(sizeInByte % numBytes == 0, "sizeInByte must be a multiple of numBytes of word")
  val mem = Mem(sizeInByte / numBytes, dataType)

  if (filePath.isDefined) {
    chisel3.util.experimental.loadMemoryFromFileInline(mem, filePath.get)
  }

  val rdPort = mem(io.rdAddr >> log2Ceil(numBytes))
  val wrPort = mem(io.wrAddr >> log2Ceil(numBytes))
  when(io.write) {
    for (i <- 0 until numBytes) {
      when(io.mask(i)) {
        wrPort(i) := io.dataIn(i)
      }
    }
    io.dataOut := DontCare
  }.otherwise { io.dataOut := rdPort }
}

class AXI4MemUnit(val sizeInByte: Int,val InitHexFilePath: Option[String] = None) extends Module {
  val io = IO(AXI4IO.Slave)

  val sio = io

  // AR

  val rdAddrBegReg = Reg(Types.UWord)
  val rdAddrBeg    = Wire(Types.UWord)
  val rdAddr       = Wire(Types.UWord)
  dontTouch(rdAddr)
  dontTouch(rdAddrBeg)

  when(sio.arvalid && sio.arready) {
    rdAddrBeg := sio.araddr
  }

  val sARIdle :: sARWait :: Nil = Enum(2)
  val arState                   = RegInit(sARIdle)
  sio.arready := (arState === sARIdle) && (!reset.asBool)

  arState      := MuxLookup(arState, sARIdle)(
    Seq(
      sARIdle -> Mux(sio.arvalid, sARWait, sARIdle),
      sARWait -> Mux(sio.rvalid && sio.rlast, sARIdle, sARWait)
    )
  )
  rdAddrBegReg := Mux(sio.arvalid && sio.arready, sio.araddr, rdAddrBegReg)
  rdAddrBeg    := Mux(arState === sARIdle, sio.araddr, rdAddrBegReg)

  val arLen        = Reg(UInt(8.W))
  val curReadCount = Wire(UInt(8.W))
  dontTouch(curReadCount)

  when(sio.arvalid && sio.arready) {
    arLen := sio.arlen

    when(sio.arlen =/= 0.U) {
      assert(sio.arsize === AXI4IO.SizeType.WORD, "Only support word size read now")
      assert(sio.arburst === AXI4IO.BurstType.INCR, "Only support INCR burst type now")
    }
  }
  rdAddr := rdAddrBeg + (curReadCount << 2)

  // R
  // support burst read

  object RState extends ChiselEnum {
    val idle, waitMem, sendData = Value
  }
  val rState = RegInit(RState.idle)

  val rdFIFO = Module(new Queue(Types.UWord, 16))
  curReadCount := rdFIFO.io.count

  sio.rvalid          := (rState === RState.sendData) && rdFIFO.io.deq.valid
  rdFIFO.io.deq.ready := sio.rready && sio.rvalid
  sio.rdata           := rdFIFO.io.deq.bits
  sio.rresp           := AXI4IO.RResp.OKAY
  sio.rid             := 0.U
  sio.rlast           := (curReadCount === 1.U)

  rState := MuxLookup(rState, RState.idle)(
    Seq(
      RState.idle     -> Mux(sio.arvalid, RState.waitMem, RState.idle),
      RState.waitMem  -> Mux(curReadCount === arLen, RState.sendData, RState.waitMem),
      RState.sendData -> Mux(curReadCount === 0.U, Mux(sio.arvalid, RState.waitMem, RState.idle), RState.sendData)
    )
  )

  val enRdDataCall = WireDefault((rState === RState.waitMem) || (rState === RState.idle && sio.arvalid))
  dontTouch(enRdDataCall)

  val mem = Module(new MaskedRdWrMem(sizeInByte, InitHexFilePath))
  mem.io := DontCare

  when(rState === RState.waitMem) {
    mem.io.write        := false.B
    mem.io.rdAddr       := rdAddr
    rdFIFO.io.enq.bits  := mem.io.dataOut.asUInt
    rdFIFO.io.enq.valid := true.B
  }.otherwise {
    rdFIFO.io.enq.bits  := 0.U
    rdFIFO.io.enq.valid := false.B
  }

  // AW

  val wrAddr = Reg(Types.UWord)

  when(sio.awvalid && sio.awready) {
    wrAddr := sio.awaddr
  }

  val sAWIdle :: sAWWait :: Nil = Enum(2)
  val awState                   = RegInit(sAWIdle)
  sio.awready := (awState === sAWIdle)

  awState := MuxLookup(awState, sAWIdle)(
    Seq(
      sAWIdle -> Mux(sio.awvalid, sAWWait, sAWIdle),
      sAWWait -> Mux(sio.bvalid, sAWIdle, sAWWait)
    )
  )

  // W

  val wrData = Reg(Types.UWord)
  val wrMask = Reg(UInt(4.W))
  when(sio.wvalid && sio.wready) {
    wrData := sio.wdata
    wrMask := sio.wstrb
  }

  val sWIdle :: sWWait :: Nil = Enum(2)
  val wState                  = RegInit(sWIdle)
  sio.wready := (wState === sWIdle)
  wState     := MuxLookup(wState, sWIdle)(
    Seq(
      sWIdle -> Mux(sio.wvalid, sWWait, sWIdle),
      sWWait -> Mux(sio.bvalid, sWIdle, sWWait)
    )
  )

  // B

  val sBIdle :: sBWaitAddrOrData :: sBWaitMem :: sBWaitRdy :: Nil = Enum(4)

  val bState = RegInit(sBIdle)
  sio.bvalid := (bState === sBWaitRdy)
  sio.bresp  := AXI4IO.BResp.OKAY

  sio.bid := 0.U

  val memWriteFinished = Wire(Bool())
  val memWritePrepared = (awState === sAWWait) && (wState === sWWait)

  bState := MuxLookup(bState, sBIdle)(
    Seq(
      sBIdle           -> Mux(sio.awvalid || sio.wvalid, sBWaitAddrOrData, sBIdle),
      sBWaitAddrOrData -> Mux(memWritePrepared, sBWaitMem, sBWaitAddrOrData),
      sBWaitMem        -> Mux(memWriteFinished, sBWaitRdy, sBWaitMem),
      sBWaitRdy        -> Mux(sio.bready, sBIdle, sBWaitRdy)
    )
  )

  when(bState === sBWaitMem) {
    mem.io.write  := true.B
    mem.io.wrAddr := wrAddr
    mem.io.mask   := wrMask.asBools
    mem.io.dataIn := wrData.asTypeOf(mem.dataType)
  }
  // for now mem write always finish in one cycle
  memWriteFinished := RegNext(bState === sBWaitMem)

}
