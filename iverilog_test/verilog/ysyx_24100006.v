// Combined Verilog Files
// Generated on: 2025年 11月 02日 星期日 22:25:30 CST
// Source directory: ./ysyx-workbench/npc/vsrc/
// ==========================================
// FILE 1: ./ysyx-workbench/npc/vsrc/ysyx_24100006_IDU.v
// ===========================
/**
    译码模块
*/
// TAG: 这里不知道是否需要把irq和irq_no传出去，然后在WB级在写回
module ysyx_24100006_idu(
	input 			clk,
	input 			reset,
	// from IFU
	input [31:0] 	instruction,


    //调试使用
	input [31:0] 	pc_D,
`ifdef VERILATOR_SIM
    output [31:0] 	pc_E,
`endif

    // === 新增：stall from hazard unit,防止数据冒险 ===
    input           stall_id,

	// from WBU(一些从写回级来的信号，比如写入的数据是什么)
	input 			irq_W,
	// input [3:0] 	irq_no_W,
	input 			Gpr_Write_W,
	input 			Csr_Write_W,
    input [3:0]     Gpr_Write_Addr_W,
    input [11:0]    Csr_Write_Addr_W,
	input [31:0] 	wdata_gpr_W,
	input [31:0] 	wdata_csr_W,

	// 握手机制使用
	input           id_out_valid,   // IF_ID -> IDU (上游 valid)
    output          id_out_ready,   // IDU -> IF_ID  (上游 ready)
    output          id_in_valid,    // IDU -> ID_EXE (下游 valid)
    input           id_in_ready,    // ID_EXE -> IDU (下游 ready)

    // === 新增：输出 rs1 / rs2 读使能 ===
    output          rs1_ren,
    output          rs2_ren,
    output          is_break, // 是否是ebreak指令

	// to EXEU
	// control signal
	output 			is_fence_i, // 是否刷新icache
	output [3:0] 	aluop,
	output 			Gpr_Write_E,
	output 			Csr_Write_E,
    output [3:0]    Gpr_Write_Addr,
    output [11:0]   Csr_Write_Addr,
	output [1:0] 	Gpr_Write_RD,
	output [2:0] 	Jump,

	output [1:0] 	sram_read_write,

	// TO IFU
	// CSR寄存器取出的异常PC,ecall指令使用的,mret指令直接在内部就会计算一个pc
	output [31:0] 	mtvec

    // 异常处理相关
    ,output         irq_D

    // 面积优化
    ,output [31:0]  pc_j_m_e_n_D        // NO_JUMP/MRET/ECALL三种跳转的地址
    ,output [31:0]  alu_a_data_D
    ,output [31:0]  alu_b_data_D
    ,output [31:0]  pc_add_imm_D

    ,output [31:0]  wdata_csr_D
    ,output [31:0]  wdata_gpr_D

    ,output [2:0]   Mem_Mask

    ,output [31:0]  pc_add_4_o

    // 前递单元设计
    ,input [1:0]    forwardA
    ,input [1:0]    forwardB
    ,input [31:0]   exe_fw_data
    ,input [31:0]   mem_fw_data
);

	// 握手机制
    assign id_in_valid  = id_out_valid & ~stall_id; // If there is a hazard, do not continue passing data
    assign id_out_ready = id_in_ready & ~stall_id; // If there's a hazard, don't continue passing data


	// GPR combinational read outputs
    wire [31:0] rs1_data_comb;
    wire [31:0] rs2_data_comb;

	// 通用寄存器堆
	ysyx_24100006_GPR GPR(
		.clk(clk),
		.wdata(wdata_gpr_W),
		.waddr(Gpr_Write_Addr_W),
		.wen(Gpr_Write_W),
		.rs1(instruction[18:15]),
		.rs2(instruction[23:20]),
		.rs1_data(rs1_data_comb),
		.rs2_data(rs2_data_comb)
	);

	// CSR read (combinational rdata)
	// 系统寄存器
	// TAG:需要写CSR寄存器的指令有mret、csrrs、csrrw三条，所以这里的wdata和waddr需要使用MUX进行选值
    wire [31:0] rdata_csr_comb;
    wire [31:0] mtvec_comb;
    wire [31:0] mepc_comb;
    ysyx_24100006_CSR CSR(
        .clk(clk),
        .irq(irq_W),
        .wdata(wdata_csr_W),
        .waddr(Csr_Write_Addr_W),
        .wen(Csr_Write_W),
        .raddr(instruction[31:20]),
        .rdata(rdata_csr_comb),
        .mtvec(mtvec_comb),
        .mepc(mepc_comb)
    );

	// immediate sign-extend (combinational)
    wire [2:0] Imm_Type;
    wire [31:0] sext_imm_wire;

    wire [31:0]immI;
	wire [31:0]immU;
	wire [31:0]immJ;
	wire [31:0]immS;
	wire [31:0]immB;

    assign immI = {{21{instruction[31]}},instruction[30:20]};
	assign immU = {instruction[31:12],12'b0};
	assign immJ = {{12{instruction[31]}},instruction[19:12],instruction[20],instruction[30:21],1'b0};
	assign immS = {{21{instruction[31]}},instruction[30:25],instruction[11:7]};
	assign immB = {{20{instruction[31]}},instruction[7],instruction[30:25],instruction[11:8],1'b0};

	assign sext_imm_wire = (Imm_Type[2] == 1'b1) ? immU : 
						((Imm_Type[1:0] == 2'b00) ? immI: 
						(Imm_Type[1:0] == 2'b01) ? immJ: 
						(Imm_Type[1:0] == 2'b11) ? immB: immS);

	// controller_remake
    wire [3:0]  ctrl_aluop;
    wire        ctrl_Gpr_Write;
    wire [2:0]  ctrl_Gpr_Write_RD;
    wire        ctrl_Csr_Write;
    wire [1:0]  ctrl_Csr_Write_RD;
    wire [2:0]  ctrl_Jump;
    wire        ctrl_AluSrcA;
    wire        ctrl_AluSrcB;
    wire [2:0]  ctrl_Mem_RMask;
    wire [2:0]  ctrl_Mem_WMask;
    wire [1:0]  ctrl_sram_read_write;
    wire        ctrl_is_fence_i;
    wire        ctrl_irq;

    // 新增：来自 controller 的 jalr/mret 指示
    wire        ctrl_is_jalr;
    wire        ctrl_is_mret;

	ysyx_24100006_controller_remake controller(
        .opcode(instruction[6:0]),
        .funct3(instruction[14:12]),
        .funct7(instruction[31:25]),
        .funct12(instruction[31:20]),

        .rs1_ren(rs1_ren), // 是否需要读rs1寄存器
        .rs2_ren(rs2_ren), // 是否需要读rs2寄存器
        .is_ebreak(is_break), // 是否是ebreak指令

        .irq(ctrl_irq),
        .aluop(ctrl_aluop),
        .Gpr_Write(ctrl_Gpr_Write),
        .Gpr_Write_RD(ctrl_Gpr_Write_RD),
        .Csr_Write(ctrl_Csr_Write),
        .Csr_Write_RD(ctrl_Csr_Write_RD),
        .Jump(ctrl_Jump),
        .Imm_Type(Imm_Type),
        .AluSrcA(ctrl_AluSrcA),
        .AluSrcB(ctrl_AluSrcB),
        .Mem_RMask(ctrl_Mem_RMask),
        .Mem_WMask(ctrl_Mem_WMask),
        .sram_read_write(ctrl_sram_read_write),
        .is_fence_i(ctrl_is_fence_i)
        // 新增输出
        ,.is_jalr(ctrl_is_jalr),
        .is_mret(ctrl_is_mret)
    );

    // 前递单元设计
    wire [31:0] rs1_data_fw;
    wire [31:0] rs2_data_fw;
    assign rs1_data_fw = (forwardA == 2'b00) ? rs1_data_comb :
                        (forwardA == 2'b01) ? exe_fw_data :
                        (forwardA == 2'b10) ? mem_fw_data : 32'b0;

    assign rs2_data_fw = (forwardB == 2'b00) ? rs2_data_comb :
                        (forwardB == 2'b01) ? exe_fw_data : 
                        (forwardB == 2'b10) ? mem_fw_data : 32'b0;

	
	// ---------------- map combinational outputs ----------------

`ifdef VERILATOR_SIM
    // 调试使用
    assign pc_E        		= pc_D;
`endif

    assign mtvec       		= mtvec_comb;

    assign aluop       		= ctrl_aluop;
    assign Gpr_Write_Addr   = instruction[10:7];
    assign Gpr_Write_E 		= ctrl_Gpr_Write;
    assign Gpr_Write_RD		= ctrl_Gpr_Write_RD[1:0];
    assign Csr_Write_Addr   = instruction[31:20];
    assign Csr_Write_E 		= ctrl_Csr_Write;
    assign Jump        		= ctrl_Jump;
    assign sram_read_write 	= ctrl_sram_read_write;
    assign is_fence_i  		= (reset == 1 || id_out_valid == 0) ? 0 : ctrl_is_fence_i;

    // 异常处理相关
    assign irq_D       		= ctrl_irq;

    // 面积优化
    // assign pc_add_4_o           =   pc_D + 4;
    // wire [31:0] rs1_add_imm_D   =   (rs1_data_fw + sext_imm_wire) & (~32'b1);
    // assign pc_j_m_e_n_D         =   (instruction[6:0] == 7'b1100111) ? rs1_add_imm_D :               // JALR
    //                                 (instruction[6:0] == 7'b1110011 && instruction[31:20] == 12'b001100000010) ? mepc_comb : pc_add_4_o;     // MRET，ECALL指令并不会产生跳转指令，因为属于异常处理

    // 面积优化：PC 选择仅依赖控制信号，不再重复比较 opcode
    assign pc_add_4_o           = {(pc_D[31:2] + 1'b1), 2'b00};
    wire [31:0] rs1_add_imm_D   = (rs1_data_fw + sext_imm_wire) & (~32'b1);
    assign pc_j_m_e_n_D         = ctrl_is_jalr ? rs1_add_imm_D :
                                  ctrl_is_mret ? mepc_comb    :
                                                 pc_add_4_o;

    assign alu_a_data_D     = (ctrl_AluSrcA == 1'b0) ? rs1_data_fw : pc_D;
    assign alu_b_data_D     = (ctrl_AluSrcB == 1'b0) ? rs2_data_fw : sext_imm_wire;
    assign pc_add_imm_D     = pc_D + sext_imm_wire;

    
    assign wdata_gpr_D      = (ctrl_sram_read_write[1] == 1'b1) ? rs2_data_fw : ((ctrl_Gpr_Write_RD[2] == 1'b1) ? rdata_csr_comb : ((ctrl_Gpr_Write_RD[1] == 1'b1) ? pc_add_4_o : sext_imm_wire));
    assign wdata_csr_D      = (ctrl_Csr_Write_RD[1] == 1'b1) ? (rdata_csr_comb | rs1_data_fw) : ((ctrl_Csr_Write_RD[0] == 1'b1) ? rs1_data_fw : pc_D);

    assign Mem_Mask         = (ctrl_sram_read_write[0] == 1'b1) ? ctrl_Mem_RMask :    // load
                                                                ctrl_Mem_WMask;     // write

endmodule
// ===========================

// FILE 2: ./ysyx-workbench/npc/vsrc/ysyx_24100006.v
// ===========================
module ysyx_24100006(
	input			clock,
    input			reset
`ifndef NPC
	,

	input 			io_interrupt,

	//-----------------------------
    // AXI4 主设备接口 (物理总线侧)
    //-----------------------------
    // 写地址通道
	input			io_master_awready,
	output			io_master_awvalid,
	output  [31:0]  io_master_awaddr,
	output  [3:0]  	io_master_awid,
	output  [7:0]  	io_master_awlen,
	output  [2:0]  	io_master_awsize,
	output  [1:0]  	io_master_awburst,

	// 写数据通道
	input			io_master_wready,
	output          io_master_wvalid,
	output  [31:0]  io_master_wdata,
	output  [3:0]  	io_master_wstrb,
	output  		io_master_wlast,

	// 写响应通道
	output			io_master_bready,
	input			io_master_bvalid,
	input   [1:0]  	io_master_bresp,
	input   [3:0]  	io_master_bid,

	// 读地址通道
	input           io_master_arready,
	output          io_master_arvalid,
	output  [31:0]  io_master_araddr,
	output  [3:0]  	io_master_arid,
	output  [7:0]  	io_master_arlen,
	output  [2:0]  	io_master_arsize,
	output  [1:0]  	io_master_arburst,

	// 读数据通道
	output  		io_master_rready,
	input           io_master_rvalid,
	input   [1:0]  	io_master_rresp,
	input   [31:0]  io_master_rdata,
	input           io_master_rlast,
	input   [3:0]  	io_master_rid,

	//-----------------------------
    // 写地址通道 (Slave 接收 Master 的请求)
    //-----------------------------
    output wire        io_slave_awready,  // Slave 准备好接收地址
    input  wire        io_slave_awvalid,  // Master 地址有效
    input  wire [31:0] io_slave_awaddr,   // 地址
    input  wire [3:0]  io_slave_awid,     // 事务 ID
    input  wire [7:0]  io_slave_awlen,    // 突发长度
    input  wire [2:0]  io_slave_awsize,   // 突发大小
    input  wire [1:0]  io_slave_awburst,  // 突发类型

    //-----------------------------
    // 写数据通道 (Slave 接收数据)
    //-----------------------------
    output wire        io_slave_wready,   // Slave 准备好接收数据
    input  wire        io_slave_wvalid,   // Master 数据有效
    input  wire [31:0] io_slave_wdata,    // 数据
    input  wire [3:0]  io_slave_wstrb,    // 字节选通
    input  wire        io_slave_wlast,    // 最后一个数据包

    //-----------------------------
    // 写响应通道 (Slave 返回响应)
    //-----------------------------
    input  wire        io_slave_bready,   // Master 准备好接收响应
    output wire        io_slave_bvalid,   // Slave 响应有效
    output wire [1:0]  io_slave_bresp,    // 响应状态
    output wire [3:0]  io_slave_bid,      // 事务 ID

    //-----------------------------
    // 读地址通道 (Slave 接收读请求)
    //-----------------------------
    output wire        io_slave_arready,  // Slave 准备好接收地址
    input  wire        io_slave_arvalid,  // Master 地址有效
    input  wire [31:0] io_slave_araddr,   // 地址
    input  wire [3:0]  io_slave_arid,     // 事务 ID
    input  wire [7:0]  io_slave_arlen,    // 突发长度
    input  wire [2:0]  io_slave_arsize,   // 突发大小
    input  wire [1:0]  io_slave_arburst,  // 突发类型

    //-----------------------------
    // 读数据通道 (Slave 返回数据)
    //-----------------------------
    input  wire        io_slave_rready,   // Master 准备好接收数据
    output wire        io_slave_rvalid,   // Slave 数据有效
    output wire [1:0]  io_slave_rresp,    // 响应状态
    output wire [31:0] io_slave_rdata,    // 数据
    output wire        io_slave_rlast,    // 最后一个数据包
    output wire [3:0]  io_slave_rid       // 事务 ID
	
`endif

// 网表仿真的时候将uart接出去
`ifndef VERILATOR_SIM
	`ifdef NPC
		,output        	uart_axi_arvalid,
		input       	uart_axi_arready,
		output [31:0]	uart_axi_araddr,
		// 读数据通道
		input          	uart_axi_rvalid,
		output         	uart_axi_rready,
		input  [1:0]	uart_axi_rresp,
		input  [31:0]	uart_axi_rdata,
		// 写地址通道
		output			uart_axi_awvalid,
		input			uart_axi_awready,
		output [31:0]	uart_axi_awaddr,
		// 写数据通道
		output			uart_axi_wvalid,
		input         	uart_axi_wready,
		output [31:0] 	uart_axi_wdata,
		output [3:0]   	uart_axi_wstrb,
		// 写响应通道
		input          	uart_axi_bvalid,
		output         	uart_axi_bready,
		input  [1:0]  	uart_axi_bresp
	`endif
`endif
);

`ifndef NPC
	//-----------------------------
	// 所有 output 信号强制置零
	//-----------------------------
	assign io_slave_awready   = 1'b0;   // 1-bit
	assign io_slave_wready    = 1'b0;   // 1-bit
	assign io_slave_bvalid    = 1'b0;   // 1-bit
	assign io_slave_bresp     = 2'h0;   // 2-bit
	assign io_slave_bid       = 4'h0;   // 4-bit
	assign io_slave_arready   = 1'b0;   // 1-bit
	assign io_slave_rvalid    = 1'b0;   // 1-bit
	assign io_slave_rresp     = 2'h0;   // 2-bit
	assign io_slave_rdata     = 32'h0;  // 32-bit
	assign io_slave_rlast     = 1'b0;   // 1-bit
	assign io_slave_rid       = 4'h0;   // 4-bit
`endif

	// 模块的信号
	// Icache -> EXEU
	wire 		icache_flush_done_CE;
	// hazard -> IDU;
	// === Hazard wires ===
	wire        stall_id;
	// IDU -> hazard
	wire		rs1_ren_D;
	wire		rs2_ren_D;
	// MEMU -> hazard
	// 是否是lw指令
	wire 		is_load;

	// EXEU -> IFU
	wire [31:0] npc_E_F;              	// EXE->IFU传递的下一条PC
	wire		redirect_valid_E_F;
	// WBU -> IDU
	wire 		irq_WD;
	wire [3:0] 	irq_no_WD;
	wire [3:0] 	Gpr_Write_Addr_WD;
	wire [11:0]	Csr_Write_Addr_WD;
	wire 		Gpr_Write_WD;
	wire 		Csr_Write_WD;
	wire [31:0] wdata_gpr_WD;
	wire [31:0] wdata_csr_WD;



	// 调试使用
	wire [31:0] pc_F;                 	// IF阶段PC
	wire [31:0] pc_F_D;               	// IF->ID传递的PC
`ifdef VERILATOR_SIM
	wire [31:0] pc_D;                 	// ID阶段PC
	wire [31:0] pc_D_E;               	// ID->EXE传递的PC
	wire [31:0] pc_E;                 	// EXE阶段PC
	wire [31:0] pc_E_M;               	// EXE->MEM传递的PC
	wire [31:0] pc_M;                 	// MEM阶段PC
	wire [31:0] pc_M_W;               	// MEM->WB传递的PC
`endif 



	// IF阶段信号
	wire		irq_F;
	wire [3:0]	irq_no_F;
	wire [31:0]	inst_F;					// IF阶段instruction

	// IF_ID输出信号
	wire		irq_F_D;			  	// IF->ID传递的中断标志
	wire [3:0]	irq_no_F_D;		  		// IF->ID传递的中断号
	wire [31:0] instruction_F_D;      	// IF->ID传递的指令

	// ID阶段信号
	wire [3:0]  alu_op_D;             	// ID阶段ALU操作码
	wire [3:0]	Gpr_Write_Addr_D;	  	// ID阶段GPR写寄存器的地址
	wire [11:0]	Csr_Write_Addr_D;	  	// ID阶段CSR写寄存器的地址 
	wire [1:0]  Gpr_Write_RD_D;       	// ID阶段GPR写寄存器
	wire [2:0]  Jump_D;               	// ID阶段跳转控制
	wire [3:0]  irq_no_D;             	// ID阶段中断号
	wire [31:0] mtvec_D;              	// ID阶段mtvec值
	wire        is_fence_i_D;         	// ID阶段fence.i标志
	wire        irq_D;                	// ID阶段中断标志
	wire        Gpr_Write_D;          	// ID阶段GPR写使能
	wire        Csr_Write_D;          	// ID阶段CSR写使能
	wire		is_break_D;			  	// ID阶段break指令标志
	wire [1:0]	sram_read_write_D;    	// ID阶段SRAM读写使能，这个是在MEMU中判断是LOAD操作还是STORE操作使用

	// ID_EXE输出信号
	wire [3:0]  alu_op_D_E;           	// ID->EXE传递的ALU操作码
	wire [3:0]	Gpr_Write_Addr_D_E;	  	// ID->EXE传递的GPR写寄存器的地址
	wire [11:0]	Csr_Write_Addr_D_E;	  	// ID->EXE传递的CSR写寄存器的地址 
	wire [1:0]  Gpr_Write_RD_D_E;     	// ID->EXE传递的GPR写寄存器
	wire [2:0]  Jump_D_E;             	// ID->EXE传递的跳转控制
	wire [3:0]  irq_no_D_E;           	// ID->EXE传递的中断号
	wire [31:0] mtvec_D_E;            	// ID->EXE传递的mtvec值
	wire        is_fence_i_D_E;       	// ID->EXE传递的fence.i标志
	wire        irq_D_E;             	// ID->EXE传递的中断标志
	wire        Gpr_Write_D_E;        	// ID->EXE传递的GPR写使能
	wire        Csr_Write_D_E;        	// ID->EXE传递的CSR写使能
	wire		is_break_D_E; 		  	// ID->EXE传递的break指令标志
	wire [1:0]	sram_read_write_D_E;  	// ID->EXE传递的SRAM读写使能，这个是在MEMU中判断是LOAD操作还是STORE操作使用

	// EXE阶段信号
	wire		redirect_valid_E;	  	// 是否使用EXE级的结果更新PC
	wire [31:0] npc_E;                	// EXE阶段下一条PC
	wire [31:0] alu_result_E;        	// EXE阶段ALU结果
	wire [3:0]	Gpr_Write_Addr_E;	  	// EXE级GPR写寄存器的地址
	wire [11:0]	Csr_Write_Addr_E;	  	// EXE级CSR写寄存器的地址 
	wire [1:0]  Gpr_Write_RD_E;       	// EXE阶段GPR写寄存器
	wire [1:0]  Csr_Write_RD_E;       	// EXE阶段CSR写寄存器
	wire [3:0]  irq_no_E;             	// EXE阶段中断号
	wire        irq_E;                	// EXE阶段中断标志
	wire        Gpr_Write_E;          	// EXE阶段GPR写使能
	wire        Csr_Write_E;          	// EXE阶段CSR写使能
	wire		is_break_E; 		  	// EXE->EXE_MEM传递的break指令标志
	wire [1:0]	sram_read_write_E;    	// EXE阶段SRAM读写使能，这个是在MEMU中判断是LOAD操作还是STORE操作使用

	// EXE_MEM输出信号
	wire [31:0] alu_result_E_M;       	// EXE->MEM传递的ALU结果
	wire [3:0]	Gpr_Write_Addr_E_M;	  	// EXE->MEM传递的GPR写寄存器的地址
	wire [11:0]	Csr_Write_Addr_E_M;	  	// EXE->MEM传递的CSR写寄存器的地址 
	wire [1:0]  Gpr_Write_RD_E_M;     	// EXE->MEM传递的GPR写寄存器
	wire [1:0]  Csr_Write_RD_E_M;     	// EXE->MEM传递的CSR写寄存器
	wire [3:0]  irq_no_E_M;           	// EXE->MEM传递的中断号
	wire        irq_E_M;              	// EXE->MEM传递的中断标志
	wire        Gpr_Write_E_M;        	// EXE->MEM传递的GPR写使能
	wire        Csr_Write_E_M;        	// EXE->MEM传递的CSR写使能
	wire		is_break_E_M; 		  	// EXE_MEM->MEM传递的break指令标志
	wire [1:0]	sram_read_write_E_M;  	// EXE->MEM传递的SRAM读写使能，这个是在MEMU中判断是LOAD操作还是STORE操作使用

	// MEM阶段信号
	wire [31:0] alu_result_M;         	// MEM阶段ALU结果
	wire [3:0]	Gpr_Write_Addr_M;	  	// MEM级GPR写寄存器的地址
	wire [11:0]	Csr_Write_Addr_M;	  	// MEM级CSR写寄存器的地址 
	wire [3:0]  irq_no_M;             	// MEM阶段中断号
	wire        irq_M;                	// MEM阶段中断标志
	wire        Gpr_Write_M;          	// MEM阶段GPR写使能
	wire        Csr_Write_M;          	// MEM阶段CSR写使能
	wire		is_break_M; 		  	// MEM->MEM_WB传递的break指令标志

	// MEM_WB输出信号
	wire [3:0]	Gpr_Write_Addr_M_W;	  	// MEM->WB传递的GPR写寄存器的地址
	wire [11:0]	Csr_Write_Addr_M_W;	  	// MEM->WB传递的CSR写寄存器的地址 
	wire [3:0]  irq_no_M_W;           	// MEM->WB传递的中断号
	wire        irq_M_W;              	// MEM->WB传递的中断标志
	wire        Gpr_Write_M_W;        	// MEM->WB传递的GPR写使能
	wire        Csr_Write_M_W;        	// MEM->WB传递的CSR写使能
	wire		is_break_M_W; 			// MEM_WB->WBU传递的break指令标志


	// 握手机制
	// IF_ID
	wire 		if_in_valid;
	wire 		if_in_ready;
	wire 		id_out_valid;
	wire 		id_out_ready;
	
	// ID_EXE
	wire 		id_in_valid;
	wire 		id_in_ready;
	wire 		exe_out_valid;
	wire 		exe_out_ready;
	
	// EXE_MEM
	wire 		exe_in_valid;
	wire 		exe_in_ready;
	wire 		mem_out_valid;
	wire 		mem_out_ready;

	// MEM_WB
	wire 		mem_in_valid;
	wire 		mem_in_ready;
	wire 		wb_out_valid;
	wire 		wb_out_ready;
	wire 		wb_in_valid;
	wire 		wb_in_ready;
	

	// AXI-Lite
	// IFU -> IM
	// read data addr
	reg [31:0]	axi_araddr_if;
	reg 		axi_arready_if;
	reg 		axi_arvalid_if;
	// read data
	reg 		axi_rvalid_if;
	reg 		axi_rready_if;
	reg [31:0]	axi_rdata_if;
	reg [1:0] 	axi_rresp_if;
	// write data addr
	reg 		axi_awvalid_if;
	reg 		axi_awready_if;
	// write data
	reg 		axi_wvalid_if;
	reg 		axi_wready_if;
	// response
	reg 		axi_bvalid_if;
	reg 		axi_bready_if;
	// 新增AXI信号
	reg	[7:0]	axi_arlen_if;
	reg	[2:0]	axi_arsize_if;
	reg			axi_rlast_if;

	// MEMU -> MEM
	// read data addr
	reg [31:0]	axi_araddr_mem;
	reg 		axi_arready_mem;
	reg 		axi_arvalid_mem;
	// read data
	reg	[31:0]	axi_rdata_mem;
	reg 		axi_rvalid_mem;
	reg 		axi_rready_mem;
	reg [1:0] 	axi_rresp_mem;
	// write data addr
	reg [31:0]	axi_awaddr_mem;
	reg 		axi_awvalid_mem;
	reg 		axi_awready_mem;
	// write data
	reg 		axi_wvalid_mem;
	reg [31:0]	axi_wdata_mem;
	reg 		axi_wready_mem;
	// response
	reg 		axi_bvalid_mem;
	reg 		axi_bready_mem;
	reg [1:0] 	axi_bresp_mem;
	// 新增AXI信号
	reg	[7:0]	axi_arlen_mem;
	reg	[2:0]	axi_arsize_mem;
	reg			axi_rlast_mem;
	reg	[7:0]	axi_awlen_mem;
	reg	[2:0]	axi_awsize_mem;
	reg	[3:0]	axi_wstrb_mem;
	reg			axi_wlast_mem;

	// 用于分辨原始的地址的后两位
	reg [1:0]	axi_addr_suffix_mem;
    
	// 下面的SRAM_axi_信号是指从xbar输出的信号，连接到axi模块的，本来是连接到存储SRAM（即mem）
	// 读地址通道
	wire       		sram_axi_arvalid;
    wire       		sram_axi_arready;
    wire [31:0]  	sram_axi_araddr;
    // 读数据通道
    wire         	sram_axi_rvalid;
    wire        	sram_axi_rready;
    wire [1:0]		sram_axi_rresp;
    wire [31:0]   	sram_axi_rdata;
    // 写地址通道
    wire         	sram_axi_awvalid;
    wire          	sram_axi_awready;
    wire [31:0]  	sram_axi_awaddr;
    // 写数据通道
    wire          	sram_axi_wvalid;
    wire        	sram_axi_wready;
    wire [31:0] 	sram_axi_wdata;
    // 写响应通道
    wire         	sram_axi_bvalid;
    wire        	sram_axi_bready;
    wire [1:0]  	sram_axi_bresp;

	// AXI新增信号
	wire [7:0]		sram_axi_arlen;
	wire [2:0]		sram_axi_arsize;
	wire			sram_axi_rlast;
	wire [7:0]		sram_axi_awlen;
	wire [2:0]		sram_axi_awsize;
	wire [3:0]		sram_axi_wstrb;
	wire			sram_axi_wlast;

	// TAG: 时钟相关的部分
	// CLINT实例化
	// 读地址通道
	wire       		clint_axi_arvalid;
    wire       		clint_axi_arready;
    wire [31:0]  	clint_axi_araddr;
    // 读数据通道
    wire         	clint_axi_rvalid;
    wire        	clint_axi_rready;
    wire [1:0]		clint_axi_rresp;
    wire [31:0]   	clint_axi_rdata;
	wire			clint_axi_rlast;

	ysyx_24100006_clint u_clint(
		.clk			(clock),
		.reset			(reset),
		
		// axi 写入和读取地址
		.axi_araddr		(clint_axi_araddr),
		// axi控制信号
		// read data addr
		.axi_arvalid	(clint_axi_arvalid),
		.axi_rvalid		(clint_axi_rvalid),
		// axi读取的数据
		.axi_rdata		(clint_axi_rdata)
	);

`ifdef NPC
// TAG:NPC使用的ram
`ifdef VERILATOR_SIM
	ysyx_24100006_mem u_mem (
        // 系统时钟和复位
        .clk              (clock),
        .reset            (reset),
        
        // AXI 地址接口
        .axi_araddr       (sram_axi_araddr),
        .axi_awaddr       (sram_axi_awaddr),
        
        // AXI 数据接口
        .axi_wdata        (sram_axi_wdata),
        .axi_wstrb        (sram_axi_wstrb),  // 字节掩码
        
        // AXI 控制信号 - 读通道
        .axi_arvalid      (sram_axi_arvalid),
        .axi_arready      (sram_axi_arready),  // 从模块输出
        
        .axi_rready       (sram_axi_rready),
        .axi_rvalid       (sram_axi_rvalid),  // 从模块输出
        .axi_rresp        (sram_axi_rresp),   // 从模块输出
        .axi_rdata        (sram_axi_rdata),   // 从模块输出
        
        // AXI 控制信号 - 写通道
        .axi_awvalid      (sram_axi_awvalid),
        .axi_awready      (sram_axi_awready), // 从模块输出
        
        .axi_wvalid       (sram_axi_wvalid),
        .axi_wready       (sram_axi_wready),  // 从模块输出
        
        // AXI 控制信号 - 响应通道
        .axi_bready       (sram_axi_bready),
        .axi_bvalid       (sram_axi_bvalid),  // 从模块输出
        .axi_bresp        (sram_axi_bresp),    // 从模块输出

		// 新增信号
		.axi_arlen		  (sram_axi_arlen),
		.axi_arsize 	  (sram_axi_arsize),
		.axi_rlast	 	  (sram_axi_rlast),
		.axi_awlen	  	  (sram_axi_awlen),
		.axi_awsize		  (sram_axi_awsize),
		.axi_wlast		  (sram_axi_wlast)
    );
// TAG: 实例化NPC使用的UART
// 实例化 UART 模块

	// 读地址通道
	wire       		uart_axi_arvalid;
    wire       		uart_axi_arready;
    wire [31:0]  	uart_axi_araddr;
    // 读数据通道
    wire         	uart_axi_rvalid;
    wire        	uart_axi_rready;
    wire [1:0]		uart_axi_rresp;
    wire [31:0]   	uart_axi_rdata;
    // 写地址通道
    wire         	uart_axi_awvalid;
    wire          	uart_axi_awready;
    wire [31:0]  	uart_axi_awaddr;
    // 写数据通道
    wire          	uart_axi_wvalid;
    wire        	uart_axi_wready;
    wire [31:0] 	uart_axi_wdata;
    wire [3:0]   	uart_axi_wstrb;
    // 写响应通道
    wire         	uart_axi_bvalid;
    wire        	uart_axi_bready;
    wire [1:0]  	uart_axi_bresp;

    ysyx_24100006_uart uart(
		.clk			(clock),
		.reset			(reset),
		
		// axi 写入和读取地址
		.axi_araddr		(uart_axi_araddr),
		.axi_awaddr		(uart_axi_awaddr),
		// axi 写入数据和写入使用的掩码
		.axi_wdata		(uart_axi_wdata),
		.axi_wstrb		(uart_axi_wstrb),
		// axi控制信号
		// read data addr
		.axi_arvalid	(uart_axi_arvalid),
		.axi_arready	(uart_axi_arready),
		// read data
		.axi_rready		(uart_axi_rready),
		.axi_rvalid		(uart_axi_rvalid),
		// write data addr
		.axi_awvalid	(uart_axi_awvalid),
		.axi_awready	(uart_axi_awready),
		// write data
		.axi_wvalid		(uart_axi_wvalid),
		.axi_wready		(uart_axi_wready),
		// response
		.axi_bready		(uart_axi_bready),
		.axi_bvalid		(uart_axi_bvalid),
		.axi_bresp		(uart_axi_bresp),

		// axi读取的回应
		.axi_rresp		(uart_axi_rresp),
		// axi读取的数据
		.axi_rdata		(uart_axi_rdata)
	);
`endif

`endif

	// Icache
	wire			axi_arvalid_icache;
	wire			axi_arready_icache;
	wire [31:0]		axi_araddr_icache;
	wire			axi_rvalid_icache;
	wire			axi_rready_icache;
	wire [31:0]		axi_rdata_icache;
	wire [7:0]		axi_arlen_icache;
	wire [2:0]		axi_arsize_icache;
	wire [1:0]		axi_arburst_icache;
	wire 			axi_rlast_icache;

`ifdef VERILATOR_SIM
	wire			icache_hit;
`endif

	ysyx_24100006_Icache u_icache (
        .clk            (clock), 				// 系统时钟
        .rst            (reset),				// 系统复位
        
		.fence_i_i		(is_fence_i_D),		// 是否刷新icache的cache块

        // CPU -> Icache接口
        .cpu_arvalid_i  (axi_arvalid_if),	 	// CPU地址有效
        .cpu_arready_o  (axi_arready_if), 		// Icache地址就绪
        .cpu_araddr_i   (axi_araddr_if), 		// 取指地址
        
        // Icache -> CPU接口
        .cpu_rvalid_o   (axi_rvalid_if),	 	// 指令数据有效
        .cpu_rready_i   (axi_rready_if),	 	// CPU接收就绪
        .cpu_rdata_o    (axi_rdata_if),			// 返回的指令数据
        
        // Icache -> AXI接口
        .axi_arvalid_o  (axi_arvalid_icache),   // 到AXI的地址有效
        .axi_arready_i  (axi_arready_icache),   // AXI地址就绪
        .axi_araddr_o   (axi_araddr_icache),	// AXI取指地址
		.axi_arlen_o	(axi_arlen_icache),
        
        // AXI -> Icache接口
        .axi_rvalid_i   (axi_rvalid_icache),    // AXI数据有效
        .axi_rready_o   (axi_rready_icache),    // Icache接收就绪
        .axi_rdata_i    (axi_rdata_icache),		// AXI返回的数据
		.axi_rlast_i	(axi_rlast_icache),
		.icache_flush_done(icache_flush_done_CE)

`ifdef VERILATOR_SIM
		,.hit			(icache_hit)
`endif
    );


	// TAG：下面就是加入UART之后需要的，如果接入了其他的UART之后，就可以删除了。就是arbiter暴露给xbar的握手接口
	wire         m_axi_awvalid;
	wire         m_axi_awready;
	wire [31:0]  m_axi_awaddr;

	wire         m_axi_wvalid;
	wire         m_axi_wready;
	wire [31:0]  m_axi_wdata;

	wire         m_axi_bvalid;
	wire         m_axi_bready;
	wire [1:0]   m_axi_bresp;

	// 读通道
	wire         m_axi_arvalid;
	wire         m_axi_arready;
	wire [31:0]  m_axi_araddr;

	wire         m_axi_rvalid;
	wire         m_axi_rready;
	wire [31:0]  m_axi_rdata;
	wire [1:0]   m_axi_rresp;

	// AXI新增信号
	wire [7:0]	m_axi_arlen;
	wire [2:0]	m_axi_arsize;
	wire		m_axi_rlast;
	wire [7:0]	m_axi_awlen;
	wire [2:0]	m_axi_awsize;
	wire [3:0]	m_axi_wstrb;
	wire		m_axi_wlast;
	wire [1:0]	m_axi_addr_suffix;

`ifdef VERILATOR_SIM
	// Access Fault异常信号
	wire [1:0] 	Access_Fault;
`endif

`ifndef NPC

	// 没有的axi信号全部强制置零
	assign io_master_awid    	= 0;                     // 无对应信号，强制置零
	assign io_master_awburst 	= 0;                     // 无对应信号，强制置零
	assign io_master_arid    	= 0;                     // 无对应信号，强制置零
	assign io_master_arburst 	= 2'b01;                 // 突发模式  INCR

	// AXI交叉开关仲裁器
	ysyx_24100006_xbar_arbiter #(
		.SRAM_ADDR(32'h8000_0000),  // 设置SRAM基地址
		.SPI_ADDR(32'h1000_1000)    // 设置SPI基地址
	) u_xbar_arbiter (
		// 时钟和复位
		.clk		(clock),
		.reset        	(reset),
		
		// ================== IFU接口 ==================
		.ifu_axi_arvalid (axi_arvalid_icache),
		.ifu_axi_arready (axi_arready_icache),
		.ifu_axi_araddr  (axi_araddr_icache),
		.ifu_axi_rvalid  (axi_rvalid_icache),
		.ifu_axi_rready  (axi_rready_icache),
		.ifu_axi_rdata   (axi_rdata_icache),
		.ifu_axi_arlen   (axi_arlen_icache),
		.ifu_axi_rlast   (axi_rlast_icache),

		// ================== MEMU接口 ==================
		.mem_axi_arvalid  (axi_arvalid_mem),
		.mem_axi_arready  (axi_arready_mem),
		.mem_axi_araddr   (axi_araddr_mem),
		.mem_axi_rvalid   (axi_rvalid_mem),
		.mem_axi_rready   (axi_rready_mem),
		.mem_axi_rdata    (axi_rdata_mem),
		.mem_axi_awvalid  (axi_awvalid_mem),
		.mem_axi_awready  (axi_awready_mem),
		.mem_axi_awaddr   (axi_awaddr_mem),
		.mem_axi_wvalid   (axi_wvalid_mem),
		.mem_axi_wready   (axi_wready_mem),
		.mem_axi_wdata    (axi_wdata_mem),
		.mem_axi_bvalid   (axi_bvalid_mem),
		.mem_axi_bready   (axi_bready_mem),
		.mem_axi_arlen    (axi_arlen_mem),
		.mem_axi_arsize   (axi_arsize_mem),
		.mem_axi_awlen    (axi_awlen_mem),
		.mem_axi_awsize   (axi_awsize_mem),
		.mem_axi_wstrb    (axi_wstrb_mem),
		.mem_axi_addr_suffix (axi_addr_suffix_mem),

		// ================== SRAM从设备 ==================
		.sram_axi_awvalid (io_master_awvalid),
		.sram_axi_awready (io_master_awready),
		.sram_axi_awaddr  (io_master_awaddr),
		.sram_axi_wvalid  (io_master_wvalid),
		.sram_axi_wready  (io_master_wready),
		.sram_axi_wdata   (io_master_wdata),
		.sram_axi_bvalid  (io_master_bvalid),
		.sram_axi_bready  (io_master_bready),
		.sram_axi_arvalid (io_master_arvalid),
		.sram_axi_arready (io_master_arready),
		.sram_axi_araddr  (io_master_araddr),
		.sram_axi_rvalid  (io_master_rvalid),
		.sram_axi_rready  (io_master_rready),
		.sram_axi_rdata   (io_master_rdata),
		.sram_axi_arlen   (io_master_arlen),
		.sram_axi_arsize  (io_master_arsize),
		.sram_axi_rlast   (io_master_rlast),
		.sram_axi_awlen   (io_master_awlen),
		.sram_axi_awsize  (io_master_awsize),
		.sram_axi_wstrb   (io_master_wstrb),
		.sram_axi_wlast   (io_master_wlast),

		// ================== UART从设备 ==================
	`ifdef NPC
		.uart_axi_awvalid (uart_axi_awvalid),
		.uart_axi_awready (uart_axi_awready),
		.uart_axi_awaddr  (uart_axi_awaddr),
		.uart_axi_wvalid  (uart_axi_wvalid),
		.uart_axi_wready  (uart_axi_wready),
		.uart_axi_wdata   (uart_axi_wdata),
		.uart_axi_wstrb   (uart_axi_wstrb),
		.uart_axi_bvalid  (uart_axi_bvalid),
		.uart_axi_bready  (uart_axi_bready),
		.uart_axi_bresp   (uart_axi_bresp),
		.uart_axi_arvalid (uart_axi_arvalid),
		.uart_axi_arready (uart_axi_arready),
		.uart_axi_araddr  (uart_axi_araddr),
		.uart_axi_rvalid  (uart_axi_rvalid),
		.uart_axi_rready  (uart_axi_rready),
		.uart_axi_rdata   (uart_axi_rdata),
		.uart_axi_rresp   (uart_axi_rresp),
	`endif

		// ================== CLINT从设备 ==================
		.clint_axi_arvalid (clint_axi_arvalid),
		.clint_axi_araddr  (clint_axi_araddr),
		.clint_axi_rvalid  (clint_axi_rvalid),
		.clint_axi_rready  (clint_axi_rready),
		.clint_axi_rdata   (clint_axi_rdata)

`ifdef VERILATOR_SIM
		// ================== 访问错误信号 ==================
		,.Access_Fault 		(Access_Fault)
`endif
	);

`else
		// AXI交叉开关仲裁器
	ysyx_24100006_xbar_arbiter #(
		.SRAM_ADDR(32'h8000_0000),  // 设置SRAM基地址
		.SPI_ADDR(32'h1000_1000)    // 设置SPI基地址
	) u_xbar_arbiter (
		// 时钟和复位
		.clk		(clock),
		.reset        	(reset),
		
		// ================== IFU接口 ==================
		.ifu_axi_arvalid (axi_arvalid_icache),
		.ifu_axi_arready (axi_arready_icache),
		.ifu_axi_araddr  (axi_araddr_icache),
		.ifu_axi_rvalid  (axi_rvalid_icache),
		.ifu_axi_rready  (axi_rready_icache),
		.ifu_axi_rdata   (axi_rdata_icache),
		.ifu_axi_arlen   (axi_arlen_icache),
		.ifu_axi_rlast   (axi_rlast_icache),

		// ================== MEMU接口 ==================
		.mem_axi_arvalid  (axi_arvalid_mem),
		.mem_axi_arready  (axi_arready_mem),
		.mem_axi_araddr   (axi_araddr_mem),
		.mem_axi_rvalid   (axi_rvalid_mem),
		.mem_axi_rready   (axi_rready_mem),
		.mem_axi_rdata    (axi_rdata_mem),
		.mem_axi_awvalid  (axi_awvalid_mem),
		.mem_axi_awready  (axi_awready_mem),
		.mem_axi_awaddr   (axi_awaddr_mem),
		.mem_axi_wvalid   (axi_wvalid_mem),
		.mem_axi_wready   (axi_wready_mem),
		.mem_axi_wdata    (axi_wdata_mem),
		.mem_axi_bvalid   (axi_bvalid_mem),
		.mem_axi_bready   (axi_bready_mem),
		.mem_axi_arlen    (axi_arlen_mem),
		.mem_axi_arsize   (axi_arsize_mem),
		.mem_axi_awlen    (axi_awlen_mem),
		.mem_axi_awsize   (axi_awsize_mem),
		.mem_axi_wstrb    (axi_wstrb_mem),
		.mem_axi_addr_suffix (axi_addr_suffix_mem),

		// ================== SRAM从设备 ==================
		.sram_axi_awvalid (sram_axi_awvalid),
		.sram_axi_awready (sram_axi_awready),
		.sram_axi_awaddr  (sram_axi_awaddr),
		.sram_axi_wvalid  (sram_axi_wvalid),
		.sram_axi_wready  (sram_axi_wready),
		.sram_axi_wdata   (sram_axi_wdata),
		.sram_axi_bvalid  (sram_axi_bvalid),
		.sram_axi_bready  (sram_axi_bready),
		.sram_axi_arvalid (sram_axi_arvalid),
		.sram_axi_arready (sram_axi_arready),
		.sram_axi_araddr  (sram_axi_araddr),
		.sram_axi_rvalid  (sram_axi_rvalid),
		.sram_axi_rready  (sram_axi_rready),
		.sram_axi_rdata   (sram_axi_rdata),
		.sram_axi_arlen   (sram_axi_arlen),
		.sram_axi_arsize  (sram_axi_arsize),
		.sram_axi_rlast   (sram_axi_rlast),
		.sram_axi_awlen   (sram_axi_awlen),
		.sram_axi_awsize  (sram_axi_awsize),
		.sram_axi_wstrb   (sram_axi_wstrb),
		.sram_axi_wlast   (sram_axi_wlast),

		// ================== UART从设备 ==================
	`ifdef NPC
		.uart_axi_awvalid (uart_axi_awvalid),
		.uart_axi_awready (uart_axi_awready),
		.uart_axi_awaddr  (uart_axi_awaddr),
		.uart_axi_wvalid  (uart_axi_wvalid),
		.uart_axi_wready  (uart_axi_wready),
		.uart_axi_wdata   (uart_axi_wdata),
		.uart_axi_wstrb   (uart_axi_wstrb),
		.uart_axi_bvalid  (uart_axi_bvalid),
		.uart_axi_bready  (uart_axi_bready),
		.uart_axi_bresp   (uart_axi_bresp),
		.uart_axi_arvalid (uart_axi_arvalid),
		.uart_axi_arready (uart_axi_arready),
		.uart_axi_araddr  (uart_axi_araddr),
		.uart_axi_rvalid  (uart_axi_rvalid),
		.uart_axi_rready  (uart_axi_rready),
		.uart_axi_rdata   (uart_axi_rdata),
		.uart_axi_rresp   (uart_axi_rresp),
	`endif

		// ================== CLINT从设备 ==================
		.clint_axi_arvalid (clint_axi_arvalid),
		.clint_axi_araddr  (clint_axi_araddr),
		.clint_axi_rvalid  (clint_axi_rvalid),
		.clint_axi_rready  (clint_axi_rready),
		.clint_axi_rdata   (clint_axi_rdata)

`ifdef VERILATOR_SIM
		// ================== 访问错误信号 ==================
		,.Access_Fault 		(Access_Fault)
`endif
	);


`endif

`ifdef VERILATOR_SIM
	// 这是为了diff test而加的npc信号
	wire [31:0] npc_M, npc_E_old, npc_E_M, npc_M_W, npc_W;
`endif

	// 前递单元
	wire		exe_is_load;
	wire		exe_mem_is_load;
	wire [1:0] 	forwardA, forwardB;
	wire [31:0] exe_fw_data, mem_fw_data;

	// 面积优化相关的信号
	wire [31:0] pc_j_m_e_n_D, alu_a_data_D, alu_b_data_D, pc_add_imm_D;
	wire [31:0]	pc_j_m_e_n_D_E, alu_a_data_D_E, alu_b_data_D_E, pc_add_imm_D_E;

	wire [31:0]	wdata_gpr_D, wdata_gpr_D_E, wdata_csr_D, wdata_csr_D_E;
	wire [31:0]	wdata_gpr_E, wdata_gpr_E_M, wdata_csr_E, wdata_csr_E_M;
	wire [31:0]	wdata_gpr_M, wdata_gpr_M_W, wdata_csr_M, wdata_csr_M_W;

	wire [2:0] 	Mem_Mask_D, Mem_Mask_D_E;
	wire [2:0] 	Mem_Mask_E, Mem_Mask_E_M;

	wire [31:0]	pc_add_4_F, pc_add_4_F_D;
	wire [31:0] pc_add_4_D, pc_add_4_D_E;

	// TAG:pipeline Reg
	// IF_ID 模块实例化
	ysyx_24100006_IF_ID u_IF_ID (
		.clk            	(clock),
		.reset          	(reset),

		// 调试信息
		.pc_i           	(pc_F),         	// IF阶段PC输入
		.pc_o           	(pc_F_D),       	// 输出到ID阶段

		.flush_i        	(redirect_valid_E_F || irq_M || (is_fence_i_D && !icache_flush_done_CE)),   // 当是跳转指令或者发生异常时冲刷
		.instruction_i  	(inst_F),			// IF阶段指令输入

		.in_valid       	(if_in_valid),		// 来自IFU
		.in_ready       	(if_in_ready),		// 输出到IFU
		.out_valid      	(id_out_valid),		// 输出到IDU
		.out_ready      	(id_out_ready),		// 来自IDU
		
		.instruction_o  	(instruction_F_D)	// 输出到ID阶段
	);

	// ID_EXE 模块实例化
	ysyx_24100006_ID_EXE u_ID_EXE (
		.clk            	(clock),
		.reset          	(reset),

`ifdef VERILATOR_SIM
		// 调试信息
		.pc_i           	(pc_D),         	// ID阶段PC输入
		.pc_o           	(pc_D_E),
`endif

		.flush_i        	(redirect_valid_E_F || irq_M),   // 当是跳转指令或者发生异常时冲刷
		.is_break_i     	(is_break_D),     			// 是否是断点指令
		.is_break_o     	(is_break_D_E),   			// 输出到EXEU


		.alu_op_i       	(alu_op_D),
		.Gpr_Write_Addr_i	(Gpr_Write_Addr_D),
		.Csr_Write_Addr_i	(Csr_Write_Addr_D),
		.Gpr_Write_RD_i 	(Gpr_Write_RD_D),
		.Jump_i         	(Jump_D),
		.is_fence_i_i   	(is_fence_i_D),
		.irq_i          	(irq_D),
		.Gpr_Write_i    	(Gpr_Write_D),
		.Csr_Write_i    	(Csr_Write_D),
		.sram_read_write_i 	(sram_read_write_D),

		.in_valid       	(id_in_valid),		// 来自IDU
		.in_ready       	(id_in_ready),		// 输出到IDU
		.out_valid      	(exe_out_valid),    	// 输出到EXEU
		.out_ready      	(exe_out_ready),    	// 来自EXEU

		.alu_op_o       	(alu_op_D_E),
		.Gpr_Write_Addr_o	(Gpr_Write_Addr_D_E),
		.Csr_Write_Addr_o	(Csr_Write_Addr_D_E),
		.Gpr_Write_RD_o 	(Gpr_Write_RD_D_E),
		.Jump_o         	(Jump_D_E),
		.is_fence_i_o   	(is_fence_i_D_E),
		.irq_o          	(irq_D_E),
		.Gpr_Write_o    	(Gpr_Write_D_E),
		.Csr_Write_o    	(Csr_Write_D_E),
		.sram_read_write_o 	(sram_read_write_D_E)

		// 面积优化相关
		,.pc_j_m_e_n_i		(pc_j_m_e_n_D)
		,.alu_a_data_i		(alu_a_data_D)
		,.alu_b_data_i		(alu_b_data_D)
		,.pc_add_imm_i		(pc_add_imm_D)
		,.pc_j_m_e_n_o		(pc_j_m_e_n_D_E)
		,.alu_a_data_o		(alu_a_data_D_E)
		,.alu_b_data_o		(alu_b_data_D_E)
		,.pc_add_imm_o		(pc_add_imm_D_E)

		,.wdata_gpr_i		(wdata_gpr_D)
		,.wdata_csr_i		(wdata_csr_D)
		,.wdata_gpr_o		(wdata_gpr_D_E)
		,.wdata_csr_o		(wdata_csr_D_E)

		,.Mem_Mask_i		(Mem_Mask_D)
		,.Mem_Mask_o		(Mem_Mask_D_E)

		,.pc_add_4_i		(pc_add_4_D)
		,.pc_add_4_o		(pc_add_4_D_E)
	);

	// EXE_MEM 模块实例化
	ysyx_24100006_EXE_MEM u_EXE_MEM (
		.clk            	(clock),
		.reset          	(reset),

`ifdef VERILATOR_SIM
		// 调试信息
		.pc_i           	(pc_E),
		.pc_o           	(pc_E_M),
		.npc_E				(npc_E_old),
		.npc_M				(npc_E_M),
`endif

		.flush_i        	(irq_M),   // 发生异常时需要冲刷流水线
		.is_break_i     	(is_break_E),     			// 是否是断点指令
		.is_break_o     	(is_break_E_M),   			// 输出到MEMU
		
		.npc_i          	(npc_E),
		.redirect_valid_i	(redirect_valid_E),
		.alu_result_i   	(alu_result_E),
		.Gpr_Write_Addr_i	(Gpr_Write_Addr_E),
		.Csr_Write_Addr_i	(Csr_Write_Addr_E),
		.Gpr_Write_RD_i 	(Gpr_Write_RD_E),
		.irq_i          	(irq_E),
		.Gpr_Write_i    	(Gpr_Write_E),
		.Csr_Write_i    	(Csr_Write_E),
		.sram_read_write_i 	(sram_read_write_E),

		.in_valid       	(exe_in_valid), 	// 来自EXEU
		.in_ready       	(exe_in_ready),     // 输出到EXEU
		.out_valid      	(mem_out_valid), 	// 输出到MEMU
		.out_ready      	(mem_out_ready), 	// 来自MEMU

		.npc_o          	(npc_E_F),
		.redirect_valid_o	(redirect_valid_E_F),
		.alu_result_o   	(alu_result_E_M),
		.Gpr_Write_Addr_o	(Gpr_Write_Addr_E_M),
		.Csr_Write_Addr_o	(Csr_Write_Addr_E_M),
		.Gpr_Write_RD_o 	(Gpr_Write_RD_E_M),
		.irq_o          	(irq_E_M),
		.Gpr_Write_o    	(Gpr_Write_E_M),
		.Csr_Write_o    	(Csr_Write_E_M),
		.sram_read_write_o 	(sram_read_write_E_M)

		// 面积优化
		,.wdata_gpr_i		(wdata_gpr_E)
		,.wdata_csr_i		(wdata_csr_E)
		,.wdata_gpr_o		(wdata_gpr_E_M)
		,.wdata_csr_o		(wdata_csr_E_M)
		
		,.Mem_Mask_i		(Mem_Mask_E)
		,.Mem_Mask_o		(Mem_Mask_E_M)
	);
	
	ysyx_24100006_hazard u_hazard(
		// ID 当前指令寄存器号：使用 IF_ID 之后、IDU 看到的那条指令
		.id_rs1        		(instruction_F_D[18:15]),
		.id_rs2        		(instruction_F_D[23:20]),
		.id_rs1_ren    		(rs1_ren_D),   // 来自 IDU 新增输出
		.id_rs2_ren    		(rs2_ren_D),
		.id_rd				(Gpr_Write_Addr_D),
		.id_wen				(Gpr_Write_D),
		.id_out_valid		(id_out_valid),
		.is_load			(is_load),
		// EX 阶段（忙判断：exe_out_valid | ~exe_out_ready）
		.ex_out_valid		(exe_in_valid),
		.ex_out_ready   	(exe_in_ready),
		.ex_rd         		(Gpr_Write_Addr_E),
		.ex_wen        		(Gpr_Write_E),

		// MEM 阶段（忙判断：mem_out_valid | ~mem_out_ready）
		.mem_out_valid 		(mem_out_valid),
		.mem_out_ready 		(mem_out_ready),
		.mem_rd        		(Gpr_Write_Addr_M),
		.mem_wen       		(Gpr_Write_M),

		.mem_stage_wen		(Gpr_Write_E_M),
		.mem_stage_rd		(Gpr_Write_Addr_E_M),
		.mem_in_valid		(mem_in_valid),
		.mem_stage_out_valid(Gpr_Write_M),

		.stall_id      		(stall_id)

		// 前递单元设计
		,.clk				(clock)
		,.exe_mem_is_load	(exe_mem_is_load)
		,.exe_is_load		(exe_is_load)
		,.mem_rvalid		(axi_rvalid_mem)
		,.forwardA      	(forwardA)
		,.forwardB      	(forwardB)
	);



	ysyx_24100006_ifu u_IF(
		.clk				(clock),
		.reset				(reset),

		// 调试信息
		.pc_F				(pc_F),

		// 直接将 hazard 的 stall 信号给 IFU：
		.stall_id			(stall_id),

		.is_fence_i			(is_fence_i_D),
		.icache_flush_done	(icache_flush_done_CE),

		.redirect_valid		(redirect_valid_E_F),
		.npc				(npc_E_F),
		// AXI 接口信号
		// read data addr
		.axi_araddr			(axi_araddr_if),
		.axi_arready		(axi_arready_if),
		.axi_arvalid		(axi_arvalid_if),
		// read data
		.axi_rvalid			(axi_rvalid_if),
		.axi_rready			(axi_rready_if),
		.axi_rdata			(axi_rdata_if),
		// 模块握手信号
		.if_in_valid		(if_in_valid),
		.if_in_ready		(if_in_ready),

		.inst_F				(inst_F)

`ifdef VERILATOR_SIM
		// Access Fault异常
		,.Access_Fault		(Access_Fault)
`endif

		// 异常处理相关
		,.csr_mtvec			(mtvec_D)
		,.EXC				(irq_M)
	);
	
	ysyx_24100006_idu u_ID(
		.clk				(clock),
		.reset				(reset),


		// 调试信息
		.pc_D				(pc_F_D),
`ifdef VERILATOR_SIM
		.pc_E				(pc_D),
`endif

		.stall_id			(stall_id),

		.instruction		(instruction_F_D),
		.irq_W				(irq_M),
		.Gpr_Write_Addr_W	(Gpr_Write_Addr_M),
		.Csr_Write_Addr_W	(Csr_Write_Addr_M),
		.Gpr_Write_W		(Gpr_Write_M),
		.Csr_Write_W		(Csr_Write_M),
		.wdata_gpr_W		(wdata_gpr_M),
		.wdata_csr_W		(wdata_csr_M),
		
		.id_out_valid		(id_out_valid),
		.id_out_ready		(id_out_ready),
		.id_in_valid		(id_in_valid),
		.id_in_ready		(id_in_ready),

		.rs1_ren			(rs1_ren_D),
		.rs2_ren			(rs2_ren_D),
		.is_break			(is_break_D),
		
		.is_fence_i			(is_fence_i_D),
		.aluop				(alu_op_D),
		.Gpr_Write_E		(Gpr_Write_D),
		.Csr_Write_E		(Csr_Write_D),
		.Gpr_Write_Addr		(Gpr_Write_Addr_D),
		.Csr_Write_Addr		(Csr_Write_Addr_D),
		.Gpr_Write_RD		(Gpr_Write_RD_D),
		.Jump				(Jump_D),
		.sram_read_write	(sram_read_write_D),
		.mtvec				(mtvec_D)

		// 异常处理相关
		,.irq_D				(irq_D)

		// 前递单元设计
		,.forwardA			(forwardA)
		,.forwardB			(forwardB)
		,.exe_fw_data		(exe_fw_data)
		,.mem_fw_data		(mem_fw_data)
		

		// 面积优化相关
		,.pc_j_m_e_n_D		(pc_j_m_e_n_D)  
		,.alu_a_data_D		(alu_a_data_D)
		,.alu_b_data_D		(alu_b_data_D)
		,.pc_add_imm_D		(pc_add_imm_D)

		,.Mem_Mask			(Mem_Mask_D)
		
		,.wdata_gpr_D		(wdata_gpr_D)
		,.wdata_csr_D		(wdata_csr_D)

		,.pc_add_4_o		(pc_add_4_D)
	);

	ysyx_24100006_exeu u_EXE(
		.clk				(clock),
		.reset				(reset),

`ifdef VERILATOR_SIM
		// 调试信息
		.pc_E				(pc_D_E),
		.pc_M				(pc_E),
`endif

		.icache_flush_done	(icache_flush_done_CE),
		.is_break_i			(is_break_D_E), // 是否是断点指令
		.is_break_o			(is_break_E),
		
		.is_fence_i			(is_fence_i_D_E),
		.irq_E				(irq_D_E),
		.aluop				(alu_op_D_E),

		.Jump				(Jump_D_E),
		.Gpr_Write_E		(Gpr_Write_D_E),
		.Csr_Write_E		(Csr_Write_D_E),
		.Gpr_Write_Addr_E	(Gpr_Write_Addr_D_E),
		.Csr_Write_Addr_E	(Csr_Write_Addr_D_E),
		.Gpr_Write_RD_E		(Gpr_Write_RD_D_E),

		.sram_read_write_E	(sram_read_write_D_E),

		.exe_out_valid		(exe_out_valid),
		.exe_out_ready		(exe_out_ready),
		.exe_in_valid		(exe_in_valid),
		.exe_in_ready		(exe_in_ready),

		.npc_E				(npc_E),
		.redirect_valid		(redirect_valid_E),
		
		.alu_result			(alu_result_E),

		.irq_M				(irq_E),
		.Gpr_Write_M		(Gpr_Write_E),
		.Csr_Write_M		(Csr_Write_E),
		.Gpr_Write_Addr_M	(Gpr_Write_Addr_E),
		.Csr_Write_Addr_M	(Csr_Write_Addr_E),
		.Gpr_Write_RD_M		(Gpr_Write_RD_E),

		.sram_read_write_M	(sram_read_write_E)

		// 前递单元设计
		,.exe_is_load		(exe_is_load)
		,.exe_fw_data		(exe_fw_data)

		// 面积优化相关
		,.pc_j_m_e_n_E		(pc_j_m_e_n_D_E)    
		,.alu_a_data_E		(alu_a_data_D_E)
		,.alu_b_data_E		(alu_b_data_D_E)
		,.pc_add_imm_E		(pc_add_imm_D_E)

		,.wdata_gpr_E		(wdata_gpr_D_E)
		,.wdata_csr_E		(wdata_csr_D_E)
		,.wdata_gpr_M		(wdata_gpr_E)
		,.wdata_csr_M		(wdata_csr_E)

		,.Mem_Mask_E		(Mem_Mask_D_E)
		,.Mem_Mask_M		(Mem_Mask_E)

		,.pc_add_4			(pc_add_4_D_E)
	);

	ysyx_24100006_memu u_MEM(
		.clk				(clock),
		.reset				(reset),

`ifdef VERILATOR_SIM
		// 调试信息
		.pc_M				(pc_E_M),
		.pc_W				(pc_M),
		.npc_E				(npc_E_M),
		.npc_M				(npc_M),
`endif

		.is_break_i			(is_break_E_M), // 是否是断点指令
		.is_break_o			(is_break_M),

		.sram_read_write	(sram_read_write_E_M),
		.alu_result_M		(alu_result_E_M),
		.irq_M				(irq_E_M),
		.Gpr_Write_M		(Gpr_Write_E_M),
		.Csr_Write_M		(Csr_Write_E_M),
		.Gpr_Write_Addr_M	(Gpr_Write_Addr_E_M),
		.Csr_Write_Addr_M	(Csr_Write_Addr_E_M),
		.Gpr_Write_RD_M		(Gpr_Write_RD_E_M),


		// AXI 接口信号
		// read data addr
		.axi_araddr			(axi_araddr_mem),
		.axi_arready		(axi_arready_mem),
		.axi_arvalid		(axi_arvalid_mem),
		// read data
		.axi_rdata			(axi_rdata_mem),
		.axi_rvalid			(axi_rvalid_mem),
		.axi_rready			(axi_rready_mem),
		// write data addr
		.axi_awaddr			(axi_awaddr_mem),
		.axi_awvalid		(axi_awvalid_mem),
		.axi_awready		(axi_awready_mem),
		// write data
		.axi_wvalid			(axi_wvalid_mem),
		.axi_wdata			(axi_wdata_mem),
		.axi_wready			(axi_wready_mem),
		// response
		.axi_bvalid			(axi_bvalid_mem),
		.axi_bready			(axi_bready_mem),
		// 新增AXI信号
		.axi_arlen			(axi_arlen_mem),
		.axi_arsize			(axi_arsize_mem),
		.axi_awlen			(axi_awlen_mem),
		.axi_awsize			(axi_awsize_mem),
		.axi_wstrb			(axi_wstrb_mem),
		.axi_addr_suffix	(axi_addr_suffix_mem),

		// 模块握手信号
		.mem_out_valid		(mem_out_valid),
		.mem_out_ready		(mem_out_ready),
		.mem_in_valid		(mem_in_valid),
		.mem_in_ready		(1'b1),
		.is_load			(is_load),

		.irq_W				(irq_M),
		.Gpr_Write_W		(Gpr_Write_M),
		.Csr_Write_W		(Csr_Write_M),
		.Gpr_Write_Addr_W	(Gpr_Write_Addr_M),
		.Csr_Write_Addr_W	(Csr_Write_Addr_M)


		// 前递单元设计
		,.exe_mem_is_load	(exe_mem_is_load)
		,.mem_fw_data		(mem_fw_data)

		// 面积优化
		,.wdata_gpr_M		(wdata_gpr_E_M)
		,.wdata_csr_M		(wdata_csr_E_M)
		,.wdata_gpr_W		(wdata_gpr_M)
		,.wdata_csr_W		(wdata_csr_M)

		,.Mem_Mask_M		(Mem_Mask_E_M)
	);


`ifdef VERILATOR_SIM

	reg 		diff;
	reg [31:0]	diff_npc;
	always@(posedge clock)begin
		if(reset)begin
			diff	<= 0;
		end else if(mem_in_valid)begin
			diff	<= 1;
			diff_npc<= npc_M;
		end else begin
			diff	<= 0;
		end
	end

`endif


	// TAG:一些仿真使用的参数:使用下面的方式需要将csrc/CircuitSim/dpi.cpp的函数取消注释，但是这样访问会拖慢仿真速度
`ifndef __ICARUS__
	import "DPI-C" function void get_inst(input int inst);
	import "DPI-C" function void get_pc(input int pc);
	import "DPI-C" function void get_npc(input int npc);
	import "DPI-C" function void get_if_valid(input bit new_inst);	// 是否是新指令
	import "DPI-C" function void get_wb_ready(input bit wb_ready);
	import "DPI-C" function void get_pc_w(input int pc_w);
	import "DPI-C" function void get_npc_w(input int npc_w);
	always @(*) begin
		get_inst(axi_rdata_if);
		get_pc(pc_F);
		get_npc(npc_E_F);					// pc先不进行diff test，因为这个进行diff test找不到信号与之对应了
		get_if_valid(if_in_valid);
		get_wb_ready(diff);			// 用于diff test，这个结合npc_temp信号刚好，因为wb_out_valid有效的时候还没有写入，所以需要使用wb_in_valid
		get_pc_w(pc_M_W);
		get_npc_w(diff_npc);
	end
`endif


	// TAGS:Performance Counters
`ifndef __ICARUS__
import "DPI-C" function void axi_handshake(
	input bit valid, 
	input bit ready, 
	input bit last, 
	input int operate_type
);
import "DPI-C" function void exeu_finish(input bit valid);
import "DPI-C" function void idu_instr_type(
	input bit valid,
	input int opcode
);
import "DPI-C" function void ins_start(input bit new_ins_valid);
import "DPI-C" function void lsu_read_latency(input bit arvalid, input bit rvalid);
import "DPI-C" function void lsu_write_latency(input bit awvalid, input bit bvalid);
import "DPI-C" function void cache_hit(input bit valid, input bit hit);
import "DPI-C" function void cache_access_time(input bit arvalid,input bit rvalid);

	always @(*) begin
		axi_handshake(axi_rvalid_if	, axi_rready_if	, 1'b1	, 1);
		axi_handshake(axi_rvalid_mem, axi_rready_mem, axi_rlast_mem	, 2);
		axi_handshake(axi_wvalid_mem, axi_wready_mem, axi_wlast_mem	, 3);

		exeu_finish(exe_in_valid);
		idu_instr_type(id_in_valid, {25'b0, instruction_F_D[6:0]});

		// 获取当前的指令的开始时间(用axi总线取指有效作为开始)
		ins_start(axi_arvalid_if);

		lsu_read_latency(axi_arvalid_mem	, axi_rvalid_mem);
		lsu_write_latency(axi_awvalid_mem	, axi_bvalid_mem);
		
		// 判断cahce是否命中
		cache_hit(if_in_valid ,icache_hit);
		// 计算cache命中的总时间
		cache_access_time(axi_arvalid_if, axi_rvalid_if);
	end
`endif
endmodule

// ===========================

// FILE 3: ./ysyx-workbench/npc/vsrc/ysyx_24100006_MEMU.v
// ===========================
/**
    访问内存模块
*/
module ysyx_24100006_memu(
    input               clk,
    input               reset,

`ifdef VERILATOR_SIM
    input [31:0]        pc_M,
    output [31:0]       pc_W,
    input  [31:0]       npc_E,
    output [31:0]       npc_M,
`endif

    input               is_break_i,
    output              is_break_o,
    input [1:0]         sram_read_write,    // 00:无访存 01:读 10:写

    // from EXE_MEM（上一拍已寄存，但仍需在本级再次锁存）
    input [31:0]        alu_result_M,

    // control signal
    input               irq_M,
    input               Gpr_Write_M,
    input               Csr_Write_M,
    input [3:0]         Gpr_Write_Addr_M,
    input [11:0]        Csr_Write_Addr_M,
    input [1:0]         Gpr_Write_RD_M,

    // AXI-Lite接口
    // read_addr
    output  reg [31:0]  axi_araddr,
    input               axi_arready,
    output  reg         axi_arvalid,
    // read data
    input   [31:0]      axi_rdata,
    input               axi_rvalid,
    output  reg         axi_rready,
    // write addr
    output  reg [31:0]  axi_awaddr,
    input               axi_awready,
    output  reg         axi_awvalid,
    // write data
    input               axi_wready,
    output  reg [31:0]  axi_wdata,
    output  reg         axi_wvalid,
    // response
    input               axi_bvalid,
    output  reg         axi_bready,

    // 新增AXI信号
    // 读通道
    output  reg [7:0]   axi_arlen,
    output  reg [2:0]   axi_arsize,
    // 写通道
    output  reg [7:0]   axi_awlen,
    output  reg [2:0]   axi_awsize,
    output  reg [3:0]   axi_wstrb,

    // 用于分辨原始的地址的后两位
    output  reg [1:0]   axi_addr_suffix,


    // 握手机制使用
    input               mem_out_valid,   // EXE_MEM -> MEMU (上游 valid)
    output              mem_out_ready,   // MEMU -> EXE_MEM  (上游 ready)
    output              mem_in_valid,    // MEMU -> MEM_WB (下游 valid)
    input               mem_in_ready,    // MEM_WB -> MEMU (下游 ready)
    output              is_load,
    // to MEM_WB（下游）
    // control signal to WBU（经 MEM_WB）
    output              irq_W,
    output              Gpr_Write_W,
    output              Csr_Write_W,
    output [3:0]        Gpr_Write_Addr_W,
    output [11:0]       Csr_Write_Addr_W

    // 面积优化
    ,input  [31:0]      wdata_gpr_M
    ,input  [31:0]      wdata_csr_M
    ,output [31:0]      wdata_gpr_W
    ,output [31:0]      wdata_csr_W

    ,input  [2:0]       Mem_Mask_M

    // 前递单元设计
    ,output             exe_mem_is_load
    ,output [31:0]      mem_fw_data
);

    // ================= 内部寄存器（在接收上游时一次性锁存） =================
    reg         is_break_r;

    reg         irq_r;
    reg         Gpr_Write_r;
    reg         Csr_Write_r;
    reg [3:0]   Gpr_Write_Addr_r;
    reg [11:0]  Csr_Write_Addr_r;
    reg [1:0]   Gpr_Write_RD_r;

    // 面积优化
    reg [31:0]  wdata_gpr_r;
    reg [31:0]  wdata_csr_r;

    reg [2:0]   Mem_Mask_r;

    // 访存锁存
    reg [1:0]   locked_sram_read_write;
    reg [31:0]  locked_read_data;

    // ================= 状态机（已精简：仅 3 个状态） =================
    // 现在：  S_IDLE, S_ACCESS(读写统一), S_SEND
    localparam  S_IDLE   = 2'b00,
                S_ACCESS = 2'b01,
                S_SEND   = 2'b11;

    reg [1:0] state;

    // ----------------- 上下游握手信号（纯组合） -----------------
    assign mem_out_ready = (state[0] == 1'b0);
    assign mem_in_valid  = (state[1] == 1'b1);

    wire [3:0] wstrb = (Mem_Mask_M == 3'b000) ? // SB
                        ((alu_result_M[1:0]==2'b00) ? 4'b0001 :
                            (alu_result_M[1:0]==2'b01) ? 4'b0010 :
                            (alu_result_M[1:0]==2'b10) ? 4'b0100 :
                                                        4'b1000) :
                        (Mem_Mask_M == 3'b001) ?       // SH
                        ((alu_result_M[1:0]==2'b00) ? 4'b0011 :
                            (alu_result_M[1:0]==2'b01) ? 4'b0110 :
                            (alu_result_M[1:0]==2'b10) ? 4'b1100 :
                                                        4'b0000) :
                        (Mem_Mask_M == 3'b011) ?       // SW
                        ((alu_result_M[1:0]==2'b00) ? 4'b1111 : 4'b0000) :
                                                4'b0000;

    wire [31:0] real_axi_wdata = 
        (wstrb == 4'b0001) ? {24'b0, wdata_gpr_M[7:0]} :
        (wstrb == 4'b0010) ? {16'b0, wdata_gpr_M[7:0], 8'b0} :
        (wstrb == 4'b0100) ? {8'b0, wdata_gpr_M[7:0], 16'b0} :
        (wstrb == 4'b1000) ? {wdata_gpr_M[7:0], 24'b0} :
        (wstrb == 4'b0011) ? {16'b0, wdata_gpr_M[15:0]} :
        (wstrb == 4'b0110) ? {8'b0, wdata_gpr_M[15:0], 8'b0} :
        (wstrb == 4'b1100) ? {wdata_gpr_M[15:0], 16'b0} :
        (wstrb == 4'b1111) ? wdata_gpr_M : 32'b0;

    wire [2:0] arsize   = (Mem_Mask_M==3'b000 || Mem_Mask_M==3'b001) ? 3'b000 :
                                                (Mem_Mask_M==3'b010 || Mem_Mask_M==3'b011) ? 3'b001 :
                                                                                              3'b010;

    wire [2:0] awsize   = (Mem_Mask_M==3'b000) ? 3'b000 :
                                                (Mem_Mask_M==3'b001) ? 3'b001 :
                                                                       3'b010;

    always @(posedge clk) begin
        if (reset) begin
            // axi 握手信号初始化
            axi_arvalid <= 0;
            axi_awvalid <= 0;
            axi_wvalid  <= 0;
            axi_rready  <= 0;
            axi_bready  <= 0;
            axi_wdata   <= 0;

            axi_arlen   <= 8'b0;
            axi_arsize  <= 3'b010;
            axi_awlen   <= 8'b0;
            axi_awsize  <= 3'b010;
            axi_wstrb   <= 4'b0;
            // axi_wlast   <= 1'b1;

            axi_addr_suffix<= 2'b0;
            locked_sram_read_write<=0;
            state       <= S_IDLE;
            locked_read_data   <= 0;
        end else begin
            case(state)
                // ================== S_IDLE ==================
                S_IDLE: begin
                    // locked_sram_read_write <= 2'b00;
                    if (mem_out_valid && mem_out_ready) begin
                        if (sram_read_write[0] == 1'b0 && sram_read_write[1] == 1'b0) begin
                            // 无访存，直接进入发送
                            state        <= S_SEND;
                        end else begin
                            // 锁存本次操作类型/地址/写数据
                            locked_sram_read_write <= sram_read_write;

                            // 直接在此拍发起 AXI 访问，下一拍转 S_ACCESS
                            if (sram_read_write[0] == 1'b1) begin
                                // READ
                                axi_araddr   <= alu_result_M;
                                axi_arsize   <= arsize;
                                axi_addr_suffix <= alu_result_M[1:0];
                                axi_arvalid  <= 1'b1;
                                axi_rready   <= 1'b0;      // 等地址握手完成再置 1
                            end else begin
                                // WRITE（地址+数据同拍发）
                                axi_awaddr   <= alu_result_M;
                                axi_awsize   <= awsize;
                                axi_awvalid  <= 1'b1;

                                axi_wdata    <= real_axi_wdata;
                                axi_wvalid   <= 1'b1;
                                // axi_wlast    <= 1'b1;
                                // 写掩码（保持原实现）
                                axi_wstrb    <=  wstrb;
                                axi_bready   <= 1'b0;      // AW/W 完成后再置 1
                            end
                            state <= S_ACCESS;
                        end
                    end
                end

                // ================== S_ACCESS（读写统一） ==================
                S_ACCESS: begin
                    if (locked_sram_read_write[0] == 1'b1) begin
                        // ---- READ PATH ----
                        if (axi_arvalid && axi_arready) begin
                            axi_arvalid <= 1'b0;
                            axi_rready  <= 1'b1;          // 开始接收读数据
                        end
                        if (axi_rvalid && axi_rready) begin
                            locked_read_data <= axi_rdata; // 读数据锁存（扩展在组合逻辑中）
                            axi_rready  <= 1'b0;
                            locked_sram_read_write <= 2'b00; // 本次读完成
                            state       <= S_SEND;
                        end
                    end else if (locked_sram_read_write[1] == 1'b1) begin
                        // ---- WRITE PATH ----
                        if (axi_awready) begin
                            axi_awvalid <= 1'b0;
                        end
                        if (axi_wready) begin
                            axi_wvalid  <= 1'b0;
                            // axi_wlast   <= 1'b0;
                            // axi_wstrb   <= 4'b0;
                            // axi_wdata   <= 32'b0;
                        end
                        if (!axi_bready && axi_awvalid==1'b0 && axi_wvalid==1'b0) begin
                            // 地址/数据都被接收后，开始等待响应
                            axi_bready <= 1'b1;
                        end
                        if (axi_bvalid && axi_bready) begin
                            axi_bready  <= 1'b0;
                            locked_sram_read_write <= 2'b00; // 本次写完成
                            state       <= S_SEND;
                        end
                    end else begin
                        // 理论不应到此分支（防御性处理）
                        state <= S_SEND;
                    end
                end

                // ================== S_SEND ==================
                S_SEND: begin
                    if (mem_in_ready) begin
                        state <= S_IDLE;

                        // 恢复 AXI 缺省
                        // axi_arsize <= 3'b010;
                        // axi_awsize <= 3'b010;
                    end
                end

                default: state <= S_IDLE;
            endcase
        end
    end

`ifdef VERILATOR_SIM
    reg [31:0]  pc_r;
    reg [31:0]  npc_r;
`endif

    // 所存数据
    always @(posedge clk) begin
        if(reset)begin
            // 本级寄存器复位
            is_break_r      <= 1'b0; // 复位时不可能是ebreak指令

`ifdef VERILATOR_SIM
            pc_r            <= 32'b0;
`endif

            irq_r           <= 1'b0;
            Gpr_Write_r     <= 1'b0;
            Csr_Write_r     <= 1'b0;
            Gpr_Write_Addr_r<= 4'b0;
            Csr_Write_Addr_r<= 12'b0;
            Gpr_Write_RD_r  <= 2'b0;
        end else begin
            if(state[0] == 1'b0)begin
                // 锁存所有将要向下游传递的字段
                is_break_r      <= is_break_i;

                irq_r           <= irq_M;
                Gpr_Write_r     <= Gpr_Write_M;
                Csr_Write_r     <= Csr_Write_M;
                Gpr_Write_Addr_r<= Gpr_Write_Addr_M;
                Csr_Write_Addr_r<= Csr_Write_Addr_M;
                Gpr_Write_RD_r  <= Gpr_Write_RD_M;

                wdata_gpr_r     <= wdata_gpr_M;
                wdata_csr_r     <= wdata_csr_M;

                Mem_Mask_r      <= Mem_Mask_M;

`ifdef VERILATOR_SIM
                pc_r            <= pc_M;
                npc_r           <= npc_E;
`endif
            end
        end
    end
    

    // ================== 对外输出（保持原样） ==================
    assign is_load = (locked_sram_read_write[0] == 1'b1); // 仅在读操作时为1

    assign is_break_o       = is_break_r;

    // 因为需要判断是否前递或者阻塞，所以寄存器是否读写以及地址都需要锁存并且在state==S_IDLE时更新
    assign Gpr_Write_W      = (state[0] == 1'b0) ? Gpr_Write_M : Gpr_Write_r;
    assign Csr_Write_W      = (state[0] == 1'b0) ? Csr_Write_M : Csr_Write_r;
    wire [1:0] Gpr_Write_RD_W   = (state[0] == 1'b0) ? Gpr_Write_RD_M : Gpr_Write_RD_r;
    assign Gpr_Write_Addr_W = (state[0] == 1'b0) ? Gpr_Write_Addr_M : Gpr_Write_Addr_r;
    assign Csr_Write_Addr_W = (state[0] == 1'b0) ? Csr_Write_Addr_M : Csr_Write_Addr_r;

`ifdef VERILATOR_SIM
    assign pc_W             = (state[0] == 1'b0) ? pc_M : pc_r;
    assign npc_M            = (state[0] == 1'b0) ? npc_E : npc_r; 
`endif


    wire [31:0] mem_rdata;
    assign mem_rdata = (axi_rvalid) ? axi_rdata : locked_read_data;

    // ---------------- Read align (barrel shift) + sign/zero extend ----------------
    // axi_addr_suffix == ARADDR[1:0]，以字节为单位右移 0/8/16/24
    wire [4:0]  shamt8      = {axi_addr_suffix, 3'b000};
    wire [31:0] shift_data  = (mem_rdata >> shamt8);

    // Byte: 目标字节对齐到 bit[7:0]
    wire [7:0]  r_byte = shift_data[7:0];

    // Half: 目标半字对齐到 bit[15:0]；当 suffix==2'b11（半字越界）按你的策略置 0
    wire [15:0] r_half = (axi_addr_suffix == 2'b11) ? 16'h0000 : shift_data[15:0];

    // 最终扩展（Mem_Mask_r: 000=LB, 001=LBU, 010=LH, 011=LHU, 100=LW）
    wire [31:0] Mem_rdata_extend =
        (Mem_Mask_r == 3'b000) ? {{24{r_byte[7]}},  r_byte} :  // LB
        (Mem_Mask_r == 3'b001) ? {24'b0,            r_byte} :  // LBU
        (Mem_Mask_r == 3'b010) ? {{16{r_half[15]}}, r_half} :  // LH
        (Mem_Mask_r == 3'b011) ? {16'b0,            r_half} :  // LHU
                                mem_rdata;                   // LW(3'b100)，其他保留


    // 异常处理相关（保持原样，未使用 axi_bresp）
    assign irq_W            = irq_r;
    // 面积优化
    assign wdata_gpr_W      = (Gpr_Write_RD_W[0] & Gpr_Write_RD_W[1]) ? Mem_rdata_extend
                                                        : ((state[0] == 1'b0) ? wdata_gpr_M : wdata_gpr_r);
    assign wdata_csr_W      = (state[0] == 1'b0) ? wdata_csr_M : wdata_csr_r;

    // 前递单元设计（保持原样）
    reg cnt;
    // always @(posedge clk) begin
    //     if(reset) begin
    //         cnt <= 1'b0;
    //     end else begin
    //         if(mem_out_valid == 1'b1 && mem_out_ready == 1'b1 && sram_read_write[0] == 1'b1)begin
    //             cnt <= 1'b1;
    //         end
    //         if((mem_out_ready == 1'b1 && mem_out_valid == 1'b1 && sram_read_write[0] == 1'b0) || (mem_out_valid == 0 && axi_rvalid == 1)) begin
    //             cnt <= 1'b0;
    //         end
    //     end
    // end

    // (mem_out_valid == 1'b1 && mem_out_ready == 1'b1 && sram_read_write[0] == 1'b1)这个是为了判断mem_out_valid == 1'b1时是否需要阻塞
    // assign exe_mem_is_load  = ((sram_read_write[0] == 1'b1 && cnt == 1) || (mem_out_valid == 1'b1 && mem_out_ready == 1'b1 && sram_read_write[0] == 1'b1)) ? 1'b1 : 1'b0;

    // 下面是面积优化版本
    always @(posedge clk) begin
        if (reset) begin
            cnt <= 1'b0;
        end
        else begin
            // 置位条件：写操作握手成功
            if (mem_out_valid && mem_out_ready && sram_read_write[0]) begin
                cnt <= 1'b1;
            end
            // 清零条件：读操作握手成功或AXI响应有效
            if ((mem_out_ready && mem_out_valid && !sram_read_write[0]) || 
                (!mem_out_valid && axi_rvalid)) begin
                    cnt <= 1'b0;
                end
        end
    end
    assign exe_mem_is_load  = ((cnt == 1) || (mem_out_valid == 1'b1 && mem_out_ready == 1'b1 )) && sram_read_write[0] == 1'b1 ? 1'b1 : 1'b0;
    assign mem_fw_data      = wdata_gpr_W;

`ifndef __ICARUS__
import "DPI-C" function void npc_trap ();
always @(*) begin
    if(is_break_o == 1 && mem_in_valid == 1'b1)
        npc_trap();
end
`endif

endmodule

// ===========================

// FILE 4: ./ysyx-workbench/npc/vsrc/ID/ysyx_24100006_CSR.v
// ===========================
/**
  系统寄存器堆（面积优化版）
  - 去除 MuxKey，使用 case 进行译码
  - 仅为可写 CSR 建立寄存器：MTVEC、MEPC、MCAUSE
  - MSTATUS/MVENDORID/MARCHID 直接组合逻辑返回常量
  - 写入与中断处理放在同一 always 块中（irq 优先）
*/
`timescale 1ns/1ps

`define ysyx_24100006_MSTATUS   12'h300
`define ysyx_24100006_MTVEC     12'h305
`define ysyx_24100006_MCAUSE    12'h342
`define ysyx_24100006_MEPC      12'h341
`define ysyx_24100006_MVENDORID 12'hF11   // 厂商 ID（Vendor ID）
`define ysyx_24100006_MARCHID   12'hF12   // 架构 ID（Architecture ID）

module ysyx_24100006_CSR #(
  parameter ADDR_WIDTH = 12,
  parameter DATA_WIDTH = 32
)(
  input                       clk,
  input                       irq,
  input       [DATA_WIDTH-1:0] wdata,
  input       [ADDR_WIDTH-1:0] waddr,
  input                       wen,
  input       [ADDR_WIDTH-1:0] raddr,          // csr 指令的 31-20 位
  output reg  [DATA_WIDTH-1:0] rdata,
  output reg  [DATA_WIDTH-1:0] mtvec,
  output reg  [DATA_WIDTH-1:0] mepc
);

  // ===== 只读/常量 CSR（组合逻辑返回，不占用触发器） =====
  // 与原实现保持一致
  localparam [DATA_WIDTH-1:0] MSTATUS_CONST   = 32'h00001800; // 原代码固定写为 0x1800
  localparam [DATA_WIDTH-1:0] MVENDORID_CONST = 32'h79737978; // 'ysyx'
  localparam [DATA_WIDTH-1:0] MARCHID_CONST   = 32'd24100006; // 工程 ID

  // ===== 写入与中断处理（合并为一个时序块；irq 优先） =====
  always @(posedge clk) begin
    if (irq) begin
      // 中断到来：记录中断返回地址
      mepc   <= wdata;                             // 与原实现一致：irq 时 mepc <- wdata
    end
    else if (wen) begin
      // 普通 CSR 写：仅允许写 MTVEC/MEPC/MCAUSE
      case (waddr)
        `ysyx_24100006_MTVEC:  mtvec  <= wdata;
        `ysyx_24100006_MEPC:   mepc   <= wdata;
        default: ; // 其他 CSR 忽略写（MSTATUS/MVENDORID/MARCHID 为只读/常量）
      endcase
    end
  end

  // ===== CSR 读：组合译码 =====
  always @* begin
    case (raddr)
      `ysyx_24100006_MSTATUS:   rdata = MSTATUS_CONST;    // 只读常量
      `ysyx_24100006_MTVEC:     rdata = mtvec;            // 可写寄存器
      `ysyx_24100006_MCAUSE:    rdata = 32'hb;           // 可写寄存器
      `ysyx_24100006_MEPC:      rdata = mepc;             // 可写寄存器
      `ysyx_24100006_MVENDORID: rdata = MVENDORID_CONST;  // 只读常量
      `ysyx_24100006_MARCHID:   rdata = MARCHID_CONST;    // 只读常量
      default:    rdata = {DATA_WIDTH{1'b0}};
    endcase
  end

`ifndef __ICARUS__
import "DPI-C" function void get_csr(
	input int mstatus, 
	input int mtvec, 
	input int mcause, 
	input int mepc
);
  always @(*) begin
    get_csr(32'h00001800, mtvec, 32'hb, mepc);
  end

`endif




endmodule

// ===========================

// FILE 5: ./ysyx-workbench/npc/vsrc/ID/ysyx_24100006_GPR.v
// ===========================
module ysyx_24100006_GPR #(
  parameter ADDR_WIDTH = 4,
  parameter DATA_WIDTH = 32
)(
  input                       clk,
  input      [DATA_WIDTH-1:0] wdata,
  input      [ADDR_WIDTH-1:0] waddr,
  input                       wen,
  input      [ADDR_WIDTH-1:0] rs1,
  input      [ADDR_WIDTH-1:0] rs2,
  output     [DATA_WIDTH-1:0] rs1_data,
  output     [DATA_WIDTH-1:0] rs2_data
);

  localparam DEPTH = 16;
  reg [DATA_WIDTH-1:0] rf [1:DEPTH-1];
  
  // 同步写：简化写法
  always @(posedge clk) begin
    if (wen && waddr != 0) begin
      rf[waddr] <= wdata;
    end
  end

  // 异步读：直接数组索引（更简洁）
  assign rs1_data = (rs1 == 0) ? 0 : rf[rs1];
  assign rs2_data = (rs2 == 0) ? 0 : rf[rs2];

endmodule
// ===========================

// FILE 6: ./ysyx-workbench/npc/vsrc/ID/ysyx_24100006_controller_remake.v
// ===========================
/**
    输出一些控制信号
*/

// `include "ysyx_24100006_ctrl_define.v"
// `include "ysyx_24100006_inst_define.v"

// 控制信号宏定义
/*----------exception---------------*/
// 是否发生异常
`define ysyx_24100006_NIRQ                  0
`define ysyx_24100006_IRQ                   1
`define ysyx_24100006_MECALL                4'b1011
/*----------exception---------------*/
// GPR_WRITE
`define ysyx_24100006_GPRW                  1
`define ysyx_24100006_GPRNW                 0
// CSR_WRITE
`define ysyx_24100006_CSRW                  1
`define ysyx_24100006_CSRNW                 0
// MEM_WRITE
`define ysyx_24100006_MEMW                  1
`define ysyx_24100006_MEMNW                 0
// 写多少字节的内存
// `define ysyx_24100006_WByte                 8'b00000001
// `define ysyx_24100006_WHWord                8'b00000011   // 半字
// `define ysyx_24100006_WWord                 8'b00001111
`define ysyx_24100006_WByte                 3'b000
`define ysyx_24100006_WHWord                3'b001   // 半字
`define ysyx_24100006_WWord                 3'b011

// MEM_READ
`define ysyx_24100006_MEMR                  1
`define ysyx_24100006_MEMNR                 0
// 读多少字节的内存，以及读取出来之后怎么进行扩展
`define ysyx_24100006_RByte                 0
`define ysyx_24100006_RByteU                1
`define ysyx_24100006_RHWord                2   // 半字
`define ysyx_24100006_RHWordU               3   // 半字
`define ysyx_24100006_RWord                 4

// pc跳转是否加imm
`define ysyx_24100006_NJUMP_MRET_JALR       0
`define ysyx_24100006_JAL                   1
// `define ysyx_24100006_JALR                  2
`define ysyx_24100006_JBEQ                  2
`define ysyx_24100006_JBNE                  3
`define ysyx_24100006_JBLT                  4
`define ysyx_24100006_JBGE                  5
`define ysyx_24100006_JBLTU                 6
`define ysyx_24100006_JBGEU                 7
// `define ysyx_24100006_JUMPMRET              9
// `define ysyx_24100006_JUMPECALL             10
// 指令的imm的类型
`define ysyx_24100006_I_TYPE_IMM            0
`define ysyx_24100006_J_TYPE_IMM            1
`define ysyx_24100006_S_TYPE_IMM            2
`define ysyx_24100006_B_TYPE_IMM            3
`define ysyx_24100006_U_TYPE_IMM            4
// 操作
/**
    这里cmp和cmpu还有sub只能是奇数，因为需要补码运算
*/
`define ysyx_24100006_add_op                0
`define ysyx_24100006_sub_op                1
`define ysyx_24100006_cmpu_op               9  // 无符号比较
`define ysyx_24100006_cmp_op                3  // 有符号比较
`define ysyx_24100006_srl_op                4  // 无符号右移
`define ysyx_24100006_sra_op                5  // 有符号右移
`define ysyx_24100006_sll_op                6  // 左移
`define ysyx_24100006_and_op                7  // 与操作
`define ysyx_24100006_xor_op                8  // 异或操作
`define ysyx_24100006_or_op                 2  // 或操作

//ALU的源操作数
//AluSrcA
`define ysyx_24100006_A_PC                  1
`define ysyx_24100006_A_RS                  0
//AluSrcB
`define ysyx_24100006_B_IMM                 1
`define ysyx_24100006_B_RT                  0
//写通用寄存器的内容
`define ysyx_24100006_GPR_IMM               0   // 写回寄存器的是符号扩展之后的立即数
`define ysyx_24100006_GPR_RESULT            1   // 写回寄存器的是alu计算的结果
`define ysyx_24100006_GPR_PC_PLUS_4         2   // 写回寄存器的是pc+4的结果
`define ysyx_24100006_MEMR_RESULT           3   // 写回寄存器的是读内存的结果
`define ysyx_24100006_CSR                   4   // 写CSR系统寄存器的值到通用寄存器中
//写系统寄存器的内容
`define ysyx_24100006_EPC                   0   // 写mepc到寄存器
`define ysyx_24100006_CW                    1   // csrrw指令使用
`define ysyx_24100006_CS                    2   // csrrs指令使用，将通用寄存器取出来的值与CSR寄存器的值进行或操作

// 是内存写入还是读取
`define ysyx_24100006_mem_idle              2'b00
`define ysyx_24100006_mem_load              2'b01
`define ysyx_24100006_mem_store             2'b10

// RISCV32E 指令宏定义
//opcode
`define ysyx_24100006_SYSTEM              7'b1110011
`define ysyx_24100006_I_type              7'b0010011
`define ysyx_24100006_R_type              7'b0110011
`define ysyx_24100006_S_type              7'b0100011
`define ysyx_24100006_B_type              7'b1100011
`define ysyx_24100006_auipc               7'b0010111
`define ysyx_24100006_lui                 7'b0110111
`define ysyx_24100006_jal                 7'b1101111
`define ysyx_24100006_jalr                7'b1100111
`define ysyx_24100006_load                7'b0000011
//function
  //ysyx_24100006_SYSTEM
`define ysyx_24100006_ebreak              12'b000000000001
`define ysyx_24100006_ecall               12'b000000000000
`define ysyx_24100006_mret                12'b001100000010
`define ysyx_24100006_inv                 3'b000
`define ysyx_24100006_csrrw               3'b001
`define ysyx_24100006_csrrs               3'b010

  //ysyx_24100006_I_type
`define ysyx_24100006_addi                3'b000
`define ysyx_24100006_slli                3'b001
`define ysyx_24100006_slti                3'b010
`define ysyx_24100006_sltiu               3'b011
`define ysyx_24100006_xori                3'b100
`define ysyx_24100006_sri                 3'b101
`define ysyx_24100006_srli                7'b0000000
`define ysyx_24100006_srai                7'b0100000
`define ysyx_24100006_ori                 3'b110
`define ysyx_24100006_andi                3'b111

  //ysyx_24100006_R_type
`define ysyx_24100006_add_sub             3'b000
`define ysyx_24100006_add                 7'b0000000
`define ysyx_24100006_sub                 7'b0100000
`define ysyx_24100006_sll                 3'b001
`define ysyx_24100006_slt                 3'b010
`define ysyx_24100006_sltu                3'b011
`define ysyx_24100006_xor                 3'b100
`define ysyx_24100006_sr                  3'b101
`define ysyx_24100006_srl                 7'b0000000
`define ysyx_24100006_sra                 7'b0100000
`define ysyx_24100006_or                  3'b110
`define ysyx_24100006_and                 3'b111

  //ysyx_24100006_S_type
`define ysyx_24100006_sb                  3'b000
`define ysyx_24100006_sh                  3'b001
`define ysyx_24100006_sw                  3'b010

  //ysyx_24100006_B_type
`define ysyx_24100006_beq                 3'b000
`define ysyx_24100006_bne                 3'b001
`define ysyx_24100006_blt                 3'b100
`define ysyx_24100006_bge                 3'b101
`define ysyx_24100006_bltu                3'b110
`define ysyx_24100006_bgeu                3'b111

  // ysyx_24100006_load
`define ysyx_24100006_lb                  3'b000
`define ysyx_24100006_lh                  3'b001
`define ysyx_24100006_lw                  3'b010
`define ysyx_24100006_lbu                 3'b100
`define ysyx_24100006_lhu                 3'b101


// import "DPI-C" function void npc_trap ();

/**
    主要是重构一下controller模块
*/
module ysyx_24100006_controller_remake(

    input [6:0]opcode,
    input [2:0]funct3,
    input [6:0]funct7,
    input [11:0]funct12,

    output  rs1_ren,
    output  rs2_ren,
    output  is_ebreak,

    /* 是否发生中断 */
    output  irq,
    // output  [3:0] irq_no,
    /* 操作类型 */
    output  [3:0]aluop,
    /* 写通用寄存器 */
    output  Gpr_Write,
    /* 写回通用寄存器的内容 */
    output  [2:0] Gpr_Write_RD,
    /* 写系统寄存器 */
    output  Csr_Write,
    /* 写系统寄存器的内容 */
    output  [1:0] Csr_Write_RD,

    /* pc的跳转类型 */
    output  [2:0] Jump,
    /* 立即数的种类 */
    output  [2:0] Imm_Type,
    /* 源操作数的种类 */
    output  AluSrcA,
    output  AluSrcB,
    /* 读内存是读多少字节，以及如何扩展 */
    output  [2:0] Mem_RMask,
    /* 写内存是多少字节 */
    output  [2:0] Mem_WMask,
    /* 判断MEMU的是读取数据、写入数据还是不操作内存 */
    output [1:0] sram_read_write,
    /* 是否刷新icache */
    output  is_fence_i

    ,output is_jalr
    ,output is_mret
);


    // rs1 是否被使用
    // - LUI/JAL 不用 rs1；AUIPC/JALR/Load/Store/Branch/I-type/R-type 用 rs1
    // - SYSTEM: CSR 指令分两类：funct3[2]==1 为 zimm，不读 rs1；否则读 rs1
    // - ecall/ebreak/mret 不读 rs1
    wire is_system   = (opcode == `ysyx_24100006_SYSTEM);
    wire is_csr      = is_system && (funct3 != `ysyx_24100006_inv) && (funct12 != `ysyx_24100006_ecall) && (funct12 != `ysyx_24100006_ebreak) && (funct12 != `ysyx_24100006_mret);
    wire csr_use_zimm= is_csr && funct3[2];  // CSRxxI 形式
    wire is_ecall    = is_system && (funct12 == `ysyx_24100006_ecall);
    assign is_ebreak = is_system && (funct12 == `ysyx_24100006_ebreak);
    assign is_mret     = is_system && (funct12 == `ysyx_24100006_mret);
    assign is_jalr     = (opcode == `ysyx_24100006_jalr);

    assign rs1_ren =
        ((opcode == `ysyx_24100006_I_type)  ||
        (opcode == `ysyx_24100006_R_type)  ||
        (opcode == `ysyx_24100006_S_type)  ||
        (opcode == `ysyx_24100006_load)    ||
        (opcode == `ysyx_24100006_B_type)  ||
        (opcode == `ysyx_24100006_jalr)    ||
        (opcode == `ysyx_24100006_auipc)   ||   // rs1 来自 PC，但对 “RAW from rd” 判定无影响；这里保持 true/false 均可。为了规整，置 0 也可以。
        (is_csr && !csr_use_zimm)) && !(opcode == `ysyx_24100006_lui) && !(opcode == `ysyx_24100006_jal) && !is_ecall && !is_ebreak && !is_mret;

    // rs2 是否被使用：R-type/Store/Branch 使用，其他大多数不使用
    assign rs2_ren =
        (opcode == `ysyx_24100006_R_type) ||
        (opcode == `ysyx_24100006_S_type) ||
        (opcode == `ysyx_24100006_B_type);


    //TAG 这样写有一个问题，ebreak如何跳转到结束，加了，但是不确定正确

    assign irq = (opcode == `ysyx_24100006_SYSTEM && (funct3 == `ysyx_24100006_inv) && (funct12 == `ysyx_24100006_ecall)) ? `ysyx_24100006_IRQ : `ysyx_24100006_NIRQ;
    
    // ALU操作类型
    assign aluop = 
        /* auipc指令 */
        (opcode == `ysyx_24100006_auipc) ? `ysyx_24100006_add_op :
        /* jal/jalr指令 */
        ((opcode == `ysyx_24100006_jal) || (opcode == `ysyx_24100006_jalr)) ? `ysyx_24100006_add_op :
        /* I-type指令 */
        (opcode == `ysyx_24100006_I_type) ? (
            (funct3 == `ysyx_24100006_addi) ? `ysyx_24100006_add_op :
            (funct3 == `ysyx_24100006_slti) ? `ysyx_24100006_cmp_op :
            (funct3 == `ysyx_24100006_sltiu) ? `ysyx_24100006_cmpu_op :
            (funct3 == `ysyx_24100006_sri) ? (
                (funct7 == `ysyx_24100006_srli) ? `ysyx_24100006_srl_op :
                (funct7 == `ysyx_24100006_srai) ? `ysyx_24100006_sra_op : 4'b0
            ) : 
            (funct3 == `ysyx_24100006_andi) ? `ysyx_24100006_and_op :
            (funct3 == `ysyx_24100006_xori) ? `ysyx_24100006_xor_op :
            (funct3 == `ysyx_24100006_ori) ? `ysyx_24100006_or_op :
            (funct3 == `ysyx_24100006_slli) ? `ysyx_24100006_sll_op : 4'b0
        ) :
        /* R-type指令 */
        (opcode == `ysyx_24100006_R_type) ? (
            (funct3 == `ysyx_24100006_add_sub) ? (
                (funct7 == `ysyx_24100006_add) ? `ysyx_24100006_add_op :
                (funct7 == `ysyx_24100006_sub) ? `ysyx_24100006_sub_op : 4'b0
            ) :
            (funct3 == `ysyx_24100006_sll) ? `ysyx_24100006_sll_op :
            (funct3 == `ysyx_24100006_slt) ? `ysyx_24100006_cmp_op :
            (funct3 == `ysyx_24100006_sltu) ? `ysyx_24100006_cmpu_op :
            (funct3 == `ysyx_24100006_xor) ? `ysyx_24100006_xor_op :
            (funct3 == `ysyx_24100006_sr) ? (
                (funct7 == `ysyx_24100006_srl) ? `ysyx_24100006_srl_op :
                (funct7 == `ysyx_24100006_sra) ? `ysyx_24100006_sra_op : 4'b0
            ) :
            (funct3 == `ysyx_24100006_or) ? `ysyx_24100006_or_op :
            (funct3 == `ysyx_24100006_and) ? `ysyx_24100006_and_op : 4'b0
        ) :
        /* S-type指令 */
        (opcode == `ysyx_24100006_S_type) ? `ysyx_24100006_add_op :
        /* Load指令 */
        (opcode == `ysyx_24100006_load) ? `ysyx_24100006_add_op :
        /* B-type指令 */
        (opcode == `ysyx_24100006_B_type) ? (
            (funct3 == `ysyx_24100006_beq || funct3 == `ysyx_24100006_bne) ? `ysyx_24100006_sub_op :
            (funct3 == `ysyx_24100006_blt || funct3 == `ysyx_24100006_bge) ? `ysyx_24100006_cmp_op :
            (funct3 == `ysyx_24100006_bltu || funct3 == `ysyx_24100006_bgeu) ? `ysyx_24100006_cmpu_op : 4'b0
        ) : 4'b0;

    // 通用寄存器写使能
    // 之前使用的wb_ready==1'b0，这个会导致写入的数据错误，所以使用mem_valid==1'b1进行写入
    assign Gpr_Write = 
        /* SYSTEM指令 */
        (opcode == `ysyx_24100006_SYSTEM) ? (
            (funct3 == `ysyx_24100006_csrrw || funct3 == `ysyx_24100006_csrrs) ? `ysyx_24100006_GPRW : 
            `ysyx_24100006_GPRNW
        ) :
        /* 其他指令 */
        (opcode == `ysyx_24100006_auipc || 
        opcode == `ysyx_24100006_lui ||
        opcode == `ysyx_24100006_jal ||
        opcode == `ysyx_24100006_jalr ||
        opcode == `ysyx_24100006_I_type ||
        opcode == `ysyx_24100006_R_type ||
        opcode == `ysyx_24100006_load) ? `ysyx_24100006_GPRW : `ysyx_24100006_GPRNW;

    // 通用寄存器写回数据选择
    assign Gpr_Write_RD = 
        /* SYSTEM指令 */
        (opcode == `ysyx_24100006_SYSTEM) ? (
            (funct3 == `ysyx_24100006_csrrw || funct3 == `ysyx_24100006_csrrs) ? 
            `ysyx_24100006_CSR : 
            `ysyx_24100006_GPR_RESULT  // 默认值
        ) :
        /* auipc指令 */
        (opcode == `ysyx_24100006_auipc) ? `ysyx_24100006_GPR_RESULT :
        /* lui指令 */
        (opcode == `ysyx_24100006_lui) ? `ysyx_24100006_GPR_IMM :
        /* jal/jalr指令 */
        ((opcode == `ysyx_24100006_jal) || (opcode == `ysyx_24100006_jalr)) ? 
        `ysyx_24100006_GPR_PC_PLUS_4 :
        /* I-type/R-type指令 */
        ((opcode == `ysyx_24100006_I_type) || (opcode == `ysyx_24100006_R_type)) ? 
        `ysyx_24100006_GPR_RESULT :
        /* Load指令 */
        (opcode == `ysyx_24100006_load) ? `ysyx_24100006_MEMR_RESULT : 
        /* 默认值 */
        3'b0;

    // 系统寄存器写使能
    assign Csr_Write = 
        (opcode == `ysyx_24100006_SYSTEM) ? 
            ((funct3 == `ysyx_24100006_csrrw || funct3 == `ysyx_24100006_csrrs) ? `ysyx_24100006_CSRW : 
            (funct3 == `ysyx_24100006_inv && funct12 == `ysyx_24100006_ecall) ? `ysyx_24100006_CSRW : 
            `ysyx_24100006_CSRNW) : `ysyx_24100006_CSRNW;

    // CSR写回数据选择
    assign Csr_Write_RD = 
        (opcode == `ysyx_24100006_SYSTEM) ? (
            (funct3 == `ysyx_24100006_inv && funct12 == `ysyx_24100006_ecall) ? 
            `ysyx_24100006_EPC :
            (funct3 == `ysyx_24100006_csrrw) ? `ysyx_24100006_CW :
            (funct3 == `ysyx_24100006_csrrs) ? `ysyx_24100006_CS : 
            2'b00  // 默认
        ) : 2'b00;

    // 跳转类型
    assign Jump = 
        ((opcode == `ysyx_24100006_jal) ? `ysyx_24100006_JAL :
        (opcode == `ysyx_24100006_B_type) ? (
            (funct3 == `ysyx_24100006_beq) ? `ysyx_24100006_JBEQ :
            (funct3 == `ysyx_24100006_bne) ? `ysyx_24100006_JBNE :
            (funct3 == `ysyx_24100006_blt) ? `ysyx_24100006_JBLT :
            (funct3 == `ysyx_24100006_bge) ? `ysyx_24100006_JBGE :
            (funct3 == `ysyx_24100006_bltu) ? `ysyx_24100006_JBLTU :
            (funct3 == `ysyx_24100006_bgeu) ? `ysyx_24100006_JBGEU : `ysyx_24100006_NJUMP_MRET_JALR
        ) : `ysyx_24100006_NJUMP_MRET_JALR);

    // 立即数类型
    assign Imm_Type = 
        (opcode == `ysyx_24100006_auipc || opcode == `ysyx_24100006_lui) ? `ysyx_24100006_U_TYPE_IMM :
        (opcode == `ysyx_24100006_jal) ? `ysyx_24100006_J_TYPE_IMM :
        (opcode == `ysyx_24100006_jalr || opcode == `ysyx_24100006_I_type || opcode == `ysyx_24100006_load) ? `ysyx_24100006_I_TYPE_IMM :
        (opcode == `ysyx_24100006_S_type) ? `ysyx_24100006_S_TYPE_IMM :
        (opcode == `ysyx_24100006_B_type) ? `ysyx_24100006_B_TYPE_IMM : 3'b0;

    // ALU源A选择
    assign AluSrcA = 
        /* auipc/jal/jalr使用PC */
        ((opcode == `ysyx_24100006_auipc) || 
        (opcode == `ysyx_24100006_jal) || 
        (opcode == `ysyx_24100006_jalr)) ? 
        `ysyx_24100006_A_PC : 
        /* 其他指令使用寄存器 */
        `ysyx_24100006_A_RS;

    // ALU源B选择 
    assign AluSrcB = 
        /* 需要立即数的指令 */
        ((opcode == `ysyx_24100006_auipc) ||
        (opcode == `ysyx_24100006_jal) ||
        (opcode == `ysyx_24100006_jalr) ||
        (opcode == `ysyx_24100006_I_type) ||
        (opcode == `ysyx_24100006_S_type) ||
        (opcode == `ysyx_24100006_load)) ? 
        `ysyx_24100006_B_IMM : 
        /* R-type/B-type使用寄存器 */
        `ysyx_24100006_B_RT;

    // 内存读模式选择
    assign Mem_RMask = 
        (opcode == `ysyx_24100006_load) ? (
            (funct3 == `ysyx_24100006_lbu) ? `ysyx_24100006_RByteU :
            (funct3 == `ysyx_24100006_lb) ? `ysyx_24100006_RByte : 
            (funct3 == `ysyx_24100006_lw) ? `ysyx_24100006_RWord : 
            (funct3 == `ysyx_24100006_lh) ? `ysyx_24100006_RHWord : 
            (funct3 == `ysyx_24100006_lhu) ? `ysyx_24100006_RHWordU : 3'b0
        ) : 3'b0;

    // 内存写模式选择
    assign Mem_WMask = 
        (opcode == `ysyx_24100006_S_type) ? (
            (funct3 == `ysyx_24100006_sb) ? `ysyx_24100006_WByte :
            (funct3 == `ysyx_24100006_sh) ? `ysyx_24100006_WHWord : 
            (funct3 == `ysyx_24100006_sw) ? `ysyx_24100006_WWord : 3'b0
        ) : 3'b0;

    assign sram_read_write =    (opcode == `ysyx_24100006_S_type)   ? `ysyx_24100006_mem_store  : 
                                (opcode == `ysyx_24100006_load)     ? `ysyx_24100006_mem_load   : `ysyx_24100006_mem_idle;

    assign is_fence_i = (opcode == 7'b0001111 && funct3 == 3'b001) ? 1'b1 : 1'b0;

`ifdef VERILATOR_SIM
    always @(*) begin
        if(opcode == `ysyx_24100006_SYSTEM && funct3 == `ysyx_24100006_inv && funct12 == `ysyx_24100006_ebreak) begin
            // $display("asdasdasdasd");
            // npc_trap();
        end
    end
`endif

endmodule

// ===========================

// FILE 7: ./ysyx-workbench/npc/vsrc/ysyx_24100006_IFU.v
// ===========================
/**
    取指模块
*/
module ysyx_24100006_ifu(
    input clk,
    input reset,
	input               stall_id, 
	
	input 				is_fence_i,
	input 				icache_flush_done,

	// from EXE
    input [31:0] 		npc,
	input 				redirect_valid, 	// 需要重定向PC
	// AXI-Lite接口
    // read_addr
	output	reg [31:0]	axi_araddr,
	input 		 		axi_arready,
	output 	reg 		axi_arvalid,
    // read data
	input 		 		axi_rvalid,
    output 	reg 		axi_rready,
	input	[31:0]		axi_rdata,

	// 握手信号
	output 	reg			if_in_valid,
	input 				if_in_ready,


    output reg	[31:0]  pc_F,


	output reg [31:0] 	inst_F
	// output [31:0]		pc_add_4_o

`ifdef VERILATOR_SIM
	// Access Fault异常
	,input	[1:0]		Access_Fault
`endif

	// 异常相关
	,input [31:0]		csr_mtvec
	,input				EXC
);

	// 是否发送重定向
	reg [1:0] redirect_flag;	// 检测上升沿
	always @(posedge clk) begin
		redirect_flag <= {redirect_flag[0],redirect_valid};
	end
	// 异常处理机制
	reg [1:0] exc_flag;	// 检测上升沿
	always @(posedge clk) begin
		exc_flag <= {exc_flag[0],EXC};
	end
	reg [1:0] req_epoch;
	reg [1:0] cur_epoch;
	always @(posedge clk) begin
		if (reset) begin
			req_epoch <= 2'b0;
			cur_epoch <= 2'b0;
		end else begin
			if (axi_arvalid && axi_arready) begin
				req_epoch <= cur_epoch;
			end
			if (( redirect_valid == 1 && redirect_flag == 2'b00) || (EXC == 1 && exc_flag == 2'b00)) begin
				cur_epoch <= cur_epoch + 1;
			end
		end
	end

	reg PCW; 

	// 是否可以启动新取指
	wire can_accept_new = !if_in_valid || (if_in_ready & ~stall_id) || (is_fence_i);

	// 握手机制
	parameter S_IDLE = 0, S_FETCH = 1, S_WAITD = 3;
	reg [1:0] state;

	always @(posedge clk) begin
		if(reset) begin
			state 			<= S_IDLE;
			if_in_valid		<= 1'b0;
			PCW				<= 1'b0;
			axi_arvalid 	<= 1'b0;
			axi_rready		<= 1'b0;

		end else begin

			// 当 icache 刷新完毕后，回到空闲状态
			// 以防止在刷新过程中进入取指状态
			if(icache_flush_done)begin
				state <= S_IDLE;
			end

			case (state)
                S_IDLE: begin
                    if (can_accept_new) begin
                        axi_arvalid <= 1'b1;
                        state       <= S_FETCH;
                    end
                end
                S_FETCH: begin
                    if (axi_arready) begin
                        axi_arvalid <= 1'b0;
                        axi_rready	<= 1'b1;
                        state   	<= S_WAITD;
                    end
                end
                S_WAITD: begin
                    if (axi_rvalid && axi_rready) begin
                        if(req_epoch == cur_epoch && !redirect_valid && !EXC) begin
							// 取指成功
							inst_F     	<= axi_rdata;
							if_in_valid	<= 1'b1; // 有新指令可输出
						end 
						axi_rready	<= 1'b0;
						state     	<= S_IDLE;
                    end
                end
            endcase

			// 当 IF_ID 接走数据后，清除 valid
            if (if_in_valid && if_in_ready) begin
                if_in_valid 		<= 1'b0;
            end
		end
	end

	// 判断指令是否为jal指令，并计算跳转的位置
	// wire [31:0] jal_target;
	// wire 		is_jal;
	// assign is_jal 		= (inst_F[6:0] == 7'b1101111) ? 1'b1 : 1'b0;
	// assign jal_target 	= pc_F + {{12{inst_F[31]}},inst_F[19:12],inst_F[20],inst_F[30:21],1'b0};


	wire [31:0] npc_temp;
	// assign npc_temp 	= EXC ? csr_mtvec : (redirect_valid ? npc : (is_jal ? jal_target : pc_F + 4));
	assign npc_temp 	= EXC ? csr_mtvec : (redirect_valid ? npc : {(pc_F[31:2] + 1'b1), 2'b00});
	assign axi_araddr 	= pc_F;


`ifndef NPC
	// ysyx_24100006_Reg #(32,32'h30000000) pc1(
	// 	.clk(clk),
	// 	.rst(reset),
	// 	.din(npc_temp),
	// 	.dout(pc_F),
	// 	.wen((if_in_valid == 1 && if_in_ready == 1) || redirect_valid || EXC)
	// );
	always @(posedge clk) begin
		if (reset) pc_F <= 32'h30000000;
		else if ((if_in_valid == 1 && if_in_ready == 1) || redirect_valid || EXC) pc_F <= npc_temp;
	end
`else
	// ysyx_24100006_Reg #(32,32'h80000000) pc1(
	// 	.clk(clk),
	// 	.rst(reset),
	// 	.din(npc_temp),
	// 	.dout(pc_F),
	// 	.wen((if_in_valid == 1 && if_in_ready == 1) || redirect_valid || EXC)
	// );
	always @(posedge clk) begin
		if (reset) pc_F <= 32'h80000000;
		else if ((if_in_valid == 1 && if_in_ready == 1) || redirect_valid || EXC) pc_F <= npc_temp;
	end
`endif


`ifndef __ICARUS__
	import "DPI-C" function void get_PCW(input bit PCW);
	always @(*) begin
		get_PCW(if_in_valid);
	end
`endif

endmodule
// ===========================

// FILE 8: ./ysyx-workbench/npc/vsrc/axi/ysyx_24100006_xbar_arbiter.v
// ===========================
// 这个模块是xbar和arbiter一起的，后面需要重新写
// 把xbar和arbiter的修改字段的功能全部写到内部去
module ysyx_24100006_xbar_arbiter #(
    parameter SRAM_ADDR     = 32'h8000_0000,
    parameter SPI_ADDR      = 32'h1000_1000
)(
    input         clk,
    input         reset,
    
    // ================== IFU接口 ==================
    // 读地址通道
    input               ifu_axi_arvalid,
    output              ifu_axi_arready,
    input   [31:0]      ifu_axi_araddr,
    // 读数据通道
    output              ifu_axi_rvalid,
    input               ifu_axi_rready,
    output  [31:0]      ifu_axi_rdata,
    // AXI新增信号
    input   [7:0]       ifu_axi_arlen,
    output              ifu_axi_rlast,

    // ================== MEMU接口 ==================
    // 读地址通道
    input               mem_axi_arvalid,
    output              mem_axi_arready,
    input   [31:0]      mem_axi_araddr,
    // 读数据通道
    output              mem_axi_rvalid,
    input               mem_axi_rready,

    output  [31:0]      mem_axi_rdata,
    // 写地址通道
    input               mem_axi_awvalid,
    output              mem_axi_awready,
    input   [31:0]      mem_axi_awaddr,
    // 写数据通道
    input               mem_axi_wvalid,
    output              mem_axi_wready,
    input   [31:0]      mem_axi_wdata,
    // 写响应通道
    output              mem_axi_bvalid,
    input               mem_axi_bready,

    // 新增AXI信号
    input   [7:0]       mem_axi_arlen,
    input   [2:0]       mem_axi_arsize,

    // 写通道
    input   [7:0]       mem_axi_awlen,
    input   [2:0]       mem_axi_awsize,
    input   [3:0]       mem_axi_wstrb,
    input   [1:0]       mem_axi_addr_suffix,

    // ================== 从设备接口 ==================
    // SRAM从设备
    output        sram_axi_awvalid,
    input         sram_axi_awready,
    output [31:0] sram_axi_awaddr,
    
    output        sram_axi_wvalid,
    input         sram_axi_wready,
    output [31:0] sram_axi_wdata,
    
    input         sram_axi_bvalid,
    output        sram_axi_bready,

    output        sram_axi_arvalid,
    input         sram_axi_arready,
    output [31:0] sram_axi_araddr,
    
    input         sram_axi_rvalid,
    output        sram_axi_rready,
    input  [31:0] sram_axi_rdata,
    // 新增AXI信号
    output  [7:0]  sram_axi_arlen,
    output  [2:0]  sram_axi_arsize,
    input          sram_axi_rlast,
    // 写通道
    output  [7:0]  sram_axi_awlen,
    output  [2:0]  sram_axi_awsize,
    output  [3:0]  sram_axi_wstrb,
    output         sram_axi_wlast,

`ifdef NPC
    // UART从设备
    output        uart_axi_awvalid,
    input         uart_axi_awready,
    output [31:0] uart_axi_awaddr,
    
    output        uart_axi_wvalid,
    input         uart_axi_wready,
    output [31:0] uart_axi_wdata,
    output [3:0]  uart_axi_wstrb,
    
    input         uart_axi_bvalid,
    output        uart_axi_bready,
    input  [1:0]  uart_axi_bresp,

    output        uart_axi_arvalid,
    input         uart_axi_arready,
    output [31:0] uart_axi_araddr,
    
    input         uart_axi_rvalid,
    output        uart_axi_rready,
    input  [31:0] uart_axi_rdata,
    input  [1:0]  uart_axi_rresp,
`endif


    output        clint_axi_arvalid,
    output [31:0] clint_axi_araddr,
    
    input         clint_axi_rvalid,
    output        clint_axi_rready,
    input  [31:0] clint_axi_rdata

`ifdef VERILATOR_SIM
    // Access Fault信号
    ,output  [1:0]  Access_Fault
`endif
);

    // 地址定义
`ifndef NPC
    parameter UART_ADDR     = 32'h1000_0000;
    parameter CLINT_ADDR    = 32'h0200_0000;
`else
    parameter UART_ADDR     = 32'ha000_03f8;
    parameter CLINT_ADDR    = 32'ha000_0048;
`endif

    // ================== 仲裁器逻辑 ==================
    parameter   ARB_IDLE        = 3'b000,
                ARB_IFU_READ    = 3'b001,
                ARB_MEMU_READ   = 3'b010,
                ARB_MEMU_WRITE  = 3'b100;

    parameter   IDLE = 1'b0, BUSY = 1'b1;

    reg         axi_state;
    reg [2:0] targeted_module;
    wire [31:0] real_sram_data;

    // 仲裁状态机
`ifndef NPC
    always @(posedge clk) begin
        if(reset) begin
            axi_state <= IDLE;
            targeted_module <= ARB_IDLE;
        end else begin
            case(axi_state)
                IDLE: begin
                    if(mem_axi_awvalid) begin
                        axi_state <= BUSY;
                        targeted_module <= ARB_MEMU_WRITE;
                    end else if(ifu_axi_arvalid) begin
                        axi_state <= BUSY;
                        targeted_module <= ARB_IFU_READ;
                    end else if(mem_axi_arvalid) begin
                        axi_state <= BUSY;
                        targeted_module <= ARB_MEMU_READ;
                    end
                end
                BUSY: begin
                    if((targeted_module == ARB_IFU_READ || targeted_module == ARB_MEMU_READ) && 
                       ((sram_axi_rready && sram_axi_rvalid && sram_axi_rlast) || (clint_axi_rready && clint_axi_rvalid))) begin
                        axi_state <= IDLE;
                        targeted_module <= ARB_IDLE;
                    end else if(targeted_module == ARB_MEMU_WRITE && 
                               sram_axi_bready && sram_axi_bvalid) begin
                        axi_state <= IDLE;
                        targeted_module <= ARB_IDLE;
                    end
                end
            endcase
        end
    end
`else
    // NPC需要判断UART的写入是否完成
    always @(posedge clk) begin
        if(reset) begin
            axi_state <= IDLE;
            targeted_module <= ARB_IDLE;
        end else begin
            case(axi_state)
                IDLE: begin
                    if(mem_axi_awvalid) begin
                        axi_state <= BUSY;
                        targeted_module <= ARB_MEMU_WRITE;
                    end else if(ifu_axi_arvalid) begin
                        axi_state <= BUSY;
                        targeted_module <= ARB_IFU_READ;
                    end else if(mem_axi_arvalid) begin
                        axi_state <= BUSY;
                        targeted_module <= ARB_MEMU_READ;
                    end
                end
                BUSY: begin
                    if((targeted_module == ARB_IFU_READ || targeted_module == ARB_MEMU_READ) && 
                       ((sram_axi_rready && sram_axi_rvalid && sram_axi_rlast) || (clint_axi_rready && clint_axi_rvalid))) begin
                        axi_state <= IDLE;
                        targeted_module <= ARB_IDLE;
                    end else if(targeted_module == ARB_MEMU_WRITE && 
                               ((sram_axi_bready && sram_axi_bvalid) || (uart_axi_bready && uart_axi_bvalid)) ) begin
                        axi_state <= IDLE;
                        targeted_module <= ARB_IDLE;
                    end
                end
            endcase
        end
    end
`endif

    // ================== 地址解码 ==================
`ifndef NPC
    wire sel_clint  =   (mem_axi_araddr[31:12] == CLINT_ADDR[31:12] && targeted_module == ARB_MEMU_READ);
    wire sel_uart   =   (mem_axi_araddr[31:12] == UART_ADDR[31:12] && targeted_module == ARB_MEMU_READ);
    wire sel_spi    =   (mem_axi_araddr[31:12] == SPI_ADDR[31:12] && targeted_module == ARB_MEMU_READ) || 
                        (ifu_axi_araddr[31:12] == SPI_ADDR[31:12] && targeted_module == ARB_IFU_READ);
    wire sel_sram   =    ~sel_clint;
`else
    wire sel_uart   = (mem_axi_awaddr >= UART_ADDR && mem_axi_awaddr < (UART_ADDR + 32'h0000_0008) && targeted_module == ARB_MEMU_WRITE);
    wire sel_clint  = (mem_axi_araddr >= CLINT_ADDR && mem_axi_araddr < (CLINT_ADDR + 32'h0000_0008) && targeted_module == ARB_MEMU_READ);
    wire sel_sram   = ~sel_uart & ~sel_clint;
    wire sel_spi    = 1'b0;
`endif

    // ================== 主设备到仲裁器的连接 ==================
    // IFU读通道
    wire ifu_arready  = (targeted_module == ARB_IFU_READ) ? sram_axi_arready : 1'b0;
    wire ifu_rvalid   = (targeted_module == ARB_IFU_READ) ? sram_axi_rvalid  : 1'b0;
    wire ifu_rlast    = (targeted_module == ARB_IFU_READ) ? sram_axi_rlast   : 1'b0;

    // MEMU读通道
    wire mem_arready  = (targeted_module == ARB_MEMU_READ) ? sram_axi_arready : 1'b0;
    wire mem_rvalid   = (targeted_module == ARB_MEMU_READ) ? sram_axi_rvalid  : 1'b0;

    // MEMU写通道
    wire mem_awready  = (targeted_module == ARB_MEMU_WRITE) ? sram_axi_awready : 1'b0;
    wire mem_wready   = (targeted_module == ARB_MEMU_WRITE) ? sram_axi_wready  : 1'b0;
    wire mem_bvalid   = (targeted_module == ARB_MEMU_WRITE) ? sram_axi_bvalid  : 1'b0;

    // ================== 仲裁器到SRAM的连接 ==================
    wire sram_arvalid = (targeted_module == ARB_MEMU_READ) ? mem_axi_arvalid : 
                       ((targeted_module == ARB_IFU_READ) ? ifu_axi_arvalid : 1'b0);
    wire sram_rready  = (targeted_module == ARB_MEMU_READ) ? mem_axi_rready : 
                       ((targeted_module == ARB_IFU_READ) ? ifu_axi_rready : 1'b0);
    wire [31:0] sram_araddr = (targeted_module == ARB_MEMU_READ) ? mem_axi_araddr : 
                             ((targeted_module == ARB_IFU_READ) ? ifu_axi_araddr : 32'b0);

    // AXI新增信号
    wire [7:0] sram_arlen = (targeted_module == ARB_MEMU_READ) ? mem_axi_arlen :
                           ((targeted_module == ARB_IFU_READ) ? ifu_axi_arlen : 8'h0);
    wire [2:0] sram_arsize = (targeted_module == ARB_MEMU_READ) ? mem_axi_arsize :3'b010;

    wire [1:0] sram_addr_suffix = (targeted_module == ARB_MEMU_READ) ? mem_axi_addr_suffix : 2'b0;

    // SRAM写通道
    wire sram_awvalid = (targeted_module == ARB_MEMU_WRITE) ? mem_axi_awvalid : 1'b0;
    wire [31:0] sram_awaddr = (targeted_module == ARB_MEMU_WRITE) ? mem_axi_awaddr : 32'b0;
    wire sram_wvalid = (targeted_module == ARB_MEMU_WRITE) ? mem_axi_wvalid : 1'b0;
    wire sram_bready = (targeted_module == ARB_MEMU_WRITE) ? mem_axi_bready : 1'b0;

    // AXI新增信号
    wire [7:0] sram_awlen = (targeted_module == ARB_MEMU_WRITE) ? mem_axi_awlen : 8'h0;
    wire [2:0] sram_awsize = (targeted_module == ARB_MEMU_WRITE) ? mem_axi_awsize : 3'h0;
    wire [3:0] sram_wstrb = (targeted_module == ARB_MEMU_WRITE) ? mem_axi_wstrb : 4'h0;

    // ================== 读数据通道寄存器 ==================
    
    // 真正读取的数据寄存
    wire [31:0] real_read_data = (sel_clint) ? clint_axi_rdata : sram_axi_rdata;

    // 最终输出连接
    assign ifu_axi_rdata = real_read_data;
    assign mem_axi_rdata = real_read_data;

    // ================== 交叉开关逻辑 ==================
    // 写通道路由
    // SRAM
    assign sram_axi_awvalid = sel_sram ? sram_awvalid : 0;
    assign sram_axi_awaddr = sel_sram ? sram_awaddr : 32'h0;
    assign sram_axi_wvalid = sel_sram ? sram_wvalid : 0;
    assign sram_axi_wdata = sel_sram ? mem_axi_wdata : 32'h0;
    assign sram_axi_bready = sel_sram ? sram_bready : 0;

`ifdef NPC
    // UART
    assign uart_axi_awvalid = sel_uart ? mem_axi_awvalid : 0;
    assign uart_axi_awaddr = sel_uart ? mem_axi_awaddr : 32'h0;
    assign uart_axi_wvalid = sel_uart ? mem_axi_wvalid : 0;
    assign uart_axi_wdata = sel_uart ? mem_axi_wdata : 32'h0;
    assign uart_axi_wstrb = sel_uart ? mem_axi_wstrb : 4'h0;
    assign uart_axi_bready = sel_uart ? mem_axi_bready : 0;
`endif

    // 读通道路由
    // SRAM
    assign sram_axi_arvalid = sel_sram ? sram_arvalid : 0;
    assign sram_axi_araddr = sel_sram ? sram_araddr : 32'h0;
    assign sram_axi_rready = sel_sram ? sram_rready : 0;

`ifdef NPC
    // UART
    assign uart_axi_arvalid = 0;
    assign uart_axi_araddr = 32'h0;
    assign uart_axi_rready = 0;
`endif

    // CLINT
    assign clint_axi_arvalid = sel_clint ? mem_axi_arvalid : 0;
    assign clint_axi_araddr = sel_clint ? mem_axi_araddr : 32'h0;
    assign clint_axi_rready = sel_clint ? mem_axi_rready : 0;

    // ================== 响应合并 ==================
`ifndef NPC
    // 响应合并（无NPC）
    assign ifu_axi_arready = sel_sram ? ifu_arready : 0;
    assign ifu_axi_rvalid = sel_sram ? ifu_rvalid : 0;
    assign ifu_axi_rlast = sel_sram ? ifu_rlast : 0;

    assign mem_axi_arready = sel_sram ? mem_arready : 
                            sel_clint ? 1'b1 : 0;
    assign mem_axi_rvalid = sel_sram ? mem_rvalid : 
                           sel_clint ? clint_axi_rvalid : 0;

    assign mem_axi_awready = sel_sram ? mem_awready : 0;
    assign mem_axi_wready = sel_sram ? mem_wready : 0;
    assign mem_axi_bvalid = sel_sram ? mem_bvalid : 0;
`else
    // 响应合并（有NPC）
    assign ifu_axi_arready = sel_sram ? ifu_arready : 0;
    assign ifu_axi_rvalid = sel_sram ? ifu_rvalid : 0;
    assign ifu_axi_rlast = sel_sram ? ifu_rlast : 0;

    assign mem_axi_arready = sel_sram ? mem_arready : 
                            sel_uart ? uart_axi_arready : 
                            sel_clint ? 1'b1 : 0;
    assign mem_axi_rvalid = sel_sram ? mem_rvalid : 
                           sel_uart ? uart_axi_rvalid : 
                           sel_clint ? clint_axi_rvalid : 0;

    assign mem_axi_awready = sel_sram ? mem_awready : 
                            sel_uart ? uart_axi_awready : 0;
    assign mem_axi_wready = sel_sram ? mem_wready : 
                           sel_uart ? uart_axi_wready : 0;
    assign mem_axi_bvalid = sel_sram ? mem_bvalid : 
                           sel_uart ? uart_axi_bvalid : 0;
`endif

    // ================== AXI信号传递 ==================
    assign sram_axi_arlen = sram_arlen;
    assign sram_axi_arsize = sel_uart ? 3'b000 : (sel_spi ? sram_arsize : 3'b010);
    assign sram_axi_awlen = sram_awlen;
    assign sram_axi_awsize = sram_awsize;
    assign sram_axi_wstrb = sram_wstrb;
    assign sram_axi_wlast = 1'b1;

`ifdef VERILATOR_SIM
    // Acess Fault信号
    assign Access_Fault = 2'b00; // 先不实现
`endif

endmodule
// ===========================

// FILE 9: ./ysyx-workbench/npc/vsrc/pipeline/ysyx_2410006_IF_ID.v
// ===========================
// 冲刷流水线：清空有效位即可；数据在 valid=0 时视为无效，不必清零（节省复位/冲刷多路选择器面积）
// TODO: PCW信号不用向外暴露了（保持现有接口，不新增端口）
module ysyx_24100006_IF_ID(
    input           clk,
    input           reset,

    input           flush_i,

    // IFU  <----> IF_ID
    input           in_valid,
    output          in_ready,
    input   [31:0]  instruction_i,

    // IF_ID <----> IDU
    output          out_valid,
    input           out_ready,
    output  [31:0]  instruction_o


    ,input  [31:0]  pc_i,
    output  [31:0]  pc_o

);

    // ================= Registers =================
    reg             valid_q;

    reg [31:0]      instruction_q;


    reg [31:0]      pc_q;


    // ================= Handshake =================
    // 简化：in_ready = ~valid_q || out_ready
    // 语义：若本级为空即可接收；或下游准备好时可滑动
    assign in_ready   = (~valid_q) || out_ready;
    assign out_valid  =  valid_q;

    // ================= Outputs ===================
    assign instruction_o = instruction_q;


    assign pc_o          = pc_q;


    // ================= Control ===================
    // 接收新数据（同时满足：上游有效 且 我方可接收）
    wire accept = in_valid && in_ready;
    // 下游取走当前拍（本级持有有效 且 下游 ready）
    wire send   = valid_q && out_ready;

    // 有效位：flush/复位优先；其次依据 accept/send 自动进出栈
    always @(posedge clk) begin
        if (reset) begin
            valid_q <= 1'b0;
        end else if (flush_i) begin
            valid_q <= 1'b0; // 冲刷：仅清有效位
        end else begin
            // 若同时 send 与 accept，保持 valid=1（换新不掉拍）
            if (accept)
                valid_q <= 1'b1;
            else if (send)
                valid_q <= 1'b0;
            // 否则保持
        end
    end

    // 数据位：仅在真正接收新拍时写入（降低翻转/利于推导CE门控）
    always @(posedge clk) begin
        if (accept) begin
            instruction_q <= instruction_i;

            pc_q          <= pc_i;

        end
    end

endmodule

// ===========================

// FILE 10: ./ysyx-workbench/npc/vsrc/pipeline/ysyx_2410006_MEM_WB.v
// ===========================
// 最后的那个reset不能删除或者被设置为仅仿真有效，不然就会运行rtt出错
module ysyx_24100006_MEM_WB(
    input           clk,
    input           reset,

`ifdef VERILATOR_SIM
    input  [31:0]   pc_i,
    output [31:0]   pc_o,
    input  [31:0]   npc_M,
    output [31:0]   npc_W,
`endif

    input           is_break_i,
    output          is_break_o,
    
    // MEMU  <----> MEM_WB
    input           in_valid,
    output          in_ready,
    
    input  [3:0]    Gpr_Write_Addr_i,
    input  [11:0]   Csr_Write_Addr_i,
    input  [3:0]    irq_no_i,

    // 控制信号
    input           irq_i,
    input           Gpr_Write_i,
    input           Csr_Write_i,

    // MEM_WB <----> WBU
    output          out_valid,
    input           out_ready,

    output [3:0]    Gpr_Write_Addr_o,
    output [11:0]   Csr_Write_Addr_o,
    output [3:0]    irq_no_o,

    // 控制信号
    output          irq_o,
    output          Gpr_Write_o,
    output          Csr_Write_o

    // 面积优化
    ,input  [31:0]  wdata_csr_i
    ,input  [31:0]  wdata_gpr_i
    ,output [31:0]  wdata_csr_o
    ,output [31:0]  wdata_gpr_o

    // 异常处理相关
    ,input          flush_i
);

    // ================= Registers =================
    reg             valid_q;

    reg [3:0]       Gpr_Write_Addr_q;
    reg [11:0]      Csr_Write_Addr_q;
    reg [3:0]       irq_no_q;

    reg             irq_q;
    reg             Gpr_Write_q;
    reg             Csr_Write_q;
    reg             is_break_q;

    // payload
    reg [31:0]      wdata_gpr_q;
    reg [31:0]      wdata_csr_q;

`ifdef VERILATOR_SIM
    reg [31:0]      pc_q;
    reg [31:0]      npc_q;
`endif

    // ================= Handshake =================
    // 空或“可滑动”即可接收
    assign in_ready  = (~valid_q) || out_ready;
    // flush 当拍屏蔽输出，保持“即刻杀”语义
    assign out_valid = valid_q & ~flush_i;

    // ================= Outputs ===================
    assign Gpr_Write_Addr_o = Gpr_Write_Addr_q;
    assign Csr_Write_Addr_o = Csr_Write_Addr_q;
    assign irq_no_o         = irq_no_q;

    assign irq_o            = irq_q;
    assign Gpr_Write_o      = Gpr_Write_q;
    assign Csr_Write_o      = Csr_Write_q;
    assign is_break_o       = is_break_q;

    assign wdata_gpr_o      = wdata_gpr_q;
    assign wdata_csr_o      = wdata_csr_q;

`ifdef VERILATOR_SIM
    assign pc_o             = pc_q;
    assign npc_W            = npc_q;
`endif

    // ================= Control ===================
    wire accept = in_valid  && in_ready;      // 本拍接入新数据
    wire send   = out_valid && out_ready;     // 本拍对下游完成握手（考虑 flush 屏蔽）

    // 有效位：复位/冲刷优先
    always @(posedge clk) begin
        if (reset) begin
            valid_q <= 1'b0;
        end else if (flush_i) begin
            valid_q <= 1'b0;                  // 冲刷：仅清有效位
        end else begin
            if (accept)      valid_q <= 1'b1; // 有新拍 → 有效
            else if (send)   valid_q <= 1'b0; // 被消费且无新拍 → 置空
            // 否则保持
        end
    end

    // 数据位：仅在 accept 时更新（便于门控/降翻转）
    always @(posedge clk) begin
        if (accept) begin
            Gpr_Write_Addr_q <= Gpr_Write_Addr_i;
            Csr_Write_Addr_q <= Csr_Write_Addr_i;
            irq_no_q         <= irq_no_i;

            irq_q            <= irq_i;
            Gpr_Write_q      <= Gpr_Write_i;
            Csr_Write_q      <= Csr_Write_i;
            is_break_q       <= is_break_i;

            wdata_gpr_q      <= wdata_gpr_i;
            wdata_csr_q      <= wdata_csr_i;

`ifdef VERILATOR_SIM
            pc_q             <= pc_i;
            npc_q            <= npc_M;
`endif
        end
// `ifdef VERILATOR_SIM
        // 仿真友好：reset/flush 清零，便于读波形（综合时可不清以省面积）
        else if (reset || flush_i) begin
            Gpr_Write_Addr_q <= 4'd0;
            Csr_Write_Addr_q <= 12'd0;
            irq_no_q         <= 4'b0;

            irq_q            <= 1'b0;
            Gpr_Write_q      <= 1'b0;
            Csr_Write_q      <= 1'b0;
            is_break_q       <= 1'b0;

            wdata_gpr_q      <= 32'd0;
            wdata_csr_q      <= 32'd0;

`ifdef VERILATOR_SIM
            pc_q             <= pc_i;
            npc_q            <= npc_M;
`endif
        end
// `endif
    end

endmodule

// ===========================

// FILE 11: ./ysyx-workbench/npc/vsrc/pipeline/ysyx_2410006_ID_EXE.v
// ===========================
// 冲刷流水线就是将所有的存储的数据都置为0
module ysyx_24100006_ID_EXE(
    input           clk,
    input           reset,

`ifdef VERILATOR_SIM
    // 调试使用
    input [31:0]    pc_i,
    output [31:0]   pc_o,
`endif

    input           is_break_i,
    output          is_break_o,
    input           flush_i,   // NEW: flush current ID/EXE pipeline register on redirect
    // IDU  <----> ID_EXE
    input           in_valid,
    output          in_ready,
    
    input [3:0]     alu_op_i,
    input [3:0]     Gpr_Write_Addr_i,
    input [11:0]    Csr_Write_Addr_i,
    input [1:0]     Gpr_Write_RD_i,
    input [2:0]     Jump_i,

    // 控制信号
    input           is_fence_i_i,
    input           irq_i,
    input           Gpr_Write_i,
    input           Csr_Write_i,
    input [1:0]     sram_read_write_i,


    // ID_EXE <----> EXEU
    output          out_valid,
    input           out_ready,      // 下一级给的输入
    
    output [3:0]    alu_op_o,
    output [3:0]    Gpr_Write_Addr_o,
    output [11:0]   Csr_Write_Addr_o,
    output [1:0]    Gpr_Write_RD_o,
    output [2:0]    Jump_o
        
    // 面积优化
    ,input  [31:0]  pc_j_m_e_n_i
    ,input  [31:0]  alu_a_data_i
    ,input  [31:0]  alu_b_data_i
    ,input  [31:0]  pc_add_imm_i
    ,output [31:0]  pc_j_m_e_n_o
    ,output [31:0]  alu_a_data_o
    ,output [31:0]  alu_b_data_o
    ,output [31:0]  pc_add_imm_o

    ,input  [31:0]  wdata_csr_i
    ,input  [31:0]  wdata_gpr_i
    ,output [31:0]  wdata_csr_o
    ,output [31:0]  wdata_gpr_o

    ,input  [2:0]   Mem_Mask_i
    ,output [2:0]   Mem_Mask_o

    ,input  [31:0]  pc_add_4_i
    ,output [31:0]  pc_add_4_o,

    // 控制信号
    output          is_fence_i_o,
    output          irq_o,
    output          Gpr_Write_o,
    output          Csr_Write_o,
    output [1:0]    sram_read_write_o
);

    // 声明临时寄存器

`ifdef VERILATOR_SIM
    // 调试使用
    reg [31:0]      pc_temp;
`endif

    reg [3:0]       alu_op_temp;
    reg [3:0]       Gpr_Write_Addr_temp;
    reg [11:0]      Csr_Write_Addr_temp;
    reg [1:0]       Gpr_Write_RD_temp;
    reg [2:0]       Jump_temp;
    reg [2:0]       Mem_WMask_temp;
    reg [2:0]       Mem_RMask_temp;
    reg             is_fence_i_temp;
    reg             irq_temp;
    reg             Gpr_Write_temp;
    reg             Csr_Write_temp;
    reg             is_break_temp;
    reg [1:0]       sram_read_write_temp;
    reg             valid_temp;
    
    // 面积优化
    reg [31:0]      pc_j_m_e_n_temp;
    reg [31:0]      alu_a_data_temp;
    reg [31:0]      alu_b_data_temp;
    reg [31:0]      pc_add_imm_temp;
    assign pc_j_m_e_n_o         = pc_j_m_e_n_temp;
    assign alu_a_data_o         = alu_a_data_temp;
    assign alu_b_data_o         = alu_b_data_temp;
    assign pc_add_imm_o         = pc_add_imm_temp;

    reg [31:0]      wdata_gpr_temp;
    reg [31:0]      wdata_csr_temp;
    assign wdata_gpr_o          = wdata_gpr_temp;
    assign wdata_csr_o          = wdata_csr_temp;

    reg [2:0]       Mem_Mask_temp;
    assign Mem_Mask_o           = Mem_Mask_temp;

    reg [31:0]      pc_add_4_temp;
    assign pc_add_4_o           = pc_add_4_temp;


    // 使用 assign 语句将临时寄存器赋值给输出信号
`ifdef VERILATOR_SIM
    // 调试使用
    assign pc_o                 = pc_temp;
`endif

    assign alu_op_o             = alu_op_temp;
    assign Gpr_Write_Addr_o     = Gpr_Write_Addr_temp;
    assign Csr_Write_Addr_o     = Csr_Write_Addr_temp;
    assign Gpr_Write_RD_o       = Gpr_Write_RD_temp;
    assign Jump_o               = Jump_temp;
    assign is_fence_i_o         = is_fence_i_temp;
    assign irq_o                = irq_temp;
    assign Gpr_Write_o          = Gpr_Write_temp;
    assign Csr_Write_o          = Csr_Write_temp;
    assign is_break_o           = is_break_temp;
    assign sram_read_write_o    = sram_read_write_temp;

    assign out_valid            = (flush_i == 1'b1) ? 1'b0 : valid_temp;
    // 当没有有效存储时，或者当存储并且下游准备好时，可以接受新数据（可以滑动）
    assign in_ready             = (!valid_temp) || (out_ready && valid_temp);

    always@(posedge clk)begin
        if(reset)begin
            valid_temp <= 1'b0;
        end else begin
            // flush的时候，将有效位清除
            if(flush_i)begin
                valid_temp <= 1'b0;
            end
            // 当允许接受新输入时
            else if (in_ready) begin
                valid_temp <= in_valid;
            end
            // 否则保持不变
        end
    end

    // 如果 in_valid==0 且 in_ready==1 -> 清除有效（已由 valid_r <= in_valid 完成）
    always @(posedge clk) begin
        if (reset) begin
            // 复位逻辑 - 所有临时寄存器赋值为0

`ifdef VERILATOR_SIM
            // 调试使用
            pc_temp                     <= 32'h00000000;
`endif

            alu_op_temp                 <= 4'd0;
            Gpr_Write_Addr_temp         <= 4'b0;
            Csr_Write_Addr_temp         <= 12'b0;
            Gpr_Write_RD_temp           <= 2'd0;
            Jump_temp                   <= 3'd0;
            is_fence_i_temp             <= 1'd0;
            irq_temp                    <= 1'd0;
            Gpr_Write_temp              <= 1'd0;
            Csr_Write_temp              <= 1'd0;
            is_break_temp               <= 1'b0;        // 复位时不是ebreak状态
            sram_read_write_temp        <= 2'd0;
        end else begin
            // flush的时候，将所有的数据都清除，不然会导致错误的指令被执行
            if(flush_i)begin
                irq_temp                <= 1'b0; // 冲刷流水线时清除中断信号

`ifdef VERILATOR_SIM
                // 调试使用
                pc_temp                 <= 32'h00000000;
`endif

                Jump_temp               <= 3'd0;
                is_fence_i_temp         <= 1'd0;
                Gpr_Write_temp          <= 1'd0;
                Csr_Write_temp          <= 1'd0;
                is_break_temp           <= 1'b0;        // 复位时不是ebreak状态
            end
            // 当允许接受新输入时
            else if (in_ready & in_valid) begin
                // 非复位逻辑 - 将输入信号赋值给临时寄存器

`ifdef VERILATOR_SIM
                // 调试使用
                pc_temp                 <= pc_i;
`endif
                alu_op_temp             <= alu_op_i;
                Gpr_Write_Addr_temp     <= Gpr_Write_Addr_i;
                Csr_Write_Addr_temp     <= Csr_Write_Addr_i;
                Gpr_Write_RD_temp       <= Gpr_Write_RD_i;
                Jump_temp               <= Jump_i;
                is_fence_i_temp         <= is_fence_i_i;
                irq_temp                <= irq_i;
                Gpr_Write_temp          <= Gpr_Write_i;
                Csr_Write_temp          <= Csr_Write_i;
                is_break_temp           <= is_break_i;
                sram_read_write_temp    <= sram_read_write_i;

                // 面积优化
                pc_j_m_e_n_temp         <= pc_j_m_e_n_i;
                alu_a_data_temp         <= alu_a_data_i;
                alu_b_data_temp         <= alu_b_data_i;
                pc_add_imm_temp         <= pc_add_imm_i;

                wdata_gpr_temp          <= wdata_gpr_i;
                wdata_csr_temp          <= wdata_csr_i;

                Mem_Mask_temp           <= Mem_Mask_i;

                pc_add_4_temp           <= pc_add_4_i;
            end
            // 没有新数据则一直保持数据
        end
    end

endmodule
// ===========================

// FILE 12: ./ysyx-workbench/npc/vsrc/pipeline/ysyx_2410006_EXE_MEM.v
// ===========================
// 冲刷流水线就是将所有的存储的数据都置为0
// TODO：要想是否可以建一个新的模块来算这个，放在IFU的前面，这个应该存在问题，因为最开始的几拍就流不起来了
module ysyx_24100006_EXE_MEM(
    input           clk,
    input           reset,

`ifdef VERILATOR_SIM
    input [31:0]    pc_i,
    output [31:0]   pc_o,
    input [31:0]    npc_E,
    output [31:0]   npc_M,
`endif

    input           is_break_i,
    output          is_break_o,

    // EXEU   <----> EXE_MEM
    input           in_valid,
    output          in_ready,
    input [31:0]    npc_i,          // 还是需要缓存一下npc
    input           redirect_valid_i,   // 是使用EXE计算的NPC还是直接pc+4
    input [31:0]    alu_result_i,
    input [3:0]     Gpr_Write_Addr_i,
    input [11:0]    Csr_Write_Addr_i,
    input [1:0]     Gpr_Write_RD_i,

    // 控制信号
    input           irq_i,
    input           Gpr_Write_i,
    input           Csr_Write_i,
    input [1:0]     sram_read_write_i,

    // EXE_MEM <----> MEMU
    output          out_valid,
    input           out_ready,
    output [31:0]   npc_o,          // 缓存后的npc,这个信号是去IFU的
    output          redirect_valid_o,
    output [31:0]   alu_result_o,
    output [3:0]    Gpr_Write_Addr_o,
    output [11:0]   Csr_Write_Addr_o,
    output [1:0]    Gpr_Write_RD_o,

    // 控制信号
    output          irq_o,
    output          Gpr_Write_o,
    output          Csr_Write_o,
    output [1:0]    sram_read_write_o

    // 面积优化
    ,input  [31:0]  wdata_csr_i
    ,input  [31:0]  wdata_gpr_i
    ,output [31:0]  wdata_csr_o
    ,output [31:0]  wdata_gpr_o

    ,input  [2:0]   Mem_Mask_i
    ,output [2:0]   Mem_Mask_o

    // 异常处理相关
    ,input          flush_i
);

    // 声明临时寄存器
    reg [31:0]      npc_temp;
    reg             redirect_valid_temp;
    reg [31:0]      alu_result_temp;
    reg [31:0]      rs2_data_temp;
    
    reg [3:0]       Gpr_Write_Addr_temp;
    reg [11:0]      Csr_Write_Addr_temp;
    reg [1:0]       Gpr_Write_RD_temp;
    reg             irq_temp;
    reg             Gpr_Write_temp;
    reg             Csr_Write_temp;
    reg             is_break_temp; // 是否是ebreak指令
    reg [1:0]       sram_read_write_temp;
    reg             valid_temp;

`ifdef VERILATOR_SIM
    reg [31:0]      pc_temp;
    reg [31:0]      npc_temp_old;
`endif

    // 面积优化
    reg [31:0]      wdata_gpr_temp;
    reg [31:0]      wdata_csr_temp;
    assign wdata_gpr_o          = wdata_gpr_temp;
    assign wdata_csr_o          = wdata_csr_temp;

    reg [2:0]       Mem_Mask_temp;
    assign Mem_Mask_o           = Mem_Mask_temp;

    // 使用 assign 语句将临时寄存器赋值给输出信号
    assign npc_o                = npc_temp;
    assign redirect_valid_o     = redirect_valid_temp;
    assign alu_result_o         = alu_result_temp;
    assign Gpr_Write_Addr_o     = Gpr_Write_Addr_temp;
    assign Csr_Write_Addr_o     = Csr_Write_Addr_temp;
    assign Gpr_Write_RD_o       = Gpr_Write_RD_temp;
    assign irq_o                = irq_temp;
    assign Gpr_Write_o          = Gpr_Write_temp;
    assign Csr_Write_o          = Csr_Write_temp;
    assign is_break_o           = is_break_temp;
    assign sram_read_write_o    = sram_read_write_temp;

    assign out_valid            = valid_temp;
    // 当没有有效存储时，或者当存储并且下游准备好时，可以接受新数据（可以滑动）
    assign in_ready             = (!valid_temp) || (out_ready && valid_temp);

`ifdef VERILATOR_SIM
    assign pc_o                 = pc_temp;
    assign npc_M                = npc_temp_old;
`endif

    always@(posedge clk)begin
        if(reset)begin
            valid_temp <= 1'b0;
        end else begin
            // flush的时候，将有效位清除
            if(flush_i)begin
                valid_temp  <= 1'b0;
            end
            // 当允许接受新输入时
            else if (in_ready) begin
                valid_temp <= in_valid;
            end
            // 否则保持不变
        end
    end

    // 如果 in_valid==0 且 in_ready==1 -> 清除有效（已由 valid_r <= in_valid 完成）
    always @(posedge clk) begin
        if (reset) begin
            // 复位逻辑 - 所有临时寄存器赋值为0

`ifdef VERILATOR_SIM
            pc_temp                 <= 32'h00000000;
`endif

            npc_temp                <= 32'd0;
            redirect_valid_temp     <= 1'b0;
            alu_result_temp         <= 32'd0;
            Gpr_Write_Addr_temp     <= 4'b0;
            Csr_Write_Addr_temp     <= 12'b0;
            Gpr_Write_RD_temp       <= 2'd0;
            irq_temp                <= 1'd0;
            Gpr_Write_temp          <= 1'd0;
            Csr_Write_temp          <= 1'd0;
            is_break_temp           <= 1'b0; // 复位时不可能是ebreak指令
            sram_read_write_temp    <= 2'd0;


        end
        // 若果当前输出被接受且有跳转指令，则清除当前的有效位，防止错误执行
        else if(out_ready && redirect_valid_temp)begin 
            redirect_valid_temp     <=0;
        end
        else if(flush_i == 1)begin
            irq_temp                <= 1'b0;
        end
        else begin
            // 当允许接受新输入时
            if (in_ready & in_valid) begin
                // if (in_valid)begin
                    // 非复位逻辑 - 将输入信号赋值给临时寄存器
                    npc_temp                <= npc_i;
                    redirect_valid_temp     <= redirect_valid_i;
                    alu_result_temp         <= alu_result_i;
                    Gpr_Write_Addr_temp     <= Gpr_Write_Addr_i;
                    Csr_Write_Addr_temp     <= Csr_Write_Addr_i;
                    Gpr_Write_RD_temp       <= Gpr_Write_RD_i;
                    irq_temp                <= irq_i;
                    Gpr_Write_temp          <= Gpr_Write_i;
                    Csr_Write_temp          <= Csr_Write_i;
                    is_break_temp           <= is_break_i;
                    sram_read_write_temp    <= sram_read_write_i;
`ifdef VERILATOR_SIM
                    pc_temp                 <= pc_i;
                    npc_temp_old            <= npc_i;
`endif
                    // 面积优化
                    wdata_gpr_temp          <= wdata_gpr_i;
                    wdata_csr_temp          <= wdata_csr_i;

                    Mem_Mask_temp           <= Mem_Mask_i;
                end 
            end
            // 没有新数据则一直保持数据
        end
    // end

endmodule

// TAGS:原版面积更小
// ===========================

// FILE 13: ./ysyx-workbench/npc/vsrc/pipeline/ysyx_24100006_hazard.v
// ===========================
module ysyx_24100006_hazard(
    // data hazard
input         clk,
    // 来自 ID 阶段
    input  [3:0]   id_rs1,          // instruction[18:15]
    input  [3:0]   id_rs2,          // instruction[23:20]
    input          id_rs1_ren,
    input          id_rs2_ren,
    input  [3:0]    id_rd,
    input           id_wen,
input id_out_valid,         //什么时候需要阻塞
input is_load,
    // EX 阶段目的寄存器与状态
    input          ex_out_valid,
    input          ex_out_ready,
    input  [3:0]   ex_rd,
    input          ex_wen,          // Gpr_Write_E

    // MEM 阶段
    input          mem_out_valid,    // 注意：mem 模块的 "out" 对应 u_EXE_MEM 的 out -> mem_out_valid
    input          mem_out_ready,
    input  [3:0]   mem_rd,
    input          mem_wen,         // Gpr_Write_M

    input          mem_stage_wen,   // 这里是因为load-use的情况，所以需要知道mem阶段正在处理的指令的rd是否写回，而不能学之前使用mem_wen，mem_wen是下一条指令的，而不是表示正在处理的指令是否需要写入寄存器
    input [3:0]    mem_stage_rd,    // 这才是真正的MEM阶段的rd，mem_rd其实是EXE阶段出来的，但是如果是load-use，那么mem_rd和mem_stage_rd不一样
    input          mem_in_valid,
    input          mem_stage_out_valid,     // 表示mem处理完总线请求时，存储的要写回的寄存器是否有效

    output         stall_id

    // 前递单元设计
    ,input          exe_mem_is_load
    ,input          exe_is_load // EXE阶段的指令是否是load指令
    ,input          mem_rvalid  // MEM阶段访存是否取出结果
    ,output [1:0]   forwardA    // 00: 不前递，01: 从EX前递，10: 从MEM前递, 11: 从WB前递
    ,output [1:0]   forwardB
);

    // rd != x0
    wire ex_wen_v  = ex_wen  & (ex_rd  != 4'd0);
    wire mem_wen_v = mem_wen & (mem_rd != 4'd0);

    // 与任一阶段 RAW 冲突
    wire raw_ex_rs1  = id_rs1_ren & ex_wen_v  & (id_rs1 == ex_rd);
    wire raw_ex_rs2  = id_rs2_ren & ex_wen_v  & (id_rs2 == ex_rd);
    wire raw_mem_rs1 = id_rs1_ren & mem_wen_v & (id_rs1 == mem_rd);
    wire raw_mem_rs2 = id_rs2_ren & mem_wen_v & (id_rs2 == mem_rd);

    // 前递单元设计(有冲突，且能够通过前递解决，在输出有效的时候就前递)
    // 优先级：EX > MEM > WB
    wire can_rs1_fw_exe, can_rs2_fw_exe, can_rs1_fw_mem, can_rs2_fw_mem, can_rs1_fw_wb, can_rs2_fw_wb;
    assign can_rs1_fw_exe = raw_ex_rs1 && (exe_is_load == 1'b0) && (id_out_valid == 1'b1); // 如果EXE阶段是load指令，则不能前递
    assign can_rs2_fw_exe = raw_ex_rs2 && (exe_is_load == 1'b0) && (id_out_valid == 1'b1);
    assign can_rs1_fw_mem = raw_mem_rs1&& (is_load == 1'b0 || mem_rvalid == 1) && (id_out_valid == 1'b1); // 如果MEM阶段是load指令，则不能前递
    assign can_rs2_fw_mem = raw_mem_rs2&& (is_load == 1'b0 || mem_rvalid == 1) && (id_out_valid == 1'b1);
    
    assign forwardA = can_rs1_fw_exe ? 2'b01 :
                      can_rs1_fw_mem ? 2'b10 : 2'b00;

    assign forwardB = can_rs2_fw_exe ? 2'b01 :
                      can_rs2_fw_mem ? 2'b10 : 2'b00;

    // 当mem_out_ready == 1的时候检测是否有冲突，只需要一拍(当mem_out_ready刚为1的时候，所有的检测都没有效果了，因为EXE阶段的指令已经进入了MEM阶段，但是MEM阶段接收数据需要一个周期，这期间可能会有冲突)
    // 这里的mem_out_ready是指mem模块的out_ready信号，表示mem模块的输出可以被下一个模块接收
    reg [1:0] mem_out_ready_d;
    always @(posedge clk) begin
        mem_out_ready_d <= {mem_out_ready_d[0], mem_out_ready};
    end
    wire raw_mem_ready_rs = (mem_out_ready == 1) && (mem_out_ready_d != 2'b11) && (exe_is_load == 1) && (raw_ex_rs1 || raw_ex_rs2);

    // exe/mem -> mem
    wire raw_ex_load_rs =   (exe_mem_is_load == 1) && 
                            ((id_rs1_ren == 1  && (mem_stage_wen == 1 && ((id_rs1 == mem_stage_rd)))) ||
                            (id_rs2_ren == 1  && (mem_stage_wen == 1 && ((id_rs2 == mem_stage_rd)))));
            
    // 只需要判断在exe级发生冲突且是load指令以及mem级发生冲突且是load指令但还没有取出数据的情况就行，只有这两种情况才需要stall
    assign stall_id =   (raw_ex_rs1 && exe_is_load) && (mem_out_ready == 0 || ex_out_valid) ||    // EXE本身只用在结果有效的时候不冲突就行，后面的exe->exe/mem和exe/mem->mem的冲突由raw_ex_load_rs和raw_mem_ready_rs进行判断
                        (raw_ex_rs2 && exe_is_load) && (mem_out_ready == 0 || ex_out_valid) || 
                        (raw_mem_rs1 && is_load && mem_rvalid == 1'b0) || 
                        (raw_mem_rs2 && is_load && mem_rvalid == 1'b0) || raw_ex_load_rs || raw_mem_ready_rs;

endmodule

// ===========================

// FILE 14: ./ysyx-workbench/npc/vsrc/cache/ysyx_24100006_Icache.v
// ===========================
// ============================================================
// Tiny Direct-Mapped I-Cache (area-optimized, CPU side uses AXI-like handshake)
// - CPU侧使用 arvalid/arready & rvalid/rready 握手
// - 数据行用寄存器直接存储（1 行 × 16B = 4×32bit）>= 4 指令
// - 直接映射：单 tag + valid
// - 直通区域：0x0f00_0000 ~ 0x0fff_ffff（单拍）
// - 回填：4 拍 AXI burst
// - 命中路径保留 1 拍等待（S_HIT_WAIT），便于与同步RAM等价时序；也可直接去掉以减1拍
// ============================================================

module ysyx_24100006_Icache #(
    parameter SRAM_BASE_ADDR = 32'h0f00_0000,
    parameter SRAM_SIZE      = 32'h00ff_ffff
)(
    input               clk,
    input               rst,
    input               fence_i_i,

    // ---------------- CPU <-> I$ (AXI-like read address/data channels) ----------------
    // AR channel
    input               cpu_arvalid_i,  // CPU 发起请求：addr 同拍有效
    output              cpu_arready_o,  // I$ 空闲且可接受请求时拉高
    input  [31:0]       cpu_araddr_i,   // 指令地址

    // R channel
    output              cpu_rvalid_o,   // I$ 返回数据有效（保持到与cpu_rready_i握手）
    input               cpu_rready_i,   // CPU 接受数据
    output [31:0]       cpu_rdata_o,    // 指令数据

    // ---------------- I$ <-> 外部AXI（与原版一致） ----------------
    output              axi_arvalid_o,
    input               axi_arready_i,
    output [31:0]       axi_araddr_o,
    output [7:0]        axi_arlen_o,

    input               axi_rvalid_i,
    output              axi_rready_o,
    input  [31:0]       axi_rdata_i,
    input               axi_rlast_i,

    output              icache_flush_done

`ifdef VERILATOR_SIM
    ,output reg         hit
`endif
);
    // ---------------------- Params / widths ----------------------
    localparam OFFSET_WIDTH   = 4;                  // 16B line
    localparam TAG_WIDTH      = 32 - OFFSET_WIDTH;  // 28 bits (addr[31:4])
    localparam WORDS_PER_LINE = 4;                  // 4 × 32b
    localparam WORD_SEL_W     = 2;

    // ---------------------- Bypass region ------------------------
    // 简化判断：高8位为 0x0f 即认定直通
    wire is_sram_addr_now = (cpu_araddr_i[31:24] == 8'h0f);

    // ---------------------- FSM states ---------------------------
    localparam S_IDLE      = 3'b000;
    localparam S_LOOKUP    = 3'b001;
    localparam S_MISS_AR   = 3'b010;
    localparam S_MISS_R    = 3'b011;
    // localparam S_HIT_WAIT  = 3'b100;  // 命中路径等待1拍
    localparam S_RESP      = 3'b100;  // 等待CPU取走数据（rvalid保持，直到rready握手）

    reg [2:0] state, state_n;

    // ---------------------- Request latches ----------------------
    reg [TAG_WIDTH-1:0]  req_tag;     // addr[31:4]
    reg [WORD_SEL_W-1:0] word_sel;    // addr[3:2]
    reg                  req_bypass;

    // ---------------------- Tag/valid （单行）--------------------
    reg [TAG_WIDTH-1:0]  tag_q;
    reg                  valid_q;

    // ---------------------- AXI address channel ------------------
    reg         arvalid_q;
    reg [31:0]  araddr_q;

    // ---------------------- Data path ----------------------------
    // 1行×4词（直接用reg存储）
    reg [31:0] line [0:WORDS_PER_LINE-1];

    // 命中组合数据（RESP 时直接用）
    wire [31:0] hit_word_comb = line[word_sel];

    // Miss/直通缓冲
    reg [31:0]  miss_or_bypass_data_q;
    // RESP 数据来源：1=命中（组合读取 line[]）；0=miss/直通缓冲
    reg         resp_src_is_hit_q;

    // 回填 burst 计数
    reg [1:0]   burst_cnt;

    // ---------------------- VERILATOR stats ----------------------
`ifdef VERILATOR_SIM
    reg cache_fill_start, cache_fill_end;
`endif

    // ---------------------- fence / flush ------------------------
    reg fence_d;
    always @(posedge clk) begin
        if (rst) fence_d <= 1'b0;
        else     fence_d <= fence_i_i;
    end
    wire fence_pulse = fence_i_i & ~fence_d;
    assign icache_flush_done = fence_pulse;

    // ---------------------- Handshake / I/O ----------------------
    // 仅在空闲且非fence时接受CPU请求
    assign cpu_arready_o = (state == S_IDLE) && ~fence_i_i;

    // R通道：在S_RESP保持rvalid直到CPU rready握手
    assign cpu_rvalid_o  = (state == S_RESP);
    assign cpu_rdata_o   = resp_src_is_hit_q ? hit_word_comb : miss_or_bypass_data_q;

    // 外部AXI（与原版一致）
    assign axi_arvalid_o = arvalid_q;
    assign axi_araddr_o  = araddr_q;
    assign axi_arlen_o   = req_bypass ? 8'd0 : 8'd3;  // 直通：单拍；回填：4拍
    assign axi_rready_o  = (state == S_MISS_R);

    // AXI R 完成条件
    wire r_done_bypass = req_bypass && axi_rvalid_i && axi_rready_o;                   // 单拍
    wire r_done_fill   = (~req_bypass) && axi_rvalid_i && axi_rready_o && axi_rlast_i; // 4拍
    wire r_done        = r_done_bypass | r_done_fill;

    // ---------------------- Sequential ---------------------------
    integer i;
    always @(posedge clk) begin
        if (rst) begin
            state                 <= S_IDLE;
            valid_q               <= 1'b0;
            tag_q                 <= {TAG_WIDTH{1'b0}};
            arvalid_q             <= 1'b0;
            araddr_q              <= 32'b0;
            miss_or_bypass_data_q <= 32'b0;
            resp_src_is_hit_q     <= 1'b0;
            burst_cnt             <= 2'b00;
            req_tag               <= {TAG_WIDTH{1'b0}};
            word_sel              <= {WORD_SEL_W{1'b0}};
            req_bypass            <= 1'b0;
            for (i=0; i<WORDS_PER_LINE; i=i+1) line[i] <= 32'b0;
`ifdef VERILATOR_SIM
            hit               <= 1'b0;
            cache_fill_start  <= 1'b0;
            cache_fill_end    <= 1'b0;
`endif
        end else begin
            // fence：1拍脉冲，清valid
            if (fence_pulse) begin
                valid_q <= 1'b0;
            end

            state <= state_n;

            case (state)
                // ---------------- IDLE ----------------
                S_IDLE: begin
`ifdef VERILATOR_SIM
                    hit <= 1'b0;
`endif
                    // CPU请求握手：arvalid & arready
                    if (cpu_arvalid_i && cpu_arready_o) begin
                        req_tag    <= cpu_araddr_i[31:4];  // 28-bit tag
                        word_sel   <= cpu_araddr_i[3:2];
                        req_bypass <= is_sram_addr_now;
                    end
                end

                // ---------------- LOOKUP ----------------
                S_LOOKUP: begin
                    if (req_bypass) begin
                        // 直通 -> miss路径（单拍R）
                        resp_src_is_hit_q <= 1'b0;
`ifdef VERILATOR_SIM
                        hit <= 1'b0;
                        cache_fill_start <= 1'b1;
`endif
                    end else if (valid_q && (tag_q == req_tag)) begin
                        // 命中：RESP 数据来源为组合读取
                        resp_src_is_hit_q <= 1'b1;
`ifdef VERILATOR_SIM
                        hit <= 1'b1;
`endif
                    end else begin
                        // 未命中：发起AXI读并回填
                        resp_src_is_hit_q <= 1'b0;
`ifdef VERILATOR_SIM
                        hit <= 1'b0;
                        cache_fill_start <= 1'b1;
`endif
                    end
                end

                // ---------------- MISS AR ----------------
                S_MISS_AR: begin
`ifdef VERILATOR_SIM
                    cache_fill_start <= 1'b0;
`endif
                    arvalid_q <= 1'b1;
                    araddr_q  <= req_bypass ? {req_tag, word_sel, 2'b00}  // 直通：字对齐
                                            : {req_tag, 4'b0000};        // 回填：行对齐
                    if (axi_arvalid_o && axi_arready_i) begin
                        arvalid_q <= 1'b0;
                        burst_cnt <= 2'b00;
                    end
                end

                // ---------------- MISS R ----------------
                S_MISS_R: begin
                    if (axi_rvalid_i && axi_rready_o) begin
                        if (req_bypass) begin
                            // 直通：单拍进缓冲
                            miss_or_bypass_data_q <= axi_rdata_i;
                        end else begin
                            // 回填：逐拍写入行寄存器；命中词同时放入缓冲
                            line[burst_cnt] <= axi_rdata_i;
                            if (burst_cnt == word_sel)
                                miss_or_bypass_data_q <= axi_rdata_i;
                            burst_cnt <= burst_cnt + 2'd1;
                        end

                        if (r_done) begin
                            if (!req_bypass) begin
                                tag_q   <= req_tag;
                                valid_q <= 1'b1;
                            end
`ifdef VERILATOR_SIM
                            if (!req_bypass) cache_fill_end <= 1'b1;
`endif
                        end
                    end
                end

                // ---------------- HIT WAIT ----------------
                // S_HIT_WAIT: begin
                //     // 保留一拍等待（可直接省略此状态以减1拍）
                // end

                // ---------------- RESP ----------------
                S_RESP: begin
`ifdef VERILATOR_SIM
                    cache_fill_end <= 1'b0;
`endif
                    // 在此状态保持 cpu_rvalid_o=1，直到 CPU 以 rready 握手取走
                end

                default: ;
            endcase
        end
    end

    // ---------------------- Next-state logic ---------------------
    wire will_hit = (~req_bypass) && valid_q && (tag_q == req_tag);

    always @* begin
        state_n = state;
        case (state)
            S_IDLE: begin
                if (cpu_arvalid_i && cpu_arready_o) state_n = S_LOOKUP;
            end
            S_LOOKUP: begin
                if (req_bypass) begin
                    state_n = S_MISS_AR;
                end else if (will_hit) begin
                    state_n = S_RESP;  // 命中：进入等待1拍（可直接改到S_RESP）
                end else begin
                    state_n = S_MISS_AR;   // 未命中：走AXI
                end
            end
            S_MISS_AR: begin
                if (axi_arvalid_o && axi_arready_i) state_n = S_MISS_R;
            end
            S_MISS_R: begin
                if (r_done) state_n = S_RESP; // 直通：首拍即完成；回填：看RLAST
            end
            // S_HIT_WAIT: begin
            //     state_n = S_RESP;
            // end
            S_RESP: begin
                // 仅当 CPU rready 与 rvalid 握手后回到空闲
                if (cpu_rvalid_o && cpu_rready_i) state_n = S_IDLE;
            end
            default: state_n = S_IDLE;
        endcase
    end

// -------------------- TAGS:Performance Counters -----------------
`ifndef __ICARUS__
    import "DPI-C" function void cache_miss_time(
        input bit start_fill,
        input bit end_fill
    );
    always @(*) cache_miss_time(cache_fill_start, cache_fill_end);
`endif

endmodule

// ===========================

// FILE 15: ./ysyx-workbench/npc/vsrc/MEM/ysyx_24100006_clint.v
// ===========================
`ifndef __ICARUS__
import "DPI-C" function void skip();
`endif
module ysyx_24100006_clint (
    input               clk,
    input               reset,

    // AXI-Lite 接口
    input  [31:0]       axi_araddr,
    input               axi_arvalid,
    output              axi_rvalid,
    output reg [31:0]   axi_rdata
);

`ifndef NPC
    parameter BASE_ADDR = 32'h0200_0000;  // TIMER 基地址
`else
    parameter BASE_ADDR = 32'ha000_0048;  // NPC 仿真基地址
`endif

    // 状态定义
    localparam S_WAIT_ARV = 1'b0;  // 等待地址有效
    localparam S_WAIT_RR  = 1'b1;  // 等待读取就绪
    
    reg         state;

    // mtime 计数器
    reg [31:0] mtime_lo, mtime_hi;
    reg carry;
    always @(posedge clk) begin
        if (reset) begin 
            mtime_lo<=0; 
            mtime_hi<=0; 
            carry   <=0;
        end
        else begin
            {carry, mtime_lo} <= mtime_lo + 32'd1;
            if (carry) begin
                mtime_hi <= mtime_hi + 32'd1;
            end
        end
    end

    // AXI 控制信号默认值
    assign axi_rvalid  = (state == S_WAIT_RR);

    // 状态机与数据处理
    always @(posedge clk) begin
        if (reset) begin
            state       <= S_WAIT_ARV;
            axi_rdata   <= 32'b0;
        end else begin
            case (state)
                S_WAIT_ARV: begin
                    if (axi_arvalid) begin
                        state       <= S_WAIT_RR;
                        
                        `ifndef __ICARUS__
                            skip();
                        `endif
                        axi_rdata   <= (state == S_WAIT_ARV && axi_araddr[2] == BASE_ADDR[2]) 
                                    ? mtime_lo 
                                    : mtime_hi;
                    end
                end
                
                S_WAIT_RR: begin
                    state       <= S_WAIT_ARV;
                end
            endcase
        end
    end

endmodule
// ===========================

// FILE 16: ./ysyx-workbench/npc/vsrc/EX/ysyx_24100006_alu.v
// ===========================
module ysyx_24100006_alu (
    input  [31:0] rs_data,
    input  [31:0] rt_data,
    input  [3:0]  aluop,
    output [31:0] result
    // ,output        of
    // ,output        cf
    ,output        zf
);
    // opcode
    localparam OP_ADD  = 4'b0000;
    localparam OP_SUB  = 4'b0001;
    localparam OP_OR   = 4'b0010;
    localparam OP_SLT  = 4'b0011;
    localparam OP_SRL  = 4'b0100;
    localparam OP_SRA  = 4'b0101;
    localparam OP_SLL  = 4'b0110;
    localparam OP_AND  = 4'b0111;
    localparam OP_XOR  = 4'b1000;
    localparam OP_SLTU = 4'b1001;

    // 加/减共用加法器；slt/sltu 也要减
    wire is_sub = (aluop == OP_SUB) | (aluop == OP_SLT) | (aluop == OP_SLTU);
    wire [31:0] b_sel = rt_data ^ {32{is_sub}};
    wire [31:0] add_sub_result;
    wire        cf_raw;
    assign {cf_raw, add_sub_result} = rs_data + b_sel + {31'b0, is_sub};

    // 溢出只对 add/sub 有意义
    wire of_raw = (~(rs_data[31] ^ b_sel[31])) & (rs_data[31] ^ add_sub_result[31]);

    // 逻辑运算（OR 由 XOR^AND 得到，避免再一棵 OR 树）
    wire [31:0] and_result = rs_data & rt_data;
    wire [31:0] xor_result = rs_data ^ rt_data;
    wire [31:0] or_result  = xor_result ^ and_result;

    // 单套右移桶形 + 位反转实现 SLL
    wire [4:0]  shamt = rt_data[4:0];
    wire        is_sll = (aluop == OP_SLL);
    wire        is_sra = (aluop == OP_SRA);

    wire [31:0] sh_in = is_sll ? bitrev32(rs_data) : rs_data;
    wire        fill  = is_sra ? rs_data[31]       : 1'b0;
    wire [31:0] sh_r  = rshift_var(sh_in, shamt, fill);

    wire [31:0] srl_sra_result = sh_r;
    wire [31:0] sll_result     = bitrev32(sh_r);

    // 比较 1bit 后再扩展
    wire sltu_bit = ~cf_raw;
    wire a31 = rs_data[31], b31 = rt_data[31];
    wire slt_bit = (a31 & ~b31) | ( ~(a31 ^ b31) & add_sub_result[31] );

    // 结果选择
    reg [31:0] res;
    always @* begin
        case (aluop)
            OP_ADD, OP_SUB: res = add_sub_result;
            OP_OR:          res = or_result;
            OP_SLT:         res = {31'b0, slt_bit};
            OP_SRL:         res = srl_sra_result;
            OP_SRA:         res = srl_sra_result;
            OP_SLL:         res = sll_result;
            OP_AND:         res = and_result;
            OP_XOR:         res = xor_result;
            OP_SLTU:        res = {31'b0, sltu_bit};
            default:        res = 32'b0;
        endcase
    end

    assign result = res;
    assign zf     = ~|res;

    // cf/of 只在 add/sub 导出，其他置 0，利于上游剪枝
    wire is_addsub = (aluop == OP_ADD) | (aluop == OP_SUB);
    // assign cf = is_addsub ? cf_raw : 1'b0;
    // assign of = is_addsub ? of_raw : 1'b0;

    // ===== 工具函数（Verilog-2001 兼容） =====
    function [31:0] rshift_var;
        input [31:0] x;
        input [4:0]  s;
        input        fill;
        reg [31:0] t;
        begin
            t = s[0] ? {fill,       x[31:1]}  : x;
            t = s[1] ? {{2{fill}},  t[31:2]}  : t;
            t = s[2] ? {{4{fill}},  t[31:4]}  : t;
            t = s[3] ? {{8{fill}},  t[31:8]}  : t;
            t = s[4] ? {{16{fill}}, t[31:16]} : t;
            rshift_var = t;
        end
    endfunction

    function [31:0] bitrev32;
        input [31:0] x;
        integer i;
        begin
            for (i = 0; i < 32; i = i + 1)
                bitrev32[i] = x[31 - i];
        end
    endfunction
endmodule

// ===========================

// FILE 17: ./ysyx-workbench/npc/vsrc/ysyx_24100006_EXEU.v
// ===========================
/**
    执行模块
*/
module ysyx_24100006_exeu(
	input 			clk,
    input 			reset,

`ifdef VERILATOR_SIM
	// 调试使用
	input [31:0] 	pc_E,
	output [31:0] 	pc_M,
`endif

	// 是否为ebreak指令
	input           is_break_i,
    output    		is_break_o,
	// from icache
	input 			icache_flush_done,	// icache是否刷新完毕

	// from IDU
	// control signal from IDU
	input 			is_fence_i,	// 是否刷新icache

	input 			irq_E,
    input [3:0] 	aluop,
    input [2:0] 	Jump,
	input 			Gpr_Write_E,
	input 			Csr_Write_E,
	input [3:0]     Gpr_Write_Addr_E,
    input [11:0]    Csr_Write_Addr_E,
	input [1:0] 	Gpr_Write_RD_E,
	input [1:0]		sram_read_write_E,

	// 握手机制使用
	input           exe_out_valid,   // ID_EXE -> IDU 	(上游 valid)
    output          exe_out_ready,   // EXEU -> ID_EXE  (上游 ready)
    output          exe_in_valid,    // EXEU -> EXE_MEM (下游 valid)
    input           exe_in_ready,    // EXE_MEM -> IDU 	(下游 ready)

	// to IFU
	output [31:0] 	npc_E,
	output 			redirect_valid,
	
	// to MEMU
	output [31:0] 	alu_result,

	// control signal
	output 			irq_M,
	output 			Gpr_Write_M,
	output 			Csr_Write_M,
	output [3:0]    Gpr_Write_Addr_M,
    output [11:0]   Csr_Write_Addr_M,
	output [1:0] 	Gpr_Write_RD_M,
	output [1:0] 	sram_read_write_M

	// 面积优化
	,input 	[31:0]  pc_j_m_e_n_E        // NO_JUMP/MRET/ECALL三种跳转的地址
    ,input 	[31:0]  alu_a_data_E
    ,input 	[31:0]  alu_b_data_E
    ,input 	[31:0]  pc_add_imm_E

	,input 	[31:0]  wdata_gpr_E
	,input 	[31:0]  wdata_csr_E
    ,output [31:0]  wdata_gpr_M
    ,output [31:0]  wdata_csr_M
    
	,input  [2:0]   Mem_Mask_E
    ,output [2:0]   Mem_Mask_M

	,input  [31:0]	pc_add_4

	// 前递单元设计
	,output 		exe_is_load
	,output	[31:0]	exe_fw_data
);

	// 组合握手：当需要等待 icache 刷新时，对上游施加反压、对下游不发 valid
	// 握手机制
	// 下游 valid：上游 valid 且本级不 stall
	assign exe_in_valid  = exe_out_valid;
	// 上游 ready：下游 ready 且本级不 stall
    assign exe_out_ready = exe_in_ready;

	// 计算
    // wire [31:0] alu_a_data,alu_b_data;
	wire [31:0] alu_result_temp;
	wire of,cf,zf;


	// 运算器
	ysyx_24100006_alu alu(
		.rs_data(alu_a_data_E),
		.aluop(aluop),
		.rt_data(alu_b_data_E),
		.result(alu_result_temp)
		// ,.of(of),
		// .cf(cf),
		,.zf(zf)
	);

    // 计算npc
	wire [31:0] npc_temp;
	// 约定：alu_result_temp[0] = 本条指令需要的<比较结果位>
	// 对于 {BLT,BLTU} 取 cmp；{BGE,BGEU} 取 ~cmp（通过与 Jump[0] 异或实现）

	wire j2 = Jump[2];
	wire j1 = Jump[1];
	wire j0 = Jump[0];

	wire cmp = alu_result_temp[0];  // 来自 ALU 的比较结果位
	wire cond_eq = zf  ^ j0;        // BEQ(010): j0=0 -> zf； BNE(011): j0=1 -> ~zf
	wire cond_lt = cmp ^ j0;        // BLT/BLTU(1x0): j0=0 -> cmp；BGE/BGEU(1x1): j0=1 -> ~cmp

	// 当 j2=0：{000,001,010,011}
	//   - j1=0 -> {000,001}：直接输出 j0（NJUMP=0, JAL=1）
	//   - j1=1 -> {010,011}：用 cond_eq
	// 当 j2=1：{100,101,110,111}：用 cond_lt
	wire br_taken = j2 ? cond_lt
					: (j1 ? cond_eq : j0);

	assign npc_temp = br_taken ? pc_add_imm_E : pc_j_m_e_n_E;

	// 当是跳转指令且目标地址与pc+4不同时，才重定向
	// 若是 jal 指令不需要要重定向，因为前面已经计算好了 npc
	assign redirect_valid = (exe_out_valid == 1 && npc_temp[28:2] != pc_add_4[28:2]) ? 1'b1 : 1'b0;

	// 直接透传到 EXE_MEM（它会寄存）
`ifdef VERILATOR_SIM
	// 调试使用
    assign pc_M            		= pc_E;
`endif

	assign alu_result			= alu_result_temp;

    assign irq_M           		= irq_E;
    assign Gpr_Write_M     		= Gpr_Write_E;
    assign Csr_Write_M     		= Csr_Write_E;
    assign Gpr_Write_RD_M  		= Gpr_Write_RD_E;
	assign sram_read_write_M	= sram_read_write_E;
	
	assign Gpr_Write_Addr_M		= Gpr_Write_Addr_E;
	assign Csr_Write_Addr_M		= Csr_Write_Addr_E;

	assign npc_E				= npc_temp;
	assign is_break_o			= is_break_i;

	// 面积优化
	// 如果真实写回寄存器的值时读内存的值，那么后续在MEMU会进行替换的
	assign wdata_gpr_M			= (Gpr_Write_RD_M[0] == 1'b1) ? alu_result_temp : wdata_gpr_E;
	assign wdata_csr_M			= wdata_csr_E;

	assign Mem_Mask_M			= Mem_Mask_E;

	// 前递单元设计
	assign exe_is_load 			= 	(sram_read_write_M[0] == 1'b1) ? 1'b1 : 1'b0;
	assign exe_fw_data 			= 	wdata_gpr_M;

endmodule

// ===========================

