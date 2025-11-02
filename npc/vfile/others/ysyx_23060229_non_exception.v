//final version by yangjiaxin, 2025.09.29, dual port for icache
//revision: no exception handling(except for ecall), to save area
//PART I: Configuration & Macros
//	I1: auto
//	I2: macro
//PART II: Registers & Cache
//	II1: Register
//	II2: CSRegister
//	II3: icache
//PART III: Backbone
//	III1: alu
//	III2: IFU
//	III3: IDU
//	III4: EXU
//	III5: LSU
//PART IV: Auxiliary
//	IV1: CLINT
//	IV2: miniXbar
//PART V: Controllers
//	V1: ForwardingCtl
//	V2: StallingCtl
//	V3: ExceptionCtl
//PART VI: Integration
//	ysyx_23060229 CPU	



`ifndef __YSYX_23060229__
`define __YSYX_23060229__

//PART I: Configuration & Macros
//-----------------------------------------I1:auto-----------------------------------------//
//`define ysyx_23060229_CONFIG_FLASH 1//由verilator -D选项传入
`define ysyx_23060229_CONFIG_FAST_FLASH 1
`define ysyx_23060229_CONFIG_N 2
`define ysyx_23060229_CONFIG_M 3
//`define ysyx_23060229_CONFIG_ITRACE 1
//`define ysyx_23060229_CONFIG_CALIB_AXI4 1
//`define ysyx_23060229_CONFIG_CALIB_APB 1
//`define verilator //会在开启verilator仿真时自动定义;开启后会输出统计数据
//`define simulation 1 //deprecated
//-----------------------------------------end-of-auto-----------------------------------------//


//-----------------------------------------I2:macro-----------------------------------------//
	//cache配置,N为块数(默认为2),M为块大小(默认为3)
	`ifdef ysyx_23060229_CONFIG_N
		`define ysyx_23060229_N `ysyx_23060229_CONFIG_N
	`else
		`define ysyx_23060229_N 2
	`endif

	`ifdef ysyx_23060229_CONFIG_M
		`define ysyx_23060229_M `ysyx_23060229_CONFIG_M
	`else
		`define ysyx_23060229_M 3
	`endif

	//`ifdef ysyx_23060229_nonSoC_Memory
	//	`define 	ysyx_23060229_RESET_PC	  32'h8000_0000
	`ifdef ysyx_23060229_CONFIG_FLASH
    	`define     ysyx_23060229_RESET_PC    32'h3000_0000
	`elsif ysyx_23060229_CONFIG_MROM
    	`define     ysyx_23060229_RESET_PC    32'h2000_0000
	`else
		`define 	ysyx_23060229_RESET_PC	  32'h8000_0000
	`endif

	//type 1: write reg with reg
	//type 2: write reg with mem
	//type 3: write mem with reg
	
	//import "DPI-C" function int pmem_read(input int raddr, input byte ren);
	//import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
	
`ifdef verilator//only used in verilator environment
	import "DPI-C" function void hit_good_trap();
	import "DPI-C" function void hit_bad_trap();

	//icache
	import "DPI-C" function void hit_counter_increase();
	import "DPI-C" function void unhit_timer_increase();
	

	import "DPI-C" function void IFU_counter_increase();
	import "DPI-C" function void EXU_counter_increase();
	import "DPI-C" function void LSU_counter_increase();
	import "DPI-C" function void cal_inst_counter_increase();
	import "DPI-C" function void ma_inst_counter_increase();
	import "DPI-C" function void branch_inst_counter_increase();
	import "DPI-C" function void csr_inst_counter_increase();

	import "DPI-C" function void flush_counter_increase();
`endif


	`define ysyx_23060229_CLINT_BASE	32'h02000000//8x8=64位mtime寄存器
	`define ysyx_23060229_CLINT_END		32'h0200ffff

	
	`define ysyx_23060229_SELECT_SLAVE(addr, xbar, clint)		(addr[31:16] == 16'h0200) ? clint : xbar


	`define ysyx_23060229_CHECK_CLINT(addr, signal)		(addr[31:16] == 16'h0200) ? signal : 0
	`define ysyx_23060229_CHECK_XBAR(addr, signal)		(addr[31:16] == 16'h0200) ? 0 : signal


	`define ysyx_23060229_MSTATUS		12'h300
	`define ysyx_23060229_MTVEC			12'h305
	`define ysyx_23060229_MEPC 			12'h341
	`define ysyx_23060229_MCAUSE		12'h342

	`define ysyx_23060229_MVENDORID		12'hf11
	`define ysyx_23060229_MARCHID		12'hf12


	`define ysyx_23060229_Invalid  		3'b000
   	`define ysyx_23060229_WriteReg  	3'b001
    `define ysyx_23060229_WriteMem 		3'b010
    `define ysyx_23060229_ReadMem 		3'b011
    `define ysyx_23060229_Jump_B 		3'b100//非写入reg型跳转
    `define ysyx_23060229_Jump_J 		3'b101//写入reg型跳转
	`define ysyx_23060229_WriteCSReg	3'b110//写入reg和csreg
	`define ysyx_23060229_Jump_CS		3'b111


	//WriteReg, 3'b001
	`define ysyx_23060229_R_ADD     8'b00100000
    `define ysyx_23060229_R_AND     8'b00100001
    `define ysyx_23060229_R_OR      8'b00100010
    `define ysyx_23060229_R_XOR     8'b00100011
   	`define ysyx_23060229_R_SLTU    8'b00100100
	`define ysyx_23060229_R_SLL     8'b00100101
    `define ysyx_23060229_R_SRL     8'b00100110
    `define ysyx_23060229_R_SRA     8'b00100111
    `define ysyx_23060229_R_SUB     8'b00101000
    `define ysyx_23060229_R_SLT     8'b00101001

	`define ysyx_23060229_I_ADDI    8'b00110000
    `define ysyx_23060229_I_ANDI    8'b00110001
    `define ysyx_23060229_I_ORI     8'b00110010
    `define ysyx_23060229_I_XORI    8'b00110011
    `define ysyx_23060229_I_SLTIU   8'b00110100
    `define ysyx_23060229_I_SLLI    8'b00110101
    `define ysyx_23060229_I_SRLI    8'b00110110
    `define ysyx_23060229_I_SRAI    8'b00110111
    `define ysyx_23060229_I_SLTI    8'b00111000
	
	`define ysyx_23060229_U_AUIPC 	8'b00111100//[3:1]特殊
	`define ysyx_23060229_U_LUI		8'b00111110


	//WriteMem, 3'b010
	`define ysyx_23060229_S_SB		8'b01000001
	`define ysyx_23060229_S_SH		8'b01000011
	`define ysyx_23060229_S_SW		8'b01001111
	

	
	//ReadMem, 3'b011
	`define ysyx_23060229_I_LB      8'b01100000
	`define ysyx_23060229_I_LBU     8'b01100001
	`define ysyx_23060229_I_LH      8'b01100010
	`define ysyx_23060229_I_LHU  	8'b01100011
	`define ysyx_23060229_I_LW   	8'b01100100


	//Jump_B, 3'b100
	`define ysyx_23060229_B_BEQ		8'b10000000
    `define ysyx_23060229_B_BNE     8'b10000001
    `define ysyx_23060229_B_BLT     8'b10000010
    `define ysyx_23060229_B_BLTU    8'b10000011
    `define ysyx_23060229_B_BGE     8'b10000100
    `define ysyx_23060229_B_BGEU    8'b10000101
	`define ysyx_23060229_MRET		8'b10001000
	`define ysyx_23060229_FENCEI	8'b10010000
	//将fencei视为特殊jumpB


	//Jump_J, 3'b101
	`define ysyx_23060229_J_JAL	    8'b10100000
	`define ysyx_23060229_I_JALR    8'b10100001

	
	
	//WriteCSReg, 3'b110
	`define ysyx_23060229_I_CSRRW	8'b11000000
	`define ysyx_23060229_I_CSRRWI	8'b11000001
	`define ysyx_23060229_I_CSRRS	8'b11000010
	`define ysyx_23060229_I_CSRRSI	8'b11000011
	`define ysyx_23060229_I_CSRRC	8'b11000100
	`define ysyx_23060229_I_CSRRCI	8'b11000101
	

	//Jump_CS, 3'b111
	`define ysyx_23060229_ECALL		8'b11100000
	
	//Invalid, 3'b000
	`define ysyx_23060229_NONE		8'b00000000
	`define ysyx_23060229_EBREAK    8'b00000001

//-----------------------------------------end-of-macro-----------------------------------------//
//end of PART I



//PART II: Registers & Cache
//-----------------------------------------II1:Register-----------------------------------------//
module ysyx_23060229_Register(
	input clk,
	input rst,
	input wen,
	input [31:0] wdata,
	input [3:0] waddr,
	input [3:0] raddr1, raddr2,
	output [31:0] rdata1, rdata2
	//`ifdef simulation//不再引出
	//,output reg[31:0] Reg[0:15]
	//`endif
);

	//`ifndef simulation
	reg[31:0] Reg[0:15];
	//`endif
	//直接读，不必等时钟
	assign rdata1 = Reg[raddr1];
	assign rdata2 = Reg[raddr2];

	
	always @(posedge clk) begin
		if(rst) begin
			Reg[0] <= 0;
			//$display("Register resetting ...");
			//$readmemh("resource/reg.hex", Reg);
		end

		else if(wen && |waddr) begin//考虑到JARL和JAR指令可能写0号reg
			Reg[waddr] <= wdata;
		end
	end

endmodule
//-----------------------------------------end-of-Register-----------------------------------------//



//-----------------------------------------II2:CSRegister-----------------------------------------//
module ysyx_23060229_CSRegister(
	input clk,
	input rst,
	input [7:0] wen,//注意此处的wen比较特殊，因为可能涉及到ecall等
					//一条指令写多个CS寄存器的情况
	
	input [31:0] wdata,
	input [11:0] waddr, raddr,
	output [31:0] rdata,
	output reg excp_written,
	output [31:0] mtvec,//供IFU跳转
	output [31:0] mepc//供ExceptionCtl使用
);

	//目前只支持8个(mstatus,mtvec,mepc,mcause,mvendorid,marchid,剩下两个备用)
	//0-3号分别存放mstatus,mtvec,mepc,mcause; 4-5号存放mvendorid,marchid
	reg [31:0] CSReg [0:7];

	assign mtvec = CSReg[1];
	assign mepc = CSReg[2];

	assign rdata = 	(raddr == 12'h300) ? CSReg[0] ://mstatus
					(raddr == 12'h305) ? CSReg[1] ://mtvec
					(raddr == 12'h341) ? CSReg[2] ://mepc
					(raddr == 12'h342) ? CSReg[3] ://mcause
					(raddr == 12'hf11) ? CSReg[4] ://mvendorid
					(raddr == 12'hf12) ? CSReg[5] ://marchid
					0;

	always @(posedge clk) begin
		excp_written <= 0;
		if(rst) begin
			CSReg[4] <= 32'h79737978;
			CSReg[5] <= 32'h015fdf05;
			//$display("CSRegister resetting ...");
			//$readmemh("resource/csreg.hex",CSReg);
		end
		else if(wen[7]) begin//wen = 8'b1xxx_xxxx, 说明要写入
			case(waddr)
            	12'h300: CSReg[0] <= wdata;//mstatus
                12'h305: CSReg[1] <= wdata;//mtvec
                12'h341: CSReg[2] <= wdata;//mepc
                12'h342: CSReg[3] <= wdata;//mcause
                default: ;
            endcase
			if(wen[6]) begin//wen = 8'b11xx_xxxx, 说明要额外写入异常, 其中低6位为异常原因
				CSReg[3] <= {26'b0, wen[5:0]};
				excp_written <= 1;
			end
		end
	end
endmodule
//-----------------------------------------end-of-CSRegister-----------------------------------------//



//-----------------------------------------II3:icache-----------------------------------------//
//在icache中offset不对齐不会报错
module ysyx_23060229_icache(
    input clk,
	input rst,//用于fencei的冲刷,并不是全局reset信号
    input wen,
    input [`ysyx_23060229_N-1:0] index,
	input [`ysyx_23060229_M-1:0] offset,
    input valid_data_in,
	input [31-`ysyx_23060229_M-`ysyx_23060229_N:0] tag_data_in,
	input [31:0] data_data_in,
	output valid_data_out,
	output [31-`ysyx_23060229_M-`ysyx_23060229_N:0] tag_data_out,
	output [31:0] data_data_out
	//全部改为双端口
	//inout valid_data,
    //inout [31-`ysyx_23060229_M-`ysyx_23060229_N:0] tag_data,
    //inout [31:0] data_data
);

    //parameter M = 3;//块大小为2^M = 8, 2 insts
    //parameter N = 2;//块数量为2^N = 4

    localparam block_size = (1 << `ysyx_23060229_M);
	localparam inst_num	= (block_size >> 2);
    localparam block_num  = (1 << `ysyx_23060229_N);

    reg                         valid   [0:block_num-1];//用于存放每一个cache块的valid
    reg[31-`ysyx_23060229_M-`ysyx_23060229_N:0]             tag     [0:block_num-1];//用于存放每一个cache块的tag
	reg[31:0]					data	[0:(block_num << (`ysyx_23060229_M-2))-1];//块大小为2^M,可以存放的指令数为2^M/4 = 2^(M-2)

	
	/* verilator lint_off WIDTHEXPAND */
    /* verilator lint_off WIDTHTRUNC */
	//这里要根据实际情况改动,延拓(M-2)个0
	wire [`ysyx_23060229_N+`ysyx_23060229_M-3:0] index_expanded = index;
	wire [`ysyx_23060229_N+`ysyx_23060229_M-3:0] n = (index_expanded << (`ysyx_23060229_M-2)) + (offset >> 2);
	
	integer i;

    always @(posedge clk) begin
		if(rst) begin
			for(i = 0; i < block_num; i = i + 1)
				valid[i] = 0;
		end
			
		else if(wen) begin
            valid[index] <= valid_data_in;
            tag[index] <= tag_data_in;
			data[n] <= data_data_in;//inst_num * index + offset / 4
        end
    end

	assign valid_data_out = valid[index];
	assign tag_data_out = tag[index];
    assign data_data_out = data[n];

endmodule
/* verilator lint_on WIDTHTRUNC */
/* verilator lint_on WIDTHEXPAND */
//-----------------------------------------end-of-icache-----------------------------------------//
//end of PART II



//PART III: Backbone
//-----------------------------------------III1:alu-----------------------------------------//
module ysyx_23060229_alu(
    input [31:0] src1,
    input [31:0] src2,
    input [2:0] cmd,
    output reg[31:0] out
);
	
	wire [31:0] rshifted = (src1 >> src2[4:0]);

    always @(*) begin
        case(cmd)
            3'b000: out = src1 + src2;
            3'b001: out = src1 & src2;
            3'b010: out = src1 | src2;
            3'b011: out = src1 ^ src2;
            3'b100: out = {31'b0, (src1 < src2)};
            3'b101: out = src1 << src2[4:0];
            3'b110: out = rshifted;
            3'b111: out = ({32{src1[31]}} << (32 - src2)) | rshifted;
        endcase
    end

endmodule
//-----------------------------------------end-of-alu-----------------------------------------//



//-----------------------------------------III2:IFU-----------------------------------------//
//采用icache后的IFU,IFU和icacheCtl合并后版本
module ysyx_23060229_IFU(
	input clock,
	input reset,
	input check_quest,
	input stall_quest_fencei,
	input [31:0] pc_jump,
	output reg check_assert,
	
	input readyFromIDU,
	output validToIDU,
	
	output reg[31:0] pc,
    output reg[31:0] inst,

	//axi总线组1
    output [31:0] araddr,//本质为pc
    output arvalid,
    input arready,
    output [3:0] arid,
    output [7:0] arlen,
    output [2:0] arsize,
    output [1:0] arburst,

    //axi总线组2
    input [31:0] rdata,
    input [1:0] rresp,
    input rvalid,
    output rready,
    input rlast,
    input [3:0] rid,

    output rmem_quest

	//output wrong_pred
);
	localparam block_size = (1 << `ysyx_23060229_M);
    localparam block_num  = (1 << `ysyx_23060229_N);

	reg [`ysyx_23060229_M-1:0] tmp_offset;


    reg wen;

    wire valid_in = wen;
	wire [31-`ysyx_23060229_M-`ysyx_23060229_N:0] tag_in = araddr[31:`ysyx_23060229_M+`ysyx_23060229_N];
	wire [31:0] data_in = rdata;

    wire valid_out;
	wire [31-`ysyx_23060229_M-`ysyx_23060229_N:0] tag_out;
	wire [31:0] data_out;
    
	wire [`ysyx_23060229_N-1:0] index = wen ? araddr[`ysyx_23060229_M+`ysyx_23060229_N-1:`ysyx_23060229_M] : 
										pc[`ysyx_23060229_M+`ysyx_23060229_N-1:`ysyx_23060229_M];
    wire [`ysyx_23060229_M-1:0] offset = wen ? tmp_offset : pc[`ysyx_23060229_M-1:0];
	
	wire hit = ((tag_out === pc[31:`ysyx_23060229_M+`ysyx_23060229_N]) & valid_out);

	//修改1:
	ysyx_23060229_icache myicache (clock, stall_quest_fencei|reset, wen, index, offset, valid_in, tag_in, data_in, valid_out, tag_out, data_out);


	parameter   Idle = 2'b00,
                Wait_Rvalid = 2'b01,
                Wait_IDU_Ready = 2'b10;

	reg [1:0] state;
	
	wire wrong_pred = (check_quest & (pc != pc_jump));

	//在第一个状态(Idle)上做好AXI4通信准备
	assign araddr = ((pc >> `ysyx_23060229_M) << `ysyx_23060229_M);
	assign arid = 1;
	assign arlen = (1 << (`ysyx_23060229_M - 2)) - 1;
	assign arsize = 3'b010;
	assign arburst = 2'b01;
	assign rready = (state == Idle & ~hit & ~stall_quest_fencei & ~reset) || (state == Wait_Rvalid);
	assign arvalid = (state == Idle) & (~stall_quest_fencei) & ~reset;

	//branch prediction
	wire [31:0] imm_branch = {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
	wire [31:0] imm_jal = {{11{inst[31]}},inst[31],inst[19:12],inst[20],inst[30:21],1'b0};
	wire is_branch = (inst[6:0] == 7'b1100011);
	wire is_jal = (inst[6:0] == 7'b1101111);
	wire pred_jump = inst[31];//backward taken forward not taken
	wire [31:0] op = (is_branch & pred_jump) ? imm_branch :
					(is_jal) ? imm_jal : 4;

	always @(posedge clock) begin
		//延迟reset策略,防止在axi4总线访问过程中直接进行reset
		//if(reset && state != Wait_Rvalid) begin
		if(reset) begin
			state <= Idle;
			pc <= `ysyx_23060229_RESET_PC; //inst <= 0;
			wen <= 0; tmp_offset <= 0;
		end

		else begin
			case(state)
				Idle: begin
					check_assert <= 0;
					if(~stall_quest_fencei) begin//确保未发生icache冲刷
						if(hit) begin//击中
							inst <= data_out;
							state <= Wait_IDU_Ready;
							`ifdef verilator
								IFU_counter_increase();
								hit_counter_increase();
							`endif
						end	
						else begin//未击中,准备访存
							if(arready) begin
								state <= Wait_Rvalid;
								wen <= 1;
							end
						end
					end
				end


				Wait_Rvalid: begin
                    `ifdef verilator
                        unhit_timer_increase();
                    `endif
					if(rvalid && rresp == 0 && rlast == 0 && rid == arid) begin
                        tmp_offset <= tmp_offset + 4;//持续向icache进行写入
                        if(tmp_offset == pc[`ysyx_23060229_M-1:0])//同时获取可能传给ifu的inst
                            inst <= rdata;
                    end
					if(rvalid && rresp == 0 && rlast && rid == arid) begin
                        state <= Wait_IDU_Ready; wen <= 0;
                        tmp_offset <= 0;//最后一次向icache进行写入
                        if(tmp_offset == pc[`ysyx_23060229_M-1:0])
                            inst <= rdata;
						`ifdef verilator
                            IFU_counter_increase();
                        `endif
						//if(to_reset) begin
                        //    state <= Idle; pc <= mtvec; to_reset <= 0; wen <= 0; inst <= 0;
                        //end
                    end

				end


				Wait_IDU_Ready: begin
					if(readyFromIDU) begin
					   	if(wrong_pred) begin//实际上下游IDU未取指
							check_assert <= 1;
							pc <= pc_jump;
							`ifdef verilator
								flush_counter_increase();
							`endif
						end
						else begin//说明pc_previous对应的跳转指令正确预测了跳转地址
							check_assert <= 1;
							pc <= pc + op;
						end
						state <= Idle;
					end
				end
				
				default: begin
					state <= Idle;
				end
			endcase
		end
	end


	assign validToIDU = ((state == Wait_IDU_Ready) & ~wrong_pred);
	assign rmem_quest = ((state == Idle && ~hit) || (state == Wait_Rvalid));

endmodule
//-----------------------------------------end-of-IFU-----------------------------------------//




//-----------------------------------------III3:IDU-----------------------------------------//
module ysyx_23060229_IDU(
	input clk,
	input rst,
	input loaduse_clear,//loaduse请求清除
	//input wrong_pred,//IFU分支预测错误,等待一轮
	
	input validFromIFU,
	input readyFromEXU,
	output readyToIFU,
	output validToEXU,
	
	input [31:0] inst,//由IF/ID寄存器提供
	input [31:0] pc,
	
	output reg[31:0] pc_out,
	output reg[7:0] typ,
	output reg[31:0] imm,
	output reg[4:0] rs1, rs2,
	output reg[4:0] rd,
	output reg[11:0] csr,//同时提供CSReg的读写地址
	output reg stall_quest_loaduse,
	output reg stall_quest_fencei,
	output reg fc_disenable//ForwardingCtl只选择origin_src1/origin_src2
	
);	
	
	
	wire previous_load = (typ[7:5] == 3'b011);//LB,LH,LW,LBU,LHU
	
	//第一类load-use,use指令只涉及单一源寄存器(rs)
	wire loaduse_case1 = 	(previous_load == 1) && (rd == inst[19:15]);
	//第二类load-use,use指令涉及两个源寄存器
	wire loaduse_case2 =	(previous_load == 1) && (rd == inst[19:15] || rd == inst[24:20]);

	
	parameter	Wait_IFU_Valid = 2'b00,
				Halt = 2'b01,
				Wait_EXU_Ready = 2'b10;
	reg [1:0] state;

	
	assign readyToIFU = (state == Wait_IFU_Valid);
    assign validToEXU = (state == Wait_EXU_Ready);	
		
	integer fd;

	always @(posedge clk) begin
		if(rst) begin
			state <= Wait_IFU_Valid;
			stall_quest_loaduse <= 0;
			stall_quest_fencei <= 0;
			fc_disenable <= 0;
			typ <= 0; //pc_out <= 0;
			rs1 <= 0; rs2 <= 0; rd <= 0; csr <= 0;
		end

		else begin
			case(state)
				Wait_IFU_Valid: begin
					if(validFromIFU) begin//确保IFU预测正确时才进行状态转换
						stall_quest_fencei <= 0;//通常都为0,除非遇到fence.i
											
						pc_out <= pc;
						casez(inst)
							/****************************************************************************************/
							//WriteReg,typ[7:5] = 3'b001,共同点涉及到写寄存器(单目的寄存器rd),不同点在于源寄存器rs数量(2/1/0)
							

							//R类,涉及到双源寄存器,单目的寄存器
							//8'b001-00000, R(rd) = R(rs1) + R(rs2)
							32'b0000000_?????_?????_000_?????_0110011: begin
								typ <= `ysyx_23060229_R_ADD; imm <= 0;
		        	            rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
								`endif
							end	
							
							//8'b001-00001, R(rd) = R(rs1) & R(rs2)
							32'b0000000_?????_?????_111_?????_0110011: begin
        			            typ <= `ysyx_23060229_R_AND; imm <= 0;
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end
							
							//8'b001-00010, R(rd) = R(rs1) | R(rs2)
							32'b0000000_?????_?????_110_?????_0110011: begin
        			            typ <= `ysyx_23060229_R_OR; imm <= 0;
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end
							
							//8'b001-00011, R(rd) = R(rs1) ^ R(rs2)
							32'b0000000_?????_?????_100_?????_0110011: begin
    	    		            typ <= `ysyx_23060229_R_XOR; imm <= 0;
        	        		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end
							
							//8'b001-00100, R(rd) = R(rs1) < R(rs2), less than unsigned
							32'b0000000_?????_?????_011_?????_0110011: begin
        			            typ <= `ysyx_23060229_R_SLTU; imm <= 0;
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end
							
							//8'b001-00101, R(rd) = R(rs1) << R(rs2), shift left logic
							32'b0000000_?????_?????_001_?????_0110011: begin
        		        	    typ <= `ysyx_23060229_R_SLL; imm <= 0;
                			    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
    	            			`endif
							end
							
							//8'b001-00110, R(rd) = R(rs1) >> R(rs2), shift right logic(高位补0)
							32'b0000000_?????_?????_101_?????_0110011: begin
        			            typ <= `ysyx_23060229_R_SRL; imm <= 0;
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end
							
							//8'b001-00111, R(rd) = (signed)R(rs1) >> R(rs2), shift right arithmatic(高位符号延拓)
							32'b0100000_?????_?????_101_?????_0110011: begin
        			            typ <= `ysyx_23060229_R_SRA; imm <= 0;
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end
							
							//8'b001-01000, R(rd) = R(rs1) - R(rs2)
							32'b0100000_?????_?????_000_?????_0110011: begin
        			            typ <= `ysyx_23060229_R_SUB; imm <= 0;
                			    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
	                			`endif
							end
							
							//8'b001-01001, R(rd) = (signed)R(rs1) < (signed)R(rs2), less than
							32'b0000000_?????_?????_010_?????_0110011: begin
        			            typ <= `ysyx_23060229_R_SLT; imm <= 0;
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
								`endif
							end
							
							
							
							
							//I类,涉及单源寄存器+立即数,单目的寄存器
							//8'b001-10000, R(rd) = R(rs1) + imm
							32'b???????_?????_?????_000_?????_0010011: begin
        			            typ <= `ysyx_23060229_I_ADDI; imm <= {{20{inst[31]}},inst[31:20]};
                			    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
        	        			`endif
							end
							
							//8'b001-10001, R(rd) = R(rs1) & imm
							32'b???????_?????_?????_111_?????_0010011: begin
        			            typ <= `ysyx_23060229_I_ANDI; imm <= {{20{inst[31]}},inst[31:20]};
                			    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
	                			`endif
							end
							
							//8'b001-10010, R(rd) = R(rs1) | imm
							32'b???????_?????_?????_110_?????_0010011: begin
        			            typ <= `ysyx_23060229_I_ORI; imm <= {{20{inst[31]}},inst[31:20]};
            	    		    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end
							
							//8'b001-10011, R(rd) = R(rs1) ^ imm
							32'b???????_?????_?????_100_?????_0010011: begin
        			            typ <= `ysyx_23060229_I_XORI; imm <= {{20{inst[31]}},inst[31:20]};
            	    		    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end
							
							//8'b001-10100, R(rd) = R(rs1) < imm, less than imm unsigned
							32'b???????_?????_?????_011_?????_0010011: begin
        	        		    typ <= `ysyx_23060229_I_SLTIU; imm <= {{20{inst[31]}},inst[31:20]};
        			            rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end
							
							//8'b001-10101, R(rd) = R(rs1) << imm, shift left logic imm
							32'b0000000_?????_?????_001_?????_0010011: begin
            	    		    typ <= `ysyx_23060229_I_SLLI; imm <= {27'b0, inst[24:20]};
		        	            rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
    	            			`endif
							end	

							//8'b001-10110, R(rd) = R(rs1) >> imm, shift right logic imm(高位补0)
							32'b0000000_?????_?????_101_?????_0010011: begin
        			            typ <= `ysyx_23060229_I_SRLI; imm <= {27'b0, inst[24:20]};
                			    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end

							//8'b001-10111, R(rd) = (signed)R(rs1) >> imm, shift right arithmetic imm(高位符号延拓)
							32'b0100000_?????_?????_101_?????_0010011: begin
    	    		            typ <= `ysyx_23060229_I_SRAI; imm <= {27'b0, inst[24:20]};
        	        		    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end
							
							//8'b001-11000, R(rd) = (signed)R(rs1) < (signed)imm, less than imm
							32'b???????_?????_?????_010_?????_0010011: begin
        			            typ <= `ysyx_23060229_I_SLTI; imm <= {{20{inst[31]}},inst[31:20]};
            	    		    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
                				`endif
							end




							//U类,涉及pc+立即数,单目的寄存器
							//8'b001-11100, R(rd) = imm + pc
							32'b???????_?????_?????_???_?????_0010111: begin
								typ <= `ysyx_23060229_U_AUIPC; imm <= {inst[31:12],12'h000};
								rs1 <= 0; rs2 <= 0; rd <= inst[11:7];
								stall_quest_loaduse <= 0;
								state <= Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
								`endif
							end

							//8'b001-11110, R(rd) = imm
							32'b???????_?????_?????_???_?????_0110111: begin
        	            		typ <= `ysyx_23060229_U_LUI; imm <= {inst[31:12],12'h000};
            	        		rs1 <= 0; rs2 <= 0; rd <= inst[11:7];
								stall_quest_loaduse <= 0;
								state <= Wait_EXU_Ready;
								`ifdef verilator
									cal_inst_counter_increase();
								`endif
							end
							/****************************************************************************************/


							/****************************************************************************************/
                            //WriteMem,typ[7:5] = 3'b010,共同点涉及到写内存,双源寄存器rs分别用于给出带写数据地址和写入地址
	
							//8'b010-00001, R(rs2)的1B -> Mem(R(rs1) + imm)
            	    		32'b???????_?????_?????_000_?????_0100011: begin
                	    		typ <= `ysyx_23060229_S_SB; imm <= {{20{inst[31]}},inst[31:25],inst[11:7]};
                    			rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
								stall_quest_loaduse <= loaduse_case2;//store的地址由寄存器索引,可能涉及到load-use冲突
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									ma_inst_counter_increase();
	                			`endif
							end

							//8'b010-00011, R(rs2)的2B -> Mem(R(rs1) + imm)
    	    		        32'b???????_?????_?????_001_?????_0100011: begin
        	        		    typ <= `ysyx_23060229_S_SH; imm <= {{20{inst[31]}},inst[31:25],inst[11:7]};
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									ma_inst_counter_increase();
             		   			`endif
							end

							//8'b010-01111, R(rs2)的4B -> Mem(R(rs1) + imm)
							32'b???????_?????_?????_010_?????_0100011: begin
    	    		            typ <= `ysyx_23060229_S_SW; imm <= {{20{inst[31]}},inst[31:25],inst[11:7]};
        	        		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									ma_inst_counter_increase();
								`endif
							end
							/****************************************************************************************/	
							

							/****************************************************************************************/
							//ReadMem,typ[7:5] = 3'b011,共同点涉及到读内存+写寄存器,一个源寄存器rs用于给出读内存地址,一个目的寄存器rd存放读出结果
            	    		
							//8'b011-00000, R(rd) = SEXT[Mem(R(rs1) + imm, 1)]
							32'b???????_?????_?????_000_?????_0000011: begin
		        	            typ <= `ysyx_23060229_I_LB; imm <= {{20{inst[31]}},inst[31:20]};
        		    	        rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									ma_inst_counter_increase();
    	    		        	`endif
							end	
							
							//8'b011-00001, R(rd) = Mem(R(rs1) + imm, 1)
							32'b???????_?????_?????_100_?????_0000011: begin
	        	            	typ <= `ysyx_23060229_I_LBU; imm <= {{20{inst[31]}},inst[31:20]};
    	            		    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									ma_inst_counter_increase();
            	    			`endif
							end
							
							//8'b011-00010, R(rd) = SEXT[Mem(R(rs1) + imm, 2)]
							32'b???????_?????_?????_001_?????_0000011: begin
		    	                typ <= `ysyx_23060229_I_LH; imm <= {{20{inst[31]}},inst[31:20]};
		        	            rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									ma_inst_counter_increase();
			                	`endif
							end	
							
							//8'b011-00011, R(rd) = Mem(R(rs1) + imm, 2)
							32'b???????_?????_?????_101_?????_0000011: begin
        			            typ <= `ysyx_23060229_I_LHU; imm <= {{20{inst[31]}},inst[31:20]};
            	    		    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									ma_inst_counter_increase();
                				`endif
							end
							
							//8'b011-00100, R(rd) = Mem(R(rs1) + imm, 4)
							32'b???????_?????_?????_010_?????_0000011: begin
        			            typ <= `ysyx_23060229_I_LW; imm <= {{20{inst[31]}},inst[31:20]};
                			    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									ma_inst_counter_increase();
                				`endif
							end	
							/****************************************************************************************/

							
							
							/****************************************************************************************/
							//Jump_B,typ[7:5] = 3'b100,均为根据条件判断是否跳转的分支语句,涉及两个源寄存器rs用于提供判断条件

							//8'b100-00000, pc = (R(rs1) == R(rs2)) ? (pc + imm) : (pc + 4)
							32'b???????_?????_?????_000_?????_1100011: begin
								typ <= `ysyx_23060229_B_BEQ; imm <= {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
								rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									branch_inst_counter_increase();
								`endif
							end
	
							//8'b100-00001, pc = (R(rs1) != R(rs2)) ? (pc + imm) : (pc + 4)
							32'b???????_?????_?????_001_?????_1100011: begin
        			            typ <= `ysyx_23060229_B_BNE; imm <= {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									branch_inst_counter_increase();
            		    		`endif
							end
	
							//8'b100-00010, pc = ((signed)R(rs1) < (signed)R(rs2)) ? (pc + imm) : (pc + 4)
							32'b???????_?????_?????_100_?????_1100011: begin
        			            typ <= `ysyx_23060229_B_BLT; imm <= {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									branch_inst_counter_increase();
                				`endif
							end
	
							//8'b100-00011, pc = (R(rs1) < R(rs2)) ? (pc + imm) : (pc + 4)
							32'b???????_?????_?????_110_?????_1100011: begin
        			            typ <= `ysyx_23060229_B_BLTU; imm <= {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									branch_inst_counter_increase();
                				`endif
							end
	
							//8'b100-00100, pc = ((signed)R(rs1) >= (signed)R(rs2)) ? (pc + imm) : (pc + 4)
							32'b???????_?????_?????_101_?????_1100011: begin
        			            typ <= `ysyx_23060229_B_BGE; imm <= {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									branch_inst_counter_increase();
        		        		`endif
							end
	
							//8'b100-00101, pc = (R(rs1) >= R(rs2)) ? (pc + imm) : (pc + 4)
							32'b???????_?????_?????_111_?????_1100011: begin
        			            typ <= `ysyx_23060229_B_BGEU; imm <= {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
            	    		    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
                    			stall_quest_loaduse <= loaduse_case2;
								state <= loaduse_case2 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									branch_inst_counter_increase();
        		    	    	`endif
							end

							
							
							//MRET,特殊的跳转指令并入Jump_B
							//8'b100-01000, pc = `MEPC
							32'b0011000_00010_00000_000_00000_1110011: begin//mret
								typ <= `ysyx_23060229_MRET; imm <= 0;
                			    rs1 <= 0; rs2 <= 0; rd <= 0; csr <= `ysyx_23060229_MEPC;
								stall_quest_loaduse <= 0;
								state <= Wait_EXU_Ready;
								`ifdef verilator
									csr_inst_counter_increase();
        		        		`endif
							end


							//fence.i,特殊的非跳转指令并入Jump_B,负责重置icache
							32'b???????_?????_?????_001_?????_0001111: begin
                                typ <= `ysyx_23060229_FENCEI; imm <= 0;
                                rs1 <= 0; rs2 <= 0; rd <= 0;
                                stall_quest_loaduse <= 0;
								stall_quest_fencei <= 1;
                                state <= Wait_EXU_Ready;
                            end
							/****************************************************************************************/
	
							
							/****************************************************************************************/
							//Jump_J, typ[7:5] = 3'b101, 直接跳转指令, 涉及一个目的寄存器rd用于存放pc+4,一个源寄存器rs用于提供跳转地址
							
							//8'b101-00000, R(rd) = pc + 4; pc = pc + imm
							32'b???????_?????_?????_???_?????_1101111: begin
        			            typ <= `ysyx_23060229_J_JAL; imm <= {{11{inst[31]}},inst[31],inst[19:12],inst[20],inst[30:21],1'b0};
                			    rs1 <= 0; rs2 <= 0; rd <= inst[11:7];
								stall_quest_loaduse <= 0;
								state <= Wait_EXU_Ready;
								`ifdef verilator
									branch_inst_counter_increase();
	                			`endif
							end

							//8'b101-00001, R(rd) = pc + 4; pc = (R(rs1) + imm) & 0xffff_fffe
							32'b???????_?????_?????_000_?????_1100111: begin
            	    		    typ <= `ysyx_23060229_I_JALR; imm <= {{20{inst[31]}},inst[31:20]};
		        	            rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									branch_inst_counter_increase();
			                	`endif
							end	
							/****************************************************************************************/



							/****************************************************************************************/
							//WriteCSReg, typ[7:5] = 3'b110, 写寄存器和状态寄存器
							
							//8'b110-00000, R(rd) = SR(csr), SR(csr) = R(rs1)
							32'b???????_?????_?????_001_?????_1110011: begin
            	    		    typ <= `ysyx_23060229_I_CSRRW; imm <= {27'b0, inst[19:15]};
		        	            rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7]; csr <= inst[31:20];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									csr_inst_counter_increase();
			                	`endif
							end	
	
							//8'b110-00001, R(rd) = SR(csr), SR(csr) = imm
							32'b???????_?????_?????_101_?????_1110011: begin
        			            typ <= `ysyx_23060229_I_CSRRWI; imm <= {27'b0, inst[19:15]};
                			    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7]; csr <= inst[31:20];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									csr_inst_counter_increase();
	                			`endif
							end
	
							//8'b110-00010, R(rd) = SR(csr), SR(csr) = R(rs1) | SR(csr), read set
							32'b???????_?????_?????_010_?????_1110011: begin
        			            typ <= `ysyx_23060229_I_CSRRS; imm <= {27'b0, inst[19:15]};
            	    		    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7]; csr <= inst[31:20];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									csr_inst_counter_increase();
                				`endif
							end

							//8'b110-00011, R(rd) = SR(csr), SR(csr) = imm | SR(csr), read set imm
							32'b???????_?????_?????_110_?????_1110011: begin
    	    		            typ <= `ysyx_23060229_I_CSRRSI; imm <= {27'b0, inst[19:15]};
        	        		    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7]; csr <= inst[31:20];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									csr_inst_counter_increase();
                				`endif
							end
	
							//8'b110-00100, R(rd) = SR(csr), SR(csr) = R(rs1) & SR(csr), read clear
							32'b???????_?????_?????_011_?????_1110011: begin
        			            typ <= `ysyx_23060229_I_CSRRC; imm <= {27'b0, inst[19:15]};
            	    		    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7]; csr <= inst[31:20];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									csr_inst_counter_increase();
                				`endif
							end
	
							//8'b110-00101, R(rd) = SR(csr), SR(csr) = imm & SR(csr), read clear imm
							32'b???????_?????_?????_111_?????_1110011: begin
        			            typ <= `ysyx_23060229_I_CSRRCI; imm <= {27'b0, inst[19:15]};
            	    		    rs1 <= inst[19:15]; rs2 <= 0; rd <= inst[11:7]; csr <= inst[31:20];
                    			stall_quest_loaduse <= loaduse_case1;
								state <= loaduse_case1 ? Halt : Wait_EXU_Ready;
								`ifdef verilator
									csr_inst_counter_increase();
                				`endif
							end
							/****************************************************************************************/
	




							/****************************************************************************************/
							//Jump_CS, typ[7:5] = 3'b111, 特殊跳转指令

							//ECALL写入MEPC和MCAUSE，跳转至MTVEC
							32'b0000000_00000_00000_000_00000_1110011: begin//ecall
								`ifdef verilator
                                    $display("Exception: Ecall in IDU! Error pc: %x", pc);
                                `endif
        			        	typ <= `ysyx_23060229_ECALL; 
								imm <= 0;
            	    		    rs1 <= 0; rs2 <= 0; rd <= 0; csr <= `ysyx_23060229_MTVEC;
								stall_quest_loaduse <= 0;
								state <= Wait_EXU_Ready;
								`ifdef verilator
									csr_inst_counter_increase();
								`endif
							end
							/****************************************************************************************/


    			            32'b0000000_00001_00000_000_00000_1110011: begin//ebreak
            			        typ <= `ysyx_23060229_EBREAK; imm <= 0; rs1 <= 0; rs2 <= 0; rd <= 0;
								stall_quest_loaduse <= 0;
								state <= Wait_EXU_Ready;
    		            	end

							default: begin//异常illegal inst处理
								`ifdef verilator
									$display("Exception: Illegal Instruction in IDU! Error pc: %x", pc);
								`endif
								typ <= `ysyx_23060229_NONE;
								state <= Wait_EXU_Ready;
							end
            			endcase
					end
				end

				Halt: begin
					fc_disenable <= 1;
					if(loaduse_clear) begin
						state <= Wait_EXU_Ready;
						stall_quest_loaduse <= 0;//必须要清零，否则StallingCtl可能执行多个循环
					end
				end

				Wait_EXU_Ready: begin
					stall_quest_fencei <= 0;
					if(readyFromEXU) begin
						state <= Wait_IFU_Valid;
						stall_quest_loaduse <= 0; //stall_quest_fencei <= 0;
						fc_disenable <= 0;
					end
				end

				default: begin
					state <= Wait_IFU_Valid;
					stall_quest_loaduse <= 0;
					fc_disenable <= 0;
				end
			endcase
		end
	end

endmodule
//-----------------------------------------end-of-IDU-----------------------------------------//



//-----------------------------------------III4:EXU-----------------------------------------//
module ysyx_23060229_EXU(
	input clk,
	input rst,
	input validFromIDU,
	input readyFromLSU,
	output readyToIDU,
	output validToLSU,
	
	input [31:0] pc,//来自ID/EX寄存器
	input [7:0] typ,//以下input均来自ID/EX寄存器
	input [31:0] imm,
	input [4:0] rd,
	input [11:0] csr,
	input [31:0] src1, src2,
	input [31:0] srccs,

	output reg[7:0] typ_out,
	//`ifdef simulation
	output reg[31:0] pc_out,//为确保ExceptionCtl正常工作必须为32 bit
	//`else
	//output reg pc_out,
	//`endif
	output [2:0] flag,
	output reg[4:0] dest_reg,//寄存器地址
	output reg[31:0] result_reg,
	output reg[31:0] dest_csreg_mem,//mem地址和csreg地址合并
	output reg[31:0] result_csreg_mem,
	output reg[31:0] pc_jump,//可能的跳转地址

	input check_assert,
	output reg check_quest,

	input LSU_arready_set,
	input LSU_awready_set	
);

	assign flag = typ_out[7:5];


	//scomp生成SLT/SLTI的结果
    //wire scomp_out;
    //wire [31:0] scomp_op = typ[4] ? imm : src2;
	//ysyx_23060229_scomp myscomp(src1, scomp_op, scomp_out);


	wire scomp_out;
    wire overflow;
    wire [31:0] scomp_op = typ[4] ? imm : src2;
    wire [31:0] sub;
    assign sub = src1 - scomp_op;
    assign overflow = (src1[31] != scomp_op[31]) && (sub[31] != src1[31]);
    assign scomp_out = sub[31] ^ overflow;


	//alu生成大多数cal类指令结果
	wire [31:0] alu_out;
	wire [31:0] alu_op = typ[4] ? imm : src2;
	ysyx_23060229_alu myalu(src1, alu_op, typ[2:0], alu_out);


	//用于判断Jump_B指令的条件是否成立
	wire isequal = (src1 == src2);
	wire isless = (src1 < src2);
	wire JumpB_cond =    (typ[2:0] == 3'b000) ? isequal :
                         (typ[2:0] == 3'b001) ? ~isequal :
                         (typ[2:0] == 3'b010) ? scomp_out :
                         (typ[2:0] == 3'b011) ? isless :
                         (typ[2:0] == 3'b100) ? ~scomp_out :
                         (typ[2:0] == 3'b101) ? ~isless : 1'b1;
	

	//用于生成WriteCSReg指令的写入CSReg结果
	wire [31:0] op = typ[0] ? imm : src1;
	wire [31:0] WriteCSReg_Result = (typ[2:1] == 2'b00) ? op :
									(typ[2:1] == 2'b01) ? (op|srccs) : (op&srccs);


	//用于生成常用跳转/索引地址
	wire [31:0] pc_plus_4 = pc + 4;
	wire [31:0] pc_plus_imm = pc + imm;
	wire [31:0] src1_plus_imm = src1 + imm;

	parameter	Wait_IDU_Valid = 1'b0,
				Wait_LSU_Ready = 1'b1;
	reg state;
	
	
	always @(posedge clk) begin
		if(rst) begin
			state <= Wait_IDU_Valid;
			check_quest <= 0;
			typ_out <= 0; pc_out <= 0; pc_jump <= `ysyx_23060229_RESET_PC;
			dest_reg <= 0; //dest_csreg_mem <= 0;
			//`ifdef verilator $display("EXU resetting ..."); `endif
		end

		else begin
			if(check_assert)
				check_quest <= 0;
			case(state)
				Wait_IDU_Valid: begin
					state <= validFromIDU ? Wait_LSU_Ready : Wait_IDU_Valid;
					if(validFromIDU) begin
						//`ifdef simulation
							pc_out <= pc;
							//EXU_counter_increase();
						//`else
						//	pc_out <= pc[2];
						//`endif
						
						`ifdef verilator
							EXU_counter_increase();
						`endif

						typ_out <= typ; 
						
						//待写入Reg的结果大多由alu计算生成,少数特例见下述WriteReg/Jump_J/WriteCSReg中情形
						result_reg <= alu_out;
						//Reg目的地址均为rd
						dest_reg <= rd;

						//当typ[7:5] = 3'b110(WriteCSReg)/3'b111(Jump_CS)时,result_csreg_mem视为result_csreg,否则视为result_mem
						result_csreg_mem <=   (typ[7:5] == 3'b110) ? WriteCSReg_Result : (typ[7:5] == 3'b111) ? pc : src2;
						//当typ[7:5] = 3'b110(WriteCSReg)/3'b111(Jump_CS)时,dest_csreg_mem视为dest_csreg,否则视为dest_mem
						dest_csreg_mem <= (typ[7:5] == 3'b110) ? {20'b0,csr} : (typ[7:5] == 3'b111) ? {20'b0,`ysyx_23060229_MEPC} : src1_plus_imm;
						

						//case(typ[7:5])
						if(typ[7:5] == `ysyx_23060229_WriteReg) begin
								case(typ[4:0])
									5'b01000: result_reg <= src1 - src2;//SUB
									5'b01001: result_reg <= {31'b0, scomp_out};//SLT
									5'b11000: result_reg <= {31'b0, scomp_out};//SLTI
									5'b11100: result_reg <= pc_plus_imm;//AUIPC
									5'b11110: result_reg <= imm;//LUI
									default: ;
								endcase
						end
							

						if(typ[7:5] == `ysyx_23060229_Jump_B) begin
								check_quest <= 1;//Jump_B的预测结果可能错误,因而需发出check_quest
								pc_jump <= JumpB_cond ? pc_plus_imm : pc_plus_4;
								if(typ[3]) begin//是MRET
									pc_jump <= srccs;
								end
								if(typ[4]) begin//是fencei
									check_quest <= 0;
								end
						end
							

						if(typ[7:5] == `ysyx_23060229_Jump_J) begin
								check_quest <= typ[0];//JAL的预测结果必然正确,无需发出check_quest;JALR的预测结果大概率错误,需发出check_quest
								pc_jump <= typ[0] ? ((src1_plus_imm)&(32'hffff_fffe)) : pc_plus_imm;
								result_reg <= pc_plus_4; 
						end


						if(typ[7:5] == `ysyx_23060229_WriteCSReg) begin
								result_reg <= srccs; 
						end


            			if(typ[7:5] == `ysyx_23060229_Jump_CS) begin//ECALL的预测结果大概率错误,因而需发出check_quest
								check_quest <= 1;
								pc_jump <= srccs;
						end
							

						`ifdef verilator
						if(typ[7:5] == `ysyx_23060229_Invalid) begin
								if(typ[0]) begin hit_good_trap(); end//ebreak,特殊的invalid
								else ; //hit_bad_trap(); //else 处理Illegal Inst异常
						end
						`endif
						
						`ifdef ysyx_23060229_sim_iverilog
						if(typ[7:5] == `ysyx_23060229_Invalid) begin
								if(typ[0]) begin $finish; end//ebreak,特殊的invalid
								else ; //hit_bad_trap(); //else 处理Illegal Inst异常
						end
						`endif
						
					end
				end

				Wait_LSU_Ready: begin
					if(flag == `ysyx_23060229_ReadMem)
						state <= (readyFromLSU & LSU_arready_set) ? Wait_IDU_Valid : state;
					else if(flag == `ysyx_23060229_WriteMem)
						state <= (readyFromLSU & LSU_awready_set) ? Wait_IDU_Valid : state;
					else
						state <= readyFromLSU ? Wait_IDU_Valid : state;
				end

				default: begin
					state <= Wait_IDU_Valid;
				end
			endcase
		end
	end

	assign validToLSU = state;
	assign readyToIDU = ~state;

endmodule
//-----------------------------------------end-of-EXU-----------------------------------------//



//-----------------------------------------III5:LSU-----------------------------------------//
//默认不采用多突发传输;默认awlen=0, awsize=3'b010, arburst=0, arid=2
//假设主机发出的arid均为2,awid均为3
module ysyx_23060229_LSU(
	input clock,
	input rst,

	input validFromEXU,
	output readyToEXU,
	
	//`ifdef simulation
	input [31:0] pc,
	//`else
	//input pc,
	//`endif
	input [7:0] typ,
	input [4:0] dest_reg,//reg的写地址
	input [31:0] result_reg,//reg的写内容
	input [31:0] dest_csreg_mem,//csreg/mem的读/写地址
	input [31:0] result_csreg_mem,//csreg/mem的写内容
	input [31:0] pc_jump,

	output reg[4:0] waddr_reg,
	output reg[31:0] wdata_reg,
	output reg[11:0] waddr_csreg,
	output reg[31:0] wdata_csreg,
	output reg wen_reg,
	output reg[7:0] wen_csreg,
	//`ifdef simulation//不再引出pc因此只需1bit
	//output reg[31:0] pc_out,
	//`else
	output reg pc_out,//用于StallingCtl
	//`endif
	
	//`ifdef simulation//不再引出
	//output reg one_inst_done,
	//`endif
	output reg previous_load_done,//用于StallingCtl


	//axi总线组1
    output [31:0] araddr,
    output arvalid,
    input arready,
	output [3:0] arid,
	output [7:0] arlen,
	output [2:0] arsize,
	output [1:0] arburst,

    //axi总线组2
    input [31:0] rdata,
    input [1:0] rresp,
    input rvalid,
    output rready,
	input rlast,
	input [3:0] rid,

    //axi总线组3
    output [31:0] awaddr,
    output awvalid,
    input awready,
	output [3:0] awid,
	output [7:0] awlen,
	output [2:0] awsize,
	output [1:0] awburst,

    //axi总线组4
    output [31:0] wdata,
    output [3:0] wstrb,
    output wvalid,
    input wready,
	output wlast,

    //axi总线组5
    input [1:0] bresp,
    input bvalid,
    output bready,
	input [3:0] bid,

	output rmem_quest_LSU,

	output LSU_arready_set,
	output LSU_awready_set
);
	
	wire [2:0] flag = typ[7:5];
	
	parameter	Wait_EXU_Valid = 3'b000,
				Wait_Rvalid = 3'b001,
				Wait_Wready = 3'b010,
				Wait_Awready = 3'b011,
				Wait_Bvalid = 3'b100;
	reg [2:0] state;
	


	//说明LSU已经取走了内存读写地址
	assign LSU_arready_set = arready;
	assign LSU_awready_set = awready;
	
	//暂存的araddr,awaddr,typ
	reg [31:0] araddr_tmp;
	reg [31:0] awaddr_tmp;
	reg [7:0] typ_tmp;


	//用于WriteReg时生成写入的数据
    wire [7:0] slice1 = (araddr_tmp[1:0] == 2'b00) ? rdata[7:0] :
                        (araddr_tmp[1:0] == 2'b01) ? rdata[15:8] :
                        (araddr_tmp[1:0] == 2'b10) ? rdata[23:16] : rdata[31:24];
    wire [15:0] slice2 = (araddr_tmp[1:0] == 2'b00) ? rdata[15:0] : rdata[31:16];



	//AR和R通道时刻做好准备
	assign arlen = 0;
	assign arburst = 0;
	assign arid = 2;
	assign arsize = typ[3:1];
	//assign arsize = (typ == `ysyx_23060229_I_LB || typ == `ysyx_23060229_I_LBU) ? 3'b000 : 
	//				(typ == `ysyx_23060229_I_LH || typ == `ysyx_23060229_I_LHU) ? 3'b001 : 3'b010;
	assign araddr = (state == Wait_EXU_Valid && flag == `ysyx_23060229_ReadMem && validFromEXU) ? dest_csreg_mem : araddr_tmp;

	assign arvalid = (state == Wait_EXU_Valid && flag == `ysyx_23060229_ReadMem && validFromEXU);
	assign rready = (state == Wait_EXU_Valid && flag == `ysyx_23060229_ReadMem && validFromEXU) || (state == Wait_Rvalid);


	//AW,W和B通道时刻做好准备
	assign awlen = 0;
	assign awburst = 0;
	assign wlast = 1;
	assign awid = 3;
	assign awsize = (typ == `ysyx_23060229_S_SB) ? 3'b000 : 
					(typ == `ysyx_23060229_S_SH) ? 3'b001 : 3'b010;
	assign wdata = (result_csreg_mem << {dest_csreg_mem[1:0], 3'b0});
	//assign wdata = 	(dest_csreg_mem[1:0] == 2'b00) ? result_csreg_mem :
    //                (dest_csreg_mem[1:0] == 2'b01) ? (result_csreg_mem << 8) :
    //                (dest_csreg_mem[1:0] == 2'b10) ? (result_csreg_mem << 16) : (result_csreg_mem << 24);
	assign wstrb = (typ[3:0] << dest_csreg_mem[1:0]);
    assign awaddr = (state == Wait_EXU_Valid && flag == `ysyx_23060229_WriteMem && validFromEXU) ? dest_csreg_mem : awaddr_tmp;


	assign awvalid = (state == Wait_EXU_Valid && flag == `ysyx_23060229_WriteMem && validFromEXU) || (state == Wait_Awready);
	assign wvalid =  (state == Wait_EXU_Valid && flag == `ysyx_23060229_WriteMem && validFromEXU) || (state == Wait_Wready);
	assign bready = (state == Wait_EXU_Valid && flag == `ysyx_23060229_WriteMem && validFromEXU) || (state == Wait_Awready) || (state == Wait_Wready) 
					|| (state == Wait_Bvalid);


	assign readyToEXU = (state == Wait_EXU_Valid || state == Wait_Awready);


	always @(posedge clock) begin
		//if(rst && state == Wait_EXU_Valid) begin//确保reset时AXI传输未开始
		if(rst) begin
			state <= Wait_EXU_Valid;
			wen_reg <= 0; wen_csreg <= 0;
			pc_out <= 0;
			previous_load_done <= 0;
			//`ifdef verilator $display("LSU resetting ..."); `endif
		end

		else begin
			case(state)
				Wait_EXU_Valid: begin
				wen_reg <= 0; wen_csreg <= 0;
				//`ifdef simulation 	one_inst_done <= 0; `endif

				if(validFromEXU) begin	
					typ_tmp <= typ; araddr_tmp <= dest_csreg_mem;
					//`ifdef simulation
					//	pc_out <= pc;
					//`else
						pc_out <= pc[2];
					//`endif
			
					waddr_reg <= dest_reg; wdata_reg <= result_reg;
					previous_load_done <= 0;

					

					if(flag == `ysyx_23060229_WriteReg) begin//仅写reg
                        wen_reg <= 1; wen_csreg <= 0;
                        state <= Wait_EXU_Valid;
                       	//`ifdef simulation one_inst_done <= 1; `endif
                    end
					if(flag == `ysyx_23060229_WriteCSReg) begin//写reg和csreg
                        waddr_csreg <= dest_csreg_mem[11:0]; wdata_csreg <= result_csreg_mem;
                        wen_reg <= 1; wen_csreg <= 8'b10000000;
                        state <= Wait_EXU_Valid;
                        //`ifdef simulation one_inst_done <= 1; `endif
                    end
					
					

					if(flag == `ysyx_23060229_Jump_J) begin//仅写reg
                        wen_reg <= 1;
						state <= Wait_EXU_Valid;
						waddr_csreg <= `ysyx_23060229_MEPC; wdata_csreg <= pc;
						wen_csreg <= 0;
                    end
					if(flag == `ysyx_23060229_Jump_CS) begin//仅写csreg,就是ecall
						wen_reg <= 0;
						state <= Wait_EXU_Valid;
						waddr_csreg <= `ysyx_23060229_MEPC; wdata_csreg <= pc;
						wen_csreg <= 8'b11001011;
					end
					if(flag == `ysyx_23060229_Jump_B) begin//啥都不做，比如Jump_B
						wen_reg <= 0;
                        state <= Wait_EXU_Valid;
                        waddr_csreg <= `ysyx_23060229_MEPC; wdata_csreg <= pc;
						wen_csreg <= 0;
					end


					if(flag == `ysyx_23060229_ReadMem) begin//读mem+写reg
						wen_reg <= 0;
						state <= Wait_EXU_Valid;
                        waddr_csreg <= `ysyx_23060229_MEPC; wdata_csreg <= pc;
						if(arready) begin
							wen_csreg <= 0; state <= Wait_Rvalid; //araddr_tmp <= dest_csreg_mem;
						end
					end
					if(flag == `ysyx_23060229_WriteMem) begin//写mem
						if(awready & wready) begin
							state <= Wait_Bvalid; 
							awaddr_tmp <= dest_csreg_mem;
						end
						else if(awready) begin
							state <= Wait_Wready;
							awaddr_tmp <= dest_csreg_mem;
						end
						else if(wready) begin
							state <= Wait_Awready;
							awaddr_tmp <= dest_csreg_mem;
						end
					end
					
					
					if(flag == `ysyx_23060229_Invalid) begin//由于ebreak已经在EXU中用hit_good_trap处理过了,所以这里只有illegal inst
						wen_csreg <= 8'b11000010;//excp.no = 0x2
						wen_reg <= 0;
						waddr_csreg <= `ysyx_23060229_MEPC; wdata_csreg <= pc;
						state <= Wait_EXU_Valid;
					end
				
				end

				end
				


				Wait_Rvalid: begin
					if(rvalid && rresp == 0 && rlast && rid == arid) begin
						previous_load_done <= 1;
						`ifdef verilator
							LSU_counter_increase();
						`endif
						//`ifdef simulation one_inst_done <= 1;`endif
						state <= Wait_EXU_Valid;
						wen_reg <= 1; wen_csreg <= 0;
						wdata_reg <= 	(typ_tmp[2:0] == 3'b000) ? {{24{slice1[7]}}, slice1} : 
										(typ_tmp[2:0] == 3'b001) ? {24'b0, slice1} : 
										(typ_tmp[2:0] == 3'b010) ? {{16{slice2[15]}}, slice2} : 
										(typ_tmp[2:0] == 3'b011) ? {16'b0, slice2} : rdata;
					end
					
					`ifdef verilator
					if(rvalid && rresp == 2'b11) begin
						//$display("Access Fault in LSU (type:R)! Simulation Aborted...\n");
						hit_bad_trap();
					end
					`endif
				end


				Wait_Wready: begin
					state <= wready ? Wait_Bvalid : state;
				end

				Wait_Awready: begin
					state <= awready ? Wait_Bvalid : state;
				end



				Wait_Bvalid: begin
					if(bvalid && bresp == 0 && bid == awid) begin
						wen_reg <= 0; wen_csreg <= 0;//不写reg
						state <= Wait_EXU_Valid;
						`ifdef verilator
							LSU_counter_increase();
						`endif
						//`ifdef simulation one_inst_done <= 1; `endif
					end
					`ifdef verilator
					if(bvalid && bresp == 2'b11) begin
						//$display("Access Fault in LSU (type:W)! Simulation Aborted...\n");
						hit_bad_trap();
					end
					`endif
				end	

				default: begin
                    state <= Wait_EXU_Valid;
				end
			endcase
		end
	end

	assign rmem_quest_LSU = (state == Wait_Rvalid) || (state == Wait_EXU_Valid && flag == `ysyx_23060229_ReadMem && validFromEXU);

endmodule
//-----------------------------------------end-of-LSU-----------------------------------------//
//end of PART III






//PART IV:Auxiliary
//-----------------------------------------IV1:CLINT-----------------------------------------//
//0xa0000048 - 0xa000004f 定时器地址范围
//目标:实现一个基于AXI-lite总线协议的CLINT模块,只读
module ysyx_23060229_CLINT(
	input clk,
	input rst,

	//AR，读通道，CPU读取CLINT
    input [31:0] araddr,
    input arvalid,
    output arready,
	input [3:0] arid,
	//input [7:0] arlen,
	//input [2:0] arsize,
    //input [1:0] arburst,

    //R，同上
    output [31:0] rdata,
    output [1:0] rresp,
    output rvalid,
    input rready,
    output rlast,
    output [3:0] rid

);

	parameter   Wait_Arvalid = 1'b0,
                Wait_Rready = 1'b1;

    reg state_r;

	reg [63:0] mtime;//mtime寄存器
	
	always @(posedge clk)
		mtime <= rst ? 0 : (mtime + 1);


    //状态机r，和读CLINT有关
    always @(posedge clk) begin
        if(rst) begin
            state_r <= Wait_Arvalid;
        end

        else begin
            case(state_r)
                Wait_Arvalid: begin
                    if(arvalid == 1) begin//0200_0000 - 0200_ffff
						//rdata <= (araddr == `CLINT_BASE) ? mtime[31:0] :
						//		((araddr == `CLINT_BASE + 4) ? mtime[63:32] : 0 );
                        //0200_0000 - 0200_ffff,实际上只用了0200_0000- 0200_0007
						//读地址只有两个,分别是0200_0000和0200_0004
						//rdata <= araddr[2] ? mtime[63:32] : mtime[31:0];
						state_r <= Wait_Rready;
                    end
                end

                Wait_Rready: begin
                    state_r <= rready ? Wait_Arvalid : state_r;
                end

            endcase
        end
    end

	assign rdata = araddr[2] ? mtime[63:32] : mtime[31:0];
	
	
	assign arready = ~state_r;
	assign rvalid = state_r;

	//用不到
	assign rresp = 0;
	assign rlast = 1;
	assign rid = arid;

endmodule
//-----------------------------------------end-of-CLINT-----------------------------------------//



//-----------------------------------------IV2:miniXbar-----------------------------------------//
//一个多入(IFU与LSU)多出(SRAM和UART等)的Xbar/总线桥模块
//或许rresp和bresp可以用下游信号赋值
module ysyx_23060229_miniXbar(
	input clk,
	input rst,
	
	input rmem_quest_IFU,
	input rmem_quest_LSU,

	/******************************IFU的axi接口*****************************/
    //IFU-AR
    input [31:0] araddr_IFU,//cpu发送的读地址
    input arvalid_IFU,//cpu发来的读地址有效
    output arready_IFU,//mem准备好去读cpu发来的读地址
	input [3:0] arid_IFU,
	input [7:0] arlen_IFU,
	input [2:0] arsize_IFU,
	input [1:0] arburst_IFU,

    //axi-R,mem为master，cpu为slave
    output [31:0] rdata_IFU,//mem发送的读出数据
    output [1:0] rresp_IFU,//mem发送读状态
    output rvalid_IFU,//mem发送的读出数据有效
    input rready_IFU,//cpu准备好去读mem发来的读出数据
	output rlast_IFU,
	output [3:0] rid_IFU,


	/*******************************LSU的总线接口**************************/
    input [31:0] araddr_LSU,//cpu发送的读地址
    input arvalid_LSU,//cpu发来的读地址有效
    output arready_LSU,//mem准备好去读cpu发来的读地址
	input [3:0] arid_LSU,
	input [7:0] arlen_LSU,
	input [2:0] arsize_LSU,
	input [1:0] arburst_LSU,

    //axi-R,mem为master，cpu为slave
    output [31:0]  rdata_LSU,//mem发送的读出数据
    output [1:0] rresp_LSU,//mem发送读状态
    output rvalid_LSU,//mem发送的读出数据有效
    input rready_LSU,//cpu准备好去读mem发来的读出数据
	output rlast_LSU,
	output [3:0] rid_LSU,

    //axi-AW,cpu为master，mem为slave
    input [31:0] awaddr_LSU,//cpu发送的写地址
    input awvalid_LSU,//cpu发送的写地址有效
    output awready_LSU,//mem准备好去读cpu发来的写地址
	input [3:0] awid_LSU,
	input [7:0] awlen_LSU,
	input [2:0] awsize_LSU,
	input [1:0] awburst_LSU,

	//axi-W，cpu为master，mem为slave
    input [31:0] wdata_LSU,//cpu发送的写数据
    input [3:0] wstrb_LSU,//cpu发送的写掩码
    input wvalid_LSU,//cpu发送的写数据有效
    output wready_LSU,//mem准备好去读mem发来的写数据
	input wlast_LSU,

    //axi-B，mem为master，cpu为slave
    output [1:0] bresp_LSU,//mem发送的写状态
    output bvalid_LSU,//mem发送的写状态有效
    input bready_LSU,//cpu准备好去读mem发送的写状态
	output [3:0] bid_LSU,
	

	/*************************与Xbar连接的axi总线信号**********************/
    //axi-AR
    output [31:0] araddr_xbar,//即
    output arvalid_xbar,
    input arready_xbar,
	output [3:0] arid_xbar,
	output [7:0] arlen_xbar,
	output [2:0] arsize_xbar,
	output [1:0] arburst_xbar,

    //axi-R
    input [31:0] rdata_xbar,
    input [1:0] rresp_xbar,
    input rvalid_xbar,
    output rready_xbar,
	input rlast_xbar,
	input [3:0] rid_xbar,

    //axi-AW
    output [31:0] awaddr_xbar,
    output awvalid_xbar,
    input awready_xbar,
	output [3:0] awid_xbar,
	output [7:0] awlen_xbar,
	output [2:0] awsize_xbar,
	output [1:0] awburst_xbar,

    //axi-W
    output [31:0] wdata_xbar,
    output [3:0] wstrb_xbar,
    output wvalid_xbar,
    input wready_xbar,
	output wlast_xbar,

    //axi-B
    input [1:0] bresp_xbar,
    input bvalid_xbar,
    output bready_xbar,
	input [3:0] bid_xbar,


	/************************与CLINT连接的axi总线信号**********************/
    //axi-AR
    output [31:0] araddr_clint,
    output arvalid_clint,
    input arready_clint,
	output [3:0] arid_clint,
	//output [7:0] arlen_clint,
	//output [2:0] arsize_clint,
	//output [1:0] arburst_clint,

    //axi_R
    input [31:0] rdata_clint,
    input [1:0] rresp_clint,
    input rvalid_clint,
    output rready_clint,
	input rlast_clint,
	input [3:0] rid_clint

);

	//中间变量
	//axi总线组1
    wire [31:0] araddr;
    wire arvalid;
    wire arready;
	wire [3:0] arid;
	wire [7:0] arlen;
	wire [2:0] arsize;
	wire [1:0] arburst;

    //axi总线组2
    wire [31:0] rdata;
    wire [1:0] rresp;
    wire rvalid;
    wire rready;
	wire rlast;
	wire [3:0] rid;

    //axi总线组3
    wire [31:0] awaddr;
    wire awvalid;
    wire awready;
	wire [3:0] awid;
    wire [7:0] awlen;
    wire [2:0] awsize;
    wire [1:0] awburst;

    //axi总线组4
    wire [31:0] wdata;
    wire [3:0] wstrb;
    wire wvalid;
    wire wready;
	wire wlast;

    //axi总线组5
    wire [1:0] bresp;
    wire bvalid;
    wire bready;
	wire [3:0] bid;


	/********************************************************************************************/
	//对于写事务三个通道AW,W,B,直接将来自LSU的信号传给xbar,将来自xbar的信号传给LSU
	//axi-AW
	//情形1:接受单一渠道上游信号，分发给多渠道下游信号
	assign awaddr = awaddr_LSU;
	assign awaddr_xbar = awaddr;

	assign awvalid = awvalid_LSU;
	assign awvalid_xbar = awvalid_LSU;
	
	assign awid = awid_LSU;
	assign awid_xbar = awid;

	assign awlen = awlen_LSU;
	assign awlen_xbar = awlen;

	assign awsize = awsize_LSU;
	assign awsize_xbar = awsize;

	assign awburst = awburst_LSU;
	assign awburst_xbar = awburst;
	
	//情形2:接受多渠道下游信号，分发给单一渠道上游信号
	assign awready = awready_xbar;
	assign awready_LSU = awready;


	//axi-W
	assign wdata = wdata_LSU;
	assign wdata_xbar = wdata;

	assign wstrb = wstrb_LSU;
	assign wstrb_xbar = wstrb;

	assign wvalid = wvalid_LSU;
	assign wvalid_xbar = wvalid;
	
	assign wlast = wlast_LSU;
	assign wlast_xbar = wlast;

	assign wready = wready_xbar;
	assign wready_LSU = wready;


	//axi-B
	assign bresp = bresp_xbar;
	assign bresp_LSU = bresp;
	
	assign bvalid = bvalid_xbar;
	assign bvalid_LSU = bvalid;

	assign bid = bid_xbar;
	assign bid_LSU = bid;
	
	assign bready = bready_LSU;
	assign bready_xbar = bready;
	
	/********************************************************************************************/

	//和读mem/uart相关，同样暂时用作为中间变量的axi信号组
	parameter	Initial = 2'b00,
				Service_for_IFU = 2'b01,
				Service_for_LSU = 2'b10;
	reg [1:0] state;
	

	always@(posedge clk) begin
		if(rst) begin
			state <= Initial;
			//`ifdef verilator $display("Xbar(Interconnect) resetting..."); `endif
		end
		else begin
			case(state)
				Initial: begin
					if(rmem_quest_IFU)
						state <= Service_for_IFU;
					else if(rmem_quest_LSU)
						state <= Service_for_LSU;
					else
						state <= Initial;
				end

				Service_for_IFU: begin
					if(rmem_quest_IFU)
						state <= Service_for_IFU;
					else if(rmem_quest_LSU)
						state <= Service_for_LSU;
					else
						state <= Initial;
				end

				Service_for_LSU: begin
                    if(rmem_quest_LSU)
                        state <= Service_for_LSU;
                    else if(rmem_quest_IFU)
                        state <= Service_for_IFU;
                    else
                        state <= Initial;
                end

                default:
                    state <= Initial;
			endcase
		end
	end
	
	//axi-AR
	//araddr_mem和araddr_uart可以共用上游传来的地址
	assign araddr = (rmem_quest_IFU && state != Service_for_LSU) ? araddr_IFU : (rmem_quest_LSU ? araddr_LSU : 0);
	assign araddr_xbar = araddr;
	assign araddr_clint = araddr;

	//arvalid_mem和arvalid_uart不可以共用，因为这两个信号同时至多只有一个生效
	assign arvalid = (rmem_quest_IFU && state != Service_for_LSU) ? arvalid_IFU : (rmem_quest_LSU ? arvalid_LSU : 0);
	assign arvalid_xbar = `ysyx_23060229_CHECK_XBAR(araddr, arvalid);
	assign arvalid_clint = `ysyx_23060229_CHECK_CLINT(araddr, arvalid);

	assign arid = (rmem_quest_IFU && state != Service_for_LSU) ? arid_IFU : (rmem_quest_LSU ? arid_LSU : 0);
	assign arid_xbar = arid;
    assign arid_clint = arid;
	//assign arid_clint = `ysyx_23060229_CHECK_CLINT(araddr, arid);

	assign arlen = (rmem_quest_IFU && state != Service_for_LSU) ? arlen_IFU : (rmem_quest_LSU ? arlen_LSU : 0);
    assign arlen_xbar = arlen;
    //assign arlen_clint = arlen;
	//assign arlen_clint = `ysyx_23060229_CHECK_CLINT(araddr, arlen);

	assign arsize = (rmem_quest_IFU && state != Service_for_LSU) ? arsize_IFU : (rmem_quest_LSU ? arsize_LSU : 0);
    assign arsize_xbar = arsize;
    //assign arsize_clint = arsize;
	//assign arsize_clint = `ysyx_23060229_CHECK_CLINT(araddr, arsize);

	assign arburst = (rmem_quest_IFU && state != Service_for_LSU) ? arburst_IFU : (rmem_quest_LSU ? arburst_LSU : 0);
    assign arburst_xbar = arburst;
    //assign arburst_clint = arburst;
	//assign arburst_clint = `ysyx_23060229_CHECK_CLINT(araddr, arburst);

	//下游向上游传递的arready信号
	assign arready = `ysyx_23060229_SELECT_SLAVE(araddr, arready_xbar, arready_clint);
	assign arready_IFU = (rmem_quest_IFU && state != Service_for_LSU) ? arready : 0;
    assign arready_LSU = (rmem_quest_LSU && !(rmem_quest_IFU && state != Service_for_LSU)) ? arready : 0;




	//axi-R
	//下游向上游传递的rdata信号
	assign rdata = `ysyx_23060229_SELECT_SLAVE(araddr, rdata_xbar, rdata_clint);
	assign rdata_IFU = (rmem_quest_IFU && state != Service_for_LSU) ? rdata : 0;
    assign rdata_LSU = (rmem_quest_LSU && !(rmem_quest_IFU && state != Service_for_LSU)) ? rdata : 0;

	assign rresp = `ysyx_23060229_SELECT_SLAVE(araddr, rresp_xbar, rresp_clint);
	//2'b11代表解码错误，地址超出从机范围;2'b10表示从机错误，即该从机不可读
	assign rresp_IFU = (rmem_quest_IFU && state != Service_for_LSU) ? rresp : 0;
    assign rresp_LSU = (rmem_quest_LSU && !(rmem_quest_IFU && state != Service_for_LSU)) ? rresp : 0;

	assign rvalid = `ysyx_23060229_SELECT_SLAVE(araddr, rvalid_xbar, rvalid_clint);
	assign rvalid_IFU = (rmem_quest_IFU && state != Service_for_LSU) ? rvalid : 0;
    assign rvalid_LSU = (rmem_quest_LSU && !(rmem_quest_IFU && state != Service_for_LSU)) ? rvalid : 0;

    assign rready = (rmem_quest_IFU && state != Service_for_LSU) ? rready_IFU : (rmem_quest_LSU ? rready_LSU : 0);
	assign rready_xbar = `ysyx_23060229_CHECK_XBAR(araddr, rready);
	//assign rready_clint = rready;
	assign rready_clint = `ysyx_23060229_CHECK_CLINT(araddr, rready);

	assign rlast = `ysyx_23060229_SELECT_SLAVE(araddr, rlast_xbar, rlast_clint);
    assign rlast_IFU = (rmem_quest_IFU && state != Service_for_LSU) ? rlast : 0;
    assign rlast_LSU = (rmem_quest_LSU && !(rmem_quest_IFU && state != Service_for_LSU)) ? rlast : 0;

	assign rid = `ysyx_23060229_SELECT_SLAVE(araddr, rid_xbar, rid_clint);
    assign rid_IFU = (rmem_quest_IFU && state != Service_for_LSU) ? rid : 0;
    assign rid_LSU = (rmem_quest_LSU && !(rmem_quest_IFU && state != Service_for_LSU)) ? rid : 0;

endmodule
//-----------------------------------------end-of-miniXbar-----------------------------------------//
//end of PART IV







//PART V:Controllers
//-----------------------------------------V1:ForwardingCtl-----------------------------------------//
module ysyx_23060229_ForwardingCtl(
	input disen,//去使能信号，置1时输出origin_src1

	input [4:0] ID_EX_rs1,
	input [4:0] ID_EX_rs2,
	input [11:0] ID_EX_csr,

	input [4:0] EX_LS_rd,
	input [11:0] EX_LS_csr,
	input EX_LS_RegWrite,
	input EX_LS_CSRegWrite,

	input [31:0] origin_src1,//原始的src1和src2,由上级输出
	input [31:0] origin_src2,
	input [31:0] origin_srccs,
	
	input [31:0] cached_EX_LS_src1,//本级缓存的src1和src2
	input [31:0] cached_EX_LS_src2,
	input [31:0] cached_EX_LS_srccs,
	
	output [31:0] src1,//仲裁后的src1和src2,送入EXU
	output [31:0] src2,
	output [31:0] srccs

);
	
	assign src1 = (EX_LS_rd == ID_EX_rs1 && EX_LS_rd != 0 && EX_LS_RegWrite == 1 && !disen) ? cached_EX_LS_src1 : origin_src1;
	assign src2 = (EX_LS_rd == ID_EX_rs2 && EX_LS_rd != 0 && EX_LS_RegWrite == 1 && !disen) ? cached_EX_LS_src2 : origin_src2;


	//注:为何当stall_quest_loaduse生效时，src1和src2只能取origin_src1和origin_src2、亦即ForwardingCtl暂时失效?
	//因为上一个指令为load指令，EX/LS中暂存的并非正确的src1和src2（因为涉及到读内存，在经过EXU时src1和src2尚未被获取）
	//(非load指令的result_reg最早在EXU阶段就已经正确生成,而load指令的result_reg只能在LSU阶段生成)

	assign srccs = (EX_LS_csr == ID_EX_csr && EX_LS_CSRegWrite == 1) ? cached_EX_LS_srccs : origin_srccs;

endmodule
//-----------------------------------------end-of-ForwardingCtl-----------------------------------------//





//-----------------------------------------V2:StallingCtl-----------------------------------------//
module ysyx_23060229_StallingCtl(
	input clk,
	input rst,

	input stall_quest_loaduse,
	input ID_EX_pc,
	input LS_WB_pc,
	input previous_load_done,
	
	output reg loaduse_clear//loaduse请求清零
	
);
	
	parameter	Wait_LS_WB_pc = 2'b00,
				Wait_Write_Regs = 2'b01,
				Wait_Stall_Quest_Loaduse_Reset = 2'b10;
	reg [1:0] state;


	always @(posedge clk) begin
		if(rst) begin
			loaduse_clear <= 0; state <= Wait_LS_WB_pc;
			//`ifdef verilator $display("Stalling Controller resetting ..."); `endif
		end

		else begin
			case(state)
				Wait_LS_WB_pc: begin
					loaduse_clear <= 0;
					//实际的pc关系为:LS_WB_pc == ID_EX_pc - 4,后进行简化至1位,即仅比较LS_WB_pc[2] ?= ID_EX_pc[2]
					if(stall_quest_loaduse && LS_WB_pc != ID_EX_pc) begin
						state <= Wait_Write_Regs;
					end
				end

				Wait_Write_Regs: begin
					if(previous_load_done) begin//WBU状态变为Write_Regs
						state <= Wait_Stall_Quest_Loaduse_Reset;
						loaduse_clear <= 1;
					end
				end

				Wait_Stall_Quest_Loaduse_Reset: begin
					state <= Wait_LS_WB_pc;
					loaduse_clear <= 0;
				end

				default: begin
					state <= Wait_LS_WB_pc;
					loaduse_clear <= 0;
				end
			endcase
		end
	end

endmodule
//-----------------------------------------end-of-StallingCtl-----------------------------------------//




//-----------------------------------------V3:ExceptionCtl-----------------------------------------//
//none
//-----------------------------------------end-of-ExceptionCtl-----------------------------------------//
//end of PART V







//PART VI:Integration
//-----------------------------------------ysyx_23060229-----------------------------------------//
module ysyx_23060229(
	input clock,
	input reset,
	input io_interrupt,
	input io_master_awready,
	output io_master_awvalid,
	output [31:0] io_master_awaddr,
	output [3:0] io_master_awid,
	output [7:0] io_master_awlen,
	output [2:0] io_master_awsize,
	output [1:0] io_master_awburst,
	input io_master_wready,
	output io_master_wvalid,
	output [31:0] io_master_wdata,
	output [3:0] io_master_wstrb,
	output io_master_wlast,
	output io_master_bready,
	input io_master_bvalid,
	input [1:0] io_master_bresp,
	input [3:0] io_master_bid,
	input io_master_arready,
	output io_master_arvalid,
	output [31:0] io_master_araddr,
	output [3:0] io_master_arid,
	output [7:0] io_master_arlen,
	output [2:0] io_master_arsize,
	output [1:0] io_master_arburst,
	output io_master_rready,
	input io_master_rvalid,
	input [1:0] io_master_rresp,
	input [31:0] io_master_rdata,
	input io_master_rlast,
	input [3:0] io_master_rid,

	output io_slave_awready,
    input io_slave_awvalid,
    input [31:0] io_slave_awaddr,
    input [3:0] io_slave_awid,
    input [7:0] io_slave_awlen,
    input [2:0] io_slave_awsize,
    input [1:0] io_slave_awburst,
    output io_slave_wready,
    input io_slave_wvalid,
    input [31:0] io_slave_wdata,
    input [3:0] io_slave_wstrb,
    input io_slave_wlast,
    input io_slave_bready,
    output io_slave_bvalid,
    output [1:0] io_slave_bresp,
    output [3:0] io_slave_bid,
    output io_slave_arready,
    input io_slave_arvalid,
    input [31:0] io_slave_araddr,
    input [3:0] io_slave_arid,
    input [7:0] io_slave_arlen,
    input [2:0] io_slave_arsize,
    input [1:0] io_slave_arburst,
    input io_slave_rready,
    output io_slave_rvalid,
    output [1:0] io_slave_rresp,
    output [31:0] io_slave_rdata,
    output io_slave_rlast,
    output [3:0] io_slave_rid
	
	//`ifdef simulation
	//,output [31:0] pc,
	//output one_inst_done,//仅用于difftest
	//output [31:0] regs [0:15]
	//`endif
);

	
	//`ifdef simulation//不再引出
	//assign pc = LS_WB_pc;
	//`endif

	assign io_slave_awready = 0;
	assign io_slave_wready = 0;
	assign io_slave_bvalid = 0;
	assign io_slave_bresp = 0;
	assign io_slave_bid = 0;
	assign io_slave_arready = 0;
	assign io_slave_rvalid = 0;
	assign io_slave_rresp = 0;
	assign io_slave_rdata = 0;
	assign io_slave_rlast = 0;
	assign io_slave_rid = 0;


	/*------------------------------------------------------------------------------*/
	//IFU与IDU通信信号
	wire IFU_valid_IDU;
	wire IDU_ready_IFU;


	//IFU与Xbar通信信号
	//axi总线组1
    wire [31:0] araddr_IFU;//本质为pc
    wire arvalid_IFU;
    wire arready_IFU;
	wire [3:0] arid_IFU;
	wire [7:0] arlen_IFU;
	wire [2:0] arsize_IFU;
	wire [1:0] arburst_IFU;

    //axi总线组2
    wire [31:0] rdata_IFU;
    wire [1:0] rresp_IFU;
    wire rvalid_IFU;
    wire rready_IFU;
	wire rlast_IFU;
	wire [3:0] rid_IFU;

	wire rmem_quest_IFU;

	//wire wrong_pred;


	//IF/ID寄存器
	wire [31:0] IF_ID_pc;
	wire [31:0] IF_ID_inst;

	
	/*------------------------------------------------------------------------------*/
	//IDU与EXU通信信号
	wire EXU_ready_IDU;
	wire IDU_valid_EXU;

	//ID/EX寄存器
	wire [31:0] ID_EX_pc;
	wire [7:0] ID_EX_typ;
	wire [31:0] ID_EX_imm;
	wire [4:0] ID_EX_rs1, ID_EX_rs2;
	wire [4:0] ID_EX_rd;
	wire [11:0] ID_EX_csr;

	wire stall_quest_loaduse;
	wire stall_quest_fencei;
	wire fc_disenable;


	/*------------------------------------------------------------------------------*/
	//EXU与LSU通信信号
	wire EXU_valid_LSU;
	wire LSU_ready_EXU;

	//EX/LS寄存器
	wire [7:0] EX_LS_typ;
	//`ifdef simulation
	wire [31:0] EX_LS_pc;//为确保ExceptionCtl正常工作必须为32 bit
	//`else
	//wire EX_LS_pc;
	//`endif
	wire [2:0] EX_LS_flag;
	wire [4:0] EX_LS_dest_reg;
	wire [31:0] EX_LS_result_reg;
	wire [31:0] EX_LS_dest_csreg_mem;
	wire [31:0] EX_LS_result_csreg_mem;

	wire [31:0] pc_jump;
	
	wire check_assert;
	wire check_quest;


	/*------------------------------------------------------------------------------*/
	//LSU与WBU通信信号

	//LS/WB寄存器
	//`ifdef simulation//不再作为pc引出因而只需1bit
	//wire [31:0] LS_WB_pc;
	//`else
	wire LS_WB_pc;
	//`endif
	wire [4:0] LS_WB_waddr_reg;
	wire [31:0] LS_WB_wdata_reg;
	wire [11:0] LS_WB_waddr_csreg;
	wire [31:0] LS_WB_wdata_csreg;
	wire LS_WB_wen_reg;
	wire [7:0] LS_WB_wen_csreg;


	//LSU与Xbar通信信号
    //axi总线组1
    wire [31:0] araddr_LSU;//本质为pc
    wire arvalid_LSU;
    wire arready_LSU;
	wire [3:0] arid_LSU;
	wire [7:0] arlen_LSU;
	wire [2:0] arsize_LSU;
	wire [1:0] arburst_LSU;

    //axi总线组2
    wire [31:0] rdata_LSU;
    wire [1:0] rresp_LSU;
    wire rvalid_LSU;
    wire rready_LSU;
	wire rlast_LSU;
	wire [3:0] rid_LSU;

    //axi总线组3
    wire [31:0] awaddr_LSU;
    wire awvalid_LSU;
    wire awready_LSU;
	wire [3:0] awid_LSU;
	wire [7:0] awlen_LSU;
	wire [2:0] awsize_LSU;
	wire [1:0] awburst_LSU;

    //axi总线组4
    wire [31:0] wdata_LSU;
    wire [3:0] wstrb_LSU;
    wire wvalid_LSU;
    wire wready_LSU;
	wire wlast_LSU;

    //axi总线组5
    wire [1:0] bresp_LSU;
    wire bvalid_LSU;
    wire bready_LSU;
	wire [3:0] bid_LSU;

	wire rmem_quest_LSU;

	
	wire previous_load_done;
	wire LSU_arready_set;
	wire LSU_awready_set;


	//寄存器其他接口(Reg和CSReg)
	wire [31:0] src1_raw, src2_raw;
	wire [31:0] srccs_raw;
	wire excp_written;
	wire [31:0] mepc;
	wire [31:0] mtvec;

	
	/*-------------------------------------------------------------------------------*/
    //miniXbar和CLINT交互信号
    //axi总线组1
    wire [31:0] araddr_clint;
    wire arvalid_clint;
    wire arready_clint;
	wire [3:0] arid_clint;
    //wire [7:0] arlen_clint;
    //wire [2:0] arsize_clint;
    //wire [1:0] arburst_clint;

    //axi总线组2
    wire [31:0] rdata_clint;
    wire [1:0] rresp_clint;
    wire rvalid_clint;
    wire rready_clint;
	wire rlast_clint;
	wire [3:0] rid_clint;

	
	/*------------------------------------------------------------------------------*/
	//与StallingCtl相关的接口
	wire loaduse_clear;

	/*------------------------------------------------------------------------------*/
	//与ForwardingCtl相关的接口
	wire EX_LS_RegWrite = (EX_LS_flag == `ysyx_23060229_WriteReg || EX_LS_flag == `ysyx_23060229_ReadMem || EX_LS_flag == `ysyx_23060229_Jump_J
							|| EX_LS_flag == `ysyx_23060229_WriteCSReg);
    wire EX_LS_CSRegWrite = (EX_LS_flag == `ysyx_23060229_WriteCSReg);
	wire [31:0] src1, src2, srccs;

	/*------------------------------------------------------------------------------*/



	/*------------------------------------------------------------------------------*/
    //与ExceptionCtl相关的接口
	//none
	/*------------------------------------------------------------------------------*/


	ysyx_23060229_IFU myifu		(clock, reset, check_quest, stall_quest_fencei, pc_jump, check_assert,
								IDU_ready_IFU, IFU_valid_IDU, IF_ID_pc, IF_ID_inst,
								araddr_IFU, arvalid_IFU, arready_IFU, arid_IFU, arlen_IFU, arsize_IFU, arburst_IFU,//axi总线组1
                                rdata_IFU, rresp_IFU, rvalid_IFU, rready_IFU, rlast_IFU, rid_IFU,//2
								rmem_quest_IFU);
								


	ysyx_23060229_IDU	myidu	(clock, reset, loaduse_clear,
								IFU_valid_IDU, EXU_ready_IDU, IDU_ready_IFU, IDU_valid_EXU,
								IF_ID_inst, IF_ID_pc,
								ID_EX_pc, ID_EX_typ, ID_EX_imm, ID_EX_rs1, ID_EX_rs2, ID_EX_rd, ID_EX_csr,
								stall_quest_loaduse, stall_quest_fencei, fc_disenable);


	ysyx_23060229_EXU	myexu	(clock, reset, IDU_valid_EXU, LSU_ready_EXU, EXU_ready_IDU, EXU_valid_LSU,
								ID_EX_pc, ID_EX_typ, ID_EX_imm, ID_EX_rd, ID_EX_csr, src1, src2, srccs,
								EX_LS_typ, EX_LS_pc, EX_LS_flag, EX_LS_dest_reg, EX_LS_result_reg,
								EX_LS_dest_csreg_mem, EX_LS_result_csreg_mem,
								pc_jump, check_assert, check_quest, LSU_arready_set, LSU_awready_set);


	ysyx_23060229_LSU	mylsu	(clock, reset, EXU_valid_LSU, LSU_ready_EXU,
								EX_LS_pc, EX_LS_typ, 
								EX_LS_dest_reg, EX_LS_result_reg,
								EX_LS_dest_csreg_mem, EX_LS_result_csreg_mem,
								pc_jump,
								LS_WB_waddr_reg, LS_WB_wdata_reg, LS_WB_waddr_csreg, LS_WB_wdata_csreg,
								LS_WB_wen_reg, LS_WB_wen_csreg, 
								LS_WB_pc, 
								//`ifdef simulation//不再引出
								//one_inst_done, 
								//`endif
								previous_load_done,
								araddr_LSU, arvalid_LSU, arready_LSU, arid_LSU, arlen_LSU, arsize_LSU, arburst_LSU,//axi总线组1
                                rdata_LSU, rresp_LSU, rvalid_LSU, rready_LSU, rlast_LSU, rid_LSU,//2
                                awaddr_LSU, awvalid_LSU, awready_LSU, awid_LSU, awlen_LSU, awsize_LSU, awburst_LSU,//3
                                wdata_LSU, wstrb_LSU, wvalid_LSU, wready_LSU, wlast_LSU,//4
                                bresp_LSU, bvalid_LSU, bready_LSU, bid_LSU,//5
								rmem_quest_LSU, LSU_arready_set, LSU_awready_set);




	ysyx_23060229_Register	myreg	(clock, reset, LS_WB_wen_reg, LS_WB_wdata_reg, LS_WB_waddr_reg[3:0], ID_EX_rs1[3:0], ID_EX_rs2[3:0],
									src1_raw, src2_raw
									//`ifdef simulation//不再引出
									//	,regs
									//`endif
									);

	
	ysyx_23060229_CSRegister	mycsreg		(clock, reset, LS_WB_wen_csreg, LS_WB_wdata_csreg, LS_WB_waddr_csreg, ID_EX_csr, srccs_raw, 
											excp_written, mtvec, mepc);


	ysyx_23060229_miniXbar		myminixbar		(clock, reset, rmem_quest_IFU, rmem_quest_LSU,
												araddr_IFU, arvalid_IFU, arready_IFU, arid_IFU, arlen_IFU, arsize_IFU, arburst_IFU,//IFU的axi总线组1
                                        		rdata_IFU, rresp_IFU, rvalid_IFU, rready_IFU, rlast_IFU, rid_IFU,//2
                                        		araddr_LSU, arvalid_LSU, arready_LSU, arid_LSU, arlen_LSU, arsize_LSU, arburst_LSU,//LSU的axi总线组1
                                        		rdata_LSU, rresp_LSU, rvalid_LSU, rready_LSU, rlast_LSU, rid_LSU,//2
                                        		awaddr_LSU, awvalid_LSU, awready_LSU, awid_LSU, awlen_LSU, awsize_LSU, awburst_LSU,//3
                                        		wdata_LSU, wstrb_LSU, wvalid_LSU, wready_LSU, wlast_LSU,//4
                                        		bresp_LSU, bvalid_LSU, bready_LSU, bid_LSU,//5
												io_master_araddr, io_master_arvalid, io_master_arready, io_master_arid, io_master_arlen, io_master_arsize, io_master_arburst,//1
												io_master_rdata, io_master_rresp, io_master_rvalid, io_master_rready, io_master_rlast, io_master_rid,//2
												io_master_awaddr, io_master_awvalid, io_master_awready, io_master_awid, io_master_awlen, io_master_awsize, io_master_awburst,//3
												io_master_wdata, io_master_wstrb, io_master_wvalid, io_master_wready, io_master_wlast,//4
												io_master_bresp, io_master_bvalid, io_master_bready, io_master_bid,//5
												araddr_clint, arvalid_clint, arready_clint, arid_clint,//arlen_clint, arsize_clint, arburst_clint,//clint的axi总线组1
                                                rdata_clint, rresp_clint, rvalid_clint, rready_clint, rlast_clint, rid_clint//2
												);

	//CLINT
    ysyx_23060229_CLINT    	myclint 	(clock, reset,
                                    	araddr_clint, arvalid_clint, arready_clint, arid_clint, //arlen_clint, arsize_clint, arburst_clint,//axi总线组1
                                    	rdata_clint, rresp_clint, rvalid_clint, rready_clint, rlast_clint, rid_clint//2
										);//5

									
	ysyx_23060229_ForwardingCtl myfc	(fc_disenable, ID_EX_rs1, ID_EX_rs2, ID_EX_csr, 
										EX_LS_dest_reg, EX_LS_dest_csreg_mem[11:0], EX_LS_RegWrite, EX_LS_CSRegWrite,
										src1_raw, src2_raw, srccs_raw,
										EX_LS_result_reg, EX_LS_result_reg, EX_LS_result_csreg_mem, 
										src1, src2, srccs);


	ysyx_23060229_StallingCtl	mysc	(clock, reset, stall_quest_loaduse, ID_EX_pc[2], 
										//`ifdef simulation//由于不再引出因而只需1bit
										//LS_WB_pc[2], 
										//`else
										LS_WB_pc,
										//`endif
										previous_load_done, loaduse_clear);

	
endmodule
//-----------------------------------------end-of-ysyx_23060229-----------------------------------------//



`endif//__YSYX_23060229__
