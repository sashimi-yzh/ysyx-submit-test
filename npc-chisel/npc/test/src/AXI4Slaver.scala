package npc

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers
import npc.common._
import npc._

class TopAXI4LiteSlaveTest extends AnyFlatSpec with Matchers {
  // 测试配置

  // 状态推断函数（仅通过IO信号）
  def inferState(dut: TopAXI4LiteSlave): String = {
    var state = dut.io.debug.state.peekValue().asBigInt.toInt
    val state_string = 
        state match {
        case 0 => "s_idle"
        case 1 => "s_inflight"
        case 2 => "s_wait_rready_bready"
        case _ => "unknown"
    }
    state_string
  }

  "TopAXI4LiteSlave" should "handle multi-cycle read delays correctly" in {
    implicit val conf = Config()

    simulate(new TopAXI4LiteSlave()) { dut =>
      implicit val clock = dut.clock
      
      // 初始化信号
      dut.io.reset.poke(true.B)
      dut.io.axi_io.ar.valid.poke(false.B)
      dut.io.axi_io.aw.valid.poke(false.B)
      dut.io.axi_io.w.valid.poke(false.B)
      dut.io.axi_io.r.ready.poke(false.B)
      dut.io.axi_io.b.ready.poke(false.B)
      dut.io.out.dr.ready.poke(false.B)
      dut.io.out.dw.ready.poke(false.B)
      
      clock.step(3)
      dut.io.reset.poke(false.B)
      clock.step(2)

      /**************** 测试用例1：读操作多周期延迟 ****************/
      println("===== TEST 1: Read with multi-cycle delays =====")
      
      // 阶段1：延迟ARVALID
      clock.step(3)
      println(f"  [State: ${inferState(dut)}] Asserting ARVALID")
      dut.io.axi_io.ar.valid.poke(true.B)
      dut.io.axi_io.ar.addr.poke(0x1000.U)
      
      // 验证ARREADY在1周期内响应
      clock.step()
      println(f"  [State: ${inferState(dut)}] ARREADY: ${dut.io.axi_io.ar.ready.peek().litValue}")
      dut.io.axi_io.ar.ready.expect(true.B)
      dut.io.out.dr.en.expect(true.B)  // 应进入INFLIGHT状态
      
      // 阶段2：延迟DR.READY（内部存储延迟）
      clock.step(4)
      println(f"  [State: ${inferState(dut)}] Asserting DR.READY")
      dut.io.out.dr.ready.poke(true.B)
      dut.io.out.dr.data.poke(0xCAFE.U)
      
      // 验证RVALID在1周期内拉高
      clock.step()
      println(f"  [State: ${inferState(dut)}] RVALID: ${dut.io.axi_io.r.valid.peek().litValue}")
      dut.io.axi_io.r.valid.expect(true.B)
      dut.io.axi_io.r.data.expect(0xCAFE.U)
      
      // 阶段3：延迟RREADY（主设备接收延迟）
      clock.step(3)
      println(f"  [State: ${inferState(dut)}] Asserting RREADY")
      dut.io.axi_io.r.ready.poke(true.B)
      
      // 验证状态返回IDLE
      clock.step()
      println(f"  [State: ${inferState(dut)}] After read completion")
      dut.io.axi_io.r.valid.expect(false.B)
      
      // 清理信号
      dut.io.axi_io.ar.valid.poke(false.B)
      dut.io.out.dr.ready.poke(false.B)
      dut.io.axi_io.r.ready.poke(false.B)
      clock.step(2)
    }}

"TopAXI4LiteSlave" should "handle multi-cycle write delays correctly" in {
    implicit val conf = Config()

    simulate(new TopAXI4LiteSlave()) { dut =>
      implicit val clock = dut.clock
      /**************** 测试用例2：写操作多周期延迟 ****************/
      println("\n===== TEST 2: Write with multi-cycle delays =====")
      
      // 阶段1：延迟AWVALID（地址延迟）
      clock.step(2)
      println(f"  [State: ${inferState(dut)}] Asserting AWVALID")
      dut.io.axi_io.aw.valid.poke(true.B)
      dut.io.axi_io.aw.addr.poke(0x2000.U)
      
      // 阶段2：延迟WVALID（数据延迟）
      clock.step(3)
      println(f"  [State: ${inferState(dut)}] Asserting WVALID")
      dut.io.axi_io.w.valid.poke(true.B)
      dut.io.axi_io.w.data.poke(0xBEEF.U)
      dut.io.axi_io.w.strb.poke("b1111".U)
      
      // 验证握手信号
      clock.step()
      println(f"  [State: ${inferState(dut)}] AWREADY: ${dut.io.axi_io.aw.ready.peek().litValue}, WREADY: ${dut.io.axi_io.w.ready.peek().litValue}")
      dut.io.axi_io.aw.ready.expect(true.B)
      dut.io.axi_io.w.ready.expect(true.B)
      dut.io.out.dw.en.expect(true.B)
      
      // 阶段3：延迟DW.READY（内部处理延迟）
      clock.step(4)
      println(f"  [State: ${inferState(dut)}] Asserting DW.READY")
      dut.io.out.dw.ready.poke(true.B)
      
      // 验证BVALID响应
      clock.step()
      println(f"  [State: ${inferState(dut)}] BVALID: ${dut.io.axi_io.b.valid.peek().litValue}")
      dut.io.axi_io.b.valid.expect(true.B)
      
      // 阶段4：延迟BREADY（主设备响应延迟）
      clock.step(3)
      println(f"  [State: ${inferState(dut)}] Asserting BREADY")
      dut.io.axi_io.b.ready.poke(true.B)
      
      // 验证状态返回IDLE
      clock.step()
      println(f"  [State: ${inferState(dut)}] After write completion")
      dut.io.axi_io.b.valid.expect(false.B)
      
      // 清理信号
      dut.io.axi_io.aw.valid.poke(false.B)
      dut.io.axi_io.w.valid.poke(false.B)
      dut.io.out.dw.ready.poke(false.B)
      dut.io.axi_io.b.ready.poke(false.B)
      clock.step(2)
    }}

"TopAXI4LiteSlave" should "handle multi-cycle write/read delays correctly" in {
    implicit val conf = Config()
    simulate(new TopAXI4LiteSlave()) { dut =>
    implicit val clock = dut.clock

      /**************** 测试用例3：并发读写操作 ****************/
      println("\n===== TEST 3: Concurrent read/write with delays =====")
      
      // 启动读请求（优先处理）
      println(f"  [State: ${inferState(dut)}] Asserting ARVALID for read")
      dut.io.axi_io.ar.valid.poke(true.B)
      dut.io.axi_io.ar.addr.poke(0x3000.U)
      clock.step(2)
      
      // 启动写请求（应被阻塞）
      println(f"  [State: ${inferState(dut)}] Asserting AWVALID/WVALID for write")
      dut.io.axi_io.aw.valid.poke(true.B)
      dut.io.axi_io.w.valid.poke(true.B)
      dut.io.axi_io.aw.addr.poke(0x4000.U)
      dut.io.axi_io.w.data.poke(0xDEAD.U)
      
      // 验证写请求被阻塞
      clock.step()
      println(f"  [State: ${inferState(dut)}] AWREADY: ${dut.io.axi_io.aw.ready.peek().litValue}")
      dut.io.axi_io.aw.ready.expect(false.B)
      
      // 完成读操作
      println(f"  [State: ${inferState(dut)}] Completing read")
      dut.io.axi_io.r.ready.poke(true.B)
      dut.io.out.dr.ready.poke(true.B)
      dut.io.out.dr.data.poke(0xABCD.U)
      clock.step()
      dut.io.axi_io.r.valid.expect(true.B)
      dut.io.axi_io.r.data.expect(0xABCD.U)
      clock.step()
      dut.io.axi_io.ar.valid.poke(false.B)
      dut.io.out.dr.ready.poke(false.B)
      clock.step()

    // 写请求启动
      println(f"  [State: ${inferState(dut)}] Write should start")
      dut.io.axi_io.aw.valid.poke(true.B)
      dut.io.axi_io.w.valid.poke(true.B)
      dut.io.axi_io.aw.addr.poke(0x4000.U)
      dut.io.axi_io.w.data.poke(0xDEAD.U)
      dut.io.axi_io.w.strb.poke("b1111".U)
      clock.step(1)

      // 验证写操作自动开始
      dut.io.axi_io.aw.ready.expect(true.B)
      dut.io.axi_io.w.ready.expect(true.B)
      
      // 完成写操作
      clock.step(3)
      dut.io.out.dw.ready.poke(true.B)
      clock.step()
      dut.io.axi_io.b.ready.poke(true.B)
      clock.step()
    }
  }
}