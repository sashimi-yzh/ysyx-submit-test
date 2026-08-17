package empty

import circt.stage._
import chisel3._
import chisel3.layer._

import scopt.OParser

abstract class PrefixedModule(prefix: String = "ysyx_25080216") extends Module {
  override val desiredName = s"${prefix}_${this.getClass.getSimpleName}"
  println(s"Module name: $name")
}

abstract class PrefixedRawModule(prefix: String = "ysyx_25080216")
    extends Module {
  override val desiredName = s"${prefix}_${this.getClass.getSimpleName}"
  println(s"Module name: $name")
}

object AddMain extends App {

  case class Config(
      performanceCounter: Boolean = true,
      axiasset: Boolean = true,
      verifying: Boolean = true,
      init_pc: Long = 0x30000000,
      to_soc: Boolean = true,
      output_dir: String = "../build"
  )

  val builder = OParser.builder[Config]
  val parser = {
    import builder._
    OParser.sequence(
      programName("NPC"),
      opt[Unit]("pc")
        .action((_, c) => c.copy(performanceCounter = true))
        .text("enable performance counter"),
      opt[Unit]("no-pc")
        .action((_, c) => c.copy(performanceCounter = false))
        .text("disable performance counter"),
      opt[Unit]("axiasset")
        .action((_, c) => c.copy(axiasset = true))
        .text("enable axiasset"),
      opt[Unit]("no-axiasset")
        .action((_, c) => c.copy(axiasset = false))
        .text("disable axiasset"),
      opt[Unit]("verifying")
        .action((_, c) => c.copy(verifying = true))
        .text("enable verifying"),
      opt[Unit]("no-verifying")
        .action((_, c) => c.copy(verifying = false))
        .text("disable verifying"),
      opt[Unit]("to-soc")
        .action((_, c) =>
          c.copy(to_soc = true, output_dir = "../generated_svsrc")
        ),
      opt[Unit]("to-npc")
        .action((_, c) =>
          c.copy(
            to_soc = false,
            output_dir = "generated_svsrc"
          )
        )
        .text("disable verifying"),
      opt[Long]("init-pc")
        .action((x, c) => c.copy(init_pc = x))
        .text("set initial PC address (default: 0x30000000)")
    )
  }

  val conf = OParser.parse(parser, args, Config()).getOrElse(sys.exit(1))

  println("Generating the CPU RTL")

  if (conf.to_soc) {
    ChiselStage.emitSystemVerilogFile(
      new ysyx_25080216(
        performance_counter = conf.performanceCounter,
        axiasset = conf.axiasset,
        verifying = conf.verifying,
        init_pc = conf.init_pc
      ),
      Array(
        "--target-dir",
        conf.output_dir
      ),
      Array(
        "--disable-all-randomization",
        "--disable-layers=Verification",
        "--lowering-options=" + List(
          // make yosys happy
          // see https://github.com/llvm/circt/blob/main/docs/VerilogGeneration.md
          "disallowLocalVariables",
          "disallowPackedArrays",
          "disallowPackedStructAssignments",
          // "disallowDeclAssignments",
          // "disallowPortDeclSharing",
          "disallowExpressionInliningInPorts",
          "locationInfoStyle=wrapInAtSquareBracket"
        ).reduce(_ + "," + _)
      )
    )
  } else {

    ChiselStage.emitSystemVerilogFile(
      new npc_top(
        performance_counter = conf.performanceCounter,
        init_pc = conf.init_pc
      ),
      Array("--target-dir", conf.output_dir),
      Array(
        "--disable-all-randomization",
        "--disable-layers=Verification",
        "--lowering-options=" + List(
          // make yosys happy
          // see https://github.com/llvm/circt/blob/main/docs/VerilogGeneration.md
          "disallowLocalVariables",
          "disallowPackedArrays",
          "disallowPackedStructAssignments",
          // "disallowDeclAssignments",
          // "disallowPortDeclSharing",
          "disallowExpressionInliningInPorts",
          "locationInfoStyle=wrapInAtSquareBracket"
        ).reduce(_ + "," + _)
      )
    )

  }

}
