package top

import chisel3._
import chisel3.util._
import axi4._
import diplomatic._
import org.chipsalliance.cde.config.Parameters
import config.Configs
class ICacheReq  extends Bundle {
  val addr = UInt(32.W)
}
class ICacheResp extends Bundle {
  val valid = Bool()
  val data  = UInt(32.W)
}
class CacheCell(
  tagBits:     Int,
  wordOffBits: Int)
    extends Bundle {
  require(wordOffBits >= 0)
  require(tagBits >= 0)
  val valid = Bool()
  val tag   = UInt(tagBits.W)
  val block = Vec(1 << wordOffBits, UInt(32.W))
}
class InstructionCache(
  wordBits:           Int = 2,
  addrWidth:          Int = 32,
  uncacheableRegions: Seq[AddressSet] = AddressSet.misaligned(0x0f000000, 0x1000000)
)(
  implicit p:         Parameters)
    extends Module {
  val wordOffBits                                                                                     = p(Configs.ICacheWordOffBits)
  val BlockBits                                                                                       = p(Configs.ICacheBlockBits)
  val io                                                                                              = IO(new Bundle {
    val req   = Flipped(Decoupled(new ICacheReq))
    val resp  = Output(new ICacheResp)
    val axi   = new AXI4Bundle(new AXI4Parameters)
    val flush = Input(Bool())
  })
  val wordCount                                                                                       = 1 << wordOffBits
  val numBlocks                                                                                       = 1 << BlockBits
  val tagBits                                                                                         = addrWidth - BlockBits - wordOffBits - wordBits
  val sIdle :: sMissSendAR :: sMissWaitR :: sMissSendARObsolete :: sMissWaitRObsolete :: sResp :: Nil = Enum(6)
  val state                                                                                           = RegInit(sIdle)
  val reqAddrLatch                                                                                    = Reg(UInt(addrWidth.W))
  val addressCurrentForcus                                                                            = Mux(state === sIdle, io.req.bits.addr, reqAddrLatch)
  val cacheTable                                                                                      = Reg(Vec(numBlocks, new CacheCell(tagBits = tagBits, wordOffBits = wordOffBits)))

  val wordIndex   = if (wordOffBits == 0) 0.U else addressCurrentForcus(wordBits + wordOffBits - 1, wordBits)
  val blockIndex  = if (BlockBits == 0) 0.U else addressCurrentForcus(wordBits + wordOffBits + BlockBits - 1, wordBits + wordOffBits)
  val blockTag    = addressCurrentForcus(addrWidth - 1, wordBits + wordOffBits + BlockBits)
  val blockAddr   = addressCurrentForcus(addrWidth - 1, wordOffBits + 2) ## 0.U((wordOffBits + 2).W)
  val uncacheAble = uncacheableRegions.foldLeft(false.B)(_ || _.contains(addressCurrentForcus))

  val cacheHitBlock = if (BlockBits == 0) cacheTable(0) else cacheTable(blockIndex)
  val cacheHitWord  = if (wordOffBits == 0) cacheHitBlock.block(0) else cacheHitBlock.block(wordIndex)
  val hit           = cacheHitBlock.valid && cacheHitBlock.tag === blockTag
  val beatCounter   = if (wordOffBits > 0) RegInit(0.U(wordOffBits.W)) else null

  state := MuxLookup(state, sIdle)(
    Seq(
      sIdle               -> Mux(io.req.fire & !io.flush, Mux(hit && !uncacheAble, sResp, sMissSendAR), sIdle),
      sMissSendAR         -> Mux(io.flush, Mux(io.axi.ar.fire, sMissWaitRObsolete, sMissSendARObsolete), Mux(io.axi.ar.fire, sMissWaitR, sMissSendAR)),
      sMissWaitR          -> Mux(
        io.flush,
        Mux(io.axi.r.fire && io.axi.r.bits.last, sIdle, sMissWaitRObsolete),
        Mux(io.axi.r.fire && io.axi.r.bits.last, Mux(uncacheAble, sIdle, sResp), sMissWaitR)
      ),
      sMissSendARObsolete -> Mux(io.axi.ar.fire, sMissWaitRObsolete, sMissSendARObsolete),
      sMissWaitRObsolete  -> Mux(io.axi.r.fire && io.axi.r.bits.last, sIdle, sMissWaitRObsolete),
      sResp               -> sIdle
    )
  )

  when(io.req.fire) {
    reqAddrLatch := io.req.bits.addr
  }
  when(io.flush || reset.asBool) {
    for (i <- 0 until cacheTable.length) {
      cacheTable(i).valid := false.B
    }
  }
  io.req.ready  := state === sIdle
  io.resp.valid := state === sResp || state === sMissWaitR && uncacheAble && io.axi.r.fire
  io.resp.data  := Mux(uncacheAble, io.axi.r.bits.data, cacheHitWord)

  io.axi.aw.valid := false.B
  io.axi.aw.bits  := 0.U.asTypeOf(io.axi.aw.bits)
  io.axi.w.valid  := false.B
  io.axi.w.bits   := 0.U.asTypeOf(io.axi.w.bits)
  io.axi.b.ready  := false.B

  io.axi.ar.valid      := state === sMissSendAR || state === sMissSendARObsolete
  io.axi.ar.bits.addr  := Mux(uncacheAble, addressCurrentForcus, blockAddr)
  io.axi.ar.bits.size  := "b010".U
  io.axi.ar.bits.burst := AXI4BurstEnum.INCR
  io.axi.ar.bits.id    := 0.U
  io.axi.ar.bits.len   := Mux(uncacheAble, 0.U, (wordCount - 1).U)
  io.axi.r.ready       := state === sMissWaitR || state === sMissWaitRObsolete
  switch(state) {
    is(sMissSendAR) {
      when(io.axi.ar.fire) {
        if (wordOffBits > 0) {
          beatCounter := 0.U
        }
      }
    }
    is(sMissWaitR) {
      when(io.axi.r.fire && !io.flush && !uncacheAble) {
        if (wordOffBits == 0) {
          cacheHitBlock.block(0) := io.axi.r.bits.data
        } else {
          cacheHitBlock.block(beatCounter) := io.axi.r.bits.data
          beatCounter                      := beatCounter + 1.U
        }
        when(io.axi.r.bits.last) {
          cacheHitBlock.tag   := blockTag
          cacheHitBlock.valid := true.B
        }
      }
    }
  }
}
