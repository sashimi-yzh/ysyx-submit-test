package npc.core.exu

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._
import npc.bus.axi._

class LSU_DMEMIO extends Bundle {
    val dmem = Flipped(new AXI4WithoutClk)
}

/*LSU handshake in and out*/
class LSUIO_in extends Bundle {
    val op1 = Output(UInt(WORD_LEN.W))
    val op2 = Output(UInt(WORD_LEN.W))
    val processtpe = Output(UInt(ProcessTpe.ProcessTpe_Width.W))
}
class LSUIO_out extends Bundle {
    val gpr_wdata = Output(UInt(WORD_LEN.W))
}
class LSUIO extends Bundle {
    val in = Flipped(Decoupled(new LSUIO_in))
    val out = Decoupled(new LSUIO_out)
}


class LSU extends Module {
    val io_dmem = IO(new LSU_DMEMIO)
    val io = IO(new LSUIO)

    val (processtpe, dmem_addr, dmem_wdata) = (io.in.bits.processtpe, io.in.bits.op1, io.in.bits.op2)

    //disable something in AR R AW W B
    io_dmem.dmem.arid := 0.U
    io_dmem.dmem.arlen := 0.U
    io_dmem.dmem.arburst := 0.U
    io_dmem.dmem.awid := 0.U
    io_dmem.dmem.awlen := 0.U
    io_dmem.dmem.awburst := 0.U
    io_dmem.dmem.wlast := true.B

    val isS = processtpe(3)
    val isL = ~processtpe(3)

    //handshake between modules
    val in_ready = RegInit(false.B)
    val out_valid = RegInit(false.B)
    io.in.ready := in_ready
    io.out.valid := out_valid

    val araddr = RegInit(0.U)
    val arvalid = RegInit(false.B)
    val arsize = RegInit(0.U)
    val rready = RegInit(false.B)
    val awaddr = RegInit(0.U)
    val awvalid = RegInit(false.B)
    val awsize = RegInit(0.U)
    val wdata = RegInit(0.U)
    val wstrb = RegInit(0.U)
    val wvalid = RegInit(false.B)
    val bready = RegInit(false.B)
    io_dmem.dmem.araddr  := araddr
    io_dmem.dmem.arvalid := arvalid
    io_dmem.dmem.arsize := arsize
    io_dmem.dmem.rready  := rready
    io_dmem.dmem.awaddr  := awaddr
    io_dmem.dmem.awvalid := awvalid
    io_dmem.dmem.awsize := awsize
    io_dmem.dmem.wdata   := wdata
    io_dmem.dmem.wstrb   := wstrb
    io_dmem.dmem.wvalid  := wvalid
    io_dmem.dmem.bready  := bready

    val s_BeforePreFire :: s_BeforeAXI_ARorAWW_Fire :: s_BeforeAXI_RorB_Fire :: s_AfterPreFire :: Nil = Enum(4)
    val c_state = RegInit(s_BeforePreFire)
    val n_state = WireDefault(c_state)
    dontTouch(n_state)

    val AXI_ARorAWW_fire = (arvalid & io_dmem.dmem.arready) | ((awvalid & io_dmem.dmem.awready) & (wvalid & io_dmem.dmem.wready))
    val AXI_RorB_fire = (io_dmem.dmem.rvalid & rready) | (io_dmem.dmem.bvalid & bready)

    c_state := n_state//first phase

    n_state := MuxLookup(c_state, s_BeforePreFire)(Seq(//second phase
        s_BeforePreFire             ->  Mux(io.in.fire, s_BeforeAXI_ARorAWW_Fire, s_BeforePreFire),
        s_BeforeAXI_ARorAWW_Fire    ->  Mux(AXI_ARorAWW_fire, s_BeforeAXI_RorB_Fire, s_BeforeAXI_ARorAWW_Fire),
        s_BeforeAXI_RorB_Fire       ->  Mux(AXI_RorB_fire, s_AfterPreFire, s_BeforeAXI_RorB_Fire),
        s_AfterPreFire              ->  Mux(io.out.fire, s_BeforePreFire, s_AfterPreFire)
    ))

    val dmem_rdata = RegInit(0.U)//保存一下读出的数据
    dmem_rdata := Mux(n_state === s_AfterPreFire, io_dmem.dmem.rdata, dmem_rdata)

    val arsize_func = processtpe(1, 0)
    val awsize_func = processtpe(1, 0)
    araddr := dmem_addr
    awaddr := dmem_addr

    switch(n_state){//third phase
        is(s_BeforePreFire){
            //between modules
            in_ready := true.B
            out_valid := false.B
            //AXI
            arvalid := false.B
            rready := false.B
            awvalid := false.B
            wvalid := false.B
            bready := false.B
            arsize := 2.U
            awsize := 2.U
        }
        is(s_BeforeAXI_ARorAWW_Fire){
            //between modules
            in_ready := false.B
            out_valid := false.B
            //AXI
            arvalid := isL
            arsize := arsize_func
            rready := false.B
            awvalid := isS
            awsize := awsize_func
            wvalid := isS
            bready := false.B
        }
        is(s_BeforeAXI_RorB_Fire){
            //between modules
            in_ready := false.B
            out_valid := false.B
            //AXI
            arvalid := false.B
            arsize := arsize_func
            rready := isL
            awvalid := false.B
            awsize := awsize_func
            wvalid := false.B
            bready := isS
        }
        is(s_AfterPreFire){
            //between modules
            in_ready := false.B
            out_valid := true.B
            //AXI
            arvalid := false.B
            rready := false.B
            awvalid := false.B
            wvalid := false.B
            bready := false.B
            arsize := 2.U
            awsize := 2.U
        }
    }

    val shift_op = dmem_addr(1, 0) << 3.U

    /*STORE INST*/
    wdata := dmem_wdata << shift_op
    wstrb := MuxLookup(processtpe(1, 0), "b00000001".U)(Seq(
      "b00".U -> "b00000001".U,
      "b01".U -> "b00000011".U,
      "b10".U -> "b00001111".U
    )) << dmem_addr(1,0)

    /*LOAD INST*/
    val shift_rdata = dmem_rdata >> shift_op
    val dmem_rdata_processed = MuxLookup(processtpe(2, 0), shift_rdata)(Seq(
        "b000".U -> Cat(Fill(24, shift_rdata(7)), shift_rdata(7,0)),
        "b001".U -> Cat(Fill(16, shift_rdata(15)), shift_rdata(15,0)),
        "b010".U -> shift_rdata,
        "b100".U -> Cat(Fill(24, 0.U), shift_rdata(7,0)),
        "b101".U -> Cat(Fill(16, 0.U), shift_rdata(15,0))
    ))
    val wb_data = dmem_rdata_processed


    //connection
    io.out.bits.gpr_wdata := wb_data
}

