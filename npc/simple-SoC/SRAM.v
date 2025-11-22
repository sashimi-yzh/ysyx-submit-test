module SRAM (
    input  wire         clk,
    input  wire         rst,

    output reg          awready,
    input  wire         awvalid,
    input  wire [31: 0] awaddr,
    input  wire [ 3: 0] awid,
    input  wire [ 7: 0] awlen,
    input  wire [ 2: 0] awsize,
    input  wire [ 1: 0] awburst,
    output reg          wready,
    input  wire         wvalid,
    input  wire [31: 0] wdata,
    input  wire [ 3: 0] wstrb,
    input  wire         wlast,
    input  wire         bready,
    output reg          bvalid,
    output reg  [ 1: 0] bresp,
    output reg  [ 3: 0] bid,
    output reg          arready,
    input  wire         arvalid,
    input  wire [31: 0] araddr,
    input  wire [ 3: 0] arid,
    input  wire [ 7: 0] arlen,
    input  wire [ 2: 0] arsize,
    input  wire [ 1: 0] arburst,
    input  wire         rready,
    output reg          rvalid,
    output reg  [ 1: 0] rresp,
    output reg  [31: 0] rdata,
    output reg          rlast,
    output reg  [ 3: 0] rid
);

    localparam IDLE         = 1'b0;
    localparam BUSY         = 1'b1;
    reg          state, next_state;
    reg  [31: 0] read_addr, write_addr, write_data;
    reg  [ 3: 0] write_strb;
    reg          is_read_req, is_write_req;
    reg  [ 3: 0] read_id, write_id;
    wire [31: 0] addr_off = awaddr & 32'b11;

    `ifdef __ICARUS__
        localparam SRAM_DEPTH = 8 * 1024 * 1024;
        reg [7:0]  sram_array [0:SRAM_DEPTH-1]; 

        wire [31:0] sram_addr_r = {araddr[31:2], 2'b0} - 32'h80000000;
        wire [31:0] sram_addr_w = {awaddr[31:2], 2'b0} - 32'h80000000;
        wire [7:0] b0, b1, b2, b3;
        assign b0 = sram_array[sram_addr_r + 0];
        assign b1 = sram_array[sram_addr_r + 1];
        assign b2 = sram_array[sram_addr_r + 2];
        assign b3 = sram_array[sram_addr_r + 3];

        wire [7:0] byte0, byte1, byte2, byte3;
        wire [31:0] init_inst;

        assign byte0 = sram_array[0];
        assign byte1 = sram_array[1];
        assign byte2 = sram_array[2];
        assign byte3 = sram_array[3];
        assign init_inst = {byte3, byte2, byte1, byte0};

        localparam TARGET_PC1 = 32'h30000000;
        localparam INSTR1     = 32'h800000b7;      // lui ra 0x80000
        localparam TARGET_PC2 = 32'h30000004;
        localparam INSTR2     = 32'h00008067;      // jalr ra
        //填充4条指令
        localparam TARGET_PC3 = 32'h30000008;
        localparam TARGET_PC4 = 32'h3000000c;

        wire [31:0] sram_rdata = {b3, b2, b1, b0};
        wire [31:0] final_rdata;
        assign final_rdata = (araddr == TARGET_PC1) ? INSTR1 :
                             (araddr == TARGET_PC2) ? INSTR2 :
                             (araddr == TARGET_PC3) ? INSTR1 :
                             (araddr == TARGET_PC4) ? INSTR1 :
                              sram_rdata;

        `ifndef MEM_INIT_PATH
            `define MEM_INIT_PATH "../build/iverilog/mem_init.hex"
        `endif

        initial begin
            integer i;
            for (i = 0; i < SRAM_DEPTH; i = i + 1) begin
                sram_array[i] = 8'h00;
            end
            $display("[SRAM][iverilog] Initializing from: %s", `MEM_INIT_PATH);
            $readmemh(`MEM_INIT_PATH, sram_array);
            $display("[SRAM][iverilog] Init check: addr 0x80000000 = 0x%08x", init_inst);
        end

        always @(*) begin
            case (state)
                IDLE: next_state = (arvalid | awvalid) ? BUSY : IDLE;      
                BUSY: next_state = ((is_read_req && rlast && rvalid) | (is_write_req && bready && bvalid)) ? IDLE : BUSY; 
                default: next_state = IDLE;
            endcase
        end

        always @(posedge clk or posedge rst) begin
            if (rst) begin
                state   <= IDLE;    
                arready <= 1'b1;
                rvalid  <= 1'b0;
                rresp   <= 2'b00;
                rdata   <= 32'h0;
                rlast   <= 1'b0;
                rid     <= 4'h0;
                awready <= 1'b0;
                wready  <= 1'b0;
                bvalid  <= 1'b0;
                bresp   <= 2'b00;
                bid     <= 4'h0;
                is_read_req  <= 1'b0;
                is_write_req <= 1'b0;
                read_addr  <= 32'h0;
                write_addr <= 32'h0;
                write_data <= 32'h0;
                write_strb <= 4'h0;
                read_id    <= 4'h0;
                write_id   <= 4'h0;
            end else begin
                state <= next_state;
                case (state)
                    IDLE: begin
                        rvalid <= 1'b0;
                        bvalid <= 1'b0;
                        rlast  <= 1'b0;
                        is_read_req  <= 1'b0;
                        is_write_req <= 1'b0;
                        wready <= 1'b0;
                        
                        if (arvalid) begin
                            read_addr   <= araddr;
                            read_id     <= arid;
                            arready     <= 1'b1;
                            is_read_req <= 1'b1;
                        end else if (awvalid & wvalid) begin
                            write_addr <= awaddr;
                            write_id   <= awid;
                            awready    <= 1'b1;
                            wready     <= 1'b1;
                            is_write_req <= 1'b1;
                            write_data <= wdata;
                            write_strb <= wstrb;
                        end
                    end
                    BUSY: begin
                        if (is_read_req) begin
                            rvalid <= 1'b1;
                            rresp  <= 2'b00;
                            rdata <= final_rdata;
                            // rdata  <= {b3, b2, b1, b0}; // 大端拼接为32位指令
                            rlast  <= 1'b1;
                            rid    <= read_id;
                            
                            if (rvalid & rready) begin
                                rvalid <= 1'b0;
                                rlast  <= 1'b0;
                            end
                        end 
                        else if (is_write_req) begin
                            if (wvalid & wready) begin
                                wready <= 1'b0;
                                // 按字节写入
                                if (write_strb[0]) sram_array[sram_addr_w + 0] <= write_data[7:0];
                                if (write_strb[1]) sram_array[sram_addr_w + 1] <= write_data[15:8];
                                if (write_strb[2]) sram_array[sram_addr_w + 2] <= write_data[23:16];
                                if (write_strb[3]) sram_array[sram_addr_w + 3] <= write_data[31:24];
                                
                                bvalid <= 1'b1;
                                bresp  <= 2'b00;
                                bid    <= write_id;
                            end
                            if (bvalid & bready) begin
                                awready <= 1'b0;
                                bvalid  <= 1'b0;
                            end
                        end
                    end
                endcase
            end
        end
    `else
        import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
        import "DPI-C" function void pmem_write(input int unsigned waddr, input int unsigned wdata, input int len);
        // import "DPI-C" function int pmem_read(input int addr, input int len, input int trace_on);
        // import "DPI-C" function void pmem_write(input int addr, input int len, input int data, input int trace_on);
        always @(*) begin
            case (state)
                IDLE: next_state = (arvalid | awvalid) ? BUSY : IDLE;      
                BUSY: next_state = ((is_read_req && rlast && rvalid) | (is_write_req && bready && bvalid)) ? IDLE : BUSY; 
                default: next_state = IDLE;
            endcase
        end
        always @(posedge clk or posedge rst) begin
            if (rst) begin
                state   <= IDLE;    
                arready <= 1'b1;
                rvalid  <= 1'b0;
                rresp   <= 2'b00;
                rdata   <= 32'h0;
                rlast   <= 1'b0;
                rid     <= 4'h0;
                awready <= 1'b0;
                wready  <= 1'b0;
                bvalid  <= 1'b0;
                bresp   <= 2'b00;
                bid     <= 4'h0;
                is_read_req  <= 1'b0;
                is_write_req <= 1'b0;
                read_addr    <= 32'h0;
                write_addr <= 32'h0;
                write_data <= 32'h0;
                write_strb <= 4'h0;
                read_id  <= 4'h0;
                write_id <= 4'h0;
            end else begin
                state <= next_state;
                case (state)
                    IDLE: begin
                        rvalid <= 1'b0;
                        bvalid <= 1'b0;
                        rlast  <= 1'b0;
                        is_read_req  <= 1'b0;
                        is_write_req <= 1'b0;
                        wready <= 1'b0;
                        if (arvalid) begin
                            read_addr   <= araddr;
                            read_id     <= arid;
                            arready     <= 1'b1;
                            is_read_req <= 1'b1;
                        end else if (awvalid & wvalid) begin
                            write_addr   <= awaddr;
                            write_id     <= awid;
                            awready      <= 1'b1;
                            wready       <= 1'b1;
                            is_write_req <= 1'b1;
                        end
                    end
                    BUSY: begin
                        if (is_read_req) begin
                            rvalid <= 1'b1;
                            rresp  <= 2'b00;
                            rdata  <= pmem_read(read_addr, 4) << ((read_addr & 32'b11) << 3);
                            rlast  <= 1'b1;
                            rid    <= read_id;
                            if (rvalid & rready) begin
                                rvalid <= 1'b0;
                                rlast  <= 1'b0;
                            end
                        end 
                        else if (is_write_req) begin
                            if (wvalid & wready) begin
                                wready <= 1'b0;
                                // pmem_write(write_addr,  wdata >> (addr_off << 3), {28'h0, wstrb >> addr_off});
                                case(wstrb)
                                    4'b0001, 4'b0010, 4'b0100, 4'b1000: pmem_write(write_addr, wdata >> (addr_off << 3), 1);
                                    4'b0011, 4'b1100:                   pmem_write(write_addr, wdata >> (addr_off << 3), 2);
                                    default:                            pmem_write(write_addr, wdata >> (addr_off << 3), 4);
                                endcase
                                bvalid <= 1'b1;
                                bresp  <= 2'b00;
                                bid    <= write_id;
                            end
                            if (bvalid & bready) begin
                                awready <= 1'b0;
                                bvalid  <= 1'b0;
                            end
                        end
                    end
                endcase
            end
        end
    `endif
endmodule
