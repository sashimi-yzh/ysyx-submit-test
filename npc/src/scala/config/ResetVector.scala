package config

import chisel3._
import org.chipsalliance.cde.config.Parameters

class ResetVector(
  implicit p: Parameters)
    extends ExtModule {
  override def desiredName: String = s"${p(Configs.STUID)}_ResetVector"
  val vec = IO(Output(UInt(32.W)))
  setInline(
    "ResetVector.v",
    s"""|module ${desiredName}(
      |    output [31:0] vec
      |);
      |`ifdef YOSYS
      |  assign vec = 32'h80000000;
      |`else
      |  assign vec = 32'h${p(Configs.ResetVector).toString(16)};
      |`endif
      |endmodule
    """.stripMargin
  )
}
