package axi4
import chisel3._
import chisel3.util._

object AXI4IO {

  object RResp {
    val WIDTH = 2
    private def _v(x: Int) = x.U(WIDTH.W)

    val OKAY   = _v(0)
    val EXOKAY = _v(1)
    val SLVERR = _v(2)
    val DECERR = _v(3)
  }
  object BResp {
    val WIDTH = 2
    private def _v(x: Int) = x.U(WIDTH.W)

    val OKAY   = _v(0)
    val EXOKAY = _v(1)
    val SLVERR = _v(2)
    val DECERR = _v(3)
  }

  object BurstType {
    val FIXED   = 0.U(2.W)
    val INCR    = 1.U(2.W)
    val WRAP    = 2.U(2.W)
  }
  object SizeType {
    val BYTE      = 0.U(3.W) // 1 byte
    val HALF_WORD = 1.U(3.W) // 2 bytes
    val WORD      = 2.U(3.W) // 4 bytes
  }

  // Master interface
  class Imp(val ADDR_WIDTH: Int, val DATA_WIDTH: Int) extends Bundle {

    def AddrT = UInt(ADDR_WIDTH.W)
    def DataT = UInt(DATA_WIDTH.W)

    def StrbT = UInt((DATA_WIDTH / 8).W)

    // aw channel

    val awready = Input(Bool())
    val awvalid = Output(Bool())
    val awaddr  = Output(AddrT)
    val awid    = Output(UInt(4.W))
    val awlen   = Output(UInt(8.W))
    val awsize  = Output(UInt(3.W))
    val awburst = Output(UInt(2.W))

    // w channel

    val wready = Input(Bool())
    val wvalid = Output(Bool())
    val wdata  = Output(DataT)
    val wstrb  = Output(StrbT)
    val wlast  = Output(Bool())

    // b channel

    val bready = Output(Bool())
    val bvalid = Input(Bool())
    val bresp  = Input(UInt(BResp.WIDTH.W))
    val bid    = Input(UInt(4.W))

    // ar channel

    val arready = Input(Bool())
    val arvalid = Output(Bool())
    val araddr  = Output(AddrT)
    val arid    = Output(UInt(4.W))
    val arlen   = Output(UInt(8.W))
    val arsize  = Output(UInt(3.W))
    val arburst = Output(UInt(2.W))

    // r channel

    val rready = Output(Bool())
    val rvalid = Input(Bool())
    val rdata  = Input(DataT)
    val rresp  = Input(UInt(RResp.WIDTH.W))
    val rlast  = Input(Bool())
    val rid    = Input(UInt(4.W))
  }

  def noShakeConnectAW(master: Imp, slave: Imp) = {
    slave.awaddr  := master.awaddr
    slave.awid    := master.awid
    slave.awlen   := master.awlen
    slave.awsize  := master.awsize
    slave.awburst := master.awburst
  }
  def noShakeConnectW(master: Imp, slave: Imp)  = {
    slave.wdata := master.wdata
    slave.wstrb := master.wstrb
    slave.wlast := master.wlast
  }
  def noShakeConnectB(master: Imp, slave: Imp)  = {
    master.bresp <> slave.bresp
    master.bid   <> slave.bid
  }

  def connectAW(master: Imp, slave: Imp) = {
    noShakeConnectAW(master, slave)
    slave.awvalid  := master.awvalid
    master.awready := slave.awready
  }
  def connectW(master: Imp, slave: Imp)  = {
    noShakeConnectW(master, slave)
    slave.wvalid  := master.wvalid
    master.wready := slave.wready
  }
  def connectB(master: Imp, slave: Imp)  = {
    noShakeConnectB(master, slave)
    master.bvalid := slave.bvalid
    slave.bready  := master.bready
  }

  def noShakeConnectAR(master: Imp, slave: Imp) = {
    slave.araddr  := master.araddr
    slave.arid    := master.arid
    slave.arlen   := master.arlen
    slave.arsize  := master.arsize
    slave.arburst := master.arburst
  }

  def noShakeConnectR(master: Imp, slave: Imp) = {
    master.rdata <> slave.rdata
    master.rresp <> slave.rresp
    master.rlast <> slave.rlast
    master.rid   <> slave.rid
  }

  def newMaster(addrWidth: Int = 32, dataWidth: Int = 32) = new Imp(addrWidth, dataWidth)
  def newSlave(addrWidth:  Int = 32, dataWidth: Int = 32) = Flipped(newMaster(addrWidth, dataWidth))

  class MasterT extends Imp(32, 32) {
    def dontCareAW() = {
      awvalid := false.B
      awaddr  := 0.U
      awid    := 0.U
      awlen   := 0.U
      awsize  := 0.U
      awburst := 0.U
    }
    def dontCareW()  = {
      wvalid := false.B
      wdata  := 0.U
      wstrb  := 0.U
      wlast  := false.B
    }
    def dontCareB()  = {
      bready := false.B
    }
    def dontCareNonLiteAR() = {
      arid    := 0.U
      arlen   := 0.U
      arsize  := 2.U
      arburst := 1.U
    }
    def dontCareNonLiteAW() = {
      awid    := 0.U
      awlen   := 0.U
      awsize  := 2.U
      awburst := 1.U
    }
    def dontCareNonLiteW() = {
      wlast  := false.B
    }

    def dontCareAR() = {
      arvalid := false.B
      araddr  := 0.U
      arid    := 0.U
      arlen   := 0.U
      arsize  := 0.U
      arburst := 0.U
    }
    def dontCareR()  = {
      rready := false.B
    }

  }
  class SlaveT extends Imp(32, 32) {
    def dontCareAW() = {
      awready := false.B
    }
    def dontCareW()  = {
      wready := false.B
    }
    def dontCareB()  = {
      bvalid := false.B
      bresp  := 0.U
      bid    := 0.U
    }
    def dontCareAR() = {
      arready := false.B
    }
    def dontCareR()  = {
      rvalid := false.B
      rdata  := 0.U
      rresp  := 0.U
      rlast  := false.B
      rid    := 0.U
    }

    def dontCareNonLiteR() = {
      rid    := 0.U
      rlast  := false.B
    }
    def dontCareNonLiteB() = {
      bid    := 0.U
    }
  }

  def Master = new MasterT
  def Slave  = Flipped(new SlaveT)

  def connectMasterSlave(master: MasterT, slave: SlaveT) = {
    master <> slave
  }

  def transformSlaveToMasterValidIf(cond: Bool)(master: MasterT, slave: SlaveT) = {
    master.awvalid := Mux(cond, slave.awvalid, false.B)
    master.wvalid  := Mux(cond, slave.wvalid, false.B)
    master.bready  := Mux(cond, slave.bready, false.B)
    master.arvalid := Mux(cond, slave.arvalid, false.B)
    master.rready  := Mux(cond, slave.rready, false.B)

    slave.awready := Mux(cond, master.awready, false.B)
    slave.arready := Mux(cond, master.arready, false.B)
    slave.wready  := Mux(cond, master.wready, false.B)
    slave.bvalid  := Mux(cond, master.bvalid, false.B)
    slave.rvalid  := Mux(cond, master.rvalid, false.B)

    noShakeConnectAW(slave, master)
    noShakeConnectW(slave, master)
    noShakeConnectB(slave, master)
    noShakeConnectAR(slave, master)
    noShakeConnectR(slave, master)
  }

}

object AXI4LiteIO_ {

  def BResp = AXI4IO.BResp
  def RResp = AXI4IO.RResp

  class Imp(val ADDR_WIDTH: Int, val DATA_WIDTH: Int) extends Bundle {

    def AddrT = UInt(ADDR_WIDTH.W)
    def DataT = UInt(DATA_WIDTH.W)

    def StrbT = UInt((DATA_WIDTH / 8).W)

    // addr read channel
    val ar = Decoupled(AddrT)
    // read data channel
    val r  = Flipped(Decoupled(new Bundle {
      val data = DataT
      val resp = UInt(RResp.WIDTH.W)
    }))

    // addr write channel
    val aw = Decoupled(AddrT)

    // write data channel
    val w = Decoupled(new Bundle {
      val data = DataT
      val strb = StrbT
    })

    // backward channel
    val b = Flipped(Decoupled(UInt(BResp.WIDTH.W)))
  }

  def newTX(addrWidth: Int = 32, dataWidth: Int = 32) = new Imp(addrWidth, dataWidth)
  def newRX(addrWidth: Int = 32, dataWidth: Int = 32) = Flipped(newTX(addrWidth, dataWidth))

  // for default
  def TX = newTX()
  def RX = newRX()
}
