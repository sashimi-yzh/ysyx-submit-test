package npc.perip

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._
import npc.bus.axi._

class Clint extends Module {
    val io = IO(new Bundle {
        val clk = Input(Clock())
        val rst = Input(Reset())
        val axi4 = new AXI4WithoutClk // 保持与外部接口一致
    })

    io.axi4.awready := false.B
    io.axi4.wready := false.B
    io.axi4.bvalid := false.B
    io.axi4.bresp  := 0.U
    io.axi4.rlast := true.B
    io.axi4.rid := 0.U
    io.axi4.bid := 0.U

    val ADDR = "h02000000".U
    val mtime = RegInit(0.U(64.W))
    mtime := mtime + 1.U

    val AXI_AR_fire = io.axi4.arvalid & io.axi4.arready
    val AXI_R_fire = io.axi4.rvalid & io.axi4.rready

    val sr_BeforeAXI_AR_Fire :: sr_BeforeAXI_R_Fire :: Nil = Enum(2)
    val c_state = RegInit(sr_BeforeAXI_AR_Fire)
    val n_state = WireDefault(c_state)
    n_state := MuxLookup(c_state, sr_BeforeAXI_AR_Fire)(Seq(
        sr_BeforeAXI_AR_Fire   -> Mux(AXI_AR_fire, sr_BeforeAXI_R_Fire, sr_BeforeAXI_AR_Fire),
        sr_BeforeAXI_R_Fire    -> Mux(AXI_R_fire, sr_BeforeAXI_AR_Fire, sr_BeforeAXI_R_Fire)
    ))
    c_state := n_state

    io.axi4.arready := c_state === sr_BeforeAXI_AR_Fire
    io.axi4.rvalid := c_state === sr_BeforeAXI_R_Fire
    io.axi4.rresp := 0.U

    val rdata = RegInit(0.U)
    rdata := Mux(io.axi4.araddr === ADDR, mtime(31, 0), mtime(63, 32))

    io.axi4.rdata := rdata
}

