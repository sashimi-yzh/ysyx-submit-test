package npc.bus.xbar

import chisel3._
import chisel3.util._
import npc.bus.axi._
import npc.common.Config._
import npc.bus.axi.AXI4Connector._
/*
            __  ______    _    ____
            \ \/ / __ )  / \  |  _ \
             \  /|  _ \ / _ \ | |_) |
             /  \| |_) / ___ \|  _ <
            /_/\_\____/_/   \_\_| \_\
*/
/*              This is the SOC version                        */
/*              combine Arbiter and Xbar together              */
class XbarIO extends Bundle{
    //imem ---> xbar
    //dmem ---> xbar
    val imem = new AXI4WithoutClk
    val dmem = new AXI4WithoutClk
    //xbar ---> soc
    //xbar ---> clint
    val soc = Flipped(new AXI4WithoutClk)
    val clint = Flipped(new AXI4WithoutClk)
}

class Xbar extends Module {
    val io = IO(new XbarIO)

/*-----------------------FSM-----------------------*/
    val s_IDLE :: s_i_soc :: s_d_soc :: s_d_clint :: Nil = Enum(4)
    val c_state = RegInit(s_IDLE)
    val n_state = WireDefault(c_state)
    dontTouch(c_state)
    dontTouch(n_state)

    val isclint_raddr = (io.dmem.araddr >= "h0200_0000".U(32.W) && io.dmem.araddr <= "h0200_ffff".U(32.W))
    val isclint_waddr = (io.dmem.awaddr >= "h0200_0000".U(32.W) && io.dmem.awaddr <= "h0200_ffff".U(32.W))
    val isdmem = Mux(io.dmem.arvalid | io.dmem.awvalid, true.B, false.B)
    val isimem = Mux(io.imem.arvalid, Mux(isdmem || c_state === s_d_clint || c_state === s_d_soc, false.B, true.B), false.B)

    val isclint = isclint_raddr | isclint_waddr

    c_state := n_state//first phase

    val soc_i_done = io.soc.rvalid & io.soc.rlast
    val soc_d_done = io.soc.rvalid | io.soc.bvalid
    val clint_d_done = io.clint.rvalid | io.soc.bvalid

    n_state := MuxLookup(c_state, s_IDLE)(Seq(//second phase
        s_IDLE       ->  MuxCase(s_IDLE, Seq(
            isimem                      ->    s_i_soc,
            (isdmem && ~isclint)        ->    s_d_soc,
            (isdmem && isclint)         ->    s_d_clint
        )),
        s_i_soc    ->  Mux(soc_i_done, Mux(io.imem.arvalid, s_i_soc, s_IDLE), s_i_soc),
        s_d_soc    ->  Mux(soc_d_done, s_IDLE, s_d_soc),
        s_d_clint  ->  Mux(clint_d_done, s_IDLE, s_d_clint)
    ))

    DefaultImem()
    DefaultDmem()
    DefaultSoc()
    DefaultClint()

    switch(c_state){//third phase
        is(s_IDLE){
            when(isimem){
                connectAll(io.imem, io.soc)
            }.elsewhen(isdmem & ~isclint){
                connectAll(io.dmem, io.soc)
            }.elsewhen(isdmem & isclint){
                connectAll(io.dmem, io.clint)
            }
        }
        is(s_i_soc){
            connectAll(io.imem, io.soc)
        }
        is(s_d_soc){
            connectAll(io.dmem, io.soc)
        }
        is(s_d_clint){
            connectAll(io.dmem, io.clint)
        }
    }


/*-----------------------function-----------------------*/
    def DefaultImem(): Unit = {
        io.imem.arready := false.B
        io.imem.rdata := 0.U
        io.imem.rresp := 0.U
        io.imem.rvalid := false.B
        io.imem.rlast := false.B
        io.imem.rid := 0.U
        io.imem.awready := false.B
        io.imem.wready := false.B
        io.imem.bresp := 0.U
        io.imem.bvalid := false.B
        io.imem.bid := 0.U
    }

    def DefaultDmem(): Unit = {
        io.dmem.arready := false.B
        io.dmem.rdata := 0.U
        io.dmem.rresp := 0.U
        io.dmem.rvalid := false.B
        io.dmem.rlast := false.B
        io.dmem.rid := 0.U
        io.dmem.awready := false.B
        io.dmem.wready := false.B
        io.dmem.bresp := 0.U
        io.dmem.bvalid := false.B
        io.dmem.bid := 0.U
    }

    def DefaultSoc(): Unit = {
        io.soc.araddr := 0.U
        io.soc.arvalid := false.B
        io.soc.arid := 0.U
        io.soc.arlen := 0.U
        io.soc.arsize := 0.U
        io.soc.arburst := 0.U
        io.soc.rready := false.B
        io.soc.awaddr := 0.U
        io.soc.awvalid := false.B
        io.soc.awid := 0.U
        io.soc.awlen := 0.U
        io.soc.awsize := 0.U
        io.soc.awburst := 0.U
        io.soc.wdata := 0.U
        io.soc.wstrb := 0.U
        io.soc.wvalid := false.B
        io.soc.wlast := false.B
        io.soc.bready := false.B
    }

    def DefaultClint(): Unit = {
        io.clint.araddr := 0.U
        io.clint.arvalid := false.B
        io.clint.arid := 0.U
        io.clint.arlen := 0.U
        io.clint.arsize := 0.U
        io.clint.arburst := 0.U
        io.clint.rready := false.B
        io.clint.awaddr := 0.U
        io.clint.awvalid := false.B
        io.clint.awid := 0.U
        io.clint.awlen := 0.U
        io.clint.awsize := 0.U
        io.clint.awburst := 0.U
        io.clint.wdata := 0.U
        io.clint.wstrb := 0.U
        io.clint.wvalid := false.B
        io.clint.wlast := false.B
        io.clint.bready := false.B
    }

}


/*
+-----+      +---------------+      +------+
| IMEM| ---> |               |----> | soc  |
+-----+      |               |      +------+
             |      Xbar     |
+-----+      |               |      +------+
| DMEM| ---> |               |----> | CLINT|
+-----+      +---------------+      +------+
*/