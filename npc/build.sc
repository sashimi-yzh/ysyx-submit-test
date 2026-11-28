// Mill 0.11 构建文件（CI 使用 mill 0.11.13；0.12/1.x 的 build.mill 无法被它识别）

import mill._
import mill.scalalib.scalafmt.ScalafmtModule
import mill.scalalib.TestModule.ScalaTest
import mill.scalalib._

object playground extends ScalaModule with ScalafmtModule { m =>
  override def millSourcePath = os.pwd

  override def scalaVersion = "2.13.18"

  override def scalacOptions = Seq(
    "-language:reflectiveCalls",
    "-deprecation",
    "-feature",
    "-Xcheckinit"
  )

  override def ivyDeps             = Agg(ivy"org.chipsalliance::chisel:7.7.0")
  override def scalacPluginIvyDeps = Agg(ivy"org.chipsalliance:::chisel-plugin:7.7.0")

  object test extends ScalaTests with TestModule.ScalaTest with ScalafmtModule {
    override def ivyDeps = Agg(ivy"org.scalatest::scalatest:3.2.19")
  }
}
