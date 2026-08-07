package xbar

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import org.chipsalliance.diplomacy.lazymodule.{LazyModule, LazyModuleImp}
import axi4._
import diplomatic._
import diplomatic.AXI4NodeImp

class XbarArbiter(
  implicit p: Parameters)
    extends LazyModule {
  val node = new AXI4NexusNode(
    dFn = { seq =>
      if (seq.isEmpty) AXI4MasterNodeParameters()
      else
        seq.reduce { (a, b) =>
          AXI4MasterNodeParameters(
            addrBits = a.addrBits.max(b.addrBits),
            dataBits = a.dataBits.max(b.dataBits),
            idBits = a.idBits.max(b.idBits)
          )
        }
    },
    uFn = { seq =>
      if (seq.isEmpty) AXI4SlaveNodeParameters(Nil)
      else AXI4SlaveNodeParameters(seq.flatMap(_.address))
    }
  )

  lazy val module = new Impl
  class Impl extends LazyModuleImp(this) {
    val (io_in, edgesIn)   = node.in.unzip
    val (io_out, edgesOut) = node.out.unzip
    val nMasters           = io_in.size
    val nSlaves            = io_out.size
    val axiParams          = edgesIn.headOption.map { e =>
      AXI4Parameters(e.master.addrBits, e.master.dataBits, e.master.idBits)
    }.getOrElse(AXI4Parameters())

    val arMatch = Seq.tabulate(nMasters, nSlaves) { (i, j) =>
      val slaveAddrs = edgesOut(j).slave.address
      if (slaveAddrs.isEmpty) false.B
      else slaveAddrs.map(_.contains(io_in(i).ar.bits.addr)).reduce(_ || _)
    }
    val arRoute = Seq.tabulate(nMasters, nSlaves) { (i, j) =>
      val matchHigher = (0 until j).map(k => arMatch(i)(k)).foldLeft(false.B)(_ || _)
      arMatch(i)(j) && !matchHigher
    }
    val awMatch = Seq.tabulate(nMasters, nSlaves) { (i, j) =>
      val slaveAddrs = edgesOut(j).slave.address
      if (slaveAddrs.isEmpty) false.B
      else slaveAddrs.map(_.contains(io_in(i).aw.bits.addr)).reduce(_ || _)
    }
    val awRoute = Seq.tabulate(nMasters, nSlaves) { (i, j) =>
      val matchHigher = (0 until j).map(k => awMatch(i)(k)).foldLeft(false.B)(_ || _)
      awMatch(i)(j) && !matchHigher
    }

    for (s <- io_out) {
      s.ar.valid := false.B; s.ar.bits := DontCare;
      s.r.ready  := false.B
      s.aw.valid := false.B; s.aw.bits := DontCare
      s.w.valid  := false.B; s.w.bits  := DontCare;
      s.b.ready  := false.B
    }
    val io_in_vec = VecInit(io_in)
    for (m <- 0 until nMasters) {
      io_in_vec(m).ar.ready := false.B
      io_in_vec(m).r.valid  := false.B; io_in_vec(m).r.bits := DontCare
      io_in_vec(m).aw.ready := false.B
      io_in_vec(m).w.ready  := false.B
      io_in_vec(m).b.valid  := false.B; io_in_vec(m).b.bits := DontCare
    }
    class SimpleRRArbiter(n: Int) extends Module {
      val io        = IO(new Bundle {
        val in     = Input(Vec(n, Bool()))
        val out    = Output(new Bundle {
          val valid = Bool()
        })
        val chosen = UInt(log2Ceil(n).W)
      })
      val lastGrant = RegInit(0.U(log2Ceil(n).W))

      val highPri = Wire(Vec(n, Bool()))
      for (i <- 0 until n) {
        highPri(i) := io.in(i) && (i.U > lastGrant)
      }
      val lowPri = Wire(Vec(n, Bool()))
      for (i <- 0 until n) {
        lowPri(i) := io.in(i) && (i.U <= lastGrant)
      }

      val anyHigh = highPri.reduce(_ || _)
      io.chosen    := PriorityEncoder(Mux(anyHigh, highPri, lowPri))
      io.out.valid := io.in.reduce(_ || _)

      when(io.out.valid) {
        lastGrant := io.chosen
      }
    }
    val arArb = Seq.fill(nSlaves)(Module(new SimpleRRArbiter(nMasters)))
    val awArb       = Seq.fill(nSlaves)(Module(new SimpleRRArbiter(nMasters)))
    val readChosen  = Seq.fill(nSlaves)(RegInit(0.U(log2Ceil(nMasters).W)))
    val writeChosen = Seq.fill(nSlaves)(RegInit(0.U(log2Ceil(nMasters).W)))
    for {
      m <- 0 until nMasters
      s <- 0 until nSlaves
    } {
      arArb(s).io.in(m) := io_in(m).ar.valid & arRoute(m)(s)
    }
    for {
      m <- 0 until nMasters
      s <- 0 until nSlaves
    } {
      awArb(s).io.in(m) := io_in(m).aw.valid & awRoute(m)(s)
    }
    val sIdle :: sBusy :: Nil = Enum(2)
    val readState  = Seq.fill(nSlaves)(RegInit(sIdle))
    val writeState = Seq.fill(nSlaves)(RegInit(sIdle))
    for {
      s    <- 0 until nSlaves
    } {
      readState(s) := MuxLookup(readState(s), sIdle)(
        Seq(
          sIdle -> Mux(arArb(s).io.out.valid, sBusy, sIdle),
          sBusy -> Mux(io_out(s).r.fire && io_out(s).r.bits.last, sIdle, sBusy)
        )
      )
    }
    for {
      s    <- 0 until nSlaves
    } {
      switch(readState(s)) {
        is(sIdle) {
          when(arArb(s).io.out.valid) {
            readChosen(s) := arArb(s).io.chosen
          }
        }
      }
    }
    // ar
    for {
      s    <- 0 until nSlaves
    } {
      io_out(s).ar.valid := io_in_vec(readChosen(s)).ar.valid && readState(s) === sBusy
      io_out(s).ar.bits  := io_in_vec(readChosen(s)).ar.bits
    }
    for (m <- 0 until nMasters) {
      val candidates = VecInit(Seq.tabulate(nSlaves) { s =>
        readChosen(s) === m.U && readState(s) === sBusy
      })
      io_in_vec(m).ar.ready := Mux1H(candidates, VecInit(io_out.map(_.ar.ready)))
    }
    // r
    for (m <- 0 until nMasters) {
      val candidates = VecInit(Seq.tabulate(nSlaves) { s =>
        readChosen(s) === m.U && readState(s) === sBusy
      })
      io_in_vec(m).r.valid := Mux1H(candidates, VecInit(io_out.map(_.r.valid)))
      io_in_vec(m).r.bits  := Mux1H(candidates, VecInit(io_out.map(_.r.bits)))
    }
    for {
      s    <- 0 until nSlaves
    } {
      io_out(s).r.ready := io_in_vec(readChosen(s)).r.ready && readState(s) === sBusy
    }
    for {
      s    <- 0 until nSlaves
    } {
      writeState(s) := MuxLookup(writeState(s), sIdle)(
        Seq(
          sIdle -> Mux(awArb(s).io.out.valid, sBusy, sIdle),
          sBusy -> Mux(io_out(s).b.fire, sIdle, sBusy)
        )
      )
    }
    for {
      s    <- 0 until nSlaves
    } {
      switch(writeState(s)) {
        is(sIdle) {
          when(awArb(s).io.out.valid) {
            writeChosen(s) := awArb(s).io.chosen
          }
        }
      }
    }
    // aw
    for {
      s    <- 0 until nSlaves
    } {
      io_out(s).aw.valid := io_in_vec(writeChosen(s)).aw.valid && writeState(s) === sBusy
      io_out(s).aw.bits  := io_in_vec(writeChosen(s)).aw.bits
    }
    for (m <- 0 until nMasters) {
      val candidates = VecInit(Seq.tabulate(nSlaves) { s =>
        writeChosen(s) === m.U && writeState(s) === sBusy
      })
      io_in_vec(m).aw.ready := Mux1H(candidates, VecInit(io_out.map(_.aw.ready)))
    }
    // w
    for {
      s    <- 0 until nSlaves
    } {
      io_out(s).w.valid := io_in_vec(writeChosen(s)).w.valid && writeState(s) === sBusy
      io_out(s).w.bits  := io_in_vec(writeChosen(s)).w.bits
    }
    for (m <- 0 until nMasters) {
      val candidates = VecInit(Seq.tabulate(nSlaves) { s =>
        writeChosen(s) === m.U && writeState(s) === sBusy
      })
      io_in_vec(m).w.ready := Mux1H(candidates, VecInit(io_out.map(_.w.ready)))
    }
    // b
    for (m <- 0 until nMasters) {
      val candidates = VecInit(Seq.tabulate(nSlaves) { s =>
        writeChosen(s) === m.U && writeState(s) === sBusy
      })
      io_in_vec(m).b.valid := Mux1H(candidates, VecInit(io_out.map(_.b.valid)))
      io_in_vec(m).b.bits  := Mux1H(candidates, VecInit(io_out.map(_.b.bits)))
    }
    for {
      s    <- 0 until nSlaves
    } {
      io_out(s).b.ready := io_in_vec(writeChosen(s)).b.ready && writeState(s) === sBusy
    }
  }
}

object XbarArbiter {
  def apply(
  )(
    implicit p: Parameters
  ): AXI4NexusNode = {
    val xbar = LazyModule(new XbarArbiter)
    xbar.node
  }
}
