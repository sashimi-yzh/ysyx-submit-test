package cpu  

import ysyx_23060246._   

import chisel3._
import chisel3.util._
import chiseltest._
import chiseltest.formal._
import org.scalatest.flatspec.AnyFlatSpec
import scala.math._
import AXI4._
import freechips.rocketchip.amba.axi4._



// class smallModule extends Module {
//     val io = IO(new Bundle {
//         val a = Input(UInt(32.W))
//         val b = Input(UInt(32.W))
//         val s = Output(UInt(32.W))
//     })
//     io.s := io.a + io.b
// }

// class ICacheTest extends AnyFlatSpec with ChiselScalatestTester {
//     it should "PASS" in {
//         test(new smallModule) { dut =>
//             dut.io.a.poke(1.U)
//             dut.io.b.poke(2.U)
//             dut.io.s.expect(3.U)
//         }
//     }
// }

class ICacheFormalTestBench(config: NPCConfig) extends Module {
    val io = IO(new Bundle{
        val in = Flipped(Decoupled(new SigIO_WBU_IFU(config.XLEN)))
        val stall = Input(Bool())
        val fencei = Input(Bool())
        val flush = Input(Bool())
        val npc = Input(UInt(config.XLEN.W))
        val pc = (Decoupled((UInt(config.XLEN.W))))
    })

    val icache = Module(new ysyx_23060246_ICache(config))

    val ifu_dut = Module(new ysyx_23060246_IFU(config))
    val ifu_ref = Module(new ysyx_23060246_IFU(config))
    val mem_dut = Module(new MEMforTest(config.axiparams))
    val mem_ref = Module(new MEMforTest(config.axiparams))

    ifu_dut.io.in <> io.in
    ifu_ref.io.in <> io.in
    ifu_dut.io.flush := io.flush
    ifu_ref.io.flush := io.flush
    // ifu_ref.io.exu_npc := io.npc
    // ifu_dut.io.exu_npc := io.npc
    ifu_dut.io.pc <> io.pc
    ifu_ref.io.pc <> io.pc

    icache.io.fencei := io.fencei




    // For DUT, use I$ to fetch instruction
    icache.io.ifu <> ifu_dut.io.imem
    icache.io.imem <> mem_dut.io.axi

    // For REF, directly fetch instruction
    mem_ref.io.axi <> ifu_ref.io.imem

    ifu_dut.io.out.ready := true.B
    ifu_ref.io.out.ready := true.B
    when(ifu_dut.io.out.valid && ifu_ref.io.out.valid){
        assert(ifu_dut.io.out.bits === ifu_ref.io.out.bits, "ICache Test Failed")
    }

}

class ICacheTest extends AnyFlatSpec with ChiselScalatestTester with Formal{

  val config = NPCConfig()
    it should "PASS" in {
        verify(new ICacheFormalTestBench(config), Seq(BoundedCheck(10)))
    }

}




class MEMforTest(params: AXI4BundleParameters) extends Module {
  val io = IO(new Bundle {
    val axi = Flipped(new AXI4Bundle(params))
  })

  val axi    = io.axi
  //val mem    = Module(new Mem)

  val random_r = 10.U
  val random_w = 10.U

  // 读状态机
  val s_read_idle :: s_read :: s_read_delay :: s_wait_read_ready :: Nil = Enum(4)
  val state_r = RegInit(s_read_idle)
  state_r := MuxLookup(state_r, s_read_idle)(Seq(
    s_read_idle -> Mux(axi.ar.valid, s_read, s_read_idle),
    //s_read -> s_read_delay,
    s_read -> s_wait_read_ready, //不使用随机延迟
    s_read_delay -> Mux(random_r >= 10.U , s_wait_read_ready, s_read_delay),
    s_wait_read_ready -> Mux(axi.r.ready, s_read_idle, s_wait_read_ready)
  ))

  axi.ar.ready := state_r === s_read_idle
  val rdata = RegInit(0.U(32.W))
  when(state_r === s_read){
    rdata := Cat(axi.ar.bits.addr(31,2), 0.U(2.W))  // 取出的数据固定为对齐后的addr
  }
  axi.r.valid := state_r === s_wait_read_ready
  axi.r.bits.data := rdata 
  axi.r.bits.resp := 0.U



  // 写状态机
  val s_write_idle :: s_wait_data :: s_wait_addr :: s_write :: s_write_delay :: s_wait_write_ready :: Nil = Enum(6)
  val state_w = RegInit(s_write_idle)
  state_w := MuxLookup(state_w, s_write_idle)(Seq(
    s_write_idle -> Mux(axi.aw.valid && axi.w.valid, s_write, 
                        Mux(axi.aw.valid, s_wait_data, 
                            Mux(axi.w.valid, s_wait_addr, s_write_idle))),
    s_wait_data -> Mux(axi.w.valid, s_write, s_wait_data),
    s_wait_addr -> Mux(axi.aw.valid, s_write, s_wait_addr),
    //s_write -> s_write_delay,
    s_write -> s_wait_write_ready, //不使用随机延迟
    s_write_delay -> Mux(random_w >= 10.U, s_wait_write_ready, s_write_delay),
    s_wait_write_ready -> Mux(axi.b.ready, s_write_idle, s_wait_write_ready)
  ))


  val wdata = RegInit(0.U(32.W))
  val waddr = RegInit(0.U(32.W))
  val wstrb = RegInit(0.U(4.W))
  when(axi.aw.valid){
    waddr := axi.aw.bits.addr
  }
  when(axi.w.valid){
    wdata := axi.w.bits.data
    wstrb := axi.w.bits.strb
  }
  
  axi.aw.ready := state_w === s_write_idle || state_w === s_wait_addr
  axi.w.ready := state_w === s_write_idle || state_w === s_wait_data
  axi.b.valid := state_w === s_wait_write_ready


//   mem.io.clock := clock
//   mem.io.reset := reset
//   mem.io.raddr := axi.ar.bits.addr
//   mem.io.we := state_w === s_write
//   mem.io.waddr := waddr
//   mem.io.wdata := wdata
//   mem.io.wmask := wstrb 



  io.axi.b.bits.id := 0.U
  io.axi.b.bits.resp := 0.U

  io.axi.r.bits.last := true.B
  io.axi.r.bits.id := 0.U
}
