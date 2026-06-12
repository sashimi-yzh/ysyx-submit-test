import chisel3._
import chisel3.ltl.AssertProperty

import java.nio.file.{Files, Paths}
import scala.sys.process._
import org.scalatest.flatspec.AnyFlatSpec

object Formal {
  def verify[T <: RawModule](gen: => T, topName: String, depth: Int): Unit = {

    import java.util.UUID
    val workDir = Paths.get(s"formal_${topName}_${UUID.randomUUID()}")
    Files.createDirectories(workDir)

    val firtoolOptions = Array(
      "--default-layer-specialization=enable",
      "--verification-flavor=immediate",
      "--lowering-options=" + List(
        // make yosys happy
        // see https://github.com/llvm/circt/blob/main/docs/VerilogGeneration.md
        "disallowLocalVariables",
        "disallowPackedArrays",
        "locationInfoStyle=wrapInAtSquareBracket"
      ).reduce(_ + "," + _)
    )
    val sv = circt.stage.ChiselStage
      .emitSystemVerilog(gen, firtoolOpts = firtoolOptions)

    val svPath = workDir.resolve(s"$topName.sv")
    Files.write(svPath, sv.getBytes)

    val sby =
      s"""
         |[tasks]
         |basic bmc
         |basic: default
         |
         |[options]
         |bmc:
         |mode bmc
         |vcd off
         |fst on
         |depth $depth
         |
         |[engines]
         |smtbmc
         |
         |[script]
         |plugin -i slang
         |read_slang $topName.sv
         |prep -top $topName
         |
         |[files]
         |$topName.sv
         |""".stripMargin

    val sbyPath = workDir.resolve(s"$topName.sby")
    Files.write(sbyPath, sby.getBytes)

    println(s"[Formal] Generated: $svPath")
    println(s"[Formal] Running SymbiYosys...")

    val exitCode =
      Process(Seq("sby", "-f", sbyPath.getFileName.toString), workDir.toFile).!

    val tracePath =
      workDir
        .resolve(topName + "_basic")
        .resolve("engine_0")
        .resolve("trace.fst")
        .toAbsolutePath

    org.scalatest.Assertions
      .assert(exitCode == 0, "RUN FAIL: Wave: " + tracePath.toString)
  }
}

class Sub extends Module {
  val io = IO(new Bundle {
    val a = Input(UInt(32.W))
    val b = Input(UInt(32.W))
    val c = Output(UInt(32.W))
  })

  io.c := io.a + ~io.b + Mux(io.a === "h98765".U, 0.U, 1.U)
  // io.c := io.a + ~io.b + 1.U

  val ref = io.a - io.b

  // AssertProperty(io.c === ref)
  assert(io.c === ref)
}

class FormalSpec extends AnyFlatSpec {
  "Sub" should "pass" in {
    Formal.verify(new Sub, "Sub", 2)
  }
}
