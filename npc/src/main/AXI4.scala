package npc
import chisel3._
import chisel3.util._
import utils._

object AXI4Parameters extends NPCParameters {
  // These are all fixed by the AXI4 standard:
  val lenBits   = 8
  val sizeBits  = 3
  val burstBits = 2
  val cacheBits = 4
  val protBits  = 3
  val qosBits   = 4
  val respBits  = 2

  // These are not fixed:
  val idBits    = 1
  val addrBits  = 32
  val dataBits  = XLEN
  val userBits  = 0

  def RESP_OKAY   = 0.U(respBits.W)
  def RESP_EXOKAY = 1.U(respBits.W)
  def RESP_SLVERR = 2.U(respBits.W)
  def RESP_DECERR = 3.U(respBits.W)

  def BURST_FIXED = 0.U(burstBits.W)
  def BURST_INCR  = 1.U(burstBits.W)
  def BURST_WRAP  = 2.U(burstBits.W)
}

trait AXI4HasUser {
  val user  = if (AXI4Parameters.userBits > 0) Some(Output(UInt(AXI4Parameters.userBits.W))) else None
}

trait AXI4HasData {
  def dataBits = AXI4Parameters.dataBits
  val data  = Output(UInt(dataBits.W))
}

trait AXI4HasId {
  def idBits = AXI4Parameters.idBits
  val id    = Output(UInt(idBits.W))
}

trait AXI4HasLast {
  val last = Output(Bool())
}

// AXI4-lite

class AXI4LiteBundleA extends Bundle {
  val addr  = Output(UInt(AXI4Parameters.addrBits.W))
  val size  = Output(UInt(AXI4Parameters.sizeBits.W))
//  val prot  = Output(UInt(AXI4Parameters.protBits.W))
}

class AXI4LiteBundleW(override val dataBits: Int = AXI4Parameters.dataBits) extends Bundle with AXI4HasData {
  val strb = Output(UInt((dataBits/8).W))
}

class AXI4LiteBundleB extends Bundle {
  val resp = Output(UInt(AXI4Parameters.respBits.W))
}

class AXI4LiteBundleR(override val dataBits: Int = AXI4Parameters.dataBits) extends AXI4LiteBundleB with AXI4HasData


class AXI4Lite extends Bundle {
  val aw = Decoupled(new AXI4LiteBundleA)
  val w  = Decoupled(new AXI4LiteBundleW)
  val b  = Flipped(Decoupled(new AXI4LiteBundleB))
  val ar = Decoupled(new AXI4LiteBundleA)
  val r  = Flipped(Decoupled(new AXI4LiteBundleR))
}


// AXI4-full

class AXI4BundleA(override val idBits: Int) extends AXI4LiteBundleA with AXI4HasId with AXI4HasUser {
  val len   = Output(UInt(AXI4Parameters.lenBits.W))  // number of beats - 1
//  val size  = Output(UInt(AXI4Parameters.sizeBits.W)) // bytes in beat = 2^size
  val burst = Output(UInt(AXI4Parameters.burstBits.W))
//  val lock  = Output(Bool())
//  val cache = Output(UInt(AXI4Parameters.cacheBits.W))
//  val qos   = Output(UInt(AXI4Parameters.qosBits.W))  // 0=no QoS, bigger = higher priority
  // val region = UInt(width = 4) // optional

  override def toPrintable: Printable = p"addr = 0x${Hexadecimal(addr)}, id = ${id}, len = ${len}, size = ${size}"
}

// id ... removed in AXI4
class AXI4BundleW(override val dataBits: Int) extends AXI4LiteBundleW(dataBits) with AXI4HasLast {
  override def toPrintable: Printable = p"data = ${Hexadecimal(data)}, wmask = 0x${strb}, last = ${last}"
}
class AXI4BundleB(override val idBits: Int) extends AXI4LiteBundleB with AXI4HasId with AXI4HasUser {
  override def toPrintable: Printable = p"resp = ${resp}, id = ${id}"
}
class AXI4BundleR(override val dataBits: Int, override val idBits: Int) extends AXI4LiteBundleR(dataBits) with AXI4HasLast with AXI4HasId with AXI4HasUser {
  override def toPrintable: Printable = p"resp = ${resp}, id = ${id}, data = ${Hexadecimal(data)}, last = ${last}"
}


class AXI4(val dataBits: Int = AXI4Parameters.dataBits, val idBits: Int = AXI4Parameters.idBits) extends AXI4Lite {
  override val aw = Decoupled(new AXI4BundleA(idBits))
  override val w  = Decoupled(new AXI4BundleW(dataBits))
  override val b  = Flipped(Decoupled(new AXI4BundleB(idBits)))
  override val ar = Decoupled(new AXI4BundleA(idBits))
  override val r  = Flipped(Decoupled(new AXI4BundleR(dataBits, idBits)))
}

object AXI4LiteToAXI4 {
  def master(in: AXI4Lite) = {
    val out = WireInit(0.U.asTypeOf(new AXI4))
    (out: Data).waiveAll :<>= (in: Data).waiveAll
    out.w.bits.last  := true.B
    out
  }
  def slave(out: AXI4Lite) = {
    val in = WireInit(0.U.asTypeOf(new AXI4))
    (out: Data).waiveAll :<>= (in: Data).waiveAll
    in.r.bits.last  := true.B
    in
  }
}

class AXI4CrossbarNto1[T <: AXI4Lite](n: Int, _type: T) extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Vec(n, _type))
    val out = _type
  })

  object State extends ChiselEnum { val idle, waitReqReady, waitResp = Value }

  // read channel
  val arvalids = io.in.map(_.ar.valid)
  val chosenReadIdx = PriorityEncoder(arvalids)
  val hasReadValid = arvalids.reduce(_ || _)
  val lastRead = if (_type.getClass == classOf[AXI4Lite]) true.B else io.out.asInstanceOf[AXI4].r.bits.last

  val stateRead = RegInit(State.idle)
  stateRead := Lookup1H(stateRead, Seq(
    State.idle     -> Mux(hasReadValid, Mux(io.out.ar.ready, State.waitResp, State.waitReqReady), State.idle),
    State.waitReqReady -> Mux(io.out.ar.ready, State.waitResp, State.waitReqReady),
    State.waitResp -> Mux(io.out.r.fire && lastRead, State.idle, State.waitResp),
  ))

  val acceptRead = (stateRead === State.idle) && io.out.ar.valid
  val chosenReadIdxReg_s1 = RegEnable(chosenReadIdx, 0.U, acceptRead)
  val chosenReadIdxReg_s0 = Mux(acceptRead, chosenReadIdx, chosenReadIdxReg_s1)

  io.out.ar.bits := io.in(chosenReadIdxReg_s0).ar.bits
  io.out.ar.valid := hasReadValid && (stateRead =/= State.waitResp)
  io.in.map(_.ar.ready := false.B)
  io.in(chosenReadIdxReg_s0).ar.ready := io.out.ar.ready && (stateRead =/= State.waitResp)

  io.in.map(_.r.bits := io.out.r.bits)
  io.in.map(_.r.valid := false.B)
  io.in(chosenReadIdxReg_s1).r.valid := io.out.r.valid
  io.out.r.ready := io.in(chosenReadIdxReg_s1).r.ready

  // write channel
  val inputArbWrite = Module(new Arbiter(chiselTypeOf(io.in(0).aw.bits), n))
  inputArbWrite.io.in <> io.in.map(_.aw)
  val thisWrite = inputArbWrite.io.out

  val stateWrite = RegInit(State.idle)
  stateWrite := Lookup1H(stateWrite, Seq(
    State.idle     -> Mux(thisWrite.fire, State.waitResp, State.idle),
    State.waitResp -> Mux(io.out.b.fire, State.idle, State.waitResp),
  ))

  val acceptWrite = (stateWrite === State.idle) // || io.out.b.fire
  val chosenWrite = RegEnable(inputArbWrite.io.chosen, 0.U, acceptWrite && thisWrite.fire)

  io.out.aw.bits := thisWrite.bits
  io.out.aw.valid := thisWrite.valid && acceptWrite
  thisWrite.ready := io.out.aw.ready && acceptWrite
  io.out.w.bits := io.in(inputArbWrite.io.chosen).w.bits
  io.out.w.valid := io.out.aw.valid
  io.in.map(_.w.ready := false.B)
  io.in(inputArbWrite.io.chosen).w.ready := io.out.w.ready && acceptWrite

  io.in.map(_.b.bits := io.out.b.bits)
  io.in.map(_.b.valid := false.B)
  io.in(chosenWrite).b.valid := io.out.b.valid
  io.out.b.ready := io.in(chosenWrite).b.ready
}

class AXI4Crossbar1toN[T <: AXI4Lite](addrspace: List[(Long, Long)],  _type: T) extends NPCModule {
  val nSlave = addrspace.length
  val io = IO(new Bundle {
    val in = Flipped(_type)
    val out = Vec(nSlave, _type)
  })

  val araddr = io.in.ar.bits.addr
  val arSel = List.fill(nSlave)(Wire(Bool()))
  arSel.zip(addrspace).map {
    case(s, (base, len)) => s := io.in.ar.valid && (((araddr ^ base.U) & ~len.U(PALEN.W)) === 0.U)
  }
  val outDefault = io.out(nSlave - 1)
  if (addrspace.last == (0, 0)) {
    // the last default channel is selected when other channels are not selected
    arSel(nSlave - 1) := io.in.ar.valid && !arSel.reverse.drop(1).reduce(_ || _)
  }

  object State extends ChiselEnum { val idle, waitResp, slowPathInHasNotFire, slowPathWaitARready = Value }
  val stateRead = RegInit(State.idle)

  val arSelIdx = OHToUInt(arSel)
  val selOut = io.out(arSelIdx)
  val arSel_s1 = RegEnable(VecInit(arSel), io.in.ar.valid)
  val arSelIdx_s1 = RegEnable(arSelIdx, io.in.ar.valid)
  val selOut_s1 = io.out(arSelIdx_s1)
  val lastRead = if (_type.getClass == classOf[AXI4Lite]) true.B else selOut_s1.asInstanceOf[AXI4].r.bits.last

  stateRead := Lookup1H(stateRead, Seq(
    State.idle     -> Mux(io.in.ar.valid,
                        Mux(arSel(nSlave - 1),
                          Mux(outDefault.ar.ready, State.waitResp, State.idle),
                          Mux(outDefault.ar.ready, State.slowPathWaitARready, State.slowPathInHasNotFire)),
                        State.idle),
    State.waitResp -> Mux(selOut_s1.r.valid && lastRead, State.idle, State.waitResp),
    State.slowPathInHasNotFire -> Mux(io.in.ar.ready, State.slowPathWaitARready, State.slowPathInHasNotFire),
    State.slowPathWaitARready -> Mux(selOut_s1.ar.ready, State.waitResp, State.slowPathWaitARready),
  ))

  val in_ar_bits_s1 = RegEnable(io.in.ar.bits, io.in.ar.valid)

  outDefault.ar.valid := (stateRead === State.idle) && arSel(nSlave - 1)
  outDefault.ar.bits := io.in.ar.bits
  io.out.zip(arSel_s1).reverse.drop(1).map{ case (o, s) =>
    o.ar.valid := ((stateRead === State.slowPathWaitARready) && s)
    o.ar.bits := in_ar_bits_s1
  }
  io.in.ar.ready := ((stateRead === State.idle) && outDefault.ar.ready) ||
                    ((stateRead === State.slowPathInHasNotFire) && io.out(arSelIdx_s1).ar.ready)
  io.in.r.bits := selOut_s1.r.bits
  io.in.r.valid := (stateRead === State.waitResp) && selOut_s1.r.valid
  io.out.zip(arSel_s1).map{ case (o, s) => o.r.ready := s }

  io.out.map(_.aw.valid := false.B)
  io.out.map(_. w.valid := false.B)
  io.out.map(_.aw.bits := DontCare)
  io.out.map(_. w.bits := DontCare)
  io.out.map(_. b.ready := false.B)
  io.out(nSlave - 1).aw <> io.in.aw
  io.out(nSlave - 1). w <> io.in. w
  io.out(nSlave - 1). b <> io.in. b
}
