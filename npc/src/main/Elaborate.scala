import npc.common.Config._
import npc.common._
import npc.common.Instructions._
import npc.core._
import npc.core.ifu._
import npc.core.idu._
import npc.core.isu._
import npc.core.exu._
import npc.core.wbu._
import npc.perip._

object Elaborate extends App {
    // // === 单独测试 instList ===
    // println("=== Instruction List ===")
    // instList.foreach { InstructionPattern =>
    //   println(s"${InstructionPattern.toString}")
    // }





    val firtoolOptions = Array("--lowering-options=" + List(
      // make yosys happy
      // see https://github.com/llvm/circt/blob/main/docs/VerilogGeneration.md
      "disallowLocalVariables",
      "disallowPackedArrays",
      "locationInfoStyle=wrapInAtSquareBracket",
      "noAlwaysComb"
    ).reduce(_ + "," + _))
    circt.stage.ChiselStage.emitSystemVerilogFile(new npc.ysyx_24080032, args, firtoolOptions)
}
