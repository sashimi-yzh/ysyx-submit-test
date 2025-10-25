

module ysyx_25040129_ICACHE #(
	parameter BLOCK_SIZE_WORD_DIG = 2,//2^BLOCK_SIZE_DIG = 4, // block size = 4B //最多开到3
	parameter BLOCK_NUM_DIG = 1//2^BLOCK_NUM_DIG = 16, // block number = 16
)(
	//目前16指令缓存参数最佳为1 3
	//8指令缓存参数最佳为2 1
	input clk,
	input rst,
	//---------------来自IFU的AXI-Lite信号---------------
	//---------------读地址---------------
	input [31:0] ifu_araddr,
	input ifu_arvalid,
	output ifu_arready,
	//---------------读数据---------------
	output [31:0] ifu_rdata,
	output [1:0] ifu_rresp,
	output ifu_rvalid,
	input ifu_rready,
	//--------------缓存未命中，向外界转发的AXI-Lite信号---------------
	//---------------读地址---------------
	output [31:0] out_araddr,
	output out_arvalid,
	input out_arready,
	output [7:0] out_arlen, // 突发传输大小
	output [1:0] out_arburst, 
	//---------------读数据---------------
	input [31:0] out_rdata,
	/* verilator lint_off UNUSEDSIGNAL */
	input [1:0] out_rresp,
	/* verilator lint_on UNUSEDSIGNAL */
	input out_rvalid,
	output out_rready,
	input out_rlast,
	//---------------fence.i冲刷---------------
	input fence_i
);	
	localparam IDLE = 2'b00;
	localparam WAIT_IFU_READY = 2'b01;
	localparam WAIT_OUT_READY = 2'b10;
	localparam WAIT_OUT_REQ = 2'b11;
	reg [31:0] ifu_rdata_latch;
	localparam BLOCK_SIZE_WORD = 1 << BLOCK_SIZE_WORD_DIG; 
	assign out_arlen = BLOCK_SIZE_WORD - 1; 
	assign out_arburst = 2'b01; 
	localparam BLOCK_SIZE_DIG = BLOCK_SIZE_WORD_DIG + 2;
	// localparam BLOCK_SIZE = 1 << (BLOCK_SIZE_DIG);
	localparam BLOCK_NUM = 1 << (BLOCK_NUM_DIG); 
	// verilator lint_off UNUSED
	reg [31:0] ifu_araddr_latch;
	// verilator lint_on UNUSED
	reg [31:0] cache_data[BLOCK_NUM-1:0][BLOCK_SIZE_WORD-1:0]; 
	reg [BLOCK_NUM-1:0]cache_valid;
	reg [31:BLOCK_SIZE_DIG+BLOCK_NUM_DIG] cache_tag[BLOCK_NUM-1:0];
	reg [1:0] state;
	reg [BLOCK_SIZE_WORD_DIG-1:0] burst_count;
	//--------------------------------------------------------------------------------
	wire [BLOCK_NUM_DIG-1:0] index;
	wire [BLOCK_NUM_DIG-1:0] p_index;
	wire [BLOCK_SIZE_WORD_DIG-1:0] offset;
	wire [BLOCK_SIZE_WORD_DIG-1:0] p_offset;
	wire [31-BLOCK_SIZE_DIG-BLOCK_NUM_DIG:0] tag;
	wire [31-BLOCK_SIZE_DIG-BLOCK_NUM_DIG:0] p_tag;
	//--------------------------------------------------------------------------------
	assign p_index = ifu_araddr[BLOCK_SIZE_DIG + BLOCK_NUM_DIG-1:BLOCK_SIZE_DIG];
	assign p_offset = ifu_araddr[BLOCK_SIZE_WORD_DIG+1:2];
	assign p_tag = ifu_araddr[31:BLOCK_SIZE_DIG + BLOCK_NUM_DIG];
	assign index = ifu_araddr_latch[BLOCK_SIZE_DIG + BLOCK_NUM_DIG-1:BLOCK_SIZE_DIG];
	assign offset = ifu_araddr_latch[BLOCK_SIZE_WORD_DIG+1:2];
	assign tag = ifu_araddr_latch[31:BLOCK_SIZE_DIG + BLOCK_NUM_DIG];
	//--------------------------------------------------------------------------------
	assign ifu_arready = (state == IDLE) && !fence_i;
	// 还是采用直接映射模式，支持更大块大小，并使用突发传输减少缺失代价
	//31--------block_size_dig+block_num_dig-1--------------block_size_dig-1--------------0
	//---tag--------------------------------------index-----------------------offset------

	`ifdef ysyx_25040129_DEBUG
	always @(posedge clk) begin
		icache_count_inc({6'b0,state},ifu_arvalid, cache_valid[p_index] && cache_tag[p_index] == p_tag);
		if(out_rresp != `ysyx_25040129_OKAY)$error("ICACHE: out_rresp != OKAY, resp = %b", out_rresp);
	end
	`endif
	reg fence_i_latch;
	always @(posedge clk) begin
		if(rst)begin 
			state <= IDLE;
			ifu_araddr_latch <= 32'b0;
			cache_valid <= {BLOCK_NUM{1'b0}};
			fence_i_latch <= 1'b0;
		end
		else begin
			case (state)
				IDLE:begin
					fence_i_latch <= 1'b0;
					if((fence_i||fence_i_latch)  && (|cache_valid != 1'b0))cache_valid <= {BLOCK_NUM{1'b0}}; 
					else begin
					if(ifu_arvalid) begin
						ifu_araddr_latch <= ifu_araddr;
						if(cache_valid[p_index] && cache_tag[p_index] == p_tag) begin
							ifu_rdata_latch <= cache_data[p_index][p_offset];
							if(ifu_rready) state <= IDLE;
							else state <= WAIT_IFU_READY; // 命中，直接返回数据
						end else begin
							state <= WAIT_OUT_READY; // 未命中，准备向外界请求数据
							burst_count <= 0; 
						end
					end
					end
				end 
				WAIT_IFU_READY:begin
					if(fence_i)fence_i_latch <= 1'b1;
					if(ifu_rready) begin
						state <= IDLE;
					end
				end
				WAIT_OUT_READY:begin
					if(fence_i)fence_i_latch <= 1'b1;
					if(out_arready) 
						state <= WAIT_OUT_REQ;
				end
				WAIT_OUT_REQ:begin
					if(fence_i)fence_i_latch <= 1'b1;
					if(out_rvalid) begin
						cache_data[index][burst_count] <= out_rdata;
						burst_count <= burst_count + 1;
						if(burst_count == offset)begin
							ifu_rdata_latch <= out_rdata;
						end
						if(out_rlast) begin
							cache_tag[index] <= tag;
							cache_valid[index] <= 1'b1; //标记该cache块有效
							state <= WAIT_IFU_READY;
						end
					end
				end
				default: state <= IDLE; 
			endcase
		end
	end
	assign out_araddr = {ifu_araddr_latch[31:BLOCK_SIZE_DIG], {BLOCK_SIZE_DIG{1'b0}}};
	assign out_arvalid = (state == WAIT_OUT_READY);
	assign out_rready = (state == WAIT_OUT_REQ);
	assign ifu_rresp = `ysyx_25040129_OKAY;
	assign ifu_rdata = (state == IDLE && ifu_arvalid && cache_valid[p_index] && cache_tag[p_index] == p_tag)?
	                   cache_data[p_index][p_offset] : ifu_rdata_latch;
	assign ifu_rvalid = (state == WAIT_IFU_READY) || (state == IDLE && ifu_arvalid && cache_valid[p_index] && cache_tag[p_index] == p_tag);
	// 还是采用直接映射模式，支持更大块大小，并使用突发传输减少缺失代价
	//31--------block_size_dig+block_num_dig-1--------------block_size_dig-1--------------0
	//---tag--------------------------------------index-----------------------offset------
	//icache的每个块都需要有一个valid位,id位目前直接对addr取模得到
	//tag位目前表示为addr/blocksize(这是地址addr对应的tag位)
	//对于内存地址为addr的数据块, 它将被读入编号为(addr / blocksize) % blocknum的cache块.
	//如何保证能分辨不同addr，
	//IFU 拿到一个addr，先index = (addr / blocksize) % blocknum 找到对应的cache块
	//随后，判断两个条件：
	//1. cache_valid[index] == 1'b1, 表示该cache块有效
	//2. 从addr中提取tag = addr[31:log2(blocksize)+log2(blocknum)]
	//   判断cache_data[index][31:log2(blocksize)+log2(blocknum)] == tag
	//   这两个条件都满足，表示cache命中
	//   否则，cache未命中，需要向外界请求数据 
endmodule
