
package npc

import chisel3._
import chisel3.util._
import npc.common._
import npc._
import npc.devices._


class DebugPort() (implicit val conf: Config)extends BlackBox with HasBlackBoxInline{ 
    val io = IO(new Bundle {
        val clock = Input(Clock())
        val reset = Input(Bool())   
        val halt = Input(Bool())
        val pc = Input(UInt(32.W))
        val inst = Input(UInt(32.W))
        val mem_pc = Input(UInt(32.W))
        val wb_valid = Input(Bool())
        val wb_pc = Input(UInt(32.W))
        val wb_inst = Input(UInt(32.W))
        val lsu_port = Flipped(new LSUDebugPort()) 
     })

     setInline("DebugPort.v",
     """
     import "DPI-C" function void dpi_port(input int halt, input int pc, input int inst,input int wb_pc,input int mem_pc,input int wb_inst);
     import "DPI-C" function void lsu_port(input enable,  input fcn, input int lsu_port_typ,input int addr, input int data);
     module DebugPort(
        input clock,
        input reset,
        input halt, 
        input [31:0] pc,
        input [31:0] wb_pc,
        input [31:0] wb_inst,
        input [31:0] mem_pc,
        input [31:0] inst,
        input [31:0] lsu_port_addr,
        input [31:0] lsu_port_rdata,
        input [31:0] lsu_port_wdata,
        input [31:0] lsu_port_storeCount,
        input [31:0] lsu_port_loadCount,
        input lsu_port_mem_en,
        input lsu_port_fcn,
        input lsu_port_valid,
        input wb_valid,
        input [1:0]  lsu_port_typ
        );

        wire [31:0] expand_halt = {31'b0,halt};
        wire [31:0] expand_typ   = {30'b0,lsu_port_typ};
        always @(*) begin
            dpi_port(expand_halt, pc, inst,mem_pc,wb_pc,wb_inst);
        end

        always @(posedge clock) begin
            if (lsu_port_mem_en && lsu_port_fcn == 1'b1) begin
                lsu_port(lsu_port_valid && lsu_port_mem_en,lsu_port_fcn,expand_typ, lsu_port_addr, lsu_port_wdata);
            end else if (lsu_port_valid && lsu_port_fcn == 1'b0) begin
                lsu_port(lsu_port_valid,lsu_port_fcn,expand_typ, lsu_port_addr, lsu_port_rdata);
            end else begin
                lsu_port(1'd0,1'd0,32'd0,32'd0,32'd0);
            end
        end
     endmodule
     """.stripMargin
     )

}

class PerfEventPort() (implicit val conf: Config)extends BlackBox with HasBlackBoxInline{ 
     val io = IO(new Bundle {
        val clock       = Input(Clock())
        val reset       = Input(Bool()) 
        val lsu_port    = Flipped(new LSUDebugPort()) 
        val ifu_port    = Flipped(new IFUDebugPort())
        val wbu_port    = Flipped(new WBUDebugPort())
        val ctl_port    = Flipped(new CtrlDebugPort())
     })

     setInline("PerfEventPort.v",
     """
     import "DPI-C" function void perf_event_lsu(input int storeCount, input int loadCount);
     import "DPI-C" function void perf_event_ifu(input int instFetchCount);
     import "DPI-C" function void perf_event_icache(input int hit,input int miss);
     import "DPI-C" function void perf_event_wbu(input int wbCount);
     import "DPI-C" function void perf_event_ctrl(input int csrCount, input int loadCount, input int storeCount, 
         input int itype, input int rtype, input int jtype,  input int utype, input int other);
     module PerfEventPort(
        input clock,
        input reset,
        input ifu_port_valid,
        input [31:0] lsu_port_addr,
        input [31:0] lsu_port_rdata,
        input [31:0] lsu_port_wdata,
        input [1:0]  lsu_port_typ,
        input lsu_port_mem_en,
        input lsu_port_fcn,
        input lsu_port_valid,
        input [31:0] lsu_port_storeCount,
        input [31:0] lsu_port_loadCount,
        input [31:0] wbu_port_wbCount,
        input [31:0] ifu_port_instFetchCount,
        input [31:0] ifu_port_icache_hit_cnt,
        input [31:0] ifu_port_icache_miss_cnt,        
        input [31:0] ctl_port_csrCount,
        input [31:0] ctl_port_storeCount,
        input [31:0] ctl_port_loadCount,
        input [31:0] ctl_port_itypeCount,
        input [31:0] ctl_port_rtypeCount,
        input [31:0] ctl_port_jtypeCount,
        input [31:0] ctl_port_utypeCount,
        input [31:0] ctl_port_otherCount
        );


        always @(posedge clock) begin
            perf_event_ctrl(ctl_port_csrCount, ctl_port_storeCount, 
                ctl_port_loadCount, ctl_port_itypeCount, ctl_port_rtypeCount,
                ctl_port_jtypeCount,ctl_port_utypeCount, ctl_port_otherCount);
            perf_event_wbu(wbu_port_wbCount);
            if (lsu_port_valid)
                perf_event_lsu(lsu_port_storeCount, lsu_port_loadCount);
            if (ifu_port_valid) begin
                perf_event_ifu(ifu_port_instFetchCount);   
                perf_event_icache(ifu_port_icache_hit_cnt,ifu_port_icache_miss_cnt);             
            end
        end

     endmodule
     """.stripMargin
     )
}
