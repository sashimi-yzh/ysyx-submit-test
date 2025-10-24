package npc

import chisel3._
import chisel3.util._
import npc.core._
import npc.perip._
import npc.bus._
import npc.common.Config._

class NPCIO extends Bundle{
    val interrupt = Input(Bool())
    val master = Flipped(new npc.bus.axi.AXI4WithoutClk)
    val slave = new npc.bus.axi.AXI4WithoutClk
}

class ysyx_24080032 extends Module {

if(RENAME){
    withModulePrefix("ysyx_24080032") {
        val io = IO(new NPCIO)

        io.slave.arready := false.B
        io.slave.rdata := DontCare
        io.slave.rresp := 0.U
        io.slave.rid := 0.U
        io.slave.rready := DontCare
        io.slave.rvalid := false.B
        io.slave.rlast := true.B
        io.slave.awready := false.B
        io.slave.wready := false.B
        io.slave.bresp := 0.U
        io.slave.bvalid := false.B
        io.slave.bid := 0.U
        io.master.araddr := DontCare
        io.master.arvalid := false.B
        io.master.arid := 0.U
        io.master.arlen := 0.U
        io.master.arsize := 0.U
        io.master.arburst := 0.U
        io.master.rready := false.B
        io.master.awaddr := DontCare
        io.master.awvalid := false.B
        io.master.awid := 0.U
        io.master.awlen := 0.U
        io.master.awsize := 0.U
        io.master.awburst := 0.U
        io.master.wdata := DontCare
        io.master.wstrb := 0.U
        io.master.wvalid := 0.U
        io.master.wlast := false.B
        io.master.bready := false.B






        val core = Module(new Core)
        val xbar = Module(new npc.bus.xbar.Xbar)
        val clint = Module(new npc.perip.Clint)

        //from chisel
        core.clock := clock
        core.reset := reset.asBool
        xbar.clock := clock
        xbar.reset := reset.asBool

        //from sv
        clint.io.clk := clock
        clint.io.rst := reset.asBool

        core.io.imem              <>    xbar.io.imem
        core.io.dmem              <>    xbar.io.dmem
        xbar.io.clint             <>    clint.io.axi4
        xbar.io.soc               <>    io.master
    }
} else {
        val io = IO(new NPCIO)

        io.slave.arready := false.B
        io.slave.rdata := DontCare
        io.slave.rresp := 0.U
        io.slave.rid := 0.U
        io.slave.rready := DontCare
        io.slave.rvalid := false.B
        io.slave.rlast := true.B
        io.slave.awready := false.B
        io.slave.wready := false.B
        io.slave.bresp := 0.U
        io.slave.bvalid := false.B
        io.slave.bid := 0.U
        io.master.araddr := DontCare
        io.master.arvalid := false.B
        io.master.arid := 0.U
        io.master.arlen := 0.U
        io.master.arsize := 0.U
        io.master.arburst := 0.U
        io.master.rready := false.B
        io.master.awaddr := DontCare
        io.master.awvalid := false.B
        io.master.awid := 0.U
        io.master.awlen := 0.U
        io.master.awsize := 0.U
        io.master.awburst := 0.U
        io.master.wdata := DontCare
        io.master.wstrb := 0.U
        io.master.wvalid := 0.U
        io.master.wlast := false.B
        io.master.bready := false.B






        val core = Module(new Core)
        val xbar = Module(new npc.bus.xbar.Xbar)
        val clint = Module(new npc.perip.Clint)

        //from chisel
        core.clock := clock
        core.reset := reset.asBool
        xbar.clock := clock
        xbar.reset := reset.asBool

        //from sv
        clint.io.clk := clock
        clint.io.rst := reset.asBool

        core.io.imem              <>    xbar.io.imem
        core.io.dmem              <>    xbar.io.dmem
        xbar.io.clint             <>    clint.io.axi4
        xbar.io.soc               <>    io.master
}



}
