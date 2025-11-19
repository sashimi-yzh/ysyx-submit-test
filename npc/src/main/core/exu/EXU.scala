package npc.core.exu

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._
import npc.bus.axi._
import npc.core.isu._
import npc.core.difftest._
/*
              ___ _____ _   _ _____ ____  ____ ___ ____
             / _ \_   _| | | | ____|  _ \/ ___|_ _/ ___|
            | | | || | | |_| |  _| | |_) \___ \| | |  _
            | |_| || | |  _  | |___|  _ < ___) | | |_| |
             \___/ |_| |_| |_|_____|_| \_\____/___\____|
*/
class EXUIO extends Bundle {
    val dmem = Flipped(new AXI4WithoutClk)
}
class EXU_BJIO extends Bundle {
    val valid = Output(Bool())
    val target = Output(UInt(WORD_LEN.W))
}
class EXUIO_FOR extends Bundle {
    val valid = Output(Bool())
    val processunit = Output(UInt(ProcessUnit.ProcessUnit_Width.W))
    val gpr_we = Output(Bool())
    val gpr_wdata = Output(UInt(WORD_LEN.W))
    val gpr_waddr = Output(UInt(ADDR_LEN.W))
}

class FENCEI_IO extends Bundle{//for icache
    val is_fencei = Output(Bool())
    val fencei_done = Input(Bool())
}
class FENCEI_FLUSH_IO_EXU extends Bundle{
    val fencei_flush_target = Output(UInt(WORD_LEN.W))
}
/*
             ____ ___ ____  _____ ____ ___ ____
            |  _ \_ _|  _ \| ____/ ___|_ _/ ___|
            | |_) | || |_) |  _| \___ \| | |  _
            |  __/| ||  __/| |___ ___) | | |_| |
            |_|  |___|_|   |_____|____/___\____|
*/
class EXUIO_pipe_out extends Bundle{
    val exe2wb_gpr_we = Output(Bool())
    val exe2wb_gpr_wdata = Output(UInt(WORD_LEN.W))
    val exe2wb_gpr_waddr = Output(UInt(ADDR_LEN.W))
    val diff = if(DIFFTEST) Some(new DIFFIO) else None
}
class EXUIO_pipe extends Bundle {
    val in = Flipped(Decoupled(new ISUIO_pipe_out))
    val out = Decoupled(new EXUIO_pipe_out)
}


/*
             _______  ___   _
            | ____\ \/ / | | |
            |  _|  \  /| | | |
            | |___ /  \| |_| |
            |_____/_/\_\\___/
*/
class EXU extends Module {
    val io = IO(new EXUIO)
    val io_bj = IO(new EXU_BJIO)
    val io_pipe = IO(new EXUIO_pipe)
    val io_for = IO(new EXUIO_FOR)
    val io_fencei = IO(new FENCEI_IO)
    val io_fencei_flush_exu = IO(new FENCEI_FLUSH_IO_EXU)

    val processunit = io_pipe.in.bits.is2exe_processunit
    val processtpe = io_pipe.in.bits.is2exe_processtpe
    val bjtpe = io_pipe.in.bits.is2exe_bjtpe
    val rfwe = io_pipe.in.bits.is2exe_rfwe
    val rd_addr = io_pipe.in.bits.is2exe_rd_addr
    val ch1 = io_pipe.in.bits.is2exe_ch1
    val ch2 = io_pipe.in.bits.is2exe_ch2
    val ch3 = io_pipe.in.bits.is2exe_ch3
/*
              ____ ____  ____
             / ___/ ___||  _ \
            | |   \___ \| |_) |
            | |___ ___) |  _ <
             \____|____/|_| \_\
*/
    val csr = Module(new CSR)
    csr.io.in.valid := io_pipe.in.fire && processunit === ProcessUnit.CSR
    csr.io.in.bits.op1 := ch1
    csr.io.in.bits.op2 := ch2
    csr.io.in.bits.processtpe := processtpe
    csr.io.out.ready := io_pipe.out.ready
/*
                _    _    _   _
               / \  | |  | | | |
              / _ \ | |  | | | |
             / ___ \| |__| |_| |
            /_/   \_\_____\___/
*/
    val alu = Module(new ALU)
    alu.io.in.valid := io_pipe.in.fire && (processunit === ProcessUnit.ALU || processunit === ProcessUnit.MOU)
    alu.io.in.bits.op1 := ch1
    alu.io.in.bits.op2 := ch2
    alu.io.in.bits.processtpe := processtpe
    alu.io.in.bits.bjtpe := bjtpe
    alu.io.out.ready := io_pipe.out.ready
/*
             _     ____  _   _
            | |   / ___|| | | |
            | |   \___ \| | | |
            | |___ ___) | |_| |
            |_____|____/ \___/
*/
    val lsu = Module(new LSU)
    lsu.io.in.valid := io_pipe.in.fire && processunit === ProcessUnit.LSU
    lsu.io.in.bits.op1 := ch3
    lsu.io.in.bits.op2 := ch2
    lsu.io.in.bits.processtpe := processtpe
    lsu.io_dmem.dmem <> io.dmem
    lsu.io.out.ready := io_pipe.out.ready
/*
             _____ _____ _   _  ____ _____   ___
            |  ___| ____| \ | |/ ___| ____| |_ _|
            | |_  |  _| |  \| | |   |  _|    | |
            |  _| | |___| |\  | |___| |___ _ | |
            |_|   |_____|_| \_|\____|_____(_)___|
*/
    io_fencei.is_fencei := io_pipe.in.fire && processunit === ProcessUnit.MOU
    val fencei_done = io_fencei.fencei_done





    io_fencei_flush_exu.fencei_flush_target := alu.io.out.bits.alu_out

    io_bj.valid := alu.io_bj.valid | csr.io_bj.valid
    io_bj.target := Mux(alu.io_bj.valid, ch3, Mux(csr.io_bj.valid, csr.io_bj.target, 0.U))

    val exefsh = csr.io.out.valid | alu.io.out.valid | lsu.io.out.valid | fencei_done
    val gpr_wdata = Mux(processunit === ProcessUnit.CSR, csr.io.out.bits.csr_rdata, Mux(processunit === ProcessUnit.LSU, lsu.io.out.bits.gpr_wdata, alu.io.out.bits.alu_out))

    io_pipe.out.bits.exe2wb_gpr_we := rfwe
    io_pipe.out.bits.exe2wb_gpr_wdata := gpr_wdata
    io_pipe.out.bits.exe2wb_gpr_waddr := rd_addr

    io_for.valid := exefsh
    io_for.processunit := processunit
    io_for.gpr_we := rfwe
    io_for.gpr_wdata := gpr_wdata
    io_for.gpr_waddr := rd_addr

/*
             _   _    _    _   _ ____  ____  _   _    _    _  _______
            | | | |  / \  | \ | |  _ \/ ___|| | | |  / \  | |/ / ____|
            | |_| | / _ \ |  \| | | | \___ \| |_| | / _ \ | ' /|  _|
            |  _  |/ ___ \| |\  | |_| |___) |  _  |/ ___ \| . \| |___
            |_| |_/_/   \_\_| \_|____/|____/|_| |_/_/   \_\_|\_\_____|
*/
    //handshake between modules
    val in_ready = RegInit(false.B)
    val out_valid = RegInit(false.B)
    io_pipe.in.ready := in_ready
    io_pipe.out.valid := out_valid

    val s_BeforePreFire :: s_AfterPreFire :: Nil = Enum(2)
    val c_state = RegInit(s_BeforePreFire)
    val n_state = WireDefault(c_state)
    dontTouch(n_state)

    c_state := n_state//first phase

    n_state := MuxLookup(c_state, s_BeforePreFire)(Seq(//second phase
        s_BeforePreFire  ->  Mux(io_pipe.in.fire, s_AfterPreFire, s_BeforePreFire),
        s_AfterPreFire   ->  Mux(io_pipe.out.fire, s_BeforePreFire, s_AfterPreFire)
    ))

    switch(n_state){//third phase
        is(s_BeforePreFire){
            in_ready := csr.io.in.ready && alu.io.in.ready && lsu.io.in.ready
            out_valid := false.B
        }
        is(s_AfterPreFire){
            in_ready := false.B
            out_valid := exefsh
        }
    }




    if(DIFFTEST){
        io_pipe.out.bits.diff.get.pc := io_pipe.in.bits.diff.get.pc
        io_pipe.out.bits.diff.get.inst := io_pipe.in.bits.diff.get.inst
    }


}

