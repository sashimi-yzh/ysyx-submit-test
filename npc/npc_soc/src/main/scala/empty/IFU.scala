package empty

import chisel3._
import chisel3.util._

class MessageIFU2IDU extends Bundle {
  val pc = UInt(32.W)
  val inst = UInt(32.W)
  val in_cache = Bool()
}

class IFU(init_pc: UInt) extends PrefixedModule {
  val in = IO(new Bundle {
    val exu_dnpc = Input(UInt(32.W))
    val flush_valid = Input(Bool())
    val fencei = Input(Bool())
  })
  val fetch_port = IO(new AXI)
  val icache = Module(new ICache(3, 1))
  val has_inst_r = RegInit(false.B)
  val fetch_pc_r = RegInit(init_pc)
  val out = IO(DecoupledIO(new MessageIFU2IDU))

  val cache_afire = icache.io.avalid && icache.io.aready
  val cache_rfire = icache.io.rvalid && icache.io.rready

  val timestamp_r = RegInit(0.U(2.W))
  val timestamp = Mux(in.flush_valid, timestamp_r + 1.U(2.W), timestamp_r)
  val has_inst = has_inst_r && !in.flush_valid
  val should_discard = icache.io.timestamp_res =/= timestamp

  fetch_port <> icache.fetch_port
  icache.io.addr := fetch_pc_r
  icache.io.timestamp_req := timestamp
  icache.io.avalid := !in.flush_valid
  icache.io.rready := out.fire || !has_inst
  icache.io.clear := in.fencei && in.flush_valid

  val cache_rfire_and_up_to_date = cache_rfire && !should_discard
  has_inst_r := MuxCase(
    has_inst_r,
    Seq(
      (cache_rfire_and_up_to_date && !out.fire) -> true.B,
      (in.flush_valid || (out.fire && !cache_rfire_and_up_to_date)) -> false.B
    )
  )

  val inst_reg = RegEnable(icache.io.rdata, cache_rfire)
  val inst_rpc = RegEnable(icache.io.rpc, cache_rfire)
  val inst_incache = RegEnable(icache.io.in_cache, cache_rfire)

  fetch_pc_r := MuxCase(
    fetch_pc_r,
    Seq(
      in.flush_valid -> in.exu_dnpc,
      cache_afire -> (fetch_pc_r + 4.U(32.W))
    )
  )
  timestamp_r := MuxCase(
    timestamp_r,
    Seq(in.flush_valid -> (timestamp_r + 1.U(2.W)))
  )

  out.valid := has_inst
  out.bits.inst := inst_reg
  out.bits.pc := inst_rpc
  out.bits.in_cache := inst_incache
}
