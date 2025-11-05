package ysyx_23060246 

import chisel3._
import chisel3.util._
import freechips.rocketchip.amba.axi4._
import AXI4._

class ysyx_23060246_CLINT(params: AXI4BundleParameters) extends Module {
    val io = IO(new Bundle {
        //val axi = new AXILiteSlaveIF(32,32)
        val axi = Flipped(new AXI4Bundle(params))
    })

    val mtime = RegInit(0.U(60.W))
    mtime := mtime + 1.U

    val s_idle :: s_wait_ready :: Nil = Enum(2)
    val state = RegInit(s_idle)
    state := MuxLookup(state, s_idle)(Seq(
        s_idle -> Mux(io.axi.ar.valid, s_wait_ready, s_idle),
        s_wait_ready -> Mux(io.axi.r.ready, s_idle, s_wait_ready)
    ))

    io.axi.ar.ready := state === s_idle
    io.axi.r.valid := state === s_wait_ready

    val rdata = Mux(io.axi.ar.bits.addr(3,0) === 0x8L.U, mtime(31,0), Cat(0.U(4.W), mtime(59,32)))
    io.axi.r.bits.data := rdata 
    io.axi.r.bits.resp := 0.U


    // 不支持写
    io.axi.aw.ready := false.B
    io.axi.w.ready := false.B
    io.axi.b.valid := false.B
    io.axi.b.bits.id := 0.U
    io.axi.b.bits.resp := 0.U

    io.axi.r.bits.last := true.B
    io.axi.r.bits.id := 0.U

}