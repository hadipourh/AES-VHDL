library ieee;
use ieee.std_logic_1164.all;

entity xor4 is
	generic (size : positive);
	port (
		input1 : in std_logic_vector(size - 1 downto 0);
		input2 : in std_logic_vector(size - 1 downto 0);
		input3 : in std_logic_vector(size - 1 downto 0);
		input4 : in std_logic_vector(size - 1 downto 0);
		output : out std_logic_vector(size - 1 downto 0)
	);
end xor4;

architecture rtl of xor4 is
	
begin
	gen_bitwise_xors : for i in 0 to (size -1) generate
		output(i) <= input1(i) xor input2(i) xor input3(i) xor input4(i);
	end generate gen_bitwise_xors;	
end architecture rtl;

