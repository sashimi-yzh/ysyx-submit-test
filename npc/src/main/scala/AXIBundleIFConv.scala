package AXI4 


import chisel3._
import freechips.rocketchip.amba.axi4._

// RocketChip  AXI4Bundle to AXIBundle (My AXI4Bundle)
class ysyx_23060246_AXI4BundleIFConv(addrWidthBits:Int, dataWidthBits:Int) extends Module{
    val io = IO( new Bundle{
            val in =  Flipped(new AXI4Bundle( AXI4BundleParameters(
                                  addrBits = addrWidthBits, 
                                  dataBits = dataWidthBits, 
                                  idBits = 4)))
            val out = new AXIBundle(addrWidthBits, dataWidthBits)
    })

  io.out.awaddr := io.in.aw.bits.addr
  io.out.awvalid := io.in.aw.valid
  io.out.awid := io.in.aw.bits.id
  io.out.awlen := io.in.aw.bits.len
  io.out.awsize := io.in.aw.bits.size
  io.out.awburst := io.in.aw.bits.burst
  // io.out.awlock := io.in.aw.bits.lock
  // io.out.awcache := io.in.aw.bits.cache
  // io.out.awprot := io.in.aw.bits.prot
  // io.out.awqos := io.in.aw.bits.qos

  io.out.wvalid := io.in.w.valid
  io.out.wdata  := io.in.w.bits.data
  io.out.wstrb  := io.in.w.bits.strb
  io.out.wlast  := io.in.w.bits.last

  io.out.bready := io.in.b.ready

  io.out.arvalid := io.in.ar.valid
  io.out.araddr  := io.in.ar.bits.addr
  io.out.arid    := io.in.ar.bits.id
  io.out.arlen   := io.in.ar.bits.len
  io.out.arsize  := io.in.ar.bits.size
  io.out.arburst := io.in.ar.bits.burst
  // io.out.arlock  := io.in.ar.bits.lock
  // io.out.arcache := io.in.ar.bits.cache
  // io.out.arprot  := io.in.ar.bits.prot
  // io.out.arqos   := io.in.ar.bits.qos

  io.out.rready  := io.in.r.ready  
  //----
  io.in.aw.ready := io.out.awready

  io.in.w.ready := io.out.wready

  io.in.b.valid := io.out.bvalid
  io.in.b.bits.resp := io.out.bresp 
  io.in.b.bits.id   := io.out.bid 

  io.in.ar.ready := io.out.arready

  io.in.r.valid := io.out.rvalid
  io.in.r.bits.resp := io.out.rresp
  io.in.r.bits.data := io.out.rdata
  io.in.r.bits.last := io.out.rlast
  io.in.r.bits.id   := io.out.rid

}


// Haven't successfully implemented the reverse conversion
// class AXI4BundleIFConvRev(addrWidthBits:Int, dataWidthBits:Int) extends Module{
//     val io = IO( new Bundle{
//             val in = Flipped(new AXIBundle(addrWidthBits, dataWidthBits))
//             val out =  new AXI4Bundle( AXI4BundleParameters(
//                                   addrBits = addrWidthBits, 
//                                   dataBits = dataWidthBits, 
//                                   idBits = 4))
//     })

//   io.in.awaddr := io.out.aw.bits.addr
//   io.in.awvalid := io.out.aw.valid
//   io.in.awid := io.out.aw.bits.id
//   io.in.awlen := io.out.aw.bits.len
//   io.in.awsize := io.out.aw.bits.size
//   io.in.awburst := io.out.aw.bits.burst


//   io.in.wvalid := io.out.w.valid
//   io.in.wdata := io.out.w.bits.data
//   io.in.wstrb := io.out.w.bits.strb
//   io.in.wlast := io.out.w.bits.last

//   io.in.bready := io.out.b.ready

//   io.in.arvalid := io.out.ar.valid
//   io.in.araddr := io.out.ar.bits.addr
//   io.in.arid := io.out.ar.bits.id
//   io.in.arlen := io.out.ar.bits.len
//   io.in.arsize := io.out.ar.bits.size
//   io.in.arburst := io.out.ar.bits.burst

//   io.in.rready := io.out.r.ready

//   io.out.aw.ready := io.in.awready

//   io.out.w.ready := io.in.wready

//   io.out.b.valid := io.in.bvalid
//   io.out.b.bits.resp := io.in.bresp
//   io.out.b.bits.id := io.in.bid

//   io.out.ar.ready := io.in.arready

//   io.out.r.valid := io.in.rvalid
//   io.out.r.bits.resp := io.in.rresp
//   io.out.r.bits.data := io.in.rdata
//   io.out.r.bits.last := io.in.rlast
//   io.out.r.bits.id := io.in.rid

// }