############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project datamover
set_top data_mover_8b64b
add_files datamover/datamover.cpp
add_files -tb datamover/testbench.cpp
open_solution "production"
set_part {xc7z020clg400-3} -tool vivado
create_clock -period 6.5 -name default
set_clock_uncertainty 2.0
#source "./datamover/production/directives.tcl"
csim_design -clean
csynth_design
cosim_design -rtl vhdl -tool xsim
<<<<<<< HEAD
export_design -flow impl -rtl vhdl -format ip_catalog -description "8-bit AXIS to 64-bit AXI data mover" -vendor "krtl" -library "snickerdoodle" -version "1.06" -display_name "8-bit AXIS to 64-bit AXI data mover"
=======
export_design -flow impl -rtl vhdl -format ip_catalog -description "data mover" -vendor "krtl" -library "snickerdoodle" -version "1.10" -display_name "data mover"
>>>>>>> master
