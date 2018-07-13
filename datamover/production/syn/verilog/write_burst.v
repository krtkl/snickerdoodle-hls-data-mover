// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module write_burst (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_continue,
        ap_idle,
        ap_ready,
        cache_V_address0,
        cache_V_ce0,
        cache_V_q0,
        buffer_offset_V,
        m_axi_rx_buffer_V_AWVALID,
        m_axi_rx_buffer_V_AWREADY,
        m_axi_rx_buffer_V_AWADDR,
        m_axi_rx_buffer_V_AWID,
        m_axi_rx_buffer_V_AWLEN,
        m_axi_rx_buffer_V_AWSIZE,
        m_axi_rx_buffer_V_AWBURST,
        m_axi_rx_buffer_V_AWLOCK,
        m_axi_rx_buffer_V_AWCACHE,
        m_axi_rx_buffer_V_AWPROT,
        m_axi_rx_buffer_V_AWQOS,
        m_axi_rx_buffer_V_AWREGION,
        m_axi_rx_buffer_V_AWUSER,
        m_axi_rx_buffer_V_WVALID,
        m_axi_rx_buffer_V_WREADY,
        m_axi_rx_buffer_V_WDATA,
        m_axi_rx_buffer_V_WSTRB,
        m_axi_rx_buffer_V_WLAST,
        m_axi_rx_buffer_V_WID,
        m_axi_rx_buffer_V_WUSER,
        m_axi_rx_buffer_V_ARVALID,
        m_axi_rx_buffer_V_ARREADY,
        m_axi_rx_buffer_V_ARADDR,
        m_axi_rx_buffer_V_ARID,
        m_axi_rx_buffer_V_ARLEN,
        m_axi_rx_buffer_V_ARSIZE,
        m_axi_rx_buffer_V_ARBURST,
        m_axi_rx_buffer_V_ARLOCK,
        m_axi_rx_buffer_V_ARCACHE,
        m_axi_rx_buffer_V_ARPROT,
        m_axi_rx_buffer_V_ARQOS,
        m_axi_rx_buffer_V_ARREGION,
        m_axi_rx_buffer_V_ARUSER,
        m_axi_rx_buffer_V_RVALID,
        m_axi_rx_buffer_V_RREADY,
        m_axi_rx_buffer_V_RDATA,
        m_axi_rx_buffer_V_RLAST,
        m_axi_rx_buffer_V_RID,
        m_axi_rx_buffer_V_RUSER,
        m_axi_rx_buffer_V_RRESP,
        m_axi_rx_buffer_V_BVALID,
        m_axi_rx_buffer_V_BREADY,
        m_axi_rx_buffer_V_BRESP,
        m_axi_rx_buffer_V_BID,
        m_axi_rx_buffer_V_BUSER,
        rx_buffer_V_offset_dout,
        rx_buffer_V_offset_empty_n,
        rx_buffer_V_offset_read,
        rx_buffer_V_offset_c_dout,
        rx_buffer_V_offset_c_empty_n,
        rx_buffer_V_offset_c_read
);

parameter    ap_ST_fsm_state1 = 8'd1;
parameter    ap_ST_fsm_state2 = 8'd2;
parameter    ap_ST_fsm_pp0_stage0 = 8'd4;
parameter    ap_ST_fsm_state6 = 8'd8;
parameter    ap_ST_fsm_state7 = 8'd16;
parameter    ap_ST_fsm_state8 = 8'd32;
parameter    ap_ST_fsm_state9 = 8'd64;
parameter    ap_ST_fsm_state10 = 8'd128;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
input   ap_continue;
output   ap_idle;
output   ap_ready;
output  [8:0] cache_V_address0;
output   cache_V_ce0;
input  [63:0] cache_V_q0;
input  [19:0] buffer_offset_V;
output   m_axi_rx_buffer_V_AWVALID;
input   m_axi_rx_buffer_V_AWREADY;
output  [31:0] m_axi_rx_buffer_V_AWADDR;
output  [0:0] m_axi_rx_buffer_V_AWID;
output  [31:0] m_axi_rx_buffer_V_AWLEN;
output  [2:0] m_axi_rx_buffer_V_AWSIZE;
output  [1:0] m_axi_rx_buffer_V_AWBURST;
output  [1:0] m_axi_rx_buffer_V_AWLOCK;
output  [3:0] m_axi_rx_buffer_V_AWCACHE;
output  [2:0] m_axi_rx_buffer_V_AWPROT;
output  [3:0] m_axi_rx_buffer_V_AWQOS;
output  [3:0] m_axi_rx_buffer_V_AWREGION;
output  [0:0] m_axi_rx_buffer_V_AWUSER;
output   m_axi_rx_buffer_V_WVALID;
input   m_axi_rx_buffer_V_WREADY;
output  [63:0] m_axi_rx_buffer_V_WDATA;
output  [7:0] m_axi_rx_buffer_V_WSTRB;
output   m_axi_rx_buffer_V_WLAST;
output  [0:0] m_axi_rx_buffer_V_WID;
output  [0:0] m_axi_rx_buffer_V_WUSER;
output   m_axi_rx_buffer_V_ARVALID;
input   m_axi_rx_buffer_V_ARREADY;
output  [31:0] m_axi_rx_buffer_V_ARADDR;
output  [0:0] m_axi_rx_buffer_V_ARID;
output  [31:0] m_axi_rx_buffer_V_ARLEN;
output  [2:0] m_axi_rx_buffer_V_ARSIZE;
output  [1:0] m_axi_rx_buffer_V_ARBURST;
output  [1:0] m_axi_rx_buffer_V_ARLOCK;
output  [3:0] m_axi_rx_buffer_V_ARCACHE;
output  [2:0] m_axi_rx_buffer_V_ARPROT;
output  [3:0] m_axi_rx_buffer_V_ARQOS;
output  [3:0] m_axi_rx_buffer_V_ARREGION;
output  [0:0] m_axi_rx_buffer_V_ARUSER;
input   m_axi_rx_buffer_V_RVALID;
output   m_axi_rx_buffer_V_RREADY;
input  [63:0] m_axi_rx_buffer_V_RDATA;
input   m_axi_rx_buffer_V_RLAST;
input  [0:0] m_axi_rx_buffer_V_RID;
input  [0:0] m_axi_rx_buffer_V_RUSER;
input  [1:0] m_axi_rx_buffer_V_RRESP;
input   m_axi_rx_buffer_V_BVALID;
output   m_axi_rx_buffer_V_BREADY;
input  [1:0] m_axi_rx_buffer_V_BRESP;
input  [0:0] m_axi_rx_buffer_V_BID;
input  [0:0] m_axi_rx_buffer_V_BUSER;
input  [28:0] rx_buffer_V_offset_dout;
input   rx_buffer_V_offset_empty_n;
output   rx_buffer_V_offset_read;
input  [0:0] rx_buffer_V_offset_c_dout;
input   rx_buffer_V_offset_c_empty_n;
output   rx_buffer_V_offset_c_read;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg cache_V_ce0;
reg m_axi_rx_buffer_V_AWVALID;
reg m_axi_rx_buffer_V_WVALID;
reg m_axi_rx_buffer_V_BREADY;
reg rx_buffer_V_offset_read;
reg rx_buffer_V_offset_c_read;

reg    ap_done_reg;
(* fsm_encoding = "none" *) reg   [7:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    rx_buffer_V_blk_n_AW;
wire    ap_CS_fsm_state2;
reg    rx_buffer_V_blk_n_W;
reg    ap_enable_reg_pp0_iter2;
wire    ap_block_pp0_stage0;
reg   [0:0] exitcond_i_i_i_i_reg_215;
reg   [0:0] exitcond_i_i_i_i_reg_215_pp0_iter1_reg;
reg    rx_buffer_V_blk_n_B;
wire    ap_CS_fsm_state10;
reg    rx_buffer_V_offset_blk_n;
reg    rx_buffer_V_offset_c_blk_n;
reg   [9:0] indvar_i_i_i_i_reg_144;
wire   [29:0] sum_i_i_fu_171_p2;
reg   [29:0] sum_i_i_reg_204;
reg    ap_block_state1;
reg    ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY;
wire   [0:0] exitcond_i_i_i_i_fu_187_p2;
wire    ap_CS_fsm_pp0_stage0;
wire    ap_block_state3_pp0_stage0_iter0;
wire    ap_block_state4_pp0_stage0_iter1;
wire    ap_block_state5_pp0_stage0_iter2;
reg    ap_sig_ioackin_m_axi_rx_buffer_V_WREADY;
reg    ap_block_state5_io;
reg    ap_block_pp0_stage0_11001;
wire   [9:0] indvar_next_i_i_i_i_fu_193_p2;
reg    ap_enable_reg_pp0_iter0;
reg   [63:0] cache_V_load_reg_229;
reg    ap_block_pp0_stage0_subdone;
reg    ap_condition_pp0_exit_iter0_state3;
reg    ap_enable_reg_pp0_iter1;
wire   [63:0] indvar4_i_i_i_i_fu_199_p1;
wire   [63:0] sum_cast_i_i_fu_177_p1;
reg    ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY;
reg    ap_reg_ioackin_m_axi_rx_buffer_V_WREADY;
wire    ap_block_pp0_stage0_01001;
wire   [20:0] tmp_2_i_i_fu_155_p3;
wire   [29:0] tmp_3_cast_i_i_fu_163_p1;
wire   [29:0] sext_cast_i_i_fu_167_p1;
reg   [7:0] ap_NS_fsm;
reg    ap_idle_pp0;
wire    ap_enable_pp0;

// power-on initialization
initial begin
#0 ap_done_reg = 1'b0;
#0 ap_CS_fsm = 8'd1;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
#0 ap_enable_reg_pp0_iter0 = 1'b0;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY = 1'b0;
#0 ap_reg_ioackin_m_axi_rx_buffer_V_WREADY = 1'b0;
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((m_axi_rx_buffer_V_BVALID == 1'b1) & (1'b1 == ap_CS_fsm_state10))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter0 <= 1'b0;
    end else begin
        if (((1'b1 == ap_condition_pp0_exit_iter0_state3) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
            ap_enable_reg_pp0_iter0 <= 1'b0;
        end else if (((1'b1 == ap_CS_fsm_state2) & (ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY == 1'b1))) begin
            ap_enable_reg_pp0_iter0 <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            if ((1'b1 == ap_condition_pp0_exit_iter0_state3)) begin
                ap_enable_reg_pp0_iter1 <= (1'b1 ^ ap_condition_pp0_exit_iter0_state3);
            end else if ((1'b1 == 1'b1)) begin
                ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
            end
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end else if (((1'b1 == ap_CS_fsm_state2) & (ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY == 1'b1))) begin
            ap_enable_reg_pp0_iter2 <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY <= 1'b0;
    end else begin
        if ((1'b1 == ap_CS_fsm_state2)) begin
            if ((ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY == 1'b1)) begin
                ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY <= 1'b0;
            end else if ((m_axi_rx_buffer_V_AWREADY == 1'b1)) begin
                ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY <= 1'b1;
            end
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_reg_ioackin_m_axi_rx_buffer_V_WREADY <= 1'b0;
    end else begin
        if (((exitcond_i_i_i_i_reg_215_pp0_iter1_reg == 1'd0) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
            if ((1'b0 == ap_block_pp0_stage0_11001)) begin
                ap_reg_ioackin_m_axi_rx_buffer_V_WREADY <= 1'b0;
            end else if (((1'b0 == ap_block_pp0_stage0_01001) & (m_axi_rx_buffer_V_WREADY == 1'b1))) begin
                ap_reg_ioackin_m_axi_rx_buffer_V_WREADY <= 1'b1;
            end
        end
    end
end

always @ (posedge ap_clk) begin
    if (((exitcond_i_i_i_i_fu_187_p2 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        indvar_i_i_i_i_reg_144 <= indvar_next_i_i_i_i_fu_193_p2;
    end else if (((1'b1 == ap_CS_fsm_state2) & (ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY == 1'b1))) begin
        indvar_i_i_i_i_reg_144 <= 10'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((exitcond_i_i_i_i_reg_215 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        cache_V_load_reg_229 <= cache_V_q0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        exitcond_i_i_i_i_reg_215 <= exitcond_i_i_i_i_fu_187_p2;
        exitcond_i_i_i_i_reg_215_pp0_iter1_reg <= exitcond_i_i_i_i_reg_215;
    end
end

always @ (posedge ap_clk) begin
    if ((~((rx_buffer_V_offset_c_empty_n == 1'b0) | (rx_buffer_V_offset_empty_n == 1'b0) | (ap_start == 1'b0) | (ap_done_reg == 1'b1)) & (1'b1 == ap_CS_fsm_state1))) begin
        sum_i_i_reg_204 <= sum_i_i_fu_171_p2;
    end
end

always @ (*) begin
    if ((exitcond_i_i_i_i_fu_187_p2 == 1'd1)) begin
        ap_condition_pp0_exit_iter0_state3 = 1'b1;
    end else begin
        ap_condition_pp0_exit_iter0_state3 = 1'b0;
    end
end

always @ (*) begin
    if (((m_axi_rx_buffer_V_BVALID == 1'b1) & (1'b1 == ap_CS_fsm_state10))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = ap_done_reg;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((m_axi_rx_buffer_V_BVALID == 1'b1) & (1'b1 == ap_CS_fsm_state10))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY == 1'b0)) begin
        ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY = m_axi_rx_buffer_V_AWREADY;
    end else begin
        ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY = 1'b1;
    end
end

always @ (*) begin
    if ((ap_reg_ioackin_m_axi_rx_buffer_V_WREADY == 1'b0)) begin
        ap_sig_ioackin_m_axi_rx_buffer_V_WREADY = m_axi_rx_buffer_V_WREADY;
    end else begin
        ap_sig_ioackin_m_axi_rx_buffer_V_WREADY = 1'b1;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        cache_V_ce0 = 1'b1;
    end else begin
        cache_V_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY == 1'b0) & (1'b1 == ap_CS_fsm_state2))) begin
        m_axi_rx_buffer_V_AWVALID = 1'b1;
    end else begin
        m_axi_rx_buffer_V_AWVALID = 1'b0;
    end
end

always @ (*) begin
    if (((m_axi_rx_buffer_V_BVALID == 1'b1) & (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_rx_buffer_V_BREADY = 1'b1;
    end else begin
        m_axi_rx_buffer_V_BREADY = 1'b0;
    end
end

always @ (*) begin
    if (((exitcond_i_i_i_i_reg_215_pp0_iter1_reg == 1'd0) & (ap_reg_ioackin_m_axi_rx_buffer_V_WREADY == 1'b0) & (1'b0 == ap_block_pp0_stage0_01001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        m_axi_rx_buffer_V_WVALID = 1'b1;
    end else begin
        m_axi_rx_buffer_V_WVALID = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        rx_buffer_V_blk_n_AW = m_axi_rx_buffer_V_AWREADY;
    end else begin
        rx_buffer_V_blk_n_AW = 1'b1;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state10)) begin
        rx_buffer_V_blk_n_B = m_axi_rx_buffer_V_BVALID;
    end else begin
        rx_buffer_V_blk_n_B = 1'b1;
    end
end

always @ (*) begin
    if (((exitcond_i_i_i_i_reg_215_pp0_iter1_reg == 1'd0) & (ap_enable_reg_pp0_iter2 == 1'b1) & (1'b0 == ap_block_pp0_stage0))) begin
        rx_buffer_V_blk_n_W = m_axi_rx_buffer_V_WREADY;
    end else begin
        rx_buffer_V_blk_n_W = 1'b1;
    end
end

always @ (*) begin
    if ((~((ap_start == 1'b0) | (ap_done_reg == 1'b1)) & (1'b1 == ap_CS_fsm_state1))) begin
        rx_buffer_V_offset_blk_n = rx_buffer_V_offset_empty_n;
    end else begin
        rx_buffer_V_offset_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((ap_start == 1'b0) | (ap_done_reg == 1'b1)) & (1'b1 == ap_CS_fsm_state1))) begin
        rx_buffer_V_offset_c_blk_n = rx_buffer_V_offset_c_empty_n;
    end else begin
        rx_buffer_V_offset_c_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((rx_buffer_V_offset_c_empty_n == 1'b0) | (rx_buffer_V_offset_empty_n == 1'b0) | (ap_start == 1'b0) | (ap_done_reg == 1'b1)) & (1'b1 == ap_CS_fsm_state1))) begin
        rx_buffer_V_offset_c_read = 1'b1;
    end else begin
        rx_buffer_V_offset_c_read = 1'b0;
    end
end

always @ (*) begin
    if ((~((rx_buffer_V_offset_c_empty_n == 1'b0) | (rx_buffer_V_offset_empty_n == 1'b0) | (ap_start == 1'b0) | (ap_done_reg == 1'b1)) & (1'b1 == ap_CS_fsm_state1))) begin
        rx_buffer_V_offset_read = 1'b1;
    end else begin
        rx_buffer_V_offset_read = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if ((~((rx_buffer_V_offset_c_empty_n == 1'b0) | (rx_buffer_V_offset_empty_n == 1'b0) | (ap_start == 1'b0) | (ap_done_reg == 1'b1)) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((1'b1 == ap_CS_fsm_state2) & (ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        ap_ST_fsm_pp0_stage0 : begin
            if ((~((ap_enable_reg_pp0_iter0 == 1'b1) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone) & (exitcond_i_i_i_i_fu_187_p2 == 1'd1)) & ~((ap_enable_reg_pp0_iter2 == 1'b1) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone)))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else if ((((ap_enable_reg_pp0_iter0 == 1'b1) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone) & (exitcond_i_i_i_i_fu_187_p2 == 1'd1)) | ((ap_enable_reg_pp0_iter2 == 1'b1) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone)))) begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_state6 : begin
            ap_NS_fsm = ap_ST_fsm_state7;
        end
        ap_ST_fsm_state7 : begin
            ap_NS_fsm = ap_ST_fsm_state8;
        end
        ap_ST_fsm_state8 : begin
            ap_NS_fsm = ap_ST_fsm_state9;
        end
        ap_ST_fsm_state9 : begin
            ap_NS_fsm = ap_ST_fsm_state10;
        end
        ap_ST_fsm_state10 : begin
            if (((m_axi_rx_buffer_V_BVALID == 1'b1) & (1'b1 == ap_CS_fsm_state10))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state10;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state10 = ap_CS_fsm[32'd7];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_01001 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_pp0_stage0_11001 = ((1'b1 == ap_block_state5_io) & (ap_enable_reg_pp0_iter2 == 1'b1));
end

always @ (*) begin
    ap_block_pp0_stage0_subdone = ((1'b1 == ap_block_state5_io) & (ap_enable_reg_pp0_iter2 == 1'b1));
end

always @ (*) begin
    ap_block_state1 = ((rx_buffer_V_offset_c_empty_n == 1'b0) | (rx_buffer_V_offset_empty_n == 1'b0) | (ap_start == 1'b0) | (ap_done_reg == 1'b1));
end

assign ap_block_state3_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state4_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state5_io = ((exitcond_i_i_i_i_reg_215_pp0_iter1_reg == 1'd0) & (ap_sig_ioackin_m_axi_rx_buffer_V_WREADY == 1'b0));
end

assign ap_block_state5_pp0_stage0_iter2 = ~(1'b1 == 1'b1);

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign cache_V_address0 = indvar4_i_i_i_i_fu_199_p1;

assign exitcond_i_i_i_i_fu_187_p2 = ((indvar_i_i_i_i_reg_144 == 10'd512) ? 1'b1 : 1'b0);

assign indvar4_i_i_i_i_fu_199_p1 = indvar_i_i_i_i_reg_144;

assign indvar_next_i_i_i_i_fu_193_p2 = (indvar_i_i_i_i_reg_144 + 10'd1);

assign m_axi_rx_buffer_V_ARADDR = 32'd0;

assign m_axi_rx_buffer_V_ARBURST = 2'd0;

assign m_axi_rx_buffer_V_ARCACHE = 4'd0;

assign m_axi_rx_buffer_V_ARID = 1'd0;

assign m_axi_rx_buffer_V_ARLEN = 32'd0;

assign m_axi_rx_buffer_V_ARLOCK = 2'd0;

assign m_axi_rx_buffer_V_ARPROT = 3'd0;

assign m_axi_rx_buffer_V_ARQOS = 4'd0;

assign m_axi_rx_buffer_V_ARREGION = 4'd0;

assign m_axi_rx_buffer_V_ARSIZE = 3'd0;

assign m_axi_rx_buffer_V_ARUSER = 1'd0;

assign m_axi_rx_buffer_V_ARVALID = 1'b0;

assign m_axi_rx_buffer_V_AWADDR = sum_cast_i_i_fu_177_p1;

assign m_axi_rx_buffer_V_AWBURST = 2'd0;

assign m_axi_rx_buffer_V_AWCACHE = 4'd0;

assign m_axi_rx_buffer_V_AWID = 1'd0;

assign m_axi_rx_buffer_V_AWLEN = 32'd512;

assign m_axi_rx_buffer_V_AWLOCK = 2'd0;

assign m_axi_rx_buffer_V_AWPROT = 3'd0;

assign m_axi_rx_buffer_V_AWQOS = 4'd0;

assign m_axi_rx_buffer_V_AWREGION = 4'd0;

assign m_axi_rx_buffer_V_AWSIZE = 3'd0;

assign m_axi_rx_buffer_V_AWUSER = 1'd0;

assign m_axi_rx_buffer_V_RREADY = 1'b0;

assign m_axi_rx_buffer_V_WDATA = cache_V_load_reg_229;

assign m_axi_rx_buffer_V_WID = 1'd0;

assign m_axi_rx_buffer_V_WLAST = 1'b0;

assign m_axi_rx_buffer_V_WSTRB = 8'd255;

assign m_axi_rx_buffer_V_WUSER = 1'd0;

assign sext_cast_i_i_fu_167_p1 = rx_buffer_V_offset_dout;

assign sum_cast_i_i_fu_177_p1 = sum_i_i_reg_204;

assign sum_i_i_fu_171_p2 = (tmp_3_cast_i_i_fu_163_p1 + sext_cast_i_i_fu_167_p1);

assign tmp_2_i_i_fu_155_p3 = {{rx_buffer_V_offset_c_dout}, {buffer_offset_V}};

assign tmp_3_cast_i_i_fu_163_p1 = tmp_2_i_i_fu_155_p3;

endmodule //write_burst
