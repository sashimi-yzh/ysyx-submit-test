package ysyx_23060246

import chisel3._
import circt.stage.ChiselStage
import freechips.rocketchip.amba.axi4._
import cpu._
//import defines._
import AXI4._
import io.circe._ 
import io.circe.generic.auto._
import io.circe.parser._



class npcIO extends Bundle {
  val interrupt = Input(Bool())
  val master = new AXIBundle(32,32)
  val slave = Flipped(new AXIBundle(32,32))
}


class ysyx_23060246(config: NPCConfig) extends Module {
  val io = IO(new npcIO)
  val cpu_npc = Module(new ysyx_23060246_npc(config))
  val clint = Module(new ysyx_23060246_CLINT(config.axiparams))

  
  val xbar = Module(new ysyx_23060246_AXIXbar(2, 
                        Array((0L,0xFFFFFFFFL),(config.CLINT_BASE,config.CLINT_END)) ,
                        config.axiparams))
  xbar.io.in <> cpu_npc.io.axi

  // if(config.USE_SOC){
  //   val axi4_conv = Module(new ysyx_23060246_AXI4BundleIFConv(32,32))
  //   xbar.io.out(0) <> axi4_conv.io.in
  //   axi4_conv.io.out <> io.master
  // } else {
  //   val sram = Module(new SRAM( config.axiparams))
  //   dontTouch(sram.axi)
  //   val uart = Module(new UART_AXI( config.axiparams))
  //   val xbar_2 = Module(new ysyx_23060246_AXIXbar(2, 
  //                       Array((0L,0xFFFFFFFFL),(0xa00003f0L,0xa00003ffL)) ,
  //                        config.axiparams))
  //   xbar.io.out(0) <> xbar_2.io.in 
  //   xbar_2.io.out(0) <> sram.io.axi 
  //   xbar_2.io.out(1) <> uart.io.axi
  //   io.master <> DontCare 
  // }
  
  val axi4_conv = Module(new ysyx_23060246_AXI4BundleIFConv(32,32))
  xbar.io.out(0) <> axi4_conv.io.in
  axi4_conv.io.out <> io.master
  
  xbar.io.out(1) <> clint.io.axi 


  // val axierror = Module(new AXIError)
  // axierror.io.bresp := io.master.bresp
  // axierror.io.rresp := io.master.rresp
  // axierror.io.wen := io.master.bvalid 
  // axierror.io.ren := io.master.arvalid


  //io.slave <> DontCare 
  io.slave.awready := false.B 
  io.slave.wready := false.B
  io.slave.bvalid := false.B
  io.slave.bresp := 0.U
  io.slave.bid := 0.U
  io.slave.arready := false.B
  io.slave.rvalid := false.B
  io.slave.rresp := 0.U
  io.slave.rdata := 0.U
  io.slave.rlast := false.B
  io.slave.rid := 0.U

  dontTouch(io.slave)
  dontTouch(io.interrupt)
  dontTouch(io.master)

}

object npcMain extends App {
  
  val config = NPCConfig()
  println(config.asString)

  val firtoolOptions = Array("--lowering-options=" + List(
        // make yosys happy
        // see https://github.com/llvm/circt/blob/main/docs/VerilogGeneration.md
        "disallowLocalVariables",
        "disallowPackedArrays",
        "locationInfoStyle=wrapInAtSquareBracket"
    ).reduce(_ + "," + _),
    "--disable-annotation-unknown")
  ChiselStage.emitSystemVerilogFile(new ysyx_23060246(config), args, firtoolOptions)
}
