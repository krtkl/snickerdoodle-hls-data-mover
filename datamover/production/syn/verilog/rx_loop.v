// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module rx_loop (
        axis_V_V_TDATA,
        loop_count_V,
        final_burst_length_V,
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
        rx_buffer_V_offset,
        rx_buffer_V_offset1,
        ap_clk,
        ap_rst,
        axis_V_V_TVALID,
        axis_V_V_TREADY,
        loop_count_V_ap_vld,
        final_burst_length_V_ap_vld,
        rx_buffer_V_offset_ap_vld,
        rx_buffer_V_offset1_ap_vld,
        ap_done,
        ap_start,
        ap_ready,
        ap_idle,
        ap_continue
);


input  [7:0] axis_V_V_TDATA;
input  [11:0] loop_count_V;
input  [12:0] final_burst_length_V;
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
input  [28:0] rx_buffer_V_offset;
input  [0:0] rx_buffer_V_offset1;
input   ap_clk;
input   ap_rst;
input   axis_V_V_TVALID;
output   axis_V_V_TREADY;
input   loop_count_V_ap_vld;
input   final_burst_length_V_ap_vld;
input   rx_buffer_V_offset_ap_vld;
input   rx_buffer_V_offset1_ap_vld;
output   ap_done;
input   ap_start;
output   ap_ready;
output   ap_idle;
input   ap_continue;

reg ap_done;
reg ap_ready;

wire    dataflow_in_loop_U0_m_axi_rx_buffer_V_AWVALID;
wire   [31:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_AWADDR;
wire   [0:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_AWID;
wire   [31:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_AWLEN;
wire   [2:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_AWSIZE;
wire   [1:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_AWBURST;
wire   [1:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_AWLOCK;
wire   [3:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_AWCACHE;
wire   [2:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_AWPROT;
wire   [3:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_AWQOS;
wire   [3:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_AWREGION;
wire   [0:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_AWUSER;
wire    dataflow_in_loop_U0_m_axi_rx_buffer_V_WVALID;
wire   [63:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_WDATA;
wire   [7:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_WSTRB;
wire    dataflow_in_loop_U0_m_axi_rx_buffer_V_WLAST;
wire   [0:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_WID;
wire   [0:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_WUSER;
wire    dataflow_in_loop_U0_m_axi_rx_buffer_V_ARVALID;
wire   [31:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_ARADDR;
wire   [0:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_ARID;
wire   [31:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_ARLEN;
wire   [2:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_ARSIZE;
wire   [1:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_ARBURST;
wire   [1:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_ARLOCK;
wire   [3:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_ARCACHE;
wire   [2:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_ARPROT;
wire   [3:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_ARQOS;
wire   [3:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_ARREGION;
wire   [0:0] dataflow_in_loop_U0_m_axi_rx_buffer_V_ARUSER;
wire    dataflow_in_loop_U0_m_axi_rx_buffer_V_RREADY;
wire    dataflow_in_loop_U0_m_axi_rx_buffer_V_BREADY;
wire    dataflow_in_loop_U0_axis_V_V_TREADY;
wire    dataflow_in_loop_U0_ap_done;
reg    dataflow_in_loop_U0_ap_start;
wire    dataflow_in_loop_U0_ap_ready;
wire    dataflow_in_loop_U0_ap_idle;
wire    dataflow_in_loop_U0_ap_continue;
wire    ap_sync_continue;
wire    ap_sync_done;
wire    ap_sync_ready;
reg    loop_dataflow_enable;
reg   [11:0] loop_dataflow_input_count;
reg   [11:0] loop_dataflow_output_count;
reg    loop_dataflow_busy;
wire    dataflow_in_loop_U0_start_full_n;
wire    dataflow_in_loop_U0_start_write;

// power-on initialization
initial begin
#0 loop_dataflow_enable = 1'b0;
#0 loop_dataflow_input_count = 12'd0;
#0 loop_dataflow_output_count = 12'd0;
#0 loop_dataflow_busy = 1'b0;
end

dataflow_in_loop dataflow_in_loop_U0(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .axis_V_V_TDATA(axis_V_V_TDATA),
    .loop_count_V(loop_count_V),
    .final_burst_length_V(final_burst_length_V),
    .val_assign(loop_dataflow_input_count),
    .m_axi_rx_buffer_V_AWVALID(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWVALID),
    .m_axi_rx_buffer_V_AWREADY(m_axi_rx_buffer_V_AWREADY),
    .m_axi_rx_buffer_V_AWADDR(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWADDR),
    .m_axi_rx_buffer_V_AWID(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWID),
    .m_axi_rx_buffer_V_AWLEN(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWLEN),
    .m_axi_rx_buffer_V_AWSIZE(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWSIZE),
    .m_axi_rx_buffer_V_AWBURST(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWBURST),
    .m_axi_rx_buffer_V_AWLOCK(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWLOCK),
    .m_axi_rx_buffer_V_AWCACHE(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWCACHE),
    .m_axi_rx_buffer_V_AWPROT(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWPROT),
    .m_axi_rx_buffer_V_AWQOS(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWQOS),
    .m_axi_rx_buffer_V_AWREGION(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWREGION),
    .m_axi_rx_buffer_V_AWUSER(dataflow_in_loop_U0_m_axi_rx_buffer_V_AWUSER),
    .m_axi_rx_buffer_V_WVALID(dataflow_in_loop_U0_m_axi_rx_buffer_V_WVALID),
    .m_axi_rx_buffer_V_WREADY(m_axi_rx_buffer_V_WREADY),
    .m_axi_rx_buffer_V_WDATA(dataflow_in_loop_U0_m_axi_rx_buffer_V_WDATA),
    .m_axi_rx_buffer_V_WSTRB(dataflow_in_loop_U0_m_axi_rx_buffer_V_WSTRB),
    .m_axi_rx_buffer_V_WLAST(dataflow_in_loop_U0_m_axi_rx_buffer_V_WLAST),
    .m_axi_rx_buffer_V_WID(dataflow_in_loop_U0_m_axi_rx_buffer_V_WID),
    .m_axi_rx_buffer_V_WUSER(dataflow_in_loop_U0_m_axi_rx_buffer_V_WUSER),
    .m_axi_rx_buffer_V_ARVALID(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARVALID),
    .m_axi_rx_buffer_V_ARREADY(1'b0),
    .m_axi_rx_buffer_V_ARADDR(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARADDR),
    .m_axi_rx_buffer_V_ARID(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARID),
    .m_axi_rx_buffer_V_ARLEN(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARLEN),
    .m_axi_rx_buffer_V_ARSIZE(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARSIZE),
    .m_axi_rx_buffer_V_ARBURST(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARBURST),
    .m_axi_rx_buffer_V_ARLOCK(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARLOCK),
    .m_axi_rx_buffer_V_ARCACHE(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARCACHE),
    .m_axi_rx_buffer_V_ARPROT(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARPROT),
    .m_axi_rx_buffer_V_ARQOS(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARQOS),
    .m_axi_rx_buffer_V_ARREGION(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARREGION),
    .m_axi_rx_buffer_V_ARUSER(dataflow_in_loop_U0_m_axi_rx_buffer_V_ARUSER),
    .m_axi_rx_buffer_V_RVALID(1'b0),
    .m_axi_rx_buffer_V_RREADY(dataflow_in_loop_U0_m_axi_rx_buffer_V_RREADY),
    .m_axi_rx_buffer_V_RDATA(64'd0),
    .m_axi_rx_buffer_V_RLAST(1'b0),
    .m_axi_rx_buffer_V_RID(1'd0),
    .m_axi_rx_buffer_V_RUSER(1'd0),
    .m_axi_rx_buffer_V_RRESP(2'd0),
    .m_axi_rx_buffer_V_BVALID(m_axi_rx_buffer_V_BVALID),
    .m_axi_rx_buffer_V_BREADY(dataflow_in_loop_U0_m_axi_rx_buffer_V_BREADY),
    .m_axi_rx_buffer_V_BRESP(m_axi_rx_buffer_V_BRESP),
    .m_axi_rx_buffer_V_BID(m_axi_rx_buffer_V_BID),
    .m_axi_rx_buffer_V_BUSER(m_axi_rx_buffer_V_BUSER),
    .rx_buffer_V_offset(rx_buffer_V_offset),
    .rx_buffer_V_offset1(rx_buffer_V_offset1),
    .axis_V_V_TVALID(axis_V_V_TVALID),
    .axis_V_V_TREADY(dataflow_in_loop_U0_axis_V_V_TREADY),
    .loop_count_V_ap_vld(loop_count_V_ap_vld),
    .final_burst_length_V_ap_vld(final_burst_length_V_ap_vld),
    .val_assign_ap_vld(1'b0),
    .rx_buffer_V_offset1_ap_vld(rx_buffer_V_offset1_ap_vld),
    .rx_buffer_V_offset_ap_vld(rx_buffer_V_offset_ap_vld),
    .ap_done(dataflow_in_loop_U0_ap_done),
    .ap_start(dataflow_in_loop_U0_ap_start),
    .ap_ready(dataflow_in_loop_U0_ap_ready),
    .ap_idle(dataflow_in_loop_U0_ap_idle),
    .ap_continue(dataflow_in_loop_U0_ap_continue)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        loop_dataflow_busy <= 1'b0;
    end else begin
        if (((loop_dataflow_output_count == loop_count_V) & (ap_continue == 1'b1))) begin
            loop_dataflow_busy <= 1'b0;
        end else if ((ap_start == 1'b1)) begin
            loop_dataflow_busy <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        loop_dataflow_enable <= 1'b0;
    end else begin
        if (((loop_dataflow_enable == 1'b0) & (ap_start == 1'b1))) begin
            loop_dataflow_enable <= 1'b1;
        end else if (((loop_dataflow_input_count == loop_count_V) & (loop_dataflow_enable == 1'b1))) begin
            loop_dataflow_enable <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        loop_dataflow_input_count <= 12'd0;
    end else begin
        if (((loop_dataflow_input_count == loop_count_V) & (loop_dataflow_enable == 1'b1))) begin
            loop_dataflow_input_count <= 12'd0;
        end else if (((loop_dataflow_enable == 1'b1) & (dataflow_in_loop_U0_ap_ready == 1'b1))) begin
            loop_dataflow_input_count <= (loop_dataflow_input_count + 12'd1);
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        loop_dataflow_output_count <= 12'd0;
    end else begin
        if (((loop_dataflow_output_count == loop_count_V) & (ap_continue == 1'b1))) begin
            loop_dataflow_output_count <= 12'd0;
        end else if ((dataflow_in_loop_U0_ap_done == 1'b1)) begin
            loop_dataflow_output_count <= (loop_dataflow_output_count + 12'd1);
        end
    end
end

always @ (*) begin
    if (((loop_dataflow_output_count == loop_count_V) & (loop_dataflow_busy == 1'b1))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if ((loop_dataflow_input_count == loop_count_V)) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((~(loop_dataflow_input_count == loop_count_V) & (loop_dataflow_enable == 1'b1))) begin
        dataflow_in_loop_U0_ap_start = 1'b1;
    end else begin
        dataflow_in_loop_U0_ap_start = 1'b0;
    end
end

assign ap_idle = dataflow_in_loop_U0_ap_idle;

assign ap_sync_continue = ap_continue;

assign ap_sync_done = dataflow_in_loop_U0_ap_done;

assign ap_sync_ready = dataflow_in_loop_U0_ap_ready;

assign axis_V_V_TREADY = dataflow_in_loop_U0_axis_V_V_TREADY;

assign dataflow_in_loop_U0_ap_continue = 1'b1;

assign dataflow_in_loop_U0_start_full_n = 1'b1;

assign dataflow_in_loop_U0_start_write = 1'b0;

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

assign m_axi_rx_buffer_V_AWADDR = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWADDR;

assign m_axi_rx_buffer_V_AWBURST = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWBURST;

assign m_axi_rx_buffer_V_AWCACHE = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWCACHE;

assign m_axi_rx_buffer_V_AWID = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWID;

assign m_axi_rx_buffer_V_AWLEN = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWLEN;

assign m_axi_rx_buffer_V_AWLOCK = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWLOCK;

assign m_axi_rx_buffer_V_AWPROT = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWPROT;

assign m_axi_rx_buffer_V_AWQOS = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWQOS;

assign m_axi_rx_buffer_V_AWREGION = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWREGION;

assign m_axi_rx_buffer_V_AWSIZE = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWSIZE;

assign m_axi_rx_buffer_V_AWUSER = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWUSER;

assign m_axi_rx_buffer_V_AWVALID = dataflow_in_loop_U0_m_axi_rx_buffer_V_AWVALID;

assign m_axi_rx_buffer_V_BREADY = dataflow_in_loop_U0_m_axi_rx_buffer_V_BREADY;

assign m_axi_rx_buffer_V_RREADY = 1'b0;

assign m_axi_rx_buffer_V_WDATA = dataflow_in_loop_U0_m_axi_rx_buffer_V_WDATA;

assign m_axi_rx_buffer_V_WID = dataflow_in_loop_U0_m_axi_rx_buffer_V_WID;

assign m_axi_rx_buffer_V_WLAST = dataflow_in_loop_U0_m_axi_rx_buffer_V_WLAST;

assign m_axi_rx_buffer_V_WSTRB = dataflow_in_loop_U0_m_axi_rx_buffer_V_WSTRB;

assign m_axi_rx_buffer_V_WUSER = dataflow_in_loop_U0_m_axi_rx_buffer_V_WUSER;

assign m_axi_rx_buffer_V_WVALID = dataflow_in_loop_U0_m_axi_rx_buffer_V_WVALID;

endmodule //rx_loop
