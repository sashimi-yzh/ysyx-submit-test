import chisel3._

import npc._
import npc.common.{Config}
package sifive {
  package enterprise {
    package firrtl {

      case class NestedPrefixModulesAnnotation(
          val target: _root_.firrtl.annotations.Target,
          prefix: String,
          inclusive: Boolean
      ) extends _root_.firrtl.annotations.SingleTargetAnnotation[
            _root_.firrtl.annotations.Target
          ] {

        override def duplicate(n: _root_.firrtl.annotations.Target) = ???
      }
    }
  }
}


object Elaborate extends App {
  val firtoolOptions = Array(
    "--disable-all-randomization",
    "--disable-mem-randomization",
    "--disable-reg-randomization",
    "--lowering-options=" + List(
       "disallowLocalVariables",
      "disallowPackedArrays",
      "locationInfoStyle=wrapInAtSquareBracket",
      "noAlwaysComb"
    ).reduce(_ + "," + _),
  )
  circt.stage.ChiselStage.emitSystemVerilogFile(
    new ysyx_24100012(),
    Array("--target","verilog","--target-dir","build/soc"),
    firtoolOptions)
}

object ElaborateNPC extends App {
  val firtoolOptions = Array(
    "--disable-all-randomization",
    "--disable-mem-randomization",
    "--disable-reg-randomization",
    "--lowering-options=" + List(
       "disallowLocalVariables",
      "disallowPackedArrays",
      "locationInfoStyle=wrapInAtSquareBracket",
      "noAlwaysComb",
    ).reduce(_ + "," + _),
  )
  circt.stage.ChiselStage.emitSystemVerilogFile(
    new Top(),
    Array("--split-verilog","--target","verilog","--target-dir","build/npc"),
    firtoolOptions)
}

object ElaborateIverilog extends App {
  val firtoolOptions = Array(
    "--disable-all-randomization",
    "--disable-mem-randomization",
    "--disable-reg-randomization",
    "--lowering-options=" + List(
      "disallowLocalVariables",
      "disallowPackedArrays",
      "locationInfoStyle=wrapInAtSquareBracket",
      "noAlwaysComb",
    ).reduce(_ + "," + _),
  )
  circt.stage.ChiselStage.emitSystemVerilogFile(
    new IverilogTop(),
    Array("--split-verilog","--target","verilog","--target-dir","build/iverilog"),
    firtoolOptions)
}

object ElaborateIverilogNetlist extends App {
  val firtoolOptions = Array(
    // "--disable-all-randomization",
    // "--disable-mem-randomization",
    "--lowering-options=" + List(
       "disallowLocalVariables",
      "disallowPackedArrays",
      "locationInfoStyle=wrapInAtSquareBracket",
    ).reduce(_ + "," + _),
  )
  circt.stage.ChiselStage.emitSystemVerilogFile(
    new Top(),
    Array("--split-verilog","--target","verilog","--target-dir","build/netlist"),
    firtoolOptions)
}

object ElaborateHelp extends App {
  val firtoolOptions = Array(
    "--help",
  )
  circt.stage.ChiselStage.emitSystemVerilogFile(
    new Top(),
     Array("--target","verilog","--target-dir","build/help"),
    firtoolOptions)
}


// object Elaborate extends App {
//   val firtoolOptions = Array(
//     "--lowering-options=" + List(
//       // make yosys happy
//       // see https://github.com/llvm/circt/blob/main/docs/VerilogGeneration.md
//       "disallowLocalVariables",
//       "disallowPackedArrays",
//       "locationInfoStyle=wrapInAtSquareBracket",
//     ).reduce(_ + "," + _),
//   )
//   circt.stage.ChiselStage.emitSystemVerilogFile(
//     new ysyxSoCFull(),
//     args,
//     firtoolOptions)
// }
