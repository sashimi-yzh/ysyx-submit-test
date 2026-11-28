package npc.icache

import chisel3._
import chisel3.util._


class ysyx_26030092_icache extends Module {
    val req = IO(new Bundle {
        val addr = Input(UInt(32.W))
    })

    val resp = IO(new Bundle {
        val data = Output(UInt(32.W))
        val hit  = Output(Bool())
    })

    val refill = IO(new Bundle {
        val addr  = Input(UInt(32.W))
        val data  = Input(UInt(32.W))
        val last  = Input(Bool())
        val valid = Input(Bool())
    })

    val flush_cache = IO(Input(Bool()))
    val flush       = IO(Input(Bool()))

    val data       = Reg(Vec(8, UInt(32.W)))
    val tag        = Reg(Vec(2, UInt(27.W)))
    val line_valid = RegInit(VecInit(Seq.fill(2)(false.B)))

    val offset  = req.addr(3, 2) // req addr
    val index   = req.addr(4)
    val cur_tag = req.addr(31, 5)
    dontTouch(index)
    dontTouch(offset)
    dontTouch(cur_tag)

    // val line = VecInit.tabulate(4)(i => data(index * 4.U + i.U))
    resp.data := data(Cat(index, offset))
    resp.hit  := (cur_tag === tag(index)) && line_valid(index)

    val refill_offset = refill.addr(3, 2) // refill addr
    val refill_index  = refill.addr(4)
    val refill_tag    = refill.addr(31, 5)
    when(refill.valid) {
        data(Cat(refill_index, refill_offset)) := refill.data
        when(refill.last) {
            tag(refill_index)        := refill_tag
            line_valid(refill_index) := true.B
        }
    }

    when(flush_cache) {
        line_valid.foreach(_ := false.B)
    }
}
