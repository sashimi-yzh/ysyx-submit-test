package npc.icache
import chisel3._
import chisel3.util._
import npc.AXI._
import npc.PMU._
import npc.instEntry
import npc.ysyxPrefix


class ysyx_26030092_icacheMainPipe_reg extends Module{

    val icache = Module(new ysyx_26030092_icache)

    val flush = IO(Input(Bool()))

    val req = IO(new Bundle {
        val addr = Input(UInt(32.W))
        val valid = Input(Bool())
        val ready = Output(Bool())
    })

    val resp = IO(Decoupled(new instEntry))

    val icache_flush = IO(Input(Bool()))
    icache.flush_cache := icache_flush
    icache.flush := flush

    val req_fifo = ysyxPrefix { Module(new Queue(UInt(30.W), 1, hasFlush = true)) } // req fifo
    req_fifo.io.enq.valid := req.valid
    req.ready := req_fifo.io.enq.ready
    req_fifo.io.enq.bits := req.addr(31,2)

    icache.req.addr := Cat(req_fifo.io.deq.bits, 0.U(2.W))

    // refill
    val refill_unit = Module(new ysyx_26030092_icacheRefillUnit_reg)
    refill_unit.flush := flush
    refill_unit.req.addr := Cat(req_fifo.io.deq.bits, 0.U(2.W))
    val refilling = RegInit(false.B)

    val miss = !icache.resp.hit & req_fifo.io.deq.valid
    val hit = icache.resp.hit & req_fifo.io.deq.valid

    dontTouch(miss)
    dontTouch(hit)
    refill_unit.req.valid := miss && !refilling
    when(refill_unit.req.valid & refill_unit.req.ready){
      refilling := true.B
    }
    when(refill_unit.resp.valid && refill_unit.resp.last){
      refilling := false.B
    }

    val AXI4_port = IO(new AXI4Bundle)
    AXI4_port <> refill_unit.AXI4_port

    val refill_err = AXI4_port.rvalid && (AXI4_port.rresp =/= 0.U)
    icache.refill.addr := refill_unit.resp.addr
    icache.refill.data := Mux(refill_err, "h00000013".U, refill_unit.resp.data)  // nop = addi x0, x0, 0
    icache.refill.last := refill_unit.resp.last
    icache.refill.valid := refill_unit.resp.valid

    resp.bits.pc := Cat(req_fifo.io.deq.bits, 0.U(2.W))
    resp.bits.inst := icache.resp.data
    resp.valid := hit
    req_fifo.io.deq.ready := resp.ready & resp.valid

    resp.bits.excp_code := 0.U
    resp.bits.is_excp := false.B

    req_fifo.io.flush.get := flush
    when(flush){
      resp.valid := false.B
      icache.refill.valid := false.B
      refill_unit.req.valid := false.B
      req_fifo.io.enq.valid := false.B
      req_fifo.io.deq.ready := false.B
      refilling := false.B
    }
}
