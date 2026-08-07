package axi4
import chisel3._
import chisel3.util.Irrevocable
class AXI4Bundle(params: AXI4Parameters)     extends Bundle     {
  val aw = Irrevocable(new AXI4AWChannel(params))
  val w  = Irrevocable(new AXI4WChannel(params))
  val b  = Flipped(Irrevocable(new AXI4BChannel(params)))
  val ar = Irrevocable(new AXI4ARChannel(params))
  val r  = Flipped(Irrevocable(new AXI4RChannel(params)))
}
class AXI4AWChannel(params: AXI4Parameters)  extends Bundle     {
  val addr  = UInt(params.addrBits.W)
  val id    = UInt(params.idBits.W)
  val len   = UInt(params.lenBits.W)
  val size  = UInt(params.sizeBits.W)
  val burst = UInt(params.burstBits.W)
}
class AXI4WChannel(params: AXI4Parameters)   extends Bundle     {
  val data = UInt(params.dataBits.W)
  val strb = UInt(params.strbBits.W)
  val last = Bool()
}
class AXI4BChannel(params: AXI4Parameters)   extends Bundle     {
  val resp = UInt(params.bRespWidth.W)
  val id   = UInt(params.idBits.W)
}
class AXI4ARChannel(params: AXI4Parameters)  extends Bundle     {
  val addr  = UInt(params.addrBits.W)
  val id    = UInt(params.idBits.W)
  val len   = UInt(params.lenBits.W)
  val size  = UInt(params.sizeBits.W)
  val burst = UInt(params.burstBits.W)
}
class AXI4RChannel(params: AXI4Parameters)   extends Bundle     {
  val resp = UInt(params.rRespWidth.W)
  val data = UInt(params.dataBits.W)
  val last = Bool()
  val id   = UInt(params.idBits.W)
}
object AXI4RespEnum                          extends ChiselEnum {
  val OKAY   = 0.U(2.W)
  val EXOKAY = 1.U(2.W)
  val SLVERR = 2.U(2.W)
  val DECERR = 3.U(2.W)
}
object AXI4BurstEnum                         extends ChiselEnum {
  val FIXED    = "b00".U
  val INCR     = "b01".U
  val WRAP     = "b10".U
  val RESERVED = "b11".U
}
class AXI4FlatBundle(params: AXI4Parameters) extends Bundle     {
  // AW
  val awvalid = Output(Bool())
  val awready = Input(Bool())
  val awaddr  = Output(UInt(params.addrBits.W))
  val awid    = Output(UInt(params.idBits.W))
  val awlen   = Output(UInt(params.lenBits.W))
  val awsize  = Output(UInt(params.sizeBits.W))
  val awburst = Output(UInt(params.burstBits.W))

  // W
  val wvalid = Output(Bool())
  val wready = Input(Bool())
  val wdata  = Output(UInt(params.dataBits.W))
  val wstrb  = Output(UInt(params.strbBits.W))
  val wlast  = Output(Bool())

  // B
  val bvalid = Input(Bool())
  val bready = Output(Bool())
  val bresp  = Input(UInt(params.bRespWidth.W))
  val bid    = Input(UInt(params.idBits.W))

  // AR
  val arvalid = Output(Bool())
  val arready = Input(Bool())
  val araddr  = Output(UInt(params.addrBits.W))
  val arid    = Output(UInt(params.idBits.W))
  val arlen   = Output(UInt(params.lenBits.W))
  val arsize  = Output(UInt(params.sizeBits.W))
  val arburst = Output(UInt(params.burstBits.W))

  // R
  val rvalid = Input(Bool())
  val rready = Output(Bool())
  val rresp  = Input(UInt(params.rRespWidth.W))
  val rdata  = Input(UInt(params.dataBits.W))
  val rlast  = Input(Bool())
  val rid    = Input(UInt(params.idBits.W))
  def :#=(bundle: AXI4Bundle):               AXI4FlatBundle = {
    // AW
    awvalid         := bundle.aw.valid
    awaddr          := bundle.aw.bits.addr
    awid            := bundle.aw.bits.id
    awlen           := bundle.aw.bits.len
    awsize          := bundle.aw.bits.size
    awburst         := bundle.aw.bits.burst
    bundle.aw.ready := awready

    // W
    wvalid         := bundle.w.valid
    wdata          := bundle.w.bits.data
    wstrb          := bundle.w.bits.strb
    wlast          := bundle.w.bits.last
    bundle.w.ready := wready

    // B
    bready             := bundle.b.ready
    bundle.b.valid     := bvalid
    bundle.b.bits.resp := bresp
    bundle.b.bits.id   := bid

    // AR
    arvalid         := bundle.ar.valid
    araddr          := bundle.ar.bits.addr
    arid            := bundle.ar.bits.id
    arlen           := bundle.ar.bits.len
    arsize          := bundle.ar.bits.size
    arburst         := bundle.ar.bits.burst
    bundle.ar.ready := arready

    // R
    rready             := bundle.r.ready
    bundle.r.valid     := rvalid
    bundle.r.bits.resp := rresp
    bundle.r.bits.data := rdata
    bundle.r.bits.last := rlast
    bundle.r.bits.id   := rid

    this
  }
  def fromBundleAsSlave(bundle: AXI4Bundle): AXI4FlatBundle = {
    // AW: slave 接收
    bundle.aw.valid      := awvalid
    bundle.aw.bits.addr  := awaddr
    bundle.aw.bits.id    := awid
    bundle.aw.bits.len   := awlen
    bundle.aw.bits.size  := awsize
    bundle.aw.bits.burst := awburst
    awready              := bundle.aw.ready

    // W: slave 接收
    bundle.w.valid     := wvalid
    bundle.w.bits.data := wdata
    bundle.w.bits.strb := wstrb
    bundle.w.bits.last := wlast
    wready             := bundle.w.ready

    // B: slave 返回
    bvalid         := bundle.b.valid
    bundle.b.ready := bready
    bresp          := bundle.b.bits.resp
    bid            := bundle.b.bits.id

    // AR: slave 接收
    bundle.ar.valid      := arvalid
    bundle.ar.bits.addr  := araddr
    bundle.ar.bits.id    := arid
    bundle.ar.bits.len   := arlen
    bundle.ar.bits.size  := arsize
    bundle.ar.bits.burst := arburst
    arready              := bundle.ar.ready

    // R: slave 返回
    rvalid         := bundle.r.valid
    bundle.r.ready := rready
    rresp          := bundle.r.bits.resp
    rdata          := bundle.r.bits.data
    rlast          := bundle.r.bits.last
    rid            := bundle.r.bits.id

    this
  }
}
