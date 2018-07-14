-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2018.2
-- Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity write_burst is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_continue : IN STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    cache_V_address0 : OUT STD_LOGIC_VECTOR (8 downto 0);
    cache_V_ce0 : OUT STD_LOGIC;
    cache_V_q0 : IN STD_LOGIC_VECTOR (63 downto 0);
    buffer_offset_V : IN STD_LOGIC_VECTOR (19 downto 0);
    m_axi_rx_buffer_V_AWVALID : OUT STD_LOGIC;
    m_axi_rx_buffer_V_AWREADY : IN STD_LOGIC;
    m_axi_rx_buffer_V_AWADDR : OUT STD_LOGIC_VECTOR (31 downto 0);
    m_axi_rx_buffer_V_AWID : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_rx_buffer_V_AWLEN : OUT STD_LOGIC_VECTOR (31 downto 0);
    m_axi_rx_buffer_V_AWSIZE : OUT STD_LOGIC_VECTOR (2 downto 0);
    m_axi_rx_buffer_V_AWBURST : OUT STD_LOGIC_VECTOR (1 downto 0);
    m_axi_rx_buffer_V_AWLOCK : OUT STD_LOGIC_VECTOR (1 downto 0);
    m_axi_rx_buffer_V_AWCACHE : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_rx_buffer_V_AWPROT : OUT STD_LOGIC_VECTOR (2 downto 0);
    m_axi_rx_buffer_V_AWQOS : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_rx_buffer_V_AWREGION : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_rx_buffer_V_AWUSER : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_rx_buffer_V_WVALID : OUT STD_LOGIC;
    m_axi_rx_buffer_V_WREADY : IN STD_LOGIC;
    m_axi_rx_buffer_V_WDATA : OUT STD_LOGIC_VECTOR (63 downto 0);
    m_axi_rx_buffer_V_WSTRB : OUT STD_LOGIC_VECTOR (7 downto 0);
    m_axi_rx_buffer_V_WLAST : OUT STD_LOGIC;
    m_axi_rx_buffer_V_WID : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_rx_buffer_V_WUSER : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_rx_buffer_V_ARVALID : OUT STD_LOGIC;
    m_axi_rx_buffer_V_ARREADY : IN STD_LOGIC;
    m_axi_rx_buffer_V_ARADDR : OUT STD_LOGIC_VECTOR (31 downto 0);
    m_axi_rx_buffer_V_ARID : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_rx_buffer_V_ARLEN : OUT STD_LOGIC_VECTOR (31 downto 0);
    m_axi_rx_buffer_V_ARSIZE : OUT STD_LOGIC_VECTOR (2 downto 0);
    m_axi_rx_buffer_V_ARBURST : OUT STD_LOGIC_VECTOR (1 downto 0);
    m_axi_rx_buffer_V_ARLOCK : OUT STD_LOGIC_VECTOR (1 downto 0);
    m_axi_rx_buffer_V_ARCACHE : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_rx_buffer_V_ARPROT : OUT STD_LOGIC_VECTOR (2 downto 0);
    m_axi_rx_buffer_V_ARQOS : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_rx_buffer_V_ARREGION : OUT STD_LOGIC_VECTOR (3 downto 0);
    m_axi_rx_buffer_V_ARUSER : OUT STD_LOGIC_VECTOR (0 downto 0);
    m_axi_rx_buffer_V_RVALID : IN STD_LOGIC;
    m_axi_rx_buffer_V_RREADY : OUT STD_LOGIC;
    m_axi_rx_buffer_V_RDATA : IN STD_LOGIC_VECTOR (63 downto 0);
    m_axi_rx_buffer_V_RLAST : IN STD_LOGIC;
    m_axi_rx_buffer_V_RID : IN STD_LOGIC_VECTOR (0 downto 0);
    m_axi_rx_buffer_V_RUSER : IN STD_LOGIC_VECTOR (0 downto 0);
    m_axi_rx_buffer_V_RRESP : IN STD_LOGIC_VECTOR (1 downto 0);
    m_axi_rx_buffer_V_BVALID : IN STD_LOGIC;
    m_axi_rx_buffer_V_BREADY : OUT STD_LOGIC;
    m_axi_rx_buffer_V_BRESP : IN STD_LOGIC_VECTOR (1 downto 0);
    m_axi_rx_buffer_V_BID : IN STD_LOGIC_VECTOR (0 downto 0);
    m_axi_rx_buffer_V_BUSER : IN STD_LOGIC_VECTOR (0 downto 0);
    rx_buffer_V_offset_dout : IN STD_LOGIC_VECTOR (28 downto 0);
    rx_buffer_V_offset_empty_n : IN STD_LOGIC;
    rx_buffer_V_offset_read : OUT STD_LOGIC;
    rx_buffer_V_offset_c_dout : IN STD_LOGIC_VECTOR (0 downto 0);
    rx_buffer_V_offset_c_empty_n : IN STD_LOGIC;
    rx_buffer_V_offset_c_read : OUT STD_LOGIC );
end;


architecture behav of write_burst is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (7 downto 0) := "00000001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (7 downto 0) := "00000010";
    constant ap_ST_fsm_pp0_stage0 : STD_LOGIC_VECTOR (7 downto 0) := "00000100";
    constant ap_ST_fsm_state6 : STD_LOGIC_VECTOR (7 downto 0) := "00001000";
    constant ap_ST_fsm_state7 : STD_LOGIC_VECTOR (7 downto 0) := "00010000";
    constant ap_ST_fsm_state8 : STD_LOGIC_VECTOR (7 downto 0) := "00100000";
    constant ap_ST_fsm_state9 : STD_LOGIC_VECTOR (7 downto 0) := "01000000";
    constant ap_ST_fsm_state10 : STD_LOGIC_VECTOR (7 downto 0) := "10000000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv3_0 : STD_LOGIC_VECTOR (2 downto 0) := "000";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv4_0 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_boolean_0 : BOOLEAN := false;
    constant ap_const_lv32_7 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000111";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv10_0 : STD_LOGIC_VECTOR (9 downto 0) := "0000000000";
    constant ap_const_lv32_200 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000001000000000";
    constant ap_const_lv8_FF : STD_LOGIC_VECTOR (7 downto 0) := "11111111";
    constant ap_const_lv10_200 : STD_LOGIC_VECTOR (9 downto 0) := "1000000000";
    constant ap_const_lv10_1 : STD_LOGIC_VECTOR (9 downto 0) := "0000000001";

    signal ap_done_reg : STD_LOGIC := '0';
    signal ap_CS_fsm : STD_LOGIC_VECTOR (7 downto 0) := "00000001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal rx_buffer_V_blk_n_AW : STD_LOGIC;
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal rx_buffer_V_blk_n_W : STD_LOGIC;
    signal ap_enable_reg_pp0_iter2 : STD_LOGIC := '0';
    signal ap_block_pp0_stage0 : BOOLEAN;
    signal exitcond_i_i_i_i_reg_216 : STD_LOGIC_VECTOR (0 downto 0);
    signal exitcond_i_i_i_i_reg_216_pp0_iter1_reg : STD_LOGIC_VECTOR (0 downto 0);
    signal rx_buffer_V_blk_n_B : STD_LOGIC;
    signal ap_CS_fsm_state10 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state10 : signal is "none";
    signal rx_buffer_V_offset_blk_n : STD_LOGIC;
    signal rx_buffer_V_offset_c_blk_n : STD_LOGIC;
    signal indvar_i_i_i_i_reg_145 : STD_LOGIC_VECTOR (9 downto 0);
    signal sum_i_i_fu_172_p2 : STD_LOGIC_VECTOR (29 downto 0);
    signal sum_i_i_reg_205 : STD_LOGIC_VECTOR (29 downto 0);
    signal ap_block_state1 : BOOLEAN;
    signal ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY : STD_LOGIC;
    signal exitcond_i_i_i_i_fu_188_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm_pp0_stage0 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp0_stage0 : signal is "none";
    signal ap_block_state3_pp0_stage0_iter0 : BOOLEAN;
    signal ap_block_state4_pp0_stage0_iter1 : BOOLEAN;
    signal ap_block_state5_pp0_stage0_iter2 : BOOLEAN;
    signal ap_sig_ioackin_m_axi_rx_buffer_V_WREADY : STD_LOGIC;
    signal ap_block_state5_io : BOOLEAN;
    signal ap_block_pp0_stage0_11001 : BOOLEAN;
    signal indvar_next_i_i_i_i_fu_194_p2 : STD_LOGIC_VECTOR (9 downto 0);
    signal ap_enable_reg_pp0_iter0 : STD_LOGIC := '0';
    signal cache_V_load_reg_230 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_block_pp0_stage0_subdone : BOOLEAN;
    signal ap_condition_pp0_exit_iter0_state3 : STD_LOGIC;
    signal ap_enable_reg_pp0_iter1 : STD_LOGIC := '0';
    signal indvar4_i_i_i_i_fu_200_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal sum_cast_i_i_fu_178_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY : STD_LOGIC := '0';
    signal ap_reg_ioackin_m_axi_rx_buffer_V_WREADY : STD_LOGIC := '0';
    signal ap_block_pp0_stage0_01001 : BOOLEAN;
    signal tmp_2_i_i_fu_156_p3 : STD_LOGIC_VECTOR (20 downto 0);
    signal tmp_3_cast_i_i_fu_164_p1 : STD_LOGIC_VECTOR (29 downto 0);
    signal sext_cast_i_i_fu_168_p1 : STD_LOGIC_VECTOR (29 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (7 downto 0);
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
                elsif (((m_axi_rx_buffer_V_BVALID = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state10))) then 
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
                if (((ap_const_logic_1 = ap_condition_pp0_exit_iter0_state3) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone))) then 
                    ap_enable_reg_pp0_iter0 <= ap_const_logic_0;
                elsif (((ap_const_logic_1 = ap_CS_fsm_state2) and (ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY = ap_const_logic_1))) then 
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
                    if ((ap_const_logic_1 = ap_condition_pp0_exit_iter0_state3)) then 
                        ap_enable_reg_pp0_iter1 <= (ap_const_logic_1 xor ap_condition_pp0_exit_iter0_state3);
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
                elsif (((ap_const_logic_1 = ap_CS_fsm_state2) and (ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY = ap_const_logic_1))) then 
                    ap_enable_reg_pp0_iter2 <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY <= ap_const_logic_0;
            else
                if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
                    if ((ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY = ap_const_logic_1)) then 
                        ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY <= ap_const_logic_0;
                    elsif ((m_axi_rx_buffer_V_AWREADY = ap_const_logic_1)) then 
                        ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY <= ap_const_logic_1;
                    end if;
                end if; 
            end if;
        end if;
    end process;


    ap_reg_ioackin_m_axi_rx_buffer_V_WREADY_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_reg_ioackin_m_axi_rx_buffer_V_WREADY <= ap_const_logic_0;
            else
                if (((exitcond_i_i_i_i_reg_216_pp0_iter1_reg = ap_const_lv1_0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1))) then
                    if ((ap_const_boolean_0 = ap_block_pp0_stage0_11001)) then 
                        ap_reg_ioackin_m_axi_rx_buffer_V_WREADY <= ap_const_logic_0;
                    elsif (((ap_const_boolean_0 = ap_block_pp0_stage0_01001) and (m_axi_rx_buffer_V_WREADY = ap_const_logic_1))) then 
                        ap_reg_ioackin_m_axi_rx_buffer_V_WREADY <= ap_const_logic_1;
                    end if;
                end if; 
            end if;
        end if;
    end process;


    indvar_i_i_i_i_reg_145_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond_i_i_i_i_fu_188_p2 = ap_const_lv1_0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then 
                indvar_i_i_i_i_reg_145 <= indvar_next_i_i_i_i_fu_194_p2;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state2) and (ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY = ap_const_logic_1))) then 
                indvar_i_i_i_i_reg_145 <= ap_const_lv10_0;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((exitcond_i_i_i_i_reg_216 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then
                cache_V_load_reg_230 <= cache_V_q0;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then
                exitcond_i_i_i_i_reg_216 <= exitcond_i_i_i_i_fu_188_p2;
                exitcond_i_i_i_i_reg_216_pp0_iter1_reg <= exitcond_i_i_i_i_reg_216;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((not(((rx_buffer_V_offset_c_empty_n = ap_const_logic_0) or (rx_buffer_V_offset_empty_n = ap_const_logic_0) or (ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                sum_i_i_reg_205 <= sum_i_i_fu_172_p2;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_done_reg, ap_CS_fsm, ap_CS_fsm_state1, m_axi_rx_buffer_V_BVALID, rx_buffer_V_offset_empty_n, rx_buffer_V_offset_c_empty_n, ap_CS_fsm_state2, ap_enable_reg_pp0_iter2, ap_CS_fsm_state10, ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY, exitcond_i_i_i_i_fu_188_p2, ap_enable_reg_pp0_iter0, ap_block_pp0_stage0_subdone, ap_enable_reg_pp0_iter1)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if ((not(((rx_buffer_V_offset_c_empty_n = ap_const_logic_0) or (rx_buffer_V_offset_empty_n = ap_const_logic_0) or (ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state2) and (ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                else
                    ap_NS_fsm <= ap_ST_fsm_state2;
                end if;
            when ap_ST_fsm_pp0_stage0 => 
                if ((not(((ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (exitcond_i_i_i_i_fu_188_p2 = ap_const_lv1_1))) and not(((ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone))))) then
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                elsif ((((ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (exitcond_i_i_i_i_fu_188_p2 = ap_const_lv1_1)) or ((ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone)))) then
                    ap_NS_fsm <= ap_ST_fsm_state6;
                else
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                end if;
            when ap_ST_fsm_state6 => 
                ap_NS_fsm <= ap_ST_fsm_state7;
            when ap_ST_fsm_state7 => 
                ap_NS_fsm <= ap_ST_fsm_state8;
            when ap_ST_fsm_state8 => 
                ap_NS_fsm <= ap_ST_fsm_state9;
            when ap_ST_fsm_state9 => 
                ap_NS_fsm <= ap_ST_fsm_state10;
            when ap_ST_fsm_state10 => 
                if (((m_axi_rx_buffer_V_BVALID = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state10))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state10;
                end if;
            when others =>  
                ap_NS_fsm <= "XXXXXXXX";
        end case;
    end process;
    ap_CS_fsm_pp0_stage0 <= ap_CS_fsm(2);
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state10 <= ap_CS_fsm(7);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
        ap_block_pp0_stage0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_01001 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_block_pp0_stage0_11001_assign_proc : process(ap_enable_reg_pp0_iter2, ap_block_state5_io)
    begin
                ap_block_pp0_stage0_11001 <= ((ap_const_boolean_1 = ap_block_state5_io) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1));
    end process;


    ap_block_pp0_stage0_subdone_assign_proc : process(ap_enable_reg_pp0_iter2, ap_block_state5_io)
    begin
                ap_block_pp0_stage0_subdone <= ((ap_const_boolean_1 = ap_block_state5_io) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1));
    end process;


    ap_block_state1_assign_proc : process(ap_start, ap_done_reg, rx_buffer_V_offset_empty_n, rx_buffer_V_offset_c_empty_n)
    begin
                ap_block_state1 <= ((rx_buffer_V_offset_c_empty_n = ap_const_logic_0) or (rx_buffer_V_offset_empty_n = ap_const_logic_0) or (ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1));
    end process;

        ap_block_state3_pp0_stage0_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state4_pp0_stage0_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_block_state5_io_assign_proc : process(exitcond_i_i_i_i_reg_216_pp0_iter1_reg, ap_sig_ioackin_m_axi_rx_buffer_V_WREADY)
    begin
                ap_block_state5_io <= ((exitcond_i_i_i_i_reg_216_pp0_iter1_reg = ap_const_lv1_0) and (ap_sig_ioackin_m_axi_rx_buffer_V_WREADY = ap_const_logic_0));
    end process;

        ap_block_state5_pp0_stage0_iter2 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_condition_pp0_exit_iter0_state3_assign_proc : process(exitcond_i_i_i_i_fu_188_p2)
    begin
        if ((exitcond_i_i_i_i_fu_188_p2 = ap_const_lv1_1)) then 
            ap_condition_pp0_exit_iter0_state3 <= ap_const_logic_1;
        else 
            ap_condition_pp0_exit_iter0_state3 <= ap_const_logic_0;
        end if; 
    end process;


    ap_done_assign_proc : process(ap_done_reg, m_axi_rx_buffer_V_BVALID, ap_CS_fsm_state10)
    begin
        if (((m_axi_rx_buffer_V_BVALID = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state10))) then 
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


    ap_idle_pp0_assign_proc : process(ap_enable_reg_pp0_iter2, ap_enable_reg_pp0_iter0, ap_enable_reg_pp0_iter1)
    begin
        if (((ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_0))) then 
            ap_idle_pp0 <= ap_const_logic_1;
        else 
            ap_idle_pp0 <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(m_axi_rx_buffer_V_BVALID, ap_CS_fsm_state10)
    begin
        if (((m_axi_rx_buffer_V_BVALID = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state10))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;


    ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY_assign_proc : process(m_axi_rx_buffer_V_AWREADY, ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY)
    begin
        if ((ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY = ap_const_logic_0)) then 
            ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY <= m_axi_rx_buffer_V_AWREADY;
        else 
            ap_sig_ioackin_m_axi_rx_buffer_V_AWREADY <= ap_const_logic_1;
        end if; 
    end process;


    ap_sig_ioackin_m_axi_rx_buffer_V_WREADY_assign_proc : process(m_axi_rx_buffer_V_WREADY, ap_reg_ioackin_m_axi_rx_buffer_V_WREADY)
    begin
        if ((ap_reg_ioackin_m_axi_rx_buffer_V_WREADY = ap_const_logic_0)) then 
            ap_sig_ioackin_m_axi_rx_buffer_V_WREADY <= m_axi_rx_buffer_V_WREADY;
        else 
            ap_sig_ioackin_m_axi_rx_buffer_V_WREADY <= ap_const_logic_1;
        end if; 
    end process;

    cache_V_address0 <= indvar4_i_i_i_i_fu_200_p1(9 - 1 downto 0);

    cache_V_ce0_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_11001, ap_enable_reg_pp0_iter0)
    begin
        if (((ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then 
            cache_V_ce0 <= ap_const_logic_1;
        else 
            cache_V_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    exitcond_i_i_i_i_fu_188_p2 <= "1" when (indvar_i_i_i_i_reg_145 = ap_const_lv10_200) else "0";
    indvar4_i_i_i_i_fu_200_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(indvar_i_i_i_i_reg_145),64));
    indvar_next_i_i_i_i_fu_194_p2 <= std_logic_vector(unsigned(indvar_i_i_i_i_reg_145) + unsigned(ap_const_lv10_1));
    m_axi_rx_buffer_V_ARADDR <= ap_const_lv32_0;
    m_axi_rx_buffer_V_ARBURST <= ap_const_lv2_0;
    m_axi_rx_buffer_V_ARCACHE <= ap_const_lv4_0;
    m_axi_rx_buffer_V_ARID <= ap_const_lv1_0;
    m_axi_rx_buffer_V_ARLEN <= ap_const_lv32_0;
    m_axi_rx_buffer_V_ARLOCK <= ap_const_lv2_0;
    m_axi_rx_buffer_V_ARPROT <= ap_const_lv3_0;
    m_axi_rx_buffer_V_ARQOS <= ap_const_lv4_0;
    m_axi_rx_buffer_V_ARREGION <= ap_const_lv4_0;
    m_axi_rx_buffer_V_ARSIZE <= ap_const_lv3_0;
    m_axi_rx_buffer_V_ARUSER <= ap_const_lv1_0;
    m_axi_rx_buffer_V_ARVALID <= ap_const_logic_0;
    m_axi_rx_buffer_V_AWADDR <= sum_cast_i_i_fu_178_p1(32 - 1 downto 0);
    m_axi_rx_buffer_V_AWBURST <= ap_const_lv2_0;
    m_axi_rx_buffer_V_AWCACHE <= ap_const_lv4_0;
    m_axi_rx_buffer_V_AWID <= ap_const_lv1_0;
    m_axi_rx_buffer_V_AWLEN <= ap_const_lv32_200;
    m_axi_rx_buffer_V_AWLOCK <= ap_const_lv2_0;
    m_axi_rx_buffer_V_AWPROT <= ap_const_lv3_0;
    m_axi_rx_buffer_V_AWQOS <= ap_const_lv4_0;
    m_axi_rx_buffer_V_AWREGION <= ap_const_lv4_0;
    m_axi_rx_buffer_V_AWSIZE <= ap_const_lv3_0;
    m_axi_rx_buffer_V_AWUSER <= ap_const_lv1_0;

    m_axi_rx_buffer_V_AWVALID_assign_proc : process(ap_CS_fsm_state2, ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY)
    begin
        if (((ap_reg_ioackin_m_axi_rx_buffer_V_AWREADY = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            m_axi_rx_buffer_V_AWVALID <= ap_const_logic_1;
        else 
            m_axi_rx_buffer_V_AWVALID <= ap_const_logic_0;
        end if; 
    end process;


    m_axi_rx_buffer_V_BREADY_assign_proc : process(m_axi_rx_buffer_V_BVALID, ap_CS_fsm_state10)
    begin
        if (((m_axi_rx_buffer_V_BVALID = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state10))) then 
            m_axi_rx_buffer_V_BREADY <= ap_const_logic_1;
        else 
            m_axi_rx_buffer_V_BREADY <= ap_const_logic_0;
        end if; 
    end process;

    m_axi_rx_buffer_V_RREADY <= ap_const_logic_0;
    m_axi_rx_buffer_V_WDATA <= cache_V_load_reg_230;
    m_axi_rx_buffer_V_WID <= ap_const_lv1_0;
    m_axi_rx_buffer_V_WLAST <= ap_const_logic_0;
    m_axi_rx_buffer_V_WSTRB <= ap_const_lv8_FF;
    m_axi_rx_buffer_V_WUSER <= ap_const_lv1_0;

    m_axi_rx_buffer_V_WVALID_assign_proc : process(ap_enable_reg_pp0_iter2, exitcond_i_i_i_i_reg_216_pp0_iter1_reg, ap_reg_ioackin_m_axi_rx_buffer_V_WREADY, ap_block_pp0_stage0_01001)
    begin
        if (((exitcond_i_i_i_i_reg_216_pp0_iter1_reg = ap_const_lv1_0) and (ap_reg_ioackin_m_axi_rx_buffer_V_WREADY = ap_const_logic_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_01001) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1))) then 
            m_axi_rx_buffer_V_WVALID <= ap_const_logic_1;
        else 
            m_axi_rx_buffer_V_WVALID <= ap_const_logic_0;
        end if; 
    end process;


    rx_buffer_V_blk_n_AW_assign_proc : process(m_axi_rx_buffer_V_AWREADY, ap_CS_fsm_state2)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            rx_buffer_V_blk_n_AW <= m_axi_rx_buffer_V_AWREADY;
        else 
            rx_buffer_V_blk_n_AW <= ap_const_logic_1;
        end if; 
    end process;


    rx_buffer_V_blk_n_B_assign_proc : process(m_axi_rx_buffer_V_BVALID, ap_CS_fsm_state10)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state10)) then 
            rx_buffer_V_blk_n_B <= m_axi_rx_buffer_V_BVALID;
        else 
            rx_buffer_V_blk_n_B <= ap_const_logic_1;
        end if; 
    end process;


    rx_buffer_V_blk_n_W_assign_proc : process(m_axi_rx_buffer_V_WREADY, ap_enable_reg_pp0_iter2, ap_block_pp0_stage0, exitcond_i_i_i_i_reg_216_pp0_iter1_reg)
    begin
        if (((exitcond_i_i_i_i_reg_216_pp0_iter1_reg = ap_const_lv1_0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (ap_const_boolean_0 = ap_block_pp0_stage0))) then 
            rx_buffer_V_blk_n_W <= m_axi_rx_buffer_V_WREADY;
        else 
            rx_buffer_V_blk_n_W <= ap_const_logic_1;
        end if; 
    end process;


    rx_buffer_V_offset_blk_n_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1, rx_buffer_V_offset_empty_n)
    begin
        if ((not(((ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            rx_buffer_V_offset_blk_n <= rx_buffer_V_offset_empty_n;
        else 
            rx_buffer_V_offset_blk_n <= ap_const_logic_1;
        end if; 
    end process;


    rx_buffer_V_offset_c_blk_n_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1, rx_buffer_V_offset_c_empty_n)
    begin
        if ((not(((ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            rx_buffer_V_offset_c_blk_n <= rx_buffer_V_offset_c_empty_n;
        else 
            rx_buffer_V_offset_c_blk_n <= ap_const_logic_1;
        end if; 
    end process;


    rx_buffer_V_offset_c_read_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1, rx_buffer_V_offset_empty_n, rx_buffer_V_offset_c_empty_n)
    begin
        if ((not(((rx_buffer_V_offset_c_empty_n = ap_const_logic_0) or (rx_buffer_V_offset_empty_n = ap_const_logic_0) or (ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            rx_buffer_V_offset_c_read <= ap_const_logic_1;
        else 
            rx_buffer_V_offset_c_read <= ap_const_logic_0;
        end if; 
    end process;


    rx_buffer_V_offset_read_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1, rx_buffer_V_offset_empty_n, rx_buffer_V_offset_c_empty_n)
    begin
        if ((not(((rx_buffer_V_offset_c_empty_n = ap_const_logic_0) or (rx_buffer_V_offset_empty_n = ap_const_logic_0) or (ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            rx_buffer_V_offset_read <= ap_const_logic_1;
        else 
            rx_buffer_V_offset_read <= ap_const_logic_0;
        end if; 
    end process;

    sext_cast_i_i_fu_168_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(rx_buffer_V_offset_dout),30));
    sum_cast_i_i_fu_178_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(sum_i_i_reg_205),64));
    sum_i_i_fu_172_p2 <= std_logic_vector(unsigned(tmp_3_cast_i_i_fu_164_p1) + unsigned(sext_cast_i_i_fu_168_p1));
    tmp_2_i_i_fu_156_p3 <= (rx_buffer_V_offset_c_dout & buffer_offset_V);
    tmp_3_cast_i_i_fu_164_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(tmp_2_i_i_fu_156_p3),30));
end behav;
