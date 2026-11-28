package npc

import chisel3._
import chisel3.util._
import npc.AXI.AXI4Bundle
import npc.PMU._

class ysyx_26030092_mtrace extends ExtModule{
    val io = FlatIO(new Bundle {
        val is_write = Input(Bool())
        val addr = Input(UInt(32.W))
        val data = Input(UInt(32.W))
        val size = Input(UInt(4.W))
        val valid = Input(Bool())
        val pc = Input(UInt(32.W))
    })
    addResource("/mtrace.v")
}

class LSUBundle extends Bundle{
    val mem_op     = Output(MemOp())
    val mem_size   = Output(MemSize())
    val mem_signed = Output(Bool())
    val wdata      = Output(UInt(32.W))
    val addr       = Output(UInt(32.W))
    val pc         = Output(UInt(32.W))
}

class LSUOutBundle extends Bundle{
    val rdata     = Output(UInt(32.W))
    val is_excp   = Output(Bool())
    val excp_code = Output(UInt(3.W))
}

class ysyx_26030092_LSU extends Module{
    val in  = IO(Flipped(Decoupled(new LSUBundle)))
    val out = IO(Decoupled(new LSUOutBundle))

    val AXI4_port = IO(new AXI4Bundle)

    val excp_load_misalign  = 4.U(3.W)
    val excp_load_fault     = 5.U(3.W)
    val excp_store_misalign = 6.U(3.W)
    val excp_store_fault    = 7.U(3.W)

    val s_idle :: s_ar :: s_data :: s_aw :: s_b :: s_rep :: Nil = Enum(6)
    val state = RegInit(s_idle)
    val aw_done = RegInit(false.B)
    val w_done  = RegInit(false.B)

    val addr     = Reg(UInt(32.W))
    val wdata    = Reg(UInt(32.W))
    val size     = Reg(MemSize())
    val signed   = Reg(Bool())
    val pc       = Reg(UInt(32.W))
    val to_store = Reg(Bool())

    def axi_size(s: MemSize.Type) =
        MuxLookup(s, 2.U)(Seq(MemSize.byte -> 0.U, MemSize.half -> 1.U))

    def misaligned(a: UInt, s: MemSize.Type) =
        MuxLookup(s, false.B)(Seq(
            MemSize.half -> a(0),
            MemSize.word -> a(1,0).orR))

    val req_store    = in.bits.mem_op === MemOp.store
    val req_misalign = misaligned(in.bits.addr, in.bits.mem_size)

    in.ready := state === s_idle

    when(in.fire){
        addr     := in.bits.addr
        wdata    := in.bits.wdata
        size     := in.bits.mem_size
        signed   := in.bits.mem_signed
        pc       := in.bits.pc
        to_store := req_store
    }

    val load_shift = AXI4_port.rdata >> (addr(1,0) << 3)
    val load_data  = MuxLookup(size, load_shift)(Seq(
        MemSize.byte -> Mux(signed,
            Cat(Fill(24, load_shift(7)),  load_shift(7,0)),
            Cat(0.U(24.W),                load_shift(7,0))),
        MemSize.half -> Mux(signed,
            Cat(Fill(16, load_shift(15)), load_shift(15,0)),
            Cat(0.U(16.W),                load_shift(15,0)))))

    val store_shift = wdata << (addr(1,0) << 3)
    val store_strb  = MuxLookup(size, "b1111".U)(Seq(
        MemSize.byte -> ("b1".U(4.W)  << addr(1,0))(3,0),
        MemSize.half -> ("b11".U(4.W) << addr(1,0))(3,0)))

    val mtrace_u = Module(new ysyx_26030092_mtrace)
    mtrace_u.io.is_write := to_store
    mtrace_u.io.addr     := addr
    mtrace_u.io.data     := Mux(to_store, wdata, load_data)
    mtrace_u.io.size     := MuxLookup(size, 4.U)(Seq(MemSize.byte -> 1.U, MemSize.half -> 2.U))
    mtrace_u.io.pc       := pc
    mtrace_u.io.valid    := (state === s_data && AXI4_port.rvalid) || (state === s_b && AXI4_port.bvalid)

    AXI4_port.initMaster()
    AXI4_port.arvalid := state === s_ar
    AXI4_port.araddr  := addr
    AXI4_port.arsize  := axi_size(size)
    AXI4_port.arburst := 1.U
    AXI4_port.rready  := state === s_data
    AXI4_port.awvalid := state === s_aw && !aw_done
    AXI4_port.awaddr  := addr
    AXI4_port.awsize  := axi_size(size)
    AXI4_port.awburst := 1.U
    AXI4_port.wvalid  := state === s_aw && !w_done
    AXI4_port.wdata   := store_shift
    AXI4_port.wstrb   := store_strb
    AXI4_port.wlast   := true.B
    AXI4_port.bready  := state === s_b

    switch(state){
        is(s_idle){
            aw_done := false.B
            w_done  := false.B
            when(in.fire){
                when(req_misalign)   { state := s_rep }
                .elsewhen(req_store) { state := s_aw  }
                .otherwise           { state := s_ar  }
            }
        }
        is(s_ar)   { when(AXI4_port.arready){ state := s_data } }
        is(s_data) { when(AXI4_port.rvalid) { state := s_idle } }
        is(s_aw)   {
            when(AXI4_port.awvalid && AXI4_port.awready){ aw_done := true.B }
            when(AXI4_port.wvalid  && AXI4_port.wready ){ w_done  := true.B }
            when((aw_done || AXI4_port.awready) && (w_done || AXI4_port.wready)){ state := s_b }
        }
        is(s_b)    { when(AXI4_port.bvalid) { state := s_idle } }
        is(s_rep)  { state := s_idle }
    }

    val load_done  = state === s_data && AXI4_port.rvalid
    val store_done = state === s_b    && AXI4_port.bvalid

    out.valid          := load_done || store_done || state === s_rep
    out.bits.rdata     := load_data
    out.bits.excp_code := MuxCase(0.U(3.W), Seq(
        (state === s_rep)                       -> Mux(to_store, excp_store_misalign, excp_load_misalign),
        (load_done  && AXI4_port.rresp =/= 0.U) -> excp_load_fault,
        (store_done && AXI4_port.bresp =/= 0.U) -> excp_store_fault))
    out.bits.is_excp   := out.bits.excp_code =/= 0.U

    PerfCounter("LSU_busy")            := in.valid && !in.ready
    PerfCounter("LSU_load_gate")       := in.valid && !in.ready && !req_store
    PerfCounter("LSU_store_gate")      := in.valid && !in.ready &&  req_store
    PerfCounter("LSU_load_latency")    := state =/= s_idle && !to_store
    PerfCounter("LSU_store_latency")   := state === s_aw
    PerfCounter("LSU_load_wait_free")  := state === s_ar
    PerfCounter("LSU_load_wait_resp")  := state === s_data
    PerfCounter("LSU_store_b_pending") := state === s_b
    PerfCounter("LSU_load_get_data")   := load_done
    PerfCounter("LSU_store_get_data")  := store_done
}
