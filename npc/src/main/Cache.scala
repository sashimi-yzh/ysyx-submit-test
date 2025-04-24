package npc
import chisel3._
import chisel3.util._
import utils._

class Cache(readOnly: Boolean = false) extends NPCModule {
  val io = IO(new Bundle{
    val core = Flipped(new CacheBundle)
    val mem = new AXI4
    val fence_i = Input(Bool())
    val flush = Input(Bool())
  })

  val hasVictimCache = false
  val offBits = log2Up(XLEN / 8)
  val wordIdxBits = 2
  val idxBits = 2
  val tagBits = PALEN - offBits - wordIdxBits - idxBits
  val wordsInLine = 1 << wordIdxBits
  val lines = 1 << idxBits
  val addrBundle = new Bundle {
    val tag = UInt(tagBits.W)
    val idx = UInt(idxBits.W)
    val wordIdx = UInt(wordIdxBits.W)
    val off = UInt(offBits.W)
  }
  def addrToTag(addr: UInt) = addr.asTypeOf(addrBundle).tag
  def addrToIdx(addr: UInt) = addr.asTypeOf(addrBundle).idx
  def addrToWordIdx(addr: UInt) = addr.asTypeOf(addrBundle).wordIdx

  val valid = RegInit(0.U(lines.W))
  val tag = Mem(lines, UInt(tagBits.W))
  val dirty = Mem(lines, Bool())
  val data = List.fill(wordsInLine)(Mem(lines, UInt(XLEN.W)))

  require(!hasVictimCache || readOnly, "victim cache with dcache is not supported")
  val tagVictimBits = PALEN - offBits - wordIdxBits
  def victim_addrToTag(addr: UInt) = addr(PALEN - 1, offBits + wordIdxBits)
  val victim_valid = RegInit(false.B)
  val victim_tag = Reg(UInt(tagVictimBits.W))
  val victim_dirty = Reg(Bool())
  val victim_data = Reg(Vec(wordsInLine, UInt(XLEN.W)))

  val CacheStateBundle = new Bundle {
    val req = new MemSinglePortReqBundle
    val tagRead = UInt(tagBits.W)
    val hit = Bool()
    val dirty = Bool()
    val victim_tagRead = UInt(tagVictimBits.W)
    val victim_hit = Bool()
    val victim_dirty = Bool()
    val mmio = Bool()
  }

  val s0_out = Wire(Decoupled(CacheStateBundle))
  val s1_in  = Wire(Decoupled(CacheStateBundle))

  val idx_s0 = addrToIdx(io.core.req.bits.addr)
  s0_out.bits.req := io.core.req.bits
  if (readOnly) s0_out.bits.req.addr := toPC(io.core.req.bits.addr)
  s0_out.bits.tagRead := tag(idx_s0)
  s0_out.bits.hit := valid(idx_s0) && (addrToTag(s0_out.bits.req.addr) === s0_out.bits.tagRead)
  s0_out.bits.dirty := (if (readOnly) false.B else (valid(idx_s0) && dirty(idx_s0)))
  s0_out.bits.victim_tagRead := (if (hasVictimCache) victim_tag else 0.U)
  s0_out.bits.victim_hit := victim_valid && (victim_addrToTag(s0_out.bits.req.addr) === s0_out.bits.victim_tagRead)
  s0_out.bits.victim_dirty := (if (readOnly || !hasVictimCache) false.B else (victim_valid && victim_dirty))
  s0_out.bits.mmio := !MemMap.isCachable(io.core.req.bits.addr)

  StageConnect.pipeline(s0_out, s1_in, io.core.resp, io.flush)

  val s1 = s1_in.bits
  val req_s1 = s1.req
  val wordIdx_s1 = addrToWordIdx(req_s1.addr)
  val idx_s1 = addrToIdx(req_s1.addr)
  val tag_s1 = addrToTag(req_s1.addr)
  val wen_s1 = if (readOnly) false.B else req_s1.wen
  val dataRead_s1 = VecInit(data.map(_(idx_s1)))

  val beatCnt = Counter(wordsInLine)
  val last = beatCnt.value === (wordsInLine - 1).U
  val rlast = io.mem.r.bits.last
  val wlast = RegInit(false.B)
  val wlastCond = io.mem.w.fire && (last || s1.mmio)

  object State extends ChiselEnum {
    val idle, waitRespReady, waitARready, waitRvalid = Value
    val waitAWready, waitWready, waitBvalid = Value
  }
  val state = RegInit(State.idle)

  val flushReg = RegInit(false.B)
  when (state === State.waitRespReady) { flushReg := false.B }
  val needFlushReg = !state.isOneOf(State.idle, State.waitRespReady)
  when (io.flush && needFlushReg) { flushReg := true.B }

  val reqValid = s1_in.valid && !io.flush
  val s1_hit = s1.hit || (hasVictimCache.B && s1.victim_hit)
  val stateReadTransist = Array(
    State.idle          -> Mux(reqValid,
                             Mux(s1.mmio,
                               Mux(wen_s1, State.waitAWready,
                                 Mux(io.mem.ar.ready, State.waitRvalid, State.waitARready)
                                  ),
                               Mux(s1_hit, State.idle,
                                 Mux(s1.dirty, State.waitAWready,
                                   Mux(io.mem.ar.ready, State.waitRvalid, State.waitARready)
                                    )
                                  )
                                ),
                             State.idle),
    State.waitRespReady -> Mux(io.core.resp.ready || flushReg, State.idle, State.waitRespReady),
    State.waitARready   -> Mux(io.mem.ar.ready,     State.waitRvalid,    State.waitARready),
    State.waitRvalid    -> Mux(io.mem. r.valid && (rlast || s1.mmio), State.waitRespReady, State.waitRvalid),
  )
  val stateWriteTransist = Array(
    State.waitAWready -> Mux(io.mem.aw.ready, Mux(wlastCond, State.waitBvalid, State.waitWready), State.waitAWready),
    State.waitWready  -> Mux(wlastCond || wlast, State.waitBvalid, State.waitWready),
    State.waitBvalid  -> Mux(io.mem.b.valid, Mux(s1.mmio, State.waitRespReady, State.waitARready), State.waitBvalid),
  )
  val stateTransist = stateReadTransist ++ (if (!readOnly) stateWriteTransist else Array())
  state := Lookup1H(state, stateTransist)

  val beatAddr = tag_s1 ## idx_s1 ## 0.U((wordIdxBits + offBits).W)
  io.mem.ar.valid := ((state === State.idle) && reqValid && ((s1.mmio && !wen_s1) || (!s1.mmio && !s1_hit && !s1.dirty))) ||
                      (state === State.waitARready)
  io.mem.ar.bits.addr := Mux(s1.mmio, req_s1.addr, beatAddr)
  io.mem.ar.bits.size := Mux(s1.mmio, req_s1.size, "b010".U)
  io.mem.ar.bits.len  := Mux(s1.mmio, 0.U, (wordsInLine - 1).U)
  io.mem.ar.bits.burst:= AXI4Parameters.BURST_INCR
  io.mem.ar.bits.id   := 0.U

  io.mem. r.ready := (state === State.waitRvalid)

  when (!s1.mmio && (io.mem.r.fire || io.mem.w.fire)) { beatCnt.inc() }
  when (wlastCond) { wlast := true.B }
  when (state === State.waitBvalid) { wlast := false.B }

  if (readOnly) {
    io.mem.aw.bits := DontCare
    io.mem. w.bits := DontCare
    io.mem.aw.valid := false.B
    io.mem. w.valid := false.B
    io.mem. b.ready := false.B
  } else {
    io.mem.aw.valid := (state === State.waitAWready)
    io.mem.aw.bits := io.mem.ar.bits
    io.mem.aw.bits.addr := Mux(s1.mmio, req_s1.addr, s1_in.bits.tagRead ## idx_s1 ## 0.U((wordIdxBits + offBits).W))
    io.mem. w.valid := state.isOneOf(State.waitAWready, State.waitWready) && !wlast
    io.mem. w.bits.data := Mux(s1.mmio, req_s1.wdata, dataRead_s1(beatCnt.value))
    io.mem. w.bits.strb := Mux(s1.mmio, req_s1.wmask, Fill(XLEN / 8, true.B))
    io.mem. w.bits.last := Mux(s1.mmio, true.B, last)
    io.mem. b.ready := (state === State.waitBvalid)
  }

  val dataReadIdx = Mux(s1.hit, wordIdx_s1, beatCnt.value)
  val dataRead = dataRead_s1(dataReadIdx)
  val victim_dataRead = victim_data(wordIdx_s1)

  val resFromMem = RegEnable(io.mem.r.bits.data, io.mem.r.fire && (s1.mmio || (beatCnt.value === wordIdx_s1)))
  val res = Lookup1H(resFromMem, Seq(s1.hit -> dataRead) ++
    (if (hasVictimCache) Seq(s1.victim_hit -> victim_dataRead) else Seq())
  )

  val dataWen = (state === State.waitRespReady) && req_s1.wen
  val wmaskExpand = Cat(req_s1.wmask.asBools.map(Fill(8, _)).reverse)
  val dataMerged = (res & ~wmaskExpand) | (req_s1.wdata & wmaskExpand)
  val dataWrite = Mux(dataWen, dataMerged, io.mem.r.bits.data)
  when ((dataWen || io.mem.r.fire) && !s1.mmio) {
    data.zipWithIndex.map{ case (d, i) =>
      when ((io.mem.r.fire && (i.U === beatCnt.value)) || (dataWen && i.U === wordIdx_s1)) {
        d(idx_s1) := dataWrite
      }
    }
    if (!readOnly) {
      when (dataWen || (io.mem.r.fire && rlast)) {
        dirty(idx_s1) := Mux(dataWen, true.B, false.B)
      }
    } else if (hasVictimCache) {
      when (io.mem.r.fire) { victim_data(beatCnt.value) := dataRead }
    }
  }

  when (io.mem.r.fire && rlast && !s1.mmio) {
    tag(idx_s1) := tag_s1
    valid := valid | (1.U << idx_s1)
    if (hasVictimCache) {
      victim_tag := s1_in.bits.tagRead ## idx_s1
      victim_valid := valid(idx_s1)
    }
  }

  when (io.fence_i) { valid := 0.U }

  io.core.resp.bits.addr := req_s1.addr
  io.core.resp.bits.data := res

  val s1_ok = s1_hit || (state === State.waitRespReady)
  io.core.resp.valid := s1_in.valid && s1_ok && !flushReg
  s1_in.ready := (!s1_in.valid && (state === State.idle)) || (io.core.resp.ready && s1_in.valid && s1_ok)
  s0_out.valid := io.core.req.valid
  io.core.req.ready := s0_out.ready && ((state === State.idle) || io.core.resp.valid)

  if (Global.mode != "syn") {
    val reqCnt = RegInit(0.U(64.W))
    val missCnt = RegInit(0.U(64.W))
    when (s1_in.fire && !s1.mmio) {
      reqCnt := reqCnt + 1.U
      when (!s1_hit) {
        missCnt := missCnt + 1.U
        //when (missCnt(15, 0) === 0.U) { printf("hit/req = %d/%d\n", reqCnt - missCnt, reqCnt) }
      }
      //printf("hit/req = %d/%d\n", reqCnt - missCnt, reqCnt)
    }
  }
}
