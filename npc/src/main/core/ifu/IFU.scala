package npc.core.ifu

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._
import npc.core.wbu._
import npc.core.exu._
import npc.core.icache._
import npc.bus.axi._

/*
              ___ _____ _   _ _____ ____  ____ ___ ____
             / _ \_   _| | | | ____|  _ \/ ___|_ _/ ___|
            | | | || | | |_| |  _| | |_) \___ \| | |  _
            | |_| || | |  _  | |___|  _ < ___) | | |_| |
             \___/ |_| |_| |_|_____|_| \_\____/___\____|
*/
class IFUIO extends Bundle {
    val imem = Flipped(new AXI4WithoutClk)
}
class FLUSHIO extends Bundle{
    val flush_flg = Output(Bool())//control hazard flush for idu isu
}
/*
             ____ ___ ____  _____ ____ ___ ____
            |  _ \_ _|  _ \| ____/ ___|_ _/ ___|
            | |_) | || |_) |  _| \___ \| | |  _
            |  __/| ||  __/| |___ ___) | | |_| |
            |_|  |___|_|   |_____|____/___\____|
*/
class IFUIO_pipe_in extends Bundle{
}
class IFUIO_pipe_out extends Bundle{
    val if2id_reg_pc = Output(UInt(WORD_LEN.W)) //pipe
    val if2id_inst = Output(UInt(WORD_LEN.W)) //pipe
}
class IFUIO_pipe extends Bundle{
    val in = Flipped(Decoupled(new IFUIO_pipe_in))
    val out = Decoupled(new IFUIO_pipe_out)
}
/*
             ___ _____ _   _
            |_ _|  ___| | | |
             | || |_  | | | |
             | ||  _| | |_| |
            |___|_|    \___/
*/
class IFU extends Module {
    val io = IO(new IFUIO)
    val io_pipe = IO(new IFUIO_pipe)
    val io_bj = IO(Flipped(new EXU_BJIO))
    val io_flush = IO(new FLUSHIO)
    val io_fencei_flush_exu = IO(Flipped(new FENCEI_FLUSH_IO_EXU))
    val io_fencei_flush_icache = IO(Flipped(new FENCEI_FLUSH_IO_ICACHE))

    dontTouch(io_pipe)

    val pc_next = Wire(UInt(WORD_LEN.W))
    dontTouch(pc_next)

    //flush
    io_flush.flush_flg := io_bj.valid | io_fencei_flush_icache.fencing
    val fencei_flush = io_fencei_flush_icache.fencing
    val reg_pc = RegEnable(pc_next, START_ADDR, io_pipe.out.fire || io_bj.valid || fencei_flush)

    val bj_flush = io_bj.valid && (io_bj.target =/= reg_pc)
    val flush_flg = bj_flush || fencei_flush

    //main process
    val pc_plus4 = reg_pc + 4.U(WORD_LEN.W)

    pc_next := Mux(io_bj.valid, io_bj.target, Mux(fencei_flush, io_fencei_flush_exu.fencei_flush_target, pc_plus4))

    io_pipe.out.bits.if2id_reg_pc := reg_pc
    io_pipe.out.bits.if2id_inst := io.imem.rdata

    //connect
    io.imem.araddr := Mux(bj_flush, io_bj.target, Mux(fencei_flush, io_fencei_flush_exu.fencei_flush_target, reg_pc))



/*
             _   _    _    _   _ ____  ____  _   _    _    _  _______
            | | | |  / \  | \ | |  _ \/ ___|| | | |  / \  | |/ / ____|
            | |_| | / _ \ |  \| | | | \___ \| |_| | / _ \ | ' /|  _|
            |  _  |/ ___ \| |\  | |_| |___) |  _  |/ ___ \| . \| |___
            |_| |_/_/   \_\_| \_|____/|____/|_| |_/_/   \_\_|\_\_____|
*/
    //disable AW W B and something in AR R
    io.imem.arid := 0.U
    io.imem.arlen := 0.U
    io.imem.arburst := 0.U
    io.imem.awaddr := 0.U
    io.imem.awvalid := false.B
    io.imem.awid := 0.U
    io.imem.awlen := 0.U
    io.imem.awsize := 0.U
    io.imem.awburst := 0.U
    io.imem.wdata := 0.U
    io.imem.wstrb := 0.U
    io.imem.wvalid := false.B
    io.imem.wlast := false.B
    io.imem.bready := false.B

    //handshake between modules && handshake between Imem
    val in_ready = RegInit(false.B)
    val out_valid = RegInit(false.B)
    io_pipe.in.ready := in_ready
    io_pipe.out.valid := out_valid && ~flush_flg

    val arvalid = RegInit(false.B)
    val rready = RegInit(false.B)
    io.imem.arvalid := arvalid
    io.imem.rready := rready
    io.imem.arsize := 2.U

    val s_BeforePreFire :: s_BeforeAXI_AR_Fire :: s_BeforeAXI_R_Fire :: s_AfterPreFire :: s_Flush :: Nil = Enum(5)
    val c_state = RegInit(s_BeforeAXI_AR_Fire)
    val n_state = WireDefault(c_state)
    dontTouch(n_state)

    val AXI_AR_fire = arvalid & io.imem.arready
    val AXI_R_fire = io.imem.rvalid & rready

    val start =  io_pipe.in.valid && io.imem.arready && ~flush_flg//only work at in.valid and imem ready and not flush

    val R_while_flush = AXI_R_fire & flush_flg
    val flush_before_R = ~AXI_R_fire & flush_flg
    val fetch_normal = AXI_R_fire & ~flush_flg

    c_state := n_state//first phase

    n_state := MuxLookup(c_state, s_BeforePreFire)(Seq(//second phase
        s_BeforePreFire       ->  Mux(start, s_BeforeAXI_AR_Fire, s_BeforePreFire),
        s_BeforeAXI_AR_Fire   ->  Mux(AXI_AR_fire, s_BeforeAXI_R_Fire, s_BeforeAXI_AR_Fire),
        s_BeforeAXI_R_Fire    ->  Mux(fetch_normal, s_AfterPreFire, Mux(flush_before_R, s_Flush, Mux(R_while_flush, s_BeforePreFire, s_BeforeAXI_R_Fire))),
        s_AfterPreFire        ->  Mux(io_pipe.out.fire || flush_flg, s_BeforePreFire, s_AfterPreFire),
        s_Flush               ->  Mux(AXI_R_fire, s_BeforePreFire, s_Flush)
    ))

    switch(n_state){//third phase
        is(s_BeforePreFire){
            //between modules
            in_ready := true.B
            out_valid := false.B
            //AXI
            arvalid := false.B
            rready := false.B
        }
        is(s_BeforeAXI_AR_Fire){
            //between modules
            in_ready := false.B
            out_valid := false.B
            //AXI
            arvalid := true.B
            rready := false.B
        }
        is(s_BeforeAXI_R_Fire){
            //between modules
            in_ready := false.B
            out_valid := false.B
            //AXI
            arvalid := false.B
            rready := true.B
        }
        is(s_AfterPreFire){
            //between modules
            in_ready := false.B
            out_valid := true.B
            //AXI
            arvalid := false.B
            rready := false.B
        }
        is(s_Flush){
            //between modules
            in_ready := false.B
            out_valid := false.B
            //AXI
            arvalid := false.B
            rready := true.B
        }
    }
}

