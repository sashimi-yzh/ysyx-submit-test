package npc.core.idu

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._
import npc.core.ifu._
import chisel3.util.experimental.decode._
import npc.core.difftest._
/*
              ___ _____ _   _ _____ ____  ____ ___ ____
             / _ \_   _| | | | ____|  _ \/ ___|_ _/ ___|
            | | | || | | |_| |  _| | |_) \___ \| | |  _
            | |_| || | |  _  | |___|  _ < ___) | | |_| |
             \___/ |_| |_| |_|_____|_| \_\____/___\____|
*/
class FLUSHIO extends Bundle{
    val flush_flg = Input(Bool())
}
/*
             ____ ___ ____  _____ ____ ___ ____
            |  _ \_ _|  _ \| ____/ ___|_ _/ ___|
            | |_) | || |_) |  _| \___ \| | |  _
            |  __/| ||  __/| |___ ___) | | |_| |
            |_|  |___|_|   |_____|____/___\____|
*/
class IDUIO_pipe_out extends Bundle{
    val id2is_processunit = Output(UInt(ProcessUnit.ProcessUnit_Width.W))
    val id2is_processtpe = Output(UInt(ProcessTpe.ProcessTpe_Width.W))
    val id2is_bjtpe = Output(UInt(BJTpe.BJTpe_Width.W))
    val id2is_rfwe = Output(UInt(RFwe.RFwe_Width.W))
    val id2is_rd_addr = Output(UInt(ADDR_LEN.W))
    val id2is_ch1tpe = Output(UInt(CH1Tpe.CH1Tpe_Width.W))
    val id2is_ch2tpe = Output(UInt(CH2Tpe.CH2Tpe_Width.W))
    val id2is_rs1_addr = Output(UInt(ADDR_LEN.W))
    val id2is_rs2_addr = Output(UInt(ADDR_LEN.W))
    val id2is_reg_pc = Output(UInt(WORD_LEN.W))
    val id2is_imm = Output(UInt(WORD_LEN.W))
    val id2is_csr_addr = Output(UInt(CSR_ADDR_LEN.W))
    val diff = if(DIFFTEST) Some(new DIFFIO) else None
}
class IDUIO_pipe extends Bundle{
    val in = Flipped(Decoupled(new IFUIO_pipe_out))
    val out = Decoupled(new IDUIO_pipe_out)
}
/*
             ___ ____  _   _
            |_ _|  _ \| | | |
             | || | | | | | |
             | || |_| | |_| |
            |___|____/ \___/
*/
class IDU extends Module{
    val io_pipe = IO(new IDUIO_pipe)
    val io_flush = IO(new FLUSHIO)
    val inst = io_pipe.in.bits.if2id_inst
    val reg_pc = io_pipe.in.bits.if2id_reg_pc
/*
             ____  _____ ____ ___  ____  _____ ____
            |  _ \| ____/ ___/ _ \|  _ \| ____|  _ \
            | | | |  _|| |  | | | | | | |  _| | |_) |
            | |_| | |__| |__| |_| | |_| | |___|  _ <
            |____/|_____\____\___/|____/|_____|_| \_\
*/
    val decodeTable = new DecodeTable(instList, Seq(MyProcessUnit, MyProcessTpe, MyBJTpe, MyCH1Tpe, MyCH2Tpe, MyRFwe, MyIMMTpe))
    val decodeBundle = decodeTable.decode(inst)
    // when(io_pipe.out.valid) {
    //     printf(p"decode=${decodeBundle.toPrintable}\n")
    // }

    val immtpe = decodeBundle(MyIMMTpe)
    val imm_i = inst(31, 20).asSInt
    val imm_s = Cat(inst(31, 25), inst(11, 7)).asSInt
    val imm_b = Cat(inst(31), inst(7), inst(30, 25), inst(11, 8), 0.U(1.W)).asSInt
    val imm_j = Cat(inst(31), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W)).asSInt
    val imm_u = Cat(inst(31, 12), 0.U(12.W)).asSInt
    val imm = MuxLookup(immtpe, 0.S)(Seq(
        IMMTpe.IMM_TYPE_I -> imm_i,
        IMMTpe.IMM_TYPE_U -> imm_u,
        IMMTpe.IMM_TYPE_J -> imm_j,
        IMMTpe.IMM_TYPE_S -> imm_s,
        IMMTpe.IMM_TYPE_B -> imm_b
    )).asUInt
    dontTouch(immtpe)
    dontTouch(imm_i)
    dontTouch(imm_s)
    dontTouch(imm_b)
    dontTouch(imm_j)
    dontTouch(imm_u)

    val opcode = inst(6, 0)

    //pipeline
    io_pipe.out.bits.id2is_processunit := decodeBundle(MyProcessUnit)
    io_pipe.out.bits.id2is_processtpe := decodeBundle(MyProcessTpe)
    io_pipe.out.bits.id2is_bjtpe := decodeBundle(MyBJTpe)
    io_pipe.out.bits.id2is_rfwe := decodeBundle(MyRFwe)
    io_pipe.out.bits.id2is_rd_addr := Mux(io_pipe.out.bits.id2is_rfwe === RFwe.RFwe_y, inst(11, 7), 0.U)
    io_pipe.out.bits.id2is_ch1tpe := decodeBundle(MyCH1Tpe)
    io_pipe.out.bits.id2is_ch2tpe := decodeBundle(MyCH2Tpe)
    io_pipe.out.bits.id2is_rs1_addr := Mux(opcode === "b0110111".U, 0.U, inst(19, 15))
    io_pipe.out.bits.id2is_rs2_addr := inst(24, 20)
    io_pipe.out.bits.id2is_reg_pc := reg_pc
    io_pipe.out.bits.id2is_imm := imm
    io_pipe.out.bits.id2is_csr_addr := inst(31, 20)


    class ysyx_24080032_Ebreak extends BlackBox with HasBlackBoxInline{
        val io = IO(new Bundle{
            val inst = Input(UInt(WORD_LEN.W))
            val isEbreak = Output(Bool())
        })
        setInline("ysyx_24080032_Ebreak.sv",
        """module ysyx_24080032_Ebreak(
          |     input [31:0] inst,
          |     output isEbreak
          |);
          |
          |
          |assign isEbreak = (inst == 32'h00100073);
          |
          |endmodule
        """.stripMargin)
    }

    val ebreak = Module(new ysyx_24080032_Ebreak)
    ebreak.io.inst := inst
    val isEbreak = ebreak.io.isEbreak
    dontTouch(isEbreak)


















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
    io_pipe.out.valid := out_valid && ~io_flush.flush_flg

    val s_BeforePreFire :: s_AfterPreFire :: Nil = Enum(2)
    val c_state = RegInit(s_BeforePreFire)
    val n_state = WireDefault(c_state)
    dontTouch(n_state)

    c_state := n_state//first phase

    when(io_flush.flush_flg){
        n_state := s_BeforePreFire
    }.otherwise{
        n_state := MuxLookup(c_state, s_BeforePreFire)(Seq(//second phase
            s_BeforePreFire  ->  Mux(io_pipe.in.fire, s_AfterPreFire, s_BeforePreFire),
            s_AfterPreFire   ->  Mux(io_pipe.out.fire, s_BeforePreFire, s_AfterPreFire)
        ))
    }

    switch(n_state){//third phase
        is(s_BeforePreFire){
            in_ready := true.B
            out_valid := false.B
        }
        is(s_AfterPreFire){
            in_ready := false.B
            out_valid := ~io_flush.flush_flg
        }
    }





    if(DIFFTEST){
        io_pipe.out.bits.diff.get.pc := io_pipe.in.bits.if2id_reg_pc
        io_pipe.out.bits.diff.get.inst := io_pipe.in.bits.if2id_inst
    }
}

