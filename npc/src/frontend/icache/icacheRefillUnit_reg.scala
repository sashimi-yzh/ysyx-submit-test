package npc.icache

import chisel3._
import chisel3.util._
import npc.AXI._
import npc.PMU._


class ysyx_26030092_icacheRefillUnit_reg extends Module{
    val flush = IO(Input(Bool()))
    val req = IO(new Bundle {
        val addr  = Input(UInt(32.W))
        val valid = Input(Bool())
        val ready = Output(Bool())
    })

    val resp = IO(new Bundle {
        val data  = Output(UInt(32.W))
        val last  = Output(Bool())
        val addr  = Output(UInt(32.W))
        val valid = Output(Bool())
    })

    val AXI4_port = IO(new AXI4Bundle)
    AXI4_port.initMaster()

    val s_idle :: s_wait_mem_free :: s_wait_mem_data :: Nil = Enum(3)
    val state = RegInit(s_idle)

    val req_addr_reg = Reg(UInt(32.W))
    val beat_cnt     = RegInit(0.U(2.W))

    val block_addr = Cat(req_addr_reg(31,4), 0.U(4.W))

    resp.data  := AXI4_port.rdata
    resp.last  := AXI4_port.rlast
    resp.addr  := block_addr + (beat_cnt << 2)
    resp.valid := false.B

    req.ready         := false.B
    AXI4_port.arvalid := false.B
    AXI4_port.araddr  := 0.U
    AXI4_port.arlen   := 0.U
    AXI4_port.arsize  := 0.U
    AXI4_port.arburst := 0.U
    AXI4_port.rready  := false.B

    switch(state){
        is(s_idle){
            req.ready := true.B
            when(req.valid){
                req_addr_reg := req.addr
                beat_cnt     := 0.U
                state        := s_wait_mem_free
            }
        }
        is(s_wait_mem_free){
            AXI4_port.arvalid := true.B
            AXI4_port.araddr  := block_addr
            AXI4_port.arlen   := 3.U
            AXI4_port.arsize  := 2.U
            AXI4_port.arburst := 1.U
            when(AXI4_port.arready){
                state := s_wait_mem_data
            }
        }
        is(s_wait_mem_data){
            when(AXI4_port.rvalid){
                AXI4_port.rready := true.B
                resp.valid := true.B
                beat_cnt := beat_cnt + 1.U
                when(AXI4_port.rlast){
                    state := s_idle
                }
            }
        }
    }

    PerfCounter("icache_refill_busy")  := (state =/= s_idle)
    PerfCounter("icache_refill_count") := (state === s_idle) && req.valid
}
