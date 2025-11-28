package npc.devices

import chisel3._
import chisel3.util._

import npc.common.Constants._
import npc.common._

class AXI4LiteMem(implicit val conf: Config) extends BlackBox with HasBlackBoxPath {
   val io = IO(new Bundle() { 
      val clock   =   Input(Clock())
      val reset   =   Input(Bool())
      val dr      =   new AXIRport(conf.xprlen, conf.xlen)
      val dw      =   new AXIWport(conf.xprlen, conf.xlen)
   })
   val path = System.getenv("NPC_CHISEL_HOME")+"/npc/src/main/resources/AXI4LiteMem.v"
   addPath(path)
   println(s"AsyncMem path: ${path}")
}

class AXI4LiteMemRandomDelay(implicit val conf: Config) extends BlackBox with HasBlackBoxPath {
   val io = IO(new Bundle() { 
      val clock   =   Input(Clock())
      val reset   =   Input(Bool())
      val dr      =   new AXIRport(conf.xprlen, conf.xlen)
      val dw      =   new AXIWport(conf.xprlen, conf.xlen)
   })
   val path = System.getenv("NPC_CHISEL_HOME")+"/npc/src/main/resources/AXI4LiteMemRandomDelay.v"
   addPath(path)
   println(s"AXI4LiteMemRandomDelay path: ${path}")
}

class AsyncMem(val addrWidth: Int) extends BlackBox with HasBlackBoxPath {
   val io = IO(new Bundle{
      val dr = new AXIRport(addrWidth,32)
      val dw = new AXIWport(addrWidth,32)
      val clock = Input(Clock())
      val reset = Input(Bool())
   }) 

   val path = System.getenv("NPC_CHISEL_HOME")+"/npc/src/main/resources/AsyncMem.v"
   addPath(path)
   println(s"AsyncMem path: ${path}")
}


class TopAXI4LiteMem(implicit val conf: Config) extends BlackBox with HasBlackBoxInline  {
   val io = IO(new Bundle{
      val dr = new AXIRport(conf.xprlen, conf.xlen)
      val dw = new AXIWport(conf.xprlen, conf.xlen)
      val clock = Input(Clock())
      val reset = Input(Bool())
   }) 
      
   setInline("TopAXI4LiteMem.v",
   """module TopAXI4LiteMem #(
   |    ADDR_WIDTH = 32,
   |    DATA_WIDTH = 32,
   |    MASK_WIDTH = 4,
   |    ORIGIN_ADDR=32'h80000000,
   |    MEM_SIZE=32'h08000000,
   |    LOADER_MEM_SIZE = 32'h100
   |) (
   |    input clock,
   |    input reset,
   |
   |    // 写端口（dw: Wport）
   |    input                   dw_en,           // 写使能 (原MemWEn)
   |    input  [ADDR_WIDTH-1:0] dw_addr,        // 写地址
   |    input  [DATA_WIDTH-1:0] dw_data,        // 写数据
   |    input  [MASK_WIDTH-1:0] dw_mask,         // 字节掩码 (原Length整合至mask)
   |    // 读端口（dr: Rport)）
   |    input                   dr_en,          // 端口使能
   |    input  [ADDR_WIDTH-1:0] dr_addr,        // 端口0地址
   |
   |    output  reg [DATA_WIDTH-1:0]    dr_data,   // 端口数据
   |    output  reg                     dr_ready,
   |    output  reg                     dw_ready
   |);
   |
   |import "DPI-C" function void pmem_mask_write(input int inaddr,input int mask, input int din);
   |import "DPI-C" function void pmem_mask_read(input int outaddr,input int mask, output int dout);
   |
   |    reg [7:0] mem_start[LOADER_MEM_SIZE-1:0];
   |    wire [DATA_WIDTH-1:0] dw_mask_wide;
   |    Top_mask_expander me (
   |        .mask(dw_mask),
   |        .mask_wide(dw_mask_wide)
   |    );
   |    wire [31:0] dw_addr_aligned,dr_addr_aligned; 
   |    assign dw_addr_aligned = {dw_addr[ADDR_WIDTH-1:2],2'b0} ;
   |    assign dr_addr_aligned = {dr_addr[ADDR_WIDTH-1:2],2'b0} ;
   |    always @(posedge clock) begin
   |        if (dw_en) begin
   |            pmem_mask_write(dw_addr_aligned, dw_mask_wide, dw_data);
   |        end 
   |    end
   |    initial begin
   |    integer j;
   |    for (j = 0; j < 128; j = j + 4) begin
   |         // 小端格式存储
   |         mem_start[j]   = 8'h33;  // 最低字节
   |         mem_start[j+1] = 8'h40;  // 
   |         mem_start[j+2] = 8'h00;  // 
   |         mem_start[j+3] = 8'h00;  // 最高字节
   |     end 
   |     {mem_start[3],mem_start[2],mem_start[1],mem_start[0]}= 32'h50000097;
   |     {mem_start[7],mem_start[6],mem_start[5],mem_start[4]}= 32'h00008067;
   |    end
   |    always @(posedge clock) begin
   |     if (dr_en && dr_addr >= 32'h30000000 && dr_addr < 32'h30001000) begin
   |         dr_data = {mem_start[(dr_addr-32'h30000000)+3],mem_start[(dr_addr-32'h30000000)+2],mem_start[(dr_addr-32'h30000000)+1],mem_start[(dr_addr-32'h30000000)]};
   |         dr_ready =  1'b1;     
   |     end else if (dr_en) begin
   |            // -1 -> 1111
   |            pmem_mask_read(dr_addr_aligned, -1, dr_data);
   |            dr_ready = 1'b1;
   |        end else begin
   |            dr_data = 32'b0;
   |            dr_ready = 1'b0;
   |        end
   |    end
   |
   |    assign dw_ready = 1'b1;
   |
   |endmodule
    """.stripMargin)
   

 }


class IverilogAXI4LiteMem(implicit val conf: Config) extends BlackBox with HasBlackBoxInline  {
   val io = IO(new Bundle{
      val dr = new AXIRport(conf.xprlen, conf.xlen)
      val dw = new AXIWport(conf.xprlen, conf.xlen)
      val clock = Input(Clock())
      val reset = Input(Bool())
   }) 
   setInline("IverilogAXI4LiteMem.v",
   """module IverilogAXI4LiteMem #(
   |    ADDR_WIDTH = 32,
   |    DATA_WIDTH = 32,
   |    MASK_WIDTH = 4,
   |    ORIGIN_ADDR=32'h80000000,
   |    MEM_SIZE=32'h08000000,
   |    LOADER_MEM_SIZE = 32'h100
   |) (
   |    input clock,
   |    input reset,
   |
   |    // 写端口（dw: Wport）
   |    input                   dw_en,           // 写使能 (原MemWEn)
   |    input  [ADDR_WIDTH-1:0] dw_addr,        // 写地址
   |    input  [DATA_WIDTH-1:0] dw_data,        // 写数据
   |    input  [MASK_WIDTH-1:0] dw_mask,         // 字节掩码 (原Length整合至mask)
   |    // 读端口（dr: Rport)）
   |    input                   dr_en,          // 端口使能
   |    input  [ADDR_WIDTH-1:0] dr_addr,        // 端口0地址
   |
   |    output  reg [DATA_WIDTH-1:0]    dr_data,   // 端口数据
   |    output  reg                     dr_ready,
   |    output  reg                     dw_ready
   |);
   |  wire [DATA_WIDTH-1:0] dw_mask_wide;
   |  Top_mask_expander me (
   |      .mask(dw_mask),
   |      .mask_wide(dw_mask_wide)
   |  );
   |  reg [7:0] mem [MEM_SIZE:0];
   |  reg [2047:0] path = 0;
   |  reg [63:0] current_time;
   |  reg [7:0] mem_start[LOADER_MEM_SIZE-1:0];
   |  initial begin
   |   integer j;
   |   for (j = 0; j < 128; j = j + 4) begin
   |        // 小端格式存储
   |        mem_start[j]   = 8'h33;  // 最低字节
   |        mem_start[j+1] = 8'h40;  // 
   |        mem_start[j+2] = 8'h00;  // 
   |        mem_start[j+3] = 8'h00;  // 最高字节
   |    end 
   |   {mem_start[7],mem_start[6],mem_start[5],mem_start[4]}= 32'h00008067;
   |   {mem_start[3],mem_start[2],mem_start[1],mem_start[0]}= 32'h50000097;
   |    if (!$value$plusargs("image=%s", path)) begin
   |      path = "./iverilog_scripts/dummy-riscv32e-npc.hex";
   |    end
   |    $display("Reading image from %s", path);
   |    $readmemh( path, mem,0,4000000);
   |  end
   |  reg wen_reg;
   |  reg [31:0] wdata_reg,wmask_wide_reg,rdata_reg;
   |  wire [31:0] dr_addr_aligned;
   |  reg [31:0] dw_addr_aligned; 
   |  assign dr_addr_aligned = {dr_addr[ADDR_WIDTH-1:2],2'b0}-32'h80000000 ;
   |  always @(posedge clock) begin
   |      dw_ready <= 1'b0; // 默认值
   |      
   |      if (reset) begin
   |          wen_reg <= 1'b0;
   |          dw_ready <= 1'b0;
   |      end else if (dw_en && !dw_ready) begin
   |          // 特殊地址处理：串口输出
   |          if (dw_addr == 32'ha00003f8) begin
   |              $write("%c", dw_data[7:0]);
   |              dw_ready <= 1'b1;
   |          end 
   |          // 内存范围写操作
   |          else if (dw_addr >= ORIGIN_ADDR && dw_addr < ORIGIN_ADDR + MEM_SIZE) begin
   |              // 计算对齐地址（使用参数）
   |              dw_addr_aligned <= (dw_addr - ORIGIN_ADDR) & ~3;
   |              
   |              // 存储写数据
   |              wdata_reg <= dw_data;
   |              wmask_wide_reg <= dw_mask_wide;
   |              wen_reg <= 1'b1;
   |              dw_ready <= 1'b1;
   |          end 
   |          // 其他地址写操作
   |          else begin
   |              dw_ready <= 1'b1;
   |          end
   |      end 
   |      // 实际内存写入
   |      else if (wen_reg) begin
   |          // 直接按字节写入，避免读取旧数据
   |          if (wmask_wide_reg[31:24]) mem[dw_addr_aligned+3] <= wdata_reg[31:24];
   |          if (wmask_wide_reg[23:16]) mem[dw_addr_aligned+2] <= wdata_reg[23:16];
   |          if (wmask_wide_reg[15:8])  mem[dw_addr_aligned+1] <= wdata_reg[15:8];
   |          if (wmask_wide_reg[7:0])   mem[dw_addr_aligned]   <= wdata_reg[7:0];
   |          
   |          wen_reg <= 1'b0;
   |      end
   |  end
   |   
   |  always @(posedge clock) begin
   |     if (dr_en && (dr_addr == 32'ha0000048 || dr_addr == 32'ha000004c)) begin
   |         current_time = $time/1000;
   |         dr_data = (dr_addr == 32'ha0000048)? current_time[31:0]:current_time[63:32];
   |         dr_ready =  1'b1;     
   |     end else if (dr_en && dr_addr >= 32'h30000000 && dr_addr < 32'h30001000) begin
   |         dr_data = {mem_start[(dr_addr-32'h30000000)+3],mem_start[(dr_addr-32'h30000000)+2],mem_start[(dr_addr-32'h30000000)+1],mem_start[(dr_addr-32'h30000000)]};
   |         dr_ready =  1'b1;     
   |     end else if (dr_en && dr_addr >= 32'h80000000 && dr_addr < 32'h90000000) begin
   |          dr_data = {mem[dr_addr_aligned+3],mem[dr_addr_aligned+2],mem[dr_addr_aligned+1],mem[dr_addr_aligned]};
   |          dr_ready =  1'b1;     
   |     end else begin 
   |         dr_data = 32'b0;
   |         dr_ready = 1'b0;
   |     end
   |   end
   |endmodule
    """.stripMargin)
   
}