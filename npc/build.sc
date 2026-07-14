import mill._
import mill.scalalib.scalafmt.ScalafmtModule
import mill.scalalib.TestModule.ScalaTest
import mill.scalalib._

// 0.11.x 使用 RootModule 将模块挂载到项目根级，对应 1.1 的 object `package`
object root extends RootModule with ScalaModule with ScalafmtModule { m =>
  def scalaVersion = "2.13.18"

  def scalacOptions = Seq(
    "-language:reflectiveCalls",
    "-deprecation",
    "-feature",
    "-Xcheckinit"
  )

  // 0.11.x 必须使用 ivyDeps 以及 Agg(ivy"...") 来引入依赖
  def ivyDeps              = Agg(ivy"org.chipsalliance::chisel:7.7.0")
  def scalacPluginIvyDeps  = Agg(ivy"org.chipsalliance:::chisel-plugin:7.7.0")

  object test extends ScalaTests with TestModule.ScalaTest with ScalafmtModule {
    def ivyDeps = m.ivyDeps() ++ Agg(
      ivy"edu.berkeley.cs::chiseltest:6.0.0",
      ivy"org.scalatest::scalatest::3.2.19"
    )
  }
}