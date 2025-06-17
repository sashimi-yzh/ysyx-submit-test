object Elaborate extends App {
  val firtoolLoweringOptions = Array("--lowering-options=" + List(
    // make yosys happy
    // see https://github.com/llvm/circt/blob/main/docs/VerilogGeneration.md
    "disallowLocalVariables",
    "disallowPackedArrays",
    "locationInfoStyle=wrapInAtSquareBracket"
  ).reduce(_ + "," + _))

  def parseArgs(firrtlOptions: Array[String], firtoolOptions: Array[String], args: List[String]):
    (Array[String], Array[String]) = {
    args match {
      case "--mode" :: mode :: tail => if (npc.Global.mode != "syn") npc.Global.mode = mode; // "syn" has higher priority
                                       parseArgs(firrtlOptions, firtoolOptions, tail)
      case "--freq-file" :: file :: tail => npc.Global.freqFile = file; parseArgs(firrtlOptions, firtoolOptions, tail)
      case "--rv64" :: tail => npc.Global.xlen = 64; npc.Global.rve = false; parseArgs(firrtlOptions, firtoolOptions, tail)
      case "--debug" :: tail => npc.Global.debug = true; parseArgs(firrtlOptions, firtoolOptions, tail)
      case s :: tail => parseArgs(firrtlOptions :+ s, firtoolOptions, tail)
      case Nil => (firrtlOptions, firtoolOptions)
    }
  }
  val (firrtlOpt, firtoolOpt) = parseArgs(Array[String](), Array[String](), args.toList)
  require(Seq("sim", "ysyxsoc", "syn").exists(npc.Global.mode == _))
  val firtoolOptDebug = (if (npc.Global.debug) Array("--preserve-aggregate=vec", "--preserve-values=all") else
                                               Array("--preserve-aggregate=none", "--preserve-values=strip"))
  val firtoolOptFinal = firtoolOpt ++ firtoolOptDebug ++ (if (npc.Global.mode == "syn") firtoolLoweringOptions else Array())

  (new circt.stage.ChiselStage).execute(
    Array("--target", "chirrtl") ++ firrtlOpt,
    Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new npc.Top())) ++ firtoolOptFinal.map(circt.stage.FirtoolOption(_))
  )

  circt.stage.ChiselStage.emitSystemVerilogFile(new npc.Top(), firrtlOpt, firtoolOptFinal)
}
