############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project datamover
set_top data_mover
add_files datamover/datamover.cpp
add_files -tb datamover/testbench.cpp
open_solution "production"
set_part {xc7z020clg400-3} -tool vivado
create_clock -period 6.5 -name default
set_clock_uncertainty 2.0
#source "./datamover/production/directives.tcl"
csynth_design
