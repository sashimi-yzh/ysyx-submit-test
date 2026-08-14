`include "defines.v"

import "DPI-C" function int pmem_read(input int raddr, input int mtrace_flag);
import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
import "DPI-C" function void ftrace_call(input int pc, input int dnpc);
import "DPI-C" function void ftrace_ret(input int pc);
import "DPI-C" function void npctrap(input int a0);

module minirv_top(
  input clk,
  input rst_n
);
  wire [`INST_ADDR_WIDTH-1:0] pc;
  wire [`INST_DATA_WIDTH-1:0] inst;
  wire [`WORD_WIDTH-1:0] rd1;
  wire [`WORD_WIDTH-1:0] rd2;
  wire [`REG_ADDR_WIDTH-1:0] ra1;
  wire [`REG_ADDR_WIDTH-1:0] ra2; 
  wire [`WORD_WIDTH-1:0] src1;
  wire [`WORD_WIDTH-1:0] src2;
  wire [`ALU_OP_WIDTH-1:0] alu_op;
  wire [`WORD_WIDTH-1:0] alu_res;
  wire [`REG_ADDR_WIDTH-1:0] wa;
  wire [`WORD_WIDTH-1:0] wd;
  wire wreg;
  wire [`INST_ADDR_WIDTH-1:0] jump_addr;
  wire jump_flag;
  wire [3:0] ls_inst;
  wire [`REG_DATA_WIDTH-1:0] a0;

  wire mwreg;
  wire [`DATA_DATA_WIDTH-1:0] mwd;

  IFU IFU0(
    .clk(clk),
    .rst_n(rst_n),
    .if_pc(pc),
    .jump_addr(jump_addr),
    .jump_flag(jump_flag),
    .inst(inst)
  );

  RegisterFile RegisterFile0(
    .clk(clk),
    .rst_n(rst_n),
    .wdata(wd),
    .waddr(wa),
    .wen(wreg),
    .r1addr(ra1),
    .r2addr(ra2),
    .r1data(rd1),
    .r2data(rd2),

    .a0(a0)
  );

  IDU IDU0(
    .pc(pc),
    .inst(inst),
    .a0(a0),
    .rd1(rd1),
    .rd2(rd2),
    .ra1(ra1),
    .ra2(ra2),
    .src1(src1),
    .src2(src2),
    .alu_op(alu_op),
    .wreg(wreg),
    .wa(wa),

    .jump_addr(jump_addr),
    .jump_flag(jump_flag),

    .ls_inst(ls_inst)
  );

  EXU EXU0(
    .src1(src1),
    .src2(src2),
    .alu_op(alu_op),
    .alu_res(alu_res)
  );

  LSU LSU0(
    .clk(clk),
    .ls_inst(ls_inst),
    .rd2(rd2),
    .mwd(mwd),
    .mwreg(mwreg),
    .alu_res(alu_res)
  );

  WBU WBU0(
    .alu_res(alu_res),
    .mwd(mwd),
    .mwreg(mwreg),
    .wd(wd)
  );
endmodule