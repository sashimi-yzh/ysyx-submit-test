package sirius

import chisel3._
import chisel3.util._

class AutoLocker(nPort: Int) extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(nPort.W))
    val out = Output(UInt(nPort.W))
  })

  val prevOut = RegNext(io.out, 0.U)
  val keeping = prevOut & io.in
  val hasKeeping = keeping.orR
  io.out := Mux(hasKeeping, keeping, io.in)
}

class ArbiterAutoLock[T <: Data](val gen: T, val n: Int) extends Module {
  val io = IO(new ArbiterIO(gen, n))

  val testaa = 1
  val arbiter = Module(new Arbiter(gen, n) {
    for ((in, g) <- this.io.in.zip(this.grant))
      in.ready := g && in.valid && this.io.out.ready
  })
  // dontTouch(arbiter.io)
  val autoLocker = Module(new AutoLocker(n))

  val valids = VecInit(io.in.map(_.valid)).asUInt
  autoLocker.io.in := valids

  io :<>= arbiter.io
  for (i <- 0 until n) {
    arbiter.io.in(i).valid := autoLocker.io.out(i)
  }
}

class Xbar(
  nMasters: Int = 2,
  nSlaves:  Int = 2,
  routeFn:  Seq[UInt => Bool],
  busWidth: Int = 32,
  idWidth:  Int = 4)
    extends Module {

  require(routeFn.length == nSlaves)
  val masterIdBits = log2Ceil(nMasters)
  require(masterIdBits < idWidth, "ID width not enough")

  val lowIdBits = idWidth - masterIdBits

  val io = IO(new Bundle {
    val in = Flipped(Vec(nMasters, new Axi4IO(busWidth)))
    val out = Vec(nSlaves, new Axi4IO(busWidth))
  })

  for (m <- 0 until nMasters) {
    when (io.in(m).aw.fire) {
      assert(io.in(m).aw.bits.id(idWidth - 1, lowIdBits) === 0.U)
    }
    when (io.in(m).ar.fire) {
      assert(io.in(m).ar.bits.id(idWidth - 1, lowIdBits) === 0.U)
    }
  }

  def decode(addr: UInt): Vec[Bool] = {
    VecInit(routeFn.map(f => f(addr)))
  }

  io.out :<= 0.U.asTypeOf(chiselTypeOf(io.out))
  0.U.asTypeOf(chiselTypeOf(io.in)) :>= io.in

  // AW W
  val awReady = Wire(Vec(nMasters, Vec(nSlaves, Bool())))
  val wReady = Wire(Vec(nMasters, Vec(nSlaves, Bool())))
  for (s <- 0 until nSlaves) {
    val awArb = Module(new ArbiterAutoLock(chiselTypeOf(io.in(0).aw.bits), nMasters))
    val wArb = Module(new ArbiterAutoLock(chiselTypeOf(io.in(0).w.bits), nMasters))

    for (m <- 0 until nMasters) {
      val sel = decode(io.in(m).aw.bits.addr)(s)
      val fireCond = io.in(m).aw.valid && io.in(m).w.valid && sel

      awArb.io.in(m).valid := fireCond
      awArb.io.in(m).bits := io.in(m).aw.bits
      awArb.io.in(m).bits.id :=
        m.U(masterIdBits.W) ## io.in(m).aw.bits.id(lowIdBits - 1, 0)

      wArb.io.in(m).valid := fireCond
      wArb.io.in(m).bits := io.in(m).w.bits

      awReady(m)(s) := awArb.io.in(m).ready && fireCond
      wReady(m)(s) := wArb.io.in(m).ready && fireCond
    }

    io.out(s).aw :<>= awArb.io.out
    io.out(s).w :<>= wArb.io.out
  }
  for (m <- 0 until nMasters) {
    io.in(m).aw.ready := awReady(m).reduce(_ || _)
    io.in(m).w.ready := wReady(m).reduce(_ || _)
  }

  // AR
  val arReady = Wire(Vec(nMasters, Vec(nSlaves, Bool())))
  for (s <- 0 until nSlaves) {
    val arArb = Module(new ArbiterAutoLock(chiselTypeOf(io.in(0).ar.bits), nMasters))

    for (m <- 0 until nMasters) {
      val sel = decode(io.in(m).ar.bits.addr)(s)

      arArb.io.in(m).valid := io.in(m).ar.valid && sel
      arArb.io.in(m).bits := io.in(m).ar.bits
      arArb.io.in(m).bits.id :=
        m.U(masterIdBits.W) ## io.in(m).ar.bits.id(lowIdBits - 1, 0)

      arReady(m)(s) := arArb.io.in(m).ready && sel
    }

    io.out(s).ar :<>= arArb.io.out
  }
  for (m <- 0 until nMasters) {
    io.in(m).ar.ready := arReady(m).reduce(_ || _)
  }

  // B
  for (s <- 0 until nSlaves) {
    val bid = io.out(s).b.bits.id

    val masterSel = bid(idWidth - 1, lowIdBits)
    val realId = bid(lowIdBits - 1, 0)

    for (m <- 0 until nMasters) {
      when(masterSel === m.U && io.out(s).b.valid) {
        io.in(m).b.valid := io.out(s).b.valid
        io.in(m).b.bits := io.out(s).b.bits
        io.in(m).b.bits.id := realId

        io.out(s).b.ready := io.in(m).b.ready
      }
    }
  }

  // R
  for (s <- 0 until nSlaves) {
    val rid = io.out(s).r.bits.id

    val masterSel = rid(idWidth - 1, lowIdBits)
    val realId = rid(lowIdBits - 1, 0)

    for (m <- 0 until nMasters) {
      when(masterSel === m.U && io.out(s).r.valid) {
        io.in(m).r.valid := io.out(s).r.valid
        io.in(m).r.bits := io.out(s).r.bits
        io.in(m).r.bits.id := realId

        io.out(s).r.ready := io.in(m).r.ready
      }
    }
  }
}

class SimpleXbar extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Vec(2, new Axi4IO))
    val out = Vec(2, new Axi4IO)
  })

  def outSel(addr: UInt) = addr >= "h02000000".U && addr < "h02010000".U

  val rAllowHandshake = RegInit(false.B)
  val rInSel = RegInit(false.B)
  val rOutSel = RegInit(false.B)

  val rInValid = io.in.map(_.ar.valid).reduce(_ || _)
  val rFinish = io.out.map(axi => axi.r.fire && axi.r.bits.last).reduce(_ || _)
  switch(rAllowHandshake) {
    is(false.B) {
      when(rInValid) {
        rAllowHandshake := true.B
        rInSel := !io.in(0).ar.valid
        rOutSel := Mux(
          io.in(0).ar.valid,
          outSel(io.in(0).ar.bits.addr),
          outSel(io.in(1).ar.bits.addr)
        )
      }
    }
    is(true.B) {
      when(rFinish) {
        rAllowHandshake := false.B
      }
    }
  }

  
  io.out.foreach { axi =>
    axi.ar.bits := DontCare
    axi.ar.valid := false.B
    axi.r.ready := false.B
  }
  io.in.foreach { axi =>
    axi.r.bits := DontCare
    axi.r.valid := false.B
    axi.ar.ready := false.B
  }
  when(rAllowHandshake) {
    switch(rInSel ## rOutSel) {
      is("b00".U) {
        io.out(0).ar :<>= io.in(0).ar
        io.in(0).r :<>= io.out(0).r
      }
      is("b01".U) {
        io.out(1).ar :<>= io.in(0).ar
        io.in(0).r :<>= io.out(1).r
      }
      is("b10".U) {
        io.out(0).ar :<>= io.in(1).ar
        io.in(1).r :<>= io.out(0).r
      }
      is("b11".U) {
        io.out(1).ar :<>= io.in(1).ar
        io.in(1).r :<>= io.out(1).r
      }
    }
  }

  io.out(0).aw :<>= io.in(0).aw
  io.out(0).w :<>= io.in(0).w
  io.in(0).b :<>= io.out(0).b

  0.U.asTypeOf(chiselTypeOf(io.out(1).aw)) :>= io.in(1).aw
  0.U.asTypeOf(chiselTypeOf(io.out(1).w)) :>= io.in(1).w
  io.in(1).b :<= 0.U.asTypeOf(chiselTypeOf(io.in(1).b))

  io.out(1).aw :<= 0.U.asTypeOf(chiselTypeOf(io.out(1).aw))
  io.out(1).w :<= 0.U.asTypeOf(chiselTypeOf(io.out(1).w))
  0.U.asTypeOf(chiselTypeOf(io.out(1).b)) :>= io.out(1).b

  // val wAllowHandshake = RegInit(false.B)
  // val wOutSel = RegInit(false.B)
  //
  // val wInValid = io.in(0).aw.valid
  // val wFinish = io.in(0).b.fire
  // switch(rAllowHandshake) {
  //   is(false.B) {
  //     when(wInValid) {
  //       wAllowHandshake := true.B
  //       wOutSel := outSel(io.in(0).aw.bits.addr)
  //     }
  //   }
  //   is(true.B) {
  //     when(wFinish) {
  //       wAllowHandshake := false.B
  //     }
  //   }
  // }
  //
  //
  // io.out.foreach { axi =>
  //   axi.aw.bits := DontCare
  //   axi.w.bits := DontCare
  //   axi.aw.valid := false.B
  //   axi.w.valid := false.B
  //   axi.b.ready := false.B
  // }
  // io.in.foreach { axi =>
  //   axi.b.bits := DontCare
  //   axi.b.valid := false.B
  //   axi.aw.ready := false.B
  //   axi.w.ready := false.B
  // }
  // when(wAllowHandshake) {
  //   when(wOutSel) {
  //     io.out(0).aw :<>= io.in(0).aw
  //     io.out(0).w :<>= io.in(0).w
  //     io.in(0).b :<>= io.out(0).b
  //   }.otherwise {
  //     io.out(0).aw :<>= io.in(0).aw
  //     io.out(0).w :<>= io.in(0).w
  //     io.in(0).b :<>= io.out(0).b
  //   }
  // }
}
