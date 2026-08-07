package config
import org.chipsalliance.cde.config.Field

object Configs {
  case object STUID                     extends Field[String]("ysyx_25060161")
  case object ResetVector               extends Field[BigInt](BigInt(sys.env.get("NPC_RESET_VECTOR").filter(_.nonEmpty).getOrElse("30000000").stripPrefix("0x"), 16))
  case object DebugMode                 extends Field[Boolean](sys.env.get("NPC_DEBUG_MODE").filter(_.nonEmpty).forall(_ == "true"))
  case object ICacheWordOffBits         extends Field[Int](sys.env.get("NPC_ICACHE_WORD_OFF_BITS").filter(_.nonEmpty).map(_.toInt).getOrElse(1))
  case object ICacheBlockBits           extends Field[Int](sys.env.get("NPC_ICACHE_BLOCK_BITS").filter(_.nonEmpty).map(_.toInt).getOrElse(0))
  case object BranchPredictorIndexWidth extends Field[Int](sys.env.get("NPC_BRANCH_PREDICTOR_INDEX_WIDTH").filter(_.nonEmpty).map(_.toInt).getOrElse(0))
}
