
package npc.devices

import chisel3._
import chisel3.util._

import npc.common.Constants._
import npc.common._
import npc.common.Util._

object  CLINTS{
    val mtime       =     0XBFF8.U(16.W)
    val mtime_high  =     0XBFFC.U(16.W)
}

class AXI4CLINT(implicit val conf: Config) extends Module { 
    val io = IO(new Bundle() { 
        val axi_io = Flipped(new AXI4LiteIo())
        val reset = Input(Bool())
        val clock = Input(Clock())
    })

    val clint = Module(new CLINT())
    val node = Module(new TopAXI4LiteSlave())
    
    clint.io.clock := io.clock
    clint.io.reset := io.reset
    node.io.axi_io <> io.axi_io
    node.io.reset := io.reset
    node.io.clock := io.clock
    node.io.out <> clint.io.in 

}

class CLINT(implicit val conf: Config) extends Module { 
    val io = IO(new Bundle() { 
        val reset = Input(Bool())
        val clock = Input(Clock())
        val in =new Bundle{
            val dr      =   new AXIRport(conf.xprlen, conf.xlen)
            val dw      =   new AXIWport(conf.xprlen, conf.xlen)
        }
    })
    val reg_mtime = RegInit(0.U(64.W))
    val clint_addr = io.in.dr.addr(15,0)
    val read_data = MuxLookup(clint_addr,0.U)(Seq(
        CLINTS.mtime -> reg_mtime(31,0),
        CLINTS.mtime_high -> reg_mtime(63,32)
    ))

    io.in.dw := DontCare
    io.in.dr.ready := true.B
    io.in.dr.data := Mux(io.in.dr.en,read_data,0.U)

    reg_mtime := reg_mtime + 1.U
}
