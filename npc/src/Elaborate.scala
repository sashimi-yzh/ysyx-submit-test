object Elaborate extends App {
  val firtoolOptions = Array(
    "--default-layer-specialization=enable",
    "--verification-flavor=if-else-fatal",
    "--lowering-options=" + List(
      // make yosys happy
      // see https://github.com/llvm/circt/blob/main/docs/VerilogGeneration.md
      "disallowLocalVariables",
      "disallowPackedArrays",
      "locationInfoStyle=wrapInAtSquareBracket"
    ).reduce(_ + "," + _)
  )
  circt.stage.ChiselStage.emitSystemVerilogFile(new npc.ysyx_26030092, args, firtoolOptions)
}
