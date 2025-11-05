package cpu 

import chisel3._ 
import chisel3.util._
import freechips.rocketchip.amba.axi4._


class ICacheIO(axiparams: AXI4BundleParameters) extends Bundle {
  val fencei = Input(Bool())
  val ifu = Flipped(new AXI4Bundle(axiparams))
  val imem = (new AXI4Bundle(axiparams))
}



class ysyx_23060246_ICache(config: NPCConfig) extends Module{
    val io = IO(new ICacheIO(config.axiparams))
    val cacheparams = config.icacheparams
    val tagBits = cacheparams.tagBits
    val indexBits = cacheparams.indexBits
    val offsetBits = cacheparams.offsetBits
    val nSets = cacheparams.nSets
    val nWays = cacheparams.nWays
    val blockSize = cacheparams.blockSize
    
    assert(blockSize % (config.axiparams.dataBits/8) == 0, "iCache blockSize*8 must be N times of databits"); 
    assert(nWays > 0, "iCache nWays must be greater than 0")
    assert(nSets > 0, "iCache nSets must be greater than 0")
    assert(blockSize > 0, "iCache blockSize must be greater than 0")

    val totalLines = nWays * nSets 
    val cache_data = SyncReadMem(totalLines, Vec(blockSize/4, UInt(32.W)))
    val cache_tag = SyncReadMem(totalLines, UInt(tagBits.W))
    val cache_valid = SyncReadMem(totalLines, UInt(1.W))

    val fencei_reg = RegInit(false.B)
    fencei_reg := io.fencei
    when (reset.asBool || fencei_reg) {
        for (i <- 0 until totalLines) {
            cache_valid.write(i.U, 0.U)
        }
    }
    dontTouch(io.fencei)


    val raddr_ifu = Mux(io.ifu.ar.valid, io.ifu.ar.bits.addr, RegEnable(io.ifu.ar.bits.addr, io.ifu.ar.valid))
    val rtag = raddr_ifu(tagBits + indexBits + offsetBits - 1, indexBits + offsetBits)
    val ridx = raddr_ifu(indexBits + offsetBits - 1, offsetBits)
    val roffset = raddr_ifu(offsetBits - 1, 0)


     val data_way = Wire(Vec(nWays, Vec(blockSize/4, UInt(32.W))))
     val hit_way = Wire(Vec(nWays, Bool()))

    if(!isPow2(nWays)){
        println("NPC WARNING: It is recommended for nWays to be a power of 2, "
                +"but the current setup is acceptable.")
        for (i <- 0 until nWays){ 
            when(cache_tag(ridx*nWays.U+i.U) === rtag){
                data_way(i) := cache_data(ridx*nWays.U+i.U)
                hit_way(i) :=  cache_valid(ridx*nWays.U+i.U)
            }.otherwise{
                data_way(i) := VecInit(Seq.fill(blockSize/4)(0.U(32.W)))
                hit_way(i) :=  0.U
            }
        }
    }else{
        val wayIdx = log2Ceil(nWays)
        for (i <- 0 until nWays) {
            val lineIdx = (ridx << wayIdx) | i.U
            when(cache_tag(lineIdx) === rtag) {
                data_way(i) := cache_data(lineIdx)
                hit_way(i) := cache_valid(lineIdx)
            }.otherwise {
                data_way(i) := VecInit(Seq.fill(blockSize / 4)(0.U(32.W)))
                hit_way(i) := false.B
            }
        }
    }
    

    val hit = Wire(Bool())
    hit := hit_way.reduce(_ || _)
    dontTouch(hit)
    
    val blockdata = Wire(Vec(blockSize/4, UInt(32.W)))
    //blockdata := Mux1H(hit_way, data_way)
    for (i <- 0 until (blockSize / 4)) {
        blockdata(i) := Mux1H(hit_way, data_way.map(_(i)))
    }

    val rdata_cache = Wire(UInt(32.W))
    val wordIndex = Wire(UInt((offsetBits-2).W))  // WARNING
    wordIndex := roffset(roffset.getWidth - 1, 2)
    dontTouch(wordIndex)
    dontTouch(rdata_cache)
    if(blockSize == 4){
        rdata_cache := blockdata(0)
    }else {
        //rdata_cache := blockdata(wordIndex)
        rdata_cache := MuxLookup(wordIndex, 0.U)( // Default value if no case matches
            (0 until (blockSize / 4)).map(i => (i.U, blockdata(i)))
        )
    }
    

    
    val bypass = RegInit(false.B)
    val to_bypass = Wire(Bool())
    if(config.USE_SOC){
        // IF the address is not in the range of the SDRAM address, then it is a bypass
        to_bypass := (io.ifu.ar.bits.addr(31,29) =/= "b101".U)
        //bypass := true.B
        when(to_bypass && io.ifu.r.valid){
            bypass := true.B
        }.elsewhen(io.ifu.r.valid){
            bypass := false.B
        }
    }else{
        to_bypass := true.B //NPC的SRAM还不支持突发传输，所以不支持icache  
        bypass := true.B
    }
    dontTouch(bypass)
    

    val burst_cnt = RegInit(0.U(log2Ceil(blockSize/4).W))
    val imem_first_read = burst_cnt === 0.U
    //bypass := 1.U 
    val s_idle :: s_read :: s_replace :: s_refill :: s_wait :: Nil = Enum(5)

    val state = RegInit(s_idle)
    val state_next = Wire(UInt(state.getWidth.W))
    state_next := MuxLookup(state, s_idle)(Seq(
        s_idle -> Mux(io.ifu.ar.valid, Mux(bypass, s_idle, s_read), s_idle),
        s_read -> Mux(hit && burst_cnt === 0.U, s_idle,Mux(burst_cnt =/= 0.U, s_refill, s_replace)),
        s_replace -> Mux(io.imem.ar.ready,  s_refill, s_replace),
        s_refill -> Mux(io.imem.r.valid, Mux(burst_cnt === (blockSize/4-1).U, s_wait, s_read), s_refill),
        s_wait -> s_read,
    ))
    state := state_next


    val imem_read_valid = state === s_refill && io.imem.r.valid
    when(imem_read_valid){
        burst_cnt := burst_cnt + 1.U
    }.elsewhen(state === s_idle){
        burst_cnt := 0.U
    }

    io.ifu.ar.ready := Mux(bypass , io.imem.ar.ready, state === s_idle)
    io.ifu.r.valid := Mux(bypass, io.imem.r.valid, (state === s_read && hit && imem_first_read))
    io.ifu.r.bits.data := Mux(bypass, io.imem.r.bits.data, rdata_cache)
    dontTouch(io.ifu.r.valid)


    val alignMask = ~(((1 << log2Ceil(blockSize)) - 1).U(config.axiparams.addrBits.W))
    dontTouch(alignMask)
    io.imem.ar.bits.addr := Mux(bypass, io.ifu.ar.bits.addr, raddr_ifu & alignMask)
    io.imem.ar.valid := Mux(bypass, io.ifu.ar.valid, (state === s_replace && imem_first_read))
    io.imem.r.ready := Mux(bypass, io.ifu.r.ready ,state === s_refill)


    
    val cache_refill = (imem_read_valid && burst_cnt === (blockSize/4-1).U)


    val wtag = Wire(UInt(rtag.getWidth.W))
    val widx = Wire(UInt(ridx.getWidth.W))
    val woffset = Wire(UInt(roffset.getWidth.W))
    widx := ridx
    woffset := roffset
    wtag := rtag
    // val wtag = RegEnable(rtag, io.ifu.ar.valid)
    // val widx = RegEnable(ridx, io.ifu.ar.valid)
    // val woffset = RegEnable(roffset, io.ifu.ar.valid)

    // FIFO Ptr
    val fifoPtr = RegInit(VecInit(Seq.fill(nSets)(0.U(log2Ceil(nWays).W))))

    val victimWay = fifoPtr(widx)
    val cache_refill_data = RegInit(VecInit(Seq.fill(blockSize/4)(0.U(32.W))))
    val cache_refill_prev = RegInit(false.B)
    
    when(imem_read_valid){
        cache_data(widx*nWays.U + victimWay)(burst_cnt) := io.imem.r.bits.data
    }

    cache_refill_prev := cache_refill
    if(isPow2(nWays)){
        when(!cache_refill_prev & cache_refill){
            cache_tag(victimWay + widx*nWays.U) := wtag
            cache_valid(victimWay + widx*nWays.U) := 1.U

            val nextWay = victimWay + 1.U
            fifoPtr(ridx) := Mux(nextWay === nWays.U, 0.U, nextWay) 
        }
    }else{ // TODO
        when(!cache_refill_prev & cache_refill){
            cache_tag(victimWay + widx*nWays.U) := wtag
            cache_valid(victimWay + widx*nWays.U) := 1.U

            val nextWay = victimWay + 1.U
            fifoPtr(ridx) := Mux(nextWay === nWays.U, 0.U, nextWay) 
        }
    }

    
    io.ifu.r.bits.last := Mux(bypass,  io.imem.r.bits.last , burst_cnt === (blockSize/4 - 1).U)
    io.ifu.r.bits.id := Mux(bypass,  io.imem.r.bits.id , 0.U)
    io.ifu.r.bits.resp := Mux(bypass, io.imem.r.bits.resp, 0.U)


    io.imem.ar.bits.len := Mux(bypass, io.ifu.ar.bits.len, (blockSize/4 - 1).U)

    io.imem.ar.bits.prot := 0.U
    io.imem.ar.bits.id := 0.U
    io.imem.ar.bits.size := 2.U
    io.imem.ar.bits.burst := 1.U // INCR
    io.imem.ar.bits.lock := 0.U
    io.imem.ar.bits.cache := 0.U
    io.imem.ar.bits.qos := 0.U
    

 //Icache Dont need to write 
    io.imem.w.valid := false.B
    io.imem.aw.valid := false.B
    io.imem.aw.bits.addr := 0.U
    io.imem.aw.bits.prot := 0.U
    io.imem.w.bits.data := 0.U
    io.imem.w.bits.strb := 0.U
    io.imem.b.ready := false.B
    io.imem.aw.bits.id := 0.U
    io.imem.aw.bits.len := 0.U
    io.imem.aw.bits.size := 2.U
    io.imem.aw.bits.burst := 0.U
    io.imem.aw.bits.lock := 0.U
    io.imem.aw.bits.cache := 0.U
    io.imem.aw.bits.qos := 0.U
    io.imem.w.bits.last := true.B


    io.ifu.aw.ready := false.B
    io.ifu.w.ready := false.B
    io.ifu.b.valid := false.B
    io.ifu.b.bits.id := 0.U
    io.ifu.b.bits.resp := 0.U


    if(config.PERF_CNT){
        val icache_access_cnt = RegInit(0.U(64.W))
        val icache_hit_cnt = RegInit(0.U(64.W))
        val state_delay = RegInit(0.U(state.getWidth.W))
        val icache_bypass_cnt = RegInit(0.U(64.W))
        val icache_hit_access_time_cnt = RegInit(0.U(64.W))
        val icache_miss_penalty_cnt = RegInit(0.U(64.W))
        dontTouch(icache_access_cnt)
        dontTouch(icache_hit_cnt)
        dontTouch(state_delay)
        dontTouch(icache_bypass_cnt)
        dontTouch(icache_hit_access_time_cnt)
        dontTouch(icache_miss_penalty_cnt)
        state_delay := state 
        when(state === s_idle && state_next =/= s_idle){
            icache_access_cnt := icache_access_cnt + 1.U
        }
        when(state_delay === s_idle && state === s_read && hit){
            icache_hit_cnt := icache_hit_cnt + 1.U
        }
        when(io.ifu.r.valid && io.ifu.r.valid && bypass){
            icache_bypass_cnt := icache_bypass_cnt + 1.U 
        }
        when(state === s_read && hit && burst_cnt === 0.U){
            icache_hit_access_time_cnt := icache_hit_access_time_cnt + 1.U
        }
        when(state === s_refill || state === s_replace || state === s_wait){
            icache_miss_penalty_cnt := icache_miss_penalty_cnt + 1.U
        }.elsewhen(state === s_read){
            when(burst_cnt =/= 0.U){
                icache_miss_penalty_cnt := icache_miss_penalty_cnt + 1.U
            }
        }
    }

}