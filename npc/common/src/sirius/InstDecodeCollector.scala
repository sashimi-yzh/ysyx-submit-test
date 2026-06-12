package sirius

import chisel3._
import chisel3.util.experimental.decode._
import chisel3.util.BitPat
import scala.collection.immutable.ListMap
import cpuutil.CanAutoGenSig
import org.chipsalliance.rvdecoderdb

object InstSetParser {
  def apply(name: String): (String, Int, String, String) = {
    val RVStrPattern = """rv(32|64)?_([a-z0-9]+)(?:_([a-z0-9]+))?""".r
    name match {
      case RVStrPattern(n, x, y) =>
        if (n != null && x != null && y == null) {
          ("nx", n.toInt, x, "")
        } else if (n == null && x != null && y == null) {
          ("x", 0, x, "")
        } else if (n == null && x != null && y != null) {
          ("xy", 0, x, y)
        } else {
          ("", 0, "", "")
        }
      case _ => ("", 0, "", "")
    }
  }
}

// 根据启用的扩展生成Seq[DecodePattern]和Seq[DecodeField]
case class InstDecodeCollector(
)(
  implicit private val cfg: CoreConfig) {

  // 生成Fields
  val allFields: Seq[DecodeField[InstPattern, _ <: Data] with CanAutoGenSig] =
    cfg.fieldMap.flatten

  // 生成Patterns
  private val allRvInsts = rvdecoderdb.instructions(cfg.rvOpCodesPath, cfg.curtomOpCodesPath)
  private val rvInsts = cfg.OpCodesFilter(allRvInsts)
  private val instPatterns = InstPatterns()(rvInsts, cfg)
  val allPatterns: Seq[InstPattern] = cfg.patternMap(instPatterns).flatten
}
