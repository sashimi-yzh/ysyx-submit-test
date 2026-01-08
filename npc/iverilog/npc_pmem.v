`timescale 1ns/1ps

module npc_pmem #(
	parameter ADDR_WIDTH = 32,
	parameter DATA_WIDTH = 32,
	parameter PMEM_SIZE = 32'h08000000,  
	
	// 特殊地址
	parameter SERIAL_PORT = 32'ha00003f8,  // 串口地址
	parameter PMEM_BASE   = 32'h80000000,   // 程序内存基址

	// 状态常量作为参数
	parameter ST_IDLE  = 2'b00,
	parameter ST_READ  = 2'b01,  
	parameter ST_WRITE = 2'b10
)(
	input wire clk,
	input wire rst,
	
	// ========== AXI4 写地址通道 ==========
	output wire               awready,
	input  wire               awvalid,
	input  wire [ADDR_WIDTH-1:0] awaddr,
	input  wire [3:0]         awid,
	input  wire [7:0]         awlen,
	input  wire [2:0]         awsize,
	input  wire [1:0]         awburst,
	
	// ========== AXI4 写数据通道 ==========
	output wire                wready,
	input  wire               wvalid,
	input  wire [DATA_WIDTH-1:0] wdata,
	input  wire [3:0]         wstrb,
	input  wire               wlast,
	
	// ========== AXI4 写响应通道 ==========
	input  wire               bready,
	output wire                bvalid,
	output wire [1:0]          bresp,
	output wire [3:0]          bid,
	
	// ========== AXI4 读地址通道 ==========
	output wire                arready,
	input  wire               arvalid,
	input  wire [ADDR_WIDTH-1:0] araddr,
	input  wire [3:0]         arid,
	input  wire [7:0]         arlen,
	input  wire [2:0]         arsize,
	input  wire [1:0]         arburst,
	
	// ========== AXI4 读数据通道 ==========
	input  wire               rready,
	output wire                rvalid,
	output wire [1:0]          rresp,
	output wire [DATA_WIDTH-1:0] rdata,
	output wire                rlast,
	output wire [3:0]          rid
);
	
	// ==================== 内存定义 ====================
	reg [31:0] pmem [0:PMEM_SIZE-1] ;  // 字节数组
	reg [31:0] flash [0:3] ;  // 字节数组
	// ==================== 状态寄存器 ====================  
	reg [1:0]  state;
	reg [1:0]  wen;
	reg [3:0]  ren;
	reg [31:0]  addr;
	reg [31:0]  data;
	wire [31:0] burst_addr;//突发传输地址
	wire [31:0] full_mask;  // 掩码
	// ==================== 初始化 ====================
	integer i;
	integer j;  
	initial begin
		// 初始化内存为0
		for (i = 0; i < PMEM_SIZE; i = i + 1) begin
			pmem[i] = 32'b0;
		end
		flash[0] = 32'h80000137;
		flash[1] = 32'h00010067;
		$display("physical memory area [0X%08X,0X%08X].", PMEM_BASE, PMEM_BASE + PMEM_SIZE -1);

		// 加载程序
		$readmemh("./build/obj_dir/program.hex", pmem);

		for (j = 0; j < PMEM_SIZE; j = j +  1) begin
			if (pmem[j] != 8'h00) begin
		 		pmem[j] = {pmem[j][7:0], pmem[j][15:8], pmem[j][23:16], pmem[j][31:24]};
		     	//$display("  pmem[0x%08x] = 0x%08x", PMEM_BASE + 4*j, pmem[j]);
		    end
		end

		$display("[iverilog_PMEM]Memory initialized from program.hex");
		state = ST_IDLE;
		wen = 0;
		ren = 0;

	end

	//掩码
	assign full_mask = {{8{wstrb[3]}}, {8{wstrb[2]}}, {8{wstrb[1]}}, {8{wstrb[0]}}};
   
	assign burst_addr = ( (addr >> 2) << 2) + ((ren - 2) << 1 ) ;
	assign arready = 1'b1;
	assign rdata = (state == ST_READ) ? 
					( (araddr[31:28] == 4'h3) ? flash[burst_addr[2]] : pmem[( burst_addr) >> 2] ):
					//pmem[( burst_addr) >> 2] :
					32'h0;
	assign rvalid = (ren[0] == 1'b0) && (state == ST_READ);
	assign rlast = (ren == ((arlen + 1) << 1));
	assign rresp = 2'b00;
	assign rid = 4'h0;

	assign wready = 1'b1;
	assign awready = 1'b1;
	assign bvalid = (wen == 2'b10);
	assign bresp = 2'b00;
	assign bid = 4'h0;

	// ==================== 时钟边沿处理 ====================
	always @(posedge clk) begin
			//$display("[PMEM] state=%d",  state);    
		if (rst) begin// 复位所有状态
			state <= ST_IDLE;
		end else begin

			//$display("[PMEM] state=%d",  state);        

			case (state)
				ST_IDLE: begin
					if (arvalid) state <= ST_READ;
					else if (awvalid && wvalid) state <= ST_WRITE;
					else state <= ST_IDLE;
				end
				ST_READ: begin
					if (rvalid && rlast) state <= ST_IDLE;
					else state <= ST_READ;
				end
				ST_WRITE: begin
					if (bvalid) state <= ST_IDLE;
					else state <= ST_WRITE;
				end
			endcase

			/*保存地址*/
			if(arvalid) begin
				//if(araddr[31:28] == 4'h3) begin
				// 	addr = araddr;
				// end else begin
					addr <= {4'b0000, araddr[27:0]};
				//end
			end else if (awvalid && wvalid) begin
				if (awaddr == SERIAL_PORT) begin//串口的输出功能
					addr <= awaddr;
					data <= wdata;
				end else begin
					addr <= {4'b0000, awaddr[27:0]};
					data <= wdata;
				end
			end
			
			if( ren == ( (arlen + 1) << 1) ) begin
				 ren <= 2'b0;
			end else if ((state == ST_READ) || arvalid) begin
				ren <= ren + 1'b1;
			end


			if (wen == 2'b10) begin
				if (addr == SERIAL_PORT) begin//串口的输出功能
				//printf("[%x]=%x wdata=%c %d\n", npc.dnpc, top->io_inst, wdata & 0xFF, wdata & 0xFF);
				$write("%c", data[7:0]);
				$fflush();
				end else begin
					pmem[( addr) >> 2] <= (pmem[( addr) >> 2] & ~full_mask) |(data & full_mask);
				end
				wen <= 2'b00;
			end else if( (state == ST_WRITE) || (awvalid && wvalid)) begin
				wen <= wen + 1'b1;
			end
		end
	end    


endmodule
