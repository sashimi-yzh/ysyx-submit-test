`timescale 1ns/1ns

module SRAM(
    input             clk,
    input             rst, 
    
    input             sram_arvalid,
    output reg        sram_arready,
    input      [31:0] sram_araddr,
    output reg [31:0] sram_rdata,
    output reg        sram_rvalid,
    input             sram_rready,
    output reg [1:0]  sram_rresp,

    // input      [31:0] lsu_sram_araddr,
    // input             lsu_sram_rvalid,
    // output reg        sram_lsu_rready,
    // output reg [31:0] sram_lsu_rdata,

    input      [31:0] sram_awaddr,
    input             sram_awvalid,
    output reg        sram_awready,
    input      [31:0] sram_wdata,
    input      [3:0]  sram_wstrb,
    input             sram_wvalid,
    output reg        sram_wready,
    output reg [1:0]  sram_bresp,
    output reg        sram_bvalid,
    input             sram_bready

    // input             lsu_sram_wvalid,
    // input      [31:0] lsu_sram_awaddr,
    // input      [31:0] lsu_sram_wdata,
    // input      [7:0]  lsu_sram_wstrb,
    // output reg        sram_lsu_wready
);
    import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
    import "DPI-C" function void pmem_write(input int unsigned waddr, input int unsigned wdata, input int len);

    parameter OKAY = 2'b0;
    parameter MIN_DELAY = 1;
    parameter MAX_DELAY = 4;

    reg [31:0] read_addr;
    reg [31:0] LFSR;
    reg        read_pending;
    //读通道
    always @(posedge clk) begin
        if(rst) begin
            sram_arready <= 1;
            sram_rvalid  <= 0;
            sram_rdata   <= 32'h0;
            sram_rresp   <= OKAY;
            read_pending <= 0;
            LFSR         <= MIN_DELAY;
        end
        else begin
            if(sram_arvalid && sram_arready) begin
                read_addr    <= sram_araddr;
                read_pending <= 1;
                sram_arready <= 0;
                // LFSR         <= $urandom_range(MIN_DELAY, MAX_DELAY);
                LFSR         <= MIN_DELAY;
            end
            if(read_pending) begin
                if(LFSR > 0) begin
                    LFSR <= LFSR - 1;
                end
                else begin
                    sram_rdata  <= pmem_read(read_addr, 4);
                    sram_rvalid <= 1;
                    sram_rresp  <= OKAY;
                end
            end
            if(sram_rvalid && sram_rready) begin
                sram_rvalid  <= 0;
                read_pending <= 0;
                sram_arready <= 1;
            end
        end
    end
    
    reg [31:0] write_addr;
    reg        write_addr_valid;
    reg [31:0] write_data;
    reg [3:0]  write_strb;
    reg        write_data_valid;
    //写通道
    always @(posedge clk) begin
        if(rst) begin
            sram_awready <= 1;
            sram_wready  <= 1;
            sram_bvalid  <= 0;
            sram_bresp   <= OKAY;
            write_addr_valid <= 0;
            write_data_valid <= 0;
        end
        else begin
            if (sram_awvalid && sram_awready) begin
                write_addr       <= sram_awaddr;
                write_addr_valid <= 1;
                sram_awready     <= 0;
                // LFSR             <= $urandom_range(MIN_DELAY, MAX_DELAY);
                LFSR             <= MIN_DELAY;
            end
            if (sram_wvalid && sram_wready) begin
                write_data       <= sram_wdata;
                write_strb       <= sram_wstrb;
                write_data_valid <= 1;
                sram_wready      <= 0;
            end
            if (write_addr_valid && write_data_valid) begin
                if(LFSR > 0) begin
                    LFSR <= LFSR - 1;
                end
                else begin
                    case (write_strb)
                        4'b0001: pmem_write(write_addr, write_data, 1); 
                        4'b0011: pmem_write(write_addr, write_data, 2); 
                        4'b1111: pmem_write(write_addr, write_data, 4); 
                        default: pmem_write(write_addr, write_data, 4);
                    endcase
                    sram_bvalid       <= 1;
                    sram_bresp        <= OKAY;
                    write_addr_valid  <= 0;
                    write_data_valid  <= 0;
                    sram_awready      <= 1;
                    sram_wready       <= 1;
                end
            end
            if (sram_bvalid && sram_bready) begin
                sram_bvalid <= 0;
            end
        end
    end
    // always @(posedge clk) begin
    //     if(rst) begin
    //         sram_lsu_rready <= 0;
    //         sram_lsu_wready <= 0;
    //     end
    //     else if(lsu_sram_rvalid && sram_lsu_rready) begin
    //         sram_lsu_rready <= 0;
    //         sram_lsu_rdata <= 32'h0;
    //     end
    //     else if(lsu_sram_rvalid) begin
    //         sram_lsu_rready <= 1;
    //         sram_lsu_rdata <= pmem_read(lsu_sram_araddr, 4);
    //     end
    // end

    // always @(posedge clk) begin
    //     if(rst) begin
    //         sram_lsu_wready <= 0;
    //     end
    //     else if(lsu_sram_wvalid) begin
    //         sram_lsu_wready <= 1;
    //         // pmem_write(lsu_sram_awaddr, lsu_sram_wdata, lsu_sram_wstrb);
    //         case(lsu_sram_wstrb)
    //             4'b0001: pmem_write(lsu_sram_awaddr,lsu_sram_wdata,1);//sb
    //             4'b0011: pmem_write(lsu_sram_awaddr,lsu_sram_wdata,2);//sh
    //             4'b1111: pmem_write(lsu_sram_awaddr,lsu_sram_wdata,4);//sw
    //             default: pmem_write(lsu_sram_awaddr,lsu_sram_wdata,4);
    //         endcase
    //     end
    //     else begin
    //         sram_lsu_wready <= 0;
    //     end
    // end
endmodule