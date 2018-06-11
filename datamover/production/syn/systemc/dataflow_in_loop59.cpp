// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "dataflow_in_loop59.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic dataflow_in_loop59::ap_const_logic_1 = sc_dt::Log_1;
const sc_lv<64> dataflow_in_loop59::ap_const_lv64_0 = "0000000000000000000000000000000000000000000000000000000000000000";
const sc_logic dataflow_in_loop59::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<2> dataflow_in_loop59::ap_const_lv2_0 = "00";
const sc_lv<2> dataflow_in_loop59::ap_const_lv2_1 = "1";
const sc_lv<1> dataflow_in_loop59::ap_const_lv1_0 = "0";
const sc_lv<1> dataflow_in_loop59::ap_const_lv1_1 = "1";
const sc_lv<32> dataflow_in_loop59::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<3> dataflow_in_loop59::ap_const_lv3_0 = "000";
const sc_lv<4> dataflow_in_loop59::ap_const_lv4_0 = "0000";
const sc_lv<8> dataflow_in_loop59::ap_const_lv8_0 = "00000000";
const bool dataflow_in_loop59::ap_const_boolean_1 = true;

dataflow_in_loop59::dataflow_in_loop59(sc_module_name name) : sc_module(name), mVcdFile(0) {
    cache_V_U = new dataflow_in_loop5bkb("cache_V_U");
    cache_V_U->clk(ap_clk);
    cache_V_U->reset(ap_rst);
    cache_V_U->i_address0(read_burst_U0_cache_V_address0);
    cache_V_U->i_ce0(read_burst_U0_cache_V_ce0);
    cache_V_U->i_we0(read_burst_U0_cache_V_we0);
    cache_V_U->i_d0(read_burst_U0_cache_V_d0);
    cache_V_U->i_q0(cache_V_i_q0);
    cache_V_U->t_address0(tx_axis_words_U0_cache_V_address0);
    cache_V_U->t_ce0(tx_axis_words_U0_cache_V_ce0);
    cache_V_U->t_we0(ap_var_for_const0);
    cache_V_U->t_d0(ap_var_for_const1);
    cache_V_U->t_q0(cache_V_t_q0);
    cache_V_U->i_ce(ap_var_for_const2);
    cache_V_U->t_ce(ap_var_for_const2);
    cache_V_U->i_full_n(cache_V_i_full_n);
    cache_V_U->i_write(ap_channel_done_cache_V);
    cache_V_U->t_empty_n(cache_V_t_empty_n);
    cache_V_U->t_read(tx_axis_words_U0_ap_ready);
    read_burst_U0 = new read_burst("read_burst_U0");
    read_burst_U0->ap_clk(ap_clk);
    read_burst_U0->ap_rst(ap_rst);
    read_burst_U0->ap_start(read_burst_U0_ap_start);
    read_burst_U0->ap_done(read_burst_U0_ap_done);
    read_burst_U0->ap_continue(read_burst_U0_ap_continue);
    read_burst_U0->ap_idle(read_burst_U0_ap_idle);
    read_burst_U0->ap_ready(read_burst_U0_ap_ready);
    read_burst_U0->m_axi_tx_buffer_V_AWVALID(read_burst_U0_m_axi_tx_buffer_V_AWVALID);
    read_burst_U0->m_axi_tx_buffer_V_AWREADY(ap_var_for_const0);
    read_burst_U0->m_axi_tx_buffer_V_AWADDR(read_burst_U0_m_axi_tx_buffer_V_AWADDR);
    read_burst_U0->m_axi_tx_buffer_V_AWID(read_burst_U0_m_axi_tx_buffer_V_AWID);
    read_burst_U0->m_axi_tx_buffer_V_AWLEN(read_burst_U0_m_axi_tx_buffer_V_AWLEN);
    read_burst_U0->m_axi_tx_buffer_V_AWSIZE(read_burst_U0_m_axi_tx_buffer_V_AWSIZE);
    read_burst_U0->m_axi_tx_buffer_V_AWBURST(read_burst_U0_m_axi_tx_buffer_V_AWBURST);
    read_burst_U0->m_axi_tx_buffer_V_AWLOCK(read_burst_U0_m_axi_tx_buffer_V_AWLOCK);
    read_burst_U0->m_axi_tx_buffer_V_AWCACHE(read_burst_U0_m_axi_tx_buffer_V_AWCACHE);
    read_burst_U0->m_axi_tx_buffer_V_AWPROT(read_burst_U0_m_axi_tx_buffer_V_AWPROT);
    read_burst_U0->m_axi_tx_buffer_V_AWQOS(read_burst_U0_m_axi_tx_buffer_V_AWQOS);
    read_burst_U0->m_axi_tx_buffer_V_AWREGION(read_burst_U0_m_axi_tx_buffer_V_AWREGION);
    read_burst_U0->m_axi_tx_buffer_V_AWUSER(read_burst_U0_m_axi_tx_buffer_V_AWUSER);
    read_burst_U0->m_axi_tx_buffer_V_WVALID(read_burst_U0_m_axi_tx_buffer_V_WVALID);
    read_burst_U0->m_axi_tx_buffer_V_WREADY(ap_var_for_const0);
    read_burst_U0->m_axi_tx_buffer_V_WDATA(read_burst_U0_m_axi_tx_buffer_V_WDATA);
    read_burst_U0->m_axi_tx_buffer_V_WSTRB(read_burst_U0_m_axi_tx_buffer_V_WSTRB);
    read_burst_U0->m_axi_tx_buffer_V_WLAST(read_burst_U0_m_axi_tx_buffer_V_WLAST);
    read_burst_U0->m_axi_tx_buffer_V_WID(read_burst_U0_m_axi_tx_buffer_V_WID);
    read_burst_U0->m_axi_tx_buffer_V_WUSER(read_burst_U0_m_axi_tx_buffer_V_WUSER);
    read_burst_U0->m_axi_tx_buffer_V_ARVALID(read_burst_U0_m_axi_tx_buffer_V_ARVALID);
    read_burst_U0->m_axi_tx_buffer_V_ARREADY(m_axi_tx_buffer_V_ARREADY);
    read_burst_U0->m_axi_tx_buffer_V_ARADDR(read_burst_U0_m_axi_tx_buffer_V_ARADDR);
    read_burst_U0->m_axi_tx_buffer_V_ARID(read_burst_U0_m_axi_tx_buffer_V_ARID);
    read_burst_U0->m_axi_tx_buffer_V_ARLEN(read_burst_U0_m_axi_tx_buffer_V_ARLEN);
    read_burst_U0->m_axi_tx_buffer_V_ARSIZE(read_burst_U0_m_axi_tx_buffer_V_ARSIZE);
    read_burst_U0->m_axi_tx_buffer_V_ARBURST(read_burst_U0_m_axi_tx_buffer_V_ARBURST);
    read_burst_U0->m_axi_tx_buffer_V_ARLOCK(read_burst_U0_m_axi_tx_buffer_V_ARLOCK);
    read_burst_U0->m_axi_tx_buffer_V_ARCACHE(read_burst_U0_m_axi_tx_buffer_V_ARCACHE);
    read_burst_U0->m_axi_tx_buffer_V_ARPROT(read_burst_U0_m_axi_tx_buffer_V_ARPROT);
    read_burst_U0->m_axi_tx_buffer_V_ARQOS(read_burst_U0_m_axi_tx_buffer_V_ARQOS);
    read_burst_U0->m_axi_tx_buffer_V_ARREGION(read_burst_U0_m_axi_tx_buffer_V_ARREGION);
    read_burst_U0->m_axi_tx_buffer_V_ARUSER(read_burst_U0_m_axi_tx_buffer_V_ARUSER);
    read_burst_U0->m_axi_tx_buffer_V_RVALID(m_axi_tx_buffer_V_RVALID);
    read_burst_U0->m_axi_tx_buffer_V_RREADY(read_burst_U0_m_axi_tx_buffer_V_RREADY);
    read_burst_U0->m_axi_tx_buffer_V_RDATA(m_axi_tx_buffer_V_RDATA);
    read_burst_U0->m_axi_tx_buffer_V_RLAST(m_axi_tx_buffer_V_RLAST);
    read_burst_U0->m_axi_tx_buffer_V_RID(m_axi_tx_buffer_V_RID);
    read_burst_U0->m_axi_tx_buffer_V_RUSER(m_axi_tx_buffer_V_RUSER);
    read_burst_U0->m_axi_tx_buffer_V_RRESP(m_axi_tx_buffer_V_RRESP);
    read_burst_U0->m_axi_tx_buffer_V_BVALID(ap_var_for_const0);
    read_burst_U0->m_axi_tx_buffer_V_BREADY(read_burst_U0_m_axi_tx_buffer_V_BREADY);
    read_burst_U0->m_axi_tx_buffer_V_BRESP(ap_var_for_const3);
    read_burst_U0->m_axi_tx_buffer_V_BID(ap_var_for_const4);
    read_burst_U0->m_axi_tx_buffer_V_BUSER(ap_var_for_const4);
    read_burst_U0->tx_buffer_V_offset(tx_buffer_V_offset);
    read_burst_U0->val_assign(val_assign);
    read_burst_U0->loop_count_V(loop_count_V);
    read_burst_U0->final_burst_length_V(final_burst_length_V);
    read_burst_U0->cache_V_address0(read_burst_U0_cache_V_address0);
    read_burst_U0->cache_V_ce0(read_burst_U0_cache_V_ce0);
    read_burst_U0->cache_V_we0(read_burst_U0_cache_V_we0);
    read_burst_U0->cache_V_d0(read_burst_U0_cache_V_d0);
    read_burst_U0->ap_return(read_burst_U0_ap_return);
    tx_axis_words_U0 = new tx_axis_words("tx_axis_words_U0");
    tx_axis_words_U0->ap_clk(ap_clk);
    tx_axis_words_U0->ap_rst(ap_rst);
    tx_axis_words_U0->ap_start(tx_axis_words_U0_ap_start);
    tx_axis_words_U0->ap_done(tx_axis_words_U0_ap_done);
    tx_axis_words_U0->ap_continue(tx_axis_words_U0_ap_continue);
    tx_axis_words_U0->ap_idle(tx_axis_words_U0_ap_idle);
    tx_axis_words_U0->ap_ready(tx_axis_words_U0_ap_ready);
    tx_axis_words_U0->cache_V_address0(tx_axis_words_U0_cache_V_address0);
    tx_axis_words_U0->cache_V_ce0(tx_axis_words_U0_cache_V_ce0);
    tx_axis_words_U0->cache_V_q0(cache_V_t_q0);
    tx_axis_words_U0->p_read(data_length_V_dout);
    tx_axis_words_U0->axis_V_V_TDATA(tx_axis_words_U0_axis_V_V_TDATA);
    tx_axis_words_U0->axis_V_V_TVALID(tx_axis_words_U0_axis_V_V_TVALID);
    tx_axis_words_U0->axis_V_V_TREADY(axis_V_V_TREADY);
    data_length_V_U = new fifo_w10_d2_A("data_length_V_U");
    data_length_V_U->clk(ap_clk);
    data_length_V_U->reset(ap_rst);
    data_length_V_U->if_read_ce(ap_var_for_const2);
    data_length_V_U->if_write_ce(ap_var_for_const2);
    data_length_V_U->if_din(read_burst_U0_ap_return);
    data_length_V_U->if_full_n(data_length_V_full_n);
    data_length_V_U->if_write(ap_channel_done_data_length_V);
    data_length_V_U->if_dout(data_length_V_dout);
    data_length_V_U->if_empty_n(data_length_V_empty_n);
    data_length_V_U->if_read(tx_axis_words_U0_ap_ready);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_ap_channel_done_cache_V);
    sensitive << ( read_burst_U0_ap_done );
    sensitive << ( ap_sync_reg_channel_write_cache_V );

    SC_METHOD(thread_ap_channel_done_data_length_V);
    sensitive << ( read_burst_U0_ap_done );
    sensitive << ( ap_sync_reg_channel_write_data_length_V );

    SC_METHOD(thread_ap_done);
    sensitive << ( tx_axis_words_U0_ap_done );

    SC_METHOD(thread_ap_idle);
    sensitive << ( read_burst_U0_ap_idle );
    sensitive << ( tx_axis_words_U0_ap_idle );
    sensitive << ( cache_V_t_empty_n );
    sensitive << ( data_length_V_empty_n );

    SC_METHOD(thread_ap_ready);
    sensitive << ( read_burst_U0_ap_ready );

    SC_METHOD(thread_ap_sync_channel_write_cache_V);
    sensitive << ( ap_channel_done_cache_V );
    sensitive << ( read_burst_U0_cache_V_full_n );
    sensitive << ( ap_sync_reg_channel_write_cache_V );

    SC_METHOD(thread_ap_sync_channel_write_data_length_V);
    sensitive << ( ap_channel_done_data_length_V );
    sensitive << ( data_length_V_full_n );
    sensitive << ( ap_sync_reg_channel_write_data_length_V );

    SC_METHOD(thread_ap_sync_continue);
    sensitive << ( ap_continue );

    SC_METHOD(thread_ap_sync_done);
    sensitive << ( tx_axis_words_U0_ap_done );

    SC_METHOD(thread_ap_sync_ready);
    sensitive << ( read_burst_U0_ap_ready );

    SC_METHOD(thread_axis_V_V_TDATA);
    sensitive << ( tx_axis_words_U0_axis_V_V_TDATA );

    SC_METHOD(thread_axis_V_V_TVALID);
    sensitive << ( tx_axis_words_U0_axis_V_V_TVALID );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARADDR);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARADDR );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARBURST);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARBURST );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARCACHE);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARCACHE );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARID);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARID );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARLEN);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARLEN );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARLOCK);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARLOCK );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARPROT);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARPROT );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARQOS);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARQOS );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARREGION);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARREGION );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARSIZE);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARSIZE );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARUSER);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARUSER );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARVALID);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_ARVALID );

    SC_METHOD(thread_m_axi_tx_buffer_V_AWADDR);

    SC_METHOD(thread_m_axi_tx_buffer_V_AWBURST);

    SC_METHOD(thread_m_axi_tx_buffer_V_AWCACHE);

    SC_METHOD(thread_m_axi_tx_buffer_V_AWID);

    SC_METHOD(thread_m_axi_tx_buffer_V_AWLEN);

    SC_METHOD(thread_m_axi_tx_buffer_V_AWLOCK);

    SC_METHOD(thread_m_axi_tx_buffer_V_AWPROT);

    SC_METHOD(thread_m_axi_tx_buffer_V_AWQOS);

    SC_METHOD(thread_m_axi_tx_buffer_V_AWREGION);

    SC_METHOD(thread_m_axi_tx_buffer_V_AWSIZE);

    SC_METHOD(thread_m_axi_tx_buffer_V_AWUSER);

    SC_METHOD(thread_m_axi_tx_buffer_V_AWVALID);

    SC_METHOD(thread_m_axi_tx_buffer_V_BREADY);

    SC_METHOD(thread_m_axi_tx_buffer_V_RREADY);
    sensitive << ( read_burst_U0_m_axi_tx_buffer_V_RREADY );

    SC_METHOD(thread_m_axi_tx_buffer_V_WDATA);

    SC_METHOD(thread_m_axi_tx_buffer_V_WID);

    SC_METHOD(thread_m_axi_tx_buffer_V_WLAST);

    SC_METHOD(thread_m_axi_tx_buffer_V_WSTRB);

    SC_METHOD(thread_m_axi_tx_buffer_V_WUSER);

    SC_METHOD(thread_m_axi_tx_buffer_V_WVALID);

    SC_METHOD(thread_read_burst_U0_ap_continue);
    sensitive << ( ap_sync_channel_write_data_length_V );
    sensitive << ( ap_sync_channel_write_cache_V );

    SC_METHOD(thread_read_burst_U0_ap_start);
    sensitive << ( ap_start );

    SC_METHOD(thread_read_burst_U0_cache_V_full_n);
    sensitive << ( cache_V_i_full_n );

    SC_METHOD(thread_read_burst_U0_start_full_n);

    SC_METHOD(thread_read_burst_U0_start_write);

    SC_METHOD(thread_tx_axis_words_U0_ap_continue);
    sensitive << ( ap_continue );

    SC_METHOD(thread_tx_axis_words_U0_ap_start);
    sensitive << ( cache_V_t_empty_n );
    sensitive << ( data_length_V_empty_n );

    SC_METHOD(thread_tx_axis_words_U0_start_full_n);

    SC_METHOD(thread_tx_axis_words_U0_start_write);

    SC_THREAD(thread_ap_var_for_const2);

    SC_THREAD(thread_ap_var_for_const1);

    SC_THREAD(thread_ap_var_for_const0);

    SC_THREAD(thread_ap_var_for_const3);

    SC_THREAD(thread_ap_var_for_const4);

    ap_sync_reg_channel_write_data_length_V = SC_LOGIC_0;
    ap_sync_reg_channel_write_cache_V = SC_LOGIC_0;
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "dataflow_in_loop59_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT_HIER__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWVALID, "(port)m_axi_tx_buffer_V_AWVALID");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWREADY, "(port)m_axi_tx_buffer_V_AWREADY");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWADDR, "(port)m_axi_tx_buffer_V_AWADDR");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWID, "(port)m_axi_tx_buffer_V_AWID");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWLEN, "(port)m_axi_tx_buffer_V_AWLEN");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWSIZE, "(port)m_axi_tx_buffer_V_AWSIZE");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWBURST, "(port)m_axi_tx_buffer_V_AWBURST");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWLOCK, "(port)m_axi_tx_buffer_V_AWLOCK");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWCACHE, "(port)m_axi_tx_buffer_V_AWCACHE");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWPROT, "(port)m_axi_tx_buffer_V_AWPROT");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWQOS, "(port)m_axi_tx_buffer_V_AWQOS");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWREGION, "(port)m_axi_tx_buffer_V_AWREGION");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_AWUSER, "(port)m_axi_tx_buffer_V_AWUSER");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_WVALID, "(port)m_axi_tx_buffer_V_WVALID");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_WREADY, "(port)m_axi_tx_buffer_V_WREADY");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_WDATA, "(port)m_axi_tx_buffer_V_WDATA");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_WSTRB, "(port)m_axi_tx_buffer_V_WSTRB");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_WLAST, "(port)m_axi_tx_buffer_V_WLAST");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_WID, "(port)m_axi_tx_buffer_V_WID");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_WUSER, "(port)m_axi_tx_buffer_V_WUSER");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARVALID, "(port)m_axi_tx_buffer_V_ARVALID");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARREADY, "(port)m_axi_tx_buffer_V_ARREADY");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARADDR, "(port)m_axi_tx_buffer_V_ARADDR");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARID, "(port)m_axi_tx_buffer_V_ARID");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARLEN, "(port)m_axi_tx_buffer_V_ARLEN");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARSIZE, "(port)m_axi_tx_buffer_V_ARSIZE");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARBURST, "(port)m_axi_tx_buffer_V_ARBURST");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARLOCK, "(port)m_axi_tx_buffer_V_ARLOCK");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARCACHE, "(port)m_axi_tx_buffer_V_ARCACHE");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARPROT, "(port)m_axi_tx_buffer_V_ARPROT");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARQOS, "(port)m_axi_tx_buffer_V_ARQOS");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARREGION, "(port)m_axi_tx_buffer_V_ARREGION");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_ARUSER, "(port)m_axi_tx_buffer_V_ARUSER");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_RVALID, "(port)m_axi_tx_buffer_V_RVALID");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_RREADY, "(port)m_axi_tx_buffer_V_RREADY");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_RDATA, "(port)m_axi_tx_buffer_V_RDATA");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_RLAST, "(port)m_axi_tx_buffer_V_RLAST");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_RID, "(port)m_axi_tx_buffer_V_RID");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_RUSER, "(port)m_axi_tx_buffer_V_RUSER");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_RRESP, "(port)m_axi_tx_buffer_V_RRESP");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_BVALID, "(port)m_axi_tx_buffer_V_BVALID");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_BREADY, "(port)m_axi_tx_buffer_V_BREADY");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_BRESP, "(port)m_axi_tx_buffer_V_BRESP");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_BID, "(port)m_axi_tx_buffer_V_BID");
    sc_trace(mVcdFile, m_axi_tx_buffer_V_BUSER, "(port)m_axi_tx_buffer_V_BUSER");
    sc_trace(mVcdFile, tx_buffer_V_offset, "(port)tx_buffer_V_offset");
    sc_trace(mVcdFile, val_assign, "(port)val_assign");
    sc_trace(mVcdFile, loop_count_V, "(port)loop_count_V");
    sc_trace(mVcdFile, final_burst_length_V, "(port)final_burst_length_V");
    sc_trace(mVcdFile, axis_V_V_TDATA, "(port)axis_V_V_TDATA");
    sc_trace(mVcdFile, tx_buffer_V_offset_ap_vld, "(port)tx_buffer_V_offset_ap_vld");
    sc_trace(mVcdFile, val_assign_ap_vld, "(port)val_assign_ap_vld");
    sc_trace(mVcdFile, loop_count_V_ap_vld, "(port)loop_count_V_ap_vld");
    sc_trace(mVcdFile, final_burst_length_V_ap_vld, "(port)final_burst_length_V_ap_vld");
    sc_trace(mVcdFile, axis_V_V_TVALID, "(port)axis_V_V_TVALID");
    sc_trace(mVcdFile, axis_V_V_TREADY, "(port)axis_V_V_TREADY");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_continue, "(port)ap_continue");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, cache_V_i_q0, "cache_V_i_q0");
    sc_trace(mVcdFile, cache_V_t_q0, "cache_V_t_q0");
    sc_trace(mVcdFile, read_burst_U0_ap_start, "read_burst_U0_ap_start");
    sc_trace(mVcdFile, read_burst_U0_ap_done, "read_burst_U0_ap_done");
    sc_trace(mVcdFile, read_burst_U0_ap_continue, "read_burst_U0_ap_continue");
    sc_trace(mVcdFile, read_burst_U0_ap_idle, "read_burst_U0_ap_idle");
    sc_trace(mVcdFile, read_burst_U0_ap_ready, "read_burst_U0_ap_ready");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWVALID, "read_burst_U0_m_axi_tx_buffer_V_AWVALID");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWADDR, "read_burst_U0_m_axi_tx_buffer_V_AWADDR");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWID, "read_burst_U0_m_axi_tx_buffer_V_AWID");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWLEN, "read_burst_U0_m_axi_tx_buffer_V_AWLEN");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWSIZE, "read_burst_U0_m_axi_tx_buffer_V_AWSIZE");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWBURST, "read_burst_U0_m_axi_tx_buffer_V_AWBURST");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWLOCK, "read_burst_U0_m_axi_tx_buffer_V_AWLOCK");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWCACHE, "read_burst_U0_m_axi_tx_buffer_V_AWCACHE");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWPROT, "read_burst_U0_m_axi_tx_buffer_V_AWPROT");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWQOS, "read_burst_U0_m_axi_tx_buffer_V_AWQOS");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWREGION, "read_burst_U0_m_axi_tx_buffer_V_AWREGION");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_AWUSER, "read_burst_U0_m_axi_tx_buffer_V_AWUSER");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_WVALID, "read_burst_U0_m_axi_tx_buffer_V_WVALID");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_WDATA, "read_burst_U0_m_axi_tx_buffer_V_WDATA");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_WSTRB, "read_burst_U0_m_axi_tx_buffer_V_WSTRB");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_WLAST, "read_burst_U0_m_axi_tx_buffer_V_WLAST");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_WID, "read_burst_U0_m_axi_tx_buffer_V_WID");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_WUSER, "read_burst_U0_m_axi_tx_buffer_V_WUSER");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARVALID, "read_burst_U0_m_axi_tx_buffer_V_ARVALID");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARADDR, "read_burst_U0_m_axi_tx_buffer_V_ARADDR");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARID, "read_burst_U0_m_axi_tx_buffer_V_ARID");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARLEN, "read_burst_U0_m_axi_tx_buffer_V_ARLEN");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARSIZE, "read_burst_U0_m_axi_tx_buffer_V_ARSIZE");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARBURST, "read_burst_U0_m_axi_tx_buffer_V_ARBURST");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARLOCK, "read_burst_U0_m_axi_tx_buffer_V_ARLOCK");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARCACHE, "read_burst_U0_m_axi_tx_buffer_V_ARCACHE");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARPROT, "read_burst_U0_m_axi_tx_buffer_V_ARPROT");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARQOS, "read_burst_U0_m_axi_tx_buffer_V_ARQOS");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARREGION, "read_burst_U0_m_axi_tx_buffer_V_ARREGION");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_ARUSER, "read_burst_U0_m_axi_tx_buffer_V_ARUSER");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_RREADY, "read_burst_U0_m_axi_tx_buffer_V_RREADY");
    sc_trace(mVcdFile, read_burst_U0_m_axi_tx_buffer_V_BREADY, "read_burst_U0_m_axi_tx_buffer_V_BREADY");
    sc_trace(mVcdFile, read_burst_U0_cache_V_address0, "read_burst_U0_cache_V_address0");
    sc_trace(mVcdFile, read_burst_U0_cache_V_ce0, "read_burst_U0_cache_V_ce0");
    sc_trace(mVcdFile, read_burst_U0_cache_V_we0, "read_burst_U0_cache_V_we0");
    sc_trace(mVcdFile, read_burst_U0_cache_V_d0, "read_burst_U0_cache_V_d0");
    sc_trace(mVcdFile, read_burst_U0_ap_return, "read_burst_U0_ap_return");
    sc_trace(mVcdFile, ap_channel_done_data_length_V, "ap_channel_done_data_length_V");
    sc_trace(mVcdFile, data_length_V_full_n, "data_length_V_full_n");
    sc_trace(mVcdFile, ap_sync_reg_channel_write_data_length_V, "ap_sync_reg_channel_write_data_length_V");
    sc_trace(mVcdFile, ap_sync_channel_write_data_length_V, "ap_sync_channel_write_data_length_V");
    sc_trace(mVcdFile, ap_channel_done_cache_V, "ap_channel_done_cache_V");
    sc_trace(mVcdFile, read_burst_U0_cache_V_full_n, "read_burst_U0_cache_V_full_n");
    sc_trace(mVcdFile, ap_sync_reg_channel_write_cache_V, "ap_sync_reg_channel_write_cache_V");
    sc_trace(mVcdFile, ap_sync_channel_write_cache_V, "ap_sync_channel_write_cache_V");
    sc_trace(mVcdFile, tx_axis_words_U0_ap_start, "tx_axis_words_U0_ap_start");
    sc_trace(mVcdFile, tx_axis_words_U0_ap_done, "tx_axis_words_U0_ap_done");
    sc_trace(mVcdFile, tx_axis_words_U0_ap_continue, "tx_axis_words_U0_ap_continue");
    sc_trace(mVcdFile, tx_axis_words_U0_ap_idle, "tx_axis_words_U0_ap_idle");
    sc_trace(mVcdFile, tx_axis_words_U0_ap_ready, "tx_axis_words_U0_ap_ready");
    sc_trace(mVcdFile, tx_axis_words_U0_cache_V_address0, "tx_axis_words_U0_cache_V_address0");
    sc_trace(mVcdFile, tx_axis_words_U0_cache_V_ce0, "tx_axis_words_U0_cache_V_ce0");
    sc_trace(mVcdFile, tx_axis_words_U0_axis_V_V_TDATA, "tx_axis_words_U0_axis_V_V_TDATA");
    sc_trace(mVcdFile, tx_axis_words_U0_axis_V_V_TVALID, "tx_axis_words_U0_axis_V_V_TVALID");
    sc_trace(mVcdFile, ap_sync_continue, "ap_sync_continue");
    sc_trace(mVcdFile, cache_V_i_full_n, "cache_V_i_full_n");
    sc_trace(mVcdFile, cache_V_t_empty_n, "cache_V_t_empty_n");
    sc_trace(mVcdFile, data_length_V_dout, "data_length_V_dout");
    sc_trace(mVcdFile, data_length_V_empty_n, "data_length_V_empty_n");
    sc_trace(mVcdFile, ap_sync_done, "ap_sync_done");
    sc_trace(mVcdFile, ap_sync_ready, "ap_sync_ready");
    sc_trace(mVcdFile, read_burst_U0_start_full_n, "read_burst_U0_start_full_n");
    sc_trace(mVcdFile, read_burst_U0_start_write, "read_burst_U0_start_write");
    sc_trace(mVcdFile, tx_axis_words_U0_start_full_n, "tx_axis_words_U0_start_full_n");
    sc_trace(mVcdFile, tx_axis_words_U0_start_write, "tx_axis_words_U0_start_write");
#endif

    }
}

dataflow_in_loop59::~dataflow_in_loop59() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    delete cache_V_U;
    delete read_burst_U0;
    delete tx_axis_words_U0;
    delete data_length_V_U;
}

void dataflow_in_loop59::thread_ap_var_for_const2() {
    ap_var_for_const2 = ap_const_logic_1;
}

void dataflow_in_loop59::thread_ap_var_for_const1() {
    ap_var_for_const1 = ap_const_lv64_0;
}

void dataflow_in_loop59::thread_ap_var_for_const0() {
    ap_var_for_const0 = ap_const_logic_0;
}

void dataflow_in_loop59::thread_ap_var_for_const3() {
    ap_var_for_const3 = ap_const_lv2_0;
}

void dataflow_in_loop59::thread_ap_var_for_const4() {
    ap_var_for_const4 = ap_const_lv1_0;
}

void dataflow_in_loop59::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_sync_reg_channel_write_cache_V = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_const_logic_1, (read_burst_U0_ap_done.read() & 
             read_burst_U0_ap_continue.read()))) {
            ap_sync_reg_channel_write_cache_V = ap_const_logic_0;
        } else {
            ap_sync_reg_channel_write_cache_V = ap_sync_channel_write_cache_V.read();
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_sync_reg_channel_write_data_length_V = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_const_logic_1, (read_burst_U0_ap_done.read() & 
             read_burst_U0_ap_continue.read()))) {
            ap_sync_reg_channel_write_data_length_V = ap_const_logic_0;
        } else {
            ap_sync_reg_channel_write_data_length_V = ap_sync_channel_write_data_length_V.read();
        }
    }
}

void dataflow_in_loop59::thread_ap_channel_done_cache_V() {
    ap_channel_done_cache_V = (read_burst_U0_ap_done.read() & (ap_sync_reg_channel_write_cache_V.read() ^ 
  ap_const_logic_1));
}

void dataflow_in_loop59::thread_ap_channel_done_data_length_V() {
    ap_channel_done_data_length_V = (read_burst_U0_ap_done.read() & (ap_sync_reg_channel_write_data_length_V.read() ^ 
  ap_const_logic_1));
}

void dataflow_in_loop59::thread_ap_done() {
    ap_done = tx_axis_words_U0_ap_done.read();
}

void dataflow_in_loop59::thread_ap_idle() {
    ap_idle = (read_burst_U0_ap_idle.read() & tx_axis_words_U0_ap_idle.read() & (cache_V_t_empty_n.read() ^ 
  ap_const_logic_1) & (data_length_V_empty_n.read() ^ 
  ap_const_logic_1));
}

void dataflow_in_loop59::thread_ap_ready() {
    ap_ready = read_burst_U0_ap_ready.read();
}

void dataflow_in_loop59::thread_ap_sync_channel_write_cache_V() {
    ap_sync_channel_write_cache_V = ((ap_channel_done_cache_V.read() & 
  read_burst_U0_cache_V_full_n.read()) | ap_sync_reg_channel_write_cache_V.read());
}

void dataflow_in_loop59::thread_ap_sync_channel_write_data_length_V() {
    ap_sync_channel_write_data_length_V = ((ap_channel_done_data_length_V.read() & 
  data_length_V_full_n.read()) | ap_sync_reg_channel_write_data_length_V.read());
}

void dataflow_in_loop59::thread_ap_sync_continue() {
    ap_sync_continue = ap_continue.read();
}

void dataflow_in_loop59::thread_ap_sync_done() {
    ap_sync_done = tx_axis_words_U0_ap_done.read();
}

void dataflow_in_loop59::thread_ap_sync_ready() {
    ap_sync_ready = read_burst_U0_ap_ready.read();
}

void dataflow_in_loop59::thread_axis_V_V_TDATA() {
    axis_V_V_TDATA = tx_axis_words_U0_axis_V_V_TDATA.read();
}

void dataflow_in_loop59::thread_axis_V_V_TVALID() {
    axis_V_V_TVALID = tx_axis_words_U0_axis_V_V_TVALID.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARADDR() {
    m_axi_tx_buffer_V_ARADDR = read_burst_U0_m_axi_tx_buffer_V_ARADDR.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARBURST() {
    m_axi_tx_buffer_V_ARBURST = read_burst_U0_m_axi_tx_buffer_V_ARBURST.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARCACHE() {
    m_axi_tx_buffer_V_ARCACHE = read_burst_U0_m_axi_tx_buffer_V_ARCACHE.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARID() {
    m_axi_tx_buffer_V_ARID = read_burst_U0_m_axi_tx_buffer_V_ARID.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARLEN() {
    m_axi_tx_buffer_V_ARLEN = read_burst_U0_m_axi_tx_buffer_V_ARLEN.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARLOCK() {
    m_axi_tx_buffer_V_ARLOCK = read_burst_U0_m_axi_tx_buffer_V_ARLOCK.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARPROT() {
    m_axi_tx_buffer_V_ARPROT = read_burst_U0_m_axi_tx_buffer_V_ARPROT.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARQOS() {
    m_axi_tx_buffer_V_ARQOS = read_burst_U0_m_axi_tx_buffer_V_ARQOS.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARREGION() {
    m_axi_tx_buffer_V_ARREGION = read_burst_U0_m_axi_tx_buffer_V_ARREGION.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARSIZE() {
    m_axi_tx_buffer_V_ARSIZE = read_burst_U0_m_axi_tx_buffer_V_ARSIZE.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARUSER() {
    m_axi_tx_buffer_V_ARUSER = read_burst_U0_m_axi_tx_buffer_V_ARUSER.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_ARVALID() {
    m_axi_tx_buffer_V_ARVALID = read_burst_U0_m_axi_tx_buffer_V_ARVALID.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWADDR() {
    m_axi_tx_buffer_V_AWADDR = ap_const_lv32_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWBURST() {
    m_axi_tx_buffer_V_AWBURST = ap_const_lv2_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWCACHE() {
    m_axi_tx_buffer_V_AWCACHE = ap_const_lv4_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWID() {
    m_axi_tx_buffer_V_AWID = ap_const_lv1_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWLEN() {
    m_axi_tx_buffer_V_AWLEN = ap_const_lv32_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWLOCK() {
    m_axi_tx_buffer_V_AWLOCK = ap_const_lv2_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWPROT() {
    m_axi_tx_buffer_V_AWPROT = ap_const_lv3_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWQOS() {
    m_axi_tx_buffer_V_AWQOS = ap_const_lv4_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWREGION() {
    m_axi_tx_buffer_V_AWREGION = ap_const_lv4_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWSIZE() {
    m_axi_tx_buffer_V_AWSIZE = ap_const_lv3_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWUSER() {
    m_axi_tx_buffer_V_AWUSER = ap_const_lv1_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_AWVALID() {
    m_axi_tx_buffer_V_AWVALID = ap_const_logic_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_BREADY() {
    m_axi_tx_buffer_V_BREADY = ap_const_logic_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_RREADY() {
    m_axi_tx_buffer_V_RREADY = read_burst_U0_m_axi_tx_buffer_V_RREADY.read();
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_WDATA() {
    m_axi_tx_buffer_V_WDATA = ap_const_lv64_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_WID() {
    m_axi_tx_buffer_V_WID = ap_const_lv1_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_WLAST() {
    m_axi_tx_buffer_V_WLAST = ap_const_logic_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_WSTRB() {
    m_axi_tx_buffer_V_WSTRB = ap_const_lv8_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_WUSER() {
    m_axi_tx_buffer_V_WUSER = ap_const_lv1_0;
}

void dataflow_in_loop59::thread_m_axi_tx_buffer_V_WVALID() {
    m_axi_tx_buffer_V_WVALID = ap_const_logic_0;
}

void dataflow_in_loop59::thread_read_burst_U0_ap_continue() {
    read_burst_U0_ap_continue = (ap_sync_channel_write_data_length_V.read() & ap_sync_channel_write_cache_V.read());
}

void dataflow_in_loop59::thread_read_burst_U0_ap_start() {
    read_burst_U0_ap_start = ap_start.read();
}

void dataflow_in_loop59::thread_read_burst_U0_cache_V_full_n() {
    read_burst_U0_cache_V_full_n = cache_V_i_full_n.read();
}

void dataflow_in_loop59::thread_read_burst_U0_start_full_n() {
    read_burst_U0_start_full_n = ap_const_logic_1;
}

void dataflow_in_loop59::thread_read_burst_U0_start_write() {
    read_burst_U0_start_write = ap_const_logic_0;
}

void dataflow_in_loop59::thread_tx_axis_words_U0_ap_continue() {
    tx_axis_words_U0_ap_continue = ap_continue.read();
}

void dataflow_in_loop59::thread_tx_axis_words_U0_ap_start() {
    tx_axis_words_U0_ap_start = (cache_V_t_empty_n.read() & data_length_V_empty_n.read());
}

void dataflow_in_loop59::thread_tx_axis_words_U0_start_full_n() {
    tx_axis_words_U0_start_full_n = ap_const_logic_1;
}

void dataflow_in_loop59::thread_tx_axis_words_U0_start_write() {
    tx_axis_words_U0_start_write = ap_const_logic_0;
}

}

