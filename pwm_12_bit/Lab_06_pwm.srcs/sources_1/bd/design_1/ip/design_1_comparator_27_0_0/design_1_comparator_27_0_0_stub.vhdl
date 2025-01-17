-- Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2019.1 (lin64) Build 2552052 Fri May 24 14:47:09 MDT 2019
-- Date        : Wed Dec 18 12:19:19 2019
-- Host        : Lenovo-Ideapad running 64-bit Ubuntu 16.04.6 LTS
-- Command     : write_vhdl -force -mode synth_stub
--               /home/rasmus/Documents/RobTek/Robot_Electronics/Lek_06/Lab_06_pwm/Lab_06_pwm.srcs/sources_1/bd/design_1/ip/design_1_comparator_27_0_0/design_1_comparator_27_0_0_stub.vhdl
-- Design      : design_1_comparator_27_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_comparator_27_0_0 is
  Port ( 
    a : in STD_LOGIC_VECTOR ( 11 downto 0 );
    b : in STD_LOGIC_VECTOR ( 11 downto 0 );
    c : out STD_LOGIC
  );

end design_1_comparator_27_0_0;

architecture stub of design_1_comparator_27_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "a[11:0],b[11:0],c";
attribute x_core_info : string;
attribute x_core_info of stub : architecture is "comparator_27,Vivado 2019.1";
begin
end;
