library ieee;
use ieee.std_logic_1164.all;

entity gfmult_by3 is 
	port (
		input_byte : in std_logic_vector(7 downto 0);
		output_byte : out std_logic_vector(7 downto 0)
	);
end gfmult_by3;


architecture behavioral of gfmult_by3 is
	signal shifted_byte : std_logic_vector(7 downto 0);
begin
	gfmult_by2_inst : entity work.gfmult_by2
		port map(
			input_byte  => input_byte,
			output_byte => shifted_byte
		);
	output_byte <= shifted_byte xor input_byte;
--	xor2_inst : entity work.xor2
--		generic map(
--			size => 8
--		)
--		port map(
--			input1 => shifted_byte,
--			input2 => input_byte,
--			output => output_byte
--		);	
		
end architecture behavioral;
