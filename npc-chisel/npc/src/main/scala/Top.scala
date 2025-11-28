
package npc

import chisel3._

import npc.common.{Config, 
                     AXI4LiteMaster,TopAXI4LiteSlave,
                     AXI4BurstSlave,AXI4LiteArbiter}
import npc._
import npc.devices.{TopAXI4LiteMem,IverilogAXI4LiteMem}

class IverilogTop extends Module { 
    val io = IO(new Bundle{
        // val halt = Output(Bool())
    })
   implicit val conf = Config()
    io := DontCare
    val core = Module(new ysyx_24100012())
    core.io := DontCare


    val axi_mem_slave   = Module(new TopAXI4LiteSlave())
    val axi_mem        = Module(new IverilogAXI4LiteMem())

    axi_mem_slave.io := DontCare
    axi_mem.io.clock := clock
    axi_mem.io.reset := reset

    axi_mem_slave.io.out.dr <> axi_mem.io.dr
    axi_mem_slave.io.out.dw <> axi_mem.io.dw
    core.io.master <>  axi_mem_slave.io.axi_io
}

class Top extends Module 
{
    val io = IO(new Bundle{
        // val halt = Output(Bool())
    })
   implicit val conf = Config()
    io := DontCare
    val core = Module(new ysyx_24100012())
    core.io := DontCare


    val axi_mem_slave   = Module(new TopAXI4LiteSlave())
    val axi_mem        = Module(new TopAXI4LiteMem())

    axi_mem_slave.io := DontCare
    axi_mem.io.clock := clock
    axi_mem.io.reset := reset

    axi_mem_slave.io.out.dr <> axi_mem.io.dr
    axi_mem_slave.io.out.dw <> axi_mem.io.dw
    core.io.master <>  axi_mem_slave.io.axi_io
    // io.halt := core.io.halt
}
