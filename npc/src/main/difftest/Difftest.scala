package npc.core.difftest

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._


/*
             ____ ___ _____ _____ _____ _____ ____ _____
            |  _ \_ _|  ___|  ___|_   _| ____/ ___|_   _|
            | | | | || |_  | |_    | | |  _| \___ \ | |
            | |_| | ||  _| |  _|   | | | |___ ___) || |
            |____/___|_|   |_|     |_| |_____|____/ |_|
*/

class DIFFIO extends Bundle {
    val pc = Output(UInt(WORD_LEN.W))
    val inst = Output(UInt(WORD_LEN.W))
}