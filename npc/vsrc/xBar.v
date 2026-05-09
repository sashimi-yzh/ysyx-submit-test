`include "npc_config.vh"

module ysyx_25040102_xBar(
    input               clk,
    input               reset,
    
    output              ifu_arready, 
    input               ifu_arvalid, 
    input   [31:0]      ifu_araddr,  
    input   [3:0]       ifu_arid,    
    input   [7:0]       ifu_arlen,   
    input   [2:0]       ifu_arsize,  
    input   [1:0]       ifu_arburst, 
    input               ifu_rready,  
    output              ifu_rvalid,  
    output  [1:0]       ifu_rresp,   
    output  [31:0]      ifu_rdata,   
    output              ifu_rlast,   
    output  [3:0]       ifu_rid,     

    output              lsu_awready,
    input               lsu_awvalid, 
    input   [31:0]      lsu_awaddr,  
    input   [3:0]       lsu_awid,    
    input   [7:0]       lsu_awlen,   
    input   [2:0]       lsu_awsize,  
    input   [1:0]       lsu_awburst, 
    output              lsu_wready,  
    input               lsu_wvalid,  
    input   [31:0]      lsu_wdata,   
    input   [3:0]       lsu_wstrb,   
    input               lsu_wlast,   
    input               lsu_bready,  
    output              lsu_bvalid,  
    output  [1:0]       lsu_bresp,   
    output  [3:0]       lsu_bid,     
    output              lsu_arready, 
    input               lsu_arvalid, 
    input   [31:0]      lsu_araddr,  
    input   [3:0]       lsu_arid,    
    input   [7:0]       lsu_arlen,   
    input   [2:0]       lsu_arsize,  
    input   [1:0]       lsu_arburst, 
    input               lsu_rready,  
    output              lsu_rvalid,  
    output  [1:0]       lsu_rresp,   
    output  [31:0]      lsu_rdata,   
    output              lsu_rlast,   
    output  [3:0]       lsu_rid,

    input               io_master_awready,
    output              io_master_awvalid, 
    output  [31:0]      io_master_awaddr,  
    output  [3:0]       io_master_awid,    
    output  [7:0]       io_master_awlen,   
    output  [2:0]       io_master_awsize,  
    output  [1:0]       io_master_awburst, 
    input               io_master_wready,  
    output              io_master_wvalid,  
    output  [31:0]      io_master_wdata,   
    output  [3:0]       io_master_wstrb,   
    output              io_master_wlast,   
    output              io_master_bready,  
    input               io_master_bvalid,  
    input   [1:0]       io_master_bresp,   
    input   [3:0]       io_master_bid,     
    input               io_master_arready, 
    output              io_master_arvalid, 
    output  [31:0]      io_master_araddr,  
    output  [3:0]       io_master_arid,    
    output  [7:0]       io_master_arlen,   
    output  [2:0]       io_master_arsize,  
    output  [1:0]       io_master_arburst, 
    output              io_master_rready,  
    input               io_master_rvalid,  
    input   [1:0]       io_master_rresp,   
    input   [31:0]      io_master_rdata,   
    input               io_master_rlast,   
    input   [3:0]       io_master_rid,

    input               clint_master_awready,
    output              clint_master_awvalid, 
    output  [31:0]      clint_master_awaddr,  
    output  [3:0]       clint_master_awid,    
    output  [7:0]       clint_master_awlen,   
    output  [2:0]       clint_master_awsize,  
    output  [1:0]       clint_master_awburst, 
    input               clint_master_wready,  
    output              clint_master_wvalid,  
    output  [31:0]      clint_master_wdata,   
    output  [3:0]       clint_master_wstrb,   
    output              clint_master_wlast,   
    output              clint_master_bready,  
    input               clint_master_bvalid,  
    input   [1:0]       clint_master_bresp,   
    input   [3:0]       clint_master_bid,     
    input               clint_master_arready, 
    output              clint_master_arvalid, 
    output  [31:0]      clint_master_araddr,  
    output  [3:0]       clint_master_arid,    
    output  [7:0]       clint_master_arlen,   
    output  [2:0]       clint_master_arsize,  
    output  [1:0]       clint_master_arburst, 
    output              clint_master_rready,  
    input               clint_master_rvalid,  
    input   [1:0]       clint_master_rresp,   
    input   [31:0]      clint_master_rdata,   
    input               clint_master_rlast,   
    input   [3:0]       clint_master_rid
    
);

    localparam  IDLE        = 0;
    localparam  IFU_ADDR    = 1;
    localparam  LSU_ADDR    = 2;

    wire    clint;
    assign  clint   = ((lsu_araddr[31:24] == 8'h02));

    reg     [1:0]   current_state;
    reg     [1:0]   next_state;

    always @(posedge clk) begin
        if(reset) begin
            current_state   <= IDLE;
        end
        else begin
            current_state   <= next_state;
        end
    end

    always @(*) begin
        case(current_state)
            
            IDLE: begin
                if(lsu_awvalid == 1'b1 || lsu_arvalid == 1'b1) begin
                    next_state      = LSU_ADDR;
                end
                else if(ifu_arvalid == 1'b1) begin
                    next_state      = IFU_ADDR;
                end
                else begin
                    next_state      = IDLE;
                end
            end

            IFU_ADDR: begin
                if(ifu_arready == 1'b1) begin
                    next_state      = IDLE;
                end
                else begin
                    next_state      = IFU_ADDR;
                end
            end

            LSU_ADDR: begin
                if(lsu_arready == 1'b1 || lsu_awready == 1'b1) begin
                    next_state      = IDLE;
                end
                else begin
                    next_state      = LSU_ADDR;
                end
            end

            default: begin
                next_state  = IDLE;
            end
        endcase
    end

    assign  lsu_awready             = (current_state == LSU_ADDR) ? (clint == 1'b1) ? clint_master_awready : io_master_awready : 0;
    assign  lsu_wready              = (clint == 1'b1) ? clint_master_wready  : io_master_wready  ;
    assign  lsu_bvalid              = (clint == 1'b1) ? clint_master_bvalid  : io_master_bvalid  ;
    assign  lsu_bresp               = (clint == 1'b1) ? clint_master_bresp   : io_master_bresp   ;
    assign  lsu_bid                 = 4'b0001;

    assign  ifu_arready             = (current_state == IFU_ADDR) ? io_master_arready : 1'b0;
    assign  lsu_arready             = (current_state == LSU_ADDR) ? (clint == 1'b1) ? clint_master_arready : io_master_arready : 0;
    
    assign  ifu_rvalid              = (io_master_rid == 4'b0) ? io_master_rvalid : 1'b0;
    assign  lsu_rvalid              = (io_master_rid == 4'b1) ? io_master_rvalid : (clint == 1'b1) ? clint_master_rvalid : 0;

    assign  ifu_rresp               = (io_master_rid == 4'b0) ? io_master_rresp : 2'b0;
    assign  lsu_rresp               = (io_master_rid == 4'b1) ? io_master_rresp : (clint == 1'b1) ? clint_master_rresp : 0;

    assign  ifu_rdata               = (io_master_rid == 4'b0) ? io_master_rdata : 32'b0;
    assign  lsu_rdata               = (io_master_rid == 4'b1) ? io_master_rdata : (clint == 1'b1) ? clint_master_rdata : 0;

    assign  ifu_rlast               = (io_master_rid == 4'b0) ? io_master_rlast : 1'b0;
    assign  lsu_rlast               = (io_master_rid == 4'b1) ? io_master_rlast : (clint == 1'b1) ? clint_master_rlast : 0;

    assign  ifu_rid                 = 4'b0000;
    assign  lsu_rid                 = 4'b0001;

    assign  io_master_awvalid       = (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_awvalid : 0;        
    assign  io_master_awaddr        = (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_awaddr  : 0;      
    assign  io_master_awid          = (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_awid    : 0;  
    assign  io_master_awlen         = (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_awlen   : 0;    
    assign  io_master_awsize        = (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_awsize  : 0;      
    assign  io_master_awburst       = (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_awburst : 0;        
    assign  io_master_wvalid        = (clint == 1'b1) ? 0 : lsu_wvalid ;
    assign  io_master_wdata         = (clint == 1'b1) ? 0 : lsu_wdata  ;    
    assign  io_master_wstrb         = (clint == 1'b1) ? 0 : lsu_wstrb  ;    
    assign  io_master_wlast         = (clint == 1'b1) ? 0 : lsu_wlast  ;    
    assign  io_master_bready        = (clint == 1'b1) ? 0 : lsu_bready ;       
    assign  io_master_arvalid       = (current_state == IFU_ADDR) ? ifu_arvalid : (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_arvalid  : 0;        
    assign  io_master_araddr        = (current_state == IFU_ADDR) ? ifu_araddr  : (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_araddr   : 0;      
    assign  io_master_arid          = (current_state == IFU_ADDR) ? ifu_arid    : (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_arid     : 0;  
    assign  io_master_arlen         = (current_state == IFU_ADDR) ? ifu_arlen   : (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_arlen    : 0;    
    assign  io_master_arsize        = (current_state == IFU_ADDR) ? ifu_arsize  : (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_arsize   : 0;      
    assign  io_master_arburst       = (current_state == IFU_ADDR) ? ifu_arburst : (current_state == LSU_ADDR) ? (clint == 1'b1) ? 0 : lsu_arburst  : 0;        
    assign  io_master_rready        = (io_master_rid == 4'h0) ? ifu_rready  : (clint == 1'b1) ? 0 : lsu_rready   ;      

    assign  clint_master_awvalid    = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_awvalid : 0 : 0;        
    assign  clint_master_awaddr     = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_awaddr  : 0 : 0;      
    assign  clint_master_awid       = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_awid    : 0 : 0;  
    assign  clint_master_awlen      = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_awlen   : 0 : 0;    
    assign  clint_master_awsize     = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_awsize  : 0 : 0;      
    assign  clint_master_awburst    = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_awburst : 0 : 0;        
    assign  clint_master_wvalid     = lsu_wvalid ;      
    assign  clint_master_wdata      = lsu_wdata  ;    
    assign  clint_master_wstrb      = lsu_wstrb  ;    
    assign  clint_master_wlast      = lsu_wlast  ;    
    assign  clint_master_bready     = lsu_bready ;       
    assign  clint_master_arvalid    = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_arvalid : 0 : 0;        
    assign  clint_master_araddr     = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_araddr  : 0 : 0;      
    assign  clint_master_arid       = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_arid    : 0 : 0;  
    assign  clint_master_arlen      = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_arlen   : 0 : 0;    
    assign  clint_master_arsize     = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_arsize  : 0 : 0;      
    assign  clint_master_arburst    = (current_state == LSU_ADDR) ? (clint == 1'b1) ? lsu_arburst : 0 : 0;        
    assign  clint_master_rready     = (clint_master_rid == 4'h1) ? (clint == 1'b1) ? lsu_rready  : 0  : 0;      


endmodule
