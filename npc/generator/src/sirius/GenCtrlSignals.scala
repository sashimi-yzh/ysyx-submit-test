package sirius

import cpuutil.BundleGenerator

object GenCtrlSignals extends App {
  val rootStr = System.getProperty("project.root")
  val workspacePath = os.Path(rootStr)
  val rvOpCodesPath = workspacePath / "riscv-opcodes"
  val cfg = CoreConfig(rvOpCodesPath = rvOpCodesPath)
  val collector = InstDecodeCollector()(cfg)
  val gen = new BundleGenerator("sirius", "CtrlSignals", collector.allFields)
  gen.generate(args(0) + "/CtrlSignals.scala")
}
