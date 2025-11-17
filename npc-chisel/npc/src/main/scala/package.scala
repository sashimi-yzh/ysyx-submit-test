package npc
import npc.constants._

import chisel3._
import chisel3.util._

object Constants extends
   ScalarOpConstants with
   npc.common.MemoryOpConstants with
   NPCProcConstants with
   npc.common.PrivilegedConstants with
   RISCVConstants with
   npc.common.AXI4BurstTypes with
    ExceptionCodesConstants
{
}