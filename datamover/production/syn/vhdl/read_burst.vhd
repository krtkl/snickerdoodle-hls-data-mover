-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2018.1
-- Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity read_burst is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_continue : IN STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    m_axi_tx_buffer_V_AWVALID : OUT STD_LOGIC;
    m_axi_tx_buffer_V_AWREADY : IN STD_LOGIC;
    m_axi_tx_buffer_V_AWADDR : OUT STD_LOGIC_VECTOR (31 downto 0);
    m_axi_tx_buffer_V_AWID : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_tx_buffer_V_AWLEN : OUT STD_LOGIC_VECTOR (31 downto 0);
    m_axi_tx_buffer_V_AWSIZE : OUT STD_LOGIC_VECTOR (2 downto 0);
    m_axi_tx_buffer_V_AWBURST : OUT STD_LOGIC_VECTOR (1 downto 0);
    m_axi_tx_buffer_V_AWLOCK : OUT STD_LOGIC_VECTOR (1 downto 0);
    m_axi_tx_buffer_V_AWCACHE : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_tx_buffer_V_AWPROT : OUT STD_LOGIC_VECTOR (2 downto 0);
    m_axi_tx_buffer_V_AWQOS : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_tx_buffer_V_AWREGION : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_tx_buffer_V_AWUSER : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_tx_buffer_V_WVALID : OUT STD_LOGIC;
    m_axi_tx_buffer_V_WREADY : IN STD_LOGIC;
    m_axi_tx_buffer_V_WDATA : OUT STD_LOGIC_VECTOR (63 downto 0);
    m_axi_tx_buffer_V_WSTRB : OUT STD_LOGIC_VECTOR (7 downto 0);
    m_axi_tx_buffer_V_WLAST : OUT STD_LOGIC;
    m_axi_tx_buffer_V_WID : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_tx_buffer_V_WUSER : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_tx_buffer_V_ARVALID : OUT STD_LOGIC;
    m_axi_tx_buffer_V_ARREADY : IN STD_LOGIC;
    m_axi_tx_buffer_V_ARADDR : OUT STD_LOGIC_VECTOR (31 downto 0);
    m_axi_tx_buffer_V_ARID : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_tx_buffer_V_ARLEN : OUT STD_LOGIC_VECTOR (31 downto 0);
    m_axi_tx_buffer_V_ARSIZE : OUT STD_LOGIC_VECTOR (2 downto 0);
    m_axi_tx_buffer_V_ARBURST : OUT STD_LOGIC_VECTOR (1 downto 0);
    m_axi_tx_buffer_V_ARLOCK : OUT STD_LOGIC_VECTOR (1 downto 0);
    m_axi_tx_buffer_V_ARCACHE : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_tx_buffer_V_ARPROT : OUT STD_LOGIC_VECTOR (2 downto 0);
    m_axi_tx_buffer_V_ARQOS : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_tx_buffer_V_ARREGION : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_tx_buffer_V_ARUSER : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_tx_buffer_V_RVALID : IN STD_LOGIC;
    m_axi_tx_buffer_V_RREADY : OUT STD_LOGIC;
    m_axi_tx_buffer_V_RDATA : IN STD_LOGIC_VECTOR (63 downto 0);
    m_axi_tx_buffer_V_RLAST : IN STD_LOGIC;
    m_axi_tx_buffer_V_RID : IN STD_LOGIC_VECTOR (0 downto 0);
    m_axi_tx_buffer_V_RUSER : IN STD_LOGIC_VECTOR (0 downto 0);
    m_axi_tx_buffer_V_RRESP : IN STD_LOGIC_VECTOR (1 downto 0);
    m_axi_tx_buffer_V_BVALID : IN STD_LOGIC;
    m_axi_tx_buffer_V_BREADY : OUT STD_LOGIC;
    m_axi_tx_buffer_V_BRESP : IN STD_LOGIC_VECTOR (1 downto 0);
    m_axi_tx_buffer_V_BID : IN STD_LOGIC_VECTOR (0 downto 0);
    m_axi_tx_buffer_V_BUSER : IN STD_LOGIC_VECTOR (0 downto 0);
    tx_buffer_V_offset : IN STD_LOGIC_VECTOR (28 downto 0);
    tx_buffer_V_offset1 : IN STD_LOGIC_VECTOR (0 downto 0);
    val_assign : IN STD_LOGIC_VECTOR (11 downto 0);
    loop_count_V : IN STD_LOGIC_VECTOR (11 downto 0);
    final_burst_length_V : IN STD_LOGIC_VECTOR (12 downto 0);
    cache_V_address0 : OUT STD_LOGIC_VECTOR (8 downto 0);
    cache_V_ce0 : OUT STD_LOGIC;
    cache_V_we0 : OUT STD_LOGIC;
    cache_V_d0 : OUT STD_LOGIC_VECTOR (63 downto 0);
    ap_return : OUT STD_LOGIC_VECTOR (12 downto 0) );
end;


architecture behav of read_burst is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (9 downto 0) := "0000000001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (9 downto 0) := "0000000010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (9 downto 0) := "0000000100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (9 downto 0) := "0000001000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (9 downto 0) := "0000010000";
    constant ap_ST_fsm_state6 : STD_LOGIC_VECTOR (9 downto 0) := "0000100000";
    constant ap_ST_fsm_state7 : STD_LOGIC_VECTOR (9 downto 0) := "0001000000";
    constant ap_ST_fsm_state8 : STD_LOGIC_VECTOR (9 downto 0) := "0010000000";
    constant ap_ST_fsm_pp0_stage0 : STD_LOGIC_VECTOR (9 downto 0) := "0100000000";
    constant ap_ST_fsm_state12 : STD_LOGIC_VECTOR (9 downto 0) := "1000000000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv3_0 : STD_LOGIC_VECTOR (2 downto 0) := "000";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv4_0 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
    constant ap_const_lv64_0 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000";
    constant ap_const_lv8_0 : STD_LOGIC_VECTOR (7 downto 0) := "00000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv32_8 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001000";
    constant ap_const_boolean_0 : BOOLEAN := false;
    constant ap_const_lv32_7 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000111";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv10_0 : STD_LOGIC_VECTOR (9 downto 0) := "0000000000";
    constant ap_const_lv32_200 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000001000000000";
    constant ap_const_lv9_0 : STD_LOGIC_VECTOR (8 downto 0) := "000000000";
    constant ap_const_lv10_200 : STD_LOGIC_VECTOR (9 downto 0) := "1000000000";
    constant ap_const_lv10_1 : STD_LOGIC_VECTOR (9 downto 0) := "0000000001";
    constant ap_const_lv32_9 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001001";
    constant ap_const_lv13_1FFF : STD_LOGIC_VECTOR (12 downto 0) := "1111111111111";
    constant ap_const_lv13_1000 : STD_LOGIC_VECTOR (12 downto 0) := "1000000000000";
    constant ap_const_lv13_0 : STD_LOGIC_VECTOR (12 downto 0) := "0000000000000";

    signal ap_done_reg : STD_LOGIC := '0';
    signal ap_CS_fsm : STD_LOGIC_VECTOR (9 downto 0) := "0000000001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal tx_buffer_V_blk_n_AR : STD_LOGIC;
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal tx_buffer_V_blk_n_R : STD_LOGIC;
    signal ap_CS_fsm_pp0_stage0 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp0_stage0 : signal is "none";
    signal ap_enable_reg_pp0_iter1 : STD_LOGIC := '0';
    signal ap_block_pp0_stage0 : BOOLEAN;
    signal exitcond_i_i_reg_250 : STD_LOGIC_VECTOR (0 downto 0);
    signal indvar_i_i_reg_132 : STD_LOGIC_VECTOR (9 downto 0);
    signal indvar_i_i_reg_132_pp0_iter1_reg : STD_LOGIC_VECTOR (9 downto 0);
    signal ap_block_state9_pp0_stage0_iter0 : BOOLEAN;
    signal ap_block_state10_pp0_stage0_iter1 : BOOLEAN;
    signal ap_block_state11_pp0_stage0_iter2 : BOOLEAN;
    signal ap_block_pp0_stage0_11001 : BOOLEAN;
    signal tmp_fu_144_p1 : STD_LOGIC_VECTOR (10 downto 0);
    signal tmp_reg_224 : STD_LOGIC_VECTOR (10 downto 0);
    signal ap_block_state1 : BOOLEAN;
    signal sum_i_fu_166_p2 : STD_LOGIC_VECTOR (29 downto 0);
    signal sum_i_reg_229 : STD_LOGIC_VECTOR (29 downto 0);
    signal ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY : STD_LOGIC;
    signal ap_CS_fsm_state8 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state8 : signal is "none";
    signal exitcond_i_i_fu_182_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal exitcond_i_i_reg_250_pp0_iter1_reg : STD_LOGIC_VECTOR (0 downto 0);
    signal indvar_next_i_i_fu_188_p2 : STD_LOGIC_VECTOR (9 downto 0);
    signal indvar_next_i_i_reg_254 : STD_LOGIC_VECTOR (9 downto 0);
    signal ap_enable_reg_pp0_iter0 : STD_LOGIC := '0';
    signal tx_buffer_V_addr_rea_reg_259 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_block_pp0_stage0_subdone : BOOLEAN;
    signal ap_condition_pp0_exit_iter0_state9 : STD_LOGIC;
    signal ap_enable_reg_pp0_iter2 : STD_LOGIC := '0';
    signal ap_phi_mux_indvar_i_i_phi_fu_136_p4 : STD_LOGIC_VECTOR (9 downto 0);
    signal indvar4_i_i_fu_194_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal sum_cast_i_fu_172_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY : STD_LOGIC := '0';
    signal tmp_7_i_fu_148_p4 : STD_LOGIC_VECTOR (20 downto 0);
    signal tmp_8_cast_i_fu_158_p1 : STD_LOGIC_VECTOR (29 downto 0);
    signal sext_cast_i_fu_162_p1 : STD_LOGIC_VECTOR (29 downto 0);
    signal ap_CS_fsm_state12 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state12 : signal is "none";
    signal lhs_V_cast_i_i_fu_199_p1 : STD_LOGIC_VECTOR (12 downto 0);
    signal tmp_2_cast_i_i_fu_208_p1 : STD_LOGIC_VECTOR (12 downto 0);
    signal r_V_fu_202_p2 : STD_LOGIC_VECTOR (12 downto 0);
    signal tmp_3_i_i_fu_211_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal data_length_V_write_s_fu_217_p3 : STD_LOGIC_VECTOR (12 downto 0);
    signal ap_return_preg : STD_LOGIC_VECTOR (12 downto 0) := "0000000000000";
    signal ap_NS_fsm : STD_LOGIC_VECTOR (9 downto 0);
    signal ap_idle_pp0 : STD_LOGIC;
    signal ap_enable_pp0 : STD_LOGIC;


begin




    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    ap_done_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_done_reg <= ap_const_logic_0;
            else
                if ((ap_continue = ap_const_logic_1)) then 
                    ap_done_reg <= ap_const_logic_0;
                elsif ((ap_const_logic_1 = ap_CS_fsm_state12)) then 
                    ap_done_reg <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter0_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter0 <= ap_const_logic_0;
            else
                if (((ap_const_logic_1 = ap_condition_pp0_exit_iter0_state9) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone))) then 
                    ap_enable_reg_pp0_iter0 <= ap_const_logic_0;
                elsif ((ap_const_logic_1 = ap_CS_fsm_state8)) then 
                    ap_enable_reg_pp0_iter0 <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter1_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter1 <= ap_const_logic_0;
            else
                if ((ap_const_boolean_0 = ap_block_pp0_stage0_subdone)) then
                    if ((ap_const_logic_1 = ap_condition_pp0_exit_iter0_state9)) then 
                        ap_enable_reg_pp0_iter1 <= (ap_const_logic_1 xor ap_condition_pp0_exit_iter0_state9);
                    elsif ((ap_const_boolean_1 = ap_const_boolean_1)) then 
                        ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
                    end if;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter2_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter2 <= ap_const_logic_0;
            else
                if ((ap_const_boolean_0 = ap_block_pp0_stage0_subdone)) then 
                    ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
                elsif ((ap_const_logic_1 = ap_CS_fsm_state8)) then 
                    ap_enable_reg_pp0_iter2 <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY <= ap_const_logic_0;
            else
                if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
                    if ((ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY = ap_const_logic_1)) then 
                        ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY <= ap_const_logic_0;
                    elsif ((m_axi_tx_buffer_V_ARREADY = ap_const_logic_1)) then 
                        ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY <= ap_const_logic_1;
                    end if;
                end if; 
            end if;
        end if;
    end process;


    ap_return_preg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_return_preg <= ap_const_lv13_0;
            else
                if ((ap_const_logic_1 = ap_CS_fsm_state12)) then 
                    ap_return_preg <= data_length_V_write_s_fu_217_p3;
                end if; 
            end if;
        end if;
    end process;


    indvar_i_i_reg_132_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond_i_i_reg_250 = ap_const_lv1_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then 
                indvar_i_i_reg_132 <= indvar_next_i_i_reg_254;
            elsif ((ap_const_logic_1 = ap_CS_fsm_state8)) then 
                indvar_i_i_reg_132 <= ap_const_lv10_0;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then
                exitcond_i_i_reg_250 <= exitcond_i_i_fu_182_p2;
                exitcond_i_i_reg_250_pp0_iter1_reg <= exitcond_i_i_reg_250;
                indvar_i_i_reg_132_pp0_iter1_reg <= indvar_i_i_reg_132;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then
                indvar_next_i_i_reg_254 <= indvar_next_i_i_fu_188_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((not(((ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                sum_i_reg_229 <= sum_i_fu_166_p2;
                tmp_reg_224 <= tmp_fu_144_p1;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond_i_i_reg_250 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then
                tx_buffer_V_addr_rea_reg_259 <= m_axi_tx_buffer_V_RDATA;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_done_reg, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, ap_enable_reg_pp0_iter1, ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY, exitcond_i_i_fu_182_p2, ap_enable_reg_pp0_iter0, ap_block_pp0_stage0_subdone, ap_enable_reg_pp0_iter2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if ((not(((ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state2) and (ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state3;
                else
                    ap_NS_fsm <= ap_ST_fsm_state2;
                end if;
            when ap_ST_fsm_state3 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when ap_ST_fsm_state4 => 
                ap_NS_fsm <= ap_ST_fsm_state5;
            when ap_ST_fsm_state5 => 
                ap_NS_fsm <= ap_ST_fsm_state6;
            when ap_ST_fsm_state6 => 
                ap_NS_fsm <= ap_ST_fsm_state7;
            when ap_ST_fsm_state7 => 
                ap_NS_fsm <= ap_ST_fsm_state8;
            when ap_ST_fsm_state8 => 
                ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
            when ap_ST_fsm_pp0_stage0 => 
                if ((not(((ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (exitcond_i_i_fu_182_p2 = ap_const_lv1_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0))) and not(((ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0))))) then
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                elsif ((((ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0)) or ((ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (exitcond_i_i_fu_182_p2 = ap_const_lv1_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0)))) then
                    ap_NS_fsm <= ap_ST_fsm_state12;
                else
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                end if;
            when ap_ST_fsm_state12 => 
                ap_NS_fsm <= ap_ST_fsm_state1;
            when others =>  
                ap_NS_fsm <= "XXXXXXXXXX";
        end case;
    end process;
    ap_CS_fsm_pp0_stage0 <= ap_CS_fsm(8);
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state12 <= ap_CS_fsm(9);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state8 <= ap_CS_fsm(7);
        ap_block_pp0_stage0 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_block_pp0_stage0_11001_assign_proc : process(m_axi_tx_buffer_V_RVALID, ap_enable_reg_pp0_iter1, exitcond_i_i_reg_250)
    begin
                ap_block_pp0_stage0_11001 <= ((exitcond_i_i_reg_250 = ap_const_lv1_0) and (m_axi_tx_buffer_V_RVALID = ap_const_logic_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1));
    end process;


    ap_block_pp0_stage0_subdone_assign_proc : process(m_axi_tx_buffer_V_RVALID, ap_enable_reg_pp0_iter1, exitcond_i_i_reg_250)
    begin
                ap_block_pp0_stage0_subdone <= ((exitcond_i_i_reg_250 = ap_const_lv1_0) and (m_axi_tx_buffer_V_RVALID = ap_const_logic_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1));
    end process;


    ap_block_state1_assign_proc : process(ap_start, ap_done_reg)
    begin
                ap_block_state1 <= ((ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1));
    end process;


    ap_block_state10_pp0_stage0_iter1_assign_proc : process(m_axi_tx_buffer_V_RVALID, exitcond_i_i_reg_250)
    begin
                ap_block_state10_pp0_stage0_iter1 <= ((exitcond_i_i_reg_250 = ap_const_lv1_0) and (m_axi_tx_buffer_V_RVALID = ap_const_logic_0));
    end process;

        ap_block_state11_pp0_stage0_iter2 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state9_pp0_stage0_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_condition_pp0_exit_iter0_state9_assign_proc : process(exitcond_i_i_fu_182_p2)
    begin
        if ((exitcond_i_i_fu_182_p2 = ap_const_lv1_1)) then 
            ap_condition_pp0_exit_iter0_state9 <= ap_const_logic_1;
        else 
            ap_condition_pp0_exit_iter0_state9 <= ap_const_logic_0;
        end if; 
    end process;


    ap_done_assign_proc : process(ap_done_reg, ap_CS_fsm_state12)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state12)) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_done_reg;
        end if; 
    end process;

    ap_enable_pp0 <= (ap_idle_pp0 xor ap_const_logic_1);

    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_pp0_assign_proc : process(ap_enable_reg_pp0_iter1, ap_enable_reg_pp0_iter0, ap_enable_reg_pp0_iter2)
    begin
        if (((ap_enable_reg_pp0_iter2 = ap_const_logic_0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0))) then 
            ap_idle_pp0 <= ap_const_logic_1;
        else 
            ap_idle_pp0 <= ap_const_logic_0;
        end if; 
    end process;


    ap_phi_mux_indvar_i_i_phi_fu_136_p4_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter1, ap_block_pp0_stage0, exitcond_i_i_reg_250, indvar_i_i_reg_132, indvar_next_i_i_reg_254)
    begin
        if (((exitcond_i_i_reg_250 = ap_const_lv1_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0))) then 
            ap_phi_mux_indvar_i_i_phi_fu_136_p4 <= indvar_next_i_i_reg_254;
        else 
            ap_phi_mux_indvar_i_i_phi_fu_136_p4 <= indvar_i_i_reg_132;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_CS_fsm_state12)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state12)) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;


    ap_return_assign_proc : process(ap_CS_fsm_state12, data_length_V_write_s_fu_217_p3, ap_return_preg)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state12)) then 
            ap_return <= data_length_V_write_s_fu_217_p3;
        else 
            ap_return <= ap_return_preg;
        end if; 
    end process;


    ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY_assign_proc : process(m_axi_tx_buffer_V_ARREADY, ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY)
    begin
        if ((ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY = ap_const_logic_0)) then 
            ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY <= m_axi_tx_buffer_V_ARREADY;
        else 
            ap_sig_ioackin_m_axi_tx_buffer_V_ARREADY <= ap_const_logic_1;
        end if; 
    end process;

    cache_V_address0 <= indvar4_i_i_fu_194_p1(9 - 1 downto 0);

    cache_V_ce0_assign_proc : process(ap_block_pp0_stage0_11001, ap_enable_reg_pp0_iter2)
    begin
        if (((ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then 
            cache_V_ce0 <= ap_const_logic_1;
        else 
            cache_V_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    cache_V_d0 <= tx_buffer_V_addr_rea_reg_259;

    cache_V_we0_assign_proc : process(ap_block_pp0_stage0_11001, exitcond_i_i_reg_250_pp0_iter1_reg, ap_enable_reg_pp0_iter2)
    begin
        if (((exitcond_i_i_reg_250_pp0_iter1_reg = ap_const_lv1_0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then 
            cache_V_we0 <= ap_const_logic_1;
        else 
            cache_V_we0 <= ap_const_logic_0;
        end if; 
    end process;

    data_length_V_write_s_fu_217_p3 <= 
        final_burst_length_V when (tmp_3_i_i_fu_211_p2(0) = '1') else 
        ap_const_lv13_1000;
    exitcond_i_i_fu_182_p2 <= "1" when (ap_phi_mux_indvar_i_i_phi_fu_136_p4 = ap_const_lv10_200) else "0";
    indvar4_i_i_fu_194_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(indvar_i_i_reg_132_pp0_iter1_reg),64));
    indvar_next_i_i_fu_188_p2 <= std_logic_vector(unsigned(ap_phi_mux_indvar_i_i_phi_fu_136_p4) + unsigned(ap_const_lv10_1));
    lhs_V_cast_i_i_fu_199_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(loop_count_V),13));
    m_axi_tx_buffer_V_ARADDR <= sum_cast_i_fu_172_p1(32 - 1 downto 0);
    m_axi_tx_buffer_V_ARBURST <= ap_const_lv2_0;
    m_axi_tx_buffer_V_ARCACHE <= ap_const_lv4_0;
    m_axi_tx_buffer_V_ARID <= ap_const_lv1_0;
    m_axi_tx_buffer_V_ARLEN <= ap_const_lv32_200;
    m_axi_tx_buffer_V_ARLOCK <= ap_const_lv2_0;
    m_axi_tx_buffer_V_ARPROT <= ap_const_lv3_0;
    m_axi_tx_buffer_V_ARQOS <= ap_const_lv4_0;
    m_axi_tx_buffer_V_ARREGION <= ap_const_lv4_0;
    m_axi_tx_buffer_V_ARSIZE <= ap_const_lv3_0;
    m_axi_tx_buffer_V_ARUSER <= ap_const_lv1_0;

    m_axi_tx_buffer_V_ARVALID_assign_proc : process(ap_CS_fsm_state2, ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY)
    begin
        if (((ap_reg_ioackin_m_axi_tx_buffer_V_ARREADY = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            m_axi_tx_buffer_V_ARVALID <= ap_const_logic_1;
        else 
            m_axi_tx_buffer_V_ARVALID <= ap_const_logic_0;
        end if; 
    end process;

    m_axi_tx_buffer_V_AWADDR <= ap_const_lv32_0;
    m_axi_tx_buffer_V_AWBURST <= ap_const_lv2_0;
    m_axi_tx_buffer_V_AWCACHE <= ap_const_lv4_0;
    m_axi_tx_buffer_V_AWID <= ap_const_lv1_0;
    m_axi_tx_buffer_V_AWLEN <= ap_const_lv32_0;
    m_axi_tx_buffer_V_AWLOCK <= ap_const_lv2_0;
    m_axi_tx_buffer_V_AWPROT <= ap_const_lv3_0;
    m_axi_tx_buffer_V_AWQOS <= ap_const_lv4_0;
    m_axi_tx_buffer_V_AWREGION <= ap_const_lv4_0;
    m_axi_tx_buffer_V_AWSIZE <= ap_const_lv3_0;
    m_axi_tx_buffer_V_AWUSER <= ap_const_lv1_0;
    m_axi_tx_buffer_V_AWVALID <= ap_const_logic_0;
    m_axi_tx_buffer_V_BREADY <= ap_const_logic_0;

    m_axi_tx_buffer_V_RREADY_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter1, exitcond_i_i_reg_250, ap_block_pp0_stage0_11001)
    begin
        if (((exitcond_i_i_reg_250 = ap_const_lv1_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then 
            m_axi_tx_buffer_V_RREADY <= ap_const_logic_1;
        else 
            m_axi_tx_buffer_V_RREADY <= ap_const_logic_0;
        end if; 
    end process;

    m_axi_tx_buffer_V_WDATA <= ap_const_lv64_0;
    m_axi_tx_buffer_V_WID <= ap_const_lv1_0;
    m_axi_tx_buffer_V_WLAST <= ap_const_logic_0;
    m_axi_tx_buffer_V_WSTRB <= ap_const_lv8_0;
    m_axi_tx_buffer_V_WUSER <= ap_const_lv1_0;
    m_axi_tx_buffer_V_WVALID <= ap_const_logic_0;
    r_V_fu_202_p2 <= std_logic_vector(unsigned(lhs_V_cast_i_i_fu_199_p1) + unsigned(ap_const_lv13_1FFF));
    sext_cast_i_fu_162_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tx_buffer_V_offset),30));
    sum_cast_i_fu_172_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(sum_i_reg_229),64));
    sum_i_fu_166_p2 <= std_logic_vector(unsigned(tmp_8_cast_i_fu_158_p1) + unsigned(sext_cast_i_fu_162_p1));
    tmp_2_cast_i_i_fu_208_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_reg_224),13));
    tmp_3_i_i_fu_211_p2 <= "1" when (tmp_2_cast_i_i_fu_208_p1 = r_V_fu_202_p2) else "0";
    tmp_7_i_fu_148_p4 <= ((tx_buffer_V_offset1 & tmp_fu_144_p1) & ap_const_lv9_0);
    tmp_8_cast_i_fu_158_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_7_i_fu_148_p4),30));
    tmp_fu_144_p1 <= val_assign(11 - 1 downto 0);

    tx_buffer_V_blk_n_AR_assign_proc : process(m_axi_tx_buffer_V_ARREADY, ap_CS_fsm_state2)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            tx_buffer_V_blk_n_AR <= m_axi_tx_buffer_V_ARREADY;
        else 
            tx_buffer_V_blk_n_AR <= ap_const_logic_1;
        end if; 
    end process;


    tx_buffer_V_blk_n_R_assign_proc : process(m_axi_tx_buffer_V_RVALID, ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter1, ap_block_pp0_stage0, exitcond_i_i_reg_250)
    begin
        if (((exitcond_i_i_reg_250 = ap_const_lv1_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0))) then 
            tx_buffer_V_blk_n_R <= m_axi_tx_buffer_V_RVALID;
        else 
            tx_buffer_V_blk_n_R <= ap_const_logic_1;
        end if; 
    end process;

end behav;
