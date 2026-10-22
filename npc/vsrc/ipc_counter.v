`ifdef VERILATOR
module ipc_counter(
    input clk,
    input rst,
    // input [31:0] pc,
    input        wbu_valid,
    input        ebreak,
    input [63:0] ifu_performance_counter,
    input [63:0] idu_performance_counter,
    input [63:0] exu_performance_counter,
    input [63:0] lsu_performance_counter,
    input [63:0] wbu_performance_counter,
    input [63:0] csr_hit_counter,
    input [63:0] exu_hit_counter,
    input [63:0] jump_hit_counter,
    input [63:0] mem_hit_counter,
    input [63:0] fence_hit_counter,
    input [63:0] ifu_cycles_counter,
    input [63:0] idu_cycles_counter,
    input [63:0] exu_cycles_counter,
    input [63:0] lsu_cycles_counter,
    input [63:0] wbu_cycles_counter,
    input [63:0] single_cycle_counter,
    input [7:5]  inst,
    input [63:0] icache_hit_counter
);

    localparam  EXU_INST     = 3'b001;
    localparam  JUMP_INST    = 3'b010;
    localparam  MEM_INST     = 3'b011;
    localparam  CSR_INST     = 3'b100;
    localparam  SPECIAL_INST = 3'b101;
    parameter icache_access_time = 1;
    parameter icache_miss_penalty = 30; // 36 apb delay_on dram // 30 axiburst

    wire [63:0] EXU_instructions = exu_hit_counter;
    wire [63:0] CSR_instructions = csr_hit_counter;
    wire [63:0] MEM_instructions = mem_hit_counter;
    wire [63:0] JUMP_instructions = jump_hit_counter;
    wire [63:0] FENCE_instructions = fence_hit_counter;

    // reg [31:0] prev_pc;
    reg [63:0] counter;
    reg [63:0] cycle_counter;
    reg [63:0] exu_cycle_counter;
    reg [63:0] mem_cycle_counter;
    reg [63:0] csr_cycle_counter;
    reg [63:0] jump_cycle_counter;
    reg [63:0] fence_cycle_counter;
    // reg [63:0] single_cycle_counter;
    // reg [63:0] ifu_performance_counter_prev;
    // reg [63:0] EXU_instructions_prev;
    // reg [63:0] CSR_instructions_prev;
    // reg [63:0] MEM_instructions_prev;

    // always @(posedge clk) begin
    //     prev_pc <= pc;
    // end

    always @(posedge clk) begin
        if (rst) begin
            exu_cycle_counter <= 0;
            mem_cycle_counter <= 0;
            csr_cycle_counter <= 0;
            jump_cycle_counter <= 0;
            fence_cycle_counter <= 0;
        end else if (wbu_valid) begin
            case (inst)
            CSR_INST:     csr_cycle_counter <= csr_cycle_counter + single_cycle_counter;
            MEM_INST:     mem_cycle_counter <= mem_cycle_counter + single_cycle_counter;
            SPECIAL_INST: fence_cycle_counter <= fence_cycle_counter + single_cycle_counter;
            JUMP_INST:    jump_cycle_counter <= jump_cycle_counter + single_cycle_counter;
            default:      exu_cycle_counter <= exu_cycle_counter + single_cycle_counter;
            endcase
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            counter <= 1;
            cycle_counter <= 0;
        end else begin
            cycle_counter <= cycle_counter + 1;
            if (wbu_valid)
                counter <= counter + 1;
            if (ebreak & wbu_valid) begin
                $display("\033[1;33mIFU Performance Counter: %16d spent %16d cycles busy account for %f\033[0m", ifu_performance_counter, ifu_cycles_counter, $itor(ifu_cycles_counter) / $itor(cycle_counter));
                $display("\033[1;33mIDU Performance Counter: %16d spent %16d cycles busy account for %f\033[0m", idu_performance_counter, idu_cycles_counter, $itor(idu_cycles_counter) / $itor(cycle_counter));
                $display("\033[1;33mEXU Performance Counter: %16d spent %16d cycles busy account for %f\033[0m", exu_performance_counter, exu_cycles_counter, $itor(exu_cycles_counter) / $itor(cycle_counter));
                $display("\033[1;33mLSU Performance Counter: %16d spent %16d cycles busy account for %f\033[0m", exu_performance_counter, lsu_cycles_counter, $itor(lsu_cycles_counter) / $itor(cycle_counter));
                $display("\033[1;33mWBU Performance Counter: %16d spent %16d cycles busy account for %f\033[0m", wbu_performance_counter, wbu_cycles_counter, $itor(wbu_cycles_counter) / $itor(cycle_counter));

                $display("\033[1;94mEXU   instructions:%16d account for %02f%% average spent %f cycles\033[0m", 
                        EXU_instructions, $itor(EXU_instructions) / $itor(idu_performance_counter), $itor(exu_cycle_counter) / $itor(EXU_instructions));
                $display("\033[1;94mCSR   instructions:%16d account for %02f%% average spent %f cycles\033[0m", 
                        CSR_instructions, $itor(CSR_instructions) / $itor(idu_performance_counter), $itor(csr_cycle_counter) / $itor(CSR_instructions));
                $display("\033[1;94mMEM   instructions:%16d account for %02f%% average spent %f cycles\033[0m", 
                        MEM_instructions, $itor(MEM_instructions) / $itor(idu_performance_counter), $itor(mem_cycle_counter) / $itor(MEM_instructions));
                $display("\033[1;94mJUMP  instructions:%16d account for %02f%% average spent %f cycles\033[0m", 
                        JUMP_instructions, $itor(JUMP_instructions) / $itor(idu_performance_counter), $itor(jump_cycle_counter) / $itor(JUMP_instructions));
                $display("\033[1;94mFENCE instructions:%16d account for %02f%% average spent %f cycles\033[0m", 
                        FENCE_instructions, $itor(FENCE_instructions) / $itor(idu_performance_counter), $itor(fence_cycle_counter) / $itor(FENCE_instructions));
                $display("\033[1;94micache hit rate = %f AMAT = %f\033[0m",  
                        $itor(icache_hit_counter) / $itor(ifu_performance_counter), $itor(icache_access_time) + (1 - $itor(icache_hit_counter) / $itor(ifu_performance_counter)) * icache_miss_penalty);
                $display("\033[1;32mTotal instructions: %16d\t Total cycles: %16d\033[0m",  counter , cycle_counter);
                $display("\033[1;32mIPC = %f\033[0m",  $itor(counter) / $itor(cycle_counter));
                $display("\033[1;32mCPI = %f\033[0m",  $itor(cycle_counter) / $itor(counter));
            end
        end
    end

endmodule
`endif
