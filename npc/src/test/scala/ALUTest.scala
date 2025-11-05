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



class ALUEquivCheckBench(val width: Int) extends Module {
    val io = IO(new ALUIO(width))

    val alu_ref = Module(new ysyx_23060246_ALU(width))

    val alu_dut = Module(new ysyx_23060246_ALU_AREA(width))
    alu_dut.io.A := io.A
    alu_dut.io.B := io.B
    alu_ref.io.A := io.A
    alu_ref.io.B := io.B
    alu_ref.io.aluop := io.aluop
    alu_dut.io.aluop := io.aluop
    io.out := alu_dut.io.out 

    assume(io.aluop < 12.U, "Invalid ALU Operation")
    assert(alu_dut.io.out === alu_ref.io.out, "ALU Equivalence Check Failed!")

}

class ALUTest extends AnyFlatSpec with ChiselScalatestTester with Formal{

    it should "PASS" in {
        verify(new ALUEquivCheckBench(32), Seq(BoundedCheck(1)))
    }

}