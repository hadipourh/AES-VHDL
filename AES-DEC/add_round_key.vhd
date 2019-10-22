library ieee;
use ieee.std_logic_1164.all;

entity add_round_key is
	port (
		input1 : in std_logic_vector(127 downto 0);
		input2 : in std_logic_vector(127 downto 0);
		output : out std_logic_vector(127 downto 0)
	);
end add_round_key;

architecture rtl of add_round_key is
	
begin
	output <= input1 xor input2;
--	xor2_inst : entity work.xor2
--		generic map(
--			size => 128
--		)
--		port map(
--			input1 => input1,
--			input2 => input2,
--			output => output
--		);		
end architecture rtl;
