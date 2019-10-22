library ieee;
use ieee.std_logic_1164.all;

entity gfmult_by2 is
	port (
		input_byte : in std_logic_vector(7 downto 0);
		output_byte : out std_logic_vector(7 downto 0)
	);
end gfmult_by2;

architecture behavioral of gfmult_by2 is
	signal shifted_byte : std_logic_vector(7 downto 0);
	signal conditional_xor : std_logic_vector(7 downto 0);
begin
	shifted_byte <= input_byte(6 downto 0) & "0";
	conditional_xor <= "000" & input_byte(7) & input_byte(7) & "0" & input_byte(7) & input_byte(7);
	output_byte <= shifted_byte xor conditional_xor;
--	xor2_inst : entity work.xor2
--		generic map(
--			size => 8
--		)
--		port map(
--			input1 => conditional_xor,
--			input2 => shifted_byte,
--			output => output_byte
--		);
--	
end architecture behavioral;

