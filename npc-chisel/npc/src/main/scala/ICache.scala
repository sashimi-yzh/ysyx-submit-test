
package npc

import chisel3._
import chisel3.util._

import npc.common._
import npc.Constants._

class ICacheDebugPort(implicit val conf: Config) extends Bundle { 
    val hit_cnt = Output(UInt(conf.perfCountBits.W))
    val miss_cnt = Output(UInt(conf.perfCountBits.W))
}

class ICacheIO(implicit val conf: Config) extends Bundle {
  val pc        = Input(UInt(conf.xprlen.W))
  val fencei    = Input(Bool())
  val req_valid = Input(Bool())
  val inst      = Output(UInt(conf.xlen.W))
  val valid     = Output(Bool())
  val exception = Output(UInt(5.W))
  val debug     = Output(new ICacheDebugPort)
  val port      = new MemPortIo(conf.xlen)
  
}

class ICache(implicit val conf: Config) extends Module { 
    val io = IO(new ICacheIO)
    io.port := DontCare
    io.port.req.bits.burst := WireDefault(BURST_FIXED)

    val sIdle :: sRequesting :: sBurstRequesting :: sReceiving :: sComplete :: Nil = Enum(5)

    val state               = RegInit(sIdle)
    val s_bits              = conf.ICacheSizeBits
    val b_bits              = conf.ICacheBlockBits
    val size                = 1 << conf.ICacheSizeBits 
    val subBlocksPerLine    = 1 << b_bits
    val cache_data_width = subBlocksPerLine * conf.xlen
    val tag_bits            = conf.xlen-s_bits-b_bits-2
    // tag bits = xprlen-s_bits-b_bits-2bits(4bytes)
    //          = 32-4-1-2 = 25 (16 = 2^4,4 = 2^2 bytes)
    // valid bits = 1, tag bits = 25, b_bits = 1 
    // 1+ 25 +32 = 58
    
    val ren                 = RegInit(false.B)
    val offset              = RegInit(0.U(b_bits.W)) // 当前加载偏移
    
    // val tag                 = RegInit(0.U(tag_bits.W))
    // val cache_data          = RegInit(0.U(conf.xlen.W))
    // val cache_valid         = RegInit(false.B)
    // val cacheLineBuffer     = Reg(Vec(subBlocksPerLine, UInt(conf.xlen.W))) // 块缓冲区
    // val mem = RegInit(VecInit(Seq.fill(size)(0.U(cache_data_width.W)))).suggestName("icache_mem") 
    // val tags = RegInit(VecInit(Seq.fill(size)(0.U(tag_bits.W)))).suggestName("icache_tags") 
    // val valids = RegInit(VecInit(Seq.fill(size)(false.B))).suggestName("icache_valids") 

    // val group_index = if (b_bits >0) io.pc(b_bits+2-1,2) else 0.U
    // val cache_block = Mux( ren || io.req_valid, mem(io.pc(s_bits+b_bits+2-1,b_bits+2)),0.U)
    // val cache_block_vec =  VecInit.tabulate(subBlocksPerLine) { i =>cache_block((i + 1) * conf.xlen - 1, i * conf.xlen) }
    // val fullCacheLine = cacheLineBuffer.asUInt

    val cache_valid         = RegInit(false.B)
    val valids              = RegInit(VecInit(Seq.fill(size)(false.B))).suggestName("icache_valids") 
    val mem                 = SyncReadMem(size, UInt(cache_data_width.W))
    val tags                = SyncReadMem(size, UInt(tag_bits.W))
    val cache_block         = mem.read(io.pc(s_bits+b_bits+2-1,b_bits+2), ren || io.req_valid)
    val tag                 = tags.read(io.pc(s_bits+b_bits+2-1,b_bits+2),ren || io.req_valid)
    val cache_block_vec     = VecInit.tabulate(subBlocksPerLine) { i =>cache_block((i + 1) * conf.xlen - 1, i * conf.xlen) }
    val cacheLineBuffer     = Reg(Vec(subBlocksPerLine, UInt(conf.xlen.W))) // 块缓冲区
    val fullCacheLine       = cacheLineBuffer.asUInt
    val group_index         = if (b_bits >0) io.pc(b_bits+2-1,2) else 0.U
    val cache_data          = cache_block_vec(group_index)



    //////// pipeline icache
    // cache_valid :=  Mux( ren || io.req_valid, valids(io.pc(s_bits+b_bits+2-1,b_bits+2)),false.B)
    // tag         :=  Mux(ren || io.req_valid, tags(io.pc(s_bits+b_bits+2-1,b_bits+2)),0.U)
    // cache_data  := cache_block_vec(group_index)
    val hit             = cache_valid && (io.pc(conf.xprlen-1,s_bits+b_bits+2) === tag)
    val req_valid_reg   = RegNext(io.req_valid,true.B)
    cache_valid        := Mux( ren || io.req_valid, valids(io.pc(s_bits+b_bits+2-1,b_bits+2)),false.B)

    //////// pipeline icache
    

        // 状态迁移
    when(state === sIdle) {
        ren := false.B
        when(!hit && req_valid_reg) {
            state := Mux(conf.ICacheEnableBurst,sBurstRequesting,sRequesting)
            offset := 0.U
    }}
    .elsewhen(state === sRequesting ){
            io.port.req.valid       := state === sRequesting
            io.port.req.bits.addr   := Cat(io.pc(conf.xprlen-1,b_bits+2),offset,0.U(2.W))
            io.port.req.bits.fcn    := M_XRD
            io.port.req.bits.typ    := MT_WU 
            io.port.req.bits.burstlen := 0.U
            when(io.port.req.ready) {state := sReceiving }}
    .elsewhen(state === sBurstRequesting) { 
        io.port.req.valid           := state === sBurstRequesting
        io.port.req.bits.addr       := Cat(io.pc(conf.xprlen-1,b_bits+2),0.U(b_bits.W),0.U(2.W))
        io.port.req.bits.fcn        := M_XRD
        io.port.req.bits.typ        := MT_WU
        io.port.req.bits.burst      := BURST_INCR
        io.port.req.bits.burstlen   := Mux(conf.ICacheEnableBurst,conf.burstLength.U,0.U)
        when(io.port.req.ready) {state := sReceiving }}
    .elsewhen(state === sReceiving) {
        when(io.port.resp.valid) {
            offset := offset + 1.U
            cacheLineBuffer(offset) := io.port.resp.bits.data // 存储子块
            // 检查是否完成
            when(offset === (subBlocksPerLine-1).U) {
                state := sComplete
            }.elsewhen(conf.ICacheEnableBurst) { 
                state := sReceiving 
            }.otherwise {
                state := sRequesting // 继续请求下一子块
            }
        }
    }.elsewhen(state === sComplete) { 
        val index = io.pc(s_bits + b_bits + 2 - 1, b_bits+2)
        mem.write(index    , fullCacheLine)                              // 写入数据
        tags.write(index   , io.pc(conf.xprlen-1, s_bits + b_bits + 2)) // 写入Tag
        valids(index)   := true.B // 标记有效
        state   := sIdle
        ren     := true.B
    }
    
    io.inst         := Mux(hit,cache_data,BUBBLE)
    io.valid        := Mux(hit,true.B,false.B)
    io.exception    := Mux(io.port.resp.bits.resp =/= 0.U,EXC_INSTR_ACCESS_FAULT,
                        Mux(io.pc(1,0) =/= 0.U,EXC_INSTR_ADDR_MISALIGNED,EXC_NORMAL))

    when (io.fencei){
        for (addr <- 0 until size) {
            valids(addr.U):= false.B
        }
    }

    /////// DEBUG PORT
    val hit_cnt = RegInit(0.U(conf.perfCountBits.W))
    val miss_cnt = RegInit(0.U(conf.perfCountBits.W))
    hit_cnt := Mux(hit && req_valid_reg,hit_cnt+1.U,hit_cnt)
    miss_cnt := Mux(!hit && req_valid_reg,miss_cnt+1.U,miss_cnt)
    io.debug.hit_cnt := hit_cnt
    io.debug.miss_cnt := miss_cnt
    ////// END DEBUG

}