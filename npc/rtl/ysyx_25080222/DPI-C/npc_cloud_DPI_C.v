//DPI-C机制
`ifdef NPC_CLOUD_SIM
import "DPI-C" function void NPC_Cloud_trap_ebreak(); 

import "DPI-C" function void NPC_Cloud_itrace(input int pc, input int inst, input int dnpc);  
import "DPI-C" function void NPC_Cloud_ifu_count(input int addr);  
import "DPI-C" function void NPC_Cloud_ifu_start(input int addr);

import "DPI-C" context function void NPC_Cloud_reg(input int gpr, input int i); 

import "DPI-C" function void NPC_Cloud_icache_start(input int addr);
import "DPI-C" function void NPC_Cloud_icache_check(input int addr);  
import "DPI-C" function void NPC_Cloud_icache_sdram(input int addr);  

import "DPI-C" function void NPC_Cloud_lsu_start(); 
import "DPI-C" function void NPC_Cloud_lsu_rcount();  
import "DPI-C" function void NPC_Cloud_lsu_wcount();

import "DPI-C" function void NPC_Cloud_alu_count();  
import "DPI-C" function void NPC_Cloud_csr_count();  

`endif

//ebreak指令:利用DPI-C机制, 使得在NPC在执行的时候通知仿真环境结束仿真. 
module ysyx_25080222_exu_ebreak(
	input clk,
	input is
);

`ifdef NPC_CLOUD_SIM
	always @(posedge clk) begin
		if(is) NPC_Cloud_trap_ebreak();
	end
`endif

endmodule


module ysyx_25080222_itrace(
	input clk,
	input rst,
	input arvalid,
	input rvalid,
	input valid,
    input [31:0] pc,    
    input [31:0] inst
);

`ifdef NPC_CLOUD_SIM
	reg [31:0] pc_buf[7:0];
	reg [31:0] inst_buf[7:0];
	reg [2:0] rptr;
	reg [2:0] wptr;

    // 初始化缓冲区
    integer i;
    initial begin
        for(i = 0; i < 8; i = i + 1) begin
            pc_buf[i] = 32'b0; inst_buf[i] = 32'b0;
        end
        rptr = 3'b0; wptr = 3'b0;
    end

	always @(posedge clk) begin
        if(rst) begin  // 复位信号通常高有效
            // 复位时清空缓冲区和指针
            for(i = 0; i < 8; i = i + 1) begin
                pc_buf[i] <= 32'b0; inst_buf[i] <= 32'b0;
            end
            rptr <= 3'b0; wptr <= 3'b0;
        end
        else begin
			if(arvalid) begin   // arvalid: 记录PC并通知跟踪开始
				pc_buf[wptr] <= pc;
				NPC_Cloud_ifu_start(pc);
			end
			if(rvalid) begin   // rvalid: 记录指令,统计ifu性能计数器并更新写指针
				inst_buf[wptr] <= inst;
				NPC_Cloud_ifu_count(pc);
				wptr <= wptr + 1;
			end
    		if(valid) begin  // valid: 输出跟踪信息并更新读指针
				NPC_Cloud_itrace(pc_buf[rptr], inst_buf[rptr], pc_buf[rptr + 1]);
				rptr <= rptr + 1;
			end
		end
	end
`endif

endmodule


// module ysyx_25080222_reg_trace #(ADDR_WIDTH = 5, DATA_WIDTH = 32) (
// 	input clk,
// 	input valid,
//     input wen,
// 	input [DATA_WIDTH-1:0] wdata,
// 	input [ADDR_WIDTH-1:0] waddr
// );


module ysyx_25080222_reg_trace (
	input clk,
	input valid,
    input wen,
	input [31:0] wdata,
	input [4:0] waddr
);

`ifdef NPC_CLOUD_SIM
	always @(posedge clk) begin
         if(valid && wen) NPC_Cloud_reg(wdata, {27'b0, waddr});
	end
`endif

endmodule



module ysyx_25080222_icache_count(
	input clk,
	input arvalid,
	input [31:0] addr,
	input check,
	input sdram
);

`ifdef NPC_CLOUD_SIM
	reg [31:0] raddr;
	always @(posedge clk) begin
    	if(arvalid) begin 
			raddr <= addr;
			NPC_Cloud_icache_start(addr);
		end
		if(check) NPC_Cloud_icache_check(raddr);
		if(sdram)  NPC_Cloud_icache_sdram(raddr);
	end
`endif

endmodule



module ysyx_25080222_lsu_count(
	input clk,
	input rvalid,
	input ren,
	input bvalid,
	input wen
);

`ifdef NPC_CLOUD_SIM
	always @(posedge clk) begin
		if(ren || wen) NPC_Cloud_lsu_start();
    	if(rvalid) NPC_Cloud_lsu_rcount();
		if(bvalid) NPC_Cloud_lsu_wcount();
	end
`endif

endmodule



module ysyx_25080222_instruction_count(
	input clk,
	input alu_valid,
	input csr_valid
);

`ifdef NPC_CLOUD_SIM
	always @(posedge clk) begin
    	if(alu_valid) NPC_Cloud_alu_count();
		if(csr_valid) NPC_Cloud_csr_count();
	end
`endif

endmodule


