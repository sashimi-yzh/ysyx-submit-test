//注意！！！该版本Momery不采用DPI-C进行内存读写,而是直接用verilog定义reg实现
//适用于: nonSoC, nonSoC_netlist
/******** 注意npc和ysyxsoc的外设(clint和uart)地址不同*******************
		
				npc							     ysyxsoc

clint		0xa0000048 ~						0x02000000 ~
			0xa000004f							0x02000007
		(由ysyx_23060229_memory实现)		(由ysyx_23060229_CLINT实现)

uart		0xa00003f8							0x10000000
		(由ysyx_23060229_memory实现)		(由ysyxSoCFull + DPI-C实现)

主存		0x80000000 ~						0xa0000000 ~
(sdram)		0x8fffffff							0xa1ffffff
		(由ysyx_23060229_memory实现)		(由ysyxSoCFull + DPI-C实现)

**************************************************************************/


`ifndef __YSYX_23060229_MEMORY__
`define __YSYX_23060229_MEMORY__

//memory-specific macros
`define WRAP_INCREASE(no, max)      ((no == max) ? 0 : no + 1)
//表示no在0-max内循环加一
`define WRAP_DECREASE(no, max)      ((no == 0) ? max : no - 1)
//表示no在0-max内循环减一
`define INCR_ADDR(addr, no, size)   (addr + (no << size))


/* verilator lint_off WIDTHEXPAND */
module ysyx_23060229_memory(
	input clock,
	input reset,

	//axi-AR,cpu为master，mem为slave
	input [31:0] araddr,//cpu发送的读地址
	input arvalid,//cpu发来的读地址有效
	output arready,//mem准备好去读cpu发来的读地址
	input [3:0] arid,//AR事务号
	input [7:0] arlen,//传输数目
	input [2:0] arsize,//单次传输byte数
	input [1:0] arburst,//突发类型

	//axi-R,mem为master，cpu为slave
	output reg[31:0] rdata,//mem发送的读出数据
	output reg[1:0] rresp,//mem发送读状态
	output rvalid,//mem发送的读出数据有效
	input rready,//cpu准备好去读mem发来的读出数据
	output rlast,//最后一个传输标志
	output reg[3:0] rid,//R事务号，应该和arid保持一致



	//axi-AW,cpu为master，mem为slave
	input [31:0] awaddr,//cpu发送的写地址
	input awvalid,//cpu发送的写地址有效
	output awready,//mem准备好去读cpu发来的写地址
	input [3:0] awid,//AW事务号
	input [7:0] awlen,//传输数目
	input [2:0] awsize,//单次传输byte数
	input [1:0] awburst,//突发类型
	
	//axi-W，cpu为master，mem为slave
	input [31:0] wdata,//cpu发送的写数据
	input [3:0] wstrb,//cpu发送的写掩码
	input wvalid,//cpu发送的写数据有效
	output wready,//mem准备好去读mem发来的写数据
	input wlast,//最后一个输出标志

	//axi-B，mem为master，cpu为slave
	output reg[1:0] bresp,//mem发送的写状态
	output bvalid,//mem发送的写状态有效
	input bready,//cpu准备好去读mem发送的写状态
	output reg[3:0] bid//B事务号，应该和awid保持一致
);

	
	

	reg [48:0] queue_AR [15:0];//AR事务循环队列
	//[48:16] araddr; [16:13] arid; [12:5] arlen; [4:2] arsize; [1:0] arburst
	reg [3:0] head_queue_AR;
	reg [3:0] tail_queue_AR;

	wire flag_queue_AR_empty;
	assign flag_queue_AR_empty = (head_queue_AR == tail_queue_AR);
	wire flag_queue_AR_full;
	assign flag_queue_AR_full = (head_queue_AR == `WRAP_INCREASE(tail_queue_AR, 15));

	wire [3:0] end_queue_AR;
	assign end_queue_AR = `WRAP_DECREASE(tail_queue_AR, 15);
	
	
	reg [48:0] queue_AW [15:0];//AW事务循环队列
	//[48:16] awaddr; [16:13] awid; [12:5] awlen; [4:2] awsize; [1:0] awburst
	reg [3:0] head_queue_AW;
	reg [3:0] tail_queue_AW;

	wire flag_queue_AW_empty;
	assign flag_queue_AW_empty = (head_queue_AW == tail_queue_AW);
	wire flag_queue_AW_full;
	assign flag_queue_AW_full = (head_queue_AW == `WRAP_INCREASE(tail_queue_AW, 15));

	wire [3:0] end_queue_AW;
	assign end_queue_AW = `WRAP_DECREASE(tail_queue_AW, 15);
	
	
	
	//定义几个存储器
	//reg [7:0] flash[0:32'h0fffffff];//0x30000000 - 0x3fffffff
	//reg [7:0] sram [0:32'h00ffffff];//0x0f000000 - 0x0fffffff
	//reg [7:0] sdram[0:32'h01ffffff];//0xa0000000 - 0xa1ffffff
	

	//此为SOC访存行为
	//reg [7:0] flash[0:32'h00ffffff];//0x30000000 - 0x3fffffff
	//reg [7:0] sram [0:32'h0000ffff];//0x0f000000 - 0x0fffffff
	//reg [7:0] sdram[0:32'h004fffff];//0xa0000000 - 0xa1ffffff
	
	//此为nonSOC访存行为
	reg [7:0] mem[0:32'h07ffffff];//0x80000000 - 0x8fffffff
	
	reg [63:0] mtime;//额外实现mtime寄存器以模拟CLINT
    always @(posedge clock)
        mtime <= reset ? 0 : (mtime + 1);


	
	//定义读内存函数
	function [31:0] pmem_read_verilog;
		input [31:0] araddr;
		input [2:0] arsize;
		reg [31:0] araddr_local;
		begin
			/*此处为SoC内存读取行为,主要基地址为a0000000*/
			/*if ((araddr >= 32'h30000000) && (araddr <= 32'h3fffffff)) begin
                araddr_local = (araddr - 32'h30000000) & 32'hfffffffc;
				pmem_read_verilog = {flash[araddr_local+3], flash[araddr_local+2], flash[araddr_local+1], flash[araddr_local]};
            end 
			else if ((araddr >= 32'h0f000000) && (araddr <= 32'h0fffffff)) begin
                araddr_local = (araddr - 32'h0f000000) & 32'hfffffffc;
				pmem_read_verilog = {sram[araddr_local+3], sram[araddr_local+2], sram[araddr_local+1], sram[araddr_local]};
            end
			else if ((araddr >= 32'ha0000000) && (araddr <= 32'hbfffffff)) begin
                araddr_local = (araddr - 32'ha0000000) & 32'hfffffffc;
				pmem_read_verilog = {sdram[araddr_local+3], sdram[araddr_local+2], sdram[araddr_local+1], sdram[araddr_local]};
            end
			else if(araddr == 32'h10000005) begin//uart
				pmem_read_verilog = 32'hffffffff;
			end
			else begin
				pmem_read_verilog = 32'h0;
			end*/
		   	
			/*此处为nonSoC内存读取行为,主要基地址为80000000*/
		   	if ((araddr >= 32'h80000000) && (araddr <= 32'h8fffffff)) begin
                araddr_local = (araddr - 32'h80000000) & 32'hfffffffc;
                pmem_read_verilog = {mem[araddr_local+3], mem[araddr_local+2], mem[araddr_local+1], mem[araddr_local]};
            	//if(araddr == 32'h8000ffb0) begin
				//	$display("read 8000ffb0, data = %x\n", {mem[araddr_local+3], mem[araddr_local+2], mem[araddr_local+1], mem[araddr_local]});
				//end
			end
			else if ((araddr >= 32'ha0000048) && (araddr <= 32'ha000004f)) begin
                araddr_local = (araddr - 32'ha0000048) & 32'hfffffffc;
                pmem_read_verilog = araddr_local[2] ? mtime[63:32] : mtime[31:0];
            end
			
			//重要修改,确保不论reset_pc是0x30000000还是0x80000000，都跳转至
			//0x80000000处执行
			else if(araddr == 32'h30000000) begin
				pmem_read_verilog = 32'h80000537;//mv a0, 0x80000000
			end
			else if(araddr == 32'h30000004) begin
				pmem_read_verilog = 32'h00050067;//jalr a0, 0
			end
			
			
			else begin
				pmem_read_verilog = 32'h0;
			end
		end
	endfunction


	//定义写内存任务
	task pmem_write_verilog;
		input [31:0] waddr;
		input [31:0] wdata;
		input [3:0] wmask;
		reg [31:0] waddr_local;
		begin
			//$display("write mem: %x with data: %x", waddr, wdata);
			waddr_local = waddr & 32'hfffffffc;
			if(|(wmask & 4'b0001)) begin
				/*if(waddr >= 32'h0f000000 && waddr <= 32'h0fffffff) begin
					sram[waddr_local-32'h0f000000] = wdata[7:0];
				end
				else if(waddr >= 32'ha0000000 && waddr <= 32'hbfffffff) begin
					sdram[waddr_local-32'ha0000000] = wdata[7:0];
				end
				else if(waddr == 32'h10000000) begin
					$write("%c",wdata[7:0]);
				end*/
			   	if(waddr >= 32'h80000000 && waddr <= 32'h8fffffff) begin
                    mem[waddr_local-32'h80000000] = wdata[7:0];
                end
                else if(waddr == 32'ha00003f8) begin
                    $write("%c",wdata[7:0]);
                end
			end
			if(|(wmask & 4'b0010)) begin
				/*if(waddr >= 32'h0f000000 && waddr <= 32'h0fffffff) begin
                    sram[waddr_local-32'h0f000000+1] = wdata[15:8];
                end
                else if(waddr >= 32'ha0000000 && waddr <= 32'hbfffffff) begin
                    sdram[waddr_local-32'ha0000000+1] = wdata[15:8];
                end
                else if(waddr == 32'h10000000) begin
                    $write("%c",wdata[15:8]);
                end*/
			   	if(waddr >= 32'h80000000 && waddr <= 32'h8fffffff) begin
                    mem[waddr_local-32'h80000000+1] = wdata[15:8];
                end
                else if(waddr == 32'ha00003f8) begin
                    $write("%c",wdata[15:8]);
                end
			end
			if(|(wmask & 4'b0100)) begin
				/*if(waddr >= 32'h0f000000 && waddr <= 32'h0fffffff) begin
                    sram[waddr_local-32'h0f000000+2] = wdata[23:16];
                end
                else if(waddr >= 32'ha0000000 && waddr <= 32'hbfffffff) begin
                    sdram[waddr_local-32'ha0000000+2] = wdata[23:16];
                end
                else if(waddr == 32'h10000000) begin
                    $write("%c",wdata[23:16]);
                end*/
			   	if(waddr >= 32'h80000000 && waddr <= 32'h8fffffff) begin
                    mem[waddr_local-32'h80000000+2] = wdata[23:16];
                end
                else if(waddr == 32'ha00003f8) begin
                    $write("%c",wdata[23:16]);
                end
			end
			if(|(wmask & 4'b1000)) begin
				/*if(waddr >= 32'h0f000000 && waddr <= 32'h0fffffff) begin
                    sram[waddr_local-32'h0f000000+3] = wdata[31:24];
                end
                else if(waddr >= 32'ha0000000 && waddr <= 32'hbfffffff) begin
                    sdram[waddr_local-32'ha0000000+3] = wdata[31:24];
                end
                else if(waddr == 32'h10000000) begin
                    $write("%c",wdata[31:24]);
                end*/
			   	if(waddr >= 32'h80000000 && waddr <= 32'h8fffffff) begin
                    mem[waddr_local-32'h80000000+3] = wdata[31:24];
                end
                else if(waddr == 32'ha00003f8) begin
                    $write("%c",wdata[31:24]);
                end
			end
		end
	endtask
	
	
	//integer j;
	parameter HEX_FILE = "none";
	always @(posedge clock) begin
		if(reset) begin
			$readmemh(HEX_FILE, mem);//nonSOC,直接读到mem而非flash
			//强制清0,避免bss段存在未初始化的static变量
			//for(j = 0; j <= 32'h004fffff; j += 1) begin
			//	sdram[j] <= 0;
			//end
		end
	end


	integer i;
	always@(posedge clock) begin
		if(reset) begin
			head_queue_AR <= 0; tail_queue_AR <= 0;
			head_queue_AW <= 0; tail_queue_AW <= 0;
			for(i = 0; i <= 15; i+=1) begin
				queue_AR[i] <= 49'b0;
				queue_AW[i] <= 49'b0;
			end
		end
	end	
		

	/*******************状态机1:AR事务*********************/
	parameter 	Wait_Arvalid = 1'b0,
				Interim_AR = 1'b1;
	
	reg state_AR;
	
	always @(posedge clock) begin
		if(reset) begin
			state_AR <= Wait_Arvalid;
		end

		else begin
			case(state_AR)
				Wait_Arvalid: begin
					if(arvalid == 1 && (((arid != queue_AR[end_queue_AR][16:13])&&!flag_queue_AR_full) 
							|| flag_queue_AR_empty)) begin
						queue_AR[tail_queue_AR][48:17] <= araddr;
						queue_AR[tail_queue_AR][16:13] <= arid;
						queue_AR[tail_queue_AR][12:5] <= arlen;
						queue_AR[tail_queue_AR][4:2] <= arsize;
						queue_AR[tail_queue_AR][1:0] <= arburst;
						tail_queue_AR <= `WRAP_INCREASE(tail_queue_AR, 15);
						state_AR <= Interim_AR;
					end
				end
				Interim_AR: begin
					state_AR <= Wait_Arvalid;
				end
				default: begin
					state_AR <= Wait_Arvalid;
				end
			endcase
		end
	end
	
	assign arready = (state_AR == Wait_Arvalid);


	
	/*******************状态机2:R事务*********************/
	parameter 	Await_R = 1'b0,
				Wait_Rready = 1'b1;
	
	reg state_R;

	reg [7:0] cnt_R;//用于计数当前这个突发传输已经传了几个

	always@(posedge clock) begin
		if(reset) begin
			state_R <= Await_R;
			cnt_R <= 0;
		end
	
		else begin
			case(state_R)
				Await_R: begin
					if(arready && arvalid) begin
						rdata <= pmem_read_verilog(araddr, arsize);
						rresp <= 0;
						rid <= arid;
						state_R <= Wait_Rready;
					end
				end
				Wait_Rready: begin
					if(rready && cnt_R == queue_AR[head_queue_AR][12:5] //本次传输完毕，队列将被清空
							&& `WRAP_INCREASE(head_queue_AR, 15) == tail_queue_AR) begin
						cnt_R <= 0; head_queue_AR <= `WRAP_INCREASE(head_queue_AR, 15);
						rresp <= 0; rdata <= 0;
						state_R <= Await_R;
					end
					
					else if(rready && cnt_R == queue_AR[head_queue_AR][12:5]//本次传输完毕，队列还没清空
							&& `WRAP_INCREASE(head_queue_AR, 15) != tail_queue_AR) begin
						cnt_R <= 0; head_queue_AR <= `WRAP_INCREASE(head_queue_AR, 15);
						rresp <= 0; rid <= queue_AR[`WRAP_INCREASE(head_queue_AR, 15)][16:13];
						rdata <= pmem_read_verilog(queue_AR[`WRAP_INCREASE(head_queue_AR, 15)][48:17], 
											queue_AR[`WRAP_INCREASE(head_queue_AR, 15)][4:2]);
						//注意这里读取的数据永远仅由araddr和arsize决定，与arburst无关
					end

					else if(rready && cnt_R != queue_AR[head_queue_AR][12:5]) begin//本次传输还没完毕
						cnt_R <= cnt_R + 1;
						rresp <= 0; rid <= queue_AR[head_queue_AR][16:13];
						case(queue_AR[head_queue_AR][1:0])//根据arburst方式读取数据
							2'b00: rdata <= pmem_read_verilog(queue_AR[head_queue_AR][48:17], queue_AR[head_queue_AR][4:2]);
							2'b01: rdata <= pmem_read_verilog(`INCR_ADDR(queue_AR[head_queue_AR][48:17], cnt_R + 1, queue_AR[head_queue_AR][4:2]),
														queue_AR[head_queue_AR][4:2]);
							default: rdata <= 0;
						endcase//注意pmem_read需要重写
					end

					else begin
						;//pass
					end
				end
				default: begin
					state_R <= Await_R;
					cnt_R <= 0;
				end
			endcase
		end
	end

	assign rvalid = (state_R == Wait_Rready);
	assign rlast = (cnt_R == queue_AR[head_queue_AR][12:5]) && (!flag_queue_AR_empty);



	/*******************状态机3:AW事务*********************/
	parameter 	Wait_Awvalid = 1'b0,
				Interim_AW = 1'b1;
	
	reg state_AW;

	reg [3:0] cnt_delay_AW;
	
	always @(posedge clock) begin
		if(reset) begin
			state_AW <= Wait_Awvalid;
			cnt_delay_AW <= 0;
		end

		else begin
			case(state_AW)
				Wait_Awvalid: begin
					if(awvalid == 1 && (((awid != queue_AW[end_queue_AW][16:13])&&!flag_queue_AW_full) 
							|| flag_queue_AW_empty)) begin
						queue_AW[tail_queue_AW][48:17] <= awaddr;
						queue_AW[tail_queue_AW][16:13] <= awid;
						queue_AW[tail_queue_AW][12:5] <= awlen;
						queue_AW[tail_queue_AW][4:2] <= awsize;
						queue_AW[tail_queue_AW][1:0] <= awburst;
						tail_queue_AW <= `WRAP_INCREASE(tail_queue_AW, 15);
						state_AW <= Interim_AW;
					end
				end
				Interim_AW: begin
					//cnt_delay_AW <= (cnt_delay_AW == 15) ? 0 : cnt_delay_AW + 1;
					//state_AW <= (cnt_delay_AW == 15) ? Wait_Awvalid : state_AW;
					state_AW <= Wait_Awvalid;
				end
				default: begin
					state_AW <= Wait_Awvalid;
				end
			endcase
		end
	end

	assign awready = (state_AW == Wait_Awvalid);



	/*******************状态机4:W事务*********************/
	parameter 	Await_W = 2'b00,
				Delay_W = 2'b01,
				Wait_Wvalid = 2'b10;
	
	reg [1:0] state_W;

	reg [3:0] cnt_delay_W;

	reg [7:0] cnt_W;//用于计数当前这个突发传输已经传了几个

	always@(posedge clock) begin
		if(reset) begin
			state_W <= Await_W;
			cnt_W <= 0;
			cnt_delay_W <= 0;
		end
	
		else begin
			case(state_W)
				Await_W: begin
					if(awready && awvalid) begin
						state_W <= Delay_W;
					end
				end
				Delay_W: begin
					cnt_delay_W <= (cnt_delay_W == 15) ? 0 : cnt_delay_W + 1;
					state_W <= (cnt_delay_W == 15) ? Wait_Wvalid : state_W;
				end
				Wait_Wvalid: begin
					if(wvalid && cnt_W == queue_AW[head_queue_AW][12:5] && wlast//本次传输完毕，队列将被清空
							&& `WRAP_INCREASE(head_queue_AW, 15) == tail_queue_AW) begin
						cnt_W <= 0; head_queue_AW <= `WRAP_INCREASE(head_queue_AW, 15);
						case(queue_AW[head_queue_AW][1:0])//根据awburst进行定址写入
							2'b00: pmem_write_verilog(queue_AW[head_queue_AW][48:17], wdata, wstrb);
							2'b01: pmem_write_verilog(`INCR_ADDR(queue_AW[head_queue_AW][48:17], cnt_W, queue_AW[head_queue_AW][4:2]), wdata, wstrb);
							default: ;
						endcase
						state_W <= Await_W;
					end
					
					else if(wvalid && cnt_W == queue_AW[head_queue_AW][12:5] && wlast//本次传输完毕，队列还没清空
							&& `WRAP_INCREASE(head_queue_AW, 15) != tail_queue_AW) begin
						cnt_W <= 0; head_queue_AW <= `WRAP_INCREASE(head_queue_AW, 15);
						case(queue_AW[head_queue_AW][1:0])//根据awburst进行定址写入
                            2'b00: pmem_write_verilog(queue_AW[head_queue_AW][48:17], wdata, wstrb);
                            2'b01: pmem_write_verilog(`INCR_ADDR(queue_AW[head_queue_AW][48:17], cnt_W, queue_AW[head_queue_AW][4:2]), wdata, wstrb);
                            default: ;
                        endcase
					end

					else if(wvalid && cnt_W != queue_AW[head_queue_AW][12:5] && !wlast) begin//本次传输还没完毕
						cnt_W <= cnt_W + 1;
						case(queue_AW[head_queue_AW][1:0])//根据awburst进行定址写入
                            2'b00: pmem_write_verilog(queue_AW[head_queue_AW][48:17], wdata, wstrb);
                            2'b01: pmem_write_verilog(`INCR_ADDR(queue_AW[head_queue_AW][48:17], cnt_W, queue_AW[head_queue_AW][4:2]), wdata, wstrb);
                            default: ;
						endcase//注意pmem_read需要重写
					end

					else begin
						;//pass
					end
				end
				default: begin
					state_W <= Await_W;
					cnt_W <= 0;
				end
			endcase
		end
	end

	assign wready = (state_W == Wait_Wvalid);



	/*******************状态机5:B事务*********************/
    parameter   Await_B = 1'b0,
                Wait_Bready = 1'b1;

    reg state_B;
	
	always@(posedge clock) begin
		if(reset) begin
			state_B <= Await_B;
		end

		else begin
			case(state_B)
				Await_B: begin
					if(wlast) begin
						bresp <= 0; bid <= queue_AW[head_queue_AW][16:13];
						state_B <= Wait_Bready;
					end
				end
				Wait_Bready: begin
					if(bready && wlast) begin//
						bresp <= 0; bid <= queue_AW[head_queue_AW][16:13];
					end
					else if(bready && !wlast) begin
						state_B <= Await_B;
					end
				end
				default: begin
					state_B <= Await_B;
				end
			endcase
		end
	
	end

	assign bvalid = (state_B == Wait_Bready);

endmodule

/* verilator lint_on WIDTHEXPAND */

`endif
