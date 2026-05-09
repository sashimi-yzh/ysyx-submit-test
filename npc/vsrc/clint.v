// `include "npc_config.vh"

// `ifdef DIFFTEST
// import "DPI-C" function void difftest_skip_ref();
// `endif 

module ysyx_25040102_clint(
    input               clk,
    input               reset,

    output              clint_slave_awready,
    input               clint_slave_awvalid, 
    input   [31:0]      clint_slave_awaddr,  
    input   [3:0]       clint_slave_awid,    
    input   [7:0]       clint_slave_awlen,   
    input   [2:0]       clint_slave_awsize,  
    input   [1:0]       clint_slave_awburst, 
    output              clint_slave_wready,  
    input               clint_slave_wvalid,  
    input   [31:0]      clint_slave_wdata,   
    input   [3:0]       clint_slave_wstrb,   
    input               clint_slave_wlast,
    input               clint_slave_bready,  
    output              clint_slave_bvalid,  
    output  [1:0]       clint_slave_bresp,   
    output  [3:0]       clint_slave_bid,  
    output              clint_slave_arready, 
    input               clint_slave_arvalid, 
    input   [31:0]      clint_slave_araddr,  
    input   [3:0]       clint_slave_arid,    
    input   [7:0]       clint_slave_arlen,   
    input   [2:0]       clint_slave_arsize,  
    input   [1:0]       clint_slave_arburst, 
    input               clint_slave_rready,  
    output              clint_slave_rvalid,  
    output  [1:0]       clint_slave_rresp,   
    output  [31:0]      clint_slave_rdata,   
    output              clint_slave_rlast,   
    output  [3:0]       clint_slave_rid
);

    reg     [3:0]   addr;
    // reg     [10:0]  count;
    reg     [63:0]  m_time;

    // wire    [31:0]  r_data;

    reg     [1:0]   current_state;
    reg     [1:0]   next_state;
    
    localparam  IDLE    = 0;
    localparam  WAIT_RREADY  = 1;
    localparam  WAIT_WVALID  = 2;
    localparam  WAIT_BREADY  = 3;
    
    always @(posedge clk) begin
        if(reset  == 1'b1) begin
            current_state   <= IDLE;
        end
        else begin
            current_state   <= next_state;
        end
    end


    always @(*) begin
        case(current_state)

            IDLE: begin
                if(clint_slave_arvalid == 1'b1) begin
                    next_state  = WAIT_RREADY;
                end
                else if(clint_slave_awvalid ==  1'b1) begin
                    next_state  = WAIT_WVALID;
                end
                else begin
                    next_state  = IDLE;
                end
            end

            WAIT_RREADY: begin
                if(clint_slave_rready == 1'b1) begin
                    next_state  = IDLE;
                end
                else begin
                    next_state  = WAIT_RREADY;
                end
            end

            WAIT_WVALID: begin
                if(clint_slave_wvalid == 1'b1) begin
                    next_state  = WAIT_BREADY;
                end
                else begin
                    next_state  = WAIT_WVALID;
                end
            end

            WAIT_BREADY: begin
                if(clint_slave_bready == 1'b1) begin
                    next_state  = IDLE;
                end
                else begin
                    next_state  = WAIT_BREADY;
                end
            end

        endcase
    end

    always @(posedge clk) begin // addr
        // if(reset == 1'b1) begin
        //     addr    <= 4'h0;
        // end
        // else begin
            if(clint_slave_arready == 1'b1 && clint_slave_arvalid == 1'b1) begin
                addr    <= clint_slave_araddr[3:0];
            end
            else if(clint_slave_awready == 1'b1 && clint_slave_awvalid == 1'b1) begin
                addr    <= clint_slave_awaddr[3:0];
            end
        // end
    end

    always @(posedge clk) begin
        if(reset) begin
            m_time      <= 0;
        end
        else begin
            if(clint_slave_wvalid && clint_slave_wready) begin
                if(addr[3:0] == 4'h0) begin
                    m_time  <= {m_time[63:32], clint_slave_wdata};
                end
                else if(addr[3:0] == 4'h4) begin
                    m_time  <= {clint_slave_wdata, m_time[31:0]};
                end
            end
            else begin
                m_time  <= m_time + 1;
            end
        end    
    end


    assign clint_slave_rresp = 2'b00;
    assign clint_slave_awready = (current_state == IDLE);
    assign clint_slave_arready = (current_state == IDLE);
    assign clint_slave_wready  = (current_state == WAIT_WVALID);
    assign clint_slave_rvalid  = (current_state == WAIT_RREADY);
    assign clint_slave_rdata   = (addr[3:0] == 4'h0) ? m_time[31:0] : m_time[63:32];
    assign clint_slave_rlast   = (current_state == WAIT_RREADY);
    assign clint_slave_bvalid  = (current_state == WAIT_BREADY);
    assign clint_slave_bresp   = 2'b00;
    assign clint_slave_bid     = (current_state == WAIT_BREADY) ? 4'h1 : 0;
    assign clint_slave_rid     = (current_state == WAIT_RREADY) ? 4'h1 : 0;

endmodule
