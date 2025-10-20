module vga_top_apb(
  input         clock,
  input         reset,
  input  [31:0] in_paddr,
  input         in_psel,
  input         in_penable,
  input  [2:0]  in_pprot,
  input         in_pwrite,
  input  [31:0] in_pwdata,
  input  [3:0]  in_pstrb,
  output        in_pready,
  output [31:0] in_prdata,
  output        in_pslverr,

  output [7:0]  vga_r,
  output [7:0]  vga_g,
  output [7:0]  vga_b,
  output        vga_hsync,
  output        vga_vsync,
  output        vga_valid
);

  localparam N = 2 ** 21;
  reg sync_reg;

  localparam h_sync       = 96;
  localparam h_active     = 48;
  localparam h_back       = 16;
  localparam h_disp       = 640;
  localparam h_total      = 800;
  localparam v_sync       = 2;
  localparam v_active     = 35;
  localparam v_back       = 10;
  localparam v_disp       = 480;
  localparam v_total      = 525;

  reg [ 9:0] h_cnt;
  reg [ 9:0] v_cnt;
  reg [20:0] counter;
  reg [31:0] data[0:N-1];
  wire h_valid;
  wire v_valid;

  always @(posedge clock or posedge reset) begin
    if (reset) begin
      h_cnt <= 0;
    end else begin
      if (h_cnt == h_total) begin
        if (v_cnt == v_total) begin
          h_cnt <= 0;
        end else begin
          h_cnt <= 1;
        end
      end else if (h_cnt > 0) begin
        h_cnt <= h_cnt + 1;
      end else begin
        if (sync_reg) begin
          h_cnt <= 1;
        end
      end
    end
  end

  always @(posedge clock or posedge reset) begin
    if (reset) begin
      v_cnt <= 1;
    end else begin
      if (h_cnt == h_total) begin
        if (v_cnt == v_total) begin
          v_cnt <= 1;
        end else begin
          v_cnt <= v_cnt + 1;
        end
      end
    end
  end

  always @(posedge clock or posedge reset) begin
    if (reset) begin
      counter <= 0;
    end else begin
      if (v_cnt == v_total) begin
        counter <= 0;
      end else if (vga_valid) begin
        counter <= counter + 1;
      end else begin
        counter <= counter;
      end
    end
  end

  localparam IDLE  = 2'b0;
  localparam WRITE = 2'b1;
  reg [1:0] state;

  assign in_pready  = (state == WRITE) ? 1'b1 : 1'b0;
  assign in_prdata  = 32'b0;
  assign in_pslverr = 1'b0;

  always @(posedge clock) begin
    if (reset) begin
      state <= IDLE;
    end else begin
      case (state)
        IDLE: begin
          if (in_psel && in_pwrite) begin
            state <= WRITE;
          end
        end
        WRITE: begin
          state <= IDLE;
        end
        default: begin
          state <= IDLE;
        end
      endcase
    end
  end

  always @(posedge clock or posedge reset) begin
    if (reset) begin
      sync_reg <= 1'b0;
    end else begin
      if (in_penable) begin
        if (in_paddr == 32'h211FFFF4) begin
          sync_reg <= in_pwdata[0];
        end else begin
          data[in_paddr[22:2]] <= in_pwdata;
          sync_reg <= 1'b0;
        end
      end
    end
  end

  assign vga_hsync = (h_cnt > h_sync);
  assign vga_vsync = (v_cnt > v_sync);

  assign h_valid   = (h_cnt > h_sync + h_active) & (h_cnt <= h_sync + h_active + h_disp);
  assign v_valid   = (v_cnt > v_sync + v_active) & (v_cnt <= v_sync + v_active + v_disp);
  assign vga_valid = h_valid & v_valid;

  assign vga_r     = vga_valid ? data[counter][23:16] : 8'h00;
  assign vga_g     = vga_valid ? data[counter][15: 8] : 8'h00;
  assign vga_b     = vga_valid ? data[counter][ 7: 0] : 8'h00;

endmodule
