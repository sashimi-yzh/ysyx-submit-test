package empty

import chisel3._
import chisel3.util._
import chisel3.layer.block

class CacheLine(linesize_2pow: Int, linecount_2pow: Int) extends Bundle {
  val words = (1 << (linesize_2pow - 2))
  val tag_width = 32 - linesize_2pow - linecount_2pow
  val tag = UInt(tag_width.W)
  val data = Vec(words, UInt(32.W))
}

object ShouldCache {
  def apply(addr: UInt): Bool = {
    val high_4bit = addr(31, 28)
    val high_8bit = addr(31, 24)
    return high_4bit === 0x3.U(4.W) || high_4bit === 0x8.U(
      4.W
    ) || high_4bit === 0xa.U(
      4.W
    ) || high_4bit === 0xb.U(4.W) || high_8bit === 0x0f.U(8.W)
  }
}
class ICache(linesize_2pow: Int, linecount_2pow: Int) extends PrefixedModule {
  val io = IO(new Bundle {
    val addr = Input(UInt(32.W))
    val timestamp_req = Input(UInt(2.W))
    val avalid = Input(Bool())
    val aready = Output(Bool())
    val rdata = Output(UInt(32.W))
    val rpc = Output(UInt(32.W))
    val timestamp_res = Output(UInt(2.W))
    val in_cache = Output(Bool())
    val rvalid = Output(Bool())
    val rready = Input(Bool())
    val clear = Input(Bool())
  })

  val fetch_port = IO(new AXI)
  set_AXIfull_zero(fetch_port)

  val bytes = (1 << linesize_2pow)
  val words = (1 << (linesize_2pow - 2))
  val line_count = (1 << linecount_2pow)

  val cacheline_bits =
    (32 - linesize_2pow - linecount_2pow) + words * 32

  val content = Module(new FFRAM(linecount_2pow, cacheline_bits))
  content.suggestName("ysyx_25080216_ICacheRegisterFile")
  content.io.wen := false.B
  content.io.wdata := 0.U(cacheline_bits.W)

  val valid_flags =
    RegInit(Vec(line_count, Bool()), VecInit(Seq.fill(line_count)(false.B)))

  val fire = GenerateFireSignal(fetch_port)
  val ifu_afire = io.avalid && io.aready
  val ifu_rfire = io.rvalid && io.rready

  val addr_r = RegEnable(io.addr, 0.U(32.W), ifu_afire)
  val timestamp_r = RegEnable(io.timestamp_req, 0.U(2.W), ifu_afire)
  val has_request_r = RegInit(Bool(), false.B)

  has_request_r := MuxCase(
    has_request_r,
    Seq(
      (ifu_afire && !ifu_rfire) -> true.B,
      (!ifu_afire && ifu_rfire) -> false.B
    )
  )

  val input_tag = addr_r(31, linecount_2pow + linesize_2pow)
  val input_cache_index =
    addr_r(linecount_2pow + linesize_2pow - 1, linesize_2pow)
  val input_index_inside_cacheline = addr_r(linesize_2pow - 1, 2)

  content.io.addr := input_cache_index

  val cache_rdata =
    content.io.rdata.asTypeOf(new CacheLine(linesize_2pow, linecount_2pow))

  val should_cache = ShouldCache(addr_r)

  val in_cache = should_cache && valid_flags(
    input_cache_index
  ) && (cache_rdata.tag === input_tag)

  io.rpc := addr_r
  io.in_cache := in_cache

  val out_ar = RegInit(false.B)
  val has_r = RegInit(false.B)

  out_ar := MuxCase(
    out_ar,
    Seq(
      ifu_rfire -> false.B,
      fire.ar_fire -> true.B
    )
  )

  has_r := MuxCase(
    has_r,
    Seq(
      ifu_rfire -> false.B,
      fire.r_burst_last -> true.B
    )
  )

  fetch_port.ar.addr := Mux(
    should_cache,
    Cat(addr_r(31, linesize_2pow), 0.U(linesize_2pow.W)),
    addr_r
  )

  fetch_port.ar.valid := has_request_r && !out_ar && (!in_cache || !should_cache)
  fetch_port.r.ready := out_ar && !has_r

  val axi_rdata_latched_next = Wire(Vec(words, UInt(32.W)))
  val axi_rdata_latched = RegEnable(axi_rdata_latched_next, fire.r_fire)

  axi_rdata_latched_next(words - 1) := fetch_port.r.data

  for (i <- 0 until (words - 1))
    axi_rdata_latched_next(i) := axi_rdata_latched(i + 1)

  val cache_wdata = Wire(new CacheLine(linesize_2pow, linecount_2pow))
  cache_wdata.data := axi_rdata_latched.asTypeOf(Vec(words, UInt(32.W)))
  cache_wdata.tag := input_tag

  val pending_fencei = RegInit(Bool(), false.B)

  pending_fencei := MuxCase(
    pending_fencei,
    Seq(
      io.clear -> true.B,
      fire.r_burst_last -> false.B
    )
  )

  when(!in_cache && ifu_rfire && should_cache && !pending_fencei) {
    content.io.wen := true.B
    content.io.wdata := cache_wdata.asUInt
    valid_flags(input_cache_index) := true.B
  }

  when(io.clear) {
    for (i <- 0 until line_count)
      valid_flags(i) := false.B
  }

  io.aready := (in_cache && ifu_rfire) || !has_request_r
  io.timestamp_res := timestamp_r
  io.rvalid := has_request_r && (in_cache || has_r)

  io.rdata := Mux(
    should_cache,
    Mux(
      in_cache,
      cache_rdata.data(input_index_inside_cacheline),
      axi_rdata_latched(input_index_inside_cacheline)
    ),
    axi_rdata_latched(words - 1)
  )

  fetch_port.aw.id := "b0000".U(4.W)
  fetch_port.ar.id := "b0000".U(4.W)
  fetch_port.w.last := true.B
  fetch_port.ar.len := Mux(should_cache, (words - 1).U(8.W), 0.U(8.W))

  block(AXIAssertLayer) {
    check_signal_stable(
      fetch_port.ar.ready,
      fetch_port.ar.valid,
      Cat(
        fetch_port.ar.addr,
        fetch_port.ar.burst,
        fetch_port.ar.id,
        fetch_port.ar.len,
        fetch_port.ar.size
      ),
      "IFU.ar"
    )

    assert(!fetch_port.aw.valid && !fetch_port.w.valid, "ifu should not write")

    when(fire.r_fire) {
      assert(fetch_port.r.resp === "b00".U, "ifu.axi.rresp is not b00")
      assert(fetch_port.r.id === "b0000".U, "ifu.axi.rid is not b0000")
    }
  }
}
