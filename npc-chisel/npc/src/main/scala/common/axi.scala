package npc.common

import chisel3._
import chisel3.util._

import Constants._
import npc.common._
import npc.devices.{AXI4LiteMem,AXI4LiteMemRandomDelay}

trait AXI4BurstTypes
{
   val BURST_FIXED  = 0.asUInt(2.W)
   val BURST_INCR   = 1.asUInt(2.W)
   val BURST_WRAP   = 2.asUInt(2.W)
   val BURST_X      = 3.asUInt(2.W)
}

class AXI4Req (val dataWidth : Int)(implicit val conf: Config) extends Bundle{
    val maskWidth = dataWidth/8
    val raddr   = Input(UInt(conf.xprlen.W))
    val waddr   = Input(UInt(conf.xprlen.W))
    val data    = Input(UInt(dataWidth.W))
    val mask    = Input(UInt(maskWidth.W))
    val ren     = Input (Bool())
    val wen     = Input (Bool())
    val burst   = Input(UInt(BURST_X.getWidth.W))
    val burstlen = Input(UInt(conf.AXIBurstLenBits.W))
    val typ     = Input(UInt(MT_X.getWidth.W)) // bytes in beat = 2^size
}

class AXI4Resp(val data_width: Int) extends Bundle
{
   val data = Output(UInt(data_width.W))
   val resp = Output(UInt(2.W))
}

class AXIWport(val addrWidth : Int,val dataWidth : Int) extends Bundle{
    val maskWidth = addrWidth/8
    val addr = Input(UInt(addrWidth.W))
    val data = Input(UInt(dataWidth.W))
    val en       =   Input(Bool())
    val ready    =   Output(Bool())
    val mask = Input(UInt(maskWidth.W))
}

class AXIRport(val addrWidth : Int,val dataWidth : Int) extends Bundle{
    val addr     =   Input(UInt(addrWidth.W))
    val data     =   Output(UInt(dataWidth.W))
    val en       =   Input(Bool())
    val ready    =   Output(Bool())
}


class AXI4LiteAR (val addrWidth : Int) (implicit val conf: Config) extends Bundle{
    val valid   =   Output(Bool())
    val addr    =   Output(UInt(conf.xprlen.W))
    val ready   =   Input(Bool()) 
    val id      =   Output(UInt(conf.idBits.W))
    val len     =   Output(UInt(conf.lenBits.W))  // number of beats - 1
    val size    =   Output(UInt(conf.sizeBits.W)) // bytes in beat = 2^size
    val burst   =   Output(UInt(BURST_X.getWidth.W))
} 

class AXI4LiteR (val addrWidth : Int) (implicit val conf: Config)extends Bundle{
    val valid   =   Input(Bool())
    val data    =   Input(UInt(addrWidth.W))
    val resp    =   Input(UInt(2.W))
    val ready   =   Output(Bool()) 
    val id      =   Input(UInt(conf.idBits.W))
    val last    =   Input(Bool())
} 

class AXI4LiteAW (val addrWidth : Int) (implicit val conf: Config) extends Bundle{
    val valid   =   Output(Bool())
    val addr    =   Output(UInt(addrWidth.W))
    val ready   =   Input(Bool()) 
    val id      =   Output(UInt(conf.idBits.W))
    val len     =   Output(UInt(conf.lenBits.W))  // number of beats - 1
    val size    =   Output(UInt(conf.sizeBits.W)) // bytes in beat = 2^size
    val burst   =   Output(UInt(BURST_X.getWidth.W))
} 

class AXI4LiteW (val addrWidth : Int) (implicit val conf: Config) extends Bundle{
    val valid   =   Output(Bool())
    val data    =   Output(UInt(addrWidth.W))
    val strb    =   Output(UInt(conf.maskBits.W))
    val ready   =   Input(Bool()) 
    val last    =   Output(Bool())
} 

class AXI4LiteB (val addrWidth : Int) (implicit val conf: Config) extends Bundle{
    val valid   =   Input(Bool())
    val resp    =   Input(UInt(2.W))
    val ready   =   Output(Bool()) 
    val id      =   Input(UInt(conf.idBits.W))
} 

class AXI4LiteIo (implicit val conf: Config) extends Bundle{ 
    val ar      =   new AXI4LiteAR(conf.xprlen)
    val r       =   new AXI4LiteR(conf.xlen)
    val aw      =   new AXI4LiteAW(conf.xprlen)
    val w       =   new AXI4LiteW(conf.xlen)
    val b       =   new AXI4LiteB(conf.xlen)
}

class AXI4LiteMaster (implicit val conf: Config) extends Module{
    val io = IO( new Bundle {
        val clock   =   Input(Clock())
        val reset   =   Input(Bool())
        val axi_io  =   new AXI4LiteIo()
        val req     =   new AXI4Req(conf.xlen)
        val resp    =   new DecoupledIO(new AXI4Resp(conf.xlen))
        val debug   =   new Bundle{
            val rstate = Output(UInt(2.W))
            val wstate = Output(UInt(2.W))
            val is_write = Output(Bool())
            val is_read = Output(Bool())
        }
    })
    io := DontCare
    io.resp.bits := DontCare

    //////  AXI4Lite read/write master
    val rs_idle :: rs_wait_arready :: rs_wait_rlast :: Nil = Enum(3)
    val rstate = RegInit(rs_idle)
    val ws_idle :: ws_wait_ready ::ws_wait_bvalid:: Nil = Enum(3)
    val wstate = RegInit(ws_idle)

    val accept_read = (rstate === rs_idle) && io.req.ren
    val accept_write = !accept_read && (wstate === ws_idle) && io.req.wen
    val is_read = Mux((rstate === rs_idle), accept_read, RegEnable (accept_read,false.B,(rstate === rs_idle)))
    val is_write = Mux((wstate === ws_idle), accept_write, RegEnable (accept_write,false.B,(wstate === ws_idle)))
    val awfire = RegInit(false.B)
    val wfire = RegInit(false.B)
    val arfire = RegInit(false.B)
    val bfire = RegInit(false.B)
    val rfire = RegInit(false.B)

    awfire  :=  Mux(wstate === ws_wait_bvalid,  false.B, (io.axi_io.aw.valid && io.axi_io.aw.ready) || awfire)
    wfire   :=  Mux(wstate === ws_wait_bvalid,  false.B, (io.axi_io.w.valid && io.axi_io.w.ready) || wfire)
    bfire   :=  Mux(wstate === ws_idle,         false.B,        (io.axi_io.b.valid && io.axi_io.b.ready) || bfire)
    arfire  :=  Mux(rstate === rs_wait_rlast || io.axi_io.r.last,   false.B,  (io.axi_io.ar.valid && io.axi_io.ar.ready) || arfire)
    rfire   :=  Mux(rstate === rs_idle,         false.B,  (io.axi_io.r.valid && io.axi_io.r.ready) || rfire)


    //////  AXI4Lite write/read channel
    // RegNext 2 cycle, maybe need to change
    val maskWidth   = conf.xlen/8
    val size    = MuxCase(0.U,Seq(
        (io.req.typ(1,0) === 3.U)  ->  2.U,
        (io.req.typ(1,0) === 2.U)  ->  1.U
    ))

    val arvalid = Mux(arfire || rstate===rs_wait_rlast,false.B, is_read)
    val araddr  = Mux(accept_read,io.req.raddr,RegEnable(io.req.raddr,  0.U ,  accept_read||io.axi_io.ar.ready))
    val arlen   = Mux(accept_read, io.req.burstlen,RegEnable(io.req.burstlen,accept_read))
    val arburst = Mux(accept_read,io.req.burst,RegEnable(io.req.burst,accept_read))

    val awaddr  =   Mux(accept_write,io.req.waddr,RegEnable(io.req.waddr, accept_write||io.axi_io.aw.ready))
    val awvalid =   Mux(awfire|| wstate === ws_wait_bvalid,false.B, is_write)
    val wvalid  =   Mux(wfire || wstate === ws_wait_bvalid,false.B, is_write)
    val wlast   =   Mux(wfire || wstate === ws_wait_bvalid,false.B, is_write)
    val wdata   =   Mux(accept_write,io.req.data,RegEnable(io.req.data, 0.U,  accept_write||io.axi_io.w.ready))
    val wstrb   =   Mux(accept_write,io.req.mask,RegEnable(io.req.mask, 0.U,  accept_write||io.axi_io.w.ready))
    val awburst =   io.req.burst

    val rready  = (rstate === rs_wait_rlast) || (rstate === rs_wait_arready ) 
    val bready  = (wstate === ws_wait_bvalid) || (wstate === ws_wait_ready ) 
    
    io.axi_io.ar.addr   := Mux(rstate===rs_idle, io.req.raddr,araddr)
    io.axi_io.ar.valid  := arvalid
    io.axi_io.ar.size   := size
    io.axi_io.ar.id     := 0.U
    io.axi_io.r.ready   := rready
    io.axi_io.b.ready   := bready
    if(conf.EnableBurst){
        io.axi_io.ar.len    := arlen
        io.axi_io.ar.burst  := arburst
    } else {
        io.axi_io.ar.len    := 0.U
        io.axi_io.ar.burst  := 0.U
    }

    switch(rstate){
        is(rs_idle)         { rstate := Mux(accept_read, Mux(io.axi_io.ar.valid && io.axi_io.ar.ready,rs_wait_rlast , rs_wait_arready), rs_idle)}
        is (rs_wait_arready){ rstate := Mux(arfire || (io.axi_io.ar.valid && io.axi_io.ar.ready), rs_wait_rlast, rs_wait_arready)}
        is (rs_wait_rlast){ 
            // rlast is high when rvalid is high
            rstate := Mux(io.axi_io.r.last && io.axi_io.r.valid , rs_idle, rs_wait_rlast)
            when (io.axi_io.r.valid){ io.resp.bits.data  := io.axi_io.r.data}
        }
    }

    
    //////  AXI4Lite write master
    io.axi_io.aw.valid      :=  Mux(wstate===ws_idle, accept_write,awvalid)
    io.axi_io.aw.addr       :=  awaddr
    io.axi_io.aw.burst      :=  0.U
    io.axi_io.aw.size       :=  size
    io.axi_io.aw.id         :=  0.U
    io.axi_io.aw.len        :=  0.U

    io.axi_io.w.valid       :=  Mux(wstate===ws_idle, accept_write,wvalid)
    io.axi_io.w.data        :=  wdata
    io.axi_io.w.strb        :=  wstrb
    io.axi_io.w.last        :=  wlast
    // write not support burst 
    // io.axi_io.aw.burst      :=  awburst
    
    switch(wstate){
        is(ws_idle)         { wstate := Mux(accept_write, ws_wait_ready, ws_idle)}
        is (ws_wait_ready)  { wstate := Mux((awfire && wfire) || (io.axi_io.aw.valid && io.axi_io.aw.ready), ws_wait_bvalid, ws_wait_ready)}
        is (ws_wait_bvalid) { wstate := Mux(bfire , ws_idle, ws_wait_bvalid)}
    }

    io.resp.valid := Mux(wstate =/= ws_idle ,(io.axi_io.b.valid),io.axi_io.r.valid)
    io.resp.bits.resp :=  Mux(io.axi_io.r.valid, io.axi_io.r.resp ,
                          Mux(io.axi_io.b.valid , io.axi_io.b.resp, 0.U ))

    ///// Debug signals
    io.debug.rstate     := rstate
    io.debug.wstate     := wstate
    io.debug.is_write   := is_write
    io.debug.is_read    := is_read
}



class TopAXI4LiteSlave (implicit val conf: Config) extends Module{
    val io = IO( new Bundle {
        val clock   =   Input(Clock())
        val reset   =   Input(Bool())
        val axi_io  =   Flipped(new AXI4LiteIo())
        val out     =   Flipped(new Bundle{
            val dr      =   new AXIRport(conf.xprlen, conf.xlen)
            val dw      =   new AXIWport(conf.xprlen, conf.xlen)
        })
        val debug =   new Bundle{
            val state = Output(UInt(2.W))
        }
    })
    io := DontCare

    val s_idle :: s_inflight :: s_wait_rready_bready :: Nil = Enum(3)
    val state = RegInit(s_idle)
    val accept_read = (state === s_idle) && io.axi_io.ar.valid
    val accept_write = !accept_read && (state === s_idle) && io.axi_io.aw.valid && io.axi_io.w.valid
    val is_write = Mux((state === s_idle), accept_write, RegEnable(accept_write,false.B,(state === s_idle)))
    io.debug.state := state

    switch (state) {
        is (s_idle)     { state := Mux(io.axi_io.ar.valid || (io.axi_io.aw.valid && io.axi_io.w.valid), s_inflight, s_idle) }
        is (s_inflight) { state := Mux((!is_write && io.out.dr.ready) || (is_write && io.out.dw.ready) ,  s_wait_rready_bready, s_inflight) }
        // is (s_inflight) { state := Mux(io.out.dr.ready ,  s_wait_rready_bready, s_inflight) }
        is (s_wait_rready_bready) { state := s_idle }
    }
    //////  AXI4Lite 
    io.axi_io.ar.ready      :=   accept_read  || (state === s_inflight && !is_write)
    io.axi_io.w.ready       :=   accept_write || (state === s_inflight && is_write)
    io.axi_io.aw.ready      :=   accept_write || (state === s_inflight && is_write)
    val araddr              =   Mux(accept_read, io.axi_io.ar.addr,         RegEnable(io.axi_io.ar.addr,    io.axi_io.ar.valid))
    val awaddr              =   Mux(accept_write, io.axi_io.aw.addr,        RegEnable(io.axi_io.aw.addr,    io.axi_io.aw.valid))
    val wdata               =   Mux(io.axi_io.w.valid, io.axi_io.w.data,    RegEnable(io.axi_io.w.data,     io.axi_io.w.valid))
    val wstrb               =   Mux(io.axi_io.w.valid, io.axi_io.w.strb,    RegEnable(io.axi_io.w.strb,     io.axi_io.w.valid)) 

    io.out.dr.en      := !is_write && state === s_inflight
    io.out.dr.addr    := araddr
    io.out.dw.en      := is_write&&(state === s_inflight)
    io.out.dw.addr    := awaddr
    // when wvalid high, io.out.dw.data should valid
    io.out.dw.data    := wdata
    io.out.dw.mask    := wstrb


    val resp        =   0.U  // OKAY
    val resp_hold = Mux((state === s_inflight),resp, RegNext(resp))  

    io.axi_io.r.resp    := resp_hold
    io.axi_io.r.valid   := !is_write && (state === s_inflight && io.out.dr.ready) || (state === s_wait_rready_bready)
    io.axi_io.r.data    := Mux((state === s_inflight),io.out.dr.data, RegEnable(io.out.dr.data,(state === s_inflight)))  
    io.axi_io.r.last    := io.axi_io.r.valid 
    io.axi_io.b.valid   := is_write && (((state === s_inflight) && io.out.dw.ready ) || (state === s_wait_rready_bready))
    io.axi_io.b.resp    := resp_hold
}


class AXI4BurstSlave (implicit val conf: Config) extends Module {
    val io = IO( new Bundle {
        val clock   =   Input(Clock())
        val reset   =   Input(Bool())
        val axi_io  =   Flipped(new AXI4LiteIo())
        val out     =   Flipped(new Bundle{
            val dr      =   new AXIRport(conf.xprlen, conf.xlen)
            val dw      =   new AXIWport(conf.xprlen, conf.xlen)
        })
        val debug =   new Bundle{
            val state = Output(UInt(3.W))
            val burst_counter = Output(UInt(8.W))
        }
    })
    io := DontCare

    // 扩展状态机支持 Burst
    val s_idle :: s_read_addr :: s_read_data :: s_write_addr :: s_write_data :: s_write_resp :: Nil = Enum(6)
    val state = RegInit(s_idle)
    
    // Burst 控制寄存器
    val burst_counter = RegInit(0.U(8.W))
    val burst_length = RegInit(0.U(8.W))
    val burst_addr = RegInit(0.U(conf.xprlen.W))
    val burst_size = RegInit(0.U(3.W))
    val burst_type = RegInit(0.U(2.W))
    
    // 调试输出
    io.debug.state := state
    io.debug.burst_counter := burst_counter

    // 状态机控制
    switch(state) {
        is(s_idle) {
            when(io.axi_io.ar.valid) {
                state := s_read_addr
                burst_addr := io.axi_io.ar.addr
                burst_length := io.axi_io.ar.len
                burst_size := io.axi_io.ar.size
                burst_type := io.axi_io.ar.burst
                burst_counter := 0.U
            }.elsewhen(io.axi_io.aw.valid && io.axi_io.w.valid) {
                state := s_write_addr
                burst_addr := io.axi_io.aw.addr
                burst_length := io.axi_io.aw.len
                burst_size := io.axi_io.aw.size
                burst_type := io.axi_io.aw.burst
                burst_counter := 0.U
            }
        }
        
        is(s_read_addr) {
            when(io.axi_io.ar.ready && io.axi_io.ar.valid) {
                state := s_read_data
            }
        }
        
        is(s_read_data) {
            when(io.out.dr.ready) {
                burst_counter := burst_counter + 1.U
                burst_addr := next_burst_addr(burst_addr, burst_size, burst_type)
                
                when(burst_counter === burst_length) {
                    state := s_idle
                }
            }
        }
        
        is(s_write_addr) {
            when(io.axi_io.aw.ready && io.axi_io.aw.valid && io.axi_io.w.ready && io.axi_io.w.valid ) {
                state := s_write_data
            }
        }
        
        is(s_write_data) {
            burst_counter := burst_counter + 1.U
            burst_addr := next_burst_addr(burst_addr, burst_size, burst_type)
            when(burst_counter === burst_length) {
                state := s_write_resp
            }
        }
        
        is(s_write_resp) {
            state := s_idle
        }
    }
    
    // Burst 地址计算函数
    def next_burst_addr(current_addr: UInt, size: UInt, burst_type: UInt): UInt = {
        val size_bytes = 1.U << size
        val next_addr = Wire(UInt(conf.xprlen.W))
        
        when(burst_type === 1.U) { // INCR
            next_addr := current_addr + size_bytes}
        .elsewhen (burst_type === 2.U) { // WRAP
            val wrap_boundary = (burst_length + 1.U) * size_bytes
            val aligned_addr = current_addr & ~(wrap_boundary - 1.U)
            val addr_offset = (current_addr + size_bytes) & (wrap_boundary - 1.U)
            next_addr := aligned_addr | addr_offset}
        .otherwise {
            next_addr := current_addr}
        next_addr
    }
    
    // 地址通道处理
    io.axi_io.ar.ready := state === s_read_addr
    io.axi_io.aw.ready := state === s_write_addr
    
    // 写数据通道处理
    io.axi_io.w.ready := (state === s_write_data) || (state === s_write_addr)
    
    // 内存接口连接
    io.out.dr.en := io.axi_io.ar.ready && io.axi_io.ar.valid
    io.out.dr.addr := burst_addr
    
    io.out.dw.en := io.axi_io.aw.ready && io.axi_io.aw.valid
    io.out.dw.addr := burst_addr
    io.out.dw.data := io.axi_io.w.data
    io.out.dw.mask := io.axi_io.w.strb
    
    // 读响应通道
    io.axi_io.r.valid := state === s_read_data
    io.axi_io.r.data := io.out.dr.data
    io.axi_io.r.resp := 0.U // OKAY
    io.axi_io.r.last := burst_counter === burst_length
    
    // 写响应通道
    io.axi_io.b.valid := state === s_write_resp
    io.axi_io.b.resp := 0.U // OKAY
}