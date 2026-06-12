package formal

import chisel3._

import java.nio.file.{Files, Paths}
import scala.sys.process._

object Formal {
  def verify[T <: Module](
    gen:     => T,
    topName: String,
    depth:   Int,
    skip:    Int = 0,
    append:  Int = 0,
    engines: Set[String] = Set("smtbmc")
  ): Unit = {
    // import java.util.UUID
    // val workDir = Paths.get(s"formal_${topName}_${UUID.randomUUID()}")
    val workDir = Paths.get(s"formal_${topName}")
    Files.createDirectories(workDir)

    val firtoolOptions = Array(
      "--default-layer-specialization=enable",
      "--verification-flavor=immediate",
      // "--lowering-options=verifLabels=false",
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

    Process(
      Seq(
        "perl",
        "-0777",
        "-pi",
        "-e",
        """
        s/^\s*((assert)|(assume))__[a-zA-Z0-9_]+:\s*//gm;
        s/(\b((assert)|(assume))\s*\(.*?\))\s*\n?\s*else\s+\$error\(.*?\);/$1;/gs;
        """,
        svPath.toAbsolutePath.toString
      ),
      workDir.toFile
    ).!

    val sby =
      s"""
[tasks]
basic bmc
basic: default

[options]
bmc:
mode bmc
vcd off
fst on
depth $depth
skip $skip
append $append

[engines]
${engines.mkString("\n")}

[script]
read -sv $topName.sv
prep -flatten -nordff -top $topName
chformal -early

[autotune]
parallel 12

[files]
$topName.sv
"""

    // |plugin -i slang
    // |read_slang $topName.sv
    // |skip $skip
    // |presat on
    // |abc bmc3
    // |smtbmc boolector
    // |smtbmc boolector -- --noincr
    val sbyPath = workDir.resolve(s"$topName.sby")
    Files.write(sbyPath, sby.getBytes)

    println(s"[Formal] Generated: $svPath")
    println(s"[Formal] Running SymbiYosys...")

    val exitCode =
      Process(
        Seq(
          "sby",
          // "--autotune",
          "-f",
          sbyPath.getFileName.toString,
          "-d",
          workDir.toString
        ),
        workDir.toFile
      ).!

    // val tracePath =
    //   workDir
    //     .resolve(topName + "_basic")
    //     .resolve("engine_0")
    //     .resolve("trace.fst")
    //     .toAbsolutePath
    // import java.nio.file.Files

    val waves = os.walk(os.Path(workDir.toAbsolutePath)).filter(p => os.isFile(p) && p.ext == "fst")
    org.scalatest.Assertions
      .assert(exitCode == 0, "RUN FAIL: Wave:\n" + waves.mkString("\n"))
  }
}

class InitAssume extends ExtModule {
  val cond = IO(Input(Bool()))
  setInline(
    "InitAssume.sv",
    """module InitAssume(
      |    input  cond
      |);
      |  always_comb assume (cond == $initstate);
      |endmodule
    """.stripMargin
  )
}
object InitAssume {
  def apply(cond: Bool): Bool = {
    Module(new InitAssume).cond := cond
    cond
  }
}

class ModuleWithInitReset extends Module {
  InitAssume(reset.asBool)
}
