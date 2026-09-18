module ysyx_26010027_CSR (
    input              clock,
    input              reset,
    input              csr_ecall,
    input              csr_mret,
    input       [11:0] csr_raddr,
    input       [11:0] csr_waddr,
    input       [31:0] csr_wdata,
    output      [31:0] csr_rdata,
    output      [31:0] csr_mtvec,
    output      [31:0] csr_mepc,
    input       [31:0] pc,
    input  wire        csr_we

);

    reg [31:0] mvendorid = 32'h79737978;  // "ysyx"
    reg [31:0] marchid   = 32'h18CE1AB;   // "26010027"

    reg [31:0] mstatus;
    reg [31:0] mtvec;
    reg [31:0] mepc;
    reg [31:0] mcause;
    // reg [63:0] mc;

    // Write
    always @(posedge clock, posedge reset) begin
        if (reset) begin
            mstatus <= 32'h1800;
            mtvec   <= 32'h0;
            mepc    <= 32'h0;
            mcause  <= 32'h0;
        end else begin
            if (csr_ecall) begin  // ecall
                mepc   <= pc;
                mcause <= 32'd11;  // M-mode
`ifdef NPC_SIM
                get_csr({20'b0, 12'h341}, pc);
                get_csr({20'b0, 12'h342}, 32'd11);
`endif
            end 
            else if (csr_we && !csr_ecall && !csr_mret) begin
`ifdef NPC_SIM
                get_csr({20'b0, csr_waddr}, csr_wdata);
`endif
                case (csr_waddr)
                    12'h300: mstatus <= csr_wdata;
                    12'h305: mtvec   <= csr_wdata;
                    12'h341: mepc    <= csr_wdata;
                    12'h342: mcause  <= csr_wdata;
                    default: begin
`ifdef NPC_SIM
                        $fatal(1, "Warning: Write to unknown CSR address %h", csr_waddr);
`endif
                    end
                endcase
            end
        end
    end

    // Read
    assign csr_rdata = (csr_raddr == 12'hf11) ? mvendorid :
                       (csr_raddr == 12'hf12) ? marchid :
                       (csr_raddr == 12'h300) ? mstatus :
                       (csr_raddr == 12'h305) ? mtvec :
                       (csr_raddr == 12'h341) ? mepc :
                       (csr_raddr == 12'h342) ? mcause : 0;

    assign csr_mtvec = mtvec;
    assign csr_mepc  = mepc;

endmodule
