library ieee;
use ieee.std_logic_1164.all;

entity inv_column_calculator is
	port (
		input_data : in std_logic_vector(31 downto 0);
		output_data : out std_logic_vector(31 downto 0)
	);
end inv_column_calculator;

architecture rtl of inv_column_calculator is		
	signal temp0 : std_logic_vector(7 downto 0);
	signal temp1 : std_logic_vector(7 downto 0);
	signal temp0x2 : std_logic_vector(7 downto 0);
	signal temp1x2 : std_logic_vector(7 downto 0); 
	signal temp0x2x2 : std_logic_vector(7 downto 0);
	signal temp1x2x2 : std_logic_vector(7 downto 0);
	signal mixcol_input : std_logic_vector(31 downto 0);
begin
	temp0 <= input_data(7 downto 0) xor input_data(23 downto 16);
	temp1 <= input_data(15 downto 8) xor input_data(31 downto 24);		
	gfmult_by2_inst0 : entity work.gfmult_by2
		port map(
			input_byte  => temp0,
			output_byte => temp0x2
		);
	gfmult_by2_inst1 : entity work.gfmult_by2
		port map(
			input_byte  => temp1,
			output_byte => temp1x2
		);
	gfmult_by2_inst2 : entity work.gfmult_by2
		port map(
			input_byte  => temp0x2,
			output_byte => temp0x2x2
		);
	gfmult_by2_inst3 : entity work.gfmult_by2
		port map(
			input_byte  => temp1x2,
			output_byte => temp1x2x2
		);
	mixcol_input(7 downto 0) <= input_data(7 downto 0) xor temp0x2x2;
	mixcol_input(15 downto 8) <= input_data(15 downto 8) xor temp1x2x2;
	mixcol_input(23 downto 16) <= input_data(23 downto 16) xor temp0x2x2;
	mixcol_input(31 downto 24) <= input_data(31 downto 24) xor temp1x2x2;
	column_calculator_inst : entity work.column_calculator
		port map(
			input_data  => mixcol_input,
			output_data => output_data
		);		
end architecture rtl;
