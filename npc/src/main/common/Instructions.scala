package npc.common

import chisel3._
import chisel3.util._
import chisel3.util.experimental.decode._
import org.chipsalliance.rvdecoderdb

object Instructions{

    val instTable: Iterable[rvdecoderdb.Instruction] = rvdecoderdb.instructions(os.pwd / "rvdecoderdb" / "rvdecoderdbtest" / "jvm" / "riscv-opcodes")

    case class Insn (val inst: rvdecoderdb.Instruction) extends DecodePattern {
        override def bitPat: BitPat = BitPat("b" + inst.encoding.toString())
    }

    object Insn {
        implicit class addMethodsToInsn(i: Insn) {
            def hasArg(arg: String) = i.inst.args.map(_.name).contains(arg)
        }
    }

    val instSet_more = Set("rv64_i")
    val ex_rv64_i = Set("lwu", "ld", "sd", "addiw", "slliw", "srliw", "sraiw", "addw"
    , "subw", "sllw", "srlw", "sraw")
    val patternSeq_more = instTable
        .filter(_.pseudoFrom.isEmpty)
        .filter(inst => instSet_more.contains(inst.instructionSet.name))
        .filter(inst => !ex_rv64_i.contains(inst.name))
        .map(Insn(_))
        .toSeq
    val instSets = Set("rv_i", "rv_zicsr", "rv_system", "rv_zifencei")
    val ex_rv_i = Set("fence")
    val ex_rv_zicsr = Set("csrrc", "csrrwi", "csrrsi", "csrrci")
    val ex_rv_system = Set("wfi")
    val patternSeq = instTable
        .filter(_.pseudoFrom.isEmpty) //伪指令不考虑
        .filter(inst => instSets.contains(inst.instructionSet.name))
        .filter(inst => !ex_rv_i.contains(inst.name))
        .filter(inst => !ex_rv_zicsr.contains(inst.name))
        .filter(inst => !ex_rv_system.contains(inst.name))
        .map(Insn(_))
        .toSeq
    val instList = patternSeq ++ patternSeq_more


    trait InstCateg{
        val aluInst_add = Set("add", "addi", "lui", "auipc")
        val aluInst_sub = Set("sub")
        val aluInst_and = Set("and", "andi")
        val aluInst_or  = Set("or", "ori")
        val aluInst_xor = Set("xor", "xori")
        val aluInst_sll = Set("sll", "slli")
        val aluInst_srl = Set("srl", "srli")
        val aluInst_sra = Set("sra", "srai")
        val aluInst_comps = Set("slt", "slti")
        val aluInst_compu= Set("sltu", "sltiu")
        val aluInst = Set(
            aluInst_add ++ aluInst_sub ++ aluInst_and ++ aluInst_or ++ aluInst_xor ++ aluInst_sll ++ aluInst_srl ++ aluInst_sra ++ aluInst_comps ++ aluInst_compu
        ).flatten

        val csrInst_w  = Set("csrrw")
        val csrInst_s  = Set("csrrs")
        val csrInst_mret = Set("mret")
        val csrInst_ecall= Set("ecall")
        val csrInst = Set(
            csrInst_w ++ csrInst_s ++ csrInst_mret ++ csrInst_ecall
        ).flatten

        val lsuInst_l = Set("lb", "lh", "lw", "lbu", "lhu")
        val lsuInst_s= Set("sb", "sh", "sw")
        val lsuInst = Set(
            lsuInst_l ++ lsuInst_s
        ).flatten

        val bjInst_j =   Set("jal", "jalr")
        val bjInst_beq =  Set("beq")
        val bjInst_bne =  Set("bne")
        val bjInst_blt = Set("blt")
        val bjInst_bltu = Set("bltu")
        val bjInst_bge = Set("bge")
        val bjInst_bgeu = Set("bgeu")
        val bjInst =Set(
            bjInst_j ++ bjInst_beq ++ bjInst_bne ++ bjInst_blt ++ bjInst_bltu ++ bjInst_bge ++ bjInst_bgeu
        ).flatten

        val mouInst_fence_i = Set("fence.i")
        val mouInst = Set(
            mouInst_fence_i
        ).flatten
    }

    object MyProcessUnit extends DecodeField[Insn, UInt] with InstCateg{
        def name = "processunit"
        def chiselType = UInt(ProcessUnit.ProcessUnit_Width.W)
        def genTable(i: Insn): BitPat = i.inst.name match {
            case name if aluInst.contains(name) || bjInst.contains(name) => BitPat(ProcessUnit.ALU)
            case name if csrInst.contains(name) => BitPat(ProcessUnit.CSR)
            case name if lsuInst.contains(name) => BitPat(ProcessUnit.LSU)
            case name if mouInst.contains(name) => BitPat(ProcessUnit.MOU)
            case _ => BitPat(ProcessUnit.ALU)
        }
    }

    object MyProcessTpe extends DecodeField[Insn, UInt] with InstCateg{
        def name = "processtpe"
        def chiselType = UInt(ProcessTpe.ProcessTpe_Width.W)
        def genTable(i: Insn): BitPat = i.inst.name match {
            case name if aluInst.contains(name) => genALUTpeTable(i)
            case name if csrInst.contains(name) => genCSRTpeTable(i)
            case name if lsuInst.contains(name) => genLSUTpeTable(i)
            case _ => genALUTpeTable(i)
        }
            def genALUTpeTable(i: Insn): BitPat = i.inst.name match {
                case name if aluInst_add.contains(name)                                             => BitPat(ProcessTpe.ALU.ALU_ADD)
                case name if aluInst_sub.contains(name) || (name == "beq") || (name == "bne")       => BitPat(ProcessTpe.ALU.ALU_SUB)
                case name if aluInst_and.contains(name)                                             => BitPat(ProcessTpe.ALU.ALU_AND)
                case name if aluInst_or.contains(name)                                              => BitPat(ProcessTpe.ALU.ALU_OR)
                case name if aluInst_xor.contains(name)                                             => BitPat(ProcessTpe.ALU.ALU_XOR)
                case name if aluInst_sll.contains(name)                                             => BitPat(ProcessTpe.ALU.ALU_SLL)
                case name if aluInst_srl.contains(name)                                             => BitPat(ProcessTpe.ALU.ALU_SRL)
                case name if aluInst_sra.contains(name)                                             => BitPat(ProcessTpe.ALU.ALU_SRA)
                case name if aluInst_comps.contains(name) || (name == "blt") || (name == "bge")     => BitPat(ProcessTpe.ALU.ALU_COMPS)
                case name if aluInst_compu.contains(name) || (name == "bltu") || (name == "bgeu")   => BitPat(ProcessTpe.ALU.ALU_COMPU)
                case _ => BitPat(ProcessTpe.ALU.ALU_ADD)
            }
            def genCSRTpeTable(i: Insn): BitPat = i.inst.name match {
                case name if csrInst_s.contains(name)     => BitPat(ProcessTpe.CSR.CSR_S)
                case name if csrInst_w.contains(name)     => BitPat(ProcessTpe.CSR.CSR_W)
                case name if csrInst_mret.contains(name)  => BitPat(ProcessTpe.CSR.CSR_MRET)
                case name if csrInst_ecall.contains(name) => BitPat(ProcessTpe.CSR.CSR_ECALL)
                case _ => BitPat(ProcessTpe.CSR.CSR_S)
            }
            def genLSUTpeTable(i: Insn): BitPat = i.inst.name match {
                case "lb"   => BitPat(ProcessTpe.LSU.LSU_LB)
                case "lh"   => BitPat(ProcessTpe.LSU.LSU_LH)
                case "lw"   => BitPat(ProcessTpe.LSU.LSU_LW)
                case "lbu"  => BitPat(ProcessTpe.LSU.LSU_LBU)
                case "lhu"  => BitPat(ProcessTpe.LSU.LSU_LHU)
                case "sb"   => BitPat(ProcessTpe.LSU.LSU_SB)
                case "sh"   => BitPat(ProcessTpe.LSU.LSU_SH)
                case "sw"   => BitPat(ProcessTpe.LSU.LSU_SW)
                case _ => BitPat(ProcessTpe.LSU.LSU_LB)
            }
    }

    object MyBJTpe extends DecodeField[Insn, UInt] with InstCateg{
        def name = "bjtpe"
        def chiselType = UInt(BJTpe.BJTpe_Width.W)
        def genTable(i: Insn): BitPat = i.inst.name match {
            case "jal"             => BitPat(BJTpe.BJ_J)
            case "jalr"            => BitPat(BJTpe.BJ_JR)
            case "beq"             => BitPat(BJTpe.BJ_BEQ)
            case "bne"             => BitPat(BJTpe.BJ_BNE)
            case "bltu"            => BitPat(BJTpe.BJ_BLTU)
            case "blt"             => BitPat(BJTpe.BJ_BLT)
            case "bgeu"            => BitPat(BJTpe.BJ_BGEU)
            case "bge"             => BitPat(BJTpe.BJ_BGE)
            case _ => BitPat(BJTpe.BJ_X)
        }
    }

    object MyCH1Tpe extends DecodeField[Insn, UInt] with InstCateg{
        def name = "ch1tpe"
        def chiselType = UInt(CH1Tpe.CH1Tpe_Width.W)
        def genTable(i: Insn): BitPat = {
            if(i.hasArg("rs1") && i.inst.name != "jalr" && i.inst.name != "fence.i") BitPat(CH1Tpe.CH1Tpe_RS1)
            else if(i.inst.name == "lui") BitPat(CH1Tpe.CH1Tpe_RS1)
            else BitPat(CH1Tpe.CH1Tpe_PC)
        }
    }

    object MyCH2Tpe extends DecodeField[Insn, UInt] with InstCateg{
        def name = "ch2tpe"
        def chiselType = UInt(CH2Tpe.CH2Tpe_Width.W)
        def genTable(i: Insn): BitPat = {
            if(i.hasArg("rs2")) BitPat(CH2Tpe.CH2Tpe_RS2)
            else if(i.hasArg("csr")) BitPat(CH2Tpe.CH2Tpe_CSR_ADDR)
            else if(i.inst.name == "jal" || i.inst.name == "jalr" || i.inst.name == "fence.i") BitPat(CH2Tpe.CH2Tpe_4)
            else BitPat(CH2Tpe.CH2Tpe_IMM)
        }
    }

    object MyRFwe extends DecodeField[Insn, UInt] with InstCateg{
        def name = "rfwe"
        def chiselType = UInt(RFwe.RFwe_Width.W)
        def genTable(i: Insn): BitPat = {
            if(i.hasArg("rd")) BitPat(RFwe.RFwe_y)
            else BitPat(RFwe.RFwe_n)
        }
    }

    object MyIMMTpe extends DecodeField[Insn, UInt] with InstCateg{
        def name = "immtpe"
        def chiselType = UInt(IMMTpe.IMMTpe_Width.W)
        def genTable(i: Insn): BitPat = {
            if(i.hasArg("imm12") || i.hasArg("shamtd")) BitPat(IMMTpe.IMM_TYPE_I)
            else if(i.hasArg("imm12hi") || i.hasArg("imm12lo")) BitPat(IMMTpe.IMM_TYPE_S)
            else if(i.hasArg("bimm12hi") || i.hasArg("bimm12lo")) BitPat(IMMTpe.IMM_TYPE_B)
            else if(i.hasArg("imm20")) BitPat(IMMTpe.IMM_TYPE_U)
            else if(i.hasArg("jimm20")) BitPat(IMMTpe.IMM_TYPE_J)
            else BitPat(IMMTpe.IMM_TYPE_X)
        }
    }
}