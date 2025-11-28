package npc

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.must.Matchers

import npc.common._
import npc._

class AXI4LiteMasterTest extends AnyFlatSpec with Matchers {
  
  // 测试配置
  
  // 状态监控函数
  def monitorState(dut: AXI4LiteMaster): String = {
    val rstate = dut.io.debug.rstate.peekValue().asBigInt.toInt
    val wstate = dut.io.debug.wstate.peekValue().asBigInt.toInt
    
    val rstateStr = rstate match {
      case 0    => "rs_idle"
      case 1    => "rs_wait_arready" 
      case 2    => "rs_wait_rlast"
      case _    => s"rs_unknown($rstate)"
    }
    
    val wstateStr = wstate match {
      case 0   => "ws_idle"
      case 1   => "ws_wait_ready"
      case 2   => "ws_wait_bvalid"
      case _ => s"ws_unknown($wstate)"
    }
    
    s"R:$rstateStr W:$wstateStr, is_read:${dut.io.debug.is_read.peek().litToBoolean}, is_write:${dut.io.debug.is_write.peek().litToBoolean}"
  }

  "AXI4LiteMaster" should "handle single read operation correctly" in {
    implicit val conf = Config()      
    simulate(new AXI4LiteMaster()) { dut =>
      
      // 初始化
      dut.io.reset.poke(true.B)
      dut.clock.step(3)
      dut.io.reset.poke(false.B)
      
      // 设置读请求
      dut.io.req.raddr.poke(0x1000.U)
      dut.io.req.ren.poke(true.B)
      dut.io.req.wen.poke(false.B)
      dut.io.req.typ.poke(2.U) // 32位访问
      
      // 验证AR通道信号
      dut.io.axi_io.ar.valid.expect(true.B)
      dut.io.axi_io.ar.addr.expect(0x1000.U)
      println(s"Cycle 1 - State: ${monitorState(dut)}")
      
      // AXI从设备准备好接收地址
      dut.io.axi_io.ar.ready.poke(true.B)
      dut.io.axi_io.r.valid.poke(false.B)
      
      dut.clock.step()
      println(s"Cycle 2 - State: ${monitorState(dut)}")
      
      // 从设备返回数据
      dut.io.axi_io.r.valid.poke(true.B)
      dut.io.axi_io.r.data.poke(0x12345678.U)
      dut.io.axi_io.r.resp.poke(0.U) // OKAY响应
      dut.io.axi_io.r.last.poke(true.B)
      
      dut.clock.step()
      println(s"Cycle 3 - State: ${monitorState(dut)}")
      
      // 验证响应
      dut.io.resp.valid.expect(true.B)
      dut.io.resp.bits.data.expect(0x12345678.U)
      dut.io.resp.bits.resp.expect(0.U)
    }
  }

  "AXI4LiteMaster" should "handle single read wait rvalid correctly" in {
    implicit val conf = Config()      
    simulate(new AXI4LiteMaster()) { dut =>
      
      // 初始化
      dut.io.reset.poke(true.B)
      dut.clock.step(3)
      dut.io.reset.poke(false.B)
      
      // 设置读请求
      dut.io.req.raddr.poke(0x1000.U)
      dut.io.req.ren.poke(true.B)
      dut.io.req.wen.poke(false.B)
      dut.io.req.typ.poke(2.U) // 32位访问
      
      // 验证AR通道信号
      dut.io.axi_io.ar.valid.expect(true.B)
      dut.io.axi_io.ar.addr.expect(0x1000.U)
      println(s"Cycle 1 - State: ${monitorState(dut)}")
      
      // AXI从设备准备好接收地址
      dut.clock.step(3)
      dut.io.axi_io.ar.ready.poke(true.B)
      dut.io.axi_io.r.valid.poke(false.B)
      
      println(s"Cycle 2 - State: ${monitorState(dut)}")
      dut.clock.step(3)
      println(s"Cycle 3 - State: ${monitorState(dut)}")

      // 从设备返回数据
      dut.io.axi_io.r.valid.poke(true.B)
      dut.io.axi_io.r.data.poke(0x12345678.U)
      dut.io.axi_io.r.resp.poke(0.U) // OKAY响应
      // dut.io.axi_io.r.last.poke(true.B)
      
      dut.clock.step()
      println(s"Cycle 4 - State: ${monitorState(dut)}")
      
      // 验证响应
      dut.io.resp.valid.expect(true.B)
      dut.io.resp.bits.data.expect(0x12345678.U)
      dut.io.resp.bits.resp.expect(0.U)
    }
  }

  "AXI4LiteMaster" should "handle single write correctly" in {
    implicit val conf = Config()      
    simulate(new AXI4LiteMaster()) { dut =>
      
      // 初始化
      dut.io.reset.poke(true.B)
      dut.clock.step(3)
      dut.io.reset.poke(false.B)
      
      // 立即执行写操作
      dut.io.req.waddr.poke(0x7000.U)
      dut.io.req.data.poke(0x12345678.U)
      dut.io.req.mask.poke("b0001".U)
      dut.io.req.typ.poke(3.U)
      dut.io.req.wen.poke(true.B)
      dut.io.req.ren.poke(false.B)
      dut.clock.step(2)

      dut.io.axi_io.aw.ready.poke(true.B)
      dut.io.axi_io.w.ready.poke(true.B)
      dut.io.debug.wstate.expect(1.U) // ws_wait_ready
      dut.clock.step(2)

      dut.io.debug.is_write.expect(true.B)
      dut.io.debug.wstate.expect(2.U) // ws_wait_ready
      dut.io.axi_io.w.data.expect(0x12345678.U)
      dut.io.axi_io.aw.size.expect(2.U)
      dut.io.axi_io.w.strb.expect("b0001".U)

      dut.io.axi_io.b.valid.poke(true.B)
      dut.io.axi_io.b.resp.poke(0.U)
      
      println(s"Switch to write - State: ${monitorState(dut)}")
      dut.io.resp.valid.expect(true.B)
      dut.clock.step(2)
      dut.io.debug.wstate.expect(0.U) // ws_wait_ready

      // 验证写响应
      dut.io.resp.valid.expect(false.B)
      dut.io.resp.bits.resp.expect(0.U)
    }
  }




  "AXI4LiteMaster" should "handle multi-cycle read with ARREADY delay" in {
    implicit val conf = Config()       
    simulate(new AXI4LiteMaster()) { dut =>
      
      dut.io.reset.poke(true.B)
      dut.clock.step(3)
      dut.io.reset.poke(false.B)
      
      // 设置读请求
      dut.io.req.raddr.poke(0x2000.U)
      dut.io.req.ren.poke(true.B)
      dut.io.req.wen.poke(false.B)
      dut.io.req.burstlen.poke(3.U) // 4次传输
      dut.io.req.burst.poke(1.U) // INCR模式
      dut.io.req.typ.poke(3.U)
      
      // 初始ARREADY为低，模拟延迟
      dut.io.axi_io.ar.ready.poke(false.B)
      dut.io.axi_io.r.valid.poke(false.B)
      
      println(s"Start - State: ${monitorState(dut)}")
      
      // 等待3个周期后ARREADY变高
      dut.clock.step(3)
      println(s"After 3 cycles delay - State: ${monitorState(dut)}")
      
      dut.io.axi_io.ar.ready.poke(true.B)
      dut.clock.step()
      
      // 模拟返回4个数据beat，每个beat间隔1周期
      for (i <- 0 until 4) {
        dut.io.axi_io.r.valid.poke(true.B)
        dut.io.axi_io.r.data.poke((0x1000 + i * 4).U)
        dut.io.axi_io.r.last.poke(i == 3)
        
        if (i == 3) {
          dut.clock.step()
          dut.io.resp.valid.expect(true.B)
          dut.io.resp.bits.data.expect(0x100c.U)
        }
        
        dut.clock.step()
        println(s"Beat $i - State: ${monitorState(dut)}")
        
        dut.io.axi_io.r.valid.poke(false.B)
      }
    }
  }


  "AXI4LiteMaster" should "handle back-to-back read and write operations" in {
    implicit val conf = Config()       
    simulate(new AXI4LiteMaster()) { dut =>
      
      dut.io.reset.poke(true.B)
      dut.clock.step(3)
      dut.io.reset.poke(false.B)
      
      // 先执行读操作
      dut.io.req.raddr.poke(0x6000.U)
      dut.io.req.ren.poke(true.B)
      dut.io.req.typ.poke(2.U)
      dut.io.req.wen.poke(false.B)
      
      dut.io.axi_io.ar.ready.poke(true.B)
      dut.clock.step(2)
      dut.io.req.ren.poke(false.B)
      dut.io.axi_io.ar.size.expect(1.U)

      dut.io.axi_io.r.valid.poke(true.B)
      dut.io.axi_io.r.data.poke(0xAAA5555.U)
      dut.io.axi_io.r.last.poke(true.B)
      dut.io.axi_io.r.resp.poke(0.U)

      println(s"Start read - State: ${monitorState(dut)}")
      dut.io.resp.valid.expect(true.B)
      dut.io.debug.rstate.expect(2.U)
      dut.io.resp.bits.data.expect(0xAAA5555.U)
      
      dut.clock.step()
      dut.io.axi_io.r.valid.poke(false.B)

      // 验证读响应
      dut.clock.step(2)
      dut.io.debug.rstate.expect(0.U) 

      // 立即执行写操作
      dut.io.req.waddr.poke(0x7000.U)
      dut.io.req.data.poke(0x12345678.U)
      dut.io.req.mask.poke("b1111".U)
      dut.io.req.typ.poke(1.U)
      dut.io.req.wen.poke(true.B)
      dut.io.req.ren.poke(false.B)
      
      dut.io.axi_io.aw.ready.poke(true.B)
      dut.io.axi_io.w.ready.poke(true.B)
      dut.clock.step(2)
      dut.io.axi_io.aw.size.expect(0.U)
      dut.io.axi_io.w.strb.expect("b1111".U)


      dut.io.axi_io.b.valid.poke(true.B)
      dut.io.axi_io.b.resp.poke(0.U)
      dut.io.resp.valid.expect(true.B)

      println(s"Switch to write - State: ${monitorState(dut)}")
      dut.clock.step(2)
      // 验证写响应
      dut.io.resp.valid.expect(false.B)
      dut.io.resp.bits.resp.expect(0.U)
    }
  }

  "AXI4LiteMaster" should "handle error responses correctly" in {
    implicit val conf = Config()       
    simulate(new AXI4LiteMaster()) { dut =>
      
      dut.io.reset.poke(true.B)
      dut.clock.step(3)
      dut.io.reset.poke(false.B)
      
      // 测试读错误
      dut.io.req.raddr.poke(0x8000.U)
      dut.io.req.ren.poke(true.B)
      
      dut.io.axi_io.ar.ready.poke(true.B)
      dut.clock.step(2)
      dut.io.debug.rstate.expect(2.U) // rs_wait_arready
      dut.io.axi_io.r.valid.poke(true.B)
      dut.io.axi_io.r.data.poke(0.U)
      dut.io.axi_io.r.resp.poke(2.U) // SLVERR错误
      dut.io.axi_io.r.last.poke(true.B)
      
      dut.clock.step(2)
      dut.io.resp.valid.expect(true.B)
      dut.io.resp.bits.resp.expect(2.U)
      dut.io.axi_io.r.valid.poke(false.B)

      // 测试写错误
      dut.io.req.waddr.poke(0x9000.U)
      dut.io.req.data.poke(0xFFFFFFF.U)
      dut.io.req.wen.poke(true.B)
      dut.io.req.ren.poke(false.B)
      
      dut.io.axi_io.aw.ready.poke(true.B)
      dut.io.axi_io.w.ready.poke(true.B)
      dut.io.axi_io.b.valid.poke(true.B)
      dut.io.axi_io.b.resp.poke(3.U) // DECERR错误
      
      dut.clock.step(2)
      dut.io.resp.valid.expect(true.B)
      dut.io.resp.bits.resp.expect(3.U)
    }
  }
}

// 运行所有测试的入口对象
object AXI4LiteMasterTestRunner {
  def main(args: Array[String]): Unit = {
    // 这里可以添加具体的测试运行逻辑
    println("AXI4LiteMaster 测试套件")
  }
}