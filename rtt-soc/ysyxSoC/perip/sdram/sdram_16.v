module sdram_16(
  input        clk,
  input        cke,
  input        cs,
  input        ras,
  input        cas,
  input        we,
  input [12:0] a,
  input [ 1:0] ba,
  input [ 1:0] dqm,
  inout [15:0] dq
);

  localparam CMD_NOP       = 3'b111;
  localparam CMD_ACTIVE    = 3'b011;
  localparam CMD_READ      = 3'b101;
  localparam CMD_WRITE     = 3'b100;
  localparam CMD_TERMINATE = 3'b110;
  localparam CMD_PRECHARGE = 3'b010;
  localparam CMD_REFRESH   = 3'b001;
  localparam CMD_MODE      = 3'b000;

  localparam BANK_SIZE     = 8192*512;

  reg  [15:0] bank[0:3][0:BANK_SIZE-1];
  reg  [12:0] Line_addr[0:3];

  wire [15:0] dout_en;
  reg  [15:0] dout;
  wire [15:0] din;
  assign din = dq;

  genvar i;
  generate
    for (i = 0; i < 16; i = i + 1) begin
      assign dq[i] = dout_en[i] ? dout[i] : 1'bz;
    end
  endgenerate

  reg  [ 2:0] CAS_Latency;
  reg  [ 2:0] Brust_Length;
  wire [ 2:0] cmd = {ras, cas, we};

  reg  [ 1:0] L_bank;
  reg         dqm_bufL;
  reg         dqm_bufH;


  reg  [ 3:0] r_cnt;
  reg  [ 3:0] w_cnt;
  reg         read_en;
  reg  [ 8:0] r_addr;
  reg  [ 8:0] w_addr;
  reg  [15:0] w_data;
  wire [21:0] r_sdram_addr = {Line_addr[L_bank], r_addr};
  wire [21:0] w_sdram_addr = {Line_addr[L_bank], w_addr};
  wire [ 3:0] length = (Brust_Length == 3'b011) ? 4'd8 :
                       (Brust_Length == 3'b010) ? 4'd4 :
                       (Brust_Length == 3'b001) ? 4'd2 :4'd1;

  assign dout_en = read_en ? 16'hffff : 16'b0;

  always @(posedge clk) begin
    if (!cke) begin
      Line_addr[0] <= 13'b0;
      Line_addr[1] <= 13'b0;
      Line_addr[2] <= 13'b0;
      Line_addr[3] <= 13'b0;
    end else if (!cs & (cmd == CMD_ACTIVE)) begin
      Line_addr[ba] = a;
    end
  end

  always @(posedge clk) begin
    if (!cke) begin
      L_bank <= 2'b0;
    end else if (!cs & (cmd == CMD_ACTIVE | cmd == CMD_READ | cmd == CMD_WRITE)) begin
      L_bank <= ba;
    end
  end


  always @(posedge clk) begin
    if (!cke) begin
      CAS_Latency  <= 3'b0;
      Brust_Length <= 3'b0;
    end else if (!cs & (cmd == CMD_MODE)) begin
      CAS_Latency  <= a[6:4];
      Brust_Length <= a[2:0];
    end
  end

  always @(posedge clk) begin
    if (!cke) begin
      dqm_bufL <= 1'b0;
      dqm_bufH <= 1'b0;
    end else if (!cs) begin
      dqm_bufL <= dqm[0];
      dqm_bufH <= dqm[1];
    end
  end

  always @(posedge clk) begin
    if (!cke) begin
      r_cnt   <= 4'b0;
      r_addr  <= 9'b0;
      read_en <= 1'b0;
    end else if (!cs) begin
      if (cmd == CMD_READ) begin
        r_cnt   <= r_cnt + 1;
        r_addr  <= a[8:0];
        read_en <= 1'b1;
      end else if ((r_cnt > 0) && (r_cnt < {1'b0, CAS_Latency} - 1)) begin
        r_cnt   <= r_cnt + 1;
        read_en <= 1'b1;
      end else if (r_cnt >= {1'b0, CAS_Latency} - 1) begin
        r_cnt   <= (r_cnt < length + CAS_Latency - 1) ? r_cnt + 1 : 4'b0;
        r_addr  <= r_addr + 1;
        read_en <= 1'b1;
      end else begin
        r_cnt   <= 4'b0;
        r_addr  <= 9'b0;
        read_en <= 1'b0;
      end
    end else begin
      r_cnt   <= 4'b0;
      r_addr  <= 9'b0;
      read_en <= 1'b0;
      dout    <= 16'b0;
    end
  end
  
  always @(posedge clk) begin
    if (!cke) begin
      dout <= 16'b0;
    end else if (!cs) begin
      if (r_cnt >= {1'b0, CAS_Latency} - 1) begin
        dout[15:8] <= bank[L_bank][r_sdram_addr][15:8];
        dout[ 7:0] <= bank[L_bank][r_sdram_addr][ 7:0];
      end else begin
        dout <= 16'b0;
      end

      if (w_cnt > 0) begin
        bank[L_bank][w_sdram_addr][15:8] <= (!dqm_bufH) ? w_data[15:8] : bank[L_bank][w_sdram_addr][15:8];
        bank[L_bank][w_sdram_addr][ 7:0] <= (!dqm_bufL) ? w_data[ 7:0] : bank[L_bank][w_sdram_addr][ 7:0];
      end
    end else begin
      dout <= 16'b0;
    end
  end

  always @(posedge clk) begin
    if (!cke) begin
      w_cnt  <= 4'b0;
      w_addr <= 9'b0;
      w_data <= 16'b0;
    end else if (!cs) begin
      if (cmd == CMD_WRITE) begin
        w_cnt  <= w_cnt + 1;
        w_addr <= a[8:0];
        w_data <= din;
      end else if (w_cnt > 0) begin
        w_cnt  <= (w_cnt < length) ? w_cnt + 1 : 4'b0;
        w_addr <= w_addr + 1;
        w_data <= din;
      end else begin
        w_cnt  <= 4'b0;
        w_addr <= 9'b0;
        w_data <= 16'b0;
      end
    end
  end

endmodule
