/**
    AXI-Lite接口的UART功能：本质上就是使用MEM那一套，只是不能读，只能使用$write进行写操作
*/
// TAG:如果rresp返回的是01,则表示读了不可读的部分
module ysyx_24100006_uart #(
    parameter BASE_ADDR = 32'ha000_03f8     // UART基地址,然后可以向后写8个字节
)(
    input               clk,
    input               reset,

    // axi 写入和读取地址
    input [31:0]        axi_araddr,
    input [31:0]        axi_awaddr,
    // axi 写入数据和写入使用的掩码
    input [31:0]        axi_wdata,
    input [3:0]         axi_wstrb,

    // axi控制信号
    // read data addr
    input               axi_arvalid,
    output  reg         axi_arready,
    // read data
    input               axi_rready,
    output  reg         axi_rvalid,
    // write data addr
	input               axi_awvalid,
	output  reg         axi_awready,
	// write data
	input               axi_wvalid,
	output  reg         axi_wready,
	// response
    input               axi_bready,
	output  reg         axi_bvalid,
    output  reg [1:0]   axi_bresp,

    // axi 读取的回应
    output  reg [1:0]   axi_rresp,
    output  reg [31:0]  axi_rdata
    
);
    
    parameter   S_IDLE          = 0, 
                S_READ_ADDR     = 1, 
                S_READ_DATA     = 2, 
                S_WRITE_ADDR    = 3, 
                S_WRITE_DATA    = 4, 
                S_WRITE_RESP    = 5;


    reg [3:0] state;
    
    always @(posedge clk) begin
        if(reset) begin
            state           <= S_IDLE;
            axi_arready     <= 1'b0;
            axi_awready     <= 1'b0;
            axi_wready      <= 1'b0;
            axi_rvalid      <= 1'b0;
            axi_bvalid      <= 1'b0;
            axi_rdata       <= 32'h00000000;
        end else begin
            case(state)
                S_IDLE: begin
                    if(axi_arvalid == 1'b1) begin
                        axi_arready     <= 1'b1;
                        state           <= S_READ_ADDR;
                    end else if(axi_awvalid == 1'b1 && axi_wvalid == 1'b1) begin
                        axi_awready     <= 1'b1;
                        axi_wready      <= 1'b1;
                        state           <= S_WRITE_ADDR;
                    end
                end
                S_READ_ADDR: begin
                    axi_arready         <= 1'b0;
                    if(axi_arvalid == 1'b1 && axi_arready == 1'b1) begin
                        axi_rvalid      <= 1'b1;
                        $display("Error: You cannot read from UART");
                        axi_rdata       <= 32'h0;
                        axi_rresp       <= 2'b01;       // 读回应为01表示读了不可读的区域
                        state           <= S_READ_DATA;
                    end
                end
                S_READ_DATA: begin
                    if(axi_rready == 1'b1 && axi_rvalid == 1'b1) begin
                        axi_rvalid      <= 1'b0;
                        state           <= S_IDLE;
                    end
                end
                // 写入地址握手和数据握手放在一起
                S_WRITE_ADDR: begin
                    axi_awready         <= 1'b0;
                    axi_wready          <= 1'b0;
                    if(axi_awvalid == 1'b1 && axi_awready == 1'b1 && axi_wvalid == 1'b1 && axi_wready == 1'b1) begin
                        // 写入数据
                        $write("%c",axi_wdata[7:0]);
                        axi_bresp       <= 2'b00;
                        axi_bvalid      <= 1'b1;
                        state           <= S_WRITE_RESP;
                    end
                end
                S_WRITE_RESP: begin
                    if(axi_bready == 1'b1 && axi_bvalid == 1'b1)begin
                        axi_bvalid      <= 1'b0;
                        state           <= S_IDLE;
                    end
                end

                default: state          <= S_IDLE;
            endcase
        end
    end


endmodule

