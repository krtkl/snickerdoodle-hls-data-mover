// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module dataflow_in_loop66 (
        ap_clk,
        ap_rst,
        m_axi_tx_buffer_V_AWVALID,
        m_axi_tx_buffer_V_AWREADY,
        m_axi_tx_buffer_V_AWADDR,
        m_axi_tx_buffer_V_AWID,
        m_axi_tx_buffer_V_AWLEN,
        m_axi_tx_buffer_V_AWSIZE,
        m_axi_tx_buffer_V_AWBURST,
        m_axi_tx_buffer_V_AWLOCK,
        m_axi_tx_buffer_V_AWCACHE,
        m_axi_tx_buffer_V_AWPROT,
        m_axi_tx_buffer_V_AWQOS,
        m_axi_tx_buffer_V_AWREGION,
        m_axi_tx_buffer_V_AWUSER,
        m_axi_tx_buffer_V_WVALID,
        m_axi_tx_buffer_V_WREADY,
        m_axi_tx_buffer_V_WDATA,
        m_axi_tx_buffer_V_WSTRB,
        m_axi_tx_buffer_V_WLAST,
        m_axi_tx_buffer_V_WID,
        m_axi_tx_buffer_V_WUSER,
        m_axi_tx_buffer_V_ARVALID,
        m_axi_tx_buffer_V_ARREADY,
        m_axi_tx_buffer_V_ARADDR,
        m_axi_tx_buffer_V_ARID,
        m_axi_tx_buffer_V_ARLEN,
        m_axi_tx_buffer_V_ARSIZE,
        m_axi_tx_buffer_V_ARBURST,
        m_axi_tx_buffer_V_ARLOCK,
        m_axi_tx_buffer_V_ARCACHE,
        m_axi_tx_buffer_V_ARPROT,
        m_axi_tx_buffer_V_ARQOS,
        m_axi_tx_buffer_V_ARREGION,
        m_axi_tx_buffer_V_ARUSER,
        m_axi_tx_buffer_V_RVALID,
        m_axi_tx_buffer_V_RREADY,
        m_axi_tx_buffer_V_RDATA,
        m_axi_tx_buffer_V_RLAST,
        m_axi_tx_buffer_V_RID,
        m_axi_tx_buffer_V_RUSER,
        m_axi_tx_buffer_V_RRESP,
        m_axi_tx_buffer_V_BVALID,
        m_axi_tx_buffer_V_BREADY,
        m_axi_tx_buffer_V_BRESP,
        m_axi_tx_buffer_V_BID,
        m_axi_tx_buffer_V_BUSER,
        tx_buffer_V_offset,
        tx_buffer_V_offset1,
        val_assign,
        loop_count_V,
        final_burst_length_V,
        axis_V_V_TDATA,
        tx_buffer_V_offset_ap_vld,
        tx_buffer_V_offset1_ap_vld,
        val_assign_ap_vld,
        loop_count_V_ap_vld,
        final_burst_length_V_ap_vld,
        axis_V_V_TVALID,
        axis_V_V_TREADY,
        ap_done,
        ap_start,
        ap_ready,
        ap_idle,
        ap_continue
);


input   ap_clk;
input   ap_rst;
output   m_axi_tx_buffer_V_AWVALID;
input   m_axi_tx_buffer_V_AWREADY;
output  [31:0] m_axi_tx_buffer_V_AWADDR;
output  [0:0] m_axi_tx_buffer_V_AWID;
output  [31:0] m_axi_tx_buffer_V_AWLEN;
output  [2:0] m_axi_tx_buffer_V_AWSIZE;
output  [1:0] m_axi_tx_buffer_V_AWBURST;
output  [1:0] m_axi_tx_buffer_V_AWLOCK;
output  [3:0] m_axi_tx_buffer_V_AWCACHE;
output  [2:0] m_axi_tx_buffer_V_AWPROT;
output  [3:0] m_axi_tx_buffer_V_AWQOS;
output  [3:0] m_axi_tx_buffer_V_AWREGION;
output  [0:0] m_axi_tx_buffer_V_AWUSER;
output   m_axi_tx_buffer_V_WVALID;
input   m_axi_tx_buffer_V_WREADY;
output  [63:0] m_axi_tx_buffer_V_WDATA;
output  [7:0] m_axi_tx_buffer_V_WSTRB;
output   m_axi_tx_buffer_V_WLAST;
output  [0:0] m_axi_tx_buffer_V_WID;
output  [0:0] m_axi_tx_buffer_V_WUSER;
output   m_axi_tx_buffer_V_ARVALID;
input   m_axi_tx_buffer_V_ARREADY;
output  [31:0] m_axi_tx_buffer_V_ARADDR;
output  [0:0] m_axi_tx_buffer_V_ARID;
output  [31:0] m_axi_tx_buffer_V_ARLEN;
output  [2:0] m_axi_tx_buffer_V_ARSIZE;
output  [1:0] m_axi_tx_buffer_V_ARBURST;
output  [1:0] m_axi_tx_buffer_V_ARLOCK;
output  [3:0] m_axi_tx_buffer_V_ARCACHE;
output  [2:0] m_axi_tx_buffer_V_ARPROT;
output  [3:0] m_axi_tx_buffer_V_ARQOS;
output  [3:0] m_axi_tx_buffer_V_ARREGION;
output  [0:0] m_axi_tx_buffer_V_ARUSER;
input   m_axi_tx_buffer_V_RVALID;
output   m_axi_tx_buffer_V_RREADY;
input  [63:0] m_axi_tx_buffer_V_RDATA;
input   m_axi_tx_buffer_V_RLAST;
input  [0:0] m_axi_tx_buffer_V_RID;
input  [0:0] m_axi_tx_buffer_V_RUSER;
input  [1:0] m_axi_tx_buffer_V_RRESP;
input   m_axi_tx_buffer_V_BVALID;
output   m_axi_tx_buffer_V_BREADY;
input  [1:0] m_axi_tx_buffer_V_BRESP;
input  [0:0] m_axi_tx_buffer_V_BID;
input  [0:0] m_axi_tx_buffer_V_BUSER;
input  [28:0] tx_buffer_V_offset;
input  [0:0] tx_buffer_V_offset1;
input  [11:0] val_assign;
input  [11:0] loop_count_V;
input  [12:0] final_burst_length_V;
output  [7:0] axis_V_V_TDATA;
input   tx_buffer_V_offset_ap_vld;
input   tx_buffer_V_offset1_ap_vld;
input   val_assign_ap_vld;
input   loop_count_V_ap_vld;
input   final_burst_length_V_ap_vld;
output   axis_V_V_TVALID;
input   axis_V_V_TREADY;
output   ap_done;
input   ap_start;
output   ap_ready;
output   ap_idle;
input   ap_continue;

wire   [63:0] cache_V_i_q0;
wire   [63:0] cache_V_t_q0;
wire    read_burst_U0_ap_start;
wire    read_burst_U0_ap_done;
wire    read_burst_U0_ap_continue;
wire    read_burst_U0_ap_idle;
wire    read_burst_U0_ap_ready;
wire    read_burst_U0_m_axi_tx_buffer_V_AWVALID;
wire   [31:0] read_burst_U0_m_axi_tx_buffer_V_AWADDR;
wire   [0:0] read_burst_U0_m_axi_tx_buffer_V_AWID;
wire   [31:0] read_burst_U0_m_axi_tx_buffer_V_AWLEN;
wire   [2:0] read_burst_U0_m_axi_tx_buffer_V_AWSIZE;
wire   [1:0] read_burst_U0_m_axi_tx_buffer_V_AWBURST;
wire   [1:0] read_burst_U0_m_axi_tx_buffer_V_AWLOCK;
wire   [3:0] read_burst_U0_m_axi_tx_buffer_V_AWCACHE;
wire   [2:0] read_burst_U0_m_axi_tx_buffer_V_AWPROT;
wire   [3:0] read_burst_U0_m_axi_tx_buffer_V_AWQOS;
wire   [3:0] read_burst_U0_m_axi_tx_buffer_V_AWREGION;
wire   [0:0] read_burst_U0_m_axi_tx_buffer_V_AWUSER;
wire    read_burst_U0_m_axi_tx_buffer_V_WVALID;
wire   [63:0] read_burst_U0_m_axi_tx_buffer_V_WDATA;
wire   [7:0] read_burst_U0_m_axi_tx_buffer_V_WSTRB;
wire    read_burst_U0_m_axi_tx_buffer_V_WLAST;
wire   [0:0] read_burst_U0_m_axi_tx_buffer_V_WID;
wire   [0:0] read_burst_U0_m_axi_tx_buffer_V_WUSER;
wire    read_burst_U0_m_axi_tx_buffer_V_ARVALID;
wire   [31:0] read_burst_U0_m_axi_tx_buffer_V_ARADDR;
wire   [0:0] read_burst_U0_m_axi_tx_buffer_V_ARID;
wire   [31:0] read_burst_U0_m_axi_tx_buffer_V_ARLEN;
wire   [2:0] read_burst_U0_m_axi_tx_buffer_V_ARSIZE;
wire   [1:0] read_burst_U0_m_axi_tx_buffer_V_ARBURST;
wire   [1:0] read_burst_U0_m_axi_tx_buffer_V_ARLOCK;
wire   [3:0] read_burst_U0_m_axi_tx_buffer_V_ARCACHE;
wire   [2:0] read_burst_U0_m_axi_tx_buffer_V_ARPROT;
wire   [3:0] read_burst_U0_m_axi_tx_buffer_V_ARQOS;
wire   [3:0] read_burst_U0_m_axi_tx_buffer_V_ARREGION;
wire   [0:0] read_burst_U0_m_axi_tx_buffer_V_ARUSER;
wire    read_burst_U0_m_axi_tx_buffer_V_RREADY;
wire    read_burst_U0_m_axi_tx_buffer_V_BREADY;
wire   [8:0] read_burst_U0_cache_V_address0;
wire    read_burst_U0_cache_V_ce0;
wire    read_burst_U0_cache_V_we0;
wire   [63:0] read_burst_U0_cache_V_d0;
wire   [12:0] read_burst_U0_ap_return;
wire    ap_channel_done_data_length_V;
wire    data_length_V_full_n;
reg    ap_sync_reg_channel_write_data_length_V;
wire    ap_sync_channel_write_data_length_V;
wire    ap_channel_done_cache_V;
wire    read_burst_U0_cache_V_full_n;
reg    ap_sync_reg_channel_write_cache_V;
wire    ap_sync_channel_write_cache_V;
wire    tx_axis_words_U0_ap_start;
wire    tx_axis_words_U0_ap_done;
wire    tx_axis_words_U0_ap_continue;
wire    tx_axis_words_U0_ap_idle;
wire    tx_axis_words_U0_ap_ready;
wire   [8:0] tx_axis_words_U0_cache_V_address0;
wire    tx_axis_words_U0_cache_V_ce0;
wire   [7:0] tx_axis_words_U0_axis_V_V_TDATA;
wire    tx_axis_words_U0_axis_V_V_TVALID;
wire    ap_sync_continue;
wire    cache_V_i_full_n;
wire    cache_V_t_empty_n;
wire   [12:0] data_length_V_dout;
wire    data_length_V_empty_n;
wire    ap_sync_done;
wire    ap_sync_ready;
wire    read_burst_U0_start_full_n;
wire    read_burst_U0_start_write;
wire    tx_axis_words_U0_start_full_n;
wire    tx_axis_words_U0_start_write;

// power-on initialization
initial begin
#0 ap_sync_reg_channel_write_data_length_V = 1'b0;
#0 ap_sync_reg_channel_write_cache_V = 1'b0;
end

dataflow_in_loop6bkb #(
    .DataWidth( 64 ),
    .AddressRange( 512 ),
    .AddressWidth( 9 ))
cache_V_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .i_address0(read_burst_U0_cache_V_address0),
    .i_ce0(read_burst_U0_cache_V_ce0),
    .i_we0(read_burst_U0_cache_V_we0),
    .i_d0(read_burst_U0_cache_V_d0),
    .i_q0(cache_V_i_q0),
    .t_address0(tx_axis_words_U0_cache_V_address0),
    .t_ce0(tx_axis_words_U0_cache_V_ce0),
    .t_we0(1'b0),
    .t_d0(64'd0),
    .t_q0(cache_V_t_q0),
    .i_ce(1'b1),
    .t_ce(1'b1),
    .i_full_n(cache_V_i_full_n),
    .i_write(ap_channel_done_cache_V),
    .t_empty_n(cache_V_t_empty_n),
    .t_read(tx_axis_words_U0_ap_ready)
);

read_burst read_burst_U0(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(read_burst_U0_ap_start),
    .ap_done(read_burst_U0_ap_done),
    .ap_continue(read_burst_U0_ap_continue),
    .ap_idle(read_burst_U0_ap_idle),
    .ap_ready(read_burst_U0_ap_ready),
    .m_axi_tx_buffer_V_AWVALID(read_burst_U0_m_axi_tx_buffer_V_AWVALID),
    .m_axi_tx_buffer_V_AWREADY(1'b0),
    .m_axi_tx_buffer_V_AWADDR(read_burst_U0_m_axi_tx_buffer_V_AWADDR),
    .m_axi_tx_buffer_V_AWID(read_burst_U0_m_axi_tx_buffer_V_AWID),
    .m_axi_tx_buffer_V_AWLEN(read_burst_U0_m_axi_tx_buffer_V_AWLEN),
    .m_axi_tx_buffer_V_AWSIZE(read_burst_U0_m_axi_tx_buffer_V_AWSIZE),
    .m_axi_tx_buffer_V_AWBURST(read_burst_U0_m_axi_tx_buffer_V_AWBURST),
    .m_axi_tx_buffer_V_AWLOCK(read_burst_U0_m_axi_tx_buffer_V_AWLOCK),
    .m_axi_tx_buffer_V_AWCACHE(read_burst_U0_m_axi_tx_buffer_V_AWCACHE),
    .m_axi_tx_buffer_V_AWPROT(read_burst_U0_m_axi_tx_buffer_V_AWPROT),
    .m_axi_tx_buffer_V_AWQOS(read_burst_U0_m_axi_tx_buffer_V_AWQOS),
    .m_axi_tx_buffer_V_AWREGION(read_burst_U0_m_axi_tx_buffer_V_AWREGION),
    .m_axi_tx_buffer_V_AWUSER(read_burst_U0_m_axi_tx_buffer_V_AWUSER),
    .m_axi_tx_buffer_V_WVALID(read_burst_U0_m_axi_tx_buffer_V_WVALID),
    .m_axi_tx_buffer_V_WREADY(1'b0),
    .m_axi_tx_buffer_V_WDATA(read_burst_U0_m_axi_tx_buffer_V_WDATA),
    .m_axi_tx_buffer_V_WSTRB(read_burst_U0_m_axi_tx_buffer_V_WSTRB),
    .m_axi_tx_buffer_V_WLAST(read_burst_U0_m_axi_tx_buffer_V_WLAST),
    .m_axi_tx_buffer_V_WID(read_burst_U0_m_axi_tx_buffer_V_WID),
    .m_axi_tx_buffer_V_WUSER(read_burst_U0_m_axi_tx_buffer_V_WUSER),
    .m_axi_tx_buffer_V_ARVALID(read_burst_U0_m_axi_tx_buffer_V_ARVALID),
    .m_axi_tx_buffer_V_ARREADY(m_axi_tx_buffer_V_ARREADY),
    .m_axi_tx_buffer_V_ARADDR(read_burst_U0_m_axi_tx_buffer_V_ARADDR),
    .m_axi_tx_buffer_V_ARID(read_burst_U0_m_axi_tx_buffer_V_ARID),
    .m_axi_tx_buffer_V_ARLEN(read_burst_U0_m_axi_tx_buffer_V_ARLEN),
    .m_axi_tx_buffer_V_ARSIZE(read_burst_U0_m_axi_tx_buffer_V_ARSIZE),
    .m_axi_tx_buffer_V_ARBURST(read_burst_U0_m_axi_tx_buffer_V_ARBURST),
    .m_axi_tx_buffer_V_ARLOCK(read_burst_U0_m_axi_tx_buffer_V_ARLOCK),
    .m_axi_tx_buffer_V_ARCACHE(read_burst_U0_m_axi_tx_buffer_V_ARCACHE),
    .m_axi_tx_buffer_V_ARPROT(read_burst_U0_m_axi_tx_buffer_V_ARPROT),
    .m_axi_tx_buffer_V_ARQOS(read_burst_U0_m_axi_tx_buffer_V_ARQOS),
    .m_axi_tx_buffer_V_ARREGION(read_burst_U0_m_axi_tx_buffer_V_ARREGION),
    .m_axi_tx_buffer_V_ARUSER(read_burst_U0_m_axi_tx_buffer_V_ARUSER),
    .m_axi_tx_buffer_V_RVALID(m_axi_tx_buffer_V_RVALID),
    .m_axi_tx_buffer_V_RREADY(read_burst_U0_m_axi_tx_buffer_V_RREADY),
    .m_axi_tx_buffer_V_RDATA(m_axi_tx_buffer_V_RDATA),
    .m_axi_tx_buffer_V_RLAST(m_axi_tx_buffer_V_RLAST),
    .m_axi_tx_buffer_V_RID(m_axi_tx_buffer_V_RID),
    .m_axi_tx_buffer_V_RUSER(m_axi_tx_buffer_V_RUSER),
    .m_axi_tx_buffer_V_RRESP(m_axi_tx_buffer_V_RRESP),
    .m_axi_tx_buffer_V_BVALID(1'b0),
    .m_axi_tx_buffer_V_BREADY(read_burst_U0_m_axi_tx_buffer_V_BREADY),
    .m_axi_tx_buffer_V_BRESP(2'd0),
    .m_axi_tx_buffer_V_BID(1'd0),
    .m_axi_tx_buffer_V_BUSER(1'd0),
    .tx_buffer_V_offset(tx_buffer_V_offset),
    .tx_buffer_V_offset1(tx_buffer_V_offset1),
    .val_assign(val_assign),
    .loop_count_V(loop_count_V),
    .final_burst_length_V(final_burst_length_V),
    .cache_V_address0(read_burst_U0_cache_V_address0),
    .cache_V_ce0(read_burst_U0_cache_V_ce0),
    .cache_V_we0(read_burst_U0_cache_V_we0),
    .cache_V_d0(read_burst_U0_cache_V_d0),
    .ap_return(read_burst_U0_ap_return)
);

tx_axis_words tx_axis_words_U0(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(tx_axis_words_U0_ap_start),
    .ap_done(tx_axis_words_U0_ap_done),
    .ap_continue(tx_axis_words_U0_ap_continue),
    .ap_idle(tx_axis_words_U0_ap_idle),
    .ap_ready(tx_axis_words_U0_ap_ready),
    .cache_V_address0(tx_axis_words_U0_cache_V_address0),
    .cache_V_ce0(tx_axis_words_U0_cache_V_ce0),
    .cache_V_q0(cache_V_t_q0),
    .p_read(data_length_V_dout),
    .axis_V_V_TDATA(tx_axis_words_U0_axis_V_V_TDATA),
    .axis_V_V_TVALID(tx_axis_words_U0_axis_V_V_TVALID),
    .axis_V_V_TREADY(axis_V_V_TREADY)
);

fifo_w13_d2_A data_length_V_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .if_read_ce(1'b1),
    .if_write_ce(1'b1),
    .if_din(read_burst_U0_ap_return),
    .if_full_n(data_length_V_full_n),
    .if_write(ap_channel_done_data_length_V),
    .if_dout(data_length_V_dout),
    .if_empty_n(data_length_V_empty_n),
    .if_read(tx_axis_words_U0_ap_ready)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_sync_reg_channel_write_cache_V <= 1'b0;
    end else begin
        if (((read_burst_U0_ap_done & read_burst_U0_ap_continue) == 1'b1)) begin
            ap_sync_reg_channel_write_cache_V <= 1'b0;
        end else begin
            ap_sync_reg_channel_write_cache_V <= ap_sync_channel_write_cache_V;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_sync_reg_channel_write_data_length_V <= 1'b0;
    end else begin
        if (((read_burst_U0_ap_done & read_burst_U0_ap_continue) == 1'b1)) begin
            ap_sync_reg_channel_write_data_length_V <= 1'b0;
        end else begin
            ap_sync_reg_channel_write_data_length_V <= ap_sync_channel_write_data_length_V;
        end
    end
end

assign ap_channel_done_cache_V = (read_burst_U0_ap_done & (ap_sync_reg_channel_write_cache_V ^ 1'b1));

assign ap_channel_done_data_length_V = (read_burst_U0_ap_done & (ap_sync_reg_channel_write_data_length_V ^ 1'b1));

assign ap_done = tx_axis_words_U0_ap_done;

assign ap_idle = (tx_axis_words_U0_ap_idle & read_burst_U0_ap_idle & (data_length_V_empty_n ^ 1'b1) & (cache_V_t_empty_n ^ 1'b1));

assign ap_ready = read_burst_U0_ap_ready;

assign ap_sync_channel_write_cache_V = ((read_burst_U0_cache_V_full_n & ap_channel_done_cache_V) | ap_sync_reg_channel_write_cache_V);

assign ap_sync_channel_write_data_length_V = ((data_length_V_full_n & ap_channel_done_data_length_V) | ap_sync_reg_channel_write_data_length_V);

assign ap_sync_continue = ap_continue;

assign ap_sync_done = tx_axis_words_U0_ap_done;

assign ap_sync_ready = read_burst_U0_ap_ready;

assign axis_V_V_TDATA = tx_axis_words_U0_axis_V_V_TDATA;

assign axis_V_V_TVALID = tx_axis_words_U0_axis_V_V_TVALID;

assign m_axi_tx_buffer_V_ARADDR = read_burst_U0_m_axi_tx_buffer_V_ARADDR;

assign m_axi_tx_buffer_V_ARBURST = read_burst_U0_m_axi_tx_buffer_V_ARBURST;

assign m_axi_tx_buffer_V_ARCACHE = read_burst_U0_m_axi_tx_buffer_V_ARCACHE;

assign m_axi_tx_buffer_V_ARID = read_burst_U0_m_axi_tx_buffer_V_ARID;

assign m_axi_tx_buffer_V_ARLEN = read_burst_U0_m_axi_tx_buffer_V_ARLEN;

assign m_axi_tx_buffer_V_ARLOCK = read_burst_U0_m_axi_tx_buffer_V_ARLOCK;

assign m_axi_tx_buffer_V_ARPROT = read_burst_U0_m_axi_tx_buffer_V_ARPROT;

assign m_axi_tx_buffer_V_ARQOS = read_burst_U0_m_axi_tx_buffer_V_ARQOS;

assign m_axi_tx_buffer_V_ARREGION = read_burst_U0_m_axi_tx_buffer_V_ARREGION;

assign m_axi_tx_buffer_V_ARSIZE = read_burst_U0_m_axi_tx_buffer_V_ARSIZE;

assign m_axi_tx_buffer_V_ARUSER = read_burst_U0_m_axi_tx_buffer_V_ARUSER;

assign m_axi_tx_buffer_V_ARVALID = read_burst_U0_m_axi_tx_buffer_V_ARVALID;

assign m_axi_tx_buffer_V_AWADDR = 32'd0;

assign m_axi_tx_buffer_V_AWBURST = 2'd0;

assign m_axi_tx_buffer_V_AWCACHE = 4'd0;

assign m_axi_tx_buffer_V_AWID = 1'd0;

assign m_axi_tx_buffer_V_AWLEN = 32'd0;

assign m_axi_tx_buffer_V_AWLOCK = 2'd0;

assign m_axi_tx_buffer_V_AWPROT = 3'd0;

assign m_axi_tx_buffer_V_AWQOS = 4'd0;

assign m_axi_tx_buffer_V_AWREGION = 4'd0;

assign m_axi_tx_buffer_V_AWSIZE = 3'd0;

assign m_axi_tx_buffer_V_AWUSER = 1'd0;

assign m_axi_tx_buffer_V_AWVALID = 1'b0;

assign m_axi_tx_buffer_V_BREADY = 1'b0;

assign m_axi_tx_buffer_V_RREADY = read_burst_U0_m_axi_tx_buffer_V_RREADY;

assign m_axi_tx_buffer_V_WDATA = 64'd0;

assign m_axi_tx_buffer_V_WID = 1'd0;

assign m_axi_tx_buffer_V_WLAST = 1'b0;

assign m_axi_tx_buffer_V_WSTRB = 8'd0;

assign m_axi_tx_buffer_V_WUSER = 1'd0;

assign m_axi_tx_buffer_V_WVALID = 1'b0;

assign read_burst_U0_ap_continue = (ap_sync_channel_write_data_length_V & ap_sync_channel_write_cache_V);

assign read_burst_U0_ap_start = ap_start;

assign read_burst_U0_cache_V_full_n = cache_V_i_full_n;

assign read_burst_U0_start_full_n = 1'b1;

assign read_burst_U0_start_write = 1'b0;

assign tx_axis_words_U0_ap_continue = ap_continue;

assign tx_axis_words_U0_ap_start = (data_length_V_empty_n & cache_V_t_empty_n);

assign tx_axis_words_U0_start_full_n = 1'b1;

assign tx_axis_words_U0_start_write = 1'b0;

endmodule //dataflow_in_loop66
