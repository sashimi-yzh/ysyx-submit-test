import scala.sys.process._

import testSoC._
import common_def.CPUParameters

import chisel3._

object Elaborate extends App {
  if (args.size != 2) {
    println("Usage: --target-dir <dir>")
    sys.exit(1)
  }
  val firtoolOptions = Array(
    "--lowering-options=" + List(
      // make yosys happy
      // see https://github.com/llvm/circt/blob/main/docs/VerilogGeneration.md
      "disallowLocalVariables",
      "disallowPackedArrays",
      "locationInfoStyle=wrapInAtSquareBracket"
    ).reduce(_ + "," + _),
    "-disable-all-randomization",
    "-strip-debug-info"
  )

  val designName = "ysyx_25100261"

  def emit(gen: => chisel3.RawModule, emitDir: String) = {
    println(s"Emitting Verilog... to $emitDir")
    circt.stage.ChiselStage.emitSystemVerilogFile(
      gen,
      Array("--target-dir", emitDir),
      firtoolOptions
    )

    println(s"Preprocessing Verilog... on $emitDir")
    val preProcSoC = s"./scripts/preproc_vsrcs.sh ${emitDir} ${designName}".!
    if (preProcSoC != 0) sys.exit(preProcSoC)
    println(s"Finish emitting and preprocessing Verilog on $emitDir")
  }

  val emitRootDir = args(1)

  emit(new top.ysyx_25100261(CPUParameters(gprAddrWidth = 4)), s"$emitRootDir/riscv32e")
  emit(
    new top.ysyx_25100261(
      CPUParameters(
        gprAddrWidth = 5,
        skipDifftestAddrs = jyd.AddrSpace.needSkipDifftestGroup,
        resetVector = "h80000000".U(32.W)
      )
    ),
    s"$emitRootDir/riscv32"
  )

  emit(new TestSoC(new npc.NPCDevices), s"$emitRootDir/testsoc/npc")
  emit(new TestSoC(new jyd.JYDDevices), s"$emitRootDir/testsoc/jyd")
}
