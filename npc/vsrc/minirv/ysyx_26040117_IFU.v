module ysyx_26040117_IFU#(RESET_VECTOR=32'h30000000)(clk,rst,
    redirect_valid,dnpc,fence_i,
    IFU_IDU_valid,IFU_IDU_ready,inst,pc,fence_done,idu_pc,pred_taken,
    MEM_IFU_wrapper,IFU_MEM_wrapper,
    btb_hit,btb_target,btb_araddr
);
    input clk,rst;
    localparam [29:0] RESET_PC=RESET_VECTOR[31:2];
    //WBU-IFU
    input redirect_valid;
    input[31:0]dnpc/* verilator public_flat_rd */;
    input fence_i;
    //IFU-IDU
    input IFU_IDU_ready;
    output IFU_IDU_valid;
    output [31:0]inst;
    output [31:0]pc;
    output fence_done,pred_taken;
    //IDU-IFU
    input [31:0] idu_pc;
    //IFU-MEM
    input [67:0] MEM_IFU_wrapper;
    output[37:0] IFU_MEM_wrapper;
    //IFU_BTB
    input btb_hit;
    input [31:0] btb_target;
    output[31:0] btb_araddr;

    wire rvalid,rready,arready,arvalid;
    reg s1_redirect,s1_btb_valid;
    wire flush_pending,fence_done;
    wire s1_valid=!(flush_pending||fence_done);
    wire cache_clear=rst||fence_i;
    wire pipe_clear=cache_clear||redirect_valid;
    assign arvalid=s1_valid&&!pipe_clear;
    wire arfire=arvalid&&arready;
    reg[29:0] s1_snpc,s1_dnpc;
    wire [31:0] araddr;
    always @(posedge clk) begin
        if(redirect_valid)
            s1_dnpc<=dnpc[31:2];
        else if(btb_hit&&s1_valid&&arready)
            s1_dnpc<=btb_target[31:2];
    end
    wire[29:0] snpc_next=fence_done?idu_pc[31:2]:araddr[31:2];
    always @(posedge clk) begin
        if(rst)
            s1_snpc<=RESET_PC;
        else if(fence_done||(s1_valid&&arready))
            s1_snpc<=snpc_next+30'd1;
    end
    assign  araddr={(s1_redirect||s1_btb_valid)?s1_dnpc:s1_snpc,2'b00};
    always @(posedge clk) begin
        if(cache_clear)begin
            s1_redirect<=1'b0;
        end else if(redirect_valid)begin 
            s1_redirect<=1'b1;
        end else if(arfire)begin
            s1_redirect<=1'b0;
        end
    end
    //BTB
    assign btb_araddr=araddr;
    assign pred_taken=s1_btb_valid;
    always @(posedge clk) begin
        if(pipe_clear)
            s1_btb_valid<=1'b0;
        else if(arfire)
            s1_btb_valid<=btb_hit;
    end

    //state machine 
    assign rready=IFU_IDU_ready;
    assign IFU_IDU_valid=rvalid;
    //取指
    assign IFU_MEM_wrapper={fence_i,pipe_clear,cache_clear,s1_valid,arvalid,araddr,rready};
    assign {flush_pending,fence_done,arready,rvalid,pc,inst}=MEM_IFU_wrapper;
endmodule
