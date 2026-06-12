package sirius

import chisel3._
import chisel3.util._
import scala.collection.immutable.NumericRange

class Xorshift32 extends Module {
  val io = IO(new Bundle {
    val en = Input(Bool())
    val out = Output(UInt(32.W))
  })
  val reg = RegInit(1.U(32.W))
  io.out := reg
  val tmp1 = reg ^ (reg << 13)
  val tmp2 = tmp1 ^ (tmp1 >> 17)
  val next = tmp2 ^ (tmp2 << 5)
  when(io.en) {
    reg := next
  }
}

class IcacheIO(
  implicit private val cfg: CoreConfig)
    extends Bundle {
  val abort = Bool()
  val fencei = Bool()
  val ar = Decoupled(new Bundle {
    val addr = UInt(cfg.xlen.W)
  })
  val r = Flipped(Decoupled(new Bundle {
    val data = UInt(cfg.xlen.W)
  }))
}

class Icache(
  setNum:    BigInt,
  wayNum:    BigInt,
  wayByte:   BigInt,
  busByte:   BigInt,
  whiteList: Option[NumericRange[BigInt]] = None
)(
  implicit private val cfg: CoreConfig)
    extends Module {
  require(setNum > 0 && setNum.bitCount == 1)
  require(wayNum > 0 && wayNum.bitCount == 1)
  require(wayByte >= busByte && wayByte.bitCount == 1)
  require(busByte > 0 && busByte.bitCount == 1)

  val wayIdxWidth = log2Ceil(wayNum).toInt
  val burstTimes = (wayByte / busByte).toInt
  val offWidth = 2
  val wordIdxWidth = (log2Ceil(wayByte) - offWidth).toInt
  val setIdxWidth = log2Ceil(setNum).toInt
  val tagWidth = (busByte * 8 - offWidth - wordIdxWidth - setIdxWidth).toInt

  val io = IO(new Bundle {
    val cached = Flipped(new IcacheIO)
    val mem = new Axi4IO
  })

  // FSM state
  val sReadCache :: sReq :: sFirstResp :: sFillCache :: sWait :: Nil = Enum(5)
  val state = RegInit(sReadCache)

  // Addr
  class AddrLine extends Bundle {
    val tag = UInt(tagWidth.W)
    val setIdx = UInt(setIdxWidth.W)
    val wordIdx = UInt(wordIdxWidth.W)
    val off = UInt(offWidth.W)
  }
  val rAddrReg = RegEnable(io.cached.ar.bits.addr, state === sReadCache)
  val rAddr = Mux(state === sReadCache, io.cached.ar.bits.addr, rAddrReg)
  val rAddrLine = rAddr.asTypeOf(new AddrLine)
  val inWhiteList = if (whiteList.isDefined) {
    rAddr >= whiteList.get.start.U && rAddr < whiteList.get.end.U
  } else { true.B }

  // Random
  val xorshift32 = Module(new Xorshift32)
  val rand = xorshift32.io.out
  // val lfsr = Module(new MaxPeriodGaloisLFSR(64))
  // lfsr.io.seed := DontCare
  // val rand = lfsr.io.out.asUInt

  // Cache
  val cacheValid = RegInit(0.U.asTypeOf(Vec(setNum.toInt, Vec(wayNum.toInt, Bool()))))
  val cacheTag = Reg(Vec(setNum.toInt, Vec(wayNum.toInt, UInt(tagWidth.W))))
  val cacheData = Reg(
    Vec(setNum.toInt, Vec(wayNum.toInt, Vec(burstTimes.toInt, UInt((busByte * 8).toInt.W))))
  )

  val setIdx = if (setIdxWidth != 0) rAddrLine.setIdx else 0.U
  val setValid = cacheValid(setIdx)
  val setTag = cacheTag(setIdx)
  val setData = cacheData(setIdx)

  when(io.cached.fencei) {
    cacheValid := 0.U.asTypeOf(chiselTypeOf(cacheValid))
  }

  // Check hit
  val setHit = VecInit(setValid.zip(setTag).map { case (valid, tag) =>
    valid && (tag === rAddrLine.tag)
  })
  val isHit = setHit.asUInt.orR
  val hitData = Mux1H(setHit, setData)

  // Replace sel
  val invalidWayIdx = PriorityEncoderOH(~setValid.asUInt)
  val isAllValid = setValid.asUInt.andR
  val allValidWayIdx = if (wayIdxWidth != 0) UIntToOH(rand.head(wayIdxWidth)) else 1.U
  val wayMask = Mux(isAllValid, allValidWayIdx, invalidWayIdx)

  // FSM
  val nextState = WireDefault(state)
  state := nextState

  val abortReg = RegInit(false.B)
  when(io.cached.abort) {
    abortReg := true.B
  }

  val fenceiReg = RegInit(false.B)
  when(io.cached.fencei) {
    fenceiReg := true.B
  }

  val rFiredReg = RegInit(false.B)
  when(io.cached.r.fire || io.cached.abort) {
    rFiredReg := true.B
  }
  val rFired = io.cached.r.fire || io.cached.abort || rFiredReg

  switch(state) {
    is(sReadCache) {
      when(io.cached.ar.valid) {
        when(!(isHit && inWhiteList)) {
          nextState := sReq
        }.elsewhen(!rFired) {
          nextState := sWait
        }.otherwise {
          abortReg := false.B
          fenceiReg := false.B
          rFiredReg := false.B
        }
      }.otherwise {
        abortReg := false.B
        fenceiReg := false.B
        rFiredReg := false.B
      }
    }
    is(sReq) {
      when(io.mem.ar.fire) {
        nextState := sFirstResp
      }
    }
    is(sFirstResp) {
      when(io.mem.r.fire) {
        nextState := Mux(io.mem.r.bits.last, sWait, sFillCache)
      }
    }
    is(sFillCache) {
      when(io.mem.r.fire && io.mem.r.bits.last) {
        when(rFired) {
          nextState := sReadCache
          abortReg := false.B
          fenceiReg := false.B
          rFiredReg := false.B
        }.otherwise {
          nextState := sWait
        }
      }
    }
    is(sWait) {
      when(rFired) {
        nextState := sReadCache
        abortReg := false.B
        fenceiReg := false.B
        rFiredReg := false.B
      }
    }
  }

  // Update cache
  xorshift32.io.en := state =/= sFirstResp && state =/= sFillCache
  // lfsr.io.increment := state =/= sFirstResp && state =/= sFillCache

  val wordMask = if (wayByte == busByte) 1.U else UIntToOH(rAddrLine.wordIdx)
  val wordWriteMask = if (wayByte == busByte) {
    1.U
  } else {
    val wordWriteMaskReg = Reg(UInt(burstTimes.W))
    when(io.mem.ar.fire) {
      wordWriteMaskReg := wordMask
    }.elsewhen(io.mem.r.fire) {
      wordWriteMaskReg := wordWriteMaskReg.rotateLeft(1)
    }
    wordWriteMaskReg
  }

  for (s <- 0 until setNum.toInt) {
    for (w <- 0 until wayNum.toInt) {
      val writeCond = io.mem.r.fire && inWhiteList && (setIdx === s.U) && wayMask(w)
      when(writeCond && io.mem.r.bits.last) {
        cacheValid(s)(w) := !fenceiReg
        cacheTag(s)(w) := rAddrLine.tag
      }
      for (word <- 0 until burstTimes) {
        when(writeCond && wordWriteMask(word)) {
          cacheData(s)(w)(word) := io.mem.r.bits.data
        }
      }
    }
  }

  // Mem bus
  io.mem :<= 0.U.asTypeOf(chiselTypeOf(io.mem))
  io.mem.ar.bits.addr := rAddr & ~((busByte - 1).U(rAddr.getWidth.W))
  io.mem.ar.bits.len := Mux(inWhiteList, (burstTimes - 1).U, 0.U)
  io.mem.ar.bits.size := "b010".U
  io.mem.ar.bits.burst := Axi4Burst.warp.U
  io.mem.ar.valid := state === sReq
  io.mem.r.ready := true.B
  when(io.mem.r.valid) {
    assert(io.mem.r.bits.resp(1) === 0.U)
  }

  // Cached bus
  val cachedRValidReg = RegInit(false.B)
  val cachedRDataReg = Reg(UInt((busByte * 8).toInt.W))
  when(state === sFirstResp && io.mem.r.fire) {
    cachedRValidReg := true.B
    cachedRDataReg := io.mem.r.bits.data
  }.elsewhen(io.cached.r.ready) {
    cachedRValidReg := false.B
  }
  when(abortReg || io.cached.abort) {
    cachedRValidReg := false.B
  }

  0.U.asTypeOf(chiselTypeOf(io.cached)) :>= io.cached
  io.cached.ar.ready := state === sReadCache
  io.cached.r.valid := !abortReg && ((io.cached.ar.valid && state === sReadCache && isHit) || cachedRValidReg || state === sWait)
  io.cached.r.bits.data := Mux(
    cachedRValidReg,
    cachedRDataReg,
    Mux1H(wordMask, hitData)
  )
}

class SimpleIcacheIO(
  implicit private val cfg: CoreConfig)
    extends Bundle {
  val fencei = Bool()

  val abort = Bool()
  val newAddr = UInt(cfg.xlen.W)

  val r = Flipped(Decoupled(new Bundle {
    val data = UInt(cfg.xlen.W)
  }))
}

class SimpleIcache(
  setNum: BigInt,
  // wayNum:    BigInt = 1,
  // wayByte:   BigInt = 8,
  // busByte:   BigInt = 4,
  whiteList: Option[NumericRange[BigInt]] = None
)(
  implicit private val cfg: CoreConfig)
    extends Module {
  require(setNum > 0 && setNum.bitCount == 1)

  val io = IO(new Bundle {
    val cached = Flipped(new SimpleIcacheIO)
    val mem = new Axi4IO
  })

  val offWidth = 2
  val wordIdxWidth = 1
  val setIdxWidth = log2Ceil(setNum).toInt
  val tagWidth = 32 - offWidth - wordIdxWidth - setIdxWidth

  class AddrLine extends Bundle {
    val tag = UInt(tagWidth.W)
    val setIdx = UInt(setIdxWidth.W)
    val wordIdx = UInt(wordIdxWidth.W)
    val off = UInt(offWidth.W)
  }

  val abortReg = RegInit(false.B)
  val addrReg = RegInit((cfg.pcInit >> offWidth).U((cfg.xlen - offWidth).W))
  val staticNextAddrReg = addrReg + 1.U
  val nextAddrReg =
    Mux(io.cached.abort || abortReg, io.cached.newAddr(cfg.xlen - 1, offWidth), staticNextAddrReg)
  val addr = addrReg ## 0.U(offWidth.W)
  val addrLine = addr.asTypeOf(new AddrLine)
  val setIdx = addrLine.setIdx
  val inWhiteList = if (whiteList.isDefined) {
    addr >= whiteList.get.start.U && addr < whiteList.get.end.U
  } else { true.B }

  val cacheValid = RegInit(0.U.asTypeOf(Vec(setNum.toInt, Bool())))
  val cacheTag = Reg(Vec(setNum.toInt, UInt(tagWidth.W)))
  val cacheData = Reg(Vec(setNum.toInt, Vec(2, UInt(32.W))))

  val setValid = cacheValid(setIdx)
  val setTag = cacheTag(setIdx)
  val setData = cacheData(setIdx)

  val hit = setValid && (setTag === addrLine.tag)
  val hitData = setData(addrLine.wordIdx)

  val sReadCache :: sReqMem :: sFirstResp :: sFillCache :: Nil = Enum(4)
  val state = RegInit(sReadCache)

  when(io.mem.r.fire && io.mem.r.bits.last) {
    abortReg := false.B
  }.elsewhen(state =/= sReadCache && io.cached.abort) {
    abortReg := true.B
  }

  // when(io.mem.r.fire && io.mem.r.bits.last) {
  //   disableOverrideReg := false.B
  // }.elsewhen((state === sReqMem || (state === sFirstResp && !io.mem.r.fire)) && io.cached.abort) {
  //   disableOverrideReg := true.B
  // }

  switch(state) {
    is(sReadCache) {
      val cacheHit = hit && inWhiteList
      when(io.cached.r.ready && !(cacheHit || io.cached.abort)) {
        state := sReqMem
      }
      when(io.cached.abort || (cacheHit && io.cached.r.ready)) {
        addrReg := nextAddrReg
      }
    }
    is(sReqMem) {
      when(io.mem.ar.fire) { state := sFirstResp }
    }
    is(sFirstResp) {
      when(io.mem.r.fire) {
        when(io.mem.r.bits.last) {
          state := sReadCache
          addrReg := nextAddrReg
        }.otherwise {
          state := sFillCache
        }
      }
    }
    is(sFillCache) {
      when(io.mem.r.fire) {
        state := sReadCache
        addrReg := nextAddrReg
      }
    }
  }

  when(io.mem.r.fire && inWhiteList) {
    setData((state === sFillCache).asUInt ^ addrReg(0).asUInt) := io.mem.r.bits.data
    when(state === sFillCache) {
      setTag := addrLine.tag
      setValid := true.B
    }
  }

  // when(io.cached.abort) {
  //   addrReg := io.cached.newAddr(cfg.xlen - 1, offWidth)
  //   when(state =/= sReadCache) {
  //     setValid := false.B
  //   }
  // }

  when(io.cached.fencei) {
    cacheValid := 0.U.asTypeOf(chiselTypeOf(cacheValid))
  }

  io.cached.r.valid :=
    ((state === sReadCache) && hit) || ((state === sFirstResp) && io.mem.r.fire && !abortReg)
  io.cached.r.bits.data := Mux(state === sReadCache, hitData, io.mem.r.bits.data)
  when(state =/= sReadCache && io.cached.r.valid) {
    assert(io.cached.r.ready)
  }

  io.mem :<= 0.U.asTypeOf(chiselTypeOf(io.mem))
  io.mem.ar.bits.addr := addr
  io.mem.ar.bits.len := Mux(inWhiteList, 1.U, 0.U) // Mux(cond, 2 beats, 1 beat)
  io.mem.ar.bits.size := "b010".U // 4B
  io.mem.ar.bits.burst := Axi4Burst.warp.U
  io.mem.ar.valid := state === sReqMem
  io.mem.r.ready := true.B
  when(io.mem.r.valid) {
    assert(io.mem.r.bits.resp === Axi4Resp.okay.U)
  }
}
