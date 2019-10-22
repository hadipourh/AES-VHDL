library ieee;
use ieee.std_logic_1164.all;

entity inv_mix_columns is
	port (
		input_data : in std_logic_vector(127 downto 0);
		output_data : out std_logic_vector(127 downto 0)
	);
end inv_mix_columns;

architecture rtl of inv_mix_columns is
	
begin
	mix_columns_inst0 : entity work.inv_column_calculator
		port map(
			input_data  => input_data(31 downto 0),
			output_data => output_data(31 downto 0)
		);
	mix_columns_inst1 : entity work.inv_column_calculator
		port map(
			input_data  => input_data(63 downto 32),
			output_data => output_data(63 downto 32)
		);		
	mix_columns_inst2 : entity work.inv_column_calculator
		port map(
			input_data  => input_data(95 downto 64),
			output_data => output_data(95 downto 64)
		);
	mix_columns_inst3 : entity work.inv_column_calculator
		port map(
			input_data  => input_data(127 downto 96),
			output_data => output_data(127 downto 96)
		);	
end architecture rtl;
