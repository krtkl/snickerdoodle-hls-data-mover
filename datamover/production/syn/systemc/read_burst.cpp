// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.2
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "read_burst.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic read_burst::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic read_burst::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<10> read_burst::ap_ST_fsm_state1 = "1";
const sc_lv<10> read_burst::ap_ST_fsm_state2 = "10";
const sc_lv<10> read_burst::ap_ST_fsm_state3 = "100";
const sc_lv<10> read_burst::ap_ST_fsm_state4 = "1000";
const sc_lv<10> read_burst::ap_ST_fsm_state5 = "10000";
const sc_lv<10> read_burst::ap_ST_fsm_state6 = "100000";
const sc_lv<10> read_burst::ap_ST_fsm_state7 = "1000000";
const sc_lv<10> read_burst::ap_ST_fsm_state8 = "10000000";
const sc_lv<10> read_burst::ap_ST_fsm_pp0_stage0 = "100000000";
const sc_lv<10> read_burst::ap_ST_fsm_state12 = "1000000000";
const sc_lv<32> read_burst::ap_const_lv32_0 = "00000000000000000000000000000000";
const bool read_burst::ap_const_boolean_1 = true;
const sc_lv<1> read_burst::ap_const_lv1_0 = "0";
const sc_lv<3> read_burst::ap_const_lv3_0 = "000";
const sc_lv<2> read_burst::ap_const_lv2_0 = "00";
const sc_lv<4> read_burst::ap_const_lv4_0 = "0000";
const sc_lv<64> read_burst::ap_const_lv64_0 = "0000000000000000000000000000000000000000000000000000000000000000";
const sc_lv<8> read_burst::ap_const_lv8_0 = "00000000";
const sc_lv<32> read_burst::ap_const_lv32_1 = "1";
const sc_lv<32> read_burst::ap_const_lv32_8 = "1000";
const bool read_burst::ap_const_boolean_0 = false;
const sc_lv<32> read_burst::ap_const_lv32_7 = "111";
const sc_lv<1> read_burst::ap_const_lv1_1 = "1";
const sc_lv<10> read_burst::ap_const_lv10_0 = "0000000000";
const sc_lv<32> read_burst::ap_const_lv32_200 = "1000000000";
const sc_lv<9> read_burst::ap_const_lv9_0 = "000000000";
const sc_lv<10> read_burst::ap_const_lv10_200 = "1000000000";
const sc_lv<10> read_burst::ap_const_lv10_1 = "1";
const sc_lv<32> read_burst::ap_const_lv32_9 = "1001";
const sc_lv<13> read_burst::ap_const_lv13_1FFF = "1111111111111";
const sc_lv<13> read_burst::ap_const_lv13_1000 = "1000000000000";
const sc_lv<13> read_burst::ap_const_lv13_0 = "0000000000000";

read_burst::read_burst(sc_module_name name) : sc_module(name), mVcdFile(0) {

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_ap_CS_fsm_pp0_stage0);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state12);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state8);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_block_pp0_stage0);

    SC_METHOD(thread_ap_block_pp0_stage0_11001);
    sensitive << ( m_axi_tx_buffer_V_RVALID );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( exitcond_i_i_reg_251 );

    SC_METHOD(thread_ap_block_pp0_stage0_subdone);
    sensitive << ( m_axi_tx_buffer_V_RVALID );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( exitcond_i_i_reg_251 );

    SC_METHOD(thread_ap_block_state1);
    sensitive << ( ap_start );
    sensitive << ( ap_done_reg );

    SC_METHOD(thread_ap_block_state10_pp0_stage0_iter1);
    sensitive << ( m_axi_tx_buffer_V_RVALID );
    sensitive << ( exitcond_i_i_reg_251 );

    SC_METHOD(thread_ap_block_state11_pp0_stage0_iter2);

    SC_METHOD(thread_ap_block_state9_pp0_stage0_iter0);

    SC_METHOD(thread_ap_condition_pp0_exit_iter0_state9);
    sensitive << ( exitcond_i_i_fu_183_p2 );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_done_reg );
    sensitive << ( ap_CS_fsm_state12 );

    SC_METHOD(thread_ap_enable_pp0);
    sensitive << ( ap_idle_pp0 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_idle_pp0);
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_enable_reg_pp0_iter2 );

    SC_METHOD(thread_ap_phi_mux_indvar_i_i_phi_fu_137_p4);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_block_pp0_stage0 );
    sensitive << ( exitcond_i_i_reg_251 );
    sensitive << ( indvar_i_i_reg_133 );
    sensitive << ( indvar_next_i_i_reg_255 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state12 );

    SC_METHOD(thread_ap_return);
    sensitive << ( ap_CS_fsm_state12 );
    sensitive << ( data_length_V_write_s_fu_218_p3 );
    sensitive << ( ap_return_preg );

    SC_METHOD(thread_ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY);
    sensitive << ( m_axi_tx_buffer_V_ARREADY );
    sensitive << ( ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY );

    SC_METHOD(thread_cache_V_address0);
    sensitive << ( ap_block_pp0_stage0 );
    sensitive << ( ap_enable_reg_pp0_iter2 );
    sensitive << ( indvar4_i_i_fu_195_p1 );

    SC_METHOD(thread_cache_V_ce0);
    sensitive << ( ap_block_pp0_stage0_11001 );
    sensitive << ( ap_enable_reg_pp0_iter2 );

    SC_METHOD(thread_cache_V_d0);
    sensitive << ( ap_block_pp0_stage0 );
    sensitive << ( tx_buffer_V_addr_rea_reg_260 );
    sensitive << ( ap_enable_reg_pp0_iter2 );

    SC_METHOD(thread_cache_V_we0);
    sensitive << ( ap_block_pp0_stage0_11001 );
    sensitive << ( exitcond_i_i_reg_251_pp0_iter1_reg );
    sensitive << ( ap_enable_reg_pp0_iter2 );

    SC_METHOD(thread_data_length_V_write_s_fu_218_p3);
    sensitive << ( final_burst_length_V );
    sensitive << ( tmp_3_i_i_fu_212_p2 );

    SC_METHOD(thread_exitcond_i_i_fu_183_p2);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_block_pp0_stage0_11001 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_phi_mux_indvar_i_i_phi_fu_137_p4 );

    SC_METHOD(thread_indvar4_i_i_fu_195_p1);
    sensitive << ( indvar_i_i_reg_133_pp0_iter1_reg );

    SC_METHOD(thread_indvar_next_i_i_fu_189_p2);
    sensitive << ( ap_phi_mux_indvar_i_i_phi_fu_137_p4 );

    SC_METHOD(thread_lhs_V_cast_i_i_fu_200_p1);
    sensitive << ( loop_count_V );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARADDR);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( sum_cast_i_fu_173_p1 );
    sensitive << ( ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARBURST);

    SC_METHOD(thread_m_axi_tx_buffer_V_ARCACHE);

    SC_METHOD(thread_m_axi_tx_buffer_V_ARID);

    SC_METHOD(thread_m_axi_tx_buffer_V_ARLEN);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY );

    SC_METHOD(thread_m_axi_tx_buffer_V_ARLOCK);

    SC_METHOD(thread_m_axi_tx_buffer_V_ARPROT);

    SC_METHOD(thread_m_axi_tx_buffer_V_ARQOS);

    SC_METHOD(thread_m_axi_tx_buffer_V_ARREGION);

    SC_METHOD(thread_m_axi_tx_buffer_V_ARSIZE);

    SC_METHOD(thread_m_axi_tx_buffer_V_ARUSER);

    SC_METHOD(thread_m_axi_tx_buffer_V_ARVALID);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY );

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
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( exitcond_i_i_reg_251 );
    sensitive << ( ap_block_pp0_stage0_11001 );

    SC_METHOD(thread_m_axi_tx_buffer_V_WDATA);

    SC_METHOD(thread_m_axi_tx_buffer_V_WID);

    SC_METHOD(thread_m_axi_tx_buffer_V_WLAST);

    SC_METHOD(thread_m_axi_tx_buffer_V_WSTRB);

    SC_METHOD(thread_m_axi_tx_buffer_V_WUSER);

    SC_METHOD(thread_m_axi_tx_buffer_V_WVALID);

    SC_METHOD(thread_r_V_fu_203_p2);
    sensitive << ( lhs_V_cast_i_i_fu_200_p1 );

    SC_METHOD(thread_sext_cast_i_fu_163_p1);
    sensitive << ( tx_buffer_V_offset );

    SC_METHOD(thread_sum_cast_i_fu_173_p1);
    sensitive << ( sum_i_reg_230 );

    SC_METHOD(thread_sum_i_fu_167_p2);
    sensitive << ( tmp_8_cast_i_fu_159_p1 );
    sensitive << ( sext_cast_i_fu_163_p1 );

    SC_METHOD(thread_tmp_2_cast_i_i_fu_209_p1);
    sensitive << ( tmp_reg_225 );

    SC_METHOD(thread_tmp_3_i_i_fu_212_p2);
    sensitive << ( ap_CS_fsm_state12 );
    sensitive << ( tmp_2_cast_i_i_fu_209_p1 );
    sensitive << ( r_V_fu_203_p2 );

    SC_METHOD(thread_tmp_7_i_fu_149_p4);
    sensitive << ( tx_buffer_V_offset1 );
    sensitive << ( tmp_fu_145_p1 );

    SC_METHOD(thread_tmp_8_cast_i_fu_159_p1);
    sensitive << ( tmp_7_i_fu_149_p4 );

    SC_METHOD(thread_tmp_fu_145_p1);
    sensitive << ( val_assign );

    SC_METHOD(thread_tx_buffer_V_blk_n_AR);
    sensitive << ( m_axi_tx_buffer_V_ARREADY );
    sensitive << ( ap_CS_fsm_state2 );

    SC_METHOD(thread_tx_buffer_V_blk_n_R);
    sensitive << ( m_axi_tx_buffer_V_RVALID );
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_block_pp0_stage0 );
    sensitive << ( exitcond_i_i_reg_251 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_done_reg );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY );
    sensitive << ( exitcond_i_i_fu_183_p2 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_block_pp0_stage0_subdone );
    sensitive << ( ap_enable_reg_pp0_iter2 );

    ap_done_reg = SC_LOGIC_0;
    ap_CS_fsm = "0000000001";
    ap_enable_reg_pp0_iter1 = SC_LOGIC_0;
    ap_enable_reg_pp0_iter0 = SC_LOGIC_0;
    ap_enable_reg_pp0_iter2 = SC_LOGIC_0;
    ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY = SC_LOGIC_0;
    ap_return_preg = "0000000000000";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "read_burst_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT_HIER__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_continue, "(port)ap_continue");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
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
    sc_trace(mVcdFile, tx_buffer_V_offset1, "(port)tx_buffer_V_offset1");
    sc_trace(mVcdFile, val_assign, "(port)val_assign");
    sc_trace(mVcdFile, loop_count_V, "(port)loop_count_V");
    sc_trace(mVcdFile, final_burst_length_V, "(port)final_burst_length_V");
    sc_trace(mVcdFile, cache_V_address0, "(port)cache_V_address0");
    sc_trace(mVcdFile, cache_V_ce0, "(port)cache_V_ce0");
    sc_trace(mVcdFile, cache_V_we0, "(port)cache_V_we0");
    sc_trace(mVcdFile, cache_V_d0, "(port)cache_V_d0");
    sc_trace(mVcdFile, ap_return, "(port)ap_return");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_done_reg, "ap_done_reg");
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, tx_buffer_V_blk_n_AR, "tx_buffer_V_blk_n_AR");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, tx_buffer_V_blk_n_R, "tx_buffer_V_blk_n_R");
    sc_trace(mVcdFile, ap_CS_fsm_pp0_stage0, "ap_CS_fsm_pp0_stage0");
    sc_trace(mVcdFile, ap_enable_reg_pp0_iter1, "ap_enable_reg_pp0_iter1");
    sc_trace(mVcdFile, ap_block_pp0_stage0, "ap_block_pp0_stage0");
    sc_trace(mVcdFile, exitcond_i_i_reg_251, "exitcond_i_i_reg_251");
    sc_trace(mVcdFile, indvar_i_i_reg_133, "indvar_i_i_reg_133");
    sc_trace(mVcdFile, indvar_i_i_reg_133_pp0_iter1_reg, "indvar_i_i_reg_133_pp0_iter1_reg");
    sc_trace(mVcdFile, ap_block_state9_pp0_stage0_iter0, "ap_block_state9_pp0_stage0_iter0");
    sc_trace(mVcdFile, ap_block_state10_pp0_stage0_iter1, "ap_block_state10_pp0_stage0_iter1");
    sc_trace(mVcdFile, ap_block_state11_pp0_stage0_iter2, "ap_block_state11_pp0_stage0_iter2");
    sc_trace(mVcdFile, ap_block_pp0_stage0_11001, "ap_block_pp0_stage0_11001");
    sc_trace(mVcdFile, tmp_fu_145_p1, "tmp_fu_145_p1");
    sc_trace(mVcdFile, tmp_reg_225, "tmp_reg_225");
    sc_trace(mVcdFile, ap_block_state1, "ap_block_state1");
    sc_trace(mVcdFile, sum_i_fu_167_p2, "sum_i_fu_167_p2");
    sc_trace(mVcdFile, sum_i_reg_230, "sum_i_reg_230");
    sc_trace(mVcdFile, ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY, "ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY");
    sc_trace(mVcdFile, ap_CS_fsm_state8, "ap_CS_fsm_state8");
    sc_trace(mVcdFile, exitcond_i_i_fu_183_p2, "exitcond_i_i_fu_183_p2");
    sc_trace(mVcdFile, exitcond_i_i_reg_251_pp0_iter1_reg, "exitcond_i_i_reg_251_pp0_iter1_reg");
    sc_trace(mVcdFile, indvar_next_i_i_fu_189_p2, "indvar_next_i_i_fu_189_p2");
    sc_trace(mVcdFile, indvar_next_i_i_reg_255, "indvar_next_i_i_reg_255");
    sc_trace(mVcdFile, ap_enable_reg_pp0_iter0, "ap_enable_reg_pp0_iter0");
    sc_trace(mVcdFile, tx_buffer_V_addr_rea_reg_260, "tx_buffer_V_addr_rea_reg_260");
    sc_trace(mVcdFile, ap_block_pp0_stage0_subdone, "ap_block_pp0_stage0_subdone");
    sc_trace(mVcdFile, ap_condition_pp0_exit_iter0_state9, "ap_condition_pp0_exit_iter0_state9");
    sc_trace(mVcdFile, ap_enable_reg_pp0_iter2, "ap_enable_reg_pp0_iter2");
    sc_trace(mVcdFile, ap_phi_mux_indvar_i_i_phi_fu_137_p4, "ap_phi_mux_indvar_i_i_phi_fu_137_p4");
    sc_trace(mVcdFile, indvar4_i_i_fu_195_p1, "indvar4_i_i_fu_195_p1");
    sc_trace(mVcdFile, sum_cast_i_fu_173_p1, "sum_cast_i_fu_173_p1");
    sc_trace(mVcdFile, ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY, "ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY");
    sc_trace(mVcdFile, tmp_7_i_fu_149_p4, "tmp_7_i_fu_149_p4");
    sc_trace(mVcdFile, tmp_8_cast_i_fu_159_p1, "tmp_8_cast_i_fu_159_p1");
    sc_trace(mVcdFile, sext_cast_i_fu_163_p1, "sext_cast_i_fu_163_p1");
    sc_trace(mVcdFile, ap_CS_fsm_state12, "ap_CS_fsm_state12");
    sc_trace(mVcdFile, lhs_V_cast_i_i_fu_200_p1, "lhs_V_cast_i_i_fu_200_p1");
    sc_trace(mVcdFile, tmp_2_cast_i_i_fu_209_p1, "tmp_2_cast_i_i_fu_209_p1");
    sc_trace(mVcdFile, r_V_fu_203_p2, "r_V_fu_203_p2");
    sc_trace(mVcdFile, tmp_3_i_i_fu_212_p2, "tmp_3_i_i_fu_212_p2");
    sc_trace(mVcdFile, data_length_V_write_s_fu_218_p3, "data_length_V_write_s_fu_218_p3");
    sc_trace(mVcdFile, ap_return_preg, "ap_return_preg");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
    sc_trace(mVcdFile, ap_idle_pp0, "ap_idle_pp0");
    sc_trace(mVcdFile, ap_enable_pp0, "ap_enable_pp0");
#endif

    }
}

read_burst::~read_burst() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

}

void read_burst::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_done_reg = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_const_logic_1, ap_continue.read())) {
            ap_done_reg = ap_const_logic_0;
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state12.read())) {
            ap_done_reg = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_condition_pp0_exit_iter0_state9.read()) && 
             esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
             esl_seteq<1,1,1>(ap_const_boolean_0, ap_block_pp0_stage0_subdone.read()))) {
            ap_enable_reg_pp0_iter0 = ap_const_logic_0;
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read())) {
            ap_enable_reg_pp0_iter0 = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter1 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_const_boolean_0, ap_block_pp0_stage0_subdone.read())) {
            if (esl_seteq<1,1,1>(ap_const_logic_1, ap_condition_pp0_exit_iter0_state9.read())) {
                ap_enable_reg_pp0_iter1 = (ap_condition_pp0_exit_iter0_state9.read() ^ ap_const_logic_1);
            } else if (esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1)) {
                ap_enable_reg_pp0_iter1 = ap_enable_reg_pp0_iter0.read();
            }
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter2 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_const_boolean_0, ap_block_pp0_stage0_subdone.read())) {
            ap_enable_reg_pp0_iter2 = ap_enable_reg_pp0_iter1.read();
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read())) {
            ap_enable_reg_pp0_iter2 = ap_const_logic_0;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
            if (esl_seteq<1,1,1>(ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY.read(), ap_const_logic_1)) {
                ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY = ap_const_logic_0;
            } else if (esl_seteq<1,1,1>(ap_const_logic_1, m_axi_tx_buffer_V_ARREADY.read())) {
                ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY = ap_const_logic_1;
            }
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_return_preg = ap_const_lv13_0;
    } else {
        if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state12.read())) {
            ap_return_preg = data_length_V_write_s_fu_218_p3.read();
        }
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_i_i_reg_251.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0))) {
        indvar_i_i_reg_133 = indvar_next_i_i_reg_255.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read())) {
        indvar_i_i_reg_133 = ap_const_lv10_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0))) {
        exitcond_i_i_reg_251 = exitcond_i_i_fu_183_p2.read();
        exitcond_i_i_reg_251_pp0_iter1_reg = exitcond_i_i_reg_251.read();
        indvar_i_i_reg_133_pp0_iter1_reg = indvar_i_i_reg_133.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_enable_reg_pp0_iter0.read(), ap_const_logic_1))) {
        indvar_next_i_i_reg_255 = indvar_next_i_i_fu_189_p2.read();
    }
    if ((!(esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1)) && esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        sum_i_reg_230 = sum_i_fu_167_p2.read();
        tmp_reg_225 = tmp_fu_145_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_i_i_reg_251.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0))) {
        tx_buffer_V_addr_rea_reg_260 = m_axi_tx_buffer_V_RDATA.read();
    }
}

void read_burst::thread_ap_CS_fsm_pp0_stage0() {
    ap_CS_fsm_pp0_stage0 = ap_CS_fsm.read()[8];
}

void read_burst::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void read_burst::thread_ap_CS_fsm_state12() {
    ap_CS_fsm_state12 = ap_CS_fsm.read()[9];
}

void read_burst::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void read_burst::thread_ap_CS_fsm_state8() {
    ap_CS_fsm_state8 = ap_CS_fsm.read()[7];
}

void read_burst::thread_ap_block_pp0_stage0() {
    ap_block_pp0_stage0 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void read_burst::thread_ap_block_pp0_stage0_11001() {
    ap_block_pp0_stage0_11001 = (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_i_i_reg_251.read()) && esl_seteq<1,1,1>(ap_const_logic_0, m_axi_tx_buffer_V_RVALID.read()));
}

void read_burst::thread_ap_block_pp0_stage0_subdone() {
    ap_block_pp0_stage0_subdone = (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_i_i_reg_251.read()) && esl_seteq<1,1,1>(ap_const_logic_0, m_axi_tx_buffer_V_RVALID.read()));
}

void read_burst::thread_ap_block_state1() {
    ap_block_state1 = (esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1));
}

void read_burst::thread_ap_block_state10_pp0_stage0_iter1() {
    ap_block_state10_pp0_stage0_iter1 = (esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_i_i_reg_251.read()) && esl_seteq<1,1,1>(ap_const_logic_0, m_axi_tx_buffer_V_RVALID.read()));
}

void read_burst::thread_ap_block_state11_pp0_stage0_iter2() {
    ap_block_state11_pp0_stage0_iter2 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void read_burst::thread_ap_block_state9_pp0_stage0_iter0() {
    ap_block_state9_pp0_stage0_iter0 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void read_burst::thread_ap_condition_pp0_exit_iter0_state9() {
    if (esl_seteq<1,1,1>(exitcond_i_i_fu_183_p2.read(), ap_const_lv1_1)) {
        ap_condition_pp0_exit_iter0_state9 = ap_const_logic_1;
    } else {
        ap_condition_pp0_exit_iter0_state9 = ap_const_logic_0;
    }
}

void read_burst::thread_ap_done() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state12.read())) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_done_reg.read();
    }
}

void read_burst::thread_ap_enable_pp0() {
    ap_enable_pp0 = (ap_idle_pp0.read() ^ ap_const_logic_1);
}

void read_burst::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void read_burst::thread_ap_idle_pp0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_enable_reg_pp0_iter0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_enable_reg_pp0_iter2.read()))) {
        ap_idle_pp0 = ap_const_logic_1;
    } else {
        ap_idle_pp0 = ap_const_logic_0;
    }
}

void read_burst::thread_ap_phi_mux_indvar_i_i_phi_fu_137_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_i_i_reg_251.read()))) {
        ap_phi_mux_indvar_i_i_phi_fu_137_p4 = indvar_next_i_i_reg_255.read();
    } else {
        ap_phi_mux_indvar_i_i_phi_fu_137_p4 = indvar_i_i_reg_133.read();
    }
}

void read_burst::thread_ap_ready() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state12.read())) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void read_burst::thread_ap_return() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state12.read())) {
        ap_return = data_length_V_write_s_fu_218_p3.read();
    } else {
        ap_return = ap_return_preg.read();
    }
}

void read_burst::thread_ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY() {
    if (esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY.read())) {
        ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY = m_axi_tx_buffer_V_ARREADY.read();
    } else {
        ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY = ap_const_logic_1;
    }
}

void read_burst::thread_cache_V_address0() {
    cache_V_address0 =  (sc_lv<9>) (indvar4_i_i_fu_195_p1.read());
}

void read_burst::thread_cache_V_ce0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_enable_reg_pp0_iter2.read(), ap_const_logic_1))) {
        cache_V_ce0 = ap_const_logic_1;
    } else {
        cache_V_ce0 = ap_const_logic_0;
    }
}

void read_burst::thread_cache_V_d0() {
    cache_V_d0 = tx_buffer_V_addr_rea_reg_260.read();
}

void read_burst::thread_cache_V_we0() {
    if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_enable_reg_pp0_iter2.read(), ap_const_logic_1) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_i_i_reg_251_pp0_iter1_reg.read()))) {
        cache_V_we0 = ap_const_logic_1;
    } else {
        cache_V_we0 = ap_const_logic_0;
    }
}

void read_burst::thread_data_length_V_write_s_fu_218_p3() {
    data_length_V_write_s_fu_218_p3 = (!tmp_3_i_i_fu_212_p2.read()[0].is_01())? sc_lv<13>(): ((tmp_3_i_i_fu_212_p2.read()[0].to_bool())? final_burst_length_V.read(): ap_const_lv13_1000);
}

void read_burst::thread_exitcond_i_i_fu_183_p2() {
    exitcond_i_i_fu_183_p2 = (!ap_phi_mux_indvar_i_i_phi_fu_137_p4.read().is_01() || !ap_const_lv10_200.is_01())? sc_lv<1>(): sc_lv<1>(ap_phi_mux_indvar_i_i_phi_fu_137_p4.read() == ap_const_lv10_200);
}

void read_burst::thread_indvar4_i_i_fu_195_p1() {
    indvar4_i_i_fu_195_p1 = esl_zext<64,10>(indvar_i_i_reg_133_pp0_iter1_reg.read());
}

void read_burst::thread_indvar_next_i_i_fu_189_p2() {
    indvar_next_i_i_fu_189_p2 = (!ap_phi_mux_indvar_i_i_phi_fu_137_p4.read().is_01() || !ap_const_lv10_1.is_01())? sc_lv<10>(): (sc_biguint<10>(ap_phi_mux_indvar_i_i_phi_fu_137_p4.read()) + sc_biguint<10>(ap_const_lv10_1));
}

void read_burst::thread_lhs_V_cast_i_i_fu_200_p1() {
    lhs_V_cast_i_i_fu_200_p1 = esl_zext<13,12>(loop_count_V.read());
}

void read_burst::thread_m_axi_tx_buffer_V_ARADDR() {
    m_axi_tx_buffer_V_ARADDR =  (sc_lv<32>) (sum_cast_i_fu_173_p1.read());
}

void read_burst::thread_m_axi_tx_buffer_V_ARBURST() {
    m_axi_tx_buffer_V_ARBURST = ap_const_lv2_0;
}

void read_burst::thread_m_axi_tx_buffer_V_ARCACHE() {
    m_axi_tx_buffer_V_ARCACHE = ap_const_lv4_0;
}

void read_burst::thread_m_axi_tx_buffer_V_ARID() {
    m_axi_tx_buffer_V_ARID = ap_const_lv1_0;
}

void read_burst::thread_m_axi_tx_buffer_V_ARLEN() {
    m_axi_tx_buffer_V_ARLEN = ap_const_lv32_200;
}

void read_burst::thread_m_axi_tx_buffer_V_ARLOCK() {
    m_axi_tx_buffer_V_ARLOCK = ap_const_lv2_0;
}

void read_burst::thread_m_axi_tx_buffer_V_ARPROT() {
    m_axi_tx_buffer_V_ARPROT = ap_const_lv3_0;
}

void read_burst::thread_m_axi_tx_buffer_V_ARQOS() {
    m_axi_tx_buffer_V_ARQOS = ap_const_lv4_0;
}

void read_burst::thread_m_axi_tx_buffer_V_ARREGION() {
    m_axi_tx_buffer_V_ARREGION = ap_const_lv4_0;
}

void read_burst::thread_m_axi_tx_buffer_V_ARSIZE() {
    m_axi_tx_buffer_V_ARSIZE = ap_const_lv3_0;
}

void read_burst::thread_m_axi_tx_buffer_V_ARUSER() {
    m_axi_tx_buffer_V_ARUSER = ap_const_lv1_0;
}

void read_burst::thread_m_axi_tx_buffer_V_ARVALID() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY.read()))) {
        m_axi_tx_buffer_V_ARVALID = ap_const_logic_1;
    } else {
        m_axi_tx_buffer_V_ARVALID = ap_const_logic_0;
    }
}

void read_burst::thread_m_axi_tx_buffer_V_AWADDR() {
    m_axi_tx_buffer_V_AWADDR = ap_const_lv32_0;
}

void read_burst::thread_m_axi_tx_buffer_V_AWBURST() {
    m_axi_tx_buffer_V_AWBURST = ap_const_lv2_0;
}

void read_burst::thread_m_axi_tx_buffer_V_AWCACHE() {
    m_axi_tx_buffer_V_AWCACHE = ap_const_lv4_0;
}

void read_burst::thread_m_axi_tx_buffer_V_AWID() {
    m_axi_tx_buffer_V_AWID = ap_const_lv1_0;
}

void read_burst::thread_m_axi_tx_buffer_V_AWLEN() {
    m_axi_tx_buffer_V_AWLEN = ap_const_lv32_0;
}

void read_burst::thread_m_axi_tx_buffer_V_AWLOCK() {
    m_axi_tx_buffer_V_AWLOCK = ap_const_lv2_0;
}

void read_burst::thread_m_axi_tx_buffer_V_AWPROT() {
    m_axi_tx_buffer_V_AWPROT = ap_const_lv3_0;
}

void read_burst::thread_m_axi_tx_buffer_V_AWQOS() {
    m_axi_tx_buffer_V_AWQOS = ap_const_lv4_0;
}

void read_burst::thread_m_axi_tx_buffer_V_AWREGION() {
    m_axi_tx_buffer_V_AWREGION = ap_const_lv4_0;
}

void read_burst::thread_m_axi_tx_buffer_V_AWSIZE() {
    m_axi_tx_buffer_V_AWSIZE = ap_const_lv3_0;
}

void read_burst::thread_m_axi_tx_buffer_V_AWUSER() {
    m_axi_tx_buffer_V_AWUSER = ap_const_lv1_0;
}

void read_burst::thread_m_axi_tx_buffer_V_AWVALID() {
    m_axi_tx_buffer_V_AWVALID = ap_const_logic_0;
}

void read_burst::thread_m_axi_tx_buffer_V_BREADY() {
    m_axi_tx_buffer_V_BREADY = ap_const_logic_0;
}

void read_burst::thread_m_axi_tx_buffer_V_RREADY() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_i_i_reg_251.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0))) {
        m_axi_tx_buffer_V_RREADY = ap_const_logic_1;
    } else {
        m_axi_tx_buffer_V_RREADY = ap_const_logic_0;
    }
}

void read_burst::thread_m_axi_tx_buffer_V_WDATA() {
    m_axi_tx_buffer_V_WDATA = ap_const_lv64_0;
}

void read_burst::thread_m_axi_tx_buffer_V_WID() {
    m_axi_tx_buffer_V_WID = ap_const_lv1_0;
}

void read_burst::thread_m_axi_tx_buffer_V_WLAST() {
    m_axi_tx_buffer_V_WLAST = ap_const_logic_0;
}

void read_burst::thread_m_axi_tx_buffer_V_WSTRB() {
    m_axi_tx_buffer_V_WSTRB = ap_const_lv8_0;
}

void read_burst::thread_m_axi_tx_buffer_V_WUSER() {
    m_axi_tx_buffer_V_WUSER = ap_const_lv1_0;
}

void read_burst::thread_m_axi_tx_buffer_V_WVALID() {
    m_axi_tx_buffer_V_WVALID = ap_const_logic_0;
}

void read_burst::thread_r_V_fu_203_p2() {
    r_V_fu_203_p2 = (!lhs_V_cast_i_i_fu_200_p1.read().is_01() || !ap_const_lv13_1FFF.is_01())? sc_lv<13>(): (sc_biguint<13>(lhs_V_cast_i_i_fu_200_p1.read()) + sc_bigint<13>(ap_const_lv13_1FFF));
}

void read_burst::thread_sext_cast_i_fu_163_p1() {
    sext_cast_i_fu_163_p1 = esl_zext<30,29>(tx_buffer_V_offset.read());
}

void read_burst::thread_sum_cast_i_fu_173_p1() {
    sum_cast_i_fu_173_p1 = esl_zext<64,30>(sum_i_reg_230.read());
}

void read_burst::thread_sum_i_fu_167_p2() {
    sum_i_fu_167_p2 = (!tmp_8_cast_i_fu_159_p1.read().is_01() || !sext_cast_i_fu_163_p1.read().is_01())? sc_lv<30>(): (sc_biguint<30>(tmp_8_cast_i_fu_159_p1.read()) + sc_biguint<30>(sext_cast_i_fu_163_p1.read()));
}

void read_burst::thread_tmp_2_cast_i_i_fu_209_p1() {
    tmp_2_cast_i_i_fu_209_p1 = esl_zext<13,11>(tmp_reg_225.read());
}

void read_burst::thread_tmp_3_i_i_fu_212_p2() {
    tmp_3_i_i_fu_212_p2 = (!tmp_2_cast_i_i_fu_209_p1.read().is_01() || !r_V_fu_203_p2.read().is_01())? sc_lv<1>(): sc_lv<1>(tmp_2_cast_i_i_fu_209_p1.read() == r_V_fu_203_p2.read());
}

void read_burst::thread_tmp_7_i_fu_149_p4() {
    tmp_7_i_fu_149_p4 = esl_concat<12,9>(esl_concat<1,11>(tx_buffer_V_offset1.read(), tmp_fu_145_p1.read()), ap_const_lv9_0);
}

void read_burst::thread_tmp_8_cast_i_fu_159_p1() {
    tmp_8_cast_i_fu_159_p1 = esl_zext<30,21>(tmp_7_i_fu_149_p4.read());
}

void read_burst::thread_tmp_fu_145_p1() {
    tmp_fu_145_p1 = val_assign.read().range(11-1, 0);
}

void read_burst::thread_tx_buffer_V_blk_n_AR() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        tx_buffer_V_blk_n_AR = m_axi_tx_buffer_V_ARREADY.read();
    } else {
        tx_buffer_V_blk_n_AR = ap_const_logic_1;
    }
}

void read_burst::thread_tx_buffer_V_blk_n_R() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_i_i_reg_251.read()))) {
        tx_buffer_V_blk_n_R = m_axi_tx_buffer_V_RVALID.read();
    } else {
        tx_buffer_V_blk_n_R = ap_const_logic_1;
    }
}

void read_burst::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((!(esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1)) && esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state3;
            } else {
                ap_NS_fsm = ap_ST_fsm_state2;
            }
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_fsm_state4;
            break;
        case 8 : 
            ap_NS_fsm = ap_ST_fsm_state5;
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_fsm_state6;
            break;
        case 32 : 
            ap_NS_fsm = ap_ST_fsm_state7;
            break;
        case 64 : 
            ap_NS_fsm = ap_ST_fsm_state8;
            break;
        case 128 : 
            ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            break;
        case 256 : 
            if ((!(esl_seteq<1,1,1>(ap_enable_reg_pp0_iter0.read(), ap_const_logic_1) && esl_seteq<1,1,1>(ap_const_boolean_0, ap_block_pp0_stage0_subdone.read()) && esl_seteq<1,1,1>(exitcond_i_i_fu_183_p2.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_enable_reg_pp0_iter1.read(), ap_const_logic_0)) && !(esl_seteq<1,1,1>(ap_enable_reg_pp0_iter2.read(), ap_const_logic_1) && esl_seteq<1,1,1>(ap_const_boolean_0, ap_block_pp0_stage0_subdone.read()) && esl_seteq<1,1,1>(ap_enable_reg_pp0_iter1.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            } else if (((esl_seteq<1,1,1>(ap_enable_reg_pp0_iter2.read(), ap_const_logic_1) && 
  esl_seteq<1,1,1>(ap_const_boolean_0, ap_block_pp0_stage0_subdone.read()) && 
  esl_seteq<1,1,1>(ap_enable_reg_pp0_iter1.read(), ap_const_logic_0)) || (esl_seteq<1,1,1>(ap_enable_reg_pp0_iter0.read(), ap_const_logic_1) && 
  esl_seteq<1,1,1>(ap_const_boolean_0, ap_block_pp0_stage0_subdone.read()) && 
  esl_seteq<1,1,1>(exitcond_i_i_fu_183_p2.read(), ap_const_lv1_1) && 
  esl_seteq<1,1,1>(ap_enable_reg_pp0_iter1.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_state12;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            }
            break;
        case 512 : 
            ap_NS_fsm = ap_ST_fsm_state1;
            break;
        default : 
            ap_NS_fsm = "XXXXXXXXXX";
            break;
    }
}

}

