scalacOptions ++= Seq(
  "-deprecation",
  "-feature",
  "-unchecked",
  // "-Xfatal-warnings",
  "-language:reflectiveCalls"
)

/*
scalaVersion := "2.13.14"
val chiselVersion = "3.6.1"
addCompilerPlugin("edu.berkeley.cs" %% "chisel3-plugin" % chiselVersion cross CrossVersion.full)
libraryDependencies += "edu.berkeley.cs" %% "chisel3" % chiselVersion
libraryDependencies += "edu.berkeley.cs" %% "chiseltest" % "0.6.2"
 */

/*
scalaVersion := "2.13.14"
val chiselVersion = "6.5.0"
addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full)
libraryDependencies += "org.chipsalliance" %% "chisel" % chiselVersion
libraryDependencies += "edu.berkeley.cs" %% "chiseltest" % "6.0.0"
 */

scalaVersion := "2.13.18"
val chiselVersion = "7.13.0"
addCompilerPlugin(
  "org.chipsalliance" %% "chisel-plugin" % chiselVersion cross CrossVersion.full
)
libraryDependencies += "org.chipsalliance" %% "chisel" % chiselVersion

// libraryDependencies += "edu.berkeley.cs" %% "chiseltest" % "6.0.0"
// libraryDependencies += "xyz.kamyar" %% "chiseltest" % "6.0.0"

// libraryDependencies += "org.json4s" %% "json4s-native" % "4.0.7"
// dependencyOverrides += "org.json4s" %% "json4s-native" % "4.0.7"
// dependencyOverrides += "org.json4s" %% "json4s-core" % "4.0.7"
// dependencyOverrides += "org.json4s" %% "json4s-ext" % "4.0.7"
// dependencyOverrides += "org.json4s" %% "json4s-jackson" % "4.0.7"
// dependencyOverrides += "org.scalatest" %% "scalatest" % "3.2.10"
libraryDependencies += "org.scalatest" %% "scalatest" % "3.2.19" % Test

libraryDependencies += "com.github.scopt" %% "scopt" % "4.1.0"

// DO NOT EDIT! This file is auto-generated.

// This plugin enables semantic information to be produced by sbt.
// It also adds support for debugging using the Debug Adapter Protocol
