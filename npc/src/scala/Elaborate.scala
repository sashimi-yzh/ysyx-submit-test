import org.chipsalliance.cde.config.Parameters
import org.chipsalliance.diplomacy.lazymodule.LazyModule
import config._
object Elaborate extends App {
  implicit val p: Parameters = Parameters.empty

  val firtoolOptions = Array(
    "--lowering-options=" + List(
      // make yosys happy
      // see https://github.com/llvm/circt/blob/main/docs/VerilogGeneration.md
      "disallowLocalVariables",
      "disallowPackedArrays",
      "locationInfoStyle=none"
    ).reduce(_ + "," + _)
  )
  val top            = LazyModule(new Top())
  circt.stage.ChiselStage.emitSystemVerilogFile(top.module, args, firtoolOptions)
}
